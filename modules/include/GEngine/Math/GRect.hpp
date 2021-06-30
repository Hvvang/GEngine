#pragma once

#include <MiniKit/MiniKit.hpp>
#include <GEngine/Math/GVector.hpp>

namespace GEngine::Math {

    using ::MiniKit::Graphics::Rect2D;

    template<class T>
    struct GRect : Rect2D<T> {

        static const GRect<T> ZERO;
        static const GRect<T> INF;

        /*!
         * Default Constructor of 2D Rectangle with default position and size equal zero.
         */
        GRect() : GRect(0, 0, 0, 0) {}
        /*!
         * A 2D Rectangle Constructor with 4 params.
         * @param rectLeft - define X coord of left top point (position of rectangle)
         * @param rectTop - define Y coord of left top point (position of rectangle)
         * @param rectWidth - define width of rect (size of  rectangle)
         * @param rectHeight - define height of rect (size of  rectangle)
         */
        GRect(T rectLeft, T rectTop, T rectWidth, T rectHeight) : Rect2D<T>{rectLeft, rectTop, rectWidth, rectHeight} {}

        /*!
         * A 2D Rectangle Constructor with 2 params.
         * @param pos - Vector that defines X and Y coords of left top point of rectangle
         * @param size - Vector that defines width and height of rectangle
         */
        GRect(const GVector<T> &position, const GVector<T> &size) : Rect2D<T>{position, size} {}


        GRect &operator=(const Rect2D<T> &rect) {
            this->position = rect.position;
            this->size = rect.size;
            return *this;
        }

        const T *Data() const noexcept {
            return &this->position.x;
        }

        T *Data() noexcept {
            return &this->position.x;
        }

        /*!
         * Function for set upping new position of rectangle
         * @param pos - Vector that defines X and Y coords of left top point of rectangle
         */
        void setPosition(const GVector<T> &pos) {
            this->position = pos;
        }
        /*!
         * Function for set upping new size of rectangle
         * @param size - Vector that defines width and height of rectangle
         */
        void setSize(const GVector<T> &size) {
            this->size = size;
        }
        /*!
         * Const function for getting position of rectangle
         * @return Vector position of rectangle
         */
        Vector2D<T> getPosition() const noexcept {
            return this->position;
        }
        /*!
         * Const function for getting size of rectangle
         * @return Vector size of rectangle
         */
        Vector2D<T> getSize() const noexcept {
            return this->size;
        }

        /*!
         * Function for getting position of rectangle
         * @return Vector position of rectangle
         */
        Vector2D<T> &getPosition() noexcept {
            return this->position;
        }
        /*!
         * Function for getting size of rectangle
         * @return Vector size of rectangle
         */
        Vector2D<T> &getSize() noexcept {
            return this->size;
        }

        /*!
         * Function for getting position of point in center of the rectangle
         * @return Vector position of rectangle
         */
        Vector2D<T> getCenter() const {
            return this->position + this->size / 2;
        }

        /*!
         * Check if a point is inside the rectangle's area.
         * This check is non-inclusive. If the point lies on the edge of the rectangle, this function will return false.
         * @tparam T - template param (int, float, double etc.)
         * @param x - X coordinate of the point to test
         * @param y - Y coordinate of the point to test
         * @return true if the point is inside, false otherwise
         */
        bool contains(T x, T y) const {
            return this->position.x < x && this->position.x + this->size.width > x
                && this->position.y < y && this->position.y + this->size.height > y;
        }

        /*!
         * Check if a point is inside the rectangle's area.
         * This check is non-inclusive. If the point lies on the edge of the rectangle, this function will return false.
         * @tparam T - template param (int, float, double etc.)
         * @param point - point to test
         * @return true if the point is inside, false otherwise
         */
        bool contains(const GVector<T> &point) const {
            return contains(point.x, point.y);
        }

        /*!
         * Check the intersection between two rectangles.
         * @param rectangle - Rectangle to test
         * @return true if rectangles overlap, false otherwise
         */
        bool intersects(const GRect<T> &rectangle) const {
            const auto &rightBottomPoint = this->position + this->size;
            const auto &rectRightBottomPoint = rectangle.position + rectangle.size;

            // If one rectangle is on left side of other
            if (this->position.x >= rectRightBottomPoint.x || rectangle.x >= rightBottomPoint.x) {
                return false;
            }
            // If one rectangle is above other
            if (this->position.y >= rectRightBottomPoint.y || rectangle.y >= rightBottomPoint.y) {
                return false;
            }
            return true;
        }

        /*!
         * Check the intersection between two rectangles.
         * @param rectangle - Rectangle to test
         * @param overlap - Overlapping rectangle area
         * @return true if rectangles overlap, false otherwise
         */
        template <class U>
        bool intersects(const GRect<T> &rectangle, GRect<U> &overlap) const {
            if (intersects(rectangle)) {
                overlap.x = (this->position.x > rectangle.x)
                            ? this->position.x
                            : rectangle.x;
                overlap.y = (this->position.y > rectangle.y)
                            ? this->position.y
                            : rectangle.y;

                overlap.width = (this->position.x + this->size.width > rectangle.x + rectangle.width)
                                ? rectangle.x + rectangle.width - this->position.x - overlap.x
                                : this->position.x + this->size.width - rectangle.x - overlap.x;
                overlap.height = (this->position.y + this->size.height > rectangle.y + rectangle.height)
                                 ? rectangle.y + rectangle.height - this->position.y - overlap.y
                                 : this->position.y + this->size.height - rectangle.y - overlap.y;

                overlap.setPosition({overlap.x, overlap.y});
                overlap.setSize({overlap.width, overlap.height});

                return true;
            }
            return false;
        }
    };

    using IntRect = GRect<int32_t>;
    using UIntRect = GRect<uint32_t>;
    using FloatRect = GRect<float>;
    using DoubleRect = GRect<double>;

    /*!
     * Overload of binary operator ==.
     * This operator compares strict equality between two rectangles.
     * @tparam T - template param (int, float, double etc.)
     * @param left - Left operand (a rectangle)
     * @param right - Right operand (a rectangle)
     * @return true if left is equal to right
     */
    template <class T>
    bool operator==(const Rect2D<T> &left, const Rect2D<T> &right) {
        return left.position == right.position && left.size == right.size;
    }

    /*!
     * Overload of binary operator !=.
     * This operator compares strict difference between two rectangles.
     * @tparam T - template param (int, float, double etc.)
     * @param left - Left operand (a rectangle)
     * @param right - Right operand (a rectangle)
     * @return true if left is not equal to right
     */
    template <class T>
    bool operator!=(const Rect2D<T> &left, const Rect2D<T> &right) {
        return !operator==(left, right);
    }

    template<class T>
    std::ostream &operator<<(std::ostream& out, const Rect2D<T> &rect) {
        out << "GRect(" << rect.position.x << ", " << rect.position.y << ", " << rect.size.width << ", " << rect.size.height << ");";
        return out;
    }

    template <class T>
    const GRect<T> GRect<T>::ZERO{ 0, 0, 0, 0 };
    template <class T>
    const GRect<T> GRect<T>::INF{ 0, 0, ::std::numeric_limits<T>::infinity(), ::std::numeric_limits<T>::infinity() };

}
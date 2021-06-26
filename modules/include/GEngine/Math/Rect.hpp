#pragma once

#include <MiniKit/MiniKit.hpp>

namespace GEngine::Math {

    using ::MiniKit::Graphics::Rect2D;

    template<class T>
    struct Rect {
        union {
            struct {
                T x;
                T y;
                T width;
                T height;
            };
            Rect2D<T> rect;
        };

        /*!
         * Default Constructor of 2D Rectangle with default position and size equal zero.
         */
        Rect() : Rect(0, 0, 0, 0) {}
        /*!
         * A 2D Rectangle Constructor with 4 params.
         * @param rectLeft - define X coord of left top point (position of rectangle)
         * @param rectTop - define Y coord of left top point (position of rectangle)
         * @param rectWidth - define width of rect (size of  rectangle)
         * @param rectHeight - define height of rect (size of  rectangle)
         */
        Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight)
                : x(rectLeft)
                , y(rectTop)
                , width(rectWidth)
                , height(rectHeight) {
        }
        /*!
         * A 2D Rectangle Constructor with 2 params.
         * @param position - Vector that defines X and Y coords of left top point of rectangle
         * @param size - Vector that defines width and height of rectangle
         */
        Rect(const Vector2D<T> &position, const Vector2D<T> &size)
                : position(position)
                , size(size) {}

        /*!
         * Function for set upping new position of rectangle
         * @param position - Vector that defines X and Y coords of left top point of rectangle
         */
        void setPosition(const Vector2D<T> &position) {
            this->position = position;
        }
        /*!
         * Function for set upping new size of rectangle
         * @param size - Vector that defines width and height of rectangle
         */
        void setSize(const Vector2D<T> &size) {
            this->size = size;
        }
        /*!
         * Const function for getting position of rectangle
         * @return Vector position of rectangle
         */
        Vector2D<T> getPosition() const noexcept {
            return position;
        }
        /*!
         * Const function for getting size of rectangle
         * @return Vector size of rectangle
         */
        Vector2D<T> getSize() const noexcept {
            return size;
        }

        /*!
         * Function for getting position of rectangle
         * @return Vector position of rectangle
         */
        Vector2D<T> &getPosition() noexcept {
            return position;
        }
        /*!
         * Function for getting size of rectangle
         * @return Vector size of rectangle
         */
        Vector2D<T> &getSize() noexcept {
            return size;
        }

        /*!
         * Function for getting position of point in center of the rectangle
         * @return Vector position of rectangle
         */
        Vector2D<T> getCenter() const {
            return {x + width / 2, y + height / 2 };
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
            return x < x && x + width > x && y < y && y + height > y;
        }

        /*!
         * Check if a point is inside the rectangle's area.
         * This check is non-inclusive. If the point lies on the edge of the rectangle, this function will return false.
         * @tparam T - template param (int, float, double etc.)
         * @param point - point to test
         * @return true if the point is inside, false otherwise
         */
        bool contains(const Vector2D<T> &point) const {
            return contains(point.x, point.y);
        }

        /*!
         * Check the intersection between two rectangles.
         * @param rectangle - Rectangle to test
         * @return true if rectangles overlap, false otherwise
         */
        bool intersects(const Rect<T> &rectangle) const {
            const auto &rightBottomPoint = position + size;
            const auto &rectRightBottomPoint = rectangle.position + rectangle.size;

            // If one rectangle is on left side of other
            if (x >= rectRightBottomPoint.x || rectangle.x >= rightBottomPoint.x) {
                return false;
            }
            // If one rectangle is above other
            if (y >= rectRightBottomPoint.y || rectangle.y >= rightBottomPoint.y) {
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
        bool intersects(const Rect<T> &rectangle, Rect<U> &overlap) const {
            if (intersects(rectangle)) {
                overlap.x = (x > rectangle.x)
                            ? x
                            : rectangle.x;
                overlap.y = (y > rectangle.y)
                            ? y
                            : rectangle.y;

                overlap.width = (x + width > rectangle.x + rectangle.width)
                                ? rectangle.x + rectangle.width - x - overlap.x
                                : x + width - rectangle.x - overlap.x;
                overlap.height = (y + height > rectangle.y + rectangle.height)
                                 ? rectangle.y + rectangle.height - y - overlap.y
                                 : y + height - rectangle.y - overlap.y;

                overlap.setPosition({overlap.x, overlap.y});
                overlap.setSize({overlap.width, overlap.height});

                return true;
            }
            return false;
        }
    };

    using IntRect = Rect<int32_t>;
    using UIntRect = Rect<uint32_t>;
    using FloatRect = Rect<float>;
    using DoubleRect = Rect<double>;

    /*!
     * Overload of binary operator ==.
     * This operator compares strict equality between two rectangles.
     * @tparam T - template param (int, float, double etc.)
     * @param left - Left operand (a rectangle)
     * @param right - Right operand (a rectangle)
     * @return true if left is equal to right
     */
    template <class T>
    bool operator==(const Rect<T> &left, const Rect<T> &right) {
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
    bool operator!=(const Rect<T> &left, const Rect<T> &right) {
        return !operator==(left, right);
    }

}
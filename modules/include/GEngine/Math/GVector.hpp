#pragma once

#include <MiniKit/MiniKit.hpp>

#include <iostream>

namespace GEngine::Math {

    using ::MiniKit::Graphics::Vector2D;

    template<class T>
    struct GVector : Vector2D<T> {

        GVector() : Vector2D<T>{ 0, 0 } {};
        GVector(T x, T y) : Vector2D<T>{ x, y } {};
        GVector(const Vector2D<T> &data) : Vector2D<T>{ data.x, data.y } {};

        const T *Data() const {
            return &this->x;
        }

        T *Data() {
            return &this->x;
        }

        float Length() const {
            return sqrt(this->x * this->x + this->y * this->y);
        }

        GVector &operator=(const Vector2D<T> &rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
            return *this;
        }
        GVector &operator=(const std::initializer_list<T>& lst) {
            if (lst.size() < 2)
                throw ::std::invalid_argument("Initializer list has not enough params for GVector construction.");
            this->x = *lst.begin();
            this->y = *(lst.begin() + 1);
            return *this;
        }

        bool operator==(const Vector2D<T> &rhs) {
            return this->x == rhs.x && this->y == rhs.y;
        }

        bool operator!=(const Vector2D<T> &rhs) {
            return !operator==(rhs);
        }

        GVector operator+(const Vector2D<T> &rhs) {
            return GVector<T>(this->x + rhs.x, this->y + rhs.y);
        }

        GVector operator-(const Vector2D<T> &rhs) {
            return GVector<T>(this->x - rhs.x, this->y - rhs.y);
        }

        GVector operator-() {
            return GVector<T>(-this->x, -this->y);
        }

        GVector operator*(T rhs) {
            return GVector<T>(this->x * rhs, this->y * rhs);
        }

        GVector operator*(const Vector2D<T> &rhs) {
            return GVector<T>(this->x * rhs.x, this->y * rhs.y);
        }

        GVector operator/(T rhs) {
            return GVector<T>(this->x / rhs, this->y / rhs);
        }

        GVector operator/(const Vector2D<T> &rhs) {
            return GVector<T>(this->x / rhs.x, this->y / rhs.y);
        }

        GVector &operator+=(const Vector2D<T> &rhs) {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }

        GVector &operator-=(const Vector2D<T> &rhs) {
            this->x -= rhs.x;
            this->y -= rhs.y;
            return *this;
        }

        GVector &operator*=(T rhs) {
            this->x *= rhs;
            this->y *= rhs;
            return *this;
        }

        GVector &operator/=(T rhs) {
            this->x /= rhs;
            this->y /= rhs;
            return *this;
        }


        GVector &operator*=(const Vector2D<T> &rhs) {
            this->x *= rhs.x;
            this->y *= rhs.y;
            return *this;
        }

        GVector &operator/=(const Vector2D<T> &rhs) {
            this->x /= rhs.x;
            this->y /= rhs.y;
            return *this;
        }

        static const GVector<T> ZERO;
        static const GVector<T> LEFT;
        static const GVector<T> RIGHT;
        static const GVector<T> UP;
        static const GVector<T> DOWN;
        static const GVector<T> ONE;

    };

    using Vector2i = GVector<int32_t>;
    using Vector2u = GVector<uint32_t>;
    using Vector2f = GVector<float>;
    using Vector2d = GVector<double>;

    /*!
     *  Overload of binary operator !=.
     *  This operator compares strict difference between two vectors.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return true if left is not equal to right
     */
    template<class T>
    bool operator!=(const Vector2D<T> &left, const Vector2D<T> &right) {
        return left.x != right.x || left.y != right.y;
    }
    /*!
     *  Overload of binary operator ==.
     *  This operator compares strict equality between two vectors..
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return true if left is not equal to right
     */
    template<class T>
    bool operator==(const Vector2D<T> &left, const Vector2D<T> &right) {
        return !operator!=(left, right);
    }
    /*!
     * Overload of binary operator -=.
     * This operator performs a memberwise subtraction of both vectors, and assigns the result to left.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return Reference to left
     */
    template<class T>
    Vector2D<T> &operator-=(Vector2D<T> &left, const Vector2D<T> &right) {
        left.x -= right.x;
        left.y -= right.y;
        return left;
    }
    /*!
     * Overload of binary operator +=.
     * This operator performs a memberwise addition of both vectors, and assigns the result to left.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return Reference to left
     */
    template<class T>
    Vector2D<T> &operator+=(Vector2D<T> &left, const Vector2D<T> &right) {
        left.x += right.x;
        left.y += right.y;
        return left;
    }
    /*!
     * Overload of binary operator /=.
     * This operator performs a memberwise division by right, and assigns the result to left.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a scalar value)
     * @return Reference to left
     */
    template<class T>
    Vector2D<T> &operator/=(Vector2D<T> &left, T right) {
        left.x /= right;
        left.y /= right;
        return left;
    }
    /*!
     * Overload of binary operator *=.
     * This operator performs a memberwise multiplication of vector and a scalar, and assigns the result to left.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a scalar value)
     * @return Reference to left
     */
    template<class T>
    Vector2D<T> &operator*=(Vector2D<T> &left, T right) {
        left.x *= right;
        left.y *= right;
        return left;
    }
    /*!
     * Overload of binary operator *=.
     * This operator performs a memberwise multiplication of both vectors, and assigns the result to left.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return Reference to left
     */
    template<class T>
    Vector2D<T> &operator*=(Vector2D<T> &left, const Vector2D<T> &right) {
        left.x *= right.x;
        left.y *= right.y;
        return left;
    }
    /*!
     * Overload of unary operator -.
     * @param right - Vector to negate
     * @return Memberwise opposite of the vector
     */
    template<class T>
    Vector2D<T> operator-(const Vector2D<T> &right) {
        return {-right.x, -right.y};
    }
    /*!
     * Overload of binary operator -.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return Memberwise subtraction of both vectors
     */
    template<class T>
    Vector2D<T> operator-(const Vector2D<T> &left, const Vector2D<T> &right) {
        return {left.x - right.x, left.y - right.y};
    }
    /*!
     * Overload of binary operator +.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a vector)
     * @return Memberwise addition of both vectors
     */
    template<class T>
    Vector2D<T> operator+(const Vector2D<T> &left, const Vector2D<T> &right) {
        return {left.x + right.x, left.y + right.y};
    }
    /*!
     * Overload of binary operator *.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a scalar value)
     * @return Memberwise multiplication of both vectors
     */
    template<class T>
    Vector2D<T> operator*(const Vector2D<T> &left, T right) {
        return {left.x * right, left.y * right};
    }
    /*!
     * Overload of binary operator *.
     * @param left - Left operand (a scalar value)
     * @param right - Right operand (a vector)
     * @return Memberwise multiplication of both vectors
     */
    template<class T>
    Vector2D<T> operator*(T left, const Vector2D<T> &right) {
        return {left * right.x, left * right.y};
    }
    /*!
     * Overload of binary operator /.
     * @param left - Left operand (a vector)
     * @param right - Right operand (a scalar value)
     * @return Memberwise division by right
     */
    template<class T>
    Vector2D<T> operator/(const Vector2D<T> &left, T right) {
        return {left.x / right, left.y / right};
    }

    template<class T>
    std::ostream& operator<<(std::ostream& out, const Vector2D<T> &vector) {
        out << "GVector(" << vector.x << ", " << vector.y << ");";
        return out;
    }

    template <class T>
    const GVector<T> GVector<T>::ZERO{ 0, 0 };
    template <class T>
    const GVector<T> GVector<T>::ONE{ 1, 1 };
    template <class T>
    const GVector<T> GVector<T>::DOWN{ 0, -1 };
    template <class T>
    const GVector<T> GVector<T>::UP{ 0, 1 };
    template <class T>
    const GVector<T> GVector<T>::LEFT{ -1, 0 };
    template <class T>
    const GVector<T> GVector<T>::RIGHT{ 1, 0 };
}

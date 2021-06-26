#pragma once

#include <MiniKit/MiniKit.hpp>

namespace GEngine::Math {

    using ::MiniKit::Graphics::Vector2D;
    using Vector2i = ::MiniKit::Graphics::int2;
    using Vector2u = ::MiniKit::Graphics::uint2;
    using Vector2f = ::MiniKit::Graphics::float2;
    using Vector2d = ::MiniKit::Graphics::double2;

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
}

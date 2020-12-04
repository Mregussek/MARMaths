/**
 *        MARMaths - open source computing library for MAREngine
 * Copyright (C) 2020-present Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
**/


#ifndef MAR_MATH_MAT_4_H
#define MAR_MATH_MAT_4_H 


#include "../maths.h"


namespace mar {
    namespace maths {

        struct vec3;
        struct vec4;


        /*
        mat4 is a structure with only one member - float array of 16 elements.
        It allows user to calculate basic matrices, such translation, rotation scale.
        Also implemented are projection matrices (orthographic and perspective) and view
        matrix (lookAt). Multiplication operator is overloaded, so feel free to use it.
            
        column major is used here, cause OpenGL is using it! mat4[row + col * 4]
        */
        struct mat4 {
            
            // -----------------------------------------------------
            // Float array, that contains data of 4x4 matrix   
            // ----------------------------------------------------- 
            float elements[4 * 4];                           
            
            // Default constructor for 4x4 matrix. Initialized all elements to 0.f.
            mat4();

            /*
            Constructor, that allows user to create specified diagonal.

                \param diagonal - value, to specify for diagonal
            */
            mat4(float diagonal);

            /*
            Returns selected column of 4x4 matrix in vec4 form.

                \param index - index of column
                \return vec4 - vector, that contains data
            */
            vec4 getColumn(size_t index) const;

            /*
            Returns selected row of 4x4 matrix in vec4 form.

                \param index - index of row
                \return vec4 - vector, that contains data
            */
            vec4 getRow(size_t index) const;

            /*
            Static method to create identity matrix. It simply calls mat4(1.f) constructor and returns it.

                \return mat4 - identity matrix with 1.f as diagonal
            */
            static mat4 identity();

            /*
            Multiplication method of 2 matrices (*this matrix and given mat4).

                \param other - matrix to multiply with *this
                \return mat4 - result of multiplication
            */
            mat4 multiply(const mat4& other) const;

            /*
            Multiplication method of *this matrix and given vec4.

                \param other - vec4 to multiply with *this
                \return vec4 - result of multiplication
            */
            vec4 multiply(const vec4& other) const;

            /*
            Get Projection Matrix - Orthographic with given parameters. Usually used in 2D.

                \param left - distance left
                \param right - distance right
                \param top - distance up
                \param bottom - distance down
                \param near - where start "seeing"
                \param far - where stop "seeing"
                \return mat4 - created orthographic mat4
            */
            static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
            
            /*
            Get Projection Matrix - Perspective with given parameters. Usually used in 3D.

                \param fov - Fielf Of View
                \param aspectRation
                \param near - where start "seeing"
                \param far - where stop "seeing"
                \return mat4 - created perspective mat4
            */
            static mat4 perspective(float fov, float aspectRatio, float near, float far);

            /*
            Get lookAt matrix - View Matrix with given parameters.

                \param eye - defines positions of view (camera)
                \param center - defines place, where the camera is looking
                \param up - specifies the up direction of the camera
                \return mat4 - created lookAt matrix
            */
            static mat4 lookAt(vec3 eye, vec3 center, vec3 y);

            /*
            Get Translation matrix specified for new position.

                \param trans - where the object must be have its center
                \return mat4 - created translation matrix
            */
            static mat4 translation(vec3 trans);

            /*
            Get Rotation matrix with specified angle and axis. Angle must be given in radians! 
            Axis is vec3, where each its value specifies axis. vec3.x equal to 1 says, that it will be rotated 
            around x-axis, vec3.y = 1 around y-axis and vec3.z = 1 around z-axis.

                \param angle - angle given in radians
                \param axis - vec3, which specifies rotation axis
                \return mat4 - created rotation matrix
            */
            static mat4 rotation(float angle, vec3 axis);

            /*
            Get Scale matrix with specified coefficients. Given paramater is vec3, it says 
            that every vertice must be multiplied with it. If you want scale object only in 
            x-axis pass vec3(x, 1.f, 1.f), where x is other than 1.f.

                \param scal - vec3, which specifies scale coefficients
                \return mat4 - created scale matrix
            */
            static mat4 scale(vec3 scal);

            /*
            Decomposes a model matrix to translations, rotation and scale components.

                \param transform - transform which will be decomposed
                \param translation - reference to which decomposed translation will be written
                \param rotation - reference to which decomposed rotation will be written
                \param scale - reference to which decomposed scale will be written
                \return decomposed - True if correctly decomposed matrix
            */
            static void decompose(const mat4& transform, vec3& translation, vec3& rotation, vec3& scale);

            /*
            Decomposes a model matrix to translations, rotation and scale components.

               \param transform - transform which will be decomposed
               \param translation - reference to which decomposed translation will be written
               \param rotation - reference to which decomposed rotation will be written
               \param scale - reference to which decomposed scale will be written
               \return decomposed - True if correctly decomposed matrix
           */
            void decompose(vec3& translation, vec3& rotation, vec3& scale) const;

            /*
            Get inverse matrix of given matrix as parameter. If determinant is equal to 0, 
            debug break is called and application stops.

                \param m - the matrix we'll count the inverse of
                \return mat4 - calculated inverse matrix
            */
            static mat4 inverse(const mat4& m);

            /*
            Get value pointer to first matrix element. Used especially in shaders.
                
                \param matrices - vector of matrices
                \return const float* - pointer to first value
            */
            static const float* value_ptr(const std::vector<mat4>& matrices);

            /*
            Get value pointer to first matrix element. Used especially in shaders.

                \param matrix4x4
                \return const float* - pointer to first value
            */
            static const float* value_ptr(const mat4& matrix4x4);

            /*
            Get value pointer to first matrix element. Used especially in shaders.

                \param matrix4x4
                \return float* - pointer to first value, which you can modify
            */
            static float* value_ptr_nonconst(mat4& matrix4x4);

            /*
            Get value pointer to first matrix element. Used especially in shaders.

                \return const float* - pointer to first value
            */
            const float* value_ptr() const;

            /*
            Get value pointer to first matrix element. Used especially in shaders.

                \return float* - pointer to first value, which you can modify
            */
            float* value_ptr_nonconst();

            /*
            Overloaded multiplication operator. Says that, matrix on the left and matrix on 
            the right must be multiplied with each other.

                \param left - matrix on the left side, before * operator
                \param right - matrix on the right side, after * operator
                \return mat4 - matrix 4x4 as a result of this multiplication
            */
            friend mat4 operator*(mat4 left, const mat4& right);

            /*
            Overloaded *= multiplication operator. Says that matrix on the left side is 
            *this and its given paramater is on the right side.

                \param other - matrix after *= operator
                \return mat4 - calculated matrix of (*this) * other
            */
            mat4 operator*=(const mat4& other);

            /*
            Overloaded * multiplication operator. Says that, matrix on the left and vec4 on 
            the right must be multiplied with each other.

                \param left - matrix on the left side, before * operator
                \param right - vec4 on the right side, after * operator
                \return vec4 - 4-dimensional vector as a result of this multiplication
            */
            friend vec4 operator*(mat4 left, const vec4& right);

            /*
            Overloaded *= multiplication operator. Says that matrix on the left side is 
            *this and its given paramater is on the right side.

                \param other - matrix after *= operator
                \return mat4 - calculated matrix of (*this) * other
            */
            vec4 operator*=(const vec4& other);

            /*
            Overloaded [] operator, so that we have ability to call mat4[index], which returns 
            mat4.elements[index]. This is version for read-only method, so returns const value.

                \param index - index of elements
                \return const elements[index]
            */
            const float& operator[](unsigned int index) const;

            /*
            Overloaded [] operator, so that we have ability to call mat4[index], which returns 
            mat4.elements[index]. This overloaded operator can write to specified value.

                \param index - index of elements
                \return elements[index]
            */
            float& operator[](unsigned int index);

        };

} }

#endif // !MAR_MATH_MAT_4_H


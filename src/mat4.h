/***********************************************************************
* @internal @copyright
*
*        MARMaths - open source computing library for MAREngine
*
* Copyright (C) 2020-present Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
* All rights reserved.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
************************************************************************/


#ifndef MAR_MATH_MAT_4_H
#define MAR_MATH_MAT_4_H 


#include "maths.h"


namespace marengine::maths {

    struct vec3;
    struct vec4;
    
    
    /**
     * @struct mat4 mat4.h "mat4/mat4.h"
     * @brief mat4 is a structure with only one member - float array of 16 elements.
     * It allows user to calculate basic matrices, such translation, rotation scale.
     * Also implemented are projection matrices (orthographic and perspective) and view
     * matrix (lookAt). Multiplication operator is overloaded, so feel free to use it.
     * 
     * @warning column major is used here, cause OpenGL is using it! mat4[row + col * 4]
     * +                                                                       +
     * | mat4[0 + 0 * 4] , mat4[0 + 1 * 4] , mat4[0 + 2 * 4] , mat4[0 + 3 * 4] |
     * | mat4[1 + 0 * 4] , mat4[1 + 1 * 4] , mat4[1 + 2 * 4] , mat4[1 + 3 * 4] |
     * | mat4[2 + 0 * 4] , mat4[2 + 1 * 4] , mat4[2 + 2 * 4] , mat4[2 + 3 * 4] |
     * | mat4[3 + 0 * 4] , mat4[3 + 1 * 4] , mat4[3 + 2 * 4] , mat4[3 + 3 * 4] |
     * +                                                                       +
     */
    struct mat4 {
        
        float elements[4 * 4]; ///  Float array, that contains data of 4x4 matrix   

        /// \brief Default constructor for 4x4 matrix. Initializes all elements to 0.f.
        mat4();
    
        /**
         * \brief Constructor, that allows user to create identity mat4 with specified diagonal.
         * \param diagonal diagonal value
         */
        mat4(float diagonal);
    
        /**
         * \brief Returns selected column of 4x4 matrix in vec4 form.
         * Make sure, that index is in range <0;3>. Method won't check that!
         * \param index index of column <0;3>
         * \return vector, that contains the whole column in vec4 format
         */
        vec4 getColumn4(size_t index) const;
    
        /**
         * \brief Returns selected column of 4x4 matrix in vec3 form, without the last value.
         * Make sure, that index is in range <0;3>. Method won't check that!
         * \param index index of column <0;3>
         * \return vector, that contains the whole column in vec3 format (without last row value)
         */
        vec3 getColumn3(size_t index) const;
    
        /**
         * \brief Returns selected row of 4x4 matrix in vec4 form.
         * Make sure, that index is in range <0;3>. Method won't check that!
         * \param index index of row <0;3>
         * \return vector, that contains the whole row in vec4 format
         */
        vec4 getRow4(size_t index) const;
    
        /**
         * \brief Returns selected row of 4x4 matrix in vec3 form, without last value.
         * Make sure, that index is in range <0;3>. Method won't check that!
         * \param index index of row <0;3>
         * \return vector, that contains the whole row in vec3 format (without last column value)
         */
        vec3 getRow3(size_t index) const;
    
        /**
         * \brief Static method to create identity matrix. It simply calls mat4(1.f) constructor and returns it.
         * \return identity matrix with 1.f as diagonal
         */
        static mat4 identity();
    
        /**
         * \brief Multiplication method of 2 matrices (*this matrix and given mat4).
         * \param other matrix, that is multiplied with *this
         * \return result of two matrices multiplication (which is another mat4)
         */
        mat4 multiply(const mat4& other) const;

        /**
         * \brief Multiplication method of *this matrix and given vec4.
         * \param other vec4 to multiply with *this
         * \return result of mat4 and vec4 multiplication (which is vec4)
         */
        vec4 multiply(const vec4& other) const;
            
        /**
         * \brief Multiplication method of *this matrix and given float.
         * \param other float to multiply with *this
         * \return result of mat4 and float multiplication (which is mat4)
         */
        mat4 multiply(float other) const;

        /**
         * \brief Get Projection Matrix - Orthographic with given parameters. Usually used in 2D.
         * \param left distance left
         * \param right distance right
         * \param top distance up
         * \param bottom distance down
         * \param near where start "seeing"
         * \param far where stop "seeing"
         * \return created orthographic mat4
         */
        static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
        
        /**
         * \brief Get Projection Matrix - Perspective with given parameters. Usually used in 3D.
         * \param fov Fielf Of View
         * \param aspectRatio Aspect Ratio
         * \param near - where start "seeing"
         * \param far - where stop "seeing"
         * \return created perspective mat4
         */
        static mat4 perspective(float fov, float aspectRatio, float near, float far);

        /**
         * \brief Get lookAt matrix - View Matrix with given parameters.
         * \param eye defines positions of view (camera)
         * \param center defines place, where the camera is looking
         * \param y specifies the up direction of the camera
         * \return  created lookAt matrix
         */
        static mat4 lookAt(vec3 eye, vec3 center, vec3 y);
    
        /**
         * \brief Get Translation matrix specified for new position.
         * \param trans where the object must be have its center
         * \return created translation matrix
         */
        static mat4 translation(vec3 trans);

        /**
         * \brief Get Rotation matrix with specified angle and axis. Angle must be given in radians!
         * Axis is vec3, where each its value specifies axis. vec3.x equal to 1 says,
         * that it will be rotated around x-axis, vec3.y = 1 around y-axis and vec3.z = 1 around z-axis.
         * \param angle angle given in radians
         * \param axis vec3, which specifies rotation axis
         * \return created rotation matrix
         */
        static mat4 rotation(float angle, vec3 axis);
    
        /**
         * \brief Get Scale matrix with specified coefficients. Given paramater is vec3, it says
         * that every vertice must be multiplied with it. If you want scale object only in
         * x-axis pass vec3(x, 1.f, 1.f), where x is other than 1.f.
         * \param scal vec3, which specifies scale coefficients
         * \return created scale matrix
         */
        static mat4 scale(vec3 scal);
    
        /**
         * Get inverse matrix of given matrix as parameter. If determinant is equal to 0,
         * debug break is called and application stops.
         * \param m the matrix we'll count the inverse of
         * \return calculated inverse matrix
         */
        static mat4 inverse(const mat4& m);
    
        /**
         * \brief Retrieves every column from matrix as vec4, then normalizes columns
         * and writes back data to matrix, so that every column is normalized.
         * \param transform transform, that we want to be orthonormalized
         */
        static void orthonormalize(mat4& transform);

        /**
         * \brief Retrieves every column from matrix as vec4, then normalizes columns
         * and writes back data to matrix, so that every column is normalized.
         */
        void orthonormalize();

        /*
        Decomposes a model matrix to translations, rotation and scale components.
    
            \param transform - transform which will be decomposed
            \param translation - reference to which decomposed translation will be written
            \param rotation(radians) - reference to which decomposed rotation will be written (radians)
            \param scale - reference to which decomposed scale will be written
        */
        static void decompose(const mat4& transform, vec3& translation, vec3& rotation, vec3& scale);
    
        /*
        Decomposes a model matrix to translations, rotation and scale components.
    
           \param transform - transform which will be decomposed
           \param translation - reference to which decomposed translation will be written
           \param rotation(radians) - reference to which decomposed rotation will be written(radians)
           \param scale - reference to which decomposed scale will be written
       */
        void decompose(vec3& translation, vec3& rotation, vec3& scale) const;
    
        /*
        Recomposes matrix from given parameters.
    
           \param transform - transform which will be decomposed
           \param translation - reference to which decomposed translation will be written
           \param rotation(degrees) - reference to which decomposed rotation will be written(degrees)
           \param scale - reference to which decomposed scale will be written
        */
        static void recompose(mat4& transform, const vec3& translation, const vec3& rotation, const vec3& scale);
    
        /*
        Recomposes matrix from given parameters.
    
           \param transform - transform which will be decomposed
           \param translation - reference to which decomposed translation will be written
           \param rotation(degrees) - reference to which decomposed rotation will be written(degrees)
           \param scale - reference to which decomposed scale will be written
        */
        void recompose(const vec3& translation, const vec3& rotation, const vec3& scale);
    
        /*
        Creates rotation matrix from given quanternion
    
            \param quat - vec3 that is quanternion
            \return mat4 - newly created rotation matrix
        */
        static mat4 rotationFromQuat(const vec3& quat);
    
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


}

#endif // !MAR_MATH_MAT_4_H


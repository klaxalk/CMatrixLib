/**
 * @file CMatrixLib.h
 * @author klaxalk
 * @brief header for CMatrixLib
 */
 
 /*! \mainpage Introduction to the CMatrixLib
 *
 * \section intro_sec Introduction
 *
 * The library was written to be used on a AVR u-controller.
 *
 * \section install_sec How To
 *
 * \subsection allocation Allocating the matrix
 *  
 * etc...
 */

#ifndef CMATRIXLIB_H_
#define CMATRIXLIB_H_

#include <stdint.h>
#include <string.h>

/**
 * @struct matrix_float
 * @brief Structure for a matrix.
 */
typedef struct {
	
	int16_t width; 		/**< matrix width */
	int16_t height;		/**< matrix height */
	float * data; 		/**< pointer to the data array */
	char * name; 		/**< pointer to the name array */
} matrix_float;

/**
 * @struct vector_float
 * 
 * @brief Structure for a vector.
 */
typedef struct {
	
	int16_t length; 	/**< vector length */
	int8_t orientation; /**< vector orientation */
	float * data; 		/**< pointer to the data array */
	char * name; 		/**< pointer to the name array */
} vector_float;

// allocation functions when using FreeRTOS
#if USED_PLATFORM == FREE_RTOS

/**
 * @brief used only with FreeRTOS
 * 
 * dynamically allocate the matrix using FreeRTOS pvPortMalloc
 * 
 * @param h matrix height
 * @param w matrix width
 */ 
matrix_float * matrix_float_alloc(const int16_t h, const int16_t w);

/**
 * @brief used only with FreeRTOS
 * 
 * dynamically allocate the vector using FreeRTOS pvPortMalloc
 * 
 * @param length the length of the vector
 * @param orientation the orientation of the vector
 */
vector_float * vector_float_alloc(const int16_t length, int8_t orientation);

/**
 * @brief used only with FreeRTOS
 * 
 * deallocate the matrix using FreeRTOS vPortFree
 * 
 * @param m pointer to the matrix
 */
void matrix_float_free(matrix_float * m);

/**
 * @brief used only with FreeRTOS
 * 
 * deallocate the vector using FreeRTOS vPortFree
 * 
 * @param v pointer to the vector
 */
void vector_float_free(vector_float * v);

#endif /* USED_PLATFORM == FREE_RTOS */

/**
 * @return answer is saved into b
 * 
 * @brief add two vectors, \b a+b
 * 
 * @param a vector
 * @param b vector
 */
void vector_float_add(vector_float * a, const vector_float * b);

/**
 * @return float value of inner product
 * 
 * @brief multiply two vectors by inner product, \b a*b 
 * 
 * @param a vector
 * @param b vector
 */
float vector_float_inner_product(const vector_float * a, const vector_float * b);

/**
 * @return the answer is written into C
 * 
 * @brief multiply two vectors by outer product, \b a*b
 * 
 * @param a vector
 * @param a vector
 * @param C matrix answer
 */
void vector_float_outer_product(const vector_float * a, const vector_float * b, matrix_float * C);

/**
 * @return the answer is written into a
 * 
 * @brief multiply a vector by a scalar, \b C*a
 * 
 * @param a vector
 * @param C a scalar constant
 */
void vector_float_times(vector_float * a, const float C);

/**
 * @return the answer is written into a
 * 
 * @brief copy one vector to another, \b a<-b
 * 
 * @param a vector to copy to
 * @param b vector to copy from
 */
void vector_float_copy(vector_float * a, const vector_float * b);

/**
 * @return the answer is written into v
 * 
 * @brief set the particular cell of the vector
 * 
 * @param v vector to set
 * @param pos position of the cell to set
 * @param value value to set
 */
void vector_float_set(vector_float * v, const int16_t pos, const float value);

/**
 * @brief set the vector to all zeros
 * 
 * @param v vector to set
 */
void vector_float_set_zero(vector_float * v);

/**
 * @brief get the particular cell of the vector
 * 
 * @param v vector
 * @param pos desired cell to get
 */
float vector_float_get(const vector_float * v, const int16_t pos);

/**
 * @brief set particular cell of the matrix
 * 
 * @param m matrix
 * @param h cell position <1, height>
 * @param w cell position <1, width>
 * @param value value to set
 */
void matrix_float_set(matrix_float * m, const int16_t h, const int16_t w, const float value);

/**
 * @brief get the particular cell of the matrix
 * 
 * @return float value of the cell
 * 
 * @param m matrix
 * @param h cell position <1, height>
 * @param w cell position <1, width>
 */
float matrix_float_get(const matrix_float * m, const int16_t h, const int16_t w);

/**
 * @brief transpose a matrix
 * 
 * @return output is written into C
 * 
 * @param a matrix to transpose
 * @param C matrix for saving the output
 */
void matrix_float_transpose(const matrix_float * a, matrix_float * C);

/**
 * @brief transpose a square matrix and replace the original one
 * 
 * @return output is written back into m
 * 
 * @param a matrix to transpose
 */
void matrix_float_transpose_square(matrix_float * m);

/**
 * @brief set all cells of matrix to a value
 * 
 * @return output is written back into m
 * 
 * @param m matrix to transpose
 * @param value value to set
 */
void matrix_float_set_all(matrix_float * m, const float value);

/**
 * @brief set all cells of a matrix to zero
 * 
 * @return output is written back into m
 * 
 * @param m matrix to transpose
 */
void matrix_float_set_zero(matrix_float * m);

/**
 * @brief set a matrix to the identity matrix
 * 
 * @return output is written back into m
 * 
 * @param m matrix to set
 */
void matrix_float_set_identity(matrix_float * m);

/**
 * @brief copy one matrix to another
 * 
 * @return output is written into a
 * 
 * @param a matrix to copy to
 * @param b matrix to copy from
 */
void matrix_float_copy(matrix_float * a, const matrix_float * b);

/**
 * @brief add two matrices, \b a+b
 * 
 * @return output is written into a
 * 
 * @param a first matrix 
 * @param b second matrix
 */
void matrix_float_add(matrix_float * a, const matrix_float *b);

/**
 * @brief subtract two matrices, \b a-b
 * 
 * @return output is written into a
 * 
 * @param a first matrix 
 * @param b second matrix
 */
void matrix_float_sub(matrix_float * a, const matrix_float *b);

/**
 * @brief get a particular row vector from a matrix
 * 
 * @return output is written into v
 * 
 * @param m matrix
 * @param v output vector
 * @param row number of the row <1, height>
 */
void matrix_float_get_row(const matrix_float * m, vector_float * v, const int16_t row);

/**
 * @brief get a particular column vector from a matrix
 * 
 * @return output is written into v
 * 
 * @param m matrix
 * @param v output vector
 * @param col number of the column <1, width>
 */
void matrix_float_get_col(const matrix_float * m, vector_float * v, const int16_t col);

/**
 * @brief multiply two matrices, \b a*b
 * 
 * @return output is written into C
 * 
 * @param a first matrix
 * @param b second matrix
 * @param C output matrix
 */
void matrix_float_mul(const matrix_float * a, const matrix_float * b, matrix_float * C);

/**
 * @brief multiply a matrix by a transposed matrix, \b a*b'
 * 
 * @return output is written into C
 * 
 * @param a first matrix
 * @param b second matrix, will be transposed
 * @param C output matrix
 */
void matrix_float_mul_trans(const matrix_float * a, const matrix_float * b, matrix_float * C);

/**
 * @brief multiply a matrix by a scalar, \b a*C
 * 
 * @return output is written back into a
 * 
 * @param a matrix to multiply
 * @param C scalar value
 */
void matrix_float_times(matrix_float * a, const float C);

/**
 * @brief multiply matrix by vector (right product), \b a*v
 * 
 * @return output is written into C
 * 
 * @param m matrix to multiply
 * @param v vector to multiply by
 * @param C output vector
 */
void matrix_float_mul_vec_right(const matrix_float * m, const vector_float * v, vector_float * C);

/**
 * @brief multiply matrix by vector (left product), \b v*a
 * 
 * @return output is written into C
 * 
 * @param m matrix to multiply
 * @param v vector to multiply by
 * @param C output vector
 */
void matrix_float_mul_vec_left(const matrix_float * m, const vector_float * v, vector_float * C);

/**
 * @brief compute a determinant of a matrix
 * 
 * Determinant is calculated by applying GEM. When to bottom diagonal matrix is 0, the main diagonal is multiplied.
 * 
 * @return float value of the determinant
 * 
 * @param a matrix
 */
float matrix_float_determinant(const matrix_float * a);

/**
 * @brief compute the inverse matrix
 * 
 * The inverse matrix is calculated by the naive way - GEM is used to transform an identity matrix to the inverse matrix.
 * 
 * @return int 1 if inversion exists, 0 if it doesn't. The output is written back to a.
 * 
 * @param a matrix
 */
int matrix_float_inverse(matrix_float * a);

#endif /* CMATRIXLIB_H_ */
#ifndef CDEFS_H
#define CDEFS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

/* 
 * Mathematical constant
 */ 
# define MATH_PI           3.14159265358979323846  /* pi */
# define MATH_PI_2         1.57079632679489661923  /* pi/2 */
# define MATH_PI_4         0.78539816339744830962  /* pi/4 */
# define MATH_1_PI         0.31830988618379067154  /* 1/pi */
# define MATH_2_PI         0.63661977236758134308  /* 2/pi */
# define MATH_2PI	    (2.0*MATH_PI)          /* 2*pi */
# define MATH_4PI	    (4.0*MATH_PI)          /* 4*pi */
# define MATH_SQRT2PI	    2.506628274631 /* (2*pi)^(1/2) */
# define MATH_1_SQRT2PI	    0.39894228040143 /* (2*pi)^(-1/2) */
# define MATH_E            2.7182818284590452354   /* e */
# define MATH_LOG2E        1.4426950408889634074   /* log_2 e */
# define MATH_LOG10E       0.43429448190325182765  /* log_10 e */
# define MATH_LN2          0.69314718055994530942  /* log_e 2 */
# define MATH_LN10         2.30258509299404568402  /* log_e 10 */
# define MATH_RAD2DEG	    (180.0*MATH_1_PI)     
# define MATH_DEG2RAD	    (0.00555555555556 *MATH_PI)   /* pi/180 */  
# define MATH_HUGE_NUMBER_DBL    1.0e300  /* practically infinity */
# define MATH_TINY_NUMBER_DBL    1.0e-300 /* practically 0 */
# define MATH_HUGE_NUMBER_float    1.0e30  /* practically infinity */
# define MATH_TINY_NUMBER_float    1.0e-30 /* practically 0 */
# define MATH_LARGE_NUMBER_DBL    1.0e200  /* practically infinity */
# define MATH_SMALL_NUMBER_DBL    1.0e-200 /* practically 0 */
# define MATH_LARGE_NUMBER_float    1.0e20  /* practically infinity */
# define MATH_SMALL_NUMBER_float    1.0e-20 /* practically 0 */


#define ALLOC_MEM(type,n) ( type *)malloc((size_t) (n)*sizeof( type))
#define ALLOC_MEM0(type,n) ( type *)calloc((size_t) (n),sizeof( type))
#define ALLOC_MEM1(type) ( type *) calloc((size_t) 1, sizeof( type))
#define REALLOC_MEM(pointer,type,N) ( type *) realloc((void *)(pointer),(size_t) ((N)*sizeof( type)))
#define FREE_MEM(pnt) if(pnt) {free(pnt);pnt=0;}
#define ERROR_MESSAGE(msg) fprintf(stderr,"ERROR: %s src: %s line:%d\n",msg,__FILE__,__LINE__)
#endif

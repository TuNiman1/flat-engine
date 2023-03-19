#pragma once

#define FL_SIMD_SSE

#ifdef FL_SIMD_SSE
#include <xmmintrin.h>

#define FL_SIMD_REQUIRED_ALIGNMENT 16

#define FL_SIMD_ALIGNED_MALLOC(size, alignment) _mm_malloc(size, alignment)
#define FL_SIMD_ALIGNED_FREE(block) _mm_free(block)

#define FL_SIMD_MALLOC(size) FL_SIMD_ALIGNED_MALLOC(size, FL_SIMD_REQUIRED_ALIGNMENT)
#define FL_SIMD_FREE(block) FL_SIMD_ALIGNED_FREE(block)


#endif


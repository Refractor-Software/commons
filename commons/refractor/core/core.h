#ifndef     REFRACTOR_CORE_H
#define     REFRACTOR_CORE_H

#if defined(__clang__)
    #define R_COMPILER_CLANG
#elif defined(_MSC_VER)
    #define R_COMPILER_CL
#elif defined(__GNUC__)
    #define R_COMPILER_GCC
#else
    #error "Unsupported compiler"
#endif

#if defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
    #define R_PLATFORM_WIN
#elif defined(__linux__) || defined(__gnu_linux__)
    #define R_PLATFORM_LNX
#else
    #error "Only 64-bit Windows and GNU/Linux are supported"
#endif

#if !defined(__cplusplus)
    #define R_TRUE      1
    #define R_FALSE     0
    #define R_NULLPTR   ((void*)0)
    #define R_EXTERN_C_BEGIN
    #define R_EXTERN_C_END
    #define R_NO_ARGS   void
#else /* defined(__cplusplus) */
#define R_TRUE      true
    #define R_FALSE     false
    #define R_NULLPTR   nullptr
    #define R_EXTERN_C_BEGIN    extern "C" {
    #define R_EXTERN_C_END      }
    #define R_NO_ARGS
#endif

#define R_NULL    0

#define R_CONCAT(a,b)   a ## b
#define R_MACRO_VAR(x)  R_CONCAT(x, __LINE__)

#define R_DEFER(start, end)     for (   \
    int R_MACRO_VAR(i_) = (start, 0);   \
    !R_MACRO_VAR(i_);                   \
    (R_MACRO_VAR(i_) += 1, end)         \

#define R_FWD_DECL(tp, x)   typedef tp x x

#if defined(R_COMPILER_CL)
    #define R_CL_ALIGN(x) /* not yet implemented */
    #define R_GCC_ALIGN(X) /* blank */
#elif defined(R_COMPILER_CLANG) || defined(R_COMPILER_GCC)
    #define R_CL_ALIGN(x)  /* blank */
    #define R_GCC_ALIGN(x) __attribute__((aligned((x))))
#endif

#define R_RESTRICT __restrict

#if defined(R_PLATFORM_WIN)
#include "__detail/core_win64.h"
#elif defined(R_PLATFORM_LNX)
#include "__detail/gnulnx_core.h"
#endif

#endif  /*  REFRACTOR_CORE_H  */

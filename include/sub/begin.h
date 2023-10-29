#ifndef MCSL_BEGIN_H
#define MCSL_BEGIN_H

#ifdef __cplusplus
#define MCSL_CPP __cplusplus
#define MCSL_EXTERN_C_OPEN extern "C"{
#define MCSL_EXTERN_C_CLOSE }
#endif

#if defined(__GNUC__)
#define MCSL_COMP_GCC
#elif defined(__clang__)
#define MCSL_COMP_CLANG
#elif defined(__INTEL_COMPILER)
#define MCSL_COMP_INTEL
#else
#define MCSL_COMP_O
#endif

#if defined(__ANSI__) || defined (__STRICT_ANSI__)
#define MCSL_ANSI
#endif

#ifdef __ELF__
#define MCSL_ELF
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
#define MCSL_WIN
#include <winsock2.h>
#include <windows.h>
#define MCSL_ATTR(X) __declspec(X)
#else
#include <features.h>
#include <alloca.h>
#define MCSL_ATTR(X) __attribute__ ((X))
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include <limits.h>
#include <memory.h>

#if (UINTPTR_MAX == 0xffFFffFF)
#define MCSL_PLATFORM_32 /*32-bit platform*/
#elif (UINTPTR_MAX == 0xffFFffFFffFFffFF)
#define MCSL_PLATFORM_64 /*64-bit platform*/
#else
#define MCSL_PLATFORM_O /*other*/
#endif

#include "version.h"

#define MCSL_NOINLINE MCSL_ATTR (noinline)
#define MCSL_ALWAYS_INLINE MCSL_ATTR (always_inline) __inline__
#define MCSL_ALWAYS_INLINE_STATIC static MCSL_ALWAYS_INLINE
#define MCSL_ALWAYS_INLINE_EXTERN extern MCSL_ALWAYS_INLINE
#ifdef __NO_INLINE__
#define MCSL_INLINE
#define MCSL_INLINE_STATIC
#define MCSL_INLINE_EXTERN
#else
#define MCSL_INLINE MCSL_ALWAYS_INLINE
#define MCSL_INLINE_STATIC MCSL_ALWAYS_INLINE_STATIC
#define MCSL_INLINE_EXTERN MCSL_ALWAYS_INLINE_EXTERN
#endif

#define MCSL_COLD MCSL_ATTR (cold)
#define MCSL_HOT MCSL_ATTR (hot)
#define MCSL_WUR MCSL_ATTR (warn_unused_result)
#define MCSL_DEPRECATED MCSL_ATTR (deprecated)

#define MCSL_VIS_HIDDEN MCSL_ATTR (visibility("hidden"))
#define MCSL_VIS_INTERNAL MCSL_ATTR (visibility("internal"))
#define MCSL_VIS_DEFAULT MCSL_ATTR (visibility("default"))


#ifdef MCSL_ELF
#define MCSL_NOINIT MCSL_ATTR(noinit)
#else
#define MCSL_NOINIT
#endif

#ifdef MCSL_WIN
	#ifdef BUILD_LIB
	#define MCSL_PUBLIC MCSL_ATTR (dllexport)
	#else
	#define MCSL_PUBLIC MCSL_ATTR (dllimport)
	#endif
#define MCSL_LOCAL
#define MCSL_API_PUBLIC extern MCSL_PUBLIC
#define MCSL_API_LOCAL extern MCSL_LOCAL
#else
#define MCSL_PUBLIC MCSL_VIS_DEFAULT
#define MCSL_LOCAL MCSL_VIS_HIDDEN
#define MCSL_API_PUBLIC extern MCSL_PUBLIC
#define MCSL_API_LOCAL extern MCSL_LOCAL
#endif /*MCSL_WIN*/

#define MCSL_API MCSL_API_PUBLIC

#ifdef MCSL_CPP
#if (MCSL_CPP > 201103L)
#define MCSL_REG
#else
#define MCSL_REG register
#endif
#else
#define MCSL_REG register
#endif

#define MCSL_SWAP_NUM(X,Y) X = Y - X + (Y = X)
#define MCSL_SWAP_PTR(X,Y,T) X = (T)((uintptr_t)Y - (uintptr_t)X + (uintptr_t)(Y = X))

#if !defined(MCSL_CPP) && (!defined(__STDC_VERSION__) || !(__STDC_VERSION__ >= 199901L))
/**/
#define MCSL_CAN_GET_ARGS 0
#else
#define MCSL_CAN_GET_ARGS 1
#define MCSL_N_ARGS(...) \
	__MCSL_N_ARGS_(__VA_ARGS__,__MCSL_RSEQ_N())
#define __MCSL_N_ARGS_(...) \
	__MCSL_ARG_N(__VA_ARGS__)
#define __MCSL_ARG_N( \
	_1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
	_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
	_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
	_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
	_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
	_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
	_61,_62,_63,  N, ...) N
#define __MCSL_RSEQ_N() \
	63,62,61,60,                   \
	59,58,57,56,55,54,53,52,51,50, \
	49,48,47,46,45,44,43,42,41,40, \
	39,38,37,36,35,34,33,32,31,30, \
	29,28,27,26,25,24,23,22,21,20, \
	19,18,17,16,15,14,13,12,11,10, \
	9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#endif

#ifdef MCSL_CPP
namespace mcsl{}
#endif

#include "type.h"

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif

MCSL_API const int __mcsl_version_major;
MCSL_API const int __mcsl_version_minor;
MCSL_API const int __mcsl_version_micro;
MCSL_API const int __mcsl_version_build;
MCSL_API const int __mcsl_version_varian;

MCSL_API const cstring __mcsl_identity();
MCSL_API const cstring __mcsl_version();

#define mcsl_identity __mcsl_identity
#define mcsl_version __mcsl_version
#define mcsl_version_major __mcsl_version_major
#define mcsl_version_minor __mcsl_version_minor
#define mcsl_version_micro __mcsl_version_micro
#define mcsl_version_build __mcsl_version_build
#define mcsl_version_varian __mcsl_version_varian

#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#ifdef MCSL_COMP_CLANG
#pragma GCC diagnostic ignored "-Wunknown-attributes"
#pragma GCC diagnostic ignored "-Wnewline-eof"
#pragma GCC diagnostic ignored "-Wunsequenced"
#pragma GCC diagnostic ignored "-Wc99-extensions"
#endif

#endif /*MCSL_BEGIN_H*/

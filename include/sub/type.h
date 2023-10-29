#ifndef MCSL_BEGIN_H
#error "Never include sub/type.h directly"
#endif

#ifndef MCSL_TYPE_H
#define MCSL_TYPE_H

#include <ctype.h>

#define cstring char*

typedef int8_t _i8;
typedef uint8_t _u8;
typedef int16_t _i16;
typedef uint16_t _u16;
typedef int32_t _i32;
typedef uint32_t _u32;
typedef int64_t _i64;
typedef uint64_t _u64;

typedef float _f32;
typedef double _f64;
typedef long double _f128;

#define i8_digit_max 3
#define u8_digit_max 3
#define i16_digit_max 5
#define u16_digit_max 5
#define i32_digit_max 10
#define u32_digit_max 10
#define i64_digit_max 20 /*aslinya 19 tpi plus min*/
#define u64_digit_max 20

typedef const void* _mcsl_label;
#define mcsl_label __extension__ _mcsl_label
#define goto_mcsl_label(lbl) __extension__ ({goto *(lbl);})

#define i32_add_oflow(a,b,c) __builtin_sadd_overflow((a),(b),(c))
#define u32_add_oflow(a,b,c) __builtin_uadd_overflow((a),(b),(c))
#define i64_add_oflow(a,b,c) __builtin_saddl_overflow((a),(b),(c))
#define u64_add_oflow(a,b,c) __builtin_uaddl_overflow((a),(b),(c))
#define i32_sub_oflow(a,b,c) __builtin_ssub_overflow((a),(b),(c))
#define u32_sub_oflow(a,b,c) __builtin_usub_overflow((a),(b),(c))
#define i64_sub_oflow(a,b,c) __builtin_ssubl_overflow((a),(b),(c))
#define u64_sub_oflow(a,b,c) __builtin_usubl_overflow((a),(b),(c))
#define i32_mul_oflow(a,b,c) __builtin_smul_overflow((a),(b),(c))
#define u32_mul_oflow(a,b,c) __builtin_umul_overflow((a),(b),(c))
#define i64_mul_oflow(a,b,c) __builtin_smull_overflow((a),(b),(c))
#define u64_mul_oflow(a,b,c) __builtin_umull_overflow((a),(b),(c))
#define mcsl_int_add_oflow(a,b) __builtin_add_overflow_p((a), (b), (__typeof__ ((a) + (b))) 0)
#define mcsl_int_sub_oflow(a,b) __builtin_sub_overflow_p((a), (b), (__typeof__ ((a) + (b))) 0)
#define mcsl_int_mul_oflow(a,b) __builtin_mul_overflow_p((a), (b), (__typeof__ ((a) + (b))) 0)

#define mcsl_leni(_a)\
(__extension__({\
	MCSL_REG _i64 __a = (_i64)(_a);\
	if (__a < 0) __a = -__a;\
	((__a) < 10L) ? 1 :\
	((__a) < 100L) ? 2 :\
	((__a) < 1000L) ? 3 :\
	((__a) < 10000L) ? 4 :\
	((__a) < 100000L) ? 5 :\
	((__a) < 1000000L) ? 6 :\
	((__a) < 10000000L) ? 7 :\
	((__a) < 100000000L) ? 8 :\
	((__a) < 1000000000L) ? 9 :\
	((__a) < 10000000000L) ? 0xa :\
	((__a) < 100000000000L) ? 0xb :\
	((__a) < 1000000000000L) ? 0xc :\
	((__a) < 10000000000000L) ? 0xd :\
	((__a) < 100000000000000L) ? 0xe :\
	((__a) < 1000000000000000L) ? 0xf :\
	((__a) < 10000000000000000L) ? 0x10 :\
	((__a) < 100000000000000000L) ? 0x11 :\
	((__a) < 1000000000000000000L) ? 0x12 :\
	0x13;\
}))
#define mcsl_lenu(_a)\
(__extension__({\
	MCSL_REG _u64 __a = (_u64)(_a);\
	((__a) < 10UL) ? 1 :\
	((__a) < 100UL) ? 2 :\
	((__a) < 1000UL) ? 3 :\
	((__a) < 10000UL) ? 4 :\
	((__a) < 100000UL) ? 5 :\
	((__a) < 1000000UL) ? 6 :\
	((__a) < 10000000UL) ? 7 :\
	((__a) < 100000000UL) ? 8 :\
	((__a) < 1000000000UL) ? 9 :\
	((__a) < 10000000000UL) ? 0xa :\
	((__a) < 100000000000UL) ? 0xb :\
	((__a) < 1000000000000UL) ? 0xc :\
	((__a) < 10000000000000UL) ? 0xd :\
	((__a) < 100000000000000UL) ? 0xe :\
	((__a) < 1000000000000000UL) ? 0xf :\
	((__a) < 10000000000000000UL) ? 0x10 :\
	((__a) < 100000000000000000UL) ? 0x11 :\
	((__a) < 1000000000000000000UL) ? 0x12 :\
	((__a) < 10000000000000000000UL) ? 0x13 :\
	0x14;\
}))

#define mcsl_leni_min 1
#define mcsl_leni_max 0x13
#define mcsl_lenu_min 1
#define mcsl_lenu_max 0x14

#include <malloc.h>

#define mcsl_malloc __builtin_malloc
#define mcsl_calloc __builtin_calloc
#define mcsl_realloc __builtin_realloc
#define mcsl_free __builtin_free
#define mcsl_alloca __builtin_alloca
#define mcsl_memcpy __builtin_memcpy
#define mcsl_memmove __builtin_memmove
#define mcsl_memset __builtin_memset
#define mcsl_memcmp __builtin_memcmp
#define mcsl_memchr __builtin_memchr

#define mcsl_memalign memalign
#define mcsl_valloc valloc
#define mcsl_pvalloc pvalloc

#if defined(_GNU_SOURCE) || defined(__USE_GNU)
#define mcsl_memrchr memrchr
#endif

#define mcsl_memccpy memccpy
#define mcsl_mempcpy __builtin_mempcpy

#if defined(_GNU_SOURCE) || defined(__USE_GNU)
#define mcsl_rawmemchr rawmemchr
#else
#define mcsl_rawmemchr mcsl_strchr
#endif

#define mcsl_strcpy __builtin_strcpy
#define mcsl_strncpy __builtin_strncpy
#define mcsl_stpcpy __builtin_stpcpy
#define mcsl_stpncpy __builtin_stpncpy
#define mcsl_strcat __builtin_strcat
#define mcsl_strncat __builtin_strncat
#define mcsl_strcmp __builtin_strcmp
#define mcsl_strncmp __builtin_strncmp
#define mcsl_strcasecmp __builtin_strcasecmp
#define mcsl_strncasecmp __builtin_strncasecmp

#define mcsl_strchr __builtin_strchr

#define mcsl_strstr __builtin_strstr
#define mcsl_strrchr __builtin_strrchr
#define mcsl_strspn __builtin_strspn
#define mcsl_strcspn __builtin_strcspn
#define mcsl_strpbrk __builtin_strpbrk
#define mcsl_strlen __builtin_strlen

MCSL_INLINE_STATIC MCSL_WUR size_t mcsl_str_get_len(const cstring s){
	return
	#if defined(__USE_GNU) && !defined(ANDROID)
	(size_t)((size_t)(const cstring)mcsl_rawmemchr(s,'\0') - (size_t)s);
	#else
	mcsl_strlen(s);
	#endif
}

#if defined(__USE_GNU)
#define mcsl_strnlen __builtin_strnlen
#else
#define mcsl_strnlen strnlen
#endif

#define mcsl_stpcpy __builtin_stpcpy
#define mcsl_stpncpy __builtin_stpncpy
#define mcsl_strdup __builtin_strdup
#define mcsl_strndup __builtin_strndup
#define mcsl_strfmon __builtin_strfmon
#define mcsl_toascii __builtin_toascii
#define mcsl_isascii __builtin_isascii

#define tpcmp __builtin_types_compatible_p
#define mcsl_tpcmp __builtin_types_compatible_p

#define mcsl_assume_aligned __builtin_assume_aligned

#define mcsl_sin __builtin_sin
#define mcsl_sinf __builtin_sinf
#define mcsl_sinl __builtin_sinl
#define mcsl_cos __builtin_cos
#define mcsl_cosf __builtin_cosf
#define mcsl_cosl __builtin_cosl
#define mcsl_tan __builtin_tan
#define mcsl_tanf __builtin_tanf
#define mcsl_tanl __builtin_tanl

#define mcsl_asin __builtin_asin
#define mcsl_asinf __builtin_asinf
#define mcsl_asinl __builtin_asinl
#define mcsl_acos __builtin_acos
#define mcsl_acosf __builtin_acosf
#define mcsl_acosl __builtin_acosl
#define mcsl_atan __builtin_atan
#define mcsl_atanf __builtin_atanf
#define mcsl_atanl __builtin_atanl

#define mcsl_atan2 __builtin_atan2
#define mcsl_atan2f __builtin_atan2f
#define mcsl_atan2l __builtin_atan2l

#define mcsl_sinh __builtin_sinh
#define mcsl_sinhf __builtin_sinhf
#define mcsl_sinhl __builtin_sinhl
#define mcsl_cosh __builtin_cosh
#define mcsl_coshf __builtin_coshf
#define mcsl_coshl __builtin_coshl
#define mcsl_tanh __builtin_tanh
#define mcsl_tanhf __builtin_tanhf
#define mcsl_tanhl __builtin_tanhl

#define mcsl_asinh __builtin_asinh
#define mcsl_asinhf __builtin_asinhf
#define mcsl_asinhl __builtin_asinhl
#define mcsl_acosh __builtin_acosh
#define mcsl_acoshf __builtin_acoshf
#define mcsl_acoshl __builtin_acoshl
#define mcsl_atanh __builtin_atanh
#define mcsl_atanhf __builtin_atanhf
#define mcsl_atanhl __builtin_atanhl

#define mcsl_sincos __builtin_sincos
#define mcsl_sincosf __builtin_sincosf
#define mcsl_sincosl __builtin_sincosl

#define mcsl_fabs __builtin_fabs
#define mcsl_fabsf __builtin_fabsf
#define mcsl_fabsl __builtin_fabsl

#define mcsl_abs __builtin_abs
#define mcsl_labs __builtin_labs
#define mcsl_llabs __builtin_llabs

#define mcsl_imaxabs __builtin_imaxabs

#define mcsl_log __builtin_log
#define mcsl_logf __builtin_logf
#define mcsl_logl __builtin_logl

#define mcsl_log2 __builtin_log2
#define mcsl_log2f __builtin_log2f
#define mcsl_log2l __builtin_log2l

#define mcsl_log10 __builtin_log10
#define mcsl_log10f __builtin_log10f
#define mcsl_log10l __builtin_log10l

#define mcsl_ilogb __builtin_ilogb
#define mcsl_ilogbf __builtin_ilogbf
#define mcsl_ilogbl __builtin_ilogbl

#define mcsl_logb __builtin_logb
#define mcsl_logbf __builtin_logbf
#define mcsl_logbl __builtin_logbl

#define mcsl_log1p __builtin_log1p
#define mcsl_log1pf __builtin_log1pf
#define mcsl_log1pl __builtin_log1pl

#define mcsl_pow __builtin_pow
#define mcsl_powf __builtin_powf
#define mcsl_powl __builtin_powl

#define mcsl_pow10 __builtin_pow10
#define mcsl_pow10f __builtin_pow10f
#define mcsl_pow10l __builtin_pow10l

#define mcsl_sqrt __builtin_sqrt
#define mcsl_sqrtf __builtin_sqrtf
#define mcsl_sqrtl __builtin_sqrtl

#define mcsl_exp __builtin_exp
#define mcsl_expf __builtin_expf
#define mcsl_expl __builtin_expl

#define mcsl_exp2 __builtin_exp2
#define mcsl_exp2f __builtin_exp2f
#define mcsl_exp2l __builtin_exp2l

#define mcsl_exp10 __builtin_exp10
#define mcsl_exp10f __builtin_exp10f
#define mcsl_exp10l __builtin_exp10l

#define mcsl_expm1 __builtin_expm1
#define mcsl_expm1f __builtin_expm1f
#define mcsl_expm1l __builtin_expm1l

#define mcsl_frexp __builtin_frexp
#define mcsl_frexpf __builtin_frexpf
#define mcsl_frexpl __builtin_frexpl

#define mcsl_ldexp __builtin_ldexp
#define mcsl_ldexpf __builtin_ldexpf
#define mcsl_ldexpl __builtin_ldexpl

#define mcsl_erf __builtin_erf
#define mcsl_erff __builtin_erff
#define mcsl_erfl __builtin_erfl

#define mcsl_erfc __builtin_erfc
#define mcsl_erfcf __builtin_erfcf
#define mcsl_erfcl __builtin_erfcl

#define mcsl_ceil __builtin_ceil
#define mcsl_ceilf __builtin_ceilf
#define mcsl_ceill __builtin_ceill

#define mcsl_round __builtin_round
#define mcsl_roundf __builtin_roundf
#define mcsl_roundl __builtin_roundl

#define mcsl_lround __builtin_lround
#define mcsl_lroundf __builtin_lroundf
#define mcsl_lroundl __builtin_lroundl

#define mcsl_llround __builtin_llround
#define mcsl_llroundf __builtin_llroundf
#define mcsl_llroundl __builtin_llroundl

#define mcsl_floor __builtin_floor
#define mcsl_floorf __builtin_floorf
#define mcsl_floorl __builtin_floorl

#define mcsl_rint __builtin_rint
#define mcsl_rintf __builtin_rintf
#define mcsl_rintl __builtin_rintl

#define mcsl_lrint __builtin_lrint
#define mcsl_lrintf __builtin_lrintf
#define mcsl_lrintl __builtin_lrintl

#define mcsl_llrint __builtin_llrint
#define mcsl_llrintf __builtin_llrintf
#define mcsl_llrintl __builtin_llrintl

#define mcsl_nearbyint __builtin_nearbyint
#define mcsl_nearbyintf __builtin_nearbyintf
#define mcsl_nearbyintl __builtin_nearbyintl

#define mcsl_fma __builtin_fma
#define mcsl_fmaf __builtin_fmaf
#define mcsl_fmal __builtin_fmal

#define mcsl_fmin __builtin_fmin
#define mcsl_fminf __builtin_fminf
#define mcsl_fminl __builtin_fminl

#define mcsl_fmax __builtin_fmax
#define mcsl_fmaxf __builtin_fmaxf
#define mcsl_fmaxl __builtin_fmaxl

#define mcsl_fdim __builtin_fdim
#define mcsl_fdimf __builtin_fdimf
#define mcsl_fdiml __builtin_fdiml

#define mcsl_drem __builtin_drem
#define mcsl_dremf __builtin_dremf
#define mcsl_dreml __builtin_dreml

#define mcsl_remainder __builtin_remainder
#define mcsl_remainderf __builtin_remainderf
#define mcsl_remainderl __builtin_remainderl

#define mcsl_scalb __builtin_scalb
#define mcsl_scalbf __builtin_scalbf
#define mcsl_scalbl __builtin_scalbl

#define mcsl_scalbn __builtin_scalbn
#define mcsl_scalbnf __builtin_scalbnf
#define mcsl_scalbnl __builtin_scalbnl

#define mcsl_scalbln __builtin_scalbln
#define mcsl_scalblnf __builtin_scalblnf
#define mcsl_scalblnl __builtin_scalblnl

#define mcsl_signbit __builtin_signbit
#define mcsl_signbitf __builtin_signbitf
#define mcsl_signbitl __builtin_signbitl

#define mcsl_signbitd32 __builtin_signbitd32
#define mcsl_signbitd64 __builtin_signbitd64
#define mcsl_signbitd128 __builtin_signbitd128

#define mcsl_significand __builtin_significand
#define mcsl_significandf __builtin_significandf
#define mcsl_significandl __builtin_significandl

#define mcsl_j0 __builtin_j0
#define mcsl_j1 __builtin_j1
#define mcsl_jn __builtin_jn

#define mcsl_j0f __builtin_j0f
#define mcsl_j1f __builtin_j1f
#define mcsl_jnf __builtin_jnf

#define mcsl_j0l __builtin_j0l
#define mcsl_j1l __builtin_j1l
#define mcsl_jnl __builtin_jnl

#define mcsl_y0 __builtin_y0
#define mcsl_y1 __builtin_y1
#define mcsl_yn __builtin_yn

#define mcsl_y0f __builtin_y0f
#define mcsl_y1f __builtin_y1f
#define mcsl_ynf __builtin_ynf

#define mcsl_y0l __builtin_y0l
#define mcsl_y1l __builtin_y1l
#define mcsl_ynl __builtin_ynl

#define mcsl_modf __builtin_modf
#define mcsl_modff __builtin_modff
#define mcsl_modfl __builtin_modfl

#define mcsl_fmod __builtin_fmod
#define mcsl_fmodf __builtin_fmodf
#define mcsl_fmodl __builtin_fmodl

#define mcsl_nan __builtin_nan
#define mcsl_nanf __builtin_nanf
#define mcsl_nanl __builtin_nanl

#define mcsl_nand32 __builtin_nand32
#define mcsl_nand64 __builtin_nand64
#define mcsl_nand128 __builtin_nand128

#define mcsl_isnan __builtin_isnan
#define mcsl_isnanf __builtin_isnanf
#define mcsl_isnanl __builtin_isnanl

#define mcsl_inf __builtin_inf
#define mcsl_inff __builtin_inff
#define mcsl_infl __builtin_infl

#define mcsl_infd32 __builtin_infd32
#define mcsl_infd64 __builtin_infd64
#define mcsl_infd128 __builtin_infd128

#define mcsl_isinf __builtin_isinf
#define mcsl_isinff __builtin_isinff
#define mcsl_isinfl __builtin_isinfl

#define mcsl_finite __builtin_finite
#define mcsl_finitef __builtin_finitef
#define mcsl_finitel __builtin_finitel

#define mcsl_isfinite __builtin_isfinite

#define mcsl_hypot __builtin_hypot
#define mcsl_hypotf __builtin_hypotf
#define mcsl_hypotl __builtin_hypotl

#define mcsl_cbrt __builtin_cbrt
#define mcsl_cbrtf __builtin_cbrtf
#define mcsl_cbrtl __builtin_cbrtl

#define mcsl_copysign __builtin_copysign
#define mcsl_copysignf __builtin_copysignf
#define mcsl_copysignl __builtin_copysignl

#define mcsl_nextafter __builtin_nextafter
#define mcsl_nextafterf __builtin_nextafterf
#define mcsl_nextafterl __builtin_nextafterl

#define mcsl_nexttoward __builtin_nexttoward
#define mcsl_nexttowardf __builtin_nexttowardf
#define mcsl_nexttowardl __builtin_nexttowardl

#define mcsl_nextdown __builtin_nextdown
#define mcsl_nextdownf __builtin_nextdownf
#define mcsl_nextdownl __builtin_nextdownl

#define mcsl_nextup __builtin_nextup
#define mcsl_nextupf __builtin_nextupf
#define mcsl_nextupl __builtin_nextupl

#define mcsl_trunc __builtin_trunc
#define mcsl_truncf __builtin_truncf
#define mcsl_truncl __builtin_truncl

#define mcsl_remquo __builtin_remquo
#define mcsl_remquof __builtin_remquof
#define mcsl_remquol __builtin_remquol

#define mcsl_lgamma __builtin_lgamma
#define mcsl_lgammaf __builtin_lgammaf
#define mcsl_lgammal __builtin_lgammal

#define mcsl_tgamma __builtin_tgamma
#define mcsl_tgammaf __builtin_tgammaf
#define mcsl_tgammal __builtin_tgammal

#define mcsl_gamma __builtin_gamma
#define mcsl_gammaf __builtin_gammaf
#define mcsl_gammal __builtin_gammal

#define mcsl_lgamma_r __builtin_lgamma_r
#define mcsl_lgammaf_r __builtin_lgammaf_r
#define mcsl_lgammal_r __builtin_lgammal_r

#define mcsl_fpclassify __builtin_fpclassify
#define mcsl_isnormal __builtin_isnormal

#define mcsl_popcount __builtin_popcount
#define mcsl_popcountl __builtin_popcountl
#define mcsl_popcountll __builtin_popcountll

#define mcsl_parity __builtin_parity
#define mcsl_parityl __builtin_parityl
#define mcsl_parityll __builtin_parityll

#define mcsl_clz __builtin_clz
#define mcsl_clzl __builtin_clzl
#define mcsl_clzll __builtin_clzll

#define mcsl_ctz __builtin_ctz
#define mcsl_ctzl __builtin_ctzl
#define mcsl_ctzll __builtin_ctzll

#define mcsl_isgreater __builtin_isgreater
#define mcsl_isgreaterequal __builtin_isgreaterequal
#define mcsl_isless __builtin_isless
#define mcsl_islessequal __builtin_islessequal

#define mcsl_expect __builtin_expect
#define mcsl_bswap16 __builtin_bswap16
#define mcsl_bswap32 __builtin_bswap32
#define mcsl_bswap64 __builtin_bswap64

#define mcsl_bcmp __builtin_bcmp
#define mcsl_bzero __builtin_bzero

#define mcsl_isalnum __builtin_isalnum
#define mcsl_isalpha __builtin_isalpha
#define mcsl_iscntrl __builtin_iscntrl
#define mcsl_isdigit __builtin_isdigit
#define mcsl_isgraph __builtin_isgraph
#define mcsl_islower __builtin_islower
#define mcsl_isprint __builtin_isprint
#define mcsl_ispunct __builtin_ispunct
#define mcsl_isspace __builtin_isspace
#define mcsl_isupper __builtin_isupper
#define mcsl_isxdigit __builtin_isxdigit
#define mcsl_isascii __builtin_isascii
#define mcsl_isblank __builtin_isblank

#define mcsl_setjmp __builtin_setjmp
#define mcsl_longjmp __builtin_longjmp

MCSL_INLINE_STATIC _u32 mcsl_lenf(_f32 a){
	_u32 ret;
	if (a < 0.0f) a = mcsl_fabsf(a);
	ret = 1 + (_u32)mcsl_log10f(a);
	return ret;
}
MCSL_INLINE_STATIC _u32 mcsl_lend(_f64 a){
	_u32 ret;
	if (a < 0.0f) a = mcsl_fabs(a);
	ret = 1 + (_u32)(_u64)mcsl_log10(a);
	return ret;
}
MCSL_INLINE_STATIC _u32 mcsl_lenl(_f128 a){
	_u32 ret;
	if (a < 0.0f) a = mcsl_fabsl(a);
	ret = 1 + (_u32)(_u64)mcsl_log10l(a);
	return ret;
}

typedef struct _aoc _aoc; /*array of char(string)*/
typedef struct _aos _aos; /*array of string*/

struct _aoc{
	cstring str;
	size_t len;
	size_t cap;
};
struct _aos{
	_aoc* item;
	size_t len;
	size_t cap;
};

#define aoc_null {NULL,0,0}
#define aos_null {NULL,0,0}

#define mcsl_min_of_two(a,b) (((a) < (b)) ? (a) : (b))
#define mcsl_max_of_two(a,b) (((a) > (b)) ? (a) : (b))
#define mcsl_min_of_three(a,b,c) (((a) < (b)) ? ((a) < (c)) ? (a) : (c) : ((b) < (c)) ? (b) : (c))
#define mcsl_max_of_three(a,b,c) (((a) > (b)) ? ((a) > (c)) ? (a) : (c) : ((b) > (c)) ? (b) : (c))
#define mcsl_med_of_three(a,b,c) ((((a) > (b)) ^ ((a) > (c))) ? (a) : (((b) < (a)) ^ ((b) < (c))) ? (b) : (c))

#endif
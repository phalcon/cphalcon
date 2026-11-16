/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_GLOBALS_H
#define ZEPHIR_KERNEL_GLOBALS_H

#include <php.h>

#define ZEPHIR_MAX_CACHE_SLOTS 512

/*
 * Inline property-cache slots (issue #1902 follow-up). Each slot is a
 * run-time cache region handed to the engine's read_property/write_property
 * handler: [0]=class entry, [1]=property offset, [2]=property_info (typed).
 * Stored in per-request-zeroed module globals; index 0 means "uncached".
 */
#define ZEPHIR_PROPERTY_CACHE_SLOT_SIZE 3
#define ZEPHIR_MAX_PROPERTY_CACHE_SLOTS 2048

typedef struct _zephir_function_cache {
	zend_class_entry *ce;
	zend_function *func;
} zephir_function_cache;

typedef zend_function zephir_fcall_cache_entry;

/**
 * The inline cache of one method or static call site: the method a call
 * resolved to, for the class it looked the method up in and the class the
 * calling code belongs to. The method PHP runs depends on nothing else, so a
 * later call with both classes unchanged runs it without looking it up.
 *
 * Each record is declared in the C function holding its call site. `request`
 * is the request that filled it: a class declared by a request is freed when
 * that request ends, and another class can take its address in the next.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2790
 */
typedef struct _zephir_method_cache {
	zend_class_entry *ce;
	const zend_class_entry *scope;
	zend_function *func;
	uint64_t request;
} zephir_method_cache;

/**
 * The cache record of one static property access: the zval the property of
 * a class lives in, as ZEND_FETCH_STATIC_PROP_* keeps it in a run-time cache
 * slot. Each record is declared in the C function holding the access.
 *
 * The static members of a class are allocated again in every request, so a
 * record is only good for the request that filled it.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2805
 */
typedef struct _zephir_static_property_cache {
	zend_class_entry *ce;
	zval *slot;
	zend_property_info *info;
	uint64_t request;
} zephir_static_property_cache;

#define ZEPHIR_INIT_FUNCS(class_functions) static const zend_function_entry class_functions[] =

/** Define FASTCALL */
#if defined(__GNUC__) && ZEND_GCC_VERSION >= 3004 && defined(__i386__)
# define ZEPHIR_FASTCALL __attribute__((fastcall))
#elif defined(_MSC_VER) && defined(_M_IX86)
# define ZEPHIR_FASTCALL __fastcall
#else
# define ZEPHIR_FASTCALL
#endif

#define ZEPHIR_INIT_CLASS(name) \
	int zephir_ ##name## _init(INIT_FUNC_ARGS)

#define ZEPHIR_INIT(name) \
	if (zephir_ ##name## _init(INIT_FUNC_ARGS_PASSTHRU) == FAILURE) { \
		return FAILURE; \
	}

#if defined(__GNUC__) && (defined(__clang__) || ((__GNUC__ * 100 + __GNUC_MINOR__) >= 405))
# define UNREACHABLE() __builtin_unreachable()
# define ASSUME(x) if (x) {} else __builtin_unreachable()
#else
# define UNREACHABLE() assert(0)
# define ASSUME(x) assert(!!(x));
#endif

#if defined(__GNUC__) || defined(__clang__)
# define ZEPHIR_ATTR_NONNULL __attribute__((nonnull))
# define ZEPHIR_ATTR_NONNULL1(x) __attribute__((nonnull (x)))
# define ZEPHIR_ATTR_NONNULL2(x, y) __attribute__((nonnull (x, y)))
# define ZEPHIR_ATTR_NONNULL3(x, y, z) __attribute__((nonnull (x, y, z)))
# define ZEPHIR_ATTR_PURE __attribute__((pure))
# define ZEPHIR_ATTR_CONST __attribute__((const))
# define ZEPHIR_ATTR_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define ZEPHIR_ATTR_NONNULL
# define ZEPHIR_ATTR_NONNULL1(x)
# define ZEPHIR_ATTR_NONNULL2(x, y)
# define ZEPHIR_ATTR_NONNULL3(x, y, z)
# define ZEPHIR_ATTR_PURE
# define ZEPHIR_ATTR_CONST
# define ZEPHIR_ATTR_WARN_UNUSED_RESULT
#endif

#if !defined(__GNUC__) && !(defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590))
# define __builtin_constant_p(s) (0)
#endif

#ifndef __func__
# define __func__ __FUNCTION__
#endif

#if defined(__GNUC__)
# define ZEPHIR_NO_OPT __attribute__((optimize("O0")))
#else
# define ZEPHIR_NO_OPT
#endif

#define likely(x)   EXPECTED(x)
#define unlikely(x) UNEXPECTED(x)

#ifndef ZEND_ACC_DTOR
 #define ZEND_ACC_DTOR 0
#endif

#endif

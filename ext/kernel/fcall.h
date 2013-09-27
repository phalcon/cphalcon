
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_FCALL_H
#define ZEPHIR_KERNEL_FCALL_H

#include <stdarg.h>
#include "Zend/zend_hash.h"
#include "Zend/zend.h"

#ifdef __GNUC__
#define ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func_name, nparams, ...) \
	do { \
		if (__builtin_constant_p(func_name)) { \
			if (zephir_call_func_params(return_value, return_value_ptr, func_name, sizeof(func_name)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_func_params(return_value, return_value_ptr, func_name, strlen(func_name) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method, key, nparams, ...) \
	do { \
		register ulong _key = key; \
		if (__builtin_constant_p(method)) { \
			if (zephir_call_method_params(return_value, return_value_ptr, object, method, sizeof(method)-1, (_key ? _key : zend_inline_hash_func(method, sizeof(method))) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_method_params(return_value, return_value_ptr, object, method, strlen(method), (_key ? _key : (IS_INTERNED(method) ? INTERNED_HASH(method) : 0)) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method, key, cache, nparams, ...) \
	do { \
		register ulong _key = key; \
		if (__builtin_constant_p(method)) { \
			if (zephir_call_method_cache_params(return_value, return_value_ptr, object, method, sizeof(method)-1, (_key ? _key : zend_inline_hash_func(method, sizeof(method))), cache TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_method_cache_params(return_value, return_value_ptr, object, method, strlen(method), (_key ? _key : (IS_INTERNED(method) ? INTERNED_HASH(method) : 0)), cache TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define ZEPHIR_CALL_STATIC(return_value, return_value_ptr, class_name, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(class_name) && __builtin_constant_p(method)) { \
			if (zephir_call_static_func_params(return_value, return_value_ptr, class_name, sizeof(class_name)-1, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_static_func_params(return_value, return_value_ptr, class_name, strlen(class_name), method, strlen(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define ZEPHIR_CALL_PARENT(return_value, return_value_ptr, this_ptr, class_entry, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (zephir_call_parent_func_params(return_value, return_value_ptr, this_ptr, class_entry, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_parent_func_params(return_value, return_value_ptr, this_ptr, class_entry, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define ZEPHIR_CALL_SELF(return_value, return_value_ptr, this_ptr, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (zephir_call_self_func_params(return_value, return_value_ptr, this_ptr, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_self_func_params(return_value, return_value_ptr, this_ptr, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define ZEPHIR_CALL_ZSTATIC_STR(return_value, return_value_ptr, zclass, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (zephir_call_static_zval_str_func_params(return_value, return_value_ptr, zclass, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (zephir_call_static_zval_str_func_params(return_value, return_value_ptr, zclass, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#else

#define ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func_name, nparams, ...) \
	do { \
		if (zephir_call_func_params(return_value, return_value_ptr, func_name, strlen(func_name) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method, key, nparams, ...) \
	do { \
		register ulong _key = key; \
		if (zephir_call_method_params(return_value, return_value_ptr, object, method, strlen(method), (_key ? _key : (IS_INTERNED(method) ? INTERNED_HASH(method) : 0)) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method, key, cache, nparams, ...) \
	do { \
		register ulong _key = key; \
		if (zephir_call_method_cache_params(return_value, return_value_ptr, object, method, strlen(method), (_key ? _key : (IS_INTERNED(method) ? INTERNED_HASH(method) : 0)), cache TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_STATIC(return_value, return_value_ptr, class_name, method, nparams, ...) \
	do { \
		if (zephir_call_static_func_params(return_value, return_value_ptr, class_name, strlen(class_name), method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_PARENT(return_value, return_value_ptr, this_ptr, class_entry, method, nparams, ...) \
	do { \
		if (zephir_call_parent_func_params(return_value, return_value_ptr, this_ptr, class_entry, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_SELF(return_value, return_value_ptr, this_ptr, method, nparams, ...) \
	do { \
		if (zephir_call_self_func_params(return_value, return_value_ptr, this_ptr, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_ZSTATIC_STR(return_value, return_value_ptr, zclass, method, nparams, ...) \
	do { \
		if (zephir_call_static_zval_str_func_params(return_value, return_value_ptr, zclass, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#endif

#define ZEPHIR_CALL_ZMETHOD(return_value, return_value_ptr, object, method, nparams, ...) \
	do { \
		if (zephir_call_method_zval_params(return_value, return_value_ptr, object, method TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_ZSTATIC(return_value, return_value_ptr, object, method, nparams, ...) \
	do { \
		if (zephir_call_static_zval_func_params(return_value, return_value_ptr, object, method TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)


/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define ZEPHIR_CALL_USER_FUNC(return_value, handler) ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, handler, NULL)
#define ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, handler, params) \
	do { \
		if (zephir_call_user_func_array(return_value, handler, params TSRMLS_CC) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define ZEPHIR_CALL_USER_FUNC_ARRAY_NOEX(return_value, handler, params) \
	do { \
		if (zephir_call_user_func_array_noex(return_value, handler, params TSRMLS_CC) == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)


/** Macros to call functions in the PHP userland */
#define zephir_call_func_p0_ex(return_value, return_value_ptr, func) \
	do { \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 0, NULL); \
	} while (0)

#define zephir_call_func_p1_ex(return_value, return_value_ptr, func, p1) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 1, p1); \
	} while (0)

#define zephir_call_func_p2_ex(return_value, return_value_ptr, func, p1, p2) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 2, p1, p2); \
	} while (0)

#define zephir_call_func_p3_ex(return_value, return_value_ptr, func, p1, p2, p3) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 3, p1, p2, p3); \
	} while (0)

#define zephir_call_func_p4_ex(return_value, return_value_ptr, func, p1, p2, p3, p4) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 4, p1, p2, p3, p4); \
	} while (0)

#define zephir_call_func_p5_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 5, p1, p2, p3, p4, p5); \
	} while (0)

#define zephir_call_func_p6_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5, p6) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
			if (Z_TYPE_P(p6)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 6, p1, p2, p3, p4, p5, p6); \
	} while (0)

#define zephir_call_func_p7_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5, p6, p7) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
			if (Z_TYPE_P(p6)) {} \
			if (Z_TYPE_P(p7)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 7, p1, p2, p3, p4, p5, p6, p7); \
	} while (0)

#define zephir_call_func_p8_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5, p6, p7, p8) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
			if (Z_TYPE_P(p6)) {} \
			if (Z_TYPE_P(p7)) {} \
			if (Z_TYPE_P(p8)) {} \
		} \
		ZEPHIR_CALL_FUNCTION(return_value, return_value_ptr, func, 8, p1, p2, p3, p4, p5, p6, p7, p8); \
	} while (0)

#define zephir_call_func(return_value, func)                                                          zephir_call_func_p0_ex(return_value, NULL, func)
#define zephir_call_func_p1(return_value, func, p1)                                                   zephir_call_func_p1_ex(return_value, NULL, func, p1)
#define zephir_call_func_p2(return_value, func, p1, p2)                                               zephir_call_func_p2_ex(return_value, NULL, func, p1, p2)
#define zephir_call_func_p3(return_value, func, p1, p2, p3)                                           zephir_call_func_p3_ex(return_value, NULL, func, p1, p2, p3)
#define zephir_call_func_p4(return_value, func, p1, p2, p3, p4)                                       zephir_call_func_p4_ex(return_value, NULL, func, p1, p2, p3, p4)
#define zephir_call_func_p5(return_value, func, p1, p2, p3, p4, p5)                                   zephir_call_func_p5_ex(return_value, NULL, func, p1, p2, p3, p4, p5)
#define zephir_call_func_p6(return_value, func, p1, p2, p3, p4, p5, p6)                               zephir_call_func_p6_ex(return_value, NULL, func, p1, p2, p3, p4, p5, p6)
#define zephir_call_func_p7(return_value, func, p1, p2, p3, p4, p5, p6, p7)                           zephir_call_func_p7_ex(return_value, NULL, func, p1, p2, p3, p4, p5, p6, p7)
#define zephir_call_func_p8(return_value, func, p1, p2, p3, p4, p5, p6, p7, p8)                       zephir_call_func_p8_ex(return_value, NULL, func, p1, p2, p3, p4, p5, p6, p7, p8)

#define zephir_call_func_noret(func)                                                                  zephir_call_func_p0_ex(NULL, NULL, func)
#define zephir_call_func_p1_noret(func, p1)                                                           zephir_call_func_p1_ex(NULL, NULL, func, p1)
#define zephir_call_func_p2_noret(func, p1, p2)                                                       zephir_call_func_p2_ex(NULL, NULL, func, p1, p2)
#define zephir_call_func_p3_noret(func, p1, p2, p3)                                                   zephir_call_func_p3_ex(NULL, NULL, func, p1, p2, p3)
#define zephir_call_func_p4_noret(func, p1, p2, p3, p4)                                               zephir_call_func_p4_ex(NULL, NULL, func, p1, p2, p3, p4)
#define zephir_call_func_p5_noret(func, p1, p2, p3, p4, p5)                                           zephir_call_func_p5_ex(NULL, NULL, func, p1, p2, p3, p4, p5)
#define zephir_call_func_p6_noret(func, p1, p2, p3, p4, p5, p6)                                       zephir_call_func_p6_ex(NULL, NULL, func, p1, p2, p3, p4, p5, p6)
#define zephir_call_func_p7_noret(func, p1, p2, p3, p4, p5, p6, p7)                                   zephir_call_func_p7_ex(NULL, NULL, func, p1, p2, p3, p4, p5, p6, p7)
#define zephir_call_func_p8_noret(func, p1, p2, p3, p4, p5, p6, p7, p8)                               zephir_call_func_p8_ex(NULL, NULL, func, p1, p2, p3, p4, p5, p6, p7, p8)

/** Macros to call methods in the PHP userland */
#define zephir_call_method_p0_key_ex(return_value, return_value_ptr, object, method_name, key) \
	do { \
		ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 0, NULL); \
	} while (0)

#define zephir_call_method_p1_key_ex(return_value, return_value_ptr, object, method_name, key, p1) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
		} \
		ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 1, p1); \
	} while (0)

#define zephir_call_method_p2_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
		} \
		ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 2, p1, p2); \
	} while (0)

#define zephir_call_method_p3_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
		} \
		ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 3, p1, p2, p3); \
	} while (0)

#define zephir_call_method_p4_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3, p4) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
		} \
		ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 4, p1, p2, p3, p4); \
	} while (0)

#define zephir_call_method_p5_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3, p4, p5) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
		} \
		ZEPHIR_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 5, p1, p2, p3, p4, p5); \
	} while (0)

/** Macros to call methods in the PHP userland (keeping the call cache) */
#define zephir_call_method_p0_cache_key_ex(return_value, return_value_ptr, object, method_name, key, cache) \
	do { \
		ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method_name, key, cache, 0, NULL); \
	} while (0)

#define zephir_call_method_p1_cache_key_ex(return_value, return_value_ptr, object, method_name, key, cache, p1) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
		} \
		ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method_name, key, cache, 1, p1); \
	} while (0)

#define zephir_call_method_p2_cache_key_ex(return_value, return_value_ptr, object, method_name, key, cache, p1, p2) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
		} \
		ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method_name, key, cache, 2, p1, p2); \
	} while (0)

#define zephir_call_method_p3_cache_key_ex(return_value, return_value_ptr, object, method_name, key, cache, p1, p2, p3) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
		} \
		ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method_name, key, cache, 3, p1, p2, p3); \
	} while (0)

#define zephir_call_method_p4_cache_key_ex(return_value, return_value_ptr, object, method_name, key, cache, p1, p2, p3, p4) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
		} \
		ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method_name, key, cache, 4, p1, p2, p3, p4); \
	} while (0)

#define zephir_call_method_p5_cache_key_ex(return_value, return_value_ptr, object, method_name, key, cache, p1, p2, p3, p4, p5) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
		} \
		ZEPHIR_CALL_METHOD_CACHE(return_value, return_value_ptr, object, method_name, key, cache, 5, p1, p2, p3, p4, p5); \
	} while (0)

#define zephir_call_method_p0_ex(return_value, return_value_ptr, object, method_name)                                   zephir_call_method_p0_key_ex(return_value, return_value_ptr, object, method_name, 0)
#define zephir_call_method_p1_ex(return_value, return_value_ptr, object, method_name, p1)                               zephir_call_method_p1_key_ex(return_value, return_value_ptr, object, method_name, 0, p1)
#define zephir_call_method_p2_ex(return_value, return_value_ptr, object, method_name, p1, p2)                           zephir_call_method_p2_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2)
#define zephir_call_method_p3_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3)                       zephir_call_method_p3_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3)
#define zephir_call_method_p4_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3, p4)                   zephir_call_method_p4_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3, p4)
#define zephir_call_method_p5_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3, p4, p5)               zephir_call_method_p5_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3, p4, p5)

#define zephir_call_method_p0_cache_ex(return_value, return_value_ptr, object, method_name, cache)                      zephir_call_method_p0_cache_key_ex(return_value, return_value_ptr, object, method_name, 0, cache)
#define zephir_call_method_p1_cache_ex(return_value, return_value_ptr, object, method_name, cache, p1)                  zephir_call_method_p1_cache_key_ex(return_value, return_value_ptr, object, method_name, 0, cache, p1)
#define zephir_call_method_p2_cache_ex(return_value, return_value_ptr, object, method_name, cache, p1, p2)              zephir_call_method_p2_cache_key_ex(return_value, return_value_ptr, object, method_name, 0, cache, p1, p2)
#define zephir_call_method_p3_cache_ex(return_value, return_value_ptr, object, method_name, cache, p1, p2, p3)          zephir_call_method_p3_cache_key_ex(return_value, return_value_ptr, object, method_name, 0, cache, p1, p2, p3)
#define zephir_call_method_p4_cache_ex(return_value, return_value_ptr, object, method_name, cache, p1, p2, p3, p4)      zephir_call_method_p4_cache_key_ex(return_value, return_value_ptr, object, method_name, 0, cache, p1, p2, p3, p4)
#define zephir_call_method_p5_cache_ex(return_value, return_value_ptr, object, method_name, cache, p1, p2, p3, p4, p5)  zephir_call_method_p5_cache_key_ex(return_value, return_value_ptr, object, method_name, 0, cache, p1, p2, p3, p4, p5)

#define zephir_call_method(return_value, object, method_name)                                                       zephir_call_method_p0_ex(return_value, NULL, object, method_name)
#define zephir_call_method_p1(return_value, object, method_name, p1)                                                zephir_call_method_p1_ex(return_value, NULL, object, method_name, p1)
#define zephir_call_method_p2(return_value, object, method_name, p1, p2)                                            zephir_call_method_p2_ex(return_value, NULL, object, method_name, p1, p2)
#define zephir_call_method_p3(return_value, object, method_name, p1, p2, p3)                                        zephir_call_method_p3_ex(return_value, NULL, object, method_name, p1, p2, p3)
#define zephir_call_method_p4(return_value, object, method_name, p1, p2, p3, p4)                                    zephir_call_method_p4_ex(return_value, NULL, object, method_name, p1, p2, p3, p4)
#define zephir_call_method_p5(return_value, object, method_name, p1, p2, p3, p4, p5)                                zephir_call_method_p5_ex(return_value, NULL, object, method_name, p1, p2, p3, p4, p5)

#define zephir_call_method_noret(object, method_name)                                                               zephir_call_method_p0_ex(NULL, NULL, object, method_name)
#define zephir_call_method_p1_noret(object, method_name, p1)                                                        zephir_call_method_p1_ex(NULL, NULL, object, method_name, p1)
#define zephir_call_method_p2_noret(object, method_name, p1, p2)                                                    zephir_call_method_p2_ex(NULL, NULL, object, method_name, p1, p2)
#define zephir_call_method_p3_noret(object, method_name, p1, p2, p3)                                                zephir_call_method_p3_ex(NULL, NULL, object, method_name, p1, p2, p3)
#define zephir_call_method_p4_noret(object, method_name, p1, p2, p3, p4)                                            zephir_call_method_p4_ex(NULL, NULL, object, method_name, p1, p2, p3, p4)
#define zephir_call_method_p5_noret(object, method_name, p1, p2, p3, p4, p5)                                        zephir_call_method_p5_ex(NULL, NULL, object, method_name, p1, p2, p3, p4, p5)

#define zephir_call_method_cache(return_value, object, method_name, cache)                                          zephir_call_method_p0_cache_ex(return_value, NULL, object, method_name, cache)
#define zephir_call_method_p1_cache(return_value, object, method_name, cache, p1)                                   zephir_call_method_p1_cache_ex(return_value, NULL, object, method_name, cache, p1)
#define zephir_call_method_p2_cache(return_value, object, method_name, cache, p1, p2)                               zephir_call_method_p2_cache_ex(return_value, NULL, object, method_name, cache, p1, p2)
#define zephir_call_method_p3_cache(return_value, object, method_name, cache, p1, p2, p3)                           zephir_call_method_p3_cache_ex(return_value, NULL, object, method_name, cache, p1, p2, p3)
#define zephir_call_method_p4_cache(return_value, object, method_name, cache, p1, p2, p3, p4)                       zephir_call_method_p4_cache_ex(return_value, NULL, object, method_name, cache, p1, p2, p3, p4)
#define zephir_call_method_p5_cache(return_value, object, method_name, cache, p1, p2, p3, p4, p5)                   zephir_call_method_p5_cache_ex(return_value, NULL, object, method_name, cache, p1, p2, p3, p4, p5)

#define zephir_call_method_cache_noret(object, method_name, cache)                                                  zephir_call_method_p0_cache_ex(NULL, NULL, object, method_name, cache)
#define zephir_call_method_p1_cache_noret(object, method_name, cache, p1)                                           zephir_call_method_p1_cache_ex(NULL, NULL, object, method_name, cache, p1)
#define zephir_call_method_p2_cache_noret(object, method_name, cache, p1, p2)                                       zephir_call_method_p2_cache_ex(NULL, NULL, object, method_name, cache, p1, p2)
#define zephir_call_method_p3_cache_noret(object, method_name, cache, p1, p2, p3)                                   zephir_call_method_p3_cache_ex(NULL, NULL, object, method_name, cache, p1, p2, p3)
#define zephir_call_method_p4_cache_noret(object, method_name, cache, p1, p2, p3, p4)                               zephir_call_method_p4_cache_ex(NULL, NULL, object, method_name, cache, p1, p2, p3, p4)
#define zephir_call_method_p5_cache_noret(object, method_name, cache, p1, p2, p3, p4, p5)                           zephir_call_method_p5_cache_ex(NULL, NULL, object, method_name, cache, p1, p2, p3, p4, p5)

#define zephir_call_method_key(return_value, object, method_name, key)                                              zephir_call_method_p0_key_ex(return_value, NULL, object, method_name, key)
#define zephir_call_method_p1_key(return_value, object, method_name, key, p1)                                       zephir_call_method_p1_key_ex(return_value, NULL, object, method_name, key, p1)
#define zephir_call_method_p2_key(return_value, object, method_name, key, p1, p2)                                   zephir_call_method_p2_key_ex(return_value, NULL, object, method_name, key, p1, p2)
#define zephir_call_method_p3_key(return_value, object, method_name, key, p1, p2, p3)                               zephir_call_method_p3_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3)
#define zephir_call_method_p4_key(return_value, object, method_name, key, p1, p2, p3, p4)                           zephir_call_method_p4_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3, p4)
#define zephir_call_method_p5_key(return_value, object, method_name, key, p1, p2, p3, p4, p5)                       zephir_call_method_p5_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3, p4, p5)

/** Macros to call methods with zvals as method names */
#define zephir_call_method_zval(return_value, object, method)                  ZEPHIR_CALL_ZMETHOD(return_value, NULL, object, method, 0, NULL)
#define zephir_call_method_zval_p1(return_value, object, method, p1)           ZEPHIR_CALL_ZMETHOD(return_value, NULL, object, method, 1, p1)
#define zephir_call_method_zval_p2(return_value, object, method, p1, p2)       ZEPHIR_CALL_ZMETHOD(return_value, NULL, object, method, 2, p1, p2)
#define zephir_call_method_zval_p3(return_value, object, method, p1, p2, p3)   ZEPHIR_CALL_ZMETHOD(return_value, NULL, object, method, 3, p1, p2, p3)

#define zephir_call_method_zval_noret(object, method)                          ZEPHIR_CALL_ZMETHOD(NULL, NULL, object, method, 0, NULL)
#define zephir_call_method_zval_p1_noret(object, method, p1)                   ZEPHIR_CALL_ZMETHOD(NULL, NULL, object, method, 1, p1)
#define zephir_call_method_zval_p2_noret(object, method, p1, p2)               ZEPHIR_CALL_ZMETHOD(NULL, NULL, object, method, 2, p1, p2)
#define zephir_call_method_zval_p3_noret(object, method, p1, p2, p3)           ZEPHIR_CALL_ZMETHOD(NULL, NULL, object, method, 3, p1, p2, p3)


/** Use these macros to call functions in the parent class */
#define zephir_call_parent(return_value, object, active_class, method)                 ZEPHIR_CALL_PARENT(return_value, NULL, object, active_class, method, 0, NULL)
#define zephir_call_parent_p1(return_value, object, active_class, method, p1)          ZEPHIR_CALL_PARENT(return_value, NULL, object, active_class, method, 1, p1)
#define zephir_call_parent_p2(return_value, object, active_class, method, p1, p2)      ZEPHIR_CALL_PARENT(return_value, NULL, object, active_class, method, 2, p1, p2)

#define zephir_call_parent_noret(object, active_class, method)                         ZEPHIR_CALL_PARENT(NULL, NULL, object, active_class, method, 0, NULL)
#define zephir_call_parent_p1_noret(object, active_class, method, p1)                  ZEPHIR_CALL_PARENT(NULL, NULL, object, active_class, method, 1, p1)
#define zephir_call_parent_p2_noret(object, active_class, method, p1, p2)              ZEPHIR_CALL_PARENT(NULL, NULL, object, active_class, method, 2, p1, p2)
#define zephir_call_parent_p3_noret(object, active_class, method, p1, p2, p3)          ZEPHIR_CALL_PARENT(NULL, NULL, object, active_class, method, 3, p1, p2, p3)
#define zephir_call_parent_p4_noret(object, active_class, method, p1, p2, p3, p4)      ZEPHIR_CALL_PARENT(NULL, NULL, object, active_class, method, 4, p1, p2, p3, p4)
#define zephir_call_parent_p5_noret(object, active_class, method, p1, p2, p3, p4, p5)  ZEPHIR_CALL_PARENT(NULL, NULL, object, active_class, method, 5, p1, p2, p3, p4, p5)

/** Use these functions to call static functions on the current class */
#define zephir_call_self(return_value, object, method)                     ZEPHIR_CALL_SELF(return_value, NULL, object, method, 0, NULL)
#define zephir_call_self_p1(return_value, object, method, p1)              ZEPHIR_CALL_SELF(return_value, NULL, object, method, 1, p1)
#define zephir_call_self_p2(return_value, object, method, p1, p2)          ZEPHIR_CALL_SELF(return_value, NULL, object, method, 2, p1, p2)
#define zephir_call_self_p3(return_value, object, method, p1, p2, p3)      ZEPHIR_CALL_SELF(return_value, NULL, object, method, 3, p1, p2, p3)
#define zephir_call_self_p4(return_value, object, method, p1, p2, p3, p4)  ZEPHIR_CALL_SELF(return_value, NULL, object, method, 4, p1, p2, p3, p4)

#define zephir_call_self_noret(object, method, param_count, params)        ZEPHIR_CALL_SELF(NULL, NULL, object, method, 0, NULL)
#define zephir_call_self_p1_noret(object, method, p1)                      ZEPHIR_CALL_SELF(NULL, NULL, object, method, 1, p1)
#define zephir_call_self_p2_noret(object, method, p1, p2)                  ZEPHIR_CALL_SELF(NULL, NULL, object, method, 2, p1, p2)
#define zephir_call_self_p3_noret(object, method, p1, p2, p3)              ZEPHIR_CALL_SELF(NULL, NULL, object, method, 3, p1, p2, p3)
#define zephir_call_self_p4_noret(object, method, p1, p2, p3, p4)          ZEPHIR_CALL_SELF(NULL, NULL, object, method, 4, p1, p2, p3, p4)

/** Use these macros to call functions statically  */
#define zephir_call_static(return_value, class_name, method_name)                         ZEPHIR_CALL_STATIC(return_value, NULL, class_name, method_name, 0, NULL)
#define zephir_call_static_p1(return_value, class_name, method_name, p1)                  ZEPHIR_CALL_STATIC(return_value, NULL, class_name, method_name, 1, p1)
#define zephir_call_static_p2(return_value, class_name, method_name, p1, p2)              ZEPHIR_CALL_STATIC(return_value, NULL, class_name, method_name, 2, p1, p2)
#define zephir_call_static_p3(return_value, class_name, method_name, p1, p2, p3)          ZEPHIR_CALL_STATIC(return_value, NULL, class_name, method_name, 3, p1, p2, p3)
#define zephir_call_static_p4(return_value, class_name, method_name, p1, p2, p3, p4)      ZEPHIR_CALL_STATIC(return_value, NULL, class_name, method_name, 4, p1, p2, p3, p4)
#define zephir_call_static_p5(return_value, class_name, method_name, p1, p2, p3, p4, p5)  ZEPHIR_CALL_STATIC(return_value, NULL, class_name, method_name, 5, p1, p2, p3, p4, p5)

#define zephir_call_static_noret(class_name, method_name)                                 ZEPHIR_CALL_STATIC(NULL, NULL, class_name, method_name, 0, NULL)
#define zephir_call_static_p1_noret(class_name, method_name, p1)                          ZEPHIR_CALL_STATIC(NULL, NULL, class_name, method_name, 1, p1)
#define zephir_call_static_p2_noret(class_name, method_name, p1, p2)                      ZEPHIR_CALL_STATIC(NULL, NULL, class_name, method_name, 2, p1, p2)
#define zephir_call_static_p3_noret(class_name, method_name, p1, p2, p3)                  ZEPHIR_CALL_STATIC(NULL, NULL, class_name, method_name, 3, p1, p2, p3)
#define zephir_call_static_p4_noret(class_name, method_name, p1, p2, p3, p4)              ZEPHIR_CALL_STATIC(NULL, NULL, class_name, method_name, 4, p1, p2, p3, p4)
#define zephir_call_static_p5_noret(class_name, method_name, p1, p2, p3, p4, p5)          ZEPHIR_CALL_STATIC(NULL, NULL, class_name, method_name, 5, p1, p2, p3, p4, p5)


#define zephir_call_zval_static(return_value, class_zval, method)         ZEPHIR_CALL_ZSTATIC(return_value, NULL, class_zval, method, 0, NULL)
#define zephir_call_zval_static_p1(return_value, class_zval, method, p1)  ZEPHIR_CALL_ZSTATIC(return_value, NULL, class_zval, method, 1, p1)

#define zephir_call_zval_str_static_p1(return_value, class_zval, method, p1) ZEPHIR_CALL_ZSTATIC_STR(return_value, NULL, class_zval, method, 1, p1)

int zephir_call_func_params(zval *return_value, zval **return_value_ptr, const char *func_name, int func_length TSRMLS_DC, int param_count, ...);
int zephir_call_method_params(zval *return_value, zval **return_value_ptr, zval *object, char *method_name, int method_len, ulong method_key TSRMLS_DC, int param_count, ...);
int zephir_call_method_cache_params(zval *return_value, zval **return_value_ptr, zval *object, char *method_name, int method_len, ulong method_key, zend_function **fcc TSRMLS_DC, int param_count, ...);
int zephir_call_method_zval_params(zval *return_value, zval **return_value_ptr, zval *object, zval *method TSRMLS_DC, int param_count, ...);
int zephir_call_parent_func_params(zval *return_value, zval **return_value_ptr, zval *object, zend_class_entry *active_class_ce, char *method_name, int method_len TSRMLS_DC, int param_count, ...);
int zephir_call_self_func_params(zval *return_value, zval **return_value_ptr, zval *object, char *method_name, int method_len TSRMLS_DC, int param_count, ...);
int zephir_call_static_func_params(zval *return_value, zval **return_value_ptr, char *class_name, int class_length, char *method_name, int method_length TSRMLS_DC, int param_count, ...);
int zephir_call_static_zval_func_params(zval *return_value, zval **return_value_ptr, zval *mixed_name, zval *method TSRMLS_DC, int param_count, ...);
int zephir_call_static_zval_str_func_params(zval *return_value, zval **return_value_ptr, zval *mixed_name, char *method_name, int method_len TSRMLS_DC, int param_count, ...);

int zephir_call_method_vparams(zval *return_value, zval **return_value_ptr, zval *object, char *method_name, int method_len,
	ulong method_key, zend_function **fcc TSRMLS_DC, int param_count, va_list ap);

/** Fast call_user_func_array/call_user_func */
int zephir_call_user_func_array(zval *return_value, zval *handler, zval *params TSRMLS_DC);
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC);

/** Check constructors */
int zephir_has_constructor(const zval *object TSRMLS_DC);
int zephir_has_constructor_ce(zend_class_entry *ce);

/** PHP < 5.3.9 has problems with closures */
#if PHP_VERSION_ID <= 50309
int zephir_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
#define ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER zephir_call_function
#else
#define ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER zend_call_function
#endif

#ifndef zend_error_noreturn
#define zend_error_noreturn zend_error
#endif

#endif /* ZEPHIR_KERNEL_FCALL_H */

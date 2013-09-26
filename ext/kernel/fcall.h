
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_KERNEL_FCALL_H
#define PHALCON_KERNEL_FCALL_H

#include <stdarg.h>
#include "Zend/zend_hash.h"
#include "Zend/zend.h"

#ifdef __GNUC__
#define PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func_name, nparams, ...) \
	do { \
		if (__builtin_constant_p(func_name)) { \
			if (phalcon_call_func_params(return_value, return_value_ptr, func_name, sizeof(func_name)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_func_params(return_value, return_value_ptr, func_name, strlen(func_name) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method, key, nparams, ...) \
	do { \
		register ulong _key = key; \
		if (__builtin_constant_p(method)) { \
			if (phalcon_call_method_params(return_value, return_value_ptr, object, method, sizeof(method)-1, (_key ? _key : zend_inline_hash_func(method, sizeof(method))) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_method_params(return_value, return_value_ptr, object, method, strlen(method), (_key ? _key : (IS_INTERNED(method) ? INTERNED_HASH(method) : 0)) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define PHALCON_CALL_STATIC(return_value, return_value_ptr, class_name, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(class_name) && __builtin_constant_p(method)) { \
			if (phalcon_call_static_func_params(return_value, return_value_ptr, class_name, sizeof(class_name)-1, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_static_func_params(return_value, return_value_ptr, class_name, strlen(class_name), method, strlen(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define PHALCON_CALL_PARENT(return_value, return_value_ptr, this_ptr, class_entry, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (phalcon_call_parent_func_params(return_value, return_value_ptr, this_ptr, class_entry, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_parent_func_params(return_value, return_value_ptr, this_ptr, class_entry, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define PHALCON_CALL_SELF(return_value, return_value_ptr, this_ptr, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (phalcon_call_self_func_params(return_value, return_value_ptr, this_ptr, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_self_func_params(return_value, return_value_ptr, this_ptr, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define PHALCON_CALL_ZSTATIC_STR(return_value, return_value_ptr, zclass, method, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (phalcon_call_static_zval_str_func_params(return_value, return_value_ptr, zclass, method, sizeof(method)-1 TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_static_zval_str_func_params(return_value, return_value_ptr, zclass, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#else

#define PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func_name, nparams, ...) \
	do { \
		if (phalcon_call_func_params(return_value, return_value_ptr, func_name, strlen(func_name) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method, key, nparams, ...) \
	do { \
		register ulong _key = key; \
		if (phalcon_call_method_params(return_value, return_value_ptr, object, method, strlen(method), (_key ? _key : (IS_INTERNED(method) ? INTERNED_HASH(method) : 0)) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_STATIC(return_value, return_value_ptr, class_name, method, nparams, ...) \
	do { \
		if (phalcon_call_static_func_params(return_value, return_value_ptr, class_name, strlen(class_name), method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_PARENT(return_value, return_value_ptr, this_ptr, class_entry, method, nparams, ...) \
	do { \
		if (phalcon_call_parent_func_params(return_value, return_value_ptr, this_ptr, class_entry, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_SELF(return_value, return_value_ptr, this_ptr, method, nparams, ...) \
	do { \
		if (phalcon_call_self_func_params(return_value, return_value_ptr, this_ptr, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_ZSTATIC_STR(return_value, return_value_ptr, zclass, method, nparams, ...) \
	do { \
		if (phalcon_call_static_zval_str_func_params(return_value, return_value_ptr, zclass, method, strlen(method) TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#endif

#define PHALCON_CALL_ZMETHOD(return_value, return_value_ptr, object, method, nparams, ...) \
	do { \
		if (phalcon_call_method_zval_params(return_value, return_value_ptr, object, method TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_ZSTATIC(return_value, return_value_ptr, object, method, nparams, ...) \
	do { \
		if (phalcon_call_static_zval_func_params(return_value, return_value_ptr, object, method TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)


/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define PHALCON_CALL_USER_FUNC(return_value, handler) PHALCON_CALL_USER_FUNC_ARRAY(return_value, handler, NULL)
#define PHALCON_CALL_USER_FUNC_ARRAY(return_value, handler, params) \
	do { \
		if (phalcon_call_user_func_array(return_value, handler, params TSRMLS_CC) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#define PHALCON_CALL_USER_FUNC_ARRAY_NOEX(return_value, handler, params) \
	do { \
		if (phalcon_call_user_func_array_noex(return_value, handler, params TSRMLS_CC) == FAILURE) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)


/** Macros to call functions in the PHP userland */
#define phalcon_call_func_p0_ex(return_value, return_value_ptr, func) \
	do { \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 0, NULL); \
	} while (0)

#define phalcon_call_func_p1_ex(return_value, return_value_ptr, func, p1) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
		} \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 1, p1); \
	} while (0)

#define phalcon_call_func_p2_ex(return_value, return_value_ptr, func, p1, p2) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
		} \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 2, p1, p2); \
	} while (0)

#define phalcon_call_func_p3_ex(return_value, return_value_ptr, func, p1, p2, p3) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
		} \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 3, p1, p2, p3); \
	} while (0)

#define phalcon_call_func_p4_ex(return_value, return_value_ptr, func, p1, p2, p3, p4) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
		} \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 4, p1, p2, p3, p4); \
	} while (0)

#define phalcon_call_func_p5_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
		} \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 5, p1, p2, p3, p4, p5); \
	} while (0)

#define phalcon_call_func_p6_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5, p6) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
			if (Z_TYPE_P(p6)) {} \
		} \
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 6, p1, p2, p3, p4, p5, p6); \
	} while (0)

#define phalcon_call_func_p7_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5, p6, p7) \
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
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 7, p1, p2, p3, p4, p5, p6, p7); \
	} while (0)

#define phalcon_call_func_p8_ex(return_value, return_value_ptr, func, p1, p2, p3, p4, p5, p6, p7, p8) \
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
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, func, 8, p1, p2, p3, p4, p5, p6, p7, p8); \
	} while (0)

#define phalcon_call_func(return_value, func)                                                          phalcon_call_func_p0_ex(return_value, NULL, func)
#define phalcon_call_func_p1(return_value, func, p1)                                                   phalcon_call_func_p1_ex(return_value, NULL, func, p1)
#define phalcon_call_func_p2(return_value, func, p1, p2)                                               phalcon_call_func_p2_ex(return_value, NULL, func, p1, p2)
#define phalcon_call_func_p3(return_value, func, p1, p2, p3)                                           phalcon_call_func_p3_ex(return_value, NULL, func, p1, p2, p3)
#define phalcon_call_func_p4(return_value, func, p1, p2, p3, p4)                                       phalcon_call_func_p4_ex(return_value, NULL, func, p1, p2, p3, p4)
#define phalcon_call_func_p5(return_value, func, p1, p2, p3, p4, p5)                                   phalcon_call_func_p5_ex(return_value, NULL, func, p1, p2, p3, p4, p5)
#define phalcon_call_func_p6(return_value, func, p1, p2, p3, p4, p5, p6)                               phalcon_call_func_p6_ex(return_value, NULL, func, p1, p2, p3, p4, p5, p6)
#define phalcon_call_func_p7(return_value, func, p1, p2, p3, p4, p5, p6, p7)                           phalcon_call_func_p7_ex(return_value, NULL, func, p1, p2, p3, p4, p5, p6, p7)
#define phalcon_call_func_p8(return_value, func, p1, p2, p3, p4, p5, p6, p7, p8)                       phalcon_call_func_p8_ex(return_value, NULL, func, p1, p2, p3, p4, p5, p6, p7, p8)

#define phalcon_call_func_noret(func)                                                                  phalcon_call_func_p0_ex(NULL, NULL, func)
#define phalcon_call_func_p1_noret(func, p1)                                                           phalcon_call_func_p1_ex(NULL, NULL, func, p1)
#define phalcon_call_func_p2_noret(func, p1, p2)                                                       phalcon_call_func_p2_ex(NULL, NULL, func, p1, p2)
#define phalcon_call_func_p3_noret(func, p1, p2, p3)                                                   phalcon_call_func_p3_ex(NULL, NULL, func, p1, p2, p3)
#define phalcon_call_func_p4_noret(func, p1, p2, p3, p4)                                               phalcon_call_func_p4_ex(NULL, NULL, func, p1, p2, p3, p4)
#define phalcon_call_func_p5_noret(func, p1, p2, p3, p4, p5)                                           phalcon_call_func_p5_ex(NULL, NULL, func, p1, p2, p3, p4, p5)
#define phalcon_call_func_p6_noret(func, p1, p2, p3, p4, p5, p6)                                       phalcon_call_func_p6_ex(NULL, NULL, func, p1, p2, p3, p4, p5, p6)
#define phalcon_call_func_p7_noret(func, p1, p2, p3, p4, p5, p6, p7)                                   phalcon_call_func_p7_ex(NULL, NULL, func, p1, p2, p3, p4, p5, p6, p7)
#define phalcon_call_func_p8_noret(func, p1, p2, p3, p4, p5, p6, p7, p8)                               phalcon_call_func_p8_ex(NULL, NULL, func, p1, p2, p3, p4, p5, p6, p7, p8)

/** Macros to call methods in the PHP userland */
#define phalcon_call_method_p0_key_ex(return_value, return_value_ptr, object, method_name, key) \
	do { \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 0, NULL); \
	} while (0)

#define phalcon_call_method_p1_key_ex(return_value, return_value_ptr, object, method_name, key, p1) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 1, p1); \
	} while (0)

#define phalcon_call_method_p2_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 2, p1, p2); \
	} while (0)

#define phalcon_call_method_p3_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 3, p1, p2, p3); \
	} while (0)

#define phalcon_call_method_p4_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3, p4) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 4, p1, p2, p3, p4); \
	} while (0)

#define phalcon_call_method_p5_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3, p4, p5) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 5, p1, p2, p3, p4, p5); \
	} while (0)

#define phalcon_call_method_p0_ex(return_value, return_value_ptr, object, method_name)                               phalcon_call_method_p0_key_ex(return_value, return_value_ptr, object, method_name, 0)
#define phalcon_call_method_p1_ex(return_value, return_value_ptr, object, method_name, p1)                           phalcon_call_method_p1_key_ex(return_value, return_value_ptr, object, method_name, 0, p1)
#define phalcon_call_method_p2_ex(return_value, return_value_ptr, object, method_name, p1, p2)                       phalcon_call_method_p2_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2)
#define phalcon_call_method_p3_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3)                   phalcon_call_method_p3_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3)
#define phalcon_call_method_p4_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3, p4)               phalcon_call_method_p4_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3, p4)
#define phalcon_call_method_p5_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3, p4, p5)           phalcon_call_method_p5_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3, p4, p5)

#define phalcon_call_method(return_value, object, method_name)                                                       phalcon_call_method_p0_ex(return_value, NULL, object, method_name)
#define phalcon_call_method_p1(return_value, object, method_name, p1)                                                phalcon_call_method_p1_ex(return_value, NULL, object, method_name, p1)
#define phalcon_call_method_p2(return_value, object, method_name, p1, p2)                                            phalcon_call_method_p2_ex(return_value, NULL, object, method_name, p1, p2)
#define phalcon_call_method_p3(return_value, object, method_name, p1, p2, p3)                                        phalcon_call_method_p3_ex(return_value, NULL, object, method_name, p1, p2, p3)
#define phalcon_call_method_p4(return_value, object, method_name, p1, p2, p3, p4)                                    phalcon_call_method_p4_ex(return_value, NULL, object, method_name, p1, p2, p3, p4)
#define phalcon_call_method_p5(return_value, object, method_name, p1, p2, p3, p4, p5)                                phalcon_call_method_p5_ex(return_value, NULL, object, method_name, p1, p2, p3, p4, p5)

#define phalcon_call_method_noret(object, method_name)                                                               phalcon_call_method_p0_ex(NULL, NULL, object, method_name)
#define phalcon_call_method_p1_noret(object, method_name, p1)                                                        phalcon_call_method_p1_ex(NULL, NULL, object, method_name, p1)
#define phalcon_call_method_p2_noret(object, method_name, p1, p2)                                                    phalcon_call_method_p2_ex(NULL, NULL, object, method_name, p1, p2)
#define phalcon_call_method_p3_noret(object, method_name, p1, p2, p3)                                                phalcon_call_method_p3_ex(NULL, NULL, object, method_name, p1, p2, p3)
#define phalcon_call_method_p4_noret(object, method_name, p1, p2, p3, p4)                                            phalcon_call_method_p4_ex(NULL, NULL, object, method_name, p1, p2, p3, p4)
#define phalcon_call_method_p5_noret(object, method_name, p1, p2, p3, p4, p5)                                        phalcon_call_method_p5_ex(NULL, NULL, object, method_name, p1, p2, p3, p4, p5)

#define phalcon_call_method_key(return_value, object, method_name, key)                                              phalcon_call_method_p0_key_ex(return_value, NULL, object, method_name, key)
#define phalcon_call_method_p1_key(return_value, object, method_name, key, p1)                                       phalcon_call_method_p1_key_ex(return_value, NULL, object, method_name, key, p1)
#define phalcon_call_method_p2_key(return_value, object, method_name, key, p1, p2)                                   phalcon_call_method_p2_key_ex(return_value, NULL, object, method_name, key, p1, p2)
#define phalcon_call_method_p3_key(return_value, object, method_name, key, p1, p2, p3)                               phalcon_call_method_p3_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3)
#define phalcon_call_method_p4_key(return_value, object, method_name, key, p1, p2, p3, p4)                           phalcon_call_method_p4_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3, p4)
#define phalcon_call_method_p5_key(return_value, object, method_name, key, p1, p2, p3, p4, p5)                       phalcon_call_method_p5_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3, p4, p5)

/** Macros to call methods with zvals as method names */
#define phalcon_call_method_zval(return_value, object, method)                  PHALCON_CALL_ZMETHOD(return_value, NULL, object, method, 0, NULL)
#define phalcon_call_method_zval_p1(return_value, object, method, p1)           PHALCON_CALL_ZMETHOD(return_value, NULL, object, method, 1, p1)
#define phalcon_call_method_zval_p2(return_value, object, method, p1, p2)       PHALCON_CALL_ZMETHOD(return_value, NULL, object, method, 2, p1, p2)
#define phalcon_call_method_zval_p3(return_value, object, method, p1, p2, p3)   PHALCON_CALL_ZMETHOD(return_value, NULL, object, method, 3, p1, p2, p3)

#define phalcon_call_method_zval_noret(object, method)                          PHALCON_CALL_ZMETHOD(NULL, NULL, object, method, 0, NULL)
#define phalcon_call_method_zval_p1_noret(object, method, p1)                   PHALCON_CALL_ZMETHOD(NULL, NULL, object, method, 1, p1)
#define phalcon_call_method_zval_p2_noret(object, method, p1, p2)               PHALCON_CALL_ZMETHOD(NULL, NULL, object, method, 2, p1, p2)
#define phalcon_call_method_zval_p3_noret(object, method, p1, p2, p3)           PHALCON_CALL_ZMETHOD(NULL, NULL, object, method, 3, p1, p2, p3)


/** Use these macros to call functions in the parent class */
#define phalcon_call_parent(return_value, object, active_class, method)                 PHALCON_CALL_PARENT(return_value, NULL, object, active_class, method, 0, NULL)
#define phalcon_call_parent_p1(return_value, object, active_class, method, p1)          PHALCON_CALL_PARENT(return_value, NULL, object, active_class, method, 1, p1)
#define phalcon_call_parent_p2(return_value, object, active_class, method, p1, p2)      PHALCON_CALL_PARENT(return_value, NULL, object, active_class, method, 2, p1, p2)

#define phalcon_call_parent_noret(object, active_class, method)                         PHALCON_CALL_PARENT(NULL, NULL, object, active_class, method, 0, NULL)
#define phalcon_call_parent_p1_noret(object, active_class, method, p1)                  PHALCON_CALL_PARENT(NULL, NULL, object, active_class, method, 1, p1)
#define phalcon_call_parent_p2_noret(object, active_class, method, p1, p2)              PHALCON_CALL_PARENT(NULL, NULL, object, active_class, method, 2, p1, p2)
#define phalcon_call_parent_p3_noret(object, active_class, method, p1, p2, p3)          PHALCON_CALL_PARENT(NULL, NULL, object, active_class, method, 3, p1, p2, p3)
#define phalcon_call_parent_p4_noret(object, active_class, method, p1, p2, p3, p4)      PHALCON_CALL_PARENT(NULL, NULL, object, active_class, method, 4, p1, p2, p3, p4)
#define phalcon_call_parent_p5_noret(object, active_class, method, p1, p2, p3, p4, p5)  PHALCON_CALL_PARENT(NULL, NULL, object, active_class, method, 5, p1, p2, p3, p4, p5)

/** Use these functions to call static functions on the current class */
#define phalcon_call_self(return_value, object, method)                     PHALCON_CALL_SELF(return_value, NULL, object, method, 0, NULL)
#define phalcon_call_self_p1(return_value, object, method, p1)              PHALCON_CALL_SELF(return_value, NULL, object, method, 1, p1)
#define phalcon_call_self_p2(return_value, object, method, p1, p2)          PHALCON_CALL_SELF(return_value, NULL, object, method, 2, p1, p2)
#define phalcon_call_self_p3(return_value, object, method, p1, p2, p3)      PHALCON_CALL_SELF(return_value, NULL, object, method, 3, p1, p2, p3)
#define phalcon_call_self_p4(return_value, object, method, p1, p2, p3, p4)  PHALCON_CALL_SELF(return_value, NULL, object, method, 4, p1, p2, p3, p4)

#define phalcon_call_self_noret(object, method, param_count, params)        PHALCON_CALL_SELF(NULL, NULL, object, method, 0, NULL)
#define phalcon_call_self_p1_noret(object, method, p1)                      PHALCON_CALL_SELF(NULL, NULL, object, method, 1, p1)
#define phalcon_call_self_p2_noret(object, method, p1, p2)                  PHALCON_CALL_SELF(NULL, NULL, object, method, 2, p1, p2)
#define phalcon_call_self_p3_noret(object, method, p1, p2, p3)              PHALCON_CALL_SELF(NULL, NULL, object, method, 3, p1, p2, p3)
#define phalcon_call_self_p4_noret(object, method, p1, p2, p3, p4)          PHALCON_CALL_SELF(NULL, NULL, object, method, 4, p1, p2, p3, p4)

/** Use these macros to call functions statically  */
#define phalcon_call_static(return_value, class_name, method_name)                         PHALCON_CALL_STATIC(return_value, NULL, class_name, method_name, 0, NULL)
#define phalcon_call_static_p1(return_value, class_name, method_name, p1)                  PHALCON_CALL_STATIC(return_value, NULL, class_name, method_name, 1, p1)
#define phalcon_call_static_p2(return_value, class_name, method_name, p1, p2)              PHALCON_CALL_STATIC(return_value, NULL, class_name, method_name, 2, p1, p2)
#define phalcon_call_static_p3(return_value, class_name, method_name, p1, p2, p3)          PHALCON_CALL_STATIC(return_value, NULL, class_name, method_name, 3, p1, p2, p3)
#define phalcon_call_static_p4(return_value, class_name, method_name, p1, p2, p3, p4)      PHALCON_CALL_STATIC(return_value, NULL, class_name, method_name, 4, p1, p2, p3, p4)
#define phalcon_call_static_p5(return_value, class_name, method_name, p1, p2, p3, p4, p5)  PHALCON_CALL_STATIC(return_value, NULL, class_name, method_name, 5, p1, p2, p3, p4, p5)

#define phalcon_call_static_noret(class_name, method_name)                                 PHALCON_CALL_STATIC(NULL, NULL, class_name, method_name, 0, NULL)
#define phalcon_call_static_p1_noret(class_name, method_name, p1)                          PHALCON_CALL_STATIC(NULL, NULL, class_name, method_name, 1, p1)
#define phalcon_call_static_p2_noret(class_name, method_name, p1, p2)                      PHALCON_CALL_STATIC(NULL, NULL, class_name, method_name, 2, p1, p2)
#define phalcon_call_static_p3_noret(class_name, method_name, p1, p2, p3)                  PHALCON_CALL_STATIC(NULL, NULL, class_name, method_name, 3, p1, p2, p3)
#define phalcon_call_static_p4_noret(class_name, method_name, p1, p2, p3, p4)              PHALCON_CALL_STATIC(NULL, NULL, class_name, method_name, 4, p1, p2, p3, p4)
#define phalcon_call_static_p5_noret(class_name, method_name, p1, p2, p3, p4, p5)          PHALCON_CALL_STATIC(NULL, NULL, class_name, method_name, 5, p1, p2, p3, p4, p5)


#define phalcon_call_zval_static(return_value, class_zval, method)         PHALCON_CALL_ZSTATIC(return_value, NULL, class_zval, method, 0, NULL)
#define phalcon_call_zval_static_p1(return_value, class_zval, method, p1)  PHALCON_CALL_ZSTATIC(return_value, NULL, class_zval, method, 1, p1)

#define phalcon_call_zval_str_static_p1(return_value, class_zval, method, p1) PHALCON_CALL_ZSTATIC_STR(return_value, NULL, class_zval, method, 1, p1)

int phalcon_call_func_params(zval *return_value, zval **return_value_ptr, const char *func_name, int func_length TSRMLS_DC, int param_count, ...);
int phalcon_call_method_params(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, int method_len, ulong method_key TSRMLS_DC, int param_count, ...);
int phalcon_call_method_zval_params(zval *return_value, zval **return_value_ptr, zval *object, zval *method TSRMLS_DC, int param_count, ...);
int phalcon_call_parent_func_params(zval *return_value, zval **return_value_ptr, zval *object, zend_class_entry *active_class_ce, const char *method_name, int method_len TSRMLS_DC, int param_count, ...);
int phalcon_call_self_func_params(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, int method_len TSRMLS_DC, int param_count, ...);
int phalcon_call_static_func_params(zval *return_value, zval **return_value_ptr, const char *class_name, int class_length, const char *method_name, int method_length TSRMLS_DC, int param_count, ...);
int phalcon_call_static_zval_func_params(zval *return_value, zval **return_value_ptr, zval *mixed_name, zval *method TSRMLS_DC, int param_count, ...);
int phalcon_call_static_zval_str_func_params(zval *return_value, zval **return_value_ptr, zval *mixed_name, const char *method_name, int method_len TSRMLS_DC, int param_count, ...);

int phalcon_call_method_vparams(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, int method_len, ulong method_key TSRMLS_DC, int param_count, va_list ap);

/** Fast call_user_func_array/call_user_func */
int phalcon_call_user_func_array(zval *return_value, zval *handler, zval *params TSRMLS_DC);
int phalcon_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC);

/** Check constructors */
int phalcon_has_constructor(const zval *object TSRMLS_DC);
int phalcon_has_constructor_ce(zend_class_entry *ce);

/** PHP < 5.3.9 has problems with closures */
#if PHP_VERSION_ID <= 50309
int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
#define PHALCON_ZEND_CALL_FUNCTION_WRAPPER phalcon_call_function
#else
#define PHALCON_ZEND_CALL_FUNCTION_WRAPPER zend_call_function
#endif

#ifndef zend_error_noreturn
#define zend_error_noreturn zend_error
#endif

#endif /* PHALCON_KERNEL_FCALL_H */

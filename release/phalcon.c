
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"


/** Main macros */
#define PHALCON_DEBUG 0

#define PHALCON_NOISY_FETCH 0
#define PHALCON_SILENT_FETCH 1
#define PHALCON_WRITE_FETCH 2

#define PHALCON_CALL_CHECK 1
#define PHALCON_CALL_DEFAULT 0

#define PHALCON_METHOD_CTOR 1
#define PHALCON_METHOD_NORMAL 0

#define PHALCON_INVOKE_THIS 1
#define PHALCON_INVOKE_OTHER 0

#if defined(HAVE_SPL) && ((PHP_MAJOR_VERSION > 5) || (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION >= 1))
extern ZEND_API zend_class_entry *zend_ce_iterator;
extern ZEND_API zend_class_entry *zend_ce_arrayaccess;
extern PHPAPI zend_class_entry *spl_ce_RuntimeException;
extern PHPAPI zend_class_entry *spl_ce_Countable;
extern PHPAPI zend_class_entry *spl_ce_SeekableIterator;
#endif

/** Startup functions */
extern void php_phalcon_init_globals(zend_phalcon_globals *phalcon_globals TSRMLS_DC);

/** Globals functions */
int phalcon_init_global(char *global, int global_length TSRMLS_DC);
int phalcon_get_global(zval *arr, char *global, int global_type TSRMLS_DC);
int phalcon_get_global_by_index(char *global, char *index, zval *result TSRMLS_DC);

int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC);

/** Exception Functions */
extern void phalcon_throw_exception(zval *object TSRMLS_DC);

/** Add functions */
int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);

/** Logical functions */
int phalcon_and_function(zval *result, zval *left, zval *right);

/** Concat functions */
int phalcon_concat_right(zval *result, zval *op1, const char *op2, int op2_length TSRMLS_DC);
int phalcon_concat_left(zval *result, const char *op1, int op1_length, zval *op2 TSRMLS_DC);
int phalcon_concat_both(zval *result, const char *op1, int op1_length, zval *op2, const char *op3, int op3_length TSRMLS_DC);
int phalcon_concat_vboth(zval *result, zval *op1, const char *op2, int op2_length, zval *op3 TSRMLS_DC);

int phalcon_compare_strict_string(zval *op1, char *op2, int op2_length);
int phalcon_is_smaller_strict_long(zval *op1, long op2 TSRMLS_DC);
int phalcon_is_smaller_or_equal_strict_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_file_exists(zval *filename TSRMLS_DC);
extern long phalcon_count(const zval *value);

/** Low level filters */
int phalcon_filter_alphanum(zval *result, zval *param);

/** Compatibility with PHP 5.3 */
#ifndef ZVAL_COPY_VALUE
 #define ZVAL_COPY_VALUE(z, v)\
  (z)->value = (v)->value;\
  Z_TYPE_P(z) = Z_TYPE_P(v);
#endif

#ifndef INIT_PZVAL_COPY
 #define INIT_PZVAL_COPY(z, v) ZVAL_COPY_VALUE(z, v);\
  Z_SET_REFCOUNT_P(z, 1);\
  Z_UNSET_ISREF_P(z);
#endif

/** Operators */
#define PHALCON_COMPARE_STRING(op1, op2) phalcon_compare_strict_string(op1, op2, strlen(op2))
#define PHALCON_CONCAT_RIGHT(result, op1, op2) phalcon_concat_right(result, op1, op2, strlen(op2) TSRMLS_CC)
#define PHALCON_CONCAT_LEFT(result, op1, op2) phalcon_concat_left(result, op1, strlen(op1), op2 TSRMLS_CC)
#define PHALCON_CONCAT_BOTH(result, op1, op2, op3) phalcon_concat_both(result, op1, strlen(op1), op2, op3, strlen(op3) TSRMLS_CC)
#define PHALCON_CONCAT_VBOTH(result, op1, op2, op3) phalcon_concat_vboth(result, op1, op2, strlen(op2), op3 TSRMLS_CC)

/** Constants */
#define PHALCON_GET_CONSTANT(var, name) PHALCON_VAR_INIT(var); zend_get_constant(name, strlen(name), var TSRMLS_CC)
#define PHALCON_GET_CLASS_CONSTANT(var, class_entry, name) PHALCON_VAR_INIT(var); phalcon_get_class_constant(var, class_entry, name, strlen(name) TSRMLS_CC)

/** Symbols */
#define PHALCON_READ_SYMBOL(var, auxarr, name) if(EG(active_symbol_table)){\
			if(zend_hash_find(EG(active_symbol_table), name, sizeof(name), (void **)  &auxarr)==SUCCESS){\
				var = *auxarr;\
			} else {\
				ZVAL_NULL(var);\
			}\
		} else {\
			ZVAL_NULL(var);\
		}

/** Globals */
#define PHALCON_GET_GLOBAL(varr, nglobal, glovar)	phalcon_init_global(nglobal TSRMLS_CC);\
		if(&EG(symbol_table)){\
			if(zend_hash_find(&EG(symbol_table), nglobal, sizeof(nglobal), (void **) &glovar)==SUCCESS){\
				if(Z_TYPE_PP(glovar)==IS_ARRAY){\
					varr = *glovar;\
				} else {\
					PHALCON_INIT_ARRAY(varr);\
				}\
			}\
		} else {\
			PHALCON_INIT_ARRAY(varr);\
		}

#define PHALCON_RETURN_CHECK_CTOR(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		if (Z_TYPE_P(var) > IS_BOOL) {\
			zval_copy_ctor(return_value);\
		}\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
	}\
	PHALCON_MM_RESTORE();\
	return;

#define PHALCON_RETURN_CTOR(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		zval_copy_ctor(return_value);\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
	}\
	PHALCON_MM_RESTORE();\
	return;

#define PHALCON_RETURN_DZVAL(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		zval_copy_ctor(return_value);\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
		PHALCON_MM_RESTORE();\
	}\
	return;

#define PHALCON_RETURN_NCTOR(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
	}\
	PHALCON_MM_RESTORE();\
	return;

/* Utils functions */
int phalcon_inherit_not_found(char *class_name, char *inherit_name);
#define PHALCON_FCALL_MAX_CACHE 128

#define PHALCON_CALL_FUNC(return_value, func_name, fcache_pointer) phalcon_call_func(return_value, func_name, strlen(func_name), 1, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_NORETURN(func_name, fcache_pointer) phalcon_call_func(NULL, func_name, strlen(func_name), 0, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS(return_value, func_name, param_count, params, fcache_pointer) phalcon_call_func_params(return_value, func_name, strlen(func_name), param_count, params, 1, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_NORETURN(func_name, param_count, params, fcache_pointer) phalcon_call_func_params(NULL, func_name, strlen(func_name), param_count, params, 0, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_1(return_value, func_name, param1, fcache_pointer) phalcon_call_func_one_param(return_value, func_name, strlen(func_name), param1, 1, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_1_NORETURN(func_name, param1, fcache_pointer) phalcon_call_func_one_param(NULL, func_name, strlen(func_name), param1, 0, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_2(return_value, func_name, param1, param2, fcache_pointer) phalcon_call_func_two_params(return_value, func_name, strlen(func_name), param1, param2, 1, fcache_pointer TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_2_NORETURN(func_name, param1, param2, fcache_pointer) phalcon_call_func_two_params(NULL, func_name, strlen(func_name), param1, param2, 0, fcache_pointer TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_METHOD(return_value, object, method_name, check) phalcon_call_method(return_value, object, method_name, strlen(method_name), check, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_NORETURN(object, method_name, check) phalcon_call_method(NULL, object, method_name, strlen(method_name), check, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_PARAMS(return_value, object, method_name, param_count, params, check) phalcon_call_method_params(return_value, object, method_name, strlen(method_name), param_count, params, check, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_PARAMS_NORETURN(object, method_name, param_count, params, check) phalcon_call_method_params(NULL, object, method_name, strlen(method_name), param_count, params, check, 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_PARENT_PARAMS(return_value, object, active_class, method_name, param_count, params) phalcon_call_parent_func_params(return_value, object, active_class, strlen(active_class), method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT_PARAMS_NORETURN(object, active_class, method_name, param_count, params) phalcon_call_parent_func_params(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT(return_value, object, active_class, method_name) phalcon_call_parent_func(return_value, object, active_class, strlen(active_class),method_name, strlen(method_name), 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT_NORETURN(object, active_class, method_name) phalcon_call_parent_func(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), 0 TSRMLS_CC); if(EG(exception)) return;

#define PHALCON_CALL_SELF_PARAMS(return_value, object, method_name, param_count, params) phalcon_call_self_func_params(return_value, object, method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_SELF_PARAMS_NORETURN(object, method_name, param_count, params) phalcon_call_self_func_params(NULL, object, method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_SELF(return_value, object, method_name) phalcon_call_self_func(return_value, object, method_name, strlen(method_name), 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_SELF_NORETURN(object, method_name) phalcon_call_self_func(NULL, object, method_name, strlen(method_name), 0 TSRMLS_CC); if(EG(exception)) return;

#define PHALCON_CALL_STATIC_PARAMS(return_value, class_name, method_name, param_count, params) phalcon_call_static_func_params(return_value, class_name, strlen(class_name), method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_PARAMS_NORETURN(class_name, method_name, param_count, params) phalcon_call_static_func_params(NULL, class_name, strlen(class_name), method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC(return_value, class_name, method_name) phalcon_call_static_func(return_value, class_name, strlen(class_name), method_name, strlen(method_name), 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_NORETURN(class_name, method_name) phalcon_call_static_func(NULL, class_name, strlen(class_name), method_name, strlen(method_name), 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_ZVAL_STATIC(return_value, class_zval, method_name) phalcon_call_static_zval_func(return_value, class_zval, method_name, strlen(method_name), 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_ZVAL_PARAMS(return_value, class_zval, method_name, param_count, params) phalcon_call_static_zval_func_params(return_value, class_zval, method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC); if(EG(exception)) return

/** Phalcon function cache */
int phalcon_init_fcall_cache();
int phalcon_free_fcall_cache();

/** Look for call scope */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len TSRMLS_DC);
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC);

/** Call single functions */
int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn, int fcache_pointer TSRMLS_DC);
int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn, int fcache_pointer TSRMLS_DC);
int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn, int fcache_pointer TSRMLS_DC);
int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn, int fcache_pointer TSRMLS_DC);

/** Call methods on object instances */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC);
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC);

/** Call methods on parent class */
int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, int active_class_len,char *method_name, int method_len, int noreturn TSRMLS_DC);
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);

/** Call methods on self class */
int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int method_len, int noreturn TSRMLS_DC);
int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);

/** Call methods on static classes */
int phalcon_call_static_func(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, int noreturn TSRMLS_DC);
int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int method_len, int noreturn TSRMLS_DC);
int phalcon_call_static_func_params(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);

/** Call function applying zend_fcall_info_cache */
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table, zend_fcall_info_cache *fci_cache TSRMLS_DC);
int phalcon_require(zval *require_path TSRMLS_DC);
int phalcon_spprintf(char **message, int max_len, char *format, ...);

#ifndef PHALCON_RELEASE

#define PHV(v) phalcon_vdump(v)
#define PHPR(v) phalcon_print_r(v)

typedef struct _phalcon_debug_entry {
	char *class_name;
	char *method_name;
	int lineno;
	struct _phalcon_debug_entry *prev;
	struct _phalcon_debug_entry *next;
} phalcon_debug_entry;

int phalcon_start_debug();
int phalcon_stop_debug();

int phalcon_print_r(zval *userval TSRMLS_DC);
int phalcon_vdump(zval *uservar TSRMLS_DC);
int phalcon_debug_assign(char *name, zval *value TSRMLS_DC);
int phalcon_vpdump(const zval **uservar TSRMLS_DC);
int phalcon_dump_ce(zend_class_entry *ce TSRMLS_DC);
int phalcon_class_debug(zval *val TSRMLS_DC);

int phalcon_debug_backtrace_internal();
int phalcon_debug_str(char *what, char *message);
int phalcon_debug_long(char *what, uint vlong);
int phalcon_debug_screen(char *message);

int phalcon_step_over(char *message);
int phalcon_step_into(char *message);
int phalcon_step_out(char *message);

int phalcon_step_into_entry(char *class_name, char *method_name, int lineno);
int phalcon_step_out_entry();

int phalcon_debug_method_call(zval *obj, char *method_name TSRMLS_DC);
int phalcon_debug_vdump(char *preffix, zval *value TSRMLS_DC);
int phalcon_debug_param(zval *param TSRMLS_DC);

int phalcon_error_space();
int phalcon_debug_space();

extern FILE *phalcon_log;
int phalcon_debug_trace;
extern phalcon_debug_entry *start;
extern phalcon_debug_entry *active;

#endif

#ifndef PHALCON_RELEASE

int phalcon_assert_class(zval *object, char *class_name TSRMLS_DC);

#endif
/** Reads properties */
#define PHALCON_READ_PROPERTY_NOISY(result, object, property_name, property_length) PHALCON_VAR_INIT(result); phalcon_read_property(result, object, property_name, property_length, PHALCON_NOISY_FETCH TSRMLS_CC);
#define PHALCON_READ_PROPERTY_SILENT(result, object, property_name, property_length) PHALCON_VAR_INIT(result); phalcon_read_property(result, object, property_name, property_length, PHALCON_SILENT_FETCH TSRMLS_CC);

#define PHALCON_UPDATE_PROPERTY_CPY(object, property_name, value) {\
    zval *copy;\
    ALLOC_ZVAL(copy);\
    ZVAL_ZVAL(copy, value, 1, 0);\
    phalcon_update_property_zval_cpy(object, property_name, strlen(property_name), copy TSRMLS_CC);\
  }

/** New */
#define PHALCON_NEW_STD(object) PHALCON_ALLOC_ZVAL(object); object_init(object)
#define PHALCON_NEW(object, class) PHALCON_ALLOC_ZVAL(object); object_init_ex(object, class)


/** Instance of */
#define PHALCON_INSTANCE_OF(result, var, class) if(Z_TYPE_P(var)!=IS_OBJECT){\
      zend_error(E_ERROR, "instanceof expects an object instance, constant given");\
    } else {\
      PHALCON_RESULT_INIT(result);\
      ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(var), class TSRMLS_CC));\
    }


int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC);
int phalcon_class_exists(zval *return_value, zval *class_name_zval, zval *autoload_zval TSRMLS_DC);
int phalcon_clone(zval *destiny, zval *obj TSRMLS_DC);

int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC);
int phalcon_method_exists_ex(zval *object, char *method_name, int method_len TSRMLS_DC);

int phalcon_isset_property(zval *object, char *property_name, int property_length TSRMLS_DC);
int phalcon_isset_property_zval(zval *object, zval *property TSRMLS_DC);

int phalcon_read_property(zval **result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC);
int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC);

int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC);
int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC);
int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC);



#define PHALCON_ARRAY_UPDATE(arr, index, value) {\
	zval *copy;\
	ALLOC_ZVAL(copy);\
	ZVAL_ZVAL(copy, value, 1, 0);\
	phalcon_array_update_cpy(arr, index, copy TSRMLS_CC);\
}

/** Check for index existence */
int phalcon_array_isset(const zval *arr, zval *index);
int phalcon_array_isset_long(const zval *arr, ulong index);
int phalcon_array_isset_string(const zval *arr, char *index, uint index_length);

/** Unsets existing indexes */
int phalcon_array_unset(zval *arr, zval *index);
int phalcon_array_unset_long(zval *arr, ulong index);
int phalcon_array_unset_string(zval *arr, char *index, uint index_length);

/** Appends Element to arrays */
int phalcon_array_append(zval *arr, zval *value TSRMLS_DC);

/** Modifies arrays */
int phalcon_array_update(zval *arr, zval *index, zval *value TSRMLS_DC);
int phalcon_array_update_string(zval *arr, char *index, uint index_length, zval *value TSRMLS_DC);
int phalcon_array_update_long(zval *arr, ulong index, zval *value TSRMLS_DC);

/** Fetches items for arrays */
int phalcon_array_fetch(zval **return_value, const zval *arr, zval *index, int silent TSRMLS_DC);
int phalcon_array_fetch_string(zval **return_value, const zval *arr, char *index, uint index_length, int silent TSRMLS_DC);
int phalcon_array_fetch_long(zval **return_value, const zval *arr, ulong index, int silent TSRMLS_DC);

int phalcon_memory_grow_stack(TSRMLS_D);
int phalcon_memory_restore_stack(TSRMLS_D);

int phalcon_memory_observe(zval **var TSRMLS_DC);
int phalcon_memory_remove(zval **var TSRMLS_DC);

#define PHALCON_MM_GROW() phalcon_memory_grow_stack(TSRMLS_C)
#define PHALCON_MM_RESTORE() phalcon_memory_restore_stack(TSRMLS_C)

/** Memory macros */
#define PHALCON_ALLOC_ZVAL(z) \
	ALLOC_ZVAL(z); INIT_PZVAL(z);

#define PHALCON_INIT_VAR(z)\
	if (z) {\
		if (Z_REFCOUNT_P(z) > 1) {\
			Z_DELREF_P(z);\
			ALLOC_ZVAL(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		} else {\
			zval_ptr_dtor(&z);\
			PHALCON_ALLOC_ZVAL(z);\
		}\
	} else {\
		phalcon_memory_observe(&z TSRMLS_CC);\
		PHALCON_ALLOC_ZVAL(z);\
	}

#define PHALCON_INIT_VAR(z)\
	if (z) {\
		if (Z_REFCOUNT_P(z) > 1) {\
			Z_DELREF_P(z);\
			ALLOC_ZVAL(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		} else {\
			zval_ptr_dtor(&z);\
			PHALCON_ALLOC_ZVAL(z);\
		}\
	} else {\
		phalcon_memory_observe(&z TSRMLS_CC);\
		PHALCON_ALLOC_ZVAL(z);\
	}

#define PHALCON_ALLOC_ZVAL_MM(z) \
	PHALCON_ALLOC_ZVAL(z); \
	phalcon_memory_observe(&z TSRMLS_CC);

#define PHALCON_CPY_WRT(d, v) \
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zval_ptr_dtor(&d); \
		} \
	} else { \
		phalcon_memory_observe(&d TSRMLS_CC); \
	} \
	Z_ADDREF_P(v); \
	d = v;

#define PHALCON_SEPARATE_ARRAY(a) \
	{\
		if (Z_REFCOUNT_P(a) > 1) {\
			zval *new_zv;\
			Z_DELREF_P(a);\
			ALLOC_ZVAL(new_zv);\
			INIT_PZVAL_COPY(new_zv, a);\
			a = new_zv;\
			zval_copy_ctor(new_zv);\
		}\
	}

#define PHALCON_SEPARATE(z) \
	{\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			Z_DELREF_P(orig_ptr);\
			ALLOC_ZVAL(z);\
			phalcon_memory_observe(&z TSRMLS_CC);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}

#define PHALCON_SEPARATE_NMO(z) \
	{\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			Z_DELREF_P(orig_ptr);\
			ALLOC_ZVAL(z);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}

#define PHALCON_SEPARATE_PARAM(z) \
	{\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			ALLOC_ZVAL(z);\
			phalcon_memory_observe(&z TSRMLS_CC);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}

#define PHALCON_SEPARATE_PARAM_NMO(z) {\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			ALLOC_ZVAL(z);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}


#ifdef HAVE_CONFIG_H
#endif


/**
 * Initialize globals on each request or each thread started
 */
void php_phalcon_init_globals(zend_phalcon_globals *phalcon_globals TSRMLS_DC){
    phalcon_globals->phalcon_memory_stack = 0;
    phalcon_globals->start_memory = NULL;
	phalcon_globals->active_memory = NULL;
}

/**
 * Initilializes super global variables if doesn't
 */
int phalcon_init_global(char *global, int global_length TSRMLS_DC){
	#if PHP_VERSION_ID < 50400
	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));
	if (jit_initialization) {
		return zend_is_auto_global(global, global_length-1 TSRMLS_CC);
	}
	#else
	if (PG(auto_globals_jit)) {
		return zend_is_auto_global(global, global_length-1 TSRMLS_CC);
	}
	#endif
	return SUCCESS;
}

/**
 * Gets the global zval into PG macro
 */
int phalcon_get_global(zval *arr, char *global, int global_type TSRMLS_DC){
	#if PHP_VERSION_ID < 50400
	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));
	if (jit_initialization) {
		zend_is_auto_global(global, sizeof(global)-1 TSRMLS_CC);
	}
	#else
	if (PG(auto_globals_jit)) {
		zend_is_auto_global(global, sizeof(global)-1 TSRMLS_CC);
	}
	#endif
	arr = PG(http_globals)[global_type];
	return SUCCESS;
}

/**
 * Get a super global zval by its name
 */
int phalcon_get_global_by_index(char *global, char *index, zval *result TSRMLS_DC){
	zval **global_vars;
	if (zend_hash_find(&EG(symbol_table), global, sizeof(global), (void **) &global_vars) == SUCCESS) {
		if (Z_TYPE_PP(global_vars) == IS_ARRAY) {
			return zend_hash_find(Z_ARRVAL_PP(global_vars), index, sizeof(index), (void **) &result);
		}
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can't find superglobal: %s", global);
		ZVAL_NULL(result);
	}
	return FAILURE;
}

/**
 * Reads class constant from string name and returns its value
 */
int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC){

	zval **result_ptr;

	if (zend_hash_find(&ce->constants_table, constant_name, constant_length+1, (void **) &result_ptr) != SUCCESS) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Undefined class constant '%s::%s'", ce->name, constant_name);
		return FAILURE;
	} else {
		ZVAL_ZVAL(return_value, *result_ptr, 1, 0);
	}

	return SUCCESS;
}

/**
 * Throws an zval object as exception
 */
void phalcon_throw_exception(zval *object TSRMLS_DC){
	zend_throw_exception_object(object TSRMLS_CC);
	Z_ADDREF_P(object);
	PHALCON_MM_RESTORE();
}

/**
 * Makes fast count on implicit array types
 */
long phalcon_count(const zval *value){
	if (Z_TYPE_P(value) == IS_ARRAY) {
		return zend_hash_num_elements(Z_ARRVAL_P(value));
	} else {
		if (Z_TYPE_P(value) == IS_NULL) {
			return 0;
		}
	}
	return 1;
}

/**
 * Performs logical AND function operator
 */
int phalcon_and_function(zval *result, zval *left, zval *right){
	int istrue = 1;
	istrue = zend_is_true(left);
	if (istrue) {
		istrue = zend_is_true(right);
	}
	ZVAL_BOOL(result, istrue);
	return SUCCESS;
}

/**
 * Performs fast concat when right operator is char constant
 */
int phalcon_concat_right(zval *result, zval *op1, const char *op2, int op2_length TSRMLS_DC){

	zval op1_copy;
	int use_copy1 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
	}

	if (use_copy1) {
		op1 = &op1_copy;
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_length);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	return SUCCESS;
}

/**
 * Performs fast concat when left operator is char constant
 */
int phalcon_concat_left(zval *result, const char *op1, int op1_length, zval *op2 TSRMLS_DC){

	zval op2_copy;
	int use_copy2 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
	}

	if (use_copy2) {
		op2 = &op2_copy;
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op2) + op1_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_length);
	memcpy(Z_STRVAL_P(result)+op1_length, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	return SUCCESS;
}

/**
 * Performs fast concat when left and right operator are char constants
 */
int phalcon_concat_both(zval *result, const char *op1, int op1_length, zval *op2, const char *op3, int op3_length TSRMLS_DC){

	zval op2_copy;
	int use_copy2 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
	}

	if (use_copy2) {
		op2 = &op2_copy;
	}

	Z_STRLEN_P(result) = op1_length + Z_STRLEN_P(op2) + op3_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_length);
	memcpy(Z_STRVAL_P(result)+op1_length, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_length+Z_STRLEN_P(op2), op3, op3_length);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	return SUCCESS;

}

/**
 * Performs fast concat when left and right operator are zvals
 */
int phalcon_concat_vboth(zval *result, zval *op1, const char *op2, int op2_length, zval *op3 TSRMLS_DC){

	zval op1_copy, op3_copy;
	int use_copy1 = 0, use_copy3 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
	}

	if (use_copy1) {
		op1 = &op1_copy;
	}

	if (use_copy3) {
		op3 = &op3_copy;
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_length + Z_STRLEN_P(op3);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_length);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_length, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

	return SUCCESS;

}

/**
 * Natural compare with string operadus on right
 */
int phalcon_compare_strict_string(zval *op1, char *op2, int op2_length){

	switch(Z_TYPE_P(op1)){
		case IS_STRING:
			if (!Z_STRLEN_P(op1) && !op2_length) {
				return 1;
			}
			if (Z_STRLEN_P(op1) != op2_length) {
				return 0;
			}
			return zend_binary_strcmp(Z_STRVAL_P(op1), Z_STRLEN_P(op1), op2, op2_length)==0;
		case IS_NULL:
			return zend_binary_strcmp("", 0, op2, op2_length)==0;
		case IS_BOOL:
			if (!Z_BVAL_P(op1)) {
				return zend_binary_strcmp("0", strlen("0"), op2, op2_length)==0;
			} else {
				return zend_binary_strcmp("1", strlen("1"), op2, op2_length)==0;
			}
	}

	return 0;
}

/**
 * Natural is smaller compare with long operadus on right
 */
int phalcon_is_smaller_strict_long(zval *op1, long op2 TSRMLS_DC){

	zval *op2_tmp, *result;
	int bool_result;

	switch(Z_TYPE_P(op1)){
		case IS_LONG:
			return Z_LVAL_P(op1) < op2;
		case IS_DOUBLE:
			return Z_LVAL_P(op1) < (double) op2;
		case IS_NULL:
			return 0 < op2;
		case IS_BOOL:
			if (Z_BVAL_P(op1)) {
				return 0 < op2;
			} else {
				return 1 < op2;
			}
		default:
			ALLOC_INIT_ZVAL(result);
			ALLOC_INIT_ZVAL(op2_tmp);
			ZVAL_LONG(op2_tmp, op2);
			is_smaller_function(result, op1, op2_tmp TSRMLS_CC);
			bool_result = Z_BVAL_P(result);
			zval_ptr_dtor(&result);
			zval_ptr_dtor(&op2_tmp);
			return bool_result;
	}

}

/**
 * Natural is smaller or equal compare with long operadus on right
 */
int phalcon_is_smaller_or_equal_strict_long(zval *op1, long op2 TSRMLS_DC){

	zval *op2_tmp, *result;
	int bool_result;

	switch(Z_TYPE_P(op1)){
		case IS_LONG:
			return Z_LVAL_P(op1) <= op2;
		case IS_DOUBLE:
			return Z_DVAL_P(op1) <= (double) op2;
		case IS_NULL:
			return 0 < op2;
		case IS_BOOL:
			if (Z_BVAL_P(op1)) {
				return 0 <= op2;
			} else {
				return 1 <= op2;
			}
		default:
			ALLOC_INIT_ZVAL(result);
			ALLOC_INIT_ZVAL(op2_tmp);
			ZVAL_LONG(op2_tmp, op2);
			is_smaller_or_equal_function(result, op1, op2_tmp TSRMLS_CC);
			bool_result = Z_BVAL_P(result);
			zval_ptr_dtor(&result);
			zval_ptr_dtor(&op2_tmp);
			return bool_result;
	}

}

/**
 * Do add function keeping ref_count and is_ref
 */
int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC){
	int status;
	int ref_count = Z_REFCOUNT_P(result);
	int is_ref = Z_ISREF_P(result);
	status = add_function(result, op1, op2 TSRMLS_CC);
	Z_SET_REFCOUNT_P(result, ref_count);
	Z_SET_ISREF_TO_P(result, is_ref);
	return status;
}

/**
 * Inmediate function resolution for addslaches function
 */
int phalcon_addslashes(zval *return_value, zval *param TSRMLS_DC){

	if (Z_TYPE_P(param) != IS_STRING) {
		return FAILURE;
	}

	//ZVAL_STRING(return_value, php_addslashes(Z_STRVAL_P(param), Z_STRLEN_P(param), &Z_STRLEN_P(return_value), 0 TSRMLS_CC), 0);

	return SUCCESS;
}

/**
 * Checks if a file exists
 *
 */
int phalcon_file_exists(zval *filename TSRMLS_DC){

	if (Z_TYPE_P(filename) != IS_STRING) {
		return FAILURE;
	}

	if (VCWD_ACCESS(Z_STRVAL_P(filename), F_OK)==0) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Filter alphanum string
 */
int phalcon_filter_alphanum(zval *result, zval *param){

	int i, ch, alloc = 0;
	char temp[255];

	if (Z_TYPE_P(param) == IS_STRING) {
		for(i=0; i < Z_STRLEN_P(param) && i < 255;i++){
			ch = Z_STRVAL_P(param)[i];
			if((ch>96&&ch<123)||(ch>64&&ch<91)||(ch>47&&ch<58)){
				temp[alloc] = ch;
				alloc++;
			}
		}
	}

	if (alloc > 0) {
		Z_TYPE_P(result) = IS_STRING;
		Z_STRLEN_P(result) = alloc;
		Z_STRVAL_P(result) = (char *) emalloc(alloc+1);
		memcpy(Z_STRVAL_P(result), temp, alloc);
		Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	} else {
		ZVAL_STRING(result, "", 1);
	}

	return SUCCESS;
}

/**
 * Generates error when inherited class isn't found
 */
int phalcon_inherit_not_found(char *class_name, char *inherit_name){
	fprintf(stderr, "Phalcon Error: Extended class '%s' not found when registering class '%s'", class_name, inherit_name);
	return SUCCESS;
}
#ifdef HAVE_CONFIG_H
#endif


/**
 * Current fcall pointer
 */
int phalcon_fcall_pointer = 0;

/**
 * Global zend_fcall_info_cache for current execution
 */
zend_fcall_info_cache *phalcon_fcall_cache[PHALCON_FCALL_MAX_CACHE];

/**
 * Initializes fcall cache
 */
int phalcon_init_fcall_cache(){
	register int i;
	for(i=0;i<PHALCON_FCALL_MAX_CACHE;i++){
		phalcon_fcall_cache[i] = NULL;
	}
	return SUCCESS;
}

/**
 * Frees fcall cache
 */
int phalcon_free_fcall_cache(){
	register int i;
	for(i=0;i<PHALCON_FCALL_MAX_CACHE;i++){
		if(phalcon_fcall_cache[i]){
			efree(phalcon_fcall_cache[i]);
		}
	}
	return SUCCESS;
}

/**
 * Lookups a function call and caches its zend_fcall_info_cache for further calls
 */
int phalcon_cache_lookup_function(zval *fn, int fcache_pointer TSRMLS_DC){
	if(!phalcon_fcall_cache[fcache_pointer]){
		{
			char *callable_name;
			char *error = NULL;

			phalcon_fcall_cache[fcache_pointer] = emalloc(sizeof(zend_fcall_info_cache));
			if (!zend_is_callable_ex(fn, NULL, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, phalcon_fcall_cache[fcache_pointer], &error TSRMLS_CC)) {
				if (error) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid callback %s, %s", callable_name, error);
					efree(error);
					return FAILURE;
				}
			}

			efree(callable_name);
		}
	}
	return SUCCESS;
}

/**
 * Finds the correct scope to execute the function
 */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len TSRMLS_DC){
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	while (ce) {
		if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {
			EG(scope) = ce;
			efree(lcname);
			return SUCCESS;
		}
		ce = ce->parent;
	}
	if (lcname) {
		efree(lcname);
	}
	return FAILURE;
}

/**
 * Find function scope on parent classes
 */
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC){
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	while (ce) {
		if (!zend_binary_strcasecmp(ce->name, ce->name_length, active_class, active_class_len)) {
			if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {
				EG(scope) = ce;
				efree(lcname);
				return SUCCESS;
			}
		}
		ce = ce->parent;
	}
	if (lcname) {
		efree(lcname);
	}
	return FAILURE;
}

/**
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn, int fcache_pointer TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zval *local_retval_ptr = NULL;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	/*status = phalcon_cache_lookup_function(fn, fcache_pointer);
	if (status == FAILURE) {
		return FAILURE;
	}*/

	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	//status = phalcon_call_user_function_ex(CG(function_table), NULL, fn, &local_retval_ptr, 0, NULL, 1, NULL, phalcon_fcall_cache[fcache_pointer] TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires arbitrary number of parameters
 */
int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn, int fcache_pointer TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	//zval ***params_array;
	zval *local_retval_ptr = NULL;
	//int i;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	/*status = phalcon_cache_lookup_function(fn, fcache_pointer);
	if (status == FAILURE) {
		return FAILURE;
	}*/

	/*if(param_count){
		params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
		for (i=0; i<param_count; i++) {
			params_array[i] = &params[i];
		}
	} else {
		params_array = NULL;
	}*/

	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	//status = phalcon_call_user_function_ex(CG(function_table), NULL, fn, &local_retval_ptr, param_count, params_array, 1, NULL, phalcon_fcall_cache[fcache_pointer] TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	/*if (params_array) {
		efree(params_array);
	}*/

	return status;
}

/**
 * Call single function which requires only 1 parameter
 */
int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn, int fcache_pointer TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_func_params(return_value, func_name, func_length, 1, params, noreturn, fcache_pointer TSRMLS_CC);
}

/**
 * Call single function which requires only 2 parameters
 */
int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn, int fcache_pointer TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_func_params(return_value, func_name, func_length, 2, params, noreturn, fcache_pointer TSRMLS_CC);
}

/**
 * Call method on an object which not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)) {
			return FAILURE;
		}
	}

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, method_name, method_len, 1);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, 0, NULL TSRMLS_CC);
		if (status == FAILURE) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s()", Z_STRVAL_P(fn));
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which requires parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, method_len+1)) {
			return FAILURE;
		}
	}

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, method_name, method_len, 1);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, param_count, params TSRMLS_CC);
		if (status == FAILURE) {
			EG(scope) = active_scope;
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", Z_STRVAL_P(fn), Z_OBJCE_P(object)->name);
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call parent static function which not requires parameters
 */
int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, active_class_len, method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "parent", strlen("parent"), method_name, method_len, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call parent static function which requires parameters
 */
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, active_class_len, method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "parent", strlen("parent"), method_name, method_len, param_count, params, noreturn TSRMLS_CC);
	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which not requires parameters
 */
int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int method_len, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "self", strlen("self"), method_name, method_len, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which requires parameters
 */
int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "self", strlen("self"), method_name, method_len, param_count, params, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call single static function which not requires parameters
 */
int phalcon_call_static_func(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, class_name, class_length, 1);
	add_next_index_stringl(fn, method_name, method_len, 1);
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function on a zval which not requires parameters
 */
int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int method_len, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_zval(fn, mixed_name);
	add_next_index_stringl(fn, method_name, method_len, 1);
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function on a zval which requires parameters
 */
int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_zval(fn, mixed_name);
	add_next_index_stringl(fn, method_name, method_len, 1);
	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function which requires parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, class_name, class_length, 1);
	add_next_index_stringl(fn, method_name, method_len, 1);

	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function direct on a zend_class_entry which requires parameters
 */
int phalcon_call_static_ce_func_params(zval *return_value, zend_class_entry *ce, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, ce->name, ce->name_length, 0);
	add_next_index_stringl(fn, method_name, method_len, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", ce->name, method_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;

}

/**
 * Call single function on zval which requires parameters
 */
int phalcon_call_static_func_zval_params(zval *return_value, zval *mixed_name, char *method_name, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	status = call_user_function(CG(function_table), NULL, mixed_name, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", method_name);
		}
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Executes zend_function with a prepared fci_cache
 */
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table, zend_fcall_info_cache *fci_cache TSRMLS_DC){

	zend_fcall_info fci;

	fci.size = sizeof(fci);
	fci.function_table = function_table;
	fci.object_ptr = object_pp ? *object_pp : NULL;
	fci.function_name = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr;
	fci.param_count = param_count;
	fci.params = params;
	fci.no_separation = (zend_bool) no_separation;
	fci.symbol_table = symbol_table;

	return zend_call_function(&fci, fci_cache TSRMLS_CC);
}
#ifdef HAVE_CONFIG_H
#endif


/**
 * Do an internal require to a plain php file
 *
 */
int phalcon_require(zval *require_path TSRMLS_DC){

	int ret;
	char *file_path;
	int file_path_length;
	zend_file_handle file_handle;
	zval *result = NULL;
	
	zval **original_return_value = EG(return_value_ptr_ptr);
  zend_op **original_opline_ptr = EG(opline_ptr);
  zend_op_array *original_active_op_array = EG(active_op_array);

	zend_op_array *new_op_array = NULL;	

	if (Z_TYPE_P(require_path) != IS_STRING) {
    php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid require path value");
    return FAILURE;
	}	

	file_path = Z_STRVAL_P(require_path);
	file_path_length = Z_STRLEN_P(require_path);

	ret = php_stream_open_for_zend_ex(file_path, &file_handle, ENFORCE_SAFE_MODE|USE_PATH|STREAM_OPEN_FOR_INCLUDE TSRMLS_CC);
	if (ret==SUCCESS) {

		if(!file_handle.opened_path){
			file_handle.opened_path = estrndup(file_path, file_path_length);
		}

		EG(exit_status) = 0;
		PG(during_request_startup) = 0;

		if(file_handle.filename && (file_handle.filename[0] != '-' || file_handle.filename[1] != 0) && file_handle.opened_path == NULL && file_handle.type != ZEND_HANDLE_FILENAME){
			char realfile[MAXPATHLEN];
			int realfile_len;
			int dummy = 1;
			if(expand_filepath(file_handle.filename, realfile TSRMLS_CC)){
				realfile_len =  strlen(realfile);
				zend_hash_add(&EG(included_files), realfile, realfile_len+1, (void *)&dummy, sizeof(int), NULL);
				file_handle.opened_path = estrndup(realfile, realfile_len);
			}
		}		
    
    new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
    zend_destroy_file_handle(&file_handle TSRMLS_CC);    

    if (new_op_array) {
    		
      EG(return_value_ptr_ptr) = &result;
      EG(active_op_array) = new_op_array;
      if (!EG(active_symbol_table)) {
        zend_rebuild_symbol_table(TSRMLS_C);
      }

      zend_execute(new_op_array TSRMLS_CC);

    	destroy_op_array(new_op_array TSRMLS_CC);
    	efree(new_op_array);
    	if (!EG(exception)) {
    		if (EG(return_value_ptr_ptr)) {
    			zval_ptr_dtor(EG(return_value_ptr_ptr));
    		}
      }

    } 

		EG(return_value_ptr_ptr) = original_return_value;
    EG(opline_ptr) = original_opline_ptr;
    EG(active_op_array) = original_active_op_array;

		return SUCCESS;
	}

	return FAILURE;

}

#ifdef HAVE_CONFIG_H
#endif


/**
 * Applies sprintf function to a variable list
 */
int phalcon_spprintf(char **message, int max_len, char *format, ...){
	va_list arg;
	int len;

	va_start(arg, format);
	len = vspprintf(message, max_len, format, arg);
	va_end(arg);
	return len;
}

#ifndef PHALCON_RELEASE

FILE *phalcon_log = NULL;
int phalcon_debug_trace = 0;
phalcon_debug_entry *start = NULL;
phalcon_debug_entry *active = NULL;

/**
 * Stars debug on file pipe
 */
int phalcon_start_debug(){
	if(!phalcon_log){
		/*//phalcon_log = fopen("/home/gutierrezandresfelipe/phalcon-debug.a", "w");
		phalcon_log = fopen("/tmp/phalcon-debug.a", "w");
		if(!phalcon_log){
			fprintf(stderr, "Can't open debug log\n");
		}*/
		phalcon_log = stderr;
	}
	return SUCCESS;
}

/**
 * Stops debug process
 */
int phalcon_stop_debug(){
	phalcon_debug_entry *ptr = active;
	phalcon_debug_entry *this_entry = NULL;
	while(ptr){
		this_entry = ptr;
		ptr = ptr->prev;
		efree(this_entry);
	}
	//fclose(phalcon_log);
	phalcon_log = NULL;
	return SUCCESS;
}

/**
 * Executes a print_r on an interal zval
 */
int phalcon_print_r(zval *userval TSRMLS_DC){
	zend_print_zval_r(userval, 0 TSRMLS_CC);
	return SUCCESS;
}

/**
 * Internal fast zval dump
 */
int phalcon_vdump(zval *uservar TSRMLS_DC){
	phalcon_start_debug();
    if(!uservar){
		fprintf(phalcon_log, "Null pointer\n");
		return SUCCESS;
	}
    switch(Z_TYPE_P(uservar)){
        case IS_NULL:
            fprintf(phalcon_log, "NULL \n");
            break;
        case IS_BOOL:
            fprintf(phalcon_log, "Boolean: %s\n", Z_LVAL_P(uservar) ? "TRUE" : "FALSE");
            break;
        case IS_LONG:
            fprintf(phalcon_log, "Long: %ld at %p, refcount=%d\n", Z_LVAL_P(uservar), uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_DOUBLE:
            fprintf(phalcon_log, "Double: %f\n", Z_DVAL_P(uservar));
            break;
        case IS_STRING:
			fprintf(phalcon_log, "String: %s(%d) at %p, refcount=%d\n", Z_STRVAL_P(uservar), Z_STRLEN_P(uservar), uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_RESOURCE:
            fprintf(phalcon_log, "Resource\n");
            break;
        case IS_ARRAY:
            fprintf(phalcon_log, "Array at %p, refcount=%d\n", uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_OBJECT:
            fprintf(phalcon_log, "Object <%s> at %p\n", Z_OBJCE_P(uservar)->name, uservar);
            break;
        default:
            fprintf(phalcon_log, "Unknown\n");
    }
    return SUCCESS;
}

/**
 * Internal fast zval dump
 */
int phalcon_vpdump(const zval **uservar TSRMLS_DC){
     if(!uservar){
		fprintf(phalcon_log, "Null pointer");
		return SUCCESS;
     }
     switch(Z_TYPE_PP(uservar)){
        case IS_NULL:
            fprintf(phalcon_log, "NULL\n");
            break;
        case IS_BOOL:
            fprintf(phalcon_log, "Boolean: %s\n", Z_LVAL_PP(uservar) ? "TRUE" : "FALSE");
            break;
        case IS_LONG:
            fprintf(phalcon_log, "Long: %ld\n", Z_LVAL_PP(uservar));
            break;
        case IS_DOUBLE:
            fprintf(phalcon_log, "Double: %f\n", Z_DVAL_PP(uservar));
            break;
        case IS_STRING:
            fprintf(phalcon_log, "String: %s\n", Z_STRVAL_PP(uservar));
            break;
        case IS_RESOURCE:
            fprintf(phalcon_log, "Resource\n");
            break;
        case IS_ARRAY:
            fprintf(phalcon_log, "Array\n");
            break;
        case IS_OBJECT:
            fprintf(phalcon_log, "Object\n");
            break;
        default:
            fprintf(phalcon_log, "Unknown\n");
    }
    return SUCCESS;
}

int phalcon_dump_ce(zend_class_entry *ce TSRMLS_DC){
	char *message = emalloc(sizeof(char *)*120);
	if(ce){
		sprintf(message, "- ClassType => %d", ce->type);
		phalcon_step_over(message);
		if(ce->name){
			sprintf(message, "- ClassName => %s", ce->name);
			phalcon_step_over(message);
		} else {
			phalcon_step_over("- ClassName => NULL");
		}
	} else {
		phalcon_step_over("- NULL class entry :(");
	}
	return SUCCESS;
}

int phalcon_class_debug(zval *val TSRMLS_DC){
	char *message = emalloc(sizeof(char *)*120);
	zend_class_entry *ce;
	if(val){
		ce = Z_OBJCE_P(val);
		if(ce){
			sprintf(message, "- MemoryAddress => %p", val);
			phalcon_step_over(message);
			phalcon_dump_ce(ce TSRMLS_CC);
		} else {
			phalcon_step_over("- No class entry :(");
		}
	} else {
		phalcon_step_over("- this_ptr is null :(");
	}
	return SUCCESS;
}

/**
 * Append debug information to file
 */
int phalcon_debug_str(char *what, char *message){
	fprintf(phalcon_log, "%s", what);
	fprintf(phalcon_log, "%s", message);
	fprintf(phalcon_log, "\n");
	return SUCCESS;
}

int phalcon_debug_long(char *what, uint vlong){
	fprintf(phalcon_log, "%s", what);
	fprintf(phalcon_log, "%u", vlong);
	fprintf(phalcon_log, "\n");
	return SUCCESS;
}

int phalcon_debug_screen(char *message){
	phalcon_debug_space();
	fprintf(phalcon_log, "%s\n", message);
	return SUCCESS;
}

int phalcon_debug_method_call(zval *obj, char *method_name TSRMLS_DC){
	if(Z_TYPE_P(obj)==IS_OBJECT){
		phalcon_debug_space();
	} else {
		phalcon_error_space();
	}
	if(Z_TYPE_P(obj)==IS_OBJECT){
		fprintf(phalcon_log, "Calling method %s::%s on Object at %p\n", Z_OBJCE_P(obj)->name, method_name, obj);
	} else {
		fprintf(phalcon_log, "Calling method %s on non object :(\n", method_name);
	}
	return SUCCESS;
}

int phalcon_error_space(){
	int i;
	fprintf(phalcon_log, "[ERROR] ");
	for(i=0;i<phalcon_debug_trace;i++){
		fprintf(phalcon_log, " ");
	}
	return SUCCESS;
}

int phalcon_debug_space(){
	int i;
	fprintf(phalcon_log, "[DEBUG] ");
	for(i=0;i<phalcon_debug_trace;i++){
		fprintf(phalcon_log, " ");
	}
	return SUCCESS;
}

int phalcon_debug_param(zval *param TSRMLS_DC){
	phalcon_debug_space();
	fprintf(phalcon_log, "Push method Param > ");
	phalcon_vdump(param TSRMLS_CC);
	return SUCCESS;
}

int phalcon_debug_vdump(char *preffix, zval *value TSRMLS_DC){
	phalcon_debug_space();
	fprintf(phalcon_log, "%s", preffix);
	phalcon_vdump(value TSRMLS_CC);
	return SUCCESS;
}

int phalcon_debug_assign(char *name, zval *value TSRMLS_DC){
	phalcon_debug_space();
	fprintf(phalcon_log, "Assign on %s with ", name);
	phalcon_vdump(value TSRMLS_CC);
	return SUCCESS;
}

int phalcon_step_over(char *message){
	phalcon_debug_screen(message);
	return SUCCESS;
}

int phalcon_step_into(char *message){
	phalcon_debug_trace++;
	phalcon_debug_screen(message);
	return SUCCESS;
}

int phalcon_step_out(char *message){
	phalcon_debug_screen(message);
	phalcon_debug_trace--;
	return SUCCESS;
}

/**
 * Prints internal debug backtrace
 */
int phalcon_debug_backtrace_internal(){
	int step = 0;
	char *message;
	phalcon_debug_entry *ptr = active;
	while(ptr){
		phalcon_spprintf(&message, 0, "#%d %s::%s", step, ptr->class_name, ptr->method_name);
		phalcon_debug_screen(message);
		efree(message);
		ptr = ptr->prev;
		step++;
	}
	return SUCCESS;
}

/**
 * Appends a debug entry to internal execution scope
 */
int phalcon_step_into_entry(char *class_name, char *method_name, int lineno){

	char *message;
	phalcon_debug_entry *entry;

	if (!start) {
		start = (phalcon_debug_entry *) emalloc(sizeof(phalcon_debug_entry));
		start->class_name = "__main__";
		start->method_name = "__init__";
		start->lineno = 0;
		start->prev = NULL;
		start->next = NULL;
		active = start;
	}

	phalcon_spprintf(&message, 0, "Step Into %s::%s", class_name, method_name);
	phalcon_debug_screen(message);
	efree(message);

	entry = emalloc(sizeof(phalcon_debug_entry));
	entry->class_name = class_name;
	entry->method_name = method_name;
	entry->lineno = lineno;
	entry->prev = active;
	active->next = entry;
	active = entry;
	phalcon_debug_trace++;

	return SUCCESS;
}

/**
 * Steps out current stack
 */
int phalcon_step_out_entry(){

	char *message;
	phalcon_debug_entry *prev;
	if(active){

		phalcon_debug_trace--;

		phalcon_spprintf(&message, 0, "Step out %s::%s", active->class_name, active->method_name);
		phalcon_debug_screen(message);
		efree(message);

		prev = active->prev;
		efree(active);
		active = prev;

	} else {
		fprintf(phalcon_log, "Problem, stack?");
		return FAILURE;
	}
	return SUCCESS;
}

#endif

#ifdef HAVE_CONFIG_H
#endif


#ifndef PHALCON_RELEASE

int phalcon_assert_class(zval *object, char *class_name TSRMLS_DC){
	if(object){
		if(Z_TYPE_P(object)!=IS_OBJECT){
			phalcon_error_space();
			fprintf(phalcon_log, "AssertClass: [Failed] Value is not an object\n");
			return FAILURE;
		} else {
			if(strcmp(Z_OBJCE_P(object)->name, class_name)){
				phalcon_error_space();
				fprintf(phalcon_log, "AssertClass: [Failed] Object is not class %s, is %s\n", class_name, Z_OBJCE_P(object)->name);
				return FAILURE;
			}
		}
	}
	return SUCCESS;
}

#endif
#ifdef HAVE_CONFIG_H
#endif

#ifdef PHP_WIN32
#endif

/**
 * Check if class is instance of
 */
int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC){
	if(Z_TYPE_P(object)!=IS_OBJECT){
		zend_error(E_ERROR, "instanceof expects an object instance, constant given");
		return FAILURE;
    } else {
		ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(object), ce TSRMLS_CC));
    }
    return SUCCESS;
}

/**
 * Check if a class exists
 *
 * @TODO Unfortunately doesn't works
 */
int phalcon_class_exists(zval *return_value, zval *class_name_zval, zval *autoload_zval TSRMLS_DC){

	/*char *class_name;
	int class_name_len;
	zend_class_entry ***ce;
	ulong hash;
	ALLOCA_FLAG(use_heap)

	switch(Z_TYPE_P(class_name_zval)){
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameter for class_exists");
			return FAILURE;
	}

	if(Z_TYPE_P(class_name_zval)!=IS_STRING){
		convert_to_string(class_name_zval);
	}

	class_name = estrndup(Z_STRVAL_P(class_name_zval), Z_STRLEN_P(class_name_zval));
	class_name_len = strlen(class_name);

	zend_str_tolower(class_name, class_name_len);

	hash = zend_inline_hash_func(class_name, class_name_len);
	if(zend_hash_quick_find(EG(class_table), class_name, class_name_len, hash, (void **) ce) == SUCCESS) {
		free_alloca(class_name, use_heap);
		return SUCCESS;
	}

	free_alloca(class_name, use_heap);*/
	return FAILURE;

}

/**
 * Clones an object from obj to destiny
 */
int phalcon_clone(zval *destiny, zval *obj TSRMLS_DC){

	zend_class_entry *ce;
	zend_object_clone_obj_t clone_call;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "__clone method called on non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(obj);
	clone_call =  Z_OBJ_HT_P(obj)->clone_obj;
	if (!clone_call) {
		if (ce) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trying to clone an uncloneable object of class %s", ce->name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trying to clone an uncloneable object");
		}
		return FAILURE;
	}

	if(!EG(exception)){
		Z_OBJVAL_P(destiny) = clone_call(obj TSRMLS_CC);
		Z_TYPE_P(destiny) = IS_OBJECT;
		Z_SET_REFCOUNT_P(destiny, 1);
		Z_SET_ISREF_P(destiny);
		if(EG(exception)){
			zval_ptr_dtor(&destiny);
		}
	}

	return SUCCESS;
}

/**
 * Checks if property exists on object
 */
int phalcon_isset_property(zval *object, char *property_name, int property_length TSRMLS_DC){
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if(zend_hash_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length+1)){
			return 1;
		} else {
			return zend_hash_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), property_name, property_length+1);
		}
	} else {
		return 0;
	}
}

/**
 * Checks if string property exists on object
 */
int phalcon_isset_property_zval(zval *object, zval *property TSRMLS_DC){
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {
			if(zend_hash_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property)+1)){
				return 1;
			} else {
				return zend_hash_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), Z_STRVAL_P(property), Z_STRLEN_P(property)+1);
			}
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

/**
 * Reads a property from an object
 */
int phalcon_read_property(zval **result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;

	ZVAL_NULL((*result));

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		while (ce) {
			if (zend_hash_exists(&ce->properties_info, property_name, property_length+1)) {
				tmp = zend_read_property(ce, object, property_name, property_length, 0 TSRMLS_CC);
				Z_ADDREF_P(tmp);
				zval_ptr_dtor(result);
				*result = tmp;
				return SUCCESS;
			}
			ce = ce->parent;
		}
		tmp = zend_read_property(Z_OBJCE_P(object), object, property_name, property_length, 1 TSRMLS_CC);
		Z_ADDREF_P(tmp);
		zval_ptr_dtor(result);
		*result = tmp;
		return SUCCESS;
	} else {
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
		}
	}
	return FAILURE;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;

	ZVAL_NULL((*result));

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {
			ce = Z_OBJCE_P(object);
			while (ce) {
				if (zend_hash_exists(&ce->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property)+1)) {
					tmp = zend_read_property(ce, object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0 TSRMLS_CC);
					Z_ADDREF_P(tmp);
					zval_ptr_dtor(result);
					*result = tmp;
					return SUCCESS;
				}
				ce = ce->parent;
			}
			tmp = zend_read_property(Z_OBJCE_P(object), object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0 TSRMLS_CC);
			Z_ADDREF_P(tmp);
			zval_ptr_dtor(result);
			*result = tmp;
		}
	} else {
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
			return FAILURE;
		}
	}
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with long value
 */
int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC){
	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Attempt to assign property of non-object");
		return FAILURE;
	} else {
		zend_update_property_long(Z_OBJCE_P(obj), obj, property_name, property_length, value TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with string value
 */
int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC){
	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Attempt to assign property of non-object");
		return FAILURE;
	} else {
		zend_update_property_string(Z_OBJCE_P(obj), obj, property_name, property_length, value TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Checks wheter obj is an object and updates property with another zval
 */
int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC){
	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Attempt to assign property of non-object");
		return FAILURE;
	} else {
		zend_update_property(Z_OBJCE_P(obj), obj, property_name, property_length, value TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Check if method exists on certain object
 */
int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC){

	char *lcname;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	if (Z_TYPE_P(method_name) != IS_STRING) {
		return FAILURE;
	}

	lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	if (zend_hash_exists(&Z_OBJCE_P(object)->function_table, lcname, Z_STRLEN_P(method_name)+1)) {
		efree(lcname);
		return SUCCESS;
	}

	efree(lcname);
	return FAILURE;
}

/**
 * Check if method exists on certain object using explicit char param
 */
int phalcon_method_exists_ex(zval *object, char *method_name, int method_len TSRMLS_DC){

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	if (zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, method_len+1)) {
		return SUCCESS;
	}

	return FAILURE;
}


#ifdef HAVE_CONFIG_H
#endif


/**
 * Check if index exists on an array zval
 */
int phalcon_array_isset(const zval *arr, zval *index){

	zval *copy;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, index, 1, 0);
		convert_to_string(copy);
		index = copy;
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, index, 1, 0);
			convert_to_long(copy);
			index = copy;
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		return zend_hash_exists(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1);
	} else {
		return zend_hash_index_exists(Z_ARRVAL_P(arr), Z_LVAL_P(index));
	}

	return 0;
}

/**
 * Check if char index exists on an array zval
 */
int phalcon_array_isset_string(const zval *arr, char *index, uint index_length){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}
	return zend_hash_exists(Z_ARRVAL_P(arr), index, index_length);
}

/**
 * Check if char index exists on an array zval
 */
int phalcon_array_isset_long(const zval *arr, ulong index){
	if(Z_TYPE_P(arr)!=IS_ARRAY){
		return 0;
	}
	return zend_hash_index_exists(Z_ARRVAL_P(arr), index);
}

/**
 * Unsets zval index from array
 */
int phalcon_array_unset(zval *arr, zval *index){

	zval *copy;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, index, 1, 0);
		convert_to_string(copy);
		index = copy;
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, index, 1, 0);
			convert_to_long(copy);
			index = copy;
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		return zend_hash_del(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1);
	} else {
		return zend_hash_index_del(Z_ARRVAL_P(arr), Z_LVAL_P(index));
	}

	return 0;
}

/**
 * Unsets string index from array
 */
int phalcon_array_unset_string(zval *arr, char *index, uint index_length){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}
	return zend_hash_del(Z_ARRVAL_P(arr), index, index_length);
}

/**
 * Unsets long index from array
 */
int phalcon_array_unset_long(zval *arr, ulong index){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}
	return zend_hash_index_del(Z_ARRVAL_P(arr), index);
}

/**
 * Push one or more elements onto the end of array
 */
int phalcon_array_append(zval *arr, zval *value TSRMLS_DC){
	if (Z_TYPE_P(arr) == IS_ARRAY) {
		return add_next_index_zval(arr, value);
	} else {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
	}
	return FAILURE;
}

/**
 * Updates values on arrays by string or long indexes
 */
int phalcon_array_update(zval *arr, zval *index, zval *value TSRMLS_DC){

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		convert_to_string(index);
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			convert_to_long(index);
		}
	}

 	if(Z_TYPE_P(index) == IS_STRING){
		return zend_hash_update(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, &value, sizeof(zval *), NULL);
	} else {
		if (Z_TYPE_P(index) == IS_LONG) {
			return zend_hash_index_update(Z_ARRVAL_P(arr), Z_LVAL_P(index), &value, sizeof(zval *), NULL);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

	return FAILURE;
}

/**
 * Updates values on arrays by string indexes only
 */
int phalcon_array_update_string(zval *arr, char *index, uint index_length, zval *value TSRMLS_DC){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}
	return zend_hash_update(Z_ARRVAL_P(arr), index, index_length+1, &value, sizeof(zval *), NULL);
}

/**
 * Updates values on arrays by long indexes only
 */
int phalcon_array_update_long(zval *arr, ulong index, zval *value TSRMLS_DC){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}
	return zend_hash_index_update(Z_ARRVAL_P(arr), index, &value, sizeof(zval *), NULL);
}

/**
 * Reads an item from an array using a zval as index
 */
int phalcon_array_fetch(zval **return_value, const zval *arr, zval *index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE, type;

 	if (Z_TYPE_P(index) == IS_ARRAY || Z_TYPE_P(index) == IS_OBJECT) {
		ZVAL_NULL(*return_value);
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

 	if (Z_TYPE_P(index) == IS_NULL) {
		convert_to_string(index);
	}

	ZVAL_NULL(*return_value);

	if (Z_TYPE_P(arr) == IS_NULL || Z_TYPE_P(arr) == IS_BOOL) {
		return FAILURE;
	}

	if (Z_TYPE_P(index) != IS_STRING && Z_TYPE_P(index) != IS_LONG && Z_TYPE_P(index) != IS_DOUBLE) {
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

 	if (Z_TYPE_P(index) == IS_STRING) {
       	if((type = is_numeric_string(Z_STRVAL_P(index), Z_STRLEN_P(index), NULL, NULL, 0))){
			if (type == IS_LONG) {
				convert_to_long(index);
			}
		}
	} else {
		if (Z_TYPE_P(index) == IS_DOUBLE) {
			convert_to_long(index);
		}
	}

 	if (Z_TYPE_P(index) == IS_STRING) {
		if((result = zend_hash_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, (void**) &zv)) == SUCCESS){
			zval_ptr_dtor(return_value);
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}
	}

 	if (Z_TYPE_P(index) == IS_LONG) {
		if ((result = zend_hash_index_find(Z_ARRVAL_P(arr), Z_LVAL_P(index), (void**) &zv)) == SUCCESS) {
			zval_ptr_dtor(return_value);
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}
	}

	if (silent == PHALCON_NOISY_FETCH) {
		if (Z_TYPE_P(index) == IS_LONG) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", Z_LVAL_P(index));
		} else {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", Z_STRVAL_P(index));
		}
	}

	return FAILURE;
}

/**
 * Reads an item from an array using a string as index
 */
int phalcon_array_fetch_string(zval **return_value, const zval *arr, char *index, uint index_length, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	ZVAL_NULL(*return_value);

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		ZVAL_NULL(*return_value);
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}
		return FAILURE;
	}

	if ((result = zend_hash_find(Z_ARRVAL_P(arr), index, index_length+1, (void**)&zv)) == SUCCESS) {
		zval_ptr_dtor(return_value);
		*return_value = *zv;
		Z_ADDREF_PP(return_value);
		return SUCCESS;
	}

	if (silent == PHALCON_NOISY_FETCH) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", index);
	}

	return FAILURE;

}

/**
 * Reads an item from an array using a long as index
 */
int phalcon_array_fetch_long(zval **return_value, const zval *arr, ulong index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	ZVAL_NULL(*return_value);

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}
		return FAILURE;
	}

	if ((result = zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv)) == SUCCESS) {
		zval_ptr_dtor(return_value);
		*return_value = *zv;
		Z_ADDREF_PP(return_value);
		return SUCCESS;
	}

	if (silent == PHALCON_NOISY_FETCH) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", index);
	}

	return FAILURE;

}

#ifdef HAVE_CONFIG_H
#endif


/**
 * Initializes memory stack for the active function
 */
int phalcon_memory_grow_stack(TSRMLS_D){

	register int i;
	phalcon_memory_entry *entry;

	if(!PHALCON_GLOBAL(start_memory)){
		PHALCON_GLOBAL(start_memory) = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
		PHALCON_GLOBAL(start_memory)->pointer = -1;
		PHALCON_GLOBAL(start_memory)->prev = NULL;
		PHALCON_GLOBAL(start_memory)->next = NULL;
		PHALCON_GLOBAL(active_memory) = PHALCON_GLOBAL(start_memory);
	}

	entry = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
	for(i=0;i<PHALCON_MAX_MEMORY_STACK;i++){
		entry->addresses[i] = NULL;
	}
	entry->pointer = -1;
	entry->prev = PHALCON_GLOBAL(active_memory);
	PHALCON_GLOBAL(active_memory)->next = entry;
	PHALCON_GLOBAL(active_memory) = entry;

	return SUCCESS;
}

/**
 * Finishes memory stack by releasing allocated memory
 */
int phalcon_memory_restore_stack(TSRMLS_D){

	register int i;
	phalcon_memory_entry *prev;
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);

	if(active_memory){

		if (active_memory->pointer > -1) {
			for (i=active_memory->pointer;i>=0;i--) {
				if(active_memory->addresses[i] != NULL){
					if(*active_memory->addresses[i]){
						if (Z_REFCOUNT_PP(active_memory->addresses[i])-1 == 0) {
							zval_ptr_dtor(active_memory->addresses[i]);
							*active_memory->addresses[i] = NULL;
							active_memory->addresses[i] = NULL;
						} else {
							Z_DELREF_PP(active_memory->addresses[i]);
							if (Z_REFCOUNT_PP(active_memory->addresses[i]) == 1) {
								active_memory->addresses[i] = NULL;
							}
						}
					}
				}
			}
		}

		prev = active_memory->prev;
		efree(PHALCON_GLOBAL(active_memory));
		PHALCON_GLOBAL(active_memory) = prev;
		if(prev != NULL){
			PHALCON_GLOBAL(active_memory)->next = NULL;
			if(PHALCON_GLOBAL(active_memory)==PHALCON_GLOBAL(start_memory)){
				efree(PHALCON_GLOBAL(active_memory));
				PHALCON_GLOBAL(start_memory) = NULL;
				PHALCON_GLOBAL(active_memory) = NULL;
			}
		} else {
			PHALCON_GLOBAL(start_memory) = NULL;
			PHALCON_GLOBAL(active_memory) = NULL;
		}

	} else {
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
int phalcon_memory_observe(zval **var TSRMLS_DC){
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);
	active_memory->pointer++;
	active_memory->addresses[active_memory->pointer] = var;
	return SUCCESS;
}

/**
 * Removes a memory pointer from the active memory pool
 */
int phalcon_memory_remove(zval **var TSRMLS_DC){
	zval_ptr_dtor(var);
	*var = NULL;
	return SUCCESS;
}
/**
 * Phalcon_Session_Namespace
 *
 * This component helps to separate session data into namespaces. Working by this way
 * you can easily create groups of session variables into the application
 */

/**
* Constructo of class
*
* @param string $name
*/
PHP_METHOD(Phalcon_Session_Namespace, __construct){

	zval *a0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_session_namespace_class_entry, this_ptr, "_data", strlen("_data"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_name", strlen("_name"), v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_name", sizeof("_name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	p0[0] = t0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_session", "get", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v1, r0);
	if (Z_TYPE_P(v1) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, "_data", strlen("_data"), v1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
* Setter of values
*
* @param string $property
* @param string $value
*/
PHP_METHOD(Phalcon_Session_Namespace, __set){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v1);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_data", strlen("_data"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_name", sizeof("_name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	p0[1] = t2;
	PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_session", "set", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
* Getter of values
*
* @param string $property
* @return string
*/
PHP_METHOD(Phalcon_Session_Namespace, __get){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	eval_int = phalcon_array_isset(v1, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, v1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *
 */

PHP_METHOD(Phalcon_Loader, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_loader_class_entry, this_ptr, "_namespaces", strlen("_namespaces"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_loader_class_entry, this_ptr, "_directories", strlen("_directories"), a1 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Register namespaces and its related directories
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_namespaces", strlen("_namespaces"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Register directories on which not found classes could be found
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerDirs){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_directories", strlen("_directories"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(this_ptr);
	PHALCON_SEPARATE_ARRAY(a0);
	add_next_index_zval(a0, this_ptr);
	add_next_index_stringl(a0, "autoLoad", strlen("autoLoad"), 1);
	Z_ADDREF_P(a0);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", a0, 0x000);
	Z_DELREF_P(a0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Makes the work of autoload registered classes
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Loader, autoLoad){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *p1[] = { NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_namespaces", sizeof("_namespaces")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_0c08_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_0c08_0;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "strlen", v0, 0x001);
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, v2, r0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			Z_ADDREF_P(v0);
			p1[0] = v0;
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_CALL_FUNC_PARAMS_1(r3, "strlen", v2, 0x001);
			Z_ADDREF_P(r3);
			p1[2] = r3;
			PHALCON_CALL_FUNC_PARAMS(r2, "substr", 3, p1, 0x002);
			Z_DELREF_P(p1[0]);
			Z_DELREF_P(p1[2]);
			PHALCON_INIT_VAR(r4);
			is_equal_function(r4, r2, v2 TSRMLS_CC);
			if (zend_is_true(r4)) {
				PHALCON_INIT_VAR(r5);
				p3[0] = v2;
				PHALCON_INIT_VAR(p3[1]);
				ZVAL_STRING(p3[1], "", 1);
				p3[2] = v0;
				PHALCON_CALL_FUNC_PARAMS(r5, "str_replace", 3, p3, 0x003);
				PHALCON_CPY_WRT(v3, r5);
				PHALCON_INIT_VAR(r6);
				concat_function(r6, v1, v3 TSRMLS_CC);
				if (phalcon_file_exists(r6 TSRMLS_CC) == SUCCESS) {
					phalcon_require(v3 TSRMLS_CC);
					if (EG(exception) || EG(exit_status) == 255) {
						return;
					}
					PHALCON_MM_RESTORE();
					RETURN_TRUE;
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_0c08_0;
		fee_0c08_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_directories", sizeof("_directories")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_0c08_1:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_0c08_1;
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r7);
		concat_function(r7, v1, v3 TSRMLS_CC);
		if (phalcon_file_exists(r7 TSRMLS_CC) == SUCCESS) {
			phalcon_require(v3 TSRMLS_CC);
			if (EG(exception) || EG(exit_status) == 255) {
				return;
			}
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_0c08_1;
		fee_0c08_1:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Test, nice){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_long_ex(a0, "hello1", strlen("hello1")+1, 1);
	add_assoc_long_ex(a0, "hello2", strlen("hello2")+1, 2);
	add_assoc_long_ex(a0, "hello3", strlen("hello3")+1, 3);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(v1), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_2ebb_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_2ebb_0;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 100);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, r0, t0 TSRMLS_CC);
		Z_ADDREF_P(r1);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v1, v3, r1 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_2ebb_0;
		fee_2ebb_0:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("print_r", v1, 0x004);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Router_Rewrite
 *
 * Phalcon_Router_Rewrite is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 *
 *
 */

PHP_METHOD(Phalcon_Router_Rewrite, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_router_rewrite_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Get rewrite info
 */
PHP_METHOD(Phalcon_Router_Rewrite, _getRewriteUri){

	zval *g0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_GET", sizeof("_GET") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_GET", sizeof("_GET"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "_url", strlen("_url")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "_url", strlen("_url"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
* Set the base of application
*
* @param string $baseUri
*/
PHP_METHOD(Phalcon_Router_Rewrite, setBaseUri){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Handles routing information received from the rewrite engine
 */
PHP_METHOD(Phalcon_Router_Rewrite, handle){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getrewriteuri", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "explode", c0, v0, 0x005);
		PHALCON_CPY_WRT(v1, r1);
		eval_int = phalcon_array_isset_long(v1, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_long(&r2, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r2;
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_filter_alphanum(r3, p2[0]);
			phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), r3 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!zend_is_true(t0)) {
				zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
			}
		} else {
			zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_long(v1, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_long(&r4, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			p3[0] = r4;
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_filter_alphanum(r5, p3[0]);
			phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), r5 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!zend_is_true(t1)) {
				zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
			}
		} else {
			zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
		}
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "count", v1, 0x007);
		PHALCON_CPY_WRT(v3, r6);
		PHALCON_INIT_VAR(v4);
		ZVAL_LONG(v4, 2);
		fs_ef57_0:
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, v4, v3 TSRMLS_CC);
		if (!zend_is_true(r7)) {
			goto fe_ef57_0;
		}
		PHALCON_INIT_VAR(r8);
		phalcon_array_fetch(&r8, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r8);
		PHALCON_SEPARATE_ARRAY(v2);
		phalcon_array_append(v2, r8 TSRMLS_CC);
		PHALCON_SEPARATE(v4);
		increment_function(v4);
		goto fs_ef57_0;
		fe_ef57_0:
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), v2 TSRMLS_CC);
	} else {
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns proccesed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Router_Rewrite, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Config_Exception
 *
 * Exceptions thrown in Phalcon_Config will use this class
 *
 */

/**
 * Phalcon_Config_Exception constructor
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Config_Exception, __construct){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Exception", "__construct", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Config_Adapter_Ini
 *
 * Reads ini files and convert it to Phalcon_Config objects.
 *
 * Given the next configuration file:
 *
 * 
 *
 * You can read it as follows:
 *
 * 
 *
 */

/**
 * Phalcon_Config_Adapter_Ini constructor
 *
 * @param string $filePath
 * @return Phalcon_Config_Adapter_Ini
 *
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p1[] = { NULL }, *p5[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "parse_ini_file", v0, c0, 0x008);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if (Z_TYPE_P(v2) == IS_BOOL && !Z_BVAL_P(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_config_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "basename", v0, 0x009);
		Z_DELREF_P(v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Configuration file ", r1, " can't be loaded");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_b840_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_b840_0;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		if (Z_TYPE_P(v3) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v3);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_b840_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_b840_1;
			} else {
				PHALCON_INIT_VAR(v6);
				htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v6, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v6, num);
					}
				}
			}
			PHALCON_INIT_VAR(v5);
			ZVAL_ZVAL(v5, *hd, 1, 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, ".", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "strpos", v6, c1, 0x00A);
			if (Z_TYPE_P(r3) != IS_BOOL || (Z_TYPE_P(r3) == IS_BOOL && Z_BVAL_P(r3))) {
				PHALCON_INIT_VAR(r4);
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, ".", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r4, "explode", c2, v6, 0x005);
				PHALCON_CPY_WRT(v7, r4);
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					zval *new_zv;
					Z_DELREF_P(t0);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t0);
					t0 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v1, v4, t0 TSRMLS_CC);
				}
				Z_ADDREF_P(t0);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v1, v4, t0 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch_long(&r5, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, t0, r5, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					zval *new_zv;
					Z_DELREF_P(t1);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t1);
					t1 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t0, r5, t1 TSRMLS_CC);
				}
				Z_ADDREF_P(t1);
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(t0, r5, t1 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r6);
				phalcon_array_fetch_long(&r6, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(v5);
				phalcon_array_update(t1, r6, v5 TSRMLS_CC);
			} else {
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					PHALCON_INIT_VAR(t2);
					phalcon_array_fetch(&t2, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t2) > 1) {
					zval *new_zv;
					Z_DELREF_P(t2);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t2);
					t2 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v1, v4, t2 TSRMLS_CC);
				}
				Z_ADDREF_P(t2);
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(v1, v4, t2 TSRMLS_CC);
				}
				Z_ADDREF_P(v5);
				phalcon_array_update(t2, v6, v5 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_b840_1;
			fee_b840_1:
			if(0){ };
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_b840_0;
		fee_b840_0:
		if(0){ };
	}
	Z_ADDREF_P(v1);
	p5[0] = v1;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", 1, p5);
	Z_DELREF_P(p5[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Exception
 *
 * All framework exceptions should use this exception
 */

/**
 * Phalcon_Exception constructor
 *
 * @param string $message
 * @param int $errorCode
 * @param boolean $showTrace
 * @param array $backtrace
 */
PHP_METHOD(Phalcon_Exception, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_LONG(v1, 0);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	if (!v3) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", v1, 0x00B);
	if (zend_is_true(r0)) {
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Exception", "__construct", 2, p1);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
	} else {
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_INIT_VAR(p2[1]);
		ZVAL_LONG(p2[1], 0);
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Exception", "__construct", 2, p2);
		Z_DELREF_P(p2[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Db
 *
 * Phalcon_Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon_Db is the basic class you use to connect your PHP application to a RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to low level database operations. If you want to interact with databases using
 * high level abstraction use Phalcon_Model.
 *
 * Phalcon_Db is an abstract class. You only can use it with a database adapter like Phalcon_Db_Mysql
 *
 * 
 */

/**
 * Phalcon_Db contructor, this method should not be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
 */
PHP_METHOD(Phalcon_Db, __construct){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_descriptor", strlen("_descriptor"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets a logger class to log all SQL operations sended to database server
 *
 * @param Phalcon_Logger $logger
 */
PHP_METHOD(Phalcon_Db, setLogger){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_logger", strlen("_logger"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the active logger
 *
 * @return Phalcon_Logger
 */
PHP_METHOD(Phalcon_Db, getLogger){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends arbitrary text to a related logger in the instance
 *
 * @param string $sqlStatement
 * @param int $type
 */
PHP_METHOD(Phalcon_Db, log){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		Z_ADDREF_P(v1);
		p0[1] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets a database profiler to the connection
 *
 * @param Phalcon_Db_Profiler $profiler
 */
PHP_METHOD(Phalcon_Db, setProfiler){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		phalcon_update_property_zval(this_ptr, "_profiler", strlen("_profiler"), v0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Profiler must be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the first row in a SQL query result
 *
 * 
 *
 * @param string $sqlQuery
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v1, r0);
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v1);
		p1[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_RETURN_CTOR(a0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Dumps the complete result of a query into an array
 *
 * 
 *
 * @param string $sqlQuery
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchAll){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_INIT_VAR(r1);
	is_not_equal_function(r1, v2, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		ws_e7f0_0:
		PHALCON_INIT_VAR(r2);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v3, r2);
		if (!zend_is_true(v3)) {
			goto we_e7f0_0;
		}
		Z_ADDREF_P(v3);
		PHALCON_SEPARATE_ARRAY(v1);
		phalcon_array_append(v1, v3 TSRMLS_CC);
		goto ws_e7f0_0;
		we_e7f0_0:
		if(0) { };
	}
	PHALCON_RETURN_CTOR(v1);
}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param array $values
 * @param array $fields
 * @param boolean $automaticQuotes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, insert){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v1);
	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_NULL(v2);
	}
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_BOOL(v3, 0);
	}
	
	PHALCON_INIT_VAR(v4);
	ZVAL_STRING(v4, "", 1);
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "count", v1, 0x007);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, r0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_BOTH(r2,  "Unable to insert into ", v0, " without data");
			Z_ADDREF_P(r2);
			p1[0] = r2;
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 0);
			PHALCON_INIT_VAR(p1[2]);
			ZVAL_BOOL(p1[2], 1);
			Z_ADDREF_P(this_ptr);
			p1[3] = this_ptr;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
			Z_DELREF_P(p1[0]);
			Z_DELREF_P(p1[3]);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		} else {
			if (zend_is_true(v3)) {
				if (Z_TYPE_P(v1) != IS_ARRAY) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
				} else {
					ALLOC_HASHTABLE(ah0);
					zend_hash_init(ah0, 0, NULL, NULL, 0);
					zend_hash_copy(ah0, Z_ARRVAL_P(v1), NULL, NULL, sizeof(zval*));
					zend_hash_internal_pointer_reset_ex(ah0, &hp0);
					fes_e7f0_1:
					if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
						goto fee_e7f0_1;
					} else {
						PHALCON_INIT_VAR(v6);
						htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
						if (htype == HASH_KEY_IS_STRING) {
							ZVAL_STRINGL(v6, index, index_len-1, 1);
						} else {
							if (htype == HASH_KEY_IS_LONG) {
								ZVAL_LONG(v6, num);
							}
						}
					}
					PHALCON_INIT_VAR(v5);
					ZVAL_ZVAL(v5, *hd, 1, 0);
					PHALCON_INIT_VAR(r3);
					phalcon_array_fetch(&r3, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r3) == IS_OBJECT) {
						PHALCON_INIT_VAR(r4);
						phalcon_array_fetch(&r4, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_VAR(r5);
						phalcon_instance_of(r5, r4, phalcon_db_rawvalue_class_entry TSRMLS_CC);
						if (zend_is_true(r5)) {
							PHALCON_INIT_VAR(r6);
							PHALCON_INIT_VAR(r7);
							PHALCON_INIT_VAR(r8);
							phalcon_array_fetch(&r8, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							PHALCON_CALL_METHOD(r7, r8, "getvalue", PHALCON_CALL_DEFAULT);
							Z_ADDREF_P(r7);
							PHALCON_CALL_FUNC_PARAMS_1(r6, "addslashes", r7, 0x00C);
							Z_DELREF_P(r7);
							Z_ADDREF_P(r6);
							if (Z_REFCOUNT_P(v1) > 1) {
								zval *new_zv;
								Z_DELREF_P(v1);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, v1);
								v1 = new_zv;
								zval_copy_ctor(new_zv);
							}
							phalcon_array_update(v1, v6, r6 TSRMLS_CC);
							goto fes_e7f0_1;
						} else {
							PHALCON_INIT_VAR(r9);
							PHALCON_INIT_VAR(r10);
							phalcon_array_fetch(&r10, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							Z_ADDREF_P(r10);
							PHALCON_CALL_FUNC_PARAMS_1(r9, "addslashes", r10, 0x00C);
							Z_DELREF_P(r10);
							PHALCON_INIT_VAR(r11);
							PHALCON_CONCAT_BOTH(r11,  "'", r9, "'");
							Z_ADDREF_P(r11);
							if (Z_REFCOUNT_P(v1) > 1) {
								zval *new_zv;
								Z_DELREF_P(v1);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, v1);
								v1 = new_zv;
								zval_copy_ctor(new_zv);
							}
							phalcon_array_update(v1, v6, r11 TSRMLS_CC);
						}
					} else {
						PHALCON_INIT_VAR(r12);
						PHALCON_INIT_VAR(r13);
						phalcon_array_fetch(&r13, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						Z_ADDREF_P(r13);
						PHALCON_CALL_FUNC_PARAMS_1(r12, "addslashes", r13, 0x00C);
						Z_DELREF_P(r13);
						PHALCON_INIT_VAR(r14);
						PHALCON_CONCAT_BOTH(r14,  "'", r12, "'");
						Z_ADDREF_P(r14);
						if (Z_REFCOUNT_P(v1) > 1) {
							zval *new_zv;
							Z_DELREF_P(v1);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v1);
							v1 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v1, v6, r14 TSRMLS_CC);
					}
					zend_hash_move_forward_ex(ah0, &hp0);
					goto fes_e7f0_1;
					fee_e7f0_1:
					zend_hash_destroy(ah0);
					efree(ah0);
				}
			}
		}
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_CONCAT_LEFT(r17, "INSERT INTO ", v0);
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ", ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c0, v2, 0x00D);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_VBOTH(r16, r17, " (", r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, ", ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r19, "join", c1, v1, 0x00D);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_VBOTH(r15, r16, ") VALUES (", r19);
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_CONCAT_RIGHT(r20, r15, ")");
			PHALCON_CPY_WRT(v4, r20);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r22);
			PHALCON_CONCAT_LEFT(r22, "INSERT INTO ", v0);
			PHALCON_ALLOC_ZVAL_MM(r23);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, ", ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r23, "join", c2, v1, 0x00D);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_CONCAT_VBOTH(r21, r22, " VALUES (", r23);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CONCAT_RIGHT(r24, r21, ")");
			PHALCON_CPY_WRT(v4, r24);
		}
		PHALCON_ALLOC_ZVAL_MM(r25);
		Z_ADDREF_P(v4);
		p9[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		PHALCON_RETURN_DZVAL(r25);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p10[0]);
		ZVAL_STRING(p10[0], "The second parameter for insert isn't an Array", 1);
		PHALCON_INIT_VAR(p10[1]);
		ZVAL_LONG(p10[1], 0);
		PHALCON_INIT_VAR(p10[2]);
		ZVAL_BOOL(p10[2], 1);
		Z_ADDREF_P(this_ptr);
		p10[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p10, PHALCON_CALL_CHECK);
		Z_DELREF_P(p10[3]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param array $fields
 * @param array $values
 * @param string $whereCondition
 * @param boolean $automaticQuotes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, update){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL, NULL }, *p8[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v2);
	
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	if (!v4) {
		PHALCON_INIT_VAR(v4);
		ZVAL_BOOL(v4, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "UPDATE ", v0, " SET ");
	PHALCON_CPY_WRT(v5, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "count", v1, 0x007);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", v2, 0x007);
	PHALCON_INIT_VAR(r3);
	is_not_equal_function(r3, r1, r2 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "The number of values to update is not the same as fields", 1);
		PHALCON_INIT_VAR(p2[1]);
		ZVAL_LONG(p2[1], 0);
		PHALCON_INIT_VAR(p2[2]);
		ZVAL_BOOL(p2[2], 1);
		Z_ADDREF_P(this_ptr);
		p2[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[3]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(v6);
	ZVAL_LONG(v6, 0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v7, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e7f0_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e7f0_2;
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_ZVAL(v8, *hd, 1, 0);
		if (zend_is_true(v4)) {
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r4) == IS_OBJECT) {
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch(&r5, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(r6);
				phalcon_instance_of(r6, r5, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r6)) {
					PHALCON_INIT_VAR(r7);
					PHALCON_INIT_VAR(r8);
					PHALCON_INIT_VAR(r9);
					phalcon_array_fetch(&r9, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_CALL_METHOD(r8, r9, "getvalue", PHALCON_CALL_DEFAULT);
					Z_ADDREF_P(r8);
					PHALCON_CALL_FUNC_PARAMS_1(r7, "addslashes", r8, 0x00C);
					Z_DELREF_P(r8);
					Z_ADDREF_P(r7);
					if (Z_REFCOUNT_P(v2) > 1) {
						zval *new_zv;
						Z_DELREF_P(v2);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v2);
						v2 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v2, v6, r7 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r10);
					PHALCON_INIT_VAR(r11);
					phalcon_array_fetch(&r11, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r11);
					PHALCON_CALL_FUNC_PARAMS_1(r10, "addslashes", r11, 0x00C);
					Z_DELREF_P(r11);
					PHALCON_INIT_VAR(r12);
					PHALCON_CONCAT_BOTH(r12,  "'", r10, "'");
					Z_ADDREF_P(r12);
					if (Z_REFCOUNT_P(v2) > 1) {
						zval *new_zv;
						Z_DELREF_P(v2);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v2);
						v2 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v2, v6, r12 TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_VAR(r13);
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch(&r14, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r14);
				PHALCON_CALL_FUNC_PARAMS_1(r13, "addslashes", r14, 0x00C);
				Z_DELREF_P(r14);
				PHALCON_INIT_VAR(r15);
				PHALCON_CONCAT_BOTH(r15,  "'", r13, "'");
				Z_ADDREF_P(r15);
				if (Z_REFCOUNT_P(v2) > 1) {
					zval *new_zv;
					Z_DELREF_P(v2);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v2);
					v2 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update(v2, v6, r15 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(r17);
		phalcon_array_fetch(&r17, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r16);
		PHALCON_CONCAT_VBOTH(r16, v8, " = ", r17);
		Z_ADDREF_P(r16);
		PHALCON_SEPARATE_ARRAY(v7);
		phalcon_array_append(v7, r16 TSRMLS_CC);
		PHALCON_SEPARATE(v6);
		increment_function(v6);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e7f0_2;
		fee_e7f0_2:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c0, v7, 0x00D);
	PHALCON_ALLOC_ZVAL_MM(r19);
	concat_function(r19, v5, r18 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r19);
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	PHALCON_INIT_VAR(r20);
	is_not_equal_function(r20, v3, t0 TSRMLS_CC);
	if (zend_is_true(r20)) {
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_CONCAT_LEFT(r21, " WHERE ", v3);
		PHALCON_ALLOC_ZVAL_MM(r22);
		concat_function(r22, v5, r21 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r22);
	}
	PHALCON_ALLOC_ZVAL_MM(r23);
	Z_ADDREF_P(v5);
	p8[0] = v5;
	PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p8[0]);
	PHALCON_RETURN_DZVAL(r23);
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param string $whereCondition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, delete){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "trim", v1, 0x00E);
	Z_DELREF_P(v1);
	if (!PHALCON_COMPARE_STRING(r0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "DELETE FROM ", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, " WHERE ", v1);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_LEFT(r5, "DELETE FROM ", v0);
		Z_ADDREF_P(r5);
		p2[0] = r5;
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "query", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		PHALCON_RETURN_DZVAL(r4);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Starts a transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, begin){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 0 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "BEGIN", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
     * Rollbacks the active transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "ROLLBACK", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[3]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Commits the active transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "COMMIT", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[3]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Manually sets a "under transaction" state for the connection
 *
 * @param boolean $underTransaction
 */
PHP_METHOD(Phalcon_Db, setUnderTransaction){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_underTransaction", strlen("_underTransaction"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Checks whether connection have auto commit
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, getHaveAutoCommit){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_autoCommit", sizeof("_autoCommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns database name in the internal connection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDatabaseName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "name", strlen("name") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns active schema name in the internal connection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDefaultSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "schema", strlen("schema") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "schema", sizeof("schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_isset_property(t3, "name", strlen("name") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, t4, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(t5);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_STRING("", 1);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the username which has connected to the database
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getUsername){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the username which has connected to the database
     *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getHostName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets an active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * This method is executed before every SQL statement sended to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _beforeQuery){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "[", t2);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "] ", v0);
		Z_ADDREF_P(r0);
		p0[0] = r0;
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_get_class_constant(t3, phalcon_logger_class_entry, "DEBUG", strlen("DEBUG") TSRMLS_CC);
		Z_ADDREF_P(t3);
		p0[1] = t3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t5, "startprofile", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * This method is executed after every SQL statement sended to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _afterQuery){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "stopprofile", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Instantiates Phalcon_Db adapter using given parameters
 *
 * @param string $adapterName
 * @param stdClass $options
 * @param boolean $persistent
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Db, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "A valid adapter name is required", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_LONG(p0[1], 0);
		PHALCON_INIT_VAR(p0[2]);
		ZVAL_BOOL(p0[2], 1);
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_db_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 0);
			PHALCON_INIT_VAR(p1[2]);
			ZVAL_BOOL(p1[2], 1);
			PHALCON_INIT_VAR(p1[3]);
			ZVAL_NULL(p1[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i1 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init(i2);
		PHALCON_CPY_WRT(v3, i2);
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_e7f0_3:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_e7f0_3;
			} else {
				PHALCON_INIT_VAR(v5);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v5, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v5, num);
					}
				}
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			phalcon_update_property_zval(v3, Z_STRVAL_P(v5), Z_STRLEN_P(v5), v4 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_e7f0_3;
			fee_e7f0_3:
			if(0){ };
		}
	} else {
		PHALCON_CPY_WRT(v3, v1);
	}
	eval_int = phalcon_isset_property(v3, "layer", strlen("layer") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, v3, "layer", sizeof("layer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, t0);
	} else {
		PHALCON_INIT_VAR(v6);
		ZVAL_STRING(v6, "native", 1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Db_Adapter_", v0);
	PHALCON_CPY_WRT(v7, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v7);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v7, 0x00F);
	Z_DELREF_P(v7);
	if (zend_is_true(r1)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v7), Z_STRLEN_P(v7), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, ce0);
		Z_ADDREF_P(v3);
		p3[0] = v3;
		Z_ADDREF_P(v2);
		p3[1] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		Z_DELREF_P(p3[1]);
		PHALCON_RETURN_CTOR(i3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i4);
		object_init_ex(i4, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Database adapter class ", v7, " was not found");
		Z_ADDREF_P(r2);
		p4[0] = r2;
		PHALCON_INIT_VAR(p4[1]);
		ZVAL_LONG(p4[1], 0);
		PHALCON_INIT_VAR(p4[2]);
		ZVAL_BOOL(p4[2], 1);
		PHALCON_INIT_VAR(p4[3]);
		ZVAL_NULL(p4[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		return phalcon_throw_exception(i4 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Logger
 *
 * Phalcon_Logger is a component whose purpose is to create logs using
 * different backends via adapters, generating options, formats and filters
 * also implementing transactions.
 *
 *
 */

/**
 * Phalcon_Logger constructor
 *
 * @param string $adapter
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "File", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Logger_Adapter_", v0);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v3, 0x00F);
	Z_DELREF_P(v3);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Logger adapter '", v3, "' cannot be found");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v3), Z_STRLEN_P(v3), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	Z_ADDREF_P(v2);
	p2[1] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), i1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, log){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_LONG(v1, 7);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a debug message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, debug){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "DEBUG", strlen("DEBUG") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a error message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, error){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "ERROR", strlen("ERROR") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a info message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, info){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "INFO", strlen("INFO") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a notice message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, notice){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "NOTICE", strlen("NOTICE") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a warning message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, warning){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "WARNING", strlen("WARNING") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Sends/Writtes a alert message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, alert){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "ALERT", strlen("ALERT") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "log", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Pass any call to the internal adapter object
 *
 * @param  string $method
 * @param  array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Logger, __call){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, t0);
	Z_ADDREF_P(v0);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, v0);
	Z_ADDREF_P(a1);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "call_user_func_array", a1, v1, 0x010);
	Z_DELREF_P(a1);
	Z_DELREF_P(v1);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Phalcon_Cache_Exception
 *
 * Exceptions thrown in Phalcon_Cache will use this class
 *
 */

/**
 * Phalcon_Cache_Frontend_Output
 *
 * Allows to cache output fragments using a file backend
 *
 */

/**
 * Phalcon_Cache_Frontend_Output constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct){

	zval *a0 = NULL;
	zval *v0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_frontend_output_class_entry, this_ptr, "_frontendOptions", strlen("_frontendOptions"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_frontendOptions", strlen("_frontendOptions"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_frontendOptions", sizeof("_frontendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t0);
	eval_int = phalcon_array_isset_string(v0, "lifetime", strlen("lifetime")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v0, "lifetime", strlen("lifetime"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, start){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_start", 0x011);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents", 0x012);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x013);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Cache_Backend_File
 *
 * Allows to cache output fragments using a file backend
 *
 *
 */

/**
 * Phalcon_Backend_Adapter_File constructor
 *
 * @paramPhalcon_Cache_Backend_Output $frontendObject
 * @paramarray $backendOptions
 */
PHP_METHOD(Phalcon_Cache_Backend_File, __construct){

	zval *a0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_backend_file_class_entry, this_ptr, "_backendOptions", strlen("_backendOptions"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_frontendObject", strlen("_frontendObject"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_backendOptions", strlen("_backendOptions"), v1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v1, "cacheDir", strlen("cacheDir")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v1, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "is_writable", r1, 0x014);
		Z_DELREF_P(r1);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_cache_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "The cache directory does not exist or is not writable", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "You must specify the cache directory with the option cachesDir", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Starts a cache. The $keyname lets us to identity the created fragment
 *
 * @param string $keyName
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, start){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v1, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	if (phalcon_file_exists(v2 TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC(r2, "time", 0x015);
		PHALCON_CPY_WRT(v4, r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, v3, "getlifetime", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		sub_function(r4, v4, v5 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		Z_ADDREF_P(v2);
		PHALCON_CALL_FUNC_PARAMS_1(r5, "filemtime", v2, 0x016);
		Z_DELREF_P(v2);
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, r4, r5 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CALL_FUNC_PARAMS_1(r7, "file_get_contents", v2, 0x017);
			PHALCON_RETURN_DZVAL(r7);
		} else {
			phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), v0 TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v3, "start", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_NULL();
		}
	} else {
		phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(v3, "start", PHALCON_CALL_DEFAULT);
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Stores cached content into file backend
 *
 * @param string $keyName
 * @param string $cachedContent
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_lastKey", sizeof("_lastKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t0);
	}
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Cache must be started first", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, t2);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v4, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r1);
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, v3, "getcontent", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r2);
	}
	Z_ADDREF_P(v5);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", v5, v1, 0x018);
	Z_DELREF_P(v5);
	Z_DELREF_P(v1);
	if (zend_is_true(v2)) {
		PHALCON_CALL_METHOD_NORETURN(v3, "stop", PHALCON_CALL_DEFAULT);
	}
	zend_print_zval(v1, 0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Acl_Exception
 *
 * Class for exceptions thrown by Phalcon_Acl
 */

/**
 * Phalcon_Acl_Adapter_Memory
 *
 * Manages ACL lists in memory
 */

PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_rolesNames", strlen("_rolesNames"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_roles", strlen("_roles"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_resources", strlen("_resources"), a2 TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_access", strlen("_access"), a3 TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_roleInherits", strlen("_roleInherits"), a4 TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_bool_ex(a5, "*", strlen("*")+1, 1);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_resourcesNames", strlen("_resourcesNames"), a5 TSRMLS_CC);
	PHALCON_INIT_VAR(a6);
	array_init(a6);
	PHALCON_INIT_VAR(a7);
	array_init(a7);
	add_assoc_bool_ex(a7, "*", strlen("*")+1, 1);
	Z_ADDREF_P(a7);
	PHALCON_SEPARATE_ARRAY(a6);
	add_assoc_zval(a6, "*", a7);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_accessList", strlen("_accessList"), a6 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the default access level (Phalcon_Acl::ALLOW or Phalcon_Acl::DENY)
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setDefaultAction){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_defaultAccess", strlen("_defaultAccess"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the default ACL access level
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getDefaultAction){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Adds a role to the ACL list. Second parameter lets to inherit access data from other existing role
 *
 * Example:
 * 
 * 
 *
 * @param  string $roleObject
 * @param  array $accessInherits
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_CPY_WRT(v3, v0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_role_class_entry);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v3, i0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v2);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_roles", sizeof("_roles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v3);
	phalcon_array_append(t1, v3 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_roles", strlen("_roles"), t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t2);
	ZVAL_BOOL(t2, 1);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	phalcon_array_update(t3, v2, t2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_rolesNames", strlen("_rolesNames"), t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch(&t6, t5, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		zval *new_zv;
		Z_DELREF_P(t6);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t6);
		t6 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t5, v2, t6 TSRMLS_CC);
	}
	Z_ADDREF_P(t6);
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(t5, v2, t6 TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch_string(&t7, t6, "*", strlen("*"), PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		zval *new_zv;
		Z_DELREF_P(t7);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t7);
		t7 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_string(t6, "*", strlen("*"), t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t7);
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_string(t6, "*", strlen("*"), t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t4);
	phalcon_array_update_string(t7, "*", strlen("*"), t4 TSRMLS_CC);
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v2);
		p2[0] = v2;
		Z_ADDREF_P(v1);
		p2[1] = v1;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "addinherit", 2, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Role '", v1, "' does not exist in the role list");
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_0;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(r2);
			is_equal_function(r2, v2, v0 TSRMLS_CC);
			if (zend_is_true(r2)) {
				goto fes_c945_0;
			}
			PHALCON_INIT_VAR(t1);
			phalcon_read_property(&t1, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset(t1, v2);
			PHALCON_INIT_VAR(r3);
			ZVAL_BOOL(r3, eval_int);
			if (!zend_is_true(r3)) {
				PHALCON_INIT_VAR(i1);
				object_init_ex(i1, phalcon_acl_exception_class_entry);
				PHALCON_INIT_VAR(r4);
				PHALCON_CONCAT_BOTH(r4,  "Role '", v2, "' does not exist in the role list");
				Z_ADDREF_P(r4);
				p1[0] = r4;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
				Z_DELREF_P(p1[0]);
				return phalcon_throw_exception(i1 TSRMLS_CC);
			}
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t2) == IS_ARRAY) {
				PHALCON_INIT_VAR(t3);
				phalcon_array_fetch(&t3, t2, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t3) > 1) {
				zval *new_zv;
				Z_DELREF_P(t3);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t3);
				t3 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t2, v0, t3 TSRMLS_CC);
			}
			Z_ADDREF_P(t3);
			if (Z_TYPE_P(t3) != IS_ARRAY) {
				convert_to_array(t3);
				phalcon_array_update(t2, v0, t3 TSRMLS_CC);
			}
			Z_ADDREF_P(v2);
			phalcon_array_append(t3, v2 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_roleInherits", strlen("_roleInherits"), t2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_0;
			fee_c945_0:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		is_equal_function(r5, v1, v0 TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t4, v1);
		PHALCON_INIT_VAR(r6);
		ZVAL_BOOL(r6, eval_int);
		if (!zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_acl_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_BOTH(r7,  "Role '", v1, "' does not exist in the role list");
			Z_ADDREF_P(r7);
			p2[0] = r7;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
			Z_DELREF_P(p2[0]);
			return phalcon_throw_exception(i2 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t5) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_array_fetch(&t6, t5, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t6) > 1) {
			zval *new_zv;
			Z_DELREF_P(t6);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t6);
			t6 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t5, v0, t6 TSRMLS_CC);
		}
		Z_ADDREF_P(t6);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
			phalcon_array_update(t5, v0, t6 TSRMLS_CC);
		}
		Z_ADDREF_P(v1);
		phalcon_array_append(t6, v1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_roleInherits", strlen("_roleInherits"), t5 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Check whether role exist in the roles list
 *
 * @param  string $roleName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Check whether resource exist in the resources list
 *
 * @param  string $resourceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Adds a resource to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * 
 *
 * @param   Phalcon_Acl_Resource $resource
 * @return  boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_CPY_WRT(v3, v0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_resource_class_entry);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v3, i0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v2);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_resources", sizeof("_resources")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v3);
		phalcon_array_append(t1, v3 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_resources", strlen("_resources"), t1 TSRMLS_CC);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(a1);
		phalcon_array_update(t2, v2, a1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t2 TSRMLS_CC);
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		phalcon_array_update(t4, v2, t3 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_resourcesNames", strlen("_resourcesNames"), t4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "addresourceaccess", 2, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	PHALCON_RETURN_DZVAL(r2);
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Resource '", v0, "' does not exist in ACL");
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_1;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			phalcon_read_property(&t1, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch(&r2, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset(r2, v2);
			PHALCON_INIT_VAR(r3);
			ZVAL_BOOL(r3, eval_int);
			if (!zend_is_true(r3)) {
				PHALCON_INIT_VAR(t2);
				ZVAL_BOOL(t2, 1);
				PHALCON_INIT_VAR(t3);
				phalcon_read_property(&t3, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t3) == IS_ARRAY) {
					PHALCON_INIT_VAR(t4);
					phalcon_array_fetch(&t4, t3, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t4) > 1) {
					zval *new_zv;
					Z_DELREF_P(t4);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t4);
					t4 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t3, v0, t4 TSRMLS_CC);
				}
				Z_ADDREF_P(t4);
				if (Z_TYPE_P(t4) != IS_ARRAY) {
					convert_to_array(t4);
					phalcon_array_update(t3, v0, t4 TSRMLS_CC);
				}
				Z_ADDREF_P(t2);
				phalcon_array_update(t4, v2, t2 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t3 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_1;
			fee_c945_1:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch(&r4, t5, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r4, v1);
		PHALCON_INIT_VAR(r5);
		ZVAL_BOOL(r5, eval_int);
		if (!zend_is_true(r5)) {
			PHALCON_INIT_VAR(t6);
			ZVAL_BOOL(t6, 1);
			PHALCON_ALLOC_ZVAL_MM(t7);
			phalcon_read_property(&t7, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t7) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t8);
				phalcon_array_fetch(&t8, t7, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t8) > 1) {
				zval *new_zv;
				Z_DELREF_P(t8);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t8);
				t8 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t7, v0, t8 TSRMLS_CC);
			}
			Z_ADDREF_P(t8);
			if (Z_TYPE_P(t8) != IS_ARRAY) {
				convert_to_array(t8);
				phalcon_array_update(t7, v0, t8 TSRMLS_CC);
			}
			Z_ADDREF_P(t6);
			phalcon_array_update(t8, v1, t6 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t7 TSRMLS_CC);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Removes an access from a resource
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_2;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property(&t0, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch(&r0, t0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r0);
			phalcon_array_unset(r0, v2);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_2;
			fee_c945_2:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_NMO(r1);
		phalcon_array_unset(r1, v1);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Role \"", v0, "\" does not exist in ACL");
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t1, v1);
	PHALCON_INIT_VAR(r2);
	ZVAL_BOOL(r2, eval_int);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "Resource \"", v1, "\" does not exist in ACL");
		Z_ADDREF_P(r3);
		p1[0] = r3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	if (Z_TYPE_P(v2) == IS_ARRAY) { 
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_3:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_3;
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset(r4, v4);
			PHALCON_INIT_VAR(r5);
			ZVAL_BOOL(r5, eval_int);
			if (!zend_is_true(r5)) {
				PHALCON_INIT_VAR(i2);
				object_init_ex(i2, phalcon_acl_exception_class_entry);
				PHALCON_INIT_VAR(r7);
				PHALCON_CONCAT_LEFT(r7, "Acccess '", v4);
				PHALCON_INIT_VAR(r6);
				PHALCON_CONCAT_VBOTH(r6, r7, "' does not exist in resource '", v1);
				PHALCON_INIT_VAR(r8);
				PHALCON_CONCAT_RIGHT(r8, r6, "' in ACL");
				Z_ADDREF_P(r8);
				p2[0] = r8;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
				Z_DELREF_P(p2[0]);
				return phalcon_throw_exception(i2 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_3;
			fee_c945_3:
			if(0){ };
		}
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_c945_4:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_c945_4;
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t3) == IS_ARRAY) {
				PHALCON_INIT_VAR(t4);
				phalcon_array_fetch(&t4, t3, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t4) > 1) {
				zval *new_zv;
				Z_DELREF_P(t4);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t4);
				t4 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t3, v0, t4 TSRMLS_CC);
			}
			Z_ADDREF_P(t4);
			if (Z_TYPE_P(t4) != IS_ARRAY) {
				convert_to_array(t4);
				phalcon_array_update(t3, v0, t4 TSRMLS_CC);
			}
			if (Z_TYPE_P(t4) == IS_ARRAY) {
				PHALCON_INIT_VAR(t5);
				phalcon_array_fetch(&t5, t4, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t5) > 1) {
				zval *new_zv;
				Z_DELREF_P(t5);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t5);
				t5 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t4, v1, t5 TSRMLS_CC);
			}
			Z_ADDREF_P(t5);
			if (Z_TYPE_P(t5) != IS_ARRAY) {
				convert_to_array(t5);
				phalcon_array_update(t4, v1, t5 TSRMLS_CC);
			}
			Z_ADDREF_P(v3);
			phalcon_array_update(t5, v4, v3 TSRMLS_CC);
			PHALCON_INIT_VAR(t6);
			phalcon_read_property(&t6, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r9);
			phalcon_array_fetch(&r9, t6, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r10);
			phalcon_array_fetch(&r10, r9, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset_string(r10, "*", strlen("*")+1);
			PHALCON_INIT_VAR(r11);
			ZVAL_BOOL(r11, eval_int);
			if (!zend_is_true(r11)) {
				PHALCON_INIT_VAR(t7);
				phalcon_read_property(&t7, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property(&t8, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t8) == IS_ARRAY) {
					PHALCON_INIT_VAR(t9);
					phalcon_array_fetch(&t9, t8, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t9) > 1) {
					zval *new_zv;
					Z_DELREF_P(t9);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t9);
					t9 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t8, v0, t9 TSRMLS_CC);
				}
				Z_ADDREF_P(t9);
				if (Z_TYPE_P(t9) != IS_ARRAY) {
					convert_to_array(t9);
					phalcon_array_update(t8, v0, t9 TSRMLS_CC);
				}
				if (Z_TYPE_P(t9) == IS_ARRAY) {
					PHALCON_INIT_VAR(t10);
					phalcon_array_fetch(&t10, t9, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t10) > 1) {
					zval *new_zv;
					Z_DELREF_P(t10);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t10);
					t10 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t9, v1, t10 TSRMLS_CC);
				}
				Z_ADDREF_P(t10);
				if (Z_TYPE_P(t10) != IS_ARRAY) {
					convert_to_array(t10);
					phalcon_array_update(t9, v1, t10 TSRMLS_CC);
				}
				Z_ADDREF_P(t7);
				phalcon_array_update_string(t10, "*", strlen("*"), t7 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_c945_4;
			fee_c945_4:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_read_property(&t11, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch(&r12, t11, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r12, v2);
		PHALCON_INIT_VAR(r13);
		ZVAL_BOOL(r13, eval_int);
		if (!zend_is_true(r13)) {
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, phalcon_acl_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "Acccess '", v2);
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_VBOTH(r14, r15, "' does not exist in resource '", v1);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_RIGHT(r16, r14, "' in ACL");
			Z_ADDREF_P(r16);
			p3[0] = r16;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p3, PHALCON_CALL_CHECK);
			Z_DELREF_P(p3[0]);
			return phalcon_throw_exception(i3 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_read_property(&t12, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t12) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t13);
			phalcon_array_fetch(&t13, t12, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t13) > 1) {
			zval *new_zv;
			Z_DELREF_P(t13);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t13);
			t13 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t12, v0, t13 TSRMLS_CC);
		}
		Z_ADDREF_P(t13);
		if (Z_TYPE_P(t13) != IS_ARRAY) {
			convert_to_array(t13);
			phalcon_array_update(t12, v0, t13 TSRMLS_CC);
		}
		if (Z_TYPE_P(t13) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t14);
			phalcon_array_fetch(&t14, t13, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t14) > 1) {
			zval *new_zv;
			Z_DELREF_P(t14);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t14);
			t14 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t13, v1, t14 TSRMLS_CC);
		}
		Z_ADDREF_P(t14);
		if (Z_TYPE_P(t14) != IS_ARRAY) {
			convert_to_array(t14);
			phalcon_array_update(t13, v1, t14 TSRMLS_CC);
		}
		Z_ADDREF_P(v3);
		phalcon_array_update(t14, v2, v3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t15);
		phalcon_read_property(&t15, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_array_fetch(&r17, t15, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_array_fetch(&r18, r17, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r18, "*", strlen("*")+1);
		PHALCON_INIT_VAR(r19);
		ZVAL_BOOL(r19, eval_int);
		if (!zend_is_true(r19)) {
			PHALCON_ALLOC_ZVAL_MM(t16);
			phalcon_read_property(&t16, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t17);
			phalcon_read_property(&t17, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t17) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t18);
				phalcon_array_fetch(&t18, t17, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t18) > 1) {
				zval *new_zv;
				Z_DELREF_P(t18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t18);
				t18 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t17, v0, t18 TSRMLS_CC);
			}
			Z_ADDREF_P(t18);
			if (Z_TYPE_P(t18) != IS_ARRAY) {
				convert_to_array(t18);
				phalcon_array_update(t17, v0, t18 TSRMLS_CC);
			}
			if (Z_TYPE_P(t18) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t19);
				phalcon_array_fetch(&t19, t18, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t19) > 1) {
				zval *new_zv;
				Z_DELREF_P(t19);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t19);
				t19 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t18, v1, t19 TSRMLS_CC);
			}
			Z_ADDREF_P(t19);
			if (Z_TYPE_P(t19) != IS_ARRAY) {
				convert_to_array(t19);
				phalcon_array_update(t18, v1, t19 TSRMLS_CC);
			}
			Z_ADDREF_P(t16);
			phalcon_array_update_string(t19, "*", strlen("*"), t16 TSRMLS_CC);
		}
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Allow access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Ej:
 * 
 *
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_INIT_VAR(p0[3]);
	ZVAL_LONG(p0[3], 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_allowordeny", 4, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Deny access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Ej:
 * 
 *
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_INIT_VAR(p0[3]);
	ZVAL_LONG(p0[3], 0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_allowordeny", 4, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * 
 *
 * @param string $role
 * @param string $resource
 * @param mixed $accessList
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "in_array", v1, t0, 0x019);
	Z_DELREF_P(v1);
	Z_DELREF_P(t0);
	if (!zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r1);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_5:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c945_5;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		is_equal_function(r2, v5, v1 TSRMLS_CC);
		if (zend_is_true(r2)) {
			eval_int = phalcon_array_isset(v4, v2);
			if (eval_int) {
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch(&r3, v4, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r3);
			}
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, v4, "*", strlen("*"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r4);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_5;
		fee_c945_5:
		if(0){ };
	}
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_c945_6:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_c945_6;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		eval_int = phalcon_array_isset_string(v4, "*", strlen("*")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset(v4, v2);
			if (eval_int) {
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch(&r5, v4, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r5);
			}
			PHALCON_INIT_VAR(r6);
			phalcon_array_fetch_string(&r6, v4, "*", strlen("*"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r6);
		}
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_c945_6;
		fee_c945_6:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Rebuild the list of access from the inherit lists
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_roles", sizeof("_roles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	mul_function(r2, v0, v0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	div_function(r3, r2, t1 TSRMLS_CC);
	Z_ADDREF_P(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ceil", r3, 0x01A);
	Z_DELREF_P(r3);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 0);
	fs_c945_7:
	PHALCON_INIT_VAR(r4);
	is_smaller_or_equal_function(r4, v2, v1 TSRMLS_CC);
	if (!zend_is_true(r4)) {
		goto fe_c945_7;
	}
	PHALCON_INIT_VAR(t2);
	phalcon_read_property(&t2, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c945_8;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(t3);
		phalcon_read_property(&t3, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t3, v4);
		if (eval_int) {
			PHALCON_INIT_VAR(t4);
			phalcon_read_property(&t4, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch(&r5, t4, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r5) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(r5);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_c945_9:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_c945_9;
				}
				PHALCON_INIT_VAR(v5);
				ZVAL_ZVAL(v5, *hd, 1, 0);
				PHALCON_INIT_VAR(t5);
				phalcon_read_property(&t5, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				eval_int = phalcon_array_isset(t5, v5);
				if (eval_int) {
					PHALCON_INIT_VAR(t6);
					phalcon_read_property(&t6, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_INIT_VAR(r6);
					phalcon_array_fetch(&r6, t6, v5, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r6) != IS_ARRAY) {
						php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
					} else {
						ah2 = Z_ARRVAL_P(r6);
						zend_hash_internal_pointer_reset_ex(ah2, &hp2);
						fes_c945_10:
						if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
							goto fee_c945_10;
						} else {
							PHALCON_INIT_VAR(v7);
							htype = zend_hash_get_current_key_ex(ah2, &index, &index_len, &num, 0, &hp2);
							if (htype == HASH_KEY_IS_STRING) {
								ZVAL_STRINGL(v7, index, index_len-1, 1);
							} else {
								if (htype == HASH_KEY_IS_LONG) {
									ZVAL_LONG(v7, num);
								}
							}
						}
						PHALCON_INIT_VAR(v6);
						ZVAL_ZVAL(v6, *hd, 1, 0);
						if (Z_TYPE_P(v6) != IS_ARRAY) {
							php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
						} else {
							ah3 = Z_ARRVAL_P(v6);
							zend_hash_internal_pointer_reset_ex(ah3, &hp3);
							fes_c945_11:
							if(zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS){
								goto fee_c945_11;
							} else {
								PHALCON_INIT_VAR(v9);
								htype = zend_hash_get_current_key_ex(ah3, &index, &index_len, &num, 0, &hp3);
								if (htype == HASH_KEY_IS_STRING) {
									ZVAL_STRINGL(v9, index, index_len-1, 1);
								} else {
									if (htype == HASH_KEY_IS_LONG) {
										ZVAL_LONG(v9, num);
									}
								}
							}
							PHALCON_INIT_VAR(v8);
							ZVAL_ZVAL(v8, *hd, 1, 0);
							PHALCON_INIT_VAR(t7);
							phalcon_read_property(&t7, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
							if (Z_TYPE_P(t7) == IS_ARRAY) {
								PHALCON_INIT_VAR(t8);
								phalcon_array_fetch(&t8, t7, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
							}
							if (Z_REFCOUNT_P(t8) > 1) {
								zval *new_zv;
								Z_DELREF_P(t8);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, t8);
								t8 = new_zv;
								zval_copy_ctor(new_zv);
								phalcon_array_update(t7, v4, t8 TSRMLS_CC);
							}
							Z_ADDREF_P(t8);
							if (Z_TYPE_P(t8) != IS_ARRAY) {
								convert_to_array(t8);
								phalcon_array_update(t7, v4, t8 TSRMLS_CC);
							}
							if (Z_TYPE_P(t8) == IS_ARRAY) {
								PHALCON_INIT_VAR(t9);
								phalcon_array_fetch(&t9, t8, v7, PHALCON_SILENT_FETCH TSRMLS_CC);
							}
							if (Z_REFCOUNT_P(t9) > 1) {
								zval *new_zv;
								Z_DELREF_P(t9);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, t9);
								t9 = new_zv;
								zval_copy_ctor(new_zv);
								phalcon_array_update(t8, v7, t9 TSRMLS_CC);
							}
							Z_ADDREF_P(t9);
							if (Z_TYPE_P(t9) != IS_ARRAY) {
								convert_to_array(t9);
								phalcon_array_update(t8, v7, t9 TSRMLS_CC);
							}
							Z_ADDREF_P(v8);
							phalcon_array_update(t9, v9, v8 TSRMLS_CC);
							zend_hash_move_forward_ex(ah3, &hp3);
							goto fes_c945_11;
							fee_c945_11:
							if(0){ };
						}
						zend_hash_move_forward_ex(ah2, &hp2);
						goto fes_c945_10;
						fee_c945_10:
						if(0){ };
					}
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_c945_9;
				fee_c945_9:
				if(0){ };
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_8;
		fee_c945_8:
		if(0){ };
	}
	increment_function(v2);
	goto fs_c945_7;
	fe_c945_7:
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 *
 * AclRole
 *
 * This class defines role entity and its description
 *
 */

/**
 * Phalcon_Acl_Role description
 *
 * @param string $name
 * @param string $description
 */
PHP_METHOD(Phalcon_Acl_Role, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "*")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Role name cannot be \"*\"", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	phalcon_update_property_zval(this_ptr, "_name", strlen("_name"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_description", strlen("_description"), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the role name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_name", sizeof("_name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns role description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getDescription){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_description", sizeof("_description")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 *
 * Phalcon_Acl_Resource
 *
 * This class defines resource entity and its description
 *
 */

/**
 * Phalcon_Acl_Resource description
 *
 * @param string $name
 * @param string $description
 */
PHP_METHOD(Phalcon_Acl_Resource, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "*")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Resource name cannot be \"*\"", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	phalcon_update_property_zval(this_ptr, "_name", strlen("_name"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_description", strlen("_description"), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the resource name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_name", sizeof("_name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns resource description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, getDescription){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_description", sizeof("_description")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Cache
 *
 * Phalcon_Cache can be used to caches output fragments to improve performance
 *
 *
 */

/**
 * Factories different caches backends from its adapters
 *
 * @paramstring $frontendAdapter
 * @paramstring $backendAdapter
 * @paramarray $frontendOptions
 * @paramarray $backendOptions
 * @return  Phalcon_Cache_Backend_File
 * @static
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL };
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
	}
	if (!v3) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v3, a1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Cache_Frontend_", v0);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v4);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v4, 0x00F);
	Z_DELREF_P(v4);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Frontend adapter \"", v1, "' doesn't exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_LEFT(r3, "Phalcon_Cache_Backend_", v1);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v5);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "class_exists", v5, 0x00F);
	Z_DELREF_P(v5);
	if (!zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_BOTH(r5,  "Backend adapter \"", v1, "' doesn't exist");
		Z_ADDREF_P(r5);
		p3[0] = r5;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v4), Z_STRLEN_P(v4), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init_ex(i2, ce0);
	Z_ADDREF_P(v2);
	p4[0] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p4, PHALCON_CALL_CHECK);
	Z_DELREF_P(p4[0]);
	PHALCON_CPY_WRT(v6, i2);
	ce1 = zend_fetch_class(Z_STRVAL_P(v5), Z_STRLEN_P(v5), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i3);
	object_init_ex(i3, ce1);
	Z_ADDREF_P(v6);
	p5[0] = v6;
	Z_ADDREF_P(v3);
	p5[1] = v3;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p5, PHALCON_CALL_CHECK);
	Z_DELREF_P(p5[0]);
	Z_DELREF_P(p5[1]);
	PHALCON_RETURN_CTOR(i3);
}

/**
 * Phalcon_View
 *
 * Phalcon_View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * 
 */

PHP_METHOD(Phalcon_View, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesBefore", strlen("_templatesBefore"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesAfter", strlen("_templatesAfter"), a2 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_View, setViewsDir){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getViewsDir){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the render level for the view
 *
 * @param string $level
 */
PHP_METHOD(Phalcon_View, setRenderLevel){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_renderLevel", strlen("_renderLevel"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Appends template before controller layout
 *
 * @param string|array $templateBefore
 */
PHP_METHOD(Phalcon_View, setTemplateBefore){

	zval *v0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), a0 TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), v0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateBefore){


	PHALCON_MM_GROW();
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_templatesBefore", strlen("_templatesBefore") TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 */
PHP_METHOD(Phalcon_View, setTemplateAfter){

	zval *v0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), a0 TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), v0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateAfter){


	PHALCON_MM_GROW();
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_templatesAfter", strlen("_templatesAfter") TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Adds parameters to views (alias of setVar)
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_View, setParamToView){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v1);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Adds parameters to views
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_View, setVar){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v1);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_View, getParamsToView){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Starts rendering process
 */
PHP_METHOD(Phalcon_View, start){


	PHALCON_MM_GROW();
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_content", strlen("_content") TSRMLS_CC);
	PHALCON_CALL_FUNC_NORETURN("ob_start", 0x011);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes render process from controller data
 *
 * @param string $controllerName
 * @param string $actionName
 */
PHP_METHOD(Phalcon_View, render){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p5[] = { NULL }, *p10[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	if (PHALCON_COMPARE_STRING(v3, "")) {
		PHALCON_INIT_VAR(v3);
		ZVAL_STRING(v3, "layouts/", 1);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_renderLevel", sizeof("_renderLevel")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, t2);
	phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), v1 TSRMLS_CC);
	if (zend_is_true(v4)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "ob_get_contents", 0x012);
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(t3);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_b0d8_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_b0d8_0;
			} else {
				PHALCON_INIT_VAR(v6);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v6, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v6, num);
					}
				}
			}
			PHALCON_INIT_VAR(v5);
			ZVAL_ZVAL(v5, *hd, 1, 0);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v6), copy);
				if (EG(exception)) {
					return;
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_b0d8_0;
			fee_b0d8_0:
			if(0){ };
		}
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 1);
		PHALCON_INIT_VAR(r1);
		is_smaller_or_equal_function(r1, t4, v4 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			concat_function(r3, v2, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_VBOTH(r2, r3, "/", v1);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_RIGHT(r4, r2, ".phtml");
			PHALCON_CPY_WRT(v7, r4);
			if (phalcon_file_exists(v7 TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x01B);
				phalcon_require(v7 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_FUNC(r5, "ob_get_contents", 0x012);
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r5 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2);
		PHALCON_INIT_VAR(r6);
		is_smaller_or_equal_function(r6, t5, v4 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v8, t6);
			if (Z_TYPE_P(v8) == IS_ARRAY) { 
				PHALCON_ALLOC_ZVAL_MM(r7);
				concat_function(r7, v2, v3 TSRMLS_CC);
				PHALCON_CPY_WRT(v7, r7);
				if (Z_TYPE_P(v8) != IS_ARRAY) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
				} else {
					ah1 = Z_ARRVAL_P(v8);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
					fes_b0d8_1:
					if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
						goto fee_b0d8_1;
					}
					PHALCON_INIT_VAR(v9);
					ZVAL_ZVAL(v9, *hd, 1, 0);
					PHALCON_INIT_VAR(r8);
					concat_function(r8, v7, v9 TSRMLS_CC);
					PHALCON_INIT_VAR(r9);
					PHALCON_CONCAT_RIGHT(r9, r8, ".phtml");
					PHALCON_CPY_WRT(v10, r9);
					if (phalcon_file_exists(v10 TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x01B);
						phalcon_require(v10 TSRMLS_CC);
						if (EG(exception) || EG(exit_status) == 255) {
							return;
						}
						PHALCON_INIT_VAR(r10);
						PHALCON_CALL_FUNC(r10, "ob_get_contents", 0x012);
						phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r10 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(i0);
						object_init_ex(i0, phalcon_view_exception_class_entry);
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_BOTH(r11,  "Template '", v9, "' was not found in layouts directory");
						Z_ADDREF_P(r11);
						p5[0] = r11;
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p5, PHALCON_CALL_CHECK);
						Z_DELREF_P(p5[0]);
						return phalcon_throw_exception(i0 TSRMLS_CC);
					}
					zend_hash_move_forward_ex(ah1, &hp1);
					goto fes_b0d8_1;
					fee_b0d8_1:
					if(0){ };
				}
			}
		}
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 3);
		PHALCON_INIT_VAR(r12);
		is_smaller_or_equal_function(r12, t7, v4 TSRMLS_CC);
		if (zend_is_true(r12)) {
			PHALCON_ALLOC_ZVAL_MM(r13);
			concat_function(r13, v2, v3 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r14);
			concat_function(r14, r13, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_RIGHT(r15, r14, ".phtml");
			PHALCON_CPY_WRT(v7, r15);
			if (phalcon_file_exists(v7 TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x01B);
				phalcon_require(v7 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r16);
				PHALCON_CALL_FUNC(r16, "ob_get_contents", 0x012);
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r16 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 4);
		PHALCON_INIT_VAR(r17);
		is_smaller_or_equal_function(r17, t8, v4 TSRMLS_CC);
		if (zend_is_true(r17)) {
			PHALCON_ALLOC_ZVAL_MM(t9);
			phalcon_read_property(&t9, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v11, t9);
			if (Z_TYPE_P(v11) == IS_ARRAY) { 
				PHALCON_ALLOC_ZVAL_MM(r18);
				concat_function(r18, v2, v3 TSRMLS_CC);
				PHALCON_CPY_WRT(v7, r18);
				if (Z_TYPE_P(v11) != IS_ARRAY) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
				} else {
					ah2 = Z_ARRVAL_P(v11);
					zend_hash_internal_pointer_reset_ex(ah2, &hp2);
					fes_b0d8_2:
					if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
						goto fee_b0d8_2;
					}
					PHALCON_INIT_VAR(v12);
					ZVAL_ZVAL(v12, *hd, 1, 0);
					PHALCON_INIT_VAR(r19);
					concat_function(r19, v7, v12 TSRMLS_CC);
					PHALCON_INIT_VAR(r20);
					PHALCON_CONCAT_RIGHT(r20, r19, ".phtml");
					PHALCON_CPY_WRT(v10, r20);
					if (phalcon_file_exists(v10 TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x01B);
						phalcon_require(v10 TSRMLS_CC);
						if (EG(exception) || EG(exit_status) == 255) {
							return;
						}
						PHALCON_INIT_VAR(r21);
						PHALCON_CALL_FUNC(r21, "ob_get_contents", 0x012);
						phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r21 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(i1);
						object_init_ex(i1, phalcon_view_exception_class_entry);
						PHALCON_INIT_VAR(r22);
						PHALCON_CONCAT_BOTH(r22,  "Template '", v9, "' was not found in layouts directory");
						Z_ADDREF_P(r22);
						p10[0] = r22;
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p10, PHALCON_CALL_CHECK);
						Z_DELREF_P(p10[0]);
						return phalcon_throw_exception(i1 TSRMLS_CC);
					}
					zend_hash_move_forward_ex(ah2, &hp2);
					goto fes_b0d8_2;
					fee_b0d8_2:
					if(0){ };
				}
			}
		}
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 5);
		PHALCON_INIT_VAR(r23);
		is_smaller_or_equal_function(r23, t10, v4 TSRMLS_CC);
		if (zend_is_true(r23)) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CONCAT_RIGHT(r24, v2, "index.phtml");
			PHALCON_CPY_WRT(v7, r24);
			if (phalcon_file_exists(v7 TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x01B);
				phalcon_require(v7 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r25);
				PHALCON_CALL_FUNC(r25, "ob_get_contents", 0x012);
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r25 TSRMLS_CC);
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Renders a partial view
 *
 * @param string $partialName
 */
PHP_METHOD(Phalcon_View, partial){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_b0d8_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_b0d8_3;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			Z_UNSET_ISREF_P(copy);
			ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v2), copy);
			if (EG(exception)) {
				return;
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_b0d8_3;
		fee_b0d8_3:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, v3, v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_RIGHT(r1, r0, ".phtml");
	PHALCON_CPY_WRT(v4, r1);
	if (phalcon_file_exists(v4 TSRMLS_CC) == SUCCESS) {
		phalcon_require(v4 TSRMLS_CC);
		if (EG(exception) || EG(exit_status) == 255) {
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Partial view '", v4, "' was not found in views directory");
		Z_ADDREF_P(r2);
		p0[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Finishes render process
 */
PHP_METHOD(Phalcon_View, finish){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x013);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns cached ouput on another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Generates a external absolute path to an application uri
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_View, url){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("print_r", v0, 0x004);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "geturl", 1, p1);
		Z_DELREF_P(p1[0]);
		PHALCON_RETURN_DZVAL(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns a local path
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_View, path){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "getlocalpath", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Phalcon_View_Exception
 *
 * Class for exceptions thrown by Phalcon_View
 */

/**
* Paginator Exception
*
* @param string $message
*/
PHP_METHOD(Phalcon_Paginator_Exception, __construct){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Paginator_Exception", "__construct", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Array_Paginator
 *
 * Component of pagination by array data
 *
 */

/**
     * Phalcon_Paginator_Adapter_Array constructor
  *
 * @param array $config
     */
PHP_METHOD(Phalcon_Paginator_Adapter_Array, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_config", strlen("_config"), v0 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_limitRows", strlen("_limitRows"), r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "page", strlen("page")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "page", strlen("page"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), r1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Array, setCurrentPage){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Array, getPaginate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p3[] = { NULL }, *p4[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_limitRows", sizeof("_limitRows")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_config", sizeof("_config")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, t1, "data", strlen("data"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_page", sizeof("_page")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t2);
	if (Z_TYPE_P(v2) == IS_NULL) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 1);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "count", v1, 0x007);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v4, i0);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, v2, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	mul_function(r3, v0, r2 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v1, 0x007);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	sub_function(r6, r5, t4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r7);
	div_function(r7, r6, v0 TSRMLS_CC);
	Z_ADDREF_P(r7);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "round", r7, 0x01C);
	Z_DELREF_P(r7);
	PHALCON_CPY_WRT(v6, r4);
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_paginator_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "Invalid data for paginator", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r8);
	p4[0] = v1;
	p4[1] = v5;
	p4[2] = v0;
	PHALCON_CALL_FUNC_PARAMS(r8, "array_slice", 3, p4, 0x01D);
	phalcon_update_property_zval(v4, "items", strlen("items"), r8 TSRMLS_CC);
	phalcon_update_property_long(v4, "first", strlen("first"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_add_function(r9, v5, v0 TSRMLS_CC);
	PHALCON_INIT_VAR(r10);
	is_smaller_function(r10, r9, v3 TSRMLS_CC);
	if (zend_is_true(r10)) {
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 1);
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_add_function(r11, v2, t5 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r11);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_add_function(r12, v5, v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r13);
		is_equal_function(r13, r12, v3 TSRMLS_CC);
		if (zend_is_true(r13)) {
			PHALCON_CPY_WRT(v7, v3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r14);
			div_function(r14, v3, v0 TSRMLS_CC);
			convert_to_long(r14);
			PHALCON_INIT_VAR(t6);
			ZVAL_LONG(t6, 1);
			PHALCON_ALLOC_ZVAL_MM(r15);
			phalcon_add_function(r15, r14, t6 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r15);
		}
	}
	PHALCON_INIT_VAR(r16);
	is_smaller_function(r16, v6, v7 TSRMLS_CC);
	if (zend_is_true(r16)) {
		PHALCON_CPY_WRT(v7, v6);
	}
	phalcon_update_property_zval(v4, "next", strlen("next"), v7 TSRMLS_CC);
	PHALCON_INIT_VAR(t7);
	ZVAL_LONG(t7, 1);
	PHALCON_INIT_VAR(r17);
	is_smaller_function(r17, t7, v2 TSRMLS_CC);
	if (zend_is_true(r17)) {
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 1);
		PHALCON_ALLOC_ZVAL_MM(r18);
		sub_function(r18, v2, t8 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r18);
	} else {
		PHALCON_INIT_VAR(v8);
		ZVAL_LONG(v8, 1);
	}
	phalcon_update_property_zval(v4, "before", strlen("before"), v8 TSRMLS_CC);
	phalcon_update_property_zval(v4, "current", strlen("current"), v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r20);
	mod_function(r20, v3, v0 TSRMLS_CC);
	if (zend_is_true(r20)) {
		PHALCON_ALLOC_ZVAL_MM(r21);
		div_function(r21, v3, v0 TSRMLS_CC);
		convert_to_long(r21);
		PHALCON_INIT_VAR(t9);
		ZVAL_LONG(t9, 1);
		PHALCON_ALLOC_ZVAL_MM(r22);
		phalcon_add_function(r22, r21, t9 TSRMLS_CC);
		r19 = r22;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r23);
		div_function(r23, v3, v0 TSRMLS_CC);
		r19 = r23;
	}
	PHALCON_CPY_WRT(v9, r19);
	phalcon_update_property_zval(v4, "last", strlen("last"), v9 TSRMLS_CC);
	phalcon_update_property_zval(v4, "total_pages", strlen("total_pages"), v9 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Phalcon_Paginator_Adapter_Model
 *
 * This adapter allows to paginate data using Phalcon_Model resultsets.
 *
 */

/**
 * Phalcon_Paginator_Adapter_Model constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_config", strlen("_config"), v0 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_limitRows", strlen("_limitRows"), r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "page", strlen("page")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "page", strlen("page"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), r1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *a0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_limitRows", sizeof("_limitRows")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_config", sizeof("_config")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, t1, "data", strlen("data"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_page", sizeof("_page")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t2);
	if (Z_TYPE_P(v2) == IS_NULL) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 1);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "count", v1, 0x007);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v4, i0);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, v2, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	mul_function(r3, v0, r2 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(r5);
	sub_function(r5, v3, t4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r6);
	div_function(r6, r5, v0 TSRMLS_CC);
	Z_ADDREF_P(r6);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "ceil", r6, 0x01A);
	Z_DELREF_P(r6);
	PHALCON_CPY_WRT(v6, r4);
	if (Z_TYPE_P(v1) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_paginator_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Invalid data for paginator", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	if (Z_TYPE_P(v2) == IS_NULL) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 0);
	}
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 0);
	PHALCON_INIT_VAR(r7);
	is_smaller_function(r7, v5, t5 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_paginator_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "The start page number is zero or less", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i2 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(v4, "items", strlen("items"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 0);
	PHALCON_INIT_VAR(r8);
	is_smaller_function(r8, t6, v3 TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_INIT_VAR(r9);
		is_smaller_or_equal_function(r9, v5, v3 TSRMLS_CC);
		if (zend_is_true(r9)) {
			Z_ADDREF_P(v5);
			p4[0] = v5;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "seek", 1, p4, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p4[0]);
		} else {
			PHALCON_INIT_VAR(p5[0]);
			ZVAL_LONG(p5[0], 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "seek", 1, p5, PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(v2);
			ZVAL_LONG(v2, 1);
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_LONG(v7, 1);
		ws_e435_0:
		PHALCON_INIT_VAR(r10);
		PHALCON_CALL_METHOD(r10, v1, "valid", PHALCON_CALL_DEFAULT);
		if (!zend_is_true(r10)) {
			goto we_e435_0;
		}
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, v1, "current", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(t7);
		phalcon_read_property(&t7, v4, "items", sizeof("items")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r11);
		phalcon_array_append(t7, r11 TSRMLS_CC);
		phalcon_update_property_zval(v4, "items", strlen("items"), t7 TSRMLS_CC);
		PHALCON_INIT_VAR(r12);
		is_smaller_or_equal_function(r12, v0, v7 TSRMLS_CC);
		if (zend_is_true(r12)) {
			goto we_e435_0;
		}
		PHALCON_SEPARATE(v7);
		increment_function(v7);
		goto ws_e435_0;
		we_e435_0:
		if(0) { };
	}
	phalcon_update_property_long(v4, "first", strlen("first"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r13);
	phalcon_add_function(r13, v5, v0 TSRMLS_CC);
	PHALCON_INIT_VAR(r14);
	is_smaller_function(r14, r13, v3 TSRMLS_CC);
	if (zend_is_true(r14)) {
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 1);
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_add_function(r15, v2, t8 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r15);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r16);
		phalcon_add_function(r16, v5, v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r17);
		is_equal_function(r17, r16, v3 TSRMLS_CC);
		if (zend_is_true(r17)) {
			PHALCON_CPY_WRT(v8, v3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			div_function(r19, v3, v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r18, "intval", r19, 0x01E);
			PHALCON_INIT_VAR(t9);
			ZVAL_LONG(t9, 1);
			PHALCON_ALLOC_ZVAL_MM(r20);
			phalcon_add_function(r20, r18, t9 TSRMLS_CC);
			PHALCON_CPY_WRT(v8, r20);
		}
	}
	PHALCON_INIT_VAR(r21);
	is_smaller_function(r21, v6, v8 TSRMLS_CC);
	if (zend_is_true(r21)) {
		PHALCON_CPY_WRT(v8, v6);
	}
	phalcon_update_property_zval(v4, "next", strlen("next"), v8 TSRMLS_CC);
	PHALCON_INIT_VAR(t10);
	ZVAL_LONG(t10, 1);
	PHALCON_INIT_VAR(r22);
	is_smaller_function(r22, t10, v2 TSRMLS_CC);
	if (zend_is_true(r22)) {
		PHALCON_INIT_VAR(t11);
		ZVAL_LONG(t11, 1);
		PHALCON_ALLOC_ZVAL_MM(r23);
		sub_function(r23, v2, t11 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r23);
	} else {
		PHALCON_INIT_VAR(v9);
		ZVAL_LONG(v9, 1);
	}
	phalcon_update_property_zval(v4, "before", strlen("before"), v9 TSRMLS_CC);
	phalcon_update_property_zval(v4, "current", strlen("current"), v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r24);
	mod_function(r24, v3, v0 TSRMLS_CC);
	if (zend_is_true(r24)) {
		PHALCON_ALLOC_ZVAL_MM(r25);
		PHALCON_ALLOC_ZVAL_MM(r26);
		div_function(r26, v3, v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r25, "intval", r26, 0x01E);
		PHALCON_INIT_VAR(t12);
		ZVAL_LONG(t12, 1);
		PHALCON_ALLOC_ZVAL_MM(r27);
		phalcon_add_function(r27, r25, t12 TSRMLS_CC);
		PHALCON_CPY_WRT(v10, r27);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r28);
		div_function(r28, v3, v0 TSRMLS_CC);
		PHALCON_CPY_WRT(v10, r28);
	}
	phalcon_update_property_zval(v4, "last", strlen("last"), v10 TSRMLS_CC);
	phalcon_update_property_zval(v4, "total_pages", strlen("total_pages"), v10 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v4);
}

/**
* Paginator Exception
*
* @param string $message
*/
PHP_METHOD(Phalcon_Tag_Exception, __construct){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Tag_Exception", "__construct", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Controller
 *
 * Every application controller should extends this class that encapsulates all the controller functionality
 *
 * Controllers provide the “flow” between models and views. Controllers are responsible
 * for processing the incoming requests from the web browser, interrogating the models for data,
 * and passing that data on to the views for presentation.
 *
 *
 */

/**
 * Constructor for Phalcon_Controller
 *
 * @param Phalcon_Dispatcher $dispatcher
 * @param Phalcon_Request $request
 * @param Phalcon_Response $response
 * @param Phalcon_View $view
 * @param Phalcon_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	if (!v4) {
		PHALCON_INIT_VAR(v4);
		ZVAL_NULL(v4);
	}
	
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "request", strlen("request"), v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "response", strlen("response"), v2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "view", strlen("view"), v3 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), v4 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Forwards execution flow to another controller/action.
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Controller, _forward){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, t0, "forward", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_Controller, __get){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (PHALCON_COMPARE_STRING(v0, "view")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "view", strlen("view"), r0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "view", sizeof("view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t0);
	}
	if (PHALCON_COMPARE_STRING(v0, "filter")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "filter", strlen("filter"), i0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "filter", sizeof("filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t1);
	}
	if (PHALCON_COMPARE_STRING(v0, "session")) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_session_namespace_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x01F);
		Z_ADDREF_P(r1);
		p2[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		phalcon_update_property_zval(this_ptr, "session", strlen("session"), i1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "session", sizeof("session")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t3)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p4[0] = v0;
		PHALCON_CALL_METHOD_PARAMS(r2, t4, "ismodel", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v0);
			p5[0] = v0;
			PHALCON_CALL_METHOD_PARAMS(r3, t5, "getmodel", 1, p5, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p5[0]);
			PHALCON_RETURN_DZVAL(r3);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Paginator
 *
 * Phalcon_Paginator is designed to simplify building of pagination on views
 *
 * 
 *
 */

/**
     * Factories a paginator adapter
     *
     * @param   string $adapterName
     * @param   array $options
     * @return  Object
     */
PHP_METHOD(Phalcon_Paginator, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Paginator_Adapter_", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v2, 0x00F);
	Z_DELREF_P(v2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_paginator_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "The paginator adapter file \"", v0, "\" does not exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	PHALCON_CPY_WRT(v3, i1);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Phalcon_Utils
 *
 * Implements functionality used widely by the framework
 */

/**
 * Converts strings to camelize style
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Utils, camelize){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p2[] = { NULL, NULL, NULL }, *p0[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], " ", 1);
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_STRING(p0[1], "", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(p2[0]);
	ZVAL_STRING(p2[0], "_", 1);
	PHALCON_INIT_VAR(p2[1]);
	ZVAL_STRING(p2[1], " ", 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", v0, 0x021);
	p2[2] = r3;
	PHALCON_CALL_FUNC_PARAMS(r2, "str_replace", 3, p2, 0x003);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ucwords", r2, 0x020);
	p0[2] = r1;
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x003);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Uncamelize strings which are camelized
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Utils, uncamelize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p2[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_stringl_ex(a0, "/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/", strlen("/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/")+1, "\\1_\\2", strlen("\\1_\\2"), 1);
	add_assoc_stringl_ex(a0, "/(?<=(?:[a-z]))([A-Z])/", strlen("/(?<=(?:[a-z]))([A-Z])/")+1, "_\\1", strlen("_\\1"), 1);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_6277_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_6277_0;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		Z_ADDREF_P(v3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "preg_match", v3, v0, 0x022);
		Z_DELREF_P(v3);
		Z_DELREF_P(v0);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(r1);
			PHALCON_INIT_VAR(r2);
			p2[0] = v3;
			p2[1] = v2;
			p2[2] = v0;
			PHALCON_CALL_FUNC_PARAMS(r2, "preg_replace", 3, p2, 0x023);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "strtolower", r2, 0x021);
			PHALCON_RETURN_DZVAL(r1);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_6277_0;
		fee_6277_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", v0, 0x021);
	PHALCON_RETURN_DZVAL(r3);
}

/**
     * Changes only first letter to lowercase
     *     
     * @param string $str
     * @return string
     * @static
     **/
PHP_METHOD(Phalcon_Utils, lcfirst){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_INIT_VAR(p1[1]);
	ZVAL_LONG(p1[1], 0);
	PHALCON_INIT_VAR(p1[2]);
	ZVAL_LONG(p1[2], 1);
	PHALCON_CALL_FUNC_PARAMS(r1, "substr", 3, p1, 0x002);
	Z_DELREF_P(p1[0]);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strtolower", r1, 0x021);
	PHALCON_ALLOC_ZVAL_MM(r2);
	Z_ADDREF_P(v0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "substr", v0, c0, 0x002);
	Z_DELREF_P(v0);
	PHALCON_ALLOC_ZVAL_MM(r3);
	concat_function(r3, r0, r2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r3);
}

/**
 * Gets public URL to phalcon instance
 *
 * @param string $params
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getUrl){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbaseuri", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

/**
 * Gets path to local file
 *
 * @param string $params
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getLocalPath){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbasepath", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

/**
 * Phalcon_Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 * 
 */

PHP_METHOD(Phalcon_Dispatcher, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_dispatcher_class_entry, this_ptr, "_controllers", strlen("_controllers"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_dispatcher_class_entry, this_ptr, "_params", strlen("_params"), a1 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets default controllers directory
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Dispatcher, setControllersDir){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets active controllers directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllersDir){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets base path for controllers dir
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Dispatcher, setBasePath){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets base path for controllers dir
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getBasePath){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setControllerName){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets last dispacthed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets last dispacthed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets action params to be dispatch
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets action params
     *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Dispatchs a action controller taking care of routing
 *
 * @param Phalcon_Request $request
 * @param Phalcon_Response $response
 * @param Phalcon_View $view
 * @param Phalcon_Model_Manager $model
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL, NULL, NULL, NULL }, *p7[] = { NULL, NULL, NULL }, *p10[] = { NULL, NULL }, *p11[] = { NULL }, *p12[] = { NULL, NULL, NULL }, *p13[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_NULL(v2);
	}
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_INIT_VAR(v5);
	ZVAL_NULL(v5);
	PHALCON_INIT_VAR(v6);
	ZVAL_NULL(v6);
	PHALCON_INIT_VAR(v7);
	ZVAL_LONG(v7, 0);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	ws_e10f_0:
	PHALCON_INIT_VAR(t2);
	phalcon_read_property(&t2, this_ptr, "_finished", sizeof("_finished")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t2)) {
		goto we_e10f_0;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 1 TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	phalcon_read_property(&t3, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v8, t3);
	if (!zend_is_true(v8)) {
		PHALCON_INIT_VAR(t4);
		phalcon_read_property(&t4, this_ptr, "_defaultController", sizeof("_defaultController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t4);
		phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), v8 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t5);
	phalcon_read_property(&t5, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v9, t5);
	PHALCON_INIT_VAR(r1);
	Z_ADDREF_P(v8);
	p0[0] = v8;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_utils", "camelize", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_INIT_VAR(r2);
	PHALCON_CONCAT_RIGHT(r2, r1, "Controller");
	PHALCON_CPY_WRT(v10, r2);
	eval_int = phalcon_array_isset(v9, v10);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		PHALCON_INIT_VAR(r4);
		Z_ADDREF_P(v10);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_FUNC_PARAMS_2(r4, "class_exists", v10, c0, 0x00F);
		Z_DELREF_P(v10);
		if (!zend_is_true(r4)) {
			PHALCON_INIT_VAR(r5);
			concat_function(r5, v4, v10 TSRMLS_CC);
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_RIGHT(r6, r5, ".php");
			PHALCON_CPY_WRT(v11, r6);
			if (phalcon_file_exists(v11 TSRMLS_CC) == SUCCESS) {
				phalcon_require(v11 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
			} else {
				PHALCON_INIT_VAR(i0);
				object_init_ex(i0, phalcon_exception_class_entry);
				PHALCON_INIT_VAR(r7);
				PHALCON_CONCAT_BOTH(r7,  "File for controller class ", v10, " doesn't exist");
				Z_ADDREF_P(r7);
				p2[0] = r7;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
				Z_DELREF_P(p2[0]);
				return phalcon_throw_exception(i0 TSRMLS_CC);
			}
			PHALCON_INIT_VAR(r8);
			Z_ADDREF_P(v10);
			PHALCON_INIT_VAR(c1);
			ZVAL_BOOL(c1, 0);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "class_exists", v10, c1, 0x00F);
			Z_DELREF_P(v10);
			if (!zend_is_true(r8)) {
				PHALCON_INIT_VAR(i1);
				object_init_ex(i1, phalcon_exception_class_entry);
				PHALCON_INIT_VAR(r9);
				PHALCON_CONCAT_BOTH(r9,  "Class ", v10, " was not found on controller file");
				Z_ADDREF_P(r9);
				p4[0] = r9;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
				Z_DELREF_P(p4[0]);
				return phalcon_throw_exception(i1 TSRMLS_CC);
			}
		}
		ce0 = zend_fetch_class(Z_STRVAL_P(v10), Z_STRLEN_P(v10), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_INIT_VAR(i2);
		object_init_ex(i2, ce0);
		Z_ADDREF_P(this_ptr);
		p5[0] = this_ptr;
		Z_ADDREF_P(v0);
		p5[1] = v0;
		Z_ADDREF_P(v1);
		p5[2] = v1;
		Z_ADDREF_P(v2);
		p5[3] = v2;
		Z_ADDREF_P(v3);
		p5[4] = v3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 5, p5, PHALCON_CALL_CHECK);
		Z_DELREF_P(p5[0]);
		Z_DELREF_P(p5[1]);
		Z_DELREF_P(p5[2]);
		Z_DELREF_P(p5[3]);
		Z_DELREF_P(p5[4]);
		PHALCON_CPY_WRT(v6, i2);
		if (phalcon_method_exists_ex(v6, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(v6, "initialize", PHALCON_CALL_DEFAULT);
		}
		PHALCON_INIT_VAR(t6);
		phalcon_read_property(&t6, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v6);
		phalcon_array_update(t6, v10, v6 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_controllers", strlen("_controllers"), t6 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(r10);
		phalcon_array_fetch(&r10, v9, v10, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r10);
	}
	PHALCON_INIT_VAR(t7);
	phalcon_read_property(&t7, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v12, t7);
	PHALCON_INIT_VAR(t8);
	phalcon_read_property(&t8, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v13, t8);
	if (!zend_is_true(v13)) {
		PHALCON_INIT_VAR(t9);
		phalcon_read_property(&t9, this_ptr, "_defaultAction", sizeof("_defaultAction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v13, t9);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), v13 TSRMLS_CC);
	}
	if (phalcon_method_exists_ex(v6, "beforedispatch", strlen("beforedispatch") TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(r11);
		Z_ADDREF_P(v8);
		p7[0] = v8;
		Z_ADDREF_P(v13);
		p7[1] = v13;
		Z_ADDREF_P(v12);
		p7[2] = v12;
		PHALCON_CALL_METHOD_PARAMS(r11, v6, "beforedispatch", 3, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		Z_DELREF_P(p7[1]);
		Z_DELREF_P(p7[2]);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			PHALCON_INIT_VAR(v5);
			ZVAL_BOOL(v5, 0);
			goto we_e10f_0;
		}
	}
	PHALCON_INIT_VAR(r12);
	PHALCON_CONCAT_RIGHT(r12, v13, "Action");
	PHALCON_CPY_WRT(v14, r12);
	if (phalcon_method_exists(v6, v14 TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(r13);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v6);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v6);
		Z_ADDREF_P(v14);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v14);
		Z_ADDREF_P(a0);
		Z_ADDREF_P(v12);
		PHALCON_CALL_FUNC_PARAMS_2(r13, "call_user_func_array", a0, v12, 0x010);
		Z_DELREF_P(a0);
		Z_DELREF_P(v12);
		PHALCON_CPY_WRT(v5, r13);
	} else {
		if (phalcon_method_exists_ex(v6, "notfoundaction", strlen("notfoundaction") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(r14);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			Z_ADDREF_P(v6);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, v6);
			add_next_index_stringl(a1, "notFoundAction", strlen("notFoundAction"), 1);
			Z_ADDREF_P(a1);
			Z_ADDREF_P(v12);
			PHALCON_CALL_FUNC_PARAMS_2(r14, "call_user_func_array", a1, v12, 0x010);
			Z_DELREF_P(a1);
			Z_DELREF_P(v12);
			PHALCON_CPY_WRT(v5, r14);
		} else {
			PHALCON_INIT_VAR(p10[0]);
			ZVAL_LONG(p10[0], 404);
			PHALCON_INIT_VAR(p10[1]);
			ZVAL_STRING(p10[1], "Not Found", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setstatuscode", 2, p10, PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(i3);
			object_init_ex(i3, phalcon_exception_class_entry);
			PHALCON_INIT_VAR(r16);
			PHALCON_CONCAT_LEFT(r16, "Action '", v13);
			PHALCON_INIT_VAR(r15);
			PHALCON_CONCAT_VBOTH(r15, r16, "' was not found on controller '", v8);
			PHALCON_INIT_VAR(r17);
			PHALCON_CONCAT_RIGHT(r17, r15, "'");
			Z_ADDREF_P(r17);
			p11[0] = r17;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p11, PHALCON_CALL_CHECK);
			Z_DELREF_P(p11[0]);
			return phalcon_throw_exception(i3 TSRMLS_CC);
		}
	}
	if (phalcon_method_exists_ex(v6, "afterdispatch", strlen("afterdispatch") TSRMLS_CC) == SUCCESS) {
		Z_ADDREF_P(v8);
		p12[0] = v8;
		Z_ADDREF_P(v13);
		p12[1] = v13;
		Z_ADDREF_P(v12);
		p12[2] = v12;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "afterdispatch", 3, p12, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p12[0]);
		Z_DELREF_P(p12[1]);
		Z_DELREF_P(p12[2]);
	}
	PHALCON_SEPARATE(v7);
	increment_function(v7);
	PHALCON_INIT_VAR(t10);
	ZVAL_LONG(t10, 256);
	PHALCON_INIT_VAR(r18);
	is_smaller_function(r18, t10, v7 TSRMLS_CC);
	if (zend_is_true(r18)) {
		PHALCON_INIT_VAR(i4);
		object_init_ex(i4, phalcon_exception_class_entry);
		PHALCON_INIT_VAR(p13[0]);
		ZVAL_STRING(p13[0], "Dispatcher has detected a cyclic routing causing stability problems", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 1, p13, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i4 TSRMLS_CC);
	}
	goto ws_e10f_0;
	we_e10f_0:
	if(0) { };
	phalcon_update_property_zval(this_ptr, "_returnedValue", strlen("_returnedValue"), v5 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_lastController", strlen("_lastController"), v6 TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(v6);
}

/**
 * Routes to a controller/action using a string or array uri
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Dispatcher, forward){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		PHALCON_CPY_WRT(v1, v0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "explode", c0, v0, 0x005);
		PHALCON_CPY_WRT(v1, r0);
	}
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_filter_alphanum(r2, p1[0]);
		phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), r2 TSRMLS_CC);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 0);
	} else {
		eval_int = phalcon_array_isset_string(v1, "controller", strlen("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, v1, "controller", strlen("controller"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r3;
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_filter_alphanum(r4, p2[0]);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), r4 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getcontrollername", PHALCON_CALL_DEFAULT);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), r5 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_long(&r6, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p4[0] = r6;
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_filter_alphanum(r7, p4[0]);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r7 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_long(&r8, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r8 TSRMLS_CC);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 1);
	} else {
		eval_int = phalcon_array_isset_string(v1, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			phalcon_array_fetch_string(&r9, v1, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p5[0] = r9;
			PHALCON_ALLOC_ZVAL_MM(r10);
			phalcon_filter_alphanum(r10, p5[0]);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r10 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_CALL_METHOD(r11, this_ptr, "getactionname", PHALCON_CALL_DEFAULT);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r11 TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e10f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e10f_1;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		if (Z_TYPE_P(v4) == IS_LONG) {
			PHALCON_INIT_VAR(r12);
			phalcon_array_fetch(&r12, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r12);
			PHALCON_SEPARATE_ARRAY(v2);
			phalcon_array_append(v2, r12 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e10f_1;
		fee_e10f_1:
		if(0){ };
	}
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), v2 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns all instantiated controllers whitin the dispatcher
 *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getControllers){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns last dispatched controller
 *
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, getLastController){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_lastController", sizeof("_lastController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns value returned by last dispacthed action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_returnedValue", sizeof("_returnedValue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Db_Pool
 *
 * Manages caching of database connections. With the help of Phalcon_Db_Pool, developers can be sure that no new database
 * connections will made when calling multiple of times Phalcon_Db_Pool::getConnection.
 */

/**
 * Check if a default descriptor has already defined
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Pool, hasDefaultDescriptor){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_INIT_VAR(r0);
	is_not_identical_function(r0, t1, t0 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Sets the default descriptor for database connections.
 *
 *
 *
 * @param array $options
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Pool, setDefaultDescriptor){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			PHALCON_INIT_VAR(p0[0]);
			ZVAL_STRING(p0[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_INIT_VAR(p0[1]);
			ZVAL_LONG(p0[1], 0);
			PHALCON_INIT_VAR(p0[2]);
			ZVAL_BOOL(p0[2], 1);
			PHALCON_INIT_VAR(p0[3]);
			ZVAL_NULL(p0[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init(i1);
		PHALCON_CPY_WRT(v1, i1);
		if (Z_TYPE_P(v0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_162f_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_162f_0;
			} else {
				PHALCON_INIT_VAR(v3);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v3, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v3, num);
					}
				}
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), v2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_162f_0;
			fee_162f_0:
			if(0){ };
		}
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	zend_update_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns a connection builded with the default descriptor parameters
 *
 * 
 *
 * @param boolean $newConnection
     * @param boolean $renovate
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Db_Pool, getConnection){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Default database connection parameters was not defined", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_LONG(p0[1], 0);
		PHALCON_INIT_VAR(p0[2]);
		ZVAL_BOOL(p0[2], 1);
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_isset_property(v2, "adapter", strlen("adapter") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_BOOL(t1, eval_int);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "A valid adapter name is required", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		PHALCON_INIT_VAR(p1[3]);
		ZVAL_NULL(p1[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	if (zend_is_true(v0)) {
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t2);
			p2[0] = t2;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			PHALCON_INIT_VAR(p2[2]);
			ZVAL_BOOL(p2[2], 1);
			PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db", "factory", 3, p2);
			Z_DELREF_P(p2[0]);
			Z_DELREF_P(p2[1]);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r0 TSRMLS_CC);
			t3 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_CPY_WRT(v3, t3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t4);
			p3[0] = t4;
			Z_ADDREF_P(v2);
			p3[1] = v2;
			PHALCON_INIT_VAR(p3[2]);
			ZVAL_BOOL(p3[2], 0);
			PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_db", "factory", 3, p3);
			Z_DELREF_P(p3[0]);
			Z_DELREF_P(p3[1]);
			PHALCON_CPY_WRT(v3, r1);
		}
	} else {
		t5 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t5)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t6);
			p4[0] = t6;
			Z_ADDREF_P(v2);
			p4[1] = v2;
			PHALCON_INIT_VAR(p4[2]);
			ZVAL_BOOL(p4[2], 1);
			PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_db", "factory", 3, p4);
			Z_DELREF_P(p4[0]);
			Z_DELREF_P(p4[1]);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r2 TSRMLS_CC);
		}
		t7 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v3, t7);
	}
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * Phalcon_Db_Profiler
 *
 * Instances of Phalcon_Db can generate execution profiles
 * on SQL statements sended to the relational database. Profiled
 * information includes excution time in miliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 */

PHP_METHOD(Phalcon_Db_Profiler, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_db_profiler_class_entry, this_ptr, "_allProfiles", strlen("_allProfiles"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Starts the profile of a SQL sentence
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_db_profiler_item_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_update_property_zval(this_ptr, "_activeProfile", strlen("_activeProfile"), i0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "setsqlstatement", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "microtime", c0, 0x024);
	Z_ADDREF_P(r0);
	p2[0] = r0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "setinitialtime", 1, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	if (phalcon_method_exists_ex(this_ptr, "beforestartprofile", strlen("beforestartprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t2);
		p4[0] = t2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "beforestartprofile", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Stops the active profile
 *
 * @access public
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "microtime", c0, 0x024);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "setfinaltime", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_totalSeconds", sizeof("_totalSeconds")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t2, "getinitialtime", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, v0, r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_add_function(r3, t1, r2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_totalSeconds", strlen("_totalSeconds"), r3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_allProfiles", sizeof("_allProfiles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t3);
	phalcon_array_append(t4, t3 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_allProfiles", strlen("_allProfiles"), t4 TSRMLS_CC);
	if (phalcon_method_exists_ex(this_ptr, "afterendprofile", strlen("afterendprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t5);
		p3[0] = t5;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "afterendprofile", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Returns the total number of SQL statements processed
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_allProfiles", sizeof("_allProfiles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns the total time in seconds spent by the profiles
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_totalSeconds", sizeof("_totalSeconds")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns all the processed profiles
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_allProfiles", sizeof("_allProfiles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Resets the profiler, cleaning up all the profiles
 *
 */
PHP_METHOD(Phalcon_Db_Profiler, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_allProfiles", strlen("_allProfiles"), a0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the last profile executed in the profiler
 *
 * @returnPhalcon_Db_Profiler_Item
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Db_Exception
 *
 * Exceptions thrown in Phalcon_Db will use this class
 *
 */

/**
 * Phalcon_Db_Exception constructor
 *
 * @param string $message
 * @param int $code
 * @param boolean $showTrace
 * @param array $backtrace
 */
PHP_METHOD(Phalcon_Db_Exception, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_Exception", "__construct", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Db_Reference
 *
 * Allows to define reference constraints on tables
 *
 *
 */

/**
 * Phalcon_Db_Reference constructor
 *
 * @param string $indexName
 * @param array $columns
 */
PHP_METHOD(Phalcon_Db_Reference, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p5[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_referenceName", strlen("_referenceName"), v0 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v1, "referencedTable", strlen("referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "referencedTable", strlen("referencedTable"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedTable", strlen("_referencedTable"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Referenced table is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v1, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Foreign key columns are required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "referencedColumns", strlen("referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v1, "referencedColumns", strlen("referencedColumns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedColumns", strlen("_referencedColumns"), r2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Referenced columns of the foreign key are required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i2 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "schema", strlen("schema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v1, "schema", strlen("schema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r3 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "referencedSchema", strlen("referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v1, "referencedSchema", strlen("referencedSchema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedSchema", strlen("_referencedSchema"), r4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r5, "count", t0, 0x007);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_referencedColumns", sizeof("_referencedColumns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r6, "count", t1, 0x007);
	PHALCON_INIT_VAR(r7);
	is_not_equal_function(r7, r5, r6 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p5[0]);
		ZVAL_STRING(p5[0], "Number of columns is not equals than the number of columns referenced", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p5, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i3 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets the index name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_referenceName", sizeof("_referenceName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schemaName", sizeof("_schemaName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_referencedSchema", sizeof("_referencedSchema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the referenced table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_referencedTable", sizeof("_referencedTable")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets referenced columns
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_referencedColumns", sizeof("_referencedColumns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Restore a Phalcon_Db_Reference object from export
 *
 * @param array $data
 * @return Phalcon_Db_Reference
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	eval_int = phalcon_array_isset_string(v0, "_referenceName", strlen("_referenceName")+1);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "_referenceName parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "_referenceName", strlen("_referenceName"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r1);
	}
	eval_int = phalcon_array_isset_string(v0, "_referencedSchema", strlen("_referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v0, "_referencedSchema", strlen("_referencedSchema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_INIT_VAR(v2);
		ZVAL_NULL(v2);
	}
	eval_int = phalcon_array_isset_string(v0, "_referencedTable", strlen("_referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v0, "_referencedTable", strlen("_referencedTable"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r3);
	} else {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	eval_int = phalcon_array_isset_string(v0, "_columns", strlen("_columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v0, "_columns", strlen("_columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r4);
	} else {
		PHALCON_INIT_VAR(v4);
		ZVAL_NULL(v4);
	}
	eval_int = phalcon_array_isset_string(v0, "_referencedColumns", strlen("_referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v0, "_referencedColumns", strlen("_referencedColumns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r5);
	} else {
		PHALCON_INIT_VAR(v5);
		ZVAL_NULL(v5);
	}
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_reference_class_entry);
	Z_ADDREF_P(v1);
	p1[0] = v1;
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(v2);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "referencedSchema", v2);
	Z_ADDREF_P(v3);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "referencedTable", v3);
	Z_ADDREF_P(v4);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "columns", v4);
	Z_ADDREF_P(v5);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "referencedColumns", v5);
	Z_ADDREF_P(a0);
	p1[1] = a0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p1, PHALCON_CALL_CHECK);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
	PHALCON_RETURN_CTOR(i1);
}

/**
 * Phalcon_Db_Mysql
 *
 * Phalcon_Db_Mysql is the Phalcon_Db adapter for MySQL database.
 * 
 */

/**
 * Constructor for Phalcon_Db_Adapter_Mysql. This method does not should to be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
 * @param boolean $persistent
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "")) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t0);
	}
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "connect", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * This method is automatically called in Phalcon_Db_Mysql constructor.
 * Call it when you need to restore a database connection
 *
 * @param stdClass $descriptor
 * @param boolean $persistent
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, connect){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL, *t27 = NULL;
	zval *t28 = NULL, *t29 = NULL, *t30 = NULL, *t31 = NULL, *t32 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t0);
	}
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_BOOL(t1, eval_int);
	if (zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r0 = t2;
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_STRING(t3, "", 1);
		r0 = t3;
	}
	PHALCON_CPY_WRT(v2, r0);
	eval_int = phalcon_isset_property(v0, "username", strlen("username") TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_BOOL(t4, eval_int);
	if (zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, v0, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r1 = t5;
	} else {
		PHALCON_INIT_VAR(t6);
		ZVAL_STRING(t6, "", 1);
		r1 = t6;
	}
	PHALCON_CPY_WRT(v3, r1);
	eval_int = phalcon_isset_property(v0, "password", strlen("password") TSRMLS_CC);
	PHALCON_INIT_VAR(t7);
	ZVAL_BOOL(t7, eval_int);
	if (zend_is_true(t7)) {
		PHALCON_ALLOC_ZVAL_MM(t8);
		phalcon_read_property(&t8, v0, "password", sizeof("password")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r2 = t8;
	} else {
		PHALCON_INIT_VAR(t9);
		ZVAL_STRING(t9, "", 1);
		r2 = t9;
	}
	PHALCON_CPY_WRT(v4, r2);
	eval_int = phalcon_isset_property(v0, "port", strlen("port") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t10);
		phalcon_read_property(&t10, v0, "port", sizeof("port")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_VBOTH(r3, v2, ":", t10);
		PHALCON_CPY_WRT(v5, r3);
	} else {
		PHALCON_CPY_WRT(v5, v2);
	}
	PHALCON_INIT_VAR(v6);
	ZVAL_NULL(v6);
	eval_int = phalcon_isset_property(v0, "compression", strlen("compression") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_read_property(&t11, v0, "compression", sizeof("compression")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t11)) {
			if (!zend_is_true(v6)) {
				PHALCON_INIT_VAR(t12);
				ZVAL_LONG(t12, 32);
				PHALCON_CPY_WRT(v6, t12);
			} else {
				PHALCON_INIT_VAR(t13);
				ZVAL_LONG(t13, 32);
				PHALCON_ALLOC_ZVAL_MM(r4);
				bitwise_or_function(r4, v6, t13 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r4);
			}
		}
	}
	eval_int = phalcon_isset_property(v0, "ssl", strlen("ssl") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t14);
		phalcon_read_property(&t14, v0, "ssl", sizeof("ssl")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t14)) {
			if (!zend_is_true(v6)) {
				PHALCON_INIT_VAR(t15);
				ZVAL_LONG(t15, 2048);
				PHALCON_CPY_WRT(v6, t15);
			} else {
				PHALCON_INIT_VAR(t16);
				ZVAL_LONG(t16, 2048);
				PHALCON_ALLOC_ZVAL_MM(r5);
				bitwise_or_function(r5, v6, t16 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r5);
			}
		}
	}
	eval_int = phalcon_isset_property(v0, "interactive", strlen("interactive") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t17);
		phalcon_read_property(&t17, v0, "interactive", sizeof("interactive")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t17)) {
			if (!zend_is_true(v6)) {
				PHALCON_INIT_VAR(t18);
				ZVAL_LONG(t18, 1024);
				PHALCON_CPY_WRT(v6, t18);
			} else {
				PHALCON_INIT_VAR(t19);
				ZVAL_LONG(t19, 1024);
				PHALCON_ALLOC_ZVAL_MM(r6);
				bitwise_or_function(r6, v6, t19 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r6);
			}
		}
	}
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		p0[0] = v5;
		p0[1] = v3;
		p0[2] = v4;
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_BOOL(p0[3], 1);
		p0[4] = v6;
		PHALCON_CALL_FUNC_PARAMS(r7, "mysql_connect", 5, p0, 0x025);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r7 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		p1[0] = v5;
		p1[1] = v3;
		p1[2] = v4;
		p1[3] = v6;
		PHALCON_CALL_FUNC_PARAMS(r8, "mysql_pconnect", 4, p1, 0x026);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r8 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t20);
	phalcon_read_property(&t20, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t20)) {
		eval_int = phalcon_isset_property(v0, "name", strlen("name") TSRMLS_CC);
		PHALCON_INIT_VAR(t21);
		ZVAL_BOOL(t21, eval_int);
		if (zend_is_true(t21)) {
			PHALCON_ALLOC_ZVAL_MM(t22);
			phalcon_read_property(&t22, v0, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			r9 = t22;
		} else {
			PHALCON_INIT_VAR(t23);
			ZVAL_STRING(t23, "", 1);
			r9 = t23;
		}
		PHALCON_CPY_WRT(v7, r9);
		PHALCON_INIT_VAR(t24);
		ZVAL_STRING(t24, "", 1);
		PHALCON_INIT_VAR(r10);
		is_not_identical_function(r10, t24, v7 TSRMLS_CC);
		if (zend_is_true(r10)) {
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_ALLOC_ZVAL_MM(t25);
			phalcon_read_property(&t25, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_2(r11, "mysql_select_db", v7, t25, 0x027);
			if (!zend_is_true(r11)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_db_exception_class_entry);
				PHALCON_ALLOC_ZVAL_MM(r12);
				PHALCON_CALL_METHOD(r12, this_ptr, "error", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r12);
				p3[0] = r12;
				PHALCON_ALLOC_ZVAL_MM(r13);
				PHALCON_CALL_METHOD(r13, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r13);
				p3[1] = r13;
				PHALCON_INIT_VAR(p3[2]);
				ZVAL_BOOL(p3[2], 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p3, PHALCON_CALL_CHECK);
				Z_DELREF_P(p3[0]);
				Z_DELREF_P(p3[1]);
				return phalcon_throw_exception(i0 TSRMLS_CC);
			}
		}
		eval_int = phalcon_isset_property(v0, "autocommit", strlen("autocommit") TSRMLS_CC);
		PHALCON_INIT_VAR(t26);
		ZVAL_BOOL(t26, eval_int);
		if (zend_is_true(t26)) {
			PHALCON_ALLOC_ZVAL_MM(t27);
			phalcon_read_property(&t27, v0, "autocommit", sizeof("autocommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			r14 = t27;
		} else {
			PHALCON_INIT_VAR(t28);
			ZVAL_BOOL(t28, 0);
			r14 = t28;
		}
		PHALCON_CPY_WRT(v8, r14);
		phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), v8 TSRMLS_CC);
		PHALCON_INIT_VAR(t29);
		ZVAL_LONG(t29, 3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t29 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p6[0] = v0;
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_Adapter_Mysql", "__construct", 1, p6);
		Z_DELREF_P(p6[0]);
		eval_int = phalcon_isset_property(v0, "charset", strlen("charset") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t30);
			phalcon_read_property(&t30, v0, "charset", sizeof("charset")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "SET NAMES ", t30);
			Z_ADDREF_P(r15);
			p7[0] = r15;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p7, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p7[0]);
		}
		eval_int = phalcon_isset_property(v0, "collation", strlen("collation") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t31);
			phalcon_read_property(&t31, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_LEFT(r16, "SET collation_connection=", t31);
			Z_ADDREF_P(r16);
			p8[0] = r16;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p8[0]);
			PHALCON_ALLOC_ZVAL_MM(t32);
			phalcon_read_property(&t32, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_CONCAT_LEFT(r17, "SET collation_database=", t32);
			Z_ADDREF_P(r17);
			p9[0] = r17;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p9[0]);
		}
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CALL_METHOD(r18, this_ptr, "error", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r18);
		p10[0] = r18;
		PHALCON_ALLOC_ZVAL_MM(r19);
		PHALCON_CALL_METHOD(r19, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r19);
		p10[1] = r19;
		PHALCON_INIT_VAR(p10[2]);
		ZVAL_BOOL(p10[2], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p10, PHALCON_CALL_CHECK);
		Z_DELREF_P(p10[0]);
		Z_DELREF_P(p10[1]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sends SQL statements to the MySQL database server returning success state.
 * When the SQL sent have returned any row, the result is a PHP resource.
 *
 * 
 *
 * @param  string $sqlStatement
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, query){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL }, *p5[] = { NULL }, *p4[] = { NULL }, *p7[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	if (!zend_is_true(v1)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "connect", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(t1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	phalcon_update_property_zval(this_ptr, "_lastQuery", strlen("_lastQuery"), v0 TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_beforequery", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_query", v0, v1, 0x028);
	PHALCON_CPY_WRT(v2, r0);
	if (zend_is_true(v2)) {
		phalcon_update_property_zval(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), v2 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_afterquery", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		PHALCON_RETURN_CHECK_CTOR(v2);
	} else {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), 0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, " when executing \"", v0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_INIT_VAR(p5[0]);
		ZVAL_BOOL(p5[0], 1);
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "getconnectionid", 1, p5, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, "\" on connection \"", r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_RIGHT(r5, r2, "\"");
		Z_ADDREF_P(r5);
		p4[0] = r5;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		PHALCON_CPY_WRT(v3, r1);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_METHOD(r6, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r6);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD(r7, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r7);
		p7[1] = r7;
		PHALCON_INIT_VAR(p7[2]);
		ZVAL_BOOL(p7[2], 1);
		Z_ADDREF_P(this_ptr);
		p7[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p7, PHALCON_CALL_CHECK);
		Z_DELREF_P(p7[0]);
		Z_DELREF_P(p7[1]);
		Z_DELREF_P(p7[3]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon_Db_Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, close){

	zval *t0 = NULL, *t1 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zend_bool silence;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		silence = PG(display_errors);
		PG(display_errors) = 0;
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_close", t1, 0x029);
		Z_DELREF_P(t1);
		PG(display_errors) = silence;
		PHALCON_CPY_WRT(v0, r0);
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_idConnection", strlen("_idConnection") TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon_Db_Mysql::setFetchMode
 *
 * 
 *
 * @param resource $resultQuery
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, fetchArray){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		if (!zend_is_true(v0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_fetch_array", v0, t2, 0x02A);
	Z_DELREF_P(v0);
	Z_DELREF_P(t2);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets number of rows returned by a resulset
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, numRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p2[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		if (!zend_is_true(v0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_num_rows", v0, 0x02B);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	if (Z_TYPE_P(v1) != IS_BOOL || (Z_TYPE_P(v1) == IS_BOOL && Z_BVAL_P(v1))) {
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[3]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dataSeek){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t0);
		if (!zend_is_true(v1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_data_seek", v1, v0, 0x02C);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if (Z_TYPE_P(v2) != IS_BOOL || (Z_TYPE_P(v2) == IS_BOOL && Z_BVAL_P(v2))) {
		PHALCON_RETURN_CHECK_CTOR(v2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v3, pv0, "php_errormsg");
		Z_ADDREF_P(v3);
		p2[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns number of affected rows by the last INSERT/UPDATE/DELETE repoted by MySQL
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, affectedRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_affected_rows", t0, 0x02D);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	if (Z_TYPE_P(v1) != IS_BOOL || (Z_TYPE_P(v1) == IS_BOOL && Z_BVAL_P(v1))) {
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Changes the fetching mode affecting Phalcon_Db_Mysql::fetchArray
 *
 * 
 *
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, setFetchMode){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 2);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t3 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v0, t4 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t5 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns last error message from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, error){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "mysql_error", 0x02E);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "mysql_error", t1, 0x02E);
		PHALCON_CPY_WRT(v2, r1);
	}
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "\"", v2);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, "\" ", v0);
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "[Unknown MySQL error: ", v0, "]");
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_lastError", sizeof("_lastError")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Returns last error code from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, noError){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_errno", t1, 0x02F);
	Z_DELREF_P(t1);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string $table
 * @param string $primaryKey
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, lastInsertId){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_insert_id", t1, 0x030);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets a list of columns
 *
 * @paramarray $columnList
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getColumnList){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "getcolumnlist", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * 
 *
 * @param string $errorString
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, limit){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "limit", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, tableExists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "tableexists", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchone", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v4, r1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), v3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r2);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, viewExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "tableexists", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Devuelve un FOR UPDATE valido para un SELECT del RBDM
 *
 * @paramstring $sqlQuery
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, forUpdate){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_RIGHT(r0, v0, " FOR UPDATE");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Devuelve un SHARED LOCK valido para un SELECT del RBDM
 *
 * @paramstring $sqlQuery
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, sharedLock){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_RIGHT(r0, v0, " LOCK IN SHARE MODE");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Creates a table using MySQL SQL
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramarray $definition
 * @returnboolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, createTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL, NULL }, *p5[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "Invalid definition to create the table '", v0, "'");
		Z_ADDREF_P(r0);
		p0[0] = r0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v2, "columns", strlen("columns")+1);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "The table must contain at least one column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, v2, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", r3, 0x007);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "The table must contain at least one column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i2 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v0);
	p4[0] = v0;
	Z_ADDREF_P(v1);
	p4[1] = v1;
	Z_ADDREF_P(v2);
	p4[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_db_dialect_mysql", "createtable", 3, p4);
	Z_DELREF_P(p4[0]);
	Z_DELREF_P(p4[1]);
	Z_DELREF_P(p4[2]);
	PHALCON_CPY_WRT(v3, r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	Z_ADDREF_P(v3);
	p5[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r5, this_ptr, "query", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	PHALCON_RETURN_DZVAL(r5);
}

/**
 * Drops a table from a schema/database
 *
 * @paramstring $tableName
 * @param   string $schemaName
 * @paramboolean $ifExists
 * @returnboolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "droptable", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a column to a table
 *
 * @paramstring $tableName
 * @param string $schemaName
 * @paramPhalcon_Db_Column $column
 * @returnboolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addcolumn", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Modifies a table column based on a definition
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Column $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, modifyColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "modifycolumn", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops a column from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $columnName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropcolumn", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds an index to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramDbIndex $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addindex", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drop an index from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $indexName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropindex", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a primary key to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Index $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addprimarykey", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops primary key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropprimarykey", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a foreign key to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Reference $reference
 * @returnboolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addforeignkey", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops a foreign key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $referenceName
 * @returnboolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropforeignkey", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Returns the SQL column definition from a column
 *
 * @paramPhalcon_Db_Column $column
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getColumnDefinition){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "getcolumndefinition", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Generates SQL describing a table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describetable", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * List all tables on a database
 *
 * 
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, listTables){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "listtables", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v1);
	p1[0] = v1;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_0;
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r2);
		PHALCON_SEPARATE_ARRAY(v4);
		phalcon_array_append(v4, r2 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_0;
		fee_321f_0:
		if(0){ };
	}
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), v2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Returns a database date formatted
 *
 * 
 *
 * @param string $date
 * @param string $format
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getDateUsingFormat){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "YYYY-MM-DD", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "'", v0, "'");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Lists table indexes
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnarray
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeIndexes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describeindexes", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_1;
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, v5, "Key_name", strlen("Key_name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r2);
		eval_int = phalcon_array_isset(v4, v6);
		PHALCON_INIT_VAR(r3);
		ZVAL_BOOL(r3, eval_int);
		if (!zend_is_true(r3)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			Z_ADDREF_P(a1);
			if (Z_REFCOUNT_P(v4) > 1) {
				zval *new_zv;
				Z_DELREF_P(v4);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v4);
				v4 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update(v4, v6, a1 TSRMLS_CC);
		}
		PHALCON_INIT_VAR(r4);
		phalcon_array_fetch_string(&r4, v5, "Column_name", strlen("Column_name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(v4) == IS_ARRAY) {
			PHALCON_INIT_VAR(t1);
			phalcon_array_fetch(&t1, v4, v6, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t1) > 1) {
			zval *new_zv;
			Z_DELREF_P(t1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t1);
			t1 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(v4, v6, t1 TSRMLS_CC);
		}
		Z_ADDREF_P(t1);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
			phalcon_array_update(v4, v6, t1 TSRMLS_CC);
		}
		Z_ADDREF_P(r4);
		phalcon_array_append(t1, r4 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_1;
		fee_321f_1:
		if(0){ };
	}
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(v7, a2);
	if (Z_TYPE_P(v4) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(v4);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_321f_2:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_2;
		} else {
			PHALCON_INIT_VAR(v9);
			htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v9, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v9, num);
				}
			}
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_ZVAL(v8, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_index_class_entry);
		Z_ADDREF_P(v9);
		p2[0] = v9;
		Z_ADDREF_P(v8);
		p2[1] = v8;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_ADDREF_P(i0);
		if (Z_REFCOUNT_P(v7) > 1) {
			zval *new_zv;
			Z_DELREF_P(v7);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v7);
			v7 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v7, v9, i0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_321f_2;
		fee_321f_2:
		if(0){ };
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v7);
}

/**
 * Lists table references
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnarray
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeReferences){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describereferences", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v3, a0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v4, r1);
	if (Z_TYPE_P(v4) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v4);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_3;
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, v5, "CONSTRAINT_NAME", strlen("CONSTRAINT_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r2);
		eval_int = phalcon_array_isset(v3, v6);
		PHALCON_INIT_VAR(r3);
		ZVAL_BOOL(r3, eval_int);
		if (!zend_is_true(r3)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, v5, "REFERENCED_TABLE_SCHEMA", strlen("REFERENCED_TABLE_SCHEMA"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r4);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "referencedSchema", r4);
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_string(&r5, v5, "REFERENCED_TABLE_NAME", strlen("REFERENCED_TABLE_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r5);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "referencedTable", r5);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			Z_ADDREF_P(a2);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "columns", a2);
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			Z_ADDREF_P(a3);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "referencedColumns", a3);
			Z_ADDREF_P(a1);
			if (Z_REFCOUNT_P(v3) > 1) {
				zval *new_zv;
				Z_DELREF_P(v3);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v3);
				v3 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update(v3, v6, a1 TSRMLS_CC);
		}
		PHALCON_INIT_VAR(r6);
		phalcon_array_fetch_string(&r6, v5, "COLUMN_NAME", strlen("COLUMN_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(v3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t1);
			phalcon_array_fetch(&t1, v3, v6, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t1) > 1) {
			zval *new_zv;
			Z_DELREF_P(t1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t1);
			t1 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(v3, v6, t1 TSRMLS_CC);
		}
		Z_ADDREF_P(t1);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
			phalcon_array_update(v3, v6, t1 TSRMLS_CC);
		}
		if (Z_TYPE_P(t1) == IS_ARRAY) {
			PHALCON_INIT_VAR(t2);
			phalcon_array_fetch_string(&t2, t1, "columns", strlen("columns"), PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t2) > 1) {
			zval *new_zv;
			Z_DELREF_P(t2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t2);
			t2 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update_string(t1, "columns", strlen("columns"), t2 TSRMLS_CC);
		}
		Z_ADDREF_P(t2);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
			phalcon_array_update_string(t1, "columns", strlen("columns"), t2 TSRMLS_CC);
		}
		Z_ADDREF_P(r6);
		phalcon_array_append(t2, r6 TSRMLS_CC);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch_string(&r7, v5, "REFERENCED_COLUMN_NAME", strlen("REFERENCED_COLUMN_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(v3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t3);
			phalcon_array_fetch(&t3, v3, v6, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t3) > 1) {
			zval *new_zv;
			Z_DELREF_P(t3);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t3);
			t3 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(v3, v6, t3 TSRMLS_CC);
		}
		Z_ADDREF_P(t3);
		if (Z_TYPE_P(t3) != IS_ARRAY) {
			convert_to_array(t3);
			phalcon_array_update(v3, v6, t3 TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t4);
			phalcon_array_fetch_string(&t4, t3, "referencedColumns", strlen("referencedColumns"), PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			zval *new_zv;
			Z_DELREF_P(t4);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t4);
			t4 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update_string(t3, "referencedColumns", strlen("referencedColumns"), t4 TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update_string(t3, "referencedColumns", strlen("referencedColumns"), t4 TSRMLS_CC);
		}
		Z_ADDREF_P(r7);
		phalcon_array_append(t4, r7 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_3;
		fee_321f_3:
		if(0){ };
	}
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	PHALCON_CPY_WRT(v7, a4);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_321f_4:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_4;
		} else {
			PHALCON_INIT_VAR(v9);
			htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v9, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v9, num);
				}
			}
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_ZVAL(v8, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_reference_class_entry);
		Z_ADDREF_P(v9);
		p2[0] = v9;
		PHALCON_INIT_VAR(a5);
		array_init(a5);
		PHALCON_INIT_VAR(r8);
		phalcon_array_fetch_string(&r8, v8, "referencedSchema", strlen("referencedSchema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r8);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "referencedSchema", r8);
		PHALCON_INIT_VAR(r9);
		phalcon_array_fetch_string(&r9, v8, "referencedTable", strlen("referencedTable"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r9);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "referencedTable", r9);
		PHALCON_INIT_VAR(r10);
		phalcon_array_fetch_string(&r10, v8, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r10);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "columns", r10);
		PHALCON_INIT_VAR(r11);
		phalcon_array_fetch_string(&r11, v8, "referencedColumns", strlen("referencedColumns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r11);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "referencedColumns", r11);
		Z_ADDREF_P(a5);
		p2[1] = a5;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_ADDREF_P(i0);
		if (Z_REFCOUNT_P(v7) > 1) {
			zval *new_zv;
			Z_DELREF_P(v7);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v7);
			v7 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v7, v9, i0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_321f_4;
		fee_321f_4:
		if(0){ };
	}
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t5 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v7);
}

/**
 * Get creation options from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @returnarray
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, tableOptions){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "tableoptions", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v3, a0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v4, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r2);
}

/**
 * Phalcon_Db_Profiler_Item
 *
 * This class identifies each profile in a Phalcon_Db_Profiler
 *
 */

/**
 * Sets the SQL statement related to the profile
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLStatement){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_sqlStatement", strlen("_sqlStatement"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the SQL statement related to the profile
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLStatement){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_sqlStatement", sizeof("_sqlStatement")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the timestamp on when the profile started
 *
 * @param int $initialTime
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_initialTime", strlen("_initialTime"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets the timestamp on when the profile ended
 *
 * @param int $finalTime
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_finalTime", strlen("_finalTime"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the initial time in milseconds on when the profile started
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_initialTime", sizeof("_initialTime")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns the initial time in milseconds on when the profile ended
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_finalTime", sizeof("_finalTime")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns the total time in seconds spent by the profile
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_finalTime", sizeof("_finalTime")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_initialTime", sizeof("_initialTime")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Phalcon_Db_RawValue
 *
 * This class lets to insert/update raw data without quoting or formating.
 *
 *
 */

/**
 * Phalcon_Db_RawValue constructor
 *
 * @param string $value
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_value", strlen("_value"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns internal raw value without quoting or formating
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Magic method __toString returns raw value without quoting or formating
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Db_Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *
 *
 */

/**
 * Phalcon_Db_Column constructor
 *
 * @param string $columnName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Column, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_columnName", strlen("_columnName"), v0 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v1, "type", strlen("type")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "type", strlen("type"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column type is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "notNull", strlen("notNull")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v1, "notNull", strlen("notNull"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_notNull", strlen("_notNull"), r1 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "size", strlen("size")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v1, "size", strlen("size"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_size", strlen("_size"), r2 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "scale", strlen("scale")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 3);
		PHALCON_ALLOC_ZVAL_MM(r3);
		is_equal_function(r3, t0, t1 TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_string(&r4, v1, "scale", strlen("scale"), PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_scale", strlen("_scale"), r4 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_db_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "Column type does not support scale parameter", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i1 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v1, "unsigned", strlen("unsigned")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v1, "unsigned", strlen("unsigned"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_unsigned", strlen("_unsigned"), r5 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "autoIncrement", strlen("autoIncrement")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 0);
		PHALCON_ALLOC_ZVAL_MM(r6);
		is_equal_function(r6, t2, t3 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			phalcon_array_fetch_string(&r7, v1, "autoIncrement", strlen("autoIncrement"), PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_autoIncrement", strlen("_autoIncrement"), r7 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_db_exception_class_entry);
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "Column type cannot be auto-increment", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i2 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v1, "first", strlen("first")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, v1, "first", strlen("first"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_first", strlen("_first"), r8 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "after", strlen("after")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		phalcon_array_fetch_string(&r9, v1, "after", strlen("after"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_after", strlen("_after"), r9 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns schema's table related to column
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schemaName", sizeof("_schemaName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columnName", sizeof("_columnName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column type
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getType){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column size
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getSize){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_size", sizeof("_size")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column scale
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getScale){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_scale", sizeof("_scale")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_unsigned", sizeof("_unsigned")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Not null
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_notNull", sizeof("_notNull")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_autoIncrement", sizeof("_autoIncrement")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isFirst){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_first", sizeof("_first")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_after", sizeof("_after")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Db_Index
 *
 * Allows to define indexes to be used on tables
 *
 */

/**
 * Phalcon_Db_Index constructor
 *
 * @param string $indexName
 * @param array $columns
 */
PHP_METHOD(Phalcon_Db_Index, __construct){

	zval *v0 = NULL, *v1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_indexName", strlen("_indexName"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets the index name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Index, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_indexName", sizeof("_indexName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the columns that comprends the index
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Index, getColumns){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Restore a Phalcon_Db_Index object from export
 *
 * @param array $data
 * @return Phalcon_Db_Index
 */
PHP_METHOD(Phalcon_Db_Index, __set_state){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	eval_int = phalcon_array_isset_string(v0, "_indexName", strlen("_indexName")+1);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "_indexName parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "_columns", strlen("_columns")+1);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "_columns parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init_ex(i2, phalcon_db_index_class_entry);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, v0, "_indexName", strlen("_indexName"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p2[0] = r2;
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, v0, "_columns", strlen("_columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r3);
	p2[1] = r3;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	PHALCON_RETURN_CTOR(i2);
}

/**
 * Phalcon_Db_Dialect_Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */

/**
 * Generates the SQL for a MySQL LIMIT clause
 *
 * @param string $errorString
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, limit){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", v1, 0x00B);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "intval", v1, 0x01E);
		PHALCON_CPY_WRT(v2, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, v0, " LIMIT ", v2);
		PHALCON_RETURN_CTOR(r2);
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets a list of columns
 *
 * @paramarray $columnList
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnList){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_52be_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_0;
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CONCAT_BOTH(r0,  "`", v2, "`");
		Z_ADDREF_P(r0);
		PHALCON_SEPARATE_ARRAY(v1);
		phalcon_array_append(v1, r0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_0;
		fee_52be_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "join", c0, v1, 0x00D);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Gets the column name in MySQL
 *
 * @param Phalcon_Db_Column $column
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *p0[] = { NULL }, *p6[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column definition must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsize", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "gettype", PHALCON_CALL_DEFAULT);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, r1, t0 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "INT(", v1, ")");
		PHALCON_CPY_WRT(v2, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, v0, "isunsigned", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " UNSIGNED", 1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			concat_function(r5, v2, t1 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r5);
		}
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, r1, t2 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "DATE", 1);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 2);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, r1, t3 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "VARCHAR(", v1, ")");
		PHALCON_CPY_WRT(v2, r8);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, r1, t4 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_LEFT(r11, "DECIMAL(", v1);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, v0, "getscale", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_VBOTH(r10, r11, ",", r12);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CONCAT_RIGHT(r13, r10, ")");
		PHALCON_CPY_WRT(v2, r13);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_METHOD(r14, v0, "isunsigned", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r14)) {
			PHALCON_INIT_VAR(t5);
			ZVAL_STRING(t5, " UNSIGNED", 1);
			PHALCON_ALLOC_ZVAL_MM(r15);
			concat_function(r15, v2, t5 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r15);
		}
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 4);
	PHALCON_ALLOC_ZVAL_MM(r16);
	is_equal_function(r16, r1, t6 TSRMLS_CC);
	if (zend_is_true(r16)) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "DATETIME", 1);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t7);
	ZVAL_LONG(t7, 5);
	PHALCON_ALLOC_ZVAL_MM(r17);
	is_equal_function(r17, r1, t7 TSRMLS_CC);
	if (zend_is_true(r17)) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_BOTH(r18,  "CHAR(", v1, ")");
		PHALCON_CPY_WRT(v2, r18);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 6);
	PHALCON_ALLOC_ZVAL_MM(r19);
	is_equal_function(r19, r1, t8 TSRMLS_CC);
	if (zend_is_true(r19)) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "TEXT", 1);
		goto se_52be_1;
	}
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_exception_class_entry);
	PHALCON_INIT_VAR(p6[0]);
	ZVAL_STRING(p6[0], "Unrecognized MySQL data type", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p6, PHALCON_CALL_CHECK);
	return phalcon_throw_exception(i1 TSRMLS_CC);
	se_52be_1:
	if(0) { };
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates SQL to add a column to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Column $column
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column parameter must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumndefinition", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` ", r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	concat_function(r8, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r8);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, v2, "isnotnull", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v3, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r10);
	}
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, v2, "isfirst", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r11)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, " FIRST", 1);
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, v3, t1 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r12);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CALL_METHOD(r13, v2, "getafterposition", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r13);
		if (zend_is_true(v4)) {
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_LEFT(r14, " AFTER ", v4);
			PHALCON_ALLOC_ZVAL_MM(r15);
			concat_function(r15, v3, r14 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r15);
		}
	}
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to modify a column in a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Column $column
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column parameter must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` MODIFY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` MODIFY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumndefinition", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` ", r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	concat_function(r8, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r8);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, v2, "isnotnull", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v3, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r10);
	}
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to delete a column from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP COLUMN ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP COLUMN ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", v2, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to add an index to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Index $index
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Index parameter must be an instance of Phalcon_Db_Index", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD INDEX ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD INDEX ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, v2, "getcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r8);
	p2[0] = r8;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumnlist", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` (", r7);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_RIGHT(r9, r4, ")");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, v3, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r10);
	PHALCON_RETURN_CTOR(v3);
}

/**
  * Generates SQL to delete an index from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $indexName
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP INDEX ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP INDEX ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", v2, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to add the primary key to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Index $index
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Index parameter must be an instance of Phalcon_Db_Index", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r5);
	p1[0] = r5;
	PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "getcolumnlist", 1, p1);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_BOTH(r6,  "(", r4, ")");
	PHALCON_ALLOC_ZVAL_MM(r7);
	concat_function(r7, v3, r6 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r7);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates SQL to add an index to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Reference $reference
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Reference parameter must be an instance of Phalcon_Db_Reference", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, v2, "getcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r8);
	p2[0] = r8;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumnlist", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "`(", r7);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_RIGHT(r9, r4, ") REFERENCES ");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, v3, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r10);
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, v2, "getreferencedschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r11);
	if (zend_is_true(v4)) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_BOTH(r12,  "`", v4, "`.");
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, v3, r12 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r13);
	}
	PHALCON_ALLOC_ZVAL_MM(r15);
	PHALCON_CALL_METHOD(r15, v2, "getreferencedtable", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_CONCAT_LEFT(r16, "`", r15);
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_CALL_METHOD(r18, v2, "getreferencedcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r18);
	p6[0] = r18;
	PHALCON_CALL_SELF_PARAMS(r17, this_ptr, "getcolumnlist", 1, p6);
	Z_DELREF_P(p6[0]);
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_VBOTH(r14, r16, "`(", r17);
	PHALCON_ALLOC_ZVAL_MM(r19);
	PHALCON_CONCAT_RIGHT(r19, r14, ")");
	PHALCON_ALLOC_ZVAL_MM(r20);
	concat_function(r20, v3, r19 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r20);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $referenceName
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", v2, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CTOR(v3);
}

PHP_METHOD(Phalcon_Db_Dialect_Mysql, _getTableOptions){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r0, "ENGINE", strlen("ENGINE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, r1, "ENGINE", strlen("ENGINE"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, r3, "ENGINE", strlen("ENGINE"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_LEFT(r5, "ENGINE=", v2);
			Z_ADDREF_P(r5);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r5 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_string(&r6, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r6, "AUTO_INCREMENT", strlen("AUTO_INCREMENT")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, r7, "AUTO_INCREMENT", strlen("AUTO_INCREMENT"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r8);
		if (zend_is_true(v3)) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_LEFT(r9, "AUTO_INCREMENT=", v3);
			Z_ADDREF_P(r9);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r9 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r10);
	phalcon_array_fetch_string(&r10, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r10, "TABLE_COLLATION", strlen("TABLE_COLLATION")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, r11, "TABLE_COLLATION", strlen("TABLE_COLLATION"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r12);
		if (zend_is_true(v4)) {
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "_", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r13, "explode", c0, v4, 0x005);
			PHALCON_CPY_WRT(v5, r13);
			PHALCON_ALLOC_ZVAL_MM(r14);
			phalcon_array_fetch_long(&r14, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "DEFAULT CHARSET=", r14);
			Z_ADDREF_P(r15);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r15 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_LEFT(r16, "COLLATE=", v4);
			Z_ADDREF_P(r16);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r16 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_CALL_FUNC_PARAMS_1(r17, "count", v1, 0x007);
	if (zend_is_true(r17)) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, " ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c1, v1, 0x00D);
		PHALCON_RETURN_DZVAL(r18);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL to create a table in MySQL
 *
 * @param string $tableName
 * @paramstring $schemaName
 * @paramarray $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p5[] = { NULL }, *p8[] = { NULL }, *p11[] = { NULL }, *p14[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "`", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "`", v0, "`");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_INIT_VAR(v4);
	ZVAL_BOOL(v4, 0);
	eval_int = phalcon_array_isset_string(v2, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v2, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r4, "temporary", strlen("temporary")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_array_fetch_string(&r5, v2, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_array_fetch_string(&r6, r5, "temporary", strlen("temporary"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_INIT_VAR(v4);
				ZVAL_BOOL(v4, 1);
			}
		}
	}
	if (zend_is_true(v4)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_BOTH(r7,  "CREATE TEMPORARY TABLE ", v3, " (\n\t");
		PHALCON_CPY_WRT(v5, r7);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "CREATE TABLE ", v3, " (\n\t");
		PHALCON_CPY_WRT(v5, r8);
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v6, a0);
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_array_fetch_string(&r9, v2, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(r9) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(r9);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_52be_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_2;
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_ZVAL(v7, *hd, 1, 0);
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, v7, "getname", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(r12);
		PHALCON_CONCAT_LEFT(r12, "`", r11);
		PHALCON_INIT_VAR(r13);
		Z_ADDREF_P(v7);
		p1[0] = v7;
		PHALCON_CALL_SELF_PARAMS(r13, this_ptr, "getcolumndefinition", 1, p1);
		Z_DELREF_P(p1[0]);
		PHALCON_INIT_VAR(r10);
		PHALCON_CONCAT_VBOTH(r10, r12, "` ", r13);
		PHALCON_CPY_WRT(v8, r10);
		PHALCON_INIT_VAR(r14);
		PHALCON_CALL_METHOD(r14, v7, "isnotnull", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r14)) {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " NOT NULL", 1);
			PHALCON_INIT_VAR(r15);
			concat_function(r15, v8, t0 TSRMLS_CC);
			PHALCON_CPY_WRT(v8, r15);
		}
		PHALCON_INIT_VAR(r16);
		PHALCON_CALL_METHOD(r16, v7, "isautoincrement", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r16)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " AUTO_INCREMENT", 1);
			PHALCON_INIT_VAR(r17);
			concat_function(r17, v8, t1 TSRMLS_CC);
			PHALCON_CPY_WRT(v8, r17);
		}
		Z_ADDREF_P(v8);
		PHALCON_SEPARATE_ARRAY(v6);
		phalcon_array_append(v6, v8 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_2;
		fee_52be_2:
		if(0){ };
	}
	eval_int = phalcon_array_isset_string(v2, "indexes", strlen("indexes")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_array_fetch_string(&r18, v2, "indexes", strlen("indexes"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r18) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(r18);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_52be_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_52be_3;
			}
			PHALCON_INIT_VAR(v9);
			ZVAL_ZVAL(v9, *hd, 1, 0);
			PHALCON_INIT_VAR(r19);
			PHALCON_CALL_METHOD(r19, v9, "getname", PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v10, r19);
			PHALCON_INIT_VAR(r20);
			PHALCON_INIT_VAR(r21);
			PHALCON_CALL_METHOD(r21, v9, "getcolumns", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r21);
			p5[0] = r21;
			PHALCON_CALL_SELF_PARAMS(r20, this_ptr, "getcolumnlist", 1, p5);
			Z_DELREF_P(p5[0]);
			PHALCON_CPY_WRT(v11, r20);
			if (PHALCON_COMPARE_STRING(v10, "PRIMARY")) {
				PHALCON_INIT_VAR(r22);
				PHALCON_CONCAT_BOTH(r22,  "PRIMARY KEY (", v11, ")");
				Z_ADDREF_P(r22);
				PHALCON_SEPARATE_ARRAY(v6);
				phalcon_array_append(v6, r22 TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r24);
				PHALCON_CONCAT_LEFT(r24, "KEY `", v10);
				PHALCON_INIT_VAR(r23);
				PHALCON_CONCAT_VBOTH(r23, r24, "` (", v11);
				PHALCON_INIT_VAR(r25);
				PHALCON_CONCAT_RIGHT(r25, r23, ")");
				Z_ADDREF_P(r25);
				PHALCON_SEPARATE_ARRAY(v6);
				phalcon_array_append(v6, r25 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_52be_3;
			fee_52be_3:
			if(0){ };
		}
	}
	eval_int = phalcon_array_isset_string(v2, "references", strlen("references")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r26);
		phalcon_array_fetch_string(&r26, v2, "references", strlen("references"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r26) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah2 = Z_ARRVAL_P(r26);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_52be_4:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_52be_4;
			}
			PHALCON_INIT_VAR(v12);
			ZVAL_ZVAL(v12, *hd, 1, 0);
			PHALCON_INIT_VAR(r30);
			PHALCON_CALL_METHOD(r30, v12, "getname", PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(r31);
			PHALCON_CONCAT_LEFT(r31, "CONSTRAINT `", r30);
			PHALCON_INIT_VAR(r32);
			PHALCON_INIT_VAR(r33);
			PHALCON_CALL_METHOD(r33, v12, "getcolumns", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r33);
			p8[0] = r33;
			PHALCON_CALL_SELF_PARAMS(r32, this_ptr, "getcolumnlist", 1, p8);
			Z_DELREF_P(p8[0]);
			PHALCON_INIT_VAR(r29);
			PHALCON_CONCAT_VBOTH(r29, r31, "` FOREIGN KEY (", r32);
			PHALCON_INIT_VAR(r34);
			PHALCON_CALL_METHOD(r34, v12, "getreferencedtable", PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(r28);
			PHALCON_CONCAT_VBOTH(r28, r29, ") REFERENCES `", r34);
			PHALCON_INIT_VAR(r35);
			PHALCON_INIT_VAR(r36);
			PHALCON_CALL_METHOD(r36, v12, "getreferencedcolumns", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r36);
			p11[0] = r36;
			PHALCON_CALL_SELF_PARAMS(r35, this_ptr, "getcolumnlist", 1, p11);
			Z_DELREF_P(p11[0]);
			PHALCON_INIT_VAR(r27);
			PHALCON_CONCAT_VBOTH(r27, r28, "`(", r35);
			PHALCON_INIT_VAR(r37);
			PHALCON_CONCAT_RIGHT(r37, r27, ")");
			Z_ADDREF_P(r37);
			PHALCON_SEPARATE_ARRAY(v6);
			phalcon_array_append(v6, r37 TSRMLS_CC);
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_52be_4;
			fee_52be_4:
			if(0){ };
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r38);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ",\n\t", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r38, "join", c0, v6, 0x00D);
	PHALCON_ALLOC_ZVAL_MM(r39);
	PHALCON_CONCAT_RIGHT(r39, r38, "\n)");
	PHALCON_ALLOC_ZVAL_MM(r40);
	concat_function(r40, v5, r39 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r40);
	eval_int = phalcon_array_isset_string(v2, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r41);
		Z_ADDREF_P(v2);
		p14[0] = v2;
		PHALCON_CALL_SELF_PARAMS(r41, this_ptr, "_gettableoptions", 1, p14);
		Z_DELREF_P(p14[0]);
		PHALCON_ALLOC_ZVAL_MM(r42);
		PHALCON_CONCAT_LEFT(r42, " ", r41);
		PHALCON_ALLOC_ZVAL_MM(r43);
		concat_function(r43, v5, r42 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r43);
	}
	PHALCON_RETURN_CTOR(v5);
}

/**
 * Generates SQL to drop a table
 *
 * @param  string $tableName
 * @param  string $schemaName
 * @param  boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "`", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "`", v0, "`");
		PHALCON_CPY_WRT(v3, r3);
	}
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_LEFT(r4, "DROP TABLE IF EXISTS ", v3);
		PHALCON_RETURN_CTOR(r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_LEFT(r5, "DROP TABLE ", v3);
		PHALCON_RETURN_CTOR(r5);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * 
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", v0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "' AND `TABLE_SCHEMA`='", v1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "'");
		PHALCON_RETURN_CTOR(r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", v0, "'");
		PHALCON_RETURN_CTOR(r3);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL describing a table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "DESCRIBE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "DESCRIBE `", v0, "`");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * List all tables on database
 *
 * 
 *
 * @param       string $schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "SHOW TABLES FROM `", v0, "`");
		PHALCON_CPY_WRT(v1, r0);
	} else {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "SHOW TABLES", 1);
	}
	PHALCON_RETURN_CTOR(v1);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "SHOW INDEXES FROM `", v0, "`");
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_LEFT(r2, "SHOW INDEXES FROM `", v1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VBOTH(r1, r2, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_RIGHT(r3, r1, "`");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME\n\t\t\tFROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "CONSTRAINT_SCHEMA = \"", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "\" AND TABLE_NAME = \"", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r3);
		concat_function(r3, v2, r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "TABLE_NAME = \"", v0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r5);
		concat_function(r5, v2, r4 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r5);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates the SQL to describe the table creation options
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "SELECT TABLES.TABLE_TYPE,TABLES.AUTO_INCREMENT,TABLES.ENGINE,TABLES.TABLE_COLLATION FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "TABLES.TABLE_SCHEMA = \"", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "\" AND TABLES.TABLE_NAME = \"", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r3);
		concat_function(r3, v2, r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "TABLES.TABLE_NAME = \"", v0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r5);
		concat_function(r5, v2, r4 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r5);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Phalcon_Model_Validator_Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *
 *
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Uniqueness, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *p4[] = { NULL }, *p9[] = { NULL }, *p11[] = { NULL }, *p13[] = { NULL }, *p15[] = { NULL, NULL, NULL }, *p16[] = { NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getrecord", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(i0);
		phalcon_clone(i0, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(v0, i0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r2);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_d73d_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_d73d_0;
				}
				PHALCON_INIT_VAR(v3);
				ZVAL_ZVAL(v3, *hd, 1, 0);
				PHALCON_INIT_VAR(r3);
				PHALCON_INIT_VAR(r4);
				Z_ADDREF_P(v3);
				p4[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r4, v0, "readattribute", 1, p4, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p4[0]);
				Z_ADDREF_P(r4);
				PHALCON_CALL_FUNC_PARAMS_1(r3, "addslashes", r4, 0x00C);
				Z_DELREF_P(r4);
				PHALCON_CPY_WRT(v4, r3);
				PHALCON_INIT_VAR(r5);
				PHALCON_CONCAT_VBOTH(r5, v3, "='", v4);
				PHALCON_INIT_VAR(r6);
				PHALCON_CONCAT_RIGHT(r6, r5, "'");
				Z_ADDREF_P(r6);
				PHALCON_SEPARATE_ARRAY(v2);
				phalcon_array_append(v2, r6 TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_d73d_0;
				fee_d73d_0:
				if(0){ };
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD(r8, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r8);
			PHALCON_CALL_FUNC_PARAMS_1(r7, "addslashes", r8, 0x00C);
			Z_DELREF_P(r8);
			PHALCON_CPY_WRT(v4, r7);
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_VBOTH(r9, v1, "='", v4);
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_RIGHT(r10, r9, "'");
			Z_ADDREF_P(r10);
			PHALCON_SEPARATE_ARRAY(v2);
			phalcon_array_append(v2, r10 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, v0, "getmanager", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r11);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, v5, "getmetadata", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v6, r12);
		PHALCON_ALLOC_ZVAL_MM(r13);
		Z_ADDREF_P(v0);
		p9[0] = v0;
		PHALCON_CALL_METHOD_PARAMS(r13, v6, "getprimarykeyattributes", 1, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		PHALCON_CPY_WRT(v7, r13);
		if (Z_TYPE_P(v7) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v7);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_d73d_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_d73d_1;
			}
			PHALCON_INIT_VAR(v8);
			ZVAL_ZVAL(v8, *hd, 1, 0);
			PHALCON_INIT_VAR(r15);
			PHALCON_INIT_VAR(r16);
			Z_ADDREF_P(v8);
			p11[0] = v8;
			PHALCON_CALL_METHOD_PARAMS(r16, v0, "readattribute", 1, p11, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p11[0]);
			Z_ADDREF_P(r16);
			PHALCON_CALL_FUNC_PARAMS_1(r15, "addslashes", r16, 0x00C);
			Z_DELREF_P(r16);
			PHALCON_INIT_VAR(r14);
			PHALCON_CONCAT_VBOTH(r14, v8, "<>'", r15);
			PHALCON_INIT_VAR(r17);
			PHALCON_CONCAT_RIGHT(r17, r14, "'");
			Z_ADDREF_P(r17);
			PHALCON_SEPARATE_ARRAY(v2);
			phalcon_array_append(v2, r17 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_d73d_1;
			fee_d73d_1:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c0, v2, 0x00D);
		PHALCON_CPY_WRT(v2, r18);
		PHALCON_ALLOC_ZVAL_MM(r19);
		Z_ADDREF_P(v2);
		p13[0] = v2;
		PHALCON_CALL_STATIC_ZVAL_PARAMS(r19, v0, "count", 1, p13);
		Z_DELREF_P(p13[0]);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r20);
		is_smaller_function(r20, t0, r19 TSRMLS_CC);
		if (zend_is_true(r20)) {
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_CALL_METHOD(r21, this_ptr, "getoptions", PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v9, r21);
			eval_int = phalcon_array_isset_string(v9, "message", strlen("message")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r22);
				phalcon_array_fetch_string(&r22, v9, "message", strlen("message"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r22);
				p15[0] = r22;
				Z_ADDREF_P(v1);
				p15[1] = v1;
				PHALCON_INIT_VAR(p15[2]);
				ZVAL_STRING(p15[2], "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p15, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p15[0]);
				Z_DELREF_P(p15[1]);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r23);
				PHALCON_CONCAT_BOTH(r23,  "Value of field '", v1, "' is already present in another record");
				Z_ADDREF_P(r23);
				p16[0] = r23;
				Z_ADDREF_P(v1);
				p16[1] = v1;
				PHALCON_INIT_VAR(p16[2]);
				ZVAL_STRING(p16[2], "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p16, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p16[0]);
				Z_DELREF_P(p16[1]);
			}
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * ExclusionInValidator
 *
 * Check if a value is not included into a list of values
 *
 *
 */

/**
     * Check that the options are valid
 *
 */
PHP_METHOD(Phalcon_Model_Validator_Exclusionin, checkOptions){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "domain", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "issetoption", 1, p0, PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "The option 'domain' is required for this validator", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "domain", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getoption", 1, p3, PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "is_array", r2, 0x031);
	Z_DELREF_P(r2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "Option 'domain' must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Exclusionin, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "domain", 1);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "issetoption", 1, p1, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "domain", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getoption", 1, p2, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v0, r2);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r4);
			Z_ADDREF_P(v0);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "in_array", r4, v0, 0x019);
			Z_DELREF_P(r4);
			Z_DELREF_P(v0);
			if (zend_is_true(r3)) {
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_METHOD(r5, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v1, r5);
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_LEFT(r7, "Value of field '", v1);
				PHALCON_ALLOC_ZVAL_MM(r8);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, ", ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r8, "join", c0, v0, 0x00D);
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CONCAT_VBOTH(r6, r7, "' must not be part of list: ", r8);
				Z_ADDREF_P(r6);
				p6[0] = r6;
				Z_ADDREF_P(v1);
				p6[1] = v1;
				PHALCON_INIT_VAR(p6[2]);
				ZVAL_STRING(p6[2], "exclusion", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				Z_DELREF_P(p6[1]);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Phalcon_Model_Validator_Regex
 *
 * Validate that the value of a field matches a regular expression
 *
 *
 *
 */

/**
 * Check that the options are correct
 *
 */
PHP_METHOD(Phalcon_Model_Validator_Regex, checkOptions){

	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "pattern", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "issetoption", 1, p0, PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Validator requires a perl-compatible regex pattern", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Regex, validate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *p3[] = { NULL }, *p2[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_NULL(v0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_INIT_VAR(v3);
	ZVAL_BOOL(v3, 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "pattern", 1);
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "getoption", 1, p3, PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r3);
	p2[0] = r3;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_SET_ISREF_P(v0);
	p2[2] = v0;
	PHALCON_CALL_FUNC_PARAMS(r2, "preg_match", 3, p2, 0x022);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_UNSET_ISREF_P(p2[2]);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_long(&r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r5);
		is_not_equal_function(r5, r4, v1 TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_INIT_VAR(v3);
			ZVAL_BOOL(v3, 0);
		}
	} else {
		PHALCON_INIT_VAR(v3);
		ZVAL_BOOL(v3, 0);
	}
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_BOTH(r6,  "Value of field '", v2, "' doesn't match regular expression");
		Z_ADDREF_P(r6);
		p4[0] = r6;
		Z_ADDREF_P(v2);
		p4[1] = v2;
		PHALCON_INIT_VAR(p4[2]);
		ZVAL_STRING(p4[2], "regex", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		Z_DELREF_P(p4[1]);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Model_Validator_Inclusionin
 *
 * Check if a value is included into a list of values
 *
 *
 *
 */

/**
     * Check that the options are valid
 *
 */
PHP_METHOD(Phalcon_Model_Validator_Inclusionin, checkOptions){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "domain", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "issetoption", 1, p0, PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "The option 'domain' is required for this validator", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "domain", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getoption", 1, p3, PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "is_array", r2, 0x031);
	Z_DELREF_P(r2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "Option 'domain' must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Inclusionin, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "domain", 1);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "issetoption", 1, p1, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "domain", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getoption", 1, p2, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v0, r2);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r4);
			Z_ADDREF_P(v0);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "in_array", r4, v0, 0x019);
			Z_DELREF_P(r4);
			Z_DELREF_P(v0);
			if (!zend_is_true(r3)) {
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_METHOD(r5, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v1, r5);
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_LEFT(r7, "Value of field '", v1);
				PHALCON_ALLOC_ZVAL_MM(r8);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, ", ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r8, "join", c0, v0, 0x00D);
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CONCAT_VBOTH(r6, r7, "' must be part of list: ", r8);
				Z_ADDREF_P(r6);
				p6[0] = r6;
				Z_ADDREF_P(v1);
				p6[1] = v1;
				PHALCON_INIT_VAR(p6[2]);
				ZVAL_STRING(p6[2], "inclusion", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				Z_DELREF_P(p6[1]);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Phalcon_Model_Validator_Numericality
 *
 *
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Numericality, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p3[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "is_numeric", r2, 0x00B);
		if (!zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_BOTH(r4,  "Value of field '", r3, "' must be numeric");
			Z_ADDREF_P(r4);
			p3[0] = r4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 1, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Phalcon_Model_Validator_Email
 *
 * Let to validate that email fields has correct values
 *
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Email, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *p2[] = { NULL, NULL, NULL }, *p5[] = { NULL, NULL, NULL }, *p6[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "/^[a-zA-Z0-9_\\.\\+]+@[a-zA-Z0-9_]+(\\.[a-zA-Z0-9_]+)*$/", 1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r3);
		p2[1] = r3;
		Z_SET_ISREF_P(v0);
		p2[2] = v0;
		PHALCON_CALL_FUNC_PARAMS(r2, "preg_match", 3, p2, 0x022);
		Z_DELREF_P(p2[1]);
		Z_UNSET_ISREF_P(p2[2]);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_long(&r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(r6);
			is_not_equal_function(r6, r4, r5 TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_BOTH(r7,  "Value of field '", v1, "' should be a valid e-mail");
				Z_ADDREF_P(r7);
				p5[0] = r7;
				Z_ADDREF_P(v1);
				p5[1] = v1;
				PHALCON_INIT_VAR(p5[2]);
				ZVAL_STRING(p5[2], "email", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p5, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p5[0]);
				Z_DELREF_P(p5[1]);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_BOTH(r8,  "Value of field '", v1, "' should be a valid e-mail");
			Z_ADDREF_P(r8);
			p6[0] = r8;
			Z_ADDREF_P(v1);
			p6[1] = v1;
			PHALCON_INIT_VAR(p6[2]);
			ZVAL_STRING(p6[2], "email", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p6, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p6[0]);
			Z_DELREF_P(p6[1]);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Phalcon_Model_Query
 *
 * Phalcon_Model_Query is designed to simplify building of search on models.
 * It provides a set of helpers to generate searchs in a dynamic way to support differents databases.
 *
 * 
 *
 */

/**
 * Phalcon_Model_Criteria constructor
 */
PHP_METHOD(Phalcon_Model_Query, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_query_class_entry, this_ptr, "_models", strlen("_models"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_query_class_entry, this_ptr, "_parameters", strlen("_parameters"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_model_query_class_entry, this_ptr, "_conditions", strlen("_conditions"), a2 TSRMLS_CC);
	
}

/**
 * Set the data to use to make the conditions in query
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Model_Query, setInputData){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_data", strlen("_data"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the Phalcon_Model_Manager instance to use in a query
 *
 * 
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Query, setManager){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Add models to use in query
 *
 * @param string $model
 */
PHP_METHOD(Phalcon_Model_Query, from){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Add conditions to use in query
 *
 * @param string $condition
 */
PHP_METHOD(Phalcon_Model_Query, where){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_conditions", sizeof("_conditions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_conditions", strlen("_conditions"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set parameter in query to different database adapters.
 *
 * @param string $parameter
 */
PHP_METHOD(Phalcon_Model_Query, setParameters){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_parameters", strlen("_parameters"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the limit of rows to show
 *
 * @param int $limit
 */
PHP_METHOD(Phalcon_Model_Query, setLimit){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_limit", strlen("_limit"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Query, getResultset){


	
}

/**
 * Get the conditions of query
 *
 * @return string $query
 */
PHP_METHOD(Phalcon_Model_Query, getConditions){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_controller_front", "getinstance");
		PHALCON_CPY_WRT(v0, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, v0, "getmodelcomponent", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		Z_ADDREF_P(v1);
		p2[0] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "setmanager", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t1);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_a355_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_a355_0;
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		Z_ADDREF_P(v2);
		p3[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r2, v1, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		PHALCON_CPY_WRT(v3, r2);
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 0);
		PHALCON_INIT_VAR(r3);
		is_equal_function(r3, v3, t3 TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_exception_class_entry);
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_BOTH(r4,  "The model ", v2, " does not exist");
			Z_ADDREF_P(r4);
			p4[0] = r4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		}
		PHALCON_INIT_VAR(r5);
		PHALCON_CALL_METHOD(r5, v1, "getmetadata", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r5);
		PHALCON_INIT_VAR(r6);
		Z_ADDREF_P(v3);
		p6[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r6, v4, "getattributes", 1, p6, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p6[0]);
		PHALCON_CPY_WRT(v5, r6);
		PHALCON_INIT_VAR(r7);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r7, v4, "getdatatypesnumeric", 1, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		PHALCON_CPY_WRT(v6, r7);
		PHALCON_INIT_VAR(v7);
		ZVAL_LONG(v7, 0);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v8, a0);
		PHALCON_INIT_VAR(t4);
		phalcon_read_property(&t4, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(t4);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_a355_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_a355_1;
			} else {
				PHALCON_INIT_VAR(v10);
				htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v10, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v10, num);
					}
				}
			}
			PHALCON_INIT_VAR(v9);
			ZVAL_ZVAL(v9, *hd, 1, 0);
			PHALCON_INIT_VAR(r8);
			Z_ADDREF_P(v10);
			Z_ADDREF_P(v5);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "in_array", v10, v5, 0x019);
			Z_DELREF_P(v10);
			Z_DELREF_P(v5);
			if (zend_is_true(r8)) {
				PHALCON_INIT_VAR(t5);
				ZVAL_STRING(t5, "@", 1);
				PHALCON_INIT_VAR(r9);
				is_not_equal_function(r9, v9, t5 TSRMLS_CC);
				PHALCON_INIT_VAR(r10);
				phalcon_and_function(r10, v9, r9);
				if (zend_is_true(r10)) {
					eval_int = phalcon_array_isset(v6, v10);
					if (eval_int) {
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_VBOTH(r11, v10, " = ?", v7);
						PHALCON_CPY_WRT(v11, r11);
						Z_ADDREF_P(v9);
						if (Z_REFCOUNT_P(v8) > 1) {
							zval *new_zv;
							Z_DELREF_P(v8);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v8);
							v8 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v8, v7, v9 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r12);
						PHALCON_CONCAT_VBOTH(r12, v10, " LIKE ?", v7);
						PHALCON_CPY_WRT(v11, r12);
						PHALCON_INIT_VAR(r13);
						PHALCON_CONCAT_BOTH(r13,  "%", v9, "%");
						Z_ADDREF_P(r13);
						if (Z_REFCOUNT_P(v8) > 1) {
							zval *new_zv;
							Z_DELREF_P(v8);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v8);
							v8 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v8, v7, r13 TSRMLS_CC);
					}
					Z_ADDREF_P(v11);
					p9[0] = v11;
					PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "where", 1, p9, PHALCON_CALL_DEFAULT);
					Z_DELREF_P(p9[0]);
				}
			}
			PHALCON_SEPARATE(v7);
			increment_function(v7);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_a355_1;
			fee_a355_1:
			if(0){ };
		}
		Z_ADDREF_P(v8);
		p10[0] = v8;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "setparameters", 1, p10, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p10[0]);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v12, a1);
		PHALCON_INIT_VAR(t6);
		phalcon_read_property(&t6, this_ptr, "_parameters", sizeof("_parameters")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t6);
		PHALCON_INIT_VAR(t7);
		phalcon_read_property(&t7, this_ptr, "_conditions", sizeof("_conditions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t7) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah2 = Z_ARRVAL_P(t7);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_a355_2:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_a355_2;
			}
			PHALCON_INIT_VAR(v11);
			ZVAL_ZVAL(v11, *hd, 1, 0);
			PHALCON_INIT_VAR(r14);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "?", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r14, "explode", c0, v11, 0x005);
			PHALCON_CPY_WRT(v13, r14);
			PHALCON_INIT_VAR(r15);
			phalcon_array_fetch_long(&r15, v13, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v14, r15);
			PHALCON_INIT_VAR(r16);
			phalcon_array_fetch(&r16, v8, v14, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v9, r16);
			if (zend_is_true(v9)) {
				PHALCON_INIT_VAR(r18);
				phalcon_array_fetch_long(&r18, v13, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(r17);
				PHALCON_CONCAT_VBOTH(r17, r18, " '", v9);
				PHALCON_INIT_VAR(r19);
				PHALCON_CONCAT_RIGHT(r19, r17, "'");
				Z_ADDREF_P(r19);
				PHALCON_SEPARATE_ARRAY(v12);
				phalcon_array_append(v12, r19 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_a355_2;
			fee_a355_2:
			if(0){ };
		}
		PHALCON_INIT_VAR(r20);
		PHALCON_CALL_FUNC_PARAMS_1(r20, "count", v12, 0x007);
		if (!zend_is_true(r20)) {
			PHALCON_INIT_VAR(v15);
			ZVAL_STRING(v15, "1=1", 1);
		} else {
			PHALCON_INIT_VAR(r21);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, " AND ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r21, "join", c1, v12, 0x00D);
			PHALCON_CPY_WRT(v15, r21);
		}
		PHALCON_RETURN_CTOR(v15);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_a355_0;
		fee_a355_0:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Get instace of model query
 *
 * @param string $modelName
 * @param array $data
 * @return Phalcon_Model_Query $query
 */
PHP_METHOD(Phalcon_Model_Query, fromInput){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_query_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "from", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setinputdata", 1, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Phalcon_Model_Base
 *
 * Phalcon_Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object- relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.
 *
 * Phalcon_Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interact with databases while is also easy to use.
 *
 * 
 *
 */

/**
 * Phalcon_Model_Base constructor
 *
 * @param Phalcon_Model_Manager $manager
 *
 */
PHP_METHOD(Phalcon_Model_Base, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	if (!zend_is_true(v0)) {
		t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t0)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
			PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_CALL_DEFAULT);
			zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, r0 TSRMLS_CC);
		}
	} else {
		zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, v0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "get_class", this_ptr, 0x01F);
	PHALCON_CPY_WRT(v1, r2);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_initialized", sizeof("_initialized")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		if (phalcon_method_exists_ex(this_ptr, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_CALL_DEFAULT);
		}
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_initialized", strlen("_initialized"), 1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Internal method for make a connection. Automatically dumps mapped table meta-data
 *
 */
PHP_METHOD(Phalcon_Model_Base, _connect){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Internal method to get table mapped attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get attributes that are part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get attributes which are not part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getNonPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnonprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get attributes that are part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getNotNullAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnotnullattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get numerical-typed attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getDataTypesNumeric){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypesnumeric", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get data-types attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getDataTypes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get identity field
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, _getIdentityField){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getidentityfield", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Dumps mapped table meta-data
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, dump){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t1, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v0, r0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_0;
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		eval_int = phalcon_isset_property_zval(this_ptr, v1 TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, eval_int);
		if (!zend_is_true(t2)) {
			PHALCON_INIT_VAR(t3);
			ZVAL_STRING(t3, "", 1);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v1), Z_STRLEN_P(v1), t3 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_0;
		fee_f9eb_0:
		if(0){ };
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Creates SQL statement which returns many rows
 *
 * @param Phalcon_Manager $manager
 * @param Phalcon_Model_Base $model
 * @param Phalcon_Db $connection
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _createSQLSelectMulti){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
	zval *p4[] = { NULL }, *p3[] = { NULL }, *p5[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL }, *p11[] = { NULL }, *p12[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v3);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v1, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v5, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v1, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r2);
	PHALCON_INIT_VAR(v7);
	ZVAL_STRING(v7, "SELECT ", 1);
	eval_int = phalcon_array_isset_string(v3, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v3, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		concat_function(r4, v7, r3 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		Z_ADDREF_P(v1);
		p4[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r6, v4, "getattributes", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		Z_ADDREF_P(r6);
		p3[0] = r6;
		PHALCON_CALL_METHOD_PARAMS(r5, v2, "getcolumnlist", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		PHALCON_ALLOC_ZVAL_MM(r7);
		concat_function(r7, v7, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r7);
	}
	if (zend_is_true(v6)) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_LEFT(r9, " FROM ", v6);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_VBOTH(r8, r9, ".", v5);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v7, r8 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r10);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_LEFT(r11, " FROM ", v5);
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, v7, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r12);
	}
	PHALCON_INIT_VAR(v8);
	ZVAL_STRING(v8, "n", 1);
	eval_int = phalcon_array_isset_string(v3, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch_string(&r13, v3, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_BOTH(r14,  " WHERE ", r13, " ");
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, v7, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r15);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r16);
		Z_ADDREF_P(v1);
		p5[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r16, v4, "getprimarykeyattributes", 1, p5, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p5[0]);
		PHALCON_CPY_WRT(v9, r16);
		eval_int = phalcon_array_isset_long(v3, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_array_fetch_long(&r18, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r17, "is_numeric", r18, 0x00B);
			if (zend_is_true(r17)) {
				eval_int = phalcon_array_isset_long(v9, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r20);
					phalcon_array_fetch_long(&r20, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r21);
					PHALCON_ALLOC_ZVAL_MM(r22);
					phalcon_array_fetch_long(&r22, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r22);
					p7[0] = r22;
					PHALCON_CALL_METHOD_PARAMS(r21, v2, "addquotes", 1, p7, PHALCON_CALL_DEFAULT);
					Z_DELREF_P(p7[0]);
					PHALCON_ALLOC_ZVAL_MM(r19);
					PHALCON_CONCAT_VBOTH(r19, r20, " = ", r21);
					Z_ADDREF_P(r19);
					if (Z_REFCOUNT_P(v3) > 1) {
						zval *new_zv;
						Z_DELREF_P(v3);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v3);
						v3 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update_string(v3, "conditions", strlen("conditions"), r19 TSRMLS_CC);
					PHALCON_INIT_VAR(v8);
					ZVAL_STRING(v8, "1", 1);
				} else {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					PHALCON_INIT_VAR(p8[0]);
					ZVAL_STRING(p8[0], "Has not been defined a primary key for source related to this model", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p8, PHALCON_CALL_CHECK);
					return phalcon_throw_exception(i0 TSRMLS_CC);
				}
			} else {
				PHALCON_ALLOC_ZVAL_MM(r23);
				phalcon_array_fetch_long(&r23, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_INIT_VAR(r24);
				is_identical_function(r24, t0, r23 TSRMLS_CC);
				if (zend_is_true(r24)) {
					eval_int = phalcon_array_isset_long(v9, 0);
					if (eval_int) {
						PHALCON_ALLOC_ZVAL_MM(r25);
						phalcon_array_fetch_long(&r25, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r26);
						PHALCON_CONCAT_RIGHT(r26, r25, " = ''");
						Z_ADDREF_P(r26);
						if (Z_REFCOUNT_P(v3) > 1) {
							zval *new_zv;
							Z_DELREF_P(v3);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v3);
							v3 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update_string(v3, "conditions", strlen("conditions"), r26 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(i1);
						object_init_ex(i1, phalcon_model_exception_class_entry);
						PHALCON_INIT_VAR(p9[0]);
						ZVAL_STRING(p9[0], "Has not been defined a primary key for source related to this model", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p9, PHALCON_CALL_CHECK);
						return phalcon_throw_exception(i1 TSRMLS_CC);
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r27);
					phalcon_array_fetch_long(&r27, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r27);
					if (Z_REFCOUNT_P(v3) > 1) {
						zval *new_zv;
						Z_DELREF_P(v3);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v3);
						v3 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update_string(v3, "conditions", strlen("conditions"), r27 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(v8);
				ZVAL_STRING(v8, "n", 1);
			}
		}
		eval_int = phalcon_array_isset_string(v3, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r28);
			phalcon_array_fetch_string(&r28, v3, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r29);
			PHALCON_CONCAT_LEFT(r29, " WHERE ", r28);
			PHALCON_ALLOC_ZVAL_MM(r30);
			concat_function(r30, v7, r29 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r30);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r31);
		phalcon_array_fetch_string(&r31, v3, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r31)) {
			PHALCON_ALLOC_ZVAL_MM(r32);
			phalcon_array_fetch_string(&r32, v3, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CONCAT_LEFT(r33, " GROUP BY ", r32);
			PHALCON_ALLOC_ZVAL_MM(r34);
			concat_function(r34, v7, r33 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r34);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r35);
		phalcon_array_fetch_string(&r35, v3, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r35)) {
			PHALCON_ALLOC_ZVAL_MM(r36);
			phalcon_array_fetch_string(&r36, v3, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r37);
			PHALCON_CONCAT_LEFT(r37, " ORDER BY ", r36);
			PHALCON_ALLOC_ZVAL_MM(r38);
			concat_function(r38, v7, r37 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r38);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r39);
		phalcon_array_fetch_string(&r39, v3, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r39)) {
			PHALCON_ALLOC_ZVAL_MM(r40);
			Z_ADDREF_P(v7);
			p10[0] = v7;
			PHALCON_ALLOC_ZVAL_MM(r41);
			phalcon_array_fetch_string(&r41, v3, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r41);
			p10[1] = r41;
			PHALCON_CALL_METHOD_PARAMS(r40, v2, "limit", 2, p10, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p10[0]);
			Z_DELREF_P(p10[1]);
			PHALCON_CPY_WRT(v7, r40);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "for_update", strlen("for_update")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r42);
		phalcon_array_fetch_string(&r42, v3, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r42)) {
			PHALCON_ALLOC_ZVAL_MM(r43);
			Z_ADDREF_P(v7);
			p11[0] = v7;
			PHALCON_CALL_METHOD_PARAMS(r43, v2, "forupdate", 1, p11, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p11[0]);
			PHALCON_CPY_WRT(v7, r43);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r44);
		phalcon_array_fetch_string(&r44, v3, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r44)) {
			PHALCON_ALLOC_ZVAL_MM(r45);
			Z_ADDREF_P(v7);
			p12[0] = v7;
			PHALCON_CALL_METHOD_PARAMS(r45, v2, "sharedlock", 1, p12, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p12[0]);
			PHALCON_CPY_WRT(v7, r45);
		}
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(v8);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "return", v8);
	Z_ADDREF_P(v7);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "sql", v7);
	PHALCON_RETURN_CTOR(a0);
}

/**
 * Creates SQL statement which returns many rows
 *
 * @param Phalcon_Manager $manager
 * @param Phalcon_Model_Base $model
 * @param Phalcon_Db $connection
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _createSQLSelectOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v3);
	
	if (!v4) {
		PHALCON_INIT_VAR(v4);
		ZVAL_STRING(v4, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v4);
	}
	
	if (Z_TYPE_P(v4) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(v4, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch_string(&r1, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_CONCAT_BOTH(r2,  " WHERE ", r1, " ");
				PHALCON_ALLOC_ZVAL_MM(r3);
				concat_function(r3, v3, r2 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r3);
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, v0, "getmetadata", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS(r4, r5, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p0[0]);
			PHALCON_CPY_WRT(v5, r4);
			eval_int = phalcon_array_isset_long(v4, 0);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_ALLOC_ZVAL_MM(r7);
				phalcon_array_fetch_long(&r7, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS_1(r6, "is_numeric", r7, 0x00B);
				if (zend_is_true(r6)) {
					PHALCON_ALLOC_ZVAL_MM(r9);
					phalcon_array_fetch_long(&r9, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r10);
					phalcon_array_fetch_long(&r10, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r8);
					PHALCON_CONCAT_VBOTH(r8, r9, " = '", r10);
					PHALCON_ALLOC_ZVAL_MM(r11);
					PHALCON_CONCAT_RIGHT(r11, r8, "'");
					Z_ADDREF_P(r11);
					if (Z_REFCOUNT_P(v4) > 1) {
						zval *new_zv;
						Z_DELREF_P(v4);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v4);
						v4 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update_string(v4, "conditions", strlen("conditions"), r11 TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r12);
					phalcon_array_fetch_long(&r12, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r12, "")) {
						PHALCON_ALLOC_ZVAL_MM(r13);
						phalcon_array_fetch_long(&r13, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r14);
						PHALCON_CONCAT_RIGHT(r14, r13, " = ''");
						Z_ADDREF_P(r14);
						if (Z_REFCOUNT_P(v4) > 1) {
							zval *new_zv;
							Z_DELREF_P(v4);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v4);
							v4 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update_string(v4, "conditions", strlen("conditions"), r14 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(r15);
						phalcon_array_fetch_long(&r15, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						Z_ADDREF_P(r15);
						if (Z_REFCOUNT_P(v4) > 1) {
							zval *new_zv;
							Z_DELREF_P(v4);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v4);
							v4 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update_string(v4, "conditions", strlen("conditions"), r15 TSRMLS_CC);
					}
				}
			}
			eval_int = phalcon_array_isset_string(v4, "conditions", strlen("conditions")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r16);
				phalcon_array_fetch_string(&r16, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_CONCAT_LEFT(r17, " WHERE ", r16);
				PHALCON_ALLOC_ZVAL_MM(r18);
				concat_function(r18, v3, r17 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r18);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "order", strlen("order")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r19);
			phalcon_array_fetch_string(&r19, v4, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL_MM(r20);
				phalcon_array_fetch_string(&r20, v4, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r21);
				PHALCON_CONCAT_LEFT(r21, " ORDER BY ", r20);
				PHALCON_ALLOC_ZVAL_MM(r22);
				concat_function(r22, v3, r21 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r22);
			}
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " ORDER BY 1", 1);
			PHALCON_ALLOC_ZVAL_MM(r23);
			concat_function(r23, v3, t0 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r23);
		}
		eval_int = phalcon_array_isset_string(v4, "limit", strlen("limit")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			phalcon_array_fetch_string(&r24, v4, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r24)) {
				PHALCON_ALLOC_ZVAL_MM(r25);
				Z_ADDREF_P(v3);
				p3[0] = v3;
				PHALCON_ALLOC_ZVAL_MM(r26);
				phalcon_array_fetch_string(&r26, v4, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r26);
				p3[1] = r26;
				PHALCON_CALL_METHOD_PARAMS(r25, v2, "limit", 2, p3, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p3[0]);
				Z_DELREF_P(p3[1]);
				PHALCON_CPY_WRT(v3, r25);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "for_update", strlen("for_update")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r27);
			phalcon_array_fetch_string(&r27, v4, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r27)) {
				PHALCON_ALLOC_ZVAL_MM(r28);
				Z_ADDREF_P(v3);
				p4[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r28, v2, "forupdate", 1, p4, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p4[0]);
				PHALCON_CPY_WRT(v3, r28);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "shared_lock", strlen("shared_lock")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r29);
			phalcon_array_fetch_string(&r29, v4, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r29)) {
				PHALCON_ALLOC_ZVAL_MM(r30);
				Z_ADDREF_P(v3);
				p5[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r30, v2, "sharedlock", 1, p5, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p5[0]);
				PHALCON_CPY_WRT(v3, r30);
			}
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CALL_FUNC_PARAMS_1(r31, "strlen", v4, 0x001);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r32);
		is_smaller_function(r32, t1, r31 TSRMLS_CC);
		if (zend_is_true(r32)) {
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CALL_FUNC_PARAMS_1(r33, "is_numeric", v4, 0x00B);
			if (zend_is_true(r33)) {
				PHALCON_ALLOC_ZVAL_MM(r35);
				phalcon_array_fetch_long(&r35, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r36);
				PHALCON_CONCAT_LEFT(r36, "WHERE ", r35);
				PHALCON_ALLOC_ZVAL_MM(r34);
				PHALCON_CONCAT_VBOTH(r34, r36, " = '", v4);
				PHALCON_ALLOC_ZVAL_MM(r37);
				PHALCON_CONCAT_RIGHT(r37, r34, "'");
				PHALCON_ALLOC_ZVAL_MM(r38);
				concat_function(r38, v3, r37 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r38);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r39);
				PHALCON_CONCAT_LEFT(r39, "WHERE ", v4);
				PHALCON_ALLOC_ZVAL_MM(r40);
				concat_function(r40, v3, r39 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r40);
			}
		}
	}
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * Creates a resultset from a SQL statement
 *
 * @param Phalcon_Model_Base $model
 * @param Phalcon_Db $connection
 * @param array $select
 * @param resource $resultResource
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Base, _createResultset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v2, "return", strlen("return"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "1", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r2, v1, "numrows", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		if (!zend_is_true(r2)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		} else {
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_LONG(p1[0], 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r3);
			Z_ADDREF_P(v3);
			p2[0] = v3;
			PHALCON_CALL_METHOD_PARAMS(r3, v1, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p2[0]);
			PHALCON_CPY_WRT(v4, r3);
			PHALCON_INIT_VAR(p3[0]);
			ZVAL_LONG(p3[0], 2);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p3, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r4);
			Z_ADDREF_P(v4);
			p4[0] = v4;
			PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "dumpresult", 1, p4);
			Z_DELREF_P(p4[0]);
			PHALCON_RETURN_DZVAL(r4);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r5, v1, "numrows", 1, p5, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p5[0]);
		PHALCON_CPY_WRT(v5, r5);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, t1, v5 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v0);
			p6[0] = v0;
			Z_ADDREF_P(v3);
			p6[1] = v3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p6, PHALCON_CALL_CHECK);
			Z_DELREF_P(p6[0]);
			Z_DELREF_P(p6[1]);
			PHALCON_RETURN_CTOR(i0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v0);
			p7[0] = v0;
			PHALCON_INIT_VAR(p7[1]);
			ZVAL_BOOL(p7[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p7, PHALCON_CALL_CHECK);
			Z_DELREF_P(p7[0]);
			PHALCON_RETURN_CTOR(i1);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes default model manager
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns internal models manager
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Model_Base, getManager){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets a transaction related to the Model instance
 *
 *
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Model_Base, setTransaction){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Transaction should be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Checks wheter model is mapped to a database view
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, isView){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 */
PHP_METHOD(Phalcon_Model_Base, setSource){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, getSource){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x01F);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS(r0, t1, "getsource", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Sets schema name where table mapped is located
 *
 * @param string $schema
 */
PHP_METHOD(Phalcon_Model_Base, setSchema){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, getSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Overwrittes internal Phalcon_Db connection
 *
 * @param Phalcon_Db $connection
 */
PHP_METHOD(Phalcon_Model_Base, setConnection){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets internal Phalcon_Db connection
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *
 *
 * @param array $result
 * @param Phalcon_Model_Base $base
 * @return Phalcon_Model_Base $result
 */
PHP_METHOD(Phalcon_Model_Base, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	phalcon_clone(i0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, i0);
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_1;
			} else {
				PHALCON_INIT_VAR(v4);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v4, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v4, num);
					}
				}
			}
			PHALCON_INIT_VAR(v3);
			ZVAL_ZVAL(v3, *hd, 1, 0);
			phalcon_update_property_zval(v2, Z_STRVAL_P(v4), Z_STRLEN_P(v4), v3 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_1;
			fee_f9eb_1:
			if(0){ };
		}
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * 
 *
 * @param array $parameters
 * @return  Phalcon_Model_Resulset
 */
PHP_METHOD(Phalcon_Model_Base, find){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL, NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL, NULL, NULL, NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x032);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			Z_ADDREF_P(v0);
			PHALCON_SEPARATE_ARRAY(a0);
			add_next_index_zval(a0, v0);
			PHALCON_CPY_WRT(v5, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v5, a1);
		}
	} else {
		PHALCON_CPY_WRT(v5, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	Z_ADDREF_P(v3);
	p6[0] = v3;
	Z_ADDREF_P(v2);
	p6[1] = v2;
	Z_ADDREF_P(v4);
	p6[2] = v4;
	Z_ADDREF_P(v5);
	p6[3] = v5;
	PHALCON_CALL_SELF_PARAMS(r3, this_ptr, "_createsqlselectmulti", 4, p6);
	Z_DELREF_P(p6[0]);
	Z_DELREF_P(p6[1]);
	Z_DELREF_P(p6[2]);
	Z_DELREF_P(p6[3]);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_string(&r5, v6, "sql", strlen("sql"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r5);
	p7[0] = r5;
	PHALCON_CALL_METHOD_PARAMS(r4, v4, "query", 1, p7, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p7[0]);
	PHALCON_CPY_WRT(v7, r4);
	PHALCON_ALLOC_ZVAL_MM(r6);
	Z_ADDREF_P(v2);
	p8[0] = v2;
	Z_ADDREF_P(v4);
	p8[1] = v4;
	Z_ADDREF_P(v6);
	p8[2] = v6;
	Z_ADDREF_P(v7);
	p8[3] = v7;
	PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "_createresultset", 4, p8);
	Z_DELREF_P(p8[0]);
	Z_DELREF_P(p8[1]);
	Z_DELREF_P(p8[2]);
	Z_DELREF_P(p8[3]);
	PHALCON_RETURN_DZVAL(r6);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * 
 *
 * @param array $parameters
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, findFirst){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p9[] = { NULL }, *p8[] = { NULL }, *p11[] = { NULL, NULL, NULL, NULL, NULL }, *p12[] = { NULL }, *p13[] = { NULL }, *p14[] = { NULL, NULL }, *p15[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x032);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			Z_ADDREF_P(v0);
			PHALCON_SEPARATE_ARRAY(a0);
			add_next_index_zval(a0, v0);
			PHALCON_CPY_WRT(v5, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v5, a1);
		}
	} else {
		PHALCON_CPY_WRT(v5, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, v2, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, v2, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v7, r4);
	PHALCON_INIT_VAR(v8);
	ZVAL_STRING(v8, "SELECT ", 1);
	eval_int = phalcon_array_isset_string(v5, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v5, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r6);
		concat_function(r6, v8, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r6);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CALL_METHOD(r9, v3, "getmetadata", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(v2);
		p9[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r8, r9, "getattributes", 1, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		Z_ADDREF_P(r8);
		p8[0] = r8;
		PHALCON_CALL_METHOD_PARAMS(r7, v4, "getcolumnlist", 1, p8, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p8[0]);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v8, r7 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r10);
	}
	if (!PHALCON_COMPARE_STRING(v6, "")) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_LEFT(r12, " FROM ", v6);
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_VBOTH(r11, r12, ".", v7);
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, v8, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r13);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_LEFT(r14, " FROM ", v7);
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, v8, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r15);
	}
	eval_int = phalcon_array_isset_string(v5, "limit", strlen("limit")+1);
	PHALCON_INIT_VAR(r16);
	ZVAL_BOOL(r16, eval_int);
	if (!zend_is_true(r16)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 1);
		Z_ADDREF_P(t0);
		if (Z_REFCOUNT_P(v5) > 1) {
			zval *new_zv;
			Z_DELREF_P(v5);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v5);
			v5 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v5, "limit", strlen("limit"), t0 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(v9);
	ZVAL_BOOL(v9, 0);
	PHALCON_ALLOC_ZVAL_MM(r17);
	Z_ADDREF_P(v3);
	p11[0] = v3;
	Z_ADDREF_P(v2);
	p11[1] = v2;
	Z_ADDREF_P(v4);
	p11[2] = v4;
	Z_ADDREF_P(v8);
	p11[3] = v8;
	Z_ADDREF_P(v5);
	p11[4] = v5;
	PHALCON_CALL_SELF_PARAMS(r17, this_ptr, "_createsqlselectone", 5, p11);
	Z_DELREF_P(p11[0]);
	Z_DELREF_P(p11[1]);
	Z_DELREF_P(p11[2]);
	Z_DELREF_P(p11[3]);
	Z_DELREF_P(p11[4]);
	PHALCON_CPY_WRT(v8, r17);
	PHALCON_INIT_VAR(p12[0]);
	ZVAL_LONG(p12[0], 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setfetchmode", 1, p12, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r18);
	Z_ADDREF_P(v8);
	p13[0] = v8;
	PHALCON_CALL_METHOD_PARAMS(r18, v4, "fetchone", 1, p13, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p13[0]);
	PHALCON_CPY_WRT(v10, r18);
	if (zend_is_true(v10)) {
		PHALCON_ALLOC_ZVAL_MM(r19);
		Z_ADDREF_P(v2);
		p14[0] = v2;
		Z_ADDREF_P(v10);
		p14[1] = v10;
		PHALCON_CALL_SELF_PARAMS(r19, this_ptr, "dumpresult", 2, p14);
		Z_DELREF_P(p14[0]);
		Z_DELREF_P(p14[1]);
		PHALCON_CPY_WRT(v9, r19);
	}
	PHALCON_INIT_VAR(p15[0]);
	ZVAL_LONG(p15[0], 2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setfetchmode", 1, p15, PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_CHECK_CTOR(v9);
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p7[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_forceExists", sizeof("_forceExists")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v0, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		if (zend_is_true(v0)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_VBOTH(r2, v0, ".", v1);
			PHALCON_CPY_WRT(v2, r2);
		} else {
			PHALCON_CPY_WRT(v2, v1);
		}
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) AS rowcount FROM ", v2, " WHERE ");
		PHALCON_CPY_WRT(v3, r3);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v4, a0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v6, r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "count", v5, 0x007);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, t1, r6 TSRMLS_CC);
		if (zend_is_true(r7)) {
			if (Z_TYPE_P(v5) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v5);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f9eb_2:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f9eb_2;
				}
				PHALCON_INIT_VAR(v7);
				ZVAL_ZVAL(v7, *hd, 1, 0);
				PHALCON_INIT_VAR(t2);
				phalcon_read_property_zval(&t2, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v8, t2);
				PHALCON_INIT_VAR(t3);
				ZVAL_NULL(t3);
				PHALCON_INIT_VAR(r8);
				is_not_identical_function(r8, t3, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "", 1);
				PHALCON_INIT_VAR(r9);
				is_not_identical_function(r9, t4, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(r10);
				phalcon_and_function(r10, r8, r9);
				if (zend_is_true(r10)) {
					eval_int = phalcon_array_isset(v6, v7);
					if (eval_int) {
						PHALCON_INIT_VAR(r12);
						PHALCON_CONCAT_LEFT(r12, " ", v7);
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_VBOTH(r11, r12, " = ", v8);
						Z_ADDREF_P(r11);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r11 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r14);
						PHALCON_CONCAT_LEFT(r14, " ", v7);
						PHALCON_INIT_VAR(r13);
						PHALCON_CONCAT_VBOTH(r13, r14, " = '", v8);
						PHALCON_INIT_VAR(r15);
						PHALCON_CONCAT_RIGHT(r15, r13, "'");
						Z_ADDREF_P(r15);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r15 TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f9eb_2;
				fee_f9eb_2:
				if(0){ };
			}
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CALL_FUNC_PARAMS_1(r16, "count", v4, 0x007);
			if (zend_is_true(r16)) {
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r17, "join", c0, v4, 0x00D);
				phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r17 TSRMLS_CC);
			} else {
				PHALCON_MM_RESTORE();
				RETURN_LONG(0);
			}
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r18);
			concat_function(r18, v3, t5 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r18);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_LONG(0);
		}
		PHALCON_ALLOC_ZVAL_MM(r19);
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_read_property(&t6, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r19, t6, "fetchone", 1, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		PHALCON_CPY_WRT(v9, r19);
		PHALCON_ALLOC_ZVAL_MM(r20);
		phalcon_array_fetch_string(&r20, v9, "rowcount", strlen("rowcount"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r20);
	} else {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v4, a1);
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_CALL_METHOD(r21, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r21);
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_CALL_METHOD(r22, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v10, r22);
		PHALCON_ALLOC_ZVAL_MM(r23);
		PHALCON_CALL_FUNC_PARAMS_1(r23, "count", v5, 0x007);
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 0);
		PHALCON_INIT_VAR(r24);
		is_smaller_function(r24, t7, r23 TSRMLS_CC);
		if (zend_is_true(r24)) {
			if (Z_TYPE_P(v5) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v5);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_f9eb_3:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_f9eb_3;
				}
				PHALCON_INIT_VAR(v7);
				ZVAL_ZVAL(v7, *hd, 1, 0);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property_zval(&t8, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v8, t8);
				PHALCON_INIT_VAR(t9);
				ZVAL_NULL(t9);
				PHALCON_INIT_VAR(r25);
				is_not_identical_function(r25, t9, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(t10);
				ZVAL_STRING(t10, "", 1);
				PHALCON_INIT_VAR(r26);
				is_not_identical_function(r26, t10, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(r27);
				phalcon_and_function(r27, r25, r26);
				if (zend_is_true(r27)) {
					eval_int = phalcon_array_isset(v10, v7);
					if (eval_int) {
						PHALCON_INIT_VAR(r29);
						PHALCON_CONCAT_LEFT(r29, " ", v7);
						PHALCON_INIT_VAR(r28);
						PHALCON_CONCAT_VBOTH(r28, r29, " = ", v8);
						Z_ADDREF_P(r28);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r28 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r31);
						PHALCON_CONCAT_LEFT(r31, " ", v7);
						PHALCON_INIT_VAR(r30);
						PHALCON_CONCAT_VBOTH(r30, r31, " = '", v8);
						PHALCON_INIT_VAR(r32);
						PHALCON_CONCAT_RIGHT(r32, r30, "'");
						Z_ADDREF_P(r32);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r32 TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_f9eb_3;
				fee_f9eb_3:
				if(0){ };
			}
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CALL_FUNC_PARAMS_1(r33, "count", v4, 0x007);
			if (zend_is_true(r33)) {
				PHALCON_ALLOC_ZVAL_MM(r34);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r34, "join", c1, v4, 0x00D);
				phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r34 TSRMLS_CC);
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			} else {
				PHALCON_MM_RESTORE();
				RETURN_LONG(0);
			}
		} else {
			PHALCON_MM_RESTORE();
			RETURN_LONG(0);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	eval_int = phalcon_array_isset_string(v1, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r0, v0, "query", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v4, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v4);
		p1[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r1, v0, "numrows", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v5, r1);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r2);
		is_smaller_function(r2, t0, v5 TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_row_class_entry);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v6, i0);
			Z_ADDREF_P(v0);
			p3[0] = v0;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "setconnection", 1, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v6);
			p4[0] = v6;
			Z_ADDREF_P(v4);
			p4[1] = v4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			Z_DELREF_P(p4[1]);
			PHALCON_RETURN_CTOR(i1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_model_resultset_class_entry);
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init(i3);
			Z_ADDREF_P(i3);
			p5[0] = i3;
			PHALCON_INIT_VAR(p5[1]);
			ZVAL_BOOL(p5[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p5, PHALCON_CALL_CHECK);
			Z_DELREF_P(p5[0]);
			PHALCON_RETURN_CTOR(i2);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v2);
		p6[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r3, v0, "fetchone", 1, p6, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p6[0]);
		PHALCON_CPY_WRT(v7, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch(&r4, v7, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r4);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Allows to count how many records match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return int
 */
PHP_METHOD(Phalcon_Model_Base, count){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p9[] = { NULL }, *p11[] = { NULL, NULL }, *p12[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x032);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "There is not model manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			Z_ADDREF_P(v0);
			PHALCON_SEPARATE_ARRAY(a0);
			add_next_index_zval(a0, v0);
			PHALCON_CPY_WRT(v5, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v5, a1);
		}
	} else {
		PHALCON_CPY_WRT(v5, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, v2, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, v2, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v7, r4);
	if (zend_is_true(v6)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, v6, ".", v7);
		PHALCON_CPY_WRT(v8, r5);
	} else {
		PHALCON_CPY_WRT(v8, v7);
	}
	eval_int = phalcon_array_isset_string(v5, "distinct", strlen("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, v5, "distinct", strlen("distinct"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_LEFT(r8, "SELECT COUNT(DISTINCT ", r7);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_VBOTH(r6, r8, ") AS rowcount FROM ", v8);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_RIGHT(r9, r6, " ");
		PHALCON_CPY_WRT(v9, r9);
	} else {
		eval_int = phalcon_array_isset_string(v5, "group", strlen("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r11);
			phalcon_array_fetch_string(&r11, v5, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r12);
			PHALCON_CONCAT_LEFT(r12, "SELECT ", r11);
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_VBOTH(r10, r12, ", COUNT(*) AS rowcount FROM ", v8);
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_CONCAT_RIGHT(r13, r10, " ");
			PHALCON_CPY_WRT(v9, r13);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_BOTH(r14,  "SELECT COUNT(*) AS rowcount FROM ", v8, " ");
			PHALCON_CPY_WRT(v9, r14);
		}
	}
	eval_int = phalcon_array_isset_string(v5, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_array_fetch_string(&r15, v5, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_BOTH(r16,  " WHERE ", r15, " ");
		PHALCON_ALLOC_ZVAL_MM(r17);
		concat_function(r17, v9, r16 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r17);
	} else {
		eval_int = phalcon_array_isset_long(v5, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_array_fetch_long(&r18, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v10, r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_CALL_FUNC_PARAMS_1(r19, "is_numeric", v10, 0x00B);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL_MM(r20);
				PHALCON_ALLOC_ZVAL_MM(r21);
				PHALCON_CALL_METHOD(r21, v3, "getmetadata", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(v2);
				p9[0] = v2;
				PHALCON_CALL_METHOD_PARAMS(r20, r21, "getprimarykeyattributes", 1, p9, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p9[0]);
				PHALCON_CPY_WRT(v11, r20);
				eval_int = phalcon_array_isset_long(v11, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r23);
					phalcon_array_fetch_long(&r23, v11, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r24);
					PHALCON_CONCAT_LEFT(r24, " WHERE ", r23);
					PHALCON_ALLOC_ZVAL_MM(r22);
					PHALCON_CONCAT_VBOTH(r22, r24, " = '", v10);
					PHALCON_ALLOC_ZVAL_MM(r25);
					PHALCON_CONCAT_RIGHT(r25, r22, "'");
					PHALCON_ALLOC_ZVAL_MM(r26);
					concat_function(r26, v9, r25 TSRMLS_CC);
					PHALCON_CPY_WRT(v9, r26);
				} else {
					PHALCON_INIT_VAR(t0);
					ZVAL_STRING(t0, " WHERE 0=1", 1);
					PHALCON_ALLOC_ZVAL_MM(r27);
					concat_function(r27, v9, t0 TSRMLS_CC);
					PHALCON_CPY_WRT(v9, r27);
				}
			} else {
				if (zend_is_true(v10)) {
					PHALCON_ALLOC_ZVAL_MM(r28);
					PHALCON_CONCAT_LEFT(r28, " WHERE ", v10);
					PHALCON_ALLOC_ZVAL_MM(r29);
					concat_function(r29, v9, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(v9, r29);
				}
			}
		}
	}
	eval_int = phalcon_array_isset_string(v5, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r30);
		phalcon_array_fetch_string(&r30, v5, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CONCAT_BOTH(r31,  " GROUP BY ", r30, " ");
		PHALCON_ALLOC_ZVAL_MM(r32);
		concat_function(r32, v9, r31 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r32);
	}
	eval_int = phalcon_array_isset_string(v5, "having", strlen("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r33);
		phalcon_array_fetch_string(&r33, v5, "having", strlen("having"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r34);
		PHALCON_CONCAT_BOTH(r34,  " HAVING ", r33, " ");
		PHALCON_ALLOC_ZVAL_MM(r35);
		concat_function(r35, v9, r34 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r35);
	}
	eval_int = phalcon_array_isset_string(v5, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r36);
		phalcon_array_fetch_string(&r36, v5, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r37);
		PHALCON_CONCAT_BOTH(r37,  " ORDER BY ", r36, " ");
		PHALCON_ALLOC_ZVAL_MM(r38);
		concat_function(r38, v9, r37 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r38);
	}
	eval_int = phalcon_array_isset_string(v5, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r39);
		Z_ADDREF_P(v9);
		p11[0] = v9;
		PHALCON_ALLOC_ZVAL_MM(r40);
		phalcon_array_fetch_string(&r40, v5, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r40);
		p11[1] = r40;
		PHALCON_CALL_METHOD_PARAMS(r39, v4, "_limit", 2, p11, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p11[0]);
		Z_DELREF_P(p11[1]);
		PHALCON_CPY_WRT(v9, r39);
	}
	PHALCON_ALLOC_ZVAL_MM(r41);
	Z_ADDREF_P(v4);
	p12[0] = v4;
	Z_ADDREF_P(v5);
	p12[1] = v5;
	Z_ADDREF_P(v9);
	p12[2] = v9;
	PHALCON_INIT_VAR(p12[3]);
	ZVAL_STRING(p12[3], "rowcount", 1);
	PHALCON_CALL_SELF_PARAMS(r41, this_ptr, "_getgroupresult", 4, p12);
	Z_DELREF_P(p12[0]);
	Z_DELREF_P(p12[1]);
	Z_DELREF_P(p12[2]);
	PHALCON_RETURN_DZVAL(r41);
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (phalcon_method_exists(this_ptr, v0 TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(v0), PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _cancelOperation){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_operationMade", sizeof("_operationMade")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 3);
		PHALCON_ALLOC_ZVAL_MM(r0);
		is_equal_function(r0, t1, t2 TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(p0[0]);
			ZVAL_STRING(p0[0], "notDeleted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
		} else {
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "notSaved", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_transaction_manager", "isautomatic");
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "getautomatic");
		PHALCON_CPY_WRT(v0, r2);
		Z_ADDREF_P(this_ptr);
		p4[0] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setrollbackedrecord", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		PHALCON_CALL_METHOD_NORETURN(v0, "rollback", PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Appends a customized message on the validation process
 *
 * 
 *
 * @param Phalcon_Model_Message $message
 */
PHP_METHOD(Phalcon_Model_Base, appendMessage){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", v0, 0x01F);
		if (!PHALCON_COMPARE_STRING(r0, "Phalcon_Model_Message")) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", v0, 0x01F);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_BOTH(r2,  "Invalid message format '", r1, "'");
			Z_ADDREF_P(r2);
			p1[0] = r2;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			Z_DELREF_P(p1[0]);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "gettype", v0, 0x033);
		Z_DELREF_P(v0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "Invalid message format '", r3, "'");
		Z_ADDREF_P(r4);
		p3[0] = r4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes validators on every validation call
 *
 *
 *
 * @param string $validatorClass
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Base, validate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL, NULL, NULL }, *p5[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Model_Validator_", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v2, 0x00F);
	Z_DELREF_P(v2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Validator '", v0, "' does not exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Parameter options must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "field", strlen("field")+1);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "Field name to be validated is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v1, "field", strlen("field"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r4);
	}
	if (Z_TYPE_P(v3) != IS_ARRAY) { 
		ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, ce0);
		Z_ADDREF_P(this_ptr);
		p4[0] = this_ptr;
		Z_ADDREF_P(v3);
		p4[1] = v3;
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property_zval(&t0, this_ptr, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t0);
		p4[2] = t0;
		Z_ADDREF_P(v1);
		p4[3] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 4, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		Z_DELREF_P(p4[1]);
		Z_DELREF_P(p4[2]);
		Z_DELREF_P(p4[3]);
		PHALCON_CPY_WRT(v4, i3);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v5, a0);
		if (Z_TYPE_P(v3) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v3);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_4;
			}
			PHALCON_INIT_VAR(v6);
			ZVAL_ZVAL(v6, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			phalcon_read_property_zval(&t1, this_ptr, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t1);
			PHALCON_SEPARATE_ARRAY(v5);
			phalcon_array_append(v5, t1 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_4;
			fee_f9eb_4:
			if(0){ };
		}
		ce1 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i4);
		object_init_ex(i4, ce1);
		Z_ADDREF_P(this_ptr);
		p5[0] = this_ptr;
		Z_ADDREF_P(v3);
		p5[1] = v3;
		Z_ADDREF_P(v5);
		p5[2] = v5;
		Z_ADDREF_P(v1);
		p5[3] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p5, PHALCON_CALL_CHECK);
		Z_DELREF_P(p5[0]);
		Z_DELREF_P(p5[1]);
		Z_DELREF_P(p5[2]);
		Z_DELREF_P(p5[3]);
		PHALCON_CPY_WRT(v4, i4);
	}
	PHALCON_CALL_METHOD_NORETURN(v4, "checkoptions", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v4, "validate", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r5) == IS_BOOL && !Z_BVAL_P(r5)) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_METHOD(r6, v4, "getmessages", PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r6) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(r6);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_f9eb_5:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_f9eb_5;
			}
			PHALCON_INIT_VAR(v7);
			ZVAL_ZVAL(v7, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v7);
			phalcon_array_append(t2, v7 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_f9eb_5;
			fee_f9eb_5:
			if(0){ };
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Check whether validation process has generated any messages
 *
 *
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, validationHasFailed){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns all the validation messages
 *
 * 
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getMessages){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Model_Base, _preSave){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p10[] = { NULL, NULL, NULL }, *p11[] = { NULL, NULL, NULL }, *p12[] = { NULL }, *p14[] = { NULL }, *p15[] = { NULL }, *p17[] = { NULL }, *p19[] = { NULL }, *p21[] = { NULL }, *p23[] = { NULL }, *p25[] = { NULL }, *p27[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), a0 TSRMLS_CC);
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "beforeValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "beforeValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(p4[0]);
			ZVAL_STRING(p4[0], "beforeValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_INIT_VAR(v2);
	ZVAL_NULL(v2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "_getnotnullattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v3, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r4);
	if (Z_TYPE_P(v3) == IS_ARRAY) { 
		PHALCON_INIT_VAR(v5);
		ZVAL_BOOL(v5, 0);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v3, 0x007);
		PHALCON_CPY_WRT(v6, r5);
		PHALCON_INIT_VAR(v7);
		ZVAL_LONG(v7, 0);
		fs_f9eb_6:
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, v7, v6 TSRMLS_CC);
		if (!zend_is_true(r6)) {
			goto fe_f9eb_6;
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_BOOL(v8, 0);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch(&r7, v3, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r7);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, t0);
		eval_int = phalcon_array_isset(v4, v9);
		PHALCON_INIT_VAR(r8);
		ZVAL_BOOL(r8, eval_int);
		if (!zend_is_true(r8)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_NULL(t1);
			PHALCON_INIT_VAR(r9);
			is_identical_function(r9, t1, v10 TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			PHALCON_INIT_VAR(r10);
			is_identical_function(r10, t2, v10 TSRMLS_CC);
			PHALCON_INIT_VAR(r11);
			ZVAL_BOOL(r11, zend_is_true(r9) || zend_is_true(r10));
			if (zend_is_true(r11)) {
				PHALCON_INIT_VAR(v8);
				ZVAL_BOOL(v8, 1);
			}
		} else {
			PHALCON_INIT_VAR(r12);
			PHALCON_CALL_FUNC_PARAMS_1(r12, "is_numeric", v10, 0x00B);
			if (!zend_is_true(r12)) {
				PHALCON_INIT_VAR(v8);
				ZVAL_BOOL(v8, 1);
			}
		}
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		PHALCON_INIT_VAR(r13);
		is_equal_function(r13, v8, t3 TSRMLS_CC);
		if (zend_is_true(r13)) {
			PHALCON_INIT_VAR(r14);
			boolean_not_function(r14, v1 TSRMLS_CC);
			PHALCON_INIT_VAR(t4);
			ZVAL_STRING(t4, "id", 1);
			PHALCON_INIT_VAR(r15);
			is_equal_function(r15, v9, t4 TSRMLS_CC);
			PHALCON_INIT_VAR(r16);
			phalcon_and_function(r16, r14, r15);
			if (zend_is_true(r16)) {
				goto fi_f9eb_6;
			}
			PHALCON_INIT_VAR(r17);
			PHALCON_INIT_VAR(p10[0]);
			ZVAL_STRING(p10[0], "_id", 1);
			PHALCON_INIT_VAR(p10[1]);
			ZVAL_STRING(p10[1], "", 1);
			p10[2] = v9;
			PHALCON_CALL_FUNC_PARAMS(r17, "str_replace", 3, p10, 0x003);
			PHALCON_CPY_WRT(v11, r17);
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_model_message_class_entry);
			PHALCON_INIT_VAR(r18);
			PHALCON_CONCAT_RIGHT(r18, v11, " is required");
			Z_ADDREF_P(r18);
			p11[0] = r18;
			Z_ADDREF_P(v9);
			p11[1] = v9;
			PHALCON_INIT_VAR(p11[2]);
			ZVAL_STRING(p11[2], "PresenceOf", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p11, PHALCON_CALL_CHECK);
			Z_DELREF_P(p11[0]);
			Z_DELREF_P(p11[1]);
			PHALCON_CPY_WRT(v12, i0);
			PHALCON_INIT_VAR(t5);
			phalcon_read_property(&t5, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v12);
			phalcon_array_append(t5, v12 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t5 TSRMLS_CC);
			PHALCON_INIT_VAR(v5);
			ZVAL_BOOL(v5, 1);
		}
		fi_f9eb_6:
		PHALCON_SEPARATE(v7);
		increment_function(v7);
		goto fs_f9eb_6;
		fe_f9eb_6:
		if (zend_is_true(v5)) {
			if (!zend_is_true(v0)) {
				PHALCON_INIT_VAR(p12[0]);
				ZVAL_STRING(p12[0], "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p12, PHALCON_CALL_DEFAULT);
			}
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r19);
	PHALCON_INIT_VAR(p14[0]);
	ZVAL_STRING(p14[0], "validation", 1);
	PHALCON_CALL_METHOD_PARAMS(r19, this_ptr, "_callevent", 1, p14, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r19) == IS_BOOL && !Z_BVAL_P(r19)) {
		if (!zend_is_true(v0)) {
			PHALCON_INIT_VAR(p15[0]);
			ZVAL_STRING(p15[0], "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p15, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(v0)) {
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_INIT_VAR(p17[0]);
			ZVAL_STRING(p17[0], "afterValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r20, this_ptr, "_callevent", 1, p17, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r20) == IS_BOOL && !Z_BVAL_P(r20)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_INIT_VAR(p19[0]);
			ZVAL_STRING(p19[0], "afterValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r21, this_ptr, "_callevent", 1, p19, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r21) == IS_BOOL && !Z_BVAL_P(r21)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_INIT_VAR(p21[0]);
		ZVAL_STRING(p21[0], "afterValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r22, this_ptr, "_callevent", 1, p21, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r22) == IS_BOOL && !Z_BVAL_P(r22)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		PHALCON_ALLOC_ZVAL_MM(r23);
		PHALCON_INIT_VAR(p23[0]);
		ZVAL_STRING(p23[0], "beforeSave", 1);
		PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "_callevent", 1, p23, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r23) == IS_BOOL && !Z_BVAL_P(r23)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_INIT_VAR(p25[0]);
			ZVAL_STRING(p25[0], "beforeUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r24, this_ptr, "_callevent", 1, p25, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r24) == IS_BOOL && !Z_BVAL_P(r24)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r25);
			PHALCON_INIT_VAR(p27[0]);
			ZVAL_STRING(p27[0], "beforeCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "_callevent", 1, p27, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r25) == IS_BOOL && !Z_BVAL_P(r25)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _postSave){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		if (zend_is_true(v2)) {
			if (!zend_is_true(v0)) {
				PHALCON_INIT_VAR(p0[0]);
				ZVAL_STRING(p0[0], "afterUpdate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
			}
		} else {
			if (!zend_is_true(v0)) {
				PHALCON_INIT_VAR(p1[0]);
				ZVAL_STRING(p1[0], "afterCreate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
			}
		}
		if (!zend_is_true(v0)) {
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
		}
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		if (!zend_is_true(v0)) {
			PHALCON_INIT_VAR(p3[0]);
			ZVAL_STRING(p3[0], "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p3, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _doLowInsert){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *p2[] = { NULL }, *p5[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(v5, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r0);
	if (Z_TYPE_P(v6) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v6);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_7;
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_ZVAL(v7, *hd, 1, 0);
		if (!PHALCON_COMPARE_STRING(v7, "id")) {
			Z_ADDREF_P(v7);
			PHALCON_SEPARATE_ARRAY(v4);
			phalcon_array_append(v4, v7 TSRMLS_CC);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property_zval(&t0, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v8, t0);
			if (Z_TYPE_P(v8) == IS_OBJECT) {
				PHALCON_INIT_VAR(r1);
				phalcon_instance_of(r1, v8, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r1)) {
					PHALCON_INIT_VAR(r2);
					PHALCON_CALL_METHOD(r2, v8, "getvalue", PHALCON_CALL_DEFAULT);
					Z_ADDREF_P(r2);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, r2 TSRMLS_CC);
				} else {
					convert_to_string(v8);
					Z_ADDREF_P(v8);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, v8 TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_VAR(t1);
				ZVAL_STRING(t1, "", 1);
				PHALCON_INIT_VAR(r3);
				is_identical_function(r3, t1, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_NULL(t2);
				PHALCON_INIT_VAR(r4);
				is_identical_function(r4, t2, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(r5);
				ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
				if (zend_is_true(r5)) {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "NULL", 1);
					Z_ADDREF_P(t3);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, t3 TSRMLS_CC);
				} else {
					eval_int = phalcon_array_isset(v3, v7);
					if (eval_int) {
						Z_ADDREF_P(v8);
						PHALCON_SEPARATE_ARRAY(v5);
						phalcon_array_append(v5, v8 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r6);
						phalcon_array_fetch(&r6, v2, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (PHALCON_COMPARE_STRING(r6, "date")) {
							PHALCON_INIT_VAR(r7);
							PHALCON_INIT_VAR(t4);
							phalcon_read_property(&t4, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
							Z_ADDREF_P(v8);
							p2[0] = v8;
							PHALCON_CALL_METHOD_PARAMS(r7, t4, "getdateusingformat", 1, p2, PHALCON_CALL_DEFAULT);
							Z_DELREF_P(p2[0]);
							Z_ADDREF_P(r7);
							PHALCON_SEPARATE_ARRAY(v5);
							phalcon_array_append(v5, r7 TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(r8);
							PHALCON_CONCAT_BOTH(r8,  "'", v8, "'");
							Z_ADDREF_P(r8);
							PHALCON_SEPARATE_ARRAY(v5);
							phalcon_array_append(v5, r8 TSRMLS_CC);
						}
					}
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_7;
		fee_f9eb_7:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, this_ptr, "_getidentityfield", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v9, r9);
	if (zend_is_true(v9)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property_zval(&t5, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, t5);
		Z_ADDREF_P(v9);
		PHALCON_SEPARATE_ARRAY(v4);
		phalcon_array_append(v4, v9 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r10);
		Z_ADDREF_P(v10);
		PHALCON_CALL_FUNC_PARAMS_1(r10, "is_null", v10, 0x034);
		Z_DELREF_P(v10);
		PHALCON_INIT_VAR(t6);
		ZVAL_STRING(t6, "", 1);
		PHALCON_INIT_VAR(r11);
		is_identical_function(r11, t6, v10 TSRMLS_CC);
		PHALCON_INIT_VAR(r12);
		ZVAL_BOOL(r12, zend_is_true(r10) || zend_is_true(r11));
		if (zend_is_true(r12)) {
			PHALCON_INIT_VAR(t7);
			ZVAL_STRING(t7, "null", 1);
			Z_ADDREF_P(t7);
			PHALCON_SEPARATE_ARRAY(v5);
			phalcon_array_append(v5, t7 TSRMLS_CC);
		} else {
			Z_ADDREF_P(v10);
			PHALCON_SEPARATE_ARRAY(v5);
			phalcon_array_append(v5, v10 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r13);
	Z_ADDREF_P(v1);
	p5[0] = v1;
	Z_ADDREF_P(v5);
	p5[1] = v5;
	Z_ADDREF_P(v4);
	p5[2] = v4;
	PHALCON_CALL_METHOD_PARAMS(r13, v0, "insert", 3, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	Z_DELREF_P(p5[1]);
	Z_DELREF_P(p5[2]);
	PHALCON_RETURN_DZVAL(r13);
}

PHP_METHOD(Phalcon_Model_Base, _doLowUpdate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(v5, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getnonprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r0);
	if (Z_TYPE_P(v6) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v6);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_8;
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_ZVAL(v7, *hd, 1, 0);
		Z_ADDREF_P(v7);
		PHALCON_SEPARATE_ARRAY(v4);
		phalcon_array_append(v4, v7 TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t0);
		if (Z_TYPE_P(v8) == IS_OBJECT) {
			PHALCON_INIT_VAR(r1);
			phalcon_instance_of(r1, v8, phalcon_db_rawvalue_class_entry TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_METHOD(r2, v8, "getvalue", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r2);
				PHALCON_SEPARATE_ARRAY(v5);
				phalcon_array_append(v5, r2 TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(t1);
				phalcon_read_property_zval(&t1, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				convert_to_string(t1);
				Z_ADDREF_P(t1);
				PHALCON_SEPARATE_ARRAY(v5);
				phalcon_array_append(v5, t1 TSRMLS_CC);
			}
		} else {
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			PHALCON_INIT_VAR(r3);
			is_identical_function(r3, t2, v8 TSRMLS_CC);
			PHALCON_INIT_VAR(t3);
			ZVAL_NULL(t3);
			PHALCON_INIT_VAR(r4);
			is_identical_function(r4, t3, v8 TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
			if (zend_is_true(r5)) {
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "NULL", 1);
				Z_ADDREF_P(t4);
				PHALCON_SEPARATE_ARRAY(v5);
				phalcon_array_append(v5, t4 TSRMLS_CC);
			} else {
				eval_int = phalcon_array_isset(v3, v7);
				if (eval_int) {
					Z_ADDREF_P(v8);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, v8 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r6);
					phalcon_array_fetch(&r6, v2, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r6, "date")) {
						PHALCON_INIT_VAR(r7);
						Z_ADDREF_P(v8);
						p2[0] = v8;
						PHALCON_CALL_METHOD_PARAMS(r7, v0, "getdateusingformat", 1, p2, PHALCON_CALL_DEFAULT);
						Z_DELREF_P(p2[0]);
						Z_ADDREF_P(r7);
						PHALCON_SEPARATE_ARRAY(v5);
						phalcon_array_append(v5, r7 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r8);
						PHALCON_CONCAT_BOTH(r8,  "'", v8, "'");
						Z_ADDREF_P(r8);
						PHALCON_SEPARATE_ARRAY(v5);
						phalcon_array_append(v5, r8 TSRMLS_CC);
					}
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_8;
		fee_f9eb_8:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r9);
	Z_ADDREF_P(v1);
	p3[0] = v1;
	Z_ADDREF_P(v4);
	p3[1] = v4;
	Z_ADDREF_P(v5);
	p3[2] = v5;
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t5);
	p3[3] = t5;
	PHALCON_CALL_METHOD_PARAMS(r9, v0, "update", 4, p3, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p3[0]);
	Z_DELREF_P(p3[1]);
	Z_DELREF_P(p3[2]);
	Z_DELREF_P(p3[3]);
	PHALCON_RETURN_DZVAL(r9);
}

/**
 * Inserts or updates a model instance. Returns true on success or else false .
 *
 * 
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, save){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p2[] = { NULL, NULL }, *p8[] = { NULL, NULL, NULL, NULL }, *p9[] = { NULL, NULL, NULL, NULL }, *p13[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_exists", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	if (!zend_is_true(v0)) {
		phalcon_update_property_long(this_ptr, "_operationMade", strlen("_operationMade"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, "_operationMade", strlen("_operationMade"), 2 TSRMLS_CC);
	}
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	Z_ADDREF_P(v0);
	p2[1] = v0;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_presave", 2, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v3, r3);
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_VBOTH(r4, v2, ".", v3);
		PHALCON_CPY_WRT(v4, r4);
	} else {
		PHALCON_CPY_WRT(v4, v3);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t1);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r5);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v7, r6);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v8, r7);
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		Z_ADDREF_P(v5);
		p8[0] = v5;
		Z_ADDREF_P(v4);
		p8[1] = v4;
		Z_ADDREF_P(v6);
		p8[2] = v6;
		Z_ADDREF_P(v8);
		p8[3] = v8;
		PHALCON_CALL_METHOD_PARAMS(r8, this_ptr, "_dolowupdate", 4, p8, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p8[0]);
		Z_DELREF_P(p8[1]);
		Z_DELREF_P(p8[2]);
		Z_DELREF_P(p8[3]);
		PHALCON_CPY_WRT(v9, r8);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r9);
		Z_ADDREF_P(v5);
		p9[0] = v5;
		Z_ADDREF_P(v4);
		p9[1] = v4;
		Z_ADDREF_P(v6);
		p9[2] = v6;
		Z_ADDREF_P(v8);
		p9[3] = v8;
		PHALCON_CALL_METHOD_PARAMS(r9, this_ptr, "_dolowinsert", 4, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		Z_DELREF_P(p9[1]);
		Z_DELREF_P(p9[2]);
		Z_DELREF_P(p9[3]);
		PHALCON_CPY_WRT(v9, r9);
	}
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CALL_METHOD(r10, v5, "isundertransaction", PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r10)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, v5, "gethaveautocommit", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r11)) {
			PHALCON_CALL_METHOD_NORETURN(v5, "commit", PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r12);
	Z_ADDREF_P(v1);
	p13[0] = v1;
	Z_ADDREF_P(v9);
	p13[1] = v9;
	Z_ADDREF_P(v0);
	p13[2] = v0;
	PHALCON_CALL_METHOD_PARAMS(r12, this_ptr, "_postsave", 3, p13, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p13[0]);
	Z_DELREF_P(p13[1]);
	Z_DELREF_P(p13[2]);
	PHALCON_RETURN_DZVAL(r12);
}

/**
 * Deletes a model instance. Returns true on success or else false .
 *
 * 
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, delete){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, t1, ".", t2);
		PHALCON_CPY_WRT(v0, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t3);
	}
	phalcon_update_property_long(this_ptr, "_operationMade", strlen("_operationMade"), 3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", v1, 0x007);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, r2, t4 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_long(&r4, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_read_property_zval(&t5, this_ptr, r4, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, t5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_long(&r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, " = '", v2);
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_RIGHT(r7, r5, "'");
		PHALCON_CPY_WRT(v3, r7);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_9:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_9;
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			PHALCON_INIT_VAR(t6);
			phalcon_read_property_zval(&t6, this_ptr, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, t6);
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_VBOTH(r8, v4, " = '", v2);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r8, "'");
			Z_ADDREF_P(r9);
			PHALCON_SEPARATE_ARRAY(v3);
			phalcon_array_append(v3, r9 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_9;
			fee_f9eb_9:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r10, "join", c0, v3, 0x00D);
		PHALCON_CPY_WRT(v3, r10);
	}
	t7 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t7);
	if (!zend_is_true(v5)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "beforeDelete", 1);
		PHALCON_CALL_METHOD_PARAMS(r11, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p5[0] = v0;
	Z_ADDREF_P(v3);
	p5[1] = v3;
	PHALCON_CALL_METHOD_PARAMS(r12, t8, "delete", 2, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	Z_DELREF_P(p5[1]);
	PHALCON_CPY_WRT(v6, r12);
	if (zend_is_true(v6)) {
		if (!zend_is_true(v5)) {
			PHALCON_INIT_VAR(p6[0]);
			ZVAL_STRING(p6[0], "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_RETURN_CHECK_CTOR(v6);
}

/**
 * Reads an attribute value by its name
 *
 * 
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Model_Base, readAttribute){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dump", sizeof("_dump")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property_zval(&t1, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Writes an attribute value by its name
 *
 * 
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Model_Base, writeAttribute){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Setup a 1-1 relation between two models
 *
 *
 *
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Base, hasOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p0[0] = this_ptr;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		Z_ADDREF_P(v1);
		p0[2] = v1;
		Z_ADDREF_P(v2);
		p0[3] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasone", 4, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_DELREF_P(p0[2]);
		Z_DELREF_P(p0[3]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *
 *
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Base, belongsTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p0[0] = this_ptr;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		Z_ADDREF_P(v1);
		p0[2] = v1;
		Z_ADDREF_P(v2);
		p0[3] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addbelongsto", 4, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_DELREF_P(p0[2]);
		Z_DELREF_P(p0[3]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Setup a relation 1-n between two models
     *
 *
 *
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Base, hasMany){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p0[0] = this_ptr;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		Z_ADDREF_P(v1);
		p0[2] = v1;
		Z_ADDREF_P(v2);
		p0[3] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasmany", 4, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_DELREF_P(p0[2]);
		Z_DELREF_P(p0[3]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Handles methods when a method does not exist
 *
 * @paramstring $method
 * @paramarray $arguments
 * @returnmixed
 * @throwsPhalcon_Model_Exception
 */
PHP_METHOD(Phalcon_Model_Base, __call){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL, *a8 = NULL, *a9 = NULL, *a10 = NULL, *a11 = NULL, *a12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p10[] = { NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p17[] = { NULL, NULL }, *p20[] = { NULL, NULL }, *p23[] = { NULL, NULL }, *p26[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_LONG(p0[1], 0);
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_LONG(p0[2], 3);
	PHALCON_CALL_FUNC_PARAMS(r0, "substr", 3, p0, 0x002);
	Z_DELREF_P(p0[0]);
	if (PHALCON_COMPARE_STRING(r0, "get")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x01F);
		PHALCON_CPY_WRT(v2, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		PHALCON_INIT_VAR(c0);
		ZVAL_LONG(c0, 3);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "substr", v0, c0, 0x002);
		Z_DELREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r2, "ucfirst", r3, 0x035);
		PHALCON_CPY_WRT(v3, r2);
		t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		Z_ADDREF_P(v2);
		p4[0] = v2;
		Z_ADDREF_P(v3);
		p4[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r4, v4, "existsbelongsto", 2, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		Z_DELREF_P(p4[1]);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			add_next_index_stringl(a1, "findFirst", strlen("findFirst"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, this_ptr);
			PHALCON_CPY_WRT(v5, a1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a2);
			add_next_index_zval(a2, v4);
			add_next_index_stringl(a2, "getBelongsToRecords", strlen("getBelongsToRecords"), 1);
			Z_ADDREF_P(a2);
			PHALCON_ALLOC_ZVAL_MM(r6);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r6, "array_merge", v5, v1, 0x036);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r6);
			PHALCON_CALL_FUNC_PARAMS_2(r5, "call_user_func_array", a2, r6, 0x010);
			Z_DELREF_P(a2);
			Z_DELREF_P(r6);
			PHALCON_RETURN_DZVAL(r5);
		}
		PHALCON_ALLOC_ZVAL_MM(r7);
		Z_ADDREF_P(v2);
		p7[0] = v2;
		Z_ADDREF_P(v3);
		p7[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r7, v4, "existshasmany", 2, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		Z_DELREF_P(p7[1]);
		if (zend_is_true(r7)) {
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			add_next_index_stringl(a3, "find", strlen("find"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a3);
			add_next_index_zval(a3, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a3);
			add_next_index_zval(a3, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a3);
			add_next_index_zval(a3, this_ptr);
			PHALCON_CPY_WRT(v5, a3);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a4);
			add_next_index_zval(a4, v4);
			add_next_index_stringl(a4, "getHasManyRecords", strlen("getHasManyRecords"), 1);
			Z_ADDREF_P(a4);
			PHALCON_ALLOC_ZVAL_MM(r9);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r9, "array_merge", v5, v1, 0x036);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r9);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "call_user_func_array", a4, r9, 0x010);
			Z_DELREF_P(a4);
			Z_DELREF_P(r9);
			PHALCON_RETURN_DZVAL(r8);
		}
		PHALCON_ALLOC_ZVAL_MM(r10);
		Z_ADDREF_P(v2);
		p10[0] = v2;
		Z_ADDREF_P(v3);
		p10[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r10, v4, "existshasone", 2, p10, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p10[0]);
		Z_DELREF_P(p10[1]);
		if (zend_is_true(r10)) {
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			add_next_index_stringl(a5, "findFirst", strlen("findFirst"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a5);
			add_next_index_zval(a5, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a5);
			add_next_index_zval(a5, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a5);
			add_next_index_zval(a5, this_ptr);
			PHALCON_CPY_WRT(v5, a5);
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a6);
			add_next_index_zval(a6, v4);
			add_next_index_stringl(a6, "getHasOneRecords", strlen("getHasOneRecords"), 1);
			Z_ADDREF_P(a6);
			PHALCON_ALLOC_ZVAL_MM(r12);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r12, "array_merge", v5, v1, 0x036);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r12);
			PHALCON_CALL_FUNC_PARAMS_2(r11, "call_user_func_array", a6, r12, 0x010);
			Z_DELREF_P(a6);
			Z_DELREF_P(r12);
			PHALCON_RETURN_DZVAL(r11);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r13);
	Z_ADDREF_P(v0);
	p13[0] = v0;
	PHALCON_INIT_VAR(p13[1]);
	ZVAL_LONG(p13[1], 0);
	PHALCON_INIT_VAR(p13[2]);
	ZVAL_LONG(p13[2], 5);
	PHALCON_CALL_FUNC_PARAMS(r13, "substr", 3, p13, 0x002);
	Z_DELREF_P(p13[0]);
	if (PHALCON_COMPARE_STRING(r13, "count")) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_FUNC_PARAMS_1(r14, "get_class", this_ptr, 0x01F);
		PHALCON_CPY_WRT(v2, r14);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_ALLOC_ZVAL_MM(r16);
		Z_ADDREF_P(v0);
		PHALCON_INIT_VAR(c1);
		ZVAL_LONG(c1, 5);
		PHALCON_CALL_FUNC_PARAMS_2(r16, "substr", v0, c1, 0x002);
		Z_DELREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r15, "ucfirst", r16, 0x035);
		PHALCON_CPY_WRT(v3, r15);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t1);
		PHALCON_ALLOC_ZVAL_MM(r17);
		Z_ADDREF_P(v2);
		p17[0] = v2;
		Z_ADDREF_P(v3);
		p17[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r17, v4, "existsbelongsto", 2, p17, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p17[0]);
		Z_DELREF_P(p17[1]);
		if (zend_is_true(r17)) {
			PHALCON_INIT_VAR(a7);
			array_init(a7);
			add_next_index_stringl(a7, "count", strlen("count"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a7);
			add_next_index_zval(a7, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a7);
			add_next_index_zval(a7, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a7);
			add_next_index_zval(a7, this_ptr);
			PHALCON_CPY_WRT(v5, a7);
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_INIT_VAR(a8);
			array_init(a8);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a8);
			add_next_index_zval(a8, v4);
			add_next_index_stringl(a8, "getBelongsToRecords", strlen("getBelongsToRecords"), 1);
			Z_ADDREF_P(a8);
			PHALCON_ALLOC_ZVAL_MM(r19);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r19, "array_merge", v5, v1, 0x036);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r19);
			PHALCON_CALL_FUNC_PARAMS_2(r18, "call_user_func_array", a8, r19, 0x010);
			Z_DELREF_P(a8);
			Z_DELREF_P(r19);
			PHALCON_RETURN_DZVAL(r18);
		}
		PHALCON_ALLOC_ZVAL_MM(r20);
		Z_ADDREF_P(v2);
		p20[0] = v2;
		Z_ADDREF_P(v3);
		p20[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r20, v4, "existshasmany", 2, p20, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p20[0]);
		Z_DELREF_P(p20[1]);
		if (zend_is_true(r20)) {
			PHALCON_INIT_VAR(a9);
			array_init(a9);
			add_next_index_stringl(a9, "count", strlen("count"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a9);
			add_next_index_zval(a9, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a9);
			add_next_index_zval(a9, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a9);
			add_next_index_zval(a9, this_ptr);
			PHALCON_CPY_WRT(v5, a9);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_INIT_VAR(a10);
			array_init(a10);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a10);
			add_next_index_zval(a10, v4);
			add_next_index_stringl(a10, "getHasManyRecords", strlen("getHasManyRecords"), 1);
			Z_ADDREF_P(a10);
			PHALCON_ALLOC_ZVAL_MM(r22);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r22, "array_merge", v5, v1, 0x036);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r22);
			PHALCON_CALL_FUNC_PARAMS_2(r21, "call_user_func_array", a10, r22, 0x010);
			Z_DELREF_P(a10);
			Z_DELREF_P(r22);
			PHALCON_RETURN_DZVAL(r21);
		}
		PHALCON_ALLOC_ZVAL_MM(r23);
		Z_ADDREF_P(v2);
		p23[0] = v2;
		Z_ADDREF_P(v3);
		p23[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r23, v4, "existshasone", 2, p23, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p23[0]);
		Z_DELREF_P(p23[1]);
		if (zend_is_true(r23)) {
			PHALCON_INIT_VAR(a11);
			array_init(a11);
			add_next_index_stringl(a11, "count", strlen("count"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a11);
			add_next_index_zval(a11, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a11);
			add_next_index_zval(a11, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a11);
			add_next_index_zval(a11, this_ptr);
			PHALCON_CPY_WRT(v5, a11);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_INIT_VAR(a12);
			array_init(a12);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a12);
			add_next_index_zval(a12, v4);
			add_next_index_stringl(a12, "getHasOneRecords", strlen("getHasOneRecords"), 1);
			Z_ADDREF_P(a12);
			PHALCON_ALLOC_ZVAL_MM(r25);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r25, "array_merge", v5, v1, 0x036);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r25);
			PHALCON_CALL_FUNC_PARAMS_2(r24, "call_user_func_array", a12, r25, 0x010);
			Z_DELREF_P(a12);
			Z_DELREF_P(r25);
			PHALCON_RETURN_DZVAL(r24);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_ALLOC_ZVAL_MM(r27);
	PHALCON_CONCAT_LEFT(r27, "Method \"", v0);
	PHALCON_ALLOC_ZVAL_MM(r28);
	PHALCON_CALL_FUNC_PARAMS_1(r28, "get_class", this_ptr, 0x01F);
	PHALCON_ALLOC_ZVAL_MM(r26);
	PHALCON_CONCAT_VBOTH(r26, r27, "\" doesn't exist on model \"", r28);
	PHALCON_ALLOC_ZVAL_MM(r29);
	PHALCON_CONCAT_RIGHT(r29, r26, "\"");
	Z_ADDREF_P(r29);
	p26[0] = r29;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p26, PHALCON_CALL_CHECK);
	Z_DELREF_P(p26[0]);
	return phalcon_throw_exception(i0 TSRMLS_CC);
}

/**
 * Phalcon_Model_Validator constructor
 *
 * @param Phalcon_Model_Base $record
 * @param string $field
 * @param string $value
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Validator, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_validator_class_entry, this_ptr, "_options", strlen("_options"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_validator_class_entry, this_ptr, "_messages", strlen("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v3) {
		PHALCON_INIT_VAR(a2);
		array_init(a2);
		PHALCON_CPY_WRT(v3, a2);
	}
	
	phalcon_update_property_zval(this_ptr, "_record", strlen("_record"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_fieldName", strlen("_fieldName"), v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_value", strlen("_value"), v2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_options", strlen("_options"), v3 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Appends a message to the validator
 *
 * @param string $message
 * @param string $field
 * @param string $type
 */
PHP_METHOD(Phalcon_Model_Validator, appendMessage){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v2);
	}
	
	if (PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_fieldName", sizeof("_fieldName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t0);
	}
	if (PHALCON_COMPARE_STRING(v2, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Validator", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_STRING(p0[1], "", 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x01F);
		p0[2] = r1;
		PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x003);
		PHALCON_CPY_WRT(v2, r0);
	}
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_message_class_entry);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(i0);
	phalcon_array_append(t1, i0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), t1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns messages generated by the validator
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Validator, getMessages){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Check whether option "required" has been passed as option
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator, isRequired){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_BOOL(v0, 1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "", 1);
	PHALCON_INIT_VAR(r0);
	is_identical_function(r0, t1, t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_NULL(t3);
	PHALCON_INIT_VAR(r1);
	is_identical_function(r1, t3, t2 TSRMLS_CC);
	PHALCON_INIT_VAR(r2);
	ZVAL_BOOL(r2, zend_is_true(r0) || zend_is_true(r1));
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset_string(t4, "required", strlen("required")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, t5, "required", strlen("required"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v0, r3);
		}
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns all the options from the validator
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Validator, getOptions){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns an option
 *
 * @paramstring $option
 * @returnmixed
 */
PHP_METHOD(Phalcon_Model_Validator, getOption){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch(&r2, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		r0 = r2;
	} else {
		PHALCON_INIT_VAR(t2);
		ZVAL_STRING(t2, "", 1);
		r0 = t2;
	}
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Check whether a option has been defined in the validator options
 *
 * @paramstring $option
 * @returnboolean
 */
PHP_METHOD(Phalcon_Model_Validator, isSetOption){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 1);
		r0 = t1;
	} else {
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, 0);
		r0 = t2;
	}
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Returns the value of the validated field
 *
 * @returnmixed
 */
PHP_METHOD(Phalcon_Model_Validator, getValue){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Devuelve el nombre del campo validado
 *
 * @access protected
 * @return string
 */
PHP_METHOD(Phalcon_Model_Validator, getFieldName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fieldName", sizeof("_fieldName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns Phalcon_Model_Base related record
 *
 * @return ActiveRecord
 */
PHP_METHOD(Phalcon_Model_Validator, getRecord){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_record", sizeof("_record")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * This method can be overridden to implement specific option validations for the validator
 *
 */
PHP_METHOD(Phalcon_Model_Validator, checkOptions){


	
}

/**
 * Phalcon_Model_Row
 *
 * This component allows to Phalcon_Model_Base returns grouped resultsets.
 */

PHP_METHOD(Phalcon_Model_Row, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_row_class_entry, this_ptr, "_columns", strlen("_columns"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Overwrittes default connection
 *
 * @param Phalcon_Db $connection
 */
PHP_METHOD(Phalcon_Model_Row, setConnection){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns default connection
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Row, getConnection){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Assigns values to a row from an array returning a new row
 *
 *
 *
 * @param array $result
 * @return Phalcon_Model $result
 */
PHP_METHOD(Phalcon_Model_Row, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	phalcon_clone(i0, this_ptr TSRMLS_CC);
	PHALCON_CPY_WRT(v1, i0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
		if (Z_TYPE_P(v0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_47c8_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_47c8_0;
			} else {
				PHALCON_INIT_VAR(v4);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v4, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v4, num);
					}
				}
			}
			PHALCON_INIT_VAR(v3);
			ZVAL_ZVAL(v3, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			ZVAL_BOOL(t2, 1);
			Z_ADDREF_P(t2);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update(v2, v4, t2 TSRMLS_CC);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v4), Z_STRLEN_P(v4), v3 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_47c8_0;
			fee_47c8_0:
			if(0){ };
		}
		phalcon_update_property_zval(v1, "_columns", strlen("_columns"), v2 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), v2 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(v0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v0);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_47c8_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_47c8_1;
			} else {
				PHALCON_INIT_VAR(v4);
				htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v4, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v4, num);
					}
				}
			}
			PHALCON_INIT_VAR(v3);
			ZVAL_ZVAL(v3, *hd, 1, 0);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v4), Z_STRLEN_P(v4), v3 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_47c8_1;
			fee_47c8_1:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(v1, "_columns", strlen("_columns"), t3 TSRMLS_CC);
	}
	PHALCON_RETURN_CHECK_CTOR(v1);
}

/**
 * Reads an attribute value by its name
 *
 * 
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Model_Row, readAttribute){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property_zval(&t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Magic method sleep
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Row, sleep){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "_columns", strlen("_columns"), 1);
	PHALCON_RETURN_CTOR(a0);
}

/**
 * Phalcon_Model_MetaData
 *
 * Because Phalcon_Model requires meta-data like field names, data types, primary keys, etc.
 * Phalcon_Model_MetaData recopiles them and store for further querying by Phalcon_Model_Base.
 * This component can also use adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon_Model_MetaData can be used to query model attributes:
 *
 * 
 *
 */

/**
 * Phalcon_Model_MetaData constructor
 *
 * @param string $adapter
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p4[] = { NULL };
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Model_MetaData_", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v2, 0x00F);
	Z_DELREF_P(v2);
	if (zend_is_true(r1)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v3, i0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, v3, "read", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), r2 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), v3 TSRMLS_CC);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(this_ptr);
		PHALCON_SEPARATE_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		add_next_index_stringl(a1, "storeMetaData", strlen("storeMetaData"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a1, 0x037);
	} else {
		ce1 = zend_fetch_class("phacon_model_exception", strlen("phacon_model_exception"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, ce1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "Meta-data adapter '", v0, "' could not found");
		Z_ADDREF_P(r3);
		p4[0] = r3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL, *v17 = NULL, *v18 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, v2, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v3);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, v0, "isview", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r3);
		if (!zend_is_true(v5)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			Z_ADDREF_P(v1);
			p2[0] = v1;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r4, v4, "tableexists", 2, p2, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p2[0]);
			Z_DELREF_P(p2[1]);
			PHALCON_CPY_WRT(v6, r4);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r5);
			Z_ADDREF_P(v1);
			p3[0] = v1;
			Z_ADDREF_P(v2);
			p3[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r5, v4, "viewexists", 2, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			Z_DELREF_P(p3[1]);
			PHALCON_CPY_WRT(v6, r5);
		}
		if (!zend_is_true(v6)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_LEFT(r8, "Table \"", v2);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_VBOTH(r7, r8, "\".\"", v1);
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CALL_FUNC_PARAMS_1(r9, "get_class", v0, 0x01F);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_VBOTH(r6, r7, "\" doesn't exist on database when dumping information for ", r9);
			Z_ADDREF_P(r6);
			p4[0] = r6;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		} else {
			if (zend_is_true(v5)) {
				PHALCON_ALLOC_ZVAL_MM(r10);
				Z_ADDREF_P(v1);
				p6[0] = v1;
				Z_ADDREF_P(v2);
				p6[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r10, v4, "describeview", 2, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				Z_DELREF_P(p6[1]);
				PHALCON_CPY_WRT(v7, r10);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r11);
				Z_ADDREF_P(v1);
				p7[0] = v1;
				Z_ADDREF_P(v2);
				p7[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r11, v4, "describetable", 2, p7, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p7[0]);
				Z_DELREF_P(p7[1]);
				PHALCON_CPY_WRT(v7, r11);
			}
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			PHALCON_CPY_WRT(v8, a0);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v9, a1);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			PHALCON_CPY_WRT(v10, a2);
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			PHALCON_CPY_WRT(v11, a3);
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			PHALCON_CPY_WRT(v12, a4);
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			PHALCON_CPY_WRT(v13, a5);
			PHALCON_INIT_VAR(v14);
			ZVAL_BOOL(v14, 0);
			if (Z_TYPE_P(v7) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v7);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f5c6_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f5c6_0;
				}
				PHALCON_INIT_VAR(v15);
				ZVAL_ZVAL(v15, *hd, 1, 0);
				PHALCON_INIT_VAR(r12);
				phalcon_array_fetch_string(&r12, v15, "Field", strlen("Field"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v16, r12);
				Z_ADDREF_P(v16);
				PHALCON_SEPARATE_ARRAY(v8);
				phalcon_array_append(v8, v16 TSRMLS_CC);
				PHALCON_INIT_VAR(r13);
				phalcon_array_fetch_string(&r13, v15, "Key", strlen("Key"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r13, "PRI")) {
					Z_ADDREF_P(v16);
					PHALCON_SEPARATE_ARRAY(v9);
					phalcon_array_append(v9, v16 TSRMLS_CC);
				} else {
					Z_ADDREF_P(v16);
					PHALCON_SEPARATE_ARRAY(v10);
					phalcon_array_append(v10, v16 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch_string(&r14, v15, "Type", strlen("Type"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v17, r14);
				Z_ADDREF_P(v17);
				if (Z_REFCOUNT_P(v13) > 1) {
					zval *new_zv;
					Z_DELREF_P(v13);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v13);
					v13 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update(v13, v16, v17 TSRMLS_CC);
				PHALCON_INIT_VAR(r15);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "int", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r15, "strpos", v17, c0, 0x00A);
				if (Z_TYPE_P(r15) != IS_BOOL || (Z_TYPE_P(r15) == IS_BOOL && Z_BVAL_P(r15))) {
					PHALCON_INIT_VAR(t1);
					ZVAL_BOOL(t1, 1);
					Z_ADDREF_P(t1);
					if (Z_REFCOUNT_P(v11) > 1) {
						zval *new_zv;
						Z_DELREF_P(v11);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v11);
						v11 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v11, v16, t1 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r16);
					PHALCON_INIT_VAR(c1);
					ZVAL_STRING(c1, "decimal", 1);
					PHALCON_CALL_FUNC_PARAMS_2(r16, "strpos", v17, c1, 0x00A);
					if (Z_TYPE_P(r16) != IS_BOOL || (Z_TYPE_P(r16) == IS_BOOL && Z_BVAL_P(r16))) {
						PHALCON_INIT_VAR(t2);
						ZVAL_BOOL(t2, 1);
						Z_ADDREF_P(t2);
						if (Z_REFCOUNT_P(v11) > 1) {
							zval *new_zv;
							Z_DELREF_P(v11);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v11);
							v11 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v11, v16, t2 TSRMLS_CC);
					}
				}
				PHALCON_INIT_VAR(r17);
				phalcon_array_fetch_string(&r17, v15, "Null", strlen("Null"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r17, "NO")) {
					Z_ADDREF_P(v16);
					PHALCON_SEPARATE_ARRAY(v12);
					phalcon_array_append(v12, v16 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r18);
				phalcon_array_fetch_string(&r18, v15, "Extra", strlen("Extra"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r18, "auto_increment")) {
					PHALCON_CPY_WRT(v14, v16);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f5c6_0;
				fee_f5c6_0:
				if(0){ };
			}
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			PHALCON_CPY_WRT(v18, a6);
			Z_ADDREF_P(v8);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 0, v8 TSRMLS_CC);
			Z_ADDREF_P(v9);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 1, v9 TSRMLS_CC);
			Z_ADDREF_P(v10);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 2, v10 TSRMLS_CC);
			Z_ADDREF_P(v12);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 3, v12 TSRMLS_CC);
			Z_ADDREF_P(v13);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 4, v13 TSRMLS_CC);
			Z_ADDREF_P(v11);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 5, v11 TSRMLS_CC);
			Z_ADDREF_P(v14);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 8, v14 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v18);
			phalcon_array_update(t3, v3, v18 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), t3 TSRMLS_CC);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns table attributes names (fields)
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns table attributes which are part of primary key
 *
 * @paramPhalcon_Model_Base $model
 * @returnarray
 */
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns table attributes which are not part of primary key
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns not null attributes
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 3, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns attributes and their data types
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns attributes which types are numerical
 *
     * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 5, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns the name of identity field (if one is present)
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getIdentityField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 8, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/** 
 * Stores meta-data using an adapter
 */
PHP_METHOD(Phalcon_Model_MetaData, storeMetaData){

	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "write", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Model_Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 * 
 *
 */

/**
     * Phalcon_Model_Message message
     *
     * @param string $message
     * @param string $field
     * @param string $type
     */
PHP_METHOD(Phalcon_Model_Message, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_NULL(v2);
	}
	
	phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_field", strlen("_field"), v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), v2 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Sets message type
     *
     * @param string $type
     */
PHP_METHOD(Phalcon_Model_Message, setType){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Returns message type
     *
     * @return string
     */
PHP_METHOD(Phalcon_Model_Message, getType){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
     * Sets verbose message
     *
     * @param string $message
     */
PHP_METHOD(Phalcon_Model_Message, setMessage){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Returns verbose message
     *
     * @return string
     */
PHP_METHOD(Phalcon_Model_Message, getMessage){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_message", sizeof("_message")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
     * Sets field name related to message
     *
     * @param string $field
     */
PHP_METHOD(Phalcon_Model_Message, setField){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_field", strlen("_field"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Returns field name related to message
     *
     * @return string
     */
PHP_METHOD(Phalcon_Model_Message, getField){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_field", sizeof("_field")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
     * Magic __toString method returns verbose message
     *
     * @return string
     */
PHP_METHOD(Phalcon_Model_Message, __toString){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_message", sizeof("_message")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
     * Magic __set_state helps to recover messsages from serialization
     *
     * @param array $message
     * @return Phalcon_Model_Message
     */
PHP_METHOD(Phalcon_Model_Message, __set_state){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_message_class_entry);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v0, "_message", strlen("_message"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r0);
	p0[0] = r0;
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, v0, "_field", strlen("_field"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r1);
	p0[1] = r1;
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, v0, "_type", strlen("_type"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[2] = r2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p0, PHALCON_CALL_CHECK);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_RETURN_CTOR(i0);
}

/**
 * Phalcon_Model_Manager
 *
 * Manages the creation of models inside application and their relationships.
 * Phacon_Model_Manager helps to control the creation of models across a request execution.
 *
 * 
 */

/**
 * Constructor for Phalcon_Model_Manager
     *
     * @param array $metaDataOptions
 */
PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL;
	zval *v0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_models", strlen("_models"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_hasMany", strlen("_hasMany"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_hasOne", strlen("_hasOne"), a2 TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_belongsTo", strlen("_belongsTo"), a3 TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_metadataOptions", strlen("_metadataOptions"), a4 TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(a6);
		array_init(a6);
		PHALCON_CPY_WRT(v0, a6);
	}
	
	PHALCON_INIT_VAR(a7);
	array_init(a7);
	Z_ADDREF_P(this_ptr);
	PHALCON_SEPARATE_ARRAY(a7);
	add_next_index_zval(a7, this_ptr);
	add_next_index_stringl(a7, "autoload", strlen("autoload"), 1);
	Z_ADDREF_P(a7);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", a7, 0x000);
	Z_DELREF_P(a7);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes default meta-data manager
 *
 * @param Phalcon_Model_Metadata $metadata
 */
PHP_METHOD(Phalcon_Model_Manager, setMetaData){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Meta-data must be an object instance of Phalcon_Model_Metadata", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns active meta-data manager. If no exist then it will be created
 *
 * @return Phalcon_Model_Metadata
 */
PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_metadataOptions", sizeof("_metadataOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		eval_int = phalcon_array_isset_string(v0, "adapter", strlen("adapter")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, v0, "adapter", strlen("adapter"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r0);
		} else {
			PHALCON_INIT_VAR(v1);
			ZVAL_STRING(v1, "Memory", 1);
		}
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_metadata_class_entry);
		Z_ADDREF_P(v1);
		p0[0] = v1;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Sets the models directory
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Model_Manager, setModelsDir){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets active models directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Manager, getModelsDir){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Checks wheater given name is a existent model
 *
 * 
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, isModel){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		Z_ADDREF_P(v0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "class_exists", v0, c0, 0x00F);
		Z_DELREF_P(v0);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			concat_function(r1, t1, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_RIGHT(r2, r1, ".php");
			PHALCON_CPY_WRT(v1, r2);
			if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
				PHALCON_ALLOC_ZVAL_MM(r3);
				Z_ADDREF_P(v0);
				p1[0] = v0;
				PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "load", 1, p1, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p1[0]);
				PHALCON_RETURN_DZVAL(r3);
			} else {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Loads a model looking for its file and initializing them
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, load){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL };
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "class_exists", v0, c0, 0x00F);
		Z_DELREF_P(v0);
		if (!zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			concat_function(r2, t1, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CONCAT_RIGHT(r3, r2, ".php");
			PHALCON_CPY_WRT(v1, r3);
			if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
				phalcon_require(v1 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r4);
				Z_ADDREF_P(v0);
				PHALCON_INIT_VAR(c1);
				ZVAL_BOOL(c1, 0);
				PHALCON_CALL_FUNC_PARAMS_2(r4, "class_exists", v0, c1, 0x00F);
				Z_DELREF_P(v0);
				if (!zend_is_true(r4)) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					PHALCON_ALLOC_ZVAL_MM(r5);
					PHALCON_CONCAT_BOTH(r5,  "Class \"", v0, "\"  not be found in the model file");
					Z_ADDREF_P(r5);
					p2[0] = r5;
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
					Z_DELREF_P(p2[0]);
					return phalcon_throw_exception(i0 TSRMLS_CC);
				}
				ce0 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(i1);
				object_init_ex(i1, ce0);
				Z_ADDREF_P(this_ptr);
				p3[0] = this_ptr;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
				Z_DELREF_P(p3[0]);
				PHALCON_CPY_WRT(v2, i1);
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CALL_METHOD(r6, this_ptr, "getconnection", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r6);
				p4[0] = r6;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p4, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p4[0]);
				PHALCON_ALLOC_ZVAL_MM(t2);
				phalcon_read_property(&t2, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(v2);
				phalcon_array_update(t2, v0, v2 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t2 TSRMLS_CC);
			} else {
				PHALCON_ALLOC_ZVAL_MM(i2);
				object_init_ex(i2, phalcon_model_exception_class_entry);
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_BOTH(r7,  "Class file path for model \"", v0, "\" could not be found");
				Z_ADDREF_P(r7);
				p6[0] = r7;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p6, PHALCON_CALL_CHECK);
				Z_DELREF_P(p6[0]);
				return phalcon_throw_exception(i2 TSRMLS_CC);
			}
		} else {
			ce1 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, ce1);
			Z_ADDREF_P(this_ptr);
			p7[0] = this_ptr;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p7, PHALCON_CALL_CHECK);
			Z_DELREF_P(p7[0]);
			PHALCON_CPY_WRT(v2, i3);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD(r8, this_ptr, "getconnection", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r8);
			p8[0] = r8;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p8, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p8[0]);
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v2);
			phalcon_array_update(t3, v0, v2 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t3 TSRMLS_CC);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Gets/Instantiates model from directory
 *
 * 
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, getModel){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "load", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r1);
}

/**
 * Gets the posibly source model name from its class name
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, getSource){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "uncamelize", 1, p0);
		Z_DELREF_P(p0[0]);
		t2 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
		}
		Z_ADDREF_P(r0);
		phalcon_array_update(t2, v0, r0 TSRMLS_CC);
		zend_update_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, t2 TSRMLS_CC);
		
	}
	t3 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_array_fetch(&t4, t3, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t4);
}

/**
 * Gets default connection to database. All models by default will use connection returned by this method
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Manager, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL;
	zval *p4[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_transaction_manager", "isautomatic");
		if (zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "get");
			PHALCON_CALL_METHOD(r1, r2, "getconnection", PHALCON_CALL_DEFAULT);
			PHALCON_RETURN_DZVAL(r1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_STATIC(r3, "phalcon_db_pool", "hasdefaultdescriptor");
			if (!zend_is_true(r3)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_exception_class_entry);
				PHALCON_INIT_VAR(p4[0]);
				ZVAL_STRING(p4[0], "There is not defined database connection parameters", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
				return phalcon_throw_exception(i0 TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_STATIC(r4, "phalcon_db_pool", "getconnection");
			phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r4 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Setup a 1-1 relation between two models
 *
 * @param Phalcon_Model_Base $model
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Manager, addHasOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", v0, 0x01F);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(a0);
		phalcon_array_update(t1, v4, a0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasOne", strlen("_hasOne"), t1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r2, v2);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_FUNC_PARAMS_1(r4, "count", v1, 0x007);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v3, 0x007);
			PHALCON_INIT_VAR(r6);
			is_not_equal_function(r6, r4, r5 TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				PHALCON_INIT_VAR(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				return phalcon_throw_exception(i0 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "fi", v1);
		Z_ADDREF_P(v2);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "rt", v2);
		Z_ADDREF_P(v3);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "rf", v3);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_array_fetch(&t4, t3, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			zval *new_zv;
			Z_DELREF_P(t4);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t4);
			t4 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
		}
		Z_ADDREF_P(a1);
		phalcon_array_update(t4, v2, a1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasOne", strlen("_hasOne"), t3 TSRMLS_CC);
	} else {
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param Phalcon_Model_Base $model
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Manager, addBelongsTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", v0, 0x01F);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(a0);
		phalcon_array_update(t1, v4, a0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_belongsTo", strlen("_belongsTo"), t1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r2, v2);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_FUNC_PARAMS_1(r4, "count", v1, 0x007);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v3, 0x007);
			PHALCON_INIT_VAR(r6);
			is_not_equal_function(r6, r4, r5 TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				PHALCON_INIT_VAR(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				return phalcon_throw_exception(i0 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "fi", v1);
		Z_ADDREF_P(v2);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "rt", v2);
		Z_ADDREF_P(v3);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "rf", v3);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_array_fetch(&t4, t3, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			zval *new_zv;
			Z_DELREF_P(t4);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t4);
			t4 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
		}
		Z_ADDREF_P(a1);
		phalcon_array_update(t4, v2, a1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_belongsTo", strlen("_belongsTo"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Setup a relation 1-n between two models
 *
 * @param Phalcon_Model_Base $model
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Manager, addHasMany){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", v0, 0x01F);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(a0);
		phalcon_array_update(t1, v4, a0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasMany", strlen("_hasMany"), t1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r2, v2);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_FUNC_PARAMS_1(r4, "count", v1, 0x007);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v3, 0x007);
			PHALCON_INIT_VAR(r6);
			is_not_equal_function(r6, r4, r5 TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				PHALCON_INIT_VAR(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				return phalcon_throw_exception(i0 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "fi", v1);
		Z_ADDREF_P(v2);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "rt", v2);
		Z_ADDREF_P(v3);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "rf", v3);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_array_fetch(&t4, t3, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			zval *new_zv;
			Z_DELREF_P(t4);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t4);
			t4 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
		}
		Z_ADDREF_P(a1);
		phalcon_array_update(t4, v2, a1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasMany", strlen("_hasMany"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether a model have a belongsTo relation with other model
 *
 * @access public
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsBelongsTo){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model have a hasMany relation with other model
 *
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsHasMany){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model have a hasOne relation with other model
 * 
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsHasOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Helper method to query records based on a relation definition
 *
 * @param array $relation
 * @param string $method
 * @param Phalcon_Model_Base $record
 */
PHP_METHOD(Phalcon_Model_Manager, _getRelationRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r2);
		p0[0] = r2;
		PHALCON_CALL_METHOD_PARAMS(r1, v2, "readattribute", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v3, r1);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v0, "rf", strlen("rf"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_VBOTH(r3, r4, " = '", v3);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_RIGHT(r5, r3, "'");
		PHALCON_CPY_WRT(v4, r5);
	} else {
		PHALCON_INIT_VAR(v5);
		ZVAL_LONG(v5, 0);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v6, a0);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r6) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(r6);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_7231_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_7231_0;
			}
			PHALCON_INIT_VAR(v7);
			ZVAL_ZVAL(v7, *hd, 1, 0);
			PHALCON_INIT_VAR(r7);
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch_string(&r8, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r9);
			phalcon_array_fetch(&r9, r8, v5, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r9);
			p1[0] = r9;
			PHALCON_CALL_METHOD_PARAMS(r7, v2, "readattribute", 1, p1, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p1[0]);
			PHALCON_CPY_WRT(v3, r7);
			PHALCON_INIT_VAR(r11);
			phalcon_array_fetch_string(&r11, v0, "rf", strlen("rf"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r12);
			phalcon_array_fetch(&r12, r11, v5, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r10);
			PHALCON_CONCAT_VBOTH(r10, r12, " = '", v3);
			PHALCON_INIT_VAR(r13);
			PHALCON_CONCAT_RIGHT(r13, r10, "'");
			Z_ADDREF_P(r13);
			PHALCON_SEPARATE_ARRAY(v6);
			phalcon_array_append(v6, r13 TSRMLS_CC);
			PHALCON_SEPARATE(v5);
			increment_function(v5);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_7231_0;
			fee_7231_0:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r14, "join", c0, v6, 0x00D);
		PHALCON_CPY_WRT(v4, r14);
	}
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	Z_ADDREF_P(v4);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, v4);
	PHALCON_CPY_WRT(v8, a1);
	PHALCON_ALLOC_ZVAL_MM(r15);
	phalcon_array_fetch_string(&r15, v0, "rt", strlen("rt"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v9, r15);
	PHALCON_ALLOC_ZVAL_MM(r16);
	Z_ADDREF_P(v9);
	p3[0] = v9;
	PHALCON_CALL_METHOD_PARAMS(r16, this_ptr, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p3[0]);
	PHALCON_CPY_WRT(v10, r16);
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_CALL_METHOD(r17, v2, "getconnection", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r17);
	p4[0] = r17;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v10, "setconnection", 1, p4, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p4[0]);
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	Z_ADDREF_P(v10);
	PHALCON_SEPARATE_ARRAY(a2);
	add_next_index_zval(a2, v10);
	Z_ADDREF_P(v1);
	PHALCON_SEPARATE_ARRAY(a2);
	add_next_index_zval(a2, v1);
	Z_ADDREF_P(a2);
	Z_ADDREF_P(v8);
	PHALCON_CALL_FUNC_PARAMS_2(r18, "call_user_func_array", a2, v8, 0x010);
	Z_DELREF_P(a2);
	Z_DELREF_P(v8);
	PHALCON_RETURN_DZVAL(r18);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon_Model_Base $record
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getBelongsToRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		PHALCON_INIT_VAR(r1);
		ZVAL_BOOL(r1, eval_int);
		if (!zend_is_true(r1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, r2, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	Z_ADDREF_P(v3);
	p0[2] = v3;
	PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_RETURN_DZVAL(r4);
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon_Model_Base $record
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getHasManyRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		PHALCON_INIT_VAR(r1);
		ZVAL_BOOL(r1, eval_int);
		if (!zend_is_true(r1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, r2, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	Z_ADDREF_P(v3);
	p0[2] = v3;
	PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_RETURN_DZVAL(r4);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon_Model_Base $record
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getHasOneRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		PHALCON_INIT_VAR(r1);
		ZVAL_BOOL(r1, eval_int);
		if (!zend_is_true(r1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, r2, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	Z_ADDREF_P(v3);
	p0[2] = v3;
	PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_RETURN_DZVAL(r4);
}

/**
 * Autoload function for model lazy loading
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Model_Manager, autoload){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "ismodel", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Model_MetaData_Memory
 *
 * Stores model meta-data in memory. Data will be erased when the request finishes
 */

PHP_METHOD(Phalcon_Model_MetaData_Memory, read){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_RETURN_CTOR(a0);
}

PHP_METHOD(Phalcon_Model_MetaData_Memory, write){


	
}

/**
 * Phalcon_Model_MetaData_Session
 *
 * Stores model meta-data in session. Data will be erased when the session finishes.
 * Meta-data are permanent while the session is active
 */

PHP_METHOD(Phalcon_Model_MetaData_Session, __construct){


	
}

PHP_METHOD(Phalcon_Model_MetaData_Session, read){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_RETURN_CTOR(a0);
}

PHP_METHOD(Phalcon_Model_MetaData_Session, write){


	
}

/**
 * Phalcon_Model_Resultset
 *
 * This component allows to Phalcon_Model_Base returns large resulsets with the minimum memory comsuption
 *
 * Resulsets can be traversed using a standard foreach or a while statement.
 *
 * 
 *
 */

/**
 * Phalcon_Model_Resultset constructor
 *
 * @param Phalcon_Model_Base $model
 * @param resource $resultResource
 */
PHP_METHOD(Phalcon_Model_Resultset, __construct){

	zval *v0 = NULL, *v1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_get_class_constant(t2, phalcon_db_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
	Z_ADDREF_P(t2);
	p1[0] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t3);
	p2[0] = t3;
	PHALCON_CALL_METHOD_PARAMS(r1, v1, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	PHALCON_CPY_WRT(v2, r1);
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		Z_ADDREF_P(v2);
		p3[1] = v2;
		PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_model_base", "dumpresult", 2, p3);
		Z_DELREF_P(p3[0]);
		Z_DELREF_P(p3[1]);
		phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), r2 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_get_class_constant(t4, phalcon_db_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
		Z_ADDREF_P(t4);
		p4[0] = t4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, current){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeRow", sizeof("_activeRow")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, next){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets pointer number to active row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, key){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, rewind){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_INIT_VAR(p1[0]);
	ZVAL_LONG(p1[0], 0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	p1[1] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Changes interal pointer to a specifically position in the resultset
 */
PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	convert_to_long(v0);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	convert_to_long(v0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p1[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *v0 = NULL;
	zval *p2[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_null", t1, 0x034);
	Z_DELREF_P(t1);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, t2, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v0, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		PHALCON_CALL_METHOD_PARAMS(r2, v0, "numrows", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), r2 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t4);
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetExists){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, v0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets row in a specifically position of the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetGet){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, v0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			PHALCON_RETURN_DZVAL(r3);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "The index does not exist in the cursor", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetSet){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	return phalcon_throw_exception(i0 TSRMLS_CC);
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetUnset){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	return phalcon_throw_exception(i0 TSRMLS_CC);
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getFirst){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_BOOL || (Z_TYPE_P(t2) == IS_BOOL && Z_BVAL_P(t2))) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_METHOD(r2, this_ptr, "current", PHALCON_CALL_DEFAULT);
			PHALCON_RETURN_DZVAL(r2);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getLast){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_BOOL || (Z_TYPE_P(t0) == IS_BOOL && Z_BVAL_P(t0))) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		sub_function(r1, r0, t1 TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			PHALCON_RETURN_DZVAL(r3);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Get model which originates the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getModel){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Tag
 *
 * Phalcon_Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */

/**
 * Sets the request dispatcher. A valid dispatcher is required to generated absolute paths
 *
 * @param Phalcon_Dispatcher $dispatcher
 */
PHP_METHOD(Phalcon_Tag, setDispatcher){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Tag, _getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		PHALCON_CALL_METHOD(r0, r1, "getdispatcher", PHALCON_CALL_DEFAULT);
		zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, r0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Assigns default values to generated tags by helpers
 *
 * 
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, setDefault){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", v1, 0x038);
	Z_DELREF_P(v1);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_tag_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Only scalar values can be assigned to UI components", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	Z_ADDREF_P(v1);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Alias of Phalcon_Tag::setDefault
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, displayTo){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "setdefault", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Every helper call this function to check whether a component has a predefined
 * value using Phalcon_Tag::displayTo or value from $_POST
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, _getValueFromAction){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		t2 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_init_global("_POST", sizeof("_POST") TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					g0 = *gv0;
				} else {
					PHALCON_INIT_VAR(g0);
					array_init(g0);
				}
			}
		}
		if (!g0) {
			PHALCON_INIT_VAR(g0);
			array_init(g0);
		}
		eval_int = phalcon_array_isset(g0, v0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc", 0x039);
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch(&r1, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_ALLOC_ZVAL_MM(r3);
				phalcon_array_fetch(&r3, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r2, "stripslashes", r3, 0x03A);
				Z_DELREF_P(r3);
				PHALCON_RETURN_DZVAL(r2);
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Resets the request and internal values to avoid that fields will have any default value
 */
PHP_METHOD(Phalcon_Tag, resetInput){

	zval *a0 = NULL;
	zval *g0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval **gv0;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, a0 TSRMLS_CC);
	phalcon_init_global("_POST", sizeof("_POST") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	if (Z_TYPE_P(g0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(g0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_0;
		} else {
			PHALCON_INIT_VAR(v1);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v1, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v1, num);
				}
			}
		}
		PHALCON_INIT_VAR(v0);
		ZVAL_ZVAL(v0, *hd, 1, 0);
		phalcon_array_unset(g0, v1);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_0;
		fee_9b93_0:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Builds a HTML A tag using framework conventions
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "", 1);
	eval_int = phalcon_array_isset_long(v2, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r0);
	} else {
		eval_int = phalcon_array_isset_string(v2, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_string(&r1, v2, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r1);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "action", strlen("action")+1);
		}
	}
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "", 1);
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r2);
	} else {
		eval_int = phalcon_array_isset_string(v2, "text", strlen("text")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, v2, "text", strlen("text"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r3);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "text", strlen("text")+1);
		}
	}
	PHALCON_INIT_VAR(v4);
	ZVAL_STRING(v4, "", 1);
	if (!PHALCON_COMPARE_STRING(v3, "")) {
		eval_int = phalcon_array_isset_string(v2, "confirm", strlen("confirm")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset_string(v2, "onclick", strlen("onclick")+1);
			PHALCON_INIT_VAR(r4);
			ZVAL_BOOL(r4, eval_int);
			if (!zend_is_true(r4)) {
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				Z_ADDREF_P(t0);
				if (Z_REFCOUNT_P(v2) > 1) {
					zval *new_zv;
					Z_DELREF_P(v2);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v2);
					v2 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update_string(v2, "onclick", strlen("onclick"), t0 TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_array_fetch_string(&r6, v2, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_LEFT(r7, "if(!confirm('", r6);
			PHALCON_ALLOC_ZVAL_MM(r8);
			phalcon_array_fetch_string(&r8, v2, "onclick", strlen("onclick"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_VBOTH(r5, r7, "')) { return false; }; ", r8);
			Z_ADDREF_P(r5);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "onclick", strlen("onclick"), r5 TSRMLS_CC);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "confirm", strlen("confirm")+1);
		}
		PHALCON_ALLOC_ZVAL_MM(r9);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		PHALCON_CALL_STATIC_PARAMS(r9, "phalcon_utils", "geturl", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_BOTH(r10,  "<a href=\"", r9, "\" ");
		PHALCON_CPY_WRT(v4, r10);
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_9b93_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_9b93_1;
			} else {
				PHALCON_INIT_VAR(v6);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v6, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v6, num);
					}
				}
			}
			PHALCON_INIT_VAR(v5);
			ZVAL_ZVAL(v5, *hd, 1, 0);
			if (Z_TYPE_P(v6) != IS_LONG) {
				PHALCON_INIT_VAR(r12);
				PHALCON_CONCAT_LEFT(r12, " ", v6);
				PHALCON_INIT_VAR(r11);
				PHALCON_CONCAT_VBOTH(r11, r12, "=\"", v5);
				PHALCON_INIT_VAR(r13);
				PHALCON_CONCAT_RIGHT(r13, r11, "\" ");
				PHALCON_INIT_VAR(r14);
				concat_function(r14, v4, r13 TSRMLS_CC);
				PHALCON_CPY_WRT(v4, r14);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_9b93_1;
			fee_9b93_1:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CONCAT_BOTH(r15,  ">", v1, "</a>");
		PHALCON_ALLOC_ZVAL_MM(r16);
		concat_function(r16, v4, r15 TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r16);
	}
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Builds generic INPUT tags
 *
 * @param   string $type
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, _inputField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v1);
	}
	eval_int = phalcon_array_isset_long(v2, 0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v2, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v2, 0, r1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r2);
	eval_int = phalcon_array_isset_string(v2, "name", strlen("name")+1);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		Z_ADDREF_P(v3);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "name", strlen("name"), v3 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v2, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r4)) {
			Z_ADDREF_P(v3);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "name", strlen("name"), v3 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v2, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v2, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r5);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v4, r6);
	}
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_LEFT(r9, "<input type=\"", v0);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CONCAT_VBOTH(r8, r9, "\" id=\"", v3);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CONCAT_VBOTH(r7, r8, "\" value=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CONCAT_RIGHT(r10, r7, "\" ");
	PHALCON_CPY_WRT(v5, r10);
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_2;
		} else {
			PHALCON_INIT_VAR(v7);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v7, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v7, num);
				}
			}
		}
		PHALCON_INIT_VAR(v6);
		ZVAL_ZVAL(v6, *hd, 1, 0);
		if (Z_TYPE_P(v7) != IS_LONG) {
			PHALCON_INIT_VAR(r11);
			PHALCON_CONCAT_VBOTH(r11, v7, "=\"", v6);
			PHALCON_INIT_VAR(r12);
			PHALCON_CONCAT_RIGHT(r12, r11, "\" ");
			PHALCON_INIT_VAR(r13);
			concat_function(r13, v5, r12 TSRMLS_CC);
			PHALCON_CPY_WRT(v5, r13);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_2;
		fee_9b93_2:
		if(0){ };
	}
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL_MM(r14);
	concat_function(r14, v5, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r14);
	PHALCON_RETURN_CTOR(v5);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "text", 1);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_inputfield", 2, p0);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="password"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, passwordField){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "password", 1);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_inputfield", 2, p0);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, hiddenField){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "hidden", 1);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_inputfield", 2, p0);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="file"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, fileField){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "file", 1);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_inputfield", 2, p0);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="submit"] tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_string(v1, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "value", strlen("value")+1);
	} else {
		eval_int = phalcon_array_isset_long(v1, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r1);
		} else {
			PHALCON_INIT_VAR(v2);
			ZVAL_STRING(v2, "", 1);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_BOTH(r2,  "<input type=\"submit\" value=\"", v2, "\" ");
	PHALCON_CPY_WRT(v3, r2);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_3;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		if (Z_TYPE_P(v5) != IS_LONG) {
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_VBOTH(r3, v5, "=\"", v4);
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_RIGHT(r4, r3, "\" ");
			PHALCON_INIT_VAR(r5);
			concat_function(r5, v3, r4 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r5);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_3;
		fee_9b93_3:
		if(0){ };
	}
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	concat_function(r6, v3, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r6);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds a HTML SELECT tag using an array for options
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r0);
	eval_int = phalcon_array_isset_string(v2, "value", strlen("value")+1);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		Z_ADDREF_P(v4);
		p0[0] = v4;
		PHALCON_CALL_SELF_PARAMS(r2, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v3, r2);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v2, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_LEFT(r5, "<select id=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r5, "\" name=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_RIGHT(r6, r4, "\" ");
	PHALCON_CPY_WRT(v5, r6);
	eval_int = phalcon_array_isset_string(v2, "dummyValue", strlen("dummyValue")+1);
	PHALCON_INIT_VAR(r7);
	ZVAL_BOOL(r7, eval_int);
	if (!zend_is_true(r7)) {
		PHALCON_INIT_VAR(v6);
		ZVAL_STRING(v6, "@", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, v2, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r8);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v2, "dummyText", strlen("dummyText")+1);
	PHALCON_INIT_VAR(r9);
	ZVAL_BOOL(r9, eval_int);
	if (!zend_is_true(r9)) {
		PHALCON_INIT_VAR(v7);
		ZVAL_STRING(v7, "Choose...", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r10);
		phalcon_array_fetch_string(&r10, v2, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r10);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyText", strlen("dummyText")+1);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v8, t0);
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_4;
		} else {
			PHALCON_INIT_VAR(v10);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v10, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v10, num);
				}
			}
		}
		PHALCON_INIT_VAR(v9);
		ZVAL_ZVAL(v9, *hd, 1, 0);
		if (Z_TYPE_P(v10) != IS_LONG) {
			if (Z_TYPE_P(v9) != IS_ARRAY) { 
				PHALCON_INIT_VAR(r11);
				PHALCON_CONCAT_VBOTH(r11, v10, "=\"", v9);
				PHALCON_INIT_VAR(r12);
				PHALCON_CONCAT_RIGHT(r12, r11, "\" ");
				PHALCON_INIT_VAR(r13);
				concat_function(r13, v5, r12 TSRMLS_CC);
				PHALCON_CPY_WRT(v5, r13);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_4;
		fee_9b93_4:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_LEFT(r14, ">", v8);
	PHALCON_ALLOC_ZVAL_MM(r15);
	concat_function(r15, v5, r14 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r15);
	eval_int = phalcon_array_isset_string(v2, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_VBOTH(r18, t1, "<option value=\"", v6);
		PHALCON_ALLOC_ZVAL_MM(r17);
		PHALCON_CONCAT_VBOTH(r17, r18, "\">", v7);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_VBOTH(r16, r17, "</option>", v8);
		PHALCON_ALLOC_ZVAL_MM(r19);
		concat_function(r19, v5, r16 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r19);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "useDummy", strlen("useDummy")+1);
	}
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r20);
		phalcon_array_fetch_long(&r20, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r20);
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_9b93_5:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_9b93_5;
				} else {
					PHALCON_INIT_VAR(v12);
					htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
					if (htype == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(v12, index, index_len-1, 1);
					} else {
						if (htype == HASH_KEY_IS_LONG) {
							ZVAL_LONG(v12, num);
						}
					}
				}
				PHALCON_INIT_VAR(v11);
				ZVAL_ZVAL(v11, *hd, 1, 0);
				PHALCON_INIT_VAR(r21);
				is_equal_function(r21, v12, v3 TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_STRING(t2, "", 1);
				PHALCON_INIT_VAR(r22);
				is_not_identical_function(r22, t2, v3 TSRMLS_CC);
				PHALCON_INIT_VAR(r23);
				phalcon_and_function(r23, r21, r22);
				if (zend_is_true(r23)) {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "\t", 1);
					PHALCON_INIT_VAR(r26);
					PHALCON_CONCAT_VBOTH(r26, t3, "<option value=\"", v12);
					PHALCON_INIT_VAR(r25);
					PHALCON_CONCAT_VBOTH(r25, r26, "\" selected=\"selected\">", v11);
					PHALCON_INIT_VAR(r24);
					PHALCON_CONCAT_VBOTH(r24, r25, "</option>", v8);
					PHALCON_INIT_VAR(r27);
					concat_function(r27, v5, r24 TSRMLS_CC);
					PHALCON_CPY_WRT(v5, r27);
				} else {
					PHALCON_INIT_VAR(t4);
					ZVAL_STRING(t4, "\t", 1);
					PHALCON_INIT_VAR(r30);
					PHALCON_CONCAT_VBOTH(r30, t4, "<option value=\"", v12);
					PHALCON_INIT_VAR(r29);
					PHALCON_CONCAT_VBOTH(r29, r30, "\">", v11);
					PHALCON_INIT_VAR(r28);
					PHALCON_CONCAT_VBOTH(r28, r29, "</option>", v8);
					PHALCON_INIT_VAR(r31);
					concat_function(r31, v5, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(v5, r31);
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_9b93_5;
				fee_9b93_5:
				if(0){ };
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_tag_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "Data supplied to Phalcon_Tag::selectStatic is not valid", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(t5);
	ZVAL_STRING(t5, "</select>", 1);
	PHALCON_ALLOC_ZVAL_MM(r32);
	concat_function(r32, v5, t5 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r32);
	PHALCON_RETURN_CTOR(v5);
}

/**
 * Builds a HTML SELECT tag using a resultset as options
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, select){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r0);
	eval_int = phalcon_array_isset_string(v2, "value", strlen("value")+1);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		Z_ADDREF_P(v4);
		p0[0] = v4;
		PHALCON_CALL_SELF_PARAMS(r2, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v5, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v2, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_LEFT(r5, "<select id=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r5, "\" name=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_RIGHT(r6, r4, "\" ");
	PHALCON_CPY_WRT(v6, r6);
	if (Z_TYPE_P(v2) == IS_ARRAY) { 
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_9b93_6:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_9b93_6;
			} else {
				PHALCON_INIT_VAR(v8);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v8, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v8, num);
					}
				}
			}
			PHALCON_INIT_VAR(v7);
			ZVAL_ZVAL(v7, *hd, 1, 0);
			if (Z_TYPE_P(v8) != IS_LONG) {
				if (Z_TYPE_P(v7) != IS_ARRAY) { 
					PHALCON_INIT_VAR(r7);
					PHALCON_CONCAT_VBOTH(r7, v8, "=\"", v7);
					PHALCON_INIT_VAR(r8);
					PHALCON_CONCAT_RIGHT(r8, r7, "\" ");
					PHALCON_INIT_VAR(r9);
					concat_function(r9, v6, r8 TSRMLS_CC);
					PHALCON_CPY_WRT(v6, r9);
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_9b93_6;
			fee_9b93_6:
			if(0){ };
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CONCAT_LEFT(r10, ">", v3);
	PHALCON_ALLOC_ZVAL_MM(r11);
	concat_function(r11, v6, r10 TSRMLS_CC);
	PHALCON_CPY_WRT(v6, r11);
	eval_int = phalcon_array_isset_string(v2, "dummyValue", strlen("dummyValue")+1);
	PHALCON_INIT_VAR(r12);
	ZVAL_BOOL(r12, eval_int);
	if (!zend_is_true(r12)) {
		PHALCON_INIT_VAR(v9);
		ZVAL_STRING(v9, "", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch_string(&r13, v2, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r13);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v2, "dummyText", strlen("dummyText")+1);
	PHALCON_INIT_VAR(r14);
	ZVAL_BOOL(r14, eval_int);
	if (!zend_is_true(r14)) {
		PHALCON_INIT_VAR(v10);
		ZVAL_STRING(v10, "Choose...", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_array_fetch_string(&r15, v2, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, r15);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyText", strlen("dummyText")+1);
	}
	eval_int = phalcon_array_isset_string(v2, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_VBOTH(r18, t1, "<option value=\"", v9);
		PHALCON_ALLOC_ZVAL_MM(r17);
		PHALCON_CONCAT_VBOTH(r17, r18, "\">", v10);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_VBOTH(r16, r17, "</option>", v3);
		PHALCON_ALLOC_ZVAL_MM(r19);
		concat_function(r19, v6, r16 TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r19);
	}
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r20);
		phalcon_array_fetch_long(&r20, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v11, r20);
		if (zend_is_true(v11)) {
			if (Z_TYPE_P(v11) == IS_OBJECT) {
				eval_int = phalcon_array_isset_string(v2, "using", strlen("using")+1);
				PHALCON_INIT_VAR(r21);
				ZVAL_BOOL(r21, eval_int);
				if (!zend_is_true(r21)) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_tag_exception_class_entry);
					PHALCON_INIT_VAR(p1[0]);
					ZVAL_STRING(p1[0], "The 'using' parameter is required", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
					return phalcon_throw_exception(i0 TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r22);
					phalcon_array_fetch_string(&r22, v2, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r22) != IS_ARRAY) { 
						PHALCON_ALLOC_ZVAL_MM(i1);
						object_init_ex(i1, phalcon_tag_exception_class_entry);
						PHALCON_INIT_VAR(p2[0]);
						ZVAL_STRING(p2[0], "The 'using' parameter should be an Array", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
						return phalcon_throw_exception(i1 TSRMLS_CC);
					}
				}
				PHALCON_ALLOC_ZVAL_MM(r23);
				phalcon_array_fetch_string(&r23, v2, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v12, r23);
				PHALCON_CALL_METHOD_NORETURN(v11, "rewind", PHALCON_CALL_DEFAULT);
				ws_9b93_7:
				PHALCON_INIT_VAR(r24);
				PHALCON_CALL_METHOD(r24, v11, "valid", PHALCON_CALL_DEFAULT);
				if (!zend_is_true(r24)) {
					goto we_9b93_7;
				}
				PHALCON_INIT_VAR(r25);
				PHALCON_CALL_METHOD(r25, v11, "current", PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v13, r25);
				PHALCON_INIT_VAR(r26);
				PHALCON_INIT_VAR(r27);
				phalcon_array_fetch_long(&r27, v12, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r27);
				p6[0] = r27;
				PHALCON_CALL_METHOD_PARAMS(r26, v13, "readattribute", 1, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				PHALCON_CPY_WRT(v14, r26);
				PHALCON_INIT_VAR(r28);
				PHALCON_INIT_VAR(r29);
				phalcon_array_fetch_long(&r29, v12, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r29);
				p7[0] = r29;
				PHALCON_CALL_METHOD_PARAMS(r28, v13, "readattribute", 1, p7, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p7[0]);
				PHALCON_CPY_WRT(v15, r28);
				PHALCON_INIT_VAR(r30);
				is_equal_function(r30, v5, v14 TSRMLS_CC);
				if (zend_is_true(r30)) {
					PHALCON_INIT_VAR(t2);
					ZVAL_STRING(t2, "\t", 1);
					PHALCON_INIT_VAR(r33);
					PHALCON_CONCAT_VBOTH(r33, t2, "<option selected=\"selected\" value=\"", v14);
					PHALCON_INIT_VAR(r32);
					PHALCON_CONCAT_VBOTH(r32, r33, "\">", v15);
					PHALCON_INIT_VAR(r31);
					PHALCON_CONCAT_VBOTH(r31, r32, "</option>", v3);
					PHALCON_INIT_VAR(r34);
					concat_function(r34, v6, r31 TSRMLS_CC);
					PHALCON_CPY_WRT(v6, r34);
				} else {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "\t", 1);
					PHALCON_INIT_VAR(r37);
					PHALCON_CONCAT_VBOTH(r37, t3, "<option value=\"", v14);
					PHALCON_INIT_VAR(r36);
					PHALCON_CONCAT_VBOTH(r36, r37, "\">", v15);
					PHALCON_INIT_VAR(r35);
					PHALCON_CONCAT_VBOTH(r35, r36, "</option>", v3);
					PHALCON_INIT_VAR(r38);
					concat_function(r38, v6, r35 TSRMLS_CC);
					PHALCON_CPY_WRT(v6, r38);
				}
				PHALCON_CALL_METHOD_NORETURN(v11, "next", PHALCON_CALL_DEFAULT);
				goto ws_9b93_7;
				we_9b93_7:
				if(0) { };
			}
		}
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "</select>", 1);
	PHALCON_ALLOC_ZVAL_MM(r39);
	concat_function(r39, v6, t4 TSRMLS_CC);
	PHALCON_CPY_WRT(v6, r39);
	PHALCON_RETURN_CTOR(v6);
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_long(v1, 0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v1, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v1, 0, r1 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r2);
	eval_int = phalcon_array_isset_string(v1, "name", strlen("name")+1);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		Z_ADDREF_P(v2);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "name", strlen("name"), v2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v1, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r4)) {
			Z_ADDREF_P(v2);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "name", strlen("name"), v2 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v1, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v1, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r5);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v3, r6);
	}
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CONCAT_BOTH(r7,  "<textarea id=\"", v2, "\" ");
	PHALCON_CPY_WRT(v4, r7);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_8;
		} else {
			PHALCON_INIT_VAR(v6);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v6, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v6, num);
				}
			}
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		if (Z_TYPE_P(v6) != IS_LONG) {
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_VBOTH(r8, v6, "=\"", v5);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r8, "\" ");
			PHALCON_INIT_VAR(r10);
			concat_function(r10, v4, r9 TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r10);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_8;
		fee_9b93_8:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CONCAT_BOTH(r11,  ">", v3, "</textarea>");
	PHALCON_ALLOC_ZVAL_MM(r12);
	concat_function(r12, v4, r11 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r12);
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Builds a HTML FORM tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *p5[] = { NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "_getdispatcher");
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v2, "getparams", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "join", c0, r2, 0x00D);
	PHALCON_CPY_WRT(v3, r1);
	eval_int = phalcon_array_isset_long(v1, 0);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		eval_int = phalcon_array_isset_string(v1, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_string(&r4, v1, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r4);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CALL_METHOD(r6, v2, "getcontrollername", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CALL_METHOD(r7, v2, "getactionname", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_VBOTH(r5, r6, "/", r7);
			PHALCON_CPY_WRT(v4, r5);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_long(&r8, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r8);
	}
	eval_int = phalcon_array_isset_string(v1, "method", strlen("method")+1);
	PHALCON_INIT_VAR(r9);
	ZVAL_BOOL(r9, eval_int);
	if (!zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "post", 1);
		Z_ADDREF_P(t0);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "method", strlen("method"), t0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "confirm", strlen("confirm")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r10);
		phalcon_array_fetch_string(&r10, v1, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, v1, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch_string(&r13, v1, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_VBOTH(r11, r12, ";if(!confirm(\"", r13);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_RIGHT(r14, r11, "\")) { return false; }");
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, r10, r14 TSRMLS_CC);
		Z_ADDREF_P(r15);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "onsubmit", strlen("onsubmit"), r15 TSRMLS_CC);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "confirm", strlen("confirm")+1);
	}
	if (zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(r16);
		Z_ADDREF_P(v4);
		p5[0] = v4;
		PHALCON_CALL_STATIC_PARAMS(r16, "phalcon_utils", "geturl", 1, p5);
		Z_DELREF_P(p5[0]);
		PHALCON_CPY_WRT(v4, r16);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r17);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_VBOTH(r18, v4, "/", v3);
		Z_ADDREF_P(r18);
		p6[0] = r18;
		PHALCON_CALL_STATIC_PARAMS(r17, "phalcon_utils", "geturl", 1, p6);
		Z_DELREF_P(p6[0]);
		PHALCON_CPY_WRT(v4, r17);
	}
	eval_int = phalcon_array_isset_string(v1, "parameters", strlen("parameters")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r19);
		phalcon_array_fetch_string(&r19, v1, "parameters", strlen("parameters"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r20);
		PHALCON_CONCAT_LEFT(r20, "?", r19);
		PHALCON_ALLOC_ZVAL_MM(r21);
		concat_function(r21, v4, r20 TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r21);
	}
	PHALCON_ALLOC_ZVAL_MM(r22);
	PHALCON_CONCAT_BOTH(r22,  "<form action=\"", v4, "\" ");
	PHALCON_CPY_WRT(v5, r22);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_9:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_9;
		} else {
			PHALCON_INIT_VAR(v7);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v7, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v7, num);
				}
			}
		}
		PHALCON_INIT_VAR(v6);
		ZVAL_ZVAL(v6, *hd, 1, 0);
		if (Z_TYPE_P(v7) != IS_LONG) {
			PHALCON_INIT_VAR(r23);
			PHALCON_CONCAT_VBOTH(r23, v7, "= \"", v6);
			PHALCON_INIT_VAR(r24);
			PHALCON_CONCAT_RIGHT(r24, r23, "\" ");
			PHALCON_INIT_VAR(r25);
			concat_function(r25, v5, r24 TSRMLS_CC);
			PHALCON_CPY_WRT(v5, r25);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_9;
		fee_9b93_9:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r26);
	PHALCON_CONCAT_RIGHT(r26, v5, ">");
	PHALCON_RETURN_CTOR(r26);
}

/**
 * Builds a HTML close FORM tag
 *
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, endForm){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("</form>", 1);
}

/**
 * Set the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, setTitle){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Add to title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Add before the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, v0, t0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Get the title of view content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitle){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_LEFT(r1, "<title>", t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VBOTH(r0, r1, "</title>", t1);
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @param   boolean $local
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	eval_int = phalcon_array_isset_string(v2, "href", strlen("href")+1);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		eval_int = phalcon_array_isset_long(v2, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_long(&r1, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r1);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "href", strlen("href"), r1 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			Z_ADDREF_P(t0);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "href", strlen("href"), t0 TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "", 1);
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r2);
	} else {
		eval_int = phalcon_array_isset_string(v2, "local", strlen("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, v2, "local", strlen("local"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r3);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "local", strlen("local")+1);
		}
	}
	eval_int = phalcon_array_isset_string(v2, "type", strlen("type")+1);
	PHALCON_INIT_VAR(r4);
	ZVAL_BOOL(r4, eval_int);
	if (!zend_is_true(r4)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/css", 1);
		Z_ADDREF_P(t1);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "type", strlen("type"), t1 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, v2, "href", strlen("href"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		PHALCON_CALL_STATIC_PARAMS(r5, "phalcon_utils", "geturl", 1, p0);
		Z_DELREF_P(p0[0]);
		Z_ADDREF_P(r5);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "href", strlen("href"), r5 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "<link rel=\"stylesheet\"", 1);
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_10:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_10;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		if (Z_TYPE_P(v5) != IS_LONG) {
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_LEFT(r8, " ", v5);
			PHALCON_INIT_VAR(r7);
			PHALCON_CONCAT_VBOTH(r7, r8, "=\"", v4);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r7, "\"");
			PHALCON_INIT_VAR(r10);
			concat_function(r10, v3, r9 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r10);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_10;
		fee_9b93_10:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CONCAT_LEFT(r11, ">", t2);
	PHALCON_ALLOC_ZVAL_MM(r12);
	concat_function(r12, v3, r11 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r12);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @param   boolean $local
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	eval_int = phalcon_array_isset_string(v2, "src", strlen("src")+1);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		eval_int = phalcon_array_isset_long(v2, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_long(&r1, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r1);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "src", strlen("src"), r1 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			Z_ADDREF_P(t0);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "src", strlen("src"), t0 TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "", 1);
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r2);
	} else {
		eval_int = phalcon_array_isset_string(v2, "local", strlen("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, v2, "local", strlen("local"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r3);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "local", strlen("local")+1);
		}
	}
	eval_int = phalcon_array_isset_string(v2, "type", strlen("type")+1);
	PHALCON_INIT_VAR(r4);
	ZVAL_BOOL(r4, eval_int);
	if (!zend_is_true(r4)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/javascript", 1);
		Z_ADDREF_P(t1);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "type", strlen("type"), t1 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, v2, "src", strlen("src"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		PHALCON_CALL_STATIC_PARAMS(r5, "phalcon_utils", "geturl", 1, p0);
		Z_DELREF_P(p0[0]);
		Z_ADDREF_P(r5);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "src", strlen("src"), r5 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "<script", 1);
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_11;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		if (Z_TYPE_P(v5) != IS_LONG) {
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_LEFT(r8, " ", v5);
			PHALCON_INIT_VAR(r7);
			PHALCON_CONCAT_VBOTH(r7, r8, "=\"", v4);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r7, "\" ");
			PHALCON_INIT_VAR(r10);
			concat_function(r10, v3, r9 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r10);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_11;
		fee_9b93_11:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CONCAT_LEFT(r11, "></script>", t2);
	PHALCON_ALLOC_ZVAL_MM(r12);
	concat_function(r12, v3, r11 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r12);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds HTML IMG tags
 *
 * @param  array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_string(v1, "src", strlen("src")+1);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		eval_int = phalcon_array_isset_long(v1, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r1);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "src", strlen("src"), r1 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			Z_ADDREF_P(t0);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "src", strlen("src"), t0 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, v1, "src", strlen("src"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r3);
	p0[0] = r3;
	PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_utils", "geturl", 1, p0);
	Z_DELREF_P(p0[0]);
	Z_ADDREF_P(r2);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v1, "src", strlen("src"), r2 TSRMLS_CC);
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "<img", 1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_12:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_12;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		if (Z_TYPE_P(v4) != IS_LONG) {
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_LEFT(r5, " ", v4);
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_VBOTH(r4, r5, "=\"", v3);
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_RIGHT(r6, r4, "\"");
			PHALCON_INIT_VAR(r7);
			concat_function(r7, v2, r6 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r7);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_12;
		fee_9b93_12:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CONCAT_LEFT(r8, ">", t1);
	PHALCON_ALLOC_ZVAL_MM(r9);
	concat_function(r9, v2, r8 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r9);
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Phalcon_Response
 *
 * Encapsulates the HTTP response message.
 *
 *
 */

/**
 * Returns singleton Phalcon_Response instance
 *
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_response_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param strign $message
 */
PHP_METHOD(Phalcon_Response, setStatusCode){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "SERVER_SOFTWARE", strlen("SERVER_SOFTWARE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "HTTP/1.1 ", v0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, " ", v1);
		Z_ADDREF_P(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r0, c0, 0x03B);
		Z_DELREF_P(r0);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "Status: ", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, " ", v1);
		Z_ADDREF_P(r2);
		PHALCON_INIT_VAR(c1);
		ZVAL_BOOL(c1, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r2, c1, 0x03B);
		Z_DELREF_P(r2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes a header in the response
 *
 *
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Response, setHeader){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "SERVER_SOFTWARE", strlen("SERVER_SOFTWARE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, v0, ": ", v1);
		Z_ADDREF_P(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r0, c0, 0x03B);
		Z_DELREF_P(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Send a raw header to the response
 *
 *
 */
PHP_METHOD(Phalcon_Response, setRawHeader){

	zval *v0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", v0, c0, 0x03B);
	Z_DELREF_P(v0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets HTTP response body
     *
 *
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, setContent){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Appends a string to the HTTP response body
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, appendContent){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets HTTP response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Response, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends HTTP response to the client
 *
 */
PHP_METHOD(Phalcon_Response, send){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zend_print_zval(t0, 0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Request
 *
 * Encapsulates request information for easily and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
 *
 * 
 *
 */

PHP_METHOD(Phalcon_Request, __construct){


	
}

/**
 * Gets the singleton instance of Phalcon_Request
 *
 * @return Phalcon_Request
 */
PHP_METHOD(Phalcon_Request, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_request_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Overwrittes Phalcon_Filter object used to sanitize input data
 *
 * @param Phalcon_Filter $filter
 */
PHP_METHOD(Phalcon_Request, setFilter){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns active filter object used to sanitize input data
 *
 * @return Phalcon_Filter
 */
PHP_METHOD(Phalcon_Request, getFilter){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Gets variable from $_POST superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Request, getPost){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_init_global("_POST", sizeof("_POST") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset(g0, v0);
	if (eval_int) {
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch(&r2, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			Z_ADDREF_P(v1);
			p0[1] = v1;
			PHALCON_CALL_METHOD_PARAMS(r0, r1, "sanitize", 2, p0, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p0[0]);
			Z_DELREF_P(p0[1]);
			PHALCON_RETURN_DZVAL(r0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch(&r3, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r3);
		}
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Request, getQuery){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_init_global("_GET", sizeof("_GET") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_GET", sizeof("_GET"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset(g0, v0);
	if (eval_int) {
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch(&r2, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			Z_ADDREF_P(v1);
			p0[1] = v1;
			PHALCON_CALL_METHOD_PARAMS(r0, r1, "sanitize", 2, p0, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p0[0]);
			Z_DELREF_P(p0[1]);
			PHALCON_RETURN_DZVAL(r0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch(&r3, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r3);
		}
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Request, getServer){

	zval *v0 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset(g0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets HTTP header from request data
 *
 * @param string $header
 * @return string
 */
PHP_METHOD(Phalcon_Request, getHeader){

	zval *v0 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset(g0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "HTTP_", v0);
		eval_int = phalcon_array_isset(g0, r1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_LEFT(r2, "HTTP_", v0);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch(&r3, g0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r3);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_STRING("", 1);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getScheme){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_HTTPS", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "on")) {
		PHALCON_MM_RESTORE();
		RETURN_STRING("https", 1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("http", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether request has been made using ajax
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isAjax){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_X_REQUESTED_WITH", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getheader", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r1);
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isSoapRequested){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "HTTP_SOAPACTION", strlen("HTTP_SOAPACTION")+1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		eval_int = phalcon_array_isset_string(g0, "CONTENT_TYPE", strlen("CONTENT_TYPE")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_string(&r1, g0, "CONTENT_TYPE", strlen("CONTENT_TYPE"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "application/soap+xml", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r0, "strpos", r1, c0, 0x00A);
			PHALCON_INIT_VAR(t0);
			ZVAL_BOOL(t0, 0);
			PHALCON_INIT_VAR(r2);
			is_not_identical_function(r2, t0, r0 TSRMLS_CC);
			PHALCON_RETURN_NCTOR(r2);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isSecureRequest){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "https", 1);
	PHALCON_INIT_VAR(r1);
	is_identical_function(r1, t0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getRawBody){

	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "php://input", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "file_get_contents", c0, 0x017);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getServerAddress){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "SERVER_ADDR", strlen("SERVER_ADDR")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "SERVER_ADDR", strlen("SERVER_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "localhost", 1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "gethostbyname", c0, 0x03C);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getServerName){

	zval *g0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "SERVER_NAME", strlen("SERVER_NAME")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "SERVER_NAME", strlen("SERVER_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("localhost", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getHttpHost){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(p1[0]);
	ZVAL_STRING(p1[0], "HTTP_SERVER_NAME", 1);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "getserver", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(p2[0]);
	ZVAL_STRING(p2[0], "HTTP_SERVER_PORT", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getserver", 1, p2, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r2);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "http", 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, v0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 80);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, v2, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(r5);
	phalcon_and_function(r5, r3, r4);
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "https", 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, v0, t2 TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 443);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, v2, t3 TSRMLS_CC);
	PHALCON_INIT_VAR(r8);
	phalcon_and_function(r8, r6, r7);
	PHALCON_INIT_VAR(r9);
	ZVAL_BOOL(r9, zend_is_true(r5) || zend_is_true(r8));
	if (zend_is_true(r9)) {
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_VBOTH(r10, v1, ":", v2);
		PHALCON_RETURN_CTOR(r10);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets most possibly client IPv4 Address
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getClientAddress){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		eval_int = phalcon_array_isset_string(g0, "REMOTE_ADDR", strlen("REMOTE_ADDR")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_string(&r1, g0, "REMOTE_ADDR", strlen("REMOTE_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r1);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_STRING("", 1);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getMethod){

	zval *g0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "REQUEST_METHOD", strlen("REQUEST_METHOD")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "REQUEST_METHOD", strlen("REQUEST_METHOD"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getUserAgent){

	zval *g0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is POST
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isPost){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "POST")) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is GET
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isGet){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "GET")) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is PUT
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isPut){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "PUT")) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is HEAD
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isHead){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "HEAD")) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is DELETE
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isDelete){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "DELETE")) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is OPTIONS
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isOptions){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "OPTIONS")) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether request include attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, hasFiles){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval **gv0;

	PHALCON_MM_GROW();
	phalcon_init_global("_FILES", sizeof("_FILES") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_FILES", sizeof("_FILES"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	if (zend_is_true(g0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "count", g0, 0x007);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r2);
		is_smaller_function(r2, t0, r1 TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_BOOL(t1, 1);
			r0 = t1;
		} else {
			PHALCON_INIT_VAR(t2);
			ZVAL_BOOL(t2, 0);
			r0 = t2;
		}
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets attached files as Phalcon_UploadFile clases
 *
 * @return array
 */
PHP_METHOD(Phalcon_Request, getUploadedFiles){

	zval *g0 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	phalcon_init_global("_FILES", sizeof("_FILES") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_FILES", sizeof("_FILES"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	if (zend_is_true(g0)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v0, a0);
		if (Z_TYPE_P(g0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(g0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_9aea_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_9aea_0;
			}
			PHALCON_INIT_VAR(v1);
			ZVAL_ZVAL(v1, *hd, 1, 0);
			ce0 = zend_fetch_class("phalcon_uploadfile", strlen("phalcon_uploadfile"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, ce0);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			Z_DELREF_P(p0[0]);
			PHALCON_CPY_WRT(v2, i0);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(v0);
			phalcon_array_append(v0, v2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_9aea_0;
			fee_9aea_0:
			if(0){ };
		}
		PHALCON_RETURN_CTOR(v0);
	} else {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_RETURN_CTOR(a1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets web page which refers active request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getHTTPReferer){

	zval *g0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "HTTP_REFERER", strlen("HTTP_REFERER")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "HTTP_REFERER", strlen("HTTP_REFERER"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets array with mime/types and their quality accepted by the browser/client.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Request, getAcceptableContent){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/,\\s*/", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "preg_split", c0, v0, 0x03D);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9aea_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9aea_1;
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, ";", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r2, "explode", c1, v3, 0x005);
		PHALCON_CPY_WRT(v4, r2);
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
			PHALCON_INIT_VAR(r3);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_long(&r4, v4, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r4);
			PHALCON_INIT_VAR(c2);
			ZVAL_LONG(c2, 2);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "substr", r4, c2, 0x002);
			Z_DELREF_P(r4);
			PHALCON_CPY_WRT(v5, r3);
		} else {
			PHALCON_INIT_VAR(v5);
			ZVAL_DOUBLE(v5, 1);
		}
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch_long(&r5, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r5);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "accept", r5);
		Z_ADDREF_P(v5);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "quality", v5);
		Z_ADDREF_P(a1);
		PHALCON_SEPARATE_ARRAY(v2);
		phalcon_array_append(v2, a1 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9aea_1;
		fee_9aea_1:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Gets best mime/type accepted by the browser/client.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Request, getBestQualityAccept){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getacceptablecontent", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(r0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9aea_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9aea_2;
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r1);
		is_equal_function(r1, v0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch_string(&r2, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r2);
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch_string(&r3, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r3);
		} else {
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			is_smaller_function(r5, v1, r4 TSRMLS_CC);
			if (zend_is_true(r5)) {
				PHALCON_INIT_VAR(r6);
				phalcon_array_fetch_string(&r6, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v1, r6);
				PHALCON_INIT_VAR(r7);
				phalcon_array_fetch_string(&r7, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v2, r7);
			}
		}
		increment_function(v0);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9aea_2;
		fee_9aea_2:
		if(0){ };
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Gets charsets array and their quality accepted by the browser/client.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Request, getClientCharsets){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT_CHARSET", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/,\\s*/", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "preg_split", c0, v0, 0x03D);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9aea_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9aea_3;
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, ";", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r2, "explode", c1, v3, 0x005);
		PHALCON_CPY_WRT(v4, r2);
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
			PHALCON_INIT_VAR(r3);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_long(&r4, v4, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r4);
			PHALCON_INIT_VAR(c2);
			ZVAL_LONG(c2, 2);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "substr", r4, c2, 0x002);
			Z_DELREF_P(r4);
			PHALCON_CPY_WRT(v5, r3);
		} else {
			PHALCON_INIT_VAR(v5);
			ZVAL_DOUBLE(v5, 1);
		}
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch_long(&r5, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r5);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "accept", r5);
		Z_ADDREF_P(v5);
		PHALCON_SEPARATE_ARRAY(a1);
		add_assoc_zval(a1, "quality", v5);
		Z_ADDREF_P(a1);
		PHALCON_SEPARATE_ARRAY(v2);
		phalcon_array_append(v2, a1 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9aea_3;
		fee_9aea_3:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Gets best charset accepted by the browser/client.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getBestQualityCharset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getclientcharsets", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(r0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9aea_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9aea_4;
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r1);
		is_equal_function(r1, v0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch_string(&r2, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r2);
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch_string(&r3, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r3);
		} else {
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			is_smaller_function(r5, v1, r4 TSRMLS_CC);
			if (zend_is_true(r5)) {
				PHALCON_INIT_VAR(r6);
				phalcon_array_fetch_string(&r6, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v1, r6);
				PHALCON_INIT_VAR(r7);
				phalcon_array_fetch_string(&r7, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v2, r7);
			}
		}
		increment_function(v0);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9aea_4;
		fee_9aea_4:
		if(0){ };
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Phalcon_Transaction_Failed
 *
 * Phalcon_Transaction_Failed will thrown to exit a try/catch block for transactions
 *
 */

/**
 * Phalcon_Transaction_Failed constructor
 *
 * @param string $message
 * @param Phalcon_Model_Base $record
 */
PHP_METHOD(Phalcon_Transaction_Failed, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_record", strlen("_record"), v1 TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_LONG(p0[1], 0);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Transaction_Failed", "__construct", 2, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return string
 */
PHP_METHOD(Phalcon_Transaction_Failed, getRecordMessages){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_record", sizeof("_record")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t0);
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getmessages", PHALCON_CALL_DEFAULT);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getmessage", PHALCON_CALL_DEFAULT);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Transaction_Failed, getRecord){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_record", sizeof("_record")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Transaction_Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them
 *
  *
 *
 */

/**
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction_Manager, has){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Returns a new Phalcon_Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, get){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 1);
	}
	
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		add_next_index_stringl(a0, "Phalcon_Transaction_Manager", strlen("Phalcon_Transaction_Manager"), 1);
		add_next_index_stringl(a0, "rollbackPendent", strlen("rollbackPendent"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a0, 0x037);
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 1);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, t1 TSRMLS_CC);
	}
	t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t2);
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_transaction_class_entry);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v2, i0);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Phalcon_Transaction_Manager", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "settransactionmanager", 1, p2, PHALCON_CALL_DEFAULT);
		t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p3[0] = t3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setdependencypointer", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2048);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_add_function(r0, t4, t5 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, r0 TSRMLS_CC);
		t6 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
		}
		Z_ADDREF_P(v2);
		phalcon_array_append(t6, v2 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, t6 TSRMLS_CC);
		
		t7 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t7);
		increment_function(t7);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t7 TSRMLS_CC);
	} else {
		t8 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		sub_function(r1, v1, t10 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t9);
		phalcon_array_fetch(&t9, t8, r1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, t9);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_BOOL(p4[0], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setisnewtransaction", 1, p4, PHALCON_CALL_DEFAULT);
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Rollbacks active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollbackPendent){


	PHALCON_MM_GROW();
	PHALCON_CALL_SELF_NORETURN(this_ptr, "rollback");
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Commmits active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, commit){

	zval *t0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_ad2c_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ad2c_0;
		}
		PHALCON_INIT_VAR(v0);
		ZVAL_ZVAL(v0, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, v1, "isundertransaction", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_NORETURN(v1, "commit", PHALCON_CALL_DEFAULT);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ad2c_0;
		fee_ad2c_0:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Rollbacks active transactions whithin the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p4[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_ad2c_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ad2c_1;
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, v1, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, v2, "isundertransaction", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_NORETURN(v2, "rollback", PHALCON_CALL_DEFAULT);
			PHALCON_CALL_METHOD_NORETURN(v2, "close", PHALCON_CALL_DEFAULT);
		}
		if (zend_is_true(v0)) {
			Z_ADDREF_P(v1);
			p4[0] = v1;
			PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p4);
			Z_DELREF_P(p4[0]);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ad2c_1;
		fee_ad2c_1:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyRollback){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyCommit){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transaction_Manager, _collectTransaction){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(v1);
		ZVAL_LONG(v1, 0);
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_ad2c_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ad2c_2;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(r2);
			is_equal_function(r2, v2, v0 TSRMLS_CC);
			if (zend_is_true(r2)) {
				t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				PHALCON_SEPARATE_NMO(t3);
				decrement_function(t3);
				zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			}
			PHALCON_SEPARATE(v1);
			increment_function(v1);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ad2c_2;
			fee_ad2c_2:
			if(0){ };
		}
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(t4);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_ad2c_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_ad2c_3;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(v3);
			phalcon_array_append(v3, v2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_ad2c_3;
			fee_ad2c_3:
			if(0){ };
		}
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, v3 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, collectTransactions){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_LONG(v0, 0);
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_ad2c_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ad2c_4;
			}
			PHALCON_INIT_VAR(v1);
			ZVAL_ZVAL(v1, *hd, 1, 0);
			t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_SEPARATE_NMO(t3);
			decrement_function(t3);
			zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			increment_function(v0);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ad2c_4;
			fee_ad2c_4:
			if(0){ };
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether manager will inject an automatic transaction to all newly
 * created instances of Phalcon_Model_base
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction_Manager, isAutomatic){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Returns automatic transaction for instances of Phalcon_Model_base
 *
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, getAutomatic){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Controller_Front
 *
 * Phalcon_Controller_Front implements a "Front Controller" pattern used in "Model-View-Controller" (MVC) applications.
 * Its purpose is to initialize the request environment, route the incoming request, and then dispatch
 * any discovered actions; it aggregates any responses and returns them when the process is complete
 *
 *
 */

/**
 * Private Phalcon_Controller_Front constructor for singleton
 */
PHP_METHOD(Phalcon_Controller_Front, __construct){


	
}

/**
 * Gets Phalcon_Controller_Front singleton instance
 *
 * @return Phalcon_Controller_Front
 */
PHP_METHOD(Phalcon_Controller_Front, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_controller_front_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Modifies multipe general settings using a Phalcon_Config object or a stdClass filled with parameters
 *
 * 
 *
 * @param stdClass $config
 */
PHP_METHOD(Phalcon_Controller_Front, setConfig){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		eval_int = phalcon_isset_property(v0, "database", strlen("database") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, v0, "database", sizeof("database")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t0);
			p0[0] = t0;
			PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_db_pool", "setdefaultdescriptor", 1, p0);
			Z_DELREF_P(p0[0]);
		}
		eval_int = phalcon_isset_property(v0, "phalcon", strlen("phalcon") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, v0, "phalcon", sizeof("phalcon")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, t1);
			eval_int = phalcon_isset_property(v1, "controllersDir", strlen("controllersDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t2);
				phalcon_read_property(&t2, v1, "controllersDir", sizeof("controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), t2 TSRMLS_CC);
			}
			eval_int = phalcon_isset_property(v1, "modelsDir", strlen("modelsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, v1, "modelsDir", sizeof("modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), t3 TSRMLS_CC);
			}
			eval_int = phalcon_isset_property(v1, "viewsDir", strlen("viewsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t4);
				phalcon_read_property(&t4, v1, "viewsDir", sizeof("viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), t4 TSRMLS_CC);
			}
			eval_int = phalcon_isset_property(v1, "baseUri", strlen("baseUri") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t5);
				phalcon_read_property(&t5, v1, "baseUri", sizeof("baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), t5 TSRMLS_CC);
			}
			eval_int = phalcon_isset_property(v1, "basePath", strlen("basePath") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t6);
				phalcon_read_property(&t6, v1, "basePath", sizeof("basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), t6 TSRMLS_CC);
			}
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Config parameter should be an Object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets the database default settings
 *
 * @param stdClass $database
 */
PHP_METHOD(Phalcon_Controller_Front, setDatabaseConfig){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_db_pool", "setdefaultdescriptor", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets controllers directory
 *
 * 
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Controller_Front, setControllersDir){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets models directory
     *
 * 
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setModelsDir){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets views directory
 *
 * 
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setViewsDir){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Replaces the default router with a predefined object
 *
 * 
 *
 * @param Phalcon_Router $router
 */
PHP_METHOD(Phalcon_Controller_Front, setRouter){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Return active router
 *
 * @return Phalcon_Router
 */
PHP_METHOD(Phalcon_Controller_Front, getRouter){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Replaces the default dispatcher with a predefined object
 *
 * @param Phalcon_Dispatcher $dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, setDispatcher){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Return active Dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Dispatch process has not started yet", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets external uri which app is executed
 *
 * @param string $baseUri
 */
PHP_METHOD(Phalcon_Controller_Front, setBaseUri){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets external uri where app is executed
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBaseUri){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *g0 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval **gv0;
	zval *p1[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_init_global("_SERVER", sizeof("_SERVER") TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					g0 = *gv0;
				} else {
					PHALCON_INIT_VAR(g0);
					array_init(g0);
				}
			}
		}
		if (!g0) {
			PHALCON_INIT_VAR(g0);
			array_init(g0);
		}
		eval_int = phalcon_array_isset_string(g0, "PHP_SELF", strlen("PHP_SELF")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "/", 1);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_string(&r4, g0, "PHP_SELF", strlen("PHP_SELF"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r3, "dirname", r4, 0x03E);
			PHALCON_CALL_FUNC_PARAMS_2(r2, "explode", c0, r3, 0x005);
			p1[0] = r2;
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 1);
			PHALCON_INIT_VAR(t2);
			ZVAL_LONG(t2, 1);
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, -1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			mul_function(r5, t1, t2 TSRMLS_CC);
			p1[2] = r5;
			PHALCON_CALL_FUNC_PARAMS(r1, "array_slice", 3, p1, 0x01D);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "/", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r0, "join", r1, c1, 0x00D);
			PHALCON_CPY_WRT(v0, r0);
		} else {
			PHALCON_INIT_VAR(v0);
			ZVAL_STRING(v0, "", 1);
		}
		if (!zend_is_true(v0)) {
			phalcon_update_property_string(this_ptr, "_baseUri", strlen("_baseUri"), "/" TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_BOTH(r6,  "/", v0, "/");
			phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), r6 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t3);
}

/**
 * Sets local path where app/ directory is located
 *
  * @param string $basePath
 */
PHP_METHOD(Phalcon_Controller_Front, setBasePath){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets local path where app/ directory is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBasePath){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Overwrittes request object default object
 *
 * @param Phalcon_Request $response
 */
PHP_METHOD(Phalcon_Controller_Front, setRequest){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes response object default object
  *
 * @param Phalcon_Response $response
 */
PHP_METHOD(Phalcon_Controller_Front, setResponse){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes models manager default object
 *
 * @param Phalcon_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller_Front, setModelComponent){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets the models manager
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Controller_Front, getModelComponent){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_manager_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v0, i0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setmodelsdir", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), v0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Sets view component
 *
 * @param Phalcon_View $view
 */
PHP_METHOD(Phalcon_Controller_Front, setViewComponent){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets the views part manager
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, getViewComponent){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), i0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t2);
		p1[0] = t2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "setviewsdir", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t3);
}

/**
 * Executes the dispatch loop
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, dispatchLoop){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p10[] = { NULL }, *p12[] = { NULL }, *p14[] = { NULL }, *p16[] = { NULL, NULL, NULL, NULL }, *p17[] = { NULL, NULL }, *p21[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_dispatcher_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v0, i0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setbasepath", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t2);
		p2[0] = t2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setcontrollersdir", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t3);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
		phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t5)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_response", "getinstance");
		phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), r1 TSRMLS_CC);
	}
	eval_int = phalcon_isset_property(this_ptr, "_router", strlen("_router") TSRMLS_CC);
	PHALCON_INIT_VAR(r2);
	ZVAL_BOOL(r2, !eval_int);
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_read_property(&t6, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	boolean_not_function(r3, t6 TSRMLS_CC);
	PHALCON_INIT_VAR(r4);
	ZVAL_BOOL(r4, zend_is_true(r2) || zend_is_true(r3));
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_router_rewrite_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i1, "__construct", PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v1, i1);
		PHALCON_CALL_METHOD_NORETURN(v1, "handle", PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_read_property(&t7, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t7);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "getviewcomponent", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r5);
	PHALCON_CALL_METHOD_NORETURN(v2, "start", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, this_ptr, "getmodelcomponent", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v3, r6);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r7);
	p10[0] = r7;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setcontrollername", 1, p10, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p10[0]);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, v1, "getactionname", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r8);
	p12[0] = r8;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setactionname", 1, p12, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p12[0]);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, v1, "getparams", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r9);
	p14[0] = r9;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setparams", 1, p14, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p14[0]);
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, t8);
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t9);
	p16[0] = t9;
	Z_ADDREF_P(v4);
	p16[1] = v4;
	Z_ADDREF_P(v2);
	p16[2] = v2;
	Z_ADDREF_P(v3);
	p16[3] = v3;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dispatch", 4, p16, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p16[0]);
	Z_DELREF_P(p16[1]);
	Z_DELREF_P(p16[2]);
	Z_DELREF_P(p16[3]);
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CALL_METHOD(r10, v0, "getcontrollername", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r10);
	p17[0] = r10;
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, v0, "getactionname", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r11);
	p17[1] = r11;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "render", 2, p17, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p17[0]);
	Z_DELREF_P(p17[1]);
	PHALCON_CALL_METHOD_NORETURN(v2, "finish", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_CALL_METHOD(r12, v2, "getcontent", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r12);
	p21[0] = r12;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setcontent", 1, p21, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p21[0]);
	PHALCON_RETURN_CHECK_CTOR(v4);
}

/**
 * Phalcon_Session
 *
 * Session client-server persistent state data management.
 */

/**
 * Starts session, optionally using an adapter
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, start){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v0, a0);
	}
	
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "session_start", 0x03F);
	PG(display_errors) = silence;
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets session options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, setOptions){

	zval *v0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	eval_int = phalcon_array_isset_string(v0, "uniqueId", strlen("uniqueId")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v0, "uniqueId", strlen("uniqueId"), PHALCON_NOISY_FETCH TSRMLS_CC);
		zend_update_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, r0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, get){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *g0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_init_global("_SESSION", sizeof("_SESSION") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset(g0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, g0, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets a session variable in an application context
 *
 * @param string $index
 * @param string $value
 */
PHP_METHOD(Phalcon_Session, set){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval **gv0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SESSION", sizeof("_SESSION") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	phalcon_array_update(g0, r0, v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Check whether a session variable is set in an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, has){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *g0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_init_global("_SESSION", sizeof("_SESSION") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset(g0, v1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Removes a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, remove){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *g0 = NULL;
	zval **gv0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_init_global("_SESSION", sizeof("_SESSION") TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	phalcon_array_unset(g0, v1);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns active session id
 *
 * @return string
 */
PHP_METHOD(Phalcon_Session, getId){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "session_id", 0x040);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Phalcon_Flash
 *
 * Shows HTML notifications related to different circustances. Classes can be stylized using CSS
 */

PHP_METHOD(Phalcon_Flash, _showMessage){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "join", c0, v1, 0x00D);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_CPY_WRT(v2, v1);
	}
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_3b3c_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_3b3c_0;
			}
			PHALCON_INIT_VAR(v3);
			ZVAL_ZVAL(v3, *hd, 1, 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_LEFT(r3, "<div class=\"", v2);
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_VBOTH(r2, r3, "\">", v3);
			PHALCON_INIT_VAR(t0);
			zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
			PHALCON_INIT_VAR(r1);
			PHALCON_CONCAT_VBOTH(r1, r2, "</div>", t0);
			zend_print_zval(r1, 0);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_3b3c_0;
			fee_3b3c_0:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_LEFT(r6, "<div class=\"", v2);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, "\">", v0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_VBOTH(r4, r5, "</div>", t1);
		zend_print_zval(r4, 0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Shows a HTML error message
 *
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, error){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "errorMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML notice/information message
 *
     * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, notice){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "noticeMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML success message
 *
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, success){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "successMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML warning message
 *
 * 
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, warning){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "warningMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Phalcon_Config
 *
 * Phalcon_Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 * 
 *
 */

/**
 * Phalcon_Config constructor
 *
 * @paramarray $arrayConfig
 * @returnPhalcon_Config
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v0, a0);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9656_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9656_0;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_config_class_entry);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			Z_DELREF_P(p0[0]);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), i0 TSRMLS_CC);
		} else {
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), v1 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9656_0;
		fee_9656_0:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Filter
 *
 * The Phalcon_Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension
 *
 *
 *
 */

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_CPY_WRT(v3, v0);
		if (Z_TYPE_P(v0) != IS_NULL) {
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_e618_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_0;
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				PHALCON_INIT_VAR(r0);
				Z_ADDREF_P(v3);
				p0[0] = v3;
				Z_ADDREF_P(v4);
				p0[1] = v4;
				Z_ADDREF_P(v2);
				p0[2] = v2;
				PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_sanitize", 3, p0, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p0[0]);
				Z_DELREF_P(p0[1]);
				Z_DELREF_P(p0[2]);
				PHALCON_CPY_WRT(v3, r0);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_0;
				fee_e618_0:
				if(0){ };
			}
		}
		PHALCON_RETURN_CHECK_CTOR(v3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		Z_ADDREF_P(v2);
		p1[2] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_sanitize", 3, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[2]);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Filters a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  array $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, filter){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_CPY_WRT(v3, v0);
		if (Z_TYPE_P(v0) != IS_NULL) {
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_e618_1:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_1;
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				PHALCON_INIT_VAR(r0);
				Z_ADDREF_P(v3);
				p0[0] = v3;
				Z_ADDREF_P(v4);
				p0[1] = v4;
				Z_ADDREF_P(v2);
				p0[2] = v2;
				PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_filter", 3, p0, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p0[0]);
				Z_DELREF_P(p0[1]);
				Z_DELREF_P(p0[2]);
				PHALCON_CPY_WRT(v3, r0);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_1;
				fee_e618_1:
				if(0){ };
			}
		}
		PHALCON_RETURN_CHECK_CTOR(v3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		Z_ADDREF_P(v2);
		p1[2] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_filter", 3, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[2]);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sanitize and Filter a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitizeAndFilter){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_BOOL(p0[2], 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "sanitize", 3, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	Z_ADDREF_P(v1);
	p1[1] = v1;
	PHALCON_INIT_VAR(p1[2]);
	ZVAL_BOOL(p1[2], 1);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "filter", 3, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "email", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v1, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 517);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "filter_var", v0, t1, 0x041);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "int", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v1, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 519);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "filter_var", v0, t3, 0x041);
		PHALCON_RETURN_DZVAL(r3);
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "string", 1);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, v1, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 513);
		PHALCON_CALL_FUNC_PARAMS_2(r5, "filter_var", v0, t5, 0x041);
		PHALCON_RETURN_DZVAL(r5);
	}
	PHALCON_INIT_VAR(t6);
	ZVAL_STRING(t6, "float", 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, v1, t6 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		p3[0] = v0;
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 520);
		p3[1] = t7;
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 4096);
		Z_ADDREF_P(t8);
		PHALCON_SEPARATE_ARRAY(a0);
		add_assoc_zval(a0, "flags", t8);
		p3[2] = a0;
		PHALCON_CALL_FUNC_PARAMS(r7, "filter_var", 3, p3, 0x041);
		PHALCON_RETURN_DZVAL(r7);
	}
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "Sanitize filter ", v1, " is not supported");
		Z_ADDREF_P(r8);
		p4[0] = r8;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	se_e618_2:
	if(0) { };
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Internal filter function
 *
 * @parammixed $value
 * @paramarray $filters
 * @param  boolean $silent
 * @returnmixed
 */
PHP_METHOD(Phalcon_Filter, _filter){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "extraspaces", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v1, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "trim", v0, 0x00E);
		Z_DELREF_P(v0);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "striptags", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v1, t1 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "strip_tags", v0, 0x042);
		Z_DELREF_P(v0);
		PHALCON_RETURN_DZVAL(r3);
	}
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "Filter ", v1, " is not supported");
		Z_ADDREF_P(r4);
		p2[0] = r4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	se_e618_3:
	if(0) { };
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Acl
 *
 * This component allows to manage ACL lists. An access control list (ACL) is a list
 * of permissions attached to an object. An ACL specifies which users or system processes
 * are granted access to objects, as well as what operations are allowed on given objects.
 *
 *
 */

/**
 * Phalcon_Acl Constructor
 *
 * @param string $adapterName
 * @param array $options
 */
PHP_METHOD(Phalcon_Acl, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "Memory", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Acl_Adapter_", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v2, 0x00F);
	Z_DELREF_P(v2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Adapter '", v0, "' does not exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), i1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Pass any call to the internal adapter object
 *
 * @param  string $method
 * @param  array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Acl, __call){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, t0);
	Z_ADDREF_P(v0);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, v0);
	Z_ADDREF_P(a1);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "call_user_func_array", a1, v1, 0x010);
	Z_DELREF_P(a1);
	Z_DELREF_P(v1);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Phalcon_Logger_Exception
 *
 * Exceptions thrown in Phalcon_Logger will use this class
 *
 */

/**
 * Phalcon_Logger_Exception constructor
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Exception, __construct){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Logger_Exception", "__construct", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Logger_Adapter_File
 *
 * Adapter to store logs in plain text files
 *
 */

/**
 * Phalcon_Logger_Adapter_File constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };
	int eval_int;
	zend_bool silence;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_logger_adapter_file_class_entry, this_ptr, "_quenue", strlen("_quenue"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v1, a1);
	}
	
	eval_int = phalcon_array_isset_string(v1, "mode", strlen("mode")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "mode", strlen("mode"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "ab", 1);
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "fopen", v0, v2, 0x043);
	PG(display_errors) = silence;
	phalcon_update_property_zval(this_ptr, "_fileHandler", strlen("_fileHandler"), r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Can't open log file at '", v0, "'");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setFormat){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_format", strlen("_format"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormat){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_format", strlen("_format"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getTypeString){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_logger_class_entry, "DEBUG", strlen("DEBUG") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "DEBUG", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "ERROR", strlen("ERROR") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "ERROR", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_get_class_constant(t2, phalcon_logger_class_entry, "WARNING", strlen("WARNING") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v0, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "WARNING", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_get_class_constant(t3, phalcon_logger_class_entry, "CUSTOM", strlen("CUSTOM") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, v0, t3 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "CUSTOM", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_get_class_constant(t4, phalcon_logger_class_entry, "CRITICAL", strlen("CRITICAL") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, v0, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "CRITICAL", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_get_class_constant(t5, phalcon_logger_class_entry, "ALERT", strlen("ALERT") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r5);
	is_equal_function(r5, v0, t5 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "ALERT", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_get_class_constant(t6, phalcon_logger_class_entry, "NOTICE", strlen("NOTICE") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, v0, t6 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "NOTICE", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_get_class_constant(t7, phalcon_logger_class_entry, "EMERGENCE", strlen("EMERGENCE") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, v0, t7 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "EMERGENCE", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_get_class_constant(t8, phalcon_logger_class_entry, "INFO", strlen("INFO") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r8);
	is_equal_function(r8, v0, t8 TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "INFO", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_get_class_constant(t9, phalcon_logger_class_entry, "SPECIAL", strlen("SPECIAL") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, v0, t9 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "SPECIAL", 1);
		goto se_654f_0;
	}
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "CUSTOM", 1);
	se_654f_0:
	if(0) { };
	PHALCON_RETURN_CHECK_CTOR(v0);
}

/**
 * Applies the internal format to the message
 *
 * @param  string $message
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, _applyFormat){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL, NULL }, *p4[] = { NULL }, *p3[] = { NULL, NULL, NULL }, *p5[] = { NULL, NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 0);
	} else {
		PHALCON_SEPARATE_PARAM(v2);
	}
	
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "time", 0x015);
		PHALCON_CPY_WRT(v2, r0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_format", sizeof("_format")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(p1[0]);
	ZVAL_STRING(p1[0], "%date%", 1);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_dateFormat", sizeof("_dateFormat")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "date", t1, v2, 0x044);
	Z_DELREF_P(t1);
	Z_DELREF_P(v2);
	PG(display_errors) = silence;
	p1[1] = r2;
	p1[2] = v3;
	PHALCON_CALL_FUNC_PARAMS(r1, "str_replace", 3, p1, 0x003);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "%type%", 1);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v1);
	p4[0] = v1;
	PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "gettypestring", 1, p4, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p4[0]);
	p3[1] = r4;
	p3[2] = v3;
	PHALCON_CALL_FUNC_PARAMS(r3, "str_replace", 3, p3, 0x003);
	PHALCON_CPY_WRT(v3, r3);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_INIT_VAR(p5[0]);
	ZVAL_STRING(p5[0], "%message%", 1);
	p5[1] = v0;
	p5[2] = v3;
	PHALCON_CALL_FUNC_PARAMS(r5, "str_replace", 3, p5, 0x003);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setDateFormat){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_dateFormat", strlen("_dateFormat"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the internal date format
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getDateFormat){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dateFormat", sizeof("_dateFormat")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, log){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL }, *p3[] = { NULL, NULL, NULL }, *p6[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Cannot send message to the log because it is invalid", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", v0, 0x038);
	Z_DELREF_P(v0);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "print_r", v0, c0, 0x004);
		PHALCON_CPY_WRT(v2, r1);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_logger_item_class_entry);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		Z_ADDREF_P(v1);
		p3[1] = v1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC(r2, "time", 0x015);
		Z_ADDREF_P(r2);
		p3[2] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		Z_DELREF_P(p3[1]);
		Z_DELREF_P(p3[2]);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_quenue", sizeof("_quenue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(i1);
		phalcon_array_append(t2, i1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_quenue", strlen("_quenue"), t2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		p6[0] = v0;
		Z_ADDREF_P(v1);
		p6[1] = v1;
		PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_applyformat", 2, p6, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p6[0]);
		Z_DELREF_P(p6[1]);
		PHALCON_ALLOC_ZVAL_MM(t4);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		concat_function(r4, r3, t4 TSRMLS_CC);
		Z_ADDREF_P(r4);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", t3, r4, 0x045);
		Z_DELREF_P(t3);
		Z_DELREF_P(r4);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Starts a transaccion
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, begin){


	PHALCON_MM_GROW();
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_transaction", strlen("_transaction"), 1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Commits the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, commit){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "There is no active transaction", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_transaction", strlen("_transaction"), 0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_quenue", sizeof("_quenue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_654f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_654f_1;
		}
		PHALCON_INIT_VAR(v0);
		ZVAL_ZVAL(v0, *hd, 1, 0);
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t2);
		PHALCON_INIT_VAR(r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, v0, "getmessage", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r1);
		p2[0] = r1;
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD(r2, v0, "gettype", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p2[1] = r2;
		PHALCON_INIT_VAR(r3);
		PHALCON_CALL_METHOD(r3, v0, "gettime", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r3);
		p2[2] = r3;
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_applyformat", 3, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_DELREF_P(p2[2]);
		PHALCON_INIT_VAR(t3);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t3 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		concat_function(r4, r0, t3 TSRMLS_CC);
		Z_ADDREF_P(r4);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", t2, r4, 0x045);
		Z_DELREF_P(t2);
		Z_DELREF_P(r4);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_654f_1;
		fee_654f_1:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback){

	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "There is no active transaction", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_transaction", strlen("_transaction"), 0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_quenue", strlen("_quenue"), a0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Closes the logger
  *
  * @return boolean
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, close){

	zval *r0 = NULL;
	zval *t0 = NULL;
	zend_bool silence;

	PHALCON_MM_GROW();
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "fclose", t0, 0x046);
	Z_DELREF_P(t0);
	PG(display_errors) = silence;
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Opens the internal file handler on unserialization
 *
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup){

	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *c0 = NULL;
	zend_bool silence;

	PHALCON_MM_GROW();
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_path", sizeof("_path")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "ab", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "fopen", t0, c0, 0x043);
	PG(display_errors) = silence;
	phalcon_update_property_zval(this_ptr, "_fileHandler", strlen("_fileHandler"), r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Phalcon_Logger_Item
 *
 * Represents each item in a logger transaction
 *
 */

/**
 * Phalcon_Logger_Item contructor
 *
 * @param string $message
 * @param integer $type
 * @param integer $time
 */
PHP_METHOD(Phalcon_Logger_Item, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 0);
	}
	
	phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_time", strlen("_time"), v2 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_message", sizeof("_message")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns the log type
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Logger_Item, getType){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns log timestamp
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Logger_Item, getTime){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_time", sizeof("_time")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Phalcon_Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon_Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon_Transaction_Manager.
 *
 *
 */

/**
 * Phalcon_Transaction constructor
 *
 * @param boolean $autoBegin
 */
PHP_METHOD(Phalcon_Transaction, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_transaction_class_entry, this_ptr, "_messages", strlen("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_BOOL(p0[0], 1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_pool", "getconnection", 1, p0);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), v1 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_CALL_METHOD_NORETURN(v1, "begin", PHALCON_CALL_DEFAULT);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon_Transaction_Manager $manager
 */
PHP_METHOD(Phalcon_Transaction, setTransactionManager){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Starts the transaction
 */
PHP_METHOD(Phalcon_Transaction, begin){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "begin", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Commits the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, commit){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, t1);
		add_next_index_stringl(a0, "notifyCommit", strlen("notifyCommit"), 1);
		Z_ADDREF_P(a0);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(this_ptr);
		PHALCON_SEPARATE_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, a1, 0x010);
		Z_DELREF_P(a0);
		Z_DELREF_P(a1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "commit", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Rollbacks the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon_Model_Base $rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p2[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, t1);
		add_next_index_stringl(a0, "notifyRollback", strlen("notifyRollback"), 1);
		Z_ADDREF_P(a0);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(this_ptr);
		PHALCON_SEPARATE_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, a1, 0x010);
		Z_DELREF_P(a0);
		Z_DELREF_P(a1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "rollback", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t3);
	ZVAL_BOOL(t3, 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v2, t3 TSRMLS_CC);
	if (zend_is_true(r1)) {
		if (PHALCON_COMPARE_STRING(v0, "")) {
			PHALCON_INIT_VAR(v0);
			ZVAL_STRING(v0, "Transaction aborted", 1);
		}
		if (zend_is_true(v1)) {
			phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), v1 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_transaction_failed_class_entry);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_rollbackRecord", sizeof("_rollbackRecord")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t4);
		p2[1] = t4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns connection related to transaction
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Transaction, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "connection_aborted", 0x047);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "The request was aborted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "rollback", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean $isNew
 */
PHP_METHOD(Phalcon_Transaction, setIsNewTransaction){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_isNewTransaction", strlen("_isNewTransaction"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHP_METHOD(Phalcon_Transaction, setRollbackOnAbort){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_rollbackOnAbort", strlen("_rollbackOnAbort"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, isManaged){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, t0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, 0);
		r0 = t2;
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		r0 = t3;
	}
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Changes dependency internal pointer
 *
 * @param int $pointer
 */
PHP_METHOD(Phalcon_Transaction, setDependencyPointer){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Attaches Phalcon_Model_Base object to the active transaction
 *
 * @param int $pointer
 * @param Phalcon_Model_Base $object
 */
PHP_METHOD(Phalcon_Transaction, attachDependency){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t1);
		increment_function(t1);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), t1 TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v1);
		phalcon_array_update(t2, v0, v1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), t2 TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t3, v0);
		PHALCON_INIT_VAR(r1);
		ZVAL_BOOL(r1, eval_int);
		if (!zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v1);
			phalcon_array_update(t4, v0, v1 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), t4 TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(v0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_NMO(t5);
			increment_function(t5);
			phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), t5 TSRMLS_CC);
			PHALCON_CPY_WRT(v0, t5);
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v1);
			phalcon_array_update(t6, v0, v1 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), t6 TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(v0);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Make a bulk save on all attached objects
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, save){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_815a_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_815a_0;
		}
		PHALCON_INIT_VAR(v0);
		ZVAL_ZVAL(v0, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, v0, "save", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 0);
		PHALCON_INIT_VAR(r1);
		is_equal_function(r1, r0, t1 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_METHOD(r2, v0, "getmessages", PHALCON_CALL_DEFAULT);
			phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), r2 TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_815a_0;
		fee_815a_0:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Transaction, getMessages){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
     * Checks whether internal connection is under an active transaction
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Transaction, isValid){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Sets object which generates rollback action
 *
 * @param Phalcon_Model_Base $record
 */
PHP_METHOD(Phalcon_Transaction, setRollbackedRecord){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_MINIT_FUNCTION(phalcon){

	zend_class_entry ce00, ce01, ce02, ce03, ce04, ce05, ce06, ce07, ce08, ce09;
	zend_class_entry ce10, ce11, ce12, ce13, ce14, ce15, ce16, ce17, ce18, ce19;
	zend_class_entry ce20, ce21, ce22, ce23, ce24, ce25, ce26, ce27, ce28, ce29;
	zend_class_entry ce30, ce31, ce32, ce33, ce34, ce35, ce36, ce37, ce38, ce39;
	zend_class_entry ce40, ce41, ce42, ce43, ce44, ce45, ce46, ce47, ce48, ce49;
	zend_class_entry ce50, ce51, ce52, ce53, ce54, ce55, ce56, ce57, ce58, ce59;
	zend_class_entry ce60, ce61, ce62, ce63, ce64, ce65, ce66, ce67, ce68, ce69;
	zend_class_entry ce70, ce71, ce72;


	if(!zend_ce_iterator){
		fprintf(stderr, "Phalcon Error: Interface Iterator was not found");
		return FAILURE;
	}
	if(!spl_ce_SeekableIterator){
		fprintf(stderr, "Phalcon Error: Interface SeekableIterator was not found");
		return FAILURE;
	}
	if(!spl_ce_Countable){
		fprintf(stderr, "Phalcon Error: Interface Countable was not found");
		return FAILURE;
	}

	/** Init globals */
	ZEND_INIT_MODULE_GLOBALS(phalcon, php_phalcon_init_globals, NULL);

	INIT_CLASS_ENTRY(ce00, "Phalcon_Session_Namespace", phalcon_session_namespace_functions);
	phalcon_session_namespace_class_entry = zend_register_internal_class(&ce00 TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_class_entry, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_class_entry, "_data", sizeof("_data")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce01, "Phalcon_Loader", phalcon_loader_functions);
	phalcon_loader_class_entry = zend_register_internal_class(&ce01 TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_class_entry, "_namespaces", sizeof("_namespaces")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_class_entry, "_directories", sizeof("_directories")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce02, "Phalcon_Test", phalcon_test_functions);
	phalcon_test_class_entry = zend_register_internal_class(&ce02 TSRMLS_CC);
	zend_declare_property_null(phalcon_test_class_entry, "p", sizeof("p")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce03, "Phalcon_Router_Rewrite", phalcon_router_rewrite_functions);
	phalcon_router_rewrite_class_entry = zend_register_internal_class(&ce03 TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_controller", sizeof("_controller")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_action", sizeof("_action")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce04, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_class_entry = zend_register_internal_class(&ce04 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_idConnection", sizeof("_idConnection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_profiler", sizeof("_profiler")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce05, "Phalcon_Logger", phalcon_logger_functions);
	phalcon_logger_class_entry = zend_register_internal_class(&ce05 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_class_entry, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "SPECIAL", sizeof("SPECIAL")-1, 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "CUSTOM", sizeof("CUSTOM")-1, 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "DEBUG", sizeof("DEBUG")-1, 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "INFO", sizeof("INFO")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "NOTICE", sizeof("NOTICE")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "WARNING", sizeof("WARNING")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "ERROR", sizeof("ERROR")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "ALERT", sizeof("ALERT")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "CRITICAL", sizeof("CRITICAL")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "EMERGENCE", sizeof("EMERGENCE")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce06, "Phalcon_Cache_Frontend_Output", phalcon_cache_frontend_output_functions);
	phalcon_cache_frontend_output_class_entry = zend_register_internal_class(&ce06 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_class_entry, "_frontendOptions", sizeof("_frontendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce07, "Phalcon_Cache_Backend_File", phalcon_cache_backend_file_functions);
	phalcon_cache_backend_file_class_entry = zend_register_internal_class(&ce07 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_file_class_entry, "_frontendObject", sizeof("_frontendObject")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_file_class_entry, "_backendOptions", sizeof("_backendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_file_class_entry, "_lastKey", sizeof("_lastKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce08, "Phalcon_Acl_Adapter_Memory", phalcon_acl_adapter_memory_functions);
	phalcon_acl_adapter_memory_class_entry = zend_register_internal_class(&ce08 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_rolesNames", sizeof("_rolesNames")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_roles", sizeof("_roles")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_resources", sizeof("_resources")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_access", sizeof("_access")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_roleInherits", sizeof("_roleInherits")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_resourcesNames", sizeof("_resourcesNames")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_accessList", sizeof("_accessList")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_acl_adapter_memory_class_entry, "_defaultAccess", sizeof("_defaultAccess")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce09, "Phalcon_Acl_Role", phalcon_acl_role_functions);
	phalcon_acl_role_class_entry = zend_register_internal_class(&ce09 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_class_entry, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_class_entry, "_description", sizeof("_description")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce10, "Phalcon_Acl_Resource", phalcon_acl_resource_functions);
	phalcon_acl_resource_class_entry = zend_register_internal_class(&ce10 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_class_entry, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_class_entry, "_description", sizeof("_description")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce11, "Phalcon_Cache", phalcon_cache_functions);
	phalcon_cache_class_entry = zend_register_internal_class(&ce11 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce12, "Phalcon_View", phalcon_view_functions);
	phalcon_view_class_entry = zend_register_internal_class(&ce12 TSRMLS_CC);
	zend_declare_property_string(phalcon_view_class_entry, "_content", sizeof("_content")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_view_class_entry, "_renderLevel", sizeof("_renderLevel")-1, 5, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_class_entry, "_layoutsDir", sizeof("_layoutsDir")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_templatesBefore", sizeof("_templatesBefore")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_templatesAfter", sizeof("_templatesAfter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_controllerName", sizeof("_controllerName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_actionName", sizeof("_actionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_MAIN_LAYOUT", sizeof("LEVEL_MAIN_LAYOUT")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_AFTER_TEMPLATE", sizeof("LEVEL_AFTER_TEMPLATE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_LAYOUT", sizeof("LEVEL_LAYOUT")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_BEFORE_TEMPLATE", sizeof("LEVEL_BEFORE_TEMPLATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_ACTION_VIEW", sizeof("LEVEL_ACTION_VIEW")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_NO_RENDER", sizeof("LEVEL_NO_RENDER")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce13, "Phalcon_Paginator_Adapter_Array", phalcon_paginator_adapter_array_functions);
	phalcon_paginator_adapter_array_class_entry = zend_register_internal_class(&ce13 TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_class_entry, "_limitRows", sizeof("_limitRows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_class_entry, "_config", sizeof("_config")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_class_entry, "_page", sizeof("_page")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce14, "Phalcon_Paginator_Adapter_Model", phalcon_paginator_adapter_model_functions);
	phalcon_paginator_adapter_model_class_entry = zend_register_internal_class(&ce14 TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_class_entry, "_limitRows", sizeof("_limitRows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_class_entry, "_config", sizeof("_config")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_class_entry, "_page", sizeof("_page")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce15, "Phalcon_Controller", phalcon_controller_functions);
	phalcon_controller_class_entry = zend_register_internal_class(&ce15 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "_view", sizeof("_view")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "request", sizeof("request")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "response", sizeof("response")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "view", sizeof("view")-1, ZEND_ACC_PUBLIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce16, "Phalcon_Paginator", phalcon_paginator_functions);
	phalcon_paginator_class_entry = zend_register_internal_class(&ce16 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce17, "Phalcon_Utils", phalcon_utils_functions);
	phalcon_utils_class_entry = zend_register_internal_class(&ce17 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce18, "Phalcon_Dispatcher", phalcon_dispatcher_functions);
	phalcon_dispatcher_class_entry = zend_register_internal_class(&ce18 TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_finished", sizeof("_finished")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_controllersDir", sizeof("_controllersDir")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_basePath", sizeof("_basePath")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_controllerName", sizeof("_controllerName")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_actionName", sizeof("_actionName")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_returnedValue", sizeof("_returnedValue")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_lastController", sizeof("_lastController")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_defaultController", sizeof("_defaultController")-1, "index", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_defaultAction", sizeof("_defaultAction")-1, "index", ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce19, "Phalcon_Db_Pool", phalcon_db_pool_functions);
	phalcon_db_pool_class_entry = zend_register_internal_class(&ce19 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce20, "Phalcon_Db_Profiler", phalcon_db_profiler_functions);
	phalcon_db_profiler_class_entry = zend_register_internal_class(&ce20 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_class_entry, "_allProfiles", sizeof("_allProfiles")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_class_entry, "_activeProfile", sizeof("_activeProfile")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_profiler_class_entry, "_totalSeconds", sizeof("_totalSeconds")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce21, "Phalcon_Db_Reference", phalcon_db_reference_functions);
	phalcon_db_reference_class_entry = zend_register_internal_class(&ce21 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_referenceName", sizeof("_referenceName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_referencedTable", sizeof("_referencedTable")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_columns", sizeof("_columns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_referencedColumns", sizeof("_referencedColumns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce22, "Phalcon_Db_Profiler_Item", phalcon_db_profiler_item_functions);
	phalcon_db_profiler_item_class_entry = zend_register_internal_class(&ce22 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_class_entry, "_sqlStatement", sizeof("_sqlStatement")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_class_entry, "_initialTime", sizeof("_initialTime")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_class_entry, "_finalTime", sizeof("_finalTime")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce23, "Phalcon_Db_RawValue", phalcon_db_rawvalue_functions);
	phalcon_db_rawvalue_class_entry = zend_register_internal_class(&ce23 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_rawvalue_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce24, "Phalcon_Db_Column", phalcon_db_column_functions);
	phalcon_db_column_class_entry = zend_register_internal_class(&ce24 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_columnName", sizeof("_columnName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_schemaName", sizeof("_schemaName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_class_entry, "_size", sizeof("_size")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_class_entry, "_scale", sizeof("_scale")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_unsigned", sizeof("_unsigned")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_notNull", sizeof("_notNull")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_autoIncrement", sizeof("_autoIncrement")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_first", sizeof("_first")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_after", sizeof("_after")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_INTEGER", sizeof("TYPE_INTEGER")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_DATE", sizeof("TYPE_DATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_VARCHAR", sizeof("TYPE_VARCHAR")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_DECIMAL", sizeof("TYPE_DECIMAL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_DATETIME", sizeof("TYPE_DATETIME")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_CHAR", sizeof("TYPE_CHAR")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_TEXT", sizeof("TYPE_TEXT")-1, 6 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce25, "Phalcon_Db_Index", phalcon_db_index_functions);
	phalcon_db_index_class_entry = zend_register_internal_class(&ce25 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_index_class_entry, "_indexName", sizeof("_indexName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce26, "Phalcon_Db_Dialect_Mysql", phalcon_db_dialect_mysql_functions);
	phalcon_db_dialect_mysql_class_entry = zend_register_internal_class(&ce26 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce27, "Phalcon_Model_Query", phalcon_model_query_functions);
	phalcon_model_query_class_entry = zend_register_internal_class(&ce27 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_data", sizeof("_data")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_models", sizeof("_models")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_parameters", sizeof("_parameters")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_conditions", sizeof("_conditions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_limit", sizeof("_limit")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce28, "Phalcon_Model_Base", phalcon_model_base_functions);
	phalcon_model_base_class_entry = zend_register_internal_class(&ce28 TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_uniqueKey", sizeof("_uniqueKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_connection", sizeof("_connection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_schema", sizeof("_schema")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_source", sizeof("_source")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_isView", sizeof("_isView")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_dumped", sizeof("_dumped")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_dumpLock", sizeof("_dumpLock")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_errorMessages", sizeof("_errorMessages")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_operationMade", sizeof("_operationMade")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_forceExists", sizeof("_forceExists")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_defaultConnection", sizeof("_defaultConnection")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_connectionName", sizeof("_connectionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_refreshPersistance", sizeof("_refreshPersistance")-1, 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_class_entry, "OP_CREATE", sizeof("OP_CREATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_class_entry, "OP_UPDATE", sizeof("OP_UPDATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_class_entry, "OP_DELETE", sizeof("OP_DELETE")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce29, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_class_entry = zend_register_internal_class(&ce29 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_fieldName", sizeof("_fieldName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce30, "Phalcon_Model_Row", phalcon_model_row_functions);
	phalcon_model_row_class_entry = zend_register_internal_class(&ce30 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_class_entry, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_class_entry, "_columns", sizeof("_columns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce31, "Phalcon_Model_Sanitize", phalcon_model_sanitize_functions);
	phalcon_model_sanitize_class_entry = zend_register_internal_class(&ce31 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce32, "Phalcon_Model_MetaData", phalcon_model_metadata_functions);
	phalcon_model_metadata_class_entry = zend_register_internal_class(&ce32 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES", sizeof("MODELS_ATTRIBUTES")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY", sizeof("MODELS_PRIMARY_KEY")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY", sizeof("MODELS_NON_PRIMARY_KEY")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_NOT_NULL", sizeof("MODELS_NOT_NULL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE", sizeof("MODELS_DATA_TYPE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC", sizeof("MODELS_DATA_TYPE_NUMERIC")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATE_AT", sizeof("MODELS_DATE_AT")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATE_IN", sizeof("MODELS_DATE_IN")-1, 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_IDENTITY_FIELD", sizeof("MODELS_IDENTITY_FIELD")-1, 8 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce33, "Phalcon_Model_Message", phalcon_model_message_functions);
	phalcon_model_message_class_entry = zend_register_internal_class(&ce33 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_class_entry, "_message", sizeof("_message")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce34, "Phalcon_Model_Manager", phalcon_model_manager_functions);
	phalcon_model_manager_class_entry = zend_register_internal_class(&ce34 TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_manager_class_entry, "_connection", sizeof("_connection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_metadata", sizeof("_metadata")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_modelsDir", sizeof("_modelsDir")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_hasMany", sizeof("_hasMany")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_hasOne", sizeof("_hasOne")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_belongsTo", sizeof("_belongsTo")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_metadataOptions", sizeof("_metadataOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce35, "Phalcon_Model_MetaData_Memory", phalcon_model_metadata_memory_functions);
	phalcon_model_metadata_memory_class_entry = zend_register_internal_class(&ce35 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce36, "Phalcon_Model_MetaData_Session", phalcon_model_metadata_session_functions);
	phalcon_model_metadata_session_class_entry = zend_register_internal_class(&ce36 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce37, "Phalcon_Model_Resultset", phalcon_model_resultset_functions);
	phalcon_model_resultset_class_entry = zend_register_internal_class(&ce37 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_model", sizeof("_model")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_resultResource", sizeof("_resultResource")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_model_resultset_class_entry, "_pointer", sizeof("_pointer")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_count", sizeof("_count")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_activeRow", sizeof("_activeRow")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_model_resultset_class_entry TSRMLS_CC, 3, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable);

	INIT_CLASS_ENTRY(ce38, "Phalcon_Tag", phalcon_tag_functions);
	phalcon_tag_class_entry = zend_register_internal_class(&ce38 TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce39, "Phalcon_Response", phalcon_response_functions);
	phalcon_response_class_entry = zend_register_internal_class(&ce39 TSRMLS_CC);
	zend_declare_property_null(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_response_class_entry, "_content", sizeof("_content")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce40, "Phalcon_Request", phalcon_request_functions);
	phalcon_request_class_entry = zend_register_internal_class(&ce40 TSRMLS_CC);
	zend_declare_property_null(phalcon_request_class_entry, "_filter", sizeof("_filter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce41, "Phalcon_Transaction_Manager", phalcon_transaction_manager_functions);
	phalcon_transaction_manager_class_entry = zend_register_internal_class(&ce41 TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce42, "Phalcon_Controller_Front", phalcon_controller_front_functions);
	phalcon_controller_front_class_entry = zend_register_internal_class(&ce42 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_controllersDir", sizeof("_controllersDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_modelsDir", sizeof("_modelsDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_viewsDir", sizeof("_viewsDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_basePath", sizeof("_basePath")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_model", sizeof("_model")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_view", sizeof("_view")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_request", sizeof("_request")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_response", sizeof("_response")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce43, "Phalcon_Session", phalcon_session_functions);
	phalcon_session_class_entry = zend_register_internal_class(&ce43 TSRMLS_CC);
	zend_declare_property_null(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_session_class_entry, "_options", sizeof("_options")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce44, "Phalcon_Flash", phalcon_flash_functions);
	phalcon_flash_class_entry = zend_register_internal_class(&ce44 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce45, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_class_entry = zend_register_internal_class(&ce45 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce46, "Phalcon_Filter", phalcon_filter_functions);
	phalcon_filter_class_entry = zend_register_internal_class(&ce46 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce47, "Phalcon_Acl", phalcon_acl_functions);
	phalcon_acl_class_entry = zend_register_internal_class(&ce47 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_class_entry, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_class_entry, "ALLOW", sizeof("ALLOW")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_class_entry, "DENY", sizeof("DENY")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce48, "Phalcon_Logger_Adapter_File", phalcon_logger_adapter_file_functions);
	phalcon_logger_adapter_file_class_entry = zend_register_internal_class(&ce48 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_class_entry, "_fileHandler", sizeof("_fileHandler")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_class_entry, "_transaction", sizeof("_transaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_class_entry, "_quenue", sizeof("_quenue")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_class_entry, "_dateFormat", sizeof("_dateFormat")-1, "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_class_entry, "_format", sizeof("_format")-1, "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce49, "Phalcon_Logger_Item", phalcon_logger_item_functions);
	phalcon_logger_item_class_entry = zend_register_internal_class(&ce49 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_class_entry, "message", sizeof("message")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_class_entry, "_time", sizeof("_time")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce50, "Phalcon_Transaction", phalcon_transaction_functions);
	phalcon_transaction_class_entry = zend_register_internal_class(&ce50 TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_class_entry, "_activeTransaction", sizeof("_activeTransaction")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_class_entry, "_isNewTransaction", sizeof("_isNewTransaction")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_class_entry, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_class_entry, "_pointer", sizeof("_pointer")-1, 255, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_dependencies", sizeof("_dependencies")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_rollbackRecord", sizeof("_rollbackRecord")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce51, "Phalcon_Exception", phalcon_exception_functions);
	phalcon_exception_class_entry = zend_register_internal_class_ex(&ce51, NULL, "exception" TSRMLS_CC);
	if(!phalcon_exception_class_entry){
		phalcon_inherit_not_found("Exception", "Phalcon_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce52, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_class_entry = zend_register_internal_class(&ce52 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce53, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_class_entry = zend_register_internal_class(&ce53 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_idConnection", sizeof("_idConnection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_profiler", sizeof("_profiler")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce54, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_class_entry = zend_register_internal_class(&ce54 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_fieldName", sizeof("_fieldName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce55, "Phalcon_Config_Exception", phalcon_config_exception_functions);
	phalcon_config_exception_class_entry = zend_register_internal_class_ex(&ce55, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_config_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Config_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce56, "Phalcon_Config_Adapter_Ini", phalcon_config_adapter_ini_functions);
	phalcon_config_adapter_ini_class_entry = zend_register_internal_class_ex(&ce56, NULL, "phalcon_config" TSRMLS_CC);
	if(!phalcon_config_adapter_ini_class_entry){
		phalcon_inherit_not_found("Phalcon_Config", "Phalcon_Config_Adapter_Ini");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce57, "Phalcon_Cache_Exception", phalcon_cache_exception_functions);
	phalcon_cache_exception_class_entry = zend_register_internal_class_ex(&ce57, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_cache_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Cache_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce58, "Phalcon_Acl_Exception", phalcon_acl_exception_functions);
	phalcon_acl_exception_class_entry = zend_register_internal_class_ex(&ce58, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_acl_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Acl_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce59, "Phalcon_View_Exception", phalcon_view_exception_functions);
	phalcon_view_exception_class_entry = zend_register_internal_class_ex(&ce59, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_view_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_View_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce60, "Phalcon_Paginator_Exception", phalcon_paginator_exception_functions);
	phalcon_paginator_exception_class_entry = zend_register_internal_class_ex(&ce60, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_paginator_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Paginator_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce61, "Phalcon_Tag_Exception", phalcon_tag_exception_functions);
	phalcon_tag_exception_class_entry = zend_register_internal_class_ex(&ce61, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_tag_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Tag_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce62, "Phalcon_Db_Exception", phalcon_db_exception_functions);
	phalcon_db_exception_class_entry = zend_register_internal_class_ex(&ce62, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_db_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Db_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce63, "Phalcon_Db_Adapter_Mysql", phalcon_db_adapter_mysql_functions);
	phalcon_db_adapter_mysql_class_entry = zend_register_internal_class_ex(&ce63, NULL, "phalcon_db" TSRMLS_CC);
	if(!phalcon_db_adapter_mysql_class_entry){
		phalcon_inherit_not_found("Phalcon_Db", "Phalcon_Db_Adapter_Mysql");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce64, "Phalcon_Model_Validator_Uniqueness", phalcon_model_validator_uniqueness_functions);
	phalcon_model_validator_uniqueness_class_entry = zend_register_internal_class_ex(&ce64, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_uniqueness_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Uniqueness");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce65, "Phalcon_Model_Validator_Exclusionin", phalcon_model_validator_exclusionin_functions);
	phalcon_model_validator_exclusionin_class_entry = zend_register_internal_class_ex(&ce65, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_exclusionin_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Exclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce66, "Phalcon_Model_Validator_Regex", phalcon_model_validator_regex_functions);
	phalcon_model_validator_regex_class_entry = zend_register_internal_class_ex(&ce66, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_regex_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Regex");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce67, "Phalcon_Model_Validator_Inclusionin", phalcon_model_validator_inclusionin_functions);
	phalcon_model_validator_inclusionin_class_entry = zend_register_internal_class_ex(&ce67, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_inclusionin_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Inclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce68, "Phalcon_Model_Validator_Numericality", phalcon_model_validator_numericality_functions);
	phalcon_model_validator_numericality_class_entry = zend_register_internal_class_ex(&ce68, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_numericality_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Numericality");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce69, "Phalcon_Model_Validator_Email", phalcon_model_validator_email_functions);
	phalcon_model_validator_email_class_entry = zend_register_internal_class_ex(&ce69, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_email_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Email");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce70, "Phalcon_Model_Exception", phalcon_model_exception_functions);
	phalcon_model_exception_class_entry = zend_register_internal_class_ex(&ce70, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_model_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Model_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce71, "Phalcon_Transaction_Failed", phalcon_transaction_failed_functions);
	phalcon_transaction_failed_class_entry = zend_register_internal_class_ex(&ce71, NULL, "exception" TSRMLS_CC);
	if(!phalcon_transaction_failed_class_entry){
		phalcon_inherit_not_found("Exception", "Phalcon_Transaction_Failed");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_transaction_failed_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce72, "Phalcon_Logger_Exception", phalcon_logger_exception_functions);
	phalcon_logger_exception_class_entry = zend_register_internal_class_ex(&ce72, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_logger_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Logger_Exception");
		return FAILURE;
	}
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phalcon){
	return SUCCESS;
}

PHP_RINIT_FUNCTION(phalcon){
	
	/*return phalcon_init_fcall_cache();*/
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(phalcon){
	
	/*return phalcon_free_fcall_cache();*/
	return SUCCESS;
}

zend_module_entry phalcon_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_PHALCON_EXTNAME,
	NULL,
	PHP_MINIT(phalcon),
	PHP_MSHUTDOWN(phalcon),
	PHP_RINIT(phalcon),
	PHP_RSHUTDOWN(phalcon),
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHALCON_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHALCON
ZEND_GET_MODULE(phalcon)
#endif


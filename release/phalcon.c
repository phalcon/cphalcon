
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

//Main macros

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

#define INIT_PARAM(x) ALLOC_ZVAL(x); INIT_PZVAL(x);

#if defined(HAVE_SPL) && ((PHP_MAJOR_VERSION > 5) || (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION >= 1))
extern ZEND_API zend_class_entry *zend_ce_iterator;
extern ZEND_API zend_class_entry *zend_ce_arrayaccess;
extern PHPAPI zend_class_entry *spl_ce_RuntimeException;
extern PHPAPI zend_class_entry *spl_ce_Countable;
extern PHPAPI zend_class_entry *spl_ce_SeekableIterator;
#endif

//Globals functions
int phalcon_init_global(char *global TSRMLS_DC);
int phalcon_get_global(zval *arr, char *global, int global_type TSRMLS_DC);
int phalcon_get_global_by_index(char *global, char *index, zval *result TSRMLS_DC);

int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC);

//Logical functions
int phalcon_and_function(zval *result, zval *left, zval *right);

//Concat functions
int phalcon_concat_right(zval **result, zval *op1, char *op2 TSRMLS_DC);
int phalcon_concat_left(zval **result, char *op1, zval *op2 TSRMLS_DC);
int phalcon_concat_both(zval **res, char *op1, zval *op2, char *op3 TSRMLS_DC);
int phalcon_concat_vboth(zval **res, zval *op1, char *op2, zval *op3 TSRMLS_DC);

int phalcon_compare_strict_string(zval *op1, char *op2);

int phalcon_file_exists(zval *filename TSRMLS_DC);

//Low level filters
int phalcon_filter_alphanum(zval **result, zval *param);

//Memory macros

#define PHALCON_ALLOC_ZVAL(z) \
	ALLOC_ZVAL(z); INIT_PZVAL(z);

#define PHALCON_RESULT_INIT(var) \
	if(!var){\
		PHALCON_ALLOC_ZVAL(var);\
		Z_ADDREF_P(var);\
	} else {\
		if(Z_REFCOUNT_P(var)>1){\
			SEPARATE_ZVAL(&var);\
		} else {\
			FREE_ZVAL(var);\
   			ALLOC_ZVAL(var);\
   			Z_SET_REFCOUNT_P(var, 1);\
   			Z_UNSET_ISREF_P(var);\
		}\
	}

#define PHALCON_VAR_INIT(var) \
	if(!var){\
		PHALCON_ALLOC_ZVAL(var);\
		Z_ADDREF_P(var);\
	} else {\
		if(Z_REFCOUNT_P(var)>1){\
			SEPARATE_ZVAL(&var);\
		} else {\
			FREE_ZVAL(var);\
   			ALLOC_ZVAL(var);\
   			Z_SET_REFCOUNT_P(var, 1);\
   			Z_UNSET_ISREF_P(var);\
		}\
	}

#define PHALCON_SEPARATE(copy, origvar) Z_DELREF_P(origvar);\
	PHALCON_ALLOC_ZVAL(copy);\
	if(Z_REFCOUNT_P(origvar)<1){\
		ZVAL_ZVAL(copy, origvar, 1, 1);\
	} else {\
		ZVAL_ZVAL(copy, origvar, 1, 0);\
	}\
	Z_SET_REFCOUNT_P(copy, 1);\
	Z_UNSET_ISREF_P(copy);

#define PHALCON_SHADOW_SEPARATE(var) {\
		zval *copy;\
		PHALCON_SEPARATE(copy, var);\
		var = copy;\
	}

#define PHALCON_CPY_WRT(destiny, value) \
	if(!destiny||Z_REFCOUNT_P(value)==1){\
		Z_ADDREF_P(value);\
		destiny = value;\
	} else {\
		PHALCON_SEPARATE(destiny, value);\
	}

#define PHALCON_FREE(v) if(v){ if(Z_REFCOUNT_P(v)<=1){ FREE_ZVAL(v); }}


//Control flow macros
#define FOREACH_KV(var, varcopy, slabel, elabel, arrval, pointer, key, value) \
			if(Z_TYPE_P(var)!=IS_ARRAY){\
               zend_error(E_WARNING, "Invalid argument supplied for foreach()");\
			} else {\
				if(!value){\
					PHALCON_ALLOC_ZVAL(value);\
				}\
				PHALCON_ALLOC_ZVAL(varcopy);\
				ZVAL_ZVAL(varcopy, var, 1, 0);\
				Z_SET_REFCOUNT_P(varcopy, 1);\
				arrval = Z_ARRVAL_P(varcopy);\
				zend_hash_internal_pointer_reset_ex(arrval, &pointer);\
				slabel:\
				if(zend_hash_get_current_data_ex(arrval, (void**) &hd, &pointer) != SUCCESS){\
					goto elabel;\
				} else {\
					if(!key){\
						PHALCON_ALLOC_ZVAL(key);\
					}\
					htype = zend_hash_get_current_key_ex(arrval, &index, &index_len, &num, 0, &pointer);\
					if(htype==HASH_KEY_IS_STRING){\
						ZVAL_STRING(key, index, 1);\
					} else {\
						if(htype==HASH_KEY_IS_LONG){\
							ZVAL_LONG(key, num);\
						}\
					}\
				}\
				*value = **hd;

#define FOREACH_V(var, varcopy, slabel, elabel, arrval, pointer, value) \
		if(Z_TYPE_P(var)!=IS_ARRAY){\
			zend_error(E_WARNING, "Invalid argument supplied for foreach()");\
		} else {\
			if(!value) PHALCON_ALLOC_ZVAL(value);\
			PHALCON_ALLOC_ZVAL(varcopy);\
			ZVAL_ZVAL(varcopy, var, 1, 0);\
			arrval = Z_ARRVAL_P(varcopy);\
			zend_hash_internal_pointer_reset_ex(arrval, &pointer);\
			slabel:\
			if(zend_hash_get_current_data_ex(arrval, (void**) &hd, &pointer) != SUCCESS){\
				goto elabel;\
			}\
			*value = **hd;

#define END_FOREACH(varcopy, slabel, elabel, arrval, pointer) zend_hash_move_forward_ex(arrval, &pointer);\
		goto slabel;\
		elabel:\
		PHALCON_FREE(varcopy);\
		num = 0;\
		}


//Variables
#define PHALCON_SET_LONG(var, vlong) PHALCON_VAR_INIT(var); ZVAL_LONG(var, vlong)
#define PHALCON_SET_STRING(var, str, alloc) PHALCON_VAR_INIT(var); ZVAL_STRING(var, str, alloc)
#define PHALCON_INIT_DOUBLE(var, vdouble) PHALCON_VAR_INIT(var); ZVAL_DOUBLE(var, vdouble)
#define PHALCON_INIT_NULL(var) PHALCON_VAR_INIT(var); ZVAL_NULL(var)
#define PHALCON_INIT_BOOL(var, bvalue) PHALCON_VAR_INIT(var); ZVAL_BOOL(var, bvalue)
#define PHALCON_INIT_FALSE(var) PHALCON_VAR_INIT(var); ZVAL_BOOL(var, 0)
#define PHALCON_INIT_TRUE(var) PHALCON_VAR_INIT(var); ZVAL_BOOL(var, 1)
#define PHALCON_INIT_ZVAL(var, value) PHALCON_VAR_INIT(var, value);
#define PHALCON_INIT_ARRAY(var) PHALCON_VAR_INIT(var); array_init(var)

//Funcion and method params
#define PHALCON_PARAM_STRING(param, str, cpy) INIT_PARAM(param); ZVAL_STRING(param, str, cpy)
#define PHALCON_PARAM_LONG(param, vlong) INIT_PARAM(param); ZVAL_LONG(param, vlong)
#define PHALCON_PARAM_ZVAL(param, value) INIT_PARAM(param); ZVAL_ZVAL(param, value, 1, 0)
#define PHALCON_PARAM_CPY(param, value) INIT_PZVAL(value); param = value;

//New
#define PHALCON_NEW_STD(object) PHALCON_ALLOC_ZVAL(object); object_init(object)
#define PHALCON_NEW(object, class) PHALCON_ALLOC_ZVAL(object); object_init_ex(object, class)

//Operators
#define PHALCON_EQUAL_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); is_equal_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_NOT_EQUAL_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); is_not_equal_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_SMALLER_EQUAL_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); is_smaller_or_equal_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_SMALLER_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); is_smaller_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_IDENTICAL_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); is_identical_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_NOT_IDENTICAL_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); is_not_identical_function(result, op1, op2 TSRMLS_CC)

#define PHALCON_ADD_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); add_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_SUB_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); sub_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_MUL_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); mul_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_DIV_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); div_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_MOD_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); mod_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_CONCAT_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); concat_function(result, op1, op2 TSRMLS_CC)

#define PHALCON_BITWISE_OR_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); bitwise_or_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_BITWISE_AND_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); bitwise_and_function(result, op1, op2 TSRMLS_CC)

#define PHALCON_AND_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); phalcon_and_function(result, op1, op2)
#define PHALCON_OR_FUNCTION(result, op1, op2) PHALCON_RESULT_INIT(result); ZVAL_BOOL(result, zend_is_true(op1) || zend_is_true(op2))

#define PHALCON_BOOLEAN_NOT_FUNCTION(result, op1) PHALCON_RESULT_INIT(result); boolean_not_function(result, op1 TSRMLS_CC)

//Constants
#define PHALCON_GET_CONSTANT(var, name) PHALCON_VAR_INIT(var); zend_get_constant(name, strlen(name), var TSRMLS_CC)
#define PHALCON_GET_CLASS_CONSTANT(var, class_entry, name) PHALCON_VAR_INIT(var); phalcon_get_class_constant(var, class_entry, name, strlen(name) TSRMLS_CC)

//Symbols
#define PHALCON_READ_SYMBOL(var, auxarr, name) if(EG(active_symbol_table)){\
			if(zend_hash_find(EG(active_symbol_table), name, sizeof(name), (void **)  &auxarr)==SUCCESS){\
				var = *auxarr;\
			} else {\
				ZVAL_NULL(var);\
			}\
		} else {\
			ZVAL_NULL(var);\
		}

//Instance of
#define PHALCON_INSTANCE_OF(result, var, class)	if(Z_TYPE_P(var)!=IS_OBJECT){\
			zend_error(E_ERROR, "instanceof expects an object instance, constant given");\
		} else {\
			PHALCON_RESULT_INIT(result);\
			ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(var), class TSRMLS_CC));\
		}

//Globals
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

int phalcon_call_func(zval *return_value, char *func_name, int noreturn TSRMLS_DC);
int phalcon_call_func_params(zval *return_value, char *func_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

int phalcon_call_method(zval *return_value, zval *object, char *method_name, int check, int noreturn TSRMLS_DC);
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int check, int noreturn TSRMLS_DC);

int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, char *method_name, int noreturn TSRMLS_DC);
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

int phalcon_call_static_func(zval *return_value, char *class_name, char *method_name, int noreturn TSRMLS_DC);
int phalcon_call_static_func_params(zval *return_value, char *class_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

int phalcon_is_callable_check_class(const char *name, int name_len, zend_fcall_info_cache *fcc, int *strict_class, char **error TSRMLS_DC);
int phalcon_is_callable_check_func(int check_flags, zval *callable, zend_fcall_info_cache *fcc, int strict_class, char **error TSRMLS_DC);

extern zend_bool phalcon_is_callable_ex(zval *callable, zval *object_ptr, uint check_flags, char **callable_name, int *callable_name_len, zend_fcall_info_cache *fcc, char **error TSRMLS_DC);
int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC);
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC);

int phalcon_find_scope(zend_class_entry *ce, char *method_name TSRMLS_DC);
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, char *method_name TSRMLS_DC);

#ifndef PHP_WIN32
int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
#endif

#define PHALCON_CALL_FUNC(return_value, func_name) PHALCON_RESULT_INIT(return_value); phalcon_call_func(return_value, func_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_NORETURN(func_name) phalcon_call_func(NULL, func_name, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS(return_value, func_name, param_count, params) PHALCON_RESULT_INIT(return_value); phalcon_call_func_params(return_value, func_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_NORETURN(func_name, param_count, params) PHALCON_RESULT_INIT(return_value); phalcon_call_func_params(NULL, func_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_METHOD(return_value, object, method_name, check) PHALCON_RESULT_INIT(return_value); phalcon_call_method(return_value, object, method_name, check, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_NORETURN(object, method_name, check) phalcon_call_method(NULL, object, method_name, check, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_PARAMS(return_value, object, method_name, param_count, params, check) PHALCON_RESULT_INIT(return_value); phalcon_call_method_params(return_value, object, method_name, param_count, params, check, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_PARAMS_NORETURN(object, method_name, param_count, params, check) phalcon_call_method_params(NULL, object, method_name, param_count, params, check, 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_PARENT_PARAMS(return_value, object, active_class, method_name, param_count, params) PHALCON_RESULT_INIT(return_value); phalcon_call_parent_func_params(return_value, object, active_class, method_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT_PARAMS_NORETURN(object, active_class, method_name, param_count, params) phalcon_call_parent_func_params(NULL, object, active_class, method_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT(return_value, object, active_class, method_name, param_count, params) PHALCON_RESULT_INIT(return_value); phalcon_call_parent_func(return_value, object, active_class, method_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT_NORETURN(object, active_class, method_name) phalcon_call_parent_func(NULL, object, active_class, method_name, 0 TSRMLS_CC); if(EG(exception)) return;

#define PHALCON_CALL_STATIC_PARAMS(return_value, class_name, method_name, param_count, params) PHALCON_RESULT_INIT(return_value); phalcon_call_static_func_params(return_value, class_name, method_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_PARAMS_NORETURN(class_name, method_name, param_count, params) phalcon_call_static_func_params(NULL, class_name, method_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC(return_value, class_name, method_name) PHALCON_RESULT_INIT(return_value); phalcon_call_static_func(return_value, class_name, method_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_NORETURN(class_name, method_name) phalcon_call_static_func(NULL, class_name, method_name, 0 TSRMLS_CC); if(EG(exception)) return


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

int phalcon_require(zval *require_path TSRMLS_DC);
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

int phalcon_print_r(zval *userval TSRMLS_DC);
int phalcon_vdump(zval *uservar TSRMLS_DC);
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

#ifndef PHALCON_RELEASE

int phalcon_assert_class(zval *object, char *class_name TSRMLS_DC);

#endif
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

#define PHALCON_READ_PROPERTY_NOISY(result, object, property_name, property_length) PHALCON_VAR_INIT(result); phalcon_read_property(result, object, property_name, property_length, PHALCON_NOISY_FETCH TSRMLS_CC);
#define PHALCON_READ_PROPERTY_SILENT(result, object, property_name, property_length) PHALCON_VAR_INIT(result); phalcon_read_property(result, object, property_name, property_length, PHALCON_SILENT_FETCH TSRMLS_CC);

int phalcon_class_exists(zval *return_value, zval *class_name_zval, zval *autoload_zval TSRMLS_DC);
int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC);
int phalcon_clone(zval **dst, zval *obj TSRMLS_DC);

int phalcon_read_property(zval *result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC);

int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC);
int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC);
int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC);


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

#define PHALCON_ARRFETCH_NOISY(result, arr, index) PHALCON_RESULT_INIT(result); phalcon_array_fetch(result, arr, index, PHALCON_NOISY_FETCH TSRMLS_CC);
#define PHALCON_ARRFETCH_SILENT(result, arr, index) PHALCON_RESULT_INIT(result); phalcon_array_fetch(result, arr, index, PHALCON_SILENT_FETCH TSRMLS_CC);
#define PHALCON_ARRFETCH_LONG_NOISY(result, arr, lindex) PHALCON_RESULT_INIT(result); phalcon_array_fetch_long(result, arr, lindex, PHALCON_NOISY_FETCH TSRMLS_CC);
#define PHALCON_ARRFETCH_LONG_SILENT(result, arr, lindex) PHALCON_RESULT_INIT(result); phalcon_array_fetch_long(result, arr, lindex, PHALCON_SILENT_FETCH TSRMLS_CC);
#define PHALCON_ARRFETCH_STRING_NOISY(result, arr, sindex) PHALCON_RESULT_INIT(result); phalcon_array_fetch_string(result, arr, sindex, PHALCON_NOISY_FETCH TSRMLS_CC);
#define PHALCON_ARRFETCH_STRING_SILENT(result, arr, sindex) PHALCON_RESULT_INIT(result); phalcon_array_fetch_string(result, arr, sindex, PHALCON_SILENT_FETCH TSRMLS_CC);

#define PHALCON_ARRAPPEND(arr, value) SEPARATE_ZVAL(&value); phalcon_array_append(arr, value TSRMLS_CC);
#define PHALCON_ARRUPDATE(arr, index, value) SEPARATE_ZVAL(&value); phalcon_array_update(arr, index, value TSRMLS_CC);

int phalcon_array_append(zval *arr, zval *value TSRMLS_DC);

int phalcon_array_update(zval *arr, zval *index, zval *value TSRMLS_DC);
int phalcon_array_update_string(zval *arr, char *index, zval *value TSRMLS_DC);
int phalcon_array_update_long(zval *arr, ulong index, zval *value TSRMLS_DC);

int phalcon_array_fetch(zval *return_value, zval *arr, zval *index, int silent TSRMLS_DC);
int phalcon_array_fetch_string(zval *return_value, zval *arr, char *index, int silent TSRMLS_DC);
int phalcon_array_fetch_long(zval *return_value, zval *arr, ulong index, int silent TSRMLS_DC);


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
#endif


/**
 * Initilializes super global variables if doesn't
 */
int phalcon_init_global(char *global TSRMLS_DC){
	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));
	if(jit_initialization){
		return zend_is_auto_global(global, sizeof(global)-1 TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Gets the global zval into PG macro
 */
int phalcon_get_global(zval *arr, char *global, int global_type TSRMLS_DC){
	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));
	if(jit_initialization){
		zend_is_auto_global(global, sizeof(global)-1 TSRMLS_CC);
	}
	arr = PG(http_globals)[global_type];
	return SUCCESS;
}

/**
 * Get a super global zval by its name
 */
int phalcon_get_global_by_index(char *global, char *index, zval *result TSRMLS_DC){
	zval **global_vars;
	if(zend_hash_find(&EG(symbol_table), global, sizeof(global), (void **) &global_vars)==SUCCESS){
		if(Z_TYPE_PP(global_vars)==IS_ARRAY){
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

	if(zend_hash_find(&ce->constants_table, constant_name, constant_length+1, (void **) &result_ptr) != SUCCESS){
		zend_error_noreturn(E_ERROR, "Undefined class constant '%s::%s'", ce->name, constant_name);
		return FAILURE;
	} else {
		*return_value  = **result_ptr;
	}

	return SUCCESS;
}

/**
 * Performs logical AND function operator
 */
int phalcon_and_function(zval *result, zval *left, zval *right){
	int istrue = 1;
	istrue = zend_is_true(left);
	if(istrue){
		istrue = zend_is_true(right);
	}
	ZVAL_BOOL(result, istrue);
	return SUCCESS;
}

/**
 * Performs fast concat when right operator is char constant
 */
int phalcon_concat_right(zval **res, zval *op1, char *op2 TSRMLS_DC){

	zval op1_copy, *result;
	int use_copy1 = 0;

	int op2_length = strlen(op2);

	if(Z_TYPE_P(op1) != IS_STRING){
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
	}

	if(use_copy1){
		op1 = &op1_copy;
	}

	ALLOC_INIT_ZVAL(result);

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_length);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if(use_copy1){
		zval_dtor(op1);
	}

	*res = result;

	return SUCCESS;
}

/**
 * Performs fast concat when left operator is char constant
 */
int phalcon_concat_left(zval **res, char *op1, zval *op2 TSRMLS_DC){

	zval op2_copy, *result;
	int use_copy2 = 0;

	int op1_length = strlen(op1);

	if(Z_TYPE_P(op2) != IS_STRING){
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
	}

	if(use_copy2){
		op2 = &op2_copy;
	}

	ALLOC_INIT_ZVAL(result);

	Z_STRLEN_P(result) = Z_STRLEN_P(op2) + op1_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_length);
	memcpy(Z_STRVAL_P(result)+op1_length, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if(use_copy2){
		zval_dtor(op2);
	}

	*res = result;

	return SUCCESS;
}

/**
 * Performs fast concat when left and right operator are char constants
 */
int phalcon_concat_both(zval **res, char *op1, zval *op2, char *op3 TSRMLS_DC){

	zval op2_copy, *result;
	int use_copy2 = 0;

	int op1_length = strlen(op1);
	int op3_length = strlen(op3);

	if(Z_TYPE_P(op2) != IS_STRING){
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
	}

	if(use_copy2){
		op2 = &op2_copy;
	}

	ALLOC_INIT_ZVAL(result);

	Z_STRLEN_P(result) = op1_length + Z_STRLEN_P(op2) + op3_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_length);
	memcpy(Z_STRVAL_P(result)+op1_length, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_length+Z_STRLEN_P(op2), op3, op3_length);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if(use_copy2){
		zval_dtor(op2);
	}

	*res = result;

	return SUCCESS;

}

/**
 * Performs fast concat when left and right operator are zvals
 */
int phalcon_concat_vboth(zval **res, zval *op1, char *op2, zval *op3 TSRMLS_DC){

	zval op1_copy, op3_copy, *result;
	int use_copy1 = 0, use_copy3 = 0;

	int op2_length = strlen(op2);

	if(Z_TYPE_P(op1) != IS_STRING){
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
	}

	if(Z_TYPE_P(op3) != IS_STRING){
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
	}

	if(use_copy1){
		op1 = &op1_copy;
	}

	if(use_copy3){
		op3 = &op3_copy;
	}

	ALLOC_INIT_ZVAL(result);

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_length + Z_STRLEN_P(op3);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_length);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_length, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if(use_copy1){
		zval_dtor(op1);
	}

	if(use_copy3){
		zval_dtor(op3);
	}

	*res = result;

	return SUCCESS;

}

/**
 * Natural compare with string operator on right
 */
int phalcon_compare_strict_string(zval *op1, char *op2){

	int op2_length = strlen(op2);

	switch(Z_TYPE_P(op1)){
		case IS_STRING:
			if(!Z_STRLEN_P(op1)&&!op2_length){
				return 1;
			} else {
				return zend_binary_strcmp(Z_STRVAL_P(op1), Z_STRLEN_P(op1), op2, op2_length)==0;
			}
		case IS_NULL:
			return zend_binary_strcmp("", 0, op2, op2_length)==0;
		case IS_BOOL:
			if(!Z_BVAL_P(op1)){
				return zend_binary_strcmp("0", strlen("0"), op2, op2_length)==0;
			} else {
				return zend_binary_strcmp("1", strlen("1"), op2, op2_length)==0;
			}
	}

	return 0;
}


/**
 * Inmediate function resolution for addslaches function
 */
int phalcon_addslashes(zval *return_value, zval *param TSRMLS_DC){

	if(Z_TYPE_P(param)!=IS_STRING){
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

	if(Z_TYPE_P(filename)!=IS_STRING){
		return FAILURE;
	}

	if(VCWD_ACCESS(Z_STRVAL_P(filename), F_OK)==0){
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Filter alphanum string
 */
int phalcon_filter_alphanum(zval **result, zval *param){

	int i, ch, alloc = 0;
	zval *tmp;
	char temp[255];

	if(Z_TYPE_P(param)==IS_STRING){
		for(i=0;i<Z_STRLEN_P(param)&&i<255;i++){
			ch = Z_STRVAL_P(param)[i];
			if((ch>96&&ch<123)||(ch>64&&ch<91)){
				temp[alloc] = ch;
				alloc++;
			}
		}
	}

	ALLOC_INIT_ZVAL(tmp);
	if(alloc>0){
		Z_TYPE_P(tmp) = IS_STRING;
		Z_STRLEN_P(tmp) = alloc;
		Z_STRVAL_P(tmp) = (char *) emalloc(alloc+1);
		memcpy(Z_STRVAL_P(tmp), temp, alloc);
		Z_STRVAL_P(tmp)[Z_STRLEN_P(tmp)] = 0;
	} else {
		ZVAL_STRING(tmp, "", 1);
	}

	*result = tmp;

	return SUCCESS;
}
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

  +------------------------------------------------------------------------+
  | Zend Engine                                                            |
  +------------------------------------------------------------------------+
  | Copyright (c) 1998-2011 Zend Technologies Ltd. (http://www.zend.com)   |
  +------------------------------------------------------------------------+
  | This source file is subject to version 2.00 of the Zend license,       |
  | that is bundled with this package in the file LICENSE, and is          |
  | available through the world-wide-web at the following url:             |
  | http://www.zend.com/license/2_00.txt.                                  |
  | If you did not receive a copy of the Zend license and are unable to    |
  | obtain it through the world-wide-web, please send a note to            |
  | license@zend.com so we can mail you a copy immediately.                |
  +------------------------------------------------------------------------+
  | Authors: Andi Gutmans <andi@zend.com>                                  |
  |          Zeev Suraski <zeev@zend.com>                                  |
  |          Andrei Zmievski <andrei@php.net>                              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#endif


/**
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, func_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if(status==FAILURE){
		zend_error_noreturn(E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if(!noreturn){
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires parameters
 */
int phalcon_call_func_params(zval *return_value, char *func_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, func_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if(status==FAILURE){
		zend_error_noreturn(E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if(!noreturn){
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if(check){
		if(!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)){
			return FAILURE;
		}
	}

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, method_name, 0);
	if(Z_TYPE_P(object)==IS_OBJECT){
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, 0, NULL TSRMLS_CC);
		if(status==FAILURE){
			zend_error_noreturn(E_ERROR, "Call to undefined method %s()", Z_STRVAL_P(fn));
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		zend_error_noreturn(E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	if(!noreturn){
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which requires parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if(check){
		if(!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)){
			return FAILURE;
		}
	}

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, method_name, 1);
	if(Z_TYPE_P(object)==IS_OBJECT){
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
		status = phalcon_call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, param_count, params TSRMLS_CC);
		if(status==FAILURE){
			EG(scope) = active_scope;
			zend_error_noreturn(E_ERROR, "Call to undefined method %s() on class %s", Z_STRVAL_P(fn), Z_OBJCE_P(object)->name);
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		zend_error_noreturn(E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	if(!noreturn){
		zval_ptr_dtor(&return_value);
	}

	return status;
}


/**
 * Finds the correct scope to execute the function
 */
int phalcon_find_scope(zend_class_entry *ce, char *method_name TSRMLS_DC){
	const zend_function_entry *functions;
	int method_len = strlen(method_name);
	while(ce){
		if(ce->builtin_functions){
			functions = ce->builtin_functions;
			while(functions->fname){
				if(!zend_binary_strcasecmp(functions->fname, strlen(functions->fname), method_name, method_len)){
					EG(scope) = ce;
					return SUCCESS;
				}
				functions++;
			}
		}
		ce = ce->parent;
	}
	return FAILURE;
}

/**
 *
 */
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, char *method_name TSRMLS_DC){
	const zend_function_entry *functions;
	int method_len = strlen(method_name);
	int active_class_len = strlen(active_class);
	while(ce){
		//fprintf(stderr, "%s/%s\n", active_class, ce->name);
		if(!zend_binary_strcasecmp(ce->name, strlen(ce->name), active_class, active_class_len)){
			if(ce->builtin_functions){
				functions = ce->builtin_functions;
				while(functions->fname){
					//fprintf(stderr, " %s <> %s\n", functions->fname, method_name);
					if(!zend_binary_strcasecmp(functions->fname, strlen(functions->fname), method_name, method_len)){
						EG(scope) = ce;
						return SUCCESS;
					}
					functions++;
				}
			}
		}
		ce = ce->parent;
	}
	return FAILURE;
}

/**
 * Call parent static function which not requires parameters
 */
int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, char *method_name, int noreturn TSRMLS_DC){
	int success;
	zend_class_entry *active_scope = NULL;
	if(object){
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, method_name TSRMLS_CC);
	}
	success = phalcon_call_static_func(return_value, "parent", method_name, noreturn TSRMLS_CC);
	if(object){
		EG(scope) = active_scope;
	}
	return success;
}

/**
 * Call parent static function which requires parameters
 */
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){
	int success;
	zend_class_entry *active_scope = NULL;
	if(object){
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, method_name TSRMLS_CC);
	}
	success = phalcon_call_static_func_params(return_value, "parent", method_name, param_count, params, noreturn TSRMLS_CC);
	if(object){
		EG(scope) = active_scope;
	}
	return success;
}

/**
 * Call single static function which not requires parameters
 */
int phalcon_call_static_func(zval *return_value, char *class_name, char *method_name, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_string(fn, class_name, 0);
	add_next_index_string(fn, method_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if(status==FAILURE){
		zend_error_noreturn(E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	if(!noreturn){
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_string(fn, class_name, 0);
	add_next_index_string(fn, method_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if(status==FAILURE){
		zend_error_noreturn(E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	if(!noreturn){
		zval_ptr_dtor(&return_value);
	}

	return status;
}

static inline zend_function *phalcon_check_private_int(zend_function *fbc, zend_class_entry *ce, char *function_name_strval, int function_name_strlen TSRMLS_DC){

	int result;

	if(!ce){
		return 0;
	}

	/* We may call a private function if:
	 * 1.  The class of our object is the same as the scope, and the private
	 *     function (EX(fbc)) has the same scope.
	 * 2.  One of our parent classes are the same as the scope, and it contains
	 *     a private function with the same name that has the same scope.
	 */
	if(fbc->common.scope == ce && EG(scope) == ce){
		/* rule #1 checks out ok, allow the function call */
		return fbc;
	}

	/* Check rule #2 */
	ce = ce->parent;
	while(ce){
		if(PHALCON_DEBUG){
			fprintf(stderr, "Comparing %s with %s", ce->name, EG(scope)->name);
		}
		if(ce==EG(scope)){
			result = zend_hash_find(&ce->function_table, function_name_strval, function_name_strlen+1, (void **) &fbc)==SUCCESS
				&& fbc->op_array.fn_flags & ZEND_ACC_PRIVATE
				&& fbc->common.scope == EG(scope);
			if(result){
				return fbc;
			}
			break;
		}
		ce = ce->parent;
	}
	return NULL;
}

int phalcon_check_private(zend_function *fbc, zend_class_entry *ce, char *function_name_strval, int function_name_strlen TSRMLS_DC){
	return phalcon_check_private_int(fbc, ce, function_name_strval, function_name_strlen TSRMLS_CC) != NULL;
}

/**
 * Checks if a class method is callable
 */
int phalcon_is_callable_check_class(const char *name, int name_len, zend_fcall_info_cache *fcc, int *strict_class, char **error TSRMLS_DC){

	int ret = 0;
	zend_class_entry **pce;
	char *lcname = zend_str_tolower_dup(name, name_len);

	*strict_class = 0;
	if (name_len == sizeof("self") - 1 && !memcmp(lcname, "self", sizeof("self") - 1)) {
		if(!EG(scope)){
			if(error){
				*error = estrdup("cannot access self:: when no class scope is active");
			}
		} else {
			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(scope);
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}
			ret = 1;
		}
	} else {
		if(name_len == sizeof("parent") - 1 && !memcmp(lcname, "parent", sizeof("parent") - 1)){
			if(!EG(scope)){
				if(error){
					*error = estrdup("cannot access parent:: when no class scope is active");
				}
			} else {
				if(!EG(scope)->parent){
					if(error){
						*error = estrdup("cannot access parent:: when current class scope has no parent");
					}
				} else {
					fcc->called_scope = EG(called_scope);
					fcc->calling_scope = EG(scope)->parent;
					if(!fcc->object_ptr){
						fcc->object_ptr = EG(This);
					}
					*strict_class = 1;
					ret = 1;
				}
			}
		} else {
			if (name_len == sizeof("static") - 1 && !memcmp(lcname, "static", sizeof("static") - 1)) {
				if(!EG(called_scope)){
					if (error) *error = estrdup("cannot access static:: when no class scope is active");
				} else {
					fcc->called_scope = EG(called_scope);
					fcc->calling_scope = EG(called_scope);
					if(!fcc->object_ptr){
						fcc->object_ptr = EG(This);
					}
					*strict_class = 1;
					ret = 1;
				}
			} else {
				if(zend_lookup_class_ex(name, name_len, 1, &pce TSRMLS_CC) == SUCCESS){
					zend_class_entry *scope = EG(active_op_array) ? EG(active_op_array)->scope : NULL;

					fcc->calling_scope = *pce;
					if(scope && !fcc->object_ptr && EG(This) &&
					    instanceof_function(Z_OBJCE_P(EG(This)), scope TSRMLS_CC) &&
					    instanceof_function(scope, fcc->calling_scope TSRMLS_CC)) {
						fcc->object_ptr = EG(This);
						fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
					} else {
						fcc->called_scope = fcc->object_ptr ? Z_OBJCE_P(fcc->object_ptr) : fcc->calling_scope;
					}
					*strict_class = 1;
					ret = 1;
				} else {
					if(error){
						phalcon_spprintf(error, 0, "class '%.*s' not found", name_len, name);
					}
				}
			}
		}
	}
	efree(lcname);
	return ret;
}

int phalcon_is_callable_check_func(int check_flags, zval *callable, zend_fcall_info_cache *fcc, int strict_class, char **error TSRMLS_DC){

	zend_class_entry *ce_org = fcc->calling_scope;
	int retval = 0;
	char *mname, *lmname, *colon;
	int clen, mlen, result;
	zend_class_entry *last_scope;
	HashTable *ftable;
	int call_via_handler = 0;
	zend_class_entry *scope;

	if(error){
		*error = NULL;
	}

	fcc->calling_scope = NULL;
	fcc->function_handler = NULL;

	if(!ce_org){
		/* Skip leading \ */
		if(Z_STRVAL_P(callable)[0] == '\\'){
			mlen = Z_STRLEN_P(callable) - 1;
			mname = Z_STRVAL_P(callable) + 1;
			lmname = zend_str_tolower_dup(Z_STRVAL_P(callable) + 1, mlen);
		} else {
			mlen = Z_STRLEN_P(callable);
			mname = Z_STRVAL_P(callable);
			lmname = zend_str_tolower_dup(Z_STRVAL_P(callable), mlen);
		}
		/* Check if function with given name exists.
		 * This may be a compound name that includes namespace name */
		if (zend_hash_find(EG(function_table), lmname, mlen+1, (void**)&fcc->function_handler) == SUCCESS) {
			efree(lmname);
			return 1;
		}
		efree(lmname);
	}

	/* Split name into class/namespace and method/function names */
	result = (colon = zend_memrchr(Z_STRVAL_P(callable), ':', Z_STRLEN_P(callable))) != NULL && colon > Z_STRVAL_P(callable) && *(colon-1) == ':';
	if(result){
		colon--;
		clen = colon - Z_STRVAL_P(callable);
		mlen = Z_STRLEN_P(callable) - clen - 2;

		if(colon == Z_STRVAL_P(callable)){
			if(error){
				phalcon_spprintf(error, 0, "invalid function name");
			}
			return 0;
		}

		/* This is a compound name.
		 * Try to fetch class and then find static method. */
		last_scope = EG(scope);
		if(ce_org){
			EG(scope) = ce_org;
			if(PHALCON_DEBUG){
				fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
			}
		}

		if(!phalcon_is_callable_check_class(Z_STRVAL_P(callable), clen, fcc, &strict_class, error TSRMLS_CC)){
			EG(scope) = last_scope;
			if(PHALCON_DEBUG){
				fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
			}
			return 0;
		}
		EG(scope) = last_scope;
		if(PHALCON_DEBUG){
			fprintf(stderr, "ScopeAddress=%p\n", last_scope);
		}

		ftable = &fcc->calling_scope->function_table;
		if(ce_org && !instanceof_function(ce_org, fcc->calling_scope TSRMLS_CC)){
			if (error) phalcon_spprintf(error, 0, "class '%s' is not a subclass of '%s'", ce_org->name, fcc->calling_scope->name);
			return 0;
		}
		mname = Z_STRVAL_P(callable) + clen + 2;
	} else {
		if (ce_org) {
			/* Try to fetch find static method of given class. */
			mlen = Z_STRLEN_P(callable);
			mname = Z_STRVAL_P(callable);
			ftable = &ce_org->function_table;
			fcc->calling_scope = ce_org;
		} else {
			/* We already checked for plain function before. */
			if(error && !(check_flags & IS_CALLABLE_CHECK_SILENT)){
				phalcon_spprintf(error, 0, "function '%s' not found or invalid function name", Z_STRVAL_P(callable));
			}
			return 0;
		}
	}

	lmname = zend_str_tolower_dup(mname, mlen);
	//fprintf(stderr, "%s\n", lmname);
	//fprintf(stderr, " => ");

	result = strict_class && fcc->calling_scope && mlen == sizeof(ZEND_CONSTRUCTOR_FUNC_NAME)-1 && !memcmp(lmname, ZEND_CONSTRUCTOR_FUNC_NAME, sizeof(ZEND_CONSTRUCTOR_FUNC_NAME));
	//fprintf(stderr, "%d => ", result);

	if(result){
		fcc->function_handler = fcc->calling_scope->constructor;
		if(fcc->function_handler){
			retval = 1;
		}
	} else {
		result = (zend_hash_find(ftable, lmname, mlen+1, (void**)&fcc->function_handler) == SUCCESS);
		if(result){

			//fprintf(stderr, "%d => ", result);

			retval = 1;
			result = (fcc->function_handler->op_array.fn_flags & ZEND_ACC_CHANGED) && EG(scope) && instanceof_function(fcc->function_handler->common.scope, EG(scope) TSRMLS_CC);
			if(result){
				zend_function *priv_fbc;
				if(zend_hash_find(&EG(scope)->function_table, lmname, mlen+1, (void **) &priv_fbc)==SUCCESS
					&& priv_fbc->common.fn_flags & ZEND_ACC_PRIVATE
					&& priv_fbc->common.scope == EG(scope)) {
					fcc->function_handler = priv_fbc;
				}
			}

			result = (check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0 && (fcc->calling_scope && (fcc->calling_scope->__call || fcc->calling_scope->__callstatic));
			//fprintf(stderr, "%d => ", result);

			if(result){
				if(fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE){
					if(!phalcon_check_private(fcc->function_handler, fcc->object_ptr ? Z_OBJCE_P(fcc->object_ptr) : EG(scope), lmname, mlen TSRMLS_CC)){
						retval = 0;
						fcc->function_handler = NULL;
						goto get_function_via_handler;
					}
				} else {
					if(fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED){
						if(!zend_check_protected(fcc->function_handler->common.scope, EG(scope))){
							retval = 0;
							fcc->function_handler = NULL;
							goto get_function_via_handler;
						}
					}
				}
			}
		} else {

			get_function_via_handler:
			if (fcc->object_ptr && fcc->calling_scope == ce_org) {
				if (strict_class && ce_org->__call) {
					fcc->function_handler = emalloc(sizeof(zend_internal_function));
					fcc->function_handler->internal_function.type = ZEND_INTERNAL_FUNCTION;
					fcc->function_handler->internal_function.module = ce_org->module;
					fcc->function_handler->internal_function.handler = zend_std_call_user_call;
					fcc->function_handler->internal_function.arg_info = NULL;
					fcc->function_handler->internal_function.num_args = 0;
					fcc->function_handler->internal_function.scope = ce_org;
					fcc->function_handler->internal_function.fn_flags = ZEND_ACC_CALL_VIA_HANDLER;
					fcc->function_handler->internal_function.function_name = estrndup(mname, mlen);
					fcc->function_handler->internal_function.pass_rest_by_reference = 0;
					fcc->function_handler->internal_function.return_reference = ZEND_RETURN_VALUE;
					call_via_handler = 1;
					retval = 1;
				} else if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
					fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, mname, mlen TSRMLS_CC);
					if (fcc->function_handler) {
						if (strict_class &&
						    (!fcc->function_handler->common.scope ||
						     !instanceof_function(ce_org, fcc->function_handler->common.scope TSRMLS_CC))) {
							if ((fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0) {
								if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
									efree(fcc->function_handler->common.function_name);
								}
								efree(fcc->function_handler);
							}
						} else {
							retval = 1;
							call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
						}
					}
				}
			} else if (fcc->calling_scope) {
				if (fcc->calling_scope->get_static_method) {
					fcc->function_handler = fcc->calling_scope->get_static_method(fcc->calling_scope, mname, mlen TSRMLS_CC);
				} else {
					fcc->function_handler = zend_std_get_static_method(fcc->calling_scope, mname, mlen TSRMLS_CC);
				}
				if (fcc->function_handler) {
					retval = 1;
					call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
					if (call_via_handler && !fcc->object_ptr && EG(This) &&
					    Z_OBJ_HT_P(EG(This))->get_class_entry &&
					    instanceof_function(Z_OBJCE_P(EG(This)), fcc->calling_scope TSRMLS_CC)) {
						fcc->object_ptr = EG(This);
					}
				}
			}
		}
	}

	//fprintf(stderr, "%d\n", retval);

	if(retval){
		if(fcc->calling_scope && !call_via_handler){
			if(!fcc->object_ptr && !(fcc->function_handler->common.fn_flags & ZEND_ACC_STATIC)){
				int severity;
				char *verb;
				if(fcc->function_handler->common.fn_flags & ZEND_ACC_ALLOW_STATIC){
					severity = E_STRICT;
					verb = "should not";
				} else {
					/* An internal function assumes $this is present and won't check that. So PHP would crash by allowing the call. */
					severity = E_ERROR;
					verb = "cannot";
				}
				if((check_flags & IS_CALLABLE_CHECK_IS_STATIC) != 0){
					retval = 0;
				}
				if(EG(This) && instanceof_function(Z_OBJCE_P(EG(This)), fcc->calling_scope TSRMLS_CC)){
					fcc->object_ptr = EG(This);
					if (error) {
						phalcon_spprintf(error, 0, "non-static method %s::%s() %s be called statically, assuming $this from compatible context %s", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb, Z_OBJCE_P(EG(This))->name);
						if (severity == E_ERROR) {
							retval = 0;
						}
					} else if (retval) {
						zend_error(severity, "Non-static method %s::%s() %s be called statically, assuming $this from compatible context %s", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb, Z_OBJCE_P(EG(This))->name);
					}
				} else {
					if(error){
						phalcon_spprintf(error, 0, "non-static method %s::%s() %s be called statically", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb);
						if (severity == E_ERROR) {
							retval = 0;
						}
					} else if (retval) {
						zend_error(severity, "Non-static method %s::%s() %s be called statically", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb);
					}
				}
			}

			if(retval && (check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0){
				if(fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE){
					if(fcc->object_ptr){
						scope = Z_OBJCE_P(fcc->object_ptr);
					} else {
						scope = EG(scope);
					}
					if(!phalcon_check_private(fcc->function_handler, scope, lmname, mlen TSRMLS_CC)){
						if(error){
							if(*error){
								efree(*error);
							}
							phalcon_spprintf(error, 0, "cannot access private method %s::%s() (21)", fcc->calling_scope->name, fcc->function_handler->common.function_name);
						}
						retval = 0;
					}
				} else {
					if((fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED)){
						if(!zend_check_protected(fcc->function_handler->common.scope, EG(scope))){
							if(error){
								if(*error){
									efree(*error);
								}
								phalcon_spprintf(error, 0, "cannot access protected method %s::%s() (22)", fcc->calling_scope->name, fcc->function_handler->common.function_name);
							}
							retval = 0;
						}
					}
				}
			}
		}
	} else {
		if(error && !(check_flags & IS_CALLABLE_CHECK_SILENT)){
			if(fcc->calling_scope){
				if (error) phalcon_spprintf(error, 0, "class '%s' does not have a method '%s'", fcc->calling_scope->name, mname);
			} else {
				if (error) phalcon_spprintf(error, 0, "function '%s' does not exist", mname);
			}
		}
	}
	efree(lmname);

	if(fcc->object_ptr){
		fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
	}
	if(retval){
		fcc->initialized = 1;
	}
	return retval;
}

zend_bool phalcon_is_callable_ex(zval *callable, zval *object_ptr, uint check_flags, char **callable_name, int *callable_name_len, zend_fcall_info_cache *fcc, char **error TSRMLS_DC){
	zend_bool ret;
	int callable_name_len_local;
	zend_fcall_info_cache fcc_local;

	if(callable_name){
		*callable_name = NULL;
	}
	if(callable_name_len == NULL){
		callable_name_len = &callable_name_len_local;
	}
	if(fcc == NULL){
		fcc = &fcc_local;
	}
	if(error){
		*error = NULL;
	}

	fcc->initialized = 0;
	fcc->calling_scope = NULL;
	fcc->called_scope = NULL;
	fcc->function_handler = NULL;
	fcc->calling_scope = NULL;
	fcc->object_ptr = NULL;

	if (object_ptr && Z_TYPE_P(object_ptr) != IS_OBJECT) {
		object_ptr = NULL;
	}
	if (object_ptr &&
	    (!EG(objects_store).object_buckets ||
	     !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(object_ptr)].valid)) {
		return 0;
	}

	switch (Z_TYPE_P(callable)) {
		case IS_STRING:

			if(object_ptr){
				fcc->object_ptr = object_ptr;
				fcc->calling_scope = Z_OBJCE_P(object_ptr);
				if(callable_name){
					char *ptr;

					*callable_name_len = fcc->calling_scope->name_length + Z_STRLEN_P(callable) + sizeof("::") - 1;
					ptr = *callable_name = emalloc(*callable_name_len + 1);
					memcpy(ptr, fcc->calling_scope->name, fcc->calling_scope->name_length);
					ptr += fcc->calling_scope->name_length;
					memcpy(ptr, "::", sizeof("::") - 1);
					ptr += sizeof("::") - 1;
					memcpy(ptr, Z_STRVAL_P(callable), Z_STRLEN_P(callable) + 1);
				}
			} else {
				if(callable_name){
					*callable_name = estrndup(Z_STRVAL_P(callable), Z_STRLEN_P(callable));
					*callable_name_len = Z_STRLEN_P(callable);
				}
			}

			if(check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY){
				fcc->called_scope = fcc->calling_scope;
				return 1;
			}

			ret = phalcon_is_callable_check_func(check_flags, callable, fcc, 0, error TSRMLS_CC);
			if (fcc == &fcc_local &&
			    fcc->function_handler &&
				((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
			      (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
			     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
			     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
				if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
					efree(fcc->function_handler->common.function_name);
				}
				efree(fcc->function_handler);
			}
			return ret;

		case IS_ARRAY:
			{
				zval **method = NULL;
				zval **obj = NULL;
				int strict_class = 0;

				if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
					zend_hash_index_find(Z_ARRVAL_P(callable), 0, (void **) &obj);
					zend_hash_index_find(Z_ARRVAL_P(callable), 1, (void **) &method);
				}
				if (obj && method &&
					(Z_TYPE_PP(obj) == IS_OBJECT ||
					Z_TYPE_PP(obj) == IS_STRING) &&
					Z_TYPE_PP(method) == IS_STRING) {

					if (Z_TYPE_PP(obj) == IS_STRING) {
						if (callable_name) {
							char *ptr;

							*callable_name_len = Z_STRLEN_PP(obj) + Z_STRLEN_PP(method) + sizeof("::") - 1;
							ptr = *callable_name = emalloc(*callable_name_len + 1);
							memcpy(ptr, Z_STRVAL_PP(obj), Z_STRLEN_PP(obj));
							ptr += Z_STRLEN_PP(obj);
							memcpy(ptr, "::", sizeof("::") - 1);
							ptr += sizeof("::") - 1;
							memcpy(ptr, Z_STRVAL_PP(method), Z_STRLEN_PP(method) + 1);
						}

						if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
							return 1;
						}

						if (!phalcon_is_callable_check_class(Z_STRVAL_PP(obj), Z_STRLEN_PP(obj), fcc, &strict_class, error TSRMLS_CC)) {
							return 0;
						}

					} else {
						if (!EG(objects_store).object_buckets ||
						    !EG(objects_store).object_buckets[Z_OBJ_HANDLE_PP(obj)].valid) {
							return 0;
						}

						fcc->calling_scope = Z_OBJCE_PP(obj); /* TBFixed: what if it's overloaded? */

						fcc->object_ptr = *obj;

						if (callable_name) {
							char *ptr;

							*callable_name_len = fcc->calling_scope->name_length + Z_STRLEN_PP(method) + sizeof("::") - 1;
							ptr = *callable_name = emalloc(*callable_name_len + 1);
							memcpy(ptr, fcc->calling_scope->name, fcc->calling_scope->name_length);
							ptr += fcc->calling_scope->name_length;
							memcpy(ptr, "::", sizeof("::") - 1);
							ptr += sizeof("::") - 1;
							memcpy(ptr, Z_STRVAL_PP(method), Z_STRLEN_PP(method) + 1);
						}

						if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
							fcc->called_scope = fcc->calling_scope;
							return 1;
						}
					}

					ret = phalcon_is_callable_check_func(check_flags, *method, fcc, strict_class, error TSRMLS_CC);
					if (fcc == &fcc_local &&
					    fcc->function_handler &&
						((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					      (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							efree(fcc->function_handler->common.function_name);
						}
						efree(fcc->function_handler);
					}
					return ret;

				} else {
					if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
						if (!obj || (Z_TYPE_PP(obj) != IS_STRING && Z_TYPE_PP(obj) != IS_OBJECT)) {
							if (error) phalcon_spprintf(error, 0, "first array member is not a valid class name or object");
						} else {
							if (error) phalcon_spprintf(error, 0, "second array member is not a valid method");
						}
					} else {
						if (error) phalcon_spprintf(error, 0, "array must have exactly two members");
					}
					if (callable_name) {
						*callable_name = estrndup("Array", sizeof("Array")-1);
						*callable_name_len = sizeof("Array") - 1;
					}
				}
			}
			return 0;

		case IS_OBJECT:
			if (Z_OBJ_HANDLER_P(callable, get_closure) && Z_OBJ_HANDLER_P(callable, get_closure)(callable, &fcc->calling_scope, &fcc->function_handler, &fcc->object_ptr TSRMLS_CC) == SUCCESS) {
				fcc->called_scope = fcc->calling_scope;
				if (callable_name) {
					zend_class_entry *ce = Z_OBJCE_P(callable); /* TBFixed: what if it's overloaded? */

					*callable_name_len = ce->name_length + sizeof("::__invoke") - 1;
					*callable_name = emalloc(*callable_name_len + 1);
					memcpy(*callable_name, ce->name, ce->name_length);
					memcpy((*callable_name) + ce->name_length, "::__invoke", sizeof("::__invoke"));
				}
				return 1;
			}
			/* break missing intentionally */

		default:
			if (callable_name) {
				zval expr_copy;
				int use_copy;

				zend_make_printable_zval(callable, &expr_copy, &use_copy);
				*callable_name = estrndup(Z_STRVAL(expr_copy), Z_STRLEN(expr_copy));
				*callable_name_len = Z_STRLEN(expr_copy);
				zval_dtor(&expr_copy);
			}
			if (error) phalcon_spprintf(error, 0, "no array or string given");
			return 0;
	}
}

/**
 * zend call_user_function for debugging
 *
 */
int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC){

	zval ***params_array;
	zend_uint i;
	int ex_retval;
	zval *local_retval_ptr = NULL;

	if(param_count){
		params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
		for(i=0; i<param_count; i++){
			params_array[i] = &params[i];
		}
	} else {
		params_array = NULL;
	}
	ex_retval = phalcon_call_user_function_ex(function_table, object_pp, function_name, &local_retval_ptr, param_count, params_array, 1, NULL TSRMLS_CC);
	if(local_retval_ptr){
		COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
	} else {
		INIT_ZVAL(*retval_ptr);
	}
	if(params_array){
		efree(params_array);
	}
	return ex_retval;

}

int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC){
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

	return zend_call_function(&fci, NULL TSRMLS_CC);
}

#ifndef PHP_WIN32

int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC){

	zend_uint i;
	zval **original_return_value;
	HashTable *calling_symbol_table;
	zend_op_array *original_op_array;
	zend_op **original_opline_ptr;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zval *current_this;
	zend_execute_data execute_data;

	*fci->retval_ptr_ptr = NULL;

	if(!EG(active)){
		fprintf(stderr, "Failure: executor is already inactive\n");
		return FAILURE; /* executor is already inactive */
	}

	if(EG(exception)){
		fprintf(stderr, "Failure: We would result in an instable executor otherwise\n");
		return FAILURE; /* we would result in an instable executor otherwise */
	}

	switch(fci->size){
		case sizeof(zend_fcall_info):
			break; /* nothing to do currently */
		default:
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Corrupted fcall_info provided to zend_call_function()");
			break;
	}

	/* Initialize execute_data */
	if (EG(current_execute_data)) {
		execute_data = *EG(current_execute_data);
		EX(op_array) = NULL;
		EX(opline) = NULL;
		EX(object) = NULL;
	} else {
		/* This only happens when we're called outside any execute()'s
		 * It shouldn't be strictly necessary to NULL execute_data out,
		 * but it may make bugs easier to spot
		 */
		memset(&execute_data, 0, sizeof(zend_execute_data));
	}

	if (!fci_cache || !fci_cache->initialized) {
		zend_fcall_info_cache fci_cache_local;
		char *callable_name;
		char *error = NULL;

		if (!fci_cache) {
			fci_cache = &fci_cache_local;
		}

		if(!phalcon_is_callable_ex(fci->function_name, fci->object_ptr, 0, &callable_name, NULL, fci_cache, &error TSRMLS_CC)){
			if(error){
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid callback %s, %s (1)", callable_name, error);
				efree(error);
			}
			if(callable_name){
				efree(callable_name);
			}
			return FAILURE;
		} else {
			if(error){
				/* Capitalize the first latter of the error message */
				if (error[0] >= 'a' && error[0] <= 'z') {
					error[0] += ('A' - 'a');
				}
				php_error_docref(NULL TSRMLS_CC, E_STRICT, "%s", error);
				efree(error);
			}
		}
		efree(callable_name);
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;
	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT && (!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		fprintf(stderr, "Failure: Some crazyness about buckets ¿?\n");
		return FAILURE;
	}

	if (EX(function_state).function->common.fn_flags & (ZEND_ACC_ABSTRACT|ZEND_ACC_DEPRECATED)) {
		if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
			zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		}
		if (EX(function_state).function->common.fn_flags & ZEND_ACC_DEPRECATED) {
 			php_error_docref(NULL TSRMLS_CC, E_DEPRECATED, "Function %s%s%s() is deprecated",
				EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
				EX(function_state).function->common.scope ? "::" : "",
				EX(function_state).function->common.function_name);
		}
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i=0; i<fci->param_count; i++) {
		zval *param;

		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION
			&& (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0
			&& !ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& PZVAL_IS_REF(*fci->params[i])) {
			SEPARATE_ZVAL(fci->params[i]);
		}

		if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& !PZVAL_IS_REF(*fci->params[i])) {

			if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
				    !ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if(i) {
						/* hack to clean up the stack */
						zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
						zend_vm_stack_clear_multiple(TSRMLS_C);
					}

					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
						EX(function_state).function->common.scope ? "::" : "",
						EX(function_state).function->common.function_name);
					return FAILURE;
				}

				ALLOC_ZVAL(new_zval);
				*new_zval = **fci->params[i];
				zval_copy_ctor(new_zval);
				Z_SET_REFCOUNT_P(new_zval, 1);
				Z_DELREF_PP(fci->params[i]);
				*fci->params[i] = new_zval;
			}
			Z_ADDREF_PP(fci->params[i]);
			Z_SET_ISREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else if (*fci->params[i] != &EG(uninitialized_zval)) {
			Z_ADDREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
		}
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;
	if(PHALCON_DEBUG){
		fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
	}

	current_this = EG(This);

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	} else if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
		EG(called_scope) = NULL;
	}

	if (fci->object_ptr) {
		if ((EX(function_state).function->common.fn_flags & ZEND_ACC_STATIC)) {
			EG(This) = NULL;
		} else {
			EG(This) = fci->object_ptr;

			if (!PZVAL_IS_REF(EG(This))) {
				Z_ADDREF_P(EG(This)); /* For $this pointer */
			} else {
				zval *this_ptr;

				ALLOC_ZVAL(this_ptr);
				*this_ptr = *EG(This);
				INIT_PZVAL(this_ptr);
				zval_copy_ctor(this_ptr);
				EG(This) = this_ptr;
			}
		}
	} else {
		EG(This) = NULL;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	if (EX(function_state).function->type == ZEND_USER_FUNCTION) {
		calling_symbol_table = EG(active_symbol_table);
		EG(scope) = EX(function_state).function->common.scope;
		if(PHALCON_DEBUG){
			fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
		}
		if(fci->symbol_table){
			EG(active_symbol_table) = fci->symbol_table;
		} else {
			EG(active_symbol_table) = NULL;
		}

		original_return_value = EG(return_value_ptr_ptr);
		original_op_array = EG(active_op_array);
		EG(return_value_ptr_ptr) = fci->retval_ptr_ptr;
		EG(active_op_array) = (zend_op_array *) EX(function_state).function;
		original_opline_ptr = EG(opline_ptr);
		zend_execute(EG(active_op_array) TSRMLS_CC);
		if (!fci->symbol_table && EG(active_symbol_table)) {
			if (EG(symtable_cache_ptr)>=EG(symtable_cache_limit)) {
				zend_hash_destroy(EG(active_symbol_table));
				FREE_HASHTABLE(EG(active_symbol_table));
			} else {
				/* clean before putting into the cache, since clean
				   could call dtors, which could use cached hash */
				zend_hash_clean(EG(active_symbol_table));
				*(++EG(symtable_cache_ptr)) = EG(active_symbol_table);
			}
		}
		EG(active_symbol_table) = calling_symbol_table;
		EG(active_op_array) = original_op_array;
		EG(return_value_ptr_ptr)=original_return_value;
		EG(opline_ptr) = original_opline_ptr;
	} else if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION) {
		int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
		if (EX(function_state).function->common.scope) {
			EG(scope) = EX(function_state).function->common.scope;
			if(PHALCON_DEBUG){
				fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
			}
		}
		((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		/*  We shouldn't fix bad extensions here,
			because it can break proper ones (Bug #34045)
		if (!EX(function_state).function->common.return_reference)
		{
			INIT_PZVAL(*fci->retval_ptr_ptr);
		}*/
		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}

		if (call_via_handler) {
			/* We must re-initialize function again */
			fci_cache->initialized = 0;
		}
	} else { /* ZEND_OVERLOADED_FUNCTION */
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

		/* Not sure what should be done here if it's a static method */
		if (fci->object_ptr) {
			Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
		}

		if (EX(function_state).function->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			efree(EX(function_state).function->common.function_name);
		}
		efree(EX(function_state).function);

		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}
	}
	zend_vm_stack_clear_multiple(TSRMLS_C);

	if (EG(This)) {
		zval_ptr_dtor(&EG(This));
	}
	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	if(PHALCON_DEBUG){
		fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
	}
	EG(This) = current_this;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		zend_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}
#endif
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
	zend_op_array *orig_op_array;
	zval **orig_retval_ptr_ptr;

	switch(Z_TYPE_P(require_path)){
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error_noreturn(E_ERROR, "Invalid require path value");
			return FAILURE;
	}

	if(Z_TYPE_P(require_path)!=IS_STRING){
		convert_to_string(require_path);
	}

	file_path = Z_STRVAL_P(require_path);
	file_path_length = Z_STRLEN_P(require_path);

	ret = php_stream_open_for_zend_ex(file_path, &file_handle, ENFORCE_SAFE_MODE|USE_PATH|STREAM_OPEN_FOR_INCLUDE TSRMLS_CC);
	if(ret==SUCCESS){

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

		orig_op_array = EG(active_op_array);
		orig_retval_ptr_ptr = EG(return_value_ptr_ptr);

		EG(active_op_array) = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
		if(EG(active_op_array) && file_handle.handle.stream.handle){
			EG(return_value_ptr_ptr) = NULL;
			zend_execute(EG(active_op_array) TSRMLS_CC);
			destroy_op_array(EG(active_op_array) TSRMLS_CC);
			efree(EG(active_op_array));
		} else {
			EG(active_op_array) = orig_op_array;
			EG(return_value_ptr_ptr) = orig_retval_ptr_ptr;
			return FAILURE;
		}

		EG(active_op_array) = orig_op_array;
		EG(return_value_ptr_ptr) = orig_retval_ptr_ptr;

		return SUCCESS;
	}

	return FAILURE;

}

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
 * Stars debug on file
 */
int phalcon_start_debug(){
	if(!phalcon_log){
		//phalcon_log = fopen("/Applications/MAMP/htdocs/sparkphp/debug.a", "w");
		phalcon_log = stderr;
	}
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
	fprintf(phalcon_log, "%s", message);
	fprintf(phalcon_log, "\n");
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
		message = (char *) emalloc(sizeof(char)*(strlen(ptr->class_name)+strlen(ptr->method_name)+13));
		phalcon_spprintf(&message, 0, "#%d %s::%s", step, ptr->class_name, ptr->method_name);
		phalcon_debug_screen(message);
		efree(message);
		ptr = ptr->prev;
		step++;
	}
}

/**
 * Appends a debug entry to internal execution scope
 */
int phalcon_step_into_entry(char *class_name, char *method_name, int lineno){
	char *message;
	phalcon_debug_entry *entry;
	if(!start){
		start = (phalcon_debug_entry *) emalloc(sizeof(phalcon_debug_entry));
		start->class_name = "__main__";
		start->method_name = "__init__";
		start->lineno = 0;
		start->prev = NULL;
		start->next = NULL;
		active = start;
	}

	message = (char *) emalloc(sizeof(char)*(strlen(class_name)+strlen(method_name)+14));
	phalcon_spprintf(&message, 0, "Step Into %s::%s", class_name, method_name);
	phalcon_debug_screen(message);
	efree(message);

	entry = (phalcon_debug_entry *) emalloc(sizeof(phalcon_debug_entry));
	entry->class_name = class_name;
	entry->method_name = method_name;
	entry->lineno = lineno;
	entry->prev = active;
	active->next = entry;
	active = entry;
	phalcon_debug_trace++;
}

/**
 * Steps out current stack
 */
int phalcon_step_out_entry(){
	char *message;
	phalcon_debug_entry *prev;
	if(active){

		phalcon_debug_trace--;
		message = (char *) emalloc(sizeof(char)*(strlen(active->class_name)+strlen(active->method_name)+13));
		phalcon_spprintf(&message, 0, "Step out %s::%s", active->class_name, active->method_name);
		phalcon_debug_screen(message);
		efree(message);

		prev = active->prev;
		efree(active);
		active = prev;

	} else {
		fprintf(phalcon_log, "Problem, stack?");
	}
}

#endif

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
#endif

#ifdef PHP_WIN32
#endif

/**
 * Copy on write for not tmp variables to be used as parameters
 */
int phalcon_cpy_wrt_param(zval **param, zval *value){
	if(Z_TYPE_P(value)==IS_OBJECT){
		Z_ADDREF_P(value);
		*param = value;
	} else {
		INIT_PARAM(*param);
		ALLOC_INIT_ZVAL(*param);
		ZVAL_ZVAL(*param, value, 1, 0);
	}
	return SUCCESS;
}

/**
 * Check if a class exists
 *
 * @TODO Unfortunately doesn't works
 */
int phalcon_class_exists(zval *return_value, zval *class_name_zval, zval *autoload_zval TSRMLS_DC){

	char *class_name;
	int class_name_len;
	zend_class_entry ***ce;
	ulong hash;
	ALLOCA_FLAG(use_heap)

	switch(Z_TYPE_P(class_name_zval)){
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error_noreturn(E_ERROR, "Invalid parameter for class_exists");
			return FAILURE;
	}

	if(Z_TYPE_P(class_name_zval)!=IS_STRING){
		convert_to_string(class_name_zval);
	}

	class_name = estrndup(Z_STRVAL_P(class_name_zval), Z_STRLEN_P(class_name_zval));
	class_name_len = strlen(class_name);

	php_strtolower(class_name, class_name_len);

	hash = zend_inline_hash_func(class_name, class_name_len);
	if(zend_hash_quick_find(EG(class_table), class_name, class_name_len, hash, (void **) ce) == SUCCESS) {
		free_alloca(class_name, use_heap);
		return SUCCESS;
	}

	free_alloca(class_name, use_heap);
	return FAILURE;

}

/**
 * Clones an object from obj to dst
 */
int phalcon_clone(zval **dst, zval *obj TSRMLS_DC){

	zval *destiny;
	zend_class_entry *ce;
	zend_function *clone;
	zend_object_clone_obj_t clone_call;

	if(Z_TYPE_P(obj)!=IS_OBJECT){
		zend_error_noreturn(E_ERROR, "__clone method called on non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(obj);
	clone = ce ? ce->clone : NULL;
	clone_call =  Z_OBJ_HT_P(obj)->clone_obj;
	if(!clone_call){
		if(ce){
			zend_error_noreturn(E_ERROR, "Trying to clone an uncloneable object of class %s", ce->name);
		} else {
			zend_error_noreturn(E_ERROR, "Trying to clone an uncloneable object");
		}
		return FAILURE;
	}

	if(!EG(exception)){
		ALLOC_ZVAL(destiny);
		Z_OBJVAL_P(destiny) = clone_call(obj TSRMLS_CC);
		Z_TYPE_P(destiny) = IS_OBJECT;
		Z_SET_REFCOUNT_P(destiny, 1);
		Z_SET_ISREF_P(destiny);
		if(EG(exception)){
			zval_ptr_dtor(&destiny);
			destiny = NULL;
		}
	}

	if(destiny){
		*dst = destiny;
	}

	return SUCCESS;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property(zval *result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC){
	if(Z_TYPE_P(object)==IS_OBJECT){
		*result = *zend_read_property(Z_OBJCE_P(object), object, property_name, property_length, 1 TSRMLS_CC);
	} else {
		ZVAL_NULL(result);
		if(silent==PHALCON_NOISY_FETCH){
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
		}
	}
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with long value
 */
int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC){
	if(Z_TYPE_P(obj)!=IS_OBJECT){
		zend_error_noreturn(E_ERROR, "Attempt to assign property of non-object");
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
	if(Z_TYPE_P(obj)!=IS_OBJECT){
		zend_error_noreturn(E_ERROR, "Attempt to assign property of non-object");
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
	if(Z_TYPE_P(obj)!=IS_OBJECT){
		zend_error_noreturn(E_ERROR, "Attempt to assign property of non-object");
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

	if(Z_TYPE_P(object)!=IS_OBJECT){
		return FAILURE;
	}

	if(Z_TYPE_P(method_name)!=IS_STRING){
		return FAILURE;
	}

	lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	if(zend_hash_exists(&Z_OBJCE_P(object)->function_table, lcname, Z_STRLEN_P(method_name)+1)) {
		efree(lcname);
		return SUCCESS;
	}

	return FAILURE;
}

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.sparkphp.com)           |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@sparkphp.com so we can send you a copy immediately.         |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@sparkphp.com>                        |
  |          Eduar Carvajal <eduar@sparkphp.com>                           |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#endif


int isset_check_failed = 0;

/**
 * Push one or more elements onto the end of array
 */
int phalcon_array_append(zval *arr, zval *value TSRMLS_DC){
	if(Z_TYPE_P(arr)==IS_ARRAY){
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

	if(Z_TYPE_P(arr)!=IS_ARRAY){
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if(Z_TYPE_P(index)==IS_NULL||Z_TYPE_P(index)==IS_DOUBLE){
		convert_to_string(index);
	} else {
		if(Z_TYPE_P(index)==IS_BOOL){
			convert_to_long(index);
		}
	}

 	if(Z_TYPE_P(index)==IS_STRING){
		return zend_hash_update(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, &value, sizeof(zval *), NULL);
	} else {
		if(Z_TYPE_P(index)==IS_LONG){
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
int phalcon_array_update_string(zval *arr, char *index, zval *value TSRMLS_DC){
	if(Z_TYPE_P(arr)!=IS_ARRAY){
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}
	Z_ADDREF_P(value);
	return zend_hash_update(Z_ARRVAL_P(arr), index, strlen(index)+1, &value, sizeof(zval *), NULL);
}

/**
 * Updates values on arrays by long indexes only
 */
int phalcon_array_update_long(zval *arr, ulong index, zval *value TSRMLS_DC){
	if(Z_TYPE_P(arr)!=IS_ARRAY){
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}
	Z_ADDREF_P(value);
	return zend_hash_index_update(Z_ARRVAL_P(arr), index, &value, sizeof(zval *), NULL);
}

/**
 * Reads an item from an array using a zval as index
 */
int phalcon_array_fetch(zval *return_value, zval *arr, zval *index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE, type;

 	if(Z_TYPE_P(index)==IS_ARRAY||Z_TYPE_P(index)==IS_OBJECT){
		ZVAL_NULL(return_value);
		if(silent==PHALCON_NOISY_FETCH){
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		} else {
			isset_check_failed = 1;
		}
		return FAILURE;
	}

 	if(Z_TYPE_P(index)==IS_NULL){
		convert_to_string(index);
	}

	if(Z_TYPE_P(arr)==IS_NULL||Z_TYPE_P(arr)==IS_BOOL){
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	if(Z_TYPE_P(index)!=IS_STRING && Z_TYPE_P(index)!=IS_LONG && Z_TYPE_P(index)!=IS_DOUBLE){
		ZVAL_NULL(return_value);
		if(silent==PHALCON_NOISY_FETCH){
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

 	if(Z_TYPE_P(index)==IS_STRING){
       	if((type = is_numeric_string(Z_STRVAL_P(index), Z_STRLEN_P(index), NULL, NULL, 0))){
			if(type==IS_LONG){
				convert_to_long(index);
			}
		}
	} else {
		if(Z_TYPE_P(index)==IS_DOUBLE){
			convert_to_string(index);
		}
	}

 	if(Z_TYPE_P(index)==IS_STRING){
		if((result = zend_hash_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, (void**)&zv))==SUCCESS){
			*return_value = **zv;
			return SUCCESS;
		}
	}

 	if(Z_TYPE_P(index)==IS_LONG){
		if((result = zend_hash_index_find(Z_ARRVAL_P(arr), Z_LVAL_P(index), (void**)&zv))==SUCCESS){
			*return_value = **zv;
			return SUCCESS;
		}
	}

	if(silent==PHALCON_NOISY_FETCH){
		if(Z_TYPE_P(index)==IS_LONG){
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", Z_LVAL_P(index));
		} else {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", Z_STRVAL_P(index));
		}
	} else {
		isset_check_failed = 1;
	}

	ZVAL_NULL(return_value);

	return FAILURE;
}

/**
 * Reads an item from an array using a string as index
 */
int phalcon_array_fetch_string(zval *return_value, zval *arr, char *index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	if(Z_TYPE_P(arr)==IS_NULL||Z_TYPE_P(arr)==IS_BOOL){
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	if(Z_TYPE_P(arr)!=IS_ARRAY){
		ZVAL_NULL(return_value);
		if(silent==PHALCON_NOISY_FETCH){
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}
		return FAILURE;
	}

	if((result = zend_hash_find(Z_ARRVAL_P(arr), index, strlen(index)+1, (void**)&zv))==SUCCESS){
		*return_value = **zv;
		return SUCCESS;
	}

	if(silent==PHALCON_NOISY_FETCH){
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", index);
	} else {
		isset_check_failed = 1;
	}

	ZVAL_NULL(return_value);

	return FAILURE;

}

/**
 * Reads an item from an array using a long as index
 */
int phalcon_array_fetch_long(zval *return_value, zval *arr, ulong index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	if(Z_TYPE_P(arr)==IS_NULL||Z_TYPE_P(arr)==IS_BOOL){
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	if(Z_TYPE_P(arr)!=IS_ARRAY){
		ZVAL_NULL(return_value);
		if(silent==PHALCON_NOISY_FETCH){
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}
		return FAILURE;
	}

	if((result = zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv))==SUCCESS){
		*return_value = **zv;
		return SUCCESS;
	}

	if(silent==PHALCON_NOISY_FETCH){
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", index);
	} else {
		isset_check_failed = 1;
	}

	ZVAL_NULL(return_value);

	return FAILURE;

}
PHP_METHOD(Phalcon_Dispatcher, __construct){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_frontController", strlen("_frontController"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Dispatcher, dispatch){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL, *i5 = NULL, *i6 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL, NULL }, *p10[] = { NULL }, *p11[] = { NULL }, *p15[] = { NULL, NULL }, *p16[] = { NULL, NULL }, *p17[] = { NULL }, *p18[] = { NULL };
	zend_class_entry *ce0;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_router", sizeof("_router")-1);
	if(!zend_is_true(t0)){
		PHALCON_NEW(i0, phalcon_router_rewrite_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), i0 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CPY_WRT(v0, t1);
	PHALCON_CALL_METHOD_NORETURN(v0, "handle", PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_frontController", sizeof("_frontController")-1);
	PHALCON_CALL_METHOD(v1, t2, "getbasepath", PHALCON_CALL_DEFAULT);
	//Wasted infer Constant null
	PHALCON_INIT_NULL(t3);
	PHALCON_CPY_WRT(v2, t3);
	PHALCON_SET_LONG(v3, 0);
	ws0:
	PHALCON_CALL_METHOD(r0, v0, "isrouted", PHALCON_CALL_DEFAULT);
	if(!zend_is_true(r0)){
		goto we0;
	}
	PHALCON_CALL_METHOD_NORETURN(v0, "finish", PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CALL_METHOD(v4, t4, "getcontrollername", PHALCON_CALL_DEFAULT);
	if(!zend_is_true(v4)){
		PHALCON_NEW(i1, phalcon_exception_class_entry);
		PHALCON_PARAM_STRING(p6[0], "No controller name specified", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p6, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_PARAM_CPY(p7[0], v4);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_utils", "camelize", 1, p7);
	phalcon_concat_right(&r2, r1, "Controller" TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r2);
	t5 = zend_read_static_property(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t6, t5, v5);
	if(!zend_is_true(t6)){
		phalcon_concat_vboth(&r3, v1, "app/controllers/", v5 TSRMLS_CC);
		phalcon_concat_right(&r4, r3, ".php" TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r4);
		if(phalcon_file_exists(v6 TSRMLS_CC)==SUCCESS){
			phalcon_require(v6 TSRMLS_CC);
			if(EG(exception)||EG(exit_status)==255){
				return;
			}
		} else {
			PHALCON_NEW(i2, phalcon_exception_class_entry);
			phalcon_concat_both(&r5,  "File for controller class ", v5, " doesn't exists" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p8[0], r5);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p8, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i2 TSRMLS_CC);
			Z_ADDREF_P(i2);
			return;
		}
		PHALCON_PARAM_CPY(p9[0], v5);
		PHALCON_INIT_FALSE(t7);
		PHALCON_PARAM_ZVAL(p9[1], t7);
		PHALCON_CALL_FUNC_PARAMS(r6, "class_exists", 2, p9);
		if(!zend_is_true(r6)){
			PHALCON_NEW(i3, phalcon_exception_class_entry);
			phalcon_concat_both(&r7,  "Class ", v5, " was not found on controller file" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p10[0], r7);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p10, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i3 TSRMLS_CC);
			Z_ADDREF_P(i3);
			return;
		}
		ce0 = zend_fetch_class(Z_STRVAL_P(v5), Z_STRLEN_P(v5), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_NEW(i4, ce0);
		PHALCON_PARAM_CPY(p11[0], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 1, p11, PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v2, i4);
		PHALCON_SET_STRING(t8, "initialize", 0);
		if(phalcon_method_exists(v2, t8 TSRMLS_CC)==SUCCESS){
			PHALCON_CALL_METHOD_NORETURN(v2, "initialize", PHALCON_CALL_DEFAULT);
		}
		t9 = zend_read_static_property(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if(Z_TYPE_P(t9)!=IS_ARRAY){
			array_init(t9);
		}
		PHALCON_ARRUPDATE(t9, v5, v2);
		zend_update_static_property(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, t9 TSRMLS_CC);
		
	} else {
		t10 = zend_read_static_property(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ARRFETCH_NOISY(t11, t10, v5);
		PHALCON_CPY_WRT(v2, t11);
	}
	PHALCON_READ_PROPERTY_NOISY(t12, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CALL_METHOD(v7, t12, "getparams", PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t13, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CALL_METHOD(v8, t13, "getactionname", PHALCON_CALL_DEFAULT);
	phalcon_concat_right(&r8, v8, "Action" TSRMLS_CC);
	PHALCON_CPY_WRT(v9, r8);
	if(phalcon_method_exists(v2, v9 TSRMLS_CC)==SUCCESS){
		PHALCON_INIT_ARRAY(a0);
		PHALCON_CPY_WRT(t14, v2);
		add_next_index_zval(a0, t14);
		PHALCON_CPY_WRT(t15, v9);
		add_next_index_zval(a0, t15);
		PHALCON_PARAM_ZVAL(p15[0], a0);
		PHALCON_PARAM_CPY(p15[1], v7);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p15);
	} else {
		PHALCON_SET_STRING(t16, "notFoundAction", 1);
		if(phalcon_method_exists(v2, t16 TSRMLS_CC)==SUCCESS){
			PHALCON_INIT_ARRAY(a1);
			PHALCON_CPY_WRT(t17, v2);
			add_next_index_zval(a1, t17);
			add_next_index_string(a1, "notFoundAction", 1);
			PHALCON_PARAM_ZVAL(p16[0], a1);
			PHALCON_PARAM_CPY(p16[1], v7);
			PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p16);
		} else {
			PHALCON_NEW(i5, phalcon_exception_class_entry);
			phalcon_concat_left(&r10, "Action '", v8 TSRMLS_CC);
			phalcon_concat_vboth(&r9, r10, "' was not found on controller '", v4 TSRMLS_CC);
			phalcon_concat_right(&r11, r9, "'" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p17[0], r11);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i5, "__construct", 1, p17, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i5 TSRMLS_CC);
			Z_ADDREF_P(i5);
			return;
		}
	}
	increment_function(v3);
	PHALCON_SET_LONG(t18, 256);
	PHALCON_SMALLER_FUNCTION(r12, t18, v3);
	if(zend_is_true(r12)){
		PHALCON_NEW(i6, phalcon_exception_class_entry);
		PHALCON_PARAM_STRING(p18[0], "Dispatcher has detected a cyclic routing causing stability problems", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i6, "__construct", 1, p18, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i6 TSRMLS_CC);
		Z_ADDREF_P(i6);
		return;
	}
	goto ws0;
	we0:
	r0 = NULL;
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Dispatcher, setRouter){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Dispatcher, getRouter){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_router", sizeof("_router")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Dispatcher, getFrontController){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_frontController", sizeof("_frontController")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Dispatcher, getControllers){

	zval *t0 = NULL;

	t0 = zend_read_static_property(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Request, __construct){


	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	t0 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if(!zend_is_true(t0)){
		PHALCON_NEW(i0, phalcon_request_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Request, setFilter){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getFilter){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_filter", sizeof("_filter")-1);
	if(!zend_is_true(t0)){
		PHALCON_NEW(i0, phalcon_filter_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), i0 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_filter", sizeof("_filter")-1);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Request, getPost){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	
	PHALCON_GET_GLOBAL(a0, "_POST", gv0);
	PHALCON_ARRFETCH_SILENT(r0, a0, v0);
	if(zend_is_true(r0)){
		if(zend_is_true(v1)){
			PHALCON_CALL_METHOD(r2, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			PHALCON_PARAM_ZVAL(p0[0], r0);
			PHALCON_PARAM_CPY(p0[1], v1);
			PHALCON_CALL_METHOD_PARAMS(r1, r2, "sanitize", 2, p0, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r1, 0, 0);
		} else {
			PHALCON_ARRFETCH_NOISY(r3, a0, v0);
			RETURN_ZVAL(r3, 0, 0);
		}
	} else {
		RETURN_NULL();
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getQuery){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	
	PHALCON_GET_GLOBAL(a0, "_GET", gv0);
	PHALCON_ARRFETCH_SILENT(r0, a0, v0);
	if(zend_is_true(r0)){
		if(zend_is_true(v1)){
			PHALCON_CALL_METHOD(r2, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			PHALCON_PARAM_ZVAL(p0[0], r0);
			PHALCON_PARAM_CPY(p0[1], v1);
			PHALCON_CALL_METHOD_PARAMS(r1, r2, "sanizite", 2, p0, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r1, 0, 0);
		} else {
			PHALCON_ARRFETCH_NOISY(r3, a0, v0);
			RETURN_ZVAL(r3, 0, 0);
		}
	} else {
		RETURN_NULL();
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isAjax){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_PARAM_STRING(p0[0], "HTTP_X_REQUESTED_WITH", 0);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getheader", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_SET_STRING(t0, "XMLHttpRequest", 1);
	PHALCON_EQUAL_FUNCTION(r1, r0, t0);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Request, isFlashRequested){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL }, *p0[] = { NULL }, *p2[] = { NULL, NULL };

	PHALCON_PARAM_STRING(p1[0], "HTTP_USER_AGENT", 0);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getheader", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_ZVAL(p0[0], r0);
	PHALCON_CALL_FUNC_PARAMS(v0, "strtolower", 1, p0);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_STRING(p2[1], " flash", 0);
	PHALCON_CALL_FUNC_PARAMS(r1, "strpos", 2, p2);
	PHALCON_INIT_FALSE(t0);
	PHALCON_NOT_IDENTICAL_FUNCTION(r2, r1, t0);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Request, isSoapRequested){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "HTTP_SOAPACTION");
	if(zend_is_true(r0)){
		RETURN_TRUE;
	} else {
		PHALCON_ARRFETCH_STRING_SILENT(r1, a0, "CONTENT_TYPE");
		if(zend_is_true(r1)){
			PHALCON_PARAM_ZVAL(p0[0], r1);
			PHALCON_PARAM_STRING(p0[1], "application/soap+xml", 0);
			PHALCON_CALL_FUNC_PARAMS(r2, "strpos", 2, p0);
			PHALCON_INIT_FALSE(t0);
			PHALCON_NOT_IDENTICAL_FUNCTION(r3, r2, t0);
			RETURN_ZVAL(r3, 0, 0);
		} else {
			RETURN_FALSE;
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isSecureRequest){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	PHALCON_SET_STRING(t0, "https", 1);
	PHALCON_IDENTICAL_FUNCTION(r1, r0, t0);
	if(zend_is_true(r1)){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getRawBody){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_PARAM_STRING(p0[0], "php://input", 0);
	PHALCON_CALL_FUNC_PARAMS(r0, "file_get_contents", 1, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Request, getServerAddress){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "SERVER_ADDR");
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_PARAM_STRING(p0[0], "localhost", 0);
		PHALCON_CALL_FUNC_PARAMS(r1, "gethostbyname", 1, p0);
		RETURN_ZVAL(r1, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getServerName){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "SERVER_NAME");
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		RETURN_STRING("localhost", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getHeader){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval **gv0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_SILENT(r0, a0, v0);
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		phalcon_concat_left(&r1, "HTTP_", v0 TSRMLS_CC);
		PHALCON_ARRFETCH_SILENT(r2, a0, r1);
		if(zend_is_true(r2)){
			phalcon_concat_left(&r3, "HTTP_", v0 TSRMLS_CC);
			PHALCON_ARRFETCH_NOISY(r4, a0, r3);
			RETURN_ZVAL(r4, 0, 0);
		} else {
			RETURN_STRING("", 1);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getScheme){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_PARAM_STRING(p0[0], "HTTP_HTTPS", 0);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getparamserver", 1, p0, PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "on")){
		RETURN_STRING("https", 1);
	} else {
		RETURN_STRING("http", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getHttpHost){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_CALL_METHOD(v0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_STRING(p1[0], "HTTP_SERVER_NAME", 0);
	PHALCON_CALL_METHOD_PARAMS(v1, this_ptr, "getparamserver", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_STRING(p2[0], "HTTP_SERVER_PORT", 0);
	PHALCON_CALL_METHOD_PARAMS(v2, this_ptr, "getparamserver", 1, p2, PHALCON_CALL_DEFAULT);
	PHALCON_SET_STRING(t0, "http", 1);
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	PHALCON_SET_LONG(t1, 80);
	PHALCON_EQUAL_FUNCTION(r1, v2, t1);
	PHALCON_AND_FUNCTION(r2, r0, r1);
	PHALCON_SET_STRING(t2, "https", 1);
	PHALCON_EQUAL_FUNCTION(r3, v0, t2);
	PHALCON_SET_LONG(t3, 443);
	PHALCON_EQUAL_FUNCTION(r4, v2, t3);
	PHALCON_AND_FUNCTION(r5, r3, r4);
	PHALCON_OR_FUNCTION(r6, r2, r5);
	if(zend_is_true(r6)){
		RETURN_ZVAL(v1, 0, 0);
	} else {
		phalcon_concat_vboth(&r7, v1, ":", v2 TSRMLS_CC);
		RETURN_ZVAL(r7, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getMethod){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "REQUEST_METHOD");
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getUserAgent){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "HTTP_USER_AGENT");
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isPost){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "POST")){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isGet){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "GET")){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isPut){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "PUT")){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isHead){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "HEAD")){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isDelete){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "DELETE")){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, isOptions){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if(phalcon_compare_strict_string(r0, "OPTIONS")){
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, hasFiles){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };

	PHALCON_GET_GLOBAL(a0, "_FILES", gv0);
	if(zend_is_true(a0)){
		PHALCON_PARAM_CPY(p0[0], a0);
		PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
		PHALCON_SET_LONG(t0, 0);
		PHALCON_SMALLER_FUNCTION(r2, t0, r1);
		if(zend_is_true(r2)){
			PHALCON_INIT_TRUE(t1);
			r0 = t1;
		} else {
			PHALCON_INIT_FALSE(t2);
			r0 = t2;
		}
		RETURN_ZVAL(r0, 0, 0);
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getUploadedFiles){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_class_entry *ce0;

	PHALCON_GET_GLOBAL(a0, "_FILES", gv0);
	if(zend_is_true(a0)){
		PHALCON_INIT_ARRAY(v0);
		FOREACH_V(a0, ac0, fes1, fee1, ah0, hp0, v1)
			ce0 = zend_fetch_class("controlleruploadfile", strlen("controlleruploadfile"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_NEW(i0, ce0);
			PHALCON_PARAM_CPY(p0[0], v1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v2, i0);
			PHALCON_CPY_WRT(t0, v2);
			PHALCON_ARRAPPEND(v0, t0);
		END_FOREACH(ac0, fes1, fee1, ah0, hp0);
		RETURN_ZVAL(v0, 0, 0);
	} else {
		PHALCON_INIT_ARRAY(a1);
		RETURN_ZVAL(a1, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getHTTPReferer){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "HTTP_REFERER");
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Request, getAcceptableContent){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_PARAM_STRING(p0[0], "HTTP_ACCEPT", 0);
	PHALCON_CALL_FUNC_PARAMS(v0, "getenv", 1, p0);
	PHALCON_PARAM_STRING(p1[0], "/,\s*/", 0);
	PHALCON_PARAM_CPY(p1[1], v0);
	PHALCON_CALL_FUNC_PARAMS(v1, "preg_split", 2, p1);
	PHALCON_INIT_ARRAY(v2);
	FOREACH_V(v1, ac0, fes2, fee2, ah0, hp0, v3)
		PHALCON_PARAM_STRING(p2[0], ";", 0);
		PHALCON_PARAM_CPY(p2[1], v3);
		PHALCON_CALL_FUNC_PARAMS(v4, "explode", 2, p2);
		PHALCON_ARRFETCH_LONG_SILENT(r0, v4, 1);
		if(zend_is_true(r0)){
			PHALCON_PARAM_ZVAL(p3[0], r0);
			PHALCON_PARAM_LONG(p3[1], 2);
			PHALCON_CALL_FUNC_PARAMS(v5, "substr", 2, p3);
		} else {
			//Wasted infer static type 
			PHALCON_INIT_DOUBLE(t0, 1);
			PHALCON_CPY_WRT(v5, t0);
		}
		PHALCON_INIT_ARRAY(a0);
		PHALCON_ARRFETCH_LONG_NOISY(r1, v4, 0);
		add_assoc_zval(a0, "accept", r1);
		PHALCON_CPY_WRT(t1, v5);
		add_assoc_zval(a0, "quality", t1);
		PHALCON_ARRAPPEND(v2, a0);
	END_FOREACH(ac0, fes2, fee2, ah0, hp0);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Request, getClientCharsets){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_PARAM_STRING(p0[0], "HTTP_ACCEPT_CHARSET", 0);
	PHALCON_CALL_FUNC_PARAMS(v0, "getenv", 1, p0);
	PHALCON_PARAM_STRING(p1[0], "/,\s*/", 0);
	PHALCON_PARAM_CPY(p1[1], v0);
	PHALCON_CALL_FUNC_PARAMS(v1, "preg_split", 2, p1);
	PHALCON_INIT_ARRAY(v2);
	FOREACH_V(v1, ac0, fes3, fee3, ah0, hp0, v3)
		PHALCON_PARAM_STRING(p2[0], ";", 0);
		PHALCON_PARAM_CPY(p2[1], v3);
		PHALCON_CALL_FUNC_PARAMS(v4, "explode", 2, p2);
		PHALCON_ARRFETCH_LONG_SILENT(r0, v4, 1);
		if(zend_is_true(r0)){
			PHALCON_PARAM_ZVAL(p3[0], r0);
			PHALCON_PARAM_LONG(p3[1], 2);
			PHALCON_CALL_FUNC_PARAMS(v5, "substr", 2, p3);
		} else {
			//Wasted infer static type 
			PHALCON_INIT_DOUBLE(t0, 1);
			PHALCON_CPY_WRT(v5, t0);
		}
		PHALCON_INIT_ARRAY(a0);
		PHALCON_ARRFETCH_LONG_NOISY(r1, v4, 0);
		add_assoc_zval(a0, "accept", r1);
		PHALCON_CPY_WRT(t1, v5);
		add_assoc_zval(a0, "quality", t1);
		PHALCON_ARRAPPEND(v2, a0);
	END_FOREACH(ac0, fes3, fee3, ah0, hp0);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Request, getBestQualityCharset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_SET_LONG(v0, 0);
	PHALCON_SET_STRING(v1, "", 1);
	PHALCON_SET_LONG(v2, 0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getclientcharsets", PHALCON_CALL_DEFAULT);
	FOREACH_V(r0, ac0, fes4, fee4, ah0, hp0, v3)
		PHALCON_SET_LONG(t0, 0);
		PHALCON_EQUAL_FUNCTION(r1, v2, t0);
		if(zend_is_true(r1)){
			PHALCON_ARRFETCH_STRING_NOISY(r2, v3, "quality");
			PHALCON_CPY_WRT(v0, r2);
			PHALCON_ARRFETCH_STRING_NOISY(r3, v3, "accept");
			PHALCON_CPY_WRT(v1, r3);
		} else {
			PHALCON_ARRFETCH_STRING_NOISY(r4, v3, "quality");
			PHALCON_SMALLER_FUNCTION(r5, v0, r4);
			if(zend_is_true(r5)){
				PHALCON_ARRFETCH_STRING_NOISY(r6, v3, "quality");
				PHALCON_CPY_WRT(v0, r6);
				PHALCON_ARRFETCH_STRING_NOISY(r7, v3, "accept");
				PHALCON_CPY_WRT(v1, r7);
			}
		}
		increment_function(v2);
	END_FOREACH(ac0, fes4, fee4, ah0, hp0);
	RETURN_ZVAL(v1, 0, 0);
}

PHP_METHOD(Phalcon_Request, getClientAddress){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;

	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "HTTP_X_FORWARDED_FOR");
	if(zend_is_true(r0)){
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_ARRFETCH_STRING_SILENT(r1, a0, "REMOTE_ADDR");
		if(zend_is_true(r1)){
			RETURN_ZVAL(r1, 0, 0);
		} else {
			RETURN_STRING("", 1);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, __construct){


	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, getInstance){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	t0 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	if(zend_is_true(r0)){
		PHALCON_NEW(i0, phalcon_controller_front_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Controller_Front, setConfig){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *s0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)==IS_OBJECT){
		PHALCON_READ_PROPERTY_SILENT(t0, v0, "database", sizeof("database")-1);
		if(zend_is_true(t0)){
			PHALCON_PARAM_ZVAL(p0[0], t0);
			PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_db_pool", "setdefaultdescriptor", 1, p0);
		}
		PHALCON_CPY_WRT(s0, v0);
		phalcon_update_property_zval(this_ptr, "_config", strlen("_config"), s0 TSRMLS_CC);
	} else {
		PHALCON_NEW(i0, phalcon_exception_class_entry);
		PHALCON_PARAM_STRING(p1[0], "Config parameter should be an Object", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, setDispatcher){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1);
	if(zend_is_true(t0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_dispatcher", sizeof("_dispatcher")-1);
		RETURN_ZVAL(t1, 0, 0);
	} else {
		PHALCON_NEW(i0, phalcon_exception_class_entry);
		PHALCON_PARAM_STRING(p0[0], "Disptach process has not started yet", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, setBaseUri){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, getBaseUri){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *s0 = NULL;
	zval *v0 = NULL;
	zval *a0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL }, *p4[] = { NULL }, *p3[] = { NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_baseUri", sizeof("_baseUri")-1);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	if(zend_is_true(r0)){
		PHALCON_READ_PROPERTY_SILENT(t1, this_ptr, "_config", sizeof("_config")-1);
		PHALCON_READ_PROPERTY_SILENT(t2, t1, "spark", sizeof("spark")-1);
		PHALCON_READ_PROPERTY_SILENT(t3, t2, "baseuri", sizeof("baseuri")-1);
		if(zend_is_true(t3)){
			PHALCON_CPY_WRT(s0, t3);
			phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), s0 TSRMLS_CC);
		} else {
			PHALCON_PARAM_STRING(p3[0], "/", 0);
			PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
			PHALCON_ARRFETCH_STRING_NOISY(r4, a0, "PHP_SELF");
			PHALCON_PARAM_ZVAL(p4[0], r4);
			PHALCON_CALL_FUNC_PARAMS(r3, "dirname", 1, p4);
			PHALCON_PARAM_ZVAL(p3[1], r3);
			PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p3);
			PHALCON_PARAM_ZVAL(p2[0], r2);
			PHALCON_PARAM_LONG(p2[1], 1);
			PHALCON_SET_LONG(t5, 1);
			PHALCON_SET_LONG(t4, -1);
			PHALCON_MUL_FUNCTION(r5, t4, t5);
			PHALCON_PARAM_ZVAL(p2[2], r5);
			PHALCON_CALL_FUNC_PARAMS(r1, "array_slice", 3, p2);
			PHALCON_PARAM_ZVAL(p1[0], r1);
			PHALCON_PARAM_STRING(p1[1], "/", 0);
			PHALCON_CALL_FUNC_PARAMS(v0, "join", 2, p1);
			if(phalcon_compare_strict_string(v0, "")){
				phalcon_update_property_string(this_ptr, "_baseUri", strlen("_baseUri"), "/" TSRMLS_CC);
			} else {
				phalcon_concat_both(&r6,  "/", v0, "/" TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), r6 TSRMLS_CC);
			}
		}
	}
	PHALCON_READ_PROPERTY_NOISY(t6, this_ptr, "_baseUri", sizeof("_baseUri")-1);
	RETURN_ZVAL(t6, 0, 0);
}

PHP_METHOD(Phalcon_Controller_Front, setBasePath){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, getBasePath){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_basePath", sizeof("_basePath")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Controller_Front, setModelComponent){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller_Front, getModelComponent){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_model", sizeof("_model")-1);
	if(!zend_is_true(t0)){
		PHALCON_CALL_STATIC(r0, "phalcon_db_pool", "hasdefaultdescriptor");
		if(!zend_is_true(r0)){
			PHALCON_NEW(i0, phalcon_exception_class_entry);
			PHALCON_PARAM_STRING(p1[0], "There is not defined database connection parameters", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
		PHALCON_NEW(i1, phalcon_model_manager_class_entry);
		PHALCON_PARAM_CPY(p2[0], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), i1 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_model", sizeof("_model")-1);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Controller_Front, dispatchLoop){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *p0[] = { NULL }, *p4[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1);
	if(!zend_is_true(t0)){
		PHALCON_NEW(i0, phalcon_dispatcher_class_entry);
		PHALCON_PARAM_CPY(p0[0], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), i0 TSRMLS_CC);
	}
	PHALCON_CALL_FUNC_NORETURN("ob_start");
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_dispatcher", sizeof("_dispatcher")-1);
	PHALCON_CALL_METHOD(v0, t1, "dispatch", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v1, v0, "getviewcomponent", PHALCON_CALL_DEFAULT);
	if(Z_TYPE_P(v1)!=IS_NULL){
		PHALCON_PARAM_CPY(p4[0], v0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "render", 1, p4, PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *v0 = NULL;
	zval *s0 = NULL;

	PHALCON_INIT_ARRAY(a0);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
	PHALCON_INIT_ARRAY(a1);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesBefore", strlen("_templatesBefore"), a1 TSRMLS_CC);
	PHALCON_INIT_ARRAY(a2);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesAfter", strlen("_templatesAfter"), a2 TSRMLS_CC);
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_frontController", strlen("_frontController"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setViewsDir){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setTemplateBefore){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_ARRAY(a0);
	PHALCON_CPY_WRT(t0, v0);
	add_next_index_zval(a0, t0);
	PHALCON_CPY_WRT(s0, a0);
	phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setTemplateAfter){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_ARRAY(a0);
	PHALCON_CPY_WRT(t0, v0);
	add_next_index_zval(a0, t0);
	PHALCON_CPY_WRT(s0, a0);
	phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setParamToView){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, "_params", sizeof("_params")-1);
	PHALCON_CPY_WRT(t1, v1);
	PHALCON_ARRUPDATE(t0, v0, t1);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_params", strlen("_params"), t0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, render){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *ac0 = NULL, *ac1 = NULL, *ac2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p8[] = { NULL }, *p13[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_frontController", sizeof("_frontController")-1);
	PHALCON_CALL_METHOD(v1, t0, "getbasepath", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getcontrollername", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v3, v0, "getactionname", PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_params", sizeof("_params")-1);
	FOREACH_KV(t1, ac0, fes5, fee5, ah0, hp0, v5, v4)
		ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v5), v4);
	END_FOREACH(ac0, fes5, fee5, ah0, hp0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents");
	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r0 TSRMLS_CC);
	phalcon_concat_right(&r1, v1, "app/views/" TSRMLS_CC);
	PHALCON_CPY_WRT(v6, r1);
	PHALCON_CONCAT_FUNCTION(r3, v6, v2);
	phalcon_concat_vboth(&r2, r3, "/", v3 TSRMLS_CC);
	phalcon_concat_right(&r4, r2, ".phtml" TSRMLS_CC);
	PHALCON_CPY_WRT(v7, r4);
	if(phalcon_file_exists(v7 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_require(v7 TSRMLS_CC);
		if(EG(exception)||EG(exit_status)==255){
			return;
		}
		PHALCON_CALL_FUNC(r5, "ob_get_contents");
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r5 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1);
	PHALCON_CPY_WRT(v8, t2);
	PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1);
	PHALCON_CPY_WRT(v9, t3);
	if(Z_TYPE_P(v9)==IS_ARRAY){
		PHALCON_CPY_WRT(v7, v6);
		if(phalcon_compare_strict_string(v8, "")){
			PHALCON_SET_STRING(t4, "layouts/", 0);
			PHALCON_CONCAT_FUNCTION(r6, v7, t4);
			PHALCON_CPY_WRT(v7, r6);
		} else {
			phalcon_concat_right(&r7, v8, "/" TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r8, v7, r7);
			PHALCON_CPY_WRT(v7, r8);
		}
		FOREACH_V(v9, ac1, fes6, fee6, ah1, hp1, v10)
			PHALCON_CONCAT_FUNCTION(r9, v7, v10);
			phalcon_concat_right(&r10, r9, ".phtml" TSRMLS_CC);
			PHALCON_CPY_WRT(v11, r10);
			if(phalcon_file_exists(v11 TSRMLS_CC)==SUCCESS){
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_require(v11 TSRMLS_CC);
				if(EG(exception)||EG(exit_status)==255){
					return;
				}
				PHALCON_CALL_FUNC(r11, "ob_get_contents");
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r11 TSRMLS_CC);
			} else {
				PHALCON_NEW(i0, phalcon_view_exception_class_entry);
				phalcon_concat_both(&r12,  "Template '", v10, "' was not found on templates directory" TSRMLS_CC);
				PHALCON_PARAM_ZVAL(p8[0], r12);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p8, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		END_FOREACH(ac1, fes6, fee6, ah1, hp1);
	}
	PHALCON_CPY_WRT(v7, v6);
	if(phalcon_compare_strict_string(v8, "")){
		PHALCON_SET_STRING(t5, "layouts/", 0);
		PHALCON_CONCAT_FUNCTION(r13, v7, t5);
		PHALCON_CPY_WRT(v7, r13);
	} else {
		phalcon_concat_right(&r14, v8, "/" TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r15, v7, r14);
		PHALCON_CPY_WRT(v7, r15);
	}
	phalcon_concat_right(&r16, v2, ".phtml" TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r17, v7, r16);
	PHALCON_CPY_WRT(v7, r17);
	if(phalcon_file_exists(v7 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_require(v7 TSRMLS_CC);
		if(EG(exception)||EG(exit_status)==255){
			return;
		}
		PHALCON_CALL_FUNC(r18, "ob_get_contents");
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r18 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t6, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1);
	PHALCON_CPY_WRT(v12, t6);
	if(Z_TYPE_P(v12)==IS_ARRAY){
		PHALCON_CPY_WRT(v7, v6);
		if(phalcon_compare_strict_string(v8, "")){
			PHALCON_SET_STRING(t7, "layouts/", 0);
			PHALCON_CONCAT_FUNCTION(r19, v7, t7);
			PHALCON_CPY_WRT(v7, r19);
		} else {
			phalcon_concat_right(&r20, v8, "/" TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r21, v7, r20);
			PHALCON_CPY_WRT(v7, r21);
		}
		FOREACH_V(v12, ac2, fes7, fee7, ah2, hp2, v13)
			PHALCON_CONCAT_FUNCTION(r22, v7, v13);
			phalcon_concat_right(&r23, r22, ".phtml" TSRMLS_CC);
			PHALCON_CPY_WRT(v11, r23);
			if(phalcon_file_exists(v11 TSRMLS_CC)==SUCCESS){
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_require(v11 TSRMLS_CC);
				if(EG(exception)||EG(exit_status)==255){
					return;
				}
				PHALCON_CALL_FUNC(r24, "ob_get_contents");
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r24 TSRMLS_CC);
			} else {
				PHALCON_NEW(i1, phalcon_view_exception_class_entry);
				phalcon_concat_both(&r25,  "Template '", v10, "' was not found on templates directory" TSRMLS_CC);
				PHALCON_PARAM_ZVAL(p13[0], r25);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p13, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i1 TSRMLS_CC);
				Z_ADDREF_P(i1);
				return;
			}
		END_FOREACH(ac2, fes7, fee7, ah2, hp2);
	}
	phalcon_concat_right(&r26, v1, "app/views/index.phtml" TSRMLS_CC);
	PHALCON_CPY_WRT(v7, r26);
	if(phalcon_file_exists(v7 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_require(v7 TSRMLS_CC);
		if(EG(exception)||EG(exit_status)==255){
			return;
		}
		PHALCON_CALL_FUNC(r27, "ob_get_contents");
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r27 TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_content", sizeof("_content")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_View, url){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_frontController", sizeof("_frontController")-1);
	PHALCON_CPY_WRT(v1, t0);
	if(Z_TYPE_P(v0)==IS_ARRAY){
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("print_r", 1, p0);
	} else {
		PHALCON_CALL_METHOD(r0, v1, "getbaseuri", PHALCON_CALL_DEFAULT);
		PHALCON_CONCAT_FUNCTION(r1, r0, v0);
		RETURN_ZVAL(r1, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, path){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_frontController", sizeof("_frontController")-1);
	PHALCON_CPY_WRT(v1, t0);
	PHALCON_CALL_METHOD(r0, v1, "getbasepath", PHALCON_CALL_DEFAULT);
	PHALCON_CONCAT_FUNCTION(r1, r0, v0);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Test, nice){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_ARRAY(v1);
	add_assoc_long(v1, "hello1", 1);
	add_assoc_long(v1, "hello2", 2);
	add_assoc_long(v1, "hello3", 3);
	FOREACH_KV(v1, ac0, fes8, fee8, ah0, hp0, v3, v2)
		PHALCON_ARRFETCH_NOISY(r0, v1, v3);
		PHALCON_SET_LONG(t0, 100);
		PHALCON_ADD_FUNCTION(r1, r0, t0);
		PHALCON_ARRUPDATE(v1, v3, r1);
	END_FOREACH(ac0, fes8, fee8, ah0, hp0);
	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("print_r", 1, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Utils, camelize){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p2[] = { NULL, NULL, NULL }, *p1[] = { NULL }, *p0[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_STRING(p0[0], " ", 0);
	PHALCON_PARAM_STRING(p0[1], "", 0);
	PHALCON_PARAM_STRING(p2[0], "_", 0);
	PHALCON_PARAM_STRING(p2[1], " ", 0);
	PHALCON_PARAM_CPY(p2[2], v0);
	PHALCON_CALL_FUNC_PARAMS(r2, "str_replace", 3, p2);
	PHALCON_PARAM_ZVAL(p1[0], r2);
	PHALCON_CALL_FUNC_PARAMS(r1, "ucwords", 1, p1);
	PHALCON_PARAM_ZVAL(p0[2], r1);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Utils, uncamelize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p1[] = { NULL }, *p3[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_ARRAY(v1);
	add_assoc_string(v1, "/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/", "\\1_\\2", 1);
	add_assoc_string(v1, "/(?<=(?:[a-z]))([A-Z])/", "_\\1", 1);
	FOREACH_KV(v1, ac0, fes9, fee9, ah0, hp0, v3, v2)
		PHALCON_PARAM_CPY(p0[0], v3);
		PHALCON_PARAM_CPY(p0[1], v0);
		PHALCON_CALL_FUNC_PARAMS(r0, "preg_match", 2, p0);
		if(zend_is_true(r0)){
			PHALCON_PARAM_CPY(p2[0], v3);
			PHALCON_PARAM_CPY(p2[1], v2);
			PHALCON_PARAM_CPY(p2[2], v0);
			PHALCON_CALL_FUNC_PARAMS(r2, "preg_replace", 3, p2);
			PHALCON_PARAM_ZVAL(p1[0], r2);
			PHALCON_CALL_FUNC_PARAMS(r1, "strtolower", 1, p1);
			RETURN_ZVAL(r1, 0, 0);
		}
	END_FOREACH(ac0, fes9, fee9, ah0, hp0);
	PHALCON_PARAM_CPY(p3[0], v0);
	PHALCON_CALL_FUNC_PARAMS(r3, "strtolower", 1, p3);
	RETURN_ZVAL(r3, 0, 0);
}

PHP_METHOD(Phalcon_Utils, getUrl){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbaseuri", PHALCON_CALL_DEFAULT);
	PHALCON_CONCAT_FUNCTION(r2, r0, v0);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Db, __construct){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_descriptor", strlen("_descriptor"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, setLogger){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_logger", strlen("_logger"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, log){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_logger", sizeof("_logger")-1);
	if(zend_is_true(t0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_logger", sizeof("_logger")-1);
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_PARAM_CPY(p0[1], v1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, fetchOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_METHOD_PARAMS(v1, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	if(zend_is_true(v1)){
		PHALCON_PARAM_CPY(p1[0], v1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_INIT_ARRAY(a0);
		RETURN_ZVAL(a0, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, fetchAll){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_ARRAY(v1);
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_METHOD_PARAMS(v2, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_INIT_FALSE(t0);
	PHALCON_NOT_EQUAL_FUNCTION(r0, v2, t0);
	if(zend_is_true(r0)){
		ws10:
		PHALCON_PARAM_CPY(p1[0], v2);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v3, r1);
		if(!zend_is_true(v3)){
			goto we10;
		}
		PHALCON_CPY_WRT(t1, v3);
		PHALCON_ARRAPPEND(v1, t1);
		goto ws10;
		we10:
		v3 = NULL;
	}
	RETURN_ZVAL(v1, 0, 0);
}

PHP_METHOD(Phalcon_Db, insert){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE){
		RETURN_NULL();
	}

	if(!v2){
		PHALCON_INIT_NULL(v2);
	}
	if(!v3){
		PHALCON_INIT_BOOL(v3, 0);
	}
	
	PHALCON_SET_STRING(v4, "", 1);
	if(Z_TYPE_P(v1)==IS_ARRAY){
		PHALCON_PARAM_CPY(p0[0], v1);
		PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
		PHALCON_SET_LONG(t0, 0);
		PHALCON_EQUAL_FUNCTION(r1, r0, t0);
		if(zend_is_true(r1)){
			PHALCON_NEW(i0, phalcon_db_exception_class_entry);
			phalcon_concat_both(&r2,  "Unable to insert into ", v0, " without data" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p1[0], r2);
			PHALCON_PARAM_LONG(p1[1], 0);
			PHALCON_INIT_TRUE(t1);
			PHALCON_PARAM_ZVAL(p1[2], t1);
			PHALCON_PARAM_CPY(p1[3], this_ptr);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		} else {
			if(zend_is_true(v3)){
				FOREACH_KV(v1, ac0, fes11, fee11, ah0, hp0, v6, v5)
					PHALCON_ARRFETCH_NOISY(r3, v1, v6);
					if(Z_TYPE_P(r3)==IS_OBJECT){
						PHALCON_ARRFETCH_NOISY(r4, v1, v6);
						PHALCON_INSTANCE_OF(r5, r4, phalcon_db_rawvalue_class_entry);
						if(zend_is_true(r5)){
							PHALCON_ARRFETCH_NOISY(r8, v1, v6);
							PHALCON_CALL_METHOD(r7, r8, "getvalue", PHALCON_CALL_DEFAULT);
							PHALCON_PARAM_ZVAL(p2[0], r7);
							PHALCON_CALL_FUNC_PARAMS(r6, "addslashes", 1, p2);
							PHALCON_ARRUPDATE(v1, v6, r6);
						} else {
							PHALCON_ARRFETCH_NOISY(r10, v1, v6);
							PHALCON_PARAM_ZVAL(p4[0], r10);
							PHALCON_CALL_FUNC_PARAMS(r9, "addslashes", 1, p4);
							phalcon_concat_both(&r11,  "'", r9, "'" TSRMLS_CC);
							PHALCON_ARRUPDATE(v1, v6, r11);
						}
					} else {
						PHALCON_ARRFETCH_NOISY(r13, v1, v6);
						PHALCON_PARAM_ZVAL(p5[0], r13);
						PHALCON_CALL_FUNC_PARAMS(r12, "addslashes", 1, p5);
						phalcon_concat_both(&r14,  "'", r12, "'" TSRMLS_CC);
						PHALCON_ARRUPDATE(v1, v6, r14);
					}
				END_FOREACH(ac0, fes11, fee11, ah0, hp0);
			}
		}
		if(Z_TYPE_P(v2)==IS_ARRAY){
			phalcon_concat_left(&r17, "INSERT INTO ", v0 TSRMLS_CC);
			PHALCON_PARAM_STRING(p6[0], ", ", 0);
			PHALCON_PARAM_CPY(p6[1], v2);
			PHALCON_CALL_FUNC_PARAMS(r18, "join", 2, p6);
			phalcon_concat_vboth(&r16, r17, " (", r18 TSRMLS_CC);
			PHALCON_PARAM_STRING(p7[0], ", ", 0);
			PHALCON_PARAM_CPY(p7[1], v1);
			PHALCON_CALL_FUNC_PARAMS(r19, "join", 2, p7);
			phalcon_concat_vboth(&r15, r16, ") VALUES (", r19 TSRMLS_CC);
			phalcon_concat_right(&r20, r15, ")" TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r20);
		} else {
			phalcon_concat_left(&r22, "INSERT INTO ", v0 TSRMLS_CC);
			PHALCON_PARAM_STRING(p8[0], ", ", 0);
			PHALCON_PARAM_CPY(p8[1], v1);
			PHALCON_CALL_FUNC_PARAMS(r23, "join", 2, p8);
			phalcon_concat_vboth(&r21, r22, " VALUES (", r23 TSRMLS_CC);
			phalcon_concat_right(&r24, r21, ")" TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r24);
		}
		PHALCON_PARAM_CPY(p9[0], v4);
		PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r25, 0, 0);
	} else {
		PHALCON_NEW(i1, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p10[0], "The second parameter for insert isn't an Array", 0);
		PHALCON_PARAM_LONG(p10[1], 0);
		PHALCON_INIT_TRUE(t2);
		PHALCON_PARAM_ZVAL(p10[2], t2);
		PHALCON_PARAM_CPY(p10[3], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p10, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, update){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE){
		RETURN_NULL();
	}

	if(!v3){
		PHALCON_INIT_NULL(v3);
	}
	if(!v4){
		PHALCON_INIT_BOOL(v4, 0);
	}
	
	phalcon_concat_both(&r0,  "UPDATE ", v0, " SET " TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r0);
	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
	PHALCON_PARAM_CPY(p1[0], v2);
	PHALCON_CALL_FUNC_PARAMS(r2, "count", 1, p1);
	PHALCON_NOT_EQUAL_FUNCTION(r3, r1, r2);
	if(zend_is_true(r3)){
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p2[0], "The number of values to update is not the same as fields", 0);
		PHALCON_PARAM_LONG(p2[1], 0);
		PHALCON_INIT_TRUE(t0);
		PHALCON_PARAM_ZVAL(p2[2], t0);
		PHALCON_PARAM_CPY(p2[3], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	PHALCON_SET_LONG(v6, 0);
	PHALCON_INIT_ARRAY(v7);
	FOREACH_V(v1, ac0, fes12, fee12, ah0, hp0, v8)
		if(zend_is_true(v4)){
			PHALCON_ARRFETCH_NOISY(r4, v2, v6);
			if(Z_TYPE_P(r4)==IS_OBJECT){
				PHALCON_ARRFETCH_NOISY(r5, v2, v6);
				PHALCON_INSTANCE_OF(r6, r5, phalcon_db_rawvalue_class_entry);
				if(zend_is_true(r6)){
					PHALCON_ARRFETCH_NOISY(r9, v2, v6);
					PHALCON_CALL_METHOD(r8, r9, "getvalue", PHALCON_CALL_DEFAULT);
					PHALCON_PARAM_ZVAL(p3[0], r8);
					PHALCON_CALL_FUNC_PARAMS(r7, "addslashes", 1, p3);
					PHALCON_ARRUPDATE(v2, v6, r7);
				} else {
					PHALCON_ARRFETCH_NOISY(r11, v2, v6);
					PHALCON_PARAM_ZVAL(p5[0], r11);
					PHALCON_CALL_FUNC_PARAMS(r10, "addslashes", 1, p5);
					phalcon_concat_both(&r12,  "'", r10, "'" TSRMLS_CC);
					PHALCON_ARRUPDATE(v2, v6, r12);
				}
			} else {
				PHALCON_ARRFETCH_NOISY(r14, v2, v6);
				PHALCON_PARAM_ZVAL(p6[0], r14);
				PHALCON_CALL_FUNC_PARAMS(r13, "addslashes", 1, p6);
				phalcon_concat_both(&r15,  "'", r13, "'" TSRMLS_CC);
				PHALCON_ARRUPDATE(v2, v6, r15);
			}
		}
		PHALCON_ARRFETCH_NOISY(r17, v2, v6);
		phalcon_concat_vboth(&r16, v8, " = ", r17 TSRMLS_CC);
		PHALCON_ARRAPPEND(v7, r16);
		increment_function(v6);
	END_FOREACH(ac0, fes12, fee12, ah0, hp0);
	PHALCON_PARAM_STRING(p7[0], ", ", 0);
	PHALCON_PARAM_CPY(p7[1], v7);
	PHALCON_CALL_FUNC_PARAMS(r18, "join", 2, p7);
	PHALCON_CONCAT_FUNCTION(r19, v5, r18);
	PHALCON_CPY_WRT(v5, r19);
	PHALCON_INIT_NULL(t1);
	PHALCON_NOT_EQUAL_FUNCTION(r20, v3, t1);
	if(zend_is_true(r20)){
		phalcon_concat_left(&r21, " WHERE ", v3 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r22, v5, r21);
		PHALCON_CPY_WRT(v5, r22);
	}
	PHALCON_PARAM_CPY(p8[0], v5);
	PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r23, 0, 0);
}

PHP_METHOD(Phalcon_Db, delete){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r0, "trim", 1, p0);
	if(!phalcon_compare_strict_string(r0, "")){
		phalcon_concat_left(&r3, "DELETE FROM ", v0 TSRMLS_CC);
		phalcon_concat_vboth(&r2, r3, " WHERE ", v1 TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r1, 0, 0);
	} else {
		phalcon_concat_left(&r5, "DELETE FROM ", v0 TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p2[0], r5);
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "query", 1, p2, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r4, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, begin){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 0 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 1 TSRMLS_CC);
	PHALCON_PARAM_STRING(p0[0], "BEGIN", 0);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1);
	if(zend_is_true(t0)){
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_PARAM_STRING(p0[0], "ROLLBACK", 0);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p1[0], "There is not an active transaction on relational manager", 0);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_INIT_TRUE(t1);
		PHALCON_PARAM_ZVAL(p1[2], t1);
		PHALCON_PARAM_CPY(p1[3], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1);
	if(zend_is_true(t0)){
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_PARAM_STRING(p0[0], "COMMIT", 0);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p1[0], "There is not an active transaction on relational manager", 0);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_INIT_TRUE(t1);
		PHALCON_PARAM_ZVAL(p1[2], t1);
		PHALCON_PARAM_CPY(p1[3], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, setUnderTransaction){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_underTransaction", strlen("_underTransaction"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Db, getHaveAutoCommit){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_autoCommit", sizeof("_autoCommit")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Db, getDatabaseName){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1);
	PHALCON_READ_PROPERTY_SILENT(t1, t0, "name", sizeof("name")-1);
	if(zend_is_true(t1)){
		RETURN_ZVAL(t1, 0, 0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getDefaultSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1);
	PHALCON_READ_PROPERTY_SILENT(t1, t0, "schema", sizeof("schema")-1);
	if(zend_is_true(t1)){
		RETURN_ZVAL(t1, 0, 0);
	} else {
		PHALCON_READ_PROPERTY_SILENT(t2, this_ptr, "_descriptor", sizeof("_descriptor")-1);
		PHALCON_READ_PROPERTY_SILENT(t3, t2, "name", sizeof("name")-1);
		if(zend_is_true(t3)){
			RETURN_ZVAL(t3, 0, 0);
		} else {
			RETURN_STRING("", 1);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getUsername){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1);
	PHALCON_READ_PROPERTY_SILENT(t1, t0, "username", sizeof("username")-1);
	if(zend_is_true(t1)){
		RETURN_ZVAL(t1, 0, 0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getHostName){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1);
	PHALCON_READ_PROPERTY_SILENT(t1, t0, "host", sizeof("host")-1);
	if(zend_is_true(t1)){
		RETURN_ZVAL(t1, 0, 0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Db, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *ac0 = NULL;
	zval *s0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	if(!v2){
		PHALCON_INIT_BOOL(v2, 0);
	}
	
	if(phalcon_compare_strict_string(v0, "")){
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p0[0], "A valid adapter name is required", 0);
		PHALCON_PARAM_LONG(p0[1], 0);
		PHALCON_INIT_TRUE(t0);
		PHALCON_PARAM_ZVAL(p0[2], t0);
		PHALCON_INIT_NULL(t1);
		PHALCON_PARAM_ZVAL(p0[3], t1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	if(Z_TYPE_P(v1)!=IS_ARRAY){
		if(Z_TYPE_P(v1)!=IS_OBJECT){
			PHALCON_NEW(i1, phalcon_db_exception_class_entry);
			PHALCON_PARAM_STRING(p1[0], "The parameter 'options' must be an Array or Object", 0);
			PHALCON_PARAM_LONG(p1[1], 0);
			PHALCON_INIT_TRUE(t2);
			PHALCON_PARAM_ZVAL(p1[2], t2);
			PHALCON_INIT_NULL(t3);
			PHALCON_PARAM_ZVAL(p1[3], t3);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i1 TSRMLS_CC);
			Z_ADDREF_P(i1);
			return;
		}
	}
	if(Z_TYPE_P(v1)==IS_ARRAY){
		PHALCON_NEW_STD(i2);
		PHALCON_CPY_WRT(v3, i2);
		FOREACH_KV(v1, ac0, fes13, fee13, ah0, hp0, v5, v4)
			PHALCON_CPY_WRT(s0, v4);
			phalcon_update_property_zval(v3, Z_STRVAL_P(v5), Z_STRLEN_P(v5), s0 TSRMLS_CC);
		END_FOREACH(ac0, fes13, fee13, ah0, hp0);
	} else {
		PHALCON_CPY_WRT(v3, v1);
	}
	PHALCON_READ_PROPERTY_SILENT(t4, v3, "layer", sizeof("layer")-1);
	if(zend_is_true(t4)){
		PHALCON_CPY_WRT(v6, t4);
	} else {
		PHALCON_SET_STRING(v6, "native", 1);
	}
	phalcon_concat_left(&r0, "Phalcon_Db_", v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v7, r0);
	PHALCON_PARAM_CPY(p2[0], v7);
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p2);
	if(zend_is_true(r1)){
		ce0 = zend_fetch_class(Z_STRVAL_P(v7), Z_STRLEN_P(v7), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_NEW(i3, ce0);
		PHALCON_PARAM_CPY(p3[0], v3);
		PHALCON_PARAM_CPY(p3[1], v2);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p3, PHALCON_CALL_CHECK);
		RETURN_ZVAL(i3, 0, 0);
	} else {
		PHALCON_NEW(i4, phalcon_db_exception_class_entry);
		phalcon_concat_both(&r2,  "Database adapter class ", v7, " was not found" TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p4[0], r2);
		PHALCON_PARAM_LONG(p4[1], 0);
		PHALCON_INIT_TRUE(t5);
		PHALCON_PARAM_ZVAL(p4[2], t5);
		PHALCON_INIT_NULL(t6);
		PHALCON_PARAM_ZVAL(p4[3], t6);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p4, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, e1){


	RETURN_LONG(5);
}

PHP_METHOD(Phalcon_Internal_Test, e2){


	RETURN_STRING("5", 1);
}

PHP_METHOD(Phalcon_Internal_Test, e3){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_SET_LONG(t1, 5);
	PHALCON_SET_LONG(t0, -1);
	PHALCON_MUL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e4){

	zval *v0 = NULL;

	PHALCON_SET_LONG(v0, 5);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	PHALCON_SET_LONG(v0, 5);
	PHALCON_CPY_WRT(v1, v0);
	PHALCON_CPY_WRT(v2, v1);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e6){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e7){

	zval *v0 = NULL, *v1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(v1, v0);
	RETURN_ZVAL(v1, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e8){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e9){


	RETURN_STRING("LOL", 1);
}

PHP_METHOD(Phalcon_Internal_Test, e10){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_INIT_ARRAY(v0);
	PHALCON_SET_STRING(t0, "LOL", 1);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_SET_LONG(t1, 0);
	phalcon_array_update_string(v0, "LOL", t1 TSRMLS_CC);
	PHALCON_ARRFETCH_STRING_NOISY(r0, v0, "LOL");
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e11){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_INIT_ARRAY(v0);
	PHALCON_SET_STRING(t0, "LOL", 1);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_SET_LONG(t1, 0);
	phalcon_array_update_string(v0, "LOL", t1 TSRMLS_CC);
	PHALCON_INIT_ARRAY(v1);
	PHALCON_SET_STRING(t2, "LOL", 1);
	phalcon_array_update_string(v1, "LOL", t2 TSRMLS_CC);
	PHALCON_SET_LONG(t3, 0);
	phalcon_array_update_long(v1, 0, t3 TSRMLS_CC);
	PHALCON_ARRFETCH_LONG_NOISY(r0, v1, 0);
	PHALCON_ARRFETCH_STRING_NOISY(r1, v0, "LOL");
	PHALCON_ADD_FUNCTION(r2, r0, r1);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e12){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;

	PHALCON_INIT_ARRAY(v0);
	PHALCON_SET_STRING(t0, "LOL", 1);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_INIT_ARRAY(a0);
	phalcon_array_update_long(v0, 1, a0 TSRMLS_CC);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_ARRFETCH_SILENT(r0, v0, t1);
	if(Z_TYPE_P(r0)!=IS_ARRAY){
		array_init(r0);
		PHALCON_ARRUPDATE(v0, t1, r0);
	}
	PHALCON_SET_LONG(t2, 1);
	phalcon_array_update_string(r0, "LOL", t2 TSRMLS_CC);
	PHALCON_SET_LONG(t3, 0);
	phalcon_array_update_string(v0, "LOL", t3 TSRMLS_CC);
	PHALCON_INIT_ARRAY(v1);
	PHALCON_SET_STRING(t4, "LOL", 1);
	phalcon_array_update_string(v1, "LOL", t4 TSRMLS_CC);
	PHALCON_SET_LONG(t5, 0);
	phalcon_array_update_long(v1, 0, t5 TSRMLS_CC);
	PHALCON_SET_LONG(t6, 1);
	PHALCON_ARRFETCH_SILENT(r1, v1, t6);
	if(Z_TYPE_P(r1)!=IS_ARRAY){
		array_init(r1);
		PHALCON_ARRUPDATE(v1, t6, r1);
	}
	PHALCON_SET_LONG(t7, 1);
	phalcon_array_update_string(r1, "LOL", t7 TSRMLS_CC);
	PHALCON_INIT_ARRAY(v2);
	PHALCON_INIT_ARRAY(a1);
	phalcon_array_update_long(v2, 0, a1 TSRMLS_CC);
	PHALCON_SET_LONG(t8, 0);
	PHALCON_ARRFETCH_SILENT(r2, v2, t8);
	if(Z_TYPE_P(r2)!=IS_ARRAY){
		array_init(r2);
		PHALCON_ARRUPDATE(v2, t8, r2);
	}
	PHALCON_INIT_ARRAY(a2);
	phalcon_array_update_long(r2, 0, a2 TSRMLS_CC);
	PHALCON_SET_LONG(t9, 0);
	PHALCON_SET_LONG(t10, 0);
	PHALCON_ARRFETCH_SILENT(r3, v2, t10);
	if(Z_TYPE_P(r3)!=IS_ARRAY){
		array_init(r3);
		PHALCON_ARRUPDATE(v2, t10, r3);
	}
	PHALCON_ARRFETCH_SILENT(r4, r3, t9);
	if(Z_TYPE_P(r4)!=IS_ARRAY){
		array_init(r4);
		PHALCON_ARRUPDATE(r3, t9, r4);
	}
	PHALCON_INIT_ARRAY(a3);
	phalcon_array_update_long(r4, 0, a3 TSRMLS_CC);
	PHALCON_SET_LONG(t11, 0);
	PHALCON_SET_LONG(t12, 0);
	PHALCON_SET_LONG(t13, 0);
	PHALCON_ARRFETCH_SILENT(r5, v2, t13);
	if(Z_TYPE_P(r5)!=IS_ARRAY){
		array_init(r5);
		PHALCON_ARRUPDATE(v2, t13, r5);
	}
	PHALCON_ARRFETCH_SILENT(r6, r5, t12);
	if(Z_TYPE_P(r6)!=IS_ARRAY){
		array_init(r6);
		PHALCON_ARRUPDATE(r5, t12, r6);
	}
	PHALCON_ARRFETCH_SILENT(r7, r6, t11);
	if(Z_TYPE_P(r7)!=IS_ARRAY){
		array_init(r7);
		PHALCON_ARRUPDATE(r6, t11, r7);
	}
	PHALCON_SET_LONG(t14, 1);
	phalcon_array_update_string(r7, "LOL", t14 TSRMLS_CC);
	PHALCON_ARRFETCH_LONG_NOISY(r8, v1, 1);
	PHALCON_ARRFETCH_STRING_NOISY(r9, r8, "LOL");
	PHALCON_ARRFETCH_LONG_NOISY(r10, v0, 1);
	PHALCON_ARRFETCH_STRING_NOISY(r11, r10, "LOL");
	PHALCON_MUL_FUNCTION(r12, r9, r11);
	PHALCON_ARRFETCH_LONG_NOISY(r13, v2, 0);
	PHALCON_ARRFETCH_LONG_NOISY(r14, r13, 0);
	PHALCON_ARRFETCH_LONG_NOISY(r15, r14, 0);
	PHALCON_ARRFETCH_STRING_NOISY(r16, r15, "LOL");
	PHALCON_MUL_FUNCTION(r17, r12, r16);
	RETURN_ZVAL(r17, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e13){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_NEW_STD(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_NEW_STD(i1);
	phalcon_update_property_zval(v0, "subA", strlen("subA"), i1 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t0, v0, "subA", sizeof("subA")-1);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t1, v0, "subA", sizeof("subA")-1);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t2, v0, "subA", sizeof("subA")-1);
	PHALCON_NEW_STD(i2);
	phalcon_update_property_zval(t2, "subSubA", strlen("subSubA"), i2 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t3, v0, "subA", sizeof("subA")-1);
	PHALCON_READ_PROPERTY_NOISY(t4, t3, "subSubA", sizeof("subSubA")-1);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t5, v0, "subA", sizeof("subA")-1);
	PHALCON_READ_PROPERTY_NOISY(t6, t5, "subSubA", sizeof("subSubA")-1);
	phalcon_update_property_long(t6, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t7, v0, "uno", sizeof("uno")-1);
	PHALCON_READ_PROPERTY_NOISY(t8, v0, "subA", sizeof("subA")-1);
	PHALCON_READ_PROPERTY_NOISY(t9, t8, "uno", sizeof("uno")-1);
	PHALCON_MUL_FUNCTION(r0, t7, t9);
	PHALCON_READ_PROPERTY_NOISY(t10, v0, "subA", sizeof("subA")-1);
	PHALCON_READ_PROPERTY_NOISY(t11, t10, "subSubA", sizeof("subSubA")-1);
	PHALCON_READ_PROPERTY_NOISY(t12, t11, "uno", sizeof("uno")-1);
	PHALCON_MUL_FUNCTION(r1, r0, t12);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, e14){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *s0 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_NEW_STD(i0);
	PHALCON_CPY_WRT(v1, i0);
	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(v1, "val", strlen("val"), s0 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t0, v1, "val", sizeof("val")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o1){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_ADD_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o2){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_SUB_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o3){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_MUL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o4){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_DIV_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o5){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_MOD_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o6){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	increment_function(v0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o7){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	decrement_function(v0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o8){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_SET_LONG(t0, 1);
	PHALCON_MUL_FUNCTION(r0, v0, t0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o9){

	zval *v0 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ADD_FUNCTION(r0, v0, v0);
	PHALCON_CPY_WRT(v0, r0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o10){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ADD_FUNCTION(r0, v0, v1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o11){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_SUB_FUNCTION(r0, v0, v1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o12){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_MUL_FUNCTION(r0, v0, v1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o13){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_DIV_FUNCTION(r0, v0, v1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o14){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_MOD_FUNCTION(r0, v0, v1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o15){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_STRING(t0, "10", 1);
	PHALCON_SET_LONG(t1, 10);
	PHALCON_ADD_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o16){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 10);
	PHALCON_SET_STRING(t1, "5", 1);
	PHALCON_SUB_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o17){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 5);
	PHALCON_SET_STRING(t1, "7", 1);
	PHALCON_MUL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o18){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_STRING(t0, "100", 1);
	PHALCON_SET_LONG(t1, 10);
	PHALCON_DIV_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, o19){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 40);
	PHALCON_SET_STRING(t1, "5", 1);
	PHALCON_MOD_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a1){

	zval *a0 = NULL;

	PHALCON_INIT_ARRAY(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	RETURN_ZVAL(a0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a2){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_INIT_ARRAY(a0);
	PHALCON_INIT_NULL(t0);
	add_next_index_zval(a0, t0);
	PHALCON_INIT_FALSE(t1);
	add_next_index_zval(a0, t1);
	add_next_index_long(a0, 0);
	add_next_index_string(a0, "whtzup", 1);
	RETURN_ZVAL(a0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a3){


	RETURN_LONG(0);
}

PHP_METHOD(Phalcon_Internal_Test, a10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_INIT_ARRAY(v0);
	add_assoc_long(v0, "hello1", 1);
	add_assoc_long(v0, "hello2", 2);
	add_assoc_long(v0, "hello3", 3);
	FOREACH_KV(v0, ac0, fes14, fee14, ah0, hp0, v2, v1)
		PHALCON_ARRFETCH_NOISY(r0, v0, v2);
		PHALCON_SET_LONG(t0, 100);
		PHALCON_ADD_FUNCTION(r1, r0, t0);
		PHALCON_ARRUPDATE(v0, v2, r1);
	END_FOREACH(ac0, fes14, fee14, ah0, hp0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_INIT_ARRAY(v0);
	add_next_index_long(v0, 1);
	add_next_index_long(v0, 2);
	add_next_index_long(v0, 3);
	add_next_index_long(v0, 4);
	add_next_index_long(v0, 5);
	FOREACH_KV(v0, ac0, fes15, fee15, ah0, hp0, v2, v1)
		PHALCON_ARRFETCH_NOISY(r0, v0, v2);
		PHALCON_SET_LONG(t0, 10);
		PHALCON_ADD_FUNCTION(r1, v2, t0);
		PHALCON_ARRUPDATE(v0, r1, r0);
	END_FOREACH(ac0, fes15, fee15, ah0, hp0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a12){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_SET_LONG(v0, 0);
	PHALCON_INIT_ARRAY(v1);
	add_next_index_long(v1, 1);
	add_next_index_long(v1, 2);
	add_next_index_long(v1, 3);
	add_next_index_long(v1, 4);
	add_next_index_long(v1, 5);
	FOREACH_V(v1, ac0, fes16, fee16, ah0, hp0, v2)
		PHALCON_ARRFETCH_NOISY(r0, v1, v0);
		PHALCON_SET_LONG(t0, 10);
		PHALCON_ADD_FUNCTION(r1, v0, t0);
		PHALCON_ARRUPDATE(v1, r1, r0);
		increment_function(v0);
	END_FOREACH(ac0, fes16, fee16, ah0, hp0);
	RETURN_ZVAL(v1, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a13){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_INIT_ARRAY(v0);
	PHALCON_INIT_ARRAY(v1);
	add_next_index_long(v1, 1);
	add_next_index_long(v1, 2);
	add_next_index_long(v1, 3);
	add_next_index_long(v1, 4);
	add_next_index_long(v1, 5);
	FOREACH_V(v1, ac0, fes17, fee17, ah0, hp0, v2)
		PHALCON_CPY_WRT(t0, v2);
		PHALCON_ARRAPPEND(v0, t0);
	END_FOREACH(ac0, fes17, fee17, ah0, hp0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a14){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_INIT_ARRAY(v0);
	PHALCON_INIT_ARRAY(v1);
	add_next_index_long(v1, 1);
	add_next_index_long(v1, 2);
	add_next_index_long(v1, 3);
	add_next_index_long(v1, 4);
	add_next_index_long(v1, 5);
	FOREACH_KV(v1, ac0, fes18, fee18, ah0, hp0, v3, v2)
		PHALCON_SET_LONG(t0, 2);
		PHALCON_MUL_FUNCTION(r0, v3, t0);
		PHALCON_CPY_WRT(v3, r0);
		PHALCON_ADD_FUNCTION(r1, v2, v3);
		PHALCON_ARRUPDATE(v0, v3, r1);
	END_FOREACH(ac0, fes18, fee18, ah0, hp0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, a15){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_INIT_ARRAY(v0);
	PHALCON_INIT_ARRAY(v1);
	add_next_index_long(v1, 1);
	add_next_index_long(v1, 2);
	add_next_index_long(v1, 3);
	add_next_index_long(v1, 4);
	add_next_index_long(v1, 5);
	FOREACH_KV(v1, ac0, fes19, fee19, ah0, hp0, v3, v2)
		PHALCON_ARRFETCH_NOISY(r0, v1, v3);
		PHALCON_ARRUPDATE(v0, v3, r0);
		PHALCON_SET_LONG(t0, 100);
		PHALCON_MUL_FUNCTION(r1, v3, t0);
		PHALCON_ARRUPDATE(v1, v3, r1);
		PHALCON_ARRFETCH_NOISY(r2, v0, v3);
		PHALCON_SET_LONG(t1, 50);
		PHALCON_MUL_FUNCTION(r3, r2, t1);
		PHALCON_ARRUPDATE(v0, v3, r3);
	END_FOREACH(ac0, fes19, fee19, ah0, hp0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c1){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c2){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c3){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_SMALLER_EQUAL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c4){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_SMALLER_EQUAL_FUNCTION(r0, t1, t0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c5){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_SMALLER_FUNCTION(r0, t1, t0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c6){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_SMALLER_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c7){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
	PHALCON_SET_LONG(t2, 1);
	PHALCON_SET_LONG(t3, 1);
	PHALCON_SMALLER_EQUAL_FUNCTION(r1, t2, t3);
	PHALCON_AND_FUNCTION(r2, r0, r1);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c8){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	PHALCON_SET_LONG(t2, 1);
	PHALCON_SET_LONG(t3, 1);
	PHALCON_SMALLER_FUNCTION(r1, t2, t3);
	PHALCON_AND_FUNCTION(r2, r0, r1);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c9){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_SET_LONG(t0, 0);
	PHALCON_BOOLEAN_NOT_FUNCTION(r0, t0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c10){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_SET_LONG(t0, 1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r1, t0, t1);
	PHALCON_BOOLEAN_NOT_FUNCTION(r0, r1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, c11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_EQUAL_FUNCTION(r0, v1, v2);
	PHALCON_EQUAL_FUNCTION(r1, v0, r0);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f1){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_PARAM_STRING(p0[0], "LOL", 0);
	PHALCON_CALL_FUNC_PARAMS(r0, "strlen", 1, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f2){

	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_PARAM_STRING(p0[0], "hello\t", 0);
	PHALCON_PARAM_STRING(p0[1], "\t", 0);
	PHALCON_CALL_FUNC_PARAMS(r0, "rtrim", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f3){

	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_PARAM_STRING(p0[0], "bb", 0);
	PHALCON_PARAM_STRING(p0[1], "xx", 0);
	PHALCON_PARAM_STRING(p0[2], "aabbcc", 0);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f4){

	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p0[] = { NULL, NULL };

	PHALCON_PARAM_STRING(p0[0], "deux", 0);
	PHALCON_PARAM_STRING(p1[0], "deux", 0);
	PHALCON_CALL_FUNC_PARAMS(r1, "strlen", 1, p1);
	PHALCON_PARAM_ZVAL(p0[1], r1);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_repeat", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f5){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_INIT_ARRAY(v0);
	add_next_index_string(v0, "b", 1);
	add_next_index_string(v0, "c", 1);
	add_next_index_string(v0, "a", 1);
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("asort", 1, p0);
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	PHALCON_PARAM_LONG(p0[0], 0);
	PHALCON_PARAM_LONG(p0[1], 100);
	PHALCON_CALL_FUNC_PARAMS(r0, "mt_rand", 2, p0);
	phalcon_concat_right(&r1, r0, ".txt" TSRMLS_CC);
	PHALCON_CPY_WRT(v0, r1);
	PHALCON_PARAM_CPY(p1[0], v0);
	PHALCON_PARAM_STRING(p1[1], "w", 0);
	PHALCON_CALL_FUNC_PARAMS(v1, "fopen", 2, p1);
	PHALCON_PARAM_CPY(p2[0], v1);
	PHALCON_PARAM_STRING(p2[1], "morelol\n", 0);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("fwrite", 2, p2);
	PHALCON_PARAM_CPY(p3[0], v1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("fclose", 1, p3);
	PHALCON_PARAM_CPY(p4[0], v0);
	PHALCON_CALL_FUNC_PARAMS(v2, "file_get_contents", 1, p4);
	PHALCON_PARAM_CPY(p5[0], v0);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("unlink", 1, p5);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f7){

	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	//ResolvedParam=double
	PHALCON_INIT_DOUBLE(t0, 3.14159);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "sqrt", 1, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f8){

	zval *r0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_INIT_ARRAY(a0);
	add_next_index_string(a0, ".", 1);
	add_next_index_string(a0, ",", 1);
	add_next_index_string(a0, "-", 1);
	PHALCON_PARAM_ZVAL(p0[0], a0);
	PHALCON_PARAM_STRING(p0[1], "&", 0);
	PHALCON_PARAM_STRING(p0[2], "-.,-.,", 0);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, f9){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL };

	PHALCON_SET_STRING(t0, "-1000", 1);
	PHALCON_SET_LONG(t1, 400);
	PHALCON_MUL_FUNCTION(r0, t0, t1);
	PHALCON_INIT_FALSE(t2);
	PHALCON_MUL_FUNCTION(r1, r0, t2);
	PHALCON_CPY_WRT(v0, r1);
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_FUNC_PARAMS(r2, "abs", 1, p0);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, m1){


	RETURN_STRING("private", 1);
}

PHP_METHOD(Phalcon_Internal_Test, m2){


	RETURN_STRING("protected", 1);
}

PHP_METHOD(Phalcon_Internal_Test, m3){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, m4){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Internal_Test, m5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(r1, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	PHALCON_CONCAT_FUNCTION(r2, r0, r1);
	RETURN_ZVAL(r2, 0, 0);
}

PHP_METHOD(Phalcon_Tag_Exception, __construct){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Tag_Exception", "__construct", 1, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Router_Rewrite, __construct){

	zval *a0 = NULL;

	PHALCON_INIT_ARRAY(a0);
	zend_update_property(phalcon_router_rewrite_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
}

PHP_METHOD(Phalcon_Router_Rewrite, handle){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *s0 = NULL, *s1 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };

	PHALCON_GET_GLOBAL(a0, "_GET", gv0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, a0, "_url");
	if(zend_is_true(r0)){
		PHALCON_PARAM_ZVAL(p0[0], r0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "handlestring", 1, p0, PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_defaultController", sizeof("_defaultController")-1);
		PHALCON_CPY_WRT(s0, t0);
		phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), s0 TSRMLS_CC);
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_defaultAction", sizeof("_defaultAction")-1);
		PHALCON_CPY_WRT(s1, t1);
		phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), s1 TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Router_Rewrite, handleString){

	zval *v0 = NULL, *v1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_STRING(p0[0], "/", 0);
	PHALCON_PARAM_CPY(p0[1], v0);
	PHALCON_CALL_FUNC_PARAMS(v1, "explode", 2, p0);
	PHALCON_PARAM_CPY(p1[0], v1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "handlearray", 1, p1, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Router_Rewrite, handleArray){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *s0 = NULL, *s1 = NULL, *s2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ARRFETCH_LONG_SILENT(r0, v0, 0);
	if(zend_is_true(r0)){
		PHALCON_PARAM_ZVAL(p0[0], r0);
		PHALCON_CALL_FUNC_PARAMS(r1, "phalcon_filter_alphanum", 1, p0);
		phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), r1 TSRMLS_CC);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_defaultController", sizeof("_defaultController")-1);
		PHALCON_CPY_WRT(s0, t0);
		phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), s0 TSRMLS_CC);
	}
	PHALCON_ARRFETCH_LONG_SILENT(r2, v0, 1);
	if(zend_is_true(r2)){
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_FUNC_PARAMS(r3, "phalcon_filter_alphanum", 1, p1);
		phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), r3 TSRMLS_CC);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_defaultAction", sizeof("_defaultAction")-1);
		PHALCON_CPY_WRT(s1, t1);
		phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), s1 TSRMLS_CC);
	}
	PHALCON_INIT_ARRAY(v1);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_CALL_FUNC_PARAMS(v2, "count", 1, p2);
	PHALCON_SET_LONG(v3, 2);
	fs20:
	PHALCON_SMALLER_FUNCTION(r4, v3, v2);
	if(!zend_is_true(r4)){
		goto fe20;
	}
	PHALCON_ARRFETCH_NOISY(r5, v0, v3);
	PHALCON_ARRAPPEND(v1, r5);
	fi20:
	increment_function(v3);
	goto fs20;
	fe20:
	r4 = NULL;
	PHALCON_CPY_WRT(s2, v1);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), s2 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_isRouted", strlen("_isRouted"), 1 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Router_Rewrite, handleAssocArray){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *s0 = NULL, *s1 = NULL, *s2 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "controller");
	if(zend_is_true(r0)){
		PHALCON_PARAM_ZVAL(p0[0], r0);
		PHALCON_CALL_FUNC_PARAMS(r1, "phalcon_filter_alphanum", 1, p0);
		phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), r1 TSRMLS_CC);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_defaultController", sizeof("_defaultController")-1);
		PHALCON_CPY_WRT(s0, t0);
		phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), s0 TSRMLS_CC);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r2, v0, "action");
	if(zend_is_true(r2)){
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_FUNC_PARAMS(r3, "phalcon_filter_alphanum", 1, p1);
		phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), r3 TSRMLS_CC);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_defaultAction", sizeof("_defaultAction")-1);
		PHALCON_CPY_WRT(s1, t1);
		phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), s1 TSRMLS_CC);
	}
	PHALCON_INIT_ARRAY(v1);
	FOREACH_KV(v0, ac0, fes21, fee21, ah0, hp0, v3, v2)
		if(Z_TYPE_P(v3)==IS_LONG){
			PHALCON_ARRFETCH_NOISY(r4, v0, v3);
			PHALCON_ARRAPPEND(v1, r4);
		}
	END_FOREACH(ac0, fes21, fee21, ah0, hp0);
	PHALCON_CPY_WRT(s2, v1);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), s2 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_isRouted", strlen("_isRouted"), 1 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Router_Rewrite, getControllerName){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_controller", sizeof("_controller")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Router_Rewrite, getActionName){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_action", sizeof("_action")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Router_Rewrite, getParams){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_params", sizeof("_params")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Router_Rewrite, finish){


	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_isRouted", strlen("_isRouted"), 0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Router_Rewrite, isRouted){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_isRouted", sizeof("_isRouted")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Db_Exception, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE){
		RETURN_NULL();
	}

	if(!v2){
		PHALCON_INIT_BOOL(v2, 1);
	}
	if(!v3){
		PHALCON_INIT_NULL(v3);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_PARAM_CPY(p0[2], v2);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_Exception", "__construct", 3, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	if(!v1){
		PHALCON_INIT_BOOL(v1, 0);
	}
	
	if(phalcon_compare_strict_string(v0, "")){
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1);
		PHALCON_CPY_WRT(v0, t0);
	}
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "connect", 2, p0, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, connect){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL, *t27 = NULL;
	zval *t28 = NULL, *t29 = NULL, *t30 = NULL, *t31 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *s0 = NULL, *s1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	if(!v1){
		PHALCON_INIT_BOOL(v1, 0);
	}
	
	if(phalcon_compare_strict_string(v0, "")){
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1);
		PHALCON_CPY_WRT(v0, t0);
	}
	PHALCON_READ_PROPERTY_SILENT(t1, v0, "host", sizeof("host")-1);
	if(zend_is_true(t1)){
		r0 = t1;
	} else {
		PHALCON_SET_STRING(t2, "", 1);
		r0 = t2;
	}
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_READ_PROPERTY_SILENT(t3, v0, "username", sizeof("username")-1);
	if(zend_is_true(t3)){
		r1 = t3;
	} else {
		PHALCON_SET_STRING(t4, "", 1);
		r1 = t4;
	}
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_READ_PROPERTY_SILENT(t5, v0, "password", sizeof("password")-1);
	if(zend_is_true(t5)){
		r2 = t5;
	} else {
		PHALCON_SET_STRING(t6, "", 1);
		r2 = t6;
	}
	PHALCON_CPY_WRT(v4, r2);
	PHALCON_READ_PROPERTY_SILENT(t7, v0, "port", sizeof("port")-1);
	if(zend_is_true(t7)){
		phalcon_concat_vboth(&r3, v2, ":", t7 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r3);
	} else {
		PHALCON_CPY_WRT(v5, v2);
	}
	//Wasted infer Constant null
	PHALCON_INIT_NULL(t8);
	PHALCON_CPY_WRT(v6, t8);
	PHALCON_READ_PROPERTY_SILENT(t9, v0, "compression", sizeof("compression")-1);
	if(zend_is_true(t9)){
		if(zend_is_true(t9)){
			if(Z_TYPE_P(v6)==IS_NULL){
				//Wasted infer Constant MYSQL_CLIENT_COMPRESS
				PHALCON_SET_LONG(t10, 32);
				PHALCON_CPY_WRT(v6, t10);
			} else {
				PHALCON_SET_LONG(t11, 32);
				PHALCON_BITWISE_OR_FUNCTION(r4, v6, t11);
				PHALCON_CPY_WRT(v6, r4);
			}
		}
	}
	PHALCON_READ_PROPERTY_SILENT(t12, v0, "ssl", sizeof("ssl")-1);
	if(zend_is_true(t12)){
		if(zend_is_true(t12)){
			if(Z_TYPE_P(v6)==IS_NULL){
				//Wasted infer Constant MYSQL_CLIENT_SSL
				PHALCON_SET_LONG(t13, 2048);
				PHALCON_CPY_WRT(v6, t13);
			} else {
				PHALCON_SET_LONG(t14, 2048);
				PHALCON_BITWISE_OR_FUNCTION(r5, v6, t14);
				PHALCON_CPY_WRT(v6, r5);
			}
		}
	}
	PHALCON_READ_PROPERTY_SILENT(t15, v0, "interactive", sizeof("interactive")-1);
	if(zend_is_true(t15)){
		if(zend_is_true(t15)){
			if(Z_TYPE_P(v6)==IS_NULL){
				//Wasted infer Constant MYSQL_CLIENT_INTERACTIVE
				PHALCON_SET_LONG(t16, 1024);
				PHALCON_CPY_WRT(v6, t16);
			} else {
				PHALCON_SET_LONG(t17, 1024);
				PHALCON_BITWISE_OR_FUNCTION(r6, v6, t17);
				PHALCON_CPY_WRT(v6, r6);
			}
		}
	}
	if(!zend_is_true(v1)){
		PHALCON_PARAM_CPY(p0[0], v5);
		PHALCON_PARAM_CPY(p0[1], v3);
		PHALCON_PARAM_CPY(p0[2], v4);
		PHALCON_INIT_TRUE(t18);
		PHALCON_PARAM_ZVAL(p0[3], t18);
		PHALCON_PARAM_CPY(p0[4], v6);
		PHALCON_CALL_FUNC_PARAMS(r7, "mysql_connect", 5, p0);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r7 TSRMLS_CC);
	} else {
		PHALCON_PARAM_CPY(p1[0], v5);
		PHALCON_PARAM_CPY(p1[1], v3);
		PHALCON_PARAM_CPY(p1[2], v4);
		PHALCON_PARAM_CPY(p1[3], v6);
		PHALCON_CALL_FUNC_PARAMS(r8, "mysql_pconnect", 4, p1);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r8 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t19, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(zend_is_true(t19)){
		PHALCON_READ_PROPERTY_SILENT(t20, v0, "name", sizeof("name")-1);
		if(zend_is_true(t20)){
			r9 = t20;
		} else {
			PHALCON_SET_STRING(t21, "", 1);
			r9 = t21;
		}
		PHALCON_CPY_WRT(v7, r9);
		PHALCON_SET_STRING(t22, "", 1);
		PHALCON_NOT_IDENTICAL_FUNCTION(r10, v7, t22);
		if(zend_is_true(r10)){
			PHALCON_PARAM_CPY(p2[0], v7);
			PHALCON_READ_PROPERTY_NOISY(t23, this_ptr, "_idConnection", sizeof("_idConnection")-1);
			PHALCON_PARAM_ZVAL(p2[1], t23);
			PHALCON_CALL_FUNC_PARAMS(r11, "mysql_select_db", 2, p2);
			if(!zend_is_true(r11)){
				PHALCON_NEW(i0, phalcon_db_exception_class_entry);
				PHALCON_CALL_METHOD(r12, this_ptr, "error", PHALCON_CALL_DEFAULT);
				PHALCON_PARAM_ZVAL(p3[0], r12);
				PHALCON_CALL_METHOD(r13, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
				PHALCON_PARAM_ZVAL(p3[1], r13);
				PHALCON_INIT_FALSE(t24);
				PHALCON_PARAM_ZVAL(p3[2], t24);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p3, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
		PHALCON_READ_PROPERTY_SILENT(t25, v0, "autocommit", sizeof("autocommit")-1);
		if(zend_is_true(t25)){
			r14 = t25;
		} else {
			PHALCON_INIT_FALSE(t26);
			r14 = t26;
		}
		PHALCON_CPY_WRT(v8, r14);
		PHALCON_CPY_WRT(s0, v8);
		phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), s0 TSRMLS_CC);
		//Wasted infer Constant MYSQL_BOTH
		PHALCON_SET_LONG(t27, 3);
		PHALCON_CPY_WRT(s1, t27);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s1 TSRMLS_CC);
		PHALCON_PARAM_CPY(p6[0], v0);
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_MySQL", "__construct", 1, p6);
		PHALCON_READ_PROPERTY_SILENT(t28, v0, "charset", sizeof("charset")-1);
		if(zend_is_true(t28)){
			phalcon_concat_left(&r15, "SET NAMES ", t28 TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p7[0], r15);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p7, PHALCON_CALL_DEFAULT);
		}
		PHALCON_READ_PROPERTY_SILENT(t29, v0, "collation", sizeof("collation")-1);
		if(zend_is_true(t29)){
			phalcon_concat_left(&r16, "SET collation_connection=", t29 TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p8[0], r16);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
			PHALCON_READ_PROPERTY_NOISY(t30, v0, "collation", sizeof("collation")-1);
			phalcon_concat_left(&r17, "SET collation_database=", t30 TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p9[0], r17);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
		}
		RETURN_TRUE;
	} else {
		PHALCON_NEW(i1, phalcon_db_exception_class_entry);
		PHALCON_CALL_METHOD(r18, this_ptr, "error", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p10[0], r18);
		PHALCON_CALL_METHOD(r19, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p10[1], r19);
		PHALCON_INIT_FALSE(t31);
		PHALCON_PARAM_ZVAL(p10[2], t31);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p10, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, query){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *s0 = NULL, *s1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL, NULL }, *p3[] = { NULL }, *p2[] = { NULL }, *p5[] = { NULL, NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(!zend_is_true(t0)){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "connect", PHALCON_CALL_DEFAULT);
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1);
		if(!zend_is_true(t1)){
			RETURN_FALSE;
		}
	}
	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_lastQuery", strlen("_lastQuery"), s0 TSRMLS_CC);
	PHALCON_PARAM_CPY(p1[0], v0);
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	PHALCON_PARAM_ZVAL(p1[1], t2);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_query", 2, p1);
	PHALCON_CPY_WRT(v1, r0);
	if(zend_is_true(v1)){
		PHALCON_CPY_WRT(s1, v1);
		phalcon_update_property_zval(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), s1 TSRMLS_CC);
		RETURN_ZVAL(v1, 0, 0);
	} else {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), 0 TSRMLS_CC);
		phalcon_concat_left(&r2, " when executing \"", v0 TSRMLS_CC);
		PHALCON_INIT_TRUE(t3);
		PHALCON_PARAM_ZVAL(p3[0], t3);
		PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "getconnectionid", 1, p3, PHALCON_CALL_DEFAULT);
		phalcon_concat_vboth(&r1, r2, "\" on connection \"", r3 TSRMLS_CC);
		phalcon_concat_right(&r4, r1, "\"" TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p2[0], r4);
		PHALCON_CALL_METHOD_PARAMS(v2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(v3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_PARAM_CPY(p5[0], v2);
		PHALCON_CALL_METHOD(r5, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p5[1], r5);
		PHALCON_INIT_TRUE(t4);
		PHALCON_PARAM_ZVAL(p5[2], t4);
		PHALCON_PARAM_CPY(p5[3], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p5, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, close){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *s0 = NULL;
	zval *p1[] = { NULL };
	zend_bool silence;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(zend_is_true(t0)){
		PHALCON_CALL_PARENT_NORETURN(this_ptr, "Phalcon_Db_MySQL", "close");
		silence = PG(display_errors);
		PG(display_errors) = 0;
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1);
		PHALCON_PARAM_ZVAL(p1[0], t1);
		PHALCON_CALL_FUNC_PARAMS(r0, "mysql_close", 1, p1);
		PG(display_errors) = silence;
		PHALCON_CPY_WRT(v0, r0);
		//Wasted infer Constant null
		PHALCON_INIT_NULL(t2);
		PHALCON_CPY_WRT(s0, t2);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), s0 TSRMLS_CC);
		RETURN_ZVAL(v0, 0, 0);
	} else {
		RETURN_TRUE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, fetchArray){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(!zend_is_true(t0)){
		RETURN_FALSE;
	}
	if(!zend_is_true(v0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1);
		PHALCON_CPY_WRT(v0, t1);
		if(!zend_is_true(v0)){
			RETURN_FALSE;
		}
	}
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_fetchMode", sizeof("_fetchMode")-1);
	PHALCON_PARAM_ZVAL(p0[1], t2);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_fetch_array", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, numRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	zend_bool silence;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(!zend_is_true(t0)){
		RETURN_FALSE;
	}
	if(!zend_is_true(v0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1);
		PHALCON_CPY_WRT(v0, t1);
		if(!zend_is_true(v0)){
			RETURN_FALSE;
		}
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_num_rows", 1, p0);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_INIT_FALSE(t2);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, v1, t2);
	if(zend_is_true(r1)){
		RETURN_ZVAL(v1, 0, 0);
	} else {
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		PHALCON_PARAM_CPY(p2[0], v2);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_METHOD(r3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[1], r3);
		PHALCON_INIT_TRUE(t3);
		PHALCON_PARAM_ZVAL(p1[2], t3);
		PHALCON_PARAM_CPY(p1[3], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_FALSE;
}

PHP_METHOD(Phalcon_Db_MySQL, dataSeek){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	
	if(!zend_is_true(v1)){
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1);
		PHALCON_CPY_WRT(v1, t0);
		if(!zend_is_true(v1)){
			RETURN_FALSE;
		}
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_PARAM_CPY(p0[1], v0);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_data_seek", 2, p0);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, v2, t1);
	if(zend_is_true(r1)){
		RETURN_ZVAL(v2, 0, 0);
	} else {
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_READ_SYMBOL(v3, pv0, "php_errormsg");
		PHALCON_PARAM_CPY(p2[0], v3);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_METHOD(r3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[1], r3);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_FALSE;
}

PHP_METHOD(Phalcon_Db_MySQL, affectedRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_affected_rows", 1, p0);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, v1, t1);
	if(zend_is_true(r1)){
		RETURN_ZVAL(v1, 0, 0);
	} else {
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		PHALCON_PARAM_CPY(p2[0], v2);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_METHOD(r3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[1], r3);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_FALSE;
}

PHP_METHOD(Phalcon_Db_MySQL, setFetchMode){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *s0 = NULL, *s1 = NULL, *s2 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_db_mysql_class_entry, "DB_ASSOC");
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	if(zend_is_true(r0)){
		//Wasted infer Constant MYSQL_ASSOC
		PHALCON_SET_LONG(t1, 1);
		PHALCON_CPY_WRT(s0, t1);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s0 TSRMLS_CC);
	}
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_mysql_class_entry, "DB_BOTH");
	PHALCON_EQUAL_FUNCTION(r1, v0, t2);
	if(zend_is_true(r1)){
		//Wasted infer Constant MYSQL_BOTH
		PHALCON_SET_LONG(t3, 3);
		PHALCON_CPY_WRT(s1, t3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s1 TSRMLS_CC);
	}
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_mysql_class_entry, "DB_NUM");
	PHALCON_EQUAL_FUNCTION(r2, v0, t4);
	if(zend_is_true(r2)){
		//Wasted infer Constant MYSQL_NUM
		PHALCON_SET_LONG(t5, 2);
		PHALCON_CPY_WRT(s2, t5);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s2 TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, error){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(!zend_is_true(t0)){
		PHALCON_CALL_FUNC(v2, "mysql_error");
	} else {
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1);
		PHALCON_PARAM_ZVAL(p1[0], t1);
		PHALCON_CALL_FUNC_PARAMS(v2, "mysql_error", 1, p1);
	}
	if(zend_is_true(v2)){
		phalcon_concat_left(&r1, "\"", v2 TSRMLS_CC);
		phalcon_concat_vboth(&r0, r1, "\" ", v0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r0 TSRMLS_CC);
	} else {
		phalcon_concat_both(&r2,  "[Unknown MySQL error: ", v0, "]" TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r2 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_lastError", sizeof("_lastError")-1);
	RETURN_ZVAL(t2, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, noError){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_NULL(v0);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(!zend_is_true(t0)){
		RETURN_FALSE;
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	PHALCON_PARAM_ZVAL(p0[0], t1);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_errno", 1, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, lastInsertId){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	if(!v2){
		PHALCON_SET_STRING(v2, "", 1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	if(!zend_is_true(t0)){
		RETURN_FALSE;
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1);
	PHALCON_PARAM_ZVAL(p0[0], t1);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_insert_id", 1, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, limit){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_numeric", 1, p0);
	if(zend_is_true(r0)){
		convert_to_long(v1);
		phalcon_concat_vboth(&r1, v0, " LIMIT ", v1 TSRMLS_CC);
		RETURN_ZVAL(r1, 0, 0);
	} else {
		RETURN_ZVAL(v0, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_MySQL, tableExists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *s0 = NULL, *s1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_FUNC_PARAMS(v0, "addslashes", 1, p0);
	PHALCON_PARAM_CPY(p1[0], v0);
	PHALCON_PARAM_CPY(p1[1], v1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "tableexists", 2, p1);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1);
	PHALCON_CPY_WRT(v3, t0);
	//Wasted infer Constant MYSQL_NUM
	PHALCON_SET_LONG(t1, 2);
	PHALCON_CPY_WRT(s0, t1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s0 TSRMLS_CC);
	PHALCON_PARAM_CPY(p2[0], v2);
	PHALCON_CALL_METHOD_PARAMS(v4, this_ptr, "fetchone", 1, p2, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(s1, v3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s1 TSRMLS_CC);
	PHALCON_ARRFETCH_LONG_NOISY(r1, v4, 0);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, viewExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "tableexists", 2, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, describeTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *s0 = NULL, *s1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describetable", 2, p0);
	PHALCON_CPY_WRT(v2, r0);
	//Wasted infer Constant MYSQL_ASSOC
	PHALCON_SET_LONG(t0, 1);
	PHALCON_CPY_WRT(s0, t0);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s0 TSRMLS_CC);
	PHALCON_PARAM_CPY(p1[0], v2);
	PHALCON_CALL_METHOD_PARAMS(v3, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	//Wasted infer Constant MYSQL_BOTH
	PHALCON_SET_LONG(t1, 3);
	PHALCON_CPY_WRT(s1, t1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), s1 TSRMLS_CC);
	RETURN_ZVAL(v3, 0, 0);
}

PHP_METHOD(Phalcon_Db_MySQL, getDateUsingFormat){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "YYYY-MM-DD", 1);
	}
	
	phalcon_concat_both(&r0,  "'", v0, "'" TSRMLS_CC);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db_Pool, hasDefaultDescriptor){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_NULL(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Db_Pool, setDefaultDescriptor){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *ac0 = NULL;
	zval *s0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)!=IS_ARRAY){
		if(Z_TYPE_P(v0)!=IS_OBJECT){
			PHALCON_NEW(i0, phalcon_db_exception_class_entry);
			PHALCON_PARAM_STRING(p0[0], "The parameter 'options' must be an Array or Object", 0);
			PHALCON_PARAM_LONG(p0[1], 0);
			PHALCON_INIT_TRUE(t0);
			PHALCON_PARAM_ZVAL(p0[2], t0);
			PHALCON_INIT_NULL(t1);
			PHALCON_PARAM_ZVAL(p0[3], t1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	}
	if(Z_TYPE_P(v0)==IS_ARRAY){
		PHALCON_NEW_STD(i1);
		PHALCON_CPY_WRT(v1, i1);
		FOREACH_KV(v0, ac0, fes22, fee22, ah0, hp0, v3, v2)
			PHALCON_CPY_WRT(s0, v2);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), s0 TSRMLS_CC);
		END_FOREACH(ac0, fes22, fee22, ah0, hp0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	zend_update_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, v1 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_Pool, getConnection){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_BOOL(v0, 0);
	}
	if(!v1){
		PHALCON_INIT_BOOL(v1, 0);
	}
	
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	if(!zend_is_true(v2)){
		PHALCON_NEW(i0, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p0[0], "Default database connection parameters was not defined", 0);
		PHALCON_PARAM_LONG(p0[1], 0);
		PHALCON_INIT_TRUE(t1);
		PHALCON_PARAM_ZVAL(p0[2], t1);
		PHALCON_INIT_NULL(t2);
		PHALCON_PARAM_ZVAL(p0[3], t2);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	PHALCON_READ_PROPERTY_SILENT(t3, v2, "adapter", sizeof("adapter")-1);
	if(!zend_is_true(t3)){
		PHALCON_NEW(i1, phalcon_db_exception_class_entry);
		PHALCON_PARAM_STRING(p1[0], "A valid adapter name is required", 0);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_INIT_TRUE(t4);
		PHALCON_PARAM_ZVAL(p1[2], t4);
		PHALCON_INIT_NULL(t5);
		PHALCON_PARAM_ZVAL(p1[3], t5);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	if(zend_is_true(v0)){
		if(zend_is_true(v1)){
			PHALCON_READ_PROPERTY_NOISY(t6, v2, "adapter", sizeof("adapter")-1);
			PHALCON_PARAM_ZVAL(p2[0], t6);
			PHALCON_PARAM_CPY(p2[1], v2);
			PHALCON_INIT_TRUE(t7);
			PHALCON_PARAM_ZVAL(p2[2], t7);
			PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db", "factory", 3, p2);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r0 TSRMLS_CC);
			t8 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_CPY_WRT(v3, t8);
		} else {
			PHALCON_READ_PROPERTY_NOISY(t9, v2, "adapter", sizeof("adapter")-1);
			PHALCON_PARAM_ZVAL(p3[0], t9);
			PHALCON_PARAM_CPY(p3[1], v2);
			PHALCON_INIT_FALSE(t10);
			PHALCON_PARAM_ZVAL(p3[2], t10);
			PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_db", "factory", 3, p3);
			PHALCON_CPY_WRT(v3, r1);
		}
	} else {
		t11 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p4[0], t11);
		PHALCON_CALL_FUNC_PARAMS(r2, "is_null", 1, p4);
		if(zend_is_true(r2)){
			PHALCON_READ_PROPERTY_NOISY(t12, v2, "adapter", sizeof("adapter")-1);
			PHALCON_PARAM_ZVAL(p5[0], t12);
			PHALCON_PARAM_CPY(p5[1], v2);
			PHALCON_INIT_TRUE(t13);
			PHALCON_PARAM_ZVAL(p5[2], t13);
			PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_db", "factory", 3, p5);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r3 TSRMLS_CC);
		}
		t14 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v3, t14);
	}
	RETURN_ZVAL(v3, 0, 0);
}

PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	if(phalcon_compare_strict_string(v1, "")){
		phalcon_concat_both(&r0,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", v0, "'" TSRMLS_CC);
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_PARAM_CPY(p0[0], v1);
		PHALCON_CALL_FUNC_PARAMS(v1, "addslashes", 1, p0);
		phalcon_concat_left(&r2, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", v0 TSRMLS_CC);
		phalcon_concat_vboth(&r1, r2, "' AND `TABLE_SCHEMA`='", v1 TSRMLS_CC);
		phalcon_concat_right(&r3, r1, "'" TSRMLS_CC);
		RETURN_ZVAL(r3, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	if(phalcon_compare_strict_string(v1, "")){
		phalcon_concat_both(&r0,  "DESCRIBE `", v0, "`" TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		phalcon_concat_left(&r2, "DESCRIBE `", v1 TSRMLS_CC);
		phalcon_concat_vboth(&r1, r2, "`.`", v0 TSRMLS_CC);
		phalcon_concat_right(&r3, r1, "`" TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r3);
	}
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Db_RawValue, __construct){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_value", strlen("_value"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db_RawValue, getValue){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_value", sizeof("_value")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Db_RawValue, __toString){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_value", sizeof("_value")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Flash, _showMessage){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v1)==IS_ARRAY){
		PHALCON_PARAM_STRING(p0[0], " ", 0);
		PHALCON_PARAM_CPY(p0[1], v1);
		PHALCON_CALL_FUNC_PARAMS(v2, "join", 2, p0);
	} else {
		PHALCON_CPY_WRT(v2, v1);
	}
	if(Z_TYPE_P(v0)==IS_ARRAY){
		FOREACH_V(v0, ac0, fes23, fee23, ah0, hp0, v3)
			phalcon_concat_left(&r2, "<div class=\"", v2 TSRMLS_CC);
			phalcon_concat_vboth(&r1, r2, "\">", v3 TSRMLS_CC);
			PHALCON_GET_CONSTANT(t0, "PHP_EOL");
			phalcon_concat_vboth(&r0, r1, "</div>", t0 TSRMLS_CC);
			zend_print_zval(r0, 0);
		END_FOREACH(ac0, fes23, fee23, ah0, hp0);
	} else {
		phalcon_concat_left(&r5, "<div class=\"", v2 TSRMLS_CC);
		phalcon_concat_vboth(&r4, r5, "\">", v0 TSRMLS_CC);
		PHALCON_GET_CONSTANT(t1, "PHP_EOL");
		phalcon_concat_vboth(&r3, r4, "</div>", t1 TSRMLS_CC);
		zend_print_zval(r3, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Flash, error){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "errorMessage", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_STATIC_PARAMS(r0, "self", "_showmessage", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Flash, notice){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "errorMessage", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_STATIC_PARAMS(r0, "self", "_showmessage", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Flash, success){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "successMessage", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_STATIC_PARAMS(r0, "self", "_showmessage", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Flash, warning){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "warningMessage", 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_STATIC_PARAMS(r0, "self", "_showmessage", 2, p0);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Logger, __construct){

	zval *v0 = NULL, *v1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "File", 1);
	}
	
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Logger, setFormat){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Config, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *i0 = NULL;
	zval *s0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	FOREACH_KV(v0, ac0, fes24, fee24, ah0, hp0, v2, v1)
		if(Z_TYPE_P(v1)==IS_ARRAY){
			PHALCON_NEW(i0, phalcon_config_class_entry);
			PHALCON_PARAM_CPY(p0[0], v1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), i0 TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(s0, v1);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), s0 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes24, fee24, ah0, hp0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Filter, sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v1)==IS_ARRAY){
		if(zend_is_true(v0)){
			FOREACH_V(v1, ac0, fes25, fee25, ah0, hp0, v2)
				PHALCON_PARAM_CPY(p0[0], v0);
				PHALCON_PARAM_CPY(p0[1], v2);
				PHALCON_CALL_METHOD_PARAMS(v0, this_ptr, "_sanitize", 2, p0, PHALCON_CALL_DEFAULT);
			END_FOREACH(ac0, fes25, fee25, ah0, hp0);
		}
		RETURN_ZVAL(v0, 0, 0);
	} else {
		PHALCON_PARAM_CPY(p1[0], v0);
		PHALCON_PARAM_CPY(p1[1], v1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_sanitize", 2, p1, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_SET_STRING(t0, "email", 1);
	PHALCON_EQUAL_FUNCTION(r0, v1, t0);
	if(zend_is_true(r0)){
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_SET_LONG(t1, 517);
		PHALCON_PARAM_ZVAL(p0[1], t1);
		PHALCON_CALL_FUNC_PARAMS(r1, "filter_var", 2, p0);
		RETURN_ZVAL(r1, 0, 0);
	}
	PHALCON_SET_STRING(t2, "int", 1);
	PHALCON_EQUAL_FUNCTION(r2, v1, t2);
	if(zend_is_true(r2)){
		PHALCON_PARAM_CPY(p1[0], v0);
		PHALCON_SET_LONG(t3, 519);
		PHALCON_PARAM_ZVAL(p1[1], t3);
		PHALCON_CALL_FUNC_PARAMS(r3, "filter_var", 2, p1);
		RETURN_ZVAL(r3, 0, 0);
	}
	PHALCON_SET_STRING(t4, "string", 1);
	PHALCON_EQUAL_FUNCTION(r4, v1, t4);
	if(zend_is_true(r4)){
		PHALCON_PARAM_CPY(p2[0], v0);
		PHALCON_SET_LONG(t5, 513);
		PHALCON_PARAM_ZVAL(p2[1], t5);
		PHALCON_CALL_FUNC_PARAMS(r5, "filter_var", 2, p2);
		RETURN_ZVAL(r5, 0, 0);
	}
	PHALCON_NEW(i0, phalcon_exception_class_entry);
	phalcon_concat_both(&r6,  "Filter ", v1, " is not supported" TSRMLS_CC);
	PHALCON_PARAM_ZVAL(p3[0], r6);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	se26:
	php_printf("");
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Exception, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &v0, &v1, &v2, &v3) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_LONG(v1, 0);
	}
	if(!v2){
		PHALCON_INIT_BOOL(v2, 1);
	}
	
	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_numeric", 1, p0);
	if(zend_is_true(r0)){
		PHALCON_PARAM_CPY(p1[0], v0);
		PHALCON_PARAM_CPY(p1[1], v1);
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Exception", "__construct", 2, p1);
	} else {
		PHALCON_PARAM_CPY(p2[0], v0);
		PHALCON_PARAM_LONG(p2[1], 0);
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Exception", "__construct", 2, p2);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_bool silence;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_ARRAY(v1);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_INIT_TRUE(t0);
	PHALCON_PARAM_ZVAL(p0[1], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "parse_ini_file", 2, p0);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if(Z_TYPE_P(v2)==IS_BOOL&&!Z_BVAL_P(v2)){
		PHALCON_NEW(i0, phalcon_config_exception_class_entry);
		PHALCON_PARAM_CPY(p2[0], v0);
		PHALCON_CALL_FUNC_PARAMS(r1, "basename", 1, p2);
		phalcon_concat_both(&r2,  "Configuration file ", r1, " can't be loaded" TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p1[0], r2);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	FOREACH_KV(v2, ac0, fes27, fee27, ah0, hp0, v4, v3)
		FOREACH_KV(v3, ac1, fes28, fee28, ah1, hp1, v6, v5)
			PHALCON_PARAM_CPY(p3[0], v6);
			PHALCON_PARAM_STRING(p3[1], ".", 0);
			PHALCON_CALL_FUNC_PARAMS(r3, "strpos", 2, p3);
			PHALCON_INIT_FALSE(t1);
			PHALCON_NOT_IDENTICAL_FUNCTION(r4, r3, t1);
			if(zend_is_true(r4)){
				PHALCON_PARAM_STRING(p4[0], ".", 0);
				PHALCON_PARAM_CPY(p4[1], v6);
				PHALCON_CALL_FUNC_PARAMS(v7, "explode", 2, p4);
				PHALCON_ARRFETCH_LONG_NOISY(r5, v7, 0);
				PHALCON_ARRFETCH_SILENT(r6, v1, v4);
				if(Z_TYPE_P(r6)!=IS_ARRAY){
					array_init(r6);
					PHALCON_ARRUPDATE(v1, v4, r6);
				}
				PHALCON_ARRFETCH_SILENT(r7, r6, r5);
				if(Z_TYPE_P(r7)!=IS_ARRAY){
					array_init(r7);
					PHALCON_ARRUPDATE(r6, r5, r7);
				}
				PHALCON_CPY_WRT(t2, v5);
				PHALCON_ARRFETCH_LONG_NOISY(r8, v7, 1);
				PHALCON_ARRUPDATE(r7, r8, t2);
			} else {
				PHALCON_ARRFETCH_SILENT(r9, v1, v4);
				if(Z_TYPE_P(r9)!=IS_ARRAY){
					array_init(r9);
					PHALCON_ARRUPDATE(v1, v4, r9);
				}
				PHALCON_CPY_WRT(t3, v5);
				PHALCON_ARRUPDATE(r9, v6, t3);
			}
		END_FOREACH(ac1, fes28, fee28, ah1, hp1);
	END_FOREACH(ac0, fes27, fee27, ah0, hp0);
	PHALCON_PARAM_CPY(p5[0], v1);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", 1, p5);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Config_Exception, __construct){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Exception", "__construct", 1, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller, __construct){

	zval *v0 = NULL;
	zval *s0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), s0 TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getrouter", PHALCON_CALL_DEFAULT);
	phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), r0 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getfrontcontroller", PHALCON_CALL_DEFAULT);
	phalcon_update_property_zval(this_ptr, "_front", strlen("_front"), r1 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_front", sizeof("_front")-1);
	PHALCON_CALL_METHOD(r2, t0, "getmodelcomponent", PHALCON_CALL_DEFAULT);
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), r2 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller, _forward){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)==IS_ARRAY){
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_router", sizeof("_router")-1);
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "handleassocarray", 1, p0, PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_router", sizeof("_router")-1);
		PHALCON_PARAM_CPY(p1[0], v0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "handlestring", 1, p1, PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller, _forwardToAction){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CPY_WRT(v1, t0);
	PHALCON_INIT_ARRAY(a0);
	PHALCON_CALL_METHOD(r0, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
	add_assoc_zval(a0, "controller", r0);
	PHALCON_CPY_WRT(t1, v0);
	add_assoc_zval(a0, "action", t1);
	PHALCON_PARAM_ZVAL(p0[0], a0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "handleassocarray", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller, _getViewComponent){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_view", sizeof("_view")-1);
	if(!zend_is_true(t0)){
		PHALCON_NEW(i0, phalcon_view_class_entry);
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_front", sizeof("_front")-1);
		PHALCON_PARAM_ZVAL(p0[0], t1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), i0 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_view", sizeof("_view")-1);
	RETURN_ZVAL(t2, 0, 0);
}

PHP_METHOD(Phalcon_Controller, getRequest){

	zval *r0 = NULL;

	PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Controller, setParamToView){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_CPY(p0[1], v1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(r0, "setparamtoview", 2, p0, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Controller, getViewComponent){

	zval *r0 = NULL;

	PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Controller, getControllerName){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CALL_METHOD(r0, t0, "getcontrollername", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Controller, getActionName){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_router", sizeof("_router")-1);
	PHALCON_CALL_METHOD(r0, t0, "getactionname", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Controller, __get){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL }, *p4[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(phalcon_compare_strict_string(v0, "request")){
		PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
		phalcon_update_property_zval(this_ptr, "request", strlen("request"), r0 TSRMLS_CC);
		PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "request", sizeof("request")-1);
		RETURN_ZVAL(t0, 0, 0);
	}
	if(phalcon_compare_strict_string(v0, "view")){
		PHALCON_CALL_METHOD(r1, this_ptr, "_getviewcomponent", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "view", strlen("view"), r1 TSRMLS_CC);
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "view", sizeof("view")-1);
		RETURN_ZVAL(t1, 0, 0);
	}
	if(phalcon_compare_strict_string(v0, "filter")){
		PHALCON_NEW(i0, phalcon_filter_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "filter", strlen("filter"), i0 TSRMLS_CC);
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "filter", sizeof("filter")-1);
		RETURN_ZVAL(t2, 0, 0);
	}
	if(!phalcon_compare_strict_string(v0, "_view")){
		PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_model", sizeof("_model")-1);
		PHALCON_PARAM_CPY(p3[0], v0);
		PHALCON_CALL_METHOD_PARAMS(r2, t3, "ismodel", 1, p3, PHALCON_CALL_DEFAULT);
		if(zend_is_true(r2)){
			PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, "_model", sizeof("_model")-1);
			PHALCON_PARAM_CPY(p4[0], v0);
			PHALCON_CALL_METHOD_PARAMS(r3, t4, "getmodel", 1, p4, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r3, 0, 0);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Message, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *s0 = NULL, *s1 = NULL, *s2 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	if(!v2){
		PHALCON_INIT_NULL(v2);
	}
	
	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), s0 TSRMLS_CC);
	PHALCON_CPY_WRT(s1, v1);
	phalcon_update_property_zval(this_ptr, "_field", strlen("_field"), s1 TSRMLS_CC);
	PHALCON_CPY_WRT(s2, v2);
	phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), s2 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Message, setType){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Message, getType){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_type", sizeof("_type")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Message, setMessage){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Message, getMessage){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_message", sizeof("_message")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Message, setField){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_field", strlen("_field"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Message, getField){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_field", sizeof("_field")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Message, __toString){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_message", sizeof("_message")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *v0 = NULL;
	zval *s0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_front", strlen("_front"), s0 TSRMLS_CC);
	PHALCON_INIT_ARRAY(a0);
	add_next_index_zval(a0, this_ptr);
	add_next_index_string(a0, "autoload", 1);
	PHALCON_PARAM_ZVAL(p0[0], a0);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("spl_autoload_register", 1, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Manager, isModel){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t1, t0, v0);
	if(zend_is_true(t1)){
		RETURN_TRUE;
	} else {
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_INIT_FALSE(t2);
		PHALCON_PARAM_ZVAL(p0[1], t2);
		PHALCON_CALL_FUNC_PARAMS(r0, "class_exists", 2, p0);
		if(!zend_is_true(r0)){
			PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_front", sizeof("_front")-1);
			PHALCON_CALL_METHOD(r2, t3, "getbasepath", PHALCON_CALL_DEFAULT);
			phalcon_concat_vboth(&r1, r2, "app/models/", v0 TSRMLS_CC);
			phalcon_concat_right(&r3, r1, ".php" TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r3);
			if(phalcon_file_exists(v1 TSRMLS_CC)==SUCCESS){
				PHALCON_PARAM_CPY(p2[0], v0);
				PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "initializemodel", 1, p2, PHALCON_CALL_DEFAULT);
				RETURN_ZVAL(r4, 0, 0);
			} else {
				RETURN_FALSE;
			}
		} else {
			RETURN_TRUE;
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Manager, initializeModel){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p1[] = { NULL, NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t1, t0, v0);
	if(zend_is_true(t1)){
		RETURN_TRUE;
	} else {
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_front", sizeof("_front")-1);
		PHALCON_CALL_METHOD(r1, t2, "getbasepath", PHALCON_CALL_DEFAULT);
		phalcon_concat_vboth(&r0, r1, "app/models/", v0 TSRMLS_CC);
		phalcon_concat_right(&r2, r0, ".php" TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r2);
		if(phalcon_file_exists(v1 TSRMLS_CC)==SUCCESS){
			phalcon_require(v1 TSRMLS_CC);
			if(EG(exception)||EG(exit_status)==255){
				return;
			}
			PHALCON_PARAM_CPY(p1[0], v0);
			PHALCON_INIT_FALSE(t3);
			PHALCON_PARAM_ZVAL(p1[1], t3);
			PHALCON_CALL_FUNC_PARAMS(r3, "class_exists", 2, p1);
			if(!zend_is_true(r3)){
				PHALCON_NEW(i0, phalcon_model_exception_class_entry);
				phalcon_concat_both(&r4,  "Class \"", v0, "\" was not found on model file" TSRMLS_CC);
				PHALCON_PARAM_ZVAL(p2[0], r4);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
			ce0 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_NEW(i1, ce0);
			PHALCON_PARAM_CPY(p3[0], this_ptr);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
			t4 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if(Z_TYPE_P(t4)!=IS_ARRAY){
				array_init(t4);
			}
			PHALCON_ARRUPDATE(t4, v0, i1);
			zend_update_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, t4 TSRMLS_CC);
			
			RETURN_TRUE;
		} else {
			PHALCON_NEW(i2, phalcon_model_exception_class_entry);
			phalcon_concat_both(&r5,  "Class file path for model \"", v0, "\" was not found" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p4[0], r5);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p4, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i2 TSRMLS_CC);
			Z_ADDREF_P(i2);
			return;
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Manager, getModel){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t1, t0, v0);
	if(!zend_is_true(t1)){
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "initializemodel", 1, p0, PHALCON_CALL_DEFAULT);
	}
	t2 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t2, v0);
	RETURN_ZVAL(t3, 0, 0);
}

PHP_METHOD(Phalcon_Model_Manager, getSource){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t1, t0, v0);
	if(!zend_is_true(t1)){
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "uncamelize", 1, p0);
		t2 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if(Z_TYPE_P(t2)!=IS_ARRAY){
			array_init(t2);
		}
		PHALCON_ARRUPDATE(t2, v0, r0);
		zend_update_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, t2 TSRMLS_CC);
		
	}
	t3 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t4, t3, v0);
	RETURN_ZVAL(t4, 0, 0);
}

PHP_METHOD(Phalcon_Model_Manager, getConnection){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_CALL_STATIC(r0, "phalcon_transactions", "isautomatic");
	if(!zend_is_true(r0)){
		PHALCON_CALL_STATIC(r1, "phalcon_db_pool", "getconnection");
		RETURN_ZVAL(r1, 0, 0);
	} else {
		PHALCON_CALL_STATIC(r3, "phalcon_transactions", "get");
		PHALCON_CALL_METHOD(r2, r3, "getconnection", PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r2, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Manager, setMetaData){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_metadata", sizeof("_metadata")-1);
	if(!zend_is_true(t0)){
		PHALCON_NEW(i0, phalcon_model_metadata_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), i0 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_metadata", sizeof("_metadata")-1);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_Manager, autoload){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "ismodel", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "Memory", 1);
	}
	
	phalcon_concat_left(&r0, "Phalcon_Model_MetaData_", v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p0);
	if(zend_is_true(r1)){
		ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_NEW(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), i0 TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *ac0 = NULL;
	zval *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL }, *p5[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t2, t0, v2);
	PHALCON_ARRFETCH_SILENT(t1, t2, v1);
	if(!zend_is_true(t1)){
		PHALCON_CALL_METHOD(v3, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(v4, v0, "isview", PHALCON_CALL_DEFAULT);
		if(!zend_is_true(v4)){
			PHALCON_PARAM_CPY(p2[0], v1);
			PHALCON_PARAM_CPY(p2[1], v2);
			PHALCON_CALL_METHOD_PARAMS(v5, v3, "tableexists", 2, p2, PHALCON_CALL_DEFAULT);
		} else {
			PHALCON_PARAM_CPY(p3[0], v1);
			PHALCON_PARAM_CPY(p3[1], v2);
			PHALCON_CALL_METHOD_PARAMS(v5, v3, "viewexists", 2, p3, PHALCON_CALL_DEFAULT);
		}
		if(!zend_is_true(v5)){
			PHALCON_NEW(i0, phalcon_model_exception_class_entry);
			phalcon_concat_left(&r2, "Table \"", v2 TSRMLS_CC);
			phalcon_concat_vboth(&r1, r2, "\".\"", v1 TSRMLS_CC);
			PHALCON_PARAM_CPY(p5[0], v0);
			PHALCON_CALL_FUNC_PARAMS(r3, "get_class", 1, p5);
			phalcon_concat_vboth(&r0, r1, "\" doesn't exists on database when dumping information for ", r3 TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p4[0], r0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		} else {
			if(zend_is_true(v4)){
				PHALCON_PARAM_CPY(p6[0], v1);
				PHALCON_PARAM_CPY(p6[1], v2);
				PHALCON_CALL_METHOD_PARAMS(v6, v3, "describeview", 2, p6, PHALCON_CALL_DEFAULT);
			} else {
				PHALCON_PARAM_CPY(p7[0], v1);
				PHALCON_PARAM_CPY(p7[1], v2);
				PHALCON_CALL_METHOD_PARAMS(v6, v3, "describetable", 2, p7, PHALCON_CALL_DEFAULT);
			}
			PHALCON_INIT_ARRAY(v7);
			PHALCON_INIT_ARRAY(v8);
			PHALCON_INIT_ARRAY(v9);
			PHALCON_INIT_ARRAY(v10);
			PHALCON_INIT_ARRAY(v11);
			PHALCON_INIT_ARRAY(v12);
			FOREACH_V(v6, ac0, fes29, fee29, ah0, hp0, v13)
				PHALCON_ARRFETCH_STRING_NOISY(r4, v13, "Field");
				PHALCON_CPY_WRT(v14, r4);
				PHALCON_CPY_WRT(t3, v14);
				PHALCON_ARRAPPEND(v7, t3);
				PHALCON_ARRFETCH_STRING_NOISY(r5, v13, "Key");
				if(phalcon_compare_strict_string(r5, "PRI")){
					PHALCON_CPY_WRT(t4, v14);
					PHALCON_ARRAPPEND(v8, t4);
				} else {
					PHALCON_CPY_WRT(t5, v14);
					PHALCON_ARRAPPEND(v9, t5);
				}
				PHALCON_ARRFETCH_STRING_NOISY(r6, v13, "Type");
				PHALCON_CPY_WRT(v15, r6);
				PHALCON_CPY_WRT(t6, v15);
				PHALCON_ARRUPDATE(v12, v14, t6);
				PHALCON_PARAM_CPY(p8[0], v15);
				PHALCON_PARAM_STRING(p8[1], "int", 0);
				PHALCON_CALL_FUNC_PARAMS(r7, "strpos", 2, p8);
				PHALCON_INIT_FALSE(t7);
				PHALCON_NOT_IDENTICAL_FUNCTION(r8, r7, t7);
				if(zend_is_true(r8)){
					PHALCON_INIT_TRUE(t8);
					PHALCON_ARRUPDATE(v10, v14, t8);
				} else {
					PHALCON_PARAM_CPY(p9[0], v15);
					PHALCON_PARAM_STRING(p9[1], "decimal", 0);
					PHALCON_CALL_FUNC_PARAMS(r9, "strpos", 2, p9);
					PHALCON_INIT_FALSE(t9);
					PHALCON_NOT_IDENTICAL_FUNCTION(r10, r9, t9);
					if(zend_is_true(r10)){
						PHALCON_INIT_TRUE(t10);
						PHALCON_ARRUPDATE(v10, v14, t10);
					}
				}
				PHALCON_ARRFETCH_STRING_NOISY(r11, v13, "Null");
				if(phalcon_compare_strict_string(r11, "NO")){
					PHALCON_CPY_WRT(t11, v14);
					PHALCON_ARRAPPEND(v11, t11);
				}
			END_FOREACH(ac0, fes29, fee29, ah0, hp0);
			PHALCON_INIT_ARRAY(v16);
			PHALCON_CPY_WRT(t12, v7);
			PHALCON_GET_CLASS_CONSTANT(t13, phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES");
			PHALCON_ARRUPDATE(v16, t13, t12);
			PHALCON_CPY_WRT(t14, v8);
			PHALCON_GET_CLASS_CONSTANT(t15, phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY");
			PHALCON_ARRUPDATE(v16, t15, t14);
			PHALCON_CPY_WRT(t16, v9);
			PHALCON_GET_CLASS_CONSTANT(t17, phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY");
			PHALCON_ARRUPDATE(v16, t17, t16);
			PHALCON_CPY_WRT(t18, v11);
			PHALCON_GET_CLASS_CONSTANT(t19, phalcon_model_metadata_class_entry, "MODELS_NOT_NULL");
			PHALCON_ARRUPDATE(v16, t19, t18);
			PHALCON_CPY_WRT(t20, v12);
			PHALCON_GET_CLASS_CONSTANT(t21, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE");
			PHALCON_ARRUPDATE(v16, t21, t20);
			PHALCON_CPY_WRT(t22, v10);
			PHALCON_GET_CLASS_CONSTANT(t23, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC");
			PHALCON_ARRUPDATE(v16, t23, t22);
			t24 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if(Z_TYPE_P(t24)!=IS_ARRAY){
				array_init(t24);
			}
			if(Z_TYPE_P(t24)==IS_ARRAY){
				PHALCON_ARRFETCH_SILENT(t25, t24, v2);
			}
			if(Z_TYPE_P(t25)!=IS_ARRAY){
				array_init(t25);
				PHALCON_ARRUPDATE(t24, v2, t25);
			}
			PHALCON_ARRUPDATE(t25, v1, v16);
			zend_update_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, t24 TSRMLS_CC);
			
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(v1, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_CPY(p2[1], v1);
	PHALCON_PARAM_CPY(p2[2], v2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t0, v2);
	PHALCON_ARRFETCH_NOISY(t2, t3, v1);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES");
	PHALCON_ARRFETCH_NOISY(t1, t2, t4);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(v1, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_CPY(p2[1], v1);
	PHALCON_PARAM_CPY(p2[2], v2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t0, v2);
	PHALCON_ARRFETCH_NOISY(t2, t3, v1);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY");
	PHALCON_ARRFETCH_NOISY(t1, t2, t4);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(v1, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_CPY(p2[1], v1);
	PHALCON_PARAM_CPY(p2[2], v2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t0, v2);
	PHALCON_ARRFETCH_NOISY(t2, t3, v1);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY");
	PHALCON_ARRFETCH_NOISY(t1, t2, t4);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(v1, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_CPY(p2[1], v1);
	PHALCON_PARAM_CPY(p2[2], v2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t0, v2);
	PHALCON_ARRFETCH_NOISY(t2, t3, v1);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_NOT_NULL");
	PHALCON_ARRFETCH_NOISY(t1, t2, t4);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(v1, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_CPY(p2[1], v1);
	PHALCON_PARAM_CPY(p2[2], v2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t0, v2);
	PHALCON_ARRFETCH_NOISY(t2, t3, v1);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE");
	PHALCON_ARRFETCH_NOISY(t1, t2, t4);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(v1, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v0);
	PHALCON_PARAM_CPY(p2[1], v1);
	PHALCON_PARAM_CPY(p2[2], v2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_NOISY(t3, t0, v2);
	PHALCON_ARRFETCH_NOISY(t2, t3, v1);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC");
	PHALCON_ARRFETCH_NOISY(t1, t2, t4);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *s0 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_NULL(v0);
	}
	
	if(!zend_is_true(v0)){
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), r0 TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(s0, v0);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), s0 TSRMLS_CC);
	}
	PHALCON_SET_STRING(t0, "initialize", 1);
	if(phalcon_method_exists(this_ptr, t0 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, _connect){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_connection", sizeof("_connection")-1);
	if(!zend_is_true(t0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_manager", sizeof("_manager")-1);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, _getAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _getPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _getNonPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnonprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _getNotNullAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnotnullattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _getDataTypesNumeric){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypesnumeric", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _getDataTypes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, dump){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *ac0 = NULL;
	zval *s0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_dumped", sizeof("_dumped")-1);
	if(zend_is_true(t0)){
		RETURN_FALSE;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_CALL_METHOD(r0, t1, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p0[0], this_ptr);
	PHALCON_CALL_METHOD_PARAMS(v0, r0, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	FOREACH_V(v0, ac0, fes30, fee30, ah0, hp0, v1)
		convert_to_string(v1);
		PHALCON_READ_PROPERTY_SILENT(t2, this_ptr, Z_STRVAL_P(v1), Z_STRLEN_P(v1));
		if(!zend_is_true(t2)){
			PHALCON_SET_STRING(t3, "", 1);
			PHALCON_CPY_WRT(s0, t3);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v1), Z_STRLEN_P(v1), s0 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes30, fee30, ah0, hp0);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	RETURN_ZVAL(this_ptr, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _createSQLSelectMulti){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_SET_STRING(v1, "SELECT ", 1);
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "columns");
	if(zend_is_true(r0)){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "clear", PHALCON_CALL_DEFAULT);
		PHALCON_CONCAT_FUNCTION(r1, v1, r0);
		PHALCON_CPY_WRT(v1, r1);
	} else {
		PHALCON_PARAM_STRING(p1[0], ", ", 0);
		PHALCON_CALL_METHOD(r3, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p1[1], r3);
		PHALCON_CALL_FUNC_PARAMS(r2, "join", 2, p1);
		PHALCON_CONCAT_FUNCTION(r4, v1, r2);
		PHALCON_CPY_WRT(v1, r4);
	}
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_schema", sizeof("_schema")-1);
	if(zend_is_true(t0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_schema", sizeof("_schema")-1);
		phalcon_concat_left(&r6, " FROM ", t1 TSRMLS_CC);
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_source", sizeof("_source")-1);
		phalcon_concat_vboth(&r5, r6, ".", t2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r7, v1, r5);
		PHALCON_CPY_WRT(v1, r7);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_source", sizeof("_source")-1);
		phalcon_concat_left(&r8, " FROM ", t3 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r9, v1, r8);
		PHALCON_CPY_WRT(v1, r9);
	}
	PHALCON_SET_STRING(v2, "n", 1);
	PHALCON_ARRFETCH_STRING_SILENT(r10, v0, "conditions");
	if(zend_is_true(r10)){
		phalcon_concat_both(&r11,  " WHERE ", r10, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r12, v1, r11);
		PHALCON_CPY_WRT(v1, r12);
	} else {
		PHALCON_CALL_METHOD(v3, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_ARRFETCH_LONG_SILENT(r13, v3, 0);
		if(!zend_is_true(r13)){
			PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, "_isView", sizeof("_isView")-1);
			if(zend_is_true(t4)){
				PHALCON_SET_STRING(t5, "id", 1);
				phalcon_array_update_long(v3, 0, t5 TSRMLS_CC);
			}
		}
		PHALCON_ARRFETCH_LONG_SILENT(r14, v0, 0);
		if(zend_is_true(r14)){
			PHALCON_PARAM_ZVAL(p4[0], r14);
			PHALCON_CALL_FUNC_PARAMS(r15, "is_numeric", 1, p4);
			if(zend_is_true(r15)){
				PHALCON_ARRFETCH_LONG_SILENT(r16, v3, 0);
				if(zend_is_true(r16)){
					PHALCON_READ_PROPERTY_NOISY(t6, this_ptr, "_connection", sizeof("_connection")-1);
					PHALCON_PARAM_ZVAL(p5[0], r14);
					PHALCON_CALL_METHOD_PARAMS(r18, t6, "addquotes", 1, p5, PHALCON_CALL_DEFAULT);
					phalcon_concat_vboth(&r17, r16, " = ", r18 TSRMLS_CC);
					phalcon_array_update_string(v0, "conditions", r17 TSRMLS_CC);
					PHALCON_SET_STRING(v2, "1", 1);
				} else {
					PHALCON_NEW(i0, phalcon_model_exception_class_entry);
					PHALCON_PARAM_STRING(p6[0], "Has not been defined a primary key for source related to this model", 0);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p6, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				}
			} else {
				PHALCON_ARRFETCH_LONG_NOISY(r19, v0, 0);
				PHALCON_SET_STRING(t7, "", 1);
				PHALCON_IDENTICAL_FUNCTION(r20, r19, t7);
				if(zend_is_true(r20)){
					PHALCON_ARRFETCH_LONG_SILENT(r21, v3, 0);
					if(zend_is_true(r21)){
						phalcon_concat_right(&r22, r21, " = ''" TSRMLS_CC);
						phalcon_array_update_string(v0, "conditions", r22 TSRMLS_CC);
					} else {
						PHALCON_NEW(i1, phalcon_model_exception_class_entry);
						PHALCON_PARAM_STRING(p7[0], "Has not been defined a primary key for source related to this model", 0);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p7, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				} else {
					PHALCON_ARRFETCH_LONG_NOISY(r23, v0, 0);
					phalcon_array_update_string(v0, "conditions", r23 TSRMLS_CC);
				}
				PHALCON_SET_STRING(v2, "n", 1);
			}
		}
		PHALCON_ARRFETCH_STRING_SILENT(r24, v0, "conditions");
		if(zend_is_true(r24)){
			phalcon_concat_left(&r25, " WHERE ", r24 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r26, v1, r25);
			PHALCON_CPY_WRT(v1, r26);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r27, v0, "group");
	if(zend_is_true(r27)){
		if(zend_is_true(r27)){
			phalcon_concat_left(&r28, " GROUP BY ", r27 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r29, v1, r28);
			PHALCON_CPY_WRT(v1, r29);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r30, v0, "order");
	if(zend_is_true(r30)){
		if(zend_is_true(r30)){
			phalcon_concat_left(&r31, " ORDER BY ", r30 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r32, v1, r31);
			PHALCON_CPY_WRT(v1, r32);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r33, v0, "limit");
	if(zend_is_true(r33)){
		if(zend_is_true(r33)){
			PHALCON_READ_PROPERTY_NOISY(t8, this_ptr, "_connection", sizeof("_connection")-1);
			PHALCON_PARAM_CPY(p8[0], v1);
			PHALCON_PARAM_ZVAL(p8[1], r33);
			PHALCON_CALL_METHOD_PARAMS(v1, t8, "limit", 2, p8, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r34, v0, "for_update");
	if(zend_is_true(r34)){
		if(zend_is_true(r34)){
			PHALCON_READ_PROPERTY_NOISY(t9, this_ptr, "_connection", sizeof("_connection")-1);
			PHALCON_PARAM_CPY(p9[0], v1);
			PHALCON_CALL_METHOD_PARAMS(v1, t9, "forupdate", 1, p9, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r35, v0, "shared_lock");
	if(zend_is_true(r35)){
		if(zend_is_true(r35)){
			PHALCON_READ_PROPERTY_NOISY(t10, this_ptr, "_connection", sizeof("_connection")-1);
			PHALCON_PARAM_CPY(p10[0], v1);
			PHALCON_CALL_METHOD_PARAMS(v1, t10, "sharedlock", 1, p10, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_INIT_ARRAY(a0);
	PHALCON_CPY_WRT(t11, v2);
	add_assoc_zval(a0, "return", t11);
	PHALCON_CPY_WRT(t12, v1);
	add_assoc_zval(a0, "sql", t12);
	RETURN_ZVAL(a0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _createSQLSelectOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	if(Z_TYPE_P(v1)==IS_ARRAY){
		PHALCON_ARRFETCH_STRING_SILENT(r0, v1, "conditions");
		if(zend_is_true(r0)){
			if(zend_is_true(r0)){
				phalcon_concat_both(&r1,  " WHERE ", r0, " " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r2, v0, r1);
				PHALCON_CPY_WRT(v0, r2);
			}
		} else {
			PHALCON_CALL_METHOD(v2, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
			PHALCON_ARRFETCH_LONG_SILENT(r3, v1, 0);
			if(zend_is_true(r3)){
				PHALCON_PARAM_ZVAL(p1[0], r3);
				PHALCON_CALL_FUNC_PARAMS(r4, "is_numeric", 1, p1);
				if(zend_is_true(r4)){
					PHALCON_ARRFETCH_LONG_NOISY(r6, v2, 0);
					phalcon_concat_vboth(&r5, r6, " = '", r3 TSRMLS_CC);
					phalcon_concat_right(&r7, r5, "'" TSRMLS_CC);
					phalcon_array_update_string(v1, "conditions", r7 TSRMLS_CC);
				} else {
					PHALCON_ARRFETCH_LONG_NOISY(r8, v1, 0);
					if(phalcon_compare_strict_string(r8, "")){
						PHALCON_ARRFETCH_LONG_NOISY(r9, v2, 0);
						phalcon_concat_right(&r10, r9, " = ''" TSRMLS_CC);
						phalcon_array_update_string(v1, "conditions", r10 TSRMLS_CC);
					} else {
						PHALCON_ARRFETCH_LONG_NOISY(r11, v1, 0);
						phalcon_array_update_string(v1, "conditions", r11 TSRMLS_CC);
					}
				}
			}
			PHALCON_ARRFETCH_STRING_SILENT(r12, v1, "conditions");
			if(zend_is_true(r12)){
				phalcon_concat_left(&r13, " WHERE ", r12 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r14, v0, r13);
				PHALCON_CPY_WRT(v0, r14);
			}
		}
		PHALCON_ARRFETCH_STRING_SILENT(r15, v1, "order");
		if(zend_is_true(r15)){
			if(zend_is_true(r15)){
				phalcon_concat_left(&r16, " ORDER BY ", r15 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r17, v0, r16);
				PHALCON_CPY_WRT(v0, r17);
			}
		} else {
			PHALCON_SET_STRING(t0, " ORDER BY 1", 1);
			PHALCON_CONCAT_FUNCTION(r18, v0, t0);
			PHALCON_CPY_WRT(v0, r18);
		}
		PHALCON_ARRFETCH_STRING_SILENT(r19, v1, "limit");
		if(zend_is_true(r19)){
			if(zend_is_true(r19)){
				PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_connection", sizeof("_connection")-1);
				PHALCON_PARAM_CPY(p2[0], v0);
				PHALCON_PARAM_ZVAL(p2[1], r19);
				PHALCON_CALL_METHOD_PARAMS(v0, t1, "limit", 2, p2, PHALCON_CALL_DEFAULT);
			}
		}
		PHALCON_ARRFETCH_STRING_SILENT(r20, v1, "for_update");
		if(zend_is_true(r20)){
			if(zend_is_true(r20)){
				PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_connection", sizeof("_connection")-1);
				PHALCON_PARAM_CPY(p3[0], v0);
				PHALCON_CALL_METHOD_PARAMS(v0, t2, "forupdate", 1, p3, PHALCON_CALL_DEFAULT);
			}
		}
		PHALCON_ARRFETCH_STRING_SILENT(r21, v1, "shared_lock");
		if(zend_is_true(r21)){
			if(zend_is_true(r21)){
				PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_connection", sizeof("_connection")-1);
				PHALCON_PARAM_CPY(p4[0], v0);
				PHALCON_CALL_METHOD_PARAMS(v0, t3, "sharedlock", 1, p4, PHALCON_CALL_DEFAULT);
			}
		}
	} else {
		PHALCON_PARAM_CPY(p5[0], v1);
		PHALCON_CALL_FUNC_PARAMS(r22, "strlen", 1, p5);
		PHALCON_SET_LONG(t4, 0);
		PHALCON_SMALLER_FUNCTION(r23, t4, r22);
		if(zend_is_true(r23)){
			PHALCON_PARAM_CPY(p6[0], v1);
			PHALCON_CALL_FUNC_PARAMS(r24, "is_numeric", 1, p6);
			if(zend_is_true(r24)){
				PHALCON_ARRFETCH_LONG_NOISY(r26, v2, 0);
				phalcon_concat_left(&r27, "WHERE ", r26 TSRMLS_CC);
				phalcon_concat_vboth(&r25, r27, " = '", v1 TSRMLS_CC);
				phalcon_concat_right(&r28, r25, "'" TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r29, v0, r28);
				PHALCON_CPY_WRT(v0, r29);
			} else {
				phalcon_concat_left(&r30, "WHERE ", v1 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r31, v0, r30);
				PHALCON_CPY_WRT(v0, r31);
			}
		}
	}
	RETURN_ZVAL(v0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _createResultset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CPY_WRT(v2, t0);
	PHALCON_ARRFETCH_STRING_NOISY(r0, v0, "return");
	PHALCON_SET_STRING(t1, "1", 1);
	PHALCON_EQUAL_FUNCTION(r1, r0, t1);
	if(zend_is_true(r1)){
		PHALCON_PARAM_CPY(p0[0], v1);
		PHALCON_CALL_METHOD_PARAMS(r2, v2, "numrows", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_SET_LONG(t2, 0);
		PHALCON_EQUAL_FUNCTION(r3, r2, t2);
		if(zend_is_true(r3)){
			phalcon_update_property_long(this_ptr, "_count", strlen("_count"), 0 TSRMLS_CC);
			RETURN_FALSE;
		} else {
			PHALCON_GET_CLASS_CONSTANT(t3, phalcon_db_class_entry, "DB_ASSOC");
			PHALCON_PARAM_ZVAL(p1[0], t3);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
			PHALCON_PARAM_CPY(p2[0], v1);
			PHALCON_CALL_METHOD_PARAMS(v3, v2, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
			PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_class_entry, "DB_BOTH");
			PHALCON_PARAM_ZVAL(p3[0], t4);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setfetchmode", 1, p3, PHALCON_CALL_DEFAULT);
			PHALCON_PARAM_CPY(p4[0], v3);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "dumpresultself", 1, p4, PHALCON_CALL_DEFAULT);
			phalcon_update_property_long(this_ptr, "_count", strlen("_count"), 1 TSRMLS_CC);
			PHALCON_PARAM_CPY(p5[0], v3);
			PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "dumpresult", 1, p5, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r4, 0, 0);
		}
	} else {
		PHALCON_PARAM_CPY(p6[0], v1);
		PHALCON_CALL_METHOD_PARAMS(r5, v2, "numrows", 1, p6, PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), r5 TSRMLS_CC);
		PHALCON_READ_PROPERTY_NOISY(t5, this_ptr, "_count", sizeof("_count")-1);
		PHALCON_SET_LONG(t6, 0);
		PHALCON_SMALLER_FUNCTION(r6, t6, t5);
		if(zend_is_true(r6)){
			PHALCON_NEW(i0, phalcon_model_resultset_class_entry);
			PHALCON_PARAM_CPY(p7[0], this_ptr);
			PHALCON_PARAM_CPY(p7[1], v1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p7, PHALCON_CALL_CHECK);
			RETURN_ZVAL(i0, 0, 0);
		} else {
			PHALCON_NEW(i1, phalcon_model_resultset_class_entry);
			PHALCON_PARAM_CPY(p8[0], this_ptr);
			PHALCON_INIT_FALSE(t7);
			PHALCON_PARAM_ZVAL(p8[1], t7);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p8, PHALCON_CALL_CHECK);
			RETURN_ZVAL(i1, 0, 0);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, setTransaction){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)==IS_OBJECT){
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	} else {
		PHALCON_NEW(i0, phalcon_model_exception_class_entry);
		PHALCON_PARAM_STRING(p1[0], "Transaction should be an object", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_ZVAL(this_ptr, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, isView){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_isView", sizeof("_isView")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, setSource){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, getSource){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_source", sizeof("_source")-1);
	if(phalcon_compare_strict_string(t0, "")){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_manager", sizeof("_manager")-1);
		PHALCON_PARAM_CPY(p1[0], this_ptr);
		PHALCON_CALL_FUNC_PARAMS(r1, "get_class", 1, p1);
		PHALCON_PARAM_ZVAL(p0[0], r1);
		PHALCON_CALL_METHOD_PARAMS(r0, t1, "getsource", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), r0 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_source", sizeof("_source")-1);
	RETURN_ZVAL(t2, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, setSchema){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, getSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_schema", sizeof("_schema")-1);
	if(phalcon_compare_strict_string(t0, "")){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_connection", sizeof("_connection")-1);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r0 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_schema", sizeof("_schema")-1);
	RETURN_ZVAL(t2, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_connection", sizeof("_connection")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *s0 = NULL, *s1 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	phalcon_clone(&s0, this_ptr TSRMLS_CC);
	PHALCON_CPY_WRT(v1, s0);
	zend_update_property_bool(Z_OBJCE_P(v1), v1, "_forceExists", strlen("_forceExists"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	if(Z_TYPE_P(v0)==IS_ARRAY){
		FOREACH_KV(v0, ac0, fes31, fee31, ah0, hp0, v3, v2)
			PHALCON_CPY_WRT(s1, v2);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), s1 TSRMLS_CC);
		END_FOREACH(ac0, fes31, fee31, ah0, hp0);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	RETURN_ZVAL(v1, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, dumpResultSelf){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *s0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	if(Z_TYPE_P(v0)==IS_ARRAY){
		FOREACH_KV(v0, ac0, fes32, fee32, ah0, hp0, v2, v1)
			PHALCON_CPY_WRT(s0, v1);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), s0 TSRMLS_CC);
		END_FOREACH(ac0, fes32, fee32, ah0, hp0);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, find){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_NULL(v0);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		if(Z_TYPE_P(v0)!=IS_NULL){
			PHALCON_INIT_ARRAY(v0);
			PHALCON_CPY_WRT(t0, v0);
			add_next_index_zval(v0, t0);
		} else {
			PHALCON_INIT_ARRAY(v0);
		}
	}
	PHALCON_PARAM_CPY(p1[0], v0);
	PHALCON_CALL_METHOD_PARAMS(v1, this_ptr, "_createsqlselectmulti", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_ARRFETCH_STRING_NOISY(r0, v1, "sql");
	PHALCON_PARAM_ZVAL(p2[0], r0);
	PHALCON_CALL_METHOD_PARAMS(v2, t1, "query", 1, p2, PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p3[0], v1);
	PHALCON_PARAM_CPY(p3[1], v2);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_createresultset", 2, p3, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, findFirst){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *p4[] = { NULL, NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL }, *p11[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_NULL(v0);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		if(Z_TYPE_P(v0)!=IS_NULL){
			PHALCON_INIT_ARRAY(v0);
			PHALCON_CPY_WRT(t0, v0);
			add_next_index_zval(v0, t0);
		} else {
			PHALCON_INIT_ARRAY(v0);
		}
	}
	PHALCON_CALL_METHOD(v1, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_SET_STRING(v3, "SELECT ", 1);
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "columns");
	if(zend_is_true(r0)){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "clear", PHALCON_CALL_DEFAULT);
		PHALCON_CONCAT_FUNCTION(r1, v3, r0);
		PHALCON_CPY_WRT(v3, r1);
	} else {
		PHALCON_PARAM_STRING(p4[0], ", ", 0);
		PHALCON_CALL_METHOD(r3, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_ZVAL(p4[1], r3);
		PHALCON_CALL_FUNC_PARAMS(r2, "join", 2, p4);
		PHALCON_CONCAT_FUNCTION(r4, v3, r2);
		PHALCON_CPY_WRT(v3, r4);
	}
	if(!phalcon_compare_strict_string(v1, "")){
		phalcon_concat_left(&r6, " FROM ", v1 TSRMLS_CC);
		phalcon_concat_vboth(&r5, r6, ".", v2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r7, v3, r5);
		PHALCON_CPY_WRT(v3, r7);
	} else {
		phalcon_concat_left(&r8, " FROM ", v2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r9, v3, r8);
		PHALCON_CPY_WRT(v3, r9);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r10, v0, "limit");
	if(!zend_is_true(r10)){
		PHALCON_SET_LONG(t1, 1);
		phalcon_array_update_string(v0, "limit", t1 TSRMLS_CC);
	}
	PHALCON_INIT_BOOL(v4, 0);
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CPY_WRT(v5, t2);
	PHALCON_PARAM_CPY(p6[0], v3);
	PHALCON_PARAM_CPY(p6[1], v0);
	PHALCON_CALL_METHOD_PARAMS(v3, this_ptr, "_createsqlselectone", 2, p6, PHALCON_CALL_DEFAULT);
	PHALCON_GET_CLASS_CONSTANT(t3, phalcon_db_class_entry, "DB_ASSOC");
	PHALCON_PARAM_ZVAL(p7[0], t3);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v5, "setfetchmode", 1, p7, PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p8[0], v3);
	PHALCON_CALL_METHOD_PARAMS(v6, v5, "fetchone", 1, p8, PHALCON_CALL_DEFAULT);
	if(zend_is_true(v6)){
		PHALCON_PARAM_CPY(p9[0], v6);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "dumpresultself", 1, p9, PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_CPY(p10[0], v6);
		PHALCON_CALL_METHOD_PARAMS(v4, this_ptr, "dumpresult", 1, p10, PHALCON_CALL_DEFAULT);
	}
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_class_entry, "DB_BOTH");
	PHALCON_PARAM_ZVAL(p11[0], t4);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v5, "setfetchmode", 1, p11, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(v4, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, exists){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p1[0], v0);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_exists", 1, p1, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p11[] = { NULL }, *p12[] = { NULL }, *p13[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_forceExists", sizeof("_forceExists")-1);
	if(!zend_is_true(t0)){
		PHALCON_CALL_METHOD(v1, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(v2, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
		if(zend_is_true(v1)){
			phalcon_concat_vboth(&r0, v1, ".", v2 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r0);
		} else {
			PHALCON_CPY_WRT(v3, v2);
		}
		phalcon_concat_both(&r1,  "SELECT COUNT(*) AS rowcount FROM ", v3, " WHERE " TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r1);
		if(phalcon_compare_strict_string(v0, "")){
			PHALCON_INIT_ARRAY(v0);
			PHALCON_CALL_METHOD(v5, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
			PHALCON_CALL_METHOD(v6, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
			PHALCON_PARAM_CPY(p4[0], v5);
			PHALCON_CALL_FUNC_PARAMS(r2, "count", 1, p4);
			PHALCON_SET_LONG(t1, 0);
			PHALCON_SMALLER_FUNCTION(r3, t1, r2);
			if(zend_is_true(r3)){
				FOREACH_V(v5, ac0, fes33, fee33, ah0, hp0, v7)
					convert_to_string(v7);
					PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
					PHALCON_INIT_NULL(t3);
					PHALCON_NOT_IDENTICAL_FUNCTION(r4, t2, t3);
					convert_to_string(v7);
					PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
					PHALCON_SET_STRING(t5, "", 1);
					PHALCON_NOT_IDENTICAL_FUNCTION(r5, t4, t5);
					PHALCON_AND_FUNCTION(r6, r4, r5);
					if(zend_is_true(r6)){
						PHALCON_ARRFETCH_SILENT(r7, v6, v7);
						if(zend_is_true(r7)){
							phalcon_concat_left(&r9, " ", v7 TSRMLS_CC);
							convert_to_string(v7);
							PHALCON_READ_PROPERTY_NOISY(t6, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
							phalcon_concat_vboth(&r8, r9, " = ", t6 TSRMLS_CC);
							PHALCON_ARRAPPEND(v0, r8);
						} else {
							phalcon_concat_left(&r11, " ", v7 TSRMLS_CC);
							convert_to_string(v7);
							PHALCON_READ_PROPERTY_NOISY(t7, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
							phalcon_concat_vboth(&r10, r11, " = '", t7 TSRMLS_CC);
							phalcon_concat_right(&r12, r10, "'" TSRMLS_CC);
							PHALCON_ARRAPPEND(v0, r12);
						}
					}
				END_FOREACH(ac0, fes33, fee33, ah0, hp0);
				PHALCON_PARAM_CPY(p5[0], v0);
				PHALCON_CALL_FUNC_PARAMS(r13, "count", 1, p5);
				if(zend_is_true(r13)){
					PHALCON_PARAM_STRING(p6[0], " AND ", 0);
					PHALCON_PARAM_CPY(p6[1], v0);
					PHALCON_CALL_FUNC_PARAMS(r14, "join", 2, p6);
					phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r14 TSRMLS_CC);
				} else {
					RETURN_LONG(0);
				}
				PHALCON_READ_PROPERTY_NOISY(t8, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1);
				PHALCON_CONCAT_FUNCTION(r15, v4, t8);
				PHALCON_CPY_WRT(v4, r15);
			} else {
				RETURN_LONG(0);
			}
		} else {
			PHALCON_PARAM_CPY(p7[0], v0);
			PHALCON_CALL_FUNC_PARAMS(r16, "is_numeric", 1, p7);
			if(zend_is_true(r16)){
				phalcon_concat_left(&r17, "id = ", v0 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r18, v4, r17);
				PHALCON_CPY_WRT(v4, r18);
			} else {
				PHALCON_CONCAT_FUNCTION(r19, v4, v0);
				PHALCON_CPY_WRT(v4, r19);
			}
		}
		PHALCON_READ_PROPERTY_NOISY(t9, this_ptr, "_connection", sizeof("_connection")-1);
		PHALCON_PARAM_CPY(p8[0], v4);
		PHALCON_CALL_METHOD_PARAMS(v8, t9, "fetchone", 1, p8, PHALCON_CALL_DEFAULT);
		PHALCON_ARRFETCH_STRING_NOISY(r20, v8, "rowcount");
		RETURN_ZVAL(r20, 0, 0);
	} else {
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CALL_METHOD(v5, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(v9, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_CPY(p11[0], v5);
		PHALCON_CALL_FUNC_PARAMS(r21, "count", 1, p11);
		PHALCON_SET_LONG(t10, 0);
		PHALCON_SMALLER_FUNCTION(r22, t10, r21);
		if(zend_is_true(r22)){
			FOREACH_V(v5, ac1, fes34, fee34, ah1, hp1, v7)
				convert_to_string(v7);
				PHALCON_READ_PROPERTY_NOISY(t11, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
				PHALCON_INIT_NULL(t12);
				PHALCON_NOT_IDENTICAL_FUNCTION(r23, t11, t12);
				convert_to_string(v7);
				PHALCON_READ_PROPERTY_NOISY(t13, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
				PHALCON_SET_STRING(t14, "", 1);
				PHALCON_NOT_IDENTICAL_FUNCTION(r24, t13, t14);
				PHALCON_AND_FUNCTION(r25, r23, r24);
				if(zend_is_true(r25)){
					PHALCON_ARRFETCH_SILENT(r26, v9, v7);
					if(zend_is_true(r26)){
						phalcon_concat_left(&r28, " ", v7 TSRMLS_CC);
						convert_to_string(v7);
						PHALCON_READ_PROPERTY_NOISY(t15, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
						phalcon_concat_vboth(&r27, r28, " = ", t15 TSRMLS_CC);
						PHALCON_ARRAPPEND(v0, r27);
					} else {
						phalcon_concat_left(&r30, " ", v7 TSRMLS_CC);
						convert_to_string(v7);
						PHALCON_READ_PROPERTY_NOISY(t16, this_ptr, Z_STRVAL_P(v7), Z_STRLEN_P(v7));
						phalcon_concat_vboth(&r29, r30, " = '", t16 TSRMLS_CC);
						phalcon_concat_right(&r31, r29, "'" TSRMLS_CC);
						PHALCON_ARRAPPEND(v0, r31);
					}
				}
			END_FOREACH(ac1, fes34, fee34, ah1, hp1);
			PHALCON_PARAM_CPY(p12[0], v0);
			PHALCON_CALL_FUNC_PARAMS(r32, "count", 1, p12);
			if(zend_is_true(r32)){
				PHALCON_PARAM_STRING(p13[0], " AND ", 0);
				PHALCON_PARAM_CPY(p13[1], v0);
				PHALCON_CALL_FUNC_PARAMS(r33, "join", 2, p13);
				phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r33 TSRMLS_CC);
				RETURN_TRUE;
			} else {
				RETURN_LONG(0);
			}
		} else {
			RETURN_LONG(0);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "group");
	if(zend_is_true(r0)){
		PHALCON_PARAM_CPY(p0[0], v1);
		PHALCON_CALL_METHOD_PARAMS(v4, v3, "query", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_PARAM_CPY(p1[0], v4);
		PHALCON_CALL_METHOD_PARAMS(v5, v3, "numrows", 1, p1, PHALCON_CALL_DEFAULT);
		PHALCON_SET_LONG(t1, 0);
		PHALCON_SMALLER_FUNCTION(r1, t1, v5);
		if(zend_is_true(r1)){
			ce0 = zend_fetch_class("phalcon_model_row", strlen("phalcon_model_row"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_NEW(i0, ce0);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v6, i0);
			PHALCON_PARAM_CPY(p3[0], v3);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "setconnection", 1, p3, PHALCON_CALL_DEFAULT);
			PHALCON_NEW(i1, phalcon_model_resultset_class_entry);
			PHALCON_PARAM_CPY(p4[0], v6);
			PHALCON_PARAM_CPY(p4[1], v4);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p4, PHALCON_CALL_CHECK);
			RETURN_ZVAL(i1, 0, 0);
		} else {
			PHALCON_NEW(i2, phalcon_model_resultset_class_entry);
			PHALCON_NEW_STD(i3);
			PHALCON_PARAM_ZVAL(p5[0], i3);
			PHALCON_INIT_FALSE(t2);
			PHALCON_PARAM_ZVAL(p5[1], t2);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p5, PHALCON_CALL_CHECK);
			RETURN_ZVAL(i2, 0, 0);
		}
	} else {
		PHALCON_PARAM_CPY(p6[0], v1);
		PHALCON_CALL_METHOD_PARAMS(v7, v3, "fetchone", 1, p6, PHALCON_CALL_DEFAULT);
		PHALCON_ARRFETCH_NOISY(r2, v7, v2);
		RETURN_ZVAL(r2, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, count){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL, NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		if(Z_TYPE_P(v0)!=IS_NULL){
			PHALCON_INIT_ARRAY(v0);
			PHALCON_CPY_WRT(t0, v0);
			add_next_index_zval(v0, t0);
		} else {
			PHALCON_INIT_ARRAY(v0);
		}
	}
	PHALCON_CALL_METHOD(v1, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v2, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	if(zend_is_true(v1)){
		phalcon_concat_vboth(&r0, v1, ".", v2 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r0);
	} else {
		PHALCON_CPY_WRT(v3, v2);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r1, v0, "distinct");
	if(zend_is_true(r1)){
		phalcon_concat_left(&r3, "SELECT COUNT(DISTINCT ", r1 TSRMLS_CC);
		phalcon_concat_vboth(&r2, r3, ") AS rowcount FROM ", v3 TSRMLS_CC);
		phalcon_concat_right(&r4, r2, " " TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r4);
	} else {
		PHALCON_ARRFETCH_STRING_SILENT(r5, v0, "group");
		if(zend_is_true(r5)){
			phalcon_concat_left(&r7, "SELECT ", r5 TSRMLS_CC);
			phalcon_concat_vboth(&r6, r7, ", COUNT(*) AS rowcount FROM ", v3 TSRMLS_CC);
			phalcon_concat_right(&r8, r6, " " TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r8);
		} else {
			phalcon_concat_both(&r9,  "SELECT COUNT(*) AS rowcount FROM ", v3, " " TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r9);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r10, v0, "conditions");
	if(zend_is_true(r10)){
		phalcon_concat_both(&r11,  " WHERE ", r10, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r12, v4, r11);
		PHALCON_CPY_WRT(v4, r12);
	} else {
		PHALCON_ARRFETCH_LONG_SILENT(r13, v0, 0);
		if(zend_is_true(r13)){
			PHALCON_PARAM_ZVAL(p3[0], r13);
			PHALCON_CALL_FUNC_PARAMS(r14, "is_numeric", 1, p3);
			if(zend_is_true(r14)){
				PHALCON_CALL_METHOD(v5, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
				PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_isView", sizeof("_isView")-1);
				if(zend_is_true(t1)){
					PHALCON_SET_STRING(t2, "id", 1);
					phalcon_array_update_long(v5, 0, t2 TSRMLS_CC);
				}
				PHALCON_ARRFETCH_LONG_NOISY(r16, v5, 0);
				phalcon_concat_left(&r17, " WHERE ", r16 TSRMLS_CC);
				PHALCON_ARRFETCH_LONG_NOISY(r18, v0, 0);
				phalcon_concat_vboth(&r15, r17, " = '", r18 TSRMLS_CC);
				phalcon_concat_right(&r19, r15, "'" TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r20, v4, r19);
				PHALCON_CPY_WRT(v4, r20);
			} else {
				PHALCON_ARRFETCH_LONG_NOISY(r21, v0, 0);
				phalcon_concat_left(&r22, " WHERE ", r21 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r23, v4, r22);
				PHALCON_CPY_WRT(v4, r23);
			}
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r24, v0, "group");
	if(zend_is_true(r24)){
		phalcon_concat_both(&r25,  " GROUP BY ", r24, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r26, v4, r25);
		PHALCON_CPY_WRT(v4, r26);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r27, v0, "having");
	if(zend_is_true(r27)){
		phalcon_concat_both(&r28,  " HAVING ", r27, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r29, v4, r28);
		PHALCON_CPY_WRT(v4, r29);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r30, v0, "order");
	if(zend_is_true(r30)){
		phalcon_concat_both(&r31,  " ORDER BY ", r30, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r32, v4, r31);
		PHALCON_CPY_WRT(v4, r32);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r33, v0, "limit");
	if(zend_is_true(r33)){
		PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "connection", sizeof("connection")-1);
		PHALCON_PARAM_CPY(p5[0], v4);
		PHALCON_PARAM_ZVAL(p5[1], r33);
		PHALCON_CALL_METHOD_PARAMS(v4, t3, "_limit", 2, p5, PHALCON_CALL_DEFAULT);
	}
	PHALCON_PARAM_CPY(p6[0], v0);
	PHALCON_PARAM_CPY(p6[1], v4);
	PHALCON_PARAM_STRING(p6[2], "rowcount", 0);
	PHALCON_CALL_METHOD_PARAMS(r34, this_ptr, "_getgroupresult", 3, p6, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r34, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(phalcon_method_exists(this_ptr, v0 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(v0), PHALCON_CALL_DEFAULT);
		if(Z_TYPE_P(r0)==IS_BOOL&&!Z_BVAL_P(r0)){
			RETURN_FALSE;
		}
	} else {
		convert_to_string(v0);
		PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0));
		if(zend_is_true(t0)){
			convert_to_string(v0);
			PHALCON_CPY_WRT(v1, t0);
			PHALCON_CALL_METHOD(r1, this_ptr, Z_STRVAL_P(v1), PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r1)==IS_BOOL&&!Z_BVAL_P(r1)){
				RETURN_FALSE;
			}
		}
	}
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _cancelOperation){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL };

	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_FALSE(t1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
	if(zend_is_true(r0)){
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_operationMade", sizeof("_operationMade")-1);
		PHALCON_GET_CLASS_CONSTANT(t3, phalcon_model_base_class_entry, "OP_DELETE");
		PHALCON_EQUAL_FUNCTION(r1, t2, t3);
		if(zend_is_true(r1)){
			PHALCON_PARAM_STRING(p0[0], "notDeleted", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
		} else {
			PHALCON_PARAM_STRING(p1[0], "notSaved", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_CALL_STATIC(r2, "phalcon_transactions", "isautomatic");
	if(zend_is_true(r2)){
		PHALCON_CALL_STATIC(r3, "phalcon_transactions", "getautomatictransaction");
		PHALCON_CPY_WRT(v0, r3);
		PHALCON_PARAM_CPY(p4[0], this_ptr);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setrollbackedrecord", 1, p4, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD_NORETURN(v0, "rollback", PHALCON_CALL_DEFAULT);
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, appendMessage){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL }, *p3[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)==IS_OBJECT){
		PHALCON_PARAM_CPY(p0[0], v0);
		PHALCON_CALL_FUNC_PARAMS(r0, "get_class", 1, p0);
		if(!phalcon_compare_strict_string(r0, "Phalcon_Model_Message")){
			PHALCON_NEW(i0, phalcon_model_exception_class_entry);
			PHALCON_PARAM_CPY(p2[0], v0);
			PHALCON_CALL_FUNC_PARAMS(r1, "get_class", 1, p2);
			phalcon_concat_both(&r2,  "Invalid message format '", r1, "'" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p1[0], r2);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	} else {
		PHALCON_NEW(i1, phalcon_model_exception_class_entry);
		PHALCON_PARAM_CPY(p4[0], v0);
		PHALCON_CALL_FUNC_PARAMS(r3, "gettype", 1, p4);
		phalcon_concat_both(&r4,  "Invalid message format '", r3, "'" TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p3[0], r4);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_READ_PROPERTY_SILENT(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1);
	PHALCON_CPY_WRT(t1, v0);
	PHALCON_ARRAPPEND(t0, t1);
	zend_update_property(phalcon_model_base_class_entry, this_ptr, "_errorMessages", strlen("_errorMessages"), t0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, getMessages){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, save){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL, *v17 = NULL, *v18 = NULL, *v19 = NULL, *v20 = NULL;
	zval *v21 = NULL, *v22 = NULL, *v23 = NULL, *v24 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL, *t27 = NULL;
	zval *t28 = NULL, *t29 = NULL, *t30 = NULL, *t31 = NULL, *t32 = NULL, *t33 = NULL;
	zval *s0 = NULL, *s1 = NULL, *s2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p2[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p10[] = { NULL }, *p11[] = { NULL }, *p12[] = { NULL, NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p14[] = { NULL }, *p16[] = { NULL }, *p17[] = { NULL }, *p19[] = { NULL }, *p21[] = { NULL }, *p23[] = { NULL }, *p25[] = { NULL }, *p27[] = { NULL }, *p29[] = { NULL }, *p38[] = { NULL }, *p39[] = { NULL, NULL, NULL, NULL }, *p42[] = { NULL }, *p43[] = { NULL }, *p44[] = { NULL, NULL, NULL }, *p48[] = { NULL }, *p49[] = { NULL }, *p50[] = { NULL }, *p51[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_class_entry *ce0, *ce1;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v0, this_ptr, "_exists", PHALCON_CALL_DEFAULT);
	if(!zend_is_true(v0)){
		PHALCON_GET_CLASS_CONSTANT(t0, phalcon_model_base_class_entry, "OP_CREATE");
		PHALCON_CPY_WRT(s0, t0);
		phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), s0 TSRMLS_CC);
	} else {
		PHALCON_GET_CLASS_CONSTANT(t1, phalcon_model_base_class_entry, "OP_UPDATE");
		PHALCON_CPY_WRT(s1, t1);
		phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), s1 TSRMLS_CC);
	}
	PHALCON_INIT_ARRAY(a0);
	PHALCON_CPY_WRT(s2, a0);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), s2 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t2);
	if(!zend_is_true(v1)){
		PHALCON_PARAM_STRING(p2[0], "beforeValidation", 0);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
		if(Z_TYPE_P(r0)==IS_BOOL&&!Z_BVAL_P(r0)){
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
		if(!zend_is_true(v0)){
			PHALCON_PARAM_STRING(p4[0], "beforeValidationOnCreate", 0);
			PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r1)==IS_BOOL&&!Z_BVAL_P(r1)){
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		} else {
			PHALCON_PARAM_STRING(p6[0], "beforeValidationOnUpdate", 0);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r2)==IS_BOOL&&!Z_BVAL_P(r2)){
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		}
	}
	//Wasted infer Constant null
	PHALCON_INIT_NULL(t3);
	PHALCON_CPY_WRT(v2, t3);
	PHALCON_CALL_METHOD(v3, this_ptr, "_getnotnullattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v4, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	if(Z_TYPE_P(v3)==IS_ARRAY){
		PHALCON_INIT_BOOL(v5, 0);
		PHALCON_PARAM_CPY(p10[0], v3);
		PHALCON_CALL_FUNC_PARAMS(v6, "count", 1, p10);
		PHALCON_SET_LONG(v7, 0);
		fs35:
		PHALCON_SMALLER_FUNCTION(r3, v7, v6);
		if(!zend_is_true(r3)){
			goto fe35;
		}
		PHALCON_INIT_BOOL(v8, 0);
		PHALCON_ARRFETCH_NOISY(r4, v3, v7);
		PHALCON_CPY_WRT(v9, r4);
		convert_to_string(v9);
		PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, Z_STRVAL_P(v9), Z_STRLEN_P(v9));
		PHALCON_CPY_WRT(v10, t4);
		PHALCON_ARRFETCH_SILENT(r5, v4, v9);
		if(!zend_is_true(r5)){
			PHALCON_INIT_NULL(t5);
			PHALCON_IDENTICAL_FUNCTION(r6, v10, t5);
			PHALCON_SET_STRING(t6, "", 1);
			PHALCON_IDENTICAL_FUNCTION(r7, v10, t6);
			PHALCON_OR_FUNCTION(r8, r6, r7);
			if(zend_is_true(r8)){
				PHALCON_INIT_BOOL(v8, 1);
			}
		} else {
			PHALCON_PARAM_CPY(p11[0], v10);
			PHALCON_CALL_FUNC_PARAMS(r9, "is_numeric", 1, p11);
			if(!zend_is_true(r9)){
				PHALCON_INIT_BOOL(v8, 1);
			}
		}
		PHALCON_INIT_TRUE(t7);
		PHALCON_EQUAL_FUNCTION(r10, v8, t7);
		if(zend_is_true(r10)){
			PHALCON_BOOLEAN_NOT_FUNCTION(r11, v0);
			PHALCON_SET_STRING(t8, "id", 1);
			PHALCON_EQUAL_FUNCTION(r12, v9, t8);
			PHALCON_AND_FUNCTION(r13, r11, r12);
			if(zend_is_true(r13)){
				goto fi35;
			}
			PHALCON_PARAM_STRING(p12[0], "_id", 0);
			PHALCON_PARAM_STRING(p12[1], "", 0);
			PHALCON_PARAM_CPY(p12[2], v9);
			PHALCON_CALL_FUNC_PARAMS(v11, "str_replace", 3, p12);
			PHALCON_NEW(i0, phalcon_model_message_class_entry);
			phalcon_concat_right(&r14, v11, " is required" TSRMLS_CC);
			PHALCON_PARAM_ZVAL(p13[0], r14);
			PHALCON_PARAM_CPY(p13[1], v9);
			PHALCON_PARAM_STRING(p13[2], "PresenceOf", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p13, PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v12, i0);
			PHALCON_READ_PROPERTY_SILENT(t9, this_ptr, "_errorMessages", sizeof("_errorMessages")-1);
			PHALCON_CPY_WRT(t10, v12);
			PHALCON_ARRAPPEND(t9, t10);
			zend_update_property(phalcon_model_base_class_entry, this_ptr, "_errorMessages", strlen("_errorMessages"), t9 TSRMLS_CC);
			PHALCON_INIT_BOOL(v5, 1);
		}
		fi35:
		increment_function(v7);
		goto fs35;
		fe35:
		r3 = NULL;
		if(zend_is_true(v5)){
			if(!zend_is_true(v1)){
				PHALCON_PARAM_STRING(p14[0], "onValidationFails", 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p14, PHALCON_CALL_DEFAULT);
			}
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
	}
	PHALCON_PARAM_STRING(p16[0], "validation", 0);
	PHALCON_CALL_METHOD_PARAMS(r15, this_ptr, "_callevent", 1, p16, PHALCON_CALL_DEFAULT);
	if(Z_TYPE_P(r15)==IS_BOOL&&!Z_BVAL_P(r15)){
		if(!zend_is_true(v1)){
			PHALCON_PARAM_STRING(p17[0], "onValidationFails", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p17, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		RETURN_FALSE;
	}
	if(!zend_is_true(v1)){
		if(!zend_is_true(v0)){
			PHALCON_PARAM_STRING(p19[0], "afterValidationOnCreate", 0);
			PHALCON_CALL_METHOD_PARAMS(r16, this_ptr, "_callevent", 1, p19, PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r16)==IS_BOOL&&!Z_BVAL_P(r16)){
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		} else {
			PHALCON_PARAM_STRING(p21[0], "afterValidationOnUpdate", 0);
			PHALCON_CALL_METHOD_PARAMS(r17, this_ptr, "_callevent", 1, p21, PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r17)==IS_BOOL&&!Z_BVAL_P(r17)){
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		}
		PHALCON_PARAM_STRING(p23[0], "afterValidation", 0);
		PHALCON_CALL_METHOD_PARAMS(r18, this_ptr, "_callevent", 1, p23, PHALCON_CALL_DEFAULT);
		if(Z_TYPE_P(r18)==IS_BOOL&&!Z_BVAL_P(r18)){
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
		PHALCON_PARAM_STRING(p25[0], "beforeSave", 0);
		PHALCON_CALL_METHOD_PARAMS(r19, this_ptr, "_callevent", 1, p25, PHALCON_CALL_DEFAULT);
		if(Z_TYPE_P(r19)==IS_BOOL&&!Z_BVAL_P(r19)){
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
		if(zend_is_true(v0)){
			PHALCON_PARAM_STRING(p27[0], "beforeUpdate", 0);
			PHALCON_CALL_METHOD_PARAMS(r20, this_ptr, "_callevent", 1, p27, PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r20)==IS_BOOL&&!Z_BVAL_P(r20)){
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		} else {
			PHALCON_PARAM_STRING(p29[0], "beforeCreate", 0);
			PHALCON_CALL_METHOD_PARAMS(r21, this_ptr, "_callevent", 1, p29, PHALCON_CALL_DEFAULT);
			if(Z_TYPE_P(r21)==IS_BOOL&&!Z_BVAL_P(r21)){
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		}
	}
	PHALCON_CALL_METHOD(v13, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v14, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	if(zend_is_true(v13)){
		phalcon_concat_vboth(&r22, v13, ".", v14 TSRMLS_CC);
		PHALCON_CPY_WRT(v15, r22);
	} else {
		PHALCON_CPY_WRT(v15, v14);
	}
	PHALCON_READ_PROPERTY_NOISY(t11, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CPY_WRT(v16, t11);
	PHALCON_CALL_METHOD(v17, this_ptr, "_getdatatypes", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v18, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD(v4, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	if(zend_is_true(v0)){
		PHALCON_INIT_ARRAY(v19);
		PHALCON_INIT_ARRAY(v20);
		PHALCON_CALL_METHOD(v21, this_ptr, "_getnonprimarykeyattributes", PHALCON_CALL_DEFAULT);
		FOREACH_V(v21, ac0, fes36, fee36, ah0, hp0, v9)
			PHALCON_CPY_WRT(t12, v9);
			PHALCON_ARRAPPEND(v19, t12);
			convert_to_string(v9);
			PHALCON_READ_PROPERTY_NOISY(t13, this_ptr, Z_STRVAL_P(v9), Z_STRLEN_P(v9));
			PHALCON_CPY_WRT(v10, t13);
			if(Z_TYPE_P(v10)==IS_OBJECT){
				PHALCON_INSTANCE_OF(r23, v10, phalcon_db_rawvalue_class_entry);
				if(zend_is_true(r23)){
					PHALCON_CALL_METHOD(r24, v10, "getvalue", PHALCON_CALL_DEFAULT);
					PHALCON_ARRAPPEND(v20, r24);
				} else {
					convert_to_string(v9);
					PHALCON_READ_PROPERTY_NOISY(t14, this_ptr, Z_STRVAL_P(v9), Z_STRLEN_P(v9));
					convert_to_string(t14);
					PHALCON_ARRAPPEND(v20, t14);
				}
			} else {
				PHALCON_SET_STRING(t15, "", 1);
				PHALCON_IDENTICAL_FUNCTION(r25, v10, t15);
				PHALCON_INIT_NULL(t16);
				PHALCON_IDENTICAL_FUNCTION(r26, v10, t16);
				PHALCON_OR_FUNCTION(r27, r25, r26);
				if(zend_is_true(r27)){
					PHALCON_SET_STRING(t17, "NULL", 1);
					PHALCON_ARRAPPEND(v20, t17);
				} else {
					PHALCON_ARRFETCH_SILENT(r28, v4, v9);
					if(zend_is_true(r28)){
						PHALCON_CPY_WRT(t18, v10);
						PHALCON_ARRAPPEND(v20, t18);
					} else {
						PHALCON_ARRFETCH_NOISY(r29, v17, v9);
						if(phalcon_compare_strict_string(r29, "date")){
							PHALCON_PARAM_CPY(p38[0], v10);
							PHALCON_CALL_METHOD_PARAMS(r30, v16, "getdateusingformat", 1, p38, PHALCON_CALL_DEFAULT);
							PHALCON_ARRAPPEND(v20, r30);
						} else {
							phalcon_concat_both(&r31,  "'", v10, "'" TSRMLS_CC);
							PHALCON_ARRAPPEND(v20, r31);
						}
					}
				}
			}
		END_FOREACH(ac0, fes36, fee36, ah0, hp0);
		PHALCON_PARAM_CPY(p39[0], v15);
		PHALCON_PARAM_CPY(p39[1], v19);
		PHALCON_PARAM_CPY(p39[2], v20);
		PHALCON_READ_PROPERTY_NOISY(t19, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1);
		PHALCON_PARAM_ZVAL(p39[3], t19);
		PHALCON_CALL_METHOD_PARAMS(v22, v16, "update", 4, p39, PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_INIT_ARRAY(v19);
		PHALCON_INIT_ARRAY(v20);
		PHALCON_CALL_METHOD(v23, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		FOREACH_V(v23, ac1, fes37, fee37, ah1, hp1, v9)
			if(!phalcon_compare_strict_string(v9, "id")){
				PHALCON_CPY_WRT(t20, v9);
				PHALCON_ARRAPPEND(v19, t20);
				convert_to_string(v9);
				PHALCON_READ_PROPERTY_NOISY(t21, this_ptr, Z_STRVAL_P(v9), Z_STRLEN_P(v9));
				PHALCON_CPY_WRT(v10, t21);
				if(Z_TYPE_P(v10)==IS_OBJECT){
					PHALCON_INSTANCE_OF(r32, v10, phalcon_db_rawvalue_class_entry);
					if(zend_is_true(r32)){
						PHALCON_CALL_METHOD(r33, v10, "getvalue", PHALCON_CALL_DEFAULT);
						PHALCON_ARRAPPEND(v20, r33);
					} else {
						convert_to_string(v10);
						PHALCON_CPY_WRT(t22, v10);
						PHALCON_ARRAPPEND(v20, t22);
					}
				} else {
					PHALCON_SET_STRING(t23, "", 1);
					PHALCON_IDENTICAL_FUNCTION(r34, v10, t23);
					PHALCON_INIT_NULL(t24);
					PHALCON_IDENTICAL_FUNCTION(r35, v10, t24);
					PHALCON_OR_FUNCTION(r36, r34, r35);
					if(zend_is_true(r36)){
						PHALCON_SET_STRING(t25, "NULL", 1);
						PHALCON_ARRAPPEND(v20, t25);
					} else {
						PHALCON_ARRFETCH_SILENT(r37, v4, v9);
						if(zend_is_true(r37)){
							PHALCON_CPY_WRT(t26, v10);
							PHALCON_ARRAPPEND(v20, t26);
						} else {
							PHALCON_ARRFETCH_NOISY(r38, v17, v9);
							if(phalcon_compare_strict_string(r38, "date")){
								PHALCON_READ_PROPERTY_NOISY(t27, this_ptr, "_connection", sizeof("_connection")-1);
								PHALCON_PARAM_CPY(p42[0], v10);
								PHALCON_CALL_METHOD_PARAMS(r39, t27, "getdateusingformat", 1, p42, PHALCON_CALL_DEFAULT);
								PHALCON_ARRAPPEND(v20, r39);
							} else {
								phalcon_concat_both(&r40,  "'", v10, "'" TSRMLS_CC);
								PHALCON_ARRAPPEND(v20, r40);
							}
						}
					}
				}
			}
		END_FOREACH(ac1, fes37, fee37, ah1, hp1);
		PHALCON_SET_STRING(v24, "", 1);
		if(!zend_is_true(v2)){
			PHALCON_PARAM_CPY(p43[0], v18);
			PHALCON_CALL_FUNC_PARAMS(r41, "count", 1, p43);
			PHALCON_SET_LONG(t28, 1);
			PHALCON_EQUAL_FUNCTION(r42, r41, t28);
			if(zend_is_true(r42)){
				PHALCON_READ_PROPERTY_SILENT(t29, this_ptr, "id", sizeof("id")-1);
				if(zend_is_true(t29)){
					PHALCON_SET_STRING(t30, "id", 1);
					PHALCON_ARRAPPEND(v19, t30);
					PHALCON_ARRAPPEND(v20, t29);
				}
			}
		} else {
			PHALCON_READ_PROPERTY_SILENT(t31, this_ptr, "id", sizeof("id")-1);
			if(zend_is_true(t31)){
				PHALCON_SET_STRING(t32, "id", 1);
				PHALCON_ARRAPPEND(v19, t32);
				PHALCON_ARRAPPEND(v20, t31);
			}
		}
		PHALCON_READ_PROPERTY_NOISY(t33, this_ptr, "_connection", sizeof("_connection")-1);
		PHALCON_PARAM_CPY(p44[0], v15);
		PHALCON_PARAM_CPY(p44[1], v20);
		PHALCON_PARAM_CPY(p44[2], v19);
		PHALCON_CALL_METHOD_PARAMS(v22, t33, "insert", 3, p44, PHALCON_CALL_DEFAULT);
	}
	PHALCON_CALL_METHOD(r43, v16, "isundertransaction", PHALCON_CALL_DEFAULT);
	if(!zend_is_true(r43)){
		PHALCON_CALL_METHOD(r44, v16, "gethaveautocommit", PHALCON_CALL_DEFAULT);
		if(zend_is_true(r44)){
			PHALCON_CALL_METHOD_NORETURN(v16, "commit", PHALCON_CALL_DEFAULT);
		}
	}
	if(zend_is_true(v22)){
		if(zend_is_true(v0)){
			if(!zend_is_true(v1)){
				PHALCON_PARAM_STRING(p48[0], "afterUpdate", 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p48, PHALCON_CALL_DEFAULT);
			}
		} else {
			if(!zend_is_true(v1)){
				PHALCON_PARAM_STRING(p49[0], "afterCreate", 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p49, PHALCON_CALL_DEFAULT);
			}
		}
		if(!zend_is_true(v1)){
			PHALCON_PARAM_STRING(p50[0], "afterSave", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p50, PHALCON_CALL_DEFAULT);
		}
		RETURN_ZVAL(v22, 0, 0);
	} else {
		if(!zend_is_true(v1)){
			PHALCON_PARAM_STRING(p51[0], "notSave", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p51, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, delete){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *s0 = NULL;
	zval *ac0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_schema", sizeof("_schema")-1);
	if(zend_is_true(t0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_schema", sizeof("_schema")-1);
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_source", sizeof("_source")-1);
		phalcon_concat_vboth(&r0, t1, ".", t2 TSRMLS_CC);
		PHALCON_CPY_WRT(v0, r0);
	} else {
		PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_source", sizeof("_source")-1);
		PHALCON_CPY_WRT(v0, t3);
	}
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_base_class_entry, "OP_DELETE");
	PHALCON_CPY_WRT(s0, t4);
	phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), s0 TSRMLS_CC);
	PHALCON_CALL_METHOD(v1, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_CPY(p2[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p2);
	PHALCON_SET_LONG(t5, 1);
	PHALCON_EQUAL_FUNCTION(r2, r1, t5);
	if(zend_is_true(r2)){
		PHALCON_ARRFETCH_LONG_NOISY(r3, v1, 0);
		convert_to_string(r3);
		PHALCON_READ_PROPERTY_NOISY(t6, this_ptr, Z_STRVAL_P(r3), Z_STRLEN_P(r3));
		PHALCON_CPY_WRT(v2, t6);
		PHALCON_ARRFETCH_LONG_NOISY(r5, v1, 0);
		phalcon_concat_vboth(&r4, r5, " = '", v2 TSRMLS_CC);
		phalcon_concat_right(&r6, r4, "'" TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r6);
	} else {
		PHALCON_INIT_ARRAY(v3);
		FOREACH_V(v1, ac0, fes38, fee38, ah0, hp0, v4)
			convert_to_string(v4);
			PHALCON_READ_PROPERTY_NOISY(t7, this_ptr, Z_STRVAL_P(v4), Z_STRLEN_P(v4));
			PHALCON_CPY_WRT(v2, t7);
			phalcon_concat_vboth(&r7, v4, " = '", v2 TSRMLS_CC);
			phalcon_concat_right(&r8, r7, "'" TSRMLS_CC);
			PHALCON_ARRAPPEND(v3, r8);
		END_FOREACH(ac0, fes38, fee38, ah0, hp0);
		PHALCON_PARAM_STRING(p3[0], " AND ", 0);
		PHALCON_PARAM_CPY(p3[1], v3);
		PHALCON_CALL_FUNC_PARAMS(v3, "join", 2, p3);
	}
	t8 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t8);
	if(!zend_is_true(v5)){
		PHALCON_PARAM_STRING(p4[0], "beforeDelete", 0);
		PHALCON_CALL_METHOD_PARAMS(r9, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
		if(Z_TYPE_P(r9)==IS_BOOL&&!Z_BVAL_P(r9)){
			RETURN_FALSE;
		}
	}
	PHALCON_READ_PROPERTY_NOISY(t9, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_PARAM_CPY(p5[0], v0);
	PHALCON_PARAM_CPY(p5[1], v3);
	PHALCON_CALL_METHOD_PARAMS(v6, t9, "delete", 2, p5, PHALCON_CALL_DEFAULT);
	if(zend_is_true(v6)){
		if(!zend_is_true(v5)){
			PHALCON_PARAM_STRING(p6[0], "afterDelete", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
		}
	}
	RETURN_ZVAL(v6, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, readAttribute){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_dump", sizeof("_dump")-1);
	if(!zend_is_true(t0)){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	convert_to_string(v0);
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0));
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_Base, writeAttribute){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_dumped", sizeof("_dumped")-1);
	if(!zend_is_true(t0)){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	PHALCON_CPY_WRT(s0, v1);
	phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *s0 = NULL, *s1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), s0 TSRMLS_CC);
	PHALCON_CPY_WRT(s1, v1);
	phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), s1 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	if(Z_TYPE_P(t0)==IS_BOOL&&!Z_BVAL_P(t0)){
		RETURN_FALSE;
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_model", sizeof("_model")-1);
	PHALCON_CALL_METHOD(v0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_class_entry, "DB_ASSOC");
	PHALCON_PARAM_ZVAL(p1[0], t2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	PHALCON_PARAM_ZVAL(p2[0], t3);
	PHALCON_CALL_METHOD_PARAMS(v1, v0, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
	if(zend_is_true(v1)){
		PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, "_activeRow", sizeof("_activeRow")-1);
		PHALCON_PARAM_ZVAL(p3[0], t4);
		PHALCON_CALL_FUNC_PARAMS(r0, "is_object", 1, p3);
		if(zend_is_true(r0)){
			//Unset?
		}
		PHALCON_READ_PROPERTY_NOISY(t5, this_ptr, "_model", sizeof("_model")-1);
		PHALCON_PARAM_CPY(p4[0], v1);
		PHALCON_CALL_METHOD_PARAMS(r1, t5, "dumpresult", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), r1 TSRMLS_CC);
		RETURN_TRUE;
	} else {
		PHALCON_GET_CLASS_CONSTANT(t6, phalcon_db_class_entry, "DB_BOTH");
		PHALCON_PARAM_ZVAL(p5[0], t6);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setfetchmode", 1, p5, PHALCON_CALL_DEFAULT);
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, current){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_activeRow", sizeof("_activeRow")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Resultset, next){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_pointer", sizeof("_pointer")-1);
	increment_function(t0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, key){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_pointer", sizeof("_pointer")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Resultset, rewind){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *p1[] = { NULL, NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	if(Z_TYPE_P(t0)==IS_BOOL&&!Z_BVAL_P(t0)){
		RETURN_FALSE;
	}
	phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_model", sizeof("_model")-1);
	PHALCON_CALL_METHOD(v0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_LONG(p1[0], 0);
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	PHALCON_PARAM_ZVAL(p1[1], t2);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *v0 = NULL, *v1 = NULL;
	zval *s0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	convert_to_long(v0);
	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), s0 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_model", sizeof("_model")-1);
	PHALCON_CALL_METHOD(v1, t0, "getconnection", PHALCON_CALL_DEFAULT);
	convert_to_long(v0);
	PHALCON_PARAM_ZVAL(p1[0], v0);
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	PHALCON_PARAM_ZVAL(p1[1], t1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	if(Z_TYPE_P(t0)==IS_BOOL&&!Z_BVAL_P(t0)){
		RETURN_LONG(0);
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_count", sizeof("_count")-1);
	PHALCON_PARAM_ZVAL(p0[0], t1);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	if(zend_is_true(r0)){
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_model", sizeof("_model")-1);
		PHALCON_CALL_METHOD(v0, t2, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_READ_PROPERTY_NOISY(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1);
		PHALCON_PARAM_ZVAL(p2[0], t3);
		PHALCON_CALL_METHOD_PARAMS(r1, v0, "numrows", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), r1 TSRMLS_CC);
	}
	PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, "_count", sizeof("_count")-1);
	RETURN_ZVAL(t4, 0, 0);
}

PHP_METHOD(Phalcon_Model_Resultset, offsetExists){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	PHALCON_SMALLER_FUNCTION(r1, v0, r0);
	if(zend_is_true(r1)){
		RETURN_TRUE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, offsetGet){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p4[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	PHALCON_SMALLER_FUNCTION(r1, v0, r0);
	if(zend_is_true(r1)){
		PHALCON_PARAM_CPY(p1[0], v0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p1, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if(zend_is_true(r2)){
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r3, 0, 0);
		} else {
			RETURN_FALSE;
		}
	} else {
		PHALCON_NEW(i0, phalcon_model_exception_class_entry);
		PHALCON_PARAM_STRING(p4[0], "The index does not exist in the cursor", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, offsetSet){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_NEW(i0, phalcon_model_exception_class_entry);
	PHALCON_PARAM_STRING(p0[0], "Cursor is read only", 0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
}

PHP_METHOD(Phalcon_Model_Resultset, offsetUnset){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_NEW(i0, phalcon_model_exception_class_entry);
	PHALCON_PARAM_STRING(p0[0], "Cursor is read only", 0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
}

PHP_METHOD(Phalcon_Model_Resultset, getFirst){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_pointer", sizeof("_pointer")-1);
	PHALCON_SET_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	if(zend_is_true(r0)){
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_CALL_DEFAULT);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	PHALCON_INIT_FALSE(t3);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, t2, t3);
	if(zend_is_true(r1)){
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if(zend_is_true(r2)){
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r3, 0, 0);
		} else {
			RETURN_FALSE;
		}
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, getLast){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r0, t0, t1);
	if(zend_is_true(r0)){
		PHALCON_CALL_METHOD(r1, this_ptr, "count", PHALCON_CALL_DEFAULT);
		PHALCON_SET_LONG(t2, 1);
		PHALCON_SUB_FUNCTION(r2, r1, t2);
		PHALCON_PARAM_ZVAL(p0[0], r2);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(r3, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if(zend_is_true(r3)){
			PHALCON_CALL_METHOD(r4, this_ptr, "current", PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r4, 0, 0);
		} else {
			RETURN_FALSE;
		}
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Resultset, getModel){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_model", sizeof("_model")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Resultset, each){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p3[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_CALL_DEFAULT);
	ws39:
	PHALCON_CALL_METHOD(r0, this_ptr, "valid", PHALCON_CALL_DEFAULT);
	if(!zend_is_true(r0)){
		goto we39;
	}
	PHALCON_CALL_METHOD(v1, this_ptr, "current", PHALCON_CALL_DEFAULT);
	//No string fn name
	PHALCON_PARAM_CPY(p3[0], v1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("lol", 1, p3);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "next", PHALCON_CALL_DEFAULT);
	goto ws39;
	we39:
	r0 = NULL;
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *s0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_INIT_ARRAY(a0);
	zend_update_property(phalcon_model_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), a0 TSRMLS_CC);
	PHALCON_INIT_ARRAY(a1);
	zend_update_property(phalcon_model_transaction_class_entry, this_ptr, "_messages", strlen("_messages"), a1 TSRMLS_CC);
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	PHALCON_INIT_TRUE(t0);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_pool", "getconnection", 1, p0);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_CPY_WRT(s0, v1);
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), s0 TSRMLS_CC);
	PHALCON_INIT_TRUE(t1);
	PHALCON_EQUAL_FUNCTION(r1, v0, t1);
	if(zend_is_true(r1)){
		PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_connection", sizeof("_connection")-1);
		PHALCON_CALL_METHOD_NORETURN(t2, "begin", PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, setTransactionManager){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, begin){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CALL_METHOD(r0, t0, "begin", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Transaction, commit){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	if(!phalcon_compare_strict_string(t0, "")){
		PHALCON_INIT_ARRAY(a0);
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_manager", sizeof("_manager")-1);
		add_next_index_zval(a0, t1);
		add_next_index_string(a0, "notifyCommit", 1);
		PHALCON_PARAM_ZVAL(p0[0], a0);
		PHALCON_INIT_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		PHALCON_PARAM_ZVAL(p0[1], a1);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p0);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CALL_METHOD(r0, t2, "commit", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Transaction, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	zval *s0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL, NULL };
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	if(!phalcon_compare_strict_string(t0, "")){
		PHALCON_INIT_ARRAY(a0);
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_manager", sizeof("_manager")-1);
		add_next_index_zval(a0, t1);
		add_next_index_string(a0, "notifyRollback", 1);
		PHALCON_PARAM_ZVAL(p0[0], a0);
		PHALCON_INIT_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		PHALCON_PARAM_ZVAL(p0[1], a1);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p0);
	}
	PHALCON_READ_PROPERTY_NOISY(t2, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CALL_METHOD(v2, t2, "rollback", PHALCON_CALL_DEFAULT);
	PHALCON_INIT_TRUE(t3);
	PHALCON_EQUAL_FUNCTION(r0, v2, t3);
	if(zend_is_true(r0)){
		if(phalcon_compare_strict_string(v0, "")){
			PHALCON_SET_STRING(v0, "Transaction aborted", 1);
		}
		if(Z_TYPE_P(v1)!=IS_NULL){
			PHALCON_CPY_WRT(s0, v1);
			phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), s0 TSRMLS_CC);
		}
		ce0 = zend_fetch_class("phalcon_transactionfailed", strlen("phalcon_transactionfailed"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_NEW(i0, ce0);
		PHALCON_PARAM_CPY(p2[0], v0);
		PHALCON_READ_PROPERTY_NOISY(t4, this_ptr, "_rollbackRecord", sizeof("_rollbackRecord")-1);
		PHALCON_PARAM_ZVAL(p2[1], t4);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1);
	if(zend_is_true(t0)){
		PHALCON_CALL_FUNC(r0, "connection_aborted");
		if(zend_is_true(r0)){
			PHALCON_PARAM_STRING(p1[0], "The request was aborted", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "rollback", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_connection", sizeof("_connection")-1);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Model_Transaction, setIsNewTransaction){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_isNewTransaction", strlen("_isNewTransaction"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, setRollbackOnAbort){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_rollbackOnAbort", strlen("_rollbackOnAbort"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, isManaged){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_manager", sizeof("_manager")-1);
	PHALCON_INIT_NULL(t1);
	PHALCON_EQUAL_FUNCTION(r1, t0, t1);
	if(zend_is_true(r1)){
		PHALCON_INIT_FALSE(t2);
		r0 = t2;
	} else {
		PHALCON_INIT_TRUE(t3);
		r0 = t3;
	}
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Transaction, setDependencyPointer){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, attachDependency){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_INIT_NULL(t0);
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	if(zend_is_true(r0)){
		PHALCON_READ_PROPERTY_NOISY(t1, this_ptr, "_pointer", sizeof("_pointer")-1);
		increment_function(t1);
		PHALCON_CPY_WRT(v0, t1);
		PHALCON_READ_PROPERTY_SILENT(t2, this_ptr, "_dependencies", sizeof("_dependencies")-1);
		PHALCON_CPY_WRT(t3, v1);
		PHALCON_ARRUPDATE(t2, v0, t3);
		zend_update_property(phalcon_model_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), t2 TSRMLS_CC);
		RETURN_ZVAL(v0, 0, 0);
	} else {
		PHALCON_READ_PROPERTY_SILENT(t4, this_ptr, "_dependencies", sizeof("_dependencies")-1);
		PHALCON_ARRFETCH_SILENT(r1, t4, v0);
		if(!zend_is_true(r1)){
			PHALCON_CPY_WRT(t5, v1);
			PHALCON_ARRUPDATE(t4, v0, t5);
			zend_update_property(phalcon_model_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), t4 TSRMLS_CC);
			RETURN_ZVAL(v0, 0, 0);
		} else {
			PHALCON_READ_PROPERTY_NOISY(t6, this_ptr, "_pointer", sizeof("_pointer")-1);
			increment_function(t6);
			PHALCON_CPY_WRT(v0, t6);
			PHALCON_READ_PROPERTY_SILENT(t7, this_ptr, "_dependencies", sizeof("_dependencies")-1);
			PHALCON_CPY_WRT(t8, v1);
			PHALCON_ARRUPDATE(t7, v0, t8);
			zend_update_property(phalcon_model_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), t7 TSRMLS_CC);
			RETURN_ZVAL(v0, 0, 0);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction, save){

	zval *a0 = NULL;
	zval *s0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *ac0 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_INIT_ARRAY(a0);
	PHALCON_CPY_WRT(s0, a0);
	phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), s0 TSRMLS_CC);
	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_dependencies", sizeof("_dependencies")-1);
	FOREACH_V(t0, ac0, fes40, fee40, ah0, hp0, v0)
		PHALCON_CALL_METHOD(r0, v0, "save", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_FALSE(t1);
		PHALCON_EQUAL_FUNCTION(r1, r0, t1);
		if(zend_is_true(r1)){
			PHALCON_CALL_METHOD(r2, v0, "getmessages", PHALCON_CALL_DEFAULT);
			phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), r2 TSRMLS_CC);
			RETURN_FALSE;
		}
	END_FOREACH(ac0, fes40, fee40, ah0, hp0);
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Transaction, getMessages){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_messages", sizeof("_messages")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Transaction, isValid){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_connection", sizeof("_connection")-1);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Model_Transaction, setRollbackedRecord){

	zval *v0 = NULL;
	zval *s0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v0);
	phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), s0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction_Failed, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *s0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(s0, v1);
	phalcon_update_property_zval(this_ptr, "_record", strlen("_record"), s0 TSRMLS_CC);
	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_PARAM_LONG(p0[1], 0);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Model_Transaction_Failed", "__construct", 2, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction_Failed, getRecordMessages){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_record", sizeof("_record")-1);
	PHALCON_CPY_WRT(v0, t0);
	if(Z_TYPE_P(v0)!=IS_NULL){
		PHALCON_CALL_METHOD(r0, v0, "getmessages", PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 0, 0);
	} else {
		PHALCON_CALL_METHOD(r1, this_ptr, "_getmessage", PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r1, 0, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Transaction_Failed, getRecord){

	zval *t0 = NULL;

	PHALCON_READ_PROPERTY_NOISY(t0, this_ptr, "_record", sizeof("_record")-1);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Transactions, hasUserTransaction){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };

	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	PHALCON_SET_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r1, t1, r0);
	RETURN_ZVAL(r1, 0, 0);
}

PHP_METHOD(Phalcon_Transactions, get){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_BOOL(v0, 1);
	}
	
	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_initialized", sizeof("_initialized")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if(zend_is_true(t0)){
		PHALCON_INIT_ARRAY(a0);
		add_next_index_string(a0, "Phalcon_Transactions", 1);
		add_next_index_string(a0, "rollbackPendent", 1);
		PHALCON_PARAM_ZVAL(p0[0], a0);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("register_shutdown_function", 1, p0);
		PHALCON_INIT_TRUE(t1);
		zend_update_static_property(phalcon_transactions_class_entry, "_initialized", sizeof("_initialized")-1, t1 TSRMLS_CC);
	}
	t2 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_PARAM_ZVAL(p1[0], t2);
	PHALCON_CALL_FUNC_PARAMS(v1, "count", 1, p1);
	if(!zend_is_true(v1)){
		ce0 = zend_fetch_class("phalcon_transaction", strlen("phalcon_transaction"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_NEW(i0, ce0);
		PHALCON_PARAM_CPY(p2[0], v0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v2, i0);
		PHALCON_PARAM_STRING(p3[0], "Phalcon_Transactions", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "settransactionmanager", 1, p3, PHALCON_CALL_DEFAULT);
		t3 = zend_read_static_property(phalcon_transactions_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p4[0], t3);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setdependencypointer", 1, p4, PHALCON_CALL_DEFAULT);
		t4 = zend_read_static_property(phalcon_transactions_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_SET_LONG(t5, 2048);
		PHALCON_ADD_FUNCTION(r0, t4, t5);
		zend_update_static_property(phalcon_transactions_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, r0 TSRMLS_CC);
		t6 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if(Z_TYPE_P(t6)!=IS_ARRAY){
			array_init(t6);
		}
		PHALCON_INIT_NULL(t7);
		PHALCON_ARRUPDATE(t6, t7, v2);
		zend_update_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, t6 TSRMLS_CC);
		
	} else {
		t8 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_SET_LONG(t10, 1);
		PHALCON_SUB_FUNCTION(r1, v1, t10);
		PHALCON_ARRFETCH_NOISY(t9, t8, r1);
		PHALCON_CPY_WRT(v2, t9);
		PHALCON_INIT_FALSE(t11);
		PHALCON_PARAM_ZVAL(p5[0], t11);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setisnewtransaction", 1, p5, PHALCON_CALL_DEFAULT);
	}
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Transactions, rollbackPendent){


	PHALCON_CALL_STATIC_NORETURN("self", "rollback");
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, commit){

	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	FOREACH_V(t0, ac0, fes41, fee41, ah0, hp0, v0)
		PHALCON_CALL_METHOD(v1, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(r0, v1, "isundertransaction", PHALCON_CALL_DEFAULT);
		if(zend_is_true(r0)){
			PHALCON_CALL_METHOD_NORETURN(v1, "commit", PHALCON_CALL_DEFAULT);
		}
	END_FOREACH(ac0, fes41, fee41, ah0, hp0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL;
	zval *p4[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	FOREACH_V(t0, ac0, fes42, fee42, ah0, hp0, v1)
		PHALCON_CALL_METHOD(v2, v1, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(r0, v2, "isundertransaction", PHALCON_CALL_DEFAULT);
		if(zend_is_true(r0)){
			PHALCON_CALL_METHOD_NORETURN(v2, "rollback", PHALCON_CALL_DEFAULT);
			PHALCON_CALL_METHOD_NORETURN(v2, "close", PHALCON_CALL_DEFAULT);
		}
		if(zend_is_true(v0)){
			PHALCON_PARAM_CPY(p4[0], v1);
			PHALCON_CALL_STATIC_PARAMS_NORETURN("self", "_collecttransaction", 1, p4);
		}
	END_FOREACH(ac0, fes42, fee42, ah0, hp0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, notifyRollback){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_STATIC_PARAMS_NORETURN("self", "_collecttransaction", 1, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, notifyCommit){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v0);
	PHALCON_CALL_STATIC_PARAMS_NORETURN("self", "_collecttransaction", 1, p0);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, _collectTransaction){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	PHALCON_SET_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r1, t1, r0);
	if(zend_is_true(r1)){
		PHALCON_SET_LONG(v1, 0);
		t2 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		FOREACH_V(t2, ac0, fes43, fee43, ah0, hp0, v2)
			PHALCON_EQUAL_FUNCTION(r2, v2, v0);
			if(zend_is_true(r2)){
				//Unset?
				//Unset?
			}
			increment_function(v1);
		END_FOREACH(ac0, fes43, fee43, ah0, hp0);
		PHALCON_INIT_ARRAY(v3);
		t3 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		FOREACH_V(t3, ac1, fes44, fee44, ah1, hp1, v2)
			PHALCON_CPY_WRT(t4, v2);
			PHALCON_ARRAPPEND(v3, t4);
		END_FOREACH(ac1, fes44, fee44, ah1, hp1);
		zend_update_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, v3 TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, collectTransactions){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_PARAM_ZVAL(p0[0], t0);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	PHALCON_SET_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r1, t1, r0);
	if(zend_is_true(r1)){
		PHALCON_SET_LONG(v0, 0);
		t2 = zend_read_static_property(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		FOREACH_V(t2, ac0, fes45, fee45, ah0, hp0, v1)
			//Unset?
			//Unset?
			increment_function(v0);
		END_FOREACH(ac0, fes45, fee45, ah0, hp0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transactions, isAutomatic){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_NULL(t1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Transactions, getAutomaticTransaction){

	zval *t0 = NULL;

	t0 = zend_read_static_property(phalcon_transactions_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	RETURN_ZVAL(t0, 0, 0);
}

PHP_METHOD(Phalcon_Tag, setRouter){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_tag_class_entry, "_router", sizeof("_router")-1, v0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, _getRouter){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_router", sizeof("_router")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if(!zend_is_true(t0)){
		PHALCON_CALL_STATIC(r2, "phalcon_controller_front", "getinstance");
		PHALCON_CALL_METHOD(r1, r2, "getdispatcher", PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD(r0, r1, "getrouter", PHALCON_CALL_DEFAULT);
		zend_update_static_property(phalcon_tag_class_entry, "_router", sizeof("_router")-1, r0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_tag_class_entry, "_router", sizeof("_router")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	RETURN_ZVAL(t1, 0, 0);
}

PHP_METHOD(Phalcon_Tag, displayTo){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_PARAM_CPY(p0[0], v1);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_scalar", 1, p0);
	if(!zend_is_true(r0)){
		PHALCON_NEW(i0, phalcon_tag_exception_class_entry);
		PHALCON_PARAM_STRING(p1[0], "Only scalar values​can be assigned to UI components", 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if(Z_TYPE_P(t0)!=IS_ARRAY){
		array_init(t0);
	}
	PHALCON_ARRUPDATE(t0, v0, v1);
	zend_update_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, t0 TSRMLS_CC);
	
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, _getValueFromAction){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ARRFETCH_SILENT(t1, t0, v0);
	if(zend_is_true(t1)){
		t2 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ARRFETCH_NOISY(t3, t2, v0);
		RETURN_ZVAL(t3, 0, 0);
	} else {
		PHALCON_GET_GLOBAL(a0, "_POST", gv0);
		PHALCON_ARRFETCH_SILENT(r0, a0, v0);
		if(zend_is_true(r0)){
			PHALCON_CALL_FUNC(r1, "get_magic_quotes_gpc");
			if(!zend_is_true(r1)){
				RETURN_ZVAL(r0, 0, 0);
			} else {
				PHALCON_ARRFETCH_NOISY(r3, a0, v0);
				PHALCON_PARAM_ZVAL(p1[0], r3);
				PHALCON_CALL_FUNC_PARAMS(r2, "stripslashes", 1, p1);
				RETURN_ZVAL(r2, 0, 0);
			}
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, linkTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_INIT_NULL(v1);
	}
	
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
		PHALCON_CPY_WRT(t1, v1);
		add_next_index_zval(v0, t1);
	}
	PHALCON_SET_STRING(v2, "", 1);
	PHALCON_ARRFETCH_LONG_SILENT(r0, v0, 0);
	if(zend_is_true(r0)){
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_ARRFETCH_STRING_SILENT(r1, v0, "action");
		if(zend_is_true(r1)){
			PHALCON_CPY_WRT(v2, r1);
			//Unset?
		}
	}
	PHALCON_SET_STRING(v1, "", 1);
	PHALCON_ARRFETCH_LONG_SILENT(r2, v0, 1);
	if(zend_is_true(r2)){
		PHALCON_CPY_WRT(v1, r2);
	} else {
		PHALCON_ARRFETCH_STRING_SILENT(r3, v0, "text");
		if(zend_is_true(r3)){
			PHALCON_CPY_WRT(v1, r3);
			//Unset?
		}
	}
	PHALCON_SET_STRING(v3, "", 1);
	if(!phalcon_compare_strict_string(v2, "")){
		PHALCON_ARRFETCH_STRING_SILENT(r4, v0, "confirm");
		if(zend_is_true(r4)){
			PHALCON_ARRFETCH_STRING_SILENT(r5, v0, "onclick");
			if(!zend_is_true(r5)){
				PHALCON_SET_STRING(t2, "", 1);
				phalcon_array_update_string(v0, "onclick", t2 TSRMLS_CC);
			}
			PHALCON_ARRFETCH_STRING_NOISY(r7, v0, "confirm");
			phalcon_concat_left(&r8, "if(!confirm('", r7 TSRMLS_CC);
			PHALCON_ARRFETCH_STRING_NOISY(r9, v0, "onclick");
			phalcon_concat_vboth(&r6, r8, "')) { return false; }; ", r9 TSRMLS_CC);
			phalcon_array_update_string(v0, "onclick", r6 TSRMLS_CC);
			//Unset?
		}
		PHALCON_PARAM_CPY(p0[0], v2);
		PHALCON_CALL_STATIC_PARAMS(r10, "phalcon_utils", "geturl", 1, p0);
		phalcon_concat_both(&r11,  "<a href=\"", r10, "\" " TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r11);
		FOREACH_KV(v0, ac0, fes46, fee46, ah0, hp0, v5, v4)
			if(Z_TYPE_P(v5)!=IS_LONG){
				phalcon_concat_left(&r13, " ", v5 TSRMLS_CC);
				phalcon_concat_vboth(&r12, r13, "=\"", v4 TSRMLS_CC);
				phalcon_concat_right(&r14, r12, "\" " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r15, v3, r14);
				PHALCON_CPY_WRT(v3, r15);
			}
		END_FOREACH(ac0, fes46, fee46, ah0, hp0);
		phalcon_concat_both(&r16,  ">", v1, "</a>" TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r17, v3, r16);
		PHALCON_CPY_WRT(v3, r17);
	}
	RETURN_ZVAL(v3, 0, 0);
}

PHP_METHOD(Phalcon_Tag, textField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
	}
	PHALCON_ARRFETCH_LONG_SILENT(r0, v0, 0);
	if(!zend_is_true(r0)){
		PHALCON_ARRFETCH_STRING_NOISY(r1, v0, "id");
		phalcon_array_update_long(v0, 0, r1 TSRMLS_CC);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r2, v0, "name");
	if(!zend_is_true(r2)){
		PHALCON_ARRFETCH_LONG_NOISY(r3, v0, 0);
		phalcon_array_update_string(v0, "name", r3 TSRMLS_CC);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r4, v0, "name");
		if(!zend_is_true(r4)){
			PHALCON_ARRFETCH_LONG_NOISY(r5, v0, 0);
			phalcon_array_update_string(v0, "name", r5 TSRMLS_CC);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r6, v0, "value");
	if(zend_is_true(r6)){
		PHALCON_CPY_WRT(v1, r6);
		//Unset?
	} else {
		PHALCON_ARRFETCH_LONG_NOISY(r8, v0, 0);
		PHALCON_PARAM_ZVAL(p0[0], r8);
		PHALCON_CALL_STATIC_PARAMS(r7, "self", "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v1, r7);
	}
	PHALCON_ARRFETCH_LONG_NOISY(r10, v0, 0);
	phalcon_concat_left(&r11, "<input type=\"text\" id=\"", r10 TSRMLS_CC);
	phalcon_concat_vboth(&r9, r11, "\" value=\"", v1 TSRMLS_CC);
	phalcon_concat_right(&r12, r9, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r12);
	FOREACH_KV(v0, ac0, fes47, fee47, ah0, hp0, v3, v1)
		if(Z_TYPE_P(v3)!=IS_LONG){
			phalcon_concat_vboth(&r13, v3, "=\"", v1 TSRMLS_CC);
			phalcon_concat_right(&r14, r13, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r15, v2, r14);
			PHALCON_CPY_WRT(v2, r15);
		}
	END_FOREACH(ac0, fes47, fee47, ah0, hp0);
	PHALCON_SET_STRING(t1, " />", 1);
	PHALCON_CONCAT_FUNCTION(r16, v2, t1);
	PHALCON_CPY_WRT(v2, r16);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Tag, submitButton){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "value");
	if(zend_is_true(r0)){
		PHALCON_CPY_WRT(v1, r0);
		//Unset?
	} else {
		PHALCON_ARRFETCH_LONG_SILENT(r1, v0, 0);
		if(zend_is_true(r1)){
			PHALCON_CPY_WRT(v1, r1);
		} else {
			PHALCON_SET_STRING(v1, "", 1);
		}
	}
	phalcon_concat_both(&r2,  "<input type=\"submit\" value=\"", v1, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r2);
	FOREACH_KV(v0, ac0, fes48, fee48, ah0, hp0, v3, v1)
		if(Z_TYPE_P(v3)!=IS_LONG){
			phalcon_concat_vboth(&r3, v3, "=\"", v1 TSRMLS_CC);
			phalcon_concat_right(&r4, r3, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r5, v2, r4);
			PHALCON_CPY_WRT(v2, r5);
		}
	END_FOREACH(ac0, fes48, fee48, ah0, hp0);
	PHALCON_SET_STRING(t1, " />", 1);
	PHALCON_CONCAT_FUNCTION(r6, v2, t1);
	PHALCON_CPY_WRT(v2, r6);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
		PHALCON_CPY_WRT(t1, v1);
		add_next_index_zval(v0, t1);
	}
	PHALCON_SET_STRING(v2, "", 1);
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "value");
	if(!zend_is_true(r0)){
		PHALCON_ARRFETCH_LONG_NOISY(r2, v0, 0);
		PHALCON_PARAM_ZVAL(p0[0], r2);
		PHALCON_CALL_STATIC_PARAMS(r1, "self", "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v2, r1);
		//Unset?
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r3, v0, "value");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_ARRFETCH_LONG_NOISY(r5, v0, 0);
	phalcon_concat_left(&r6, "<select id=\"", r5 TSRMLS_CC);
	PHALCON_ARRFETCH_LONG_NOISY(r7, v0, 0);
	phalcon_concat_vboth(&r4, r6, "\" name=\"", r7 TSRMLS_CC);
	phalcon_concat_right(&r8, r4, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r8);
	PHALCON_ARRFETCH_STRING_SILENT(r9, v0, "dummyValue");
	if(!zend_is_true(r9)){
		PHALCON_SET_STRING(v4, "@", 1);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r10, v0, "dummyValue");
		PHALCON_CPY_WRT(v4, r10);
		//Unset?
	}
	PHALCON_ARRFETCH_STRING_SILENT(r11, v0, "dummyText");
	if(!zend_is_true(r11)){
		PHALCON_SET_STRING(v5, "Choose...", 1);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r12, v0, "dummyText");
		PHALCON_CPY_WRT(v5, r12);
		//Unset?
	}
	FOREACH_KV(v0, ac0, fes49, fee49, ah0, hp0, v7, v6)
		if(Z_TYPE_P(v7)!=IS_LONG){
			if(Z_TYPE_P(v6)!=IS_ARRAY){
				phalcon_concat_vboth(&r13, v7, "=\"", v6 TSRMLS_CC);
				phalcon_concat_right(&r14, r13, "\" " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r15, v3, r14);
				PHALCON_CPY_WRT(v3, r15);
			}
		}
	END_FOREACH(ac0, fes49, fee49, ah0, hp0);
	PHALCON_GET_CONSTANT(t2, "PHP_EOL");
	phalcon_concat_left(&r16, ">", t2 TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r17, v3, r16);
	PHALCON_CPY_WRT(v3, r17);
	PHALCON_ARRFETCH_STRING_SILENT(r18, v0, "useDummy");
	if(zend_is_true(r18)){
		PHALCON_SET_STRING(t3, "	", 1);
		phalcon_concat_vboth(&r21, t3, "<option value=\"", v4 TSRMLS_CC);
		phalcon_concat_vboth(&r20, r21, "\">", v5 TSRMLS_CC);
		PHALCON_GET_CONSTANT(t4, "PHP_EOL");
		phalcon_concat_vboth(&r19, r20, "</option>", t4 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r22, v3, r19);
		PHALCON_CPY_WRT(v3, r22);
		//Unset?
	}
	PHALCON_ARRFETCH_LONG_SILENT(r23, v0, 1);
	if(zend_is_true(r23)){
		if(Z_TYPE_P(r23)==IS_ARRAY){
			FOREACH_KV(r23, ac1, fes50, fee50, ah1, hp1, v9, v8)
				PHALCON_EQUAL_FUNCTION(r24, v9, v2);
				PHALCON_SET_STRING(t5, "", 1);
				PHALCON_NOT_IDENTICAL_FUNCTION(r25, v2, t5);
				PHALCON_AND_FUNCTION(r26, r24, r25);
				if(zend_is_true(r26)){
					PHALCON_SET_STRING(t6, "	", 1);
					phalcon_concat_vboth(&r29, t6, "<option value=\"", v9 TSRMLS_CC);
					phalcon_concat_vboth(&r28, r29, "\" selected=\"selected\">", v8 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t7, "PHP_EOL");
					phalcon_concat_vboth(&r27, r28, "</option>", t7 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r30, v3, r27);
					PHALCON_CPY_WRT(v3, r30);
				} else {
					PHALCON_SET_STRING(t8, "	", 1);
					phalcon_concat_vboth(&r33, t8, "<option value=\"", v9 TSRMLS_CC);
					phalcon_concat_vboth(&r32, r33, "\">", v8 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t9, "PHP_EOL");
					phalcon_concat_vboth(&r31, r32, "</option>", t9 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r34, v3, r31);
					PHALCON_CPY_WRT(v3, r34);
				}
			END_FOREACH(ac1, fes50, fee50, ah1, hp1);
		} else {
			PHALCON_NEW(i0, phalcon_tag_exception_class_entry);
			PHALCON_PARAM_STRING(p1[0], "Data supplied for Phalcon_Tag::selectStatic is not valid", 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	}
	PHALCON_SET_STRING(t10, "</select>", 1);
	PHALCON_CONCAT_FUNCTION(r35, v3, t10);
	PHALCON_CPY_WRT(v3, r35);
	RETURN_ZVAL(v3, 0, 0);
}

PHP_METHOD(Phalcon_Tag, select){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL, *r48 = NULL;
	zval *r49 = NULL, *r50 = NULL, *r51 = NULL, *r52 = NULL, *r53 = NULL, *r54 = NULL, *r55 = NULL;
	zval *r56 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL }, *p12[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_SET_STRING(v1, "", 1);
	}
	
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
		PHALCON_CPY_WRT(t1, v1);
		add_next_index_zval(v0, t1);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "value");
	if(!zend_is_true(r0)){
		PHALCON_ARRFETCH_LONG_NOISY(r2, v0, 0);
		PHALCON_PARAM_ZVAL(p0[0], r2);
		PHALCON_CALL_STATIC_PARAMS(r1, "self", "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v2, r1);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r3, v0, "value");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_ARRFETCH_LONG_NOISY(r5, v0, 0);
	phalcon_concat_left(&r6, "<select id='", r5 TSRMLS_CC);
	PHALCON_ARRFETCH_LONG_NOISY(r7, v0, 0);
	phalcon_concat_vboth(&r4, r6, "' name='", r7 TSRMLS_CC);
	phalcon_concat_right(&r8, r4, "' " TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r8);
	if(Z_TYPE_P(v0)==IS_ARRAY){
		FOREACH_KV(v0, ac0, fes51, fee51, ah0, hp0, v4, v2)
			if(Z_TYPE_P(v4)!=IS_LONG){
				if(Z_TYPE_P(v2)!=IS_ARRAY){
					phalcon_concat_vboth(&r9, v4, "='", v2 TSRMLS_CC);
					phalcon_concat_right(&r10, r9, "' " TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r11, v3, r10);
					PHALCON_CPY_WRT(v3, r11);
				}
			}
		END_FOREACH(ac0, fes51, fee51, ah0, hp0);
	}
	PHALCON_GET_CONSTANT(t2, "PHP_EOL");
	phalcon_concat_left(&r12, ">", t2 TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r13, v3, r12);
	PHALCON_CPY_WRT(v3, r13);
	PHALCON_ARRFETCH_STRING_SILENT(r14, v0, "dummyValue");
	if(!zend_is_true(r14)){
		PHALCON_SET_STRING(v5, "", 1);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r15, v0, "dummyValue");
		PHALCON_CPY_WRT(v5, r15);
		//Unset?
	}
	PHALCON_ARRFETCH_STRING_SILENT(r16, v0, "dummyText");
	if(!zend_is_true(r16)){
		PHALCON_SET_STRING(v6, "Choose...", 1);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r17, v0, "dummyText");
		PHALCON_CPY_WRT(v6, r17);
		//Unset?
	}
	PHALCON_ARRFETCH_STRING_SILENT(r18, v0, "useDummy");
	if(zend_is_true(r18)){
		PHALCON_SET_STRING(t3, "	", 1);
		phalcon_concat_vboth(&r21, t3, "<option value=\"", v5 TSRMLS_CC);
		phalcon_concat_vboth(&r20, r21, "\">", v6 TSRMLS_CC);
		PHALCON_GET_CONSTANT(t4, "PHP_EOL");
		phalcon_concat_vboth(&r19, r20, "</option>", t4 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r22, v3, r19);
		PHALCON_CPY_WRT(v3, r22);
	}
	PHALCON_ARRFETCH_LONG_SILENT(r23, v0, 1);
	if(zend_is_true(r23)){
		if(zend_is_true(r23)){
			if(Z_TYPE_P(r23)==IS_OBJECT){
				PHALCON_ARRFETCH_STRING_SILENT(r24, v0, "using");
				if(!zend_is_true(r24)){
					PHALCON_NEW(i0, phalcon_tag_exception_class_entry);
					PHALCON_PARAM_STRING(p1[0], "The 'using' parameter is required", 0);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				} else {
					PHALCON_ARRFETCH_STRING_NOISY(r25, v0, "using");
					if(Z_TYPE_P(r25)!=IS_ARRAY){
						PHALCON_NEW(i1, phalcon_tag_exception_class_entry);
						PHALCON_PARAM_STRING(p2[0], "The 'using' parameter should be an Array", 0);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				}
				PHALCON_ARRFETCH_STRING_NOISY(r26, v0, "using");
				PHALCON_CPY_WRT(v7, r26);
				PHALCON_ARRFETCH_LONG_NOISY(r27, v0, 1);
				PHALCON_CPY_WRT(v8, r27);
				PHALCON_CALL_METHOD_NORETURN(v8, "rewind", PHALCON_CALL_DEFAULT);
				ws52:
				PHALCON_CALL_METHOD(r28, v8, "valid", PHALCON_CALL_DEFAULT);
				if(!zend_is_true(r28)){
					goto we52;
				}
				PHALCON_CALL_METHOD(v9, v8, "current", PHALCON_CALL_DEFAULT);
				PHALCON_ARRFETCH_LONG_NOISY(r30, v7, 0);
				PHALCON_PARAM_ZVAL(p6[0], r30);
				PHALCON_CALL_METHOD_PARAMS(r29, v9, "readattribute", 1, p6, PHALCON_CALL_DEFAULT);
				PHALCON_EQUAL_FUNCTION(r31, v2, r29);
				if(zend_is_true(r31)){
					PHALCON_SET_STRING(t5, "	", 1);
					PHALCON_ARRFETCH_LONG_NOISY(r36, v7, 0);
					PHALCON_PARAM_ZVAL(p7[0], r36);
					PHALCON_CALL_METHOD_PARAMS(r35, v9, "readattribute", 1, p7, PHALCON_CALL_DEFAULT);
					phalcon_concat_vboth(&r34, t5, "<option selected=\"selected\" value=\"", r35 TSRMLS_CC);
					PHALCON_ARRFETCH_LONG_NOISY(r38, v7, 1);
					PHALCON_PARAM_ZVAL(p8[0], r38);
					PHALCON_CALL_METHOD_PARAMS(r37, v9, "readattribute", 1, p8, PHALCON_CALL_DEFAULT);
					phalcon_concat_vboth(&r33, r34, "'>", r37 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t6, "PHP_EOL");
					phalcon_concat_vboth(&r32, r33, "</option>", t6 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r39, v3, r32);
					PHALCON_CPY_WRT(v3, r39);
				} else {
					PHALCON_SET_STRING(t7, "	", 1);
					PHALCON_ARRFETCH_LONG_NOISY(r44, v7, 0);
					PHALCON_PARAM_ZVAL(p9[0], r44);
					PHALCON_CALL_METHOD_PARAMS(r43, v9, "readattribute", 1, p9, PHALCON_CALL_DEFAULT);
					phalcon_concat_vboth(&r42, t7, "<option value=\"", r43 TSRMLS_CC);
					PHALCON_ARRFETCH_LONG_NOISY(r46, v7, 1);
					PHALCON_PARAM_ZVAL(p10[0], r46);
					PHALCON_CALL_METHOD_PARAMS(r45, v9, "readattribute", 1, p10, PHALCON_CALL_DEFAULT);
					phalcon_concat_vboth(&r41, r42, "\">", r45 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t8, "PHP_EOL");
					phalcon_concat_vboth(&r40, r41, "</option>", t8 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r47, v3, r40);
					PHALCON_CPY_WRT(v3, r47);
				}
				PHALCON_CALL_METHOD_NORETURN(v8, "next", PHALCON_CALL_DEFAULT);
				goto ws52;
				we52:
				r28 = NULL;
			} else {
				PHALCON_ARRFETCH_LONG_NOISY(r48, v0, 1);
				if(Z_TYPE_P(r48)==IS_ARRAY){
					PHALCON_ARRFETCH_LONG_NOISY(r49, v0, 1);
					FOREACH_V(r49, ac1, fes53, fee53, ah1, hp1, v9)
						PHALCON_SET_STRING(t9, "	", 1);
						PHALCON_ARRFETCH_LONG_NOISY(r53, v9, 0);
						phalcon_concat_vboth(&r52, t9, "<option value=\"", r53 TSRMLS_CC);
						PHALCON_ARRFETCH_LONG_NOISY(r54, v9, 1);
						phalcon_concat_vboth(&r51, r52, "\">", r54 TSRMLS_CC);
						PHALCON_GET_CONSTANT(t10, "PHP_EOL");
						phalcon_concat_vboth(&r50, r51, "</option>", t10 TSRMLS_CC);
						PHALCON_CONCAT_FUNCTION(r55, v3, r50);
						PHALCON_CPY_WRT(v3, r55);
					END_FOREACH(ac1, fes53, fee53, ah1, hp1);
				} else {
					PHALCON_NEW(i2, phalcon_tag_exception_class_entry);
					PHALCON_PARAM_STRING(p12[0], "Options value should be an Array or Object", 0);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p12, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i2 TSRMLS_CC);
					Z_ADDREF_P(i2);
					return;
				}
			}
		}
	}
	PHALCON_SET_STRING(t11, "</select>", 1);
	PHALCON_CONCAT_FUNCTION(r56, v3, t11);
	PHALCON_CPY_WRT(v3, r56);
	RETURN_ZVAL(v3, 0, 0);
}

PHP_METHOD(Phalcon_Tag, textArea){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
	}
	PHALCON_ARRFETCH_LONG_SILENT(r0, v0, 0);
	if(!zend_is_true(r0)){
		PHALCON_ARRFETCH_STRING_NOISY(r1, v0, "id");
		phalcon_array_update_long(v0, 0, r1 TSRMLS_CC);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r2, v0, "name");
	if(!zend_is_true(r2)){
		PHALCON_ARRFETCH_LONG_NOISY(r3, v0, 0);
		phalcon_array_update_string(v0, "name", r3 TSRMLS_CC);
	} else {
		PHALCON_ARRFETCH_STRING_NOISY(r4, v0, "name");
		if(!zend_is_true(r4)){
			PHALCON_ARRFETCH_LONG_NOISY(r5, v0, 0);
			phalcon_array_update_string(v0, "name", r5 TSRMLS_CC);
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r6, v0, "value");
	if(zend_is_true(r6)){
		PHALCON_CPY_WRT(v1, r6);
		//Unset?
	} else {
		PHALCON_ARRFETCH_LONG_NOISY(r8, v0, 0);
		PHALCON_PARAM_ZVAL(p0[0], r8);
		PHALCON_CALL_STATIC_PARAMS(r7, "self", "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v1, r7);
	}
	PHALCON_ARRFETCH_LONG_NOISY(r9, v0, 0);
	phalcon_concat_both(&r10,  "<textarea id=\"", r9, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r10);
	FOREACH_KV(v0, ac0, fes54, fee54, ah0, hp0, v4, v3)
		if(Z_TYPE_P(v4)!=IS_LONG){
			phalcon_concat_vboth(&r11, v4, "=\"", v3 TSRMLS_CC);
			phalcon_concat_right(&r12, r11, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r13, v2, r12);
			PHALCON_CPY_WRT(v2, r13);
		}
	END_FOREACH(ac0, fes54, fee54, ah0, hp0);
	phalcon_concat_both(&r14,  ">", v1, "</textarea>" TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r15, v2, r14);
	PHALCON_CPY_WRT(v2, r15);
	RETURN_ZVAL(v2, 0, 0);
}

PHP_METHOD(Phalcon_Tag, form){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *ac0 = NULL;
	zval *p1[] = { NULL, NULL }, *p5[] = { NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
	}
	PHALCON_CALL_STATIC(r0, "self", "_getrouter");
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_PARAM_STRING(p1[0], "/", 0);
	PHALCON_CALL_METHOD(r1, v1, "getparams", PHALCON_CALL_DEFAULT);
	PHALCON_PARAM_ZVAL(p1[1], r1);
	PHALCON_CALL_FUNC_PARAMS(v2, "join", 2, p1);
	PHALCON_ARRFETCH_LONG_SILENT(r2, v0, 0);
	if(!zend_is_true(r2)){
		PHALCON_ARRFETCH_STRING_SILENT(r3, v0, "action");
		if(zend_is_true(r3)){
			PHALCON_CPY_WRT(v3, r3);
		} else {
			PHALCON_CALL_METHOD(r5, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
			PHALCON_CALL_METHOD(r6, v1, "getactionname", PHALCON_CALL_DEFAULT);
			phalcon_concat_vboth(&r4, r5, "/", r6 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r4);
		}
	} else {
		PHALCON_ARRFETCH_LONG_NOISY(r7, v0, 0);
		PHALCON_CPY_WRT(v3, r7);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r8, v0, "method");
	if(!zend_is_true(r8)){
		PHALCON_SET_STRING(t1, "post", 1);
		phalcon_array_update_string(v0, "method", t1 TSRMLS_CC);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r9, v0, "confirm");
	if(zend_is_true(r9)){
		PHALCON_ARRFETCH_STRING_NOISY(r10, v0, "onsubmit");
		PHALCON_ARRFETCH_STRING_NOISY(r12, v0, "onsubmit");
		phalcon_concat_vboth(&r11, r12, ";if(!confirm(\"", r9 TSRMLS_CC);
		phalcon_concat_right(&r13, r11, "\")) { return false; }" TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r14, r10, r13);
		phalcon_array_update_string(v0, "onsubmit", r14 TSRMLS_CC);
		//Unset?
	}
	if(zend_is_true(v2)){
		PHALCON_PARAM_CPY(p5[0], v3);
		PHALCON_CALL_STATIC_PARAMS(r15, "phalcon_utils", "geturl", 1, p5);
		PHALCON_CPY_WRT(v3, r15);
	} else {
		phalcon_concat_vboth(&r17, v3, "/", v2 TSRMLS_CC);
		PHALCON_PARAM_ZVAL(p6[0], r17);
		PHALCON_CALL_STATIC_PARAMS(r16, "phalcon_utils", "geturl", 1, p6);
		PHALCON_CPY_WRT(v3, r16);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r18, v0, "parameters");
	if(zend_is_true(r18)){
		phalcon_concat_left(&r19, "?", r18 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r20, v3, r19);
		PHALCON_CPY_WRT(v3, r20);
	}
	phalcon_concat_both(&r21,  "<form action=\"", v3, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r21);
	FOREACH_KV(v0, ac0, fes55, fee55, ah0, hp0, v6, v5)
		if(Z_TYPE_P(v6)!=IS_LONG){
			phalcon_concat_vboth(&r22, v6, "= \"", v5 TSRMLS_CC);
			phalcon_concat_right(&r23, r22, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r24, v4, r23);
			PHALCON_CPY_WRT(v4, r24);
		}
	END_FOREACH(ac0, fes55, fee55, ah0, hp0);
	phalcon_concat_right(&r25, v4, ">" TSRMLS_CC);
	RETURN_ZVAL(r25, 0, 0);
}

PHP_METHOD(Phalcon_Tag, endForm){


	RETURN_STRING("</form>", 1);
}

PHP_METHOD(Phalcon_Tag, setTitle){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, v0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r0, t0, v0);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r0, v0, t0);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, getTitle){

	zval *t0 = NULL;
	zval *r0 = NULL;

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_concat_both(&r0,  "<title>", t0, "</title>" TSRMLS_CC);
	RETURN_ZVAL(r0, 0, 0);
}

PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_SET_STRING(v0, "", 1);
	}
	if(!v1){
		PHALCON_INIT_BOOL(v1, 1);
	}
	
	if(Z_TYPE_P(v0)!=IS_ARRAY){
		PHALCON_INIT_ARRAY(v0);
		PHALCON_CPY_WRT(t0, v0);
		add_next_index_zval(v0, t0);
		PHALCON_CPY_WRT(t1, v1);
		add_next_index_zval(v0, t1);
	}
	PHALCON_ARRFETCH_STRING_SILENT(r0, v0, "href");
	if(!zend_is_true(r0)){
		PHALCON_ARRFETCH_LONG_SILENT(r1, v0, 0);
		if(zend_is_true(r1)){
			phalcon_array_update_string(v0, "href", r1 TSRMLS_CC);
		} else {
			PHALCON_SET_STRING(t2, "", 1);
			phalcon_array_update_string(v0, "href", t2 TSRMLS_CC);
		}
	}
	PHALCON_SET_STRING(v1, "", 1);
	PHALCON_ARRFETCH_LONG_SILENT(r2, v0, 1);
	if(zend_is_true(r2)){
		PHALCON_CPY_WRT(v1, r2);
	} else {
		PHALCON_ARRFETCH_STRING_SILENT(r3, v0, "local");
		if(zend_is_true(r3)){
			PHALCON_CPY_WRT(v1, r3);
			//Unset?
		}
	}
	PHALCON_ARRFETCH_STRING_SILENT(r4, v0, "type");
	if(!zend_is_true(r4)){
		PHALCON_SET_STRING(t3, "text/css", 1);
		phalcon_array_update_string(v0, "type", t3 TSRMLS_CC);
	}
	if(zend_is_true(v1)){
		PHALCON_ARRFETCH_STRING_NOISY(r6, v0, "href");
		PHALCON_PARAM_ZVAL(p0[0], r6);
		PHALCON_CALL_STATIC_PARAMS(r5, "phalcon_utils", "geturl", 1, p0);
		phalcon_array_update_string(v0, "href", r5 TSRMLS_CC);
	}
	PHALCON_SET_STRING(v2, "<link rel=\"stylesheet\" ", 1);
	FOREACH_KV(v0, ac0, fes56, fee56, ah0, hp0, v4, v3)
		if(Z_TYPE_P(v4)!=IS_LONG){
			phalcon_concat_left(&r8, " ", v4 TSRMLS_CC);
			phalcon_concat_vboth(&r7, r8, "=\"", v3 TSRMLS_CC);
			phalcon_concat_right(&r9, r7, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r10, v2, r9);
			PHALCON_CPY_WRT(v2, r10);
		}
	END_FOREACH(ac0, fes56, fee56, ah0, hp0);
	PHALCON_SET_STRING(t4, ">", 1);
	PHALCON_CONCAT_FUNCTION(r11, v2, t4);
	PHALCON_CPY_WRT(v2, r11);
	RETURN_ZVAL(v2, 0, 0);
}

int phalcon_dispatcher_static_init(zend_class_entry *ce TSRMLS_DC){
	zval *a0;
	PHALCON_INIT_ARRAY(a0);
	zend_update_static_property(ce, "_controllers", sizeof("_controllers")-1, a0 TSRMLS_CC);
	return 0;
}

int phalcon_test_static_init(zend_class_entry *ce TSRMLS_DC){
	zval *a0;
	PHALCON_INIT_ARRAY(a0);
	zend_update_static_property(ce, "p", sizeof("p")-1, a0 TSRMLS_CC);
	return 0;
}

int phalcon_model_manager_static_init(zend_class_entry *ce TSRMLS_DC){
	zval *a0, *a1;
	PHALCON_INIT_ARRAY(a0);
	zend_update_static_property(ce, "_models", sizeof("_models")-1, a0 TSRMLS_CC);
	PHALCON_INIT_ARRAY(a1);
	zend_update_static_property(ce, "_sourceNames", sizeof("_sourceNames")-1, a1 TSRMLS_CC);
	return 0;
}

int phalcon_transactions_static_init(zend_class_entry *ce TSRMLS_DC){
	zval *a0;
	PHALCON_INIT_ARRAY(a0);
	zend_update_static_property(ce, "_transactions", sizeof("_transactions")-1, a0 TSRMLS_CC);
	return 0;
}

int phalcon_tag_static_init(zend_class_entry *ce TSRMLS_DC){
	zval *a0;
	PHALCON_INIT_ARRAY(a0);
	zend_update_static_property(ce, "_displayValues", sizeof("_displayValues")-1, a0 TSRMLS_CC);
	return 0;
}

PHP_MINIT_FUNCTION(phalcon){

	zend_class_entry ce0, ce1, ce2, ce3, ce4, ce5, ce6, ce7, ce8, ce9, ce10, ce11, ce12, ce13, ce14, ce15, ce16, ce17, ce18, ce19, ce20, ce21, ce22, ce23, ce24, ce25, ce26, ce27, ce28, ce29, ce30, ce31, ce32, ce33, ce34, ce35, ce36;

	INIT_CLASS_ENTRY(ce0, "Phalcon_Dispatcher", phalcon_dispatcher_functions);
	phalcon_dispatcher_class_entry = zend_register_internal_class(&ce0 TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_frontController", sizeof("_frontController")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_router", sizeof("_router")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce1, "Phalcon_Request", phalcon_request_functions);
	phalcon_request_class_entry = zend_register_internal_class(&ce1 TSRMLS_CC);
	zend_declare_property_null(phalcon_request_class_entry, "_filter", sizeof("_filter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce2, "Phalcon_Controller_Front", phalcon_controller_front_functions);
	phalcon_controller_front_class_entry = zend_register_internal_class(&ce2 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_config", sizeof("_config")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_basePath", sizeof("_basePath")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_model", sizeof("_model")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce3, "Phalcon_View", phalcon_view_functions);
	phalcon_view_class_entry = zend_register_internal_class(&ce3 TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_content", sizeof("_content")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_view_class_entry, "_layoutsDir", sizeof("_layoutsDir")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_templatesBefore", sizeof("_templatesBefore")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_templatesAfter", sizeof("_templatesAfter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_frontController", sizeof("_frontController")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce4, "Phalcon_Test", phalcon_test_functions);
	phalcon_test_class_entry = zend_register_internal_class(&ce4 TSRMLS_CC);
	zend_declare_property_null(phalcon_test_class_entry, "p", sizeof("p")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce5, "Phalcon_Utils", phalcon_utils_functions);
	phalcon_utils_class_entry = zend_register_internal_class(&ce5 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce6, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_class_entry = zend_register_internal_class(&ce6 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_idConnection", sizeof("_idConnection")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_db_class_entry, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_db_class_entry, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_db_class_entry, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce7, "Phalcon_Internal_Test", phalcon_internal_test_functions);
	phalcon_internal_test_class_entry = zend_register_internal_class(&ce7 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce8, "Phalcon_Router_Rewrite", phalcon_router_rewrite_functions);
	phalcon_router_rewrite_class_entry = zend_register_internal_class(&ce8 TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_controller", sizeof("_controller")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_action", sizeof("_action")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_router_rewrite_class_entry, "_defaultController", sizeof("_defaultController")-1, "index", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_router_rewrite_class_entry, "_defaultAction", sizeof("_defaultAction")-1, "index", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_router_rewrite_class_entry, "_isRouted", sizeof("_isRouted")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce9, "Phalcon_Db_Pool", phalcon_db_pool_functions);
	phalcon_db_pool_class_entry = zend_register_internal_class(&ce9 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce10, "Phalcon_Db_Dialect_MySQL", phalcon_db_dialect_mysql_functions);
	phalcon_db_dialect_mysql_class_entry = zend_register_internal_class(&ce10 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce11, "Phalcon_Db_RawValue", phalcon_db_rawvalue_functions);
	phalcon_db_rawvalue_class_entry = zend_register_internal_class(&ce11 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_rawvalue_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce12, "Phalcon_Flash", phalcon_flash_functions);
	phalcon_flash_class_entry = zend_register_internal_class(&ce12 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce13, "Phalcon_Logger", phalcon_logger_functions);
	phalcon_logger_class_entry = zend_register_internal_class(&ce13 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "SPECIAL", sizeof("SPECIAL")-1, 9 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "CUSTOM", sizeof("CUSTOM")-1, 8 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "DEBUG", sizeof("DEBUG")-1, 7 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "INFO", sizeof("INFO")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "NOTICE", sizeof("NOTICE")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "WARNING", sizeof("WARNING")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "ERROR", sizeof("ERROR")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "ALERT", sizeof("ALERT")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "CRITICAL", sizeof("CRITICAL")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_logger_class_entry, "EMERGENCE", sizeof("EMERGENCE")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce14, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_class_entry = zend_register_internal_class(&ce14 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce15, "Phalcon_Filter", phalcon_filter_functions);
	phalcon_filter_class_entry = zend_register_internal_class(&ce15 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce16, "Phalcon_Controller", phalcon_controller_functions);
	phalcon_controller_class_entry = zend_register_internal_class(&ce16 TSRMLS_CC);
	zend_declare_property_bool(phalcon_controller_class_entry, "_dispatcher", sizeof("_dispatcher")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_controller_class_entry, "_front", sizeof("_front")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_controller_class_entry, "_router", sizeof("_router")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_controller_class_entry, "_model", sizeof("_model")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_controller_class_entry, "_view", sizeof("_view")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce17, "Phalcon_Model_Message", phalcon_model_message_functions);
	phalcon_model_message_class_entry = zend_register_internal_class(&ce17 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_class_entry, "_message", sizeof("_message")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce18, "Phalcon_Model_Manager", phalcon_model_manager_functions);
	phalcon_model_manager_class_entry = zend_register_internal_class(&ce18 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_front", sizeof("_front")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_metadata", sizeof("_metadata")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce19, "Phalcon_Model_MetaData", phalcon_model_metadata_functions);
	phalcon_model_metadata_class_entry = zend_register_internal_class(&ce19 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES", sizeof("MODELS_ATTRIBUTES")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY", sizeof("MODELS_PRIMARY_KEY")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY", sizeof("MODELS_NON_PRIMARY_KEY")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_NOT_NULL", sizeof("MODELS_NOT_NULL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE", sizeof("MODELS_DATA_TYPE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC", sizeof("MODELS_DATA_TYPE_NUMERIC")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_DATE_AT", sizeof("MODELS_DATE_AT")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_metadata_class_entry, "MODELS_DATE_IN", sizeof("MODELS_DATE_IN")-1, 7 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce20, "Phalcon_Model_Base", phalcon_model_base_functions);
	phalcon_model_base_class_entry = zend_register_internal_class(&ce20 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_uniqueKey", sizeof("_uniqueKey")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_schema", sizeof("_schema")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_source", sizeof("_source")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_double(phalcon_model_base_class_entry, "_count", sizeof("_count")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_isView", sizeof("_isView")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_dumped", sizeof("_dumped")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_dumpLock", sizeof("_dumpLock")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_errorMessages", sizeof("_errorMessages")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_operationMade", sizeof("_operationMade")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_forceExists", sizeof("_forceExists")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_defaultConnection", sizeof("_defaultConnection")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_connectionName", sizeof("_connectionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_refreshPersistance", sizeof("_refreshPersistance")-1, 1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_base_class_entry, "OP_CREATE", sizeof("OP_CREATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_base_class_entry, "OP_UPDATE", sizeof("OP_UPDATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_model_base_class_entry, "OP_DELETE", sizeof("OP_DELETE")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce21, "Phalcon_Model_MetaData_Memory", phalcon_model_metadata_memory_functions);
	phalcon_model_metadata_memory_class_entry = zend_register_internal_class(&ce21 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce22, "Phalcon_Model_Resultset", phalcon_model_resultset_functions);
	phalcon_model_resultset_class_entry = zend_register_internal_class(&ce22 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_model", sizeof("_model")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_resultResource", sizeof("_resultResource")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_model_resultset_class_entry, "_pointer", sizeof("_pointer")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_count", sizeof("_count")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_activeRow", sizeof("_activeRow")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_class_implements(phalcon_model_resultset_class_entry TSRMLS_CC, 3, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable);

	INIT_CLASS_ENTRY(ce23, "Phalcon_Model_Transaction", phalcon_model_transaction_functions);
	phalcon_model_transaction_class_entry = zend_register_internal_class(&ce23 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_transaction_class_entry, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_transaction_class_entry, "_activeTransaction", sizeof("_activeTransaction")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_transaction_class_entry, "_isNewTransaction", sizeof("_isNewTransaction")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_transaction_class_entry, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_transaction_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_model_transaction_class_entry, "_pointer", sizeof("_pointer")-1, 255, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_transaction_class_entry, "_dependencies", sizeof("_dependencies")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_transaction_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_transaction_class_entry, "_rollbackRecord", sizeof("_rollbackRecord")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce24, "Phalcon_Transactions", phalcon_transactions_functions);
	phalcon_transactions_class_entry = zend_register_internal_class(&ce24 TSRMLS_CC);
	zend_declare_property_bool(phalcon_transactions_class_entry, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transactions_class_entry, "_transactions", sizeof("_transactions")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_transactions_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transactions_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce25, "Phalcon_Tag", phalcon_tag_functions);
	phalcon_tag_class_entry = zend_register_internal_class(&ce25 TSRMLS_CC);
	zend_declare_property_bool(phalcon_tag_class_entry, "_useLocale", sizeof("_useLocale")-1, 1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_router", sizeof("_router")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce26, "Phalcon_Exception", phalcon_exception_functions);
	phalcon_exception_class_entry = zend_register_internal_class_ex(&ce26, NULL, "exception" TSRMLS_CC);
	if(!phalcon_exception_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Exception' not found when registering class 'Phalcon_Exception'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce27, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_class_entry = zend_register_internal_class(&ce27 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_idConnection", sizeof("_idConnection")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_db_class_entry, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_db_class_entry, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_db_class_entry, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce28, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_class_entry = zend_register_internal_class(&ce28 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce29, "Phalcon_Tag_Exception", phalcon_tag_exception_functions);
	phalcon_tag_exception_class_entry = zend_register_internal_class_ex(&ce29, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_tag_exception_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Exception' not found when registering class 'Phalcon_Tag_Exception'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce30, "Phalcon_Db_Exception", phalcon_db_exception_functions);
	phalcon_db_exception_class_entry = zend_register_internal_class_ex(&ce30, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_db_exception_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Exception' not found when registering class 'Phalcon_Db_Exception'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce31, "Phalcon_Db_MySQL", phalcon_db_mysql_functions);
	phalcon_db_mysql_class_entry = zend_register_internal_class_ex(&ce31, NULL, "phalcon_db" TSRMLS_CC);
	if(!phalcon_db_mysql_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Db' not found when registering class 'Phalcon_Db_MySQL'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce32, "Phalcon_Config_Adapter_Ini", phalcon_config_adapter_ini_functions);
	phalcon_config_adapter_ini_class_entry = zend_register_internal_class_ex(&ce32, NULL, "phalcon_config" TSRMLS_CC);
	if(!phalcon_config_adapter_ini_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Config' not found when registering class 'Phalcon_Config_Adapter_Ini'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce33, "Phalcon_Config_Exception", phalcon_config_exception_functions);
	phalcon_config_exception_class_entry = zend_register_internal_class_ex(&ce33, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_config_exception_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Exception' not found when registering class 'Phalcon_Config_Exception'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce34, "Phalcon_Model_Exception", phalcon_model_exception_functions);
	phalcon_model_exception_class_entry = zend_register_internal_class_ex(&ce34, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_model_exception_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Exception' not found when registering class 'Phalcon_Model_Exception'");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce35, "Phalcon_Model_Transaction_Failed", phalcon_model_transaction_failed_functions);
	phalcon_model_transaction_failed_class_entry = zend_register_internal_class_ex(&ce35, NULL, "exception" TSRMLS_CC);
	if(!phalcon_model_transaction_failed_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Exception' not found when registering class 'Phalcon_Model_Transaction_Failed'");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_model_transaction_failed_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce36, "Phalcon_View_Exception", phalcon_view_exception_functions);
	phalcon_view_exception_class_entry = zend_register_internal_class_ex(&ce36, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_view_exception_class_entry){
		fprintf(stderr, "Phalcon Error: Extended class 'Phalcon_Exception' not found when registering class 'Phalcon_View_Exception'");
		return FAILURE;
	}
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phalcon){
	return SUCCESS;
}

zend_module_entry phalcon_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_PHALCON_EXTNAME,
	main_functions,
	PHP_MINIT(phalcon),
	PHP_MSHUTDOWN(phalcon),
	NULL,
	NULL,
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHALCON_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHALCON
ZEND_GET_MODULE(phalcon)
#endif


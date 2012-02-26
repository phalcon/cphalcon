
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

extern int phalcon_find_scope(zend_class_entry *ce, char *method_name TSRMLS_DC);
extern int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, char *method_name TSRMLS_DC);

extern int phalcon_call_func(zval *return_value, char *func_name, int noreturn TSRMLS_DC);
extern int phalcon_call_func_params(zval *return_value, char *func_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

extern int phalcon_call_method(zval *return_value, zval *object, char *method_name, int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int check, int noreturn TSRMLS_DC);

extern int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, char *method_name, int noreturn TSRMLS_DC);
extern int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

extern int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int noreturn TSRMLS_DC);
extern int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

extern int phalcon_call_static_func(zval *return_value, char *class_name, char *method_name, int noreturn TSRMLS_DC);
extern int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int noreturn TSRMLS_DC);
extern int phalcon_call_static_func_params(zval *return_value, char *class_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC);

extern int phalcon_is_callable_check_class(const char *name, int name_len, zend_fcall_info_cache *fcc, int *strict_class, char **error TSRMLS_DC);
extern int phalcon_is_callable_check_func(int check_flags, zval *callable, zend_fcall_info_cache *fcc, int strict_class, char **error TSRMLS_DC);

extern zend_bool phalcon_is_callable_ex(zval *callable, zval *object_ptr, uint check_flags, char **callable_name, int *callable_name_len, zend_fcall_info_cache *fcc, char **error TSRMLS_DC);
extern int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC);
extern int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC);

#ifndef PHP_WIN32
extern int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
#endif

#define PHALCON_CALL_FUNC(return_value, func_name) phalcon_call_func(return_value, func_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_NORETURN(func_name) phalcon_call_func(NULL, func_name, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS(return_value, func_name, param_count, params) PHALCON_RESULT_INIT(return_value); phalcon_call_func_params(return_value, func_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_FUNC_PARAMS_NORETURN(func_name, param_count, params) phalcon_call_func_params(NULL, func_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_METHOD(return_value, object, method_name, check) phalcon_call_method(return_value, object, method_name, check, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_NORETURN(object, method_name, check) phalcon_call_method(NULL, object, method_name, check, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_PARAMS(return_value, object, method_name, param_count, params, check) phalcon_call_method_params(return_value, object, method_name, param_count, params, check, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_METHOD_PARAMS_NORETURN(object, method_name, param_count, params, check) phalcon_call_method_params(NULL, object, method_name, param_count, params, check, 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_PARENT_PARAMS(return_value, object, active_class, method_name, param_count, params)  phalcon_call_parent_func_params(return_value, object, active_class, method_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT_PARAMS_NORETURN(object, active_class, method_name, param_count, params) phalcon_call_parent_func_params(NULL, object, active_class, method_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT(return_value, object, active_class, method_name) phalcon_call_parent_func(return_value, object, active_class, method_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_PARENT_NORETURN(object, active_class, method_name) phalcon_call_parent_func(NULL, object, active_class, method_name, 0 TSRMLS_CC); if(EG(exception)) return;

#define PHALCON_CALL_SELF_PARAMS(return_value, object, method_name, param_count, params) phalcon_call_self_func_params(return_value, object, method_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_SELF_PARAMS_NORETURN(object, method_name, param_count, params) phalcon_call_self_func_params(NULL, object, method_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_SELF(return_value, object, method_name) phalcon_call_self_func(return_value, object, method_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_SELF_NORETURN(object, method_name) phalcon_call_self_func(NULL, object, method_name, 0 TSRMLS_CC); if(EG(exception)) return;

#define PHALCON_CALL_STATIC_PARAMS(return_value, class_name, method_name, param_count, params) phalcon_call_static_func_params(return_value, class_name, method_name, param_count, params, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_PARAMS_NORETURN(class_name, method_name, param_count, params) phalcon_call_static_func_params(NULL, class_name, method_name, param_count, params, 0 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC(return_value, class_name, method_name) phalcon_call_static_func(return_value, class_name, method_name, 1 TSRMLS_CC); if(EG(exception)) return
#define PHALCON_CALL_STATIC_NORETURN(class_name, method_name) phalcon_call_static_func(NULL, class_name, method_name, 0 TSRMLS_CC); if(EG(exception)) return

#define PHALCON_CALL_ZVAL_STATIC(return_value, class_zval, method_name) phalcon_call_static_zval_func(return_value, class_zval, method_name, 1 TSRMLS_CC); if(EG(exception)) return
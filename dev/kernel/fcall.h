
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

#define PHALCON_CALL_FUNC(return_value, func_name) if(phalcon_call_func(return_value, func_name, strlen(func_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_NORETURN(func_name) if(phalcon_call_func(NULL, func_name, strlen(func_name), 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS(return_value, func_name, param_count, params) if(phalcon_call_func_params(return_value, func_name, strlen(func_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_NORETURN(func_name, param_count, params) if(phalcon_call_func_params(NULL, func_name, strlen(func_name), param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_1(return_value, func_name, param1) if(phalcon_call_func_one_param(return_value, func_name, strlen(func_name), param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_1_NORETURN(func_name, param1) if(phalcon_call_func_one_param(NULL, func_name, strlen(func_name), param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_2(return_value, func_name, param1, param2) if(phalcon_call_func_two_params(return_value, func_name, strlen(func_name), param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_2_NORETURN(func_name, param1, param2) if(phalcon_call_func_two_params(NULL, func_name, strlen(func_name), param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_3(return_value, func_name, param1, param2, param3) if(phalcon_call_func_three_params(return_value, func_name, strlen(func_name), param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_3_NORETURN(func_name, param1, param2, param3) if(phalcon_call_func_three_params(NULL, func_name, strlen(func_name), param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;

#define PHALCON_CALL_METHOD(return_value, object, method_name, check) if(phalcon_call_method(return_value, object, method_name, strlen(method_name), check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_NORETURN(object, method_name, check) if(phalcon_call_method(NULL, object, method_name, strlen(method_name), check, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS(return_value, object, method_name, param_count, params, check) if(phalcon_call_method_params(return_value, object, method_name, strlen(method_name), param_count, params, check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_NORETURN(object, method_name, param_count, params, check) if(phalcon_call_method_params(NULL, object, method_name, strlen(method_name), param_count, params, check, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1(return_value, object, method_name, param1, check) if(phalcon_call_method_one_param(return_value, object, method_name, strlen(method_name), param1, check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, method_name, param1, check) if(phalcon_call_method_one_param(NULL, object, method_name, strlen(method_name), param1, check, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2(return_value, object, method_name, param1, param2, check) if(phalcon_call_method_two_params(return_value, object, method_name, strlen(method_name), param1, param2, check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_NORETURN(object, method_name, param1, param2, check) if(phalcon_call_method_two_params(NULL, object, method_name, strlen(method_name), param1, param2, check, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3(return_value, object, method_name, param1, param2, param3, check) if(phalcon_call_method_three_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_NORETURN(object, method_name, param1, param2, param3, check) if(phalcon_call_method_three_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, check, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4(return_value, object, method_name, param1, param2, param3, param4, check) if(phalcon_call_method_four_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_NORETURN(object, method_name, param1, param2, param3, param4, check) if(phalcon_call_method_four_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, check, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5(return_value, object, method_name, param1, param2, param3, param4, param5, check) if(phalcon_call_method_five_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, param5, check, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_NORETURN(object, method_name, param1, param2, param3, param4, param5, check) if(phalcon_call_method_five_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, param5, check, 0 TSRMLS_CC)==FAILURE) return;

#define PHALCON_CALL_PARENT_PARAMS(return_value, object, active_class, method_name, param_count, params) if(phalcon_call_parent_func_params(return_value, object, active_class, strlen(active_class), method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_NORETURN(object, active_class, method_name, param_count, params) if(phalcon_call_parent_func_params(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_1(return_value, object, active_class, method_name, param1) if(phalcon_call_parent_func_one_param(return_value, object, active_class, strlen(active_class), method_name, strlen(method_name), param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_1_NORETURN(object, active_class, method_name, param1) if(phalcon_call_parent_func_one_param(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_2(return_value, object, active_class, method_name, param1, param2) if(phalcon_call_parent_func_two_params(return_value, object, active_class, strlen(active_class), method_name, strlen(method_name), param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_2_NORETURN(object, active_class, method_name, param1, param2) if(phalcon_call_parent_func_two_params(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_3(return_value, object, active_class, method_name, param1, param2, param3) if(phalcon_call_parent_func_three_params(return_value, object, active_class, strlen(active_class), method_name, strlen(method_name), param1, param2, param3 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_3_NORETURN(object, active_class, method_name, param1, param2, param3) if(phalcon_call_parent_func_three_params(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT(return_value, object, active_class, method_name) if(phalcon_call_parent_func(return_value, object, active_class, strlen(active_class),method_name, strlen(method_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_NORETURN(object, active_class, method_name) if(phalcon_call_parent_func(NULL, object, active_class, strlen(active_class),method_name, strlen(method_name), 0 TSRMLS_CC)==FAILURE) return;;

#define PHALCON_CALL_SELF_PARAMS(return_value, object, method_name, param_count, params) if(phalcon_call_self_func_params(return_value, object, method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_NORETURN(object, method_name, param_count, params) if(phalcon_call_self_func_params(NULL, object, method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_1(return_value, object, method_name, param1) if(phalcon_call_self_func_one_param(return_value, object, method_name, strlen(method_name), param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_1_NORETURN(object, method_name, param1) if(phalcon_call_self_func_one_param(NULL, object, method_name, strlen(method_name), param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_2(return_value, object, method_name, param1, param2) if(phalcon_call_self_func_two_params(return_value, object, method_name, strlen(method_name), param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_2_NORETURN(object, method_name, param1, param2) if(phalcon_call_self_func_two_params(NULL, object, method_name, strlen(method_name), param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_3(return_value, object, method_name, param1, param2, param3) if(phalcon_call_self_func_three_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_3_NORETURN(object, method_name, param1, param2, param3) if(phalcon_call_self_func_three_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF(return_value, object, method_name) if(phalcon_call_self_func(return_value, object, method_name, strlen(method_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_NORETURN(object, method_name) if(phalcon_call_self_func(NULL, object, method_name, strlen(method_name), 0 TSRMLS_CC)==FAILURE) return;

#define PHALCON_CALL_STATIC_PARAMS(return_value, class_name, method_name, param_count, params) if(phalcon_call_static_func_params(return_value, class_name, strlen(class_name), method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_NORETURN(class_name, method_name, param_count, params) if(phalcon_call_static_func_params(NULL, class_name, strlen(class_name), method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_1(return_value, class_name, method_name, param1) if(phalcon_call_static_func_one_param(return_value, class_name, strlen(class_name), method_name, strlen(method_name), param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_1_NORETURN(class_name, method_name, param1) if(phalcon_call_static_func_one_param(NULL, class_name, strlen(class_name), method_name, strlen(method_name), param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_2(return_value, class_name, method_name, param1, param2) if(phalcon_call_static_func_two_params(return_value, class_name, strlen(class_name), method_name, strlen(method_name), param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_2_NORETURN(class_name, method_name, param1, param2) if(phalcon_call_static_func_two_params(NULL, class_name, strlen(class_name), method_name, strlen(method_name), param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_3(return_value, class_name, method_name, param1, param2, param3) if(phalcon_call_static_func_three_params(return_value, class_name, strlen(class_name), method_name, strlen(method_name), param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_3_NORETURN(class_name, method_name, param1, param2, param3) if(phalcon_call_static_func_three_params(NULL, class_name, strlen(class_name), method_name, strlen(method_name), param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC(return_value, class_name, method_name) if(phalcon_call_static_func(return_value, class_name, strlen(class_name), method_name, strlen(method_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_NORETURN(class_name, method_name) if(phalcon_call_static_func(NULL, class_name, strlen(class_name), method_name, strlen(method_name), 0 TSRMLS_CC)==FAILURE) return;

#define PHALCON_CALL_ZVAL_STATIC(return_value, class_zval, method_name) if(phalcon_call_static_zval_func(return_value, class_zval, method_name, strlen(method_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_ZVAL_PARAMS(return_value, class_zval, method_name, param_count, params) if(phalcon_call_static_zval_func_params(return_value, class_zval, method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_ZVAL_PARAMS_1(return_value, class_zval, method_name, param1) if(phalcon_call_static_zval_func_one_param(return_value, class_zval, method_name, strlen(method_name), param1, 1 TSRMLS_CC)==FAILURE) return;

/** Look for call scope */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len TSRMLS_DC);
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC);

/** Lookups and cache fci data **/
int phalcon_cache_lookup_method(char *func_name, int func_name_length TSRMLS_DC);
int phalcon_cache_lookup_function(char *func_name, int func_name_length, int fcache_pointer TSRMLS_DC);

/** Call single functions */
extern int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn TSRMLS_DC);
extern int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn TSRMLS_DC);
extern int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn TSRMLS_DC);
extern int phalcon_call_func_three_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC);

/** Call methods on object instances */
extern int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, int check, int noreturn TSRMLS_DC);
extern int phalcon_call_method_five_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5, int check, int noreturn TSRMLS_DC);

/** Call methods on parent class */
extern int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, int active_class_len,char *method_name, int method_len, int noreturn TSRMLS_DC);
extern int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_parent_func_one_param(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC);
extern int phalcon_call_parent_func_two_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC);
extern int phalcon_call_parent_func_three_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC);

/** Call methods on self class */
extern int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int method_len, int noreturn TSRMLS_DC);
extern int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_self_func_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC);
extern int phalcon_call_self_func_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC);
extern int phalcon_call_self_func_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC);

/** Call methods on static classes */
extern int phalcon_call_static_func(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, int noreturn TSRMLS_DC);
extern int phalcon_call_static_func_params(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_static_func_one_param(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC);
extern int phalcon_call_static_func_two_params(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC);
extern int phalcon_call_static_func_three_params(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC);

/** Call methods on static classes from a zval class name */
extern int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int method_len, int noreturn TSRMLS_DC);
extern int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_static_zval_func_one_param(zval *return_value, zval *mixed_name, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC);

/** Call functions */
int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC);
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC);
int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
int phalcon_lookup_class_ex(const char *name, int name_length, int use_autoload, zend_class_entry ***ce TSRMLS_DC);
int phalcon_lookup_class(const char *name, int name_length, zend_class_entry ***ce TSRMLS_DC);

#if PHP_VERSION_ID <= 50308
#define PHALCON_CALL_USER_FUNCTION phalcon_call_user_function
#else
#define PHALCON_CALL_USER_FUNCTION call_user_function
#endif

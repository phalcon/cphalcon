
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
#if PHP_VERSION_ID < 50400
#define PH_MEHASH_C , 0
#define PH_MEHASH_D , unsigned long method_key
#else
#define PH_MEHASH_C
#define PH_MEHASH_D
#endif
#else
#if PHP_VERSION_ID < 50400
#define PH_MEHASH_C , method_key
#define PH_MEHASH_D , unsigned long method_key
#else
#define PH_MEHASH_C
#define PH_MEHASH_D
#endif
#endif

/* Macros to call functions in the PHP userland */
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

/** Macros to call methods in the PHP userland (use these in development) */
#define PHALCON_CALL_METHOD(return_value, object, method_name) if(phalcon_call_method(return_value, object, method_name, strlen(method_name), 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_NORETURN(object, method_name) if(phalcon_call_method(NULL, object, method_name, strlen(method_name), 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS(return_value, object, method_name, param_count, params) if(phalcon_call_method_params(return_value, object, method_name, strlen(method_name), param_count, params, 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_NORETURN(object, method_name, param_count, params) if(phalcon_call_method_params(NULL, object, method_name, strlen(method_name), param_count, params, 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1(return_value, object, method_name, param1) if(phalcon_call_method_one_param(return_value, object, method_name, strlen(method_name), param1, 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, method_name, param1) if(phalcon_call_method_one_param(NULL, object, method_name, strlen(method_name), param1, 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2(return_value, object, method_name, param1, param2) if(phalcon_call_method_two_params(return_value, object, method_name, strlen(method_name), param1, param2, 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_NORETURN(object, method_name, param1, param2) if(phalcon_call_method_two_params(NULL, object, method_name, strlen(method_name), param1, param2, 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3(return_value, object, method_name, param1, param2, param3) if(phalcon_call_method_three_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_NORETURN(object, method_name, param1, param2, param3) if(phalcon_call_method_three_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4(return_value, object, method_name, param1, param2, param3, param4) if(phalcon_call_method_four_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_NORETURN(object, method_name, param1, param2, param3, param4) if(phalcon_call_method_four_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5(return_value, object, method_name, param1, param2, param3, param4, param5) if(phalcon_call_method_five_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, param5, 1 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_NORETURN(object, method_name, param1, param2, param3, param4, param5) if(phalcon_call_method_five_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, param5, 0 PH_MEHASH_C TSRMLS_CC)==FAILURE) return;

/** Macros to call methods in the PHP userland with a precalculated hash key (not use these in development) */
#define PHALCON_CALL_METHOD_KEY(return_value, object, method_name, key) if(phalcon_call_method(return_value, object, method_name, strlen(method_name), 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_NORETURN_KEY(object, method_name, key) if(phalcon_call_method(NULL, object, method_name, strlen(method_name), 0, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_KEY(return_value, object, method_name, param_count, params, key) if(phalcon_call_method_params(return_value, object, method_name, strlen(method_name), param_count, params, 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_NORETURN_KEY(object, method_name, param_count, params, key) if(phalcon_call_method_params(NULL, object, method_name, strlen(method_name), param_count, params, 0, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_KEY(return_value, object, method_name, param1, key) if(phalcon_call_method_one_param(return_value, object, method_name, strlen(method_name), param1, 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_NORETURN_KEY(object, method_name, param1, key) if(phalcon_call_method_one_param(NULL, object, method_name, strlen(method_name), param1, 0, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_KEY(return_value, object, method_name, param1, param2, key) if(phalcon_call_method_two_params(return_value, object, method_name, strlen(method_name), param1, param2, 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_NORETURN_KEY(object, method_name, param1, param2, key) if(phalcon_call_method_two_params(NULL, object, method_name, strlen(method_name), param1, param2, 0, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_KEY(return_value, object, method_name, param1, param2, param3, key) if(phalcon_call_method_three_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_NORETURN_KEY(object, method_name, param1, param2, param3, key) if(phalcon_call_method_three_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, 0, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_KEY(return_value, object, method_name, param1, param2, param3, param4, key) if(phalcon_call_method_four_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_NORETURN_KEY(object, method_name, param1, param2, param3, param4, key) if(phalcon_call_method_four_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, 0, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_KEY(return_value, object, method_name, param1, param2, param3, param4, param5, key) if(phalcon_call_method_five_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, param5, 1, key TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_NORETURN_KEY(object, method_name, param1, param2, param3, param4, param5, key) if(phalcon_call_method_five_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, param5, 0, key TSRMLS_CC)==FAILURE) return;

/** Use these macros to call functions in the parent class */
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

/** Use these functions to call static functions on the current class */
#define PHALCON_CALL_SELF_PARAMS(return_value, object, method_name, param_count, params) if(phalcon_call_self_func_params(return_value, object, method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_NORETURN(object, method_name, param_count, params) if(phalcon_call_self_func_params(NULL, object, method_name, strlen(method_name), param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_1(return_value, object, method_name, param1) if(phalcon_call_self_func_one_param(return_value, object, method_name, strlen(method_name), param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_1_NORETURN(object, method_name, param1) if(phalcon_call_self_func_one_param(NULL, object, method_name, strlen(method_name), param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_2(return_value, object, method_name, param1, param2) if(phalcon_call_self_func_two_params(return_value, object, method_name, strlen(method_name), param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_2_NORETURN(object, method_name, param1, param2) if(phalcon_call_self_func_two_params(NULL, object, method_name, strlen(method_name), param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_3(return_value, object, method_name, param1, param2, param3) if(phalcon_call_self_func_three_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_3_NORETURN(object, method_name, param1, param2, param3) if(phalcon_call_self_func_three_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_4(return_value, object, method_name, param1, param2, param3, param4) if(phalcon_call_self_func_four_params(return_value, object, method_name, strlen(method_name), param1, param2, param3, param4, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_4_NORETURN(object, method_name, param1, param2, param3, param4) if(phalcon_call_self_func_four_params(NULL, object, method_name, strlen(method_name), param1, param2, param3, param4, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF(return_value, object, method_name) if(phalcon_call_self_func(return_value, object, method_name, strlen(method_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_NORETURN(object, method_name) if(phalcon_call_self_func(NULL, object, method_name, strlen(method_name), 0 TSRMLS_CC)==FAILURE) return;

/** Use these macros to call functions statically  */
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

/** Use these functions to call static functions using a zval as callable */
#define PHALCON_CALL_ZVAL_STATIC(return_value, class_zval, method_name) if(phalcon_call_static_zval_func(return_value, class_zval, method_name, strlen(method_name), 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_ZVAL_PARAMS(return_value, class_zval, method_name, param_count, params) if(phalcon_call_static_zval_func_params(return_value, class_zval, method_name, strlen(method_name), param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_ZVAL_PARAMS_1(return_value, class_zval, method_name, param1) if(phalcon_call_static_zval_func_one_param(return_value, class_zval, method_name, strlen(method_name), param1, 1 TSRMLS_CC)==FAILURE) return;

/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define PHALCON_CALL_USER_FUNC(return_value, handler) if(phalcon_call_user_func(return_value, handler TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_USER_FUNC_ARRAY(return_value, handler, params) if(phalcon_call_user_func_array(return_value, handler, params TSRMLS_CC)==FAILURE) return;

/** Look for call scope */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len TSRMLS_DC);
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC);

/** Call single functions */
extern int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn TSRMLS_DC);
extern int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn TSRMLS_DC);
extern int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn TSRMLS_DC);
extern int phalcon_call_func_three_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC);

/** Call methods on object instances */
extern int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int noreturn PH_MEHASH_D TSRMLS_DC);
extern int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn PH_MEHASH_D TSRMLS_DC);
extern int phalcon_call_method_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, int noreturn PH_MEHASH_D TSRMLS_DC);
extern int phalcon_call_method_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, int noreturn PH_MEHASH_D TSRMLS_DC);
extern int phalcon_call_method_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn PH_MEHASH_D TSRMLS_DC);
extern int phalcon_call_method_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, int noreturn PH_MEHASH_D TSRMLS_DC);
extern int phalcon_call_method_five_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5, int noreturn PH_MEHASH_D TSRMLS_DC);

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
extern int phalcon_call_self_func_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, int noreturn TSRMLS_DC);

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

/** Fast call_user_func_array/call_user_func */
extern int phalcon_call_user_func(zval *return_value, zval *handler TSRMLS_DC);
extern int phalcon_call_user_func_array(zval *return_value, zval *handler, zval *params TSRMLS_DC);

/** Check constructors */
extern int phalcon_has_constructor(zval *object TSRMLS_DC);

/** Call functions */
int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC);
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC);
int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
int phalcon_lookup_class_ex(const char *name, int name_length, int use_autoload, zend_class_entry ***ce TSRMLS_DC);
int phalcon_lookup_class(const char *name, int name_length, zend_class_entry ***ce TSRMLS_DC);

/** PHP < 5.3.9 has problems with closures */
#if PHP_VERSION_ID <= 50309
#define PHALCON_CALL_USER_FUNCTION_EX phalcon_call_user_function_ex
#else
#define PHALCON_CALL_USER_FUNCTION_EX call_user_function_ex
#endif

#ifndef zend_error_noreturn
#define zend_error_noreturn zend_error
#endif
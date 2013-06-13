
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

/* Macros to call functions in the PHP userland (deprecated) */
#define PHALCON_CALL_FUNC(return_value, func_name) if (phalcon_call_func_ex(return_value, func_name, sizeof(func_name)-1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_NORETURN(func_name) if (phalcon_call_func_ex(NULL, func_name, sizeof(func_name)-1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS(return_value, func_name, param_count, params) if (phalcon_call_func_params(return_value, func_name, sizeof(func_name)-1, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_NORETURN(func_name, param_count, params) if (phalcon_call_func_params(NULL, func_name, sizeof(func_name)-1, param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_1(return_value, func_name, param1) if (phalcon_call_func_one_param(return_value, func_name, sizeof(func_name)-1, param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_1_NORETURN(func_name, param1) if (phalcon_call_func_one_param(NULL, func_name, sizeof(func_name)-1, param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_2(return_value, func_name, param1, param2) if (phalcon_call_func_two_params(return_value, func_name, sizeof(func_name)-1, param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_2_NORETURN(func_name, param1, param2) if (phalcon_call_func_two_params(NULL, func_name, sizeof(func_name)-1, param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_3(return_value, func_name, param1, param2, param3) if (phalcon_call_func_three_params(return_value, func_name, sizeof(func_name)-1, param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_FUNC_PARAMS_3_NORETURN(func_name, param1, param2, param3) if (phalcon_call_func_three_params(NULL, func_name, sizeof(func_name)-1, param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;

/* Macros to call functions in the PHP userland */
#define phalcon_call_func(return_value, func_name) if(phalcon_call_func_ex(return_value, func_name, sizeof(func_name)-1, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_noret(func_name) if(phalcon_call_func_ex(NULL, func_name, sizeof(func_name)-1, 0 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_pn(return_value, func_name, param_count, params) if(phalcon_call_func_params(return_value, func_name, sizeof(func_name)-1, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_pn_noret(func_name, param_count, params) if (phalcon_call_func_params(NULL, func_name, sizeof(func_name)-1, param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p1(return_value, func_name, param1) if (phalcon_call_func_one_param(return_value, func_name, sizeof(func_name)-1, param1, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p1_noret(func_name, param1) if (phalcon_call_func_one_param(NULL, func_name, sizeof(func_name)-1, param1, 0 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p2(return_value, func_name, param1, param2) if (phalcon_call_func_two_params(return_value, func_name, sizeof(func_name)-1, param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p2_noret(func_name, param1, param2) if (phalcon_call_func_two_params(NULL, func_name, sizeof(func_name)-1, param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p3(return_value, func_name, param1, param2, param3) if (phalcon_call_func_three_params(return_value, func_name, sizeof(func_name)-1, param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p3_noret(func_name, param1, param2, param3) if (phalcon_call_func_three_params(NULL, func_name, sizeof(func_name)-1, param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p4(return_value, func_name, param1, param2, param3, param4) if (phalcon_call_func_four_params(return_value, func_name, sizeof(func_name)-1, param1, param2, param3, param4, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_func_p4_noret(func_name, param1, param2, param3, param4) if (phalcon_call_func_four_params(NULL, func_name, sizeof(func_name)-1, param1, param2, param3, param4, 0 TSRMLS_CC)==FAILURE) return;

/** Macros to call methods in the PHP userland (use these in development) (deprecated) */
#define PHALCON_CALL_METHOD(return_value, object, method_name) if(phalcon_call_method_ex(return_value, object, method_name, sizeof(method_name)-1, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_NORETURN(object, method_name) if(phalcon_call_method_ex(NULL, object, method_name, sizeof(method_name)-1, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS(return_value, object, method_name, param_count, params) if(phalcon_call_method_params(return_value, object, method_name, sizeof(method_name)-1, param_count, params, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_NORETURN(object, method_name, param_count, params) if(phalcon_call_method_params(NULL, object, method_name, sizeof(method_name)-1, param_count, params, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1(return_value, object, method_name, param1) if(phalcon_call_method_one_param(return_value, object, method_name, sizeof(method_name)-1, param1, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, method_name, param1) if(phalcon_call_method_one_param(NULL, object, method_name, sizeof(method_name)-1, param1, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2(return_value, object, method_name, param1, param2) if(phalcon_call_method_two_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_NORETURN(object, method_name, param1, param2) if(phalcon_call_method_two_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3(return_value, object, method_name, param1, param2, param3) if(phalcon_call_method_three_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_NORETURN(object, method_name, param1, param2, param3) if(phalcon_call_method_three_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4(return_value, object, method_name, param1, param2, param3, param4) if(phalcon_call_method_four_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_NORETURN(object, method_name, param1, param2, param3, param4) if(phalcon_call_method_four_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5(return_value, object, method_name, param1, param2, param3, param4, param5) if(phalcon_call_method_five_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_NORETURN(object, method_name, param1, param2, param3, param4, param5) if(phalcon_call_method_five_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 0, 0, 1 TSRMLS_CC)==FAILURE) return;

/** Macros to call methods in the PHP userland (use these in development) */
#define phalcon_call_method(return_value, object, method_name) if (phalcon_call_method_ex(return_value, object, method_name, sizeof(method_name)-1, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_noret(object, method_name) if (phalcon_call_method_ex(NULL, object, method_name, sizeof(method_name)-1, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_pn(return_value, object, method_name, param_count, params) if(phalcon_call_method_params(return_value, object, method_name, sizeof(method_name)-1, param_count, params, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_pn_noret(object, method_name, param_count, params) if (phalcon_call_method_params(NULL, object, method_name, sizeof(method_name)-1, param_count, params, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p1(return_value, object, method_name, param1) if (phalcon_call_method_one_param(return_value, object, method_name, sizeof(method_name)-1, param1, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p1_noret(object, method_name, param1) if (phalcon_call_method_one_param(NULL, object, method_name, sizeof(method_name)-1, param1, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p2(return_value, object, method_name, param1, param2) if (phalcon_call_method_two_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p2_noret(object, method_name, param1, param2) if (phalcon_call_method_two_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p3(return_value, object, method_name, param1, param2, param3) if(phalcon_call_method_three_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p3_noret(object, method_name, param1, param2, param3) if(phalcon_call_method_three_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p4(return_value, object, method_name, param1, param2, param3, param4) if(phalcon_call_method_four_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p4_noret(object, method_name, param1, param2, param3, param4) if(phalcon_call_method_four_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p5(return_value, object, method_name, param1, param2, param3, param4, param5) if(phalcon_call_method_five_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p5_noret(object, method_name, param1, param2, param3, param4, param5) if(phalcon_call_method_five_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 0, 0, 1 TSRMLS_CC)==FAILURE) return;

/** Macros to call methods with zvals as method names */
#define phalcon_call_method_zval(return_value, object, method) if (phalcon_call_method_zval_ex(return_value, object, method, 1, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_zval_noret(object, method) if (phalcon_call_method_zval_ex(NULL, object, method, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_zval_p1_noret(object, method, param1) if (phalcon_call_method_zval_one_param(NULL, object, method, param1, 0, 0, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_zval_p3(return_value, object, method, param1, param2, param3) if(phalcon_call_method_zval_three_params(return_value, object, method, param1, param2, param3, 1, 0, 1 TSRMLS_CC)==FAILURE) return;

/** Macros to call methods in the PHP userland with a precalculated hash key (not use these in development) (deprecated) */
#define PHALCON_CALL_METHOD_KEY(return_value, object, method_name, key) if(phalcon_call_method_ex(return_value, object, method_name, sizeof(method_name)-1, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_NORETURN_KEY(object, method_name, key) if(phalcon_call_method_ex(NULL, object, method_name, sizeof(method_name)-1, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_KEY(return_value, object, method_name, param_count, params, key) if(phalcon_call_method_params(return_value, object, method_name, sizeof(method_name)-1, param_count, params, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_NORETURN_KEY(object, method_name, param_count, params, key) if(phalcon_call_method_params(NULL, object, method_name, sizeof(method_name)-1, param_count, params, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_KEY(return_value, object, method_name, param1, key) if(phalcon_call_method_one_param(return_value, object, method_name, sizeof(method_name)-1, param1, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_1_NORETURN_KEY(object, method_name, param1, key) if(phalcon_call_method_one_param(NULL, object, method_name, sizeof(method_name)-1, param1, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_KEY(return_value, object, method_name, param1, param2, key) if(phalcon_call_method_two_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_2_NORETURN_KEY(object, method_name, param1, param2, key) if(phalcon_call_method_two_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_KEY(return_value, object, method_name, param1, param2, param3, key) if(phalcon_call_method_three_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_3_NORETURN_KEY(object, method_name, param1, param2, param3, key) if(phalcon_call_method_three_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_KEY(return_value, object, method_name, param1, param2, param3, param4, key) if(phalcon_call_method_four_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_4_NORETURN_KEY(object, method_name, param1, param2, param3, param4, key) if(phalcon_call_method_four_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_KEY(return_value, object, method_name, param1, param2, param3, param4, param5, key) if(phalcon_call_method_five_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_METHOD_PARAMS_5_NORETURN_KEY(object, method_name, param1, param2, param3, param4, param5, key) if(phalcon_call_method_five_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 0, key, 1 TSRMLS_CC)==FAILURE) return;

/** Macros to call methods in the PHP userland with a precalculated hash key (not use these in development) */
#define phalcon_call_method_key(return_value, object, method_name, key) if(phalcon_call_method_ex(return_value, object, method_name, sizeof(method_name)-1, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_noret_key(object, method_name, key) if(phalcon_call_method_ex(NULL, object, method_name, sizeof(method_name)-1, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_params_key(return_value, object, method_name, param_count, params, key) if(phalcon_call_method_params(return_value, object, method_name, sizeof(method_name)-1, param_count, params, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_params_noret_key(object, method_name, param_count, params, key) if(phalcon_call_method_params(NULL, object, method_name, sizeof(method_name)-1, param_count, params, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p1_key(return_value, object, method_name, param1, key) if(phalcon_call_method_one_param(return_value, object, method_name, sizeof(method_name)-1, param1, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p1_noret_key(object, method_name, param1, key) if(phalcon_call_method_one_param(NULL, object, method_name, sizeof(method_name)-1, param1, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p2_key(return_value, object, method_name, param1, param2, key) if(phalcon_call_method_two_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p2_noret_key(object, method_name, param1, param2, key) if(phalcon_call_method_two_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p3_key(return_value, object, method_name, param1, param2, param3, key) if(phalcon_call_method_three_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p3_noret_key(object, method_name, param1, param2, param3, key) if(phalcon_call_method_three_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p4_key(return_value, object, method_name, param1, param2, param3, param4, key) if(phalcon_call_method_four_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p4_noret_key(object, method_name, param1, param2, param3, param4, key) if(phalcon_call_method_four_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 0, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p5_key(return_value, object, method_name, param1, param2, param3, param4, param5, key) if(phalcon_call_method_five_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 1, key, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_method_p5_noret_key(object, method_name, param1, param2, param3, param4, param5, key) if(phalcon_call_method_five_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 0, key, 1 TSRMLS_CC)==FAILURE) return;

/** Use these macros to call functions in the parent class */
#define PHALCON_CALL_PARENT_PARAMS(return_value, object, active_class, method_name, param_count, params) if(phalcon_call_parent_func_params(return_value, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_NORETURN(object, active_class, method_name, param_count, params) if(phalcon_call_parent_func_params(NULL, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_1(return_value, object, active_class, method_name, param1) if(phalcon_call_parent_func_one_param(return_value, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_1_NORETURN(object, active_class, method_name, param1) if(phalcon_call_parent_func_one_param(NULL, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_2(return_value, object, active_class, method_name, param1, param2) if(phalcon_call_parent_func_two_params(return_value, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_2_NORETURN(object, active_class, method_name, param1, param2) if(phalcon_call_parent_func_two_params(NULL, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_3(return_value, object, active_class, method_name, param1, param2, param3) if(phalcon_call_parent_func_three_params(return_value, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param1, param2, param3 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_PARAMS_3_NORETURN(object, active_class, method_name, param1, param2, param3) if(phalcon_call_parent_func_three_params(NULL, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT(return_value, object, active_class, method_name) if(phalcon_call_parent_func(return_value, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_PARENT_NORETURN(object, active_class, method_name) if(phalcon_call_parent_func(NULL, object, active_class, sizeof(active_class)-1, method_name, sizeof(method_name)-1, 0 TSRMLS_CC)==FAILURE) return;;

/** Use these functions to call static functions on the current class */
#define PHALCON_CALL_SELF_PARAMS(return_value, object, method_name, param_count, params) if(phalcon_call_self_func_params(return_value, object, method_name, sizeof(method_name)-1, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_NORETURN(object, method_name, param_count, params) if(phalcon_call_self_func_params(NULL, object, method_name, sizeof(method_name)-1, param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_1(return_value, object, method_name, param1) if(phalcon_call_self_func_one_param(return_value, object, method_name, sizeof(method_name)-1, param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_1_NORETURN(object, method_name, param1) if(phalcon_call_self_func_one_param(NULL, object, method_name, sizeof(method_name)-1, param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_2(return_value, object, method_name, param1, param2) if(phalcon_call_self_func_two_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_2_NORETURN(object, method_name, param1, param2) if(phalcon_call_self_func_two_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_3(return_value, object, method_name, param1, param2, param3) if(phalcon_call_self_func_three_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_3_NORETURN(object, method_name, param1, param2, param3) if(phalcon_call_self_func_three_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_4(return_value, object, method_name, param1, param2, param3, param4) if(phalcon_call_self_func_four_params(return_value, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_PARAMS_4_NORETURN(object, method_name, param1, param2, param3, param4) if(phalcon_call_self_func_four_params(NULL, object, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF(return_value, object, method_name) if(phalcon_call_self_func(return_value, object, method_name, sizeof(method_name)-1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_SELF_NORETURN(object, method_name) if(phalcon_call_self_func(NULL, object, method_name, sizeof(method_name)-1, 0 TSRMLS_CC)==FAILURE) return;

/** Use these macros to call functions statically  */
#define PHALCON_CALL_STATIC_PARAMS(return_value, class_name, method_name, param_count, params) if(phalcon_call_static_func_params(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_NORETURN(class_name, method_name, param_count, params) if(phalcon_call_static_func_params(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param_count, params, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_1(return_value, class_name, method_name, param1) if(phalcon_call_static_func_one_param(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_1_NORETURN(class_name, method_name, param1) if(phalcon_call_static_func_one_param(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_2(return_value, class_name, method_name, param1, param2) if(phalcon_call_static_func_two_params(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_2_NORETURN(class_name, method_name, param1, param2) if(phalcon_call_static_func_two_params(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_3(return_value, class_name, method_name, param1, param2, param3) if(phalcon_call_static_func_three_params(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, param3, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_3_NORETURN(class_name, method_name, param1, param2, param3) if(phalcon_call_static_func_three_params(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, param3, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_4(return_value, class_name, method_name, param1, param2, param3, param4) if(phalcon_call_static_func_four_params(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_4_NORETURN(class_name, method_name, param1, param2, param3, param4) if(phalcon_call_static_func_four_params(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, param3, param4, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_5(return_value, class_name, method_name, param1, param2, param3, param4, param5) if(phalcon_call_static_func_five_params(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_PARAMS_5_NORETURN(class_name, method_name, param1, param2, param3, param4, param5) if(phalcon_call_static_func_five_params(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, param1, param2, param3, param4, param5, 0 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC(return_value, class_name, method_name) if(phalcon_call_static_func(return_value, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_NORETURN(class_name, method_name) if(phalcon_call_static_func(NULL, class_name, sizeof(class_name)-1, method_name, sizeof(method_name)-1, 0 TSRMLS_CC)==FAILURE) return;

/** Use these functions to call static functions using a zval as callable */
#define PHALCON_CALL_ZVAL_STATIC(return_value, class_zval, method) if(phalcon_call_static_zval_func(return_value, class_zval, method, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_ZVAL_PARAMS(return_value, class_zval, method, param_count, params) if(phalcon_call_static_zval_func_params(return_value, class_zval, method, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_STATIC_ZVAL_PARAMS_1(return_value, class_zval, method, param1) if(phalcon_call_static_zval_func_one_param(return_value, class_zval, method, param1, 1 TSRMLS_CC)==FAILURE) return;

#define phalcon_call_zval_static(return_value, class_zval, method) if(phalcon_call_static_zval_func(return_value, class_zval, method, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_zval_static_params(return_value, class_zval, method, param_count, params) if(phalcon_call_static_zval_func_params(return_value, class_zval, method, param_count, params, 1 TSRMLS_CC)==FAILURE) return;
#define phalcon_call_zval_static_p1(return_value, class_zval, method, param1) if(phalcon_call_static_zval_func_one_param(return_value, class_zval, method, param1, 1 TSRMLS_CC)==FAILURE) return;

#define phalcon_call_zval_str_static_p1(return_value, class_zval, method_name, param1) if(phalcon_call_static_zval_str_func_one_param(return_value, class_zval, method_name, sizeof(method_name)-1, param1, 1 TSRMLS_CC)==FAILURE) return;

/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define PHALCON_CALL_USER_FUNC(return_value, handler) if(phalcon_call_user_func(return_value, handler TSRMLS_CC)==FAILURE) return;
#define PHALCON_CALL_USER_FUNC_ARRAY(return_value, handler, params) if(phalcon_call_user_func_array(return_value, handler, params TSRMLS_CC)==FAILURE) return;

/** Look for call scope */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len, int lower TSRMLS_DC);
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC);

/** Call single functions */
extern int phalcon_call_func_ex(zval *return_value, char *func_name, int func_length, int noreturn TSRMLS_DC);
extern int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn TSRMLS_DC);
extern int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn TSRMLS_DC);
extern int phalcon_call_func_three_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC);
extern int phalcon_call_func_four_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, zval *param3, zval *param4, int noreturn TSRMLS_DC);

/** Call methods on object instances */
extern int phalcon_call_method_ex(zval *return_value, zval *object, char *method_name, int method_len, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_five_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5, int noreturn, unsigned long method_key, int lower TSRMLS_DC);

/** Call zval methods on object instances */
extern int phalcon_call_method_zval_ex(zval *return_value, zval *object, zval *method, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_zval_one_param(zval *return_value, zval *object, zval *method, zval *param1, int noreturn, unsigned long method_key, int lower TSRMLS_DC);
extern int phalcon_call_method_zval_three_params(zval *return_value, zval *object, zval *method, zval *param1, zval *param2, zval *param3, int noreturn, unsigned long method_key, int lower TSRMLS_DC);

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
extern int phalcon_call_static_func_four_params(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, int noreturn TSRMLS_DC);
extern int phalcon_call_static_func_five_params(zval *return_value, char *class_name, int class_name_len, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5, int noreturn TSRMLS_DC);

/** Call methods on static classes from a zval class name */
extern int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, zval *method, int noreturn TSRMLS_DC);
extern int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, zval *method, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC);
extern int phalcon_call_static_zval_func_one_param(zval *return_value, zval *mixed_name, zval *method, zval *param1, int noreturn TSRMLS_DC);

extern int phalcon_call_static_zval_str_func_one_param(zval *return_value, zval *mixed_name, char *method_name, int method_le, zval *param1, int noreturn TSRMLS_DC);

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
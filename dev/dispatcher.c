
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_dispatcher_class_entry, this_ptr, "_controllers", strlen("_controllers"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_dispatcher_class_entry, this_ptr, "_params", strlen("_params"), a1 TSRMLS_CC);
}

/**
 * Sets default controllers directory
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Dispatcher, setControllersDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_controllersDir", v0);
	RETURN_NULL();
}

/**
 * Gets active controllers directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllersDir){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets base path for controllers dir
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Dispatcher, setBasePath){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_basePath", v0);
	RETURN_NULL();
}

/**
 * Gets base path for controllers dir
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getBasePath){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setControllerName){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_controllerName", v0);
	RETURN_NULL();
}

/**
 * Gets last dispacthed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllerName){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_actionName", v0);
	RETURN_NULL();
}

/**
 * Gets last dispacthed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets action params to be dispatch
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_params", v0);
	RETURN_NULL();
}

/**
 * Gets action params
     *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getParams){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL, NULL, NULL, NULL }, *p7[] = { NULL, NULL, NULL }, *p10[] = { NULL }, *p11[] = { NULL, NULL, NULL }, *p12[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	if (!v2) {
		PHALCON_ALLOC_ZVAL(v2);
		ZVAL_NULL(v2);
	}
	if (!v3) {
		PHALCON_ALLOC_ZVAL(v3);
		ZVAL_NULL(v3);
	}
	
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL(v5);
	ZVAL_NULL(v5);
	PHALCON_ALLOC_ZVAL(v6);
	ZVAL_NULL(v6);
	PHALCON_ALLOC_ZVAL(v7);
	ZVAL_LONG(v7, 0);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	ws0:
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_finished", sizeof("_finished")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	boolean_not_function(r1, t2 TSRMLS_CC);
	if (!zend_is_true(r1)) {
		goto we0;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 1 TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	phalcon_read_property(t3, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v8, t3);
	if (!zend_is_true(v8)) {
		PHALCON_INIT_VAR(t4);
		phalcon_read_property(t4, this_ptr, "_defaultController", sizeof("_defaultController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t4);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_controllerName", v8);
	}
	PHALCON_INIT_VAR(t5);
	phalcon_read_property(t5, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v9, t5);
	PHALCON_INIT_RESULT(r2);
	Z_ADDREF_P(v8);
	p0[0] = v8;
	PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_utils", "camelize", 1, p0);
	PHALCON_INIT_RESULT(r3);
	PHALCON_CONCAT_RIGHT(r3, r2, "Controller");
	PHALCON_CPY_WRT(v10, r3);
	eval_int = phalcon_array_isset(v9, v10);
	if (!eval_int) {
		PHALCON_INIT_RESULT(r4);
		Z_ADDREF_P(v10);
		PHALCON_INIT_VARTYPE(c0, IS_BOOL);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_FUNC_PARAMS_2(r4, "class_exists", v10, c0, 0x000);
		if (!zend_is_true(r4)) {
			PHALCON_INIT_RESULT(r5);
			concat_function(r5, v4, v10 TSRMLS_CC);
			PHALCON_INIT_RESULT(r6);
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
				PHALCON_INIT_RESULT(r7);
				PHALCON_CONCAT_BOTH(r7,  "File for controller class ", v10, " doesn't exists");
				Z_ADDREF_P(r7);
				p2[0] = r7;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
			PHALCON_INIT_RESULT(r8);
			Z_ADDREF_P(v10);
			PHALCON_INIT_VARTYPE(c1, IS_BOOL);
			ZVAL_BOOL(c1, 0);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "class_exists", v10, c1, 0x000);
			if (!zend_is_true(r8)) {
				PHALCON_INIT_VAR(i1);
				object_init_ex(i1, phalcon_exception_class_entry);
				PHALCON_INIT_RESULT(r9);
				PHALCON_CONCAT_BOTH(r9,  "Class ", v10, " was not found on controller file");
				Z_ADDREF_P(r9);
				p4[0] = r9;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i1 TSRMLS_CC);
				Z_ADDREF_P(i1);
				return;
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
		PHALCON_CPY_WRT(v6, i2);
		if (phalcon_method_exists_ex(v6, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(v6, "initialize", PHALCON_CALL_DEFAULT);
		}
		PHALCON_INIT_VAR(t6);
		phalcon_read_property(t6, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ARRAY_UPDATE(t6, v10, v6);
		phalcon_update_property_zval(this_ptr, "_controllers", strlen("_controllers"), t6 TSRMLS_CC);
	} else {
		PHALCON_INIT_RESULT(r10);
		phalcon_array_fetch(r10, v9, v10, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r10);
	}
	PHALCON_INIT_VAR(t7);
	phalcon_read_property(t7, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v12, t7);
	PHALCON_INIT_VAR(t8);
	phalcon_read_property(t8, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v13, t8);
	if (!zend_is_true(v13)) {
		PHALCON_INIT_VAR(t9);
		phalcon_read_property(t9, this_ptr, "_defaultAction", sizeof("_defaultAction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v13, t9);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_actionName", v13);
	}
	if (phalcon_method_exists_ex(v6, "beforedispatch", strlen("beforedispatch") TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_RESULT(r11);
		Z_ADDREF_P(v8);
		p7[0] = v8;
		Z_ADDREF_P(v13);
		p7[1] = v13;
		Z_ADDREF_P(v12);
		p7[2] = v12;
		PHALCON_CALL_METHOD_PARAMS(r11, v6, "beforedispatch", 3, p7, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			PHALCON_INIT_VARTYPE(v5, IS_BOOL);
			ZVAL_BOOL(v5, 0);
			goto we0;
		}
	}
	PHALCON_INIT_RESULT(r12);
	PHALCON_CONCAT_RIGHT(r12, v13, "Action");
	PHALCON_CPY_WRT(v14, r12);
	if (phalcon_method_exists(v6, v14 TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_RESULT(r13);
		PHALCON_INIT_VARTYPE(a0, IS_ARRAY);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v14, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		Z_ADDREF_P(a0);
		Z_ADDREF_P(v12);
		PHALCON_CALL_FUNC_PARAMS_2(r13, "call_user_func_array", a0, v12, 0x001);
		PHALCON_CPY_WRT(v5, r13);
	} else {
		if (phalcon_method_exists_ex(v6, "notfoundaction", strlen("notfoundaction") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_RESULT(r14);
			PHALCON_INIT_VARTYPE(a1, IS_ARRAY);
			array_init(a1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v6, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a1);
				add_next_index_zval(a1, copy);
			}
			add_next_index_string(a1, "notFoundAction", 1);
			Z_ADDREF_P(a1);
			Z_ADDREF_P(v12);
			PHALCON_CALL_FUNC_PARAMS_2(r14, "call_user_func_array", a1, v12, 0x001);
			PHALCON_CPY_WRT(v5, r14);
		} else {
			PHALCON_INIT_VAR(i3);
			object_init_ex(i3, phalcon_exception_class_entry);
			PHALCON_INIT_RESULT(r16);
			PHALCON_CONCAT_LEFT(r16, "Action '", v13);
			PHALCON_INIT_RESULT(r15);
			PHALCON_CONCAT_VBOTH(r15, r16, "' was not found on controller '", v8);
			PHALCON_INIT_RESULT(r17);
			PHALCON_CONCAT_RIGHT(r17, r15, "'");
			Z_ADDREF_P(r17);
			p10[0] = r17;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p10, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i3 TSRMLS_CC);
			Z_ADDREF_P(i3);
			return;
		}
	}
	if (phalcon_method_exists_ex(v6, "afterdispatch", strlen("afterdispatch") TSRMLS_CC) == SUCCESS) {
		Z_ADDREF_P(v8);
		p11[0] = v8;
		Z_ADDREF_P(v13);
		p11[1] = v13;
		Z_ADDREF_P(v12);
		p11[2] = v12;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "afterdispatch", 3, p11, PHALCON_CALL_DEFAULT);
	}
	PHALCON_SEPARATE(v7);
	increment_function(v7);
	if (!phalcon_is_smaller_strict_long(v7, 256)) {
		PHALCON_INIT_VAR(i4);
		object_init_ex(i4, phalcon_exception_class_entry);
		PHALCON_INIT_VARTYPE(p12[0], IS_STRING);
		ZVAL_STRING(p12[0], "Dispatcher has detected a cyclic routing causing stability problems", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 1, p12, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		return;
	}
	goto ws0;
	we0:
	r1 = NULL;
	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_returnedValue", v5);
	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_lastController", v6);
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
	zval *ac0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		PHALCON_CPY_WRT(v1, v0);
	} else {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "explode", c0, v0, 0x002);
		FREE_ZVAL(c0);
		PHALCON_CPY_WRT(v1, r0);
	}
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		phalcon_filter_alphanum(&r2, p1[0]);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_controllerName", r2);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 0);
	} else {
		eval_int = phalcon_array_isset_string(v1, "controller", strlen("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v1, "controller", strlen("controller"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r3;
			phalcon_filter_alphanum(&r4, p2[0]);
			PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_controllerName", r4);
		} else {
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getcontrollername", PHALCON_CALL_DEFAULT);
			PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_controllerName", r5);
		}
	}
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p4[0] = r6;
		phalcon_filter_alphanum(&r7, p4[0]);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_actionName", r7);
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_long(r8, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_actionName", r8);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 1);
	} else {
		eval_int = phalcon_array_isset_string(v1, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r9);
			phalcon_array_fetch_string(r9, v1, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p5[0] = r9;
			phalcon_filter_alphanum(&r10, p5[0]);
			PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_actionName", r10);
		} else {
			PHALCON_ALLOC_ZVAL(r11);
			PHALCON_CALL_METHOD(r11, this_ptr, "getactionname", PHALCON_CALL_DEFAULT);
			PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_actionName", r11);
		}
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	FOREACH_KV(v1, ac0, fes1, fee1, ah0, hp0, v4, v3)
		if (Z_TYPE_P(v4) == IS_LONG) {
			PHALCON_INIT_RESULT(r12);
			phalcon_array_fetch(r12, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r12, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(v2);
				phalcon_array_append(v2, copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes1, fee1, ah0, hp0);
	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_params", v2);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	RETURN_NULL();
}

/**
 * Returns all instantiated controllers whitin the dispatcher
 *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getControllers){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns last dispatched controller
 *
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, getLastController){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_lastController", sizeof("_lastController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns value returned by last dispacthed action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_returnedValue", sizeof("_returnedValue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}


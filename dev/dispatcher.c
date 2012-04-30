
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
#include "kernel/memory.h"

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
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				PHALCON_MM_RESTORE();
				return;
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
				zend_throw_exception_object(i1 TSRMLS_CC);
				Z_ADDREF_P(i1);
				PHALCON_MM_RESTORE();
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
			zend_throw_exception_object(i3 TSRMLS_CC);
			Z_ADDREF_P(i3);
			PHALCON_MM_RESTORE();
			return;
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
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		PHALCON_MM_RESTORE();
		return;
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



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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), copy TSRMLS_CC);
	}
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
	PHALCON_RETURN_CTOR(t0);
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), copy TSRMLS_CC);
	}
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
	PHALCON_RETURN_CTOR(t0);
}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setControllerName){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
	}
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
	PHALCON_RETURN_CTOR(t0);
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
	}
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
	PHALCON_RETURN_CTOR(t0);
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
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
	PHALCON_RETURN_CTOR(t0);
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
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL, NULL, NULL, NULL }, *p7[] = { NULL, NULL, NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL, NULL }, *p10[] = { NULL }, *p11[] = { NULL, NULL, NULL }, *p12[] = { NULL };
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
	if (!t3) {
		PHALCON_ALLOC_ZVAL(t3);
	} else {
		if (Z_REFCOUNT_P(t3) > 1) {
			PHALCON_SEPARATE(t3);
		} else {
			FREE_ZVAL(t3);
			PHALCON_ALLOC_ZVAL(t3);
		}
	}
	phalcon_read_property(t3, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v8, t3);
	if (!zend_is_true(v8)) {
		if (!t4) {
			PHALCON_ALLOC_ZVAL(t4);
		} else {
			if (Z_REFCOUNT_P(t4) > 1) {
				PHALCON_SEPARATE(t4);
			} else {
				FREE_ZVAL(t4);
				PHALCON_ALLOC_ZVAL(t4);
			}
		}
		phalcon_read_property(t4, this_ptr, "_defaultController", sizeof("_defaultController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t4);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
		}
	}
	if (!t5) {
		PHALCON_ALLOC_ZVAL(t5);
	} else {
		if (Z_REFCOUNT_P(t5) > 1) {
			PHALCON_SEPARATE(t5);
		} else {
			FREE_ZVAL(t5);
			PHALCON_ALLOC_ZVAL(t5);
		}
	}
	phalcon_read_property(t5, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v9, t5);
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1) {
			PHALCON_SEPARATE(r2);
		} else {
			FREE_ZVAL(r2);
			PHALCON_ALLOC_ZVAL(r2);
		}
	}
	Z_ADDREF_P(v8);
	p0[0] = v8;
	PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_utils", "camelize", 1, p0);
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1) {
			PHALCON_SEPARATE(r3);
		} else {
			FREE_ZVAL(r3);
			PHALCON_ALLOC_ZVAL(r3);
		}
	}
	PHALCON_CONCAT_RIGHT(r3, r2, "Controller");
	PHALCON_CPY_WRT(v10, r3);
	eval_int = phalcon_array_isset(v9, v10);
	if (!eval_int) {
		if (!r4) {
			PHALCON_ALLOC_ZVAL(r4);
		} else {
			if (Z_REFCOUNT_P(r4) > 1) {
				PHALCON_SEPARATE(r4);
			} else {
				FREE_ZVAL(r4);
				PHALCON_ALLOC_ZVAL(r4);
			}
		}
		Z_ADDREF_P(v10);
		p1[0] = v10;
		PHALCON_PARAM_BOOL(p1[1], 0);
		PHALCON_CALL_FUNC_PARAMS(r4, "class_exists", 2, p1);
		if (!zend_is_true(r4)) {
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					PHALCON_SEPARATE(r5);
				} else {
					FREE_ZVAL(r5);
					PHALCON_ALLOC_ZVAL(r5);
				}
			}
			concat_function(r5, v4, v10 TSRMLS_CC);
			if (!r6) {
				PHALCON_ALLOC_ZVAL(r6);
			} else {
				if (Z_REFCOUNT_P(r6) > 1) {
					PHALCON_SEPARATE(r6);
				} else {
					FREE_ZVAL(r6);
					PHALCON_ALLOC_ZVAL(r6);
				}
			}
			PHALCON_CONCAT_RIGHT(r6, r5, ".php");
			PHALCON_CPY_WRT(v11, r6);
			if (phalcon_file_exists(v11 TSRMLS_CC) == SUCCESS) {
				phalcon_require(v11 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
			} else {
				if (!i0) {
					PHALCON_ALLOC_ZVAL(i0);
				} else {
					if (Z_REFCOUNT_P(i0) > 1) {
						PHALCON_SEPARATE(i0);
					} else {
						FREE_ZVAL(i0);
						PHALCON_ALLOC_ZVAL(i0);
					}
				}
				object_init_ex(i0, phalcon_exception_class_entry);
				if (!r7) {
					PHALCON_ALLOC_ZVAL(r7);
				} else {
					if (Z_REFCOUNT_P(r7) > 1) {
						PHALCON_SEPARATE(r7);
					} else {
						FREE_ZVAL(r7);
						PHALCON_ALLOC_ZVAL(r7);
					}
				}
				phalcon_concat_both(r7,  "File for controller class ", v10, " doesn't exists" TSRMLS_CC);
				Z_ADDREF_P(r7);
				p2[0] = r7;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
			if (!r8) {
				PHALCON_ALLOC_ZVAL(r8);
			} else {
				if (Z_REFCOUNT_P(r8) > 1) {
					PHALCON_SEPARATE(r8);
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			Z_ADDREF_P(v10);
			p3[0] = v10;
			PHALCON_PARAM_BOOL(p3[1], 0);
			PHALCON_CALL_FUNC_PARAMS(r8, "class_exists", 2, p3);
			if (!zend_is_true(r8)) {
				if (!i1) {
					PHALCON_ALLOC_ZVAL(i1);
				} else {
					if (Z_REFCOUNT_P(i1) > 1) {
						PHALCON_SEPARATE(i1);
					} else {
						FREE_ZVAL(i1);
						PHALCON_ALLOC_ZVAL(i1);
					}
				}
				object_init_ex(i1, phalcon_exception_class_entry);
				if (!r9) {
					PHALCON_ALLOC_ZVAL(r9);
				} else {
					if (Z_REFCOUNT_P(r9) > 1) {
						PHALCON_SEPARATE(r9);
					} else {
						FREE_ZVAL(r9);
						PHALCON_ALLOC_ZVAL(r9);
					}
				}
				phalcon_concat_both(r9,  "Class ", v10, " was not found on controller file" TSRMLS_CC);
				Z_ADDREF_P(r9);
				p4[0] = r9;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i1 TSRMLS_CC);
				Z_ADDREF_P(i1);
				return;
			}
		}
		ce0 = zend_fetch_class(Z_STRVAL_P(v10), Z_STRLEN_P(v10), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		if (!i2) {
			PHALCON_ALLOC_ZVAL(i2);
		} else {
			if (Z_REFCOUNT_P(i2) > 1) {
				PHALCON_SEPARATE(i2);
			} else {
				FREE_ZVAL(i2);
				PHALCON_ALLOC_ZVAL(i2);
			}
		}
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
		if (!t6) {
			PHALCON_ALLOC_ZVAL(t6);
		} else {
			if (Z_REFCOUNT_P(t6) > 1) {
				SEPARATE_ZVAL(&t6);
			} else {
				if (Z_TYPE_P(t6) != IS_STRING) {
					FREE_ZVAL(t6);
					PHALCON_ALLOC_ZVAL(t6);
				}
			}
		}
		ZVAL_STRING(t6, "initialize", 0);
		if (phalcon_method_exists(v6, t6 TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(v6, "initialize", PHALCON_CALL_DEFAULT);
		}
		if (!t7) {
			PHALCON_ALLOC_ZVAL(t7);
		} else {
			if (Z_REFCOUNT_P(t7) > 1) {
				PHALCON_SEPARATE(t7);
			} else {
				FREE_ZVAL(t7);
				PHALCON_ALLOC_ZVAL(t7);
			}
		}
		phalcon_read_property(t7, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(t7);
			phalcon_array_update(t7, v10, copy TSRMLS_CC);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_controllers", strlen("_controllers"), copy TSRMLS_CC);
		}
	} else {
		if (!r10) {
			PHALCON_ALLOC_ZVAL(r10);
		} else {
			if (Z_REFCOUNT_P(r10) > 1) {
				PHALCON_SEPARATE(r10);
			} else {
				FREE_ZVAL(r10);
				PHALCON_ALLOC_ZVAL(r10);
			}
		}
		phalcon_array_fetch(r10, v9, v10, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r10);
	}
	if (!t8) {
		PHALCON_ALLOC_ZVAL(t8);
	} else {
		if (Z_REFCOUNT_P(t8) > 1) {
			PHALCON_SEPARATE(t8);
		} else {
			FREE_ZVAL(t8);
			PHALCON_ALLOC_ZVAL(t8);
		}
	}
	phalcon_read_property(t8, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v12, t8);
	if (!t9) {
		PHALCON_ALLOC_ZVAL(t9);
	} else {
		if (Z_REFCOUNT_P(t9) > 1) {
			PHALCON_SEPARATE(t9);
		} else {
			FREE_ZVAL(t9);
			PHALCON_ALLOC_ZVAL(t9);
		}
	}
	phalcon_read_property(t9, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v13, t9);
	if (!zend_is_true(v13)) {
		if (!t10) {
			PHALCON_ALLOC_ZVAL(t10);
		} else {
			if (Z_REFCOUNT_P(t10) > 1) {
				PHALCON_SEPARATE(t10);
			} else {
				FREE_ZVAL(t10);
				PHALCON_ALLOC_ZVAL(t10);
			}
		}
		phalcon_read_property(t10, this_ptr, "_defaultAction", sizeof("_defaultAction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v13, t10);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v13, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
		}
	}
	if (!t11) {
		PHALCON_ALLOC_ZVAL(t11);
	} else {
		if (Z_REFCOUNT_P(t11) > 1) {
			SEPARATE_ZVAL(&t11);
		} else {
			if (Z_TYPE_P(t11) != IS_STRING) {
				FREE_ZVAL(t11);
				PHALCON_ALLOC_ZVAL(t11);
			}
		}
	}
	ZVAL_STRING(t11, "beforeDispatch", 0);
	if (phalcon_method_exists(v6, t11 TSRMLS_CC) == SUCCESS) {
		if (!r11) {
			PHALCON_ALLOC_ZVAL(r11);
		} else {
			if (Z_REFCOUNT_P(r11) > 1) {
				PHALCON_SEPARATE(r11);
			} else {
				FREE_ZVAL(r11);
				PHALCON_ALLOC_ZVAL(r11);
			}
		}
		Z_ADDREF_P(v8);
		p7[0] = v8;
		Z_ADDREF_P(v13);
		p7[1] = v13;
		Z_ADDREF_P(v12);
		p7[2] = v12;
		PHALCON_CALL_METHOD_PARAMS(r11, v6, "beforedispatch", 3, p7, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			if (!v5) {
				PHALCON_ALLOC_ZVAL(v5);
			} else {
				if (Z_REFCOUNT_P(v5) > 1) {
					SEPARATE_ZVAL(&v5);
				} else {
					if (Z_TYPE_P(v5) != IS_BOOL) {
						FREE_ZVAL(v5);
						PHALCON_ALLOC_ZVAL(v5);
					}
				}
			}
			ZVAL_BOOL(v5, 0);
			goto we0;
		}
	}
	if (!r12) {
		PHALCON_ALLOC_ZVAL(r12);
	} else {
		if (Z_REFCOUNT_P(r12) > 1) {
			PHALCON_SEPARATE(r12);
		} else {
			FREE_ZVAL(r12);
			PHALCON_ALLOC_ZVAL(r12);
		}
	}
	PHALCON_CONCAT_RIGHT(r12, v13, "Action");
	PHALCON_CPY_WRT(v14, r12);
	if (phalcon_method_exists(v6, v14 TSRMLS_CC) == SUCCESS) {
		if (!r13) {
			PHALCON_ALLOC_ZVAL(r13);
		} else {
			if (Z_REFCOUNT_P(r13) > 1) {
				PHALCON_SEPARATE(r13);
			} else {
				FREE_ZVAL(r13);
				PHALCON_ALLOC_ZVAL(r13);
			}
		}
		if (!a0) {
			PHALCON_ALLOC_ZVAL(a0);
		} else {
			if (Z_REFCOUNT_P(a0) > 1) {
				SEPARATE_ZVAL(&a0);
			} else {
				if (Z_TYPE_P(a0) != IS_ARRAY) {
					FREE_ZVAL(a0);
					PHALCON_ALLOC_ZVAL(a0);
				}
			}
		}
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
		p8[0] = a0;
		Z_ADDREF_P(v12);
		p8[1] = v12;
		PHALCON_CALL_FUNC_PARAMS(r13, "call_user_func_array", 2, p8);
		PHALCON_CPY_WRT(v5, r13);
	} else {
		if (!t12) {
			PHALCON_ALLOC_ZVAL(t12);
		} else {
			if (Z_REFCOUNT_P(t12) > 1) {
				SEPARATE_ZVAL(&t12);
			} else {
				if (Z_TYPE_P(t12) != IS_STRING) {
					FREE_ZVAL(t12);
					PHALCON_ALLOC_ZVAL(t12);
				}
			}
		}
		ZVAL_STRING(t12, "notFoundAction", 0);
		if (phalcon_method_exists(v6, t12 TSRMLS_CC) == SUCCESS) {
			if (!r14) {
				PHALCON_ALLOC_ZVAL(r14);
			} else {
				if (Z_REFCOUNT_P(r14) > 1) {
					PHALCON_SEPARATE(r14);
				} else {
					FREE_ZVAL(r14);
					PHALCON_ALLOC_ZVAL(r14);
				}
			}
			if (!a1) {
				PHALCON_ALLOC_ZVAL(a1);
			} else {
				if (Z_REFCOUNT_P(a1) > 1) {
					SEPARATE_ZVAL(&a1);
				} else {
					if (Z_TYPE_P(a1) != IS_ARRAY) {
						FREE_ZVAL(a1);
						PHALCON_ALLOC_ZVAL(a1);
					}
				}
			}
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
			p9[0] = a1;
			Z_ADDREF_P(v12);
			p9[1] = v12;
			PHALCON_CALL_FUNC_PARAMS(r14, "call_user_func_array", 2, p9);
			PHALCON_CPY_WRT(v5, r14);
		} else {
			if (!i3) {
				PHALCON_ALLOC_ZVAL(i3);
			} else {
				if (Z_REFCOUNT_P(i3) > 1) {
					PHALCON_SEPARATE(i3);
				} else {
					FREE_ZVAL(i3);
					PHALCON_ALLOC_ZVAL(i3);
				}
			}
			object_init_ex(i3, phalcon_exception_class_entry);
			if (!r16) {
				PHALCON_ALLOC_ZVAL(r16);
			} else {
				if (Z_REFCOUNT_P(r16) > 1) {
					PHALCON_SEPARATE(r16);
				} else {
					FREE_ZVAL(r16);
					PHALCON_ALLOC_ZVAL(r16);
				}
			}
			PHALCON_CONCAT_LEFT(r16, "Action '", v13);
			if (!r15) {
				PHALCON_ALLOC_ZVAL(r15);
			} else {
				if (Z_REFCOUNT_P(r15) > 1) {
					PHALCON_SEPARATE(r15);
				} else {
					FREE_ZVAL(r15);
					PHALCON_ALLOC_ZVAL(r15);
				}
			}
			phalcon_concat_vboth(r15, r16, "' was not found on controller '", v8 TSRMLS_CC);
			if (!r17) {
				PHALCON_ALLOC_ZVAL(r17);
			} else {
				if (Z_REFCOUNT_P(r17) > 1) {
					PHALCON_SEPARATE(r17);
				} else {
					FREE_ZVAL(r17);
					PHALCON_ALLOC_ZVAL(r17);
				}
			}
			PHALCON_CONCAT_RIGHT(r17, r15, "'");
			Z_ADDREF_P(r17);
			p10[0] = r17;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p10, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i3 TSRMLS_CC);
			Z_ADDREF_P(i3);
			return;
		}
	}
	if (!t13) {
		PHALCON_ALLOC_ZVAL(t13);
	} else {
		if (Z_REFCOUNT_P(t13) > 1) {
			SEPARATE_ZVAL(&t13);
		} else {
			if (Z_TYPE_P(t13) != IS_STRING) {
				FREE_ZVAL(t13);
				PHALCON_ALLOC_ZVAL(t13);
			}
		}
	}
	ZVAL_STRING(t13, "afterDispatch", 0);
	if (phalcon_method_exists(v6, t13 TSRMLS_CC) == SUCCESS) {
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
	if (!t14) {
		PHALCON_ALLOC_ZVAL(t14);
	} else {
		if (Z_REFCOUNT_P(t14) > 1) {
			SEPARATE_ZVAL(&t14);
		} else {
			if (Z_TYPE_P(t14) != IS_LONG) {
				FREE_ZVAL(t14);
				PHALCON_ALLOC_ZVAL(t14);
			}
		}
	}
	ZVAL_LONG(t14, 256);
	if (!r18) {
		PHALCON_ALLOC_ZVAL(r18);
	} else {
		if (Z_REFCOUNT_P(r18) > 1) {
			SEPARATE_ZVAL(&r18);
		} else {
			if (Z_TYPE_P(r18) != IS_BOOL) {
				FREE_ZVAL(r18);
				PHALCON_ALLOC_ZVAL(r18);
			}
		}
	}
	is_smaller_function(r18, t14, v7 TSRMLS_CC);
	if (zend_is_true(r18)) {
		if (!i4) {
			PHALCON_ALLOC_ZVAL(i4);
		} else {
			if (Z_REFCOUNT_P(i4) > 1) {
				PHALCON_SEPARATE(i4);
			} else {
				FREE_ZVAL(i4);
				PHALCON_ALLOC_ZVAL(i4);
			}
		}
		object_init_ex(i4, phalcon_exception_class_entry);
		if (!p12[0]) {
			PHALCON_ALLOC_ZVAL(p12[0]);
		} else {
			if (Z_REFCOUNT_P(p12[0]) > 1) {
				SEPARATE_ZVAL(&p12[0]);
			} else {
				if (Z_TYPE_P(p12[0]) != IS_STRING) {
					FREE_ZVAL(p12[0]);
					PHALCON_ALLOC_ZVAL(p12[0]);
				}
			}
		}
		ZVAL_STRING(p12[0], "Dispatcher has detected a cyclic routing causing stability problems", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 1, p12, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		return;
	}
	goto ws0;
	we0:
	r1 = NULL;
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v5, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_returnedValue", strlen("_returnedValue"), copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v6, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_lastController", strlen("_lastController"), copy TSRMLS_CC);
	}
	PHALCON_RETURN_CTOR(v6);
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
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };
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
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "/", 1);
		p0[1] = v0;
		PHALCON_CALL_FUNC_PARAMS(r0, "explode", 2, p0);
		PHALCON_CPY_WRT(v1, r0);
	}
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		phalcon_filter_alphanum(&r2, p1[0]);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
		}
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 0);
	} else {
		eval_int = phalcon_array_isset_string(v1, "controller", strlen("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v1, "controller", strlen("controller"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r3;
			phalcon_filter_alphanum(&r4, p2[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
			}
		} else {
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getcontrollername", PHALCON_CALL_DEFAULT);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
			}
		}
	}
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p4[0] = r6;
		phalcon_filter_alphanum(&r7, p4[0]);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_long(r8, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
		}
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 1);
	} else {
		eval_int = phalcon_array_isset_string(v1, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r9);
			phalcon_array_fetch_string(r9, v1, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p5[0] = r9;
			phalcon_filter_alphanum(&r10, p5[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r10, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
			}
		} else {
			PHALCON_ALLOC_ZVAL(r11);
			PHALCON_CALL_METHOD(r11, this_ptr, "getactionname", PHALCON_CALL_DEFAULT);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r11, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
			}
		}
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	FOREACH_KV(v1, ac0, fes1, fee1, ah0, hp0, v4, v3)
		if (Z_TYPE_P(v4) == IS_LONG) {
			if (!r12) {
				PHALCON_ALLOC_ZVAL(r12);
			} else {
				if (Z_REFCOUNT_P(r12) > 1) {
					PHALCON_SEPARATE(r12);
				} else {
					FREE_ZVAL(r12);
					PHALCON_ALLOC_ZVAL(r12);
				}
			}
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
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
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
	PHALCON_RETURN_CTOR(t0);
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
	PHALCON_RETURN_CTOR(t0);
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
	PHALCON_RETURN_CTOR(t0);
}


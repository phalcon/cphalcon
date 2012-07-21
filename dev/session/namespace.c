
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

/**
 * Phalcon\Session\Namespace
 *
 * This component helps to separate session data into namespaces. Working by this way
 * you can easily create groups of session variables into the application
 */

/**
 * Constructor of class
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Session_Namespace, __construct){

	zval *name = NULL, *data = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_session_namespace_ce, this_ptr, SL("_data"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_STATIC_PARAMS_1(data, "phalcon\\session", "get", t0);
	if (Z_TYPE_P(data) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Setter of values
 *
 * @param string $property
 * @param string $value
 */
PHP_METHOD(Phalcon_Session_Namespace, __set){

	zval *property = NULL, *value = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &property, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_data"), PH_NOISY_CC);
	phalcon_array_update(&t0, property, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_data"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_data"), PH_NOISY_CC);
	PHALCON_CALL_STATIC_PARAMS_2_NORETURN("phalcon\\session", "set", t1, t2);
	
	PHALCON_MM_RESTORE();
}

/**
 * Getter of values
 *
 * @param string $property
 * @return string
 */
PHP_METHOD(Phalcon_Session_Namespace, __get){

	zval *property = NULL, *data = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(data);
	phalcon_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(data, property);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, data, property, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_MM_RESTORE();
}


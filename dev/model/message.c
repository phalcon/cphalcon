
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


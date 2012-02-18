
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
 * Php_Model_Message
 *
 * Encapsulates validation related information generated before save/delete records
 */

PHP_METHOD(Phalcon_Model_Message, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_INIT_NULL(v1);
	}
	if (!v2) {
		PHALCON_INIT_NULL(v2);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Message", "__construct", 0);
	phalcon_step_over("Phalcon_Model_Message::__construct (Assignment) File=Library/Phalcon/Model/Message.php Line=15");
	//$message
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Message::__construct (Assignment) File=Library/Phalcon/Model/Message.php Line=16");
	//$field
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_field", strlen("_field"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Message::__construct (Assignment) File=Library/Phalcon/Model/Message.php Line=17");
	//$type
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Message::__construct (Method) File=Library/Phalcon/Model/Message.php Line=20");
}

PHP_METHOD(Phalcon_Model_Message, setType){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Message", "setType", 0);
	phalcon_step_over("Phalcon_Model_Message::setType (Assignment) File=Library/Phalcon/Model/Message.php Line=21");
	//$type
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Message::setType (Method) File=Library/Phalcon/Model/Message.php Line=24");
}

PHP_METHOD(Phalcon_Model_Message, getType){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Message", "getType", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Message::getType (Method) File=Library/Phalcon/Model/Message.php Line=28");
}

PHP_METHOD(Phalcon_Model_Message, setMessage){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Message", "setMessage", 0);
	phalcon_step_over("Phalcon_Model_Message::setMessage (Assignment) File=Library/Phalcon/Model/Message.php Line=29");
	//$message
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_message", strlen("_message"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Message::setMessage (Method) File=Library/Phalcon/Model/Message.php Line=32");
}

PHP_METHOD(Phalcon_Model_Message, getMessage){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Message", "getMessage", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_message", sizeof("_message")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Message::getMessage (Method) File=Library/Phalcon/Model/Message.php Line=36");
}

PHP_METHOD(Phalcon_Model_Message, setField){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Message", "setField", 0);
	phalcon_step_over("Phalcon_Model_Message::setField (Assignment) File=Library/Phalcon/Model/Message.php Line=37");
	//$field
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_field", strlen("_field"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Message::setField (Method) File=Library/Phalcon/Model/Message.php Line=40");
}

PHP_METHOD(Phalcon_Model_Message, getField){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Message", "getField", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_field", sizeof("_field")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Message::getField (Method) File=Library/Phalcon/Model/Message.php Line=44");
}

PHP_METHOD(Phalcon_Model_Message, __toString){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Message", "__toString", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_message", sizeof("_message")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Message::__toString (Method) File=Library/Phalcon/Model/Message.php Line=48");
}

PHP_METHOD(Phalcon_Model_Message, __set_state){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Message", "__set_state", 0);
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_message_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Message" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	//$message
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "_message", strlen("_message"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r0);
	p0[0] = r0;
	phalcon_debug_param(r0 TSRMLS_CC);
	//$message
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_string(r1, v0, "_field", strlen("_field"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r1);
	p0[1] = r1;
	phalcon_debug_param(r1 TSRMLS_CC);
	//$message
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_string(r2, v0, "_type", strlen("_type"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[2] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Message" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", i0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(i0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
}


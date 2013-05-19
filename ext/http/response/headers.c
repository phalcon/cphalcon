
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */


/**
 * Phalcon\Http\Response\Headers initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Response_Headers){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, http_response_headers, phalcon_http_response_headers_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_headers_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_headers_ce TSRMLS_CC, 1, phalcon_http_response_headersinterface_ce);

	return SUCCESS;
}

/**
 * Sets a header to be sent at the end of the request
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set){

	zval *name, *value;

	phalcon_fetch_params(0, 2, 0, &name, &value);
	
	phalcon_update_property_array(this_ptr, SL("_headers"), name, value TSRMLS_CC);
	
}

/**
 * Gets a header value from the internal bag
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get){

	zval *name, *headers, *header_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(headers);
	phalcon_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (phalcon_array_isset(headers, name)) {
		PHALCON_OBS_VAR(header_value);
		phalcon_array_fetch(&header_value, headers, name, PH_NOISY_CC);
		RETURN_CCTOR(header_value);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string $header
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw){

	zval *header, *zval_null;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &header);
	
	PHALCON_INIT_VAR(zval_null);
	phalcon_update_property_array(this_ptr, SL("_headers"), header, zval_null TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends the headers to the client
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send){

	zval *headers_was_sent, *t, *headers, *value = NULL, *header = NULL;
	zval *http_header = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers_was_sent);
	PHALCON_CALL_FUNC(headers_was_sent, "headers_sent");
	if (!zend_is_true(headers_was_sent)) {
	
		PHALCON_INIT_VAR(t);
		ZVAL_BOOL(t, 1);
	
		PHALCON_OBS_VAR(headers);
		phalcon_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(headers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(header, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			if (PHALCON_IS_NOT_EMPTY(value)) {
				PHALCON_INIT_NVAR(http_header);
				PHALCON_CONCAT_VSV(http_header, header, ": ", value);
				phalcon_call_func_p2_noret("header", http_header, t);
			} else {
				phalcon_call_func_p2_noret("header", header, t);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Reset set headers
 *
 */
PHP_METHOD(Phalcon_Http_Response_Headers, reset){

	zval *empty_array;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_headers"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Restore a Phalcon\Http\Response\Headers object
 *
 * @param array $data
 * @return Phalcon\Http\Response\Headers
 */
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state){

	zval *data, *headers, *data_headers, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	PHALCON_INIT_VAR(headers);
	object_init_ex(headers, phalcon_http_response_headers_ce);
	if (phalcon_array_isset_string(data, SS("_headers"))) {
	
		PHALCON_OBS_VAR(data_headers);
		phalcon_array_fetch_string(&data_headers, data, SL("_headers"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(data_headers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			phalcon_call_method_p2_noret(headers, "set", key, value);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_CTOR(headers);
}


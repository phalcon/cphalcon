/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "http/response/headers.h"
#include "http/response/headersinterface.h"

#include <main/SAPI.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
zend_class_entry *phalcon_http_response_headers_ce;

PHP_METHOD(Phalcon_Http_Response_Headers, set);
PHP_METHOD(Phalcon_Http_Response_Headers, get);
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw);
PHP_METHOD(Phalcon_Http_Response_Headers, remove);
PHP_METHOD(Phalcon_Http_Response_Headers, send);
PHP_METHOD(Phalcon_Http_Response_Headers, reset);
PHP_METHOD(Phalcon_Http_Response_Headers, toArray);
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_response_headers_method_entry[] = {
	PHP_ME(Phalcon_Http_Response_Headers, set, arginfo_phalcon_http_response_headersinterface_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, get, arginfo_phalcon_http_response_headersinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, setRaw, arginfo_phalcon_http_response_headersinterface_setraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, remove, arginfo_phalcon_http_response_headersinterface_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, __set_state, arginfo_phalcon_http_response_headers___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

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

	phalcon_fetch_params(0, 1, 0, &name);
	
	headers = phalcon_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&header_value, headers, name)) {
		RETURN_ZVAL(header_value, 1, 0);
	}
	
	RETURN_FALSE;
}

/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string $header
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw){

	zval *header;

	phalcon_fetch_params(0, 1, 0, &header);
	
	phalcon_update_property_array(this_ptr, SL("_headers"), header, PHALCON_GLOBAL(z_null) TSRMLS_CC);
}

/**
 * Removes a header to be sent at the end of the request
 *
 * @param string $header Header name
 */
PHP_METHOD(Phalcon_Http_Response_Headers, remove){

	zval *header_index, *headers;

	phalcon_fetch_params(0, 1, 0, &header_index);

	headers = phalcon_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY TSRMLS_CC);

	phalcon_array_unset(&headers, header_index, 0);

	phalcon_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
}

/**
 * Sends the headers to the client
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send){

	sapi_header_line ctr = { NULL, 0, 0 };

	if (!SG(headers_sent)) {
		zval *headers = phalcon_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY TSRMLS_CC);
		zval **value;
		HashPosition hp0;

		if (Z_TYPE_P(headers) != IS_ARRAY) {
			/* No headers to send */
			RETURN_TRUE;
		}
	
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(headers), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(headers), (void**)&value, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(headers), &hp0)
		) {
			zval header = phalcon_get_current_key_w(Z_ARRVAL_P(headers), &hp0);

			if (PHALCON_IS_NOT_EMPTY(*value)) {
				zval *http_header;
				
				MAKE_STD_ZVAL(http_header);
				PHALCON_CONCAT_VSV(http_header, &header, ": ", *value);
				ctr.line     = Z_STRVAL_P(http_header);
				ctr.line_len = Z_STRLEN_P(http_header);
				sapi_header_op(SAPI_HEADER_REPLACE, &ctr TSRMLS_CC);
				zval_ptr_dtor(&http_header);
			}
			else if (Z_TYPE(header) == IS_STRING) {
				ctr.line     = Z_STRVAL(header);
				ctr.line_len = Z_STRLEN(header);
				sapi_header_op(SAPI_HEADER_REPLACE, &ctr TSRMLS_CC);
			}
			else {
				zval *tmp, *pheader = &header;

				MAKE_STD_ZVAL(tmp);
				ZVAL_ZVAL(tmp, pheader, 1, 0);
				convert_to_string(tmp);

				ctr.line     = Z_STRVAL_P(tmp);
				ctr.line_len = Z_STRLEN_P(tmp);
				sapi_header_op(SAPI_HEADER_REPLACE, &ctr TSRMLS_CC);

				zval_ptr_dtor(&tmp);
			}
		}
	
		RETURN_TRUE;
	}
	
	RETURN_FALSE;
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
 * Returns the current headers as an array
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Response_Headers, toArray){


	RETURN_MEMBER(this_ptr, "_headers");
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
		phalcon_array_fetch_string(&data_headers, data, SL("_headers"), PH_NOISY);
	
		phalcon_is_iterable(data_headers, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			PHALCON_CALL_METHOD(NULL, headers, "set", key, value);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_CTOR(headers);
}

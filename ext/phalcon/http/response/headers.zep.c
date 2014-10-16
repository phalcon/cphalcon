
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


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
/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, phalcon, http_response_headers, phalcon_http_response_headers_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_headers_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_headers_ce TSRMLS_CC, 1, phalcon_http_response_headersinterface_ce);
	return SUCCESS;

}

/**
 * Sets a header to be sent at the end of the request
 *
 * @param string name
 * @param string value
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set) {

	zval *name, *value;

	zephir_fetch_params(0, 2, 0, &name, &value);



	zephir_update_property_array(this_ptr, SL("_headers"), name, value TSRMLS_CC);

}

/**
 * Gets a header value from the internal bag
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get) {

	zval *name, *headers, *headerValue;

	zephir_fetch_params(0, 1, 0, &name);



	headers = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&headerValue, headers, name, 1 TSRMLS_CC)) {
		RETURN_CTORW(headerValue);
	}
	RETURN_BOOL(0);

}

/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string header
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw) {

	zval *header;

	zephir_fetch_params(0, 1, 0, &header);



	zephir_update_property_array(this_ptr, SL("_headers"), header, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

/**
 * Removes a header to be sent at the end of the request
 *
 * @param string header Header name
 */
PHP_METHOD(Phalcon_Http_Response_Headers, remove) {

	zval *header_param = NULL, *headers;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(header, header_param);


	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	zephir_array_unset(&headers, header, PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends the headers to the client
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zval *header = NULL, *value = NULL, *_0 = NULL, *_2, **_5, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
		zephir_is_iterable(_2, &_4, &_3, 0, 0, "phalcon/http/response/headers.zep", 98);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(header, _4, _3);
			ZEPHIR_GET_HVALUE(value, _5);
			if (!(ZEPHIR_IS_EMPTY(value))) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_VSV(_6, header, ": ", value);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, _6, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, header, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
			}
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reset set headers
 *
 */
PHP_METHOD(Phalcon_Http_Response_Headers, reset) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_headers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current headers as an array
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Response_Headers, toArray) {


	RETURN_MEMBER(this_ptr, "_headers");

}

/**
 * Restore a Phalcon\Http\Response\Headers object
 *
 * @param array data
 * @return Phalcon\Http\Response\Headers
 */
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state) {

	zephir_fcall_cache_entry *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *headers, *key = NULL, *value = NULL, *dataHeaders, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(headers);
	object_init_ex(headers, phalcon_http_response_headers_ce);
	if (zephir_has_constructor(headers TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(dataHeaders);
	if (zephir_array_isset_string_fetch(&dataHeaders, data, SS("_headers"), 0 TSRMLS_CC)) {
		zephir_is_iterable(dataHeaders, &_1, &_0, 0, 0, "phalcon/http/response/headers.zep", 136);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			ZEPHIR_CALL_METHOD(NULL, headers, "set", &_3, key, value);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(headers);

}


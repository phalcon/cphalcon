
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 *
 */

PHP_METHOD(Phalcon_Http_Response_Headers, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_http_response_headers_ce, this_ptr, SL("_headers"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets a header to be sent at the end of the request
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set){

	zval *name = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, name, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_headers"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a header value from the internal bag
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get){

	zval *name = NULL, *headers = NULL, *header_value = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(headers, name);
	if (eval_int) {
		PHALCON_INIT_VAR(header_value);
		phalcon_array_fetch(&header_value, headers, name, PH_NOISY_CC);
		
		RETURN_CCTOR(header_value);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string $header
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw){

	zval *header = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PH_NOISY_CC);
	phalcon_array_update_zval_bool(&t0, header, 0, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_headers"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends the headers to the client
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send){

	zval *headers_was_sent = NULL, *t = NULL, *headers = NULL, *value = NULL, *header = NULL;
	zval *http_header = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers_was_sent);
	PHALCON_CALL_FUNC(headers_was_sent, "headers_sent");
	if (!zend_is_true(headers_was_sent)) {
		PHALCON_INIT_VAR(t);
		ZVAL_BOOL(t, 1);
		
		PHALCON_INIT_VAR(headers);
		phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(headers TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(headers);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e2ae_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_e2ae_0;
			}
			
			PHALCON_INIT_VAR(header);
			PHALCON_GET_FOREACH_KEY(header, ah0, hp0);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			if (zend_is_true(value)) {
				PHALCON_INIT_VAR(http_header);
				PHALCON_CONCAT_VSV(http_header, header, ": ", value);
				PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", http_header, t);
			} else {
				PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", header, t);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_e2ae_0;
		fee_e2ae_0:
		
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Reset set headers
 *
 */
PHP_METHOD(Phalcon_Http_Response_Headers, reset){

	zval *empty_array = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_headers"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Restore a Phalcon\Http\Response\Headers object
 */
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state){

	zval *data = NULL, *headers = NULL, *data_headers = NULL, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	object_init_ex(headers, phalcon_http_response_headers_ce);
	PHALCON_CALL_METHOD_NORETURN(headers, "__construct", PH_CHECK);
	eval_int = phalcon_array_isset_string(data, SL("_headers")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(data_headers);
		phalcon_array_fetch_string(&data_headers, data, SL("_headers"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(data_headers TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(data_headers);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e2ae_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_e2ae_1;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", key, value, PH_NO_CHECK);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_e2ae_1;
		fee_e2ae_1:
		if(0){}
		
	}
	
	
	RETURN_CTOR(headers);
}


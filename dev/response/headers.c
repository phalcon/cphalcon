
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
 * Phalcon_Response_Headers
 *
 * This class is a bag to manage the response headers
 *
 *
 */

PHP_METHOD(Phalcon_Response_Headers, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_response_headers_ce, this_ptr, SL("_headers"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets a header to be sent at the end of the request
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Response_Headers, set){

	zval *name = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, name, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_headers"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a header value from the internal bag
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Response_Headers, get){

	zval *name = NULL, *headers = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(headers, t0);
	eval_int = phalcon_array_isset(headers, name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, headers, name, PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(r0);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string $header
 */
PHP_METHOD(Phalcon_Response_Headers, setRaw){

	zval *header = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t1, header, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_headers"), t1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends the headers to the client
 */
PHP_METHOD(Phalcon_Response_Headers, send){

	zval *t = NULL, *value = NULL, *header = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "headers_sent");
	if (!zend_is_true(r0)) {
		PHALCON_INIT_VAR(t);
		ZVAL_BOOL(t, 1);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(t0 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(t0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_ae51_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ae51_0;
			} else {
				PHALCON_INIT_VAR(header);
				PHALCON_GET_FOREACH_KEY(header, ah0, hp0);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			if (zend_is_true(value)) {
				PHALCON_INIT_VAR(r1);
				PHALCON_CONCAT_VSV(r1, header, ": ", value);
				PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r1, t);
			} else {
				PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", header, t);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ae51_0;
			fee_ae51_0:
			if(0){}
		} else {
			return;
		}
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}


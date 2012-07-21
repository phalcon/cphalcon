
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
#include "kernel/concat.h"

/**
 * Phalcon\Response
 *
 * Encapsulates the HTTP response message.
 *
 *
 */

/**
 * Returns singleton Phalcon\Response instance
 *
 * @return Phalcon\Response
 */
PHP_METHOD(Phalcon_Response, getInstance){

	zval *instance = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(instance);
	phalcon_read_static_property(&instance, SL("phalcon\\response"), SL("_instance") TSRMLS_CC);
	if (!zend_is_true(instance)) {
		PHALCON_INIT_VAR(instance);
		object_init_ex(instance, phalcon_response_ce);
		phalcon_update_static_property(SL("phalcon\\response"), SL("_instance"), instance TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(instance);
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param strign $message
 * @return Phalcon\Response
 */
PHP_METHOD(Phalcon_Response, setStatusCode){

	zval *code = NULL, *message = NULL, *headers = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &code, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SVSV(r0, "HTTP/1.1 ", code, " ", message);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(headers, "setraw", r0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Status", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_VSV(r1, code, " ", message);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", c0, r1, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Returns headers set by the user
 *
 * @return Phalcon\Response\Headers
 */
PHP_METHOD(Phalcon_Response, getHeaders){

	zval *headers = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (!zend_is_true(headers)) {
		PHALCON_INIT_VAR(headers);
		object_init_ex(headers, phalcon_response_headers_ce);
		PHALCON_CALL_METHOD_NORETURN(headers, "__construct", PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(headers);
}

/**
 * Overwrites a header in the response
 *
 * @param string $name
 * @param string $value
 * @return Phalcon\Response
 */
PHP_METHOD(Phalcon_Response, setHeader){

	zval *name = NULL, *value = NULL, *headers = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", name, value, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Send a raw header to the response
 *
 * @param string $header
 * @return Phalcon\Response
 */
PHP_METHOD(Phalcon_Response, setRawHeader){

	zval *header = NULL, *headers = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setraw", header, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sets output expire time header
 *
 * @param DateTime $datetime
 * @return Phalcon\Response
 */
PHP_METHOD(Phalcon_Response, setExpires){

	zval *datetime = NULL, *headers = NULL, *date = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &datetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(datetime) == IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_response_exception_ce, "datetime parameter must be an instance of DateTime");
		return;
	}
	
	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	if (phalcon_clone(i0, datetime TSRMLS_CC) == FAILURE){
		return;
	}
	PHALCON_CPY_WRT(date, i0);
	ce0 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "UTC", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(date, "settimezone", i1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Expires", 1);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "D, d M Y H:i:s", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, date, "format", c2, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_VS(r1, r0, " GMT");
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c1, r1, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sends a Not-Modified response
 */
PHP_METHOD(Phalcon_Response, setNotModified){

	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 304);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Not modified", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", c0, c1, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sets the response content-type mime, optionally the charset
 *
 */
PHP_METHOD(Phalcon_Response, setContentType){


	
}

/**
 * Redirect by HTTP to another action or URL
 *
 * @param string $location
 * @param boolean $externalRedirect
 * @param int $statusCode
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, redirect){

	zval *location = NULL, *external_redirect = NULL, *status_code = NULL;
	zval *header = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &location, &external_redirect, &status_code) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!external_redirect) {
		PHALCON_ALLOC_ZVAL_MM(external_redirect);
		ZVAL_BOOL(external_redirect, 0);
	}
	
	if (!status_code) {
		PHALCON_ALLOC_ZVAL_MM(status_code);
		ZVAL_LONG(status_code, 302);
	}
	
	if (zend_is_true(external_redirect)) {
		PHALCON_CPY_WRT(header, location);
	} else {
		PHALCON_INIT_VAR(header);
		PHALCON_CALL_STATIC_PARAMS_1(header, "phalcon\\utils", "geturl", location);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Redirect", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", status_code, c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Location", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c1, header, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sets HTTP response body
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, setContent){

	zval *content = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_content"), content TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Appends a string to the HTTP response body
 *
 * @param string $content
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, appendContent){

	zval *content = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_content"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, content TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_content"), r0 TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Gets HTTP response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Response, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_content"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sends headers to the client
 *
 */
PHP_METHOD(Phalcon_Response, sendHeaders){

	zval *headers = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (zend_is_true(headers)) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, send){

	zval *headers = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (zend_is_true(headers)) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PH_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(t0, 1);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Resets the internal singleton
 */
PHP_METHOD(Phalcon_Response, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("phalcon\\response"), SL("_instance"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}


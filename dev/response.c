
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
 * Phalcon_Response
 *
 * Encapsulates the HTTP response message.
 *
 *
 */

/**
 * Returns singleton Phalcon_Response instance
 *
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, getInstance){

	zval *instance = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Response"), SL("_instance") TSRMLS_CC);
	PHALCON_CPY_WRT(instance, t0);
	if (!zend_is_true(instance)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_response_ce);
		PHALCON_CPY_WRT(instance, i0);
		phalcon_update_static_property(SL("Phalcon_Response"), SL("_instance"), instance TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(instance);
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param strign $message
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, setStatusCode){

	zval *code = NULL, *message = NULL, *headers = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &code, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getheaders", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(headers, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_SVSV(r1, "HTTP/1.1 ", code, " ", message);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(headers, "setraw", r1, PHALCON_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Status", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VSV(r2, code, " ", message);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", c0, r2, PHALCON_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	
	RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Returns headers set by the user
 *
 * @return Phalcon_Response_Headers
 */
PHP_METHOD(Phalcon_Response, getHeaders){

	zval *headers = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(headers, t0);
	if (!zend_is_true(headers)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_response_headers_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(headers, i0);
		phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(headers);
}

/**
 * Overwrites a header in the response
 *
 *
 *
 * @param string $name
 * @param string $value
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, setHeader){

	zval *name = NULL, *value = NULL, *headers = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getheaders", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(headers, r0);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", name, value, PHALCON_NO_CHECK);
	
	RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Send a raw header to the response
 *
 *
*
 * @param string $header
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, setRawHeader){

	zval *header = NULL, *headers = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getheaders", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(headers, r0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setraw", header, PHALCON_NO_CHECK);
	
	RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Sets output expire time header
 *
 * @param DateTime $datetime
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, setExpires){

	zval *datetime = NULL, *headers = NULL, *date = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getheaders", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(headers, r0);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	if (phalcon_clone(i0, datetime TSRMLS_CC) == FAILURE){
		return;
	}
	PHALCON_CPY_WRT(date, i0);
	ce0 = zend_fetch_class("DateTimeZone", strlen("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "UTC", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(date, "settimezone", i1, PHALCON_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Expires", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "D, d M Y H:i:s", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r2, date, "format", c2, PHALCON_NO_CHECK);
	PHALCON_CONCAT_VS(r1, r2, " GMT");
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c1, r1, PHALCON_NO_CHECK);
	
	RETURN_CHECK_CTOR(this_ptr);
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
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", c0, c1, PHALCON_NO_CHECK);
	
	RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Sets the response content-type mime, optionally the charset
 *
 *
 */
PHP_METHOD(Phalcon_Response, setContentType){


	
}

/**
 * Redirect by HTTP to another action or URL
 *
 *
 *
 * @param string $location
 * @param boolean $externalRedirect
 * @param int $statusCode
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, redirect){

	zval *location = NULL, *external_redirect = NULL, *status_code = NULL;
	zval *header = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &location, &external_redirect, &status_code) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!external_redirect) {
		PHALCON_INIT_VAR(external_redirect);
		ZVAL_BOOL(external_redirect, 0);
	}
	
	if (!status_code) {
		PHALCON_INIT_VAR(status_code);
		ZVAL_LONG(status_code, 302);
	}
	
	if (zend_is_true(external_redirect)) {
		PHALCON_CPY_WRT(header, location);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_utils", "geturl", location);
		PHALCON_CPY_WRT(header, r0);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Redirect", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", status_code, c0, PHALCON_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Location", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c1, header, PHALCON_NO_CHECK);
	
	RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Sets HTTP response body
*
 *
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
	
	RETURN_CHECK_CTOR(this_ptr);
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
	phalcon_read_property(&t0, this_ptr, SL("_content"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, content TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_content"), r0 TSRMLS_CC);
	
	RETURN_CHECK_CTOR(this_ptr);
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
	phalcon_read_property(&t0, this_ptr, SL("_content"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Sends headers to the client
 *
 */
PHP_METHOD(Phalcon_Response, sendHeaders){

	zval *headers = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(headers, t0);
	if (zend_is_true(headers)) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PHALCON_NO_CHECK);
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
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_headers"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(headers, t0);
	if (zend_is_true(headers)) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_content"), PHALCON_NOISY TSRMLS_CC);
	zend_print_zval(t1, 1);
	
	RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Resets the internal singleton
 */
PHP_METHOD(Phalcon_Response, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("Phalcon_Response"), SL("_instance"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}


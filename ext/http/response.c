
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
#include "kernel/exception.h"

/**
 * Phalcon\Http\Response
 *
 * Encapsulates the HTTP response message.
 *
 *<code>
 *$response = new Phalcon\Http\Response();
 *$response->setStatusCode(200, "OK");
 *$response->setContent("<html><body>Hello</body></html>");
 *$response->send();
 *</code>
 */

PHP_METHOD(Phalcon_Http_Response, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Http_Response, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param string $message
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setStatusCode){

	zval *code = NULL, *message = NULL, *headers = NULL, *header_value = NULL, *status_value = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &code, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(header_value);
	PHALCON_CONCAT_SVSV(header_value, "HTTP/1.1 ", code, " ", message);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(headers, "setraw", header_value, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(status_value);
	PHALCON_CONCAT_VSV(status_value, code, " ", message);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Status", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", c0, status_value, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Returns headers set by the user
 *
 * @return Phalcon\Http\Response\Headers
 */
PHP_METHOD(Phalcon_Http_Response, getHeaders){

	zval *headers = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_NULL) {
		PHALCON_INIT_VAR(headers);
		object_init_ex(headers, phalcon_http_response_headers_ce);
		PHALCON_CALL_METHOD_NORETURN(headers, "__construct", PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(headers);
}

/**
 * Overwrites a header in the response
 *
 *<code>
 *$response->setHeader("Content-Type", "text/plain");
 *</code>
 *
 * @param string $name
 * @param string $value
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setHeader){

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
 *<code>
 *$response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 *
 * @param string $header
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader){

	zval *header = NULL, *headers = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(headers, "setraw", header, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders){

	zval *headers = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(headers, "reset", PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sets output expire time header
 *
 * @param DateTime $datetime
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setExpires){

	zval *datetime = NULL, *headers = NULL, *date = NULL, *timezone = NULL, *utc_format = NULL;
	zval *utc_date = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &datetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(datetime) == IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "datetime parameter must be an instance of DateTime");
		return;
	}
	
	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(date);
	if (phalcon_clone(date, datetime TSRMLS_CC) == FAILURE) {
		return;
	}
	ce0 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(timezone);
	object_init_ex(timezone, ce0);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "UTC", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(timezone, "__construct", c0, PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(date, "settimezone", timezone, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "D, d M Y H:i:s", 1);
	
	PHALCON_INIT_VAR(utc_format);
	PHALCON_CALL_METHOD_PARAMS_1(utc_format, date, "format", c1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(utc_date);
	PHALCON_CONCAT_VS(utc_date, utc_format, " GMT");
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "Expires", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c2, utc_date, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified){

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
 *<code>
 *$response->setContentType('text/plain', 'UTF-8');
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setContentType){

	zval *content_type = NULL, *charset = NULL, *headers = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &content_type, &charset) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!charset) {
		PHALCON_ALLOC_ZVAL_MM(charset);
		ZVAL_NULL(charset);
	}
	
	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Content-Type", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", c0, content_type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Redirect by HTTP to another action or URL
 *
 *<code>
 *$response->redirect("posts/index");
 *$response->redirect("http://en.wikipedia.org", true);
 *$response->redirect("http://www.example.com/new-location", true, 301);
 *</code>
 *
 * @param string $location
 * @param boolean $externalRedirect
 * @param int $statusCode
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, redirect){

	zval *location = NULL, *external_redirect = NULL, *status_code = NULL;
	zval *header = NULL, *dependency_injector = NULL, *url = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

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
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'url' service");
			return;
		}
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "url", 1);
		
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_METHOD_PARAMS_1(url, dependency_injector, "get", c0, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(header);
		PHALCON_CALL_METHOD_PARAMS_1(header, url, "get", location, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Redirect", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", status_code, c1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "Location", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c2, header, PH_NO_CHECK);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sets HTTP response body
 *
 *<code>
 *$response->setContent("<h1>Hello!</h1>");
 *</code>
 *
 * @param string $content
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setContent){

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
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, appendContent){

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
PHP_METHOD(Phalcon_Http_Response, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_content"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sends headers to the client
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, sendHeaders){

	zval *headers = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) != IS_NULL) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, send){

	zval *headers = NULL, *content = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) != IS_NULL) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(content);
	phalcon_read_property(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(content, 1);
	
	RETURN_CCTOR(this_ptr);
}


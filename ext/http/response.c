
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
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *<code>
 *	$response = new Phalcon\Http\Response();
 *	$response->setStatusCode(200, "OK");
 *	$response->setContent("<html><body>Hello</body></html>");
 *	$response->send();
 *</code>
 */


/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Response, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Http_Response, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the HTTP response code
 *
 *<code>
 *$response->setStatusCode(404, "Not Found");
 *</code>
 *
 * @param int $code
 * @param string $message
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setStatusCode){

	zval *code, *message, *headers, *header_value, *status_value;
	zval *status_header;

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
	
	PHALCON_INIT_VAR(status_header);
	ZVAL_STRING(status_header, "Status", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", status_header, status_value, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_headers"), headers TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
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
		PHALCON_INIT_NVAR(headers);
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
 *	$response->setHeader("Content-Type", "text/plain");
 *</code>
 *
 * @param string $name
 * @param string $value
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setHeader){

	zval *name, *value, *headers;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", name, value, PH_NO_CHECK);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Send a raw header to the response
 *
 *<code>
 *	$response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 *
 * @param string $header
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader){

	zval *header, *headers;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(headers, "setraw", header, PH_NO_CHECK);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders){

	zval *headers;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(headers, "reset", PH_NO_CHECK);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Sets output expire time header
 *
 * @param DateTime $datetime
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setExpires){

	zval *datetime, *headers, *date, *utc_zone, *timezone;
	zval *format, *utc_format, *utc_date, *expires_header;
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
	
	PHALCON_INIT_VAR(utc_zone);
	ZVAL_STRING(utc_zone, "UTC", 1);
	ce0 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(timezone);
	object_init_ex(timezone, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(timezone, "__construct", utc_zone, PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(date, "settimezone", timezone, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "D, d M Y H:i:s", 1);
	
	PHALCON_INIT_VAR(utc_format);
	PHALCON_CALL_METHOD_PARAMS_1(utc_format, date, "format", format, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(utc_date);
	PHALCON_CONCAT_VS(utc_date, utc_format, " GMT");
	
	PHALCON_INIT_VAR(expires_header);
	ZVAL_STRING(expires_header, "Expires", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", expires_header, utc_date, PH_NO_CHECK);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified){

	zval *code, *status;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(code);
	ZVAL_LONG(code, 304);
	
	PHALCON_INIT_VAR(status);
	ZVAL_STRING(status, "Not modified", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", code, status, PH_NO_CHECK);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Sets the response content-type mime, optionally the charset
 *
 *<code>
 *	$response->setContentType('application/pdf');
 *	$response->setContentType('text/plain', 'UTF-8');
 *</code>
 *
 * @param string $contentType
 * @param string $charset
 */
PHP_METHOD(Phalcon_Http_Response, setContentType){

	zval *content_type, *charset = NULL, *headers, *name, *header_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &content_type, &charset) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!charset) {
		PHALCON_INIT_NVAR(charset);
	}
	
	PHALCON_INIT_VAR(headers);
	PHALCON_CALL_METHOD(headers, this_ptr, "getheaders", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "Content-Type", 1);
	if (Z_TYPE_P(charset) == IS_NULL) {
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", name, content_type, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(header_value);
		PHALCON_CONCAT_VSV(header_value, content_type, "; charset=", charset);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(headers, "set", name, header_value, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Redirect by HTTP to another action or URL
 *
 *<code>
 *	$response->redirect("posts/index");
 *	$response->redirect("http://en.wikipedia.org", true);
 *	$response->redirect("http://www.example.com/new-location", true, 301);
 *</code>
 *
 * @param string $location
 * @param boolean $externalRedirect
 * @param int $statusCode
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, redirect){

	zval *location, *external_redirect = NULL, *status_code = NULL;
	zval *header = NULL, *dependency_injector, *service;
	zval *url, *status_text, *header_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &location, &external_redirect, &status_code) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!external_redirect) {
		PHALCON_INIT_NVAR(external_redirect);
		ZVAL_BOOL(external_redirect, 0);
	}
	
	if (!status_code) {
		PHALCON_INIT_NVAR(status_code);
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
		
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "url", 1);
		
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_METHOD_PARAMS_1(url, dependency_injector, "getshared", service, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(header);
		PHALCON_CALL_METHOD_PARAMS_1(header, url, "get", location, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(status_text);
	ZVAL_STRING(status_text, "Redirect", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setstatuscode", status_code, status_text, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(header_name);
	ZVAL_STRING(header_name, "Location", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", header_name, header, PH_NO_CHECK);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Sets HTTP response body
 *
 *<code>
 *	$response->setContent("<h1>Hello!</h1>");
 *</code>
 *
 * @param string $content
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setContent){

	zval *content;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_content"), content TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Appends a string to the HTTP response body
 *
 * @param string $content
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, appendContent){

	zval *content;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_content"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, content TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_content"), r0 TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Gets HTTP response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response, getContent){


	RETURN_MEMBER(this_ptr, "_content");
}

/**
 * Sends headers to the client
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, sendHeaders){

	zval *headers;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) != IS_NULL) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PH_NO_CHECK);
	}
	
	
	RETURN_CTOR(this_ptr);
}

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, send){

	zval *headers, *content;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers);
	phalcon_read_property(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) != IS_NULL) {
		PHALCON_CALL_METHOD_NORETURN(headers, "send", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(content);
	phalcon_read_property(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(content, 1);
	
	RETURN_CTOR(this_ptr);
}


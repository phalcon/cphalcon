
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Response, phalcon, http_response, phalcon_http_response_method_entry, 0);

	zend_declare_property_bool(phalcon_http_response_ce, SL("_sent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_ce TSRMLS_CC, 1, phalcon_http_responseinterface_ce);
	zend_class_implements(phalcon_http_response_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Http\Response constructor
 *
 * @param string content
 * @param int code
 * @param string status
 */
PHP_METHOD(Phalcon_Http_Response, __construct) {

	zval *content = NULL, *code = NULL, *status = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &code, &status);

	if (!content) {
		ZEPHIR_CPY_WRT(content, ZEPHIR_GLOBAL(global_null));
	}
	if (!code) {
		ZEPHIR_CPY_WRT(code, ZEPHIR_GLOBAL(global_null));
	}
	if (!status) {
		ZEPHIR_CPY_WRT(status, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(content) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	}
	if ((Z_TYPE_P(code) != IS_NULL)) {
		zephir_call_method_p2_noret(this_ptr, "setstatuscode", code, status);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Response, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Response, getDI) {

	zval *dependencyInjector = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'url' service");
			return;
		}
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	RETURN_CCTOR(dependencyInjector);

}

/**
 * Sets the HTTP response code
 *
 *<code>
 *	$response->setStatusCode(404, "Not Found");
 *</code>
 *
 * @param int code
 * @param string message
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setStatusCode) {

	zval *code_param = NULL, *message_param = NULL, *headers, *_0, *_1, *_2, *_3, *_4, *_5;
	zval *code = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &message_param);

		zephir_get_strval(code, code_param);
		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "HTTP/1.1 ", code);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, " ");
	ZEPHIR_INIT_VAR(_2);
	concat_function(_2, _1, message TSRMLS_CC);
	zephir_call_method_p1_noret(headers, "setraw", _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, code, " ");
	ZEPHIR_INIT_VAR(_4);
	concat_function(_4, _3, message TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "Status", 1);
	zephir_call_method_p2_noret(headers, "set", _4, _5);
	zephir_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a headers bag for the response externally
 *
 * @param Phalcon\Http\Response\HeadersInterface headers
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setHeaders) {

	zval *headers;

	zephir_fetch_params(0, 1, 0, &headers);



	zephir_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns headers set by the user
 *
 * @return Phalcon\Http\Response\HeadersInterface
 */
PHP_METHOD(Phalcon_Http_Response, getHeaders) {

	zval *headers;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if ((Z_TYPE_P(headers) == IS_NULL)) {
		ZEPHIR_INIT_BNVAR(headers);
		object_init_ex(headers, phalcon_http_response_headers_ce);
		zephir_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	}
	RETURN_CCTOR(headers);

}

/**
 * Sets a cookies bag for the response externally
 *
 * @param Phalcon\Http\Response\CookiesInterface cookies
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setCookies) {

	zval *cookies;

	zephir_fetch_params(0, 1, 0, &cookies);



	if ((Z_TYPE_P(cookies) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_http_response_exception_ce, "The cookies bag is not valid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_cookies"), cookies TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns coookies set by the user
 *
 * @return Phalcon\Http\Response\CookiesInterface
 */
PHP_METHOD(Phalcon_Http_Response, getCookies) {


	RETURN_MEMBER(this_ptr, "_cookies");

}

/**
 * Overwrites a header in the response
 *
 *<code>
 *	$response->setHeader("Content-Type", "text/plain");
 *</code>
 *
 * @param string name
 * @param string value
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setHeader) {

	zval *name_param = NULL, *value, *headers;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

		zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	zephir_call_method_p2_noret(headers, "set", name, value);
	RETURN_THIS();

}

/**
 * Send a raw header to the response
 *
 *<code>
 *	response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 *
 * @param string header
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader) {

	zval *header_param = NULL, *headers;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

		zephir_get_strval(header, header_param);


	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	zephir_call_method_p1_noret(headers, "setraw", header);
	RETURN_THIS();

}

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders) {

	zval *headers;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	zephir_call_method_noret(headers, "reset");
	RETURN_THIS();

}

/**
 * Sets a Expires header to use HTTP cache
 *
 *<code>
 *	$this->response->setExpires(new DateTime());
 *</code>
 *
 * @param DateTime datetime
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setExpires) {

	zend_class_entry *_1;
	zval *datetime, *headers, *date, *_0, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	ZEPHIR_INIT_VAR(date);
	ZVAL_NULL(date);
	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "UTC", 1);
	zephir_call_method_p1_noret(_0, "__construct", _2);
	zephir_call_method_p1_noret(date, "settimezone", _0);
	ZEPHIR_INIT_BNVAR(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "D, d M Y H:i:s", 1);
	zephir_call_method_p1(_2, date, "format", _3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _2, " GMT");
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Expires", 1);
	zephir_call_method_p2_noret(this_ptr, "setheader", _3, _4);
	RETURN_THIS();

}

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Not modified", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 304);
	zephir_call_method_p2_noret(this_ptr, "setstatuscode", _0, _1);
	RETURN_THIS();

}

/**
 * Sets the response content-type mime, optionally the charset
 *
 *<code>
 *	$response->setContentType('application/pdf');
 *	$response->setContentType('text/plain', 'UTF-8');
 *</code>
 *
 * @param string contentType
 * @param string charset
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setContentType) {

	zval *contentType_param = NULL, *charset = NULL, *headers, *name, *_0, *_1;
	zval *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &contentType_param, &charset);

		zephir_get_strval(contentType, contentType_param);
	if (!charset) {
		ZEPHIR_CPY_WRT(charset, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	ZEPHIR_INIT_VAR(name);
	ZVAL_STRING(name, "Content-Type", 1);
	if ((Z_TYPE_P(charset) == IS_NULL)) {
		zephir_call_method_p2_noret(headers, "set", name, contentType);
	} else {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, contentType, "; charset=");
		ZEPHIR_INIT_VAR(_1);
		concat_function(_1, _0, charset TSRMLS_CC);
		zephir_call_method_p2_noret(headers, "set", name, _1);
	}
	RETURN_THIS();

}

/**
 * Set a custom ETag
 *
 *<code>
 *	$response->setEtag(md5(time()));
 *</code>
 *
 * @param string etag
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setEtag) {

	zval *etag_param = NULL, *headers, *_0;
	zval *etag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &etag_param);

		zephir_get_strval(etag, etag_param);


	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Etag", 1);
	zephir_call_method_p2_noret(headers, "set", _0, etag);
	RETURN_THIS();

}

/**
 * Redirect by HTTP to another action or URL
 *
 *<code>
 *  //Using a string redirect (internal/external)
 *	$response->redirect("posts/index");
 *	$response->redirect("http://en.wikipedia.org", true);
 *	$response->redirect("http://www.example.com/new-location", true, 301);
 *
 *	//Making a redirection based on a named route
 *	$response->redirect(array(
 *		"for" => "index-lang",
 *		"lang" => "jp",
 *		"controller" => "index"
 *	));
 *</code>
 *
 * @param string|array location
 * @param boolean externalRedirect
 * @param int statusCode
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, redirect) {

	zval *location = NULL, *externalRedirect = NULL, *statusCode = NULL, *header = NULL, *url = NULL, *dependencyInjector, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &location, &externalRedirect, &statusCode);

	if (!location) {
		ZEPHIR_CPY_WRT(location, ZEPHIR_GLOBAL(global_null));
	}
	if (!externalRedirect) {
		ZEPHIR_CPY_WRT(externalRedirect, ZEPHIR_GLOBAL(global_false));
	}
	if (!statusCode) {
		ZEPHIR_INIT_VAR(statusCode);
		ZVAL_LONG(statusCode, 302);
	}


	if (zephir_is_true(externalRedirect)) {
		ZEPHIR_CPY_WRT(header, location);
	} else {
		ZEPHIR_INIT_VAR(dependencyInjector);
		zephir_call_method(dependencyInjector, this_ptr, "getdi");
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "url", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
		ZEPHIR_CPY_WRT(url, _0);
		ZEPHIR_INIT_VAR(header);
		zephir_call_method_p1(header, url, "get", location);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Redirect", 1);
	zephir_call_method_p2_noret(this_ptr, "setstatuscode", statusCode, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Location", 1);
	zephir_call_method_p2_noret(this_ptr, "setheader", _0, header);
	RETURN_THIS();

}

/**
 * Sets HTTP response body
 *
 *<code>
 *	response->setContent("<h1>Hello!</h1>");
 *</code>
 *
 * @param string content
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	zephir_fetch_params(0, 1, 0, &content_param);

		zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets HTTP response body. The parameter is automatically converted to JSON
 *
 *<code>
 *	response->setJsonContent(array("status" => "OK"));
 *</code>
 *
 * @param mixed content
 * @param int jsonOptions
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setJsonContent) {

	zval *content, *jsonOptions = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &content, &jsonOptions);

	if (!jsonOptions) {
		ZEPHIR_INIT_VAR(jsonOptions);
		ZVAL_LONG(jsonOptions, 0);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p2(_0, "json_encode", content, jsonOptions);
	zephir_update_property_this(this_ptr, SL("_content"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a string to the HTTP response body
 *
 * @param string content
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, appendContent) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	RETURN_THISW();

}

/**
 * Gets the HTTP response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response, getContent) {


	RETURN_MEMBER(this_ptr, "_content");

}

/**
 * Check if the response is already sent
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response, isSent) {


	RETURN_MEMBER(this_ptr, "_sent");

}

/**
 * Sends headers to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, sendHeaders) {

	zval *headers;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if ((Z_TYPE_P(headers) == IS_OBJECT)) {
		zephir_call_method_noret(headers, "send");
	}
	RETURN_THIS();

}

/**
 * Sends cookies to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, sendCookies) {

	zval *cookies;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(cookies);
	zephir_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if ((Z_TYPE_P(cookies) == IS_OBJECT)) {
		zephir_call_method_noret(cookies, "send");
	}
	RETURN_THIS();

}

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, send) {

	zval *headers, *cookies, *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_sent"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "Response was already sent");
		return;
	}
	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if ((Z_TYPE_P(cookies) == IS_OBJECT)) {
		zephir_call_method_noret(headers, "send");
	}
	ZEPHIR_OBS_VAR(cookies);
	zephir_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if ((Z_TYPE_P(cookies) == IS_OBJECT)) {
		zephir_call_method_noret(cookies, "send");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(_1, 0);
	zephir_update_property_this(this_ptr, SL("_sent"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets an attached file to be sent at the end of the request
 *
 * @param string filePath
 * @param string attachmentName
 * @return <Phalcon\Http\ResponseInterface>
 */
PHP_METHOD(Phalcon_Http_Response, setFileToSend) {

	zval *filePath_param = NULL, *attachmentName = NULL, *basePath = NULL, *headers, *_0, *_1;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &attachmentName);

		zephir_get_strval(filePath, filePath_param);
	if (!attachmentName) {
		ZEPHIR_CPY_WRT(attachmentName, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(attachmentName) == IS_STRING)) {
		ZEPHIR_INIT_VAR(basePath);
		zephir_call_func_p1(basePath, "basename", filePath);
	} else {
		ZEPHIR_CPY_WRT(basePath, attachmentName);
	}
	ZEPHIR_INIT_VAR(headers);
	zephir_call_method(headers, this_ptr, "getheaders");
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Content-Description: File Transfer", 1);
	zephir_call_method_p1_noret(headers, "setraw", _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "Content-Disposition: attachment; filename=", basePath);
	zephir_call_method_p1_noret(headers, "setraw", _1);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "Content-Transfer-Encoding: binary", 1);
	zephir_call_method_p1_noret(headers, "setraw", _0);
	zephir_update_property_this(this_ptr, SL("_file"), filePath TSRMLS_CC);
	RETURN_THIS();

}


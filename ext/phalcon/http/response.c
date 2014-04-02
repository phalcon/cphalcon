
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
#include "kernel/string.h"
#include "kernel/file.h"


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
 * Phalcon\Http\Response
 *
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *<code>
 *	$response = new \Phalcon\Http\Response();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, *code = NULL, *status = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &code, &status);

	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!code) {
		code = ZEPHIR_GLOBAL(global_null);
	}
	if (!status) {
		status = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(content) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	}
	if (Z_TYPE_P(code) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, code, status);
		zephir_check_call_status();
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



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Response, getDI) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *dependencyInjector = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'url' service", "phalcon/http/response.zep", 90);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *code_param = NULL, *message_param = NULL, *headers = NULL, *_2;
	zval *code = NULL, *message = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &message_param);

	zephir_get_strval(code, code_param);
	zephir_get_strval(message, message_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVSV(_0, "HTTP/1.1 ", code, " ", message);
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, code, " ", message);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Status", 0);
	ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, _2, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_NULL) {
		ZEPHIR_INIT_BNVAR(headers);
		object_init_ex(headers, phalcon_http_response_headers_ce);
		if (zephir_has_constructor(headers TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL);
			zephir_check_call_status();
		}
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



	if (!(zephir_instance_of_ev(cookies, phalcon_http_response_cookiesinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'cookies' must be an instance of 'Phalcon\\Http\\Response\\CookiesInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(cookies) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_http_response_exception_ce, "The cookies bag is not valid", "phalcon/http/response.zep", 168);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *headers = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Send a raw header to the response
 *
 *<code>
 *	$response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 *
 * @param string header
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *headers = NULL;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(header, header_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, header);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, headers, "reset", NULL);
	zephir_check_call_status();
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, *headers = NULL, *date, *_0, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	if (!(zephir_is_instance_of(datetime, SL("DateTime") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'datetime' must be an instance of 'DateTime'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(date);
	if (zephir_clone(date, datetime TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "UTC", 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, date, "settimezone", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "D, d M Y H:i:s", 0);
	ZEPHIR_CALL_METHOD(&_3, date, "format", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, " GMT");
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "Expires", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, _2, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Not modified", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 304);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *contentType_param = NULL, *charset = NULL, *headers = NULL, *name, *_0;
	zval *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &contentType_param, &charset);

	zephir_get_strval(contentType, contentType_param);
	if (!charset) {
		charset = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(name);
	ZVAL_STRING(name, "Content-Type", 1);
	if (Z_TYPE_P(charset) == IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, name, contentType);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, contentType, "; charset=", charset);
		ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, name, _0);
		zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *etag_param = NULL, *headers = NULL, *_0;
	zval *etag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &etag_param);

	zephir_get_strval(etag, etag_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Etag", 0);
	ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, _0, etag);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, *externalRedirect = NULL, *statusCode = NULL, *header = NULL, *url = NULL, *dependencyInjector = NULL, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &location, &externalRedirect, &statusCode);

	if (!location) {
		location = ZEPHIR_GLOBAL(global_null);
	}
	if (!externalRedirect) {
		externalRedirect = ZEPHIR_GLOBAL(global_false);
	}
	if (!statusCode) {
		ZEPHIR_INIT_VAR(statusCode);
		ZVAL_LONG(statusCode, 302);
	}


	if (zephir_is_true(externalRedirect)) {
		ZEPHIR_CPY_WRT(header, location);
	} else {
		ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "url", 0);
		ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "getshared", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(url, _0);
		ZEPHIR_CALL_METHOD(&header, url, "get", NULL, location);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Redirect", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, statusCode, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Location", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, _1, header);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets HTTP response body. The parameter is automatically converted to JSON
 *
 *<code>
 *	$response->setJsonContent(array("status" => "OK"));
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
	zephir_json_encode(_0, &(_0), content, zephir_get_intval(jsonOptions)  TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, headers, "send", NULL);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sends cookies to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, sendCookies) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cookies;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(cookies);
	zephir_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (Z_TYPE_P(cookies) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, cookies, "send", NULL);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers, *cookies, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_sent"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "Response was already sent", "phalcon/http/response.zep", 470);
		return;
	}
	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, headers, "send", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(cookies);
	zephir_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (Z_TYPE_P(cookies) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, cookies, "send", NULL);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(_0, 0);
	zephir_update_property_this(this_ptr, SL("_sent"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets an attached file to be sent at the end of the request
 *
 * @param string filePath
 * @param string attachmentName
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setFileToSend) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *attachmentName = NULL, *basePath = NULL, *headers = NULL, *_0, *_1;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &attachmentName);

	zephir_get_strval(filePath, filePath_param);
	if (!attachmentName) {
		attachmentName = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(attachmentName) == IS_STRING) {
		ZEPHIR_INIT_VAR(basePath);
		zephir_basename(basePath, filePath TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(basePath, attachmentName);
	}
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Content-Description: File Transfer", 0);
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "Content-Disposition: attachment; filename=", basePath);
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "Content-Transfer-Encoding: binary", 0);
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_file"), filePath TSRMLS_CC);
	RETURN_THIS();

}


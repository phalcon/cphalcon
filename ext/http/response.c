
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"

#include "interned-strings.h"

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
 * Phalcon\Http\Response initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Response){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Response, http_response, phalcon_http_response_method_entry, 0);

	zend_declare_property_bool(phalcon_http_response_ce, SL("_sent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_ce TSRMLS_CC, 2, phalcon_http_responseinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Http\Response constructor
 *
 * @param string $content
 * @param int $code
 * @param string $status
 */
PHP_METHOD(Phalcon_Http_Response, __construct){

	zval *content = NULL, *code = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &content, &code, &status);
	
	if (!status) {
		status = PHALCON_GLOBAL(z_null);
	}
	
	if (content && Z_TYPE_P(content) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	}
	if (code && Z_TYPE_P(code) != IS_NULL) {
		phalcon_call_method_p2_noret(this_ptr, "setstatuscode", code, status);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Response, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Response, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
	
		PHALCON_INIT_NVAR(dependency_injector);
		phalcon_call_static(dependency_injector, "phalcon\\di", "getdefault");
	
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'url' service");
			return;
		}
	
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the HTTP response code
 *
 *<code>
 *	$response->setStatusCode(404, "Not Found");
 *</code>
 *
 * @param int $code
 * @param string $message
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setStatusCode){

	zval *code, *message, *headers, *header_value, *status_value;
	zval *status_header;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &code, &message);
	
	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	
	/** 
	 * We use HTTP/1.1 instead of HTTP/1.0
	 */
	PHALCON_INIT_VAR(header_value);
	PHALCON_CONCAT_SVSV(header_value, "HTTP/1.1 ", code, " ", message);
	phalcon_call_method_p1_noret(headers, "setraw", header_value);
	
	/** 
	 * We also define a 'Status' header with the HTTP status
	 */
	PHALCON_INIT_VAR(status_value);
	PHALCON_CONCAT_VSV(status_value, code, " ", message);
	
	PHALCON_INIT_VAR(status_header);
	ZVAL_STRING(status_header, "Status", 1);
	phalcon_call_method_p2_noret(headers, "set", status_header, status_value);
	phalcon_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Sets a headers bag for the response externally
 *
 * @param Phalcon\Http\Response\HeadersInterface $headers
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setHeaders){

	zval *headers;

	phalcon_fetch_params(0, 1, 0, &headers);
	
	phalcon_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns headers set by the user
 *
 * @return Phalcon\Http\Response\HeadersInterface
 */
PHP_METHOD(Phalcon_Http_Response, getHeaders){

	zval *headers;

	headers = phalcon_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_NULL) {
		/** 
		 * A Phalcon\Http\Response\Headers bag is temporary used to manage the headers
		 * before sending them to the client
		 */
		object_init_ex(return_value, phalcon_http_response_headers_ce);
		phalcon_update_property_this(this_ptr, SL("_headers"), return_value TSRMLS_CC);
		return;
	}
	
	RETURN_ZVAL(headers, 1, 0);
}

/**
 * Sets a cookies bag for the response externally
 *
 * @param Phalcon\Http\Response\CookiesInterface $cookies
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setCookies){

	zval *cookies;

	phalcon_fetch_params(0, 1, 0, &cookies);
	
	if (Z_TYPE_P(cookies) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_response_exception_ce, "The cookies bag is not valid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_cookies"), cookies TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns coookies set by the user
 *
 * @return Phalcon\Http\Response\CookiesInterface
 */
PHP_METHOD(Phalcon_Http_Response, getCookies){


	RETURN_MEMBER(this_ptr, "_cookies");
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
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setHeader){

	zval *name, *value, *headers;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &name, &value);
	
	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	phalcon_call_method_p2_noret(headers, "set", name, value);
	RETURN_THIS();
}

/**
 * Send a raw header to the response
 *
 *<code>
 *	$response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 *
 * @param string $header
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader){

	zval *header, *headers;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &header);
	
	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	phalcon_call_method_p1_noret(headers, "setraw", header);
	RETURN_THIS();
}

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders){

	zval *headers;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	phalcon_call_method_noret(headers, "reset");
	RETURN_THIS();
}

/**
 * Sets a Expires header to use HTTP cache
 *
 *<code>
 *	$this->response->setExpires(new DateTime());
 *</code>
 *
 * @param DateTime $datetime
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setExpires){

	zval *datetime, *headers, *date, *utc_zone, *timezone;
	zval *format, *utc_format, *utc_date, *expires_header;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &datetime);
	
	if (Z_TYPE_P(datetime) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "datetime parameter must be an instance of DateTime");
		return;
	}
	
	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	
	PHALCON_INIT_VAR(date);
	if (phalcon_clone(date, datetime TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	/** 
	 * All the expiration times are sent in UTC
	 */
	PHALCON_INIT_VAR(utc_zone);
	ZVAL_STRING(utc_zone, "UTC", 1);
	ce0 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(timezone);
	object_init_ex(timezone, ce0);
	if (phalcon_has_constructor(timezone TSRMLS_CC)) {
		phalcon_call_method_p1_noret(timezone, "__construct", utc_zone);
	}
	
	/** 
	 * Change the timezone to utc
	 */
	phalcon_call_method_p1_noret(date, "settimezone", timezone);
	
	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "D, d M Y H:i:s", 1);
	
	PHALCON_INIT_VAR(utc_format);
	phalcon_call_method_p1(utc_format, date, "format", format);
	
	PHALCON_INIT_VAR(utc_date);
	PHALCON_CONCAT_VS(utc_date, utc_format, " GMT");
	
	/** 
	 * The 'Expires' header set this info
	 */
	PHALCON_INIT_VAR(expires_header);
	ZVAL_STRING(expires_header, "Expires", 1);
	phalcon_call_method_p2_noret(this_ptr, "setheader", expires_header, utc_date);
	
	RETURN_THIS();
}

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified){

	zval *code, *status;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(code);
	ZVAL_LONG(code, 304);
	
	PHALCON_INIT_VAR(status);
	ZVAL_STRING(status, "Not modified", 1);
	phalcon_call_method_p2_noret(this_ptr, "setstatuscode", code, status);
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
 * @param string $contentType
 * @param string $charset
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setContentType){

	zval *content_type, *charset = NULL, *headers, *name, *header_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &content_type, &charset);
	
	if (!charset) {
		charset = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	
	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "Content-Type", 1);
	if (Z_TYPE_P(charset) == IS_NULL) {
		phalcon_call_method_p2_noret(headers, "set", name, content_type);
	} else {
		PHALCON_INIT_VAR(header_value);
		PHALCON_CONCAT_VSV(header_value, content_type, "; charset=", charset);
		phalcon_call_method_p2_noret(headers, "set", name, header_value);
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
 * @param string $etag
 */
PHP_METHOD(Phalcon_Http_Response, setEtag){

	zval *etag, *name, *headers;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &etag);
	
	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "Etag", 1);
	
	PHALCON_INIT_VAR(headers);
	phalcon_call_method(headers, this_ptr, "getheaders");
	phalcon_call_method_p2_noret(headers, "set", name, etag);
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
 * @param string $location
 * @param boolean $externalRedirect
 * @param int $statusCode
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, redirect){

	zval *location = NULL, *external_redirect = NULL, *status_code = NULL;
	zval *header = NULL, *dependency_injector, *service;
	zval *url, *status_text, *header_name;

	static const char* redirect_phrases[] = {
		/* 300 */ "Multiple Choices",
		/* 301 */ "Moved Permanently",
		/* 302 */ "Found",
		/* 303 */ "See Other",
		/* 304 */ "Not Modified",
		/* 305 */ "Use Proxy",
		/* 306 */ "Switch Proxy",
		/* 307 */ "Temporary Redirect",
		/* 308 */ "Permanent Redirect"
	};

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &location, &external_redirect, &status_code);
	
	if (!location) {
		location = PHALCON_GLOBAL(z_null);
	}
	
	if (!external_redirect) {
		external_redirect = PHALCON_GLOBAL(z_false);
	}
	
	if (!status_code) {
		PHALCON_INIT_VAR(status_code);
		ZVAL_LONG(status_code, 302);
	}
	else if (unlikely(Z_TYPE_P(status_code) != IS_LONG)) {
		PHALCON_SEPARATE_PARAM(status_code);
		convert_to_long(status_code);
	}
	
	if (zend_is_true(external_redirect)) {
		PHALCON_CPY_WRT(header, location);
	} else {
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_call_method(dependency_injector, this_ptr, "getdi");
	
		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_url);
	
		PHALCON_INIT_VAR(url);
		phalcon_call_method_p1(url, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(url, phalcon_mvc_urlinterface_ce);
	
		PHALCON_INIT_NVAR(header);
		phalcon_call_method_p1(header, url, "get", location);
	}
	
	/** 
	 * The HTTP status is 302 by default, a temporary redirection
	 */
	PHALCON_INIT_VAR(status_text);
	if (Z_LVAL_P(status_code) < 300 || Z_LVAL_P(status_code) > 308) {
		ZVAL_STRING(status_text, "Redirect", 1);
	}
	else {
		ZVAL_STRING(status_text, redirect_phrases[Z_LVAL_P(status_code) - 300], 1);
	}

	phalcon_call_method_p2_noret(this_ptr, "setstatuscode", status_code, status_text);
	
	/** 
	 * Change the current location using 'Location'
	 */
	PHALCON_INIT_VAR(header_name);
	ZVAL_STRING(header_name, "Location", 1);
	phalcon_call_method_p2_noret(this_ptr, "setheader", header_name, header);
	
	RETURN_THIS();
}

/**
 * Sets HTTP response body
 *
 *<code>
 *	$response->setContent("<h1>Hello!</h1>");
 *</code>
 *
 * @param string $content
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setContent){

	zval *content;

	phalcon_fetch_params(0, 1, 0, &content);
	
	phalcon_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets HTTP response body. The parameter is automatically converted to JSON
 *
 *<code>
 *	$response->setJsonContent(array("status" => "OK"));
 *	$response->setJsonContent(array("status" => "OK"), JSON_NUMERIC_CHECK);
*</code>
 *
 * @param string $content
 * @param int $jsonOptions bitmask consisting on http://www.php.net/manual/en/json.constants.php
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, setJsonContent){

	zval *content, *json_options = NULL, *json_content;
	int options = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &content, &json_options);
	
	if (json_options) {
		options = phalcon_get_intval(json_options);
	}
	
	PHALCON_INIT_VAR(json_content);
	phalcon_json_encode(json_content, NULL, content, options TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_content"), json_content TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Appends a string to the HTTP response body
 *
 * @param string $content
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, appendContent){

	zval *content, *_content;
	zval *temp_content = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &content);
	
	PHALCON_OBS_VAR(_content);
	phalcon_read_property_this(&_content, this_ptr, SL("_content"), PH_NOISY_CC);
	PHALCON_INIT_VAR(temp_content);
	concat_function(temp_content, _content, content TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_content"), temp_content TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Gets the HTTP response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response, getContent){


	RETURN_MEMBER(this_ptr, "_content");
}

/**
 * Check if the response is already sent
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response, isSent){


	RETURN_MEMBER(this_ptr, "_sent");
}

/**
 * Sends headers to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, sendHeaders){

	zval *headers;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(headers);
	phalcon_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_OBJECT) {
		phalcon_call_method_noret(headers, "send");
	}
	
	RETURN_THIS();
}

/**
 * Sends cookies to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, sendCookies){

	zval *cookies;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(cookies);
	phalcon_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (Z_TYPE_P(cookies) == IS_OBJECT) {
		phalcon_call_method_noret(cookies, "send");
	}
	
	RETURN_THIS();
}

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Http_Response, send){

	zval *sent, *headers, *cookies, *content, *file;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(sent);
	phalcon_read_property_this(&sent, this_ptr, SL("_sent"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(sent)) {
	
		/** 
		 * Send headers
		 */
		PHALCON_OBS_VAR(headers);
		phalcon_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
		if (Z_TYPE_P(headers) == IS_OBJECT) {
			phalcon_call_method_noret(headers, "send");
		}
	
		PHALCON_OBS_VAR(cookies);
		phalcon_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
		if (Z_TYPE_P(cookies) == IS_OBJECT) {
			phalcon_call_method_noret(cookies, "send");
		}
	
		/** 
		 * Output the response body
		 */
		PHALCON_OBS_VAR(content);
		phalcon_read_property_this(&content, this_ptr, SL("_content"), PH_NOISY_CC);
		if (Z_STRLEN_P(content)) {
			zend_print_zval(content, 0);
		}
		else {
			PHALCON_OBS_VAR(file);
			phalcon_read_property_this(&file, this_ptr, SL("_file"), PH_NOISY_CC);

			if (Z_STRLEN_P(file)) {
				php_stream *stream;

				stream = php_stream_open_wrapper(Z_STRVAL_P(file), "rb", REPORT_ERRORS, NULL);
				if (stream != NULL) {
					php_stream_passthru(stream);
					php_stream_close(stream);
				}
			}
		}

		phalcon_update_property_bool(this_ptr, SL("_sent"), 1 TSRMLS_CC);
	
		RETURN_THIS();
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "Response was already sent");
	return;
}

/**
 * Sets an attached file to be sent at the end of the request
 *
 * @param string $filePath
 * @param string $attachmentName
 */
PHP_METHOD(Phalcon_Http_Response, setFileToSend){

	zval *file_path, *attachment_name = NULL, *attachment = NULL, *base_path = NULL;
	zval *headers, *content_description, *content_disposition;
	zval *content_transfer;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &file_path, &attachment_name, &attachment);
	
	if (!attachment_name) {
		attachment_name = PHALCON_GLOBAL(z_null);
	}

	if (!attachment) {
		attachment = PHALCON_GLOBAL(z_true);
	}
	
	if (Z_TYPE_P(attachment_name) != IS_STRING) {
		PHALCON_INIT_VAR(base_path);
		phalcon_basename(base_path, file_path TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(base_path, attachment_name);
	}
	
	if (zend_is_true(attachment)) {
		PHALCON_INIT_VAR(headers);
		phalcon_call_method(headers, this_ptr, "getheaders");

		PHALCON_INIT_VAR(content_description);
		ZVAL_STRING(content_description, "Content-Description: File Transfer", 1);
		phalcon_call_method_p1_noret(headers, "setraw", content_description);
	
		PHALCON_INIT_VAR(content_disposition);
		PHALCON_CONCAT_SV(content_disposition, "Content-Disposition: attachment; filename=", base_path);
		phalcon_call_method_p1_noret(headers, "setraw", content_disposition);
	
		PHALCON_INIT_VAR(content_transfer);
		ZVAL_STRING(content_transfer, "Content-Transfer-Encoding: binary", 1);
		phalcon_call_method_p1_noret(headers, "setraw", content_transfer);
	}
	phalcon_update_property_this(this_ptr, SL("_file"), file_path TSRMLS_CC);
	
	RETURN_THIS();
}


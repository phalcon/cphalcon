
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/file.h"


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

	zend_declare_property_null(phalcon_http_response_ce, SL("_statusCodes"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, code, status);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Response, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Response, getDI) {

	zval *dependencyInjector = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 1);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'url' service", "phalcon/http/response.zep", 97);
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
 */
PHP_METHOD(Phalcon_Http_Response, setStatusCode) {

	zval *_10$$7;
	zend_bool _4$$4;
	HashTable *_2$$3;
	HashPosition _1$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zval *message = NULL, *_14, *_16;
	zval *code_param = NULL, *message_param = NULL, *headers = NULL, *currentHeadersRaw = NULL, *key = NULL, *defaultMessage = NULL, _13, _15, *_17, *_0$$3 = NULL, **_3$$3, _5$$4 = zval_used_for_init, *_6$$4 = NULL, *_9$$6, *_11$$6, *_12$$6;
	int code, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code_param, &message_param);

	code = zephir_get_intval(code_param);
	if (!message_param) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	} else {
		zephir_get_strval(message, message_param);
	}


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&currentHeadersRaw, headers, "toarray", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(currentHeadersRaw) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_is_iterable(currentHeadersRaw, &_2$$3, &_1$$3, 0, 0, "phalcon/http/response.zep", 129);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(_0$$3, _3$$3);
			_4$$4 = Z_TYPE_P(key) == IS_STRING;
			if (_4$$4) {
				ZEPHIR_SINIT_NVAR(_5$$4);
				ZVAL_STRING(&_5$$4, "HTTP/", 0);
				ZEPHIR_CALL_FUNCTION(&_6$$4, "strstr", &_7, 230, key, &_5$$4);
				zephir_check_call_status();
				_4$$4 = zephir_is_true(_6$$4);
			}
			if (_4$$4) {
				ZEPHIR_CALL_METHOD(NULL, headers, "remove", &_8, 0, key);
				zephir_check_call_status();
			}
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(message, "")) {
		ZEPHIR_OBS_VAR(_9$$6);
		zephir_read_property_this(&_9$$6, this_ptr, SL("_statusCodes"), PH_NOISY_CC);
		if (Z_TYPE_P(_9$$6) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_10$$7);
			zephir_create_array(_10$$7, 57, 0 TSRMLS_CC);
			add_index_stringl(_10$$7, 100, SL("Continue"), 1);
			add_index_stringl(_10$$7, 101, SL("Switching Protocols"), 1);
			add_index_stringl(_10$$7, 102, SL("Processing"), 1);
			add_index_stringl(_10$$7, 200, SL("OK"), 1);
			add_index_stringl(_10$$7, 201, SL("Created"), 1);
			add_index_stringl(_10$$7, 202, SL("Accepted"), 1);
			add_index_stringl(_10$$7, 203, SL("Non-Authoritative Information"), 1);
			add_index_stringl(_10$$7, 204, SL("No Content"), 1);
			add_index_stringl(_10$$7, 205, SL("Reset Content"), 1);
			add_index_stringl(_10$$7, 206, SL("Partial Content"), 1);
			add_index_stringl(_10$$7, 207, SL("Multi-status"), 1);
			add_index_stringl(_10$$7, 208, SL("Already Reported"), 1);
			add_index_stringl(_10$$7, 300, SL("Multiple Choices"), 1);
			add_index_stringl(_10$$7, 301, SL("Moved Permanently"), 1);
			add_index_stringl(_10$$7, 302, SL("Found"), 1);
			add_index_stringl(_10$$7, 303, SL("See Other"), 1);
			add_index_stringl(_10$$7, 304, SL("Not Modified"), 1);
			add_index_stringl(_10$$7, 305, SL("Use Proxy"), 1);
			add_index_stringl(_10$$7, 306, SL("Switch Proxy"), 1);
			add_index_stringl(_10$$7, 307, SL("Temporary Redirect"), 1);
			add_index_stringl(_10$$7, 400, SL("Bad Request"), 1);
			add_index_stringl(_10$$7, 401, SL("Unauthorized"), 1);
			add_index_stringl(_10$$7, 402, SL("Payment Required"), 1);
			add_index_stringl(_10$$7, 403, SL("Forbidden"), 1);
			add_index_stringl(_10$$7, 404, SL("Not Found"), 1);
			add_index_stringl(_10$$7, 405, SL("Method Not Allowed"), 1);
			add_index_stringl(_10$$7, 406, SL("Not Acceptable"), 1);
			add_index_stringl(_10$$7, 407, SL("Proxy Authentication Required"), 1);
			add_index_stringl(_10$$7, 408, SL("Request Time-out"), 1);
			add_index_stringl(_10$$7, 409, SL("Conflict"), 1);
			add_index_stringl(_10$$7, 410, SL("Gone"), 1);
			add_index_stringl(_10$$7, 411, SL("Length Required"), 1);
			add_index_stringl(_10$$7, 412, SL("Precondition Failed"), 1);
			add_index_stringl(_10$$7, 413, SL("Request Entity Too Large"), 1);
			add_index_stringl(_10$$7, 414, SL("Request-URI Too Large"), 1);
			add_index_stringl(_10$$7, 415, SL("Unsupported Media Type"), 1);
			add_index_stringl(_10$$7, 416, SL("Requested range not satisfiable"), 1);
			add_index_stringl(_10$$7, 417, SL("Expectation Failed"), 1);
			add_index_stringl(_10$$7, 418, SL("I'm a teapot"), 1);
			add_index_stringl(_10$$7, 422, SL("Unprocessable Entity"), 1);
			add_index_stringl(_10$$7, 423, SL("Locked"), 1);
			add_index_stringl(_10$$7, 424, SL("Failed Dependency"), 1);
			add_index_stringl(_10$$7, 425, SL("Unordered Collection"), 1);
			add_index_stringl(_10$$7, 426, SL("Upgrade Required"), 1);
			add_index_stringl(_10$$7, 428, SL("Precondition Required"), 1);
			add_index_stringl(_10$$7, 429, SL("Too Many Requests"), 1);
			add_index_stringl(_10$$7, 431, SL("Request Header Fields Too Large"), 1);
			add_index_stringl(_10$$7, 500, SL("Internal Server Error"), 1);
			add_index_stringl(_10$$7, 501, SL("Not Implemented"), 1);
			add_index_stringl(_10$$7, 502, SL("Bad Gateway"), 1);
			add_index_stringl(_10$$7, 503, SL("Service Unavailable"), 1);
			add_index_stringl(_10$$7, 504, SL("Gateway Time-out"), 1);
			add_index_stringl(_10$$7, 505, SL("HTTP Version not supported"), 1);
			add_index_stringl(_10$$7, 506, SL("Variant Also Negotiates"), 1);
			add_index_stringl(_10$$7, 507, SL("Insufficient Storage"), 1);
			add_index_stringl(_10$$7, 508, SL("Loop Detected"), 1);
			add_index_stringl(_10$$7, 511, SL("Network Authentication Required"), 1);
			zephir_update_property_this(this_ptr, SL("_statusCodes"), _10$$7 TSRMLS_CC);
		}
		_11$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_statusCodes"), PH_NOISY_CC);
		if (!(zephir_array_isset_long(_11$$6, code))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "Non-standard statuscode given without a message", "phalcon/http/response.zep", 203);
			return;
		}
		_12$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_statusCodes"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(defaultMessage);
		zephir_array_fetch_long(&defaultMessage, _12$$6, code, PH_NOISY, "phalcon/http/response.zep", 206 TSRMLS_CC);
		zephir_get_strval(message, defaultMessage);
	}
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, code);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVSV(_14, "HTTP/1.1 ", &_13, " ", message);
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, 0, _14);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, code);
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_VSV(_16, &_15, " ", message);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_STRING(_17, "Status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, 0, _17, _16);
	zephir_check_temp_parameter(_17);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the status code
 *
 *<code>
 *	print_r($response->getStatusCode());
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, getStatusCode) {

	zval *_0 = NULL, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a headers bag for the response externally
 */
PHP_METHOD(Phalcon_Http_Response, setHeaders) {

	zval *headers;

	zephir_fetch_params(0, 1, 0, &headers);



	zephir_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns headers set by the user
 */
PHP_METHOD(Phalcon_Http_Response, getHeaders) {

	zval *headers = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_NULL) {
		ZEPHIR_INIT_NVAR(headers);
		object_init_ex(headers, phalcon_http_response_headers_ce);
		if (zephir_has_constructor(headers TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	}
	RETURN_CCTOR(headers);

}

/**
 * Sets a cookies bag for the response externally
 */
PHP_METHOD(Phalcon_Http_Response, setCookies) {

	zval *cookies;

	zephir_fetch_params(0, 1, 0, &cookies);



	zephir_update_property_this(this_ptr, SL("_cookies"), cookies TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns coookies set by the user
 *
 * @return \Phalcon\Http\Response\CookiesInterface
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
 * @return \Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *headers = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Send a raw header to the response
 *
 *<code>
 *	$response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *headers = NULL;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(header, header_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, 0, header);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Resets all the stablished headers
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders) {

	zval *headers = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, headers, "reset", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets a Expires header to use HTTP cache
 *
 *<code>
 *	$this->response->setExpires(new DateTime());
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setExpires) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, *date = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_INIT_VAR(date);
	if (zephir_clone(date, datetime TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, php_date_get_timezone_ce());
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "UTC", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, date, "settimezone", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "D, d M Y H:i:s", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, date, "format", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, " GMT");
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Expires", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, _1, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets Cache headers to use HTTP cache
 *
 *<code>
 *	$this->response->setCache(60);
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setCache) {

	zval *_1, *_3;
	zval *minutes_param = NULL, *date = NULL, _0, _2, *_4;
	int minutes, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &minutes_param);

	if (unlikely(Z_TYPE_P(minutes_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'minutes' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	minutes = Z_LVAL_P(minutes_param);


	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, minutes);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "+", &_0, " minutes");
	ZEPHIR_CALL_METHOD(NULL, date, "modify", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setexpires", NULL, 0, date);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, ((minutes * 60)));
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "max-age=", &_2);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Cache-Control", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, _4, _3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends a Not-Modified response
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 304);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Not modified", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_1);
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
 * @return \Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setContentType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *contentType_param = NULL, *charset = NULL, *headers = NULL, *_0$$3, *_1$$4, *_2$$4;
	zval *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &contentType_param, &charset);

	zephir_get_strval(contentType, contentType_param);
	if (!charset) {
		charset = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(charset) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, 0, _0$$3, contentType);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_VSV(_1$$4, contentType, "; charset=", charset);
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, 0, _2$$4, _1$$4);
		zephir_check_temp_parameter(_2$$4);
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
 */
PHP_METHOD(Phalcon_Http_Response, setEtag) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *etag_param = NULL, *headers = NULL, *_0;
	zval *etag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &etag_param);

	zephir_get_strval(etag, etag_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Etag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, headers, "set", NULL, 0, _0, etag);
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
 * @return \Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, redirect) {

	int statusCode, ZEPHIR_LAST_CALL_STATUS;
	zend_bool externalRedirect, _10, _0$$5;
	zval *location = NULL, *externalRedirect_param = NULL, *statusCode_param = NULL, *header = NULL, *url = NULL, *dependencyInjector = NULL, *matched = NULL, *message = NULL, *view = NULL, *_7 = NULL, *_8 = NULL, _1$$5, *_2$$5 = NULL, *_3$$6, _4$$6, *_5$$10 = NULL, *_6$$10, *_9$$11, *_11$$13, *_12$$14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &location, &externalRedirect_param, &statusCode_param);

	if (!location) {
		ZEPHIR_CPY_WRT(location, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(location);
	}
	if (!externalRedirect_param) {
		externalRedirect = 0;
	} else {
		externalRedirect = zephir_get_boolval(externalRedirect_param);
	}
	if (!statusCode_param) {
		statusCode = 302;
	} else {
		statusCode = zephir_get_intval(statusCode_param);
	}


	if (!(zephir_is_true(location))) {
		ZEPHIR_INIT_NVAR(location);
		ZVAL_STRING(location, "", 1);
	}
	if (externalRedirect) {
		ZEPHIR_CPY_WRT(header, location);
	} else {
		_0$$5 = Z_TYPE_P(location) == IS_STRING;
		if (_0$$5) {
			ZEPHIR_SINIT_VAR(_1$$5);
			ZVAL_STRING(&_1$$5, "://", 0);
			ZEPHIR_CALL_FUNCTION(&_2$$5, "strstr", NULL, 230, location, &_1$$5);
			zephir_check_call_status();
			_0$$5 = zephir_is_true(_2$$5);
		}
		if (_0$$5) {
			ZEPHIR_INIT_VAR(_3$$6);
			ZEPHIR_SINIT_VAR(_4$$6);
			ZVAL_STRING(&_4$$6, "/^[^:\\/?#]++:/", 0);
			ZEPHIR_INIT_VAR(matched);
			zephir_preg_match(matched, &_4$$6, location, _3$$6, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(matched)) {
				ZEPHIR_CPY_WRT(header, location);
			} else {
				ZEPHIR_INIT_NVAR(header);
				ZVAL_NULL(header);
			}
		} else {
			ZEPHIR_INIT_NVAR(header);
			ZVAL_NULL(header);
		}
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(header))) {
		ZEPHIR_INIT_VAR(_6$$10);
		ZVAL_STRING(_6$$10, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$10, dependencyInjector, "getshared", NULL, 0, _6$$10);
		zephir_check_temp_parameter(_6$$10);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(url, _5$$10);
		ZEPHIR_CALL_METHOD(&header, url, "get", NULL, 0, location);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, dependencyInjector, "has", NULL, 0, _8);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_9$$11);
		ZVAL_STRING(_9$$11, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&view, dependencyInjector, "getshared", NULL, 0, _9$$11);
		zephir_check_temp_parameter(_9$$11);
		zephir_check_call_status();
		if (zephir_instance_of_ev(view, phalcon_mvc_viewinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, view, "disable", NULL, 0);
			zephir_check_call_status();
		}
	}
	_10 = statusCode < 300;
	if (!(_10)) {
		_10 = statusCode > 308;
	}
	if (_10) {
		statusCode = 302;
		_11$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_statusCodes"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(message);
		zephir_array_fetch_long(&message, _11$$13, 302, PH_NOISY, "phalcon/http/response.zep", 480 TSRMLS_CC);
	} else {
		ZEPHIR_OBS_NVAR(message);
		_12$$14 = zephir_fetch_nproperty_this(this_ptr, SL("_statusCodes"), PH_NOISY_CC);
		zephir_array_isset_long_fetch(&message, _12$$14, statusCode, 0 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_LONG(_8, statusCode);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, _8, message);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "Location", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, _8, header);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets HTTP response body
 *
 *<code>
 *	response->setContent("<h1>Hello!</h1>");
 *</code>
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
 * @return \Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setJsonContent) {

	zval *content, *jsonOptions = NULL, *depth = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content, &jsonOptions, &depth);

	if (!jsonOptions) {
		ZEPHIR_INIT_VAR(jsonOptions);
		ZVAL_LONG(jsonOptions, 0);
	}
	if (!depth) {
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
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
 * @return \Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, appendContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *content, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, content);
	zephir_update_property_this(this_ptr, SL("_content"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the HTTP response body
 */
PHP_METHOD(Phalcon_Http_Response, getContent) {

	

	RETURN_MEMBER(this_ptr, "_content");

}

/**
 * Check if the response is already sent
 */
PHP_METHOD(Phalcon_Http_Response, isSent) {

	

	RETURN_MEMBER(this_ptr, "_sent");

}

/**
 * Sends headers to the client
 */
PHP_METHOD(Phalcon_Http_Response, sendHeaders) {

	zval *headers = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, headers, "send", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sends cookies to the client
 */
PHP_METHOD(Phalcon_Http_Response, sendCookies) {

	zval *cookies = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(cookies);
	zephir_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (Z_TYPE_P(cookies) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, cookies, "send", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Prints out HTTP response to the client
 */
PHP_METHOD(Phalcon_Http_Response, send) {

	zend_bool _1$$7;
	zval *headers = NULL, *cookies = NULL, *content = NULL, *file = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_sent"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "Response was already sent", "phalcon/http/response.zep", 587);
		return;
	}
	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	if (Z_TYPE_P(headers) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, headers, "send", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(cookies);
	zephir_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (Z_TYPE_P(cookies) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, cookies, "send", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(content);
	zephir_read_property_this(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	if (Z_TYPE_P(content) != IS_NULL) {
		zend_print_zval(content, 0);
	} else {
		ZEPHIR_OBS_VAR(file);
		zephir_read_property_this(&file, this_ptr, SL("_file"), PH_NOISY_CC);
		_1$$7 = Z_TYPE_P(file) == IS_STRING;
		if (_1$$7) {
			_1$$7 = (zephir_fast_strlen_ev(file)) ? 1 : 0;
		}
		if (_1$$7) {
			ZEPHIR_CALL_FUNCTION(NULL, "readfile", NULL, 231, file);
			zephir_check_call_status();
		}
	}
	if (1) {
		zephir_update_property_this(this_ptr, SL("_sent"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_sent"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Sets an attached file to be sent at the end of the request
 *
 * @param string filePath
 * @param string attachmentName
 * @return \Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Http_Response, setFileToSend) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *attachmentName = NULL, *attachment = NULL, *basePath = NULL, *headers = NULL, *_0$$5 = NULL, *_1$$5;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &filePath_param, &attachmentName, &attachment);

	zephir_get_strval(filePath, filePath_param);
	if (!attachmentName) {
		attachmentName = ZEPHIR_GLOBAL(global_null);
	}
	if (!attachment) {
		attachment = ZEPHIR_GLOBAL(global_true);
	}


	if (Z_TYPE_P(attachmentName) != IS_STRING) {
		ZEPHIR_INIT_VAR(basePath);
		zephir_basename(basePath, filePath TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(basePath, attachmentName);
	}
	if (zephir_is_true(attachment)) {
		ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_0$$5);
		ZVAL_STRING(_0$$5, "Content-Description: File Transfer", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, 0, _0$$5);
		zephir_check_temp_parameter(_0$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0$$5);
		ZVAL_STRING(_0$$5, "Content-Type: application/octet-stream", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, 0, _0$$5);
		zephir_check_temp_parameter(_0$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$5);
		ZEPHIR_CONCAT_SV(_1$$5, "Content-Disposition: attachment; filename=", basePath);
		ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, 0, _1$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0$$5);
		ZVAL_STRING(_0$$5, "Content-Transfer-Encoding: binary", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, headers, "setraw", NULL, 0, _0$$5);
		zephir_check_temp_parameter(_0$$5);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), filePath TSRMLS_CC);
	RETURN_THIS();

}


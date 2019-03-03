
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Response
 *
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *<code>
 * $response = new \Phalcon\Http\Response();
 *
 * $response->setStatusCode(200, "OK");
 * $response->setContent("<html><body>Hello</body></html>");
 *
 * $response->send();
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

	zend_declare_property_null(phalcon_http_response_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_ce TSRMLS_CC, 1, phalcon_http_responseinterface_ce);
	zend_class_implements(phalcon_http_response_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_http_response_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Http\Response constructor
 */
PHP_METHOD(Phalcon_Http_Response, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *code = NULL, code_sub, *status = NULL, status_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&status_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &code, &status);

	if (!content) {
		content = &content_sub;
		content = &__$null;
	}
	if (!code) {
		code = &code_sub;
		code = &__$null;
	}
	if (!status) {
		status = &status_sub;
		status = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_http_response_headers_ce);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_headers"), &_0);
	if (Z_TYPE_P(content) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_content"), content);
	}
	if (Z_TYPE_P(code) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, code, status);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a string to the HTTP response body
 */
PHP_METHOD(Phalcon_Http_Response, appendContent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, content);
	zephir_update_property_zval(this_ptr, SL("_content"), &_1);
	RETURN_THIS();

}

/**
 * Gets the HTTP response body
 */
PHP_METHOD(Phalcon_Http_Response, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_content");

}

/**
 * Returns cookies set by the user
 */
PHP_METHOD(Phalcon_Http_Response, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_cookies");

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Response, getDI) {

	zval dependencyInjector, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'url' service", "phalcon/http/response.zep", 113);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	RETURN_CCTOR(&dependencyInjector);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Http_Response, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Returns headers set by the user
 */
PHP_METHOD(Phalcon_Http_Response, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_headers");

}

/**
 * Returns the reason phrase
 *
 *<code>
 * echo $response->getReasonPhrase();
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, getReasonPhrase) {

	zval statusReasonPhrase, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statusReasonPhrase);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Status");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 4);
	ZEPHIR_INIT_VAR(&statusReasonPhrase);
	zephir_substr(&statusReasonPhrase, &_1, 4 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_NVAR(&_2);
	if (zephir_is_true(&statusReasonPhrase)) {
		ZEPHIR_CPY_WRT(&_2, &statusReasonPhrase);
	} else {
		ZVAL_NULL(&_2);
	}
	RETURN_CCTOR(&_2);

}

/**
 * Returns the status code
 *
 *<code>
 * echo $response->getStatusCode();
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, getStatusCode) {

	zval statusCode, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statusCode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Status");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_INIT_VAR(&statusCode);
	zephir_substr(&statusCode, &_1, 0 , 3 , 0);
	ZEPHIR_INIT_NVAR(&_2);
	if (zephir_is_true(&statusCode)) {
		ZVAL_LONG(&_2, zephir_get_intval(&statusCode));
	} else {
		ZVAL_NULL(&_2);
	}
	RETURN_CCTOR(&_2);

}

/**
 * Checks if a header exists
 *
 *<code>
 * $response->hasHeader("Content-Type");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, hasHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, headers;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&headers, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if the response is already sent
 */
PHP_METHOD(Phalcon_Http_Response, isSent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_sent");

}

/**
 * Redirect by HTTP to another action or URL
 *
 *<code>
 * // Using a string redirect (internal/external)
 * $response->redirect("posts/index");
 * $response->redirect("http://en.wikipedia.org", true);
 * $response->redirect("http://www.example.com/new-location", true, 301);
 *
 * // Making a redirection based on a named route
 * $response->redirect(
 *     [
 *         "for"        => "index-lang",
 *         "lang"       => "jp",
 *         "controller" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, redirect) {

	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zend_bool externalRedirect, _11, _0$$5;
	zval *location = NULL, location_sub, *externalRedirect_param = NULL, *statusCode_param = NULL, __$null, header, url, dependencyInjector, matched, view, _8, _9, _12, _1$$5, _2$$5, _3$$6, _4$$6, _5$$6, _6$$10, _7$$10, _10$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_10$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &location, &externalRedirect_param, &statusCode_param);

	if (!location) {
		location = &location_sub;
		ZEPHIR_CPY_WRT(location, &__$null);
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
		ZVAL_STRING(location, "");
	}
	if (externalRedirect) {
		ZEPHIR_CPY_WRT(&header, location);
	} else {
		_0$$5 = Z_TYPE_P(location) == IS_STRING;
		if (_0$$5) {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "://");
			ZEPHIR_CALL_FUNCTION(&_2$$5, "strstr", NULL, 234, location, &_1$$5);
			zephir_check_call_status();
			_0$$5 = zephir_is_true(&_2$$5);
		}
		if (_0$$5) {
			ZEPHIR_INIT_VAR(&_3$$6);
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "/^[^:\\/?#]++:/");
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/^[^:\\/?#]++:/");
			ZEPHIR_INIT_VAR(&matched);
			zephir_preg_match(&matched, &_5$$6, location, &_3$$6, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&matched)) {
				ZEPHIR_CPY_WRT(&header, location);
			} else {
				ZEPHIR_INIT_NVAR(&header);
				ZVAL_NULL(&header);
			}
		} else {
			ZEPHIR_INIT_NVAR(&header);
			ZVAL_NULL(&header);
		}
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&header))) {
		ZEPHIR_INIT_VAR(&_7$$10);
		ZVAL_STRING(&_7$$10, "url");
		ZEPHIR_CALL_METHOD(&_6$$10, &dependencyInjector, "getshared", NULL, 0, &_7$$10);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&url, &_6$$10);
		ZEPHIR_CALL_METHOD(&header, &url, "get", NULL, 0, location);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "view");
	ZEPHIR_CALL_METHOD(&_8, &dependencyInjector, "has", NULL, 0, &_9);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_INIT_VAR(&_10$$11);
		ZVAL_STRING(&_10$$11, "view");
		ZEPHIR_CALL_METHOD(&view, &dependencyInjector, "getshared", NULL, 0, &_10$$11);
		zephir_check_call_status();
		if (zephir_instance_of_ev(&view, phalcon_mvc_viewinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &view, "disable", NULL, 0);
			zephir_check_call_status();
		}
	}
	_11 = statusCode < 300;
	if (!(_11)) {
		_11 = statusCode > 308;
	}
	if (_11) {
		statusCode = 302;
	}
	ZVAL_LONG(&_12, statusCode);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "Location");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_9, &header);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Remove a header in the response
 *
 *<code>
 * $response->removeHeader("Expires");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, removeHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, headers;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &headers, "remove", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Resets all the established headers
 */
PHP_METHOD(Phalcon_Http_Response, resetHeaders) {

	zval headers;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &headers, "reset", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Prints out HTTP response to the client
 */
PHP_METHOD(Phalcon_Http_Response, send) {

	zend_bool _1$$5;
	zval __$true, __$false, content, file, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_sent"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "Response was already sent", "phalcon/http/response.zep", 293);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendcookies", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&content);
	zephir_read_property(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	if (Z_TYPE_P(&content) != IS_NULL) {
		zend_print_zval(&content, 0);
	} else {
		ZEPHIR_OBS_VAR(&file);
		zephir_read_property(&file, this_ptr, SL("_file"), PH_NOISY_CC);
		_1$$5 = Z_TYPE_P(&file) == IS_STRING;
		if (_1$$5) {
			_1$$5 = ((zephir_fast_strlen_ev(&file)) ? 1 : 0);
		}
		if (_1$$5) {
			ZEPHIR_CALL_FUNCTION(NULL, "readfile", NULL, 235, &file);
			zephir_check_call_status();
		}
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_sent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_sent"), &__$false);
	}
	RETURN_THIS();

}

/**
 * Sends cookies to the client
 */
PHP_METHOD(Phalcon_Http_Response, sendCookies) {

	zval cookies;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&cookies);
	zephir_read_property(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (Z_TYPE_P(&cookies) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, &cookies, "send", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sends headers to the client
 */
PHP_METHOD(Phalcon_Http_Response, sendHeaders) {

	zend_bool _3;
	zval headers, eventsManager, _0, _1$$3, _2$$3, _4$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&headers, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "geteventsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "response:beforeSendHeaders");
		ZEPHIR_CALL_METHOD(&_1$$3, &eventsManager, "fire", NULL, 0, &_2$$3, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&_0, &headers, "send", NULL, 0);
	zephir_check_call_status();
	_3 = zephir_is_true(&_0);
	if (_3) {
		_3 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "response:afterSendHeaders");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sets Cache headers to use HTTP cache
 *
 *<code>
 * $this->response->setCache(60);
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setCache) {

	zval _1, _3;
	zval *minutes_param = NULL, date, _0, _2, _4;
	zend_long minutes, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &minutes_param);

	if (UNEXPECTED(Z_TYPE_P(minutes_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'minutes' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	minutes = Z_LVAL_P(minutes_param);


	ZEPHIR_INIT_VAR(&date);
	object_init_ex(&date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, &date, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, minutes);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "+", &_0, " minutes");
	ZEPHIR_CALL_METHOD(NULL, &date, "modify", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setexpires", NULL, 0, &date);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, ((minutes * 60)));
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "max-age=", &_2);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Cache-Control");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_4, &_3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets HTTP response body
 *
 *<code>
 * $response->setContent("<h1>Hello!</h1>");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setContent) {

	zval *content_param = NULL;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	zephir_update_property_zval(this_ptr, SL("_content"), &content);
	RETURN_THIS();

}

/**
 * Sets the response content-length
 *
 *<code>
 * $response->setContentLength(2048);
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setContentLength) {

	zval *contentLength_param = NULL, _0, _1;
	zend_long contentLength, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contentLength_param);

	contentLength = zephir_get_intval(contentLength_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Content-Length");
	ZVAL_LONG(&_1, contentLength);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the response content-type mime, optionally the charset
 *
 *<code>
 * $response->setContentType("application/pdf");
 * $response->setContentType("text/plain", "UTF-8");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setContentType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contentType_param = NULL, *charset = NULL, charset_sub, __$null, _0$$3, _1$$4, _2$$4;
	zval contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&charset_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &contentType_param, &charset);

	zephir_get_strval(&contentType, contentType_param);
	if (!charset) {
		charset = &charset_sub;
		charset = &__$null;
	}


	if (Z_TYPE_P(charset) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Content-Type");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0$$3, &contentType);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_VSV(&_1$$4, &contentType, "; charset=", charset);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Content-Type");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2$$4, &_1$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sets a cookies bag for the response externally
 */
PHP_METHOD(Phalcon_Http_Response, setCookies) {

	zval *cookies, cookies_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies_sub);

	zephir_fetch_params(0, 1, 0, &cookies);



	zephir_update_property_zval(this_ptr, SL("_cookies"), cookies);
	RETURN_THISW();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Response, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Set a custom ETag
 *
 *<code>
 * $response->setEtag(md5(time()));
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setEtag) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *etag_param = NULL, _0;
	zval etag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&etag);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &etag_param);

	zephir_get_strval(&etag, etag_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Etag");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &etag);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets an Expires header in the response that allows to use the HTTP cache
 *
 *<code>
 * $this->response->setExpires(
 *     new DateTime()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setExpires) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, datetime_sub, date, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datetime_sub);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_INIT_VAR(&date);
	if (zephir_clone(&date, datetime TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTC");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &date, "settimezone", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s");
	ZEPHIR_CALL_METHOD(&_2, &date, "format", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &_2, " GMT");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Expires");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Http_Response, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Sets an attached file to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response, setFileToSend) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *attachmentName = NULL, attachmentName_sub, *attachment = NULL, attachment_sub, __$null, __$true, basePath, _0$$5, _1$$5;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&attachmentName_sub);
	ZVAL_UNDEF(&attachment_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &filePath_param, &attachmentName, &attachment);

	zephir_get_strval(&filePath, filePath_param);
	if (!attachmentName) {
		attachmentName = &attachmentName_sub;
		attachmentName = &__$null;
	}
	if (!attachment) {
		attachment = &attachment_sub;
		attachment = &__$true;
	}


	if (Z_TYPE_P(attachmentName) != IS_STRING) {
		ZEPHIR_INIT_VAR(&basePath);
		zephir_basename(&basePath, &filePath TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&basePath, attachmentName);
	}
	if (zephir_is_true(attachment)) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "Content-Description: File Transfer");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", NULL, 0, &_0$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "Content-Type: application/octet-stream");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", NULL, 0, &_0$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$5);
		ZEPHIR_CONCAT_SVS(&_1$$5, "Content-Disposition: attachment; filename=", &basePath, ";");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", NULL, 0, &_1$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "Content-Transfer-Encoding: binary");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", NULL, 0, &_0$$5);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_file"), &filePath);
	RETURN_THIS();

}

/**
 * Overwrites a header in the response
 *
 *<code>
 * $response->setHeader("Content-Type", "text/plain");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, headers;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, &name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets a headers bag for the response externally
 */
PHP_METHOD(Phalcon_Http_Response, setHeaders) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers, headers_sub, data, existing, name, value, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers);



	ZEPHIR_CALL_METHOD(&data, headers, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&existing, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/http/response.zep", 544);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, &existing, "set", &_4, 0, &name, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &existing, "set", &_5, 0, &name, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	zephir_update_property_zval(this_ptr, SL("_headers"), &existing);
	RETURN_THIS();

}

/**
 * Sets HTTP response body. The parameter is automatically converted to JSON
 * and also sets default header: Content-Type: "application/json; charset=UTF-8"
 *
 *<code>
 * $response->setJsonContent(
 *     [
 *         "status" => "OK",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setJsonContent) {

	zend_long jsonOptions, depth, ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, *jsonOptions_param = NULL, *depth_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content, &jsonOptions_param, &depth_param);

	if (!jsonOptions_param) {
		jsonOptions = 0;
	} else {
		jsonOptions = zephir_get_intval(jsonOptions_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "application/json");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-8");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontenttype", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_2, jsonOptions);
	ZVAL_LONG(&_3, depth);
	zephir_json_encode(&_0, content, zephir_get_intval(&_2) );
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontent", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets Last-Modified header
 *
 *<code>
 * $this->response->setLastModified(
 *     new DateTime()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setLastModified) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, datetime_sub, date, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datetime_sub);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_INIT_VAR(&date);
	if (zephir_clone(&date, datetime TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTC");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &date, "settimezone", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s");
	ZEPHIR_CALL_METHOD(&_2, &date, "format", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &_2, " GMT");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Last-Modified");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends a Not-Modified response
 */
PHP_METHOD(Phalcon_Http_Response, setNotModified) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 304);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Not modified");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the HTTP response code
 *
 *<code>
 * $response->setStatusCode(404, "Not Found");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setStatusCode) {

	zend_bool _5$$4, _10$$6;
	zend_string *_4$$3;
	zend_ulong _3$$3;
	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL, *_13 = NULL;
	zval message, _15, _17;
	zval *code_param = NULL, *message_param = NULL, headers, currentHeadersRaw, key, statusCodes, defaultMessage, _14, _16, _18, _0$$3, *_1$$3, _2$$3, _6$$4, _7$$4, _11$$6, _12$$6;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&currentHeadersRaw);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&statusCodes);
	ZVAL_UNDEF(&defaultMessage);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code_param, &message_param);

	code = zephir_get_intval(code_param);
	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&currentHeadersRaw, &headers, "toarray", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&currentHeadersRaw) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_is_iterable(&currentHeadersRaw, 0, "phalcon/http/response.zep", 630);
		if (Z_TYPE_P(&currentHeadersRaw) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&currentHeadersRaw), _3$$3, _4$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_4$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _4$$3);
				} else {
					ZVAL_LONG(&key, _3$$3);
				}
				ZEPHIR_INIT_NVAR(&_0$$3);
				ZVAL_COPY(&_0$$3, _1$$3);
				_5$$4 = Z_TYPE_P(&key) == IS_STRING;
				if (_5$$4) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_STRING(&_6$$4, "HTTP/");
					ZEPHIR_CALL_FUNCTION(&_7$$4, "strstr", &_8, 234, &key, &_6$$4);
					zephir_check_call_status();
					_5$$4 = zephir_is_true(&_7$$4);
				}
				if (_5$$4) {
					ZEPHIR_CALL_METHOD(NULL, &headers, "remove", &_9, 0, &key);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &currentHeadersRaw, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &currentHeadersRaw, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &currentHeadersRaw, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_0$$3, &currentHeadersRaw, "current", NULL, 0);
				zephir_check_call_status();
					_10$$6 = Z_TYPE_P(&key) == IS_STRING;
					if (_10$$6) {
						ZEPHIR_INIT_NVAR(&_11$$6);
						ZVAL_STRING(&_11$$6, "HTTP/");
						ZEPHIR_CALL_FUNCTION(&_12$$6, "strstr", &_8, 234, &key, &_11$$6);
						zephir_check_call_status();
						_10$$6 = zephir_is_true(&_12$$6);
					}
					if (_10$$6) {
						ZEPHIR_CALL_METHOD(NULL, &headers, "remove", &_13, 0, &key);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &currentHeadersRaw, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&key);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&message, "")) {
		ZEPHIR_INIT_VAR(&statusCodes);
		zephir_create_array(&statusCodes, 67, 0 TSRMLS_CC);
		add_index_stringl(&statusCodes, 100, SL("Continue"));
		add_index_stringl(&statusCodes, 101, SL("Switching Protocols"));
		add_index_stringl(&statusCodes, 102, SL("Processing"));
		add_index_stringl(&statusCodes, 103, SL("Early Hints"));
		add_index_stringl(&statusCodes, 200, SL("OK"));
		add_index_stringl(&statusCodes, 201, SL("Created"));
		add_index_stringl(&statusCodes, 202, SL("Accepted"));
		add_index_stringl(&statusCodes, 203, SL("Non-Authoritative Information"));
		add_index_stringl(&statusCodes, 204, SL("No Content"));
		add_index_stringl(&statusCodes, 205, SL("Reset Content"));
		add_index_stringl(&statusCodes, 206, SL("Partial Content"));
		add_index_stringl(&statusCodes, 207, SL("Multi-status"));
		add_index_stringl(&statusCodes, 208, SL("Already Reported"));
		add_index_stringl(&statusCodes, 226, SL("IM Used"));
		add_index_stringl(&statusCodes, 300, SL("Multiple Choices"));
		add_index_stringl(&statusCodes, 301, SL("Moved Permanently"));
		add_index_stringl(&statusCodes, 302, SL("Found"));
		add_index_stringl(&statusCodes, 303, SL("See Other"));
		add_index_stringl(&statusCodes, 304, SL("Not Modified"));
		add_index_stringl(&statusCodes, 305, SL("Use Proxy"));
		add_index_stringl(&statusCodes, 306, SL("Switch Proxy"));
		add_index_stringl(&statusCodes, 307, SL("Temporary Redirect"));
		add_index_stringl(&statusCodes, 308, SL("Permanent Redirect"));
		add_index_stringl(&statusCodes, 400, SL("Bad Request"));
		add_index_stringl(&statusCodes, 401, SL("Unauthorized"));
		add_index_stringl(&statusCodes, 402, SL("Payment Required"));
		add_index_stringl(&statusCodes, 403, SL("Forbidden"));
		add_index_stringl(&statusCodes, 404, SL("Not Found"));
		add_index_stringl(&statusCodes, 405, SL("Method Not Allowed"));
		add_index_stringl(&statusCodes, 406, SL("Not Acceptable"));
		add_index_stringl(&statusCodes, 407, SL("Proxy Authentication Required"));
		add_index_stringl(&statusCodes, 408, SL("Request Time-out"));
		add_index_stringl(&statusCodes, 409, SL("Conflict"));
		add_index_stringl(&statusCodes, 410, SL("Gone"));
		add_index_stringl(&statusCodes, 411, SL("Length Required"));
		add_index_stringl(&statusCodes, 412, SL("Precondition Failed"));
		add_index_stringl(&statusCodes, 413, SL("Request Entity Too Large"));
		add_index_stringl(&statusCodes, 414, SL("Request-URI Too Large"));
		add_index_stringl(&statusCodes, 415, SL("Unsupported Media Type"));
		add_index_stringl(&statusCodes, 416, SL("Requested range not satisfiable"));
		add_index_stringl(&statusCodes, 417, SL("Expectation Failed"));
		add_index_stringl(&statusCodes, 418, SL("I'm a teapot"));
		add_index_stringl(&statusCodes, 421, SL("Misdirected Request"));
		add_index_stringl(&statusCodes, 422, SL("Unprocessable Entity"));
		add_index_stringl(&statusCodes, 423, SL("Locked"));
		add_index_stringl(&statusCodes, 424, SL("Failed Dependency"));
		add_index_stringl(&statusCodes, 425, SL("Unordered Collection"));
		add_index_stringl(&statusCodes, 426, SL("Upgrade Required"));
		add_index_stringl(&statusCodes, 428, SL("Precondition Required"));
		add_index_stringl(&statusCodes, 429, SL("Too Many Requests"));
		add_index_stringl(&statusCodes, 431, SL("Request Header Fields Too Large"));
		add_index_stringl(&statusCodes, 451, SL("Unavailable For Legal Reasons"));
		add_index_stringl(&statusCodes, 499, SL("Client Closed Request"));
		add_index_stringl(&statusCodes, 500, SL("Internal Server Error"));
		add_index_stringl(&statusCodes, 501, SL("Not Implemented"));
		add_index_stringl(&statusCodes, 502, SL("Bad Gateway"));
		add_index_stringl(&statusCodes, 503, SL("Service Unavailable"));
		add_index_stringl(&statusCodes, 504, SL("Gateway Time-out"));
		add_index_stringl(&statusCodes, 505, SL("HTTP Version not supported"));
		add_index_stringl(&statusCodes, 506, SL("Variant Also Negotiates"));
		add_index_stringl(&statusCodes, 507, SL("Insufficient Storage"));
		add_index_stringl(&statusCodes, 508, SL("Loop Detected"));
		add_index_stringl(&statusCodes, 510, SL("Not Extended"));
		add_index_stringl(&statusCodes, 511, SL("Network Authentication Required"));
		if (!(zephir_array_isset_long(&statusCodes, code))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "Non-standard statuscode given without a message", "phalcon/http/response.zep", 709);
			return;
		}
		ZEPHIR_OBS_VAR(&defaultMessage);
		zephir_array_fetch_long(&defaultMessage, &statusCodes, code, PH_NOISY, "phalcon/http/response.zep", 712 TSRMLS_CC);
		zephir_get_strval(&message, &defaultMessage);
	}
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, code);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SVSV(&_15, "HTTP/1.1 ", &_14, " ", &message);
	ZEPHIR_CALL_METHOD(NULL, &headers, "setraw", NULL, 0, &_15);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, code);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_VSV(&_17, &_16, " ", &message);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_STRING(&_18, "Status");
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, &_18, &_17);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Send a raw header to the response
 *
 *<code>
 * $response->setRawHeader("HTTP/1.1 404 Not Found");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Response, setRawHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, headers;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(&header, header_param);


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &headers, "setraw", NULL, 0, &header);
	zephir_check_call_status();
	RETURN_THIS();

}


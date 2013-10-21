
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"


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
 * Phalcon\Http\Request
 *
 * <p>Encapsulates request information for easy and secure access from application controllers.</p>
 *
 * <p>The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.</p>
 *
 *<code>
 *	$request = new Phalcon\Http\Request();
 *	if ($request->isPost() == true) {
 *		if ($request->isAjax() == true) {
 *			echo 'Request was made using POST and AJAX';
 *		}
 *	}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Request, phalcon, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Request, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Request, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if needed.
 * If no parameters are given the $_REQUEST superglobal is returned
 *
 *<code>
 *	//Returns value from $_REQUEST["user_email"] without sanitizing
 *	$userEmail = $request->get("user_email");
 *
 *	//Returns value from $_REQUEST["user_email"] with sanitizing
 *	$userEmail = $request->get("user_email", "email");
 *</code>
 *
 * @param string name
 * @param string|array filters
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *request = NULL, *value, *filter = NULL, *dependencyInjector = NULL, *_REQUEST, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &filters, &defaultValue);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(request, _REQUEST);
	if (!ZEPHIR_IS_STRING(name, "")) {
		if (zephir_array_isset_fetch(&value, request, name, 1 TSRMLS_CC)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if ((Z_TYPE_P(filter) != IS_OBJECT)) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
					ZEPHIR_INIT_VAR(_1);
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", 1);
					zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", value, filters);
				RETURN_MM();
			} else {
				RETURN_CTOR(value);
			}
		}
		RETURN_CCTOR(defaultValue);
	}
	RETURN_CCTOR(request);

}

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 * If no parameters are given the $_POST superglobal is returned
 *
 *<code>
 *	//Returns value from $_POST["user_email"] without sanitizing
 *	$userEmail = $request->getPost("user_email");
 *
 *	//Returns value from $_POST["user_email"] with sanitizing
 *	$userEmail = $request->getPost("user_email", "email");
 *</code>
 *
 * @param string name
 * @param string|array filters
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost) {

	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *post = NULL, *value, *filter = NULL, *dependencyInjector = NULL, *_POST, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &filters, &defaultValue);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(post, _POST);
	if (!ZEPHIR_IS_STRING(name, "")) {
		if (zephir_array_isset_fetch(&value, post, name, 1 TSRMLS_CC)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if ((Z_TYPE_P(filter) != IS_OBJECT)) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
					ZEPHIR_INIT_VAR(_1);
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", 1);
					zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", value, filters);
				RETURN_MM();
			} else {
				RETURN_CTOR(value);
			}
		}
		RETURN_CCTOR(defaultValue);
	}
	RETURN_CCTOR(post);

}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 * If no parameters are given the $_GET superglobal is returned
 *
 *<code>
 *	//Returns value from $_GET["id"] without sanitizing
 *	$id = $request->getQuery("id");
 *
 *	//Returns value from $_GET["id"] with sanitizing
 *	$id = $request->getQuery("id", "int");
 *
 *	//Returns value from $_GET["id"] with a default value
 *	$id = $request->getQuery("id", null, 150);
 *</code>
 *
 * @param string name
 * @param string|array filters
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery) {

	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *get = NULL, *value, *filter = NULL, *dependencyInjector = NULL, *_GET, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &filters, &defaultValue);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	ZEPHIR_CPY_WRT(get, _GET);
	if (!ZEPHIR_IS_STRING(name, "")) {
		if (zephir_array_isset_fetch(&value, get, name, 1 TSRMLS_CC)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if ((Z_TYPE_P(filter) != IS_OBJECT)) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
					ZEPHIR_INIT_VAR(_1);
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", 1);
					zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", value, filters);
				RETURN_MM();
			} else {
				RETURN_CTOR(value);
			}
		}
		RETURN_CCTOR(defaultValue);
	}
	RETURN_CCTOR(get);

}

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getServer) {

	zval *name_param = NULL, *serverValue, *_SERVER;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_fetch(&serverValue, _SERVER, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(serverValue);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether $_REQUEST superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, has) {

	zval *name_param = NULL, *_REQUEST;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_REQUEST, name));

}

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zval *name_param = NULL, *_POST;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_POST, name));

}

/**
 * Checks whether $_GET superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery) {

	zval *name_param = NULL, *_GET;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_GET, name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name_param = NULL, *_SERVER;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_SERVER, name));

}

/**
 * Gets HTTP header from request data
 *
 * @param string header
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	zval *header_param = NULL, *serverValue, *headerValue, *_SERVER, *_0;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

		if (Z_TYPE_P(header_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		header = header_param;



	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_fetch(&serverValue, _SERVER, header, 1 TSRMLS_CC)) {
		RETURN_CTOR(serverValue);
	} else {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "HTTP_", header);
		if (zephir_array_isset_fetch(&headerValue, _SERVER, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(headerValue);
		}
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getScheme) {

	zval *https, *scheme = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTPS", 1);
	ZEPHIR_INIT_VAR(https);
	zephir_call_method_p1(https, this_ptr, "getserver", _0);
	if (zephir_is_true(https)) {
		ZEPHIR_INIT_VAR(scheme);
		if (ZEPHIR_IS_STRING(https, "off")) {
			ZVAL_STRING(scheme, "http", 1);
		} else {
			ZVAL_STRING(scheme, "https", 1);
		}
	} else {
		ZEPHIR_INIT_NVAR(scheme);
		ZVAL_STRING(scheme, "http", 1);
	}
	RETURN_CCTOR(scheme);

}

/**
 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH']=='XMLHttpRequest'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_X_REQUESTED_WITH", 1);
	zephir_call_method_p1(_0, this_ptr, "getheader", _1);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "XMLHttpRequest"));

}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested) {

	zval *server = NULL, *contentType, *_SERVER;

	ZEPHIR_MM_GROW();

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	ZEPHIR_CPY_WRT(server, _SERVER);
	if (zephir_array_isset_string(server, SS("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		if (zephir_array_isset_string_fetch(&contentType, server, SS("CONTENT_TYPE"), 1 TSRMLS_CC)) {
			RETURN_MM_BOOL(zephir_memnstr_str(contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 330));
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getscheme");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "https"));

}

/**
 * Gets HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody) {

	zval *rawBody, *contents, _0;

	ZEPHIR_MM_GROW();

	rawBody = zephir_fetch_nproperty_this(this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if ((0 == 0)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "php://input", 0);
		ZEPHIR_INIT_VAR(contents);
		zephir_call_func_p1(contents, "file_get_contents", &_0);
		zephir_update_property_this(this_ptr, SL("_rawBody"), contents TSRMLS_CC);
		RETURN_CCTOR(contents);
	}
	RETURN_CTOR(rawBody);

}

/**
 * Gets decoded JSON HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	zval *rawBody;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(rawBody);
	zephir_call_method(rawBody, this_ptr, "getrawbody");
	if ((Z_TYPE_P(rawBody) == IS_STRING)) {
		zephir_call_func_p1(return_value, "json_decode", rawBody);
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	zval *server = NULL, *serverAddr, *_SERVER, _0;

	ZEPHIR_MM_GROW();

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	ZEPHIR_CPY_WRT(server, _SERVER);
	if (zephir_array_isset_string_fetch(&serverAddr, server, SS("SERVER_ADDR"), 1 TSRMLS_CC)) {
		RETURN_CTOR(serverAddr);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "localhost", 0);
	zephir_call_func_p1(return_value, "gethostbyname", &_0);
	RETURN_MM();

}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval *server = NULL, *serverName, *_SERVER;

	ZEPHIR_MM_GROW();

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	ZEPHIR_CPY_WRT(server, _SERVER);
	if (zephir_array_isset_string_fetch(&serverName, server, SS("SERVER_NAME"), 1 TSRMLS_CC)) {
		RETURN_CTOR(serverName);
	}
	RETURN_MM_STRING("localhost", 1);

}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zval *httpHost, *scheme, *name, *port, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", 1);
	ZEPHIR_INIT_VAR(httpHost);
	zephir_call_method_p1(httpHost, this_ptr, "getserver", _0);
	if (zephir_is_true(httpHost)) {
		RETURN_CCTOR(httpHost);
	}
	ZEPHIR_INIT_VAR(scheme);
	zephir_call_method(scheme, this_ptr, "getscheme");
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "SERVER_NAME", 1);
	ZEPHIR_INIT_VAR(name);
	zephir_call_method_p1(name, this_ptr, "getserver", _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "SERVER_PORT", 1);
	ZEPHIR_INIT_VAR(port);
	zephir_call_method_p1(port, this_ptr, "getserver", _0);
	if ((ZEPHIR_IS_STRING(scheme, "http") && ZEPHIR_IS_LONG(port, 80))) {
		RETURN_CCTOR(name);
	}
	if ((ZEPHIR_IS_STRING(scheme, "https") && ZEPHIR_IS_LONG(port, 443))) {
		RETURN_CCTOR(name);
	}
	ZEPHIR_CONCAT_VSV(return_value, name, ":", port);
	RETURN_MM();

}

/**
 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
 *
 * @param boolean trustForwardedHeader
 * @return string|boolean
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zval *trustForwardedHeader_param = NULL, *address = NULL, *_SERVER, _0, *_1, *_2;
	zend_bool trustForwardedHeader;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);

	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		trustForwardedHeader = zephir_get_boolval(trustForwardedHeader_param);
	}


	ZEPHIR_INIT_VAR(address);
	ZVAL_NULL(address);
	if (trustForwardedHeader) {
		ZEPHIR_OBS_NVAR(address);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	}
	if ((Z_TYPE_P(address) == IS_NULL)) {
		ZEPHIR_OBS_NVAR(address);
	}
	if ((Z_TYPE_P(address) == IS_STRING)) {
		if (zephir_memnstr_str(address, SL(","), "phalcon/http/request.zep", 491)) {
			ZEPHIR_SINIT_VAR(_0);
			ZVAL_STRING(&_0, ",", 0);
			ZEPHIR_INIT_VAR(_1);
			zephir_call_func_p2(_1, "explode", &_0, address);
			zephir_array_fetch_long(&_2, _1, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			RETURN_CTOR(_2);
		}
		RETURN_CCTOR(address);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {

	zval *requestMethod, *_SERVER;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&requestMethod, _SERVER, SS("REQUEST_METHOD"), 1 TSRMLS_CC)) {
		RETURN_CTORW(requestMethod);
	}
	RETURN_STRING("", 1);

}

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {

	zval *userAgent, *_SERVER;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&userAgent, _SERVER, SS("HTTP_USER_AGENT"), 1 TSRMLS_CC)) {
		RETURN_CTORW(userAgent);
	}
	RETURN_STRING("", 1);

}

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array methods
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isMethod) {

	HashTable *_1;
	HashPosition _0;
	zval *methods, *httpMethod, *method = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &methods);



	ZEPHIR_INIT_VAR(httpMethod);
	zephir_call_method(httpMethod, this_ptr, "getmethod");
	if ((Z_TYPE_P(methods) == IS_STRING)) {
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, httpMethod));
	} else {
		zephir_is_iterable(methods, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(method, _2);
			if (ZEPHIR_IS_EQUAL(method, httpMethod)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]=="POST"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "POST"));

}

/**
 *
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]=="GET"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]=="PUT"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]=="PATCH"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]=="HEAD"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]=="DELETE"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]=="OPTIONS"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getmethod");
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "OPTIONS"));

}

/**
 * Checks whether request include attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	HashTable *_1;
	HashPosition _0;
	int numberFiles;
	zval *notErrored_param = NULL, *files = NULL, *file = NULL, *error = NULL, *_FILES, **_2;
	zend_bool notErrored;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &notErrored_param);

	if (!notErrored_param) {
		notErrored = 0;
	} else {
		notErrored = zephir_get_boolval(notErrored_param);
	}


	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	ZEPHIR_CPY_WRT(files, _FILES);
	if (notErrored) {
		RETURN_MM_BOOL((zephir_fast_count_int(files TSRMLS_CC) > 0));
	} else {
		numberFiles = 0;
		zephir_is_iterable(files, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(file, _2);
			ZEPHIR_OBS_NVAR(error);
			if (!(zephir_array_isset_string_fetch(&error, file, SS("error"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(error);
				ZVAL_BOOL(error, 1);
			}
			if (!(zephir_is_true(error))) {
				numberFiles++;
			}
		}
	}
	RETURN_MM_BOOL((numberFiles > 0));

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @param boolean notErrored
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	HashTable *_1;
	HashPosition _0;
	zval *notErrored_param = NULL, *files, *superFiles = NULL, *file = NULL, *error = NULL, *_FILES, **_2, *_3 = NULL;
	zend_bool notErrored;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &notErrored_param);

	if (!notErrored_param) {
		notErrored = 0;
	} else {
		notErrored = zephir_get_boolval(notErrored_param);
	}


	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	ZEPHIR_CPY_WRT(superFiles, _FILES);
	if (zephir_fast_count_int(superFiles TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(files);
		array_init(files);
		zephir_is_iterable(superFiles, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(file, _2);
			if (notErrored) {
				ZEPHIR_OBS_NVAR(error);
				if (!(zephir_array_isset_string_fetch(&error, file, SS("error"), 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(error);
					ZVAL_BOOL(error, 1);
				}
				if (!(zephir_is_true(error))) {
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_http_request_file_ce);
					zephir_array_append(&files, _3, PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_http_request_file_ce);
				zephir_array_append(&files, _3, PH_SEPARATE);
			}
		}
		RETURN_CCTOR(files);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Returns the available headers in the request
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	HashTable *_1;
	HashPosition _0;
	zval *headers, *key = NULL, *value = NULL, *_SERVER, **_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_is_iterable(_SERVER, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_start_with_str(key, SL("HTTP_"))) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "HTTP_", 0);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "", 0);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p3(_5, "str_replace", &_3, &_4, key);
			zephir_array_update_zval(&headers, _5, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(headers);

}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer) {

	zval *httpReferer, *_SERVER;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&httpReferer, _SERVER, SS("HTTP_REFERER"), 1 TSRMLS_CC)) {
		RETURN_CTORW(httpReferer);
	}
	RETURN_STRING("", 1);

}

/**
 * Process a request header and return an array of values with their qualities
 *
 * @param string serverIndex
 * @param string name
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader) {

	HashTable *_4;
	HashPosition _3;
	double quality;
	zval *serverIndex_param = NULL, *name_param = NULL, *returnedParts, *part = NULL, *headerParts = NULL, *qualityPart, *_0, _1 = zval_used_for_init, *_2, **_5, *_6 = NULL, *_7 = NULL, *_8 = NULL;
	zval *serverIndex = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

		if (Z_TYPE_P(serverIndex_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		serverIndex = serverIndex_param;

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	ZEPHIR_INIT_VAR(returnedParts);
	array_init(returnedParts);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "getserver", serverIndex);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/,\\s*/", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "preg_split", &_1, _0);
	zephir_is_iterable(_2, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(part, _5);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, ";", 0);
		ZEPHIR_INIT_NVAR(headerParts);
		zephir_call_func_p2(headerParts, "explode", &_1, part);
		if (zephir_array_isset_long_fetch(&qualityPart, headerParts, 1, 1 TSRMLS_CC)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 2);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_func_p2(_6, "substr", qualityPart, &_1);
			quality = zephir_get_doubleval(_6);
		} else {
			quality = 1.0;
		}
		ZEPHIR_INIT_NVAR(_6);
		array_init(_6);
		ZEPHIR_OBS_NVAR(_7);
		zephir_array_fetch_long(&_7, headerParts, 0, PH_NOISY TSRMLS_CC);
		zephir_array_update_string(&_6, SL("name"), &_7, PH_COPY);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_DOUBLE(_8, quality);
		zephir_array_update_string(&_6, SL("quality"), &_8, PH_COPY | PH_SEPARATE);
		zephir_array_append(&returnedParts, _6, PH_SEPARATE);
		//missing empty
	}
	RETURN_CCTOR(returnedParts);

}

/**
 * Process a request header and return the one with best quality
 *
 * @param array qualityParts
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality) {

	HashTable *_1;
	HashPosition _0;
	double quality, acceptQuality;
	int i;
	zval *name = NULL;
	zval *qualityParts, *name_param = NULL, *selectedName = NULL, *accept = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &qualityParts, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(selectedName);
	ZVAL_STRING(selectedName, "", 1);
	zephir_is_iterable(qualityParts, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(accept, _2);
		if ((i == 0)) {
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, accept, SL("quality"), PH_NOISY TSRMLS_CC);
			quality = zephir_get_doubleval(_3);
			ZEPHIR_OBS_NVAR(selectedName);
			zephir_array_fetch(&selectedName, accept, name, PH_NOISY TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, accept, SL("quality"), PH_NOISY TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(_3);
			if ((acceptQuality > quality)) {
				quality = acceptQuality;
				ZEPHIR_OBS_NVAR(selectedName);
				zephir_array_fetch(&selectedName, accept, name, PH_NOISY TSRMLS_CC);
			}
		}
		i++;
	}
	RETURN_CCTOR(selectedName);

}

/**
 * Gets array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", 1);
	zephir_call_method_p2(return_value, this_ptr, "_getqualityheader", _0, _1);
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getacceptablecontent");
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", 1);
	zephir_call_method_p2(return_value, this_ptr, "_getbestquality", _0, _1);
	RETURN_MM();

}

/**
 * Gets charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_CHARSET", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", 1);
	zephir_call_method_p2(return_value, this_ptr, "_getqualityheader", _0, _1);
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getclientcharsets");
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", 1);
	zephir_call_method_p2(return_value, this_ptr, "_getbestquality", _0, _1);
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_LANGUAGE", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", 1);
	zephir_call_method_p2(return_value, this_ptr, "_getqualityheader", _0, _1);
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getlanguages");
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", 1);
	zephir_call_method_p2(return_value, this_ptr, "_getbestquality", _0, _1);
	RETURN_MM();

}


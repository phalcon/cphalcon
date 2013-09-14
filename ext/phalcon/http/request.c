
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
#include "kernel/concat.h"
#include "kernel/string.h"


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

	zval *name = NULL, *filters = NULL, *defaultValue = NULL, *request = NULL, *value, *filter = NULL, *dependencyInjector, *_REQUEST, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name, &filters, &defaultValue);

	if (!name) {
		ZEPHIR_CPY_WRT(name, ZEPHIR_GLOBAL(global_null));
	}
	if (!filters) {
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(request, _REQUEST);
	if ((Z_TYPE_P(name) != IS_NULL)) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, request, name)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					ZEPHIR_OBS_VAR(dependencyInjector);
					zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
					ZEPHIR_INIT_VAR(_0);
					ZVAL_STRING(_0, "filter", 1);
					ZEPHIR_INIT_NVAR(filter);
					zephir_call_method_p1(filter, dependencyInjector, "getshared", _0);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", value, filters);
				RETURN_MM();
			} else {
				RETURN_CCTOR(value);
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

	zval *name = NULL, *filters = NULL, *defaultValue = NULL, *post = NULL, *value, *filter = NULL, *dependencyInjector, *_POST, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name, &filters, &defaultValue);

	if (!name) {
		ZEPHIR_CPY_WRT(name, ZEPHIR_GLOBAL(global_null));
	}
	if (!filters) {
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(post, _POST);
	if ((Z_TYPE_P(name) != IS_NULL)) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, post, name)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					ZEPHIR_OBS_VAR(dependencyInjector);
					zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
					ZEPHIR_INIT_VAR(_0);
					ZVAL_STRING(_0, "filter", 1);
					ZEPHIR_INIT_NVAR(filter);
					zephir_call_method_p1(filter, dependencyInjector, "getshared", _0);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", value, filters);
				RETURN_MM();
			} else {
				RETURN_CCTOR(value);
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

	zval *name = NULL, *filters = NULL, *defaultValue = NULL, *get = NULL, *value, *filter = NULL, *dependencyInjector, *_GET, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name, &filters, &defaultValue);

	if (!name) {
		ZEPHIR_CPY_WRT(name, ZEPHIR_GLOBAL(global_null));
	}
	if (!filters) {
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	ZEPHIR_CPY_WRT(get, _GET);
	if ((Z_TYPE_P(name) != IS_NULL)) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, get, name)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					ZEPHIR_OBS_VAR(dependencyInjector);
					zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
					ZEPHIR_INIT_VAR(_0);
					ZVAL_STRING(_0, "filter", 1);
					ZEPHIR_INIT_NVAR(filter);
					zephir_call_method_p1(filter, dependencyInjector, "getshared", _0);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", value, filters);
				RETURN_MM();
			} else {
				RETURN_CCTOR(value);
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

	zval *name, *serverValue, *_SERVER;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_OBS_VAR(serverValue);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_fetch(&serverValue, _SERVER, name)) {
		RETURN_CCTOR(serverValue);
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

	zval *name, *_REQUEST;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	RETURN_BOOL(zephir_array_isset(_REQUEST, name));

}

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zval *name, *_POST;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	RETURN_BOOL(zephir_array_isset(_POST, name));

}

/**
 * Checks whether $_GET superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery) {

	zval *name, *_GET;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	RETURN_BOOL(zephir_array_isset(_GET, name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name, *_SERVER;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	RETURN_BOOL(zephir_array_isset(_SERVER, name));

}

/**
 * Gets HTTP header from request data
 *
 * @param string header
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	zval *header, *serverValue, *headerValue, *_SERVER, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header);



	ZEPHIR_OBS_VAR(serverValue);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_fetch(&serverValue, _SERVER, header)) {
		RETURN_CCTOR(serverValue);
	} else {
		ZEPHIR_OBS_VAR(headerValue);
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "HTTP_", header);
		if (zephir_array_isset_fetch(&headerValue, _SERVER, _0)) {
			RETURN_CCTOR(headerValue);
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
	if (zend_is_true(https)) {
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
		ZEPHIR_OBS_VAR(contentType);
		if (zephir_array_isset_string_fetch(&contentType, server, SS("CONTENT_TYPE"))) {
			RETURN_MM_BOOL(zephir_memnstr_str(contentType, SL("application/soap+xml"), "/Users/gutierrezandresfelipe/cphalcon/phalcon/http/request.zep", 330));
		}
	}
	RETURN_MM_BOOL(0);

}


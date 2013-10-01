
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
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(request, _REQUEST);
	if (!ZEPHIR_IS_STRING(name, "")) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, request, name TSRMLS_CC)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				ZEPHIR_OBS_NVAR(filter);
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
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(post, _POST);
	if (!ZEPHIR_IS_STRING(name, "")) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, post, name TSRMLS_CC)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				ZEPHIR_OBS_NVAR(filter);
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
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	ZEPHIR_CPY_WRT(get, _GET);
	if (!ZEPHIR_IS_STRING(name, "")) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, get, name TSRMLS_CC)) {
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				ZEPHIR_OBS_NVAR(filter);
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

	zval *name_param = NULL, *serverValue, *_SERVER;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(serverValue);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_fetch(&serverValue, _SERVER, name TSRMLS_CC)) {
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

	zval *name_param = NULL, *_REQUEST;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


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

		zephir_get_strval(name, name_param);


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

		zephir_get_strval(name, name_param);


	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_GET, name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name_param = NULL, *_SERVER;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


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

		zephir_get_strval(header, header_param);


	ZEPHIR_OBS_VAR(serverValue);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_fetch(&serverValue, _SERVER, header TSRMLS_CC)) {
		RETURN_CCTOR(serverValue);
	} else {
		ZEPHIR_OBS_VAR(headerValue);
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "HTTP_", header);
		if (zephir_array_isset_fetch(&headerValue, _SERVER, _0 TSRMLS_CC)) {
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
		ZEPHIR_OBS_VAR(contentType);
		if (zephir_array_isset_string_fetch(&contentType, server, SS("CONTENT_TYPE") TSRMLS_CC)) {
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



}

/**
 * Gets HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody) {



}

/**
 * Gets decoded JSON HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {



}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {



}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {



}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {



}

/**
 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
 *
 * @param boolean trustForwardedHeader
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zval *trustForwardedHeader_param = NULL;
	zend_bool trustForwardedHeader;

	zephir_fetch_params(0, 0, 1, &trustForwardedHeader_param);

	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		trustForwardedHeader = zephir_get_boolval(trustForwardedHeader_param);
	}



}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {



}

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {



}

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array methods
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isMethod) {

	zval *methods;

	zephir_fetch_params(0, 1, 0, &methods);




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

	zval *notErrored_param = NULL;
	zend_bool notErrored;

	zephir_fetch_params(0, 0, 1, &notErrored_param);

	if (!notErrored_param) {
		notErrored = 0;
	} else {
		notErrored = zephir_get_boolval(notErrored_param);
	}



}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @param boolean notErrored
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	zval *notErrored_param = NULL;
	zend_bool notErrored;

	zephir_fetch_params(0, 0, 1, &notErrored_param);

	if (!notErrored_param) {
		notErrored = 0;
	} else {
		notErrored = zephir_get_boolval(notErrored_param);
	}



}

/**
 * Returns the available headers in the request
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {



}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer) {



}

/**
 * Process a request header and return an array of values with their qualities
 *
 * @param string serverIndex
 * @param string name
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader) {

	zval *serverIndex, *name;

	zephir_fetch_params(0, 2, 0, &serverIndex, &name);




}

/**
 * Process a request header and return the one with best quality
 *
 * @param array qualityParts
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality) {

	zval *qualityParts, *name;

	zephir_fetch_params(0, 2, 0, &qualityParts, &name);




}

/**
 * Gets array with mime/types and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent) {



}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {



}

/**
 * Gets charsets array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {



}

/**
 * Gets best charset accepted by the browser/client from _SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {



}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {



}

/**
 * Gets best language accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {



}


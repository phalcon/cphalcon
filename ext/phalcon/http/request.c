
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/hash.h"


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
 * Phalcon\Http\Request
 *
 * <p>Encapsulates request information for easy and secure access from application controllers.</p>
 *
 * <p>The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.</p>
 *
 *<code>
 *	$request = new \Phalcon\Http\Request();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *request = NULL, *value, *filter = NULL, *dependencyInjector = NULL, *_REQUEST, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &filters, &defaultValue);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
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
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, request, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 97);
						return;
					}
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", 0);
					ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_RETURN_CALL_METHOD(filter, "sanitize", NULL, value, filters);
				zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *post = NULL, *value, *filter = NULL, *dependencyInjector = NULL, *_POST, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &filters, &defaultValue);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
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
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, post, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 141);
						return;
					}
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", 0);
					ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_RETURN_CALL_METHOD(filter, "sanitize", NULL, value, filters);
				zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *get = NULL, *value, *filter = NULL, *dependencyInjector = NULL, *_GET, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &filters, &defaultValue);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
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
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, get, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 188);
						return;
					}
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", 0);
					ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_RETURN_CALL_METHOD(filter, "sanitize", NULL, value, filters);
				zephir_check_call_status();
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

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


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

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


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

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


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

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


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

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


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

	zval *header_param = NULL, *serverValue, *headerValue, *_SERVER;
	zval *header = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	if (unlikely(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(header_param) == IS_STRING)) {
		header = header_param;
	} else {
		ZEPHIR_INIT_VAR(header);
		ZVAL_EMPTY_STRING(header);
	}


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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *https = NULL, *scheme = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTPS", 0);
	ZEPHIR_CALL_METHOD(&https, this_ptr, "getserver", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
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

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_X_REQUESTED_WITH", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
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
		if (zephir_array_isset_string_fetch(&contentType, server, SS("CONTENT_TYPE"), 0 TSRMLS_CC)) {
			RETURN_MM_BOOL(zephir_memnstr_str(contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 329));
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme",  NULL);
	zephir_check_call_status();
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

	ZEPHIR_OBS_VAR(rawBody);
	zephir_read_property_this(&rawBody, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(rawBody)) {
		ZEPHIR_INIT_VAR(contents);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "php://input", 0);
		zephir_file_get_contents(contents, &_0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_rawBody"), contents TSRMLS_CC);
		RETURN_CCTOR(contents);
	}
	RETURN_CCTOR(rawBody);

}

/**
 * Gets decoded JSON HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rawBody = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody",  NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(rawBody) == IS_STRING) {
		zephir_json_decode(return_value, &(return_value), rawBody, 0  TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *serverAddr, *_SERVER, _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(serverAddr);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&serverAddr, _SERVER, SS("SERVER_ADDR"), 0 TSRMLS_CC)) {
		RETURN_CCTOR(serverAddr);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "localhost", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval *serverName, *_SERVER;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&serverName, _SERVER, SS("SERVER_NAME"), 1 TSRMLS_CC)) {
		RETURN_CTORW(serverName);
	}
	RETURN_STRING("localhost", 1);

}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zend_bool _1, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpHost = NULL, *scheme = NULL, *name = NULL, *port = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", 0);
	ZEPHIR_CALL_METHOD(&httpHost, this_ptr, "getserver", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(httpHost)) {
		RETURN_CCTOR(httpHost);
	}
	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "getscheme",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "SERVER_NAME", 0);
	ZEPHIR_CALL_METHOD(&name, this_ptr, "getserver", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "SERVER_PORT", 0);
	ZEPHIR_CALL_METHOD(&port, this_ptr, "getserver", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_STRING(scheme, "http");
	if (_1) {
		_1 = ZEPHIR_IS_LONG(port, 80);
	}
	if (_1) {
		RETURN_CCTOR(name);
	}
	_2 = ZEPHIR_IS_STRING(scheme, "https");
	if (_2) {
		_2 = ZEPHIR_IS_LONG(port, 443);
	}
	if (_2) {
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

	zval *trustForwardedHeader_param = NULL, *address = NULL, *_SERVER, *_0, *_1;
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
		ZEPHIR_OBS_VAR(address);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_array_isset_string_fetch(&address, _SERVER, SS("HTTP_X_FORWARDED_FOR"), 0 TSRMLS_CC);
	}
	if (Z_TYPE_P(address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(address);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_array_isset_string_fetch(&address, _SERVER, SS("REMOTE_ADDR"), 0 TSRMLS_CC);
	}
	if (Z_TYPE_P(address) == IS_STRING) {
		if (zephir_memnstr_str(address, SL(","), "phalcon/http/request.zep", 488)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_explode_str(_0, SL(","), address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_1, _0, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			RETURN_CTOR(_1);
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

	HashTable *_2;
	HashPosition _1;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *methods, *httpMethod = NULL, *method = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &methods);



	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod",  &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, httpMethod));
	} else {
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			zephir_is_iterable(methods, &_2, &_1, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(method, _3);
				if (ZEPHIR_IS_EQUAL(method, httpMethod)) {
					RETURN_MM_BOOL(1);
				}
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "POST"));

}

/**
 *
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]=="GET"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]=="PUT"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]=="PATCH"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]=="HEAD"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]=="DELETE"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]=="OPTIONS"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "OPTIONS"));

}

/**
 * Checks whether request include attached files
 *
 * @param boolean onlySuccessful
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	int numberFiles = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, *files = NULL, *file = NULL, *error = NULL, *_FILES, **_2, *_4 = NULL;
	zend_bool onlySuccessful, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	ZEPHIR_CPY_WRT(files, _FILES);
	if (Z_TYPE_P(files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(files, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(file, _2);
		ZEPHIR_OBS_NVAR(error);
		if (zephir_array_isset_string_fetch(&error, file, SS("error"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(error) != IS_ARRAY) {
				_3 = !zephir_is_true(error);
				if (!(_3)) {
					_3 = !onlySuccessful;
				}
				if (_3) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(error) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(&_4, this_ptr, "hasfilehelper", &_5, error, (onlySuccessful ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(_4);
			}
		}
	}
	RETURN_MM_LONG(numberFiles);

}

PHP_METHOD(Phalcon_Http_Request, hasFileHelper) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	int numberFiles = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_bool onlySuccessful, _3;
	zval *data, *onlySuccessful_param = NULL, *value = NULL, **_2, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(value) != IS_ARRAY) {
			_3 = !zephir_is_true(value);
			if (!(_3)) {
				_3 = !onlySuccessful;
			}
			if (_3) {
				numberFiles++;
			}
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "hasfilehelper", &_5, value, (onlySuccessful ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
			zephir_check_call_status();
			numberFiles += zephir_get_numberval(_4);
		}
	}
	RETURN_MM_LONG(numberFiles);

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @param boolean notErrored
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_5, *_10;
	HashPosition _0, _4, _9;
	zval *notErrored_param = NULL, *superFiles = NULL, *file = NULL, *files, *error = NULL, *subFiles = NULL, *subFile = NULL, *_FILES, **_2, *_3 = NULL, **_6, *_7 = NULL, **_11, *_12 = NULL;
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
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(file, _2);
			if (notErrored) {
				ZEPHIR_OBS_NVAR(_3);
				zephir_array_fetch_string(&_3, file, SL("name"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(_3) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(subFiles);
					array_init(subFiles);
					zephir_is_iterable(file, &_5, &_4, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
					  ; zephir_hash_move_forward_ex(_5, &_4)
					) {
						ZEPHIR_GET_HVALUE(subFile, _6);
						ZEPHIR_OBS_NVAR(error);
						if (!(zephir_array_isset_string_fetch(&error, subFile, SS("error"), 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(error);
							ZVAL_BOOL(error, 1);
						}
						if (!(zephir_is_true(error))) {
							ZEPHIR_INIT_LNVAR(_7);
							object_init_ex(_7, phalcon_http_request_file_ce);
							ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_8, subFile);
							zephir_check_call_status();
							zephir_array_append(&subFiles, _7, PH_SEPARATE);
						}
					}
					zephir_array_append(&files, subFiles, PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(error);
					if (!(zephir_array_isset_string_fetch(&error, file, SS("error"), 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(error);
						ZVAL_BOOL(error, 1);
					}
					if (!(zephir_is_true(error))) {
						ZEPHIR_INIT_LNVAR(_7);
						object_init_ex(_7, phalcon_http_request_file_ce);
						ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_8, file);
						zephir_check_call_status();
						zephir_array_append(&files, _7, PH_SEPARATE);
					}
				}
			} else {
				ZEPHIR_OBS_NVAR(_3);
				zephir_array_fetch_string(&_3, file, SL("name"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(_3) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(subFiles);
					array_init(subFiles);
					zephir_is_iterable(file, &_10, &_9, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
					  ; zephir_hash_move_forward_ex(_10, &_9)
					) {
						ZEPHIR_GET_HVALUE(subFile, _11);
						ZEPHIR_INIT_LNVAR(_12);
						object_init_ex(_12, phalcon_http_request_file_ce);
						ZEPHIR_CALL_METHOD(NULL, _12, "__construct", &_8, subFile);
						zephir_check_call_status();
						zephir_array_append(&subFiles, _12, PH_SEPARATE);
					}
					zephir_array_append(&files, subFiles, PH_SEPARATE);
				} else {
					ZEPHIR_INIT_LNVAR(_12);
					object_init_ex(_12, phalcon_http_request_file_ce);
					ZEPHIR_CALL_METHOD(NULL, _12, "__construct", &_8, file);
					zephir_check_call_status();
					zephir_array_append(&files, _12, PH_SEPARATE);
				}
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
	zval *headers, *key = NULL, *value = NULL, *_SERVER, **_2, *_3 = NULL, _4 = zval_used_for_init, _5 = zval_used_for_init;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_is_iterable(_SERVER, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_start_with_str(key, SL("HTTP_"))) {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "HTTP_", 0);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "", 0);
			zephir_fast_str_replace(_3, &_4, &_5, key);
			zephir_array_update_zval(&headers, _3, &value, PH_COPY | PH_SEPARATE);
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

	zval *_9 = NULL;
	HashTable *_5;
	HashPosition _4;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	double quality;
	zval *serverIndex_param = NULL, *name_param = NULL, *returnedParts, *part = NULL, *headerParts = NULL, *qualityPart = NULL, *_0 = NULL, _1 = zval_used_for_init, *_2 = NULL, **_6, *_7 = NULL, *_10 = NULL, *_11 = NULL;
	zval *serverIndex = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

	if (unlikely(Z_TYPE_P(serverIndex_param) != IS_STRING && Z_TYPE_P(serverIndex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(serverIndex_param) == IS_STRING)) {
		serverIndex = serverIndex_param;
	} else {
		ZEPHIR_INIT_VAR(serverIndex);
		ZVAL_EMPTY_STRING(serverIndex);
	}
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(returnedParts);
	array_init(returnedParts);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getserver", NULL, serverIndex);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/,\\s*/", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_split", &_3, &_1, _0);
	zephir_check_call_status();
	zephir_is_iterable(_2, &_5, &_4, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(part, _6);
		ZEPHIR_INIT_NVAR(headerParts);
		zephir_fast_explode_str(headerParts, SL(";"), part, LONG_MAX TSRMLS_CC);
		ZEPHIR_OBS_NVAR(qualityPart);
		if (zephir_array_isset_long_fetch(&qualityPart, headerParts, 1, 0 TSRMLS_CC)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 2);
			ZEPHIR_CALL_FUNCTION(&_7, "substr", &_8, qualityPart, &_1);
			zephir_check_call_status();
			quality = zephir_get_doubleval(_7);
		} else {
			quality = 1.0;
		}
		ZEPHIR_INIT_NVAR(_9);
		array_init_size(_9, 3);
		ZEPHIR_OBS_NVAR(_10);
		zephir_array_fetch_long(&_10, headerParts, 0, PH_NOISY TSRMLS_CC);
		zephir_array_update_string(&_9, SL("name"), &_10, PH_COPY);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_DOUBLE(_11, quality);
		zephir_array_update_string(&_9, SL("quality"), &_11, PH_COPY | PH_SEPARATE);
		zephir_array_append(&returnedParts, _9, PH_SEPARATE);
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

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(selectedName);
	ZVAL_STRING(selectedName, "", 1);
	zephir_is_iterable(qualityParts, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(accept, _2);
		if (i == 0) {
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, accept, SL("quality"), PH_NOISY TSRMLS_CC);
			quality = zephir_get_doubleval(_3);
			ZEPHIR_OBS_NVAR(selectedName);
			zephir_array_fetch(&selectedName, accept, name, PH_NOISY TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, accept, SL("quality"), PH_NOISY TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(_3);
			if (acceptQuality > quality) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_CHARSET", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_LANGUAGE", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth) {

	zend_bool _0;
	zval *auth, *_SERVER, *_1, *_2;

	ZEPHIR_MM_GROW();

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	_0 = zephir_array_isset_string(_SERVER, SS("PHP_AUTH_USER"));
	if (_0) {
		_0 = zephir_array_isset_string(_SERVER, SS("PHP_AUTH_PW"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(auth);
		array_init(auth);
		zephir_array_fetch_string(&_1, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_update_string(&auth, SL("password"), &_2, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(auth);
	}
	RETURN_MM_NULL();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *auth;
	zval *digest, *matches, *match = NULL, *_SERVER, *_0, *_1, *_2 = NULL, **_6, *_7, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(auth);
	array_init(auth);
	ZEPHIR_OBS_VAR(digest);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&digest, _SERVER, SS("PHP_AUTH_USER"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(matches);
		array_init(matches);
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#", 0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, 2);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_2, "preg_match_all", &_3, _0, digest, matches, _1);
		zephir_check_temp_parameter(_0);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (!(zephir_is_true(_2))) {
			RETURN_CTOR(auth);
		}
		if (Z_TYPE_P(matches) == IS_ARRAY) {
			zephir_is_iterable(matches, &_5, &_4, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HVALUE(match, _6);
				zephir_array_fetch_long(&_7, match, 3, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_8);
				zephir_array_fetch_long(&_8, match, 1, PH_NOISY TSRMLS_CC);
				zephir_array_update_zval(&auth, _8, &_7, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CTOR(auth);

}



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
 * @param boolean notAllowEmpty
 * @param boolean noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	zend_bool _3, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty = NULL, *noRecursive = NULL, *request = NULL, *value = NULL, *filter = NULL, *dependencyInjector = NULL, *_REQUEST, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty, &noRecursive);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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
	if (!notAllowEmpty) {
		notAllowEmpty = ZEPHIR_GLOBAL(global_false);
	}
	if (!noRecursive) {
		noRecursive = ZEPHIR_GLOBAL(global_false);
	}


	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(request, _REQUEST);
	if (!ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, request, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 105);
						return;
					}
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_1, filter, "sanitize", NULL, value, filters, noRecursive);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, _1);
				_3 = ZEPHIR_IS_EMPTY(value);
				if (_3) {
					_3 = ZEPHIR_IS_TRUE_IDENTICAL(notAllowEmpty);
				}
				_4 = _3;
				if (!(_4)) {
					_4 = ZEPHIR_IS_FALSE_IDENTICAL(value);
				}
				if (_4) {
					RETVAL_ZVAL(defaultValue, 1, 0);
					RETURN_MM();
				}
				RETURN_CCTOR(value);
			} else {
				_3 = ZEPHIR_IS_EMPTY(value);
				if (_3) {
					_3 = ZEPHIR_IS_TRUE_IDENTICAL(notAllowEmpty);
				}
				if (_3) {
					RETVAL_ZVAL(defaultValue, 1, 0);
					RETURN_MM();
				}
				RETURN_CCTOR(value);
			}
		}
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
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
 * @param boolean notAllowEmpty
 * @param boolean noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty = NULL, *noRecursive = NULL, *post = NULL, *value = NULL, *filter = NULL, *dependencyInjector = NULL, *_POST, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty, &noRecursive);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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
	if (!notAllowEmpty) {
		notAllowEmpty = ZEPHIR_GLOBAL(global_false);
	}
	if (!noRecursive) {
		noRecursive = ZEPHIR_GLOBAL(global_false);
	}


	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	ZEPHIR_CPY_WRT(post, _POST);
	if (!ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, post, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 164);
						return;
					}
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_1, filter, "sanitize", NULL, value, filters, noRecursive);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, _1);
				_3 = ZEPHIR_IS_EMPTY(value);
				if (_3) {
					_3 = ZEPHIR_IS_TRUE_IDENTICAL(notAllowEmpty);
				}
				if (_3) {
					RETVAL_ZVAL(defaultValue, 1, 0);
					RETURN_MM();
				}
				RETURN_CCTOR(value);
			} else {
				_3 = ZEPHIR_IS_EMPTY(value);
				if (_3) {
					_3 = ZEPHIR_IS_TRUE_IDENTICAL(notAllowEmpty);
				}
				if (_3) {
					RETVAL_ZVAL(defaultValue, 1, 0);
					RETURN_MM();
				}
				RETURN_CCTOR(value);
			}
		}
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
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
 * @param boolean notAllowEmpty
 * @param boolean noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty = NULL, *noRecursive = NULL, *get = NULL, *value = NULL, *filter = NULL, *dependencyInjector = NULL, *_GET, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty, &noRecursive);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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
	if (!notAllowEmpty) {
		notAllowEmpty = ZEPHIR_GLOBAL(global_false);
	}
	if (!noRecursive) {
		noRecursive = ZEPHIR_GLOBAL(global_false);
	}


	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	ZEPHIR_CPY_WRT(get, _GET);
	if (!ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, get, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CPY_WRT(dependencyInjector, _0);
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 225);
						return;
					}
					ZEPHIR_INIT_VAR(_2);
					ZVAL_STRING(_2, "filter", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(filter, _1);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_1, filter, "sanitize", NULL, value, filters, noRecursive);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, _1);
				_3 = ZEPHIR_IS_EMPTY(value);
				if (_3) {
					_3 = ZEPHIR_IS_TRUE_IDENTICAL(notAllowEmpty);
				}
				if (_3) {
					RETVAL_ZVAL(defaultValue, 1, 0);
					RETURN_MM();
				}
				RETURN_CCTOR(value);
			} else {
				_3 = ZEPHIR_IS_EMPTY(value);
				if (_3) {
					_3 = ZEPHIR_IS_TRUE_IDENTICAL(notAllowEmpty);
				}
				if (_3) {
					RETVAL_ZVAL(defaultValue, 1, 0);
					RETURN_MM();
				}
				RETURN_CCTOR(value);
			}
		}
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
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

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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

	if (likely(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(header, header_param);
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
	ZVAL_STRING(_0, "HTTPS", ZEPHIR_TEMP_PARAM_COPY);
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
 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH']==='XMLHttpRequest'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_X_REQUESTED_WITH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "XMLHttpRequest"));

}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *contentType = NULL, *_SERVER;

	ZEPHIR_MM_GROW();

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string(_SERVER, SS("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 379));
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

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "https"));

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
 * @param boolean associative
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, *rawBody = NULL;
	zend_bool associative;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(rawBody) == IS_STRING) {
		zephir_json_decode(return_value, &(return_value), rawBody, zephir_get_intval((associative ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)))  TSRMLS_CC);
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
	zval *httpHost = NULL, *scheme = NULL, *name = NULL, *port = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&httpHost, this_ptr, "getserver", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(httpHost)) {
		RETURN_CCTOR(httpHost);
	}
	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "getscheme", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "SERVER_NAME", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&name, this_ptr, "getserver", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "SERVER_PORT", ZEPHIR_TEMP_PARAM_COPY);
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
 * Gets HTTP URI which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getURI) {

	zval *requestURI, *_SERVER;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&requestURI, _SERVER, SS("REQUEST_URI"), 1 TSRMLS_CC)) {
		RETURN_CTORW(requestURI);
	}
	RETURN_STRING("", 1);

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
		ZEPHIR_OBS_NVAR(address);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_array_isset_string_fetch(&address, _SERVER, SS("HTTP_X_FORWARDED_FOR"), 0 TSRMLS_CC);
	}
	if (Z_TYPE_P(address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(address);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_array_isset_string_fetch(&address, _SERVER, SS("REMOTE_ADDR"), 0 TSRMLS_CC);
	}
	if (Z_TYPE_P(address) == IS_STRING) {
		if (zephir_memnstr_str(address, SL(","), "phalcon/http/request.zep", 555)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_explode_str(_0, SL(","), address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_1, _0, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 559 TSRMLS_CC);
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



	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, httpMethod));
	} else {
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			zephir_is_iterable(methods, &_2, &_1, 0, 0, "phalcon/http/request.zep", 618);
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
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "POST"));

}

/**
 *
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "OPTIONS"));

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
	zephir_is_iterable(files, &_1, &_0, 0, 0, "phalcon/http/request.zep", 726);
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
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/http/request.zep", 750);
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

	zephir_fcall_cache_entry *_9 = NULL, *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_11;
	HashPosition _0, _10;
	zval *notErrored_param = NULL, *superFiles = NULL, *prefix = NULL, *input = NULL, *smoothInput = NULL, *files, *file = NULL, *dataFile = NULL, *_FILES, **_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, **_12, *_14, *_15 = NULL, *_16 = NULL, *_17;
	zend_bool notErrored, _13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &notErrored_param);

	if (!notErrored_param) {
		notErrored = 0;
	} else {
		notErrored = zephir_get_boolval(notErrored_param);
	}


	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	ZEPHIR_CPY_WRT(superFiles, _FILES);
	ZEPHIR_INIT_VAR(files);
	array_init(files);
	if (zephir_fast_count_int(superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(superFiles, &_1, &_0, 0, 0, "phalcon/http/request.zep", 792);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(prefix, _1, _0);
			ZEPHIR_GET_HVALUE(input, _2);
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 770 TSRMLS_CC);
			if (Z_TYPE_P(_3) == IS_ARRAY) {
				zephir_array_fetch_string(&_4, input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 771 TSRMLS_CC);
				zephir_array_fetch_string(&_5, input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 771 TSRMLS_CC);
				zephir_array_fetch_string(&_6, input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 771 TSRMLS_CC);
				zephir_array_fetch_string(&_7, input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 771 TSRMLS_CC);
				zephir_array_fetch_string(&_8, input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 771 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_9, _4, _5, _6, _7, _8, prefix);
				zephir_check_call_status();
				zephir_is_iterable(smoothInput, &_11, &_10, 0, 0, "phalcon/http/request.zep", 786);
				for (
				  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11, &_10)
				) {
					ZEPHIR_GET_HVALUE(file, _12);
					_13 = notErrored == 0;
					if (!(_13)) {
						zephir_array_fetch_string(&_14, file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 774 TSRMLS_CC);
						_13 = ZEPHIR_IS_LONG(_14, 0);
					}
					if (_13) {
						ZEPHIR_INIT_NVAR(dataFile);
						array_init_size(dataFile, 7);
						ZEPHIR_OBS_NVAR(_15);
						zephir_array_fetch_string(&_15, file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 776 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("name"), &_15, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15);
						zephir_array_fetch_string(&_15, file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 777 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("type"), &_15, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15);
						zephir_array_fetch_string(&_15, file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 778 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("tmp_name"), &_15, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15);
						zephir_array_fetch_string(&_15, file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 779 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("size"), &_15, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15);
						zephir_array_fetch_string(&_15, file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 781 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("error"), &_15, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(_16);
						object_init_ex(_16, phalcon_http_request_file_ce);
						zephir_array_fetch_string(&_17, file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 783 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, _16, "__construct", &_18, dataFile, _17);
						zephir_check_call_status();
						zephir_array_append(&files, _16, PH_SEPARATE, "phalcon/http/request.zep", 783);
					}
				}
			} else {
				_13 = notErrored == 0;
				if (!(_13)) {
					zephir_array_fetch_string(&_4, input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 787 TSRMLS_CC);
					_13 = ZEPHIR_IS_LONG(_4, 0);
				}
				if (_13) {
					ZEPHIR_INIT_NVAR(_16);
					object_init_ex(_16, phalcon_http_request_file_ce);
					ZEPHIR_CALL_METHOD(NULL, _16, "__construct", &_18, input, prefix);
					zephir_check_call_status();
					zephir_array_append(&files, _16, PH_SEPARATE, "phalcon/http/request.zep", 788);
				}
			}
		}
	}
	RETURN_CCTOR(files);

}

/**
 * smooth out $_FILES to have plain array with all files uploaded
 *
 * @param array names
 * @param array types
 * @param array tmp_names
 * @param array sizes
 * @param array errors
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles) {

	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_12;
	HashPosition _0, _11;
	zval *prefix = NULL;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, *prefix_param = NULL, *idx = NULL, *name = NULL, *file = NULL, *files, *parentFiles = NULL, *p = NULL, **_2, *_4 = NULL, *_5, *_6, *_7, *_8, *_9, **_13;
	zval *names = NULL, *types = NULL, *tmp_names = NULL, *sizes = NULL, *errors = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &names_param, &types_param, &tmp_names_param, &sizes_param, &errors_param, &prefix_param);

	names = names_param;

	types = types_param;

	tmp_names = tmp_names_param;

	sizes = sizes_param;

	errors = errors_param;

	zephir_get_strval(prefix, prefix_param);


	ZEPHIR_INIT_VAR(files);
	array_init(files);
	zephir_is_iterable(names, &_1, &_0, 0, 0, "phalcon/http/request.zep", 837);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(idx, _1, _0);
		ZEPHIR_GET_HVALUE(name, _2);
		ZEPHIR_INIT_NVAR(p);
		ZEPHIR_CONCAT_VSV(p, prefix, ".", idx);
		if (Z_TYPE_P(name) == IS_STRING) {
			ZEPHIR_INIT_NVAR(_3);
			array_init_size(_3, 11);
			zephir_array_update_string(&_3, SL("name"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch(&_4, types, idx, PH_NOISY, "phalcon/http/request.zep", 820 TSRMLS_CC);
			zephir_array_update_string(&_3, SL("type"), &_4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch(&_4, tmp_names, idx, PH_NOISY, "phalcon/http/request.zep", 821 TSRMLS_CC);
			zephir_array_update_string(&_3, SL("tmp_name"), &_4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch(&_4, sizes, idx, PH_NOISY, "phalcon/http/request.zep", 822 TSRMLS_CC);
			zephir_array_update_string(&_3, SL("size"), &_4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch(&_4, errors, idx, PH_NOISY, "phalcon/http/request.zep", 823 TSRMLS_CC);
			zephir_array_update_string(&_3, SL("error"), &_4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3, SL("key"), &p, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, _3, PH_SEPARATE, "phalcon/http/request.zep", 825);
		}
		if (Z_TYPE_P(name) == IS_ARRAY) {
			zephir_array_fetch(&_5, names, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 829 TSRMLS_CC);
			zephir_array_fetch(&_6, types, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 829 TSRMLS_CC);
			zephir_array_fetch(&_7, tmp_names, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 829 TSRMLS_CC);
			zephir_array_fetch(&_8, sizes, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 829 TSRMLS_CC);
			zephir_array_fetch(&_9, errors, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 829 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, _5, _6, _7, _8, _9, p);
			zephir_check_call_status();
			zephir_is_iterable(parentFiles, &_12, &_11, 0, 0, "phalcon/http/request.zep", 834);
			for (
			  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
			  ; zephir_hash_move_forward_ex(_12, &_11)
			) {
				ZEPHIR_GET_HVALUE(file, _13);
				zephir_array_append(&files, file, PH_SEPARATE, "phalcon/http/request.zep", 832);
			}
		}
	}
	RETURN_CCTOR(files);

}

/**
 * Returns the available headers in the request
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	HashTable *_1, *_7;
	HashPosition _0, _6;
	zval *headers, *key = NULL, *value = NULL, *parts = NULL, *pos = NULL, *part = NULL, *_SERVER, **_2, *_3 = NULL, _4 = zval_used_for_init, _5 = zval_used_for_init, **_8, *_9 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_is_iterable(_SERVER, &_1, &_0, 0, 0, "phalcon/http/request.zep", 864);
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
			zephir_fast_str_replace(_3, &_4, &_5, key TSRMLS_CC);
			ZEPHIR_CPY_WRT(key, _3);
			ZEPHIR_INIT_NVAR(parts);
			zephir_fast_explode_str(parts, SL("_"), key, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_NVAR(key);
			ZVAL_STRING(key, "", 1);
			zephir_is_iterable(parts, &_7, &_6, 1, 0, "phalcon/http/request.zep", 860);
			for (
			  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HMKEY(pos, _7, _6);
				ZEPHIR_GET_HVALUE(part, _8);
				ZEPHIR_INIT_NVAR(_3);
				zephir_fast_strtolower(_3, part);
				ZEPHIR_CALL_FUNCTION(&_9, "ucfirst", &_10, _3);
				zephir_check_call_status();
				zephir_array_update_zval(&parts, pos, &_9, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_INIT_NVAR(key);
			zephir_fast_join_str(key, SL("-"), parts TSRMLS_CC);
			zephir_array_update_zval(&headers, key, &value, PH_COPY | PH_SEPARATE);
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

	HashTable *_7, *_12;
	HashPosition _6, _11;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, *returnedParts, *part = NULL, *headerParts = NULL, *headerPart = NULL, *split = NULL, *_0 = NULL, _1 = zval_used_for_init, _2 = zval_used_for_init, _3 = zval_used_for_init, *_4 = NULL, **_8, *_9 = NULL, *_10 = NULL, **_13, *_14 = NULL, *_15, *_16 = NULL, *_17 = NULL, *_18;
	zval *serverIndex = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

	if (unlikely(Z_TYPE_P(serverIndex_param) != IS_STRING && Z_TYPE_P(serverIndex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(serverIndex_param) == IS_STRING)) {
		zephir_get_strval(serverIndex, serverIndex_param);
	} else {
		ZEPHIR_INIT_VAR(serverIndex);
		ZVAL_EMPTY_STRING(serverIndex);
	}
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
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
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, -1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_split", &_5, &_1, _0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_7, &_6, 0, 0, "phalcon/http/request.zep", 913);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HVALUE(part, _8);
		ZEPHIR_INIT_NVAR(headerParts);
		array_init(headerParts);
		ZEPHIR_INIT_NVAR(_9);
		zephir_fast_trim(_9, part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "/\\s*;\\s*/", 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, -1);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_CALL_FUNCTION(&_10, "preg_split", &_5, &_1, _9, &_2, &_3);
		zephir_check_call_status();
		zephir_is_iterable(_10, &_12, &_11, 0, 0, "phalcon/http/request.zep", 910);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(headerPart, _13);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "=", 0);
			ZEPHIR_INIT_NVAR(_14);
			zephir_fast_strpos(_14, headerPart, &_1, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_14)) {
				ZEPHIR_INIT_NVAR(split);
				zephir_fast_explode_str(split, SL("="), headerPart, 2  TSRMLS_CC);
				zephir_array_fetch_long(&_15, split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 899 TSRMLS_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(_15, "q")) {
					ZEPHIR_OBS_NVAR(_16);
					zephir_array_fetch_long(&_16, split, 1, PH_NOISY, "phalcon/http/request.zep", 900 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_17);
					ZVAL_DOUBLE(_17, zephir_get_doubleval(_16));
					zephir_array_update_string(&headerParts, SL("quality"), &_17, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_18, split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 902 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_16);
					zephir_array_fetch_long(&_16, split, 0, PH_NOISY, "phalcon/http/request.zep", 902 TSRMLS_CC);
					zephir_array_update_zval(&headerParts, _16, &_18, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&headerParts, name, &headerPart, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_17);
				ZVAL_DOUBLE(_17, 1.0);
				zephir_array_update_string(&headerParts, SL("quality"), &_17, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_append(&returnedParts, headerParts, PH_SEPARATE, "phalcon/http/request.zep", 910);
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

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(selectedName);
	ZVAL_STRING(selectedName, "", 1);
	zephir_is_iterable(qualityParts, &_1, &_0, 0, 0, "phalcon/http/request.zep", 946);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(accept, _2);
		if (i == 0) {
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 935 TSRMLS_CC);
			quality = zephir_get_doubleval(_3);
			ZEPHIR_OBS_NVAR(selectedName);
			zephir_array_fetch(&selectedName, accept, name, PH_NOISY, "phalcon/http/request.zep", 936 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch_string(&_3, accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 938 TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(_3);
			if (acceptQuality > quality) {
				quality = acceptQuality;
				ZEPHIR_OBS_NVAR(selectedName);
				zephir_array_fetch(&selectedName, accept, name, PH_NOISY, "phalcon/http/request.zep", 941 TSRMLS_CC);
			}
		}
		i++;
	}
	RETURN_CCTOR(selectedName);

}

/**
 * Gets content type which request has been made
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getContentType) {

	zval *contentType = NULL, *_SERVER;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(contentType);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&contentType, _SERVER, SS("CONTENT_TYPE"), 0 TSRMLS_CC)) {
		RETURN_CCTOR(contentType);
	} else {
		ZEPHIR_OBS_NVAR(contentType);
		if (zephir_array_isset_string_fetch(&contentType, _SERVER, SS("HTTP_CONTENT_TYPE"), 0 TSRMLS_CC)) {
			RETURN_CCTOR(contentType);
		}
	}
	RETURN_MM_NULL();

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
	ZVAL_STRING(_0, "HTTP_ACCEPT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", ZEPHIR_TEMP_PARAM_COPY);
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
	ZVAL_STRING(_0, "HTTP_ACCEPT_CHARSET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", ZEPHIR_TEMP_PARAM_COPY);
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

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", ZEPHIR_TEMP_PARAM_COPY);
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
	ZVAL_STRING(_0, "HTTP_ACCEPT_LANGUAGE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", ZEPHIR_TEMP_PARAM_COPY);
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

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", ZEPHIR_TEMP_PARAM_COPY);
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
		zephir_array_fetch_string(&_1, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1044 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1045 TSRMLS_CC);
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
	if (zephir_array_isset_string_fetch(&digest, _SERVER, SS("PHP_AUTH_DIGEST"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(matches);
		array_init(matches);
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#", ZEPHIR_TEMP_PARAM_COPY);
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
			zephir_is_iterable(matches, &_5, &_4, 0, 0, "phalcon/http/request.zep", 1072);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HVALUE(match, _6);
				zephir_array_fetch_long(&_7, match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1070 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_8);
				zephir_array_fetch_long(&_8, match, 1, PH_NOISY, "phalcon/http/request.zep", 1070 TSRMLS_CC);
				zephir_array_update_zval(&auth, _8, &_7, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CTOR(auth);

}


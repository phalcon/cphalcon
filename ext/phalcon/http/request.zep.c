
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * Phalcon\Http\Request
 *
 * Encapsulates request information for easy and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
 *
 *<code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request();
 *
 * if ($request->isPost() && $request->isAjax()) {
 *     echo "Request was made using POST and AJAX";
 * }
 *
 * $request->getServer("HTTP_HOST"); // Retrieve SERVER variables
 * $request->getMethod();            // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getLanguages();         // An array of languages the client accepts
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Request, phalcon, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_ce, SL("_putCache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_http_request_ce, SL("_httpMethodParameterOverride"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_http_request_ce, SL("_strictHostCheck"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Http_Request, getHttpMethodParameterOverride) {

	

	RETURN_MEMBER(getThis(), "_httpMethodParameterOverride");

}

PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride) {

	zval *httpMethodParameterOverride;

	zephir_fetch_params(0, 1, 0, &httpMethodParameterOverride);



	zephir_update_property_this(getThis(), SL("_httpMethodParameterOverride"), httpMethodParameterOverride TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if needed.
 * If no parameters are given the $_REQUEST superglobal is returned
 *
 *<code>
 * // Returns value from $_REQUEST["user_email"] without sanitizing
 * $userEmail = $request->get("user_email");
 *
 * // Returns value from $_REQUEST["user_email"] with sanitizing
 * $userEmail = $request->get("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_REQUEST, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (notAllowEmpty) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_INIT_VAR(_1);
	if (noRecursive) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 239, _REQUEST, name, filters, defaultValue, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 * If no parameters are given the $_POST superglobal is returned
 *
 *<code>
 * // Returns value from $_POST["user_email"] without sanitizing
 * $userEmail = $request->getPost("user_email");
 *
 * // Returns value from $_POST["user_email"] with sanitizing
 * $userEmail = $request->getPost("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_POST, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (notAllowEmpty) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_INIT_VAR(_1);
	if (noRecursive) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 239, _POST, name, filters, defaultValue, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a variable from put request
 *
 *<code>
 * // Returns value from $_PUT["user_email"] without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from $_PUT["user_email"] with sanitizing
 * $userEmail = $request->getPut("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _0$$3;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *put = NULL, *contentType = NULL, *_5, *_6, _1$$3, *_2$$3 = NULL, *_3$$4, *_4$$6 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_OBS_VAR(put);
	zephir_read_property_this(&put, this_ptr, SL("_putCache"), PH_NOISY_CC);
	if (Z_TYPE_P(put) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		_0$$3 = Z_TYPE_P(contentType) == IS_STRING;
		if (_0$$3) {
			ZEPHIR_SINIT_VAR(_1$$3);
			ZVAL_STRING(&_1$$3, "json", 0);
			ZEPHIR_CALL_FUNCTION(&_2$$3, "stripos", NULL, 240, contentType, &_1$$3);
			zephir_check_call_status();
			_0$$3 = !ZEPHIR_IS_FALSE(_2$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZVAL_BOOL(_3$$4, 1);
			ZEPHIR_CALL_METHOD(&put, this_ptr, "getjsonrawbody", NULL, 0, _3$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(put) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(put);
				array_init(put);
			}
		} else {
			ZEPHIR_INIT_NVAR(put);
			array_init(put);
			ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getrawbody", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_MAKE_REF(put);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 241, _4$$6, put);
			ZEPHIR_UNREF(put);
			zephir_check_call_status();
		}
		zephir_update_property_this(getThis(), SL("_putCache"), put TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_5);
	if (notAllowEmpty) {
		ZVAL_BOOL(_5, 1);
	} else {
		ZVAL_BOOL(_5, 0);
	}
	ZEPHIR_INIT_VAR(_6);
	if (noRecursive) {
		ZVAL_BOOL(_6, 1);
	} else {
		ZVAL_BOOL(_6, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 239, put, name, filters, defaultValue, _5, _6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 * If no parameters are given the $_GET superglobal is returned
 *
 *<code>
 * // Returns value from $_GET["id"] without sanitizing
 * $id = $request->getQuery("id");
 *
 * // Returns value from $_GET["id"] with sanitizing
 * $id = $request->getQuery("id", "int");
 *
 * // Returns value from $_GET["id"] with a default value
 * $id = $request->getQuery("id", null, 150);
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_GET, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (notAllowEmpty) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_INIT_VAR(_1);
	if (noRecursive) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 239, _GET, name, filters, defaultValue, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Helper to get data from superglobals, applying filters if needed.
 * If no parameters are given the superglobal is returned.
 */
PHP_METHOD(Phalcon_Http_Request, getHelper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _5;
	zval *name = NULL;
	zval *source_param = NULL, *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *value = NULL, *filter = NULL, *dependencyInjector = NULL, *_0$$6, *_1$$6 = NULL, *_2$$6, *_3$$5 = NULL, *_4$$5;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &source_param, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	zephir_get_arrval(source, source_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		RETURN_CTOR(source);
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_fetch(&value, source, name, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) != IS_NULL) {
		ZEPHIR_OBS_VAR(filter);
		zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
		if (Z_TYPE_P(filter) != IS_OBJECT) {
			_0$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(dependencyInjector, _0$$6);
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 192);
				return;
			}
			ZEPHIR_INIT_VAR(_2$$6);
			ZVAL_STRING(_2$$6, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_1$$6, dependencyInjector, "getshared", NULL, 0, _2$$6);
			zephir_check_temp_parameter(_2$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(filter, _1$$6);
			zephir_update_property_this(getThis(), SL("_filter"), filter TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_4$$5);
		if (noRecursive) {
			ZVAL_BOOL(_4$$5, 1);
		} else {
			ZVAL_BOOL(_4$$5, 0);
		}
		ZEPHIR_CALL_METHOD(&_3$$5, filter, "sanitize", NULL, 0, value, filters, _4$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _3$$5);
	}
	_5 = ZEPHIR_IS_EMPTY(value);
	if (_5) {
		_5 = notAllowEmpty == 1;
	}
	if (_5) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(value);

}

/**
 * Gets variable from $_SERVER superglobal
 */
PHP_METHOD(Phalcon_Http_Request, getServer) {

	zval *name_param = NULL, *_SERVER, *serverValue = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	if (zephir_array_isset_fetch(&serverValue, _SERVER, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(serverValue);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether $_REQUEST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, has) {

	zval *name_param = NULL, *_REQUEST;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	RETURN_MM_BOOL(zephir_array_isset(_REQUEST, name));

}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zval *name_param = NULL, *_POST;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	RETURN_MM_BOOL(zephir_array_isset(_POST, name));

}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *put = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&put, this_ptr, "getput", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(put, name));

}

/**
 * Checks whether $_GET superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery) {

	zval *name_param = NULL, *_GET;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	RETURN_MM_BOOL(zephir_array_isset(_GET, name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name_param = NULL, *_SERVER;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	RETURN_MM_BOOL(zephir_array_isset(_SERVER, name));

}

/**
 * Checks whether headers has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *_SERVER, *name = NULL, _0, _1, *_2 = NULL, *_3;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &header_param);

	if (UNEXPECTED(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(header, header_param);
	} else {
		ZEPHIR_INIT_VAR(header);
		ZVAL_EMPTY_STRING(header);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "-", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "_", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 27, header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(name);
	zephir_fast_strtoupper(name, _2);
	if (zephir_array_isset(_SERVER, name)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "HTTP_", name);
	if (zephir_array_isset(_SERVER, _3)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *_SERVER, *value = NULL, *name = NULL, _0, _1, *_2 = NULL, *_3;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &header_param);

	if (UNEXPECTED(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(header, header_param);
	} else {
		ZEPHIR_INIT_VAR(header);
		ZVAL_EMPTY_STRING(header);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "-", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "_", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 27, header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(name);
	zephir_fast_strtoupper(name, _2);
	ZEPHIR_OBS_VAR(value);
	if (zephir_array_isset_fetch(&value, _SERVER, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_OBS_NVAR(value);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "HTTP_", name);
	if (zephir_array_isset_fetch(&value, _SERVER, _3, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Gets HTTP schema (http/https)
 */
PHP_METHOD(Phalcon_Http_Request, getScheme) {

	zval *https = NULL, *scheme = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTPS", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&https, this_ptr, "getserver", NULL, 0, _0);
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
 * Checks whether request has been made using ajax
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zend_bool _0;
	zval *_SERVER, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTP_X_REQUESTED_WITH"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 330 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_1, "XMLHttpRequest");
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(Phalcon_Http_Request, isSoap) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string(_SERVER, SS("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 345));
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Alias of isSoap(). It will be deprecated in future versions
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "issoap", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether request has been made using any secure layer
 */
PHP_METHOD(Phalcon_Http_Request, isSecure) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "https"));

}

/**
 * Alias of isSecure(). It will be deprecated in future versions
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "issecure", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody) {

	zval *rawBody = NULL, *contents = NULL, _0$$3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(rawBody);
	zephir_read_property_this(&rawBody, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(rawBody)) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "php://input", 0);
		ZEPHIR_INIT_VAR(contents);
		zephir_file_get_contents(contents, &_0$$3 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_rawBody"), contents TSRMLS_CC);
		RETURN_CCTOR(contents);
	}
	RETURN_CCTOR(rawBody);

}

/**
 * Gets decoded JSON HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, *rawBody = NULL, *data = NULL, _0, *_1 = NULL;
	zend_bool associative;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(rawBody)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	ZEPHIR_INIT_VAR(data);
	zephir_json_decode(data, &(data), rawBody, zephir_get_intval(&_0)  TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "json_last_error", NULL, 242);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(data);

}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *serverAddr = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(serverAddr);
	if (zephir_array_isset_string_fetch(&serverAddr, _SERVER, SS("SERVER_ADDR"), 0 TSRMLS_CC)) {
		RETURN_CCTOR(serverAddr);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "localhost", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 243, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets active server name
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval *_SERVER, *serverName = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string_fetch(&serverName, _SERVER, SS("SERVER_NAME"), 1 TSRMLS_CC)) {
		RETURN_CTOR(serverName);
	}
	RETURN_MM_STRING("localhost", 1);

}

/**
 * Gets host name used by the request.
 *
 * `Request::getHttpHost` trying to find host name in following order:
 *
 * - `$_SERVER["HTTP_HOST"]`
 * - `$_SERVER["SERVER_NAME"]`
 * - `$_SERVER["SERVER_ADDR"]`
 *
 * Optionally `Request::getHttpHost` validates and clean host name.
 * The `Request::$_strictHostCheck` can be used to validate host name.
 *
 * Note: validation and cleaning have a negative performance impact because
 * they use regular expressions.
 *
 * <code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request;
 *
 * $_SERVER["HTTP_HOST"] = "example.com";
 * $request->getHttpHost(); // example.com
 *
 * $_SERVER["HTTP_HOST"] = "example.com:8080";
 * $request->getHttpHost(); // example.com:8080
 *
 * $request->setStrictHostCheck(true);
 * $_SERVER["HTTP_HOST"] = "ex=am~ple.com";
 * $request->getHttpHost(); // UnexpectedValueException
 *
 * $_SERVER["HTTP_HOST"] = "ExAmPlE.com";
 * $request->getHttpHost(); // example.com
 * </code>
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zval *_14 = NULL;
	zend_bool _3;
	zval *host = NULL, *strict = NULL, *_0, *_1$$3, *_2$$4, *_4$$5, *_8$$5, *_9$$5, *_10$$5 = NULL, _11$$5, *_5$$6, *_6$$6, *_7$$6 = NULL, *_12$$7, *_13$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(strict);
	zephir_read_property_this(&strict, this_ptr, SL("_strictHostCheck"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (!(zephir_is_true(host))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "SERVER_NAME", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(host))) {
			ZEPHIR_INIT_VAR(_2$$4);
			ZVAL_STRING(_2$$4, "SERVER_ADDR", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, _2$$4);
			zephir_check_temp_parameter(_2$$4);
			zephir_check_call_status();
		}
	}
	_3 = zephir_is_true(host);
	if (_3) {
		_3 = zephir_is_true(strict);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_4$$5);
		zephir_fast_trim(_4$$5, host, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_NVAR(host);
		zephir_fast_strtolower(host, _4$$5);
		if (zephir_memnstr_str(host, SL(":"), "phalcon/http/request.zep", 507)) {
			ZEPHIR_INIT_VAR(_5$$6);
			ZVAL_STRING(_5$$6, "/:[[:digit:]]+$/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_6$$6);
			ZVAL_STRING(_6$$6, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_7$$6, "preg_replace", NULL, 42, _5$$6, _6$$6, host);
			zephir_check_temp_parameter(_5$$6);
			zephir_check_temp_parameter(_6$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(host, _7$$6);
		}
		ZEPHIR_INIT_VAR(_8$$5);
		ZVAL_STRING(_8$$5, "/[a-z0-9-]+\\.?/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_9$$5);
		ZVAL_STRING(_9$$5, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_10$$5, "preg_replace", NULL, 42, _8$$5, _9$$5, host);
		zephir_check_temp_parameter(_8$$5);
		zephir_check_temp_parameter(_9$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_11$$5);
		ZVAL_STRING(&_11$$5, "", 0);
		if (!ZEPHIR_IS_IDENTICAL(&_11$$5, _10$$5)) {
			ZEPHIR_INIT_VAR(_12$$7);
			object_init_ex(_12$$7, spl_ce_UnexpectedValueException);
			ZEPHIR_INIT_VAR(_13$$7);
			ZEPHIR_CONCAT_SV(_13$$7, "Invalid host ", host);
			ZEPHIR_CALL_METHOD(NULL, _12$$7, "__construct", NULL, 244, _13$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_12$$7, "phalcon/http/request.zep", 516 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_get_strval(_14, host);
	RETURN_CTOR(_14);

}

/**
 * Sets if the `Request::getHttpHost` method must be use strict validation of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, setStrictHostCheck) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 0, 1, &flag_param);

	if (!flag_param) {
		flag = 1;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	if (flag) {
		zephir_update_property_this(getThis(), SL("_strictHostCheck"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_strictHostCheck"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Checks if the `Request::getHttpHost` method will be use strict validation of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, isStrictHostCheck) {

	

	RETURN_MEMBER(getThis(), "_strictHostCheck");

}

/**
 * Gets information about the port on which the request is made.
 */
PHP_METHOD(Phalcon_Http_Request, getPort) {

	zval *host = NULL, *pos = NULL, *_0 = NULL, *_7 = NULL, _1$$4, _2$$5, *_3$$5, *_4$$3, *_5$$3 = NULL, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(host)) {
		if (zephir_memnstr_str(host, SL(":"), "phalcon/http/request.zep", 553)) {
			ZEPHIR_SINIT_VAR(_1$$4);
			ZVAL_STRING(&_1$$4, ":", 0);
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 155, host, &_1$$4);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
				ZEPHIR_SINIT_VAR(_2$$5);
				ZVAL_LONG(&_2$$5, (zephir_get_numberval(pos) + 1));
				ZEPHIR_INIT_VAR(_3$$5);
				zephir_substr(_3$$5, host, zephir_get_intval(&_2$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				RETURN_MM_LONG(zephir_get_intval(_3$$5));
			}
		}
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getscheme", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "https", 0);
		if (ZEPHIR_IS_IDENTICAL(&_6$$3, _5$$3)) {
			ZVAL_LONG(_4$$3, 443);
		} else {
			ZVAL_LONG(_4$$3, 80);
		}
		RETURN_CCTOR(_4$$3);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "SERVER_PORT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getserver", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_7));

}

/**
 * Gets HTTP URI which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getURI) {

	zval *_SERVER, *requestURI = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string_fetch(&requestURI, _SERVER, SS("REQUEST_URI"), 1 TSRMLS_CC)) {
		RETURN_CTOR(requestURI);
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Gets most possible client IPv4 Address. This method searches in
 * $_SERVER["REMOTE_ADDR"] and optionally in $_SERVER["HTTP_X_FORWARDED_FOR"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zval *trustForwardedHeader_param = NULL, *_SERVER, *address = NULL, *_0$$7, *_1$$7;
	zend_bool trustForwardedHeader;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
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
		zephir_array_isset_string_fetch(&address, _SERVER, SS("HTTP_X_FORWARDED_FOR"), 0 TSRMLS_CC);
		if (Z_TYPE_P(address) == IS_NULL) {
			ZEPHIR_OBS_NVAR(address);
			zephir_array_isset_string_fetch(&address, _SERVER, SS("HTTP_CLIENT_IP"), 0 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(address);
		zephir_array_isset_string_fetch(&address, _SERVER, SS("REMOTE_ADDR"), 0 TSRMLS_CC);
	}
	if (Z_TYPE_P(address) == IS_STRING) {
		if (zephir_memnstr_str(address, SL(","), "phalcon/http/request.zep", 604)) {
			ZEPHIR_INIT_VAR(_0$$7);
			zephir_fast_explode_str(_0$$7, SL(","), address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_1$$7, _0$$7, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 608 TSRMLS_CC);
			RETURN_CTOR(_1$$7);
		}
		RETURN_CCTOR(address);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets HTTP method which request has been made
 *
 * If the X-HTTP-Method-Override header is set, and if the method is a POST,
 * then it is used to determine the "real" intended HTTP method.
 *
 * The _method request parameter can also be used to determine the HTTP method,
 * but only if setHttpMethodParameterOverride(true) has been called.
 *
 * The method is always an uppercased string.
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {

	zval *returnMethod = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *_REQUEST, *overridedMethod = NULL, *spoofedMethod = NULL, *requestMethod = NULL, _0, *_3 = NULL, *_1$$5, *_2$$5;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(returnMethod);
	ZVAL_EMPTY_STRING(returnMethod);
	ZEPHIR_OBS_VAR(requestMethod);
	if (EXPECTED(zephir_array_isset_string_fetch(&requestMethod, _SERVER, SS("REQUEST_METHOD"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(returnMethod);
		zephir_fast_strtoupper(returnMethod, requestMethod);
	} else {
		RETURN_MM_STRING("GET", 1);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "POST", 0);
	if (ZEPHIR_IS_IDENTICAL(&_0, returnMethod)) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_STRING(_1$$5, "X-HTTP-METHOD-OVERRIDE", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&overridedMethod, this_ptr, "getheader", NULL, 245, _1$$5);
		zephir_check_temp_parameter(_1$$5);
		zephir_check_call_status();
		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_httpMethodParameterOverride"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(overridedMethod))) {
			ZEPHIR_INIT_NVAR(returnMethod);
			zephir_fast_strtoupper(returnMethod, overridedMethod);
		} else if (zephir_is_true(_2$$5)) {
			ZEPHIR_OBS_VAR(spoofedMethod);
			if (zephir_array_isset_string_fetch(&spoofedMethod, _REQUEST, SS("_method"), 0 TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(returnMethod);
				zephir_fast_strtoupper(returnMethod, spoofedMethod);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isvalidhttpmethod", NULL, 0, returnMethod);
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		RETURN_MM_STRING("GET", 1);
	}
	RETURN_CTOR(returnMethod);

}

/**
 * Gets HTTP user agent used to made the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {

	zval *_SERVER, *userAgent = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string_fetch(&userAgent, _SERVER, SS("HTTP_USER_AGENT"), 1 TSRMLS_CC)) {
		RETURN_CTOR(userAgent);
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Checks if a method is a valid HTTP method
 */
PHP_METHOD(Phalcon_Http_Request, isValidHttpMethod) {

	zval *method_param = NULL, *_0;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(method, method_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtoupper(_0, method);
	do {
		if (ZEPHIR_IS_STRING(_0, "GET") || ZEPHIR_IS_STRING(_0, "POST") || ZEPHIR_IS_STRING(_0, "PUT") || ZEPHIR_IS_STRING(_0, "DELETE") || ZEPHIR_IS_STRING(_0, "HEAD") || ZEPHIR_IS_STRING(_0, "OPTIONS") || ZEPHIR_IS_STRING(_0, "PATCH") || ZEPHIR_IS_STRING(_0, "PURGE") || ZEPHIR_IS_STRING(_0, "TRACE") || ZEPHIR_IS_STRING(_0, "CONNECT")) {
			RETURN_MM_BOOL(1);
		}
	} while(0);

	RETURN_MM_BOOL(0);

}

/**
 * Check if HTTP method match any of the passed methods
 * When strict is true it checks if validated methods are real HTTP methods
 */
PHP_METHOD(Phalcon_Http_Request, isMethod) {

	HashTable *_5$$5;
	HashPosition _4$$5;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3;
	zval *methods, *strict_param = NULL, *httpMethod = NULL, *method = NULL, *_1$$3 = NULL, *_2$$4, *_3$$4, **_6$$5, *_7$$6 = NULL, *_8$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isvalidhttpmethod", NULL, 0, methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(_2$$4);
			object_init_ex(_2$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_CONCAT_SV(_3$$4, "Invalid HTTP method: ", methods);
			ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 9, _3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2$$4, "phalcon/http/request.zep", 703 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, &_5$$5, &_4$$5, 0, 0, "phalcon/http/request.zep", 715);
		for (
		  ; zend_hash_get_current_data_ex(_5$$5, (void**) &_6$$5, &_4$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$5, &_4$$5)
		) {
			ZEPHIR_GET_HVALUE(method, _6$$5);
			ZEPHIR_INIT_NVAR(_8$$6);
			if (strict) {
				ZVAL_BOOL(_8$$6, 1);
			} else {
				ZVAL_BOOL(_8$$6, 0);
			}
			ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "ismethod", &_9, 247, method, _8$$6);
			zephir_check_call_status();
			if (zephir_is_true(_7$$6)) {
				RETURN_MM_BOOL(1);
			}
		}
		RETURN_MM_BOOL(0);
	}
	if (strict) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/http/request.zep", 719);
		return;
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "POST"));

}

/**
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "OPTIONS"));

}

/**
 * Checks whether HTTP method is PURGE (Squid and Varnish support). if _SERVER["REQUEST_METHOD"]==="PURGE"
 */
PHP_METHOD(Phalcon_Http_Request, isPurge) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PURGE"));

}

/**
 * Checks whether HTTP method is TRACE. if _SERVER["REQUEST_METHOD"]==="TRACE"
 */
PHP_METHOD(Phalcon_Http_Request, isTrace) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "TRACE"));

}

/**
 * Checks whether HTTP method is CONNECT. if _SERVER["REQUEST_METHOD"]==="CONNECT"
 */
PHP_METHOD(Phalcon_Http_Request, isConnect) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 246);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "CONNECT"));

}

/**
 * Checks whether request include attached files
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, *_FILES, *files = NULL, *file = NULL, *error = NULL, **_2, *_4$$8 = NULL, *_5$$8 = NULL;
	zend_bool onlySuccessful, _3$$6;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	numberFiles = 0;
	ZEPHIR_CPY_WRT(files, _FILES);
	if (Z_TYPE_P(files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(files, &_1, &_0, 0, 0, "phalcon/http/request.zep", 834);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(file, _2);
		ZEPHIR_OBS_NVAR(error);
		if (zephir_array_isset_string_fetch(&error, file, SS("error"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(error) != IS_ARRAY) {
				_3$$6 = !zephir_is_true(error);
				if (!(_3$$6)) {
					_3$$6 = !onlySuccessful;
				}
				if (_3$$6) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(error) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_5$$8);
				if (onlySuccessful) {
					ZVAL_BOOL(_5$$8, 1);
				} else {
					ZVAL_BOOL(_5$$8, 0);
				}
				ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "hasfilehelper", &_6, 248, error, _5$$8);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(_4$$8);
			}
		}
	}
	RETURN_MM_LONG(numberFiles);

}

/**
 * Recursively counts file in an array of files
 */
PHP_METHOD(Phalcon_Http_Request, hasFileHelper) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _3$$5;
	zval *data, *onlySuccessful_param = NULL, *value = NULL, **_2, *_4$$7 = NULL, *_5$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/http/request.zep", 861);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(value) != IS_ARRAY) {
			_3$$5 = !zephir_is_true(value);
			if (!(_3$$5)) {
				_3$$5 = !onlySuccessful;
			}
			if (_3$$5) {
				numberFiles++;
			}
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_5$$7);
			if (onlySuccessful) {
				ZVAL_BOOL(_5$$7, 1);
			} else {
				ZVAL_BOOL(_5$$7, 0);
			}
			ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "hasfilehelper", &_6, 248, value, _5$$7);
			zephir_check_call_status();
			numberFiles += zephir_get_numberval(_4$$7);
		}
	}
	RETURN_MM_LONG(numberFiles);

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	HashTable *_1$$3, *_11$$5;
	HashPosition _0$$3, _10$$5;
	zval *files;
	zephir_fcall_cache_entry *_9 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, *_FILES, *superFiles = NULL, *prefix = NULL, *input = NULL, *smoothInput = NULL, *file = NULL, *dataFile = NULL, **_2$$3, *_3$$4 = NULL, *_4$$5, *_5$$5, *_6$$5, *_7$$5, *_8$$5, **_12$$5, *_14$$6, *_15$$7 = NULL, *_16$$7 = NULL, *_17$$7, *_20$$8, *_21$$9 = NULL;
	zend_bool onlySuccessful, _13$$6, _19$$8;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	ZEPHIR_INIT_VAR(files);
	array_init(files);
	ZEPHIR_CPY_WRT(superFiles, _FILES);
	if (zephir_fast_count_int(superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(superFiles, &_1$$3, &_0$$3, 0, 0, "phalcon/http/request.zep", 906);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(prefix, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(input, _2$$3);
			ZEPHIR_OBS_NVAR(_3$$4);
			zephir_array_fetch_string(&_3$$4, input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 877 TSRMLS_CC);
			if (Z_TYPE_P(_3$$4) == IS_ARRAY) {
				zephir_array_fetch_string(&_4$$5, input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 879 TSRMLS_CC);
				zephir_array_fetch_string(&_5$$5, input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 880 TSRMLS_CC);
				zephir_array_fetch_string(&_6$$5, input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 881 TSRMLS_CC);
				zephir_array_fetch_string(&_7$$5, input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 882 TSRMLS_CC);
				zephir_array_fetch_string(&_8$$5, input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 883 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_9, 249, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, prefix);
				zephir_check_call_status();
				zephir_is_iterable(smoothInput, &_11$$5, &_10$$5, 0, 0, "phalcon/http/request.zep", 900);
				for (
				  ; zend_hash_get_current_data_ex(_11$$5, (void**) &_12$$5, &_10$$5) == SUCCESS
				  ; zend_hash_move_forward_ex(_11$$5, &_10$$5)
				) {
					ZEPHIR_GET_HVALUE(file, _12$$5);
					_13$$6 = onlySuccessful == 0;
					if (!(_13$$6)) {
						zephir_array_fetch_string(&_14$$6, file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 888 TSRMLS_CC);
						_13$$6 = ZEPHIR_IS_LONG(_14$$6, 0);
					}
					if (_13$$6) {
						ZEPHIR_INIT_NVAR(dataFile);
						zephir_create_array(dataFile, 5, 0 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 890 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("name"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 891 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 892 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("tmp_name"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 893 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("size"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 895 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("error"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(_16$$7);
						object_init_ex(_16$$7, phalcon_http_request_file_ce);
						zephir_array_fetch_string(&_17$$7, file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 897 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, _16$$7, "__construct", &_18, 250, dataFile, _17$$7);
						zephir_check_call_status();
						zephir_array_append(&files, _16$$7, PH_SEPARATE, "phalcon/http/request.zep", 897);
					}
				}
			} else {
				_19$$8 = onlySuccessful == 0;
				if (!(_19$$8)) {
					zephir_array_fetch_string(&_20$$8, input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 901 TSRMLS_CC);
					_19$$8 = ZEPHIR_IS_LONG(_20$$8, 0);
				}
				if (_19$$8) {
					ZEPHIR_INIT_NVAR(_21$$9);
					object_init_ex(_21$$9, phalcon_http_request_file_ce);
					ZEPHIR_CALL_METHOD(NULL, _21$$9, "__construct", &_18, 250, input, prefix);
					zephir_check_call_status();
					zephir_array_append(&files, _21$$9, PH_SEPARATE, "phalcon/http/request.zep", 902);
				}
			}
		}
	}
	RETURN_CTOR(files);

}

/**
 * Smooth out $_FILES to have plain array with all files uploaded
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles) {

	HashTable *_1, *_12$$5;
	HashPosition _0, _11$$5;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, *prefix_param = NULL, *idx = NULL, *name = NULL, *file = NULL, *files = NULL, *parentFiles = NULL, *p = NULL, **_2, *_4$$4 = NULL, *_5$$5, *_6$$5, *_7$$5, *_8$$5, *_9$$5, **_13$$5;
	zval *names = NULL, *types = NULL, *tmp_names = NULL, *sizes = NULL, *errors = NULL, *_3$$4 = NULL;

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
	zephir_is_iterable(names, &_1, &_0, 0, 0, "phalcon/http/request.zep", 951);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(idx, _1, _0);
		ZEPHIR_GET_HVALUE(name, _2);
		ZEPHIR_INIT_NVAR(p);
		ZEPHIR_CONCAT_VSV(p, prefix, ".", idx);
		if (Z_TYPE_P(name) == IS_STRING) {
			ZEPHIR_INIT_NVAR(_3$$4);
			zephir_create_array(_3$$4, 6, 0 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, types, idx, PH_NOISY, "phalcon/http/request.zep", 927 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, tmp_names, idx, PH_NOISY, "phalcon/http/request.zep", 928 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("tmp_name"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, sizes, idx, PH_NOISY, "phalcon/http/request.zep", 929 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("size"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, errors, idx, PH_NOISY, "phalcon/http/request.zep", 930 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("error"), &_4$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, _3$$4, PH_SEPARATE, "phalcon/http/request.zep", 932);
		}
		if (Z_TYPE_P(name) == IS_ARRAY) {
			zephir_array_fetch(&_5$$5, names, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 937 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, types, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 938 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, tmp_names, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 939 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, sizes, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 940 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, errors, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 941 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, 249, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, p);
			zephir_check_call_status();
			zephir_is_iterable(parentFiles, &_12$$5, &_11$$5, 0, 0, "phalcon/http/request.zep", 948);
			for (
			  ; zend_hash_get_current_data_ex(_12$$5, (void**) &_13$$5, &_11$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_12$$5, &_11$$5)
			) {
				ZEPHIR_GET_HVALUE(file, _13$$5);
				zephir_array_append(&files, file, PH_SEPARATE, "phalcon/http/request.zep", 946);
			}
		}
	}
	RETURN_CCTOR(files);

}

/**
 * Returns the available headers in the request
 *
 * <code>
 * $_SERVER = [
 *     "PHP_AUTH_USER" => "phalcon",
 *     "PHP_AUTH_PW"   => "secret",
 * ];
 *
 * $headers = $request->getHeaders();
 *
 * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
 * </code>
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	HashTable *_1;
	HashPosition _0;
	zval *headers = NULL, *contentHeaders;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zval *_SERVER, *name = NULL, *value = NULL, *authHeaders = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, _5$$4 = zval_used_for_init, *_6$$4 = NULL, _7$$4 = zval_used_for_init, _8$$4 = zval_used_for_init, *_10$$4 = NULL, _11$$4 = zval_used_for_init, _12$$4 = zval_used_for_init, *_13$$3 = NULL, *_14$$5 = NULL, *_15$$5 = NULL, _16$$5 = zval_used_for_init, _17$$5 = zval_used_for_init, *_18$$5 = NULL, _19$$5 = zval_used_for_init, _20$$5 = zval_used_for_init, *_21$$6;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	ZEPHIR_INIT_VAR(contentHeaders);
	zephir_create_array(contentHeaders, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_MD5"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_is_iterable(_SERVER, &_1, &_0, 0, 0, "phalcon/http/request.zep", 994);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_start_with_str(name, SL("HTTP_"))) {
			ZEPHIR_INIT_NVAR(_3$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZEPHIR_SINIT_NVAR(_5$$4);
			ZVAL_LONG(&_5$$4, 5);
			ZEPHIR_INIT_NVAR(_6$$4);
			zephir_substr(_6$$4, name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_SINIT_NVAR(_7$$4);
			ZVAL_STRING(&_7$$4, "_", 0);
			ZEPHIR_SINIT_NVAR(_8$$4);
			ZVAL_STRING(&_8$$4, " ", 0);
			zephir_fast_str_replace(&_4$$4, &_7$$4, &_8$$4, _6$$4 TSRMLS_CC);
			zephir_fast_strtolower(_3$$4, _4$$4);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 251, _3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10$$4);
			ZEPHIR_SINIT_NVAR(_11$$4);
			ZVAL_STRING(&_11$$4, " ", 0);
			ZEPHIR_SINIT_NVAR(_12$$4);
			ZVAL_STRING(&_12$$4, "-", 0);
			zephir_fast_str_replace(&_10$$4, &_11$$4, &_12$$4, name TSRMLS_CC);
			ZEPHIR_CPY_WRT(name, _10$$4);
			zephir_array_update_zval(&headers, name, &value, PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_INIT_NVAR(_13$$3);
		zephir_fast_strtoupper(_13$$3, name);
		ZEPHIR_CPY_WRT(name, _13$$3);
		if (zephir_array_isset(contentHeaders, name)) {
			ZEPHIR_INIT_NVAR(_14$$5);
			ZEPHIR_INIT_NVAR(_15$$5);
			ZEPHIR_SINIT_NVAR(_16$$5);
			ZVAL_STRING(&_16$$5, "_", 0);
			ZEPHIR_SINIT_NVAR(_17$$5);
			ZVAL_STRING(&_17$$5, " ", 0);
			zephir_fast_str_replace(&_15$$5, &_16$$5, &_17$$5, name TSRMLS_CC);
			zephir_fast_strtolower(_14$$5, _15$$5);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 251, _14$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_18$$5);
			ZEPHIR_SINIT_NVAR(_19$$5);
			ZVAL_STRING(&_19$$5, " ", 0);
			ZEPHIR_SINIT_NVAR(_20$$5);
			ZVAL_STRING(&_20$$5, "-", 0);
			zephir_fast_str_replace(&_18$$5, &_19$$5, &_20$$5, name TSRMLS_CC);
			ZEPHIR_CPY_WRT(name, _18$$5);
			zephir_array_update_zval(&headers, name, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&authHeaders, this_ptr, "resolveauthorizationheaders", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(authHeaders) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_21$$6);
		zephir_fast_array_merge(_21$$6, &(headers), &(authHeaders) TSRMLS_CC);
		ZEPHIR_CPY_WRT(headers, _21$$6);
	}
	RETURN_CTOR(headers);

}

/**
 * Resolve authorization headers.
 */
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders) {

	zval *headers = NULL, *_6$$5, *_28$$19;
	zend_bool hasEventsManager = 0, _5, _9, _27, _15$$11;
	zval *_SERVER, *resolved = NULL, *eventsManager = NULL, *dependencyInjector = NULL, *exploded = NULL, *digest = NULL, *authHeader = NULL, *_0 = NULL, *_1$$3 = NULL, *_2$$3, *_3$$4 = NULL, *_4$$4, *_7$$5, *_8$$6, *_10$$7, *_11$$7, _12$$11 = zval_used_for_init, *_13$$11 = NULL, *_14$$11 = NULL, *_16$$11 = NULL, _17$$12, *_18$$12, *_19$$12 = NULL, *_20$$13, *_21$$13, *_22$$17, *_23$$17, *_24$$17, *_25$$17 = NULL, *_26$$17, *_29$$19, *_30$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(authHeader);
	ZVAL_NULL(authHeader);
	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "eventsManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, dependencyInjector, "has", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		hasEventsManager = zephir_get_boolval(_1$$3);
		if (hasEventsManager) {
			ZEPHIR_INIT_VAR(_4$$4);
			ZVAL_STRING(_4$$4, "eventsManager", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3$$4, dependencyInjector, "getshared", NULL, 0, _4$$4);
			zephir_check_temp_parameter(_4$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(eventsManager, _3$$4);
		}
	}
	_5 = hasEventsManager;
	if (_5) {
		_5 = Z_TYPE_P(eventsManager) == IS_OBJECT;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(_6$$5);
		zephir_create_array(_6$$5, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_6$$5, SL("server"), &_SERVER, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_7$$5);
		ZVAL_STRING(_7$$5, "request:beforeAuthorizationResolve", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&resolved, eventsManager, "fire", NULL, 0, _7$$5, this_ptr, _6$$5);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_8$$6);
			zephir_fast_array_merge(_8$$6, &(headers), &(resolved) TSRMLS_CC);
			ZEPHIR_CPY_WRT(headers, _8$$6);
		}
	}
	_9 = zephir_array_isset_string(_SERVER, SS("PHP_AUTH_USER"));
	if (_9) {
		_9 = zephir_array_isset_string(_SERVER, SS("PHP_AUTH_PW"));
	}
	if (_9) {
		zephir_array_fetch_string(&_10$$7, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1035 TSRMLS_CC);
		zephir_array_update_string(&headers, SL("Php-Auth-User"), &_10$$7, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_11$$7, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1036 TSRMLS_CC);
		zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_11$$7, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_array_isset_string(_SERVER, SS("HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(authHeader);
			zephir_array_fetch_string(&authHeader, _SERVER, SL("HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/http/request.zep", 1039 TSRMLS_CC);
		} else if (zephir_array_isset_string(_SERVER, SS("REDIRECT_HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(authHeader);
			zephir_array_fetch_string(&authHeader, _SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/http/request.zep", 1041 TSRMLS_CC);
		}
		if (zephir_is_true(authHeader)) {
			ZEPHIR_SINIT_VAR(_12$$11);
			ZVAL_STRING(&_12$$11, "basic ", 0);
			ZEPHIR_CALL_FUNCTION(&_13$$11, "stripos", NULL, 240, authHeader, &_12$$11);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_12$$11);
			ZVAL_STRING(&_12$$11, "digest ", 0);
			ZEPHIR_CALL_FUNCTION(&_14$$11, "stripos", NULL, 240, authHeader, &_12$$11);
			zephir_check_call_status();
			_15$$11 = ZEPHIR_IS_LONG_IDENTICAL(_14$$11, 0);
			if (_15$$11) {
				ZEPHIR_OBS_VAR(digest);
				_15$$11 = !(zephir_array_isset_string_fetch(&digest, _SERVER, SS("PHP_AUTH_DIGEST"), 0 TSRMLS_CC));
			}
			ZEPHIR_SINIT_NVAR(_12$$11);
			ZVAL_STRING(&_12$$11, "bearer ", 0);
			ZEPHIR_CALL_FUNCTION(&_16$$11, "stripos", NULL, 240, authHeader, &_12$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(_13$$11, 0)) {
				ZEPHIR_SINIT_VAR(_17$$12);
				ZVAL_LONG(&_17$$12, 6);
				ZEPHIR_INIT_VAR(_18$$12);
				zephir_substr(_18$$12, authHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_19$$12, "base64_decode", NULL, 135, _18$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(exploded);
				zephir_fast_explode_str(exploded, SL(":"), _19$$12, 2  TSRMLS_CC);
				if (zephir_fast_count_int(exploded TSRMLS_CC) == 2) {
					zephir_array_fetch_long(&_20$$13, exploded, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1048 TSRMLS_CC);
					zephir_array_update_string(&headers, SL("Php-Auth-User"), &_20$$13, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_21$$13, exploded, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1049 TSRMLS_CC);
					zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_21$$13, PH_COPY | PH_SEPARATE);
				}
			} else if (_15$$11) {
				zephir_array_update_string(&headers, SL("Php-Auth-Digest"), &authHeader, PH_COPY | PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(_16$$11, 0)) {
				zephir_array_update_string(&headers, SL("Authorization"), &authHeader, PH_COPY | PH_SEPARATE);
			}
		}
	}
	if (!(zephir_array_isset_string(headers, SS("Authorization")))) {
		ZEPHIR_OBS_NVAR(digest);
		if (zephir_array_isset_string(headers, SS("Php-Auth-User"))) {
			zephir_array_fetch_string(&_22$$17, headers, SL("Php-Auth-User"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1061 TSRMLS_CC);
			zephir_array_fetch_string(&_23$$17, headers, SL("Php-Auth-Pw"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1061 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_24$$17);
			ZEPHIR_CONCAT_VSV(_24$$17, _22$$17, ":", _23$$17);
			ZEPHIR_CALL_FUNCTION(&_25$$17, "base64_encode", NULL, 134, _24$$17);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_26$$17);
			ZEPHIR_CONCAT_SV(_26$$17, "Basic ", _25$$17);
			zephir_array_update_string(&headers, SL("Authorization"), &_26$$17, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset_string_fetch(&digest, headers, SS("Php-Auth-Digest"), 0 TSRMLS_CC)) {
			zephir_array_update_string(&headers, SL("Authorization"), &digest, PH_COPY | PH_SEPARATE);
		}
	}
	_27 = hasEventsManager;
	if (_27) {
		_27 = Z_TYPE_P(eventsManager) == IS_OBJECT;
	}
	if (_27) {
		ZEPHIR_INIT_VAR(_28$$19);
		zephir_create_array(_28$$19, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_28$$19, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_28$$19, SL("server"), &_SERVER, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_29$$19);
		ZVAL_STRING(_29$$19, "request:afterAuthorizationResolve", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&resolved, eventsManager, "fire", NULL, 0, _29$$19, this_ptr, _28$$19);
		zephir_check_temp_parameter(_29$$19);
		zephir_check_call_status();
		if (Z_TYPE_P(resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_30$$20);
			zephir_fast_array_merge(_30$$20, &(headers), &(resolved) TSRMLS_CC);
			ZEPHIR_CPY_WRT(headers, _30$$20);
		}
	}
	RETURN_CTOR(headers);

}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer) {

	zval *_SERVER, *httpReferer = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string_fetch(&httpReferer, _SERVER, SS("HTTP_REFERER"), 1 TSRMLS_CC)) {
		RETURN_CTOR(httpReferer);
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Process a request header and return the one with best quality
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality) {

	HashTable *_1;
	HashPosition _0;
	double quality = 0, acceptQuality = 0;
	zend_long i = 0;
	zval *name = NULL;
	zval *qualityParts_param = NULL, *name_param = NULL, *selectedName = NULL, *accept = NULL, **_2, *_3$$4 = NULL, *_4$$5 = NULL;
	zval *qualityParts = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &qualityParts_param, &name_param);

	zephir_get_arrval(qualityParts, qualityParts_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(selectedName);
	ZVAL_STRING(selectedName, "", 1);
	zephir_is_iterable(qualityParts, &_1, &_0, 0, 0, "phalcon/http/request.zep", 1121);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(accept, _2);
		if (i == 0) {
			ZEPHIR_OBS_NVAR(_3$$4);
			zephir_array_fetch_string(&_3$$4, accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1110 TSRMLS_CC);
			quality = zephir_get_doubleval(_3$$4);
			ZEPHIR_OBS_NVAR(selectedName);
			zephir_array_fetch(&selectedName, accept, name, PH_NOISY, "phalcon/http/request.zep", 1111 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(_4$$5);
			zephir_array_fetch_string(&_4$$5, accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1113 TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(_4$$5);
			if (acceptQuality > quality) {
				quality = acceptQuality;
				ZEPHIR_OBS_NVAR(selectedName);
				zephir_array_fetch(&selectedName, accept, name, PH_NOISY, "phalcon/http/request.zep", 1116 TSRMLS_CC);
			}
		}
		i++;
	}
	RETURN_CCTOR(selectedName);

}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType) {

	zval *_SERVER, *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(contentType);
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
 * Gets an array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 252, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	zval *_0 = NULL, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 253, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_CHARSET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 252, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {

	zval *_0 = NULL, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 253, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_LANGUAGE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 252, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {

	zval *_0 = NULL, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 253, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_USER"]
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth) {

	zend_bool _0;
	zval *_SERVER, *auth = NULL, *_1$$3, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("PHP_AUTH_USER"));
	if (_0) {
		_0 = zephir_array_isset_string(_SERVER, SS("PHP_AUTH_PW"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(auth);
		array_init(auth);
		zephir_array_fetch_string(&_1$$3, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1202 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2$$3, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1203 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("password"), &_2$$3, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(auth);
	}
	RETURN_MM_NULL();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_DIGEST"]
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	HashTable *_4$$5;
	HashPosition _3$$5;
	zval *auth = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *digest = NULL, *matches = NULL, *match = NULL, *_0$$3, *_1$$3, *_2$$3 = NULL, **_5$$5, *_6$$6, *_7$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(auth);
	array_init(auth);
	ZEPHIR_OBS_VAR(digest);
	if (zephir_array_isset_string_fetch(&digest, _SERVER, SS("PHP_AUTH_DIGEST"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(matches);
		array_init(matches);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_LONG(_1$$3, 2);
		ZEPHIR_MAKE_REF(matches);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_match_all", NULL, 41, _0$$3, digest, matches, _1$$3);
		zephir_check_temp_parameter(_0$$3);
		ZEPHIR_UNREF(matches);
		zephir_check_call_status();
		if (!(zephir_is_true(_2$$3))) {
			RETURN_CTOR(auth);
		}
		if (Z_TYPE_P(matches) == IS_ARRAY) {
			zephir_is_iterable(matches, &_4$$5, &_3$$5, 0, 0, "phalcon/http/request.zep", 1228);
			for (
			  ; zend_hash_get_current_data_ex(_4$$5, (void**) &_5$$5, &_3$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_4$$5, &_3$$5)
			) {
				ZEPHIR_GET_HVALUE(match, _5$$5);
				zephir_array_fetch_long(&_6$$6, match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1226 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_7$$6);
				zephir_array_fetch_long(&_7$$6, match, 1, PH_NOISY, "phalcon/http/request.zep", 1226 TSRMLS_CC);
				zephir_array_update_zval(&auth, _7$$6, &_6$$6, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CTOR(auth);

}

/**
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader) {

	HashTable *_6, *_14$$3;
	HashPosition _5, _13$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, *returnedParts = NULL, *part = NULL, *headerParts = NULL, *headerPart = NULL, *split = NULL, *_0 = NULL, _1, _2, _3, *_4 = NULL, **_7, *_8$$3 = NULL, _9$$3 = zval_used_for_init, _10$$3 = zval_used_for_init, _11$$3 = zval_used_for_init, *_12$$3 = NULL, **_15$$3, _16$$4 = zval_used_for_init, *_17$$4 = NULL, *_18$$5, *_19$$6 = NULL, *_20$$6 = NULL, *_21$$7, *_22$$7 = NULL, *_23$$8 = NULL;
	zval *serverIndex = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

	if (UNEXPECTED(Z_TYPE_P(serverIndex_param) != IS_STRING && Z_TYPE_P(serverIndex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serverIndex_param) == IS_STRING)) {
		zephir_get_strval(serverIndex, serverIndex_param);
	} else {
		ZEPHIR_INIT_VAR(serverIndex);
		ZVAL_EMPTY_STRING(serverIndex);
	}
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(returnedParts);
	array_init(returnedParts);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getserver", NULL, 0, serverIndex);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/,\\s*/", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, -1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_split", NULL, 254, &_1, _0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "phalcon/http/request.zep", 1262);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(part, _7);
		ZEPHIR_INIT_NVAR(headerParts);
		array_init(headerParts);
		ZEPHIR_INIT_NVAR(_8$$3);
		zephir_fast_trim(_8$$3, part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_9$$3);
		ZVAL_STRING(&_9$$3, "/\\s*;\\s*/", 0);
		ZEPHIR_SINIT_NVAR(_10$$3);
		ZVAL_LONG(&_10$$3, -1);
		ZEPHIR_SINIT_NVAR(_11$$3);
		ZVAL_LONG(&_11$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "preg_split", NULL, 254, &_9$$3, _8$$3, &_10$$3, &_11$$3);
		zephir_check_call_status();
		zephir_is_iterable(_12$$3, &_14$$3, &_13$$3, 0, 0, "phalcon/http/request.zep", 1259);
		for (
		  ; zend_hash_get_current_data_ex(_14$$3, (void**) &_15$$3, &_13$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_14$$3, &_13$$3)
		) {
			ZEPHIR_GET_HVALUE(headerPart, _15$$3);
			ZEPHIR_SINIT_NVAR(_16$$4);
			ZVAL_STRING(&_16$$4, "=", 0);
			ZEPHIR_INIT_NVAR(_17$$4);
			zephir_fast_strpos(_17$$4, headerPart, &_16$$4, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_17$$4)) {
				ZEPHIR_INIT_NVAR(split);
				zephir_fast_explode_str(split, SL("="), headerPart, 2  TSRMLS_CC);
				zephir_array_fetch_long(&_18$$5, split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1248 TSRMLS_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(_18$$5, "q")) {
					ZEPHIR_OBS_NVAR(_19$$6);
					zephir_array_fetch_long(&_19$$6, split, 1, PH_NOISY, "phalcon/http/request.zep", 1249 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_20$$6);
					ZVAL_DOUBLE(_20$$6, zephir_get_doubleval(_19$$6));
					zephir_array_update_string(&headerParts, SL("quality"), &_20$$6, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_21$$7, split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1251 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_22$$7);
					zephir_array_fetch_long(&_22$$7, split, 0, PH_NOISY, "phalcon/http/request.zep", 1251 TSRMLS_CC);
					zephir_array_update_zval(&headerParts, _22$$7, &_21$$7, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&headerParts, name, &headerPart, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_23$$8);
				ZVAL_DOUBLE(_23$$8, 1.0);
				zephir_array_update_string(&headerParts, SL("quality"), &_23$$8, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_append(&returnedParts, headerParts, PH_SEPARATE, "phalcon/http/request.zep", 1259);
	}
	RETURN_CCTOR(returnedParts);

}



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
#include "kernel/hash.h"


/**
 * Phalcon\Http\Request
 *
 * Encapsulates request information for easy and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
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

	zend_declare_property_null(phalcon_http_request_ce, SL("_putCache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_http_request_ce, SL("_httpMethodParameterOverride"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Http_Request, getHttpMethodParameterOverride) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_httpMethodParameterOverride");

}

PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride) {

	zval *httpMethodParameterOverride, httpMethodParameterOverride_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&httpMethodParameterOverride_sub);

	zephir_fetch_params(0, 1, 0, &httpMethodParameterOverride);



	zephir_update_property_zval(this_ptr, SL("_httpMethodParameterOverride"), httpMethodParameterOverride);

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, getDI) {

	ZEPHIR_INIT_THIS();


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
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _REQUEST, __$null, _0, _1;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
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


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 226, &_REQUEST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

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
 */
PHP_METHOD(Phalcon_Http_Request, getPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _POST, __$null, _0, _1;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
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


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 226, &_POST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a variable from put request
 *
 *<code>
 *	//Returns value from $_PUT["user_email"] without sanitizing
 *	$userEmail = $request->getPut("user_email");
 *
 *	//Returns value from $_PUT["user_email"] with sanitizing
 *	$userEmail = $request->getPut("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, put, _1, _2, _0$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&put);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
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


	ZEPHIR_OBS_VAR(&put);
	zephir_read_property(&put, this_ptr, SL("_putCache"), PH_NOISY_CC);
	if (Z_TYPE_P(&put) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&put);
		array_init(&put);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getrawbody", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&put);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 227, &_0$$3, &put);
		ZEPHIR_UNREF(&put);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_putCache"), &put);
	}
	if (notAllowEmpty) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 226, &put, &name, filters, defaultValue, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

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
 */
PHP_METHOD(Phalcon_Http_Request, getQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _GET, __$null, _0, _1;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
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


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 226, &_GET, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Helper to get data from superglobals, applying filters if needed.
 * If no parameters are given the superglobal is returned.
 */
PHP_METHOD(Phalcon_Http_Request, getHelper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _5;
	zval name;
	zval *source_param = NULL, *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, value, filter, dependencyInjector, _0$$6, _1$$6, _2$$6, _3$$5, _4$$5;
	zval source;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &source_param, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	zephir_get_arrval(&source, source_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
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


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		RETURN_CTOR(source);
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_fetch(&value, &source, &name, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) != IS_NULL) {
		ZEPHIR_OBS_VAR(&filter);
		zephir_read_property(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
		if (Z_TYPE_P(&filter) != IS_OBJECT) {
			zephir_read_property(&_0$$6, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$6);
			if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 177);
				return;
			}
			ZEPHIR_INIT_VAR(&_2$$6);
			ZVAL_STRING(&_2$$6, "filter");
			ZEPHIR_CALL_METHOD(&_1$$6, &dependencyInjector, "getshared", NULL, 0, &_2$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filter, &_1$$6);
			zephir_update_property_zval(this_ptr, SL("_filter"), &filter);
		}
		if (noRecursive) {
			ZVAL_BOOL(&_4$$5, 1);
		} else {
			ZVAL_BOOL(&_4$$5, 0);
		}
		ZEPHIR_CALL_METHOD(&_3$$5, &filter, "sanitize", NULL, 0, &value, filters, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_3$$5);
	}
	_5 = ZEPHIR_IS_EMPTY(&value);
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

	zval *name_param = NULL, _SERVER, serverValue;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverValue);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	if (zephir_array_isset_fetch(&serverValue, &_SERVER, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(serverValue);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether $_REQUEST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, has) {

	zval *name_param = NULL, _REQUEST;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_REQUEST);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_REQUEST, &name));

}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zval *name_param = NULL, _POST;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_POST, &name));

}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, put;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&put);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&put, this_ptr, "getput", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&put, &name));

}

/**
 * Checks whether $_GET superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery) {

	zval *name_param = NULL, _GET;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_GET);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_GET, &name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zval *name_param = NULL, _SERVER;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_SERVER);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	RETURN_MM_BOOL(zephir_array_isset(&_SERVER, &name));

}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, _SERVER, value, name, _0, _1, _2, _3;
	zval header;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &header_param);

	if (unlikely(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(&header, header_param);
	} else {
		ZEPHIR_INIT_VAR(&header);
		ZVAL_EMPTY_STRING(&header);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 55, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, &_SERVER, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_OBS_NVAR(&value);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset_fetch(&value, &_SERVER, &_3, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	RETURN_MM_STRING("");

}

/**
 * Gets HTTP schema (http/https)
 */
PHP_METHOD(Phalcon_Http_Request, getScheme) {

	zval https, scheme, _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&https);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTPS");
	ZEPHIR_CALL_METHOD(&https, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&https)) {
		ZEPHIR_INIT_VAR(&scheme);
		if (ZEPHIR_IS_STRING(&https, "off")) {
			ZVAL_STRING(&scheme, "http");
		} else {
			ZVAL_STRING(&scheme, "https");
		}
	} else {
		ZEPHIR_INIT_NVAR(&scheme);
		ZVAL_STRING(&scheme, "http");
	}
	RETURN_CCTOR(scheme);

}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zend_bool _0;
	zval _SERVER, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(&_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_0) {
		zephir_array_fetch_string(&_1, &_SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 295 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "XMLHttpRequest");
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, contentType;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string(&_SERVER, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 310));
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether request has been made using any secure layer
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "https"));

}

/**
 * Gets HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody) {

	zval rawBody, contents, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&rawBody);
	zephir_read_property(&rawBody, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&rawBody)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "php://input");
		ZEPHIR_INIT_VAR(&contents);
		zephir_file_get_contents(&contents, &_0$$3 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_rawBody"), &contents);
		RETURN_CCTOR(contents);
	}
	RETURN_CCTOR(rawBody);

}

/**
 * Gets decoded JSON HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, rawBody, _0;
	zend_bool associative;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&rawBody) != IS_STRING) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	zephir_json_decode(return_value, &rawBody, zephir_get_intval(&_0) );
	RETURN_MM();

}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, serverAddr, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverAddr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&serverAddr);
	if (zephir_array_isset_string_fetch(&serverAddr, &_SERVER, SL("SERVER_ADDR"), 0)) {
		RETURN_CCTOR(serverAddr);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "localhost");
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 228, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets active server name
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval _SERVER, serverName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverName);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&serverName, &_SERVER, SL("SERVER_NAME"), 1)) {
		RETURN_CTOR(serverName);
	}
	RETURN_MM_STRING("localhost");

}

/**
 * Gets information about schema, host and port used by the request
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zend_bool _2, _3;
	zval httpHost, scheme, name, port, _0;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&httpHost);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&httpHost, this_ptr, "getserver", &_1, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&httpHost)) {
		RETURN_CCTOR(httpHost);
	}
	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_NAME");
	ZEPHIR_CALL_METHOD(&name, this_ptr, "getserver", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_PORT");
	ZEPHIR_CALL_METHOD(&port, this_ptr, "getserver", &_1, 0, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_STRING(&scheme, "http");
	if (_2) {
		_2 = ZEPHIR_IS_LONG(&port, 80);
	}
	if (_2) {
		RETURN_CCTOR(name);
	}
	_3 = ZEPHIR_IS_STRING(&scheme, "https");
	if (_3) {
		_3 = ZEPHIR_IS_LONG(&port, 443);
	}
	if (_3) {
		RETURN_CCTOR(name);
	}
	ZEPHIR_CONCAT_VSV(return_value, &name, ":", &port);
	RETURN_MM();

}

/**
 * Gets HTTP URI which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getURI) {

	zval _SERVER, requestURI;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&requestURI);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&requestURI, &_SERVER, SL("REQUEST_URI"), 1)) {
		RETURN_CTOR(requestURI);
	}
	RETURN_MM_STRING("");

}

/**
 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zval *trustForwardedHeader_param = NULL, _SERVER, address, _0$$7, _1$$7;
	zend_bool trustForwardedHeader;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_1$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);

	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		trustForwardedHeader = zephir_get_boolval(trustForwardedHeader_param);
	}


	ZEPHIR_INIT_VAR(&address);
	ZVAL_NULL(&address);
	if (trustForwardedHeader) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, &_SERVER, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (Z_TYPE_P(&address) == IS_NULL) {
			ZEPHIR_OBS_NVAR(&address);
			zephir_array_isset_string_fetch(&address, &_SERVER, SL("HTTP_CLIENT_IP"), 0);
		}
	}
	if (Z_TYPE_P(&address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, &_SERVER, SL("REMOTE_ADDR"), 0);
	}
	if (Z_TYPE_P(&address) == IS_STRING) {
		if (zephir_memnstr_str(&address, SL(","), "phalcon/http/request.zep", 470)) {
			ZEPHIR_INIT_VAR(&_0$$7);
			zephir_fast_explode_str(&_0$$7, SL(","), &address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_1$$7, &_0$$7, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 474 TSRMLS_CC);
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

	zval returnMethod;
	int ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, _REQUEST, headers, overridedMethod, spoofedMethod, requestMethod, _0, _2, _1$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&overridedMethod);
	ZVAL_UNDEF(&spoofedMethod);
	ZVAL_UNDEF(&requestMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&returnMethod);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&returnMethod);
	ZVAL_STRING(&returnMethod, "");
	ZEPHIR_OBS_VAR(&requestMethod);
	if (zephir_array_isset_string_fetch(&requestMethod, &_SERVER, SL("REQUEST_METHOD"), 0)) {
		zephir_get_strval(&returnMethod, &requestMethod);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "POST");
	if (ZEPHIR_IS_IDENTICAL(&_0, &requestMethod)) {
		ZEPHIR_CALL_METHOD(&headers, this_ptr, "getheaders", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&overridedMethod);
		zephir_read_property(&_1$$4, this_ptr, SL("_httpMethodParameterOverride"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&overridedMethod, &headers, SL("X-HTTP-METHOD-OVERRIDE"), 0)) {
			zephir_get_strval(&returnMethod, &overridedMethod);
		} else if (zephir_is_true(&_1$$4)) {
			ZEPHIR_OBS_VAR(&spoofedMethod);
			if (zephir_array_isset_string_fetch(&spoofedMethod, &_REQUEST, SL("_method"), 0)) {
				zephir_get_strval(&returnMethod, &spoofedMethod);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "isvalidhttpmethod", NULL, 0, &returnMethod);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_NVAR(&returnMethod);
		ZVAL_STRING(&returnMethod, "GET");
	}
	zephir_fast_strtoupper(return_value, &returnMethod);
	RETURN_MM();

}

/**
 * Gets HTTP user agent used to made the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {

	zval _SERVER, userAgent;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&userAgent);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&userAgent, &_SERVER, SL("HTTP_USER_AGENT"), 1)) {
		RETURN_CTOR(userAgent);
	}
	RETURN_MM_STRING("");

}

/**
 * Checks if a method is a valid HTTP method
 */
PHP_METHOD(Phalcon_Http_Request, isValidHttpMethod) {

	zval *method_param = NULL, _0;
	zval method;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &method);
	do {
		if (ZEPHIR_IS_STRING(&_0, "GET") || ZEPHIR_IS_STRING(&_0, "POST") || ZEPHIR_IS_STRING(&_0, "PUT") || ZEPHIR_IS_STRING(&_0, "DELETE") || ZEPHIR_IS_STRING(&_0, "HEAD") || ZEPHIR_IS_STRING(&_0, "OPTIONS") || ZEPHIR_IS_STRING(&_0, "PATCH")) {
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

	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3;
	zval *methods, methods_sub, *strict_param = NULL, httpMethod, method, _1$$3, _2$$4, _3$$4, *_4$$5, _5$$6, _6$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isvalidhttpmethod", NULL, 0, methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(&_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "Invalid HTTP method: ", methods);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 9, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/http/request.zep", 565 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, &httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, 0, "phalcon/http/request.zep", 577);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(methods), _4$$5)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _4$$5);
			if (strict) {
				ZVAL_BOOL(&_6$$6, 1);
			} else {
				ZVAL_BOOL(&_6$$6, 0);
			}
			ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "ismethod", &_7, 230, &method, &_6$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$6)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&method);
		RETURN_MM_BOOL(0);
	}
	if (strict) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/http/request.zep", 581);
		return;
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "POST"));

}

/**
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 229);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "OPTIONS"));

}

/**
 * Checks whether request include attached files
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, _FILES, files, file, error, *_0, _2$$8, _3$$8;
	zend_bool onlySuccessful, _1$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	numberFiles = 0;
	ZEPHIR_CPY_WRT(&files, &_FILES);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalcon/http/request.zep", 672);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
	{
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _0);
		ZEPHIR_OBS_NVAR(&error);
		if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
			if (Z_TYPE_P(&error) != IS_ARRAY) {
				_1$$6 = !zephir_is_true(&error);
				if (!(_1$$6)) {
					_1$$6 = !onlySuccessful;
				}
				if (_1$$6) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(&error) == IS_ARRAY) {
				if (onlySuccessful) {
					ZVAL_BOOL(&_3$$8, 1);
				} else {
					ZVAL_BOOL(&_3$$8, 0);
				}
				ZEPHIR_CALL_METHOD(&_2$$8, this_ptr, "hasfilehelper", &_4, 231, &error, &_3$$8);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_2$$8);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Recursively counts file in an array of files
 */
PHP_METHOD(Phalcon_Http_Request, hasFileHelper) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _1$$5;
	zval *data, data_sub, *onlySuccessful_param = NULL, value, *_0, _2$$7, _3$$7;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, 0, "phalcon/http/request.zep", 699);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(data), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&value) != IS_ARRAY) {
			_1$$5 = !zephir_is_true(&value);
			if (!(_1$$5)) {
				_1$$5 = !onlySuccessful;
			}
			if (_1$$5) {
				numberFiles++;
			}
		}
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			if (onlySuccessful) {
				ZVAL_BOOL(&_3$$7, 1);
			} else {
				ZVAL_BOOL(&_3$$7, 0);
			}
			ZEPHIR_CALL_METHOD(&_2$$7, this_ptr, "hasfilehelper", &_4, 231, &value, &_3$$7);
			zephir_check_call_status();
			numberFiles += zephir_get_numberval(&_2$$7);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval files;
	zephir_fcall_cache_entry *_9 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, _FILES, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _3$$4, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, *_10$$5, _12$$6, _13$$7, _14$$7, _15$$7, _18$$8, _19$$9;
	zend_bool onlySuccessful, _11$$6, _17$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&files);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CPY_WRT(&superFiles, &_FILES);
	if (zephir_fast_count_int(&superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalcon/http/request.zep", 737);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&superFiles), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&prefix, _2$$3);
			} else {
				ZVAL_LONG(&prefix, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&input);
			ZVAL_COPY(&input, _0$$3);
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_array_fetch_string(&_3$$4, &input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 715 TSRMLS_CC);
			if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
				zephir_array_fetch_string(&_4$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 716 TSRMLS_CC);
				zephir_array_fetch_string(&_5$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 716 TSRMLS_CC);
				zephir_array_fetch_string(&_6$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 716 TSRMLS_CC);
				zephir_array_fetch_string(&_7$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 716 TSRMLS_CC);
				zephir_array_fetch_string(&_8$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 716 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_9, 232, &_4$$5, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &prefix);
				zephir_check_call_status();
				zephir_is_iterable(&smoothInput, 0, "phalcon/http/request.zep", 731);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _10$$5)
				{
					ZEPHIR_INIT_NVAR(&file);
					ZVAL_COPY(&file, _10$$5);
					_11$$6 = onlySuccessful == 0;
					if (!(_11$$6)) {
						zephir_array_fetch_string(&_12$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 719 TSRMLS_CC);
						_11$$6 = ZEPHIR_IS_LONG(&_12$$6, 0);
					}
					if (_11$$6) {
						ZEPHIR_INIT_NVAR(&dataFile);
						zephir_create_array(&dataFile, 5, 0 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 721 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("name"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 722 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 723 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("tmp_name"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 724 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("size"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(&_13$$7);
						zephir_array_fetch_string(&_13$$7, &file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 726 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("error"), &_13$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_14$$7);
						object_init_ex(&_14$$7, phalcon_http_request_file_ce);
						zephir_array_fetch_string(&_15$$7, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 728 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, &_14$$7, "__construct", &_16, 233, &dataFile, &_15$$7);
						zephir_check_call_status();
						zephir_array_append(&files, &_14$$7, PH_SEPARATE, "phalcon/http/request.zep", 728);
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&file);
			} else {
				_17$$8 = onlySuccessful == 0;
				if (!(_17$$8)) {
					zephir_array_fetch_string(&_18$$8, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 732 TSRMLS_CC);
					_17$$8 = ZEPHIR_IS_LONG(&_18$$8, 0);
				}
				if (_17$$8) {
					ZEPHIR_INIT_NVAR(&_19$$9);
					object_init_ex(&_19$$9, phalcon_http_request_file_ce);
					ZEPHIR_CALL_METHOD(NULL, &_19$$9, "__construct", &_16, 233, &input, &prefix);
					zephir_check_call_status();
					zephir_array_append(&files, &_19$$9, PH_SEPARATE, "phalcon/http/request.zep", 733);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CTOR(files);

}

/**
 * Smooth out $_FILES to have plain array with all files uploaded
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval prefix;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, *prefix_param = NULL, idx, name, file, files, parentFiles, p, *_0, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5;
	zval names, types, tmp_names, sizes, errors, _3$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmp_names);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&parentFiles);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &names_param, &types_param, &tmp_names_param, &sizes_param, &errors_param, &prefix_param);

	ZEPHIR_OBS_VAR_ONCE(&names);
	ZVAL_COPY(&names, names_param);
	ZEPHIR_OBS_VAR_ONCE(&types);
	ZVAL_COPY(&types, types_param);
	ZEPHIR_OBS_VAR_ONCE(&tmp_names);
	ZVAL_COPY(&tmp_names, tmp_names_param);
	ZEPHIR_OBS_VAR_ONCE(&sizes);
	ZVAL_COPY(&sizes, sizes_param);
	ZEPHIR_OBS_VAR_ONCE(&errors);
	ZVAL_COPY(&errors, errors_param);
	zephir_get_strval(&prefix, prefix_param);


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&names, 0, "phalcon/http/request.zep", 775);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&names), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&idx);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&idx, _2);
		} else {
			ZVAL_LONG(&idx, _1);
		}
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _0);
		ZEPHIR_INIT_NVAR(&p);
		ZEPHIR_CONCAT_VSV(&p, &prefix, ".", &idx);
		if (Z_TYPE_P(&name) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_create_array(&_3$$4, 6, 0 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &types, &idx, PH_NOISY, "phalcon/http/request.zep", 758 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &tmp_names, &idx, PH_NOISY, "phalcon/http/request.zep", 759 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("tmp_name"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &sizes, &idx, PH_NOISY, "phalcon/http/request.zep", 760 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("size"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch(&_4$$4, &errors, &idx, PH_NOISY, "phalcon/http/request.zep", 761 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("error"), &_4$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, &_3$$4, PH_SEPARATE, "phalcon/http/request.zep", 763);
		}
		if (Z_TYPE_P(&name) == IS_ARRAY) {
			zephir_array_fetch(&_5$$5, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 767 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 767 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 767 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 767 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 767 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, 232, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &p);
			zephir_check_call_status();
			zephir_is_iterable(&parentFiles, 0, "phalcon/http/request.zep", 772);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _11$$5)
			{
				ZEPHIR_INIT_NVAR(&file);
				ZVAL_COPY(&file, _11$$5);
				zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/http/request.zep", 770);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&file);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(files);

}

/**
 * Returns the available headers in the request
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	zend_string *_2;
	zend_ulong _1;
	zval headers;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zval __$true, _SERVER, name, value, contentHeaders, *_0, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _10$$4, _11$$4, _12$$4, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&contentHeaders);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&contentHeaders);
	zephir_create_array(&contentHeaders, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&_SERVER, 0, "phalcon/http/request.zep", 801);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (zephir_start_with_str(&name, SL("HTTP_"))) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_5$$4, 5);
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_substr(&_6$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "_");
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, " ");
			zephir_fast_str_replace(&_4$$4, &_7$$4, &_8$$4, &_6$$4 TSRMLS_CC);
			zephir_fast_strtolower(&_3$$4, &_4$$4);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 234, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZEPHIR_INIT_NVAR(&_11$$4);
			ZVAL_STRING(&_11$$4, " ");
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "-");
			zephir_fast_str_replace(&_10$$4, &_11$$4, &_12$$4, &name TSRMLS_CC);
			ZEPHIR_CPY_WRT(&name, &_10$$4);
			zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset(&contentHeaders, &name)) {
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZEPHIR_INIT_NVAR(&_14$$5);
			ZEPHIR_INIT_NVAR(&_15$$5);
			ZVAL_STRING(&_15$$5, "_");
			ZEPHIR_INIT_NVAR(&_16$$5);
			ZVAL_STRING(&_16$$5, " ");
			zephir_fast_str_replace(&_14$$5, &_15$$5, &_16$$5, &name TSRMLS_CC);
			zephir_fast_strtolower(&_13$$5, &_14$$5);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 234, &_13$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_17$$5);
			ZEPHIR_INIT_NVAR(&_18$$5);
			ZVAL_STRING(&_18$$5, " ");
			ZEPHIR_INIT_NVAR(&_19$$5);
			ZVAL_STRING(&_19$$5, "-");
			zephir_fast_str_replace(&_17$$5, &_18$$5, &_19$$5, &name TSRMLS_CC);
			ZEPHIR_CPY_WRT(&name, &_17$$5);
			zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(headers);

}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer) {

	zval _SERVER, httpReferer;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&httpReferer);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&httpReferer, &_SERVER, SL("HTTP_REFERER"), 1)) {
		RETURN_CTOR(httpReferer);
	}
	RETURN_MM_STRING("");

}

/**
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, returnedParts, part, headerParts, headerPart, split, _0, _1, _2, _3, _4, *_6, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, *_12$$3, _13$$4, _14$$4, _15$$5, _16$$6, _17$$6, _18$$7, _19$$7, _20$$8;
	zval serverIndex, name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&serverIndex);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&returnedParts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&headerParts);
	ZVAL_UNDEF(&headerPart);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

	if (unlikely(Z_TYPE_P(serverIndex_param) != IS_STRING && Z_TYPE_P(serverIndex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(serverIndex_param) == IS_STRING)) {
		zephir_get_strval(&serverIndex, serverIndex_param);
	} else {
		ZEPHIR_INIT_VAR(&serverIndex);
		ZVAL_EMPTY_STRING(&serverIndex);
	}
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_INIT_VAR(&returnedParts);
	array_init(&returnedParts);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getserver", NULL, 0, &serverIndex);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/,\\s*/");
	ZVAL_LONG(&_2, -1);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_split", &_5, 235, &_1, &_0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/http/request.zep", 844);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _6)
	{
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _6);
		ZEPHIR_INIT_NVAR(&headerParts);
		array_init(&headerParts);
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_fast_trim(&_7$$3, &part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "/\\s*;\\s*/");
		ZVAL_LONG(&_9$$3, -1);
		ZVAL_LONG(&_10$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "preg_split", &_5, 235, &_8$$3, &_7$$3, &_9$$3, &_10$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_11$$3, 0, "phalcon/http/request.zep", 841);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$3), _12$$3)
		{
			ZEPHIR_INIT_NVAR(&headerPart);
			ZVAL_COPY(&headerPart, _12$$3);
			ZEPHIR_INIT_NVAR(&_13$$4);
			ZVAL_STRING(&_13$$4, "=");
			ZEPHIR_INIT_NVAR(&_14$$4);
			zephir_fast_strpos(&_14$$4, &headerPart, &_13$$4, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_14$$4)) {
				ZEPHIR_INIT_NVAR(&split);
				zephir_fast_explode_str(&split, SL("="), &headerPart, 2  TSRMLS_CC);
				zephir_array_fetch_long(&_15$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 830 TSRMLS_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_15$$5, "q")) {
					ZEPHIR_OBS_NVAR(&_16$$6);
					zephir_array_fetch_long(&_16$$6, &split, 1, PH_NOISY, "phalcon/http/request.zep", 831 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_17$$6);
					ZVAL_DOUBLE(&_17$$6, zephir_get_doubleval(&_16$$6));
					zephir_array_update_string(&headerParts, SL("quality"), &_17$$6, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_18$$7, &split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 833 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&_19$$7);
					zephir_array_fetch_long(&_19$$7, &split, 0, PH_NOISY, "phalcon/http/request.zep", 833 TSRMLS_CC);
					zephir_array_update_zval(&headerParts, &_19$$7, &_18$$7, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$8);
				ZVAL_DOUBLE(&_20$$8, 1.0);
				zephir_array_update_string(&headerParts, SL("quality"), &_20$$8, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&headerPart);
		zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/http/request.zep", 841);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(returnedParts);

}

/**
 * Process a request header and return the one with best quality
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality) {

	double quality = 0, acceptQuality = 0;
	int i = 0;
	zval name;
	zval *qualityParts_param = NULL, *name_param = NULL, selectedName, accept, *_0, _1$$4, _2$$5;
	zval qualityParts;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&qualityParts);
	ZVAL_UNDEF(&selectedName);
	ZVAL_UNDEF(&accept);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &qualityParts_param, &name_param);

	zephir_get_arrval(&qualityParts, qualityParts_param);
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(&selectedName);
	ZVAL_STRING(&selectedName, "");
	zephir_is_iterable(&qualityParts, 0, "phalcon/http/request.zep", 873);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&qualityParts), _0)
	{
		ZEPHIR_INIT_NVAR(&accept);
		ZVAL_COPY(&accept, _0);
		if (i == 0) {
			ZEPHIR_OBS_NVAR(&_1$$4);
			zephir_array_fetch_string(&_1$$4, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 862 TSRMLS_CC);
			quality = zephir_get_doubleval(&_1$$4);
			ZEPHIR_OBS_NVAR(&selectedName);
			zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 863 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(&_2$$5);
			zephir_array_fetch_string(&_2$$5, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 865 TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(&_2$$5);
			if (acceptQuality > quality) {
				quality = acceptQuality;
				ZEPHIR_OBS_NVAR(&selectedName);
				zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 868 TSRMLS_CC);
			}
		}
		i++;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&accept);
	RETURN_CCTOR(selectedName);

}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType) {

	zval _SERVER, contentType;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&contentType);
	if (zephir_array_isset_string_fetch(&contentType, &_SERVER, SL("CONTENT_TYPE"), 0)) {
		RETURN_CCTOR(contentType);
	} else {
		ZEPHIR_OBS_NVAR(&contentType);
		if (zephir_array_isset_string_fetch(&contentType, &_SERVER, SL("HTTP_CONTENT_TYPE"), 0)) {
			RETURN_CCTOR(contentType);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Gets an array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 236, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 237, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_CHARSET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 236, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 237, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_LANGUAGE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 236, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 237, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth) {

	zend_bool _0;
	zval _SERVER, auth, _1$$3, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_USER"));
	if (_0) {
		_0 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_PW"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&auth);
		array_init(&auth);
		zephir_array_fetch_string(&_1$$3, &_SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 955 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2$$3, &_SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 956 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("password"), &_2$$3, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(auth);
	}
	RETURN_MM_NULL();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	zval auth;
	int ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, digest, matches, match, _0$$3, _1$$3, _2$$3, *_3$$5, _4$$6, _5$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&auth);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_OBS_VAR(&digest);
	if (zephir_array_isset_string_fetch(&digest, &_SERVER, SL("PHP_AUTH_DIGEST"), 0)) {
		ZEPHIR_INIT_VAR(&matches);
		array_init(&matches);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		ZVAL_LONG(&_1$$3, 2);
		ZEPHIR_MAKE_REF(&matches);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_match_all", NULL, 28, &_0$$3, &digest, &matches, &_1$$3);
		ZEPHIR_UNREF(&matches);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$3))) {
			RETURN_CTOR(auth);
		}
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			zephir_is_iterable(&matches, 0, "phalcon/http/request.zep", 981);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&match);
				ZVAL_COPY(&match, _3$$5);
				zephir_array_fetch_long(&_4$$6, &match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 979 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_5$$6);
				zephir_array_fetch_long(&_5$$6, &match, 1, PH_NOISY, "phalcon/http/request.zep", 979 TSRMLS_CC);
				zephir_array_update_zval(&auth, &_5$$6, &_4$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&match);
		}
	}
	RETURN_CTOR(auth);

}


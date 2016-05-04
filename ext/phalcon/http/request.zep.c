
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

	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
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
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 214, _REQUEST, name, filters, defaultValue, _0, _1);
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
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_POST, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 214, _POST, name, filters, defaultValue, _0, _1);
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
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *put = NULL, *_1, *_2, *_0$$3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

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
		ZEPHIR_INIT_NVAR(put);
		array_init(put);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getrawbody", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(put);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 215, _0$$3, put);
		ZEPHIR_UNREF(put);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_putCache"), put TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_1);
	if (notAllowEmpty) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_INIT_VAR(_2);
	if (noRecursive) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 214, put, name, filters, defaultValue, _1, _2);
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
	zval *name_param = NULL, *filters = NULL, *defaultValue = NULL, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, *_GET, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 214, _GET, name, filters, defaultValue, _0, _1);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 175);
				return;
			}
			ZEPHIR_INIT_VAR(_2$$6);
			ZVAL_STRING(_2$$6, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_1$$6, dependencyInjector, "getshared", NULL, 0, _2$$6);
			zephir_check_temp_parameter(_2$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(filter, _1$$6);
			zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
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


	RETURN_MM_BOOL(zephir_array_isset(_POST, name));

}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *put = NULL;
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


	RETURN_MM_BOOL(zephir_array_isset(_SERVER, name));

}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *_SERVER, *value = NULL, *name = NULL, _0, _1, *_2 = NULL, *_3;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "-", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "_", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 55, header, &_0, &_1);
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
	int ZEPHIR_LAST_CALL_STATUS;

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
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 293 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_1, "XMLHttpRequest");
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string(_SERVER, SS("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 308));
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether request has been made using any secure layer
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "https"));

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
		zephir_update_property_this(this_ptr, SL("_rawBody"), contents TSRMLS_CC);
		RETURN_CCTOR(contents);
	}
	RETURN_CCTOR(rawBody);

}

/**
 * Gets decoded JSON HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, *rawBody = NULL, _0;
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
	if (Z_TYPE_P(rawBody) != IS_STRING) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	zephir_json_decode(return_value, &(return_value), rawBody, zephir_get_intval(&_0)  TSRMLS_CC);
	RETURN_MM();

}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *serverAddr = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(serverAddr);
	if (zephir_array_isset_string_fetch(&serverAddr, _SERVER, SS("SERVER_ADDR"), 0 TSRMLS_CC)) {
		RETURN_CCTOR(serverAddr);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "localhost", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 216, &_0);
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
 * Gets information about schema, host and port used by the request
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zend_bool _2, _3;
	zval *httpHost = NULL, *scheme = NULL, *name = NULL, *port = NULL, *_0 = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&httpHost, this_ptr, "getserver", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(httpHost)) {
		RETURN_CCTOR(httpHost);
	}
	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "SERVER_NAME", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&name, this_ptr, "getserver", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "SERVER_PORT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&port, this_ptr, "getserver", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_STRING(scheme, "http");
	if (_2) {
		_2 = ZEPHIR_IS_LONG(port, 80);
	}
	if (_2) {
		RETURN_CCTOR(name);
	}
	_3 = ZEPHIR_IS_STRING(scheme, "https");
	if (_3) {
		_3 = ZEPHIR_IS_LONG(port, 443);
	}
	if (_3) {
		RETURN_CCTOR(name);
	}
	ZEPHIR_CONCAT_VSV(return_value, name, ":", port);
	RETURN_MM();

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
 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
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
		if (zephir_memnstr_str(address, SL(","), "phalcon/http/request.zep", 468)) {
			ZEPHIR_INIT_VAR(_0$$7);
			zephir_fast_explode_str(_0$$7, SL(","), address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_1$$7, _0$$7, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 472 TSRMLS_CC);
			RETURN_CTOR(_1$$7);
		}
		RETURN_CCTOR(address);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets HTTP method which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {

	zval *_SERVER, *requestMethod = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string_fetch(&requestMethod, _SERVER, SS("REQUEST_METHOD"), 1 TSRMLS_CC)) {
		RETURN_CTOR(requestMethod);
	}
	RETURN_MM_STRING("", 1);

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

	zval *method_param = NULL, *lowerMethod = NULL;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(method, method_param);


	ZEPHIR_INIT_VAR(lowerMethod);
	zephir_fast_strtoupper(lowerMethod, method);
	do {
		if (ZEPHIR_IS_STRING(method, "GET") || ZEPHIR_IS_STRING(method, "POST") || ZEPHIR_IS_STRING(method, "PUT") || ZEPHIR_IS_STRING(method, "DELETE") || ZEPHIR_IS_STRING(method, "HEAD") || ZEPHIR_IS_STRING(method, "OPTIONS") || ZEPHIR_IS_STRING(method, "PATCH")) {
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

	HashTable *_6$$5;
	HashPosition _5$$5;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3, _8$$6;
	zval *methods, *strict_param = NULL, *httpMethod = NULL, *method = NULL, *_1$$3 = NULL, *_3$$4, *_4$$4, **_7$$5, *_9$$6 = NULL, *_10$$8 = NULL, *_11$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isvalidhttpmethod", &_2, 0, methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(_3$$4);
			object_init_ex(_3$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid HTTP method: ", methods);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 9, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "phalcon/http/request.zep", 542 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, &_6$$5, &_5$$5, 0, 0, "phalcon/http/request.zep", 560);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$5, (void**) &_7$$5, &_5$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$5, &_5$$5)
		) {
			ZEPHIR_GET_HVALUE(method, _7$$5);
			_8$$6 = strict;
			if (_8$$6) {
				ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "isvalidhttpmethod", &_2, 0, method);
				zephir_check_call_status();
				_8$$6 = !zephir_is_true(_9$$6);
			}
			if (_8$$6) {
				if (Z_TYPE_P(method) == IS_STRING) {
					ZEPHIR_INIT_NVAR(_10$$8);
					object_init_ex(_10$$8, phalcon_http_request_exception_ce);
					ZEPHIR_INIT_LNVAR(_11$$8);
					ZEPHIR_CONCAT_SV(_11$$8, "Invalid HTTP method: ", method);
					ZEPHIR_CALL_METHOD(NULL, _10$$8, "__construct", NULL, 9, _11$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(_10$$8, "phalcon/http/request.zep", 551 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/http/request.zep", 553);
					return;
				}
			}
			if (ZEPHIR_IS_EQUAL(method, httpMethod)) {
				RETURN_MM_BOOL(1);
			}
		}
		RETURN_MM_BOOL(0);
	}
	if (strict) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/http/request.zep", 564);
		return;
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "POST"));

}

/**
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 217);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "OPTIONS"));

}

/**
 * Checks whether request include attached files
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, numberFiles;
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
	zephir_is_iterable(files, &_1, &_0, 0, 0, "phalcon/http/request.zep", 655);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
				ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "hasfilehelper", &_6, 218, error, _5$$8);
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
	int ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _3$$5;
	zval *data, *onlySuccessful_param = NULL, *value = NULL, **_2, *_4$$7 = NULL, *_5$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/http/request.zep", 682);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
			ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "hasfilehelper", &_6, 218, value, _5$$7);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_is_iterable(superFiles, &_1$$3, &_0$$3, 0, 0, "phalcon/http/request.zep", 720);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(prefix, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(input, _2$$3);
			ZEPHIR_OBS_NVAR(_3$$4);
			zephir_array_fetch_string(&_3$$4, input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 698 TSRMLS_CC);
			if (Z_TYPE_P(_3$$4) == IS_ARRAY) {
				zephir_array_fetch_string(&_4$$5, input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 699 TSRMLS_CC);
				zephir_array_fetch_string(&_5$$5, input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 699 TSRMLS_CC);
				zephir_array_fetch_string(&_6$$5, input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 699 TSRMLS_CC);
				zephir_array_fetch_string(&_7$$5, input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 699 TSRMLS_CC);
				zephir_array_fetch_string(&_8$$5, input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 699 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_9, 219, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, prefix);
				zephir_check_call_status();
				zephir_is_iterable(smoothInput, &_11$$5, &_10$$5, 0, 0, "phalcon/http/request.zep", 714);
				for (
				  ; zephir_hash_get_current_data_ex(_11$$5, (void**) &_12$$5, &_10$$5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11$$5, &_10$$5)
				) {
					ZEPHIR_GET_HVALUE(file, _12$$5);
					_13$$6 = onlySuccessful == 0;
					if (!(_13$$6)) {
						zephir_array_fetch_string(&_14$$6, file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 702 TSRMLS_CC);
						_13$$6 = ZEPHIR_IS_LONG(_14$$6, 0);
					}
					if (_13$$6) {
						ZEPHIR_INIT_NVAR(dataFile);
						zephir_create_array(dataFile, 5, 0 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 704 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("name"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 705 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 706 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("tmp_name"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 707 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("size"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_15$$7);
						zephir_array_fetch_string(&_15$$7, file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 709 TSRMLS_CC);
						zephir_array_update_string(&dataFile, SL("error"), &_15$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(_16$$7);
						object_init_ex(_16$$7, phalcon_http_request_file_ce);
						zephir_array_fetch_string(&_17$$7, file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 711 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, _16$$7, "__construct", &_18, 220, dataFile, _17$$7);
						zephir_check_call_status();
						zephir_array_append(&files, _16$$7, PH_SEPARATE, "phalcon/http/request.zep", 711);
					}
				}
			} else {
				_19$$8 = onlySuccessful == 0;
				if (!(_19$$8)) {
					zephir_array_fetch_string(&_20$$8, input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 715 TSRMLS_CC);
					_19$$8 = ZEPHIR_IS_LONG(_20$$8, 0);
				}
				if (_19$$8) {
					ZEPHIR_INIT_NVAR(_21$$9);
					object_init_ex(_21$$9, phalcon_http_request_file_ce);
					ZEPHIR_CALL_METHOD(NULL, _21$$9, "__construct", &_18, 220, input, prefix);
					zephir_check_call_status();
					zephir_array_append(&files, _21$$9, PH_SEPARATE, "phalcon/http/request.zep", 716);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
	zephir_is_iterable(names, &_1, &_0, 0, 0, "phalcon/http/request.zep", 758);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
			zephir_array_fetch(&_4$$4, types, idx, PH_NOISY, "phalcon/http/request.zep", 741 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, tmp_names, idx, PH_NOISY, "phalcon/http/request.zep", 742 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("tmp_name"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, sizes, idx, PH_NOISY, "phalcon/http/request.zep", 743 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("size"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_array_fetch(&_4$$4, errors, idx, PH_NOISY, "phalcon/http/request.zep", 744 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("error"), &_4$$4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, _3$$4, PH_SEPARATE, "phalcon/http/request.zep", 746);
		}
		if (Z_TYPE_P(name) == IS_ARRAY) {
			zephir_array_fetch(&_5$$5, names, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 750 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, types, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 750 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, tmp_names, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 750 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, sizes, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 750 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, errors, idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 750 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_10, 219, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, p);
			zephir_check_call_status();
			zephir_is_iterable(parentFiles, &_12$$5, &_11$$5, 0, 0, "phalcon/http/request.zep", 755);
			for (
			  ; zephir_hash_get_current_data_ex(_12$$5, (void**) &_13$$5, &_11$$5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_12$$5, &_11$$5)
			) {
				ZEPHIR_GET_HVALUE(file, _13$$5);
				zephir_array_append(&files, file, PH_SEPARATE, "phalcon/http/request.zep", 753);
			}
		}
	}
	RETURN_CCTOR(files);

}

/**
 * Returns the available headers in the request
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	HashTable *_1;
	HashPosition _0;
	zval *headers = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zval *_SERVER, *name = NULL, *value = NULL, *contentHeaders = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, _5$$4 = zval_used_for_init, *_6$$4 = NULL, _7$$4 = zval_used_for_init, _8$$4 = zval_used_for_init, *_10$$4 = NULL, _11$$4 = zval_used_for_init, _12$$4 = zval_used_for_init, *_13$$5 = NULL, *_14$$5 = NULL, _15$$5 = zval_used_for_init, _16$$5 = zval_used_for_init, *_17$$5 = NULL, _18$$5 = zval_used_for_init, _19$$5 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	ZEPHIR_INIT_VAR(contentHeaders);
	zephir_create_array(contentHeaders, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_is_iterable(_SERVER, &_1, &_0, 0, 0, "phalcon/http/request.zep", 784);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 221, _3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10$$4);
			ZEPHIR_SINIT_NVAR(_11$$4);
			ZVAL_STRING(&_11$$4, " ", 0);
			ZEPHIR_SINIT_NVAR(_12$$4);
			ZVAL_STRING(&_12$$4, "-", 0);
			zephir_fast_str_replace(&_10$$4, &_11$$4, &_12$$4, name TSRMLS_CC);
			ZEPHIR_CPY_WRT(name, _10$$4);
			zephir_array_update_zval(&headers, name, &value, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset(contentHeaders, name)) {
			ZEPHIR_INIT_NVAR(_13$$5);
			ZEPHIR_INIT_NVAR(_14$$5);
			ZEPHIR_SINIT_NVAR(_15$$5);
			ZVAL_STRING(&_15$$5, "_", 0);
			ZEPHIR_SINIT_NVAR(_16$$5);
			ZVAL_STRING(&_16$$5, " ", 0);
			zephir_fast_str_replace(&_14$$5, &_15$$5, &_16$$5, name TSRMLS_CC);
			zephir_fast_strtolower(_13$$5, _14$$5);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_9, 221, _13$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_17$$5);
			ZEPHIR_SINIT_NVAR(_18$$5);
			ZVAL_STRING(&_18$$5, " ", 0);
			ZEPHIR_SINIT_NVAR(_19$$5);
			ZVAL_STRING(&_19$$5, "-", 0);
			zephir_fast_str_replace(&_17$$5, &_18$$5, &_19$$5, name TSRMLS_CC);
			ZEPHIR_CPY_WRT(name, _17$$5);
			zephir_array_update_zval(&headers, name, &value, PH_COPY | PH_SEPARATE);
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
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader) {

	HashTable *_7, *_15$$3;
	HashPosition _6, _14$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, *returnedParts = NULL, *part = NULL, *headerParts = NULL, *headerPart = NULL, *split = NULL, *_0 = NULL, _1, _2, _3, *_4 = NULL, **_8, *_9$$3 = NULL, _10$$3 = zval_used_for_init, _11$$3 = zval_used_for_init, _12$$3 = zval_used_for_init, *_13$$3 = NULL, **_16$$3, _17$$4 = zval_used_for_init, *_18$$4 = NULL, *_19$$5, *_20$$6 = NULL, *_21$$6 = NULL, *_22$$7, *_23$$7 = NULL, *_24$$8 = NULL;
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getserver", NULL, 0, serverIndex);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/,\\s*/", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, -1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_split", &_5, 222, &_1, _0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_7, &_6, 0, 0, "phalcon/http/request.zep", 827);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HVALUE(part, _8);
		ZEPHIR_INIT_NVAR(headerParts);
		array_init(headerParts);
		ZEPHIR_INIT_NVAR(_9$$3);
		zephir_fast_trim(_9$$3, part, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_10$$3);
		ZVAL_STRING(&_10$$3, "/\\s*;\\s*/", 0);
		ZEPHIR_SINIT_NVAR(_11$$3);
		ZVAL_LONG(&_11$$3, -1);
		ZEPHIR_SINIT_NVAR(_12$$3);
		ZVAL_LONG(&_12$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_13$$3, "preg_split", &_5, 222, &_10$$3, _9$$3, &_11$$3, &_12$$3);
		zephir_check_call_status();
		zephir_is_iterable(_13$$3, &_15$$3, &_14$$3, 0, 0, "phalcon/http/request.zep", 824);
		for (
		  ; zephir_hash_get_current_data_ex(_15$$3, (void**) &_16$$3, &_14$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15$$3, &_14$$3)
		) {
			ZEPHIR_GET_HVALUE(headerPart, _16$$3);
			ZEPHIR_SINIT_NVAR(_17$$4);
			ZVAL_STRING(&_17$$4, "=", 0);
			ZEPHIR_INIT_NVAR(_18$$4);
			zephir_fast_strpos(_18$$4, headerPart, &_17$$4, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_18$$4)) {
				ZEPHIR_INIT_NVAR(split);
				zephir_fast_explode_str(split, SL("="), headerPart, 2  TSRMLS_CC);
				zephir_array_fetch_long(&_19$$5, split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 813 TSRMLS_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(_19$$5, "q")) {
					ZEPHIR_OBS_NVAR(_20$$6);
					zephir_array_fetch_long(&_20$$6, split, 1, PH_NOISY, "phalcon/http/request.zep", 814 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_21$$6);
					ZVAL_DOUBLE(_21$$6, zephir_get_doubleval(_20$$6));
					zephir_array_update_string(&headerParts, SL("quality"), &_21$$6, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_22$$7, split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 816 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_23$$7);
					zephir_array_fetch_long(&_23$$7, split, 0, PH_NOISY, "phalcon/http/request.zep", 816 TSRMLS_CC);
					zephir_array_update_zval(&headerParts, _23$$7, &_22$$7, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&headerParts, name, &headerPart, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_24$$8);
				ZVAL_DOUBLE(_24$$8, 1.0);
				zephir_array_update_string(&headerParts, SL("quality"), &_24$$8, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_append(&returnedParts, headerParts, PH_SEPARATE, "phalcon/http/request.zep", 824);
	}
	RETURN_CCTOR(returnedParts);

}

/**
 * Process a request header and return the one with best quality
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality) {

	HashTable *_1;
	HashPosition _0;
	double quality = 0, acceptQuality = 0;
	int i = 0;
	zval *name = NULL;
	zval *qualityParts_param = NULL, *name_param = NULL, *selectedName = NULL, *accept = NULL, **_2, *_3$$4 = NULL, *_4$$5 = NULL;
	zval *qualityParts = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &qualityParts_param, &name_param);

	zephir_get_arrval(qualityParts, qualityParts_param);
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
	zephir_is_iterable(qualityParts, &_1, &_0, 0, 0, "phalcon/http/request.zep", 856);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(accept, _2);
		if (i == 0) {
			ZEPHIR_OBS_NVAR(_3$$4);
			zephir_array_fetch_string(&_3$$4, accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 845 TSRMLS_CC);
			quality = zephir_get_doubleval(_3$$4);
			ZEPHIR_OBS_NVAR(selectedName);
			zephir_array_fetch(&selectedName, accept, name, PH_NOISY, "phalcon/http/request.zep", 846 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(_4$$5);
			zephir_array_fetch_string(&_4$$5, accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 848 TSRMLS_CC);
			acceptQuality = zephir_get_doubleval(_4$$5);
			if (acceptQuality > quality) {
				quality = acceptQuality;
				ZEPHIR_OBS_NVAR(selectedName);
				zephir_array_fetch(&selectedName, accept, name, PH_NOISY, "phalcon/http/request.zep", 851 TSRMLS_CC);
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
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 223, _0, _1);
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
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accept", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 224, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_CHARSET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 223, _0, _1);
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
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "charset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 224, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTP_ACCEPT_LANGUAGE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 223, _0, _1);
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
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "language", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 224, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
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
		zephir_array_fetch_string(&_1$$3, _SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 938 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2$$3, _SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 939 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("password"), &_2$$3, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(auth);
	}
	RETURN_MM_NULL();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	HashTable *_4$$5;
	HashPosition _3$$5;
	zval *auth = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
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
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_match_all", NULL, 28, _0$$3, digest, matches, _1$$3);
		zephir_check_temp_parameter(_0$$3);
		ZEPHIR_UNREF(matches);
		zephir_check_call_status();
		if (!(zephir_is_true(_2$$3))) {
			RETURN_CTOR(auth);
		}
		if (Z_TYPE_P(matches) == IS_ARRAY) {
			zephir_is_iterable(matches, &_4$$5, &_3$$5, 0, 0, "phalcon/http/request.zep", 964);
			for (
			  ; zephir_hash_get_current_data_ex(_4$$5, (void**) &_5$$5, &_3$$5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4$$5, &_3$$5)
			) {
				ZEPHIR_GET_HVALUE(match, _5$$5);
				zephir_array_fetch_long(&_6$$6, match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 962 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_7$$6);
				zephir_array_fetch_long(&_7$$6, match, 1, PH_NOISY, "phalcon/http/request.zep", 962 TSRMLS_CC);
				zephir_array_update_zval(&auth, _7$$6, &_6$$6, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CTOR(auth);

}


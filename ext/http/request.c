
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

#include "http/request.h"
#include "http/requestinterface.h"
#include "http/request/exception.h"
#include "http/request/file.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "filterinterface.h"

#include <main/php_variables.h>
#include <main/SAPI.h>
#include <ext/standard/php_smart_str.h>
#include <ext/standard/file.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/hash.h"

#include "interned-strings.h"

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
zend_class_entry *phalcon_http_request_ce;

PHP_METHOD(Phalcon_Http_Request, setDI);
PHP_METHOD(Phalcon_Http_Request, getDI);
PHP_METHOD(Phalcon_Http_Request, get);
PHP_METHOD(Phalcon_Http_Request, getPost);
PHP_METHOD(Phalcon_Http_Request, getPut);
PHP_METHOD(Phalcon_Http_Request, getQuery);
PHP_METHOD(Phalcon_Http_Request, getServer);
PHP_METHOD(Phalcon_Http_Request, has);
PHP_METHOD(Phalcon_Http_Request, hasPost);
PHP_METHOD(Phalcon_Http_Request, hasPut);
PHP_METHOD(Phalcon_Http_Request, hasQuery);
PHP_METHOD(Phalcon_Http_Request, hasServer);
PHP_METHOD(Phalcon_Http_Request, getHeader);
PHP_METHOD(Phalcon_Http_Request, getScheme);
PHP_METHOD(Phalcon_Http_Request, isAjax);
PHP_METHOD(Phalcon_Http_Request, isSoapRequested);
PHP_METHOD(Phalcon_Http_Request, isSecureRequest);
PHP_METHOD(Phalcon_Http_Request, getRawBody);
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody);
PHP_METHOD(Phalcon_Http_Request, getServerAddress);
PHP_METHOD(Phalcon_Http_Request, getServerName);
PHP_METHOD(Phalcon_Http_Request, getHttpHost);
PHP_METHOD(Phalcon_Http_Request, getClientAddress);
PHP_METHOD(Phalcon_Http_Request, getMethod);
PHP_METHOD(Phalcon_Http_Request, getURI);
PHP_METHOD(Phalcon_Http_Request, getUserAgent);
PHP_METHOD(Phalcon_Http_Request, isMethod);
PHP_METHOD(Phalcon_Http_Request, isPost);
PHP_METHOD(Phalcon_Http_Request, isGet);
PHP_METHOD(Phalcon_Http_Request, isPut);
PHP_METHOD(Phalcon_Http_Request, isPatch);
PHP_METHOD(Phalcon_Http_Request, isHead);
PHP_METHOD(Phalcon_Http_Request, isDelete);
PHP_METHOD(Phalcon_Http_Request, isOptions);
PHP_METHOD(Phalcon_Http_Request, hasFiles);
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles);
PHP_METHOD(Phalcon_Http_Request, getHeaders);
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer);
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader);
PHP_METHOD(Phalcon_Http_Request, _getBestQuality);
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent);
PHP_METHOD(Phalcon_Http_Request, getBestAccept);
PHP_METHOD(Phalcon_Http_Request, getClientCharsets);
PHP_METHOD(Phalcon_Http_Request, getBestCharset);
PHP_METHOD(Phalcon_Http_Request, getLanguages);
PHP_METHOD(Phalcon_Http_Request, getBestLanguage);
PHP_METHOD(Phalcon_Http_Request, getBasicAuth);
PHP_METHOD(Phalcon_Http_Request, getDigestAuth);

static const zend_function_entry phalcon_http_request_method_entry[] = {
	PHP_ME(Phalcon_Http_Request, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, get, arginfo_phalcon_http_requestinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPost, arginfo_phalcon_http_requestinterface_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPut, arginfo_phalcon_http_requestinterface_getput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getQuery, arginfo_phalcon_http_requestinterface_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServer, arginfo_phalcon_http_requestinterface_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, has, arginfo_phalcon_http_requestinterface_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPost, arginfo_phalcon_http_requestinterface_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPut, arginfo_phalcon_http_requestinterface_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasQuery, arginfo_phalcon_http_requestinterface_hasquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasServer, arginfo_phalcon_http_requestinterface_hasserver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHeader, arginfo_phalcon_http_requestinterface_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSoapRequested, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSecureRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getRawBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getJsonRawBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServerAddress, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHttpHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getURI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getUserAgent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isMethod, arginfo_phalcon_http_requestinterface_ismethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isGet, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPut, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isHead, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasFiles, arginfo_phalcon_http_requestinterface_hasfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getUploadedFiles, arginfo_phalcon_http_requestinterface_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHTTPReferer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, _getQualityHeader, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, _getBestQuality, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, getAcceptableContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestAccept, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getClientCharsets, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestCharset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getLanguages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestLanguage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBasicAuth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getDigestAuth, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Http\Request initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Request){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Request, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_put"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_ce TSRMLS_CC, 2, phalcon_http_requestinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Request, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_http_request_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Request, getDI){


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
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @param boolean $notAllowEmpty
 * @param boolean $noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, get){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL, *request;
	zval *value, *filter = NULL, *dependency_injector;
	zval *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 5, &name, &filters, &default_value, &not_allow_empty, &norecursive);
	
	if (!name) {
		name = PHALCON_GLOBAL(z_null);
	}
	
	if (!filters) {
		filters = PHALCON_GLOBAL(z_null);
	}
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	if (!not_allow_empty) {
		not_allow_empty = PHALCON_GLOBAL(z_false);
	}
	
	if (!norecursive) {
		norecursive = PHALCON_GLOBAL(z_false);
	}
	
	request = phalcon_get_global(SS("_REQUEST") TSRMLS_CC);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset_fetch(&value, request, name)) {
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_RETURN_CALL_METHOD(filter, "sanitize", value, filters, norecursive);
				if (return_value_ptr) {
					return_value = *return_value_ptr;
				}

				if ((PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) || PHALCON_IS_FALSE(return_value)) {
					zval_dtor(return_value);
					RETURN_CTOR(default_value);
				}

				RETURN_MM();
			}

			if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
				RETURN_CTOR(default_value);
			}

			RETURN_CTOR(value);
		}
	
		RETURN_CTOR(default_value);
	}
	
	RETURN_CTOR(request);
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
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @param boolean $notAllowEmpty
 * @param boolean $noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL, *post;
	zval *value, *filter = NULL, *dependency_injector, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 5, &name, &filters, &default_value, &not_allow_empty, &norecursive);
	
	if (!name) {
		name = PHALCON_GLOBAL(z_null);
	}
	
	if (!filters) {
		filters = PHALCON_GLOBAL(z_null);
	}
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	if (!not_allow_empty) {
		not_allow_empty = PHALCON_GLOBAL(z_false);
	}
	
	if (!norecursive) {
		norecursive = PHALCON_GLOBAL(z_false);
	}
	
	post = phalcon_get_global(SS("_POST") TSRMLS_CC);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(post, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, post, name, PH_NOISY);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_RETURN_CALL_METHOD(filter, "sanitize", value, filters, norecursive);
				if (return_value_ptr) {
					return_value = *return_value_ptr;
				}

				if ((PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) || PHALCON_IS_FALSE(return_value)) {
					zval_dtor(return_value);
					RETURN_CTOR(default_value);
				} else {
					RETURN_MM();
				}
			} else {
				if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
					RETURN_CTOR(default_value);
				} else {
					RETURN_CTOR(value);
				}
			}
		}
	
		RETURN_CTOR(default_value);
	}
	
	RETURN_CTOR(post);
}

/**
 * Gets a variable from put request
 *
 *<code>
 *	$userEmail = $request->getPut("user_email");
 *
 *	$userEmail = $request->getPut("user_email", "email");
 *</code>
 *
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @param boolean $notAllowEmpty
 * @param boolean $noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPut){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL;
	zval *is_put = NULL, *put = NULL, *raw = NULL, *value, *filter = NULL, *dependency_injector, *service;
	char *tmp;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 5, &name, &filters, &default_value, &not_allow_empty, &norecursive);
	
	if (!name) {
		name = PHALCON_GLOBAL(z_null);
	}
	
	if (!filters) {
		filters = PHALCON_GLOBAL(z_null);
	}
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	if (!not_allow_empty) {
		not_allow_empty = PHALCON_GLOBAL(z_false);
	}
	
	if (!norecursive) {
		norecursive = PHALCON_GLOBAL(z_false);
	}

	PHALCON_CALL_METHOD(&is_put, this_ptr, "isput");

	if (!zend_is_true(is_put)) {
		put = phalcon_get_global(SS("_PUT") TSRMLS_CC);
	}
	else {
		PHALCON_OBS_VAR(put);
		phalcon_read_property_this(&put, this_ptr, SL("_put"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(put) != IS_ARRAY) {
			PHALCON_CALL_METHOD(&raw, this_ptr, "getrawbody");

			PHALCON_INIT_NVAR(put);
			array_init(put);

			PHALCON_ENSURE_IS_STRING(&raw);
			tmp = estrndup(Z_STRVAL_P(raw), Z_STRLEN_P(raw));
			sapi_module.treat_data(PARSE_STRING, tmp, put TSRMLS_CC);

			phalcon_update_property_this(getThis(), SL("_put"), put TSRMLS_CC);
		}
	}
	
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(put, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, put, name, PH_NOISY);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_RETURN_CALL_METHOD(filter, "sanitize", value, filters, norecursive);
				if (return_value_ptr) {
					return_value = *return_value_ptr;
				}

				if ((PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) || PHALCON_IS_FALSE(return_value)) {
					zval_dtor(return_value);
					RETURN_CTOR(default_value);
				} else {
					RETURN_MM();
				}
			} else {
				if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
					RETURN_CTOR(default_value);
				} else {
					RETURN_CTOR(value);
				}
			}
		}
	
		RETURN_CTOR(default_value);
	}
	
	RETURN_CTOR(put);
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
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @param boolean $notAllowEmpty
 * @param boolean $noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL, *get;
	zval *value, *filter = NULL, *dependency_injector, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 5, &name, &filters, &default_value, &not_allow_empty, &norecursive);
	
	if (!name) {
		name = PHALCON_GLOBAL(z_null);
	}
	
	if (!filters) {
		filters = PHALCON_GLOBAL(z_null);
	}
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	if (!not_allow_empty) {
		not_allow_empty = PHALCON_GLOBAL(z_false);
	}
	
	if (!norecursive) {
		norecursive = PHALCON_GLOBAL(z_false);
	}
	
	get = phalcon_get_global(SS("_GET") TSRMLS_CC);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(get, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, get, name, PH_NOISY);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_RETURN_CALL_METHOD(filter, "sanitize", value, filters, norecursive);
				if (return_value_ptr) {
					return_value = *return_value_ptr;
				}

				if ((PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) || PHALCON_IS_FALSE(return_value)) {
					zval_dtor(return_value);
					RETURN_CTOR(default_value);
				} else {
					RETURN_MM();
				}
			} else {
				if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
					RETURN_CTOR(default_value);
				} else {
					RETURN_CTOR(value);
				}
			}
		}
	
		RETURN_CTOR(default_value);
	}
	
	RETURN_CTOR(get);
}

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getServer){

	zval *name, *_SERVER, *server_value;

	phalcon_fetch_params(0, 1, 0, &name);
	
	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_fetch(&server_value, _SERVER, name)) {
		RETURN_ZVAL(server_value, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Checks whether $_REQUEST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, has){

	zval *name, *_REQUEST;

	phalcon_fetch_params(0, 1, 0, &name);
	
	_REQUEST = phalcon_get_global(SS("_REQUEST") TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(_REQUEST, name));
}

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasPost){

	zval *name, *_POST;

	phalcon_fetch_params(0, 1, 0, &name);
	
	_POST = phalcon_get_global(SS("_POST") TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(_POST, name));
}

/**
 * Checks whether put has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasPut){

	zval *name, *is_put = NULL, *put = NULL, *raw = NULL;
	char *tmp;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_CALL_METHOD(&is_put, this_ptr, "isput");

	if (!zend_is_true(is_put)) {
		put = phalcon_get_global(SS("_PUT") TSRMLS_CC);
	}
	else {
		PHALCON_OBS_VAR(put);
		phalcon_read_property_this(&put, this_ptr, SL("_put"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(put) != IS_ARRAY) {
			PHALCON_CALL_METHOD(&raw, this_ptr, "getrawbody");

			PHALCON_INIT_NVAR(put);
			array_init(put);

			PHALCON_ENSURE_IS_STRING(&raw);
			tmp = estrndup(Z_STRVAL_P(raw), Z_STRLEN_P(raw));
			sapi_module.treat_data(PARSE_STRING, tmp, put TSRMLS_CC);

			phalcon_update_property_this(getThis(), SL("_put"), put TSRMLS_CC);
		}
	}

	RETVAL_BOOL(phalcon_array_isset(put, name));
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether $_GET superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery){

	zval *name, *_GET;

	phalcon_fetch_params(0, 1, 0, &name);
	
	_GET = phalcon_get_global(SS("_GET") TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(_GET, name));
}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, hasServer){

	zval *name, *_SERVER;

	phalcon_fetch_params(0, 1, 0, &name);
	
	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(_SERVER, name));
}

/**
 * Gets HTTP header from request data
 *
 * @param string $header
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHeader){

	zval *header, *_SERVER, *server_value, *key;

	phalcon_fetch_params(0, 1, 0, &header);
	
	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_fetch(&server_value, _SERVER, header)) {
		RETURN_ZVAL(server_value, 1, 0);
	}

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_SV(key, "HTTP_", header);
	if (phalcon_array_isset_fetch(&server_value, _SERVER, key)) {
		RETURN_CTOR(server_value);
	}

	RETURN_MM_EMPTY_STRING();
}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getScheme){

	zval *https_header, *https = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(https_header);
	ZVAL_STRING(https_header, "HTTPS", 1);
	
	PHALCON_CALL_METHOD(&https, this_ptr, "getserver", https_header);
	if (zend_is_true(https)) {
		if (PHALCON_IS_STRING(https, "off")) {
			RETVAL_STRING("http", 1);
		} else {
			RETVAL_STRING("https", 1);
		}
	} else {
		RETVAL_STRING("http", 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH']=='XMLHttpRequest'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isAjax){

	zval *requested_header, *xml_http_request;
	zval *requested_with = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(requested_header);
	ZVAL_STRING(requested_header, "HTTP_X_REQUESTED_WITH", 1);
	
	PHALCON_INIT_VAR(xml_http_request);
	ZVAL_STRING(xml_http_request, "XMLHttpRequest", 1);
	
	PHALCON_CALL_METHOD(&requested_with, this_ptr, "getheader", requested_header);
	is_equal_function(return_value, requested_with, xml_http_request TSRMLS_CC);
	RETURN_MM();
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested){

	zval *server, *content_type;

	server = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string(server, SS("HTTP_SOAPACTION"))) {
		RETURN_TRUE;
	}

	if (phalcon_array_isset_string_fetch(&content_type, server, SS("CONTENT_TYPE"))) {
		if (phalcon_memnstr_str(content_type, SL("application/soap+xml"))) {
			RETURN_TRUE;
		}
	}
	
	RETURN_FALSE;
}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest){

	zval *scheme = NULL, *https;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&scheme, this_ptr, "getscheme");
	
	PHALCON_INIT_VAR(https);
	ZVAL_STRING(https, "https", 1);
	is_identical_function(return_value, https, scheme TSRMLS_CC);
	RETURN_MM();
}

/**
 * Gets HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody){

	zval *raw;

#if PHP_VERSION_ID < 50600
	if (SG(request_info).raw_post_data) {
		RETURN_STRINGL(SG(request_info).raw_post_data, SG(request_info).raw_post_data_length, 1);
	}
#endif

	raw = phalcon_fetch_nproperty_this(getThis(), SL("_rawBody"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(raw) == IS_STRING) {
		RETURN_ZVAL(raw, 1, 0);
	}

#if PHP_VERSION_ID < 50600
	if (sapi_module.read_post) {
		int read_bytes;
		char *buf          = emalloc(8192);
		smart_str raw_data = { NULL, 0, 0 };

		while ((read_bytes = sapi_module.read_post(buf, 8192 TSRMLS_CC)) > 0) {
			smart_str_appendl(&raw_data, buf, read_bytes);
			SG(read_post_bytes) += read_bytes;
		}

		efree(buf);
		if (raw_data.c) {
			smart_str_0(&raw_data);
			RETVAL_STRINGL(raw_data.c, raw_data.len, 0);
		}
		else {
			RETVAL_EMPTY_STRING();
		}

		phalcon_update_property_this(getThis(), SL("_rawBody"), return_value TSRMLS_CC);
		return;
	}

	RETURN_EMPTY_STRING();
#else

	{
		zval *zcontext = NULL;
		php_stream_context *context = php_stream_context_from_zval(zcontext, 0);
		php_stream *stream = php_stream_open_wrapper_ex("php://input", "rb", REPORT_ERRORS, NULL, context);
		long int maxlen    = PHP_STREAM_COPY_ALL;
		char *content;
		int len;

		if (!stream) {
			RETURN_FALSE;
		}

		len = php_stream_copy_to_mem(stream, &content, maxlen, 0);
		if (len > 0) {
			RETVAL_STRINGL(content, len, 0);
			phalcon_update_property_this(getThis(), SL("_rawBody"), return_value TSRMLS_CC);
		}
		else if (!len) {
			RETVAL_EMPTY_STRING();
			phalcon_update_property_this(getThis(), SL("_rawBody"), return_value TSRMLS_CC);
		}
		else {
			RETVAL_FALSE;
		}

		php_stream_close(stream);
	}
#endif
}

/**
 * Gets decoded JSON HTTP raw request body
 *
 * @param bool $assoc
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody){

	zval *raw_body = NULL, *assoc = NULL;
	int ac = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &assoc);

	if (assoc && zend_is_true(assoc)) {
		ac = 1;
	}

	PHALCON_CALL_METHOD(&raw_body, this_ptr, "getrawbody");
	if (Z_TYPE_P(raw_body) == IS_STRING) {
		RETURN_MM_ON_FAILURE(phalcon_json_decode(return_value, raw_body, ac TSRMLS_CC));
		RETURN_MM();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress){

	zval *server, *server_addr;

	server = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&server_addr, server, SS("SERVER_ADDR"))) {
		RETURN_ZVAL(server_addr, 1, 0);
	}
	
	RETURN_STRING("127.0.0.1", 1);
}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerName){

	zval *server, *server_name = NULL;

	server = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&server_name, server, SS("SERVER_NAME"))) {
		RETURN_ZVAL(server_name, 1, 0);
	}
	
	RETURN_STRING("localhost", 1);
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost){

	zval *host, *http_host = NULL, *scheme = NULL, *server_name, *name = NULL;
	zval *server_port, *port = NULL, *http, *standard_port;
	zval *is_std_name, *is_std_port, *is_std_http;
	zval *https, *secure_port, *is_secure_scheme;
	zval *is_secure_port, *is_secure_http;

	PHALCON_MM_GROW();

	/** 
	 * Get the server name from _SERVER['HTTP_HOST']
	 */
	PHALCON_INIT_VAR(host);
	ZVAL_STRING(host, "HTTP_HOST", 1);
	
	PHALCON_CALL_METHOD(&http_host, this_ptr, "getserver", host);
	if (zend_is_true(http_host)) {
		RETURN_CTOR(http_host);
	}
	
	/** 
	 * Get current scheme
	 */
	PHALCON_CALL_METHOD(&scheme, this_ptr, "getscheme");
	
	/** 
	 * Get the server name from _SERVER['SERVER_NAME']
	 */
	PHALCON_INIT_VAR(server_name);
	ZVAL_STRING(server_name, "SERVER_NAME", 1);
	
	PHALCON_CALL_METHOD(&name, this_ptr, "getserver", server_name);
	
	/** 
	 * Get the server port from _SERVER['SERVER_PORT']
	 */
	PHALCON_INIT_VAR(server_port);
	ZVAL_STRING(server_port, "SERVER_PORT", 1);
	
	PHALCON_CALL_METHOD(&port, this_ptr, "getserver", server_port);
	
	PHALCON_INIT_VAR(http);
	ZVAL_STRING(http, "http", 1);
	
	PHALCON_INIT_VAR(standard_port);
	ZVAL_LONG(standard_port, 80);
	
	/** 
	 * Check if the request is a standard http
	 */
	PHALCON_INIT_VAR(is_std_name);
	is_equal_function(is_std_name, scheme, http TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_std_port);
	is_equal_function(is_std_port, port, standard_port TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_std_http);
	phalcon_and_function(is_std_http, is_std_name, is_std_port);
	
	PHALCON_INIT_VAR(https);
	ZVAL_STRING(https, "https", 1);
	
	PHALCON_INIT_VAR(secure_port);
	ZVAL_LONG(secure_port, 443);
	
	/** 
	 * Check if the request is a secure http request
	 */
	PHALCON_INIT_VAR(is_secure_scheme);
	is_equal_function(is_secure_scheme, scheme, https TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_secure_port);
	is_equal_function(is_secure_port, port, secure_port TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_secure_http);
	phalcon_and_function(is_secure_http, is_secure_scheme, is_secure_port);
	
	/** 
	 * If is standard http we return the server name only
	 */
	if (PHALCON_IS_TRUE(is_std_http)) {
		RETURN_CTOR(name);
	}
	
	/** 
	 * If is standard secure http we return the server name only
	 */
	if (PHALCON_IS_TRUE(is_secure_http)) {
		RETURN_CTOR(name);
	}
	
	PHALCON_CONCAT_VSV(return_value, name, ":", port);
	
	RETURN_MM();
}

/**
 * Gets most possible client IPv4 Address. This method search in $_SERVER['REMOTE_ADDR'] and optionally in $_SERVER['HTTP_X_FORWARDED_FOR']
 *
 * @param boolean $trustForwardedHeader
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress){

	zval *trust_forwarded_header = NULL, *address = NULL, *_SERVER;
	zval *addresses, *first;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &trust_forwarded_header);
	
	if (!trust_forwarded_header) {
		trust_forwarded_header = PHALCON_GLOBAL(z_false);
	}
	
	PHALCON_INIT_VAR(address);
	
	/** 
	 * Proxies use this IP
	 */
	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string(_SERVER, SS("HTTP_X_FORWARDED_FOR"))) {
		if (zend_is_true(trust_forwarded_header)) {
			PHALCON_OBS_NVAR(address);
			phalcon_array_fetch_string(&address, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY);
		}
	}

	if (Z_TYPE_P(address) == IS_NULL) {
		if (phalcon_array_isset_string(_SERVER, SS("REMOTE_ADDR"))) {
			PHALCON_OBS_NVAR(address);
			phalcon_array_fetch_string(&address, _SERVER, SL("REMOTE_ADDR"), PH_NOISY);
		}
	}
	
	if (Z_TYPE_P(address) == IS_STRING) {
		if (phalcon_memnstr_str(address, SL(","))) {
			/** 
			 * The client address has multiples parts, only return the first part
			 */
			PHALCON_INIT_VAR(addresses);
			phalcon_fast_explode_str(addresses, SL(","), address);
	
			PHALCON_OBS_VAR(first);
			phalcon_array_fetch_long(&first, addresses, 0, PH_NOISY);
			RETURN_CTOR(first);
		}
	
		RETURN_CTOR(address);
	}
	
	RETURN_MM_FALSE;
}

static const char* phalcon_http_request_getmethod_helper(TSRMLS_D)
{
	zval **value;
	const char *method = SG(request_info).request_method;
	if (unlikely(!method)) {
		zval *_SERVER, key;

		INIT_ZVAL(key);
		ZVAL_STRING(&key, "REQUEST_METHOD", 0);

		_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
		if (Z_TYPE_P(_SERVER) == IS_ARRAY) {
			value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA);
			if (value && Z_TYPE_PP(value) == IS_STRING) {
				return Z_STRVAL_PP(value);
			}
		}

		return "";
	}

	return method;
}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getMethod){

	const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
	if (method) {
		RETURN_STRING(method, !IS_INTERNED(method));
	}

	RETURN_EMPTY_STRING();
}

/**
 * Gets HTTP URI which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getURI){

	zval **value, *_SERVER, key = zval_used_for_init;

	INIT_ZVAL(key);
	ZVAL_STRING(&key, "REQUEST_URI", 0);

	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	value = (Z_TYPE_P(_SERVER) == IS_ARRAY) ? phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA) : NULL;
	if (value && Z_TYPE_PP(value) == IS_STRING) {
		RETURN_ZVAL(*value, 1, 0);
	}

	RETURN_EMPTY_STRING();
}

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent){

	zval *server, *user_agent;

	server = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&user_agent, server, SS("HTTP_USER_AGENT"))) {
		RETURN_ZVAL(user_agent, 1, 0);
	}
	
	RETURN_EMPTY_STRING();
}

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array $methods
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isMethod){

	zval *methods, *http_method = NULL, *method = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &methods);
	
	PHALCON_CALL_METHOD(&http_method, this_ptr, "getmethod");

	if (Z_TYPE_P(methods) == IS_STRING) {
		is_equal_function(return_value, methods, http_method TSRMLS_CC);
		RETURN_MM();
	}
	
	phalcon_is_iterable(methods, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(method);

		if (PHALCON_IS_EQUAL(method, http_method)) {
			RETURN_MM_TRUE;
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPost){

	zval *post, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "POST"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(post);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(post, phalcon_interned_POST);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, post TSRMLS_CC);

	RETURN_MM();
}

/**
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet){

	zval *get, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "GET"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(get);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(get, phalcon_interned_GET);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, get TSRMLS_CC);

	RETURN_MM();
}

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut){

	zval *put, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "PUT"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(put);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(put, phalcon_interned_PUT);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, put TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is PATCH. if $_SERVER['REQUEST_METHOD']=='PATCH'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPatch){

	zval *patch, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "PATCH"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(patch);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(patch, phalcon_interned_PATCH);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, patch TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead){

	zval *head, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "HEAD"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(head);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(head, phalcon_interned_HEAD);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, head TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete){

	zval *delete, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "DELETE"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(delete);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(delete, phalcon_interned_DELETE);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, delete TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions){

	zval *options, *method = NULL;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "OPTIONS"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(options);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(options, phalcon_interned_OPTIONS);

	PHALCON_CALL_METHOD(&method, this_ptr, "getmethod");
	is_equal_function(return_value, method, options TSRMLS_CC);
	
	RETURN_MM();
}

static int phalcon_http_request_hasfiles_helper(zval *arr, int only_successful)
{
	HashPosition hp;
	zval **value;
	int nfiles = 0;

	assert(Z_TYPE_P(arr) == IS_ARRAY);

	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(arr), &hp);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(arr), (void**) &value, &hp) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(arr), &hp)
	) {
		if (Z_TYPE_PP(value) < IS_ARRAY) {
			if (!zend_is_true(*value) || !only_successful) {
				++nfiles;
			}
		}
		else if (Z_TYPE_PP(value) == IS_ARRAY) {
			nfiles += phalcon_http_request_hasfiles_helper(*value, only_successful);
		}
	}

	return nfiles;
}

/**
 * Checks whether request includes attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles){

	zval *not_errored = NULL, *_FILES, *error = NULL;
	HashPosition hp0;
	zval **hd;
	int nfiles = 0;
	int only_successful;

	phalcon_fetch_params(0, 0, 1, &not_errored);
	
	only_successful = not_errored ? phalcon_get_intval(not_errored) : 1;
	
	_FILES = phalcon_get_global(SS("_FILES") TSRMLS_CC);
	if (unlikely(Z_TYPE_P(_FILES) != IS_ARRAY)) {
		RETURN_LONG(0);
	}

	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(_FILES), &hp0);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(_FILES), (void**)&hd, &hp0) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(_FILES), &hp0)
	) {
		if (phalcon_array_isset_string_fetch(&error, *hd, SS("error"))) {
			if (Z_TYPE_P(error) < IS_ARRAY) {
				if (!zend_is_true(error) || !only_successful) {
					++nfiles;
				}
			}
			else if (Z_TYPE_P(error) == IS_ARRAY) {
				nfiles += phalcon_http_request_hasfiles_helper(error, only_successful);
			}
		}
	}

	RETURN_LONG(nfiles);
}

static void phalcon_http_request_getuploadedfiles_helper(zval **return_value, zval *name, zval *type, zval *tmp_name, zval *error, zval *size, int only_successful, smart_str *prefix TSRMLS_DC)
{
	if (
		   Z_TYPE_P(name) == IS_ARRAY && Z_TYPE_P(type) == IS_ARRAY
		&& Z_TYPE_P(tmp_name) == IS_ARRAY && Z_TYPE_P(error) == IS_ARRAY
		&& Z_TYPE_P(size) == IS_ARRAY
	) {
		HashPosition pos_name, pos_type, pos_tmp, pos_error, pos_size;
		zval **dname, **dtype, **dtmp, **derror, **dsize;
		zval *arr, *file, *key;
		size_t prefix_len = prefix->len;
		int res;

		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(name),     &pos_name);
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(type),     &pos_type);
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(tmp_name), &pos_tmp);
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(error),    &pos_error);
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(size),     &pos_size);

		while (
			   zend_hash_get_current_data_ex(Z_ARRVAL_P(name),     (void**)&dname,  &pos_name)  == SUCCESS
			&& zend_hash_get_current_data_ex(Z_ARRVAL_P(type),     (void**)&dtype,  &pos_type)  == SUCCESS
			&& zend_hash_get_current_data_ex(Z_ARRVAL_P(tmp_name), (void**)&dtmp,   &pos_tmp)   == SUCCESS
			&& zend_hash_get_current_data_ex(Z_ARRVAL_P(error),    (void**)&derror, &pos_error) == SUCCESS
			&& zend_hash_get_current_data_ex(Z_ARRVAL_P(size),     (void**)&dsize,  &pos_size)  == SUCCESS
		) {
			zval index = phalcon_get_current_key_w(Z_ARRVAL_P(name), &pos_name);

			if (Z_TYPE(index) == IS_STRING) {
				smart_str_appendl(prefix, Z_STRVAL(index), Z_STRLEN(index));
			}
			else {
				smart_str_append_long(prefix, Z_LVAL(index));
			}

			if (Z_TYPE_PP(derror) < IS_ARRAY) {
				if (!zend_is_true(*derror) || !only_successful) {
					Z_ADDREF_PP(dname);
					Z_ADDREF_PP(dtype);
					Z_ADDREF_PP(dtmp);
					Z_ADDREF_PP(derror);
					Z_ADDREF_PP(dsize);

					MAKE_STD_ZVAL(arr);
					array_init_size(arr, 5);
					add_assoc_zval_ex(arr, ISS(name),      *dname);
					add_assoc_zval_ex(arr, ISS(type),      *dtype);
					add_assoc_zval_ex(arr, SS("tmp_name"), *dtmp);
					add_assoc_zval_ex(arr, SS("error"),    *derror);
					add_assoc_zval_ex(arr, SS("size"),     *dsize);

					MAKE_STD_ZVAL(key);
					ZVAL_STRINGL(key, prefix->c, prefix->len, 1);
					prefix->len = prefix_len;

					MAKE_STD_ZVAL(file);
					object_init_ex(file, phalcon_http_request_file_ce);

					{
						zval *params[] = { arr, key };
						res = phalcon_call_method(NULL, file, "__construct", 2, params TSRMLS_CC);
					}

					zval_ptr_dtor(&arr);
					zval_ptr_dtor(&key);

					if (res != FAILURE) {
						add_next_index_zval(*return_value, file);
					}
					else {
						break;
					}
				}
			}
			else if (Z_TYPE_PP(derror) == IS_ARRAY) {
				smart_str_appendc(prefix, '.');
				phalcon_http_request_getuploadedfiles_helper(return_value, *dname, *dtype, *dtmp, *derror, *dsize, only_successful, prefix TSRMLS_CC);
				prefix->len = prefix_len;
			}

			zend_hash_move_forward_ex(Z_ARRVAL_P(name),     &pos_name);
			zend_hash_move_forward_ex(Z_ARRVAL_P(type),     &pos_type);
			zend_hash_move_forward_ex(Z_ARRVAL_P(tmp_name), &pos_tmp);
			zend_hash_move_forward_ex(Z_ARRVAL_P(error),    &pos_error);
			zend_hash_move_forward_ex(Z_ARRVAL_P(size),     &pos_size);
		}
	}
}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @param boolean $notErrored
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles){

	zval *name = NULL, *type = NULL, *tmp_name = NULL, *error, *size = NULL;
	zval *not_errored = NULL, *_FILES, *request_file = NULL, *key = NULL;
	zval index;
	HashPosition hp0;
	zval **hd;
	int only_successful;
	smart_str prefix = { NULL, 0, 0 };

	phalcon_fetch_params(0, 0, 1, &not_errored);
	
	only_successful = not_errored ? phalcon_get_intval(not_errored) : 1;

	array_init(return_value);

	_FILES = phalcon_get_global(SS("_FILES") TSRMLS_CC);
	if (Z_TYPE_P(_FILES) != IS_ARRAY || !zend_hash_num_elements(Z_ARRVAL_P(_FILES))) {
		return;
	}

	PHALCON_MM_GROW();
	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(_FILES), &hp0);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(_FILES), (void**)&hd, &hp0) == SUCCESS && !EG(exception);
		zend_hash_move_forward_ex(Z_ARRVAL_P(_FILES), &hp0)
	) {
		if (phalcon_array_isset_string_fetch(&error, *hd, SS("error"))) {
			index = phalcon_get_current_key_w(Z_ARRVAL_P(_FILES), &hp0);

			if (Z_TYPE_P(error) < IS_ARRAY) {
				if (!zend_is_true(error) || !only_successful) {
					PHALCON_INIT_NVAR(request_file);
					object_init_ex(request_file, phalcon_http_request_file_ce);

					PHALCON_INIT_NVAR(key);
					ZVAL_STRINGL(key, Z_STRVAL(index), Z_STRLEN(index), 1);

					PHALCON_CALL_METHOD(NULL, request_file, "__construct", *hd, key);

					phalcon_array_append(&return_value, request_file, 0);
				}
			}
			else if (Z_TYPE_P(error) == IS_ARRAY) {
				PHALCON_OBS_NVAR(name);
				PHALCON_OBS_NVAR(type);
				PHALCON_OBS_NVAR(tmp_name);
				PHALCON_OBS_NVAR(size);
				phalcon_array_fetch_string(&name,     *hd, SL("name"),     PH_NOISY);
				phalcon_array_fetch_string(&type,     *hd, SL("type"),     PH_NOISY);
				phalcon_array_fetch_string(&tmp_name, *hd, SL("tmp_name"), PH_NOISY);
				phalcon_array_fetch_string(&size,     *hd, SL("size"),     PH_NOISY);

				if (prefix.len) {
					prefix.len = 0;
				}

				if (likely(Z_TYPE(index) == IS_STRING)) {
					smart_str_appendl(&prefix, Z_STRVAL(index), Z_STRLEN(index));
				}
				else {
					smart_str_append_long(&prefix, Z_LVAL(index));
				}

				smart_str_appendc(&prefix, '.');
				phalcon_http_request_getuploadedfiles_helper(&return_value, name, type, tmp_name, error, size, only_successful, &prefix TSRMLS_CC);
			}
		}
	}
	
	if (prefix.c) {
		smart_str_free(&prefix);
	}

	RETURN_MM();
}

/**
 * Returns the available headers in the request
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders){

	zval *_SERVER;
	HashPosition hp0;
	zval **hd;

	array_init(return_value);
	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (unlikely(Z_TYPE_P(_SERVER) != IS_ARRAY)) {
		return;
	}

	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(_SERVER), &hp0);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(_SERVER), (void**)&hd, &hp0) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(_SERVER), &hp0)
	) {
		zval key = phalcon_get_current_key_w(Z_ARRVAL_P(_SERVER), &hp0);
	
		if (Z_TYPE(key) == IS_STRING && Z_STRLEN(key) > 5 && !memcmp(Z_STRVAL(key), "HTTP_", 5)) {
			zval *header;

			MAKE_STD_ZVAL(header);
			ZVAL_STRINGL(header, Z_STRVAL(key) + 5, Z_STRLEN(key) - 5, 1);
			phalcon_array_update_zval(&return_value, header, *hd, 0);
		}
	}
}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer){

	zval *_SERVER, *http_referer;

	_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&http_referer, _SERVER, SS("HTTP_REFERER"))) {
		RETURN_ZVAL(http_referer, 1, 0);
	}

	RETURN_EMPTY_STRING();
}

/**
 * Process a request header and return an array of values with their qualities
 *
 * @param string $serverIndex
 * @param string $name
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader){

	zval *server_index, *name, *quality_one;
	zval *http_server = NULL, *pattern, *parts = NULL, *part = NULL, *header_parts = NULL;
	zval *quality_part = NULL, *quality = NULL, *header_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &server_index, &name);
	
	PHALCON_INIT_VAR(quality_one);
	ZVAL_DOUBLE(quality_one, 1);
	
	array_init(return_value);
	
	PHALCON_CALL_METHOD(&http_server, this_ptr, "getserver", server_index);
	
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/,\\s*/", 1);
	PHALCON_CALL_FUNCTION(&parts, "preg_split", pattern, http_server);
	
	phalcon_is_iterable(parts, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(part);
	
		PHALCON_INIT_NVAR(header_parts);
		phalcon_fast_explode_str(header_parts, SL(";"), part);
		if (phalcon_array_isset_long(header_parts, 1)) {
			PHALCON_OBS_NVAR(quality_part);
			phalcon_array_fetch_long(&quality_part, header_parts, 1, PH_NOISY);
	
			PHALCON_INIT_NVAR(quality);
			phalcon_substr(quality, quality_part, 2, 0);
		} else {
			PHALCON_CPY_WRT(quality, quality_one);
		}
	
		PHALCON_OBS_NVAR(header_name);
		phalcon_array_fetch_long(&header_name, header_parts, 0, PH_NOISY);
	
		PHALCON_INIT_NVAR(quality_part);
		array_init_size(quality_part, 2);
		phalcon_array_update_zval(&quality_part, name, header_name, PH_COPY);
		phalcon_array_update_string(&quality_part, SL("quality"), quality, PH_COPY);
		phalcon_array_append(&return_value, quality_part, 0);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Process a request header and return the one with best quality
 *
 * @param array $qualityParts
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality){

	zval *quality_parts, *name, *quality = NULL, *selected_name = NULL;
	zval *accept = NULL, *accept_quality = NULL, *best_quality = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	long int i = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &quality_parts, &name);
	
	PHALCON_INIT_VAR(quality);
	ZVAL_LONG(quality, 0);
	
	PHALCON_INIT_VAR(selected_name);
	ZVAL_EMPTY_STRING(selected_name);
	
	phalcon_is_iterable(quality_parts, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(accept);
	
		if (i == 0) {
			PHALCON_OBS_NVAR(quality);
			phalcon_array_fetch_string(&quality, accept, SL("quality"), PH_NOISY);
	
			PHALCON_OBS_NVAR(selected_name);
			phalcon_array_fetch(&selected_name, accept, name, PH_NOISY);
		} else {
			PHALCON_OBS_NVAR(accept_quality);
			phalcon_array_fetch_string(&accept_quality, accept, SL("quality"), PH_NOISY);
	
			PHALCON_INIT_NVAR(best_quality);
			is_smaller_function(best_quality, quality, accept_quality TSRMLS_CC);
			if (PHALCON_IS_TRUE(best_quality)) {
				PHALCON_CPY_WRT(quality, accept_quality);
	
				PHALCON_OBS_NVAR(selected_name);
				phalcon_array_fetch(&selected_name, accept, name, PH_NOISY);
			}
		}

		++i;
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(selected_name);
}

/**
 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent){

	zval *accept_header, *quality_index;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(accept_header);
	ZVAL_STRING(accept_header, "HTTP_ACCEPT", 1);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "accept", 1);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", accept_header, quality_index);
	RETURN_MM();
}

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept){

	zval *quality_index, *acceptable_content = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "accept", 1);
	
	PHALCON_CALL_METHOD(&acceptable_content, this_ptr, "getacceptablecontent");
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getbestquality", acceptable_content, quality_index);
	RETURN_MM();
}

/**
 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets){

	zval *charset_header, *quality_index;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(charset_header);
	ZVAL_STRING(charset_header, "HTTP_ACCEPT_CHARSET", 1);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "charset", 1);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", charset_header, quality_index);
	RETURN_MM();
}

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset){

	zval *quality_index, *client_charsets = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "charset", 1);
	
	PHALCON_CALL_METHOD(&client_charsets, this_ptr, "getclientcharsets");
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getbestquality", client_charsets, quality_index);
	RETURN_MM();
}

/**
 * Gets languages array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages){

	zval *language_header, *quality_index;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(language_header);
	ZVAL_STRING(language_header, "HTTP_ACCEPT_LANGUAGE", 1);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "language", 1);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", language_header, quality_index);
	RETURN_MM();
}

/**
 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage){

	zval *languages = NULL, *quality_index;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&languages, this_ptr, "getlanguages");
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "language", 1);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getbestquality", languages, quality_index);
	RETURN_MM();
}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth){

	zval *_SERVER;
	zval **value;
	char *auth_user = SG(request_info).auth_user;
	char *auth_password = SG(request_info).auth_password;

	if (unlikely(!auth_user)) {
		_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
		if (Z_TYPE_P(_SERVER) == IS_ARRAY) {
			zval key = zval_used_for_init;

			ZVAL_STRING(&key, "PHP_AUTH_USER", 0);

			value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA);
			if (value && Z_TYPE_PP(value) == IS_STRING) {
				auth_user = Z_STRVAL_PP(value);
			}

			ZVAL_STRING(&key, "PHP_AUTH_PW", 0);

			value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA);
			if (value && Z_TYPE_PP(value) == IS_STRING) {
				auth_password = Z_STRVAL_PP(value);
			}
		}
	}

	if (!auth_user) {
		RETURN_NULL();
	}
	
	if (!auth_password) {
		auth_password = "";
	}

	array_init_size(return_value, 2);
	add_assoc_stringl_ex(return_value, SS("username"), auth_user, strlen(auth_user), 1);
	add_assoc_stringl_ex(return_value, SS("password"), auth_password, strlen(auth_password), 1);
}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth){

	zval *digest, *pattern, *set_order, *matches, *match = NULL, *ret = NULL, *tmp1, *tmp2;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	const char *auth_digest = SG(request_info).auth_digest;

	PHALCON_MM_GROW();

	if (unlikely(!auth_digest)) {
		zval *_SERVER = phalcon_get_global(SS("_SERVER") TSRMLS_CC);
		if (Z_TYPE_P(_SERVER) == IS_ARRAY) {
			zval key = zval_used_for_init;
			zval **value;

			ZVAL_STRING(&key, "PHP_AUTH_DIGEST", 0);

			value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA);
			if (value && Z_TYPE_PP(value) == IS_STRING) {
				auth_digest = Z_STRVAL_PP(value);
			}
		}
	}

	if (auth_digest) {
		PHALCON_INIT_VAR(digest);
		ZVAL_STRING(digest, auth_digest, 1);

		PHALCON_INIT_VAR(pattern);
		ZVAL_STRING(pattern, "#(\\w+)=(['\"]?)([^'\", ]+)\\2#", 1);

		PHALCON_INIT_VAR(set_order);
		ZVAL_LONG(set_order, 2);

		PHALCON_INIT_VAR(matches);
		Z_SET_ISREF_P(matches);
		PHALCON_CALL_FUNCTION(&ret, "preg_match_all", pattern, digest, matches, set_order);
		Z_UNSET_ISREF_P(matches);

		if (zend_is_true(ret) && Z_TYPE_P(matches) == IS_ARRAY) {
			array_init(return_value);

			phalcon_is_iterable(matches, &ah0, &hp0, 0, 0);
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HVALUE(match);

				if (Z_TYPE_P(match) == IS_ARRAY && phalcon_array_isset_long_fetch(&tmp1, match, 1) && phalcon_array_isset_long_fetch(&tmp2, match, 3)) {
					phalcon_array_update_zval(&return_value, tmp1, tmp2, PH_COPY);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
			}

			RETURN_MM();
		}
	}

	RETURN_MM_NULL();
}

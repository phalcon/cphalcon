
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "main/SAPI.h"

#include "ext/standard/php_smart_str.h"

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


/**
 * Phalcon\Http\Request initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Request){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Request, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL, *request = NULL;
	zval *_REQUEST, *value, *filter = NULL, *dependency_injector;
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
	
	phalcon_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	PHALCON_CPY_WRT(request, _REQUEST);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(request, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, request, name, PH_NOISY);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_INIT_NVAR(filter);
					phalcon_call_method_p1(filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				phalcon_call_method_p3(return_value, filter, "sanitize", value, filters, norecursive);

				if (PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) {
					zval_dtor(return_value);
					RETURN_CCTOR(default_value);
				}

				RETURN_MM();
			}

			if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
				RETURN_CCTOR(default_value);
			}

			RETURN_CCTOR(value);
		}
	
		RETURN_CCTOR(default_value);
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
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @param boolean $notAllowEmpty
 * @param boolean $noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL, *post = NULL, *_POST;
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
	
	phalcon_get_global(&_POST, SS("_POST") TSRMLS_CC);
	PHALCON_CPY_WRT(post, _POST);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(post, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, post, name, PH_NOISY);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_INIT_NVAR(filter);
					phalcon_call_method_p1(filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				phalcon_call_method_p3(return_value, filter, "sanitize", value, filters, norecursive);

				if (PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) {
					zval_dtor(return_value);
					RETURN_CCTOR(default_value);
				} else {
					RETURN_MM();
				}
			} else {
				if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
					RETURN_CCTOR(default_value);
				} else {
					RETURN_CCTOR(value);
				}
			}
		}
	
		RETURN_CCTOR(default_value);
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
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @param boolean $notAllowEmpty
 * @param boolean $noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *not_allow_empty = NULL, *norecursive = NULL, *get = NULL, *_GET;
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
	
	phalcon_get_global(&_GET, SS("_GET") TSRMLS_CC);
	PHALCON_CPY_WRT(get, _GET);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(get, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, get, name, PH_NOISY);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_INIT_NVAR(filter);
					phalcon_call_method_p1(filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				phalcon_call_method_p3(return_value, filter, "sanitize", value, filters, norecursive);

				if (PHALCON_IS_EMPTY(return_value) && zend_is_true(not_allow_empty)) {
					zval_dtor(return_value);
					RETURN_CCTOR(default_value);
				} else {
					RETURN_MM();
				}
			} else {
				if (PHALCON_IS_EMPTY(value) && zend_is_true(not_allow_empty)) {
					RETURN_CCTOR(default_value);
				} else {
					RETURN_CCTOR(value);
				}
			}
		}
	
		RETURN_CCTOR(default_value);
	}
	
	RETURN_CCTOR(get);
}

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getServer){

	zval *name, *_SERVER, *server_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset(_SERVER, name)) {
		PHALCON_OBS_VAR(server_value);
		phalcon_array_fetch(&server_value, _SERVER, name, PH_NOISY);
		RETURN_CCTOR(server_value);
	}
	RETURN_MM_NULL();
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
	
	phalcon_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	if (phalcon_array_isset(_REQUEST, name)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
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
	
	phalcon_get_global(&_POST, SS("_POST") TSRMLS_CC);
	if (phalcon_array_isset(_POST, name)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
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
	
	phalcon_get_global(&_GET, SS("_GET") TSRMLS_CC);
	if (phalcon_array_isset(_GET, name)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
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
	
	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset(_SERVER, name)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}

/**
 * Gets HTTP header from request data
 *
 * @param string $header
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHeader){

	zval *header, *_SERVER, *server_value = NULL, *key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &header);
	
	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset(_SERVER, header)) {
		PHALCON_OBS_VAR(server_value);
		phalcon_array_fetch(&server_value, _SERVER, header, PH_NOISY);
		RETURN_CCTOR(server_value);
	} else {
		PHALCON_INIT_VAR(key);
		PHALCON_CONCAT_SV(key, "HTTP_", header);
		if (phalcon_array_isset(_SERVER, key)) {
			PHALCON_OBS_NVAR(server_value);
			phalcon_array_fetch(&server_value, _SERVER, key, PH_NOISY);
			RETURN_CCTOR(server_value);
		}
	}
	RETURN_MM_EMPTY_STRING();
}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getScheme){

	zval *https_header, *https;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(https_header);
	ZVAL_STRING(https_header, "HTTPS", 1);
	
	PHALCON_INIT_VAR(https);
	phalcon_call_method_p1(https, this_ptr, "getserver", https_header);
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
	zval *requested_with;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(requested_header);
	ZVAL_STRING(requested_header, "HTTP_X_REQUESTED_WITH", 1);
	
	PHALCON_INIT_VAR(xml_http_request);
	ZVAL_STRING(xml_http_request, "XMLHttpRequest", 1);
	
	PHALCON_INIT_VAR(requested_with);
	phalcon_call_method_p1(requested_with, this_ptr, "getheader", requested_header);
	is_equal_function(return_value, requested_with, xml_http_request TSRMLS_CC);
	RETURN_MM();
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested){

	zval *server = NULL, *_SERVER, *content_type;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_CPY_WRT(server, _SERVER);
	if (phalcon_array_isset_string(server, SS("HTTP_SOAPACTION"))) {
		RETURN_MM_TRUE;
	} else {
		if (phalcon_array_isset_string(server, SS("CONTENT_TYPE"))) {
	
			PHALCON_OBS_VAR(content_type);
			phalcon_array_fetch_string(&content_type, server, SL("CONTENT_TYPE"), PH_NOISY);
			if (phalcon_memnstr_str(content_type, SL("application/soap+xml"))) {
				RETURN_MM_TRUE;
			}
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest){

	zval *scheme, *https;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(scheme);
	phalcon_call_method(scheme, this_ptr, "getscheme");
	
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
	if (SG(request_info).raw_post_data) {
		RETURN_STRINGL(SG(request_info).raw_post_data, SG(request_info).raw_post_data_length, 1);
	}

	raw = phalcon_fetch_nproperty_this(getThis(), SL("_rawBody"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(raw) == IS_STRING) {
		if (return_value_ptr) {
			zval_ptr_dtor(return_value_ptr);
			*return_value_ptr = raw;
			Z_ADDREF_P(raw);
		}
		else {
			RETURN_ZVAL(raw, 1, 0);
		}
	}
	else if (sapi_module.read_post) {
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
	}
	else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Gets decoded JSON HTTP raw request body
 *
 * @param bool $assoc
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody){

	zval *raw_body, *assoc = NULL;
	int ac = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &assoc);

	if (assoc && zend_is_true(assoc)) {
		ac = 1;
	}

	PHALCON_INIT_VAR(raw_body);
	phalcon_call_method(raw_body, this_ptr, "getrawbody");
	if (Z_TYPE_P(raw_body) == IS_STRING) {
		phalcon_json_decode(return_value, return_value_ptr, raw_body, ac TSRMLS_CC);
		RETURN_MM();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets decoded BSON HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBsonRawBody){

	zval *raw_body;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(raw_body);
	phalcon_call_method(raw_body, this_ptr, "getrawbody");
	if (Z_TYPE_P(raw_body) == IS_STRING) {
		PHALCON_CALL_FUNCTION(return_value, return_value_ptr, "bson_decode", 1, raw_body);
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

	zval *server = NULL, *_SERVER, *server_addr, *localhost;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_CPY_WRT(server, _SERVER);
	if (phalcon_array_isset_string(server, SS("SERVER_ADDR"))) {
		PHALCON_OBS_VAR(server_addr);
		phalcon_array_fetch_string(&server_addr, server, SL("SERVER_ADDR"), PH_NOISY);
		RETURN_CCTOR(server_addr);
	}
	
	PHALCON_INIT_VAR(localhost);
	ZVAL_STRING(localhost, "localhost", 1);
	phalcon_call_func_p1(return_value, "gethostbyname", localhost);
	RETURN_MM();
}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerName){

	zval *server = NULL, *_SERVER, *server_name = NULL;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_CPY_WRT(server, _SERVER);
	if (phalcon_array_isset_string(server, SS("SERVER_NAME"))) {
		PHALCON_OBS_VAR(server_name);
		phalcon_array_fetch_string(&server_name, server, SL("SERVER_NAME"), PH_NOISY);
		RETURN_CCTOR(server_name);
	}
	
	RETVAL_STRING("localhost", 1);
	PHALCON_MM_RESTORE();
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost){

	zval *host, *http_host, *scheme, *server_name, *name;
	zval *server_port, *port, *http, *standard_port;
	zval *is_std_name, *is_std_port, *is_std_http;
	zval *https, *secure_port, *is_secure_scheme;
	zval *is_secure_port, *is_secure_http;

	PHALCON_MM_GROW();

	/** 
	 * Get the server name from _SERVER['HTTP_HOST']
	 */
	PHALCON_INIT_VAR(host);
	ZVAL_STRING(host, "HTTP_HOST", 1);
	
	PHALCON_INIT_VAR(http_host);
	phalcon_call_method_p1(http_host, this_ptr, "getserver", host);
	if (zend_is_true(http_host)) {
		RETURN_CCTOR(http_host);
	}
	
	/** 
	 * Get current scheme
	 */
	PHALCON_INIT_VAR(scheme);
	phalcon_call_method(scheme, this_ptr, "getscheme");
	
	/** 
	 * Get the server name from _SERVER['SERVER_NAME']
	 */
	PHALCON_INIT_VAR(server_name);
	ZVAL_STRING(server_name, "SERVER_NAME", 1);
	
	PHALCON_INIT_VAR(name);
	phalcon_call_method_p1(name, this_ptr, "getserver", server_name);
	
	/** 
	 * Get the server port from _SERVER['SERVER_PORT']
	 */
	PHALCON_INIT_VAR(server_port);
	ZVAL_STRING(server_port, "SERVER_PORT", 1);
	
	PHALCON_INIT_VAR(port);
	phalcon_call_method_p1(port, this_ptr, "getserver", server_port);
	
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
		RETURN_CCTOR(name);
	}
	
	/** 
	 * If is standard secure http we return the server name only
	 */
	if (PHALCON_IS_TRUE(is_secure_http)) {
		RETURN_CCTOR(name);
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
	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
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
			RETURN_CCTOR(first);
		}
	
		RETURN_CCTOR(address);
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

		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA);
		if (value && Z_TYPE_PP(value) == IS_STRING) {
			return Z_STRVAL_PP(value);
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

	zval **value, *_SERVER, key;

	INIT_ZVAL(key);
	ZVAL_STRING(&key, "REQUEST_URI", 0);

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), &key, BP_VAR_NA);
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

	zval *server = NULL, *_SERVER, *user_agent = NULL;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_CPY_WRT(server, _SERVER);
	if (phalcon_array_isset_string(server, SS("HTTP_USER_AGENT"))) {
		PHALCON_OBS_VAR(user_agent);
		phalcon_array_fetch_string(&user_agent, server, SL("HTTP_USER_AGENT"), PH_NOISY);
		RETURN_CCTOR(user_agent);
	}
	
	RETVAL_EMPTY_STRING();
	PHALCON_MM_RESTORE();
}

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array $methods
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isMethod){

	zval *methods, *http_method, *method = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &methods);
	
	PHALCON_INIT_VAR(http_method);
	phalcon_call_method(http_method, this_ptr, "getmethod");

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

	zval *post, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "POST"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(post);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(post, phalcon_interned_POST);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
	is_equal_function(return_value, method, post TSRMLS_CC);

	RETURN_MM();
}

/**
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet){

	zval *get, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "GET"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(get);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(get, phalcon_interned_GET);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
	is_equal_function(return_value, method, get TSRMLS_CC);

	RETURN_MM();
}

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut){

	zval *put, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "PUT"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(put);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(put, phalcon_interned_PUT);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
	is_equal_function(return_value, method, put TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is PATCH. if $_SERVER['REQUEST_METHOD']=='PATCH'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPatch){

	zval *patch, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "PATCH"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(patch);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(patch, phalcon_interned_PATCH);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
	is_equal_function(return_value, method, patch TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead){

	zval *head, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "HEAD"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(head);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(head, phalcon_interned_HEAD);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
	is_equal_function(return_value, method, head TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete){

	zval *delete, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "DELETE"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(delete);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(delete, phalcon_interned_DELETE);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
	is_equal_function(return_value, method, delete TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions){

	zval *options, *method;

	if (Z_OBJCE_P(getThis()) == phalcon_http_request_ce) {
		const char *method = phalcon_http_request_getmethod_helper(TSRMLS_C);
		RETURN_BOOL(!strcmp(method, "OPTIONS"));
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(options);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(options, phalcon_interned_OPTIONS);

	PHALCON_INIT_VAR(method);
	phalcon_call_method(method, this_ptr, "getmethod");
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
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int nfiles = 0;
	int only_successful;

	phalcon_fetch_params(0, 0, 1, &not_errored);
	
	only_successful = not_errored ? phalcon_get_intval(not_errored) : 1;
	
	phalcon_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	if (unlikely(Z_TYPE_P(_FILES) != IS_ARRAY)) {
		RETURN_LONG(0);
	}

	phalcon_is_iterable(_FILES, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		if (phalcon_array_isset_string(*hd, SS("error"))) {
			phalcon_array_fetch_string(&error, *hd, SL("error"), PH_NOISY);
			assert(Z_REFCOUNT_P(error) > 1);
			Z_DELREF_P(error);

			if (Z_TYPE_P(error) < IS_ARRAY) {
				if (!zend_is_true(error) || !only_successful) {
					++nfiles;
				}
			}
			else if (Z_TYPE_P(error) == IS_ARRAY) {
				nfiles += phalcon_http_request_hasfiles_helper(error, only_successful);
			}
		}

		zend_hash_move_forward_ex(ah0, &hp0);
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
			&& !EG(exception)
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

					ALLOC_INIT_ZVAL(arr);
					array_init_size(arr, 5);
					add_assoc_zval_ex(arr, ISS(name),      *dname);
					add_assoc_zval_ex(arr, ISS(type),      *dtype);
					add_assoc_zval_ex(arr, SS("tmp_name"), *dtmp);
					add_assoc_zval_ex(arr, SS("error"),    *derror);
					add_assoc_zval_ex(arr, SS("size"),     *dsize);

					ALLOC_INIT_ZVAL(key);
					ZVAL_STRINGL(key, prefix->c, prefix->len, 1);
					prefix->len = prefix_len;

					ALLOC_INIT_ZVAL(file);
					object_init_ex(file, phalcon_http_request_file_ce);

					res = phalcon_call_method_params(NULL, NULL, file, SL("__construct"), zend_inline_hash_func(SS("__construct")) TSRMLS_CC, 2, arr, key);

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

	zval *name = NULL, *type = NULL, *tmp_name = NULL, *error = NULL, *size = NULL;
	zval *not_errored = NULL, *_FILES, *request_file = NULL, *key = NULL;
	zval index;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int only_successful;
	smart_str prefix = { NULL, 0, 0 };

	phalcon_fetch_params(0, 0, 1, &not_errored);
	
	only_successful = not_errored ? phalcon_get_intval(not_errored) : 1;

	array_init(return_value);

	phalcon_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	if (Z_TYPE_P(_FILES) != IS_ARRAY || !zend_hash_num_elements(Z_ARRVAL_P(_FILES))) {
		return;
	}

	PHALCON_MM_GROW();
	phalcon_is_iterable(_FILES, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS && !EG(exception)) {

		if (phalcon_array_isset_string(*hd, SS("error"))) {
			PHALCON_OBS_NVAR(error);
			phalcon_array_fetch_string(&error, *hd, SL("error"), PH_NOISY);
			index = phalcon_get_current_key_w(ah0, &hp0);

			if (Z_TYPE_P(error) < IS_ARRAY) {
				if (!zend_is_true(error) || !only_successful) {
					PHALCON_INIT_NVAR(request_file);
					object_init_ex(request_file, phalcon_http_request_file_ce);

					PHALCON_INIT_NVAR(key);
					ZVAL_STRINGL(key, Z_STRVAL(index), Z_STRLEN(index), 1);

					Z_ADDREF_PP(hd);
					phalcon_call_method_p2_noret(request_file, "__construct", *hd, key);

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

		zend_hash_move_forward_ex(ah0, &hp0);
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

	zval *_SERVER, *key = NULL, *header = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	array_init(return_value);
	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (unlikely(Z_TYPE_P(_SERVER) != IS_ARRAY)) {
		return;
	}

	PHALCON_MM_GROW();
	
	phalcon_is_iterable(_SERVER, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
	
		if (phalcon_start_with_str(key, SL("HTTP_"))) {
			PHALCON_INIT_NVAR(header);
			phalcon_substr(header, key, 5, 0);
			phalcon_array_update_zval(&return_value, header, hd, PH_COPY);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer){

	zval *_SERVER, *http_referer;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string(_SERVER, SS("HTTP_REFERER"))) {
		PHALCON_OBS_VAR(http_referer);
		phalcon_array_fetch_string(&http_referer, _SERVER, SL("HTTP_REFERER"), PH_NOISY);
		RETURN_CCTOR(http_referer);
	}
	RETURN_MM_EMPTY_STRING();
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
	zval *http_server, *pattern, *parts, *part = NULL, *header_parts = NULL;
	zval *quality_part = NULL, *quality = NULL, *header_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &server_index, &name);
	
	PHALCON_INIT_VAR(quality_one);
	ZVAL_DOUBLE(quality_one, 1);
	
	array_init(return_value);
	
	PHALCON_INIT_VAR(http_server);
	phalcon_call_method_p1(http_server, this_ptr, "getserver", server_index);
	
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/,\\s*/", 1);
	PHALCON_INIT_VAR(parts);
	phalcon_call_func_p2(parts, "preg_split", pattern, http_server);
	
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
		phalcon_array_update_zval(&quality_part, name, &header_name, PH_COPY);
		phalcon_array_update_string(&quality_part, SL("quality"), &quality, PH_COPY);
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
	
	RETURN_CCTOR(selected_name);
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
	phalcon_call_method_p2(return_value, this_ptr, "_getqualityheader", accept_header, quality_index);
	RETURN_MM();
}

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept){

	zval *quality_index, *acceptable_content;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "accept", 1);
	
	PHALCON_INIT_VAR(acceptable_content);
	phalcon_call_method(acceptable_content, this_ptr, "getacceptablecontent");
	phalcon_call_method_p2(return_value, this_ptr, "_getbestquality", acceptable_content, quality_index);
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
	phalcon_call_method_p2(return_value, this_ptr, "_getqualityheader", charset_header, quality_index);
	RETURN_MM();
}

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset){

	zval *quality_index, *client_charsets;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "charset", 1);
	
	PHALCON_INIT_VAR(client_charsets);
	phalcon_call_method(client_charsets, this_ptr, "getclientcharsets");
	phalcon_call_method_p2(return_value, this_ptr, "_getbestquality", client_charsets, quality_index);
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
	phalcon_call_method_p2(return_value, this_ptr, "_getqualityheader", language_header, quality_index);
	RETURN_MM();
}

/**
 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage){

	zval *languages, *quality_index;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(languages);
	phalcon_call_method(languages, this_ptr, "getlanguages");
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "language", 1);
	phalcon_call_method_p2(return_value, this_ptr, "_getbestquality", languages, quality_index);
	RETURN_MM();
}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth){

	zval *_SERVER, *key;
	zval **value;
	char *auth_user = SG(request_info).auth_user;
	char *auth_password = SG(request_info).auth_password;

	PHALCON_MM_GROW();

	if (unlikely(!auth_user)) {
		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

		PHALCON_INIT_VAR(key);
		ZVAL_STRING(key, "PHP_AUTH_USER", 1);

		value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), key, BP_VAR_NA);
		if (value && Z_TYPE_PP(value) == IS_STRING) {
			auth_user = Z_STRVAL_PP(value);
		}

		zval_dtor(key);
		ZVAL_STRING(key, "PHP_AUTH_PW", 1);

		value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), key, BP_VAR_NA);
		if (value && Z_TYPE_PP(value) == IS_STRING) {
			auth_password = Z_STRVAL_PP(value);
		}
	}

	if (!auth_user) {
		RETURN_MM_NULL();
	}
	
	array_init_size(return_value, 2);

	phalcon_array_update_string_string(&return_value, SL("username"), auth_user, strlen(auth_user), 0);
	phalcon_array_update_string_string(&return_value, SL("password"), auth_password, strlen(auth_password), 0);

	PHALCON_MM_RESTORE();
}

/**
 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth){

	zval *_SERVER, *key, *digest, *pattern, *set_order, *matches, *match = NULL, *ret, *tmp1, *tmp2;
	zval **value;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	const char *auth_digest = SG(request_info).auth_digest;

	PHALCON_MM_GROW();

	if (unlikely(!auth_digest)) {
		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

		PHALCON_INIT_VAR(key);
		ZVAL_STRING(key, "PHP_AUTH_DIGEST", 1);

		value = phalcon_hash_get(Z_ARRVAL_P(_SERVER), key, BP_VAR_NA);
		if (value && Z_TYPE_PP(value) == IS_STRING) {
			auth_digest = Z_STRVAL_PP(value);
		}
	}

	if (auth_digest) {
		PHALCON_INIT_VAR(digest);
		ZVAL_STRING(digest, auth_digest, 1);

		PHALCON_INIT_VAR(pattern);
		ZVAL_STRING(pattern, "#(\\w+)=(['\"]?)([a-zA-Z0-9=.:/\\_-]+)\\2#", 1);

		PHALCON_INIT_VAR(set_order);
		ZVAL_LONG(set_order, 2);

		PHALCON_INIT_VAR(matches);
		PHALCON_INIT_VAR(ret);

		Z_SET_ISREF_P(matches);
		phalcon_call_func_p4(ret, "preg_match_all", pattern, digest, matches, set_order);
		Z_UNSET_ISREF_P(matches);

		if (zend_is_true(ret) && Z_TYPE_P(matches) == IS_ARRAY) {
			array_init(return_value);

			phalcon_is_iterable(matches, &ah0, &hp0, 0, 0);				
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HVALUE(match);

				if (Z_TYPE_P(match) == IS_ARRAY && phalcon_array_isset_long_fetch(&tmp1, match, 1) && phalcon_array_isset_long_fetch(&tmp2, match, 3)) {
					phalcon_array_update_zval(&return_value, tmp1, &tmp2, PH_COPY | PH_SEPARATE);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
			}

			RETURN_MM();
		}
	}

	RETURN_MM_NULL();
}


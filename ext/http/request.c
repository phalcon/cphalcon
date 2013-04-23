
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
	zend_declare_property_null(phalcon_http_request_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
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
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, get){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *request = NULL;
	zval *_REQUEST, *value, *filter = NULL, *dependency_injector;
	zval *service, *sanitized_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &name, &filters, &default_value) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!name) {
		PHALCON_INIT_VAR(name);
	}
	
	if (!filters) {
		PHALCON_INIT_VAR(filters);
	}
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	phalcon_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	PHALCON_CPY_WRT(request, _REQUEST);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(request, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, request, name, PH_NOISY_CC);
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
					ZVAL_STRING(service, "filter", 1);
	
					PHALCON_INIT_NVAR(filter);
					PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service);
					phalcon_update_property_zval(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_INIT_VAR(sanitized_value);
				PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", value, filters);
	
				RETURN_CCTOR(sanitized_value);
			} else {
				RETURN_CCTOR(value);
			}
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
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *post = NULL, *_POST;
	zval *value, *filter = NULL, *dependency_injector, *service;
	zval *sanitized_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &name, &filters, &default_value) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!name) {
		PHALCON_INIT_VAR(name);
	}
	
	if (!filters) {
		PHALCON_INIT_VAR(filters);
	}
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	phalcon_get_global(&_POST, SS("_POST") TSRMLS_CC);
	PHALCON_CPY_WRT(post, _POST);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(post, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, post, name, PH_NOISY_CC);
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
					ZVAL_STRING(service, "filter", 1);
	
					PHALCON_INIT_NVAR(filter);
					PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service);
					phalcon_update_property_zval(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_INIT_VAR(sanitized_value);
				PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", value, filters);
	
				RETURN_CCTOR(sanitized_value);
			} else {
				RETURN_CCTOR(value);
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
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery){

	zval *name = NULL, *filters = NULL, *default_value = NULL, *get = NULL, *_GET;
	zval *value, *filter = NULL, *dependency_injector, *service;
	zval *sanitized_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &name, &filters, &default_value) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!name) {
		PHALCON_INIT_VAR(name);
	}
	
	if (!filters) {
		PHALCON_INIT_VAR(filters);
	}
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	phalcon_get_global(&_GET, SS("_GET") TSRMLS_CC);
	PHALCON_CPY_WRT(get, _GET);
	if (Z_TYPE_P(name) != IS_NULL) {
		if (phalcon_array_isset(get, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, get, name, PH_NOISY_CC);
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
					ZVAL_STRING(service, "filter", 1);
	
					PHALCON_INIT_NVAR(filter);
					PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service);
					phalcon_update_property_zval(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_INIT_VAR(sanitized_value);
				PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", value, filters);
	
				RETURN_CCTOR(sanitized_value);
			} else {
				RETURN_CCTOR(value);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset(_SERVER, name)) {
		PHALCON_OBS_VAR(server_value);
		phalcon_array_fetch(&server_value, _SERVER, name, PH_NOISY_CC);
		RETURN_CCTOR(server_value);
	}
	RETURN_MM_NULL();
}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, has){

	zval *name, *_REQUEST;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(_REQUEST, name));
	RETURN_NCTOR(r0);
}

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasPost){

	zval *name, *_POST;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_get_global(&_POST, SS("_POST") TSRMLS_CC);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(_POST, name));
	RETURN_NCTOR(r0);
}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery){

	zval *name, *_GET;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_get_global(&_GET, SS("_GET") TSRMLS_CC);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(_GET, name));
	RETURN_NCTOR(r0);
}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, hasServer){

	zval *name, *_SERVER;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(_SERVER, name));
	RETURN_NCTOR(r0);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset(_SERVER, header)) {
		PHALCON_OBS_VAR(server_value);
		phalcon_array_fetch(&server_value, _SERVER, header, PH_NOISY_CC);
		RETURN_CCTOR(server_value);
	} else {
		PHALCON_INIT_VAR(key);
		PHALCON_CONCAT_SV(key, "HTTP_", header);
		if (phalcon_array_isset(_SERVER, key)) {
			PHALCON_OBS_NVAR(server_value);
			phalcon_array_fetch(&server_value, _SERVER, key, PH_NOISY_CC);
			RETURN_CCTOR(server_value);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_EMPTY_STRING();
}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getScheme){

	zval *https_header, *https, *scheme = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(https_header);
	ZVAL_STRING(https_header, "HTTPS", 1);
	
	PHALCON_INIT_VAR(https);
	PHALCON_CALL_METHOD_PARAMS_1(https, this_ptr, "getserver", https_header);
	if (zend_is_true(https)) {
		if (PHALCON_IS_STRING(https, "off")) {
			PHALCON_INIT_VAR(scheme);
			ZVAL_STRING(scheme, "http", 1);
		} else {
			PHALCON_INIT_NVAR(scheme);
			ZVAL_STRING(scheme, "https", 1);
		}
	} else {
		PHALCON_INIT_NVAR(scheme);
		ZVAL_STRING(scheme, "http", 1);
	}
	
	
	RETURN_CTOR(scheme);
}

/**
 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH']=='XMLHttpRequest'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isAjax){

	zval *requested_header, *xml_http_request;
	zval *requested_with, *is_ajax;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(requested_header);
	ZVAL_STRING(requested_header, "HTTP_X_REQUESTED_WITH", 1);
	
	PHALCON_INIT_VAR(xml_http_request);
	ZVAL_STRING(xml_http_request, "XMLHttpRequest", 1);
	
	PHALCON_INIT_VAR(requested_with);
	PHALCON_CALL_METHOD_PARAMS_1(requested_with, this_ptr, "getheader", requested_header);
	
	PHALCON_INIT_VAR(is_ajax);
	is_equal_function(is_ajax, requested_with, xml_http_request TSRMLS_CC);
	RETURN_NCTOR(is_ajax);
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
			phalcon_array_fetch_string(&content_type, server, SL("CONTENT_TYPE"), PH_NOISY_CC);
			if (phalcon_memnstr_str(content_type, SL("application/soap+xml") TSRMLS_CC)) {
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

	zval *scheme, *https, *is_equal;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(scheme);
	PHALCON_CALL_METHOD(scheme, this_ptr, "getscheme");
	
	PHALCON_INIT_VAR(https);
	ZVAL_STRING(https, "https", 1);
	
	PHALCON_INIT_VAR(is_equal);
	is_identical_function(is_equal, https, scheme TSRMLS_CC);
	RETURN_NCTOR(is_equal);
}

/**
 * Gets HTTP raw request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody){

	zval *raw_body, *input, *contents;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(raw_body);
	phalcon_read_property_this(&raw_body, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (!zend_is_true(raw_body)) {
		PHALCON_INIT_VAR(input);
		ZVAL_STRING(input, "php://input", 1);
	
		PHALCON_INIT_VAR(contents);
		PHALCON_CALL_FUNC_PARAMS_1(contents, "file_get_contents", input);
	
		/** 
		 * We need store the read raw body because it can be read again
		 */
		phalcon_update_property_zval(this_ptr, SL("_rawBody"), contents TSRMLS_CC);
		RETURN_CCTOR(contents);
	}
	
	
	RETURN_CCTOR(raw_body);
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress){

	zval *server = NULL, *_SERVER, *server_addr = NULL, *localhost;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_CPY_WRT(server, _SERVER);
	if (phalcon_array_isset_string(server, SS("SERVER_ADDR"))) {
		PHALCON_OBS_VAR(server_addr);
		phalcon_array_fetch_string(&server_addr, server, SL("SERVER_ADDR"), PH_NOISY_CC);
		RETURN_CCTOR(server_addr);
	}
	
	PHALCON_INIT_VAR(localhost);
	ZVAL_STRING(localhost, "localhost", 1);
	
	PHALCON_INIT_NVAR(server_addr);
	PHALCON_CALL_FUNC_PARAMS_1(server_addr, "gethostbyname", localhost);
	
	RETURN_CCTOR(server_addr);
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
		phalcon_array_fetch_string(&server_name, server, SL("SERVER_NAME"), PH_NOISY_CC);
		RETURN_CCTOR(server_name);
	}
	
	PHALCON_INIT_NVAR(server_name);
	ZVAL_STRING(server_name, "localhost", 1);
	
	RETURN_CCTOR(server_name);
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost){

	zval *host, *http_host = NULL, *scheme, *server_name, *name;
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
	PHALCON_CALL_METHOD_PARAMS_1(http_host, this_ptr, "getserver", host);
	if (zend_is_true(http_host)) {
		RETURN_CCTOR(http_host);
	}
	
	/** 
	 * Get current scheme
	 */
	PHALCON_INIT_VAR(scheme);
	PHALCON_CALL_METHOD(scheme, this_ptr, "getscheme");
	
	/** 
	 * Get the server name from _SERVER['SERVER_NAME']
	 */
	PHALCON_INIT_VAR(server_name);
	ZVAL_STRING(server_name, "SERVER_NAME", 1);
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD_PARAMS_1(name, this_ptr, "getserver", server_name);
	
	/** 
	 * Get the server port from _SERVER['SERVER_PORT']
	 */
	PHALCON_INIT_VAR(server_port);
	ZVAL_STRING(server_port, "SERVER_PORT", 1);
	
	PHALCON_INIT_VAR(port);
	PHALCON_CALL_METHOD_PARAMS_1(port, this_ptr, "getserver", server_port);
	
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
	
	PHALCON_INIT_NVAR(http_host);
	PHALCON_CONCAT_VSV(http_host, name, ":", port);
	
	RETURN_CCTOR(http_host);
}

/**
 * Gets most possible client IPv4 Address. This method search in $_SERVER['REMOTE_ADDR'] and optionally in $_SERVER['HTTP_X_FORWARDED_FOR']
 *
 * @param boolean $trustForwardedHeader
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress){

	zval *trust_forwarded_header = NULL, *address = NULL, *_SERVER;
	zval *comma, *addresses, *first;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &trust_forwarded_header) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!trust_forwarded_header) {
		PHALCON_INIT_VAR(trust_forwarded_header);
		ZVAL_BOOL(trust_forwarded_header, 0);
	}
	
	PHALCON_INIT_VAR(address);
	
	/** 
	 * Proxies uses this IP
	 */
	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (phalcon_array_isset_string(_SERVER, SS("HTTP_X_FORWARDED_FOR"))) {
		if (zend_is_true(trust_forwarded_header)) {
			PHALCON_OBS_NVAR(address);
			phalcon_array_fetch_string(&address, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY_CC);
		}
	}
	
	if (Z_TYPE_P(address) == IS_NULL) {
		if (phalcon_array_isset_string(_SERVER, SS("REMOTE_ADDR"))) {
			PHALCON_OBS_NVAR(address);
			phalcon_array_fetch_string(&address, _SERVER, SL("REMOTE_ADDR"), PH_NOISY_CC);
		}
	}
	
	if (Z_TYPE_P(address) == IS_STRING) {
		if (phalcon_memnstr_str(address, SL(",") TSRMLS_CC)) {
			/** 
			 * The client address has multiples parts, only return the first part
			 */
			PHALCON_INIT_VAR(comma);
			ZVAL_STRING(comma, ",", 1);
	
			PHALCON_INIT_VAR(addresses);
			phalcon_fast_explode(addresses, comma, address TSRMLS_CC);
	
			PHALCON_OBS_VAR(first);
			phalcon_array_fetch_long(&first, addresses, 0, PH_NOISY_CC);
			RETURN_CCTOR(first);
		}
	
		RETURN_CCTOR(address);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getMethod){

	zval *server = NULL, *_SERVER, *request_method = NULL;

	PHALCON_MM_GROW();

	phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	PHALCON_CPY_WRT(server, _SERVER);
	if (phalcon_array_isset_string(server, SS("REQUEST_METHOD"))) {
		PHALCON_OBS_VAR(request_method);
		phalcon_array_fetch_string(&request_method, server, SL("REQUEST_METHOD"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(request_method);
		ZVAL_STRING(request_method, "", 1);
	}
	
	
	RETURN_CCTOR(request_method);
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
		phalcon_array_fetch_string(&user_agent, server, SL("HTTP_USER_AGENT"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(user_agent);
		ZVAL_STRING(user_agent, "", 1);
	}
	
	
	RETURN_CCTOR(user_agent);
}

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array $methods
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isMethod){

	zval *methods, *http_method, *is_equals, *method = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &methods) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(http_method);
	PHALCON_CALL_METHOD(http_method, this_ptr, "getmethod");
	if (Z_TYPE_P(methods) == IS_STRING) {
		PHALCON_INIT_VAR(is_equals);
		is_equal_function(is_equals, methods, http_method TSRMLS_CC);
		RETURN_NCTOR(is_equals);
	} else {
	
		if (!phalcon_is_iterable(methods, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(method);
	
			if (PHALCON_IS_EQUAL(method, http_method)) {
				RETURN_MM_TRUE;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPost){

	zval *post, *method, *is_post;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(post);
	ZVAL_STRING(post, "POST", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_post);
	is_equal_function(is_post, method, post TSRMLS_CC);
	RETURN_NCTOR(is_post);
}

/**
 *
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet){

	zval *get, *method, *is_get;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(get);
	ZVAL_STRING(get, "GET", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_get);
	is_equal_function(is_get, method, get TSRMLS_CC);
	RETURN_NCTOR(is_get);
}

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut){

	zval *put, *method, *is_put;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(put);
	ZVAL_STRING(put, "PUT", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_put);
	is_equal_function(is_put, method, put TSRMLS_CC);
	RETURN_NCTOR(is_put);
}

/**
 * Checks whether HTTP method is PATCH. if $_SERVER['REQUEST_METHOD']=='PATCH'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPatch){

	zval *patch, *method, *is_patch;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(patch);
	ZVAL_STRING(patch, "PATCH", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_patch);
	is_equal_function(is_patch, method, patch TSRMLS_CC);
	RETURN_NCTOR(is_patch);
}

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead){

	zval *head, *method, *is_head;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(head);
	ZVAL_STRING(head, "HEAD", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_head);
	is_equal_function(is_head, method, head TSRMLS_CC);
	RETURN_NCTOR(is_head);
}

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete){

	zval *delete, *method, *is_delete;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(delete);
	ZVAL_STRING(delete, "DELETE", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_delete);
	is_equal_function(is_delete, method, delete TSRMLS_CC);
	RETURN_NCTOR(is_delete);
}

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions){

	zval *options, *method, *is_options;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(options);
	ZVAL_STRING(options, "OPTIONS", 1);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod");
	
	PHALCON_INIT_VAR(is_options);
	is_equal_function(is_options, method, options TSRMLS_CC);
	RETURN_NCTOR(is_options);
}

/**
 * Checks whether request include attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles){

	zval *not_errored = NULL, *files = NULL, *_FILES, *zero, *number_files = NULL;
	zval *file = NULL, *error = NULL, *has_files;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &not_errored) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!not_errored) {
		PHALCON_INIT_VAR(not_errored);
		ZVAL_BOOL(not_errored, 0);
	}
	
	phalcon_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	PHALCON_CPY_WRT(files, _FILES);
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	if (zend_is_true(not_errored)) {
		PHALCON_INIT_VAR(number_files);
		phalcon_fast_count(number_files, _FILES TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(number_files);
		ZVAL_LONG(number_files, 0);
	
		if (!phalcon_is_iterable(files, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(file);
	
			if (phalcon_array_isset_string(file, SS("error"))) {
				PHALCON_OBS_NVAR(error);
				phalcon_array_fetch_string(&error, file, SL("error"), PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(error);
				ZVAL_BOOL(error, 1);
			}
			if (!zend_is_true(error)) {
				PHALCON_SEPARATE(number_files);
				increment_function(number_files);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_INIT_VAR(has_files);
	is_smaller_function(has_files, zero, number_files TSRMLS_CC);
	
	RETURN_NCTOR(has_files);
}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @param boolean $notErrored
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles){

	zval *not_errored = NULL, *super_files = NULL, *_FILES, *files;
	zval *file = NULL, *error = NULL, *request_file = NULL, *empty_files;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &not_errored) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!not_errored) {
		PHALCON_INIT_VAR(not_errored);
		ZVAL_BOOL(not_errored, 0);
	}
	
	phalcon_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	PHALCON_CPY_WRT(super_files, _FILES);
	if (phalcon_fast_count_ev(super_files TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(files);
		array_init(files);
	
		if (!phalcon_is_iterable(super_files, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(file);
	
			if (zend_is_true(not_errored)) {
				if (phalcon_array_isset_string(file, SS("error"))) {
					PHALCON_OBS_NVAR(error);
					phalcon_array_fetch_string(&error, file, SL("error"), PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(error);
					ZVAL_BOOL(error, 1);
				}
				if (!zend_is_true(error)) {
					PHALCON_INIT_NVAR(request_file);
					object_init_ex(request_file, phalcon_http_request_file_ce);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(request_file, "__construct", file);
	
					phalcon_array_append(&files, request_file, PH_SEPARATE TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_NVAR(request_file);
				object_init_ex(request_file, phalcon_http_request_file_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(request_file, "__construct", file);
	
				phalcon_array_append(&files, request_file, PH_SEPARATE TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	
		RETURN_CTOR(files);
	}
	
	PHALCON_INIT_VAR(empty_files);
	array_init(empty_files);
	
	RETURN_CTOR(empty_files);
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
		phalcon_array_fetch_string(&http_referer, _SERVER, SL("HTTP_REFERER"), PH_NOISY_CC);
		RETURN_CCTOR(http_referer);
	}
	PHALCON_MM_RESTORE();
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

	zval *server_index, *name, *quality_one, *returned_parts;
	zval *http_server, *pattern, *parts, *dot_comma;
	zval *part = NULL, *header_parts = NULL, *quality_part = NULL, *quality = NULL;
	zval *header_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &server_index, &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(quality_one);
	ZVAL_DOUBLE(quality_one, 1);
	
	PHALCON_INIT_VAR(returned_parts);
	array_init(returned_parts);
	
	PHALCON_INIT_VAR(http_server);
	PHALCON_CALL_METHOD_PARAMS_1(http_server, this_ptr, "getserver", server_index);
	
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/,\\s*/", 1);
	PHALCON_INIT_VAR(parts);
	PHALCON_CALL_FUNC_PARAMS_2(parts, "preg_split", pattern, http_server);
	
	PHALCON_INIT_VAR(dot_comma);
	ZVAL_STRING(dot_comma, ";", 1);
	
	if (!phalcon_is_iterable(parts, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(part);
	
		PHALCON_INIT_NVAR(header_parts);
		phalcon_fast_explode(header_parts, dot_comma, part TSRMLS_CC);
		if (phalcon_array_isset_long(header_parts, 1)) {
			PHALCON_OBS_NVAR(quality_part);
			phalcon_array_fetch_long(&quality_part, header_parts, 1, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(quality);
			phalcon_substr(quality, quality_part, 2, 0 TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(quality, quality_one);
		}
	
		PHALCON_OBS_NVAR(header_name);
		phalcon_array_fetch_long(&header_name, header_parts, 0, PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(quality_part);
		array_init_size(quality_part, 2);
		phalcon_array_update_zval(&quality_part, name, &header_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&quality_part, SL("quality"), &quality, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&returned_parts, quality_part, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(returned_parts);
}

/**
 * Process a request header and return the one with best quality
 *
 * @param array $qualityParts
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality){

	zval *quality_parts, *name, *i, *quality = NULL, *selected_name = NULL;
	zval *accept = NULL, *accept_quality = NULL, *best_quality = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &quality_parts, &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	
	PHALCON_INIT_VAR(quality);
	ZVAL_LONG(quality, 0);
	
	PHALCON_INIT_VAR(selected_name);
	ZVAL_STRING(selected_name, "", 1);
	
	if (!phalcon_is_iterable(quality_parts, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(accept);
	
		if (PHALCON_IS_LONG(i, 0)) {
			PHALCON_OBS_NVAR(quality);
			phalcon_array_fetch_string(&quality, accept, SL("quality"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(selected_name);
			phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
		} else {
			PHALCON_OBS_NVAR(accept_quality);
			phalcon_array_fetch_string(&accept_quality, accept, SL("quality"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(best_quality);
			is_smaller_function(best_quality, quality, accept_quality TSRMLS_CC);
			if (PHALCON_IS_TRUE(best_quality)) {
				PHALCON_CPY_WRT(quality, accept_quality);
	
				PHALCON_OBS_NVAR(selected_name);
				phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
			}
		}
		PHALCON_SEPARATE(i);
		increment_function(i);
	
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

	zval *accept_header, *quality_index, *quality_header;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(accept_header);
	ZVAL_STRING(accept_header, "HTTP_ACCEPT", 1);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "accept", 1);
	
	PHALCON_INIT_VAR(quality_header);
	PHALCON_CALL_METHOD_PARAMS_2(quality_header, this_ptr, "_getqualityheader", accept_header, quality_index);
	RETURN_CCTOR(quality_header);
}

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept){

	zval *quality_index, *acceptable_content;
	zval *best_quality;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "accept", 1);
	
	PHALCON_INIT_VAR(acceptable_content);
	PHALCON_CALL_METHOD(acceptable_content, this_ptr, "getacceptablecontent");
	
	PHALCON_INIT_VAR(best_quality);
	PHALCON_CALL_METHOD_PARAMS_2(best_quality, this_ptr, "_getbestquality", acceptable_content, quality_index);
	RETURN_CCTOR(best_quality);
}

/**
 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets){

	zval *charset_header, *quality_index, *quality_charset;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(charset_header);
	ZVAL_STRING(charset_header, "HTTP_ACCEPT_CHARSET", 1);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "charset", 1);
	
	PHALCON_INIT_VAR(quality_charset);
	PHALCON_CALL_METHOD_PARAMS_2(quality_charset, this_ptr, "_getqualityheader", charset_header, quality_index);
	RETURN_CCTOR(quality_charset);
}

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset){

	zval *quality_index, *client_charsets, *best_charset;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "charset", 1);
	
	PHALCON_INIT_VAR(client_charsets);
	PHALCON_CALL_METHOD(client_charsets, this_ptr, "getclientcharsets");
	
	PHALCON_INIT_VAR(best_charset);
	PHALCON_CALL_METHOD_PARAMS_2(best_charset, this_ptr, "_getbestquality", client_charsets, quality_index);
	RETURN_CCTOR(best_charset);
}

/**
 * Gets languages array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages){

	zval *language_header, *quality_index, *languages;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(language_header);
	ZVAL_STRING(language_header, "HTTP_ACCEPT_LANGUAGE", 1);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "language", 1);
	
	PHALCON_INIT_VAR(languages);
	PHALCON_CALL_METHOD_PARAMS_2(languages, this_ptr, "_getqualityheader", language_header, quality_index);
	RETURN_CCTOR(languages);
}

/**
 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage){

	zval *languages, *quality_index, *best_language;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(languages);
	PHALCON_CALL_METHOD(languages, this_ptr, "getlanguages");
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "language", 1);
	
	PHALCON_INIT_VAR(best_language);
	PHALCON_CALL_METHOD_PARAMS_2(best_language, this_ptr, "_getbestquality", languages, quality_index);
	RETURN_CCTOR(best_language);
}


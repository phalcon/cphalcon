
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
 * </code>
 *
 */

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
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
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Http_Request, getDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Gets variable from $_POST superglobal applying filters if needed
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
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost){

	zval *name, *filters = NULL, *value, *dependency_injector;
	zval *service, *filter, *sanitized_value;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!filters) {
		PHALCON_INIT_NVAR(filters);
	}
	
	phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch(&value, g0, name, PH_NOISY_CC);
		if (Z_TYPE_P(filters) != IS_NULL) {
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
				return;
			}
			
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "filter", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(sanitized_value);
			PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", value, filters, PH_NO_CHECK);
			
			RETURN_CCTOR(sanitized_value);
		} else {
			
			RETURN_CCTOR(value);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 *
 *<code>
 *	//Returns value from $_GET["id"] without sanitizing
 *	$id = $request->getQuery("id");
 *
 *	//Returns value from $_GET["id"] with sanitizing
 *	$id = $request->getQuery("id", "int");
 *</code>
 *
 * @param string $name
 * @param string|array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery){

	zval *name, *filters = NULL, *value, *dependency_injector;
	zval *service, *filter, *sanitized_value;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!filters) {
		PHALCON_INIT_NVAR(filters);
	}
	
	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch(&value, g0, name, PH_NOISY_CC);
		if (Z_TYPE_P(filters) != IS_NULL) {
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
				return;
			}
			
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "filter", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(sanitized_value);
			PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", value, filters, PH_NO_CHECK);
			
			RETURN_CCTOR(sanitized_value);
		} else {
			
			RETURN_CCTOR(value);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getServer){

	zval *name, *server_value;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	if (eval_int) {
		PHALCON_INIT_VAR(server_value);
		phalcon_array_fetch(&server_value, g0, name, PH_NOISY_CC);
		
		RETURN_CCTOR(server_value);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasPost){

	zval *name;
	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery){

	zval *name;
	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, hasServer){

	zval *name;
	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

/**
 * Gets HTTP header from request data
 *
 * @param string $header
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHeader){

	zval *header, *server_value = NULL, *key;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, header);
	if (eval_int) {
		PHALCON_INIT_VAR(server_value);
		phalcon_array_fetch(&server_value, g0, header, PH_NOISY_CC);
		
		RETURN_CCTOR(server_value);
	} else {
		PHALCON_INIT_VAR(key);
		PHALCON_CONCAT_SV(key, "HTTP_", header);
		eval_int = phalcon_array_isset(g0, key);
		if (eval_int) {
			PHALCON_INIT_NVAR(server_value);
			phalcon_array_fetch(&server_value, g0, key, PH_NOISY_CC);
			
			RETURN_CCTOR(server_value);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_STRING("", 1);
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
	ZVAL_STRING(https_header, "HTTP_HTTPS", 1);
	
	PHALCON_INIT_VAR(https);
	PHALCON_CALL_METHOD_PARAMS_1(https, this_ptr, "getserver", https_header, PH_NO_CHECK);
	if (PHALCON_COMPARE_STRING(https, "on")) {
		PHALCON_INIT_VAR(scheme);
		ZVAL_STRING(scheme, "https", 1);
	} else {
		PHALCON_INIT_NVAR(scheme);
		ZVAL_STRING(scheme, "http", 1);
	}
	
	
	RETURN_CTOR(scheme);
}

/**
 * Checks whether request has been made using ajax
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isAjax){

	zval *requested_header, *requested_with, *is_ajax;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(requested_header);
	ZVAL_STRING(requested_header, "HTTP_X_REQUESTED_WITH", 1);
	
	PHALCON_INIT_VAR(requested_with);
	PHALCON_CALL_METHOD_PARAMS_1(requested_with, this_ptr, "getheader", requested_header, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	
	PHALCON_INIT_VAR(is_ajax);
	is_equal_function(is_ajax, requested_with, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_ajax);
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested){

	zval *server = NULL, *content_type, *position, *have_content_type;
	zval *g0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SS("HTTP_SOAPACTION"));
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		eval_int = phalcon_array_isset_string(server, SS("CONTENT_TYPE"));
		if (eval_int) {
			PHALCON_INIT_VAR(content_type);
			phalcon_array_fetch_string(&content_type, server, SL("CONTENT_TYPE"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(position);
			phalcon_fast_strpos_str(position, content_type, SL("application/soap+xml") TSRMLS_CC);
			
			PHALCON_INIT_VAR(t0);
			ZVAL_BOOL(t0, 0);
			
			PHALCON_INIT_VAR(have_content_type);
			is_not_identical_function(have_content_type, t0, position TSRMLS_CC);
			
			RETURN_NCTOR(have_content_type);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest){

	zval *scheme, *is_equal;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(scheme);
	PHALCON_CALL_METHOD(scheme, this_ptr, "getscheme", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "https", 1);
	
	PHALCON_INIT_VAR(is_equal);
	is_identical_function(is_equal, t0, scheme TSRMLS_CC);
	
	RETURN_NCTOR(is_equal);
}

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody){

	zval *input, *contents;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(input);
	ZVAL_STRING(input, "php://input", 1);
	
	PHALCON_INIT_VAR(contents);
	PHALCON_CALL_FUNC_PARAMS_1(contents, "file_get_contents", input);
	
	RETURN_CCTOR(contents);
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress){

	zval *server = NULL, *server_addr = NULL, *localhost;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SS("SERVER_ADDR"));
	if (eval_int) {
		PHALCON_INIT_VAR(server_addr);
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

	zval *server = NULL, *server_name = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SS("SERVER_NAME"));
	if (eval_int) {
		PHALCON_INIT_VAR(server_name);
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

	zval *scheme, *server_name, *name, *server_port;
	zval *port, *is_std_http, *is_secure_http, *is_http_normal;
	zval *name_port;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(scheme);
	PHALCON_CALL_METHOD(scheme, this_ptr, "getscheme", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(server_name);
	ZVAL_STRING(server_name, "HTTP_SERVER_NAME", 1);
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD_PARAMS_1(name, this_ptr, "getserver", server_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(server_port);
	ZVAL_STRING(server_port, "HTTP_SERVER_PORT", 1);
	
	PHALCON_INIT_VAR(port);
	PHALCON_CALL_METHOD_PARAMS_1(port, this_ptr, "getserver", server_port, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "http", 1);
	
	PHALCON_INIT_VAR(r0);
	is_equal_function(r0, scheme, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 80);
	
	PHALCON_INIT_VAR(r1);
	is_equal_function(r1, port, t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_std_http);
	phalcon_and_function(is_std_http, r0, r1);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "https", 1);
	
	PHALCON_INIT_VAR(r2);
	is_equal_function(r2, scheme, t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 443);
	
	PHALCON_INIT_VAR(r3);
	is_equal_function(r3, port, t3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_secure_http);
	phalcon_and_function(is_secure_http, r2, r3);
	
	PHALCON_INIT_VAR(is_http_normal);
	ZVAL_BOOL(is_http_normal, zend_is_true(is_std_http) || zend_is_true(is_secure_http));
	if (PHALCON_IS_TRUE(is_http_normal)) {
		
		RETURN_CCTOR(name);
	}
	
	PHALCON_INIT_VAR(name_port);
	PHALCON_CONCAT_VSV(name_port, name, ":", port);
	
	RETURN_CTOR(name_port);
}

/**
 * Gets most possibly client IPv4 Address. This methods search in $_SERVER['HTTP_X_FORWARDED_FOR'] and $_SERVER['REMOTE_ADDR']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress){

	zval *address = NULL, *server = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(address);
	ZVAL_STRING(address, "", 1);
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SS("HTTP_X_FORWARDED_FOR"));
	if (eval_int) {
		PHALCON_INIT_NVAR(address);
		phalcon_array_fetch_string(&address, server, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(server, SS("REMOTE_ADDR"));
		if (eval_int) {
			PHALCON_INIT_NVAR(address);
			phalcon_array_fetch_string(&address, server, SL("REMOTE_ADDR"), PH_NOISY_CC);
		}
	}
	
	
	RETURN_CCTOR(address);
}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getMethod){

	zval *server = NULL, *request_method = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SS("REQUEST_METHOD"));
	if (eval_int) {
		PHALCON_INIT_VAR(request_method);
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

	zval *server = NULL, *user_agent = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SS("HTTP_USER_AGENT"));
	if (eval_int) {
		PHALCON_INIT_VAR(user_agent);
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
 */
PHP_METHOD(Phalcon_Http_Request, isMethod){

	zval *methods, *http_method, *is_equals = NULL, *method = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &methods) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(http_method);
	PHALCON_CALL_METHOD(http_method, this_ptr, "getmethod", PH_NO_CHECK);
	if (Z_TYPE_P(methods) == IS_STRING) {
		PHALCON_INIT_VAR(is_equals);
		is_equal_function(is_equals, methods, http_method TSRMLS_CC);
		
		RETURN_NCTOR(is_equals);
	} else {
		
		if (!phalcon_valid_foreach(methods TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(methods);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(method);
			
			PHALCON_INIT_NVAR(is_equals);
			is_equal_function(is_equals, method, http_method TSRMLS_CC);
			if (PHALCON_IS_TRUE(is_equals)) {
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPost){

	zval *method, *is_post;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "POST", 1);
	
	PHALCON_INIT_VAR(is_post);
	is_equal_function(is_post, method, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_post);
}

/**
 *
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet){

	zval *method, *is_get;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "GET", 1);
	
	PHALCON_INIT_VAR(is_get);
	is_equal_function(is_get, method, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_get);
}

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut){

	zval *method, *is_put;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "PUT", 1);
	
	PHALCON_INIT_VAR(is_put);
	is_equal_function(is_put, method, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_put);
}

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead){

	zval *method, *is_head;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "HEAD", 1);
	
	PHALCON_INIT_VAR(is_head);
	is_equal_function(is_head, method, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_head);
}

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete){

	zval *method, *is_delete;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "DELETE", 1);
	
	PHALCON_INIT_VAR(is_delete);
	is_equal_function(is_delete, method, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_delete);
}

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions){

	zval *method, *is_options;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(method);
	PHALCON_CALL_METHOD(method, this_ptr, "getmethod", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "OPTIONS", 1);
	
	PHALCON_INIT_VAR(is_options);
	is_equal_function(is_options, method, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_options);
}

/**
 * Checks whether request include attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles){

	zval *files = NULL, *number_files, *has_files;
	zval *g0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_FILES")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(files, g0);
	
	PHALCON_INIT_VAR(number_files);
	phalcon_fast_count(number_files, g0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	
	PHALCON_INIT_VAR(has_files);
	is_smaller_function(has_files, t0, number_files TSRMLS_CC);
	
	RETURN_NCTOR(has_files);
}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles){

	zval *super_files = NULL, *number_files, *files, *file = NULL;
	zval *request_file = NULL, *empty_files;
	zval *g0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_FILES")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(super_files, g0);
	
	PHALCON_INIT_VAR(number_files);
	phalcon_fast_count(number_files, super_files TSRMLS_CC);
	if (zend_is_true(number_files)) {
		PHALCON_INIT_VAR(files);
		array_init(files);
		
		if (!phalcon_valid_foreach(super_files TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(super_files);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(file);
			
			PHALCON_INIT_NVAR(request_file);
			object_init_ex(request_file, phalcon_http_request_file_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(request_file, "__construct", file, PH_CHECK);
			phalcon_array_append(&files, request_file, PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		
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

	zval *http_referer;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SS("HTTP_REFERER"));
	if (eval_int) {
		PHALCON_INIT_VAR(http_referer);
		phalcon_array_fetch_string(&http_referer, g0, SL("HTTP_REFERER"), PH_NOISY_CC);
		
		RETURN_CCTOR(http_referer);
	}
	PHALCON_MM_RESTORE();
	RETURN_STRING("", 1);
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
	zval *http_server, *pattern, *parts, *two, *dot_comma;
	zval *part = NULL, *header_parts = NULL, *quality_part = NULL, *quality = NULL;
	zval *header_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &server_index, &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(quality_one);
	ZVAL_DOUBLE(quality_one, 1);
	
	PHALCON_INIT_VAR(returned_parts);
	array_init(returned_parts);
	
	PHALCON_INIT_VAR(http_server);
	PHALCON_CALL_METHOD_PARAMS_1(http_server, this_ptr, "getserver", server_index, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/,\\s*/", 1);
	
	PHALCON_INIT_VAR(parts);
	PHALCON_CALL_FUNC_PARAMS_2(parts, "preg_split", pattern, http_server);
	
	PHALCON_INIT_VAR(two);
	ZVAL_LONG(two, 2);
	
	PHALCON_INIT_VAR(dot_comma);
	ZVAL_STRING(dot_comma, ";", 1);
	
	if (!phalcon_valid_foreach(parts TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(parts);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(part);
		
		PHALCON_INIT_NVAR(header_parts);
		phalcon_fast_explode(header_parts, dot_comma, part TSRMLS_CC);
		eval_int = phalcon_array_isset_long(header_parts, 1);
		if (eval_int) {
			PHALCON_INIT_NVAR(quality_part);
			phalcon_array_fetch_long(&quality_part, header_parts, 1, PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(quality);
			PHALCON_CALL_FUNC_PARAMS_2(quality, "substr", quality_part, two);
		} else {
			PHALCON_CPY_WRT(quality, quality_one);
		}
		
		PHALCON_INIT_NVAR(header_name);
		phalcon_array_fetch_long(&header_name, header_parts, 0, PH_NOISY_CC);
		
		PHALCON_INIT_NVAR(quality_part);
		array_init(quality_part);
		phalcon_array_update_zval(&quality_part, name, &header_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&quality_part, SL("quality"), &quality, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&returned_parts, quality_part, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	
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
	zval *accept = NULL, *accept_quality = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &quality_parts, &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	
	PHALCON_INIT_VAR(quality);
	ZVAL_LONG(quality, 0);
	
	PHALCON_INIT_VAR(selected_name);
	ZVAL_STRING(selected_name, "", 1);
	
	if (!phalcon_valid_foreach(quality_parts TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(quality_parts);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(accept);
		
		if (phalcon_compare_strict_long(i, 0 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(quality);
			phalcon_array_fetch_string(&quality, accept, SL("quality"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(selected_name);
			phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(accept_quality);
			phalcon_array_fetch_string(&accept_quality, accept, SL("quality"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(r0);
			is_smaller_function(r0, quality, accept_quality TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_CPY_WRT(quality, accept_quality);
				
				PHALCON_INIT_NVAR(selected_name);
				phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
			}
		}
		PHALCON_SEPARATE(i);
		increment_function(i);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	
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
	PHALCON_CALL_METHOD_PARAMS_2(quality_header, this_ptr, "_getqualityheader", accept_header, quality_index, PH_NO_CHECK);
	
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
	PHALCON_CALL_METHOD(acceptable_content, this_ptr, "getacceptablecontent", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(best_quality);
	PHALCON_CALL_METHOD_PARAMS_2(best_quality, this_ptr, "_getbestquality", acceptable_content, quality_index, PH_NO_CHECK);
	
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
	PHALCON_CALL_METHOD_PARAMS_2(quality_charset, this_ptr, "_getqualityheader", charset_header, quality_index, PH_NO_CHECK);
	
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
	PHALCON_CALL_METHOD(client_charsets, this_ptr, "getclientcharsets", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(best_charset);
	PHALCON_CALL_METHOD_PARAMS_2(best_charset, this_ptr, "_getbestquality", client_charsets, quality_index, PH_NO_CHECK);
	
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
	PHALCON_CALL_METHOD_PARAMS_2(languages, this_ptr, "_getqualityheader", language_header, quality_index, PH_NO_CHECK);
	
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
	PHALCON_CALL_METHOD(languages, this_ptr, "getlanguages", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(quality_index);
	ZVAL_STRING(quality_index, "language", 1);
	
	PHALCON_INIT_VAR(best_language);
	PHALCON_CALL_METHOD_PARAMS_2(best_language, this_ptr, "_getbestquality", languages, quality_index, PH_NO_CHECK);
	
	RETURN_CCTOR(best_language);
}


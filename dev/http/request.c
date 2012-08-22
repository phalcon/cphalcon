
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

/**
 * Phalcon\Http\Request
 *
 * Encapsulates request information for easy and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
 *
 * 
 *
 * @see http://phalconphp.com/documentation/request
 */

PHP_METHOD(Phalcon_Http_Request, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Http_Request, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Gets variable from $_POST superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getPost){

	zval *name = NULL, *filters = NULL, *value = NULL, *dependency_injector = NULL;
	zval *filter = NULL, *sanitized_value = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!filters) {
		PHALCON_ALLOC_ZVAL_MM(filters);
		ZVAL_NULL(filters);
	}
	
	phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch(&value, g0, name, PH_NOISY_CC);
		if (zend_is_true(filters)) {
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (!zend_is_true(dependency_injector)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
				return;
			}
			
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "filter", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", c0, PH_NO_CHECK);
			
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
 * @param string $name
 * @param string|array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request, getQuery){

	zval *name = NULL, *filters = NULL, *value = NULL, *dependency_injector = NULL;
	zval *filter = NULL, *sanitized_value = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!filters) {
		PHALCON_ALLOC_ZVAL_MM(filters);
		ZVAL_NULL(filters);
	}
	
	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, name);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch(&value, g0, name, PH_NOISY_CC);
		if (zend_is_true(filters)) {
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (!zend_is_true(dependency_injector)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
				return;
			}
			
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "filter", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", c0, PH_NO_CHECK);
			
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

	zval *name = NULL, *server_value = NULL;
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

	zval *name = NULL;
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

	zval *name = NULL;
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

	zval *name = NULL;
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

	zval *header = NULL, *server_value = NULL, *key = NULL;
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
			PHALCON_INIT_VAR(server_value);
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

	zval *https = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_HTTPS", 1);
	PHALCON_INIT_VAR(https);
	PHALCON_CALL_METHOD_PARAMS_1(https, this_ptr, "getserver", c0, PH_NO_CHECK);
	if (PHALCON_COMPARE_STRING(https, "on")) {
		PHALCON_MM_RESTORE();
		RETURN_STRING("https", 1);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_STRING("http", 1);
}

/**
 * Checks whether request has been made using ajax
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isAjax){

	zval *requested_with = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_X_REQUESTED_WITH", 1);
	PHALCON_INIT_VAR(requested_with);
	PHALCON_CALL_METHOD_PARAMS_1(requested_with, this_ptr, "getheader", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, requested_with, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested){

	zval *server = NULL, *position = NULL, *have_content_type = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SL("HTTP_SOAPACTION")+1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		eval_int = phalcon_array_isset_string(server, SL("CONTENT_TYPE")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, server, SL("CONTENT_TYPE"), PH_NOISY_CC);
			PHALCON_INIT_VAR(position);
			phalcon_fast_strpos_str(position, r0, SL("application/soap+xml") TSRMLS_CC);
			
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

	zval *scheme = NULL, *is_equal = NULL;
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

	zval *contents = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "php://input", 1);
	PHALCON_INIT_VAR(contents);
	PHALCON_CALL_FUNC_PARAMS_1(contents, "file_get_contents", c0);
	
	RETURN_CCTOR(contents);
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress){

	zval *server = NULL, *server_addr = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(server, g0);
	eval_int = phalcon_array_isset_string(server, SL("SERVER_ADDR")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(server_addr);
		phalcon_array_fetch_string(&server_addr, server, SL("SERVER_ADDR"), PH_NOISY_CC);
		
		RETURN_CCTOR(server_addr);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "localhost", 1);
	
	PHALCON_INIT_VAR(server_addr);
	PHALCON_CALL_FUNC_PARAMS_1(server_addr, "gethostbyname", c0);
	
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
	eval_int = phalcon_array_isset_string(server, SL("SERVER_NAME")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(server_name);
		phalcon_array_fetch_string(&server_name, server, SL("SERVER_NAME"), PH_NOISY_CC);
		
		RETURN_CCTOR(server_name);
	}
	
	PHALCON_INIT_VAR(server_name);
	ZVAL_STRING(server_name, "localhost", 1);
	
	RETURN_CCTOR(server_name);
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost){

	zval *scheme = NULL, *name = NULL, *port = NULL, *is_std_http = NULL, *is_secure_http = NULL;
	zval *is_http_normal = NULL, *name_port = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(scheme);
	PHALCON_CALL_METHOD(scheme, this_ptr, "getscheme", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_SERVER_NAME", 1);
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD_PARAMS_1(name, this_ptr, "getserver", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "HTTP_SERVER_PORT", 1);
	
	PHALCON_INIT_VAR(port);
	PHALCON_CALL_METHOD_PARAMS_1(port, this_ptr, "getserver", c1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "http", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, scheme, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 80);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, port, t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_std_http);
	phalcon_and_function(is_std_http, r0, r1);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "https", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, scheme, t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 443);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, port, t3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_secure_http);
	phalcon_and_function(is_secure_http, r2, r3);
	
	PHALCON_INIT_VAR(is_http_normal);
	ZVAL_BOOL(is_http_normal, zend_is_true(is_std_http) || zend_is_true(is_secure_http));
	if (zend_is_true(is_http_normal)) {
		
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
	eval_int = phalcon_array_isset_string(server, SL("HTTP_X_FORWARDED_FOR")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(address);
		phalcon_array_fetch_string(&address, server, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(server, SL("REMOTE_ADDR")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(address);
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
	eval_int = phalcon_array_isset_string(server, SL("REQUEST_METHOD")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(request_method);
		phalcon_array_fetch_string(&request_method, server, SL("REQUEST_METHOD"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(request_method);
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
	eval_int = phalcon_array_isset_string(server, SL("HTTP_USER_AGENT")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(user_agent);
		phalcon_array_fetch_string(&user_agent, server, SL("HTTP_USER_AGENT"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(user_agent);
		ZVAL_STRING(user_agent, "", 1);
	}
	
	
	RETURN_CCTOR(user_agent);
}

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array
 */
PHP_METHOD(Phalcon_Http_Request, isMethod){

	zval *methods = NULL, *http_method = NULL, *is_equals = NULL, *method = NULL;
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
		fes_ac06_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ac06_0;
			}
			
			PHALCON_INIT_VAR(method);
			ZVAL_ZVAL(method, *hd, 1, 0);
			PHALCON_INIT_VAR(is_equals);
			is_equal_function(is_equals, method, http_method TSRMLS_CC);
			if (zend_is_true(is_equals)) {
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ac06_0;
		fee_ac06_0:
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

	zval *method = NULL, *is_post = NULL;
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

	zval *method = NULL, *is_get = NULL;
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

	zval *method = NULL, *is_put = NULL;
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

	zval *method = NULL, *is_head = NULL;
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

	zval *method = NULL, *is_delete = NULL;
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

	zval *method = NULL, *is_options = NULL;
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

	zval *files = NULL, *number_files = NULL, *has_files = NULL;
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

	zval *super_files = NULL, *number_files = NULL, *files = NULL, *file = NULL;
	zval *request_file = NULL, *empty_files = NULL;
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
		fes_ac06_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ac06_1;
			}
			
			PHALCON_INIT_VAR(file);
			ZVAL_ZVAL(file, *hd, 1, 0);
			PHALCON_INIT_VAR(request_file);
			object_init_ex(request_file, phalcon_http_request_file_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(request_file, "__construct", file, PH_CHECK);
			phalcon_array_append(&files, request_file, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ac06_1;
		fee_ac06_1:
		
		
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

	zval *http_referer = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("HTTP_REFERER")+1);
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

	zval *server_index = NULL, *name = NULL, *quality_one = NULL, *returned_parts = NULL;
	zval *http_server = NULL, *parts = NULL, *part = NULL, *header_parts = NULL;
	zval *quality_part = NULL, *quality = NULL, *header_name = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
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
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/,\\s*/", 1);
	
	PHALCON_INIT_VAR(parts);
	PHALCON_CALL_FUNC_PARAMS_2(parts, "preg_split", c0, http_server);
	if (!phalcon_valid_foreach(parts TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(parts);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_ac06_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ac06_2;
		}
		
		PHALCON_INIT_VAR(part);
		ZVAL_ZVAL(part, *hd, 1, 0);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, ";", 1);
		PHALCON_INIT_VAR(header_parts);
		phalcon_fast_explode(header_parts, c1, part TSRMLS_CC);
		eval_int = phalcon_array_isset_long(header_parts, 1);
		if (eval_int) {
			PHALCON_INIT_VAR(quality_part);
			phalcon_array_fetch_long(&quality_part, header_parts, 1, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(c2);
			ZVAL_LONG(c2, 2);
			
			PHALCON_INIT_VAR(quality);
			PHALCON_CALL_FUNC_PARAMS_2(quality, "substr", quality_part, c2);
		} else {
			PHALCON_CPY_WRT(quality, quality_one);
		}
		
		PHALCON_INIT_VAR(header_name);
		phalcon_array_fetch_long(&header_name, header_parts, 0, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(quality_part);
		array_init(quality_part);
		phalcon_array_update_zval(&quality_part, name, &header_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&quality_part, SL("quality"), &quality, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&returned_parts, quality_part, PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ac06_2;
	fee_ac06_2:
	
	
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

	zval *quality_parts = NULL, *name = NULL, *i = NULL, *quality = NULL, *selected_name = NULL;
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
	fes_ac06_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ac06_3;
		}
		
		PHALCON_INIT_VAR(accept);
		ZVAL_ZVAL(accept, *hd, 1, 0);
		if (phalcon_compare_strict_long(i, 0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(quality);
			phalcon_array_fetch_string(&quality, accept, SL("quality"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(selected_name);
			phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(accept_quality);
			phalcon_array_fetch_string(&accept_quality, accept, SL("quality"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r0);
			is_smaller_function(r0, quality, accept_quality TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_CPY_WRT(quality, accept_quality);
				
				PHALCON_INIT_VAR(selected_name);
				phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
			}
		}
		PHALCON_SEPARATE(i);
		increment_function(i);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ac06_3;
	fee_ac06_3:
	
	
	RETURN_CCTOR(selected_name);
}

/**
 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent){

	zval *quality_header = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_ACCEPT", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "accept", 1);
	PHALCON_INIT_VAR(quality_header);
	PHALCON_CALL_METHOD_PARAMS_2(quality_header, this_ptr, "_getqualityheader", c0, c1, PH_NO_CHECK);
	
	RETURN_CCTOR(quality_header);
}

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept){

	zval *acceptable_content = NULL, *best_quality = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(acceptable_content);
	PHALCON_CALL_METHOD(acceptable_content, this_ptr, "getacceptablecontent", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "accept", 1);
	
	PHALCON_INIT_VAR(best_quality);
	PHALCON_CALL_METHOD_PARAMS_2(best_quality, this_ptr, "_getbestquality", acceptable_content, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(best_quality);
}

/**
 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets){

	zval *quality_charset = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_ACCEPT_CHARSET", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "charset", 1);
	PHALCON_INIT_VAR(quality_charset);
	PHALCON_CALL_METHOD_PARAMS_2(quality_charset, this_ptr, "_getqualityheader", c0, c1, PH_NO_CHECK);
	
	RETURN_CCTOR(quality_charset);
}

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset){

	zval *client_charsets = NULL, *best_charset = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(client_charsets);
	PHALCON_CALL_METHOD(client_charsets, this_ptr, "getclientcharsets", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "charset", 1);
	
	PHALCON_INIT_VAR(best_charset);
	PHALCON_CALL_METHOD_PARAMS_2(best_charset, this_ptr, "_getbestquality", client_charsets, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(best_charset);
}

/**
 * Gets languages array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages){

	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_ACCEPT_LANGUAGE", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "language", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "_getqualityheader", c0, c1, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage){

	zval *languages = NULL, *best_language = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(languages);
	PHALCON_CALL_METHOD(languages, this_ptr, "getlanguages", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "language", 1);
	
	PHALCON_INIT_VAR(best_language);
	PHALCON_CALL_METHOD_PARAMS_2(best_language, this_ptr, "_getbestquality", languages, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(best_language);
}


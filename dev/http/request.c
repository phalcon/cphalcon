
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

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	zval *filter = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;
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
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_METHOD_PARAMS_2(r0, filter, "sanitize", value, filters, PH_NO_CHECK);
			RETURN_CTOR(r0);
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
	zval *filter = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;
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
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_METHOD_PARAMS_2(r0, filter, "sanitize", value, filters, PH_NO_CHECK);
			RETURN_CTOR(r0);
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
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, g0, name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
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

	zval *header = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, header);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, g0, header, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SV(r1, "HTTP_", header);
		eval_int = phalcon_array_isset(g0, r1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_SV(r2, "HTTP_", header);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch(&r3, g0, r2, PH_NOISY_CC);
			
			RETURN_CCTOR(r3);
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

	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_HTTPS", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "getserver", c0, PH_NO_CHECK);
	if (PHALCON_COMPARE_STRING(r0, "on")) {
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

	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_X_REQUESTED_WITH", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "getheader", c0, PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("HTTP_SOAPACTION")+1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		eval_int = phalcon_array_isset_string(g0, SL("CONTENT_TYPE")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, g0, SL("CONTENT_TYPE"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_strpos_str(r1, r0, SL("application/soap+xml") TSRMLS_CC);
			PHALCON_INIT_VAR(t0);
			ZVAL_BOOL(t0, 0);
			PHALCON_ALLOC_ZVAL_MM(r2);
			is_not_identical_function(r2, t0, r1 TSRMLS_CC);
			
			RETURN_NCTOR(r2);
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

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "https", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_identical_function(r1, t0, r0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody){

	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "php://input", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "file_get_contents", c0);
	RETURN_CTOR(r0);
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("SERVER_ADDR")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, SL("SERVER_ADDR"), PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "localhost", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "gethostbyname", c0);
	RETURN_CTOR(r1);
}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getServerName){

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("SERVER_NAME")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, SL("SERVER_NAME"), PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_STRING("localhost", 1);
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost){

	zval *scheme = NULL, *name = NULL, *port = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;

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
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_and_function(r2, r0, r1);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "https", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, scheme, t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 443);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, port, t3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_and_function(r5, r3, r4);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	ZVAL_BOOL(r6, zend_is_true(r2) || zend_is_true(r5));
	if (zend_is_true(r6)) {
		
		RETURN_CCTOR(name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CONCAT_VSV(r7, name, ":", port);
	
	RETURN_CTOR(r7);
}

/**
 * Gets most possibly client IPv4 Address. This methods search in $_SERVER['HTTP_X_FORWARDED_FOR'] and $_SERVER['REMOTE_ADDR']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress){

	zval *address = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(address);
	ZVAL_STRING(address, "", 1);
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("HTTP_X_FORWARDED_FOR")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(address);
		phalcon_array_fetch_string(&address, g0, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(g0, SL("REMOTE_ADDR")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(address);
			phalcon_array_fetch_string(&address, g0, SL("REMOTE_ADDR"), PH_NOISY_CC);
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

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("REQUEST_METHOD")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, SL("REQUEST_METHOD"), PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_STRING("", 1);
}

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent){

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("HTTP_USER_AGENT")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, SL("HTTP_USER_AGENT"), PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_STRING("", 1);
}

/**
 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPost){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "POST", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 *
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isGet){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "GET", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isPut){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "PUT", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isHead){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "HEAD", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isDelete){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "DELETE", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, isOptions){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PH_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "OPTIONS", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Checks whether request include attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles){

	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_FILES")+1 TSRMLS_CC);
	if (zend_is_true(g0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_count(r0, g0 TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_smaller_function(r1, t0, r0 TSRMLS_CC);
		
		RETURN_NCTOR(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 *
 * @return Phalcon\Http\Request\File[]
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles){

	zval *super_files = NULL, *files = NULL, *file = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_FILES")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(super_files, g0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, super_files TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(files);
		array_init(files);
		if (!phalcon_valid_foreach(super_files TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(super_files);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_ac06_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ac06_0;
			}
			
			PHALCON_INIT_VAR(file);
			ZVAL_ZVAL(file, *hd, 1, 0);
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_http_request_file_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", file, PH_CHECK);
			phalcon_array_append(&files, i0, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ac06_0;
		fee_ac06_0:
		if(0){}
		
		
		RETURN_CTOR(files);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer){

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("HTTP_REFERER")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, SL("HTTP_REFERER"), PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
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

	zval *server_index = NULL, *name = NULL, *http_server = NULL, *parts = NULL;
	zval *returned_parts = NULL, *part = NULL, *header_parts = NULL, *quality = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &server_index, &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(http_server);
	PHALCON_CALL_METHOD_PARAMS_1(http_server, this_ptr, "getserver", server_index, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/,\\s*/", 1);
	
	PHALCON_INIT_VAR(parts);
	PHALCON_CALL_FUNC_PARAMS_2(parts, "preg_split", c0, http_server);
	
	PHALCON_INIT_VAR(returned_parts);
	array_init(returned_parts);
	if (!phalcon_valid_foreach(parts TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(parts);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_ac06_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ac06_1;
		}
		
		PHALCON_INIT_VAR(part);
		ZVAL_ZVAL(part, *hd, 1, 0);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, ";", 1);
		PHALCON_INIT_VAR(header_parts);
		phalcon_fast_explode(header_parts, c1, part TSRMLS_CC);
		eval_int = phalcon_array_isset_long(header_parts, 1);
		if (eval_int) {
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch_long(&r0, header_parts, 1, PH_NOISY_CC);
			PHALCON_INIT_VAR(c2);
			ZVAL_LONG(c2, 2);
			PHALCON_INIT_VAR(quality);
			PHALCON_CALL_FUNC_PARAMS_2(quality, "substr", r0, c2);
		} else {
			PHALCON_INIT_VAR(quality);
			ZVAL_DOUBLE(quality, 1);
		}
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch_long(&r1, header_parts, 0, PH_NOISY_CC);
		phalcon_array_update_zval(&a0, name, &r1, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a0, SL("quality"), &quality, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&returned_parts, a0, PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ac06_1;
	fee_ac06_1:
	if(0){}
	
	
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
	zval *accept = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
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
	fes_ac06_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ac06_2;
		}
		
		PHALCON_INIT_VAR(accept);
		ZVAL_ZVAL(accept, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, i, t0 TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(quality);
			phalcon_array_fetch_string(&quality, accept, SL("quality"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(selected_name);
			phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch_string(&r1, accept, SL("quality"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r2);
			is_smaller_function(r2, quality, r1 TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_INIT_VAR(quality);
				phalcon_array_fetch_string(&quality, accept, SL("quality"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(selected_name);
				phalcon_array_fetch(&selected_name, accept, name, PH_NOISY_CC);
			}
		}
		PHALCON_SEPARATE(i);
		increment_function(i);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ac06_2;
	fee_ac06_2:
	if(0){}
	
	
	RETURN_CCTOR(selected_name);
}

/**
 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent){

	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_ACCEPT", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "accept", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "_getqualityheader", c0, c1, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept){

	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getacceptablecontent", PH_NO_CHECK);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "accept", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "_getbestquality", r0, c0, PH_NO_CHECK);
	RETURN_CTOR(r1);
}

/**
 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets){

	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "HTTP_ACCEPT_CHARSET", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "charset", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "_getqualityheader", c0, c1, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset){

	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getclientcharsets", PH_NO_CHECK);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "charset", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "_getbestquality", r0, c0, PH_NO_CHECK);
	RETURN_CTOR(r1);
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

	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getlanguages", PH_NO_CHECK);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "language", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "_getbestquality", r0, c0, PH_NO_CHECK);
	RETURN_CTOR(r1);
}


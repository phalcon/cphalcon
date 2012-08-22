
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

PHP_METHOD(Phalcon_Mvc_Micro, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_micro_ce, this_ptr, SL("_handlers"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Micro, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Error Processing Request");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Micro, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

PHP_METHOD(Phalcon_Mvc_Micro, map){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "add", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, get){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addget", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, post){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addpost", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, put){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addput", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, head){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addhead", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, delete){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "adddelete", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, options){

	zval *route_pattern = NULL, *handler = NULL, *router = NULL, *route = NULL;
	zval *route_id = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD(router, this_ptr, "getrouter", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_1(route, router, "addoptions", route_pattern, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(route_id);
	PHALCON_CALL_METHOD(route_id, route, "getrouteid", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_handlers"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, route_id, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_handlers"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(route);
}

PHP_METHOD(Phalcon_Mvc_Micro, notFound){

	zval *handler = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_notFoundHandler"), handler TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Micro, getRouter){

	zval *router = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(router);
	phalcon_read_property(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	if (Z_TYPE_P(router) != IS_OBJECT) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "router", 1);
		PHALCON_INIT_VAR(router);
		PHALCON_CALL_METHOD_PARAMS_1(router, this_ptr, "getsharedservice", c0, PH_NO_CHECK);
		PHALCON_CALL_METHOD_NORETURN(router, "clear", PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_router"), router TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(router);
}

PHP_METHOD(Phalcon_Mvc_Micro, getService){

	zval *service_name = NULL, *dependency_injector = NULL;
	zval *service = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &service_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct", PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "get", service_name, PH_NO_CHECK);
	
	RETURN_CCTOR(service);
}

PHP_METHOD(Phalcon_Mvc_Micro, getSharedService){

	zval *service_name = NULL, *dependency_injector = NULL;
	zval *service = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &service_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		object_init_ex(dependency_injector, phalcon_di_factorydefault_ce);
		PHALCON_CALL_METHOD_NORETURN(dependency_injector, "__construct", PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "getshared", service_name, PH_NO_CHECK);
	
	RETURN_CCTOR(service);
}

PHP_METHOD(Phalcon_Mvc_Micro, handle){

	zval *dependency_injector = NULL, *router = NULL, *matched_route = NULL;
	zval *handlers = NULL, *route_id = NULL, *handler = NULL, *params = NULL, *status = NULL;
	zval *not_found_handler = NULL, *is_callable = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access related dispatching services");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "router", 1);
	
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", c0, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(router, "handle", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(matched_route);
	PHALCON_CALL_METHOD(matched_route, router, "getmatchedroute", PH_NO_CHECK);
	if (Z_TYPE_P(matched_route) == IS_OBJECT) {
		PHALCON_INIT_VAR(handlers);
		phalcon_read_property(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(route_id);
		PHALCON_CALL_METHOD(route_id, matched_route, "getrouteid", PH_NO_CHECK);
		eval_int = phalcon_array_isset(handlers, route_id);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "Matched route doesn't have an associate handler");
			return;
		}
		
		PHALCON_INIT_VAR(handler);
		phalcon_array_fetch(&handler, handlers, route_id, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(params);
		PHALCON_CALL_METHOD(params, router, "getparams", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_FUNC_PARAMS_2(status, "call_user_func_array", handler, params);
		
		RETURN_CCTOR(status);
	} else {
		PHALCON_INIT_VAR(not_found_handler);
		phalcon_read_property(&not_found_handler, this_ptr, SL("_notFoundHandler"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(is_callable);
		PHALCON_CALL_FUNC_PARAMS_1(is_callable, "is_callable", not_found_handler);
		if (!zend_is_true(is_callable)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "The Not-Found handler is not callable or is not defined");
			return;
		}
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_FUNC_PARAMS_1(status, "call_user_func", not_found_handler);
		
		RETURN_CCTOR(status);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Micro, __get){

	zval *property = NULL, *service = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(service);
	PHALCON_CALL_METHOD_PARAMS_1(service, this_ptr, "getservice", property, PH_NO_CHECK);
	phalcon_update_property_zval_zval(this_ptr, property, service TSRMLS_CC);
	
	RETURN_CCTOR(service);
}


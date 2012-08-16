
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

PHP_METHOD(Phalcon_DI, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_di_ce, this_ptr, SL("_services"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_di_ce, this_ptr, SL("_sharedInstances"), a1 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), this_ptr TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, set){

	zval *alias = NULL, *config = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, alias, &config, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_services"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, remove){

	zval *alias = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	PHALCON_SEPARATE_NMO(t0);
	phalcon_array_unset(t0, alias);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, attempt){

	zval *alias = NULL, *config = NULL, *services = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	if (!eval_int) {
		phalcon_array_update_zval(&services, alias, &config, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_services"), services TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, _factory){

	zval *service = NULL, *parameters = NULL, *found = NULL, *instance = NULL, *reflection = NULL;
	zval *class_name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1, *ce2;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &service, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(found);
	ZVAL_BOOL(found, 1);
	
	PHALCON_INIT_VAR(instance);
	ZVAL_NULL(instance);
	if (Z_TYPE_P(service) == IS_STRING) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", service);
		if (zend_is_true(r0)) {
			ce0 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(reflection);
			object_init_ex(reflection, ce0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(reflection, "__construct", service, PH_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_count(r1, parameters TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_1(instance, reflection, "newinstanceargs", parameters, PH_NO_CHECK);
			} else {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD(instance, reflection, "newinstance", PH_NO_CHECK);
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_FUNC_PARAMS_1(r2, "is_callable", service);
			if (zend_is_true(r2)) {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_FUNC_PARAMS_2(instance, "call_user_func_array", service, parameters);
			} else {
				PHALCON_INIT_VAR(found);
				ZVAL_BOOL(found, 0);
			}
		}
	} else {
		if (Z_TYPE_P(service) == IS_ARRAY) { 
			eval_int = phalcon_array_isset_string(service, SL("className")+1);
			if (!eval_int) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
				return;
			}
			
			PHALCON_INIT_VAR(class_name);
			phalcon_array_fetch_string(&class_name, service, SL("className"), PH_NOISY_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_fast_count(r3, parameters TSRMLS_CC);
			if (zend_is_true(r3)) {
				ce1 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				PHALCON_INIT_VAR(reflection);
				object_init_ex(reflection, ce1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(reflection, "__construct", class_name, PH_CHECK);
				
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_1(instance, reflection, "newinstanceargs", parameters, PH_NO_CHECK);
			} else {
				ce2 = phalcon_fetch_class(class_name TSRMLS_CC);
				PHALCON_INIT_VAR(instance);
				object_init_ex(instance, ce2);
				PHALCON_CALL_METHOD_NORETURN(instance, "__construct", PH_CHECK);
			}
			
			
			RETURN_CCTOR(instance);
		} else {
			if (Z_TYPE_P(service) == IS_OBJECT) {
				PHALCON_ALLOC_ZVAL_MM(r4);
				phalcon_get_class(r4, service TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r4, "Closure")) {
					PHALCON_INIT_VAR(instance);
					PHALCON_CALL_FUNC_PARAMS_2(instance, "call_user_func_array", service, parameters);
				} else {
					PHALCON_CPY_WRT(instance, service);
				}
			} else {
				PHALCON_INIT_VAR(found);
				ZVAL_BOOL(found, 0);
			}
		}
	}
	
	if (!zend_is_true(found)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_di_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_SVS(r5, "Service '", service, "' wasn't found in the dependency injection container");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r5, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	RETURN_CCTOR(instance);
}

PHP_METHOD(Phalcon_DI, get){

	zval *alias = NULL, *parameters = NULL, *services = NULL, *service = NULL, *instance = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		array_init(parameters);
	}
	
	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(service);
		phalcon_array_fetch(&service, services, alias, PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(service, alias);
	}
	
	PHALCON_INIT_VAR(instance);
	PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "_factory", service, parameters, PH_NO_CHECK);
	if (Z_TYPE_P(instance) == IS_OBJECT) {
		if (phalcon_method_exists_ex(instance, SL("setdi") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(instance, "setdi", this_ptr, PH_NO_CHECK);
		}
	}
	
	
	RETURN_CCTOR(instance);
}

PHP_METHOD(Phalcon_DI, getShared){

	zval *alias = NULL, *parameters = NULL, *shared_instances = NULL;
	zval *instance = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		array_init(parameters);
	}
	
	PHALCON_INIT_VAR(shared_instances);
	phalcon_read_property(&shared_instances, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(shared_instances, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(instance);
		phalcon_array_fetch(&instance, shared_instances, alias, PH_NOISY_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 0 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(instance);
		PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "get", alias, parameters, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
		phalcon_array_update_zval(&t0, alias, &instance, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_sharedInstances"), t0 TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 1 TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(instance);
}

PHP_METHOD(Phalcon_DI, has){

	zval *alias = NULL, *services = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_DI, wasFreshInstance){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_freshInstance"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

PHP_METHOD(Phalcon_DI, __call){

	zval *method = NULL, *arguments = NULL, *services = NULL, *possible_service = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 3);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_3(r0, "substr", method, c0, c1);
	if (PHALCON_COMPARE_STRING(r0, "get")) {
		PHALCON_INIT_VAR(services);
		phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(c2);
		ZVAL_LONG(c2, 3);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "substr", method, c2);
		
		PHALCON_INIT_VAR(possible_service);
		PHALCON_CALL_FUNC_PARAMS_1(possible_service, "strtolower", r1);
		eval_int = phalcon_array_isset(services, possible_service);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, arguments TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_ALLOC_ZVAL_MM(r3);
				PHALCON_CALL_METHOD_PARAMS_2(r3, this_ptr, "get", possible_service, arguments, PH_NO_CHECK);
				RETURN_CTOR(r3);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r4);
				PHALCON_CALL_METHOD_PARAMS_1(r4, this_ptr, "get", possible_service, PH_NO_CHECK);
				RETURN_CTOR(r4);
			}
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_di_exception_ce);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_SVS(r5, "Call to undefined method or service '", method, "'");
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r5, PH_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

PHP_METHOD(Phalcon_DI, setDefault){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, getDefault){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	
	RETURN_CCTOR(t0);
}

PHP_METHOD(Phalcon_DI, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}


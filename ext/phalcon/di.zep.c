
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Di
 *
 * Phalcon\Di is a component that implements Dependency Injection/Service Location
 * of services and it's itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\Di is essential to integrate the different
 * components of the framework. The developer can also use this component to inject dependencies
 * and manage global instances of the different classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern. Applying this,
 * the objects do not receive their dependencies using setters or constructors, but requesting
 * a service dependency injector. This reduces the overall complexity, since there is only one
 * way to get the required dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it less prone to errors.
 *
 *<code>
 * use Phalcon\Di;
 * use Phalcon\Http\Request;
 *
 * $di = new Di();
 *
 * // Using a string definition
 * $di->set("request", Request::class, true);
 *
 * // Using an anonymous function
 * $di->setShared(
 *     "request",
 *     function () {
 *         return new Request();
 *     }
 * );
 *
 * $request = $di->getRequest();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Di) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Di, phalcon, di, phalcon_di_method_entry, 0);

	/**
	 * List of registered services
	 */
	zend_declare_property_null(phalcon_di_ce, SL("_services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * List of shared instances
	 */
	zend_declare_property_null(phalcon_di_ce, SL("_sharedInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * To know if the latest resolved instance was shared or not
	 */
	zend_declare_property_bool(phalcon_di_ce, SL("_freshInstance"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Events Manager
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	zend_declare_property_null(phalcon_di_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Latest DI build
	 */
	zend_declare_property_null(phalcon_di_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_di_ce TSRMLS_CC, 1, phalcon_diinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Di constructor
 */
PHP_METHOD(Phalcon_Di, __construct) {

	zval *di = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(di);
	zephir_read_static_property_ce(&di, phalcon_di_ce, SL("_default") TSRMLS_CC);
	if (!(zephir_is_true(di))) {
		zephir_update_static_property_ce(phalcon_di_ce, SL("_default"), &this_ptr TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the internal event manager
 */
PHP_METHOD(Phalcon_Di, setInternalEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(getThis(), SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Di, getInternalEventsManager) {

	

	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Registers a service in the services container
 */
PHP_METHOD(Phalcon_Di, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *name_param = NULL, *definition, *shared_param = NULL, *service = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	ZEPHIR_INIT_VAR(service);
	object_init_ex(service, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_0);
	if (shared) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, service, "__construct", NULL, 70, name, definition, _0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

/**
 * Registers an "always shared" service in the services container
 */
PHP_METHOD(Phalcon_Di, setShared) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *definition, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, name, definition, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes a service in the services container
 * It also removes any shared instance created for the service
 */
PHP_METHOD(Phalcon_Di, remove) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	zephir_array_unset(&_1, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 */
PHP_METHOD(Phalcon_Di, attempt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *name_param = NULL, *definition, *shared_param = NULL, *service = NULL, *_0, *_1$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(service);
		object_init_ex(service, phalcon_di_service_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		if (shared) {
			ZVAL_BOOL(_1$$3, 1);
		} else {
			ZVAL_BOOL(_1$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, service, "__construct", NULL, 70, name, definition, _1$$3);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
		RETURN_CCTOR(service);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets a service using a raw Phalcon\Di\Service definition
 */
PHP_METHOD(Phalcon_Di, setRaw) {

	zval *name_param = NULL, *rawDefinition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &rawDefinition);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("_services"), name, rawDefinition TSRMLS_CC);
	RETVAL_ZVAL(rawDefinition, 1, 0);
	RETURN_MM();

}

/**
 * Returns a service definition without resolving
 */
PHP_METHOD(Phalcon_Di, getRaw) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *service = NULL, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&service, _0, name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(service, "getdefinition", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_di_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "Service '", name, "' wasn't found in the dependency injection container");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/di.zep", 191 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns a Phalcon\Di\Service instance
 */
PHP_METHOD(Phalcon_Di, getService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *service = NULL, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&service, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(service);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_di_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "Service '", name, "' wasn't found in the dependency injection container");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/di.zep", 205 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves the service based on its configuration
 */
PHP_METHOD(Phalcon_Di, get) {

	zend_bool _6$$6;
	zval *_1$$3, *_7$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, *service = NULL, *eventsManager = NULL, *instance = NULL, *_0, *_2$$3, *_3$$4, *_4$$7, *_8$$12;
	zval *name = NULL, *_5$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_1$$3, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$3, SL("parameters"), &parameters, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "di:beforeServiceResolve", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&instance, eventsManager, "fire", NULL, 0, _2$$3, this_ptr, _1$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(instance) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(service);
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&service, _3$$4, name, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&instance, service, "resolve", NULL, 0, parameters, this_ptr);
			zephir_check_call_status();
		} else {
			if (!(zephir_class_exists(name, 1 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_4$$7);
				object_init_ex(_4$$7, phalcon_di_exception_ce);
				ZEPHIR_INIT_VAR(_5$$7);
				ZEPHIR_CONCAT_SVS(_5$$7, "Service '", name, "' wasn't found in the dependency injection container");
				ZEPHIR_CALL_METHOD(NULL, _4$$7, "__construct", NULL, 9, _5$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4$$7, "phalcon/di.zep", 236 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_6$$6 = Z_TYPE_P(parameters) == IS_ARRAY;
			if (_6$$6) {
				_6$$6 = ((zephir_fast_count_int(parameters TSRMLS_CC)) ? 1 : 0);
			}
			if (_6$$6) {
				ZEPHIR_INIT_NVAR(instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(instance, name, parameters TSRMLS_CC);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, name TSRMLS_CC);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(instance) == IS_OBJECT) {
		if (zephir_instance_of_ev(instance, phalcon_di_injectionawareinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, instance, "setdi", NULL, 0, this_ptr);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_7$$12);
		zephir_create_array(_7$$12, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_7$$12, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_7$$12, SL("parameters"), &parameters, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_7$$12, SL("instance"), &instance, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_8$$12);
		ZVAL_STRING(_8$$12, "di:afterServiceResolve", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _8$$12, this_ptr, _7$$12);
		zephir_check_temp_parameter(_8$$12);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent
 * requests for this service will return the same instance
 *
 * @param string name
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di, getShared) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, *instance = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(instance);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&instance, _0, name, 0 TSRMLS_CC)) {
		if (0) {
			zephir_update_property_this(getThis(), SL("_freshInstance"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_freshInstance"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else {
		ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, name, parameters);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_sharedInstances"), name, instance TSRMLS_CC);
		if (1) {
			zephir_update_property_this(getThis(), SL("_freshInstance"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_freshInstance"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_CCTOR(instance);

}

/**
 * Check whether the DI contains a service by a name
 */
PHP_METHOD(Phalcon_Di, has) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 */
PHP_METHOD(Phalcon_Di, wasFreshInstance) {

	

	RETURN_MEMBER(getThis(), "_freshInstance");

}

/**
 * Return the services registered in the DI
 */
PHP_METHOD(Phalcon_Di, getServices) {

	

	RETURN_MEMBER(getThis(), "_services");

}

/**
 * Check if a service is registered using the array syntax
 */
PHP_METHOD(Phalcon_Di, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to register a shared service using the array syntax
 *
 *<code>
 * $di["request"] = new \Phalcon\Http\Request();
 *</code>
 */
PHP_METHOD(Phalcon_Di, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, *definition;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &definition);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setshared", NULL, 0, name, definition);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Allows to obtain a shared service using the array syntax
 *
 *<code>
 * var_dump($di["request"]);
 *</code>
 */
PHP_METHOD(Phalcon_Di, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getshared", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes a service from the services container using the array syntax
 */
PHP_METHOD(Phalcon_Di, offsetUnset) {

	zval *name;

	zephir_fetch_params(0, 1, 0, &name);



	RETURN_BOOL(0);

}

/**
 * Magic method to get or set services using setters/getters
 */
PHP_METHOD(Phalcon_Di, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *instance = NULL, *possibleService = NULL, *services = NULL, *definition = NULL, *_5, _0$$3, *_1$$3, _2$$8, *_3$$8, *_4$$8 = NULL;
	zval *method = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_OBS_VAR(services);
		zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_substr(_1$$3, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&possibleService, "lcfirst", NULL, 71, _1$$3);
		zephir_check_call_status();
		if (zephir_array_isset(services, possibleService)) {
			if (zephir_fast_count_int(arguments TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, possibleService, arguments);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, possibleService);
				zephir_check_call_status();
			}
			RETURN_CCTOR(instance);
		}
	}
	if (zephir_start_with_str(method, SL("set"))) {
		ZEPHIR_OBS_VAR(definition);
		if (zephir_array_isset_long_fetch(&definition, arguments, 0, 0 TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_2$$8);
			ZVAL_LONG(&_2$$8, 3);
			ZEPHIR_INIT_VAR(_3$$8);
			zephir_substr(_3$$8, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_FUNCTION(&_4$$8, "lcfirst", NULL, 71, _3$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _4$$8, definition);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, phalcon_di_exception_ce);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVS(_6, "Call to undefined method or service '", method, "'");
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 9, _6);
	zephir_check_call_status();
	zephir_throw_exception_debug(_5, "phalcon/di.zep", 406 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Registers a service provider.
 *
 * <code>
 * use Phalcon\DiInterface;
 * use Phalcon\Di\ServiceProviderInterface;
 *
 * class SomeServiceProvider implements ServiceProviderInterface
 * {
 *     public function register(DiInterface $di)
 *     {
 *         $di->setShared('service', function () {
 *             // ...
 *         });
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Di, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set a default dependency injection container to be obtained into static methods
 */
PHP_METHOD(Phalcon_Di, setDefault) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_static_property_ce(phalcon_di_ce, SL("_default"), &dependencyInjector TSRMLS_CC);

}

/**
 * Return the latest DI created
 */
PHP_METHOD(Phalcon_Di, getDefault) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(phalcon_di_ce, SL("_default") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_Di, reset) {

	

	zephir_update_static_property_ce(phalcon_di_ce, SL("_default"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

/**
 * Loads services from a yaml file.
 *
 * <code>
 * $di->loadFromYaml(
 *     "path/services.yaml",
 *     [
 *         "!approot" => function ($value) {
 *             return dirname(__DIR__) . $value;
 *         }
 *     ]
 * );
 * </code>
 *
 * And the services can be specified in the file as:
 *
 * <code>
 * myComponent:
 *     className: \Acme\Components\MyComponent
 *     shared: true
 *
 * group:
 *     className: \Acme\Group
 *     arguments:
 *         - type: service
 *           name: myComponent
 *
 * user:
 *    className: \Acme\User
 * </code>
 *
 * @link https://docs.phalconphp.com/en/latest/reference/di.html
 */
PHP_METHOD(Phalcon_Di, loadFromYaml) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callbacks = NULL;
	zval *filePath_param = NULL, *callbacks_param = NULL, *services = NULL;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &callbacks_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(callbacks);
		array_init(callbacks);
	} else {
	callbacks = callbacks_param;
	}


	ZEPHIR_INIT_VAR(services);
	object_init_ex(services, phalcon_config_adapter_yaml_ce);
	ZEPHIR_CALL_METHOD(NULL, services, "__construct", NULL, 72, filePath, callbacks);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfromconfig", NULL, 0, services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads services from a php config file.
 *
 * <code>
 * $di->loadFromPhp("path/services.php");
 * </code>
 *
 * And the services can be specified in the file as:
 *
 * <code>
 * return [
 *      'myComponent' => [
 *          'className' => '\Acme\Components\MyComponent',
 *          'shared' => true,
 *      ],
 *      'group' => [
 *          'className' => '\Acme\Group',
 *          'arguments' => [
 *              [
 *                  'type' => 'service',
 *                  'service' => 'myComponent',
 *              ],
 *          ],
 *      ],
 *      'user' => [
 *          'className' => '\Acme\User',
 *      ],
 * ];
 * </code>
 *
 * @link https://docs.phalconphp.com/en/latest/reference/di.html
 */
PHP_METHOD(Phalcon_Di, loadFromPhp) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *services = NULL;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_INIT_VAR(services);
	object_init_ex(services, phalcon_config_adapter_php_ce);
	ZEPHIR_CALL_METHOD(NULL, services, "__construct", NULL, 73, filePath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfromconfig", NULL, 0, services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads services from a Config object.
 */
PHP_METHOD(Phalcon_Di, loadFromConfig) {

	zend_bool _3$$3;
	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *services = NULL, *name = NULL, *service = NULL, **_2, *_4$$3 = NULL, *_5$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_CALL_METHOD(&services, config, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(services, &_1, &_0, 0, 0, "phalcon/di.zep", 551);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(service, _2);
		_3$$3 = zephir_array_isset_string(service, SS("shared"));
		if (_3$$3) {
			ZEPHIR_OBS_NVAR(_4$$3);
			zephir_array_fetch_string(&_4$$3, service, SL("shared"), PH_NOISY, "phalcon/di.zep", 549 TSRMLS_CC);
			_3$$3 = zephir_is_true(_4$$3);
		}
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_BOOL(_5$$3, _3$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_6, 0, name, service, _5$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}


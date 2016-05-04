
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Application
 *
 * Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.
 */
ZEPHIR_INIT_CLASS(Phalcon_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Application, phalcon, application, phalcon_di_injectable_ce, phalcon_application_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_application_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_application_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_application_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_application_ce->create_object = zephir_init_properties_Phalcon_Application;

	zend_class_implements(phalcon_application_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Application
 */
PHP_METHOD(Phalcon_Application, __construct) {

	zval *dependencyInjector = NULL;

	zephir_fetch_params(0, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Application, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Application, getEventsManager) {

	

	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Register an array of modules present in the application
 *
 * <code>
 * $this->registerModules(
 * 	[
 * 		'frontend' => [
 * 			'className' => 'Multiple\Frontend\Module',
 * 			'path'      => '../apps/frontend/Module.php'
 * 		],
 * 		'backend' => [
 * 			'className' => 'Multiple\Backend\Module',
 * 			'path'      => '../apps/backend/Module.php'
 * 		]
 * 	]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Application, registerModules) {

	zend_bool merge, _0;
	zval *modules_param = NULL, *merge_param = NULL, *_1, *_2$$3, *_3$$3;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modules_param, &merge_param);

	zephir_get_arrval(modules, modules_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge == 1;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_modules"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		zephir_fast_array_merge(_2$$3, &(_3$$3), &(modules) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_modules"), _2$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Return the modules registered in the application
 */
PHP_METHOD(Phalcon_Application, getModules) {

	

	RETURN_MEMBER(this_ptr, "_modules");

}

/**
 * Gets the module definition registered in the application via module name
 */
PHP_METHOD(Phalcon_Application, getModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *module = NULL, *_0, *_1$$3;
	zval *name = NULL, *_2$$3;

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


	ZEPHIR_OBS_VAR(module);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&module, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_application_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Module '", name, "' isn't registered in the application container");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/application.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(module);

}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 */
PHP_METHOD(Phalcon_Application, setDefaultModule) {

	zval *defaultModule_param = NULL;
	zval *defaultModule = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);

	if (unlikely(Z_TYPE_P(defaultModule_param) != IS_STRING && Z_TYPE_P(defaultModule_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultModule' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(defaultModule_param) == IS_STRING)) {
		zephir_get_strval(defaultModule, defaultModule_param);
	} else {
		ZEPHIR_INIT_VAR(defaultModule);
		ZVAL_EMPTY_STRING(defaultModule);
	}


	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the default module name
 */
PHP_METHOD(Phalcon_Application, getDefaultModule) {

	

	RETURN_MEMBER(this_ptr, "_defaultModule");

}

/**
 * Handles a request
 */
PHP_METHOD(Phalcon_Application, handle) {

}

zend_object_value zephir_init_properties_Phalcon_Application(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_modules"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}


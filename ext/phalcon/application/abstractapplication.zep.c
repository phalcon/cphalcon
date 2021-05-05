
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.
 */
ZEPHIR_INIT_CLASS(Phalcon_Application_AbstractApplication)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Application, AbstractApplication, phalcon, application_abstractapplication, phalcon_di_injectable_ce, phalcon_application_abstractapplication_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var DiInterface
	 */
	zend_declare_property_null(phalcon_application_abstractapplication_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_application_abstractapplication_ce, SL("defaultModule"), ZEND_ACC_PROTECTED);
	/**
	 * @var null | ManagerInterface
	 */
	zend_declare_property_null(phalcon_application_abstractapplication_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_application_abstractapplication_ce, SL("modules"), ZEND_ACC_PROTECTED);
	phalcon_application_abstractapplication_ce->create_object = zephir_init_properties_Phalcon_Application_AbstractApplication;

	zend_class_implements(phalcon_application_abstractapplication_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\AbstractApplication constructor
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, __construct)
{
	zval *container = NULL, container_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &container);
	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	if (Z_TYPE_P(container) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	}
}

/**
 * Returns the default module name
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, getDefaultModule)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultModule");
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, getEventsManager)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Gets the module definition registered in the application via module name
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, getModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, module, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	ZEPHIR_OBS_VAR(&module);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&module, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_application_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Module '", &name, "' isn't registered in the application container");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Application/AbstractApplication.zep", 79);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&module);
}

/**
 * Return the modules registered in the application
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, getModules)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "modules");
}

/**
 * Register an array of modules present in the application
 *
 * ```php
 * $this->registerModules(
 *     [
 *         "frontend" => [
 *             "className" => \Multiple\Frontend\Module::class,
 *             "path"      => "../apps/frontend/Module.php",
 *         ],
 *         "backend" => [
 *             "className" => \Multiple\Backend\Module::class,
 *             "path"      => "../apps/backend/Module.php",
 *         ],
 *     ]
 * );
 * ```
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, registerModules)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *modules_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval modules;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modules);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(modules)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modules_param, &merge_param);
	zephir_get_arrval(&modules, modules_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &modules);
		zephir_update_property_zval(this_ptr, ZEND_STRL("modules"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("modules"), &modules);
	}
	RETURN_THIS();
}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, setDefaultModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaultModule_param = NULL;
	zval defaultModule;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(defaultModule)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);
	if (UNEXPECTED(Z_TYPE_P(defaultModule_param) != IS_STRING && Z_TYPE_P(defaultModule_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultModule' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(defaultModule_param) == IS_STRING)) {
		zephir_get_strval(&defaultModule, defaultModule_param);
	} else {
		ZEPHIR_INIT_VAR(&defaultModule);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &defaultModule);
	RETURN_THIS();
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Application_AbstractApplication, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);


	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

zend_object *zephir_init_properties_Phalcon_Application_AbstractApplication(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("modules"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}


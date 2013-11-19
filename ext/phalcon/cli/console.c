
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Cli\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_cli_console_method_entry, 0);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_console_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_console_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_console_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cli_console_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_cli_console_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Cli\Console constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Cli_Console, __construct) {

	zval *dependencyInjector = NULL;

	zephir_fetch_params(0, 0, 1, &dependencyInjector);

	if (!dependencyInjector || Z_TYPE_P(dependencyInjector) == IS_NULL) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Cli_Console, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_cli_console_exception_ce, "Dependency Injector is invalid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Cli_Console, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Cli_Console, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Cli_Console, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Register an array of modules present in the console
 *
 *<code>
 *	$application->registerModules(array(
 *		'frontend' => array(
 *			'className' => 'Multiple\Frontend\Module',
 *			'path' => '../apps/frontend/Module.php'
 *		),
 *		'backend' => array(
 *			'className' => 'Multiple\Backend\Module',
 *			'path' => '../apps/backend/Module.php'
 *		)
 *	));
 *</code>
 *
 * @param array modules
 */
PHP_METHOD(Phalcon_Cli_Console, registerModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	if ((Z_TYPE_P(modules) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_cli_console_exception_ce, "Modules must be an Array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);

}

/**
 * Merge modules with the existing ones
 *
 *<code>
 *	application->addModules(array(
 *		'admin' => array(
 *			'className' => 'Multiple\Admin\Module',
 *			'path' => '../apps/admin/Module.php'
 *		)
 *	));
 *</code>
 *
 * @param array modules
 */
PHP_METHOD(Phalcon_Cli_Console, addModules) {

	zval *modules, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules);



	if ((Z_TYPE_P(modules) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "Modules must be an Array");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(modules), &(_1) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modules"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the modules registered in the console
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Console, getModules) {


	RETURN_MEMBER(this_ptr, "_modules");

}

/**
 * Handle the whole command-line tasks
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Cli_Console, handle) {

	zval *arguments = NULL, *dependencyInjector, *router = NULL, *eventsManager = NULL, *moduleName, *modules, *module, *path, *className = NULL, *moduleObject, *dispatcher = NULL, *task, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments || Z_TYPE_P(arguments) == IS_NULL) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "router", 1);
	zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
	ZEPHIR_CPY_WRT(router, _1);
	zephir_call_method_p1_noret(router, "handle", arguments);
	ZEPHIR_INIT_VAR(moduleName);
	zephir_call_method(moduleName, router, "getmodulename");
	if (zephir_is_true(moduleName)) {
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZEPHIR_INIT_BNVAR(_2);
			ZVAL_STRING(_2, "console:beforeStartModule", 1);
			zephir_call_method_p3(_1, eventsManager, "fire", _2, this_ptr, moduleName);
			if (ZEPHIR_IS_FALSE(_1)) {
				RETURN_MM_BOOL(0);
			}
		}
		modules = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset(modules, moduleName))) {
			ZEPHIR_INIT_BNVAR(_2);
			object_init_ex(_2, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "Module '", moduleName, "' isn't registered in the console container");
			zephir_call_method_p1_noret(_2, "__construct", _3);
			zephir_throw_exception(_2 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_fetch(&module, modules, moduleName, PH_NOISY | PH_READONLY TSRMLS_CC);
		if ((Z_TYPE_P(module) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "Invalid module definition path");
			return;
		}
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_BNVAR(_2);
			zephir_call_func_p1(_2, "file_exists", path);
			if (!(zephir_is_true(_2))) {
				ZEPHIR_INIT_VAR(_4);
				object_init_ex(_4, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVS(_3, "Module definition path '", path, "' doesn't exist");
				zephir_call_method_p1_noret(_4, "__construct", _3);
				zephir_throw_exception(_4 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_VAR(className);
		if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(className);
			ZVAL_STRING(className, "Module", 1);
		}
		ZEPHIR_INIT_VAR(moduleObject);
		zephir_call_method_p1(moduleObject, dependencyInjector, "get", className);
		zephir_call_method_noret(moduleObject, "registerautoloaders");
		zephir_call_method_p1_noret(moduleObject, "registerservices", dependencyInjector);
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			zephir_update_property_this(this_ptr, SL("_moduleObject"), moduleObject TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "console:afterStartModule", 1);
			zephir_call_method_p3(_4, eventsManager, "fire", _5, this_ptr, moduleObject);
			if (ZEPHIR_IS_FALSE(_4)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "dispatcher", 1);
	zephir_call_method_p1(_4, dependencyInjector, "getshared", _5);
	ZEPHIR_CPY_WRT(dispatcher, _4);
	ZEPHIR_INIT_NVAR(_4);
	zephir_call_method(_4, router, "gettaskname");
	zephir_call_method_p1_noret(dispatcher, "settaskname", _4);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method(_5, router, "getactionname");
	zephir_call_method_p1_noret(dispatcher, "setactionname", _5);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, router, "getparams");
	zephir_call_method_p1_noret(dispatcher, "setparams", _6);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_STRING(_8, "console:beforeHandleTask", 1);
		zephir_call_method_p3(_7, eventsManager, "fire", _8, this_ptr, dispatcher);
		if (ZEPHIR_IS_FALSE(_7)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(task);
	zephir_call_method(task, dispatcher, "dispatch");
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "console:afterHandleTask", 1);
		zephir_call_method_p3_noret(eventsManager, "fire", _5, this_ptr, task);
	}
	RETURN_CCTOR(task);

}


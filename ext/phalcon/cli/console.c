
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

	zend_bool _0;
	zval *dependencyInjector = NULL;

	zephir_fetch_params(0, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	_0 = (Z_TYPE_P(dependencyInjector) != IS_NULL);
	if (_0) {
		_0 = !zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'");
		return;
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



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'");
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



	if (!(zephir_instance_of_ev(eventsManager, phalcon_events_managerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STRW(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'");
		return;
	}
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *dependencyInjector, *router = NULL, *eventsManager = NULL, *moduleName, *modules, *module, *path, *className = NULL, *moduleObject, *dispatcher = NULL, *task, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
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
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _1);
	zephir_call_method_p1_noret(router, "handle", arguments);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(moduleName);
	zephir_call_method(moduleName, router, "getmodulename");
	zephir_check_call_status();
	if (zephir_is_true(moduleName)) {
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZEPHIR_INIT_BNVAR(_2);
			ZVAL_STRING(_2, "console:beforeStartModule", 1);
			zephir_call_method_p3(_1, eventsManager, "fire", _2, this_ptr, moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_1)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_OBS_VAR(modules);
		zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset(modules, moduleName))) {
			ZEPHIR_INIT_VAR(_3);
			object_init_ex(_3, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "Module '", moduleName, "' isn't registered in the console container");
			zephir_call_method_p1_noret(_3, "__construct", _4);
			zephir_check_call_status();
			zephir_throw_exception(_3 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(module);
		zephir_array_fetch(&module, modules, moduleName, PH_NOISY TSRMLS_CC);
		if ((Z_TYPE_P(module) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "Invalid module definition path");
			return;
		}
		ZEPHIR_OBS_VAR(path);
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
			if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Module definition path '", path, "' doesn't exist");
				zephir_call_method_p1_noret(_3, "__construct", _4);
				zephir_check_call_status();
				zephir_throw_exception(_3 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_LNVAR(_3);
			if (zephir_require_ret(_3, path TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		ZEPHIR_OBS_VAR(className);
		if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(className);
			ZVAL_STRING(className, "Module", 1);
		}
		ZEPHIR_INIT_VAR(moduleObject);
		zephir_call_method_p1(moduleObject, dependencyInjector, "get", className);
		zephir_check_call_status();
		zephir_call_method_noret(moduleObject, "registerautoloaders");
		zephir_check_call_status();
		zephir_call_method_p1_noret(moduleObject, "registerservices", dependencyInjector);
		zephir_check_call_status();
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			zephir_update_property_this(this_ptr, SL("_moduleObject"), moduleObject TSRMLS_CC);
			ZEPHIR_INIT_BNVAR(_2);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "console:afterStartModule", 1);
			zephir_call_method_p3(_2, eventsManager, "fire", _5, this_ptr, moduleObject);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "dispatcher", 1);
	zephir_call_method_p1(_5, dependencyInjector, "getshared", _6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _5);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method(_5, router, "gettaskname");
	zephir_check_call_status();
	zephir_call_method_p1_noret(dispatcher, "settaskname", _5);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_6);
	zephir_call_method(_6, router, "getactionname");
	zephir_check_call_status();
	zephir_call_method_p1_noret(dispatcher, "setactionname", _6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	zephir_call_method(_7, router, "getparams");
	zephir_check_call_status();
	zephir_call_method_p1_noret(dispatcher, "setparams", _7);
	zephir_check_call_status();
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "console:beforeHandleTask", 1);
		zephir_call_method_p3(_8, eventsManager, "fire", _9, this_ptr, dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_8)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(task);
	zephir_call_method(task, dispatcher, "dispatch");
	zephir_check_call_status();
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "console:afterHandleTask", 1);
		zephir_call_method_p3_noret(eventsManager, "fire", _5, this_ptr, task);
		zephir_check_call_status();
	}
	RETURN_CCTOR(task);

}


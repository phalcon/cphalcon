
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


	_0 = Z_TYPE_P(dependencyInjector) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'", "", 0);
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



	if (Z_TYPE_P(modules) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_cli_console_exception_ce, "Modules must be an Array", "phalcon/cli/console.zep", 112);
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



	if (Z_TYPE_P(modules) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Modules must be an Array", "phalcon/cli/console.zep", 134);
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
	zval *arguments = NULL, *dependencyInjector, *router = NULL, *eventsManager = NULL, *moduleName = NULL, *modules, *module, *path, *className = NULL, *moduleObject = NULL, *dispatcher = NULL, *task = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services", "phalcon/cli/console.zep", 163);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "router", 0);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _1);
	ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, arguments);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&moduleName, router, "getmodulename",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(moduleName)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_BNVAR(_2);
			ZVAL_STRING(_2, "console:beforeStartModule", 0);
			ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, _2, this_ptr, moduleName);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
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
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "phalcon/cli/console.zep", 182 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(module);
		zephir_array_fetch(&module, modules, moduleName, PH_NOISY, "phalcon/cli/console.zep", 185 TSRMLS_CC);
		if (Z_TYPE_P(module) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Invalid module definition path", "phalcon/cli/console.zep", 187);
			return;
		}
		ZEPHIR_OBS_VAR(path);
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
			if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Module definition path '", path, "' doesn't exist");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/cli/console.zep", 192 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		ZEPHIR_OBS_VAR(className);
		if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(className);
			ZVAL_STRING(className, "Module", 1);
		}
		ZEPHIR_CALL_METHOD(&moduleObject, dependencyInjector, "get", NULL, className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerautoloaders", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerservices", NULL, dependencyInjector);
		zephir_check_call_status();
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			zephir_update_property_this(this_ptr, SL("_moduleObject"), moduleObject TSRMLS_CC);
			ZEPHIR_INIT_BNVAR(_2);
			ZVAL_STRING(_2, "console:afterStartModule", 0);
			ZEPHIR_CALL_METHOD(&_5, eventsManager, "fire", NULL, _2, this_ptr, moduleObject);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "dispatcher", 0);
	ZEPHIR_CALL_METHOD(&_5, dependencyInjector, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _5);
	ZEPHIR_CALL_METHOD(&_5, router, "gettaskname",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "settaskname", NULL, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, router, "getactionname",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, router, "getparams",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _7);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_BNVAR(_2);
		ZVAL_STRING(_2, "console:beforeHandleTask", 0);
		ZEPHIR_CALL_METHOD(&_8, eventsManager, "fire", NULL, _2, this_ptr, dispatcher);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, dispatcher, "dispatch",  NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_BNVAR(_2);
		ZVAL_STRING(_2, "console:afterHandleTask", 0);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _2, this_ptr, task);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	RETURN_CCTOR(task);

}


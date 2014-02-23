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

#include "cli/console.h"
#include "cli/console/exception.h"
#include "cli/router.h"
#include "di/injectionawareinterface.h"
#include "events/eventsawareinterface.h"
#include "diinterface.h"
#include "dispatcherinterface.h"
#include "diinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"

#include "interned-strings.h"

/**
 * Phalcon\CLI\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
zend_class_entry *phalcon_cli_console_ce;

PHP_METHOD(Phalcon_CLI_Console, __construct);
PHP_METHOD(Phalcon_CLI_Console, setDI);
PHP_METHOD(Phalcon_CLI_Console, getDI);
PHP_METHOD(Phalcon_CLI_Console, setEventsManager);
PHP_METHOD(Phalcon_CLI_Console, getEventsManager);
PHP_METHOD(Phalcon_CLI_Console, registerModules);
PHP_METHOD(Phalcon_CLI_Console, addModules);
PHP_METHOD(Phalcon_CLI_Console, getModules);
PHP_METHOD(Phalcon_CLI_Console, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_addmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cli_console_method_entry[] = {
	PHP_ME(Phalcon_CLI_Console, __construct, arginfo_phalcon_cli_console___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_CLI_Console, setDI, arginfo_phalcon_cli_console_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, setEventsManager, arginfo_phalcon_cli_console_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, registerModules, arginfo_phalcon_cli_console_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, addModules, arginfo_phalcon_cli_console_addmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\CLI\Console initializer
 */
PHALCON_INIT_CLASS(Phalcon_CLI_Console){

	PHALCON_REGISTER_CLASS(Phalcon\\CLI, Console, cli_console, phalcon_cli_console_method_entry, 0);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_console_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_console_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_console_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cli_console_ce TSRMLS_CC, 2, phalcon_di_injectionawareinterface_ce, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\CLI\Console constructor
 */
PHP_METHOD(Phalcon_CLI_Console, __construct){

	zval *dependency_injector = NULL;

	phalcon_fetch_params(0, 0, 1, &dependency_injector);
	
	if (dependency_injector && Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_CLI_Console, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_cli_console_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_CLI_Console, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_CLI_Console, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_CLI_Console, getEventsManager){


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
 * @param array $modules
 */
PHP_METHOD(Phalcon_CLI_Console, registerModules){

	zval *modules;

	phalcon_fetch_params(0, 1, 0, &modules);
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_cli_console_exception_ce, "Modules must be an Array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
	
}

/**
 * Merge modules with the existing ones
 *
 *<code>
 *	$application->addModules(array(
 *		'admin' => array(
 *			'className' => 'Multiple\Admin\Module',
 *			'path' => '../apps/admin/Module.php'
 *		)
 *	));
 *</code>
 *
 * @param array $modules
 */
PHP_METHOD(Phalcon_CLI_Console, addModules){

	zval *modules, *original_modules, *register_modules;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &modules);
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "Modules must be an Array");
		return;
	}
	
	PHALCON_OBS_VAR(original_modules);
	phalcon_read_property_this(&original_modules, this_ptr, SL("_modules"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(register_modules);
	phalcon_fast_array_merge(register_modules, &modules, &original_modules TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_modules"), register_modules TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return the modules registered in the console
 *
 * @return array
 */
PHP_METHOD(Phalcon_CLI_Console, getModules){


	RETURN_MEMBER(this_ptr, "_modules");
}

/**
 * Handle the command-line arguments.
 *  
 * 
 * <code>
 * 	$arguments = array(
 * 		'task' => 'taskname',
 * 		'action' => 'action',
 * 		'params' => array('parameter1', 'parameter2')
 * 	);
 * 	$console->handle($arguments);
 * </code>
 *
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_CLI_Console, handle){

	zval *arguments = NULL, *dependency_injector, *events_manager;
	zval *service = NULL, *router = NULL, *module_name = NULL, *event_name = NULL;
	zval *status = NULL, *modules, *exception_msg = NULL, *module;
	zval *path, *class_name = NULL, *module_object = NULL, *task_name = NULL;
	zval *action_name = NULL, *params = NULL, *dispatcher = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &arguments);
	
	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_router);
	
	PHALCON_CALL_METHOD(&router, dependency_injector, "getshared", service);
	PHALCON_VERIFY_CLASS(router, phalcon_cli_router_ce);
	PHALCON_CALL_METHOD(NULL, router, "handle", arguments);
	
	PHALCON_CALL_METHOD(&module_name, router, "getmodulename");
	if (zend_is_true(module_name)) {
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "console:beforeStartModule", 1);
	
			PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, module_name);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			}
		}
	
		PHALCON_OBS_VAR(modules);
		phalcon_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY TSRMLS_CC);
		if (!phalcon_array_isset(modules, module_name)) {
			PHALCON_INIT_VAR(exception_msg);
			PHALCON_CONCAT_SVS(exception_msg, "Module '", module_name, "' isn't registered in the console container");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_cli_console_exception_ce, exception_msg);
			return;
		}
	
		PHALCON_OBS_VAR(module);
		phalcon_array_fetch(&module, modules, module_name, PH_NOISY);
		if (Z_TYPE_P(module) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_cli_console_exception_ce, "Invalid module definition path");
			return;
		}
	
		if (phalcon_array_isset_string(module, SS("path"))) {
	
			PHALCON_OBS_VAR(path);
			phalcon_array_fetch_string(&path, module, SL("path"), PH_NOISY);
			convert_to_string_ex(&path);

			if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
				RETURN_MM_ON_FAILURE(phalcon_require(Z_STRVAL_P(path) TSRMLS_CC));
			} else {
				zend_throw_exception_ex(phalcon_cli_console_exception_ce, 0 TSRMLS_CC, "Modules definition path '%s' does not exist", Z_STRVAL_P(path));
				PHALCON_MM_RESTORE();
				return;
			}
		}
	
		if (phalcon_array_isset_string(module, SS("className"))) {
			PHALCON_OBS_VAR(class_name);
			phalcon_array_fetch_string(&class_name, module, SL("className"), PH_NOISY);
		} else {
			PHALCON_INIT_NVAR(class_name);
			ZVAL_STRING(class_name, "Module", 1);
		}
	
		PHALCON_CALL_METHOD(&module_object, dependency_injector, "get", class_name);
		PHALCON_CALL_METHOD(NULL, module_object, "registerautoloaders");
		PHALCON_CALL_METHOD(NULL, module_object, "registerservices", dependency_injector);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			phalcon_update_property_this(this_ptr, SL("_moduleObject"), module_object TSRMLS_CC);
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "console:afterStartModule", 1);
	
			PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, module_name);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			}
		}
	}
	
	PHALCON_CALL_METHOD(&task_name, router, "gettaskname");
	PHALCON_CALL_METHOD(&action_name, router, "getactionname");
	PHALCON_CALL_METHOD(&params, router, "getparams");
	
	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_dispatcher);
	
	PHALCON_CALL_METHOD(&dispatcher, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(dispatcher, phalcon_dispatcherinterface_ce);
	PHALCON_CALL_METHOD(NULL, dispatcher, "settaskname", task_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setactionname", action_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setparams", params);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "console:beforeHandleTask", 1);
	
		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, dispatcher);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_RETURN_CALL_METHOD(dispatcher, "dispatch");
	if (return_value_ptr) {
		return_value = *return_value_ptr;
	}

	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "console:afterHandleTask", 1);
		PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr, return_value);
	}
	
	PHALCON_MM_RESTORE();
}


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
  |          Rack Lin <racklin@gmail.com>                                  |
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
#include "kernel/array.h"
#include "kernel/object.h"

/**
 * Phalcon\CLI\Router
 *
 * <p>Phalcon\CLI\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
 *	$router = new Phalcon\CLI\Router();
 *	$router->handle(array());
 *	echo $router->getTaskName();
 *</code>
 *
 */

PHP_METHOD(Phalcon_CLI_Router, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_cli_router_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_cli_router_ce, this_ptr, SL("_defaultParams"), a1 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_CLI_Router, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_CLI_Router, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the name of the default module
 *
 * @param string $moduleName
 */
PHP_METHOD(Phalcon_CLI_Router, setDefaultModule){

	zval *module_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &module_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultModule"), module_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_CLI_Router, setDefaultTask){

	zval *task_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &task_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultTask"), task_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_CLI_Router, setDefaultAction){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from command-line arguments
 *
 * @param array $arguments
 */
PHP_METHOD(Phalcon_CLI_Router, handle){

	zval *arguments = NULL, *arguments_count = NULL, *params = NULL, *arg = NULL;
	zval *module_name = NULL, *default_module = NULL;
	zval *task_name = NULL, *default_task = NULL, *task_name_tmp = NULL, *task_name_parts = NULL;
	zval *delimiter = NULL, *status = NULL;
	zval *action_name = NULL, *default_action = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_ALLOC_ZVAL_MM(arguments);
		array_init(arguments);
	}

	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cli_router_exception_ce, "Arguments must be an Array");
		return;
	}

	/*
	 * process arguments
	 */
	// initial and set default to null
	PHALCON_INIT_VAR(module_name);
	PHALCON_INIT_VAR(task_name);
	PHALCON_INIT_VAR(task_name_tmp);
	PHALCON_INIT_VAR(action_name);
	PHALCON_INIT_VAR(params);
	PHALCON_INIT_VAR(delimiter);

	array_init(params);

	phalcon_update_property_zval(this_ptr, SL("_module"), module_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_task"), task_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_action"), action_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);

	ZVAL_STRING(delimiter, ":", 1);

	PHALCON_INIT_VAR(arguments_count);
	phalcon_fast_count(arguments_count, arguments TSRMLS_CC);

	if (Z_LVAL_P(arguments_count) > 3) {
		// script, task, action, params.....
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_long(&task_name_tmp, arguments, 1, PH_NOISY_CC);
		phalcon_array_fetch_long(&action_name, arguments, 2, PH_NOISY_CC);

		// process params
		int i;
		for (i = 3; i < Z_LVAL_P(arguments_count); i++) {
			PHALCON_INIT_VAR(arg);
			phalcon_array_fetch_long(&arg, arguments, i, PH_NOISY_CC);
			phalcon_array_append(&params, arg, PH_SEPARATE TSRMLS_CC);
		}
	} else if (Z_LVAL_P(arguments_count) > 2) {
		// script, task, action
		PHALCON_INIT_VAR(task_name_tmp);
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_long(&task_name_tmp, arguments, 1, PH_NOISY_CC);
		phalcon_array_fetch_long(&action_name, arguments, 2, PH_NOISY_CC);
	} else if (Z_LVAL_P(arguments_count) > 1) {
		// script, task
		PHALCON_INIT_VAR(task_name_tmp);
		phalcon_array_fetch_long(&task_name_tmp, arguments, 1, PH_NOISY_CC);
	}

	// if task_name settings, parse task_name for module_name
	if (Z_TYPE_P(task_name_tmp) != IS_NULL) {
		PHALCON_INIT_VAR(task_name_parts);
		phalcon_fast_explode(task_name_parts, delimiter, task_name_tmp TSRMLS_CC);
		PHALCON_INIT_VAR(status);
		phalcon_fast_count(status, task_name_parts TSRMLS_CC);
		if (Z_LVAL_P(status) == 2) {
			PHALCON_INIT_VAR(module_name);
			PHALCON_INIT_VAR(task_name);
			phalcon_array_fetch_long(&module_name, task_name_parts, 0, PH_NOISY_CC);
			phalcon_array_fetch_long(&task_name, task_name_parts, 1, PH_NOISY_CC);
		}else {
			PHALCON_INIT_VAR(task_name);
			phalcon_array_fetch_long(&task_name, task_name_parts, 0, PH_NOISY_CC);
		}
	}

	// update properties
	if (Z_TYPE_P(module_name) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_module"), module_name TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(default_module);
		phalcon_read_property(&default_module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		if (Z_TYPE_P(default_module) != IS_NULL) {
			phalcon_update_property_zval(this_ptr, SL("_module"), default_module TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(module_name);
	phalcon_read_property(&module_name, this_ptr, SL("_module"), PH_NOISY_CC);

	if (Z_TYPE_P(task_name) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_task"), task_name TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(default_task);
		phalcon_read_property(&default_task, this_ptr, SL("_defaultTask"), PH_NOISY_CC);
		if (Z_TYPE_P(default_task) != IS_NULL) {
			phalcon_update_property_zval(this_ptr, SL("_task"), default_task TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(task_name);
	phalcon_read_property(&task_name, this_ptr, SL("_task"), PH_NOISY_CC);

	if (Z_TYPE_P(action_name) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_action"), action_name TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(default_action);
		phalcon_read_property(&default_action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		if (Z_TYPE_P(default_action) != IS_NULL) {
			phalcon_update_property_zval(this_ptr, SL("_action"), default_action TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(action_name);
	phalcon_read_property(&action_name, this_ptr, SL("_action"), PH_NOISY_CC);

	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);

	PHALCON_MM_RESTORE();}

/**
 * Returns proccesed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_CLI_Router, getModuleName){

	zval *module = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(module);
	phalcon_read_property(&module, this_ptr, SL("_module"), PH_NOISY_CC);
	
	RETURN_CCTOR(module);
}

/**
 * Returns proccesed task name
 *
 * @return string
 */
PHP_METHOD(Phalcon_CLI_Router, getTaskName){

	zval *task = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(task);
	phalcon_read_property(&task, this_ptr, SL("_task"), PH_NOISY_CC);
	
	RETURN_CCTOR(task);
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_CLI_Router, getActionName){

	zval *action = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(action);
	phalcon_read_property(&action, this_ptr, SL("_action"), PH_NOISY_CC);
	
	RETURN_CCTOR(action);
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_CLI_Router, getParams){

	zval *params = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(params);
}


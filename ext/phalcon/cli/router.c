
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


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
 * Phalcon\Cli\Router
 *
 * <p>Phalcon\Cli\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
 *	$router = new Phalcon\Cli\Router();
 *	$router->handle(array(
 *		'module' => 'main',
 *		'task' => 'videos',
 *		'action' => 'process'
 *	));
 *	echo $router->getTaskName();
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli, Router, phalcon, cli_router, phalcon_cli_router_method_entry, 0);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_task"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultTask"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cli_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Cli_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Cli_Router, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

		zephir_get_strval(moduleName, moduleName_param);


	zephir_update_property_this(this_ptr, SL("_defaultModule"), moduleName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default controller name
 *
 * @param string taskName
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask) {

	zval *taskName_param = NULL;
	zval *taskName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

		zephir_get_strval(taskName, taskName_param);


	zephir_update_property_this(this_ptr, SL("_defaultTask"), taskName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default action name
 *
 * @param string actionName
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

		zephir_get_strval(actionName, actionName_param);


	zephir_update_property_this(this_ptr, SL("_defaultAction"), actionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles routing information received from command-line arguments
 *
 * @param array arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle) {

	zval *arguments = NULL, *moduleName = NULL, *taskName = NULL, *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments || Z_TYPE_P(arguments) == IS_NULL) {
		ZEPHIR_CPY_WRT(arguments, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(arguments);


	if ((Z_TYPE_P(arguments) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cli_router_exception_ce, "Arguments must be an Array");
		return;
	}
	ZEPHIR_INIT_VAR(moduleName);
	ZVAL_NULL(moduleName);
	ZEPHIR_INIT_VAR(taskName);
	ZVAL_NULL(taskName);
	ZEPHIR_INIT_VAR(actionName);
	ZVAL_NULL(actionName);
	ZEPHIR_OBS_NVAR(moduleName);
	if (zephir_array_isset_string_fetch(&moduleName, arguments, SS("module"), 0 TSRMLS_CC)) {
	}
	ZEPHIR_OBS_NVAR(taskName);
	if (zephir_array_isset_string_fetch(&taskName, arguments, SS("task"), 0 TSRMLS_CC)) {
	}
	ZEPHIR_OBS_NVAR(actionName);
	if (zephir_array_isset_string_fetch(&actionName, arguments, SS("action"), 0 TSRMLS_CC)) {
	}
	zephir_update_property_this(this_ptr, SL("_module"), moduleName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_task"), taskName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_action"), actionName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_params"), arguments TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns proccesed module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cli_Router, getModuleName) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Returns proccesed task name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cli_Router, getTaskName) {


	RETURN_MEMBER(this_ptr, "_task");

}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cli_Router, getActionName) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}


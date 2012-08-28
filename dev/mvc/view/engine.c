
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
#include "kernel/fcall.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\View\Engine
 *
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */

/**
 * Phalcon\Mvc\View\Engine constructor
 *
 * @param Phalcon\Mvc\View $view
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, __construct){

	zval *view = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_view"), view TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, setDI){

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
 * Returns the dependency injection container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getDI){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getControllerName){

	zval *view = NULL, *controller_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(view);
	phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(controller_name);
	PHALCON_CALL_METHOD(controller_name, view, "getcontrollername", PH_NO_CHECK);
	
	RETURN_CCTOR(controller_name);
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getActionName){

	zval *view = NULL, *action_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(view);
	phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(action_name);
	PHALCON_CALL_METHOD(action_name, view, "getactionname", PH_NO_CHECK);
	
	RETURN_CCTOR(action_name);
}

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent){

	zval *view = NULL, *content = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(view);
	phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(content);
	PHALCON_CALL_METHOD(content, view, "getcontent", PH_NO_CHECK);
	
	RETURN_CCTOR(content);
}

/**
 * Generates a external absolute path to an application uri
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, url){

	zval *params = NULL, *dependency_injector = NULL, *url = NULL, *view_url = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_ALLOC_ZVAL_MM(params);
		ZVAL_NULL(params);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the 'url' service");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "url", 1);
	
	PHALCON_INIT_VAR(url);
	PHALCON_CALL_METHOD_PARAMS_1(url, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(view_url);
	PHALCON_CALL_METHOD_PARAMS_1(view_url, url, "get", params, PH_NO_CHECK);
	
	RETURN_CCTOR(view_url);
}

/**
 * Returns a local path
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, path){

	zval *params = NULL, *dependency_injector = NULL, *url = NULL, *view_path = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_ALLOC_ZVAL_MM(params);
		ZVAL_STRING(params, "", 1);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the 'url' service");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "url", 1);
	
	PHALCON_INIT_VAR(url);
	PHALCON_CALL_METHOD_PARAMS_1(url, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(view_path);
	PHALCON_CALL_METHOD_PARAMS_1(view_path, url, "getpath", params, PH_NO_CHECK);
	
	RETURN_CCTOR(view_path);
}

/**
 * Renders a partial inside another view
 *
 * @param string $partialPath
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, partial){

	zval *partial_path = NULL, *view = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(view);
	phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "partial", partial_path, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}



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

/**
 * Phalcon\Mvc\View\Engine
 *
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */


/**
 * Phalcon\Mvc\View\Engine initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Engine, mvc_view_engine, "phalcon\\di\\injectable", phalcon_mvc_view_engine_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_view_engine_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\View\Engine constructor
 *
 * @param Phalcon\Mvc\ViewInterface $view
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, __construct){

	zval *view, *dependency_injector = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &view, &dependency_injector);
	
	if (!dependency_injector) {
		PHALCON_INIT_VAR(dependency_injector);
	}
	
	phalcon_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent){

	zval *view, *content;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(view);
	phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(content);
	phalcon_call_method(content, view, "getcontent");
	RETURN_CCTOR(content);
}

/**
 * Renders a partial inside another view
 *
 * @param string $partialPath
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, partial){

	zval *partial_path, *view, *content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &partial_path);
	
	PHALCON_OBS_VAR(view);
	phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(content);
	phalcon_call_method_p1(content, view, "partial", partial_path);
	RETURN_CCTOR(content);
}

/**
 * Returns the view component related to the adapter
 *
 * @return Phalcon\Mvc\ViewInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getView){


	RETURN_MEMBER(this_ptr, "_view");
}


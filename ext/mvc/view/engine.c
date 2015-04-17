
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
  +------------------------------------------------------------------------+
*/

#include "mvc/view/engine.h"
#include "mvc/view/engineinterface.h"
#include "di/injectable.h"

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
zend_class_entry *phalcon_mvc_view_engine_ce;

PHP_METHOD(Phalcon_Mvc_View_Engine, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent);
PHP_METHOD(Phalcon_Mvc_View_Engine, partial);
PHP_METHOD(Phalcon_Mvc_View_Engine, getView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_view_engine_method_entry[] = {
	PHP_ME(Phalcon_Mvc_View_Engine, __construct, arginfo_phalcon_mvc_view_engine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine, partial, arginfo_phalcon_mvc_view_engineinterface_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine, getView, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\Engine initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Engine, mvc_view_engine, phalcon_di_injectable_ce, phalcon_mvc_view_engine_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_view_engine_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_engine_ce TSRMLS_CC, 1, phalcon_mvc_view_engineinterface_ce);

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

	phalcon_fetch_params(0, 1, 1, &view, &dependency_injector);
	
	if (!dependency_injector) {
		dependency_injector = PHALCON_GLOBAL(z_null);
	}
	
	phalcon_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent)
{
	zval *view = phalcon_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(view, "getcontent");
}

/**
 * Renders a partial inside another view
 *
 * @param string $partialPath
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, partial){

	zval *partial_path, *params = NULL, *view;

	phalcon_fetch_params(0, 1, 1, &partial_path, &params);
	
	if (!params) {
		params = PHALCON_GLOBAL(z_null);
	}
	
	view = phalcon_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(view, "partial", partial_path, params);
}

/**
 * Returns the view component related to the adapter
 *
 * @return Phalcon\Mvc\ViewInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getView){


	RETURN_MEMBER(this_ptr, "_view");
}


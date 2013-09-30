
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


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
/**
 * Phalcon\Mvc\View\Engine
 *
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Engine, phalcon, mvc_view_engine, phalcon_di_injectable_ce, phalcon_mvc_view_engine_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\View\Engine constructor
 *
 * @param Phalcon\Mvc\ViewInterface view
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, __construct) {

	zval *view, *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &view, &dependencyInjector);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent) {

	zval *view;

	ZEPHIR_MM_GROW();

	zephir_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	zephir_call_method(return_value, view, "getcontent");
	RETURN_MM();

}

/**
 * Renders a partial inside another view
 *
 * @param string partialPath
 * @param array params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, partial) {

	zval *partialPath_param = NULL, *params = NULL, *view;
	zval *partialPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

		zephir_get_strval(partialPath, partialPath_param);
	if (!params) {
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
	}


	zephir_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	zephir_call_method_p2(return_value, view, "partial", partialPath, params);
	RETURN_MM();

}

/**
 * Returns the view component related to the adapter
 *
 * @return Phalcon\Mvc\ViewInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getView) {


	RETURN_MEMBER(this_ptr, "_view");

}



#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"


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
 * Phalcon\Mvc\View
 *
 * Phalcon\Mvc\View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * <code>
 * //Setting views directory
 * $view = new Phalcon\Mvc\View();
 * $view->setViewsDir('app/views/');
 *
 * $view->start();
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->render('posts', 'recent');
 * $view->finish();
 *
 * //Printing views output
 * echo $view->getContent();
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, phalcon, View, mvc_view, phalcon_di_injectable_ce, phalcon_mvc_view_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_options"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_basePath"), "", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_content"), "", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_ce, SL("_renderLevel"), 5, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_disabledLevels"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewParams"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_layout"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_layoutsDir"), "", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_partialsDir"), "", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewsDir"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesBefore"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesAfter"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_engines"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_registeredEngines"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_mainView"), "index", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_controllerName"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_actionName"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_params"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_pickView"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_cache"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_ce, SL("_cacheLevel"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_activeRenderPath"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_disabled"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Render Level: To the main layout
 *
 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5 TSRMLS_CC);
/**
 * Render Level: Render to the templates "after"
 *
 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4 TSRMLS_CC);
/**
 * Render Level: Hasta el layout del controlador
 *
 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_LAYOUT"), 3 TSRMLS_CC);
/**
 * Render Level: To the templates "before"
 *
 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2 TSRMLS_CC);
/**
 * Render Level: To the action view
 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_ACTION_VIEW"), 1 TSRMLS_CC);
/**
 * Render Level: No render any view
 *
 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_NO_RENDER"), 0 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\View constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View, __construct) {

	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_INIT_VAR(options);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string viewsDir
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir) {

	zval *viewsDir;

	zephir_fetch_params(0, 1, 0, &viewsDir);



	if (Z_TYPE_P(viewsDir) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "The views directory must be a string");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_viewsDir"), viewsDir TSRMLS_CC);
	RETURN_THISW();

}


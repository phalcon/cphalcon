
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
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hicherquical levels
 *
 *<code>
 * $view = new Phalcon\Mvc\View\Simple();
 * echo $view->render('templates/my-view', array('content' => $html));
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, phalcon, Simple, mvc_view_simple, phalcon_di_injectable_ce, NULL, 0);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_options"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewsDir"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_partialsDir"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewParams"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_engines"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_registeredEngines"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_activeRenderPath"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_content"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_cache"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_cacheOptions"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}


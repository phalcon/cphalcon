
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
 * Phalcon\Mvc\Micro
 *
 * With Phalcon you can create "Micro-Framework like" applications. By doing this, you only need to
 * write a minimal amount of code to create a PHP application. Micro applications are suitable
 * to small applications, APIs and prototypes in a practical way.
 *
 *<code>
 *
 * $app = new Phalcon\Mvc\Micro();
 *
 * $app->get('/say/welcome/{name}', function ($name) {
 *    echo "<h1>Welcome $name!</h1>";
 * });
 *
 * $app->handle();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, phalcon, Micro, mvc_micro, phalcon_di_injectable_ce, NULL, 0);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_dependencyInjector"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_handlers"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_router"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_stopped"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_notFoundHandler"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_activeHandler"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_beforeHandlers"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_afterHandlers"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_finishHandlers"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("_returnedValue"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}


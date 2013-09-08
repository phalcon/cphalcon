
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, phalcon, Collection, mvc_collection, NULL, 0);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_id"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_dependencyInjector"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_modelsManager"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_source"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_operationMade"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_connection"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_errorMessages"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_reserved"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_disableEvents"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_NONE"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_CREATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	return SUCCESS;

}


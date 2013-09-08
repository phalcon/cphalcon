
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
 * Phalcon\Logger\Item
 *
 * Represents each item in a logging transaction
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Item) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, phalcon, Item, logger_item, NULL, 0);

/**
 * Log type
 *
 * @var integer
 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_type"), ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Log message
 *
 * @var string
 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_message"), ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Log timestamp
 *
 * @var integer
 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_time"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}


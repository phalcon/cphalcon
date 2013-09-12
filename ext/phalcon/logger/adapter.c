
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

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
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Adapter, phalcon, logger_adapter, NULL, 0);

/**
 * Tells if there is an active transaction or not
 *
 * @var boolean
 */
	zend_declare_property_bool(phalcon_logger_adapter_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Array with messages queued in the transacction
 *
 * @var array
 */
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Formatter
 *
 * @var object
 */
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Log level
 *
 * @var int
 */
	zend_declare_property_long(phalcon_logger_adapter_ce, SL("_logLevel"), 9, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}


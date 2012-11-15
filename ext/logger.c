
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

/**
 * Phalcon\Logger
 *
 * Phalcon\Logger is a component whose purpose is to create logs using
 * different backends via adapters, generating options, formats and filters
 * also implementing transactions.
 *
 *<code>
 *$logger = new Phalcon\Logger\Adapter\File("app/logs/test.log");
 *$logger->log("This is a message");
 *$logger->log("This is an error", Phalcon\Logger::ERROR);
 *$logger->error("This is another error");
 *$logger->close();
 * </code>
 */


/**
 * Phalcon\Logger initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger){

	PHALCON_REGISTER_CLASS(Phalcon, Logger, logger, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_logger_ce, SL("SPECIAL"), 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("CUSTOM"), 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("DEBUG"), 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("INFO"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("NOTICE"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("WARNING"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("ERROR"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("ALERT"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("CRITICAL"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("EMERGENCE"), 0 TSRMLS_CC);

	return SUCCESS;
}


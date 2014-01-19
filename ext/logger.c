
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

#include "logger.h"

#include "kernel/main.h"

/**
 * Phalcon\Logger
 *
 * Phalcon\Logger is a component whose purpose is create logs using
 * different backends via adapters, generating options, formats and filters
 * also implementing transactions.
 *
 *<code>
 *	$logger = new Phalcon\Logger\Adapter\File("app/logs/test.log");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *</code>
 */
zend_class_entry *phalcon_logger_ce;

/**
 * Phalcon\Logger initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger){

	PHALCON_REGISTER_CLASS(Phalcon, Logger, logger, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_logger_ce, SL("SPECIAL"),   PHALCON_LOGGER_SPECIAL   TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("CUSTOM"),    PHALCON_LOGGER_CUSTOM    TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("DEBUG"),     PHALCON_LOGGER_DEBUG     TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("INFO"),      PHALCON_LOGGER_INFO      TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("NOTICE"),    PHALCON_LOGGER_NOTICE    TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("WARNING"),   PHALCON_LOGGER_WARNING   TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("ERROR"),     PHALCON_LOGGER_ERROR     TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("ALERT"),     PHALCON_LOGGER_ALERT     TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("CRITICAL"),  PHALCON_LOGGER_CRITICAL  TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("EMERGENCE"), PHALCON_LOGGER_EMERGENCY TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("EMERGENCY"), PHALCON_LOGGER_EMERGENCY TSRMLS_CC);

	return SUCCESS;
}

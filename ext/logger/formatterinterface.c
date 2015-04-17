
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

#include "logger/formatterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_logger_formatterinterface_ce;

static const zend_function_entry phalcon_logger_formatterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Logger_FormatterInterface, format, arginfo_phalcon_logger_formatterinterface_format)
	PHP_FE_END
};

/**
 * Phalcon\Logger\FormatterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_FormatterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Logger, FormatterInterface, logger_formatterinterface, phalcon_logger_formatterinterface_method_entry);

	return SUCCESS;
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @param array $context
 */
PHALCON_DOC_METHOD(Phalcon_Logger_FormatterInterface, format);

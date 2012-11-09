
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

#include "kernel/main.h"

/**
 * Phalcon\Logger\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, AdapterInterface, logger_adapterinterface, phalcon_logger_adapterinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Logger_AdapterInterface, setFormat){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, getFormat){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, getTypeString){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, _applyFormat){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, setDateFormat){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, getDateFormat){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, log){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, begin){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, commit){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, rollback){ }

PHP_METHOD(Phalcon_Logger_AdapterInterface, close){ }


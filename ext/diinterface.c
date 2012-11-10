
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
 * Phalcon\DiInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DiInterface){

	PHALCON_REGISTER_CLASS(Phalcon, DiInterface, diinterface, phalcon_diinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_DiInterface, set){ }

PHP_METHOD(Phalcon_DiInterface, remove){ }

PHP_METHOD(Phalcon_DiInterface, attempt){ }

PHP_METHOD(Phalcon_DiInterface, get){ }

PHP_METHOD(Phalcon_DiInterface, getShared){ }

PHP_METHOD(Phalcon_DiInterface, has){ }

PHP_METHOD(Phalcon_DiInterface, wasFreshInstance){ }

PHP_METHOD(Phalcon_DiInterface, setDefault){ }

PHP_METHOD(Phalcon_DiInterface, getDefault){ }

PHP_METHOD(Phalcon_DiInterface, reset){ }


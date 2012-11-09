
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
 * Phalcon\Cache\BackendInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_BackendInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache, BackendInterface, cache_backendinterface, phalcon_cache_backendinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

/**
 * Phalcon\Cache\BackendInterface constructor
 */
PHP_METHOD(Phalcon_Cache_BackendInterface, __construct){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, start){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, stop){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, getFrontend){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, isFresh){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, isStarted){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, getLastKey){ }

PHP_METHOD(Phalcon_Cache_BackendInterface, get){ }


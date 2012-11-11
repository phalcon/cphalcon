
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
 * Phalcon\Cache\FrontendInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_FrontendInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Cache, FrontendInterface, cache_frontendinterface, phalcon_cache_frontendinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the cache lifetime
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, getLifetime);
/**
 * Check whether if frontend is buffering output
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, isBuffering);
/**
 * Starts the frontend
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, start);
/**
 * Returns output cached content
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, getContent);
/**
 * Stops the frontend
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, stop);
/**
 * Serializes data before storing it
 *
 * @param mixed $data
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, beforeStore);
/**
 * Unserializes data after retrieving it
 *
 * @param mixed $data
 */
PHALCON_DOC_METHOD(Phalcon_Cache_FrontendInterface, afterRetrieve);

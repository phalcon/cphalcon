
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

#include "cache/frontendinterface.h"

#include "kernel/main.h"

zend_class_entry *phalcon_cache_frontendinterface_ce;

static const zend_function_entry phalcon_cache_frontendinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getLifetime, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, isBuffering, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, start, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getContent, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, stop, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve)
	PHP_FE_END
};


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

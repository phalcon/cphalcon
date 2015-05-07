
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Cache\FrontendInterface
 *
 * Interface for Phalcon\Cache\Frontend adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_FrontendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cache, FrontendInterface, phalcon, cache_frontendinterface, phalcon_cache_frontendinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the cache lifetime
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, getLifetime);

/**
 * Check whether if frontend is buffering output
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, isBuffering);

/**
 * Starts the frontend
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, start);

/**
 * Returns output cached content
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, getContent);

/**
 * Stops the frontend
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, stop);

/**
 * Serializes data before storing it
 *
 * @param mixed data
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, beforeStore);

/**
 * Unserializes data after retrieving it
 *
 * @param mixed data
 */
ZEPHIR_DOC_METHOD(Phalcon_Cache_FrontendInterface, afterRetrieve);


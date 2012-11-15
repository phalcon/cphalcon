
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

	PHALCON_REGISTER_INTERFACE(Phalcon\\Cache, BackendInterface, cache_backendinterface, phalcon_cache_backendinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontendObject
 * @param array $backendOptions
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, __construct);

/**
 * Starts a cache. The $keyname allows to identify the created fragment
 *
 * @param int|string $keyName
 * @return  mixed
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, start);

/**
 * Stops the frontend without store any cached content
 *
 * @param boolean $stopBuffer
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, stop);

/**
 * Returns front-end instance adapter related to the back-end
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, getFrontend);

/**
 * Checks whether the last cache is fresh or cached
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, isFresh);

/**
 * Checks whether the cache has starting buffering or not
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, isStarted);

/**
 * Gets the last key stored by the cache
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, getLastKey);

/**
 * Returns data from the backend
 */
PHALCON_DOC_METHOD(Phalcon_Cache_BackendInterface, get);



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
 * Phalcon\Mvc\UrlInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_UrlInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, UrlInterface, mvc_urlinterface, phalcon_mvc_urlinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets a prefix to all the urls generated
 *
 * @param string $baseUri
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_UrlInterface, setBaseUri);
/**
 * Returns the prefix for all the generated urls. By default /
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_UrlInterface, getBaseUri);
/**
 * Sets a base paths for all the generated paths
 *
 * @param string $basePath
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_UrlInterface, setBasePath);
/**
 * Returns a base path
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_UrlInterface, getBasePath);
/**
 * Generates a URL
 *
 * @param string|array $uri
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_UrlInterface, get);
/**
 * Generates a local path
 *
 * @param string $path
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_UrlInterface, path);

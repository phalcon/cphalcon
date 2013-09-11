
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Mvc\UrlInterface
 *
 * Interface for Phalcon\Mvc\UrlInterface
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_UrlInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, UrlInterface, phalcon, mvc_urlinterface, phalcon_mvc_urlinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets a prefix to all the urls generated
 *
 * @param string baseUri
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, setBaseUri);

/**
 * Returns the prefix for all the generated urls. By default /
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, getBaseUri);

/**
 * Sets a base paths for all the generated paths
 *
 * @param string basePath
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, setBasePath);

/**
 * Returns a base path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, getBasePath);

/**
 * Generates a URL
 *
 * @param string|array uri
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, get);

/**
 * Generates a local path
 *
 * @param string path
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, path);



#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Url\UrlInterface
 */
ZEPHIR_INIT_CLASS(Phalcon_Url_UrlInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Url, UrlInterface, phalcon, url_urlinterface, phalcon_url_urlinterface_method_entry);

	return SUCCESS;

}

/**
 * Generates a URL
 *
 * @param string|array uri
 * @param array|object args Optional arguments to be appended to the query string
 */
ZEPHIR_DOC_METHOD(Phalcon_Url_UrlInterface, get);
/**
 * Returns a base path
 */
ZEPHIR_DOC_METHOD(Phalcon_Url_UrlInterface, getBasePath);
/**
 * Returns the prefix for all the generated urls. By default /
 */
ZEPHIR_DOC_METHOD(Phalcon_Url_UrlInterface, getBaseUri);
/**
 * Sets a base paths for all the generated paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Url_UrlInterface, setBasePath);
/**
 * Sets a prefix to all the urls generated
 */
ZEPHIR_DOC_METHOD(Phalcon_Url_UrlInterface, setBaseUri);
/**
 * Generates a local path
 */
ZEPHIR_DOC_METHOD(Phalcon_Url_UrlInterface, path);

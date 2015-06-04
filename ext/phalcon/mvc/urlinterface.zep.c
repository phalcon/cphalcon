
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, setBaseUri);

/**
 * Returns the prefix for all the generated urls. By default /
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, getBaseUri);

/**
 * Sets a base paths for all the generated paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, setBasePath);

/**
 * Returns a base path
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_UrlInterface, getBasePath);

/**
 * Generates a URL
 *
 * @param string|array uri
 * @param array|object args Optional arguments to be appended to the query string
 * @param bool $local
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


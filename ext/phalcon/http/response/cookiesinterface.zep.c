
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Http\Response\CookiesInterface
 *
 * Interface for Phalcon\Http\Response\Cookies
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_CookiesInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http\\Response, CookiesInterface, phalcon, http_response_cookiesinterface, phalcon_http_response_cookiesinterface_method_entry);

	return SUCCESS;

}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, useEncryption);

/**
 * Returns if the bag is automatically encrypting/decrypting cookies
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, isUsingEncryption);

/**
 * Sets a cookie to be sent at the end of the request
 *
 * @param string name
 * @param mixed value
 * @param int expire
 * @param string path
 * @param boolean secure
 * @param string domain
 * @param boolean httpOnly
 * @return Phalcon\Http\Response\CookiesInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, set);

/**
 * Gets a cookie from the bag
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, get);

/**
 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, has);

/**
 * Deletes a cookie by its name
 * This method does not removes cookies from the _COOKIE superglobal
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, delete);

/**
 * Sends the cookies to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, send);

/**
 * Reset set cookies
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, reset);



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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Http\Cookie
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_CookieInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http, CookieInterface, phalcon, http_cookieinterface, phalcon_http_cookieinterface_method_entry);

	return SUCCESS;

}

/**
 * Deletes the cookie
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, delete);

/**
 * Returns the domain that the cookie is available to
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getDomain);

/**
 * Returns the current expiration time
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getExpiration);

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getHttpOnly);

/**
 * Returns the current cookie's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getName);

/**
 * Returns the current cookie's path
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getPath);

/**
 * Returns whether the cookie must only be sent when the connection is
 * secure (HTTPS)
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getSecure);

/**
 * Returns the cookie's value.
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getValue);

/**
 * Check if the cookie is using implicit encryption
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, isUsingEncryption);

/**
 * Sends the cookie to the HTTP client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, send);

/**
 * Sets the domain that the cookie is available to
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setDomain);

/**
 * Sets the cookie's expiration time
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setExpiration);

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setHttpOnly);

/**
 * Sets the cookie's expiration time
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setPath);

/**
 * Sets if the cookie must only be sent when the connection is secure
 * (HTTPS)
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setSecure);

/**
 * Sets the cookie's value
 *
 * @param string value
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setValue);

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, useEncryption);


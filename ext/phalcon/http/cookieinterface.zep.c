
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Http\CookieInterface
 *
 * Interface for Phalcon\Http\Cookie
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_CookieInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http, CookieInterface, phalcon, http_cookieinterface, phalcon_http_cookieinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the cookie's value
 *
 * @param string value
 * @return \Phalcon\Http\CookieInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setValue);

/**
 * Returns the cookie's value.
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getValue);

/**
 * Sends the cookie to the HTTP client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, send);

/**
 * Deletes the cookie
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, delete);

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, useEncryption);

/**
 * Check if the cookie is using implicit encryption
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, isUsingEncryption);

/**
 * Sets the cookie's expiration time
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setExpiration);

/**
 * Returns the current expiration time
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getExpiration);

/**
 * Sets the cookie's expiration time
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setPath);

/**
 * Returns the current cookie's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getName);

/**
 * Returns the current cookie's path
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getPath);

/**
 * Sets the domain that the cookie is available to
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setDomain);

/**
 * Returns the domain that the cookie is available to
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getDomain);

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setSecure);

/**
 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getSecure);

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, setHttpOnly);

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_CookieInterface, getHttpOnly);



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

#include "http/response/cookiesinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_http_response_cookiesinterface_ce;

static const zend_function_entry phalcon_http_response_cookiesinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, useEncryption, arginfo_phalcon_http_response_cookiesinterface_useencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, isUsingEncryption, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, set, arginfo_phalcon_http_response_cookiesinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, get, arginfo_phalcon_http_response_cookiesinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, has, arginfo_phalcon_http_response_cookiesinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, delete, arginfo_phalcon_http_response_cookiesinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, reset, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Http\Response\CookiesInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Response_CookiesInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http\\Response, CookiesInterface, http_response_cookiesinterface, phalcon_http_response_cookiesinterface_method_entry);

	return SUCCESS;
}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
 *
 * @param boolean $useEncryption
 * @return Phalcon\Http\Response\CookiesInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, useEncryption);

/**
 * Returns if the bag is automatically encrypting/decrypting cookies
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, isUsingEncryption);

/**
 * Sets a cookie to be sent at the end of the request
 *
 * @param string $name
 * @param mixed $value
 * @param int $expire
 * @param string $path
 * @param boolean $secure
 * @param string $domain
 * @param boolean $httpOnly
 * @return Phalcon\Http\Response\CookiesInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, set);

/**
 * Gets a cookie from the bag
 *
 * @param string $name
 * @return Phalcon\Http\Cookie
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, get);

/**
 * Check if a cookie is defined in the bag or exists in the $_COOKIE superglobal
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, has);

/**
 * Deletes a cookie by its name
 * This method does not removes cookies from the $_COOKIE superglobal
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, delete);

/**
 * Sends the cookies to the client
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, send);

/**
 * Reset set cookies
 *
 * @return Phalcon\Http\Response\CookiesInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_Response_CookiesInterface, reset);

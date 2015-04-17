
<<<<<<< HEAD:ext/phalcon/http/response/cookiesinterface.zep.h
=======
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

#ifndef PHALCON_HTTP_REQUEST_COOKIESINTERFACE_H
#define PHALCON_HTTP_REQUEST_COOKIESINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/http/response/cookiesinterface.h
extern zend_class_entry *phalcon_http_response_cookiesinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_CookiesInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/http/response/cookiesinterface.zep.h
ZEPHIR_INIT_FUNCS(phalcon_http_response_cookiesinterface_method_entry) {
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
=======
#endif /* PHALCON_HTTP_REQUEST_COOKIESINTERFACE_H */
>>>>>>> master:ext/http/response/cookiesinterface.h

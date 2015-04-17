
<<<<<<< HEAD:ext/phalcon/http/response/cookies.zep.h
extern zend_class_entry *phalcon_http_response_cookies_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Cookies);

PHP_METHOD(Phalcon_Http_Response_Cookies, setDI);
PHP_METHOD(Phalcon_Http_Response_Cookies, getDI);
PHP_METHOD(Phalcon_Http_Response_Cookies, useEncryption);
PHP_METHOD(Phalcon_Http_Response_Cookies, isUsingEncryption);
PHP_METHOD(Phalcon_Http_Response_Cookies, set);
PHP_METHOD(Phalcon_Http_Response_Cookies, get);
PHP_METHOD(Phalcon_Http_Response_Cookies, has);
PHP_METHOD(Phalcon_Http_Response_Cookies, delete);
PHP_METHOD(Phalcon_Http_Response_Cookies, send);
PHP_METHOD(Phalcon_Http_Response_Cookies, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()
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

#ifndef PHALCON_HTTP_RESPONSE_COOKIES_H
#define PHALCON_HTTP_RESPONSE_COOKIES_H
>>>>>>> master:ext/http/response/cookies.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_http_response_cookies_ce;

<<<<<<< HEAD:ext/phalcon/http/response/cookies.zep.h
ZEPHIR_INIT_FUNCS(phalcon_http_response_cookies_method_entry) {
	PHP_ME(Phalcon_Http_Response_Cookies, setDI, arginfo_phalcon_http_response_cookies_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, useEncryption, arginfo_phalcon_http_response_cookies_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, isUsingEncryption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, set, arginfo_phalcon_http_response_cookies_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, get, arginfo_phalcon_http_response_cookies_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, has, arginfo_phalcon_http_response_cookies_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, delete, arginfo_phalcon_http_response_cookies_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, reset, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies);

#endif /* PHALCON_HTTP_RESPONSE_COOKIES_H */
>>>>>>> master:ext/http/response/cookies.h

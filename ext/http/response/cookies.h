
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

extern zend_class_entry *phalcon_http_response_cookies_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies);

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
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_cookies_method_entry){
	PHP_ME(Phalcon_Http_Response_Cookies, setDI, arginfo_phalcon_http_response_cookies_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, useEncryption, arginfo_phalcon_http_response_cookies_useencryption, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, isUsingEncryption, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, set, arginfo_phalcon_http_response_cookies_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, get, arginfo_phalcon_http_response_cookies_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, has, arginfo_phalcon_http_response_cookies_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, send, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


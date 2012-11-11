
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

extern zend_class_entry *phalcon_http_cookie_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Cookie);

PHP_METHOD(Phalcon_Http_Cookie, __construct);
PHP_METHOD(Phalcon_Http_Cookie, setDI);
PHP_METHOD(Phalcon_Http_Cookie, getDI);
PHP_METHOD(Phalcon_Http_Cookie, get);
PHP_METHOD(Phalcon_Http_Cookie, setValue);
PHP_METHOD(Phalcon_Http_Cookie, setExpiration);
PHP_METHOD(Phalcon_Http_Cookie, getValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_cookie_method_entry){
	PHP_ME(Phalcon_Http_Cookie, __construct, arginfo_phalcon_http_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Http_Cookie, setDI, arginfo_phalcon_http_cookie_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, get, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, setValue, arginfo_phalcon_http_cookie_setvalue, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, setExpiration, arginfo_phalcon_http_cookie_setexpiration, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


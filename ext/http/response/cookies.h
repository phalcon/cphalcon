
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

extern zend_class_entry *phalcon_http_response_cookies_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies);

PHP_METHOD(Phalcon_Http_Response_Cookies, __construct);
PHP_METHOD(Phalcon_Http_Response_Cookies, set);
PHP_METHOD(Phalcon_Http_Response_Cookies, get);
PHP_METHOD(Phalcon_Http_Response_Cookies, reset);

PHALCON_INIT_FUNCS(phalcon_http_response_cookies_method_entry){
	PHP_ME(Phalcon_Http_Response_Cookies, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Http_Response_Cookies, set, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, get, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


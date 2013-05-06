
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

extern zend_class_entry *phalcon_cache_frontend_json_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Json);

PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Json, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Json, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Json, start);
PHP_METHOD(Phalcon_Cache_Frontend_Json, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Json, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_json_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Json, __construct, arginfo_phalcon_cache_frontend_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_Json, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Json, isBuffering, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Json, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Json, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Json, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Json, beforeStore, arginfo_phalcon_cache_frontend_json_beforestore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Json, afterRetrieve, arginfo_phalcon_cache_frontend_json_afterretrieve, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


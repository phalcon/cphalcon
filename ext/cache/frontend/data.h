
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

extern zend_class_entry *phalcon_cache_frontend_data_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Data);

PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Data, start);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Data, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_data_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Data, __construct, arginfo_phalcon_cache_frontend_data___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_Data, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, isBuffering, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, beforeStore, arginfo_phalcon_cache_frontend_data_beforestore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, afterRetrieve, arginfo_phalcon_cache_frontend_data_afterretrieve, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


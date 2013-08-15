
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

#ifndef PHALCON_CACHE_FRONTEND_DATA_H
#define PHALCON_CACHE_FRONTEND_DATA_H

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

PHALCON_INIT_FUNCS(phalcon_cache_frontend_data_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Data, __construct, arginfo_phalcon_cache_frontend_data___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_Data, getLifetime, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, isBuffering, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, start, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, getContent, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, stop, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif /* PHALCON_CACHE_FRONTEND_DATA_H */

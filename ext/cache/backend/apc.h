
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

extern zend_class_entry *phalcon_cache_backend_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Apc);

PHP_METHOD(Phalcon_Cache_Backend_Apc, get);
PHP_METHOD(Phalcon_Cache_Backend_Apc, save);
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete);
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Apc, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_apc_method_entry){
	PHP_ME(Phalcon_Cache_Backend_Apc, get, arginfo_phalcon_cache_backend_apc_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, save, arginfo_phalcon_cache_backend_apc_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, delete, arginfo_phalcon_cache_backend_apc_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, queryKeys, arginfo_phalcon_cache_backend_apc_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, exists, arginfo_phalcon_cache_backend_apc_exists, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


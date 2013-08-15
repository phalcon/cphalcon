
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

extern zend_class_entry *phalcon_cache_backend_mongo_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Mongo);

PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_empty, 0, 0, 0)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_mongo_method_entry){
	PHP_ME(Phalcon_Cache_Backend_Mongo, __construct, arginfo_phalcon_cache_backend_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, _getCollection, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, get, arginfo_phalcon_cache_backend_mongo_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, save, arginfo_phalcon_cache_backend_mongo_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, delete, arginfo_phalcon_cache_backend_mongo_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, queryKeys, arginfo_phalcon_cache_backend_mongo_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, exists, arginfo_phalcon_cache_backend_mongo_exists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, gc, arginfo_phalcon_cache_backend_mongo_empty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


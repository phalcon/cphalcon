
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

extern zend_class_entry *phalcon_cache_backend_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memory);

PHP_METHOD(Phalcon_Cache_Backend_Memory, get);
PHP_METHOD(Phalcon_Cache_Backend_Memory, save);
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete);
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists);
PHP_METHOD(Phalcon_Cache_Backend_Memory, increment);
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_memory_method_entry){
	PHP_ME(Phalcon_Cache_Backend_Memory, get, arginfo_phalcon_cache_backend_memory_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, save, arginfo_phalcon_cache_backend_memory_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, delete, arginfo_phalcon_cache_backend_memory_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, queryKeys, arginfo_phalcon_cache_backend_memory_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, exists, arginfo_phalcon_cache_backend_memory_exists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, increment, arginfo_phalcon_cache_backend_memory_increment, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, decrement, arginfo_phalcon_cache_backend_memory_decrement, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memory, flush, arginfo_phalcon_cache_backend_memory_decrement, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


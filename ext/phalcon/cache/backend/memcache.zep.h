
<<<<<<< HEAD:ext/phalcon/cache/backend/memcache.zep.h
extern zend_class_entry *phalcon_cache_backend_memcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memcache);

PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, get);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, increment);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
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

#ifndef PHALCON_CACHE_BACKEND_MEMCACHE_H
#define PHALCON_CACHE_BACKEND_MEMCACHE_H
>>>>>>> master:ext/cache/backend/memcache.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_cache_backend_memcache_ce;

<<<<<<< HEAD:ext/phalcon/cache/backend/memcache.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_memcache_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Memcache, __construct, arginfo_phalcon_cache_backend_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Memcache, _connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, get, arginfo_phalcon_cache_backend_memcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, save, arginfo_phalcon_cache_backend_memcache_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, delete, arginfo_phalcon_cache_backend_memcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, queryKeys, arginfo_phalcon_cache_backend_memcache_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, exists, arginfo_phalcon_cache_backend_memcache_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, increment, arginfo_phalcon_cache_backend_memcache_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, decrement, arginfo_phalcon_cache_backend_memcache_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, flush, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memcache);

#endif /* PHALCON_CACHE_BACKEND_MEMCACHE_H */
>>>>>>> master:ext/cache/backend/memcache.h

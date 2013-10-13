
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

extern zend_class_entry *phalcon_cache_backend_file_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_File);

PHP_METHOD(Phalcon_Cache_Backend_File, __construct);
PHP_METHOD(Phalcon_Cache_Backend_File, get);
PHP_METHOD(Phalcon_Cache_Backend_File, save);
PHP_METHOD(Phalcon_Cache_Backend_File, delete);
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_File, exists);
PHP_METHOD(Phalcon_Cache_Backend_File, increment);
PHP_METHOD(Phalcon_Cache_Backend_File, decrement);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_file_method_entry){
	PHP_ME(Phalcon_Cache_Backend_File, __construct, arginfo_phalcon_cache_backend_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend_File, get, arginfo_phalcon_cache_backend_file_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, save, arginfo_phalcon_cache_backend_file_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, delete, arginfo_phalcon_cache_backend_file_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, queryKeys, arginfo_phalcon_cache_backend_file_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, exists, arginfo_phalcon_cache_backend_file_exists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, increment, arginfo_phalcon_cache_backend_file_increment, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, decrement, arginfo_phalcon_cache_backend_file_decrement, ZEND_ACC_PUBLIC)  
	PHP_FE_END
};


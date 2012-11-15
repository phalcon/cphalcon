
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

extern zend_class_entry *phalcon_cache_backendinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_BackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontendObject)
	ZEND_ARG_INFO(0, backendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backendinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, __construct, arginfo_phalcon_cache_backendinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, start, arginfo_phalcon_cache_backendinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, stop, arginfo_phalcon_cache_backendinterface_stop)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getFrontend, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getLastKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, get, arginfo_phalcon_cache_backendinterface_get)
	PHP_FE_END
};


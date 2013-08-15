
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

#ifndef PHALCON_CACHE_FRONTENDINTERFACE_H
#define PHALCON_CACHE_FRONTENDINTERFACE_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_cache_frontendinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_FrontendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_empty, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontendinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getLifetime, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, isBuffering, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, start, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getContent, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, stop, arginfo_phalcon_cache_frontendinterface_empty)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve)
	PHP_FE_END
};

#endif /* PHALCON_CACHE_FRONTENDINTERFACE_H */


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

#ifndef PHALCON_CACHE_FRONTEND_NONE_H
#define PHALCON_CACHE_FRONTEND_NONE_H

#include "cache/frontendinterface.h"

extern zend_class_entry *phalcon_cache_frontend_none_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_None);

PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve);

PHALCON_INIT_FUNCS(phalcon_cache_frontend_none_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_None, getLifetime, arginfo_phalcon_cache_frontendinterface_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif /* PHALCON_CACHE_FRONTEND_NONE_H */

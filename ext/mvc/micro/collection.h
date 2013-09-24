
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

extern zend_class_entry *phalcon_mvc_micro_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_Collection);

PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_setlazy, 0, 0, 1)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_micro_collection_method_entry){
	PHP_ME(Phalcon_Mvc_Micro_Collection, setPrefix, arginfo_phalcon_mvc_micro_collection_setprefix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandlers, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, setHandler, arginfo_phalcon_mvc_micro_collection_sethandler, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, setLazy, arginfo_phalcon_mvc_micro_collection_setlazy, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, isLazy, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandler, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, map, arginfo_phalcon_mvc_micro_collection_map, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, get, arginfo_phalcon_mvc_micro_collection_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, post, arginfo_phalcon_mvc_micro_collection_post, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, put, arginfo_phalcon_mvc_micro_collection_put, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, patch, arginfo_phalcon_mvc_micro_collection_patch, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, head, arginfo_phalcon_mvc_micro_collection_head, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, delete, arginfo_phalcon_mvc_micro_collection_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, options, arginfo_phalcon_mvc_micro_collection_options, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


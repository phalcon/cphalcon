
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

extern zend_class_entry *phalcon_mvc_router_group_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Group);

PHP_METHOD(Phalcon_Mvc_Router_Group, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute);
PHP_METHOD(Phalcon_Mvc_Router_Group, add);
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete);
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions);
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead);
PHP_METHOD(Phalcon_Mvc_Router_Group, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_router_group_method_entry){
	PHP_ME(Phalcon_Mvc_Router_Group, __construct, arginfo_phalcon_mvc_router_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Router_Group, setPrefix, arginfo_phalcon_mvc_router_group_setprefix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, getPrefix, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, setPaths, arginfo_phalcon_mvc_router_group_setpaths, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, getRoutes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, _addRoute, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Router_Group, add, arginfo_phalcon_mvc_router_group_add, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addGet, arginfo_phalcon_mvc_router_group_addget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addPost, arginfo_phalcon_mvc_router_group_addpost, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addPut, arginfo_phalcon_mvc_router_group_addput, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addPatch, arginfo_phalcon_mvc_router_group_addpatch, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addDelete, arginfo_phalcon_mvc_router_group_adddelete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addOptions, arginfo_phalcon_mvc_router_group_addoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, addHead, arginfo_phalcon_mvc_router_group_addhead, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Group, clear, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


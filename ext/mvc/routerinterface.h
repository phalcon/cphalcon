
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

extern zend_class_entry *phalcon_mvc_routerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_routerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultModule, arginfo_phalcon_mvc_routerinterface_setdefaultmodule)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultController, arginfo_phalcon_mvc_routerinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultAction, arginfo_phalcon_mvc_routerinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaults, arginfo_phalcon_mvc_routerinterface_setdefaults)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, handle, arginfo_phalcon_mvc_routerinterface_handle)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, add, arginfo_phalcon_mvc_routerinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addGet, arginfo_phalcon_mvc_routerinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPost, arginfo_phalcon_mvc_routerinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPut, arginfo_phalcon_mvc_routerinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addDelete, arginfo_phalcon_mvc_routerinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addOptions, arginfo_phalcon_mvc_routerinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addHead, arginfo_phalcon_mvc_routerinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getModuleName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatchedRoute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatches, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, wasMatched, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteById, arginfo_phalcon_mvc_routerinterface_getroutebyid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteByName, arginfo_phalcon_mvc_routerinterface_getroutebyname)
	PHP_FE_END
};


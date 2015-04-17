
<<<<<<< HEAD:ext/phalcon/mvc/router/routeinterface.zep.h
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

#ifndef PHALCON_MVC_ROUTER_ROUTEINTERFACE_H
#define PHALCON_MVC_ROUTER_ROUTEINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/mvc/router/routeinterface.h
extern zend_class_entry *phalcon_mvc_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/mvc/router/routeinterface.zep.h
ZEPHIR_INIT_FUNCS(phalcon_mvc_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, __construct, arginfo_phalcon_mvc_router_routeinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, compilePattern, arginfo_phalcon_mvc_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, via, arginfo_phalcon_mvc_router_routeinterface_via)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, reConfigure, arginfo_phalcon_mvc_router_routeinterface_reconfigure)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setName, arginfo_phalcon_mvc_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setHttpMethods, arginfo_phalcon_mvc_router_routeinterface_sethttpmethods)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getRouteId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getReversedPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getHttpMethods, NULL)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
#endif /* PHALCON_MVC_ROUTER_ROUTEINTERFACE_H */
>>>>>>> master:ext/mvc/router/routeinterface.h

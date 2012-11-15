
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

extern zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_dispatcherinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getLastController, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getActiveController, NULL)
	PHP_FE_END
};


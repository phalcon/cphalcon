
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

extern zend_class_entry *phalcon_di_serviceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DI_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_serviceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, __construct, arginfo_phalcon_di_serviceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setShared, arginfo_phalcon_di_serviceinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, isShared, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getDefinition, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, resolve, arginfo_phalcon_di_serviceinterface_resolve)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_di_serviceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};


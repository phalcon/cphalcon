
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

extern zend_class_entry *phalcon_loader_ce;

PHALCON_INIT_CLASS(Phalcon_Loader);

PHP_METHOD(Phalcon_Loader, __construct);
PHP_METHOD(Phalcon_Loader, setEventsManager);
PHP_METHOD(Phalcon_Loader, getEventsManager);
PHP_METHOD(Phalcon_Loader, setExtensions);
PHP_METHOD(Phalcon_Loader, registerNamespaces);
PHP_METHOD(Phalcon_Loader, registerPrefixes);
PHP_METHOD(Phalcon_Loader, registerDirs);
PHP_METHOD(Phalcon_Loader, registerClasses);
PHP_METHOD(Phalcon_Loader, register);
PHP_METHOD(Phalcon_Loader, unregister);
PHP_METHOD(Phalcon_Loader, autoLoad);
PHP_METHOD(Phalcon_Loader, getFoundPath);
PHP_METHOD(Phalcon_Loader, getCheckedPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_setextensions, 0, 0, 1)
	ZEND_ARG_INFO(0, extensions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registernamespaces, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerprefixes, 0, 0, 1)
	ZEND_ARG_INFO(0, prefixes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerdirs, 0, 0, 1)
	ZEND_ARG_INFO(0, directories)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerclasses, 0, 0, 1)
	ZEND_ARG_INFO(0, classes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_loader_method_entry){
	PHP_ME(Phalcon_Loader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Loader, setEventsManager, arginfo_phalcon_loader_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, setExtensions, arginfo_phalcon_loader_setextensions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerNamespaces, arginfo_phalcon_loader_registernamespaces, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerPrefixes, arginfo_phalcon_loader_registerprefixes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerDirs, arginfo_phalcon_loader_registerdirs, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerClasses, arginfo_phalcon_loader_registerclasses, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, register, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, unregister, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, autoLoad, arginfo_phalcon_loader_autoload, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getFoundPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getCheckedPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


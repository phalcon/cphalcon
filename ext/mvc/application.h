
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
  |          Antonio Lopez <alantonilopez@gmail.com>                       |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_application_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Application);

PHP_METHOD(Phalcon_Mvc_Application, registerModules);
PHP_METHOD(Phalcon_Mvc_Application, getModules);
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Application, getDefaultModule);
PHP_METHOD(Phalcon_Mvc_Application, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_application_method_entry){
	PHP_ME(Phalcon_Mvc_Application, registerModules, arginfo_phalcon_mvc_application_registermodules, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Application, getModules, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Application, setDefaultModule, arginfo_phalcon_mvc_application_setdefaultmodule, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Application, getDefaultModule, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Application, handle, arginfo_phalcon_mvc_application_handle, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_cli_router_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Router);

PHP_METHOD(Phalcon_CLI_Router, __construct);
PHP_METHOD(Phalcon_CLI_Router, setDI);
PHP_METHOD(Phalcon_CLI_Router, getDI);
PHP_METHOD(Phalcon_CLI_Router, setDefaultModule);
PHP_METHOD(Phalcon_CLI_Router, setDefaultTask);
PHP_METHOD(Phalcon_CLI_Router, setDefaultAction);
PHP_METHOD(Phalcon_CLI_Router, handle);
PHP_METHOD(Phalcon_CLI_Router, getModuleName);
PHP_METHOD(Phalcon_CLI_Router, getTaskName);
PHP_METHOD(Phalcon_CLI_Router, getActionName);
PHP_METHOD(Phalcon_CLI_Router, getParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cli_router_method_entry){
	PHP_ME(Phalcon_CLI_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_CLI_Router, setDI, arginfo_phalcon_cli_router_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, setDefaultModule, arginfo_phalcon_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, setDefaultTask, arginfo_phalcon_cli_router_setdefaulttask, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, setDefaultAction, arginfo_phalcon_cli_router_setdefaultaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, handle, arginfo_phalcon_cli_router_handle, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getModuleName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getTaskName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


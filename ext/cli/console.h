
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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_cli_console_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Console);

PHP_METHOD(Phalcon_CLI_Console, __construct);
PHP_METHOD(Phalcon_CLI_Console, setDI);
PHP_METHOD(Phalcon_CLI_Console, getDI);
PHP_METHOD(Phalcon_CLI_Console, setEventsManager);
PHP_METHOD(Phalcon_CLI_Console, getEventsManager);
PHP_METHOD(Phalcon_CLI_Console, registerModules);
PHP_METHOD(Phalcon_CLI_Console, addModules);
PHP_METHOD(Phalcon_CLI_Console, getModules);
PHP_METHOD(Phalcon_CLI_Console, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_addmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cli_console_method_entry){
	PHP_ME(Phalcon_CLI_Console, __construct, arginfo_phalcon_cli_console___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_CLI_Console, setDI, arginfo_phalcon_cli_console_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, setEventsManager, arginfo_phalcon_cli_console_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, registerModules, arginfo_phalcon_cli_console_registermodules, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, addModules, arginfo_phalcon_cli_console_addmodules, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, getModules, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


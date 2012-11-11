
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
  |          Nikolaos Dimopoulos <nikos@niden.net>                         |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_di_ce;

PHALCON_INIT_CLASS(Phalcon_DI);

PHP_METHOD(Phalcon_DI, __construct);
PHP_METHOD(Phalcon_DI, set);
PHP_METHOD(Phalcon_DI, remove);
PHP_METHOD(Phalcon_DI, attempt);
PHP_METHOD(Phalcon_DI, _factory);
PHP_METHOD(Phalcon_DI, get);
PHP_METHOD(Phalcon_DI, getShared);
PHP_METHOD(Phalcon_DI, has);
PHP_METHOD(Phalcon_DI, wasFreshInstance);
PHP_METHOD(Phalcon_DI, __call);
PHP_METHOD(Phalcon_DI, setDefault);
PHP_METHOD(Phalcon_DI, getDefault);
PHP_METHOD(Phalcon_DI, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_set, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di__factory, 0, 0, 2)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_get, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_has, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_method_entry){
	PHP_ME(Phalcon_DI, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_DI, set, arginfo_phalcon_di_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, _factory, arginfo_phalcon_di__factory, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, get, arginfo_phalcon_di_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getShared, arginfo_phalcon_di_getshared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, wasFreshInstance, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, setDefault, arginfo_phalcon_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_DI, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_DI, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};


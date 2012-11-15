
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

extern zend_class_entry *phalcon_mvc_view_engine_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine);

PHP_METHOD(Phalcon_Mvc_View_Engine, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent);
PHP_METHOD(Phalcon_Mvc_View_Engine, partial);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engine_method_entry){
	PHP_ME(Phalcon_Mvc_View_Engine, __construct, arginfo_phalcon_mvc_view_engine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_View_Engine, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine, partial, arginfo_phalcon_mvc_view_engine_partial, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


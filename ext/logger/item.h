
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_logger_item_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Item);

PHP_METHOD(Phalcon_Logger_Item, __construct);
PHP_METHOD(Phalcon_Logger_Item, getMessage);
PHP_METHOD(Phalcon_Logger_Item, getType);
PHP_METHOD(Phalcon_Logger_Item, getTime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_item_method_entry){
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger_Item, getMessage, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Item, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Item, getTime, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


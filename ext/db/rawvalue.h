
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

extern zend_class_entry *phalcon_db_rawvalue_ce;

PHALCON_INIT_CLASS(Phalcon_Db_RawValue);

PHP_METHOD(Phalcon_Db_RawValue, __construct);
PHP_METHOD(Phalcon_Db_RawValue, getValue);
PHP_METHOD(Phalcon_Db_RawValue, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_rawvalue_method_entry){
	PHP_ME(Phalcon_Db_RawValue, __construct, arginfo_phalcon_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_RawValue, getValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_RawValue, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


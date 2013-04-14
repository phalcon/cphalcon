
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
  |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_db_adapter_pdo_oracle_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Oracle);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_oracle_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_oracle_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_oracle_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_oracle_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, connect, arginfo_phalcon_db_adapter_pdo_oracle_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns, arginfo_phalcon_db_adapter_pdo_oracle_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId, arginfo_phalcon_db_adapter_pdo_oracle_lastinsertid, ZEND_ACC_PUBLIC)  
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


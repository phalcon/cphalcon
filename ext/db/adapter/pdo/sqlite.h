
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

extern zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, escapeIdentifier);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_sqlite_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, connect, arginfo_phalcon_db_adapter_pdo_sqlite_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_sqlite_escapeidentifier, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns, arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes, arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences, arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};


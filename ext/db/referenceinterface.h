
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

extern zend_class_entry *phalcon_db_referenceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ReferenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, referenceName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_referenceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, __construct, arginfo_phalcon_db_referenceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedTable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedColumns, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_referenceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};


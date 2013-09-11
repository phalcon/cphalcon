
extern zend_class_entry *phalcon_db_referenceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ReferenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, referenceName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___set_state, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_referenceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, __construct, arginfo_phalcon_db_referenceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedTable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, __set_state, arginfo_phalcon_db_referenceinterface___set_state)
	PHP_FE_END
};

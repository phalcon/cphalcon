
extern zend_class_entry *phalcon_db_indexinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, indexName)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___set_state, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_indexinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, __construct, arginfo_phalcon_db_indexinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, __set_state, arginfo_phalcon_db_indexinterface___set_state)
	PHP_FE_END
};


extern zend_class_entry *phalcon_db_indexinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_indexinterface_getcolumns, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_indexinterface_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_indexinterface_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_indexinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, arginfo_phalcon_db_indexinterface_getcolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, arginfo_phalcon_db_indexinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getType, arginfo_phalcon_db_indexinterface_gettype)
	PHP_FE_END
};

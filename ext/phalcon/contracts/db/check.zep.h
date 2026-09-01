
extern zend_class_entry *phalcon_contracts_db_check_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Check);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_check_getexpression, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_check_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_db_check_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Check, getExpression, arginfo_phalcon_contracts_db_check_getexpression)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Check, getName, arginfo_phalcon_contracts_db_check_getname)
	PHP_FE_END
};


extern zend_class_entry *phalcon_db_exceptions_unsupportedoperator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Exceptions_UnsupportedOperator);

PHP_METHOD(Phalcon_Db_Exceptions_UnsupportedOperator, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_exceptions_unsupportedoperator___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, operator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_exceptions_unsupportedoperator_method_entry) {
	PHP_ME(Phalcon_Db_Exceptions_UnsupportedOperator, __construct, arginfo_phalcon_db_exceptions_unsupportedoperator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

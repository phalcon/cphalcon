
extern zend_class_entry *phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exceptions_MissingEagerKeyColumn);

PHP_METHOD(Phalcon_Mvc_Model_Exceptions_MissingEagerKeyColumn, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_exceptions_missingeagerkeycolumn___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_exceptions_missingeagerkeycolumn_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Exceptions_MissingEagerKeyColumn, __construct, arginfo_phalcon_mvc_model_exceptions_missingeagerkeycolumn___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

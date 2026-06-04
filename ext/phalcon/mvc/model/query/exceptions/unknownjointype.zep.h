
extern zend_class_entry *phalcon_mvc_model_query_exceptions_unknownjointype_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Exceptions_UnknownJoinType);

PHP_METHOD(Phalcon_Mvc_Model_Query_Exceptions_UnknownJoinType, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_exceptions_unknownjointype___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_exceptions_unknownjointype_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Exceptions_UnknownJoinType, __construct, arginfo_phalcon_mvc_model_query_exceptions_unknownjointype___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

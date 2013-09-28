
extern zend_class_entry *phalcon_mvc_model_query_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder);

PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_builder_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, from, arginfo_phalcon_mvc_model_query_builder_from, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, columns, arginfo_phalcon_mvc_model_query_builder_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, limit, arginfo_phalcon_mvc_model_query_builder_limit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

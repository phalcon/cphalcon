
extern zend_class_entry *phalcon_mvc_model_query_lang_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang);

PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_query_lang_parsephql, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_lang_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Lang, parsePHQL, arginfo_phalcon_mvc_model_query_lang_parsephql, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

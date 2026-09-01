
extern zend_class_entry *phalcon_mvc_model_eager_pathtree_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Eager_PathTree);

PHP_METHOD(Phalcon_Mvc_Model_Eager_PathTree, parse);
PHP_METHOD(Phalcon_Mvc_Model_Eager_PathTree, assertOptions);
PHP_METHOD(Phalcon_Mvc_Model_Eager_PathTree, insert);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_pathtree_parse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, spec, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_pathtree_assertoptions, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_pathtree_insert, 0, 5, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, tree, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, segments, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_eager_pathtree_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Eager_PathTree, parse, arginfo_phalcon_mvc_model_eager_pathtree_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Eager_PathTree, assertOptions, arginfo_phalcon_mvc_model_eager_pathtree_assertoptions, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Eager_PathTree, insert, arginfo_phalcon_mvc_model_eager_pathtree_insert, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};

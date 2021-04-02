
extern zend_class_entry *phalcon_helper_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Helper_Json);

PHP_METHOD(Phalcon_Helper_Json, decode);
PHP_METHOD(Phalcon_Helper_Json, encode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_helper_json_decode, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_json_encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_helper_json_method_entry) {
	PHP_ME(Phalcon_Helper_Json, decode, arginfo_phalcon_helper_json_decode, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Helper_Json, encode, arginfo_phalcon_helper_json_encode, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

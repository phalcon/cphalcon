
extern zend_class_entry *phalcon_helper_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Helper_Json);

PHP_METHOD(Phalcon_Helper_Json, decode);
PHP_METHOD(Phalcon_Helper_Json, encode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_helper_json_decode, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, associative)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, options)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_json_encode, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_json_encode, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, options)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_helper_json_method_entry) {
	PHP_ME(Phalcon_Helper_Json, decode, arginfo_phalcon_helper_json_decode, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Helper_Json, encode, arginfo_phalcon_helper_json_encode, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

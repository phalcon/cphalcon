
extern zend_class_entry *phalcon_support_helper_json_exceptions_jsondecodeerror_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Json_Exceptions_JsonDecodeError);

PHP_METHOD(Phalcon_Support_Helper_Json_Exceptions_JsonDecodeError, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helper_json_exceptions_jsondecodeerror___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, message, IS_STRING, 0, "''")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, code, IS_LONG, 0, "0")
	ZEND_ARG_OBJ_TYPE_MASK(0, previous, Throwable, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_json_exceptions_jsondecodeerror_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Json_Exceptions_JsonDecodeError, __construct, arginfo_phalcon_support_helper_json_exceptions_jsondecodeerror___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

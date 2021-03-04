
extern zend_class_entry *phalcon_logger_formatter_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json);

PHP_METHOD(Phalcon_Logger_Formatter_Json, __construct);
PHP_METHOD(Phalcon_Logger_Formatter_Json, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_json___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, dateFormat, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_json_format, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_json_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Json, __construct, arginfo_phalcon_logger_formatter_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Formatter_Json, format, arginfo_phalcon_logger_formatter_json_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

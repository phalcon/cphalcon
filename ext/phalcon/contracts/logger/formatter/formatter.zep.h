
extern zend_class_entry *phalcon_contracts_logger_formatter_formatter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_Formatter_Formatter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_formatter_formatter_format, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_logger_formatter_formatter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Formatter_Formatter, format, arginfo_phalcon_contracts_logger_formatter_formatter_format)
	PHP_FE_END
};

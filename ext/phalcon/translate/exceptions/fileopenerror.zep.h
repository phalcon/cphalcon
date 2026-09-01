
extern zend_class_entry *phalcon_translate_exceptions_fileopenerror_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Exceptions_FileOpenError);

PHP_METHOD(Phalcon_Translate_Exceptions_FileOpenError, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_exceptions_fileopenerror___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_exceptions_fileopenerror_method_entry) {
	PHP_ME(Phalcon_Translate_Exceptions_FileOpenError, __construct, arginfo_phalcon_translate_exceptions_fileopenerror___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

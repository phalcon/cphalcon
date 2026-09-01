
extern zend_class_entry *phalcon_translate_exceptions_keynotfound_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Exceptions_KeyNotFound);

PHP_METHOD(Phalcon_Translate_Exceptions_KeyNotFound, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_exceptions_keynotfound___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_exceptions_keynotfound_method_entry) {
	PHP_ME(Phalcon_Translate_Exceptions_KeyNotFound, __construct, arginfo_phalcon_translate_exceptions_keynotfound___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


extern zend_class_entry *phalcon_html_helper_friendlytitle_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_FriendlyTitle);

PHP_METHOD(Phalcon_Html_Helper_FriendlyTitle, __construct);
PHP_METHOD(Phalcon_Html_Helper_FriendlyTitle, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_friendlytitle___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_friendlytitle___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "'-'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, lowercase, _IS_BOOL, 0, "true")
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_friendlytitle_method_entry) {
	PHP_ME(Phalcon_Html_Helper_FriendlyTitle, __construct, arginfo_phalcon_html_helper_friendlytitle___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_FriendlyTitle, __invoke, arginfo_phalcon_html_helper_friendlytitle___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

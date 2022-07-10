
extern zend_class_entry *phalcon_html_helper_doctype_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Doctype);

PHP_METHOD(Phalcon_Html_Helper_Doctype, __construct);
PHP_METHOD(Phalcon_Html_Helper_Doctype, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Doctype, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_doctype___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_doctype___invoke, 0, 0, Phalcon\\Html\\Helper\\Doctype, 0)
	ZEND_ARG_TYPE_INFO(0, flag, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_doctype___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_doctype_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Helper_Doctype, __construct, arginfo_phalcon_html_helper_doctype___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Html_Helper_Doctype, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(Phalcon_Html_Helper_Doctype, __invoke, arginfo_phalcon_html_helper_doctype___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Doctype, __toString, arginfo_phalcon_html_helper_doctype___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

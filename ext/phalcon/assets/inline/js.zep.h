
extern zend_class_entry *phalcon_assets_inline_js_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline_Js);

PHP_METHOD(Phalcon_Assets_Inline_Js, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_js___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_inline_js_method_entry) {
	PHP_ME(Phalcon_Assets_Inline_Js, __construct, arginfo_phalcon_assets_inline_js___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

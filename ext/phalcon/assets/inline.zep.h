
extern zend_class_entry *phalcon_assets_inline_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline);

PHP_METHOD(Phalcon_Assets_Inline, getType);
PHP_METHOD(Phalcon_Assets_Inline, getContent);
PHP_METHOD(Phalcon_Assets_Inline, getFilter);
PHP_METHOD(Phalcon_Assets_Inline, getAttributes);
PHP_METHOD(Phalcon_Assets_Inline, __construct);
PHP_METHOD(Phalcon_Assets_Inline, setType);
PHP_METHOD(Phalcon_Assets_Inline, setFilter);
PHP_METHOD(Phalcon_Assets_Inline, setAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_inline_method_entry) {
	PHP_ME(Phalcon_Assets_Inline, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, getFilter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, __construct, arginfo_phalcon_assets_inline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Inline, setType, arginfo_phalcon_assets_inline_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, setFilter, arginfo_phalcon_assets_inline_setfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, setAttributes, arginfo_phalcon_assets_inline_setattributes, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

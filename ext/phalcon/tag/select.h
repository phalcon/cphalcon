
extern zend_class_entry *phalcon_tag_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_Tag_Select);

PHP_METHOD(Phalcon_Tag_Select, selectField);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select_selectfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_tag_select_method_entry) {
	PHP_ME(Phalcon_Tag_Select, selectField, arginfo_phalcon_tag_select_selectfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

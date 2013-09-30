
extern zend_class_entry *phalcon_forms_element_numeric_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Numeric);

PHP_METHOD(Phalcon_Forms_Element_Numeric, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_numeric_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_numeric_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Numeric, render, arginfo_phalcon_forms_element_numeric_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_forms_element_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select);

PHP_METHOD(Phalcon_Forms_Element_Select, __construct);
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions);
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions);
PHP_METHOD(Phalcon_Forms_Element_Select, addOption);
PHP_METHOD(Phalcon_Forms_Element_Select, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_addoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_select_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Select, __construct, arginfo_phalcon_forms_element_select___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_Select, setOptions, arginfo_phalcon_forms_element_select_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, addOption, arginfo_phalcon_forms_element_select_addoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, render, arginfo_phalcon_forms_element_select_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

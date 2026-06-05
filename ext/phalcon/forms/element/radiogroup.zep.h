
extern zend_class_entry *phalcon_forms_element_radiogroup_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_RadioGroup);

PHP_METHOD(Phalcon_Forms_Element_RadioGroup, __construct);
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, getOptions);
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, render);
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, setOptions);
zend_object *zephir_init_properties_Phalcon_Forms_Element_RadioGroup(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_radiogroup___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_radiogroup_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_radiogroup_render, 0, 0, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_radiogroup_setoptions, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_radiogroup_zephir_init_properties_phalcon_forms_element_radiogroup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_radiogroup_method_entry) {
	PHP_ME(Phalcon_Forms_Element_RadioGroup, __construct, arginfo_phalcon_forms_element_radiogroup___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_RadioGroup, getOptions, arginfo_phalcon_forms_element_radiogroup_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_RadioGroup, render, arginfo_phalcon_forms_element_radiogroup_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_RadioGroup, setOptions, arginfo_phalcon_forms_element_radiogroup_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

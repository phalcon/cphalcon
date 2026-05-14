
extern zend_class_entry *phalcon_forms_element_checkgroup_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_CheckGroup);

PHP_METHOD(Phalcon_Forms_Element_CheckGroup, __construct);
PHP_METHOD(Phalcon_Forms_Element_CheckGroup, getOptions);
PHP_METHOD(Phalcon_Forms_Element_CheckGroup, render);
PHP_METHOD(Phalcon_Forms_Element_CheckGroup, setOptions);
zend_object *zephir_init_properties_Phalcon_Forms_Element_CheckGroup(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_checkgroup___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_checkgroup_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_checkgroup_render, 0, 0, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_checkgroup_setoptions, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_checkgroup_zephir_init_properties_phalcon_forms_element_checkgroup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_checkgroup_method_entry) {
	PHP_ME(Phalcon_Forms_Element_CheckGroup, __construct, arginfo_phalcon_forms_element_checkgroup___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_CheckGroup, getOptions, arginfo_phalcon_forms_element_checkgroup_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_CheckGroup, render, arginfo_phalcon_forms_element_checkgroup_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_CheckGroup, setOptions, arginfo_phalcon_forms_element_checkgroup_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

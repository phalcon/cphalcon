
extern zend_class_entry *phalcon_forms_element_abstractelement_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_AbstractElement);

PHP_METHOD(Phalcon_Forms_Element_AbstractElement, __construct);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, __toString);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addFilter);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addValidator);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addValidators);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, appendMessage);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, clear);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getAttribute);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getAttributes);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getDefault);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getFilters);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getForm);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getLabel);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getMessages);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getName);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getUserOption);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getUserOptions);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getValidators);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getValue);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, hasMessages);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, label);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, prepareAttributes);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, render);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setAttribute);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setAttributes);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setDefault);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setFilters);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setForm);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setLabel);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setMessages);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setName);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setTagFactory);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setUserOption);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setUserOptions);
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getTagFactory);
zend_object *zephir_init_properties_Phalcon_Forms_Element_AbstractElement(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_addfilter, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_TYPE_INFO(0, filter, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_addvalidator, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Filter\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_addvalidators, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_appendmessage, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_clear, 0, 0, Phalcon\\Forms\\Element\\ElementInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getattribute, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getattributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getdefault, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getfilters, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getform, 0, 0, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getlabel, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getmessages, 0, 0, Phalcon\\Messages\\Messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getuseroption, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getuseroptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getvalidators, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement_getvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_hasmessages, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_label, 0, 0, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_prepareattributes, 0, 0, IS_ARRAY, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, useChecked, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_abstractelement_render, 0, 0, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setattribute, 0, 2, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setattributes, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setdefault, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setfilters, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setform, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setlabel, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setmessages, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_OBJ_INFO(0, messages, Phalcon\\Messages\\Messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setname, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_settagfactory, 0, 1, Phalcon\\Forms\\Element\\AbstractElement, 0)
	ZEND_ARG_OBJ_INFO(0, tagFactory, Phalcon\\Html\\TagFactory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setuseroption, 0, 2, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_setuseroptions, 0, 1, Phalcon\\Forms\\Element\\ElementInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_abstractelement_gettagfactory, 0, 0, Phalcon\\Html\\TagFactory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_abstractelement_zephir_init_properties_phalcon_forms_element_abstractelement, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_abstractelement_method_entry) {
	PHP_ME(Phalcon_Forms_Element_AbstractElement, __construct, arginfo_phalcon_forms_element_abstractelement___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, __toString, arginfo_phalcon_forms_element_abstractelement___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, addFilter, arginfo_phalcon_forms_element_abstractelement_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, addValidator, arginfo_phalcon_forms_element_abstractelement_addvalidator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, addValidators, arginfo_phalcon_forms_element_abstractelement_addvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, appendMessage, arginfo_phalcon_forms_element_abstractelement_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, clear, arginfo_phalcon_forms_element_abstractelement_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getAttribute, arginfo_phalcon_forms_element_abstractelement_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getAttributes, arginfo_phalcon_forms_element_abstractelement_getattributes, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getDefault, arginfo_phalcon_forms_element_abstractelement_getdefault, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getDefault, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getFilters, arginfo_phalcon_forms_element_abstractelement_getfilters, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getFilters, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getForm, arginfo_phalcon_forms_element_abstractelement_getform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getLabel, arginfo_phalcon_forms_element_abstractelement_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getMessages, arginfo_phalcon_forms_element_abstractelement_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getName, arginfo_phalcon_forms_element_abstractelement_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getUserOption, arginfo_phalcon_forms_element_abstractelement_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getUserOptions, arginfo_phalcon_forms_element_abstractelement_getuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getValidators, arginfo_phalcon_forms_element_abstractelement_getvalidators, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getValue, arginfo_phalcon_forms_element_abstractelement_getvalue, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getValue, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Forms_Element_AbstractElement, hasMessages, arginfo_phalcon_forms_element_abstractelement_hasmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, label, arginfo_phalcon_forms_element_abstractelement_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, prepareAttributes, arginfo_phalcon_forms_element_abstractelement_prepareattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, render, arginfo_phalcon_forms_element_abstractelement_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setAttribute, arginfo_phalcon_forms_element_abstractelement_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setAttributes, arginfo_phalcon_forms_element_abstractelement_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setDefault, arginfo_phalcon_forms_element_abstractelement_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setFilters, arginfo_phalcon_forms_element_abstractelement_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setForm, arginfo_phalcon_forms_element_abstractelement_setform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setLabel, arginfo_phalcon_forms_element_abstractelement_setlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setMessages, arginfo_phalcon_forms_element_abstractelement_setmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setName, arginfo_phalcon_forms_element_abstractelement_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setTagFactory, arginfo_phalcon_forms_element_abstractelement_settagfactory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setUserOption, arginfo_phalcon_forms_element_abstractelement_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, setUserOptions, arginfo_phalcon_forms_element_abstractelement_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_AbstractElement, getTagFactory, arginfo_phalcon_forms_element_abstractelement_gettagfactory, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

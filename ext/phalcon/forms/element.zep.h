
extern zend_class_entry *phalcon_forms_element_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element);

PHP_METHOD(Phalcon_Forms_Element, __construct);
PHP_METHOD(Phalcon_Forms_Element, setForm);
PHP_METHOD(Phalcon_Forms_Element, getForm);
PHP_METHOD(Phalcon_Forms_Element, setName);
PHP_METHOD(Phalcon_Forms_Element, getName);
PHP_METHOD(Phalcon_Forms_Element, setFilters);
PHP_METHOD(Phalcon_Forms_Element, addFilter);
PHP_METHOD(Phalcon_Forms_Element, getFilters);
PHP_METHOD(Phalcon_Forms_Element, addValidators);
PHP_METHOD(Phalcon_Forms_Element, addValidator);
PHP_METHOD(Phalcon_Forms_Element, getValidators);
PHP_METHOD(Phalcon_Forms_Element, prepareAttributes);
PHP_METHOD(Phalcon_Forms_Element, setAttribute);
PHP_METHOD(Phalcon_Forms_Element, getAttribute);
PHP_METHOD(Phalcon_Forms_Element, setAttributes);
PHP_METHOD(Phalcon_Forms_Element, getAttributes);
PHP_METHOD(Phalcon_Forms_Element, setUserOption);
PHP_METHOD(Phalcon_Forms_Element, getUserOption);
PHP_METHOD(Phalcon_Forms_Element, setUserOptions);
PHP_METHOD(Phalcon_Forms_Element, getUserOptions);
PHP_METHOD(Phalcon_Forms_Element, setLabel);
PHP_METHOD(Phalcon_Forms_Element, getLabel);
PHP_METHOD(Phalcon_Forms_Element, label);
PHP_METHOD(Phalcon_Forms_Element, setDefault);
PHP_METHOD(Phalcon_Forms_Element, getDefault);
PHP_METHOD(Phalcon_Forms_Element, getValue);
PHP_METHOD(Phalcon_Forms_Element, getMessages);
PHP_METHOD(Phalcon_Forms_Element, hasMessages);
PHP_METHOD(Phalcon_Forms_Element, setMessages);
PHP_METHOD(Phalcon_Forms_Element, appendMessage);
PHP_METHOD(Phalcon_Forms_Element, clear);
PHP_METHOD(Phalcon_Forms_Element, __toString);
zend_object *zephir_init_properties_Phalcon_Forms_Element(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setform, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setform, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_getform, 0, 0, Phalcon\\Forms\\Form, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getform, 0, 0, IS_OBJECT, "Phalcon\\Forms\\Form", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setname, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setname, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setfilters, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setfilters, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_addfilter, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_addfilter, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_addvalidators, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_addvalidators, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_addvalidator, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_addvalidator, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getvalidators, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getvalidators, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_prepareattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_prepareattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useChecked, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useChecked)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setattribute, 0, 2, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setattribute, 0, 2, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setattributes, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setattributes, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setuseroption, 0, 2, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setuseroption, 0, 2, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, option)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getuseroption, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, option)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setuseroptions, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setuseroptions, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getuseroptions, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getuseroptions, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setlabel, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setlabel, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, label)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getlabel, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getlabel, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_label, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_label, 0, 0, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setdefault, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setdefault, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_getmessages, 0, 0, Phalcon\\Messages\\Messages, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_getmessages, 0, 0, IS_OBJECT, "Phalcon\\Messages\\Messages", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_hasmessages, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_hasmessages, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_setmessages, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_setmessages, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, messages, Phalcon\\Messages\\Messages, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_appendmessage, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_appendmessage, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_element_clear, 0, 0, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_clear, 0, 0, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_method_entry) {
	PHP_ME(Phalcon_Forms_Element, __construct, arginfo_phalcon_forms_element___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element, setForm, arginfo_phalcon_forms_element_setform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getForm, arginfo_phalcon_forms_element_getform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setName, arginfo_phalcon_forms_element_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getName, arginfo_phalcon_forms_element_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setFilters, arginfo_phalcon_forms_element_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addFilter, arginfo_phalcon_forms_element_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addValidators, arginfo_phalcon_forms_element_addvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addValidator, arginfo_phalcon_forms_element_addvalidator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getValidators, arginfo_phalcon_forms_element_getvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, prepareAttributes, arginfo_phalcon_forms_element_prepareattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setAttribute, arginfo_phalcon_forms_element_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getAttribute, arginfo_phalcon_forms_element_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setAttributes, arginfo_phalcon_forms_element_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getAttributes, arginfo_phalcon_forms_element_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setUserOption, arginfo_phalcon_forms_element_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getUserOption, arginfo_phalcon_forms_element_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setUserOptions, arginfo_phalcon_forms_element_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getUserOptions, arginfo_phalcon_forms_element_getuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setLabel, arginfo_phalcon_forms_element_setlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getLabel, arginfo_phalcon_forms_element_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, label, arginfo_phalcon_forms_element_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setDefault, arginfo_phalcon_forms_element_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getMessages, arginfo_phalcon_forms_element_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, hasMessages, arginfo_phalcon_forms_element_hasmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setMessages, arginfo_phalcon_forms_element_setmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, appendMessage, arginfo_phalcon_forms_element_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, clear, arginfo_phalcon_forms_element_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, __toString, arginfo_phalcon_forms_element___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

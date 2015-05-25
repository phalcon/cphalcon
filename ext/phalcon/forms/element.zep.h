
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setform, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addvalidators, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addvalidator, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_prepareattributes, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, useChecked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_label, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setmessages, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Validation\\Message\\Group, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_method_entry) {
	PHP_ME(Phalcon_Forms_Element, __construct, arginfo_phalcon_forms_element___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element, setForm, arginfo_phalcon_forms_element_setform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getForm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setName, arginfo_phalcon_forms_element_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setFilters, arginfo_phalcon_forms_element_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addFilter, arginfo_phalcon_forms_element_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addValidators, arginfo_phalcon_forms_element_addvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addValidator, arginfo_phalcon_forms_element_addvalidator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getValidators, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, prepareAttributes, arginfo_phalcon_forms_element_prepareattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setAttribute, arginfo_phalcon_forms_element_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getAttribute, arginfo_phalcon_forms_element_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setAttributes, arginfo_phalcon_forms_element_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setUserOption, arginfo_phalcon_forms_element_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getUserOption, arginfo_phalcon_forms_element_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setUserOptions, arginfo_phalcon_forms_element_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getUserOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setLabel, arginfo_phalcon_forms_element_setlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getLabel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, label, arginfo_phalcon_forms_element_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setDefault, arginfo_phalcon_forms_element_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, hasMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setMessages, arginfo_phalcon_forms_element_setmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, appendMessage, arginfo_phalcon_forms_element_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_forms_elementinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_ElementInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setform, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidators, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidator, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_prepareattributes, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, useChecked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setmessages, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Validation\\Message\\Group, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_elementinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setForm, arginfo_phalcon_forms_elementinterface_setform)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getForm, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setName, arginfo_phalcon_forms_elementinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setFilters, arginfo_phalcon_forms_elementinterface_setfilters)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addFilter, arginfo_phalcon_forms_elementinterface_addfilter)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getFilters, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidators, arginfo_phalcon_forms_elementinterface_addvalidators)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidator, arginfo_phalcon_forms_elementinterface_addvalidator)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValidators, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, prepareAttributes, arginfo_phalcon_forms_elementinterface_prepareattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttribute, arginfo_phalcon_forms_elementinterface_setattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttribute, arginfo_phalcon_forms_elementinterface_getattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttributes, arginfo_phalcon_forms_elementinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOption, arginfo_phalcon_forms_elementinterface_setuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOption, arginfo_phalcon_forms_elementinterface_getuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOptions, arginfo_phalcon_forms_elementinterface_setuseroptions)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setLabel, arginfo_phalcon_forms_elementinterface_setlabel)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getLabel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, label, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setDefault, arginfo_phalcon_forms_elementinterface_setdefault)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getDefault, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, hasMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setMessages, arginfo_phalcon_forms_elementinterface_setmessages)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, appendMessage, arginfo_phalcon_forms_elementinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, render, arginfo_phalcon_forms_elementinterface_render)
	PHP_FE_END
};

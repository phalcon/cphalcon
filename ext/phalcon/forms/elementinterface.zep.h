
extern zend_class_entry *phalcon_forms_elementinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_ElementInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_addfilter, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_addfilter, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidator, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidator, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidators, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidators, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_appendmessage, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_appendmessage, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_clear, 0, 0, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_clear, 0, 0, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_getform, 0, 0, Phalcon\\Forms\\Form, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getform, 0, 0, IS_OBJECT, "Phalcon\\Forms\\Form", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getlabel, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getlabel, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_getmessages, 0, 0, Phalcon\\Messages\\Messages, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getmessages, 0, 0, IS_OBJECT, "Phalcon\\Messages\\Messages", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getuseroption, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, option)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getuseroptions, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getuseroptions, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getvalidators, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_getvalidators, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_hasmessages, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_hasmessages, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_label, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_label, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_prepareattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_prepareattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useChecked, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useChecked)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_render, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_render, 0, 0, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setattribute, 0, 2, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setattribute, 0, 2, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setattributes, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setattributes, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setdefault, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setdefault, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setfilters, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setfilters, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setform, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setform, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setlabel, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setlabel, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, label)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setmessages, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setmessages, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, messages, Phalcon\\Messages\\Messages, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setname, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setname, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroption, 0, 2, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroption, 0, 2, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, option)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroptions, 0, 1, Phalcon\\Forms\\ElementInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroptions, 0, 1, IS_OBJECT, "Phalcon\\Forms\\ElementInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_elementinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addFilter, arginfo_phalcon_forms_elementinterface_addfilter)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidator, arginfo_phalcon_forms_elementinterface_addvalidator)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidators, arginfo_phalcon_forms_elementinterface_addvalidators)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, appendMessage, arginfo_phalcon_forms_elementinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, clear, arginfo_phalcon_forms_elementinterface_clear)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttribute, arginfo_phalcon_forms_elementinterface_getattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttributes, arginfo_phalcon_forms_elementinterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getDefault, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getFilters, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getForm, arginfo_phalcon_forms_elementinterface_getform)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getLabel, arginfo_phalcon_forms_elementinterface_getlabel)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getMessages, arginfo_phalcon_forms_elementinterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getName, arginfo_phalcon_forms_elementinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOption, arginfo_phalcon_forms_elementinterface_getuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOptions, arginfo_phalcon_forms_elementinterface_getuseroptions)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValidators, arginfo_phalcon_forms_elementinterface_getvalidators)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, hasMessages, arginfo_phalcon_forms_elementinterface_hasmessages)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, label, arginfo_phalcon_forms_elementinterface_label)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, prepareAttributes, arginfo_phalcon_forms_elementinterface_prepareattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, render, arginfo_phalcon_forms_elementinterface_render)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttribute, arginfo_phalcon_forms_elementinterface_setattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttributes, arginfo_phalcon_forms_elementinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setDefault, arginfo_phalcon_forms_elementinterface_setdefault)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setFilters, arginfo_phalcon_forms_elementinterface_setfilters)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setForm, arginfo_phalcon_forms_elementinterface_setform)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setLabel, arginfo_phalcon_forms_elementinterface_setlabel)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setMessages, arginfo_phalcon_forms_elementinterface_setmessages)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setName, arginfo_phalcon_forms_elementinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOption, arginfo_phalcon_forms_elementinterface_setuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOptions, arginfo_phalcon_forms_elementinterface_setuseroptions)
	PHP_FE_END
};

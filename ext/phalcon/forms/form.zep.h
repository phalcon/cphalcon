
extern zend_class_entry *phalcon_forms_form_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Form);

PHP_METHOD(Phalcon_Forms_Form, setValidation);
PHP_METHOD(Phalcon_Forms_Form, getValidation);
PHP_METHOD(Phalcon_Forms_Form, __construct);
PHP_METHOD(Phalcon_Forms_Form, setAction);
PHP_METHOD(Phalcon_Forms_Form, getAction);
PHP_METHOD(Phalcon_Forms_Form, setUserOption);
PHP_METHOD(Phalcon_Forms_Form, getUserOption);
PHP_METHOD(Phalcon_Forms_Form, setUserOptions);
PHP_METHOD(Phalcon_Forms_Form, getUserOptions);
PHP_METHOD(Phalcon_Forms_Form, setEntity);
PHP_METHOD(Phalcon_Forms_Form, getEntity);
PHP_METHOD(Phalcon_Forms_Form, getElements);
PHP_METHOD(Phalcon_Forms_Form, bind);
PHP_METHOD(Phalcon_Forms_Form, isValid);
PHP_METHOD(Phalcon_Forms_Form, getMessages);
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor);
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor);
PHP_METHOD(Phalcon_Forms_Form, add);
PHP_METHOD(Phalcon_Forms_Form, render);
PHP_METHOD(Phalcon_Forms_Form, get);
PHP_METHOD(Phalcon_Forms_Form, label);
PHP_METHOD(Phalcon_Forms_Form, getLabel);
PHP_METHOD(Phalcon_Forms_Form, getValue);
PHP_METHOD(Phalcon_Forms_Form, has);
PHP_METHOD(Phalcon_Forms_Form, remove);
PHP_METHOD(Phalcon_Forms_Form, clear);
PHP_METHOD(Phalcon_Forms_Form, count);
PHP_METHOD(Phalcon_Forms_Form, rewind);
PHP_METHOD(Phalcon_Forms_Form, current);
PHP_METHOD(Phalcon_Forms_Form, key);
PHP_METHOD(Phalcon_Forms_Form, next);
PHP_METHOD(Phalcon_Forms_Form, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setvalidation, 0, 0, 1)
	ZEND_ARG_INFO(0, validation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, userOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setaction, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setuseroptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setentity, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_bind, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, whitelist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_isvalid, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, byItemName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getmessagesfor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_hasmessagesfor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, element, Phalcon\\Forms\\ElementInterface, 0)
	ZEND_ARG_INFO(0, postion)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_render, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_label, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, attributes, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_form_method_entry) {
	PHP_ME(Phalcon_Forms_Form, setValidation, arginfo_phalcon_forms_form_setvalidation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getValidation, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, __construct, arginfo_phalcon_forms_form___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Form, setAction, arginfo_phalcon_forms_form_setaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setUserOption, arginfo_phalcon_forms_form_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getUserOption, arginfo_phalcon_forms_form_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setUserOptions, arginfo_phalcon_forms_form_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getUserOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setEntity, arginfo_phalcon_forms_form_setentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getEntity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getElements, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, bind, arginfo_phalcon_forms_form_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, isValid, arginfo_phalcon_forms_form_isvalid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getMessages, arginfo_phalcon_forms_form_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getMessagesFor, arginfo_phalcon_forms_form_getmessagesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, hasMessagesFor, arginfo_phalcon_forms_form_hasmessagesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, add, arginfo_phalcon_forms_form_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, render, arginfo_phalcon_forms_form_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, get, arginfo_phalcon_forms_form_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, label, arginfo_phalcon_forms_form_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getLabel, arginfo_phalcon_forms_form_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getValue, arginfo_phalcon_forms_form_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, has, arginfo_phalcon_forms_form_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, remove, arginfo_phalcon_forms_form_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, clear, arginfo_phalcon_forms_form_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

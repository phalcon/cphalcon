
extern zend_class_entry *phalcon_validation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation);

PHP_METHOD(Phalcon_Validation, getData);
PHP_METHOD(Phalcon_Validation, setValidators);
PHP_METHOD(Phalcon_Validation, __construct);
PHP_METHOD(Phalcon_Validation, add);
PHP_METHOD(Phalcon_Validation, appendMessage);
PHP_METHOD(Phalcon_Validation, bind);
PHP_METHOD(Phalcon_Validation, getEntity);
PHP_METHOD(Phalcon_Validation, getFilters);
PHP_METHOD(Phalcon_Validation, getLabel);
PHP_METHOD(Phalcon_Validation, getMessages);
PHP_METHOD(Phalcon_Validation, getValidators);
PHP_METHOD(Phalcon_Validation, getValue);
PHP_METHOD(Phalcon_Validation, rule);
PHP_METHOD(Phalcon_Validation, rules);
PHP_METHOD(Phalcon_Validation, setEntity);
PHP_METHOD(Phalcon_Validation, setFilters);
PHP_METHOD(Phalcon_Validation, setLabels);
PHP_METHOD(Phalcon_Validation, validate);
PHP_METHOD(Phalcon_Validation, preChecking);
zend_object *zephir_init_properties_Phalcon_Validation(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setvalidators, 0, 0, 1)
	ZEND_ARG_INFO(0, validators)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_add, 0, 2, Phalcon\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_appendmessage, 0, 1, Phalcon\\Validation\\ValidationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_bind, 0, 2, Phalcon\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getentity, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getfilters, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_getlabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_getmessages, 0, 0, Phalcon\\Messages\\Messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_getvalidators, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getvalue, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_rule, 0, 2, Phalcon\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_rules, 0, 2, Phalcon\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_setentity, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_setfilters, 0, 2, Phalcon\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_setlabels, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, labels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_validate, 0, 0, Phalcon\\Messages\\Messages, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_prechecking, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_zephir_init_properties_phalcon_validation, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Validation, getData, arginfo_phalcon_validation_getdata, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Validation, getData, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Validation, setValidators, arginfo_phalcon_validation_setvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, __construct, arginfo_phalcon_validation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation, add, arginfo_phalcon_validation_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, appendMessage, arginfo_phalcon_validation_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, bind, arginfo_phalcon_validation_bind, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Validation, getEntity, arginfo_phalcon_validation_getentity, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Validation, getEntity, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Validation, getFilters, arginfo_phalcon_validation_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getLabel, arginfo_phalcon_validation_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getMessages, arginfo_phalcon_validation_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValidators, arginfo_phalcon_validation_getvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValue, arginfo_phalcon_validation_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, rule, arginfo_phalcon_validation_rule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, rules, arginfo_phalcon_validation_rules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setEntity, arginfo_phalcon_validation_setentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setFilters, arginfo_phalcon_validation_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setLabels, arginfo_phalcon_validation_setlabels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, validate, arginfo_phalcon_validation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, preChecking, arginfo_phalcon_validation_prechecking, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

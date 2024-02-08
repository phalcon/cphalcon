
extern zend_class_entry *phalcon_filter_validation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation);

PHP_METHOD(Phalcon_Filter_Validation, __construct);
PHP_METHOD(Phalcon_Filter_Validation, add);
PHP_METHOD(Phalcon_Filter_Validation, appendMessage);
PHP_METHOD(Phalcon_Filter_Validation, bind);
PHP_METHOD(Phalcon_Filter_Validation, getData);
PHP_METHOD(Phalcon_Filter_Validation, getEntity);
PHP_METHOD(Phalcon_Filter_Validation, getFilters);
PHP_METHOD(Phalcon_Filter_Validation, getLabel);
PHP_METHOD(Phalcon_Filter_Validation, getMessages);
PHP_METHOD(Phalcon_Filter_Validation, getValidators);
PHP_METHOD(Phalcon_Filter_Validation, getValueByEntity);
PHP_METHOD(Phalcon_Filter_Validation, getValueByData);
PHP_METHOD(Phalcon_Filter_Validation, getValue);
PHP_METHOD(Phalcon_Filter_Validation, rule);
PHP_METHOD(Phalcon_Filter_Validation, rules);
PHP_METHOD(Phalcon_Filter_Validation, setEntity);
PHP_METHOD(Phalcon_Filter_Validation, setFilters);
PHP_METHOD(Phalcon_Filter_Validation, setLabels);
PHP_METHOD(Phalcon_Filter_Validation, setValidators);
PHP_METHOD(Phalcon_Filter_Validation, validate);
PHP_METHOD(Phalcon_Filter_Validation, preChecking);
zend_object *zephir_init_properties_Phalcon_Filter_Validation(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, validators, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_add, 0, 2, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Filter\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_appendmessage, 0, 1, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_bind, 0, 2, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_getentity, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_getfilters, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_getlabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_getmessages, 0, 0, Phalcon\\Messages\\Messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_getvalidators, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_getvaluebyentity, 0, 0, 2)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_getvaluebydata, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_getvalue, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_rule, 0, 2, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Filter\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_rules, 0, 2, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_setentity, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_setfilters, 0, 2, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_setlabels, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, labels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_setvalidators, 0, 1, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_validate, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_prechecking, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Filter\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_zephir_init_properties_phalcon_filter_validation, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_method_entry) {
	PHP_ME(Phalcon_Filter_Validation, __construct, arginfo_phalcon_filter_validation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Filter_Validation, add, arginfo_phalcon_filter_validation_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, appendMessage, arginfo_phalcon_filter_validation_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, bind, arginfo_phalcon_filter_validation_bind, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Filter_Validation, getData, arginfo_phalcon_filter_validation_getdata, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Filter_Validation, getEntity, arginfo_phalcon_filter_validation_getentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getFilters, arginfo_phalcon_filter_validation_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getLabel, arginfo_phalcon_filter_validation_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getMessages, arginfo_phalcon_filter_validation_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getValidators, arginfo_phalcon_filter_validation_getvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getValueByEntity, arginfo_phalcon_filter_validation_getvaluebyentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getValueByData, arginfo_phalcon_filter_validation_getvaluebydata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, getValue, arginfo_phalcon_filter_validation_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, rule, arginfo_phalcon_filter_validation_rule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, rules, arginfo_phalcon_filter_validation_rules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, setEntity, arginfo_phalcon_filter_validation_setentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, setFilters, arginfo_phalcon_filter_validation_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, setLabels, arginfo_phalcon_filter_validation_setlabels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, setValidators, arginfo_phalcon_filter_validation_setvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, validate, arginfo_phalcon_filter_validation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation, preChecking, arginfo_phalcon_filter_validation_prechecking, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

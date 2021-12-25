
extern zend_class_entry *phalcon_filter_validation_abstractvalidator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_AbstractValidator);

PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, __construct);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, getTemplate);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, getTemplates);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, setTemplates);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, setTemplate);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, getOption);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, hasOption);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, setOption);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, validate);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, prepareCode);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, prepareLabel);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, allowEmpty);
PHP_METHOD(Phalcon_Filter_Validation_AbstractValidator, messageFactory);
zend_object *zephir_init_properties_Phalcon_Filter_Validation_AbstractValidator(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_gettemplate, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_gettemplates, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_settemplates, 0, 1, Phalcon\\Filter\\Validation\\ValidatorInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, templates, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_settemplate, 0, 1, Phalcon\\Filter\\Validation\\ValidatorInterface, 0)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_getoption, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_hasoption, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_setoption, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_preparecode, 0, 1, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_preparelabel, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_allowempty, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_messagefactory, 0, 2, Phalcon\\Messages\\Message, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_INFO(0, field)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, replacements, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, replacements, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_abstractvalidator_zephir_init_properties_phalcon_filter_validation_abstractvalidator, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_abstractvalidator_method_entry) {
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, __construct, arginfo_phalcon_filter_validation_abstractvalidator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, getTemplate, arginfo_phalcon_filter_validation_abstractvalidator_gettemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, getTemplates, arginfo_phalcon_filter_validation_abstractvalidator_gettemplates, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, setTemplates, arginfo_phalcon_filter_validation_abstractvalidator_settemplates, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, setTemplate, arginfo_phalcon_filter_validation_abstractvalidator_settemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, getOption, arginfo_phalcon_filter_validation_abstractvalidator_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, hasOption, arginfo_phalcon_filter_validation_abstractvalidator_hasoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, setOption, arginfo_phalcon_filter_validation_abstractvalidator_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, validate, arginfo_phalcon_filter_validation_abstractvalidator_validate, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, prepareCode, arginfo_phalcon_filter_validation_abstractvalidator_preparecode, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, prepareLabel, arginfo_phalcon_filter_validation_abstractvalidator_preparelabel, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, allowEmpty, arginfo_phalcon_filter_validation_abstractvalidator_allowempty, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter_Validation_AbstractValidator, messageFactory, arginfo_phalcon_filter_validation_abstractvalidator_messagefactory, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

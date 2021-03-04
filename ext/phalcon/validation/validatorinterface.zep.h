
extern zend_class_entry *phalcon_validation_validatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_getoption, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validatorinterface_hasoption, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validatorinterface_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validatorinterface_gettemplate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validatorinterface_gettemplates, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_validatorinterface_settemplates, 0, 1, Phalcon\\Validation\\ValidatorInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, templates, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_validatorinterface_settemplate, 0, 1, Phalcon\\Validation\\ValidatorInterface, 0)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, getOption, arginfo_phalcon_validation_validatorinterface_getoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, hasOption, arginfo_phalcon_validation_validatorinterface_hasoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, validate, arginfo_phalcon_validation_validatorinterface_validate)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, getTemplate, arginfo_phalcon_validation_validatorinterface_gettemplate)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, getTemplates, arginfo_phalcon_validation_validatorinterface_gettemplates)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, setTemplates, arginfo_phalcon_validation_validatorinterface_settemplates)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, setTemplate, arginfo_phalcon_validation_validatorinterface_settemplate)
	PHP_FE_END
};

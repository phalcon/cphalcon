
extern zend_class_entry *phalcon_adr_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Application);

PHP_METHOD(Phalcon_ADR_Application, __construct);
PHP_METHOD(Phalcon_ADR_Application, bind);
PHP_METHOD(Phalcon_ADR_Application, define);
PHP_METHOD(Phalcon_ADR_Application, extend);
PHP_METHOD(Phalcon_ADR_Application, factory);
PHP_METHOD(Phalcon_ADR_Application, getContainer);
PHP_METHOD(Phalcon_ADR_Application, handle);
PHP_METHOD(Phalcon_ADR_Application, secureWith);
PHP_METHOD(Phalcon_ADR_Application, set);
PHP_METHOD(Phalcon_ADR_Application, setBaseNamespace);
zend_object *zephir_init_properties_Phalcon_ADR_Application(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, container, Phalcon\\Container\\Container, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_bind, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, interfaceName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, concrete, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_define, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parameters, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_extend, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, extender, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_factory, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, factory, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_application_getcontainer, 0, 0, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_application_handle, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_securewith, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, guard, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_set, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_application_setbasenamespace, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, baseNamespace, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_application_zephir_init_properties_phalcon_adr_application, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_application_method_entry) {
	PHP_ME(Phalcon_ADR_Application, __construct, arginfo_phalcon_adr_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Application, bind, arginfo_phalcon_adr_application_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, define, arginfo_phalcon_adr_application_define, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, extend, arginfo_phalcon_adr_application_extend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, factory, arginfo_phalcon_adr_application_factory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, getContainer, arginfo_phalcon_adr_application_getcontainer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, handle, arginfo_phalcon_adr_application_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, secureWith, arginfo_phalcon_adr_application_securewith, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, set, arginfo_phalcon_adr_application_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Application, setBaseNamespace, arginfo_phalcon_adr_application_setbasenamespace, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

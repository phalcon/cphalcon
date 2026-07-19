
extern zend_class_entry *phalcon_adr_input_input_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Input_Input);

PHP_METHOD(Phalcon_ADR_Input_Input, __construct);
PHP_METHOD(Phalcon_ADR_Input_Input, fromArray);
PHP_METHOD(Phalcon_ADR_Input_Input, fromRequest);
PHP_METHOD(Phalcon_ADR_Input_Input, get);
PHP_METHOD(Phalcon_ADR_Input_Input, has);
PHP_METHOD(Phalcon_ADR_Input_Input, toArray);
zend_object *zephir_init_properties_Phalcon_ADR_Input_Input(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_input_input___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_input_input_fromarray, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_input_input_fromrequest, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_input_input_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_input_input_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_input_input_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_input_input_zephir_init_properties_phalcon_adr_input_input, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_input_input_method_entry) {
	PHP_ME(Phalcon_ADR_Input_Input, __construct, arginfo_phalcon_adr_input_input___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Input_Input, fromArray, arginfo_phalcon_adr_input_input_fromarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Input_Input, fromRequest, arginfo_phalcon_adr_input_input_fromrequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Input_Input, get, arginfo_phalcon_adr_input_input_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Input_Input, has, arginfo_phalcon_adr_input_input_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Input_Input, toArray, arginfo_phalcon_adr_input_input_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

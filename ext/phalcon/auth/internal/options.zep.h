
extern zend_class_entry *phalcon_auth_internal_options_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Internal_Options);

PHP_METHOD(Phalcon_Auth_Internal_Options, arrayOption);
PHP_METHOD(Phalcon_Auth_Internal_Options, requireString);
PHP_METHOD(Phalcon_Auth_Internal_Options, resolveService);
PHP_METHOD(Phalcon_Auth_Internal_Options, stringOrNull);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_internal_options_arrayoption, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, defaultValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_internal_options_requirestring, 0, 3, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_internal_options_resolveservice, 0, 3, MAY_BE_OBJECT)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_TYPE_INFO(0, serviceId, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_internal_options_stringornull, 0, 2, IS_STRING, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_internal_options_method_entry) {
	PHP_ME(Phalcon_Auth_Internal_Options, arrayOption, arginfo_phalcon_auth_internal_options_arrayoption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_Options, requireString, arginfo_phalcon_auth_internal_options_requirestring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_Options, resolveService, arginfo_phalcon_auth_internal_options_resolveservice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_Options, stringOrNull, arginfo_phalcon_auth_internal_options_stringornull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

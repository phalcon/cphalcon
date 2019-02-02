
extern zend_class_entry *phalcon_service_locator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Service_Locator);

PHP_METHOD(Phalcon_Service_Locator, __construct);
PHP_METHOD(Phalcon_Service_Locator, __call);
PHP_METHOD(Phalcon_Service_Locator, get);
PHP_METHOD(Phalcon_Service_Locator, has);
PHP_METHOD(Phalcon_Service_Locator, set);
zend_object *zephir_init_properties_Phalcon_Service_Locator(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_service_locator___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_service_locator___call, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_service_locator_get, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locator_get, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locator_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locator_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_service_locator_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_service_locator_method_entry) {
	PHP_ME(Phalcon_Service_Locator, __construct, arginfo_phalcon_service_locator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Service_Locator, __call, arginfo_phalcon_service_locator___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Service_Locator, get, arginfo_phalcon_service_locator_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Service_Locator, has, arginfo_phalcon_service_locator_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Service_Locator, set, arginfo_phalcon_service_locator_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

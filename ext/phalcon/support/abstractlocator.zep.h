
extern zend_class_entry *phalcon_support_abstractlocator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_AbstractLocator);

PHP_METHOD(Phalcon_Support_AbstractLocator, __construct);
PHP_METHOD(Phalcon_Support_AbstractLocator, getAll);
PHP_METHOD(Phalcon_Support_AbstractLocator, getClass);
PHP_METHOD(Phalcon_Support_AbstractLocator, has);
PHP_METHOD(Phalcon_Support_AbstractLocator, newInstance);
PHP_METHOD(Phalcon_Support_AbstractLocator, register);
PHP_METHOD(Phalcon_Support_AbstractLocator, getExceptionClass);
PHP_METHOD(Phalcon_Support_AbstractLocator, getInterfaceClass);
PHP_METHOD(Phalcon_Support_AbstractLocator, getService);
PHP_METHOD(Phalcon_Support_AbstractLocator, getServices);
zend_object *zephir_init_properties_Phalcon_Support_AbstractLocator(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_abstractlocator___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, container)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_getall, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_getclass, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_support_abstractlocator_newinstance, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_support_abstractlocator_register, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, definition, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_getinterfaceclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_getservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_abstractlocator_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_abstractlocator_zephir_init_properties_phalcon_support_abstractlocator, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_abstractlocator_method_entry) {
	PHP_ME(Phalcon_Support_AbstractLocator, __construct, arginfo_phalcon_support_abstractlocator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Support_AbstractLocator, getAll, arginfo_phalcon_support_abstractlocator_getall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_AbstractLocator, getClass, arginfo_phalcon_support_abstractlocator_getclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_AbstractLocator, has, arginfo_phalcon_support_abstractlocator_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_AbstractLocator, newInstance, arginfo_phalcon_support_abstractlocator_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_AbstractLocator, register, arginfo_phalcon_support_abstractlocator_register, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_AbstractLocator, getExceptionClass, arginfo_phalcon_support_abstractlocator_getexceptionclass, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_AbstractLocator, getInterfaceClass, arginfo_phalcon_support_abstractlocator_getinterfaceclass, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_AbstractLocator, getService, arginfo_phalcon_support_abstractlocator_getservice, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_AbstractLocator, getServices, arginfo_phalcon_support_abstractlocator_getservices, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};

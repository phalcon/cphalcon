
extern zend_class_entry *phalcon_translate_interpolatorfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_InterpolatorFactory);

PHP_METHOD(Phalcon_Translate_InterpolatorFactory, __construct);
PHP_METHOD(Phalcon_Translate_InterpolatorFactory, newInstance);
PHP_METHOD(Phalcon_Translate_InterpolatorFactory, getExceptionClass);
PHP_METHOD(Phalcon_Translate_InterpolatorFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_interpolatorfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_newinstance, 0, 1, Phalcon\\Translate\\Interpolator\\InterpolatorInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_interpolatorfactory_method_entry) {
	PHP_ME(Phalcon_Translate_InterpolatorFactory, __construct, arginfo_phalcon_translate_interpolatorfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_InterpolatorFactory, newInstance, arginfo_phalcon_translate_interpolatorfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_InterpolatorFactory, getExceptionClass, arginfo_phalcon_translate_interpolatorfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Translate_InterpolatorFactory, getServices, arginfo_phalcon_translate_interpolatorfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

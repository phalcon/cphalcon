
extern zend_class_entry *phalcon_translate_interpolatorfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_InterpolatorFactory);

PHP_METHOD(Phalcon_Translate_InterpolatorFactory, __construct);
PHP_METHOD(Phalcon_Translate_InterpolatorFactory, newInstance);
PHP_METHOD(Phalcon_Translate_InterpolatorFactory, getAdapters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_interpolatorfactory___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, services, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_newinstance, 0, 1, Phalcon\\Translate\\Interpolator\\InterpolatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_newinstance, 0, 1, IS_OBJECT, "Phalcon\\Translate\\Interpolator\\InterpolatorInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_getadapters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_interpolatorfactory_getadapters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_interpolatorfactory_method_entry) {
	PHP_ME(Phalcon_Translate_InterpolatorFactory, __construct, arginfo_phalcon_translate_interpolatorfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_InterpolatorFactory, newInstance, arginfo_phalcon_translate_interpolatorfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_InterpolatorFactory, getAdapters, arginfo_phalcon_translate_interpolatorfactory_getadapters, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

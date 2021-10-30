
extern zend_class_entry *phalcon_translate_translatefactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_TranslateFactory);

PHP_METHOD(Phalcon_Translate_TranslateFactory, __construct);
PHP_METHOD(Phalcon_Translate_TranslateFactory, load);
PHP_METHOD(Phalcon_Translate_TranslateFactory, newInstance);
PHP_METHOD(Phalcon_Translate_TranslateFactory, getExceptionClass);
PHP_METHOD(Phalcon_Translate_TranslateFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_translatefactory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_translate_translatefactory_load, 0, 1, Phalcon\\Translate\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_translate_translatefactory_newinstance, 0, 1, Phalcon\\Translate\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_translatefactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_translatefactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_translatefactory_method_entry) {
	PHP_ME(Phalcon_Translate_TranslateFactory, __construct, arginfo_phalcon_translate_translatefactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_TranslateFactory, load, arginfo_phalcon_translate_translatefactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_TranslateFactory, newInstance, arginfo_phalcon_translate_translatefactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_TranslateFactory, getExceptionClass, arginfo_phalcon_translate_translatefactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Translate_TranslateFactory, getServices, arginfo_phalcon_translate_translatefactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

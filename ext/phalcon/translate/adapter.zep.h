
extern zend_class_entry *phalcon_translate_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter);

PHP_METHOD(Phalcon_Translate_Adapter, __construct);
PHP_METHOD(Phalcon_Translate_Adapter, _);
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists);
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet);
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet);
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset);
PHP_METHOD(Phalcon_Translate_Adapter, setInterpolator);
PHP_METHOD(Phalcon_Translate_Adapter, t);
PHP_METHOD(Phalcon_Translate_Adapter, replacePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter__, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter__, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, translateKey)
#endif
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_translate_adapter_setinterpolator, 0, 1, Phalcon\\Translate\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_setinterpolator, 0, 1, IS_OBJECT, "Phalcon\\Translate\\Adapter", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_t, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_t, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, translateKey)
#endif
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_replaceplaceholders, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_replaceplaceholders, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, translation, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, translation)
#endif
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter, __construct, arginfo_phalcon_translate_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter, _, arginfo_phalcon_translate_adapter__, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetExists, arginfo_phalcon_translate_adapter_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetGet, arginfo_phalcon_translate_adapter_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetSet, arginfo_phalcon_translate_adapter_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetUnset, arginfo_phalcon_translate_adapter_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, setInterpolator, arginfo_phalcon_translate_adapter_setinterpolator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, t, arginfo_phalcon_translate_adapter_t, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, replacePlaceholders, arginfo_phalcon_translate_adapter_replaceplaceholders, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

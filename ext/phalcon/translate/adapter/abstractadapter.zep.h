
extern zend_class_entry *phalcon_translate_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, _);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetExists);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetGet);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetSet);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetUnset);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, t);
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, replacePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter__, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter_t, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_abstractadapter_replaceplaceholders, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translation, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, __construct, arginfo_phalcon_translate_adapter_abstractadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, _, arginfo_phalcon_translate_adapter_abstractadapter__, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, offsetExists, arginfo_phalcon_translate_adapter_abstractadapter_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, offsetGet, arginfo_phalcon_translate_adapter_abstractadapter_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, offsetSet, arginfo_phalcon_translate_adapter_abstractadapter_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, offsetUnset, arginfo_phalcon_translate_adapter_abstractadapter_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, t, arginfo_phalcon_translate_adapter_abstractadapter_t, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_AbstractAdapter, replacePlaceholders, arginfo_phalcon_translate_adapter_abstractadapter_replaceplaceholders, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

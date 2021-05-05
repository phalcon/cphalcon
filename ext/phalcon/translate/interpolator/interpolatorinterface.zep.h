
extern zend_class_entry *phalcon_translate_interpolator_interpolatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_InterpolatorInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_interpolator_interpolatorinterface_replaceplaceholders, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translation, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_interpolator_interpolatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Translate_Interpolator_InterpolatorInterface, replacePlaceholders, arginfo_phalcon_translate_interpolator_interpolatorinterface_replaceplaceholders)
	PHP_FE_END
};

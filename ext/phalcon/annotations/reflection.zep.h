
extern zend_class_entry *phalcon_annotations_reflection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection);

PHP_METHOD(Phalcon_Annotations_Reflection, __construct);
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, reflectionData, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, reflectionData, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection_getclassannotations, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection_getmethodsannotations, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection_getpropertiesannotations, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_reflection_getreflectiondata, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_reflection_method_entry) {
	PHP_ME(Phalcon_Annotations_Reflection, __construct, arginfo_phalcon_annotations_reflection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Annotations_Reflection, getClassAnnotations, arginfo_phalcon_annotations_reflection_getclassannotations, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Annotations_Reflection, getClassAnnotations, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Annotations_Reflection, getMethodsAnnotations, arginfo_phalcon_annotations_reflection_getmethodsannotations, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Annotations_Reflection, getMethodsAnnotations, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Annotations_Reflection, getPropertiesAnnotations, arginfo_phalcon_annotations_reflection_getpropertiesannotations, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Annotations_Reflection, getPropertiesAnnotations, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Annotations_Reflection, getReflectionData, arginfo_phalcon_annotations_reflection_getreflectiondata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

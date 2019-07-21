
extern zend_class_entry *phalcon_annotations_reflection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection);

PHP_METHOD(Phalcon_Annotations_Reflection, __construct);
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, reflectionData, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_reflection_getreflectiondata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_reflection_getreflectiondata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_reflection_method_entry) {
	PHP_ME(Phalcon_Annotations_Reflection, __construct, arginfo_phalcon_annotations_reflection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Reflection, getClassAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, getMethodsAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, getPropertiesAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, getReflectionData, arginfo_phalcon_annotations_reflection_getreflectiondata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

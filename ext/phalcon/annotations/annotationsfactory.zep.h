
extern zend_class_entry *phalcon_annotations_annotationsfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_AnnotationsFactory);

PHP_METHOD(Phalcon_Annotations_AnnotationsFactory, __construct);
PHP_METHOD(Phalcon_Annotations_AnnotationsFactory, load);
PHP_METHOD(Phalcon_Annotations_AnnotationsFactory, newInstance);
PHP_METHOD(Phalcon_Annotations_AnnotationsFactory, getExceptionClass);
PHP_METHOD(Phalcon_Annotations_AnnotationsFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotationsfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotationsfactory_load, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_annotationsfactory_newinstance, 0, 1, Phalcon\\Annotations\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotationsfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotationsfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_annotationsfactory_method_entry) {
	PHP_ME(Phalcon_Annotations_AnnotationsFactory, __construct, arginfo_phalcon_annotations_annotationsfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_AnnotationsFactory, load, arginfo_phalcon_annotations_annotationsfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_AnnotationsFactory, newInstance, arginfo_phalcon_annotations_annotationsfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_AnnotationsFactory, getExceptionClass, arginfo_phalcon_annotations_annotationsfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_AnnotationsFactory, getServices, arginfo_phalcon_annotations_annotationsfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *phalcon_annotations_annotation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Annotation);

PHP_METHOD(Phalcon_Annotations_Annotation, __construct);
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument);
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments);
PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments);
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression);
PHP_METHOD(Phalcon_Annotations_Annotation, getName);
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument);
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedParameter);
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument);
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments);
zend_object *zephir_init_properties_Phalcon_Annotations_Annotation(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, reflectionData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getargument, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_getarguments, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_getarguments, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_getexprarguments, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_getexprarguments, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getexpression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_getname, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_getname, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getnamedargument, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getnamedparameter, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_hasargument, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_hasargument, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_numberarguments, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_annotation_numberarguments, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_zephir_init_properties_phalcon_annotations_annotation, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_annotation_method_entry) {
	PHP_ME(Phalcon_Annotations_Annotation, __construct, arginfo_phalcon_annotations_annotation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Annotation, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getArguments, arginfo_phalcon_annotations_annotation_getarguments, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getExprArguments, arginfo_phalcon_annotations_annotation_getexprarguments, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getExpression, arginfo_phalcon_annotations_annotation_getexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getName, arginfo_phalcon_annotations_annotation_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getNamedArgument, arginfo_phalcon_annotations_annotation_getnamedargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getNamedParameter, arginfo_phalcon_annotations_annotation_getnamedparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, hasArgument, arginfo_phalcon_annotations_annotation_hasargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, numberArguments, arginfo_phalcon_annotations_annotation_numberarguments, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

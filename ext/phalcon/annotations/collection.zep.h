
extern zend_class_entry *phalcon_annotations_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Collection);

PHP_METHOD(Phalcon_Annotations_Collection, __construct);
PHP_METHOD(Phalcon_Annotations_Collection, count);
PHP_METHOD(Phalcon_Annotations_Collection, current);
PHP_METHOD(Phalcon_Annotations_Collection, get);
PHP_METHOD(Phalcon_Annotations_Collection, getAll);
PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations);
PHP_METHOD(Phalcon_Annotations_Collection, has);
PHP_METHOD(Phalcon_Annotations_Collection, key);
PHP_METHOD(Phalcon_Annotations_Collection, next);
PHP_METHOD(Phalcon_Annotations_Collection, rewind);
PHP_METHOD(Phalcon_Annotations_Collection, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_collection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, reflectionData, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_collection_current, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_collection_get, 0, 1, Phalcon\\Annotations\\Annotation, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_get, 0, 1, IS_OBJECT, "Phalcon\\Annotations\\Annotation", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_getall, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_getall, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_getannotations, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_getannotations, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_key, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_key, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_next, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_next, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_annotations_collection_next NULL
#endif

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_rewind, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_rewind, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_annotations_collection_rewind NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_valid, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_collection_valid, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_collection_method_entry) {
	PHP_ME(Phalcon_Annotations_Collection, __construct, arginfo_phalcon_annotations_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Collection, count, arginfo_phalcon_annotations_collection_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, current, arginfo_phalcon_annotations_collection_current, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, get, arginfo_phalcon_annotations_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, getAll, arginfo_phalcon_annotations_collection_getall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, getAnnotations, arginfo_phalcon_annotations_collection_getannotations, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, has, arginfo_phalcon_annotations_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, key, arginfo_phalcon_annotations_collection_key, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, next, arginfo_phalcon_annotations_collection_next, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, rewind, arginfo_phalcon_annotations_collection_rewind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, valid, arginfo_phalcon_annotations_collection_valid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

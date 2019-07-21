
extern zend_class_entry *phalcon_annotations_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, get);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethod);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethods);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperty);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperties);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getReader);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, setReader);
zend_object *zephir_init_properties_Phalcon_Annotations_Adapter_AbstractAdapter(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_get, 0, 1, Phalcon\\Annotations\\Reflection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_get, 0, 1, IS_OBJECT, "Phalcon\\Annotations\\Reflection", 0)
#endif
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getmethod, 0, 2, Phalcon\\Annotations\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getmethod, 0, 2, IS_OBJECT, "Phalcon\\Annotations\\Collection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getmethods, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getmethods, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getproperty, 0, 2, Phalcon\\Annotations\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getproperty, 0, 2, IS_OBJECT, "Phalcon\\Annotations\\Collection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, propertyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, propertyName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getproperties, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getproperties, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getreader, 0, 0, Phalcon\\Annotations\\ReaderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getreader, 0, 0, IS_OBJECT, "Phalcon\\Annotations\\ReaderInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_setreader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, get, arginfo_phalcon_annotations_adapter_abstractadapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getMethod, arginfo_phalcon_annotations_adapter_abstractadapter_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getMethods, arginfo_phalcon_annotations_adapter_abstractadapter_getmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getProperty, arginfo_phalcon_annotations_adapter_abstractadapter_getproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getProperties, arginfo_phalcon_annotations_adapter_abstractadapter_getproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getReader, arginfo_phalcon_annotations_adapter_abstractadapter_getreader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, setReader, arginfo_phalcon_annotations_adapter_abstractadapter_setreader, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

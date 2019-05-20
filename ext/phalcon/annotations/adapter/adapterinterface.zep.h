
extern zend_class_entry *phalcon_annotations_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_get, 0, 1, Phalcon\\Annotations\\Reflection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_get, 0, 1, IS_OBJECT, "Phalcon\\Annotations\\Reflection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getmethod, 0, 2, Phalcon\\Annotations\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getmethod, 0, 2, IS_OBJECT, "Phalcon\\Annotations\\Collection", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getmethods, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getmethods, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getproperty, 0, 2, Phalcon\\Annotations\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getproperty, 0, 2, IS_OBJECT, "Phalcon\\Annotations\\Collection", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getproperties, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getproperties, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getreader, 0, 0, Phalcon\\Annotations\\ReaderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_getreader, 0, 0, IS_OBJECT, "Phalcon\\Annotations\\ReaderInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_adapterinterface_setreader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, get, arginfo_phalcon_annotations_adapter_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, getMethod, arginfo_phalcon_annotations_adapter_adapterinterface_getmethod)
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, getMethods, arginfo_phalcon_annotations_adapter_adapterinterface_getmethods)
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, getProperty, arginfo_phalcon_annotations_adapter_adapterinterface_getproperty)
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, getProperties, arginfo_phalcon_annotations_adapter_adapterinterface_getproperties)
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, getReader, arginfo_phalcon_annotations_adapter_adapterinterface_getreader)
	PHP_ABSTRACT_ME(Phalcon_Annotations_Adapter_AdapterInterface, setReader, arginfo_phalcon_annotations_adapter_adapterinterface_setreader)
	PHP_FE_END
};

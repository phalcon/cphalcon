
extern zend_class_entry *phalcon_annotations_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, get);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getConstant);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getConstants);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperty);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperties);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethod);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethods);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getReader);
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, setReader);
zend_object *zephir_init_properties_Phalcon_Annotations_Adapter_AbstractAdapter(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_get, 0, 1, Phalcon\\Annotations\\Reflection, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getconstant, 0, 2, Phalcon\\Annotations\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, constantName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getconstants, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getproperty, 0, 2, Phalcon\\Annotations\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, propertyName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getproperties, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getmethod, 0, 2, Phalcon\\Annotations\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getmethods, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_getreader, 0, 0, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_setreader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_abstractadapter_zephir_init_properties_phalcon_annotations_adapter_abstractadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, get, arginfo_phalcon_annotations_adapter_abstractadapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getConstant, arginfo_phalcon_annotations_adapter_abstractadapter_getconstant, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getConstants, arginfo_phalcon_annotations_adapter_abstractadapter_getconstants, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getProperty, arginfo_phalcon_annotations_adapter_abstractadapter_getproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getProperties, arginfo_phalcon_annotations_adapter_abstractadapter_getproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getMethod, arginfo_phalcon_annotations_adapter_abstractadapter_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getMethods, arginfo_phalcon_annotations_adapter_abstractadapter_getmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, getReader, arginfo_phalcon_annotations_adapter_abstractadapter_getreader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_AbstractAdapter, setReader, arginfo_phalcon_annotations_adapter_abstractadapter_setreader, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

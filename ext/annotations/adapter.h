
extern zend_class_entry *phalcon_annotations_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter);

PHP_METHOD(Phalcon_Annotations_Adapter, setReader);
PHP_METHOD(Phalcon_Annotations_Adapter, getReader);
PHP_METHOD(Phalcon_Annotations_Adapter, get);
PHP_METHOD(Phalcon_Annotations_Adapter, getMethods);
PHP_METHOD(Phalcon_Annotations_Adapter, getMethod);
PHP_METHOD(Phalcon_Annotations_Adapter, getProperties);
PHP_METHOD(Phalcon_Annotations_Adapter, getProperty);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_setReader, 0, 0, 0)
	ZEND_ARG_INFO(0, reader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_get, 0, 0, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getMethods, 0, 0, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getMethod, 0, 0, 0)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getProperties, 0, 0, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getProperty, 0, 0, 0)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter, setReader, arginfo_phalcon_annotations_adapter_setReader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getReader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, get, arginfo_phalcon_annotations_adapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getMethods, arginfo_phalcon_annotations_adapter_getMethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getMethod, arginfo_phalcon_annotations_adapter_getMethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getProperties, arginfo_phalcon_annotations_adapter_getProperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getProperty, arginfo_phalcon_annotations_adapter_getProperty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_annotations_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_setreader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, setReader, arginfo_phalcon_annotations_adapterinterface_setreader)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getReader, NULL)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, get, arginfo_phalcon_annotations_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getMethods, arginfo_phalcon_annotations_adapterinterface_getmethods)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getMethod, arginfo_phalcon_annotations_adapterinterface_getmethod)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getProperties, arginfo_phalcon_annotations_adapterinterface_getproperties)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getProperty, arginfo_phalcon_annotations_adapterinterface_getproperty)
	PHP_FE_END
};

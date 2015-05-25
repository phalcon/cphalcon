
extern zend_class_entry *phalcon_annotations_adapter_apc_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Apc);

PHP_METHOD(Phalcon_Annotations_Adapter_Apc, __construct);
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_apc_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Apc, __construct, arginfo_phalcon_annotations_adapter_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Adapter_Apc, read, arginfo_phalcon_annotations_adapter_apc_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Apc, write, arginfo_phalcon_annotations_adapter_apc_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

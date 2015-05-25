
extern zend_class_entry *phalcon_annotations_adapter_xcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Xcache);

PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_xcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_xcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_xcache_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Xcache, read, arginfo_phalcon_annotations_adapter_xcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Xcache, write, arginfo_phalcon_annotations_adapter_xcache_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

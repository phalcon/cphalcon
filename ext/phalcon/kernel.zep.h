
extern zend_class_entry *phalcon_kernel_ce;

ZEPHIR_INIT_CLASS(Phalcon_Kernel);

PHP_METHOD(Phalcon_Kernel, preComputeHashKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_kernel_precomputehashkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_kernel_method_entry) {
	PHP_ME(Phalcon_Kernel, preComputeHashKey, arginfo_phalcon_kernel_precomputehashkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_paginator_adapter_nativearray_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray);

PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_nativearray_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, __construct, arginfo_phalcon_paginator_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, getPaginate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

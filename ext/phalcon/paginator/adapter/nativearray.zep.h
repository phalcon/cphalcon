
extern zend_class_entry *phalcon_paginator_adapter_nativearray_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray);

PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, paginate);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray_paginate, 0, 0, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray_paginate, 0, 0, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_nativearray_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, paginate, arginfo_phalcon_paginator_adapter_nativearray_paginate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_paginator_paginatorfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_PaginatorFactory);

PHP_METHOD(Phalcon_Paginator_PaginatorFactory, __construct);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, load);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, newInstance);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_paginatorfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_load, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_newinstance, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_paginatorfactory_method_entry) {
	PHP_ME(Phalcon_Paginator_PaginatorFactory, __construct, arginfo_phalcon_paginator_paginatorfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, load, arginfo_phalcon_paginator_paginatorfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, newInstance, arginfo_phalcon_paginator_paginatorfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, getServices, arginfo_phalcon_paginator_paginatorfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

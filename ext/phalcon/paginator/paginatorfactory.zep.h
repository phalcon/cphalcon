
extern zend_class_entry *phalcon_paginator_paginatorfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_PaginatorFactory);

PHP_METHOD(Phalcon_Paginator_PaginatorFactory, __construct);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, load);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, newInstance);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, getExceptionClass);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, getServices);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, checkConfig);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, checkConfigElement);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, getCachedInstance);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, getService);
PHP_METHOD(Phalcon_Paginator_PaginatorFactory, init);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_paginatorfactory___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_load, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_newinstance, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_checkconfig, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_checkconfigelement, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_paginator_paginatorfactory_getcachedinstance, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_VARIADIC_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_getservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_paginatorfactory_init, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_paginatorfactory_method_entry) {
	PHP_ME(Phalcon_Paginator_PaginatorFactory, __construct, arginfo_phalcon_paginator_paginatorfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, load, arginfo_phalcon_paginator_paginatorfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, newInstance, arginfo_phalcon_paginator_paginatorfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, getExceptionClass, arginfo_phalcon_paginator_paginatorfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, getServices, arginfo_phalcon_paginator_paginatorfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, checkConfig, arginfo_phalcon_paginator_paginatorfactory_checkconfig, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, checkConfigElement, arginfo_phalcon_paginator_paginatorfactory_checkconfigelement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, getCachedInstance, arginfo_phalcon_paginator_paginatorfactory_getcachedinstance, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, getService, arginfo_phalcon_paginator_paginatorfactory_getservice, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_PaginatorFactory, init, arginfo_phalcon_paginator_paginatorfactory_init, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *phalcon_paginator_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter);

PHP_METHOD(Phalcon_Paginator_Adapter, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter, setLimit);
PHP_METHOD(Phalcon_Paginator_Adapter, getLimit);
PHP_METHOD(Phalcon_Paginator_Adapter, setRepository);
PHP_METHOD(Phalcon_Paginator_Adapter, getRepository);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 1, Phalcon\\Paginator\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, page)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 1, Phalcon\\Paginator\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limitRows, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limitRows)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_getlimit, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_getlimit, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setrepository, 0, 1, Phalcon\\Paginator\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_setrepository, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\Adapter", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, repository, Phalcon\\Paginator\\RepositoryInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_getrepository, 0, 0, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_getrepository, 0, 0, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, properties, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter, __construct, arginfo_phalcon_paginator_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter, setCurrentPage, arginfo_phalcon_paginator_adapter_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setLimit, arginfo_phalcon_paginator_adapter_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, getLimit, arginfo_phalcon_paginator_adapter_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setRepository, arginfo_phalcon_paginator_adapter_setrepository, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, getRepository, arginfo_phalcon_paginator_adapter_getrepository, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *phalcon_paginator_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, getLimit);
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, setLimit);
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, setRepository);
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, getRepository);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_abstractadapter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_abstractadapter_getlimit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_abstractadapter_setcurrentpage, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_abstractadapter_setlimit, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, limitRows, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_abstractadapter_setrepository, 0, 1, Phalcon\\Paginator\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, repository, Phalcon\\Paginator\\RepositoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_abstractadapter_getrepository, 0, 0, Phalcon\\Paginator\\RepositoryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, properties, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_AbstractAdapter, __construct, arginfo_phalcon_paginator_adapter_abstractadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_AbstractAdapter, getLimit, arginfo_phalcon_paginator_adapter_abstractadapter_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_AbstractAdapter, setCurrentPage, arginfo_phalcon_paginator_adapter_abstractadapter_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_AbstractAdapter, setLimit, arginfo_phalcon_paginator_adapter_abstractadapter_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_AbstractAdapter, setRepository, arginfo_phalcon_paginator_adapter_abstractadapter_setrepository, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_AbstractAdapter, getRepository, arginfo_phalcon_paginator_adapter_abstractadapter_getrepository, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

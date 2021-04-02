
extern zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder);

PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, paginate);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_getcurrentpage, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_getquerybuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\Builder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_paginate, 0, 0, Phalcon\\Paginator\\RepositoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, 0, 1, Phalcon\\Paginator\\Adapter\\QueryBuilder, 0)
	ZEND_ARG_OBJ_INFO(0, builder, Phalcon\\Mvc\\Model\\Query\\Builder, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_querybuilder_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, __construct, arginfo_phalcon_paginator_adapter_querybuilder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage, arginfo_phalcon_paginator_adapter_querybuilder_getcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder, arginfo_phalcon_paginator_adapter_querybuilder_getquerybuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, paginate, arginfo_phalcon_paginator_adapter_querybuilder_paginate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder, arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

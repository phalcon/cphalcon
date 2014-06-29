
extern zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder);

PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, currentPage)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_querybuilder_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, __construct, arginfo_phalcon_paginator_adapter_querybuilder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage, arginfo_phalcon_paginator_adapter_querybuilder_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};

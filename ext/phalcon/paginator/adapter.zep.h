
extern zend_class_entry *phalcon_paginator_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter);

PHP_METHOD(Phalcon_Paginator_Adapter, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter, setLimit);
PHP_METHOD(Phalcon_Paginator_Adapter, getLimit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, limitRows)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter, setCurrentPage, arginfo_phalcon_paginator_adapter_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setLimit, arginfo_phalcon_paginator_adapter_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

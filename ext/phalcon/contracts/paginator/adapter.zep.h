
extern zend_class_entry *phalcon_contracts_paginator_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Paginator_Adapter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_paginator_adapter_getlimit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_paginator_adapter_paginate, 0, 0, Phalcon\\Contracts\\Paginator\\Repository, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_paginator_adapter_setcurrentpage, 0, 1, Phalcon\\Contracts\\Paginator\\Adapter, 0)
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_paginator_adapter_setlimit, 0, 1, Phalcon\\Contracts\\Paginator\\Adapter, 0)
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_paginator_adapter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Paginator_Adapter, getLimit, arginfo_phalcon_contracts_paginator_adapter_getlimit)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Paginator_Adapter, paginate, arginfo_phalcon_contracts_paginator_adapter_paginate)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Paginator_Adapter, setCurrentPage, arginfo_phalcon_contracts_paginator_adapter_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Paginator_Adapter, setLimit, arginfo_phalcon_contracts_paginator_adapter_setlimit)
	PHP_FE_END
};

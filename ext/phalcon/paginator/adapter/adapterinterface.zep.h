
extern zend_class_entry *phalcon_paginator_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_adapterinterface_getlimit, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_adapterinterface_getlimit, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_adapterinterface_paginate, 0, 0, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_adapterinterface_paginate, 0, 0, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_adapterinterface_setcurrentpage, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, page)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_adapterinterface_setlimit, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Paginator_Adapter_AdapterInterface, getLimit, arginfo_phalcon_paginator_adapter_adapterinterface_getlimit)
	PHP_ABSTRACT_ME(Phalcon_Paginator_Adapter_AdapterInterface, paginate, arginfo_phalcon_paginator_adapter_adapterinterface_paginate)
	PHP_ABSTRACT_ME(Phalcon_Paginator_Adapter_AdapterInterface, setCurrentPage, arginfo_phalcon_paginator_adapter_adapterinterface_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Paginator_Adapter_AdapterInterface, setLimit, arginfo_phalcon_paginator_adapter_adapterinterface_setlimit)
	PHP_FE_END
};

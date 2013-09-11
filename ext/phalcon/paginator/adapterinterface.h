
extern zend_class_entry *phalcon_paginator_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setcurrentpage, 0, 0, 0)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, __construct, arginfo_phalcon_paginator_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getPaginate, NULL)
	PHP_FE_END
};


extern zend_class_entry *phalcon_paginator_repositoryinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_RepositoryInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getaliases, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getaliases, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getcurrent, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getcurrent, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getfirst, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getfirst, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getitems, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getlast, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getlast, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getlimit, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getlimit, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getnext, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getnext, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getprevious, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_getprevious, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_gettotalitems, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_gettotalitems, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_setaliases, 0, 1, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_setaliases, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, aliases, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_setproperties, 0, 1, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repositoryinterface_setproperties, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_repositoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getAliases, arginfo_phalcon_paginator_repositoryinterface_getaliases)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getCurrent, arginfo_phalcon_paginator_repositoryinterface_getcurrent)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getFirst, arginfo_phalcon_paginator_repositoryinterface_getfirst)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getItems, arginfo_phalcon_paginator_repositoryinterface_getitems)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getLast, arginfo_phalcon_paginator_repositoryinterface_getlast)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getLimit, arginfo_phalcon_paginator_repositoryinterface_getlimit)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getNext, arginfo_phalcon_paginator_repositoryinterface_getnext)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getPrevious, arginfo_phalcon_paginator_repositoryinterface_getprevious)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, getTotalItems, arginfo_phalcon_paginator_repositoryinterface_gettotalitems)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, setAliases, arginfo_phalcon_paginator_repositoryinterface_setaliases)
	PHP_ABSTRACT_ME(Phalcon_Paginator_RepositoryInterface, setProperties, arginfo_phalcon_paginator_repositoryinterface_setproperties)
	PHP_FE_END
};

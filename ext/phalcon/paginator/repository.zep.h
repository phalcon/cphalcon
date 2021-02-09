
extern zend_class_entry *phalcon_paginator_repository_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Repository);

PHP_METHOD(Phalcon_Paginator_Repository, __get);
PHP_METHOD(Phalcon_Paginator_Repository, getAliases);
PHP_METHOD(Phalcon_Paginator_Repository, getCurrent);
PHP_METHOD(Phalcon_Paginator_Repository, getFirst);
PHP_METHOD(Phalcon_Paginator_Repository, getItems);
PHP_METHOD(Phalcon_Paginator_Repository, getLast);
PHP_METHOD(Phalcon_Paginator_Repository, getLimit);
PHP_METHOD(Phalcon_Paginator_Repository, getNext);
PHP_METHOD(Phalcon_Paginator_Repository, getPrevious);
PHP_METHOD(Phalcon_Paginator_Repository, getTotalItems);
PHP_METHOD(Phalcon_Paginator_Repository, jsonSerialize);
PHP_METHOD(Phalcon_Paginator_Repository, setAliases);
PHP_METHOD(Phalcon_Paginator_Repository, setProperties);
PHP_METHOD(Phalcon_Paginator_Repository, getProperty);
PHP_METHOD(Phalcon_Paginator_Repository, getRealNameProperty);
zend_object *zephir_init_properties_Phalcon_Paginator_Repository(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_repository___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getaliases, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getaliases, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getcurrent, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getcurrent, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getfirst, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getfirst, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_repository_getitems, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getlast, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getlast, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getlimit, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getlimit, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getnext, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getnext, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getprevious, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getprevious, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_gettotalitems, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_gettotalitems, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_jsonserialize, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_jsonserialize, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_repository_setaliases, 0, 1, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_setaliases, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, aliases, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_repository_setproperties, 0, 1, Phalcon\\Paginator\\RepositoryInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_setproperties, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\RepositoryInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_repository_getproperty, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getrealnameproperty, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_repository_getrealnameproperty, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_repository_zephir_init_properties_phalcon_paginator_repository, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_repository_method_entry) {
	PHP_ME(Phalcon_Paginator_Repository, __get, arginfo_phalcon_paginator_repository___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getAliases, arginfo_phalcon_paginator_repository_getaliases, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getCurrent, arginfo_phalcon_paginator_repository_getcurrent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getFirst, arginfo_phalcon_paginator_repository_getfirst, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getItems, arginfo_phalcon_paginator_repository_getitems, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getLast, arginfo_phalcon_paginator_repository_getlast, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getLimit, arginfo_phalcon_paginator_repository_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getNext, arginfo_phalcon_paginator_repository_getnext, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getPrevious, arginfo_phalcon_paginator_repository_getprevious, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getTotalItems, arginfo_phalcon_paginator_repository_gettotalitems, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, jsonSerialize, arginfo_phalcon_paginator_repository_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, setAliases, arginfo_phalcon_paginator_repository_setaliases, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, setProperties, arginfo_phalcon_paginator_repository_setproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Repository, getProperty, arginfo_phalcon_paginator_repository_getproperty, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Paginator_Repository, getRealNameProperty, arginfo_phalcon_paginator_repository_getrealnameproperty, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *phalcon_mvc_router_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Group);

PHP_METHOD(Phalcon_Mvc_Router_Group, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router_Group, add);
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete);
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions);
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead);
PHP_METHOD(Phalcon_Mvc_Router_Group, clear);
PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group__addroute, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_group_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Group, __construct, arginfo_phalcon_mvc_router_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Group, setHostname, arginfo_phalcon_mvc_router_group_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getHostname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPrefix, arginfo_phalcon_mvc_router_group_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, beforeMatch, arginfo_phalcon_mvc_router_group_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPaths, arginfo_phalcon_mvc_router_group_setpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, add, arginfo_phalcon_mvc_router_group_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addGet, arginfo_phalcon_mvc_router_group_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPost, arginfo_phalcon_mvc_router_group_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPut, arginfo_phalcon_mvc_router_group_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPatch, arginfo_phalcon_mvc_router_group_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addDelete, arginfo_phalcon_mvc_router_group_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addOptions, arginfo_phalcon_mvc_router_group_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addHead, arginfo_phalcon_mvc_router_group_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, _addRoute, arginfo_phalcon_mvc_router_group__addroute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

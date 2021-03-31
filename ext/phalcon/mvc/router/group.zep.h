
extern zend_class_entry *phalcon_mvc_router_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Group);

PHP_METHOD(Phalcon_Mvc_Router_Group, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Group, add);
PHP_METHOD(Phalcon_Mvc_Router_Group, addConnect);
PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete);
PHP_METHOD(Phalcon_Mvc_Router_Group, addGet);
PHP_METHOD(Phalcon_Mvc_Router_Group, addHead);
PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPost);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPurge);
PHP_METHOD(Phalcon_Mvc_Router_Group, addPut);
PHP_METHOD(Phalcon_Mvc_Router_Group, addTrace);
PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, clear);
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, addRoute);
zend_object *zephir_init_properties_Phalcon_Mvc_Router_Group(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_add, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addconnect, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_adddelete, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addget, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addhead, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addoptions, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addpatch, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addpost, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addpurge, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addput, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addtrace, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_beforematch, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_group_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_getbeforematch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_group_gethostname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_getpaths, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_group_getprefix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_group_getroutes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_sethostname, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
	ZEND_ARG_TYPE_INFO(0, hostname, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_setpaths, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_setprefix, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_group_addroute, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_zephir_init_properties_phalcon_mvc_router_group, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_group_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Group, __construct, arginfo_phalcon_mvc_router_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Group, add, arginfo_phalcon_mvc_router_group_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addConnect, arginfo_phalcon_mvc_router_group_addconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addDelete, arginfo_phalcon_mvc_router_group_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addGet, arginfo_phalcon_mvc_router_group_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addHead, arginfo_phalcon_mvc_router_group_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addOptions, arginfo_phalcon_mvc_router_group_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPatch, arginfo_phalcon_mvc_router_group_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPost, arginfo_phalcon_mvc_router_group_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPurge, arginfo_phalcon_mvc_router_group_addpurge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPut, arginfo_phalcon_mvc_router_group_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addTrace, arginfo_phalcon_mvc_router_group_addtrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, beforeMatch, arginfo_phalcon_mvc_router_group_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, clear, arginfo_phalcon_mvc_router_group_clear, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Router_Group, getBeforeMatch, arginfo_phalcon_mvc_router_group_getbeforematch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Router_Group, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Router_Group, getHostname, arginfo_phalcon_mvc_router_group_gethostname, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, arginfo_phalcon_mvc_router_group_getpaths, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Router_Group, getPrefix, arginfo_phalcon_mvc_router_group_getprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getRoutes, arginfo_phalcon_mvc_router_group_getroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setHostname, arginfo_phalcon_mvc_router_group_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPaths, arginfo_phalcon_mvc_router_group_setpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPrefix, arginfo_phalcon_mvc_router_group_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addRoute, arginfo_phalcon_mvc_router_group_addroute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

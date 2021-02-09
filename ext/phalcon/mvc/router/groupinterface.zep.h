
extern zend_class_entry *phalcon_mvc_router_groupinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_GroupInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_add, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_add, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addconnect, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addconnect, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_adddelete, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_adddelete, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addget, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addget, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addhead, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addhead, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addoptions, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addoptions, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpatch, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpatch, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpost, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpost, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpurge, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpurge, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addput, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addput, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addtrace, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addtrace, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_beforematch, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_beforematch, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\GroupInterface", 0)
#endif
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_clear, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_clear, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_mvc_router_groupinterface_clear NULL
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_getbeforematch, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_gethostname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_gethostname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_getpaths, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_getprefix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_getprefix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_getroutes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_getroutes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_sethostname, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_sethostname, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\GroupInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, hostname, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, hostname)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setpaths, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setpaths, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\GroupInterface", 0)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setprefix, 0, 1, Phalcon\\Mvc\\Router\\GroupInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setprefix, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\GroupInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_groupinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, add, arginfo_phalcon_mvc_router_groupinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addConnect, arginfo_phalcon_mvc_router_groupinterface_addconnect)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addDelete, arginfo_phalcon_mvc_router_groupinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addGet, arginfo_phalcon_mvc_router_groupinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addHead, arginfo_phalcon_mvc_router_groupinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addOptions, arginfo_phalcon_mvc_router_groupinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPatch, arginfo_phalcon_mvc_router_groupinterface_addpatch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPost, arginfo_phalcon_mvc_router_groupinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPurge, arginfo_phalcon_mvc_router_groupinterface_addpurge)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPut, arginfo_phalcon_mvc_router_groupinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addTrace, arginfo_phalcon_mvc_router_groupinterface_addtrace)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, beforeMatch, arginfo_phalcon_mvc_router_groupinterface_beforematch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, clear, arginfo_phalcon_mvc_router_groupinterface_clear)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getBeforeMatch, arginfo_phalcon_mvc_router_groupinterface_getbeforematch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getHostname, arginfo_phalcon_mvc_router_groupinterface_gethostname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getPaths, arginfo_phalcon_mvc_router_groupinterface_getpaths)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getPrefix, arginfo_phalcon_mvc_router_groupinterface_getprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getRoutes, arginfo_phalcon_mvc_router_groupinterface_getroutes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setHostname, arginfo_phalcon_mvc_router_groupinterface_sethostname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setPaths, arginfo_phalcon_mvc_router_groupinterface_setpaths)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setPrefix, arginfo_phalcon_mvc_router_groupinterface_setprefix)
	PHP_FE_END
};


extern zend_class_entry *phalcon_mvc_router_groupinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_GroupInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_groupinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setHostname, arginfo_phalcon_mvc_router_groupinterface_sethostname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getHostname, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setPrefix, arginfo_phalcon_mvc_router_groupinterface_setprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getPrefix, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, beforeMatch, arginfo_phalcon_mvc_router_groupinterface_beforematch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getBeforeMatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setPaths, arginfo_phalcon_mvc_router_groupinterface_setpaths)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, add, arginfo_phalcon_mvc_router_groupinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addGet, arginfo_phalcon_mvc_router_groupinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPost, arginfo_phalcon_mvc_router_groupinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPut, arginfo_phalcon_mvc_router_groupinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPatch, arginfo_phalcon_mvc_router_groupinterface_addpatch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addDelete, arginfo_phalcon_mvc_router_groupinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addOptions, arginfo_phalcon_mvc_router_groupinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addHead, arginfo_phalcon_mvc_router_groupinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, clear, NULL)
	PHP_FE_END
};

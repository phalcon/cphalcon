
extern zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_delete, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_get, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_gethandler, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_gethandlers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_getprefix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_head, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_islazy, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_map, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_options, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_patch, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_post, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_put, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_sethandler, 0, 1, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, lazy, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setlazy, 0, 1, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, lazy, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setprefix, 0, 1, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, delete, arginfo_phalcon_mvc_micro_collectioninterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, get, arginfo_phalcon_mvc_micro_collectioninterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandler, arginfo_phalcon_mvc_micro_collectioninterface_gethandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandlers, arginfo_phalcon_mvc_micro_collectioninterface_gethandlers)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getPrefix, arginfo_phalcon_mvc_micro_collectioninterface_getprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, head, arginfo_phalcon_mvc_micro_collectioninterface_head)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, isLazy, arginfo_phalcon_mvc_micro_collectioninterface_islazy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, map, arginfo_phalcon_mvc_micro_collectioninterface_map)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, options, arginfo_phalcon_mvc_micro_collectioninterface_options)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, patch, arginfo_phalcon_mvc_micro_collectioninterface_patch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, post, arginfo_phalcon_mvc_micro_collectioninterface_post)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, put, arginfo_phalcon_mvc_micro_collectioninterface_put)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setHandler, arginfo_phalcon_mvc_micro_collectioninterface_sethandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setLazy, arginfo_phalcon_mvc_micro_collectioninterface_setlazy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setPrefix, arginfo_phalcon_mvc_micro_collectioninterface_setprefix)
	PHP_FE_END
};

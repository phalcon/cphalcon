
extern zend_class_entry *phalcon_mvc_micro_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_Collection);

PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, mapVia);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, addMap);
zend_object *zephir_init_properties_Phalcon_Mvc_Micro_Collection(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_delete, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_get, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_gethandler, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collection_gethandlers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collection_getprefix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_head, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collection_islazy, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_map, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_mapvia, 0, 3, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_options, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_patch, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_post, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_put, 0, 2, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_sethandler, 0, 1, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, lazy, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_setlazy, 0, 1, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, lazy, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_collection_setprefix, 0, 1, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_collection_addmap, 0, 3, IS_VOID, 0)

	ZEND_ARG_INFO(0, method)
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_zephir_init_properties_phalcon_mvc_micro_collection, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_collection_method_entry) {
	PHP_ME(Phalcon_Mvc_Micro_Collection, delete, arginfo_phalcon_mvc_micro_collection_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, get, arginfo_phalcon_mvc_micro_collection_get, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandler, arginfo_phalcon_mvc_micro_collection_gethandler, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandler, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandlers, arginfo_phalcon_mvc_micro_collection_gethandlers, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getPrefix, arginfo_phalcon_mvc_micro_collection_getprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, head, arginfo_phalcon_mvc_micro_collection_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, isLazy, arginfo_phalcon_mvc_micro_collection_islazy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, map, arginfo_phalcon_mvc_micro_collection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, mapVia, arginfo_phalcon_mvc_micro_collection_mapvia, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, options, arginfo_phalcon_mvc_micro_collection_options, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, patch, arginfo_phalcon_mvc_micro_collection_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, post, arginfo_phalcon_mvc_micro_collection_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, put, arginfo_phalcon_mvc_micro_collection_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setHandler, arginfo_phalcon_mvc_micro_collection_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setLazy, arginfo_phalcon_mvc_micro_collection_setlazy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setPrefix, arginfo_phalcon_mvc_micro_collection_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, addMap, arginfo_phalcon_mvc_micro_collection_addmap, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

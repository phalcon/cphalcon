
extern zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setlazy, 0, 0, 1)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setPrefix, arginfo_phalcon_mvc_micro_collectioninterface_setprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getPrefix, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandlers, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setHandler, arginfo_phalcon_mvc_micro_collectioninterface_sethandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setLazy, arginfo_phalcon_mvc_micro_collectioninterface_setlazy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, isLazy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, map, arginfo_phalcon_mvc_micro_collectioninterface_map)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, get, arginfo_phalcon_mvc_micro_collectioninterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, post, arginfo_phalcon_mvc_micro_collectioninterface_post)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, put, arginfo_phalcon_mvc_micro_collectioninterface_put)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, patch, arginfo_phalcon_mvc_micro_collectioninterface_patch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, head, arginfo_phalcon_mvc_micro_collectioninterface_head)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, delete, arginfo_phalcon_mvc_micro_collectioninterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, options, arginfo_phalcon_mvc_micro_collectioninterface_options)
	PHP_FE_END
};

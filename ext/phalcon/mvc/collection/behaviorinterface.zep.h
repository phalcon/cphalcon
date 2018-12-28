
extern zend_class_entry *phalcon_mvc_collection_behaviorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_BehaviorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface_notify, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behaviorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, notify, arginfo_phalcon_mvc_collection_behaviorinterface_notify)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, missingMethod, arginfo_phalcon_mvc_collection_behaviorinterface_missingmethod)
	PHP_FE_END
};

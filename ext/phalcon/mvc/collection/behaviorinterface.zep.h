
extern zend_class_entry *phalcon_mvc_collection_behaviorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_BehaviorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behaviorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, __construct, arginfo_phalcon_mvc_collection_behaviorinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, notify, arginfo_phalcon_mvc_collection_behaviorinterface_notify)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, missingMethod, arginfo_phalcon_mvc_collection_behaviorinterface_missingmethod)
	PHP_FE_END
};

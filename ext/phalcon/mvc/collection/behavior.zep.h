
extern zend_class_entry *phalcon_mvc_collection_behavior_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Behavior);

PHP_METHOD(Phalcon_Mvc_Collection_Behavior, __construct);
PHP_METHOD(Phalcon_Mvc_Collection_Behavior, mustTakeAction);
PHP_METHOD(Phalcon_Mvc_Collection_Behavior, getOptions);
PHP_METHOD(Phalcon_Mvc_Collection_Behavior, notify);
PHP_METHOD(Phalcon_Mvc_Collection_Behavior, missingMethod);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_musttakeaction, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_getoptions, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behavior_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Behavior, __construct, arginfo_phalcon_mvc_collection_behavior___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, mustTakeAction, arginfo_phalcon_mvc_collection_behavior_musttakeaction, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, getOptions, arginfo_phalcon_mvc_collection_behavior_getoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, notify, arginfo_phalcon_mvc_collection_behavior_notify, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, missingMethod, arginfo_phalcon_mvc_collection_behavior_missingmethod, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

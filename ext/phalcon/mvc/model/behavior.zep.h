
extern zend_class_entry *phalcon_mvc_model_behavior_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior);

PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction);
PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_getoptions, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_behavior_musttakeaction, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_notify, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_behavior_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Behavior, __construct, arginfo_phalcon_mvc_model_behavior___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Behavior, getOptions, arginfo_phalcon_mvc_model_behavior_getoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Behavior, missingMethod, arginfo_phalcon_mvc_model_behavior_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior, mustTakeAction, arginfo_phalcon_mvc_model_behavior_musttakeaction, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Behavior, notify, arginfo_phalcon_mvc_model_behavior_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

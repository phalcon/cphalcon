
extern zend_class_entry *phalcon_queue_cli_consumertask_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Cli_ConsumerTask);

PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, mainAction);
PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, intOption);
PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, stringParam);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_cli_consumertask_mainaction, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_cli_consumertask_intoption, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Cli\\Dispatcher, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_cli_consumertask_stringparam, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_cli_consumertask_method_entry) {
	PHP_ME(Phalcon_Queue_Cli_ConsumerTask, mainAction, arginfo_phalcon_queue_cli_consumertask_mainaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Cli_ConsumerTask, intOption, arginfo_phalcon_queue_cli_consumertask_intoption, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Cli_ConsumerTask, stringParam, arginfo_phalcon_queue_cli_consumertask_stringparam, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

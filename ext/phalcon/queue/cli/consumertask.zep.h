
extern zend_class_entry *phalcon_queue_cli_consumertask_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Cli_ConsumerTask);

PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, mainAction);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_cli_consumertask_mainaction, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_cli_consumertask_method_entry) {
	PHP_ME(Phalcon_Queue_Cli_ConsumerTask, mainAction, arginfo_phalcon_queue_cli_consumertask_mainaction, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

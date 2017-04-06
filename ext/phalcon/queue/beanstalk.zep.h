
extern zend_class_entry *phalcon_queue_beanstalk_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk);

PHP_METHOD(Phalcon_Queue_Beanstalk, __construct);
PHP_METHOD(Phalcon_Queue_Beanstalk, connect);
PHP_METHOD(Phalcon_Queue_Beanstalk, put);
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve);
PHP_METHOD(Phalcon_Queue_Beanstalk, choose);
PHP_METHOD(Phalcon_Queue_Beanstalk, watch);
PHP_METHOD(Phalcon_Queue_Beanstalk, ignore);
PHP_METHOD(Phalcon_Queue_Beanstalk, pauseTube);
PHP_METHOD(Phalcon_Queue_Beanstalk, kick);
PHP_METHOD(Phalcon_Queue_Beanstalk, stats);
PHP_METHOD(Phalcon_Queue_Beanstalk, statsTube);
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubes);
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubeUsed);
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubesWatched);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekDelayed);
PHP_METHOD(Phalcon_Queue_Beanstalk, jobPeek);
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus);
PHP_METHOD(Phalcon_Queue_Beanstalk, readYaml);
PHP_METHOD(Phalcon_Queue_Beanstalk, read);
PHP_METHOD(Phalcon_Queue_Beanstalk, write);
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect);
PHP_METHOD(Phalcon_Queue_Beanstalk, quit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_put, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_reserve, 0, 0, 0)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_choose, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_watch, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_ignore, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_pausetube, 0, 0, 2)
	ZEND_ARG_INFO(0, tube)
	ZEND_ARG_INFO(0, delay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_kick, 0, 0, 1)
	ZEND_ARG_INFO(0, bound)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_statstube, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_jobpeek, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_read, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_beanstalk_method_entry) {
	PHP_ME(Phalcon_Queue_Beanstalk, __construct, arginfo_phalcon_queue_beanstalk___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Beanstalk, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, put, arginfo_phalcon_queue_beanstalk_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, reserve, arginfo_phalcon_queue_beanstalk_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, choose, arginfo_phalcon_queue_beanstalk_choose, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, watch, arginfo_phalcon_queue_beanstalk_watch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, ignore, arginfo_phalcon_queue_beanstalk_ignore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, pauseTube, arginfo_phalcon_queue_beanstalk_pausetube, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, kick, arginfo_phalcon_queue_beanstalk_kick, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, stats, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, statsTube, arginfo_phalcon_queue_beanstalk_statstube, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, listTubes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, listTubeUsed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, listTubesWatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekReady, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekBuried, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekDelayed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, jobPeek, arginfo_phalcon_queue_beanstalk_jobpeek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, readStatus, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, readYaml, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, read, arginfo_phalcon_queue_beanstalk_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, write, arginfo_phalcon_queue_beanstalk_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, disconnect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, quit, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

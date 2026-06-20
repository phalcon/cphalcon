
extern zend_class_entry *phalcon_queue_adapter_beanstalk_beanstalkconnection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection);

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, buryJob);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, connect);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, deleteJob);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, disconnect);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, ignoreTube);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, put);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, read);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, readStatus);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, releaseJob);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, reserve);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, touchJob);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, useTube);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, watchTube);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, host, IS_STRING, 0, "'127.0.0.1'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, port, IS_LONG, 0, "11300")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, persistent, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_buryjob, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_connect, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_deletejob, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_disconnect, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_ignoretube, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tube, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_put, 0, 4, MAY_BE_LONG|MAY_BE_BOOL)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delay, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ttr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_read, 0, 0, MAY_BE_BOOL|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_readstatus, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_releasejob, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delay, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_reserve, 0, 0, IS_ARRAY, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_touchjob, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_usetube, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tube, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_watchtube, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tube, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_write, 0, 1, MAY_BE_BOOL|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_beanstalk_beanstalkconnection_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, __construct, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, buryJob, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_buryjob, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, connect, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, deleteJob, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_deletejob, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, disconnect, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_disconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, ignoreTube, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_ignoretube, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, put, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, read, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, readStatus, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_readstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, releaseJob, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_releasejob, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, reserve, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, touchJob, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_touchjob, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, useTube, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_usetube, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, watchTube, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_watchtube, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, write, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconnection_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

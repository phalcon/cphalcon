
extern zend_class_entry *phalcon_contracts_queue_topic_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Topic);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_topic_gettopicname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_topic_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Topic, getTopicName, arginfo_phalcon_contracts_queue_topic_gettopicname)
	PHP_FE_END
};

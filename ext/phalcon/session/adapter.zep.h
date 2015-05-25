
extern zend_class_entry *phalcon_session_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter);

PHP_METHOD(Phalcon_Session_Adapter, __construct);
PHP_METHOD(Phalcon_Session_Adapter, start);
PHP_METHOD(Phalcon_Session_Adapter, setOptions);
PHP_METHOD(Phalcon_Session_Adapter, getOptions);
PHP_METHOD(Phalcon_Session_Adapter, get);
PHP_METHOD(Phalcon_Session_Adapter, set);
PHP_METHOD(Phalcon_Session_Adapter, has);
PHP_METHOD(Phalcon_Session_Adapter, remove);
PHP_METHOD(Phalcon_Session_Adapter, getId);
PHP_METHOD(Phalcon_Session_Adapter, setId);
PHP_METHOD(Phalcon_Session_Adapter, isStarted);
PHP_METHOD(Phalcon_Session_Adapter, destroy);
PHP_METHOD(Phalcon_Session_Adapter, status);
PHP_METHOD(Phalcon_Session_Adapter, __get);
PHP_METHOD(Phalcon_Session_Adapter, __set);
PHP_METHOD(Phalcon_Session_Adapter, __isset);
PHP_METHOD(Phalcon_Session_Adapter, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_method_entry) {
	PHP_ME(Phalcon_Session_Adapter, __construct, arginfo_phalcon_session_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, setOptions, arginfo_phalcon_session_adapter_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, get, arginfo_phalcon_session_adapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, set, arginfo_phalcon_session_adapter_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, has, arginfo_phalcon_session_adapter_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, remove, arginfo_phalcon_session_adapter_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, setId, arginfo_phalcon_session_adapter_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, isStarted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __get, arginfo_phalcon_session_adapter___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __set, arginfo_phalcon_session_adapter___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __isset, arginfo_phalcon_session_adapter___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __unset, arginfo_phalcon_session_adapter___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

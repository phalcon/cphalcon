
extern zend_class_entry *phalcon_session_adapter_noop_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Noop);

PHP_METHOD(Phalcon_Session_Adapter_Noop, close);
PHP_METHOD(Phalcon_Session_Adapter_Noop, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Noop, gc);
PHP_METHOD(Phalcon_Session_Adapter_Noop, open);
PHP_METHOD(Phalcon_Session_Adapter_Noop, read);
PHP_METHOD(Phalcon_Session_Adapter_Noop, updateTimestamp);
PHP_METHOD(Phalcon_Session_Adapter_Noop, validateId);
PHP_METHOD(Phalcon_Session_Adapter_Noop, write);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_destroy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_session_adapter_noop_gc, 0, 1, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, max_lifetime, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_open, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_updatetimestamp, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_validateid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_write, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_noop_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Noop, close, arginfo_phalcon_session_adapter_noop_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, destroy, arginfo_phalcon_session_adapter_noop_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, gc, arginfo_phalcon_session_adapter_noop_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, open, arginfo_phalcon_session_adapter_noop_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, read, arginfo_phalcon_session_adapter_noop_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, updateTimestamp, arginfo_phalcon_session_adapter_noop_updatetimestamp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, validateId, arginfo_phalcon_session_adapter_noop_validateid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, write, arginfo_phalcon_session_adapter_noop_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

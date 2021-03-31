
extern zend_class_entry *phalcon_domain_payload_payload_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_Payload);

PHP_METHOD(Phalcon_Domain_Payload_Payload, getExtras);
PHP_METHOD(Phalcon_Domain_Payload_Payload, getInput);
PHP_METHOD(Phalcon_Domain_Payload_Payload, getMessages);
PHP_METHOD(Phalcon_Domain_Payload_Payload, getStatus);
PHP_METHOD(Phalcon_Domain_Payload_Payload, getOutput);
PHP_METHOD(Phalcon_Domain_Payload_Payload, getException);
PHP_METHOD(Phalcon_Domain_Payload_Payload, setException);
PHP_METHOD(Phalcon_Domain_Payload_Payload, setExtras);
PHP_METHOD(Phalcon_Domain_Payload_Payload, setInput);
PHP_METHOD(Phalcon_Domain_Payload_Payload, setMessages);
PHP_METHOD(Phalcon_Domain_Payload_Payload, setOutput);
PHP_METHOD(Phalcon_Domain_Payload_Payload, setStatus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_payload_getextras, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_payload_getinput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_payload_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_payload_getstatus, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_payload_getoutput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_getexception, 0, 0, Throwable, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_setexception, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_setextras, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, extras)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_setinput, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_setmessages, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_setoutput, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payload_setstatus, 0, 1, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_payload_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Domain_Payload_Payload, getExtras, arginfo_phalcon_domain_payload_payload_getextras, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Domain_Payload_Payload, getExtras, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Domain_Payload_Payload, getInput, arginfo_phalcon_domain_payload_payload_getinput, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Domain_Payload_Payload, getInput, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Domain_Payload_Payload, getMessages, arginfo_phalcon_domain_payload_payload_getmessages, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Domain_Payload_Payload, getMessages, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Domain_Payload_Payload, getStatus, arginfo_phalcon_domain_payload_payload_getstatus, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Domain_Payload_Payload, getStatus, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Domain_Payload_Payload, getOutput, arginfo_phalcon_domain_payload_payload_getoutput, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Domain_Payload_Payload, getOutput, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Domain_Payload_Payload, getException, arginfo_phalcon_domain_payload_payload_getexception, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Domain_Payload_Payload, setException, arginfo_phalcon_domain_payload_payload_setexception, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Domain_Payload_Payload, setExtras, arginfo_phalcon_domain_payload_payload_setextras, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Domain_Payload_Payload, setInput, arginfo_phalcon_domain_payload_payload_setinput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Domain_Payload_Payload, setMessages, arginfo_phalcon_domain_payload_payload_setmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Domain_Payload_Payload, setOutput, arginfo_phalcon_domain_payload_payload_setoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Domain_Payload_Payload, setStatus, arginfo_phalcon_domain_payload_payload_setstatus, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

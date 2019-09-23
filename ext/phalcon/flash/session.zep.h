
extern zend_class_entry *phalcon_flash_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_Session);

PHP_METHOD(Phalcon_Flash_Session, clear);
PHP_METHOD(Phalcon_Flash_Session, getMessages);
PHP_METHOD(Phalcon_Flash_Session, has);
PHP_METHOD(Phalcon_Flash_Session, message);
PHP_METHOD(Phalcon_Flash_Session, output);
PHP_METHOD(Phalcon_Flash_Session, getSessionMessages);
PHP_METHOD(Phalcon_Flash_Session, setSessionMessages);
PHP_METHOD(Phalcon_Flash_Session, getSessionService);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_clear, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_clear, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_flash_session_clear NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, type)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remove)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_has, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_has, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_message, 0, 2, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_message, 0, 2, IS_STRING, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_output, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_output, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_output, 0, 0, 0)
#define arginfo_phalcon_flash_session_output NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remove)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_getsessionmessages, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_getsessionmessages, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remove)
#endif
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_setsessionmessages, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_setsessionmessages, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_session_getsessionservice, 0, 0, Phalcon\\Session\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_session_getsessionservice, 0, 0, IS_OBJECT, "Phalcon\\Session\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_session_method_entry) {
	PHP_ME(Phalcon_Flash_Session, clear, arginfo_phalcon_flash_session_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, getMessages, arginfo_phalcon_flash_session_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, has, arginfo_phalcon_flash_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, message, arginfo_phalcon_flash_session_message, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, output, arginfo_phalcon_flash_session_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, getSessionMessages, arginfo_phalcon_flash_session_getsessionmessages, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Flash_Session, setSessionMessages, arginfo_phalcon_flash_session_setsessionmessages, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Flash_Session, getSessionService, arginfo_phalcon_flash_session_getsessionservice, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

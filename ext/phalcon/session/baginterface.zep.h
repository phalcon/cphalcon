
extern zend_class_entry *phalcon_session_baginterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_BagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface_init, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_baginterface_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_baginterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __get, arginfo_phalcon_session_baginterface___get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __isset, arginfo_phalcon_session_baginterface___isset)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __set, arginfo_phalcon_session_baginterface___set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __unset, arginfo_phalcon_session_baginterface___unset)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, init, arginfo_phalcon_session_baginterface_init)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, get, arginfo_phalcon_session_baginterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, set, arginfo_phalcon_session_baginterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, has, arginfo_phalcon_session_baginterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, remove, arginfo_phalcon_session_baginterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, clear, arginfo_phalcon_session_baginterface_clear)
	PHP_FE_END
};

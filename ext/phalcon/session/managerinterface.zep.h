
extern zend_class_entry *phalcon_session_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_managerinterface___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_exists, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_destroy, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_managerinterface_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_getid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_managerinterface_getadapter, 0, 0, SessionHandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_managerinterface_setadapter, 0, 1, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_OBJ_INFO(0, adapter, SessionHandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_managerinterface_setid, 0, 1, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_managerinterface_setname, 0, 1, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_setoptions, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_status, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_managerinterface_start, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_managerinterface_regenerateid, 0, 0, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, deleteOldSession)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, __get, arginfo_phalcon_session_managerinterface___get)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, __isset, arginfo_phalcon_session_managerinterface___isset)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, __set, arginfo_phalcon_session_managerinterface___set)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, __unset, arginfo_phalcon_session_managerinterface___unset)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, exists, arginfo_phalcon_session_managerinterface_exists)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, destroy, arginfo_phalcon_session_managerinterface_destroy)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, get, arginfo_phalcon_session_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, getId, arginfo_phalcon_session_managerinterface_getid)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, getAdapter, arginfo_phalcon_session_managerinterface_getadapter)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, getName, arginfo_phalcon_session_managerinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, getOptions, arginfo_phalcon_session_managerinterface_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, has, arginfo_phalcon_session_managerinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, remove, arginfo_phalcon_session_managerinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, set, arginfo_phalcon_session_managerinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, setAdapter, arginfo_phalcon_session_managerinterface_setadapter)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, setId, arginfo_phalcon_session_managerinterface_setid)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, setName, arginfo_phalcon_session_managerinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, setOptions, arginfo_phalcon_session_managerinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, status, arginfo_phalcon_session_managerinterface_status)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, start, arginfo_phalcon_session_managerinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Session_ManagerInterface, regenerateId, arginfo_phalcon_session_managerinterface_regenerateid)
	PHP_FE_END
};

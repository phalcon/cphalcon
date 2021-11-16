
extern zend_class_entry *phalcon_session_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Manager);

PHP_METHOD(Phalcon_Session_Manager, __construct);
PHP_METHOD(Phalcon_Session_Manager, __get);
PHP_METHOD(Phalcon_Session_Manager, __isset);
PHP_METHOD(Phalcon_Session_Manager, __set);
PHP_METHOD(Phalcon_Session_Manager, __unset);
PHP_METHOD(Phalcon_Session_Manager, destroy);
PHP_METHOD(Phalcon_Session_Manager, exists);
PHP_METHOD(Phalcon_Session_Manager, get);
PHP_METHOD(Phalcon_Session_Manager, getAdapter);
PHP_METHOD(Phalcon_Session_Manager, getId);
PHP_METHOD(Phalcon_Session_Manager, getName);
PHP_METHOD(Phalcon_Session_Manager, has);
PHP_METHOD(Phalcon_Session_Manager, getOptions);
PHP_METHOD(Phalcon_Session_Manager, regenerateId);
PHP_METHOD(Phalcon_Session_Manager, remove);
PHP_METHOD(Phalcon_Session_Manager, set);
PHP_METHOD(Phalcon_Session_Manager, setAdapter);
PHP_METHOD(Phalcon_Session_Manager, setId);
PHP_METHOD(Phalcon_Session_Manager, setName);
PHP_METHOD(Phalcon_Session_Manager, setOptions);
PHP_METHOD(Phalcon_Session_Manager, start);
PHP_METHOD(Phalcon_Session_Manager, status);
PHP_METHOD(Phalcon_Session_Manager, getUniqueKey);
PHP_METHOD(Phalcon_Session_Manager, getArrVal);
zend_object *zephir_init_properties_Phalcon_Session_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_manager___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_manager___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_destroy, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_exists, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_manager_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_manager_getadapter, 0, 0, SessionHandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_getid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_manager_regenerateid, 0, 0, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, deleteOldSession)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_manager_setadapter, 0, 1, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_OBJ_INFO(0, adapter, SessionHandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_manager_setid, 0, 1, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_manager_setname, 0, 1, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_setoptions, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_start, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_status, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_manager_getuniquekey, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_manager_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_manager_zephir_init_properties_phalcon_session_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_manager_method_entry) {
	PHP_ME(Phalcon_Session_Manager, __construct, arginfo_phalcon_session_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Manager, __get, arginfo_phalcon_session_manager___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, __isset, arginfo_phalcon_session_manager___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, __set, arginfo_phalcon_session_manager___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, __unset, arginfo_phalcon_session_manager___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, destroy, arginfo_phalcon_session_manager_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, exists, arginfo_phalcon_session_manager_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, get, arginfo_phalcon_session_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, getAdapter, arginfo_phalcon_session_manager_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, getId, arginfo_phalcon_session_manager_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, getName, arginfo_phalcon_session_manager_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, has, arginfo_phalcon_session_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, getOptions, arginfo_phalcon_session_manager_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, regenerateId, arginfo_phalcon_session_manager_regenerateid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, remove, arginfo_phalcon_session_manager_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, set, arginfo_phalcon_session_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, setAdapter, arginfo_phalcon_session_manager_setadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, setId, arginfo_phalcon_session_manager_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, setName, arginfo_phalcon_session_manager_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, setOptions, arginfo_phalcon_session_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, start, arginfo_phalcon_session_manager_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, status, arginfo_phalcon_session_manager_status, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Manager, getUniqueKey, arginfo_phalcon_session_manager_getuniquekey, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Session_Manager, getArrVal, arginfo_phalcon_session_manager_getarrval, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

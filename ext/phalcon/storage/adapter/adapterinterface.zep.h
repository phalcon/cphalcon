
extern zend_class_entry *phalcon_storage_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_clear, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_clear, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_decrement, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_getkeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_getkeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_getprefix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_getprefix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_increment, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_set, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_adapterinterface_set, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, clear, arginfo_phalcon_storage_adapter_adapterinterface_clear)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, decrement, arginfo_phalcon_storage_adapter_adapterinterface_decrement)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, delete, arginfo_phalcon_storage_adapter_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, get, arginfo_phalcon_storage_adapter_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, getAdapter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, getKeys, arginfo_phalcon_storage_adapter_adapterinterface_getkeys)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, getPrefix, arginfo_phalcon_storage_adapter_adapterinterface_getprefix)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, has, arginfo_phalcon_storage_adapter_adapterinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, increment, arginfo_phalcon_storage_adapter_adapterinterface_increment)
	PHP_ABSTRACT_ME(Phalcon_Storage_Adapter_AdapterInterface, set, arginfo_phalcon_storage_adapter_adapterinterface_set)
	PHP_FE_END
};

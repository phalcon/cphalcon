
extern zend_class_entry *phalcon_mvc_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getreservedattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getreservedattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getsource, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getsource, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setconnectionservice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, connectionService)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setdirtystate, 0, 1, Phalcon\\Mvc\\CollectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setdirtystate, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\CollectionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, dirtyState)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getdirtystate, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getdirtystate, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collectioninterface_cloneresult, 0, 2, Phalcon\\Mvc\\CollectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_cloneresult, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\CollectionInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, document, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireevent, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireevent, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireeventcancel, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireeventcancel, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_validationhasfailed, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_validationhasfailed, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_save, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findbyid, 0, 1, Phalcon\\Mvc\\CollectionInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findbyid, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\CollectionInterface", 1)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findfirst, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findfirst, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_find, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_find, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_count, 0, 0, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_delete, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collectioninterface_delete, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setId, arginfo_phalcon_mvc_collectioninterface_setid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getReservedAttributes, arginfo_phalcon_mvc_collectioninterface_getreservedattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getSource, arginfo_phalcon_mvc_collectioninterface_getsource)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setConnectionService, arginfo_phalcon_mvc_collectioninterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setDirtyState, arginfo_phalcon_mvc_collectioninterface_setdirtystate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getDirtyState, arginfo_phalcon_mvc_collectioninterface_getdirtystate)
	ZEND_FENTRY(cloneResult, NULL, arginfo_phalcon_mvc_collectioninterface_cloneresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEvent, arginfo_phalcon_mvc_collectioninterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEventCancel, arginfo_phalcon_mvc_collectioninterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, validationHasFailed, arginfo_phalcon_mvc_collectioninterface_validationhasfailed)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getMessages, arginfo_phalcon_mvc_collectioninterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, appendMessage, arginfo_phalcon_mvc_collectioninterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, save, arginfo_phalcon_mvc_collectioninterface_save)
	ZEND_FENTRY(findById, NULL, arginfo_phalcon_mvc_collectioninterface_findbyid, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_collectioninterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_collectioninterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_collectioninterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, delete, arginfo_phalcon_mvc_collectioninterface_delete)
	PHP_FE_END
};

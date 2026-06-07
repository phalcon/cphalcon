
extern zend_class_entry *phalcon_events_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Manager);

PHP_METHOD(Phalcon_Events_Manager, addSubscriber);
PHP_METHOD(Phalcon_Events_Manager, attach);
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled);
PHP_METHOD(Phalcon_Events_Manager, clearSubscribers);
PHP_METHOD(Phalcon_Events_Manager, collectResponses);
PHP_METHOD(Phalcon_Events_Manager, detach);
PHP_METHOD(Phalcon_Events_Manager, detachAll);
PHP_METHOD(Phalcon_Events_Manager, dispatch);
PHP_METHOD(Phalcon_Events_Manager, enablePriorities);
PHP_METHOD(Phalcon_Events_Manager, fire);
PHP_METHOD(Phalcon_Events_Manager, fireAll);
PHP_METHOD(Phalcon_Events_Manager, fireQueue);
PHP_METHOD(Phalcon_Events_Manager, halt);
PHP_METHOD(Phalcon_Events_Manager, getListeners);
PHP_METHOD(Phalcon_Events_Manager, getMethodExistsCacheLimit);
PHP_METHOD(Phalcon_Events_Manager, getResponses);
PHP_METHOD(Phalcon_Events_Manager, getSubscribers);
PHP_METHOD(Phalcon_Events_Manager, hasListeners);
PHP_METHOD(Phalcon_Events_Manager, isCollecting);
PHP_METHOD(Phalcon_Events_Manager, isHalted);
PHP_METHOD(Phalcon_Events_Manager, isStopOnFalse);
PHP_METHOD(Phalcon_Events_Manager, isStrict);
PHP_METHOD(Phalcon_Events_Manager, isValidHandler);
PHP_METHOD(Phalcon_Events_Manager, removeSubscriber);
PHP_METHOD(Phalcon_Events_Manager, resume);
PHP_METHOD(Phalcon_Events_Manager, setMethodExistsCacheLimit);
PHP_METHOD(Phalcon_Events_Manager, setStopOnFalse);
PHP_METHOD(Phalcon_Events_Manager, setStrict);
PHP_METHOD(Phalcon_Events_Manager, afterFire);
PHP_METHOD(Phalcon_Events_Manager, beforeFire);
PHP_METHOD(Phalcon_Events_Manager, runObjectQueue);
PHP_METHOD(Phalcon_Events_Manager, runQueue);
PHP_METHOD(Phalcon_Events_Manager, insertHandlerEntry);
PHP_METHOD(Phalcon_Events_Manager, processSubscriberEntry);
zend_object *zephir_init_properties_Phalcon_Events_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_addsubscriber, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, subscriber, Phalcon\\Contracts\\Events\\Subscriber, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_attach, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, priority, IS_LONG, 0, "100")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_areprioritiesenabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_clearsubscribers, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_collectresponses, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, collect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_detach, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_detachall, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_dispatch, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_enablepriorities, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, enablePriorities, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_fire, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancelable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_fireall, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancelable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_firequeue, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, queue, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\EventInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_halt, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_getlisteners, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_getmethodexistscachelimit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_getresponses, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_getsubscribers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_haslisteners, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_iscollecting, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_ishalted, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_isstoponfalse, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_isstrict, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_isvalidhandler, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_removesubscriber, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, subscriber, Phalcon\\Contracts\\Events\\Subscriber, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_resume, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_setmethodexistscachelimit, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, methodExistsCacheLimit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_setstoponfalse, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, flag, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_setstrict, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, strict, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_afterfire, 0, 0, 3)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancelable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_beforefire, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancelable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_runobjectqueue, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, queue, 0)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_runqueue, 0, 0, 7)
	ZEND_ARG_ARRAY_INFO(0, queue, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\EventInterface, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, cancelable, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, collect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_inserthandlerentry, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, eventType, IS_STRING, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_events_manager_processsubscriberentry, 0, 4, IS_VOID, 0)

	ZEND_ARG_INFO(0, subscriber)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_TYPE_INFO(0, detaching, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_zephir_init_properties_phalcon_events_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_manager_method_entry) {
	PHP_ME(Phalcon_Events_Manager, addSubscriber, arginfo_phalcon_events_manager_addsubscriber, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, attach, arginfo_phalcon_events_manager_attach, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, arePrioritiesEnabled, arginfo_phalcon_events_manager_areprioritiesenabled, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, clearSubscribers, arginfo_phalcon_events_manager_clearsubscribers, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, collectResponses, arginfo_phalcon_events_manager_collectresponses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, detach, arginfo_phalcon_events_manager_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, detachAll, arginfo_phalcon_events_manager_detachall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, dispatch, arginfo_phalcon_events_manager_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, enablePriorities, arginfo_phalcon_events_manager_enablepriorities, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, fire, arginfo_phalcon_events_manager_fire, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, fireAll, arginfo_phalcon_events_manager_fireall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, fireQueue, arginfo_phalcon_events_manager_firequeue, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, halt, arginfo_phalcon_events_manager_halt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, getListeners, arginfo_phalcon_events_manager_getlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, getMethodExistsCacheLimit, arginfo_phalcon_events_manager_getmethodexistscachelimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, getResponses, arginfo_phalcon_events_manager_getresponses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, getSubscribers, arginfo_phalcon_events_manager_getsubscribers, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, hasListeners, arginfo_phalcon_events_manager_haslisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, isCollecting, arginfo_phalcon_events_manager_iscollecting, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, isHalted, arginfo_phalcon_events_manager_ishalted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, isStopOnFalse, arginfo_phalcon_events_manager_isstoponfalse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, isStrict, arginfo_phalcon_events_manager_isstrict, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, isValidHandler, arginfo_phalcon_events_manager_isvalidhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, removeSubscriber, arginfo_phalcon_events_manager_removesubscriber, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, resume, arginfo_phalcon_events_manager_resume, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, setMethodExistsCacheLimit, arginfo_phalcon_events_manager_setmethodexistscachelimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, setStopOnFalse, arginfo_phalcon_events_manager_setstoponfalse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, setStrict, arginfo_phalcon_events_manager_setstrict, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, afterFire, arginfo_phalcon_events_manager_afterfire, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Events_Manager, beforeFire, arginfo_phalcon_events_manager_beforefire, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Events_Manager, runObjectQueue, arginfo_phalcon_events_manager_runobjectqueue, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Events_Manager, runQueue, arginfo_phalcon_events_manager_runqueue, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Events_Manager, insertHandlerEntry, arginfo_phalcon_events_manager_inserthandlerentry, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Events_Manager, processSubscriberEntry, arginfo_phalcon_events_manager_processsubscriberentry, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

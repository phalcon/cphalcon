
extern zend_class_entry *phalcon_di_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di);

PHP_METHOD(Phalcon_Di, __construct);
PHP_METHOD(Phalcon_Di, __call);
PHP_METHOD(Phalcon_Di, attempt);
PHP_METHOD(Phalcon_Di, get);
PHP_METHOD(Phalcon_Di, getDefault);
PHP_METHOD(Phalcon_Di, getInternalEventsManager);
PHP_METHOD(Phalcon_Di, getRaw);
PHP_METHOD(Phalcon_Di, getService);
PHP_METHOD(Phalcon_Di, getServices);
PHP_METHOD(Phalcon_Di, getShared);
PHP_METHOD(Phalcon_Di, loadFromConfig);
PHP_METHOD(Phalcon_Di, loadFromPhp);
PHP_METHOD(Phalcon_Di, loadFromYaml);
PHP_METHOD(Phalcon_Di, has);
PHP_METHOD(Phalcon_Di, offsetGet);
PHP_METHOD(Phalcon_Di, offsetExists);
PHP_METHOD(Phalcon_Di, offsetSet);
PHP_METHOD(Phalcon_Di, offsetUnset);
PHP_METHOD(Phalcon_Di, register);
PHP_METHOD(Phalcon_Di, remove);
PHP_METHOD(Phalcon_Di, reset);
PHP_METHOD(Phalcon_Di, set);
PHP_METHOD(Phalcon_Di, setDefault);
PHP_METHOD(Phalcon_Di, setInternalEventsManager);
PHP_METHOD(Phalcon_Di, setService);
PHP_METHOD(Phalcon_Di, setShared);
zend_object *zephir_init_properties_Phalcon_Di(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_getdefault, 0, 0, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_getinternaleventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getraw, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_getservice, 0, 1, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getshared, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_loadfromconfig, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config\\ConfigInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_loadfromphp, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_loadfromyaml, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, callbacks, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_register, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, provider, Phalcon\\Di\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_set, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_setdefault, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setinternaleventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_setservice, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, rawDefinition, Phalcon\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_setshared, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_zephir_init_properties_phalcon_di, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Di, __construct, arginfo_phalcon_di___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Di, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(Phalcon_Di, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, get, arginfo_phalcon_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getDefault, arginfo_phalcon_di_getdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, getInternalEventsManager, arginfo_phalcon_di_getinternaleventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getRaw, arginfo_phalcon_di_getraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getService, arginfo_phalcon_di_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getServices, arginfo_phalcon_di_getservices, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getShared, arginfo_phalcon_di_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, loadFromConfig, arginfo_phalcon_di_loadfromconfig, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Di, loadFromPhp, arginfo_phalcon_di_loadfromphp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, loadFromYaml, arginfo_phalcon_di_loadfromyaml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetGet, arginfo_phalcon_di_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetExists, arginfo_phalcon_di_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetSet, arginfo_phalcon_di_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetUnset, arginfo_phalcon_di_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, register, arginfo_phalcon_di_register, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, reset, arginfo_phalcon_di_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, set, arginfo_phalcon_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setDefault, arginfo_phalcon_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, setInternalEventsManager, arginfo_phalcon_di_setinternaleventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setService, arginfo_phalcon_di_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setShared, arginfo_phalcon_di_setshared, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

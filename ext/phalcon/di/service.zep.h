
extern zend_class_entry *phalcon_di_service_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Service);

PHP_METHOD(Phalcon_Di_Service, __construct);
PHP_METHOD(Phalcon_Di_Service, getDefinition);
PHP_METHOD(Phalcon_Di_Service, getParameter);
PHP_METHOD(Phalcon_Di_Service, isResolved);
PHP_METHOD(Phalcon_Di_Service, isShared);
PHP_METHOD(Phalcon_Di_Service, resolve);
PHP_METHOD(Phalcon_Di_Service, setDefinition);
PHP_METHOD(Phalcon_Di_Service, setParameter);
PHP_METHOD(Phalcon_Di_Service, setShared);
PHP_METHOD(Phalcon_Di_Service, setSharedInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, shared)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_getdefinition, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_getparameter, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, position)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_isresolved, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_isresolved, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_isshared, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_isshared, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setdefinition, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setdefinition, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setdefinition, 0, 0, 1)
#define arginfo_phalcon_di_service_setdefinition NULL
#endif

	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_service_setparameter, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setparameter, 0, 2, IS_OBJECT, "Phalcon\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, position)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameter, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setshared, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setshared, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setshared, 0, 0, 1)
#define arginfo_phalcon_di_service_setshared NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, shared)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setsharedinstance, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_setsharedinstance, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setsharedinstance, 0, 0, 1)
#define arginfo_phalcon_di_service_setsharedinstance NULL
#endif

	ZEND_ARG_INFO(0, sharedInstance)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_method_entry) {
	PHP_ME(Phalcon_Di_Service, __construct, arginfo_phalcon_di_service___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Di_Service, getDefinition, arginfo_phalcon_di_service_getdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, getParameter, arginfo_phalcon_di_service_getparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, isResolved, arginfo_phalcon_di_service_isresolved, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, isShared, arginfo_phalcon_di_service_isshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, resolve, arginfo_phalcon_di_service_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setDefinition, arginfo_phalcon_di_service_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setParameter, arginfo_phalcon_di_service_setparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setShared, arginfo_phalcon_di_service_setshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setSharedInstance, arginfo_phalcon_di_service_setsharedinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

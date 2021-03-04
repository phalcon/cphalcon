
extern zend_class_entry *phalcon_di_diinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_DiInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_diinterface_attempt, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_diinterface_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_diinterface_getdefault, 0, 0, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_diinterface_getraw, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_diinterface_getservice, 0, 1, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_diinterface_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_diinterface_getshared, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_diinterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_diinterface_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_diinterface_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_diinterface_set, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_diinterface_setdefault, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_diinterface_setservice, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, rawDefinition, Phalcon\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_diinterface_setshared, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_diinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, attempt, arginfo_phalcon_di_diinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, get, arginfo_phalcon_di_diinterface_get)
	ZEND_FENTRY(getDefault, NULL, arginfo_phalcon_di_diinterface_getdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, getRaw, arginfo_phalcon_di_diinterface_getraw)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, getService, arginfo_phalcon_di_diinterface_getservice)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, getServices, arginfo_phalcon_di_diinterface_getservices)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, getShared, arginfo_phalcon_di_diinterface_getshared)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, has, arginfo_phalcon_di_diinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, remove, arginfo_phalcon_di_diinterface_remove)
	ZEND_FENTRY(reset, NULL, arginfo_phalcon_di_diinterface_reset, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, set, arginfo_phalcon_di_diinterface_set)
	ZEND_FENTRY(setDefault, NULL, arginfo_phalcon_di_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, setService, arginfo_phalcon_di_diinterface_setservice)
	PHP_ABSTRACT_ME(Phalcon_Di_DiInterface, setShared, arginfo_phalcon_di_diinterface_setshared)
	PHP_FE_END
};

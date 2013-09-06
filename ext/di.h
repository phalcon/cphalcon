
extern zend_class_entry *phalcon_di_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di);

PHP_METHOD(Phalcon_Di, __construct);
PHP_METHOD(Phalcon_Di, set);
PHP_METHOD(Phalcon_Di, setShared);
PHP_METHOD(Phalcon_Di, remove);
PHP_METHOD(Phalcon_Di, attempt);
PHP_METHOD(Phalcon_Di, setRaw);
PHP_METHOD(Phalcon_Di, getRaw);
PHP_METHOD(Phalcon_Di, getService);
PHP_METHOD(Phalcon_Di, get);
PHP_METHOD(Phalcon_Di, getShared);
PHP_METHOD(Phalcon_Di, has);
PHP_METHOD(Phalcon_Di, wasFreshInstance);
PHP_METHOD(Phalcon_Di, getServices);
PHP_METHOD(Phalcon_Di, offsetExists);
PHP_METHOD(Phalcon_Di, offsetSet);
PHP_METHOD(Phalcon_Di, offsetGet);
PHP_METHOD(Phalcon_Di, offsetUnset);
PHP_METHOD(Phalcon_Di, __call);
PHP_METHOD(Phalcon_Di, setDefault);
PHP_METHOD(Phalcon_Di, getDefault);
PHP_METHOD(Phalcon_Di, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_set, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setShared, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_remove, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setRaw, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, rawDefinition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getRaw, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getService, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getShared, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_has, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetExists, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetSet, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetGet, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetUnset, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setDefault, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_method_entry) {
	PHP_ME(Phalcon_Di, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, set, arginfo_phalcon_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setShared, arginfo_phalcon_di_setShared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setRaw, arginfo_phalcon_di_setRaw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getRaw, arginfo_phalcon_di_getRaw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getService, arginfo_phalcon_di_getService, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, get, arginfo_phalcon_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getShared, arginfo_phalcon_di_getShared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, wasFreshInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetExists, arginfo_phalcon_di_offsetExists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetSet, arginfo_phalcon_di_offsetSet, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetGet, arginfo_phalcon_di_offsetGet, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetUnset, arginfo_phalcon_di_offsetUnset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setDefault, arginfo_phalcon_di_setDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_di_service_ce;

ZEPHIR_INIT_CLASS(Phalcon_DI_Service);

PHP_METHOD(Phalcon_DI_Service, __construct);
PHP_METHOD(Phalcon_DI_Service, getName);
PHP_METHOD(Phalcon_DI_Service, setShared);
PHP_METHOD(Phalcon_DI_Service, isShared);
PHP_METHOD(Phalcon_DI_Service, setSharedInstance);
PHP_METHOD(Phalcon_DI_Service, setDefinition);
PHP_METHOD(Phalcon_DI_Service, getDefinition);
PHP_METHOD(Phalcon_DI_Service, resolve);
PHP_METHOD(Phalcon_DI_Service, setParameter);
PHP_METHOD(Phalcon_DI_Service, getParameter);
PHP_METHOD(Phalcon_DI_Service, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setShared, 0, 0, 0)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setSharedInstance, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setDefinition, 0, 0, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setParameter, 0, 0, 0)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_INFO(0, parameter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_getParameter, 0, 0, 0)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___set_state, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_method_entry) {
	PHP_ME(Phalcon_DI_Service, __construct, arginfo_phalcon_di_service___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setShared, arginfo_phalcon_di_service_setShared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, isShared, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setSharedInstance, arginfo_phalcon_di_service_setSharedInstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setDefinition, arginfo_phalcon_di_service_setDefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, getDefinition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, resolve, arginfo_phalcon_di_service_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setParameter, arginfo_phalcon_di_service_setParameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, getParameter, arginfo_phalcon_di_service_getParameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, __set_state, arginfo_phalcon_di_service___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

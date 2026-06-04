
extern zend_class_entry *phalcon_auth_managerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_ManagerFactory);

PHP_METHOD(Phalcon_Auth_ManagerFactory, __construct);
PHP_METHOD(Phalcon_Auth_ManagerFactory, load);
PHP_METHOD(Phalcon_Auth_ManagerFactory, buildAdapter);
PHP_METHOD(Phalcon_Auth_ManagerFactory, buildGuard);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_managerfactory___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Encryption\\Security, 0)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_OBJ_TYPE_MASK(0, adapterLocator, Phalcon\\Auth\\Adapter\\AdapterLocator, MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, guardLocator, Phalcon\\Auth\\Guard\\GuardLocator, MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, accessLocator, Phalcon\\Auth\\Access\\AccessLocator, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_load, 0, 1, Phalcon\\Auth\\Manager, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_buildadapter, 0, 2, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, locator, Phalcon\\Auth\\Adapter\\AdapterLocator, 0)
	ZEND_ARG_ARRAY_INFO(0, cfg, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_buildguard, 0, 4, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
	ZEND_ARG_OBJ_INFO(0, locator, Phalcon\\Auth\\Guard\\GuardLocator, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_managerfactory_method_entry) {
	PHP_ME(Phalcon_Auth_ManagerFactory, __construct, arginfo_phalcon_auth_managerfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_ManagerFactory, load, arginfo_phalcon_auth_managerfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, buildAdapter, arginfo_phalcon_auth_managerfactory_buildadapter, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_ManagerFactory, buildGuard, arginfo_phalcon_auth_managerfactory_buildguard, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

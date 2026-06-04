
extern zend_class_entry *phalcon_auth_adapter_abstractarrayadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractArrayAdapter);

PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, hasIdentifyingField);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, hydrate);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, loadUsers);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, matchesRow);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractarrayadapter_retrievebycredentials, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractarrayadapter_retrievebyid, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractarrayadapter_hasidentifyingfield, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractarrayadapter_hydrate, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 0)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractarrayadapter_loadusers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractarrayadapter_matchesrow, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_abstractarrayadapter_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_AbstractArrayAdapter, retrieveByCredentials, arginfo_phalcon_auth_adapter_abstractarrayadapter_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractArrayAdapter, retrieveById, arginfo_phalcon_auth_adapter_abstractarrayadapter_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractArrayAdapter, hasIdentifyingField, arginfo_phalcon_auth_adapter_abstractarrayadapter_hasidentifyingfield, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_AbstractArrayAdapter, hydrate, arginfo_phalcon_auth_adapter_abstractarrayadapter_hydrate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_AbstractArrayAdapter, loadUsers, arginfo_phalcon_auth_adapter_abstractarrayadapter_loadusers, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_AbstractArrayAdapter, matchesRow, arginfo_phalcon_auth_adapter_abstractarrayadapter_matchesrow, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

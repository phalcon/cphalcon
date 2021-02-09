
extern zend_class_entry *phalcon_mvc_model_transaction_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager);

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransaction);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Transaction_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_collecttransactions, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_collecttransactions, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_mvc_model_transaction_manager_collecttransactions NULL
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_commit, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_get, 0, 0, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_get, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\TransactionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoBegin, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoBegin)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getdbservice, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getdbservice, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getdi, 0, 0, IS_OBJECT, "Phalcon\\Di\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, 0, 0, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\TransactionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoBegin, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoBegin)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getrollbackpendent, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getrollbackpendent, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_has, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_has, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifycommit, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifycommit, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifycommit, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_manager_notifycommit NULL
#endif

	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_manager_notifyrollback NULL
#endif

	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollback, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollback, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollback, 0, 0, 0)
#define arginfo_phalcon_mvc_model_transaction_manager_rollback NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, collect, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, collect)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollbackpendent, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollbackpendent, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_mvc_model_transaction_manager_rollbackpendent NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdbservice, 0, 1, Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdbservice, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, service)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdi, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdi, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdi, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_manager_setdi NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, 0, 1, Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rollbackPendent, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, rollbackPendent)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_collecttransaction, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_collecttransaction, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_collecttransaction, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_manager_collecttransaction NULL
#endif

	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_zephir_init_properties_phalcon_mvc_model_transaction_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, __construct, arginfo_phalcon_mvc_model_transaction_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions, arginfo_phalcon_mvc_model_transaction_manager_collecttransactions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, commit, arginfo_phalcon_mvc_model_transaction_manager_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, get, arginfo_phalcon_mvc_model_transaction_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDbService, arginfo_phalcon_mvc_model_transaction_manager_getdbservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDI, arginfo_phalcon_mvc_model_transaction_manager_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction, arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent, arginfo_phalcon_mvc_model_transaction_manager_getrollbackpendent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, has, arginfo_phalcon_mvc_model_transaction_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit, arginfo_phalcon_mvc_model_transaction_manager_notifycommit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback, arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollback, arginfo_phalcon_mvc_model_transaction_manager_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent, arginfo_phalcon_mvc_model_transaction_manager_rollbackpendent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDbService, arginfo_phalcon_mvc_model_transaction_manager_setdbservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDI, arginfo_phalcon_mvc_model_transaction_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent, arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, collectTransaction, arginfo_phalcon_mvc_model_transaction_manager_collecttransaction, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

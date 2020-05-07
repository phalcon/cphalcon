
extern zend_class_entry *phalcon_mvc_model_transaction_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction);

PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, throwRollbackException);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Transaction(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoBegin, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoBegin)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, service)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_begin, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_begin, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_commit, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_commit, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_getconnection, 0, 0, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_getconnection, 0, 0, IS_OBJECT, "Phalcon\\Db\\Adapter\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_ismanaged, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_ismanaged, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_isvalid, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_isvalid, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_rollback, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_rollback, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rollbackMessage, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, rollbackMessage)
#endif
	ZEND_ARG_OBJ_INFO(0, rollbackRecord, Phalcon\\Mvc\\ModelInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_setisnewtransaction, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_setisnewtransaction, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setisnewtransaction, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_setisnewtransaction NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, isNew, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, isNew)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackonabort, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackonabort, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackonabort, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_setrollbackonabort NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rollbackOnAbort, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, rollbackOnAbort)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_setrollbackedrecord NULL
#endif

	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_settransactionmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_settransactionmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_settransactionmanager, 0, 0, 1)
#define arginfo_phalcon_mvc_model_transaction_settransactionmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_throwrollbackexception, 0, 1, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_throwrollbackexception, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\TransactionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, status, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, status)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Transaction, __construct, arginfo_phalcon_mvc_model_transaction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction, begin, arginfo_phalcon_mvc_model_transaction_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, commit, arginfo_phalcon_mvc_model_transaction_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, getConnection, arginfo_phalcon_mvc_model_transaction_getconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, getMessages, arginfo_phalcon_mvc_model_transaction_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, isManaged, arginfo_phalcon_mvc_model_transaction_ismanaged, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, isValid, arginfo_phalcon_mvc_model_transaction_isvalid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, rollback, arginfo_phalcon_mvc_model_transaction_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setIsNewTransaction, arginfo_phalcon_mvc_model_transaction_setisnewtransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort, arginfo_phalcon_mvc_model_transaction_setrollbackonabort, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackedRecord, arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setTransactionManager, arginfo_phalcon_mvc_model_transaction_settransactionmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, throwRollbackException, arginfo_phalcon_mvc_model_transaction_throwrollbackexception, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

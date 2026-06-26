
extern zend_class_entry *phalcon_db_exceptions_invaliddialectclass_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Exceptions_InvalidDialectClass);

PHP_METHOD(Phalcon_Db_Exceptions_InvalidDialectClass, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_exceptions_invaliddialectclass___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_exceptions_invaliddialectclass_method_entry) {
	PHP_ME(Phalcon_Db_Exceptions_InvalidDialectClass, __construct, arginfo_phalcon_db_exceptions_invaliddialectclass___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


extern zend_class_entry *phalcon_db_rawvalue_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_RawValue);

PHP_METHOD(Phalcon_Db_RawValue, getValue);
PHP_METHOD(Phalcon_Db_RawValue, __toString);
PHP_METHOD(Phalcon_Db_RawValue, __construct);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_rawvalue_getvalue, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_rawvalue___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_rawvalue_method_entry) {
	PHP_ME(Phalcon_Db_RawValue, getValue, arginfo_phalcon_db_rawvalue_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_RawValue, __toString, arginfo_phalcon_db_rawvalue___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_RawValue, __construct, arginfo_phalcon_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

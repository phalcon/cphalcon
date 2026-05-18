
extern zend_class_entry *phalcon_db_check_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Check);

PHP_METHOD(Phalcon_Db_Check, __construct);
PHP_METHOD(Phalcon_Db_Check, getExpression);
PHP_METHOD(Phalcon_Db_Check, getName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_check___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_check_getexpression, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_check_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_check_method_entry) {
	PHP_ME(Phalcon_Db_Check, __construct, arginfo_phalcon_db_check___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Check, getExpression, arginfo_phalcon_db_check_getexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Check, getName, arginfo_phalcon_db_check_getname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

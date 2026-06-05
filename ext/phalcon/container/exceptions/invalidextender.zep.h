
extern zend_class_entry *phalcon_container_exceptions_invalidextender_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Exceptions_InvalidExtender);

PHP_METHOD(Phalcon_Container_Exceptions_InvalidExtender, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_exceptions_invalidextender___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_exceptions_invalidextender_method_entry) {
	PHP_ME(Phalcon_Container_Exceptions_InvalidExtender, __construct, arginfo_phalcon_container_exceptions_invalidextender___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

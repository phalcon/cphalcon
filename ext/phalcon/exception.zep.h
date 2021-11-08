
extern zend_class_entry *phalcon_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Exception);

PHP_METHOD(Phalcon_Exception, containerServiceNotFound);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_exception_containerservicenotfound, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_exception_method_entry) {
	PHP_ME(Phalcon_Exception, containerServiceNotFound, arginfo_phalcon_exception_containerservicenotfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

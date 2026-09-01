
extern zend_class_entry *phalcon_di_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Exception);

PHP_METHOD(Phalcon_Di_Exception, serviceCannotBeResolved);
PHP_METHOD(Phalcon_Di_Exception, serviceNotFound);
PHP_METHOD(Phalcon_Di_Exception, unknownServiceInParameter);
PHP_METHOD(Phalcon_Di_Exception, undefinedMethod);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_exception_servicecannotberesolved, 0, 1, Phalcon\\Di\\Exception, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_exception_servicenotfound, 0, 1, Phalcon\\Di\\Exception, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_exception_unknownserviceinparameter, 0, 1, Phalcon\\Di\\Exception, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_exception_undefinedmethod, 0, 1, Phalcon\\Di\\Exception, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_exception_method_entry) {
	PHP_ME(Phalcon_Di_Exception, serviceCannotBeResolved, arginfo_phalcon_di_exception_servicecannotberesolved, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di_Exception, serviceNotFound, arginfo_phalcon_di_exception_servicenotfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di_Exception, unknownServiceInParameter, arginfo_phalcon_di_exception_unknownserviceinparameter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di_Exception, undefinedMethod, arginfo_phalcon_di_exception_undefinedmethod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

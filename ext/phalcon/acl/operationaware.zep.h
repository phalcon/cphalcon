
extern zend_class_entry *phalcon_acl_operationaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_OperationAware);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_operationaware_getoperationname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_operationaware_getoperationname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_operationaware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_OperationAware, getOperationName, arginfo_phalcon_acl_operationaware_getoperationname)
	PHP_FE_END
};

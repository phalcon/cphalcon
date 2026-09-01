
extern zend_class_entry *phalcon_acl_abstractelement_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_AbstractElement);

PHP_METHOD(Phalcon_Acl_AbstractElement, __toString);
PHP_METHOD(Phalcon_Acl_AbstractElement, getDescription);
PHP_METHOD(Phalcon_Acl_AbstractElement, getName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_abstractelement___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_abstractelement_getdescription, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_abstractelement_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_abstractelement_method_entry) {
	PHP_ME(Phalcon_Acl_AbstractElement, __toString, arginfo_phalcon_acl_abstractelement___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_AbstractElement, getDescription, arginfo_phalcon_acl_abstractelement_getdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_AbstractElement, getName, arginfo_phalcon_acl_abstractelement_getname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_acl_traits_itemtrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Traits_ItemTrait);

PHP_METHOD(Phalcon_Acl_Traits_ItemTrait, __toString);
PHP_METHOD(Phalcon_Acl_Traits_ItemTrait, getDescription);
PHP_METHOD(Phalcon_Acl_Traits_ItemTrait, getName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_traits_itemtrait___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_traits_itemtrait_getdescription, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_traits_itemtrait_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_traits_itemtrait_method_entry) {
	PHP_ME(Phalcon_Acl_Traits_ItemTrait, __toString, arginfo_phalcon_acl_traits_itemtrait___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Traits_ItemTrait, getDescription, arginfo_phalcon_acl_traits_itemtrait_getdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Traits_ItemTrait, getName, arginfo_phalcon_acl_traits_itemtrait_getname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

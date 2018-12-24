
extern zend_class_entry *phalcon_acl_subject_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Subject);

PHP_METHOD(Phalcon_Acl_Subject, getDescription);
PHP_METHOD(Phalcon_Acl_Subject, getName);
PHP_METHOD(Phalcon_Acl_Subject, __toString);
PHP_METHOD(Phalcon_Acl_Subject, __construct);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subject_getdescription, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subject_getdescription, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subject_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subject_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subject___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subject___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_subject___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, description, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, description)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_subject_method_entry) {
	PHP_ME(Phalcon_Acl_Subject, getDescription, arginfo_phalcon_acl_subject_getdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Subject, getName, arginfo_phalcon_acl_subject_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Subject, __toString, arginfo_phalcon_acl_subject___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Subject, __construct, arginfo_phalcon_acl_subject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

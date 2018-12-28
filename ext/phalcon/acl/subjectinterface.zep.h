
extern zend_class_entry *phalcon_acl_subjectinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_SubjectInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subjectinterface_getdescription, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subjectinterface_getdescription, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subjectinterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subjectinterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subjectinterface___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_subjectinterface___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_subjectinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_SubjectInterface, getDescription, arginfo_phalcon_acl_subjectinterface_getdescription)
	PHP_ABSTRACT_ME(Phalcon_Acl_SubjectInterface, getName, arginfo_phalcon_acl_subjectinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Acl_SubjectInterface, __toString, arginfo_phalcon_acl_subjectinterface___tostring)
	PHP_FE_END
};

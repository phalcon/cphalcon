
extern zend_class_entry *phalcon_acl_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_addinherit, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_addinherit, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operationName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operationName)
#endif
	ZEND_ARG_INFO(0, operationToInherit)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_addoperation, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_addoperation, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, operation)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_addsubject, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_addsubject, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, subjectObject)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addsubjectaccess, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_allow, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operationName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operationName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_deny, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operationName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operationName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_dropsubjectaccess, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getactiveaccess, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getactiveaccess, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getactiveoperation, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getactiveoperation, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getactivesubject, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getactivesubject, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getnoargumentsdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getnoargumentsdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_acl_adapterinterface_getoperations, 0, 0, Phalcon\\Acl\\OperationInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getoperations, 0, 0, IS_OBJECT, "Phalcon\\Acl\\OperationInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_acl_adapterinterface_getsubjects, 0, 0, Phalcon\\Acl\\SubjectInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_getsubjects, 0, 0, IS_OBJECT, "Phalcon\\Acl\\SubjectInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_isallowed, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_isallowed, 0, 3, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, operationName)
	ZEND_ARG_INFO(0, subjectName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, access)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_issubject, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_issubject, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_isoperation, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapterinterface_isoperation, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operationName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operationName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_setdefaultaction, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_setnoargumentsdefaultaction, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addInherit, arginfo_phalcon_acl_adapterinterface_addinherit)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addOperation, arginfo_phalcon_acl_adapterinterface_addoperation)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addSubject, arginfo_phalcon_acl_adapterinterface_addsubject)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addSubjectAccess, arginfo_phalcon_acl_adapterinterface_addsubjectaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, allow, arginfo_phalcon_acl_adapterinterface_allow)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, deny, arginfo_phalcon_acl_adapterinterface_deny)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, dropSubjectAccess, arginfo_phalcon_acl_adapterinterface_dropsubjectaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveAccess, arginfo_phalcon_acl_adapterinterface_getactiveaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveOperation, arginfo_phalcon_acl_adapterinterface_getactiveoperation)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveSubject, arginfo_phalcon_acl_adapterinterface_getactivesubject)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getDefaultAction, arginfo_phalcon_acl_adapterinterface_getdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getNoArgumentsDefaultAction, arginfo_phalcon_acl_adapterinterface_getnoargumentsdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getOperations, arginfo_phalcon_acl_adapterinterface_getoperations)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getSubjects, arginfo_phalcon_acl_adapterinterface_getsubjects)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isAllowed, arginfo_phalcon_acl_adapterinterface_isallowed)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isSubject, arginfo_phalcon_acl_adapterinterface_issubject)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isOperation, arginfo_phalcon_acl_adapterinterface_isoperation)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, setDefaultAction, arginfo_phalcon_acl_adapterinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, setNoArgumentsDefaultAction, arginfo_phalcon_acl_adapterinterface_setnoargumentsdefaultaction)
	PHP_FE_END
};

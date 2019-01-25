
extern zend_class_entry *phalcon_acl_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveKey);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addOperation);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addSubject);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addSubjectAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropSubjectAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getOperations);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getSubjects);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isOperation);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isSubject);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivefunctioncustomargumentscount, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivefunctioncustomargumentscount, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivekey, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivekey, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addinherit, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addinherit, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operationName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operationName)
#endif
	ZEND_ARG_INFO(0, operationToInherits)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addoperation, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addoperation, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, operation)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addsubject, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addsubject, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, subjectValue)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addsubjectaccess, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addsubjectaccess, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_allow, 0, 0, 3)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_deny, 0, 0, 3)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_dropsubjectaccess, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_acl_adapter_memory_getoperations, 0, 0, Phalcon\\Acl\\OperationInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getoperations, 0, 0, IS_OBJECT, "Phalcon\\Acl\\OperationInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_acl_adapter_memory_getsubjects, 0, 0, Phalcon\\Acl\\SubjectInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getsubjects, 0, 0, IS_OBJECT, "Phalcon\\Acl\\SubjectInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isallowed, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isallowed, 0, 3, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isoperation, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isoperation, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, operationName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, operationName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_issubject, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_issubject, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, subjectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, subjectName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_setnoargumentsdefaultaction, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_allowordeny, 0, 0, 4)
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
	ZEND_ARG_INFO(0, action)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_canaccess, 0, 0, 3)
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
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, access)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveFunction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount, arginfo_phalcon_acl_adapter_memory_getactivefunctioncustomargumentscount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveKey, arginfo_phalcon_acl_adapter_memory_getactivekey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addinherit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addOperation, arginfo_phalcon_acl_adapter_memory_addoperation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addSubject, arginfo_phalcon_acl_adapter_memory_addsubject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addSubjectAccess, arginfo_phalcon_acl_adapter_memory_addsubjectaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropSubjectAccess, arginfo_phalcon_acl_adapter_memory_dropsubjectaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getOperations, arginfo_phalcon_acl_adapter_memory_getoperations, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getSubjects, arginfo_phalcon_acl_adapter_memory_getsubjects, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isOperation, arginfo_phalcon_acl_adapter_memory_isoperation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isSubject, arginfo_phalcon_acl_adapter_memory_issubject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_memory_setnoargumentsdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allowOrDeny, arginfo_phalcon_acl_adapter_memory_allowordeny, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Acl_Adapter_Memory, canAccess, arginfo_phalcon_acl_adapter_memory_canaccess, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

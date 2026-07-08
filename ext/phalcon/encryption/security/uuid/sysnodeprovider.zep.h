
extern zend_class_entry *phalcon_encryption_security_uuid_sysnodeprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_SysNodeProvider);

PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, getNode);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, isValidNode);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFclose);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFgetCsv);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileExists);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileGetContents);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFilePutContents);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFopen);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFwrite);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpIsWritable);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpUnlink);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpExtensionLoaded);
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFunctionExists);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_getnode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_isvalidnode, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, node, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpextensionloaded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfunctionexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_uuid_sysnodeprovider_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, getNode, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_getnode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, isValidNode, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_isvalidnode, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFclose, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfclose, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFgetCsv, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfgetcsv, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileExists, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfileexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileGetContents, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfilegetcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFilePutContents, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfileputcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFopen, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfopen, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFwrite, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfwrite, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpIsWritable, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpiswritable, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpUnlink, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpunlink, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpExtensionLoaded, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpextensionloaded, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFunctionExists, arginfo_phalcon_encryption_security_uuid_sysnodeprovider_phpfunctionexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};

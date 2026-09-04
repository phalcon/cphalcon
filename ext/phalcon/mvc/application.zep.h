
extern zend_class_entry *phalcon_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application);

PHP_METHOD(Phalcon_Mvc_Application, handle);
PHP_METHOD(Phalcon_Mvc_Application, sendCookiesOnHandleRequest);
PHP_METHOD(Phalcon_Mvc_Application, sendHeadersOnHandleRequest);
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView);
PHP_METHOD(Phalcon_Mvc_Application, phpFclose);
PHP_METHOD(Phalcon_Mvc_Application, phpFgetCsv);
PHP_METHOD(Phalcon_Mvc_Application, phpFileExists);
PHP_METHOD(Phalcon_Mvc_Application, phpFileGetContents);
PHP_METHOD(Phalcon_Mvc_Application, phpFilePutContents);
PHP_METHOD(Phalcon_Mvc_Application, phpFopen);
PHP_METHOD(Phalcon_Mvc_Application, phpFwrite);
PHP_METHOD(Phalcon_Mvc_Application, phpIsDir);
PHP_METHOD(Phalcon_Mvc_Application, phpIsWritable);
PHP_METHOD(Phalcon_Mvc_Application, phpMkdir);
PHP_METHOD(Phalcon_Mvc_Application, phpUnlink);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_mvc_application_handle, 0, 1, Phalcon\\Http\\ResponseInterface, MAY_BE_BOOL)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_sendcookiesonhandlerequest, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, sendCookies, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_sendheadersonhandlerequest, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, sendHeaders, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_useimplicitview, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, implicitView, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_application_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_application_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_application_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_application_phpisdir, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_application_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_application_phpmkdir, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, directory, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, permissions, IS_LONG, 0, "0777")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, recursive, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_application_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_application_method_entry) {
	PHP_ME(Phalcon_Mvc_Application, handle, arginfo_phalcon_mvc_application_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, sendCookiesOnHandleRequest, arginfo_phalcon_mvc_application_sendcookiesonhandlerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, sendHeadersOnHandleRequest, arginfo_phalcon_mvc_application_sendheadersonhandlerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, useImplicitView, arginfo_phalcon_mvc_application_useimplicitview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, phpFclose, arginfo_phalcon_mvc_application_phpfclose, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpFgetCsv, arginfo_phalcon_mvc_application_phpfgetcsv, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpFileExists, arginfo_phalcon_mvc_application_phpfileexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpFileGetContents, arginfo_phalcon_mvc_application_phpfilegetcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpFilePutContents, arginfo_phalcon_mvc_application_phpfileputcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpFopen, arginfo_phalcon_mvc_application_phpfopen, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpFwrite, arginfo_phalcon_mvc_application_phpfwrite, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpIsDir, arginfo_phalcon_mvc_application_phpisdir, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpIsWritable, arginfo_phalcon_mvc_application_phpiswritable, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpMkdir, arginfo_phalcon_mvc_application_phpmkdir, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Application, phpUnlink, arginfo_phalcon_mvc_application_phpunlink, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};

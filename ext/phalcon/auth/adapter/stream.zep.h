
extern zend_class_entry *phalcon_auth_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream);

PHP_METHOD(Phalcon_Auth_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, fromOptions);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, loadUsers);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFclose);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFgetCsv);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFileExists);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFileGetContents);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFilePutContents);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFopen);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFwrite);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpIsWritable);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Auth\\Adapter\\Config\\StreamAdapterConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_stream_fromoptions, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_loadusers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_stream_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_stream_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_stream_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_phpfopen, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_stream_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_Stream, __construct, arginfo_phalcon_auth_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_Stream, fromOptions, arginfo_phalcon_auth_adapter_stream_fromoptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Adapter_Stream, loadUsers, arginfo_phalcon_auth_adapter_stream_loadusers, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFclose, arginfo_phalcon_auth_adapter_stream_phpfclose, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFgetCsv, arginfo_phalcon_auth_adapter_stream_phpfgetcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFileExists, arginfo_phalcon_auth_adapter_stream_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFileGetContents, arginfo_phalcon_auth_adapter_stream_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFilePutContents, arginfo_phalcon_auth_adapter_stream_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFopen, arginfo_phalcon_auth_adapter_stream_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpFwrite, arginfo_phalcon_auth_adapter_stream_phpfwrite, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpIsWritable, arginfo_phalcon_auth_adapter_stream_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Stream, phpUnlink, arginfo_phalcon_auth_adapter_stream_phpunlink, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

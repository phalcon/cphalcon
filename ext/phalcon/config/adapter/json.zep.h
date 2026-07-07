
extern zend_class_entry *phalcon_config_adapter_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json);

PHP_METHOD(Phalcon_Config_Adapter_Json, __construct);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFclose);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFgetCsv);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFileExists);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFileGetContents);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFilePutContents);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFopen);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpFwrite);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpIsWritable);
PHP_METHOD(Phalcon_Config_Adapter_Json, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_json___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_json_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_config_adapter_json_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_json_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_config_adapter_json_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_config_adapter_json_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_json_phpfopen, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_config_adapter_json_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_json_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_json_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_json_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Json, __construct, arginfo_phalcon_config_adapter_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFclose, arginfo_phalcon_config_adapter_json_phpfclose, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFgetCsv, arginfo_phalcon_config_adapter_json_phpfgetcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFileExists, arginfo_phalcon_config_adapter_json_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFileGetContents, arginfo_phalcon_config_adapter_json_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFilePutContents, arginfo_phalcon_config_adapter_json_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFopen, arginfo_phalcon_config_adapter_json_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpFwrite, arginfo_phalcon_config_adapter_json_phpfwrite, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpIsWritable, arginfo_phalcon_config_adapter_json_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Json, phpUnlink, arginfo_phalcon_config_adapter_json_phpunlink, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *phalcon_forms_loader_yamlloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_YamlLoader);

PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, __construct);
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, load);
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, phpExtensionLoaded);
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, phpFunctionExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_yamlloader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_yamlloader_load, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_yamlloader_phpextensionloaded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_yamlloader_phpfunctionexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_loader_yamlloader_method_entry) {
	PHP_ME(Phalcon_Forms_Loader_YamlLoader, __construct, arginfo_phalcon_forms_loader_yamlloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Loader_YamlLoader, load, arginfo_phalcon_forms_loader_yamlloader_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Loader_YamlLoader, phpExtensionLoaded, arginfo_phalcon_forms_loader_yamlloader_phpextensionloaded, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Forms_Loader_YamlLoader, phpFunctionExists, arginfo_phalcon_forms_loader_yamlloader_phpfunctionexists, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

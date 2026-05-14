
extern zend_class_entry *phalcon_forms_loader_yamlloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_YamlLoader);

PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, __construct);
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_yamlloader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_yamlloader_load, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_loader_yamlloader_method_entry) {
	PHP_ME(Phalcon_Forms_Loader_YamlLoader, __construct, arginfo_phalcon_forms_loader_yamlloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Loader_YamlLoader, load, arginfo_phalcon_forms_loader_yamlloader_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

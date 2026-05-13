
extern zend_class_entry *phalcon_forms_loader_jsonloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_JsonLoader);

PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, __construct);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, load);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFileGetContents);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_jsonloader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_load, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_phpfilegetcontents, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_loader_jsonloader_method_entry) {
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, __construct, arginfo_phalcon_forms_loader_jsonloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, load, arginfo_phalcon_forms_loader_jsonloader_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFileGetContents, arginfo_phalcon_forms_loader_jsonloader_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *phalcon_forms_loader_arrayloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_ArrayLoader);

PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, __construct);
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, load);
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, validateDefinition);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_arrayloader___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definitions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_arrayloader_load, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_arrayloader_validatedefinition, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_loader_arrayloader_method_entry) {
	PHP_ME(Phalcon_Forms_Loader_ArrayLoader, __construct, arginfo_phalcon_forms_loader_arrayloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Loader_ArrayLoader, load, arginfo_phalcon_forms_loader_arrayloader_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Loader_ArrayLoader, validateDefinition, arginfo_phalcon_forms_loader_arrayloader_validatedefinition, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

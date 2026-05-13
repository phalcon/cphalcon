
extern zend_class_entry *phalcon_forms_formslocator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_FormsLocator);

PHP_METHOD(Phalcon_Forms_FormsLocator, __construct);
PHP_METHOD(Phalcon_Forms_FormsLocator, get);
PHP_METHOD(Phalcon_Forms_FormsLocator, getElement);
PHP_METHOD(Phalcon_Forms_FormsLocator, has);
PHP_METHOD(Phalcon_Forms_FormsLocator, hasElement);
PHP_METHOD(Phalcon_Forms_FormsLocator, set);
PHP_METHOD(Phalcon_Forms_FormsLocator, setElement);
PHP_METHOD(Phalcon_Forms_FormsLocator, getDefaultServices);
zend_object *zephir_init_properties_Phalcon_Forms_FormsLocator(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_formslocator___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, definitions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_formslocator_get, 0, 1, Phalcon\\Forms\\Form, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_formslocator_getelement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_formslocator_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_formslocator_haselement, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_formslocator_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, factory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_formslocator_setelement, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_INFO(0, factory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_formslocator_getdefaultservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_formslocator_zephir_init_properties_phalcon_forms_formslocator, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_formslocator_method_entry) {
	PHP_ME(Phalcon_Forms_FormsLocator, __construct, arginfo_phalcon_forms_formslocator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_FormsLocator, get, arginfo_phalcon_forms_formslocator_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_FormsLocator, getElement, arginfo_phalcon_forms_formslocator_getelement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_FormsLocator, has, arginfo_phalcon_forms_formslocator_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_FormsLocator, hasElement, arginfo_phalcon_forms_formslocator_haselement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_FormsLocator, set, arginfo_phalcon_forms_formslocator_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_FormsLocator, setElement, arginfo_phalcon_forms_formslocator_setelement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_FormsLocator, getDefaultServices, arginfo_phalcon_forms_formslocator_getdefaultservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

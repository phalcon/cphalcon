
extern zend_class_entry *phalcon_forms_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Manager);

PHP_METHOD(Phalcon_Forms_Manager, create);
PHP_METHOD(Phalcon_Forms_Manager, get);
PHP_METHOD(Phalcon_Forms_Manager, has);
PHP_METHOD(Phalcon_Forms_Manager, set);
zend_object *zephir_init_properties_Phalcon_Forms_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_manager_create, 0, 1, Phalcon\\Forms\\Form, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_manager_get, 0, 1, Phalcon\\Forms\\Form, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_manager_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_manager_set, 0, 2, Phalcon\\Forms\\Manager, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_zephir_init_properties_phalcon_forms_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_manager_method_entry) {
	PHP_ME(Phalcon_Forms_Manager, create, arginfo_phalcon_forms_manager_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, get, arginfo_phalcon_forms_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, has, arginfo_phalcon_forms_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, set, arginfo_phalcon_forms_manager_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

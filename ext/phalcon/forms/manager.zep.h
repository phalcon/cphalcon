
extern zend_class_entry *phalcon_forms_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Manager);

PHP_METHOD(Phalcon_Forms_Manager, create);
PHP_METHOD(Phalcon_Forms_Manager, get);
PHP_METHOD(Phalcon_Forms_Manager, has);
PHP_METHOD(Phalcon_Forms_Manager, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_create, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_manager_method_entry) {
	PHP_ME(Phalcon_Forms_Manager, create, arginfo_phalcon_forms_manager_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, get, arginfo_phalcon_forms_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, has, arginfo_phalcon_forms_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, set, arginfo_phalcon_forms_manager_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

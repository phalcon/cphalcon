
extern zend_class_entry *phalcon_forms_element_check_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Check);

PHP_METHOD(Phalcon_Forms_Element_Check, getUncheckedValue);
PHP_METHOD(Phalcon_Forms_Element_Check, hasUncheckedValue);
PHP_METHOD(Phalcon_Forms_Element_Check, setUncheckedValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_check_getuncheckedvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_element_check_hasuncheckedvalue, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_forms_element_check_setuncheckedvalue, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_check_method_entry) {
PHP_ME(Phalcon_Forms_Element_Check, getUncheckedValue, arginfo_phalcon_forms_element_check_getuncheckedvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Check, hasUncheckedValue, arginfo_phalcon_forms_element_check_hasuncheckedvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Check, setUncheckedValue, arginfo_phalcon_forms_element_check_setuncheckedvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

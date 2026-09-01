
extern zend_class_entry *phalcon_forms_exceptions_formnotinlocator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Exceptions_FormNotInLocator);

PHP_METHOD(Phalcon_Forms_Exceptions_FormNotInLocator, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_exceptions_formnotinlocator___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_exceptions_formnotinlocator_method_entry) {
	PHP_ME(Phalcon_Forms_Exceptions_FormNotInLocator, __construct, arginfo_phalcon_forms_exceptions_formnotinlocator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

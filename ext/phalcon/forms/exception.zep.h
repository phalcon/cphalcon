
extern zend_class_entry *phalcon_forms_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Exception);

PHP_METHOD(Phalcon_Forms_Exception, tagFactoryNotFound);
PHP_METHOD(Phalcon_Forms_Exception, usingParameterRequired);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_exception_tagfactorynotfound, 0, 0, Phalcon\\Forms\\Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_forms_exception_usingparameterrequired, 0, 0, Phalcon\\Forms\\Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_exception_method_entry) {
	PHP_ME(Phalcon_Forms_Exception, tagFactoryNotFound, arginfo_phalcon_forms_exception_tagfactorynotfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Exception, usingParameterRequired, arginfo_phalcon_forms_exception_usingparameterrequired, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

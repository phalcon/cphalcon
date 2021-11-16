
extern zend_class_entry *phalcon_html_escaperfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_EscaperFactory);

PHP_METHOD(Phalcon_Html_EscaperFactory, newInstance);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaperfactory_newinstance, 0, 0, Phalcon\\Html\\Escaper, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaperfactory_method_entry) {
	PHP_ME(Phalcon_Html_EscaperFactory, newInstance, arginfo_phalcon_html_escaperfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

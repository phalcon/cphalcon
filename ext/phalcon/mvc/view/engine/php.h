
extern zend_class_entry *phalcon_mvc_view_engine_php_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Php);

PHP_METHOD(Phalcon_Mvc_View_Engine_Php, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_php_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_php_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Php, render, arginfo_phalcon_mvc_view_engine_php_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

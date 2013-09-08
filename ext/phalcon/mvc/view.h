
extern zend_class_entry *phalcon_mvc_view_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View);

PHP_METHOD(Phalcon_Mvc_View, __construct);
PHP_METHOD(Phalcon_Mvc_View, setViewsDir);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setviewsdir, 0, 0, 0)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_method_entry) {
	PHP_ME(Phalcon_Mvc_View, __construct, arginfo_phalcon_mvc_view___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setViewsDir, arginfo_phalcon_mvc_view_setviewsdir, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

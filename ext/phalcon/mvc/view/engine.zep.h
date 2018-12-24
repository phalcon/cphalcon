
extern zend_class_entry *phalcon_mvc_view_engine_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine);

PHP_METHOD(Phalcon_Mvc_View_Engine, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent);
PHP_METHOD(Phalcon_Mvc_View_Engine, partial);
PHP_METHOD(Phalcon_Mvc_View_Engine, getView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\ViewBaseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_getcontent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_getcontent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_partial, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_partial, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, partialPath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, partialPath)
#endif
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_getview, 0, 0, Phalcon\\Mvc\\ViewBaseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_getview, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ViewBaseInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine, __construct, arginfo_phalcon_mvc_view_engine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine, getContent, arginfo_phalcon_mvc_view_engine_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine, partial, arginfo_phalcon_mvc_view_engine_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine, getView, arginfo_phalcon_mvc_view_engine_getview, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_mvc_view_engine_abstractengine_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_AbstractEngine);

PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, getContent);
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, getView);
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, partial);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_abstractengine___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\ViewBaseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_abstractengine_getcontent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_abstractengine_getview, 0, 0, Phalcon\\Mvc\\ViewBaseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_abstractengine_partial, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, partialPath, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_abstractengine_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_AbstractEngine, __construct, arginfo_phalcon_mvc_view_engine_abstractengine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_AbstractEngine, getContent, arginfo_phalcon_mvc_view_engine_abstractengine_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_AbstractEngine, getView, arginfo_phalcon_mvc_view_engine_abstractengine_getview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_AbstractEngine, partial, arginfo_phalcon_mvc_view_engine_abstractengine_partial, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

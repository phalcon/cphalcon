
extern zend_class_entry *phalcon_mvc_model_binder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Binder);

PHP_METHOD(Phalcon_Mvc_Model_Binder, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Binder, bindToHandler);
PHP_METHOD(Phalcon_Mvc_Model_Binder, findBoundModel);
PHP_METHOD(Phalcon_Mvc_Model_Binder, getBoundModels);
PHP_METHOD(Phalcon_Mvc_Model_Binder, getOriginalValues);
PHP_METHOD(Phalcon_Mvc_Model_Binder, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromCache);
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromReflection);
PHP_METHOD(Phalcon_Mvc_Model_Binder, setCache);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Binder(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_binder___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\Adapter\\AdapterInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binder_bindtohandler, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_TYPE_INFO(0, cacheKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_binder_findboundmodel, 0, 0, 2)
	ZEND_ARG_INFO(0, paramValue)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binder_getboundmodels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binder_getoriginalvalues, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_binder_getcache, 0, 0, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binder_getparamsfromcache, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, cacheKey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binder_getparamsfromreflection, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_TYPE_INFO(0, cacheKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_binder_setcache, 0, 1, Phalcon\\Mvc\\Model\\BinderInterface, 0)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_binder_zephir_init_properties_phalcon_mvc_model_binder, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_binder_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Binder, __construct, arginfo_phalcon_mvc_model_binder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Binder, bindToHandler, arginfo_phalcon_mvc_model_binder_bindtohandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Binder, findBoundModel, arginfo_phalcon_mvc_model_binder_findboundmodel, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Binder, getBoundModels, arginfo_phalcon_mvc_model_binder_getboundmodels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Binder, getOriginalValues, arginfo_phalcon_mvc_model_binder_getoriginalvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Binder, getCache, arginfo_phalcon_mvc_model_binder_getcache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Binder, getParamsFromCache, arginfo_phalcon_mvc_model_binder_getparamsfromcache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Binder, getParamsFromReflection, arginfo_phalcon_mvc_model_binder_getparamsfromreflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Binder, setCache, arginfo_phalcon_mvc_model_binder_setcache, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

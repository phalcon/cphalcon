
extern zend_class_entry *phalcon_mvc_model_resultset_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

PHP_METHOD(Phalcon_Mvc_Model_Resultset, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, jsonSerialize);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, update);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, valid);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Resultset(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_delete, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_filter, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultset_getcache, 0, 0, Phalcon\\Cache\\CacheInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_getfirst, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_gethydratemode, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultset_getlast, 0, 0, Phalcon\\Mvc\\ModelInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_getmessages, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_isfresh, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_key, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetget, 0, 1, IS_MIXED, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetget, 0, 1, IS_NULL, 0)
#endif
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_rewind, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_seek, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultset_sethydratemode, 0, 1, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, hydrateMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultset_setisfresh, 0, 1, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, isFresh, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_update, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultset_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_zephir_init_properties_phalcon_mvc_model_resultset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset, __construct, arginfo_phalcon_mvc_model_resultset___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset, count, arginfo_phalcon_mvc_model_resultset_count, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, delete, arginfo_phalcon_mvc_model_resultset_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, filter, arginfo_phalcon_mvc_model_resultset_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getCache, arginfo_phalcon_mvc_model_resultset_getcache, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Resultset, getFirst, arginfo_phalcon_mvc_model_resultset_getfirst, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Resultset, getFirst, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Resultset, getHydrateMode, arginfo_phalcon_mvc_model_resultset_gethydratemode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getLast, arginfo_phalcon_mvc_model_resultset_getlast, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getMessages, arginfo_phalcon_mvc_model_resultset_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getType, arginfo_phalcon_mvc_model_resultset_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, isFresh, arginfo_phalcon_mvc_model_resultset_isfresh, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, jsonSerialize, arginfo_phalcon_mvc_model_resultset_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, key, arginfo_phalcon_mvc_model_resultset_key, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, next, arginfo_phalcon_mvc_model_resultset_next, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetGet, arginfo_phalcon_mvc_model_resultset_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetExists, arginfo_phalcon_mvc_model_resultset_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetSet, arginfo_phalcon_mvc_model_resultset_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetUnset, arginfo_phalcon_mvc_model_resultset_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, rewind, arginfo_phalcon_mvc_model_resultset_rewind, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, seek, arginfo_phalcon_mvc_model_resultset_seek, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, setHydrateMode, arginfo_phalcon_mvc_model_resultset_sethydratemode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, setIsFresh, arginfo_phalcon_mvc_model_resultset_setisfresh, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, update, arginfo_phalcon_mvc_model_resultset_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, valid, arginfo_phalcon_mvc_model_resultset_valid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

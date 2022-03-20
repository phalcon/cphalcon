
extern zend_class_entry *phalcon_mvc_model_row_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Row);

PHP_METHOD(Phalcon_Mvc_Model_Row, jsonSerialize);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Model_Row, readAttribute);
PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState);
PHP_METHOD(Phalcon_Mvc_Model_Row, toArray);
PHP_METHOD(Phalcon_Mvc_Model_Row, writeAttribute);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_offsetget, 0, 1, IS_MIXED, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_offsetget, 0, 1, IS_NULL, 0)
#endif
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_readattribute, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_setdirtystate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_row_writeattribute, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_row_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Row, jsonSerialize, arginfo_phalcon_mvc_model_row_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetGet, arginfo_phalcon_mvc_model_row_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetExists, arginfo_phalcon_mvc_model_row_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetSet, arginfo_phalcon_mvc_model_row_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetUnset, arginfo_phalcon_mvc_model_row_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, readAttribute, arginfo_phalcon_mvc_model_row_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, setDirtyState, arginfo_phalcon_mvc_model_row_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, toArray, arginfo_phalcon_mvc_model_row_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, writeAttribute, arginfo_phalcon_mvc_model_row_writeattribute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

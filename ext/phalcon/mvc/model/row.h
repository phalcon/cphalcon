
extern zend_class_entry *phalcon_mvc_model_row_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Row);

PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Model_Row, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_row_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Row, setDirtyState, arginfo_phalcon_mvc_model_row_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetExists, arginfo_phalcon_mvc_model_row_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetGet, arginfo_phalcon_mvc_model_row_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetSet, arginfo_phalcon_mvc_model_row_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetUnset, arginfo_phalcon_mvc_model_row_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength);

PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_stringlength_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_stringlength_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_StringLength, validate, arginfo_phalcon_mvc_model_validator_stringlength_validate, ZEND_ACC_PUBLIC)
  PHP_FE_END
};

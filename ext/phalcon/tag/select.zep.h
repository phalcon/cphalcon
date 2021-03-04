
extern zend_class_entry *phalcon_tag_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_Tag_Select);

PHP_METHOD(Phalcon_Tag_Select, selectField);
PHP_METHOD(Phalcon_Tag_Select, optionsFromArray);
PHP_METHOD(Phalcon_Tag_Select, optionsFromResultset);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_tag_select_selectfield, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_tag_select_optionsfromarray, 0, 3, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, closeOption, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_tag_select_optionsfromresultset, 0, 4, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, resultset, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
	ZEND_ARG_INFO(0, using)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, closeOption, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_tag_select_method_entry) {
	PHP_ME(Phalcon_Tag_Select, selectField, arginfo_phalcon_tag_select_selectfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag_Select, optionsFromArray, arginfo_phalcon_tag_select_optionsfromarray, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag_Select, optionsFromResultset, arginfo_phalcon_tag_select_optionsfromresultset, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};

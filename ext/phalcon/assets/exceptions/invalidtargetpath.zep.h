
extern zend_class_entry *phalcon_assets_exceptions_invalidtargetpath_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Exceptions_InvalidTargetPath);

PHP_METHOD(Phalcon_Assets_Exceptions_InvalidTargetPath, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_exceptions_invalidtargetpath___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_exceptions_invalidtargetpath_method_entry) {
	PHP_ME(Phalcon_Assets_Exceptions_InvalidTargetPath, __construct, arginfo_phalcon_assets_exceptions_invalidtargetpath___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


extern zend_class_entry *phalcon_helper_fs_ce;

ZEPHIR_INIT_CLASS(Phalcon_Helper_Fs);

PHP_METHOD(Phalcon_Helper_Fs, basename);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_fs_basename, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_helper_fs_method_entry) {
	PHP_ME(Phalcon_Helper_Fs, basename, arginfo_phalcon_helper_fs_basename, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

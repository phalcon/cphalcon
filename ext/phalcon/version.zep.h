
extern zend_class_entry *phalcon_version_ce;

ZEPHIR_INIT_CLASS(Phalcon_Version);

PHP_METHOD(Phalcon_Version, _getVersion);
PHP_METHOD(Phalcon_Version, _getSpecial);
PHP_METHOD(Phalcon_Version, get);
PHP_METHOD(Phalcon_Version, getId);
PHP_METHOD(Phalcon_Version, getPart);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_version__getspecial, 0, 0, 1)
	ZEND_ARG_INFO(0, special)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_version_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, part)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_version_method_entry) {
	PHP_ME(Phalcon_Version, _getVersion, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, _getSpecial, arginfo_phalcon_version__getspecial, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getPart, arginfo_phalcon_version_getpart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

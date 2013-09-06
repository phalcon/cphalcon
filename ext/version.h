
extern zend_class_entry *phalcon_version_ce;

ZEPHIR_INIT_CLASS(Phalcon_Version);

PHP_METHOD(Phalcon_Version, _getVersion);
PHP_METHOD(Phalcon_Version, get);
PHP_METHOD(Phalcon_Version, getId);

ZEPHIR_INIT_FUNCS(phalcon_version_method_entry) {
	PHP_ME(Phalcon_Version, _getVersion, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

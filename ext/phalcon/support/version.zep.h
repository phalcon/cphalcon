
extern zend_class_entry *phalcon_support_version_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Version);

PHP_METHOD(Phalcon_Support_Version, getVersion);
PHP_METHOD(Phalcon_Support_Version, getSpecial);
PHP_METHOD(Phalcon_Support_Version, get);
PHP_METHOD(Phalcon_Support_Version, getId);
PHP_METHOD(Phalcon_Support_Version, getPart);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_version_getversion, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_version_getspecial, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, special, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_version_get, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_version_getid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_version_getpart, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, part, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_version_method_entry) {
	PHP_ME(Phalcon_Support_Version, getVersion, arginfo_phalcon_support_version_getversion, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Version, getSpecial, arginfo_phalcon_support_version_getspecial, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Support_Version, get, arginfo_phalcon_support_version_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Version, getId, arginfo_phalcon_support_version_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Version, getPart, arginfo_phalcon_support_version_getpart, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *phalcon_version_ce;

ZEPHIR_INIT_CLASS(Phalcon_Version);

PHP_METHOD(Phalcon_Version, _getVersion);
PHP_METHOD(Phalcon_Version, getVersion);
PHP_METHOD(Phalcon_Version, _getSpecial);
PHP_METHOD(Phalcon_Version, getSpecial);
PHP_METHOD(Phalcon_Version, get);
PHP_METHOD(Phalcon_Version, getId);
PHP_METHOD(Phalcon_Version, getPart);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version__getversion, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version__getversion, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getversion, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getversion, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version__getspecial, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version__getspecial, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, special, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, special)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getspecial, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getspecial, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, special, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, special)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_get, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_get, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getpart, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_version_getpart, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, part, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, part)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_version_method_entry) {
	PHP_ME(Phalcon_Version, _getVersion, arginfo_phalcon_version__getversion, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getVersion, arginfo_phalcon_version_getversion, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, _getSpecial, arginfo_phalcon_version__getspecial, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getSpecial, arginfo_phalcon_version_getspecial, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, get, arginfo_phalcon_version_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getId, arginfo_phalcon_version_getid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getPart, arginfo_phalcon_version_getpart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

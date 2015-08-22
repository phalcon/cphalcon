
extern zend_class_entry *phalcon_security_random_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_Random);

PHP_METHOD(Phalcon_Security_Random, bytes);
PHP_METHOD(Phalcon_Security_Random, hex);
PHP_METHOD(Phalcon_Security_Random, base58);
PHP_METHOD(Phalcon_Security_Random, base64);
PHP_METHOD(Phalcon_Security_Random, base64Safe);
PHP_METHOD(Phalcon_Security_Random, uuid);
PHP_METHOD(Phalcon_Security_Random, number);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_random_bytes, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_random_hex, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_random_base58, 0, 0, 0)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_random_base64, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_random_base64safe, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
	ZEND_ARG_INFO(0, padding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_random_number, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_random_method_entry) {
	PHP_ME(Phalcon_Security_Random, bytes, arginfo_phalcon_security_random_bytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_Random, hex, arginfo_phalcon_security_random_hex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_Random, base58, arginfo_phalcon_security_random_base58, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_Random, base64, arginfo_phalcon_security_random_base64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_Random, base64Safe, arginfo_phalcon_security_random_base64safe, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_Random, uuid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_Random, number, arginfo_phalcon_security_random_number, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

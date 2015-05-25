
extern zend_class_entry *phalcon_text_ce;

ZEPHIR_INIT_CLASS(Phalcon_Text);

PHP_METHOD(Phalcon_Text, camelize);
PHP_METHOD(Phalcon_Text, uncamelize);
PHP_METHOD(Phalcon_Text, increment);
PHP_METHOD(Phalcon_Text, random);
PHP_METHOD(Phalcon_Text, startsWith);
PHP_METHOD(Phalcon_Text, endsWith);
PHP_METHOD(Phalcon_Text, lower);
PHP_METHOD(Phalcon_Text, upper);
PHP_METHOD(Phalcon_Text, reduceSlashes);
PHP_METHOD(Phalcon_Text, concat);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_random, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_endswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, end)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_lower, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_upper, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_reduceslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_text_method_entry) {
	PHP_ME(Phalcon_Text, camelize, arginfo_phalcon_text_camelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, uncamelize, arginfo_phalcon_text_uncamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, increment, arginfo_phalcon_text_increment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, random, arginfo_phalcon_text_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, startsWith, arginfo_phalcon_text_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, endsWith, arginfo_phalcon_text_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, lower, arginfo_phalcon_text_lower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, upper, arginfo_phalcon_text_upper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, reduceSlashes, arginfo_phalcon_text_reduceslashes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, concat, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

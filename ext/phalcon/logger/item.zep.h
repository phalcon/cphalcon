
extern zend_class_entry *phalcon_logger_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Item);

PHP_METHOD(Phalcon_Logger_Item, getContext);
PHP_METHOD(Phalcon_Logger_Item, getMessage);
PHP_METHOD(Phalcon_Logger_Item, getLevel);
PHP_METHOD(Phalcon_Logger_Item, getLevelName);
PHP_METHOD(Phalcon_Logger_Item, getTime);
PHP_METHOD(Phalcon_Logger_Item, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_getcontext, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getmessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_getlevel, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getlevelname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_gettime, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, levelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, time, DateTimeImmutable, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_item_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Logger_Item, getContext, arginfo_phalcon_logger_item_getcontext, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Logger_Item, getContext, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Logger_Item, getMessage, arginfo_phalcon_logger_item_getmessage, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Logger_Item, getLevel, arginfo_phalcon_logger_item_getlevel, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Logger_Item, getLevel, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Logger_Item, getLevelName, arginfo_phalcon_logger_item_getlevelname, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Logger_Item, getTime, arginfo_phalcon_logger_item_gettime, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Logger_Item, getTime, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

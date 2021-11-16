
extern zend_class_entry *phalcon_logger_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Item);

PHP_METHOD(Phalcon_Logger_Item, getContext);
PHP_METHOD(Phalcon_Logger_Item, getMessage);
PHP_METHOD(Phalcon_Logger_Item, getLevel);
PHP_METHOD(Phalcon_Logger_Item, getLevelName);
PHP_METHOD(Phalcon_Logger_Item, getDateTime);
PHP_METHOD(Phalcon_Logger_Item, __construct);
zend_object *zephir_init_properties_Phalcon_Logger_Item(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getcontext, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getmessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getlevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getlevelname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_getdatetime, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, levelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, dateTime, DateTimeImmutable, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_zephir_init_properties_phalcon_logger_item, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_item_method_entry) {
	PHP_ME(Phalcon_Logger_Item, getContext, arginfo_phalcon_logger_item_getcontext, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getMessage, arginfo_phalcon_logger_item_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getLevel, arginfo_phalcon_logger_item_getlevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getLevelName, arginfo_phalcon_logger_item_getlevelname, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Logger_Item, getDateTime, arginfo_phalcon_logger_item_getdatetime, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Logger_Item, getDateTime, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

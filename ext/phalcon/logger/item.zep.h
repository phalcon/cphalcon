
extern zend_class_entry *phalcon_logger_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Item);

PHP_METHOD(Phalcon_Logger_Item, getContext);
PHP_METHOD(Phalcon_Logger_Item, getMessage);
PHP_METHOD(Phalcon_Logger_Item, getName);
PHP_METHOD(Phalcon_Logger_Item, getTime);
PHP_METHOD(Phalcon_Logger_Item, getType);
PHP_METHOD(Phalcon_Logger_Item, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_getcontext, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getmessage, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getmessage, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_item_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_gettime, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, time, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, time)
#endif
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_item_method_entry) {
	PHP_ME(Phalcon_Logger_Item, getContext, arginfo_phalcon_logger_item_getcontext, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getMessage, arginfo_phalcon_logger_item_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getName, arginfo_phalcon_logger_item_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getTime, arginfo_phalcon_logger_item_gettime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getType, arginfo_phalcon_logger_item_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

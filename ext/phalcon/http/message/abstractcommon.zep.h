
extern zend_class_entry *phalcon_http_message_abstractcommon_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_AbstractCommon);

PHP_METHOD(Phalcon_Http_Message_AbstractCommon, cloneInstance);
PHP_METHOD(Phalcon_Http_Message_AbstractCommon, checkStringParameter);
PHP_METHOD(Phalcon_Http_Message_AbstractCommon, processWith);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractcommon_cloneinstance, 0, 2, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractcommon_cloneinstance, 0, 2, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, element)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractcommon_checkstringparameter, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractcommon_processwith, 0, 2, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractcommon_processwith, 0, 2, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, element)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_abstractcommon_method_entry) {
	PHP_ME(Phalcon_Http_Message_AbstractCommon, cloneInstance, arginfo_phalcon_http_message_abstractcommon_cloneinstance, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractCommon, checkStringParameter, arginfo_phalcon_http_message_abstractcommon_checkstringparameter, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractCommon, processWith, arginfo_phalcon_http_message_abstractcommon_processwith, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_FE_END
};

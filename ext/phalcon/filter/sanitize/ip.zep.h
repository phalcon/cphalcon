
extern zend_class_entry *phalcon_filter_sanitize_ip_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Ip);

PHP_METHOD(Phalcon_Filter_Sanitize_Ip, __invoke);
PHP_METHOD(Phalcon_Filter_Sanitize_Ip, getIpAddressProtocolVersion);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_ip___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_filter_sanitize_ip_getipaddressprotocolversion, 0, 1, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_ip_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_Ip, __invoke, arginfo_phalcon_filter_sanitize_ip___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Sanitize_Ip, getIpAddressProtocolVersion, arginfo_phalcon_filter_sanitize_ip_getipaddressprotocolversion, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

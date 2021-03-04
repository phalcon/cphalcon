
extern zend_class_entry *phalcon_html_link_serializer_header_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Serializer_Header);

PHP_METHOD(Phalcon_Html_Link_Serializer_Header, serialize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_serializer_header_serialize, 0, 1, IS_STRING, 1)
	ZEND_ARG_ARRAY_INFO(0, links, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_serializer_header_method_entry) {
	PHP_ME(Phalcon_Html_Link_Serializer_Header, serialize, arginfo_phalcon_html_link_serializer_header_serialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

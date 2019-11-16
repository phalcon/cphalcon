
extern zend_class_entry *phalcon_html_link_serializer_serializerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Serializer_SerializerInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_serializer_serializerinterface_serialize, 0, 1, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_serializer_serializerinterface_serialize, 0, 1, IS_STRING, NULL, 1)
#endif
	ZEND_ARG_ARRAY_INFO(0, links, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_serializer_serializerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Html_Link_Serializer_SerializerInterface, serialize, arginfo_phalcon_html_link_serializer_serializerinterface_serialize)
	PHP_FE_END
};

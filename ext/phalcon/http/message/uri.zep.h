
extern zend_class_entry *phalcon_http_message_uri_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Uri);

PHP_METHOD(Phalcon_Http_Message_Uri, getFragment);
PHP_METHOD(Phalcon_Http_Message_Uri, getHost);
PHP_METHOD(Phalcon_Http_Message_Uri, getPath);
PHP_METHOD(Phalcon_Http_Message_Uri, getPort);
PHP_METHOD(Phalcon_Http_Message_Uri, getQuery);
PHP_METHOD(Phalcon_Http_Message_Uri, getScheme);
PHP_METHOD(Phalcon_Http_Message_Uri, __construct);
PHP_METHOD(Phalcon_Http_Message_Uri, __toString);
PHP_METHOD(Phalcon_Http_Message_Uri, getAuthority);
PHP_METHOD(Phalcon_Http_Message_Uri, getUserInfo);
PHP_METHOD(Phalcon_Http_Message_Uri, withFragment);
PHP_METHOD(Phalcon_Http_Message_Uri, withPath);
PHP_METHOD(Phalcon_Http_Message_Uri, withPort);
PHP_METHOD(Phalcon_Http_Message_Uri, withQuery);
PHP_METHOD(Phalcon_Http_Message_Uri, withScheme);
PHP_METHOD(Phalcon_Http_Message_Uri, withUserInfo);
PHP_METHOD(Phalcon_Http_Message_Uri, withHost);
PHP_METHOD(Phalcon_Http_Message_Uri, checkValue);
PHP_METHOD(Phalcon_Http_Message_Uri, filterFragment);
PHP_METHOD(Phalcon_Http_Message_Uri, filterPath);
PHP_METHOD(Phalcon_Http_Message_Uri, filterPort);
PHP_METHOD(Phalcon_Http_Message_Uri, filterQuery);
PHP_METHOD(Phalcon_Http_Message_Uri, filterScheme);
PHP_METHOD(Phalcon_Http_Message_Uri, splitQueryValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri_getfragment, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri_gethost, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri_getpath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri_getport, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri_getquery, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri_getscheme, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uri___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_getauthority, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_getauthority, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_getuserinfo, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_getuserinfo, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withfragment, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withfragment, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withpath, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withpath, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withport, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withport, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withquery, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withquery, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withscheme, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withscheme, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withuserinfo, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withuserinfo, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uri_withhost, 0, 1, Phalcon\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_withhost, 0, 1, IS_OBJECT, "Phalcon\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_checkvalue, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_checkvalue, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, suffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, suffix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterfragment, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterfragment, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fragment, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fragment)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterpath, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterpath, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterport, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterport, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterquery, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterquery, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, query, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, query)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterscheme, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_filterscheme, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, scheme)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_splitqueryvalue, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uri_splitqueryvalue, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_uri_method_entry) {
	PHP_ME(Phalcon_Http_Message_Uri, getFragment, arginfo_phalcon_http_message_uri_getfragment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getHost, arginfo_phalcon_http_message_uri_gethost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getPath, arginfo_phalcon_http_message_uri_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getPort, arginfo_phalcon_http_message_uri_getport, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getQuery, arginfo_phalcon_http_message_uri_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getScheme, arginfo_phalcon_http_message_uri_getscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, __construct, arginfo_phalcon_http_message_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_Uri, __toString, arginfo_phalcon_http_message_uri___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getAuthority, arginfo_phalcon_http_message_uri_getauthority, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, getUserInfo, arginfo_phalcon_http_message_uri_getuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withFragment, arginfo_phalcon_http_message_uri_withfragment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withPath, arginfo_phalcon_http_message_uri_withpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withPort, arginfo_phalcon_http_message_uri_withport, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withQuery, arginfo_phalcon_http_message_uri_withquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withScheme, arginfo_phalcon_http_message_uri_withscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withUserInfo, arginfo_phalcon_http_message_uri_withuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, withHost, arginfo_phalcon_http_message_uri_withhost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Uri, checkValue, arginfo_phalcon_http_message_uri_checkvalue, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Uri, filterFragment, arginfo_phalcon_http_message_uri_filterfragment, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Uri, filterPath, arginfo_phalcon_http_message_uri_filterpath, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Uri, filterPort, arginfo_phalcon_http_message_uri_filterport, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Uri, filterQuery, arginfo_phalcon_http_message_uri_filterquery, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Uri, filterScheme, arginfo_phalcon_http_message_uri_filterscheme, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Uri, splitQueryValue, arginfo_phalcon_http_message_uri_splitqueryvalue, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

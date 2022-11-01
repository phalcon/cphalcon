
extern zend_class_entry *phalcon_http_request_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request);

PHP_METHOD(Phalcon_Http_Request, get);
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent);
PHP_METHOD(Phalcon_Http_Request, getBasicAuth);
PHP_METHOD(Phalcon_Http_Request, getBestAccept);
PHP_METHOD(Phalcon_Http_Request, getBestCharset);
PHP_METHOD(Phalcon_Http_Request, getBestLanguage);
PHP_METHOD(Phalcon_Http_Request, getHttpMethodParameterOverride);
PHP_METHOD(Phalcon_Http_Request, getPreferredIsoLocaleVariant);
PHP_METHOD(Phalcon_Http_Request, getClientAddress);
PHP_METHOD(Phalcon_Http_Request, getClientCharsets);
PHP_METHOD(Phalcon_Http_Request, getContentType);
PHP_METHOD(Phalcon_Http_Request, getDigestAuth);
PHP_METHOD(Phalcon_Http_Request, getFilteredQuery);
PHP_METHOD(Phalcon_Http_Request, getFilteredPatch);
PHP_METHOD(Phalcon_Http_Request, getFilteredPost);
PHP_METHOD(Phalcon_Http_Request, getFilteredPut);
PHP_METHOD(Phalcon_Http_Request, getHeader);
PHP_METHOD(Phalcon_Http_Request, getHeaders);
PHP_METHOD(Phalcon_Http_Request, getHttpHost);
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer);
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody);
PHP_METHOD(Phalcon_Http_Request, getLanguages);
PHP_METHOD(Phalcon_Http_Request, getMethod);
PHP_METHOD(Phalcon_Http_Request, getPatch);
PHP_METHOD(Phalcon_Http_Request, getPort);
PHP_METHOD(Phalcon_Http_Request, getPost);
PHP_METHOD(Phalcon_Http_Request, getPut);
PHP_METHOD(Phalcon_Http_Request, getQuery);
PHP_METHOD(Phalcon_Http_Request, getRawBody);
PHP_METHOD(Phalcon_Http_Request, getScheme);
PHP_METHOD(Phalcon_Http_Request, getServer);
PHP_METHOD(Phalcon_Http_Request, getServerAddress);
PHP_METHOD(Phalcon_Http_Request, getServerName);
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles);
PHP_METHOD(Phalcon_Http_Request, getURI);
PHP_METHOD(Phalcon_Http_Request, getUserAgent);
PHP_METHOD(Phalcon_Http_Request, has);
PHP_METHOD(Phalcon_Http_Request, hasFiles);
PHP_METHOD(Phalcon_Http_Request, hasHeader);
PHP_METHOD(Phalcon_Http_Request, hasPatch);
PHP_METHOD(Phalcon_Http_Request, hasPost);
PHP_METHOD(Phalcon_Http_Request, hasPut);
PHP_METHOD(Phalcon_Http_Request, hasQuery);
PHP_METHOD(Phalcon_Http_Request, hasServer);
PHP_METHOD(Phalcon_Http_Request, isAjax);
PHP_METHOD(Phalcon_Http_Request, isConnect);
PHP_METHOD(Phalcon_Http_Request, isDelete);
PHP_METHOD(Phalcon_Http_Request, isGet);
PHP_METHOD(Phalcon_Http_Request, isHead);
PHP_METHOD(Phalcon_Http_Request, isMethod);
PHP_METHOD(Phalcon_Http_Request, isOptions);
PHP_METHOD(Phalcon_Http_Request, isPatch);
PHP_METHOD(Phalcon_Http_Request, isPost);
PHP_METHOD(Phalcon_Http_Request, isPut);
PHP_METHOD(Phalcon_Http_Request, isPurge);
PHP_METHOD(Phalcon_Http_Request, isSecure);
PHP_METHOD(Phalcon_Http_Request, isStrictHostCheck);
PHP_METHOD(Phalcon_Http_Request, isSoap);
PHP_METHOD(Phalcon_Http_Request, isTrace);
PHP_METHOD(Phalcon_Http_Request, isValidHttpMethod);
PHP_METHOD(Phalcon_Http_Request, numFiles);
PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride);
PHP_METHOD(Phalcon_Http_Request, setParameterFilters);
PHP_METHOD(Phalcon_Http_Request, setStrictHostCheck);
PHP_METHOD(Phalcon_Http_Request, getBestQuality);
PHP_METHOD(Phalcon_Http_Request, getHelper);
PHP_METHOD(Phalcon_Http_Request, hasFileHelper);
PHP_METHOD(Phalcon_Http_Request, getQualityHeader);
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders);
PHP_METHOD(Phalcon_Http_Request, smoothFiles);
PHP_METHOD(Phalcon_Http_Request, getFilterService);
PHP_METHOD(Phalcon_Http_Request, getServerArray);
PHP_METHOD(Phalcon_Http_Request, getFilteredData);
PHP_METHOD(Phalcon_Http_Request, getPatchPut);
zend_object *zephir_init_properties_Phalcon_Http_Request(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_get, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getacceptablecontent, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getbasicauth, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getbestaccept, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getbestcharset, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getbestlanguage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_gethttpmethodparameteroverride, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getpreferredisolocalevariant, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getclientaddress, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, trustForwardedHeader, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getclientcharsets, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getcontenttype, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getdigestauth, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getfilteredquery, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getfilteredpatch, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getfilteredpost, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getfilteredput, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getheader, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_gethttphost, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_gethttpreferer, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getjsonrawbody, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getlanguages, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getmethod, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getpatch, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getport, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getpost, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getput, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getquery, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getrawbody, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getscheme, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getserver, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getserveraddress, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getservername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getuploadedfiles, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, namedKeys, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_geturi, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, onlyPath, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getuseragent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_hasfiles, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_hasheader, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_haspatch, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_haspost, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_hasput, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_hasquery, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_hasserver, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isajax, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isconnect, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isdelete, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isget, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_ishead, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_ismethod, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, methods)
	ZEND_ARG_TYPE_INFO(0, strict, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isoptions, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_ispatch, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_ispost, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isput, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_ispurge, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_issecure, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isstricthostcheck, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_issoap, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_istrace, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_isvalidhttpmethod, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_numfiles, 0, 0, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_request_sethttpmethodparameteroverride, 0, 1, Phalcon\\Http\\Request, 0)
	ZEND_ARG_TYPE_INFO(0, override, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_request_setparameterfilters, 0, 1, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, scope, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, scope, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_request_setstricthostcheck, 0, 0, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_TYPE_INFO(0, flag, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getbestquality, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, qualityParts, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_gethelper, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, source, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_hasfilehelper, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getqualityheader, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, serverIndex, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_resolveauthorizationheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_smoothfiles, 0, 6, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, names, 0)
	ZEND_ARG_ARRAY_INFO(0, types, 0)
	ZEND_ARG_ARRAY_INFO(0, tmp_names, 0)
	ZEND_ARG_ARRAY_INFO(0, sizes, 0)
	ZEND_ARG_ARRAY_INFO(0, errors, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_request_getfilterservice, 0, 0, Phalcon\\Filter\\FilterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_getserverarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getfiltereddata, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, methodKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getpatchput, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, collection, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_zephir_init_properties_phalcon_http_request, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_method_entry) {
	PHP_ME(Phalcon_Http_Request, get, arginfo_phalcon_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getAcceptableContent, arginfo_phalcon_http_request_getacceptablecontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBasicAuth, arginfo_phalcon_http_request_getbasicauth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestAccept, arginfo_phalcon_http_request_getbestaccept, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestCharset, arginfo_phalcon_http_request_getbestcharset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestLanguage, arginfo_phalcon_http_request_getbestlanguage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHttpMethodParameterOverride, arginfo_phalcon_http_request_gethttpmethodparameteroverride, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPreferredIsoLocaleVariant, arginfo_phalcon_http_request_getpreferredisolocalevariant, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getClientAddress, arginfo_phalcon_http_request_getclientaddress, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getClientCharsets, arginfo_phalcon_http_request_getclientcharsets, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getContentType, arginfo_phalcon_http_request_getcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getDigestAuth, arginfo_phalcon_http_request_getdigestauth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getFilteredQuery, arginfo_phalcon_http_request_getfilteredquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getFilteredPatch, arginfo_phalcon_http_request_getfilteredpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getFilteredPost, arginfo_phalcon_http_request_getfilteredpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getFilteredPut, arginfo_phalcon_http_request_getfilteredput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHeader, arginfo_phalcon_http_request_getheader, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHeaders, arginfo_phalcon_http_request_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHttpHost, arginfo_phalcon_http_request_gethttphost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHTTPReferer, arginfo_phalcon_http_request_gethttpreferer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getJsonRawBody, arginfo_phalcon_http_request_getjsonrawbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getLanguages, arginfo_phalcon_http_request_getlanguages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getMethod, arginfo_phalcon_http_request_getmethod, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPatch, arginfo_phalcon_http_request_getpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPort, arginfo_phalcon_http_request_getport, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPost, arginfo_phalcon_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPut, arginfo_phalcon_http_request_getput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getQuery, arginfo_phalcon_http_request_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getRawBody, arginfo_phalcon_http_request_getrawbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getScheme, arginfo_phalcon_http_request_getscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServer, arginfo_phalcon_http_request_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServerAddress, arginfo_phalcon_http_request_getserveraddress, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServerName, arginfo_phalcon_http_request_getservername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getUploadedFiles, arginfo_phalcon_http_request_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getURI, arginfo_phalcon_http_request_geturi, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getUserAgent, arginfo_phalcon_http_request_getuseragent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, has, arginfo_phalcon_http_request_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasFiles, arginfo_phalcon_http_request_hasfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasHeader, arginfo_phalcon_http_request_hasheader, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPatch, arginfo_phalcon_http_request_haspatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPost, arginfo_phalcon_http_request_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPut, arginfo_phalcon_http_request_hasput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasQuery, arginfo_phalcon_http_request_hasquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasServer, arginfo_phalcon_http_request_hasserver, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isAjax, arginfo_phalcon_http_request_isajax, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isConnect, arginfo_phalcon_http_request_isconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isDelete, arginfo_phalcon_http_request_isdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isGet, arginfo_phalcon_http_request_isget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isHead, arginfo_phalcon_http_request_ishead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isMethod, arginfo_phalcon_http_request_ismethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isOptions, arginfo_phalcon_http_request_isoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPatch, arginfo_phalcon_http_request_ispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPost, arginfo_phalcon_http_request_ispost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPut, arginfo_phalcon_http_request_isput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPurge, arginfo_phalcon_http_request_ispurge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSecure, arginfo_phalcon_http_request_issecure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isStrictHostCheck, arginfo_phalcon_http_request_isstricthostcheck, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSoap, arginfo_phalcon_http_request_issoap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isTrace, arginfo_phalcon_http_request_istrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isValidHttpMethod, arginfo_phalcon_http_request_isvalidhttpmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, numFiles, arginfo_phalcon_http_request_numfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, setHttpMethodParameterOverride, arginfo_phalcon_http_request_sethttpmethodparameteroverride, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, setParameterFilters, arginfo_phalcon_http_request_setparameterfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, setStrictHostCheck, arginfo_phalcon_http_request_setstricthostcheck, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestQuality, arginfo_phalcon_http_request_getbestquality, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, getHelper, arginfo_phalcon_http_request_gethelper, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, hasFileHelper, arginfo_phalcon_http_request_hasfilehelper, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, getQualityHeader, arginfo_phalcon_http_request_getqualityheader, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, resolveAuthorizationHeaders, arginfo_phalcon_http_request_resolveauthorizationheaders, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, smoothFiles, arginfo_phalcon_http_request_smoothfiles, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request, getFilterService, arginfo_phalcon_http_request_getfilterservice, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Request, getServerArray, arginfo_phalcon_http_request_getserverarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Request, getFilteredData, arginfo_phalcon_http_request_getfiltereddata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPatchPut, arginfo_phalcon_http_request_getpatchput, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

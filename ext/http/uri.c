/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "http/uri.h"

#include <ext/standard/url.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"

/**
 * Phalcon\Http\Uri
 *
 *<code>
 *	$uri1 = new Uri('http://phalconphp.com/foo/bar/baz?var1=a&var2=1');

 *	$uri2 = $uri1->resolve('/last');
 *	echo $uri2->build(); // http://phalconphp.com/last?var1=a&var2=1


 *	$uri3 = $uri1->resolve('last');
 *	echo $uri3->build(); // http://phalconphp.com/foo/bar/baz/last?var1=a&var2=1

 *	$uri4 = new Uri(array(
 *	    'scheme' => 'https',
 *	    'host' => 'admin.example.com',
 *	    'user' => 'john',
 *	    'pass' => 'doe'
 *	));
 *	
 *	$uri5 = $uri1->resolve($uri4);
 *	echo $uri5->build(); // https://john:doe@admin.example.com/foo/bar/baz?var1=a&var2=1
 *</code>
 */
zend_class_entry *phalcon_http_uri_ce;

PHP_METHOD(Phalcon_Http_Uri, __construct);
PHP_METHOD(Phalcon_Http_Uri, __toString);
PHP_METHOD(Phalcon_Http_Uri, __unset);
PHP_METHOD(Phalcon_Http_Uri, __set);
PHP_METHOD(Phalcon_Http_Uri, __get);
PHP_METHOD(Phalcon_Http_Uri, __isset);
PHP_METHOD(Phalcon_Http_Uri, getParts);
PHP_METHOD(Phalcon_Http_Uri, build);
PHP_METHOD(Phalcon_Http_Uri, resolve);
PHP_METHOD(Phalcon_Http_Uri, extend);
PHP_METHOD(Phalcon_Http_Uri, extendQuery);
PHP_METHOD(Phalcon_Http_Uri, extendPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri_extend, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_uri_extendquery, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_uri_method_entry[] = {
	PHP_ME(Phalcon_Http_Uri, __construct, arginfo_phalcon_http_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, __unset, arginfo_phalcon_http_uri___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, __set, arginfo_phalcon_http_uri___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, __get, arginfo_phalcon_http_uri___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, __isset, arginfo_phalcon_http_uri___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, getParts, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, build, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, resolve, arginfo_phalcon_http_uri_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, extend, arginfo_phalcon_http_uri_extend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Uri, extendQuery, arginfo_phalcon_http_uri_extendquery, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Http\Uri initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Uri){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Uri, http_uri, phalcon_http_uri_method_entry, 0);

	zend_declare_property_null(phalcon_http_uri_ce, SL("_parts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Http\Uri constructor
 *
 * @param mixed $uri
 */
PHP_METHOD(Phalcon_Http_Uri, __construct){

	zval *uri = NULL, *parts = NULL, *query, *params;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);

	if (!uri || PHALCON_IS_EMPTY(uri)) {
		phalcon_update_property_empty_array(this_ptr, SL("_parts") TSRMLS_CC);
	} else if (Z_TYPE_P(uri) == IS_STRING) {
		PHALCON_CALL_FUNCTION(&parts, "parse_url", uri);
		if (phalcon_array_isset_string_fetch(&query, parts, SS("query"))) {
			PHALCON_INIT_VAR(params);
			Z_SET_ISREF_P(params);
			PHALCON_CALL_FUNCTION(NULL, "parse_str", query, params);
			Z_UNSET_ISREF_P(params);
			phalcon_array_update_string(&parts, SL("query"), params, PH_COPY);
		}

		phalcon_update_property_this(this_ptr, SL("_parts"), parts TSRMLS_CC);
	} else if (Z_TYPE_P(uri) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_parts"), uri TSRMLS_CC);
	} else if (Z_TYPE_P(uri) == IS_OBJECT && Z_OBJCE_P(uri) == phalcon_http_uri_ce) {
		phalcon_read_property(&parts, uri, SL("_parts"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_parts"), parts TSRMLS_CC);
	} else {
		phalcon_update_property_empty_array(this_ptr, SL("_parts") TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Magic __toString method returns uri
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Uri, __toString){

	PHALCON_RETURN_CALL_SELFW("build");
}

/**
 * Magic __unset method
 *
 * @param string $key
 */
PHP_METHOD(Phalcon_Http_Uri, __unset){

	zval *key;

	phalcon_fetch_params(0, 1, 0, &key);

	phalcon_unset_property_array(this_ptr, SL("_parts"), key TSRMLS_CC);
}

/**
 * Magic __set method
 *
 * @param string $key
 */
PHP_METHOD(Phalcon_Http_Uri, __set){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);

	phalcon_update_property_array(this_ptr, SL("_parts"), key, value TSRMLS_CC);
}

/**
 * Magic __get method
 *
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Http_Uri, __get){

	zval *key, *parts, *value = NULL;

	phalcon_fetch_params(0, 1, 0, &key);

	parts = phalcon_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY TSRMLS_CC);

	if (!phalcon_array_isset_fetch(&value, parts, key)) {
		 RETURN_NULL();
	}

	RETURN_ZVAL(value, 1, 0);
}

/**
 * Magic __isset method
 *
 * @param string $key
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Uri, __isset){

	zval *key, *parts;

	phalcon_fetch_params(0, 1, 0, &key);

	parts = phalcon_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY TSRMLS_CC);

	RETURN_BOOL(phalcon_array_isset(parts, key));
}

/**
 * Returns parts
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Uri, getParts){
	
	RETURN_MEMBER(this_ptr, "_parts");
}

/**
 * Returns uri
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Uri, build){

	zval *parts, *uri, *scheme, *host, *user, *pass, *port, *path, *query, *fragment, *tmp = NULL;

	PHALCON_MM_GROW();

	parts = phalcon_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(uri);

	if (phalcon_array_isset_string_fetch(&scheme, parts, SS("scheme")) && PHALCON_IS_NOT_EMPTY(scheme)) {
		if (phalcon_array_isset_string_fetch(&host, parts, SS("host")) && PHALCON_IS_NOT_EMPTY(host)) {
			if (phalcon_array_isset_string_fetch(&user, parts, SS("user")) && PHALCON_IS_NOT_EMPTY(user)) {
				if (phalcon_array_isset_string_fetch(&pass, parts, SS("pass")) && PHALCON_IS_NOT_EMPTY(pass)) {
					PHALCON_CONCAT_VSVSVSV(uri, scheme, "://", user, ":", pass, "@", host);
				} else {
					PHALCON_CONCAT_VSVSV(uri, scheme, "://", user, "@", host);
				}
			} else {
				PHALCON_CONCAT_VSV(uri, scheme, "://", host);
			}
		} else {
			PHALCON_CONCAT_VS(uri, scheme, ":");
		}
	}

	if (phalcon_array_isset_string_fetch(&port, parts, SS("port")) && PHALCON_IS_NOT_EMPTY(port)) {
		PHALCON_CONCAT_SV(uri, ":", port);
	}

	if (phalcon_array_isset_string_fetch(&path, parts, SS("path")) && PHALCON_IS_NOT_EMPTY(path)) {
		if (!phalcon_start_with_str(path, SL("/"))) {
			PHALCON_SCONCAT_SV(uri, "/", path);
		} else {
			PHALCON_INIT_NVAR(tmp);
			PHALCON_CONCAT_VV(tmp, uri, path);
			PHALCON_CPY_WRT(uri, tmp);
		}
	}

	if (phalcon_array_isset_string_fetch(&query, parts, SS("query")) && PHALCON_IS_NOT_EMPTY(query)) {
		PHALCON_INIT_NVAR(tmp);
		phalcon_http_build_query(tmp, query, "&" TSRMLS_CC);
		PHALCON_SCONCAT_SV(uri, "?", tmp);
	}

	if (phalcon_array_isset_string_fetch(&fragment, parts, SS("fragment")) && PHALCON_IS_NOT_EMPTY(fragment)) {
		PHALCON_SCONCAT_SV(uri, "#", fragment);
	}

	RETURN_CTOR(uri);
}

PHP_METHOD(Phalcon_Http_Uri, resolve){

	zval *uri, *self;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &uri);

	PHALCON_INIT_VAR(self);
	object_init_ex(self, phalcon_http_uri_ce);
	PHALCON_CALL_METHOD(NULL, self, "__construct", this_ptr);
	PHALCON_CALL_METHOD(NULL, self, "extend", uri);

	RETURN_CTOR(self);
}

PHP_METHOD(Phalcon_Http_Uri, extend){

	zval *uri, *self, *parts = NULL, *parts2 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &uri);

	PHALCON_CALL_SELF(&parts, "getParts");

	if (Z_TYPE_P(uri) != IS_OBJECT || Z_OBJCE_P(uri) != phalcon_http_uri_ce) {
		PHALCON_INIT_VAR(self);
		object_init_ex(self, phalcon_http_uri_ce);
		PHALCON_CALL_METHOD(NULL, self, "__construct", uri);

		PHALCON_CALL_METHOD(&parts2, self, "getParts");
	} else {
		PHALCON_CALL_METHOD(&parts2, self, "getParts");
	}

	phalcon_array_merge_recursive_n(&parts, parts2);

	phalcon_update_property_this(this_ptr, SL("_parts"), parts TSRMLS_CC);

	RETURN_THIS();
}

PHP_METHOD(Phalcon_Http_Uri, extendQuery){

	zval *params;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &params);


	RETURN_THIS();
}

PHP_METHOD(Phalcon_Http_Uri, extendPath){

	zval *path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &path);


	RETURN_THIS();
}

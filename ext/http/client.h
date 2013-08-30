
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/
#ifndef PHALCON_HTTP_CLIENT_H
#define PHALCON_HTTP_CLIENT_H

#include "php_phalcon.h"

#include "ext/standard/php_smart_str.h"

#ifdef PHALCON_USE_CURL
#include <curl/curl.h>
#include <curl/multi.h>
#endif

extern zend_class_entry *phalcon_http_client_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Client);

PHP_METHOD(Phalcon_Http_Client, __construct);
PHP_METHOD(Phalcon_Http_Client, setDI);
PHP_METHOD(Phalcon_Http_Client, getDI);
PHP_METHOD(Phalcon_Http_Client, setUrl);
PHP_METHOD(Phalcon_Http_Client, getUrl);
PHP_METHOD(Phalcon_Http_Client, setCookies);
PHP_METHOD(Phalcon_Http_Client, getCookies);
PHP_METHOD(Phalcon_Http_Client, setContentType);
PHP_METHOD(Phalcon_Http_Client, getContentType);
PHP_METHOD(Phalcon_Http_Client, setHeaders);
PHP_METHOD(Phalcon_Http_Client, getHeaders);
PHP_METHOD(Phalcon_Http_Client, setMethod);
PHP_METHOD(Phalcon_Http_Client, getMethod);
PHP_METHOD(Phalcon_Http_Client, setOptions);
PHP_METHOD(Phalcon_Http_Client, getOptions);
PHP_METHOD(Phalcon_Http_Client, setBody);
PHP_METHOD(Phalcon_Http_Client, getBody);
PHP_METHOD(Phalcon_Http_Client, setData);
PHP_METHOD(Phalcon_Http_Client, getData);
PHP_METHOD(Phalcon_Http_Client, setFiles);
PHP_METHOD(Phalcon_Http_Client, getFiles);
PHP_METHOD(Phalcon_Http_Client, setResponseHeader);
PHP_METHOD(Phalcon_Http_Client, getResponseHeaders);
PHP_METHOD(Phalcon_Http_Client, getResponseStatus);
PHP_METHOD(Phalcon_Http_Client, getResponseCookies);
PHP_METHOD(Phalcon_Http_Client, getResponseBody);
PHP_METHOD(Phalcon_Http_Client, send);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setcookies, 0, 0, 1)
	ZEND_ARG_INFO(0, cookies)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, content_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, request_method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, files)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setresponseheader, 0, 0, 2)
	ZEND_ARG_INFO(0, ch)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()


PHALCON_INIT_FUNCS(phalcon_http_client_method_entry){
	PHP_ME(Phalcon_Http_Client, __construct, arginfo_phalcon_http_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Client, setDI, arginfo_phalcon_http_client_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setUrl, arginfo_phalcon_http_client_seturl, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getUrl, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setCookies, arginfo_phalcon_http_client_setcookies, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getCookies, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setContentType, arginfo_phalcon_http_client_setcontenttype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getContentType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setHeaders, arginfo_phalcon_http_client_setheaders, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getHeaders, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setMethod, arginfo_phalcon_http_client_setmethod, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getMethod, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setOptions, arginfo_phalcon_http_client_setoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setBody, arginfo_phalcon_http_client_setbody, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getBody, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setData, arginfo_phalcon_http_client_setdata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setFiles, arginfo_phalcon_http_client_setfiles, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getFiles, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, setResponseHeader, arginfo_phalcon_http_client_setresponseheader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getResponseHeaders, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getResponseStatus, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getResponseCookies, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getResponseBody, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, send, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

#ifdef PHALCON_USE_CURL
#define CURLOPT_RETURNTRANSFER 19913
#define CURLOPT_BINARYTRANSFER 19914
#define PHP_CURL_STDOUT 0
#define PHP_CURL_FILE   1
#define PHP_CURL_USER   2
#define PHP_CURL_DIRECT 3
#define PHP_CURL_RETURN 4
#define PHP_CURL_ASCII  5
#define PHP_CURL_BINARY 6
#define PHP_CURL_IGNORE 7

extern int  le_curl;
#define le_curl_name "cURL handle"

typedef struct {
	zval            *func_name;
	zend_fcall_info_cache fci_cache;
	FILE            *fp;
	smart_str       buf;
	int             method;
	int             type;
	zval		*stream;
} php_curl_write;

typedef struct {
	zval            *func_name;
	zend_fcall_info_cache fci_cache;
	FILE            *fp;
	long            fd;
	int             method;
	zval		*stream;
} php_curl_read;

typedef struct {
	zval 		*func_name;
	zend_fcall_info_cache fci_cache;
	int    	        method;
} php_curl_progress;

typedef struct {
	php_curl_write *write;
	php_curl_write *write_header;
	php_curl_read  *read;
	zval           *passwd;
	zval           *std_err;
	php_curl_progress *progress;
} php_curl_handlers;

struct _php_curl_error  {
	char str[CURL_ERROR_SIZE + 1];
	int  no;
};

struct _php_curl_send_headers {
	char *str;
	size_t str_len;
};

struct _php_curl_free {
	zend_llist str;
	zend_llist post;
	zend_llist slist;
};

typedef struct {
	struct _php_curl_error   err;
	struct _php_curl_free    *to_free;
	struct _php_curl_send_headers header;
	void ***thread_ctx;
	CURL                    *cp;
	php_curl_handlers       *handlers;
	long                     id;
	unsigned int             uses;
	zend_bool                in_callback;
	zval                     *clone;
} php_curl;
#endif

#endif /* PHALCON_HTTP_CLIENT_H */

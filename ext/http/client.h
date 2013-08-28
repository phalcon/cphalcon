
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
#ifdef PHALCON_USE_PHP_CURL
extern zend_class_entry *phalcon_http_client_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Client);

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
PHP_METHOD(Phalcon_Http_Client, setData);
PHP_METHOD(Phalcon_Http_Client, getData);
PHP_METHOD(Phalcon_Http_Client, setFields);
PHP_METHOD(Phalcon_Http_Client, getFields);
PHP_METHOD(Phalcon_Http_Client, setfile);
PHP_METHOD(Phalcon_Http_Client, getfile);
PHP_METHOD(Phalcon_Http_Client, setFiles);
PHP_METHOD(Phalcon_Http_Client, getFiles);
/*
PHP_METHOD(Phalcon_Http_Client, setPostData);
PHP_METHOD(Phalcon_Http_Client, getPostData);
PHP_METHOD(Phalcon_Http_Client, setPostFields);
PHP_METHOD(Phalcon_Http_Client, getPostFields);
PHP_METHOD(Phalcon_Http_Client, setPostFiles);
PHP_METHOD(Phalcon_Http_Client, getPostFiles);
PHP_METHOD(Phalcon_Http_Client, setPutData);
PHP_METHOD(Phalcon_Http_Client, getPutData);
PHP_METHOD(Phalcon_Http_Client, setPutFile);
PHP_METHOD(Phalcon_Http_Client, getPutFile);
PHP_METHOD(Phalcon_Http_Client, setQueryData);
PHP_METHOD(Phalcon_Http_Client, getQueryData);
*/
PHP_METHOD(Phalcon_Http_Client, getResponseHeader);
PHP_METHOD(Phalcon_Http_Client, getResponseStatus);
PHP_METHOD(Phalcon_Http_Client, getResponseMessage);
PHP_METHOD(Phalcon_Http_Client, getResponseCookies);
PHP_METHOD(Phalcon_Http_Client, getResponseBody);


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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setfields, 0, 0, 1)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_setfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, files)
ZEND_END_ARG_INFO()


PHALCON_INIT_FUNCS(phalcon_http_client_method_entry){
	PHP_ME(Phalcon_Http_Client, setDI, arginfo_phalcon_http_client_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Client, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

#endif
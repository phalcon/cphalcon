
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_urlinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_UrlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_urlinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBaseUri, arginfo_phalcon_mvc_urlinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBaseUri, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBasePath, arginfo_phalcon_mvc_urlinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBasePath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, get, arginfo_phalcon_mvc_urlinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, path, arginfo_phalcon_mvc_urlinterface_path)
	PHP_FE_END
};


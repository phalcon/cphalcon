
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

extern zend_class_entry *phalcon_http_request_fileinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_request_fileinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, __construct, arginfo_phalcon_http_request_fileinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getTempName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, moveTo, arginfo_phalcon_http_request_fileinterface_moveto)
	PHP_FE_END
};


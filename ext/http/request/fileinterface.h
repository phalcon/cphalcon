
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

#ifndef PHALCON_HTTP_REQUEST_FILEINTERFACE_H
#define PHALCON_HTTP_REQUEST_FILEINTERFACE_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_http_request_fileinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_REQUEST_FILEINTERFACE_H */

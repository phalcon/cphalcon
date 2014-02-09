
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

#include "http/request/fileinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_http_request_fileinterface_ce;

static const zend_function_entry phalcon_http_request_fileinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getTempName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getRealType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, moveTo, arginfo_phalcon_http_request_fileinterface_moveto)
	PHP_FE_END
};

/**
 * Phalcon\Http\Request\FileInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http\\Request, FileInterface, http_request_fileinterface, phalcon_http_request_fileinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the file size of the uploaded file
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, getSize);

/**
 * Returns the real name of the uploaded file
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, getName);

/**
 * Returns the temporal name of the uploaded file
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, getTempName);

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, getType);

/**
 * Gets the real mime type of the upload file using finfo
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, getRealType);

/**
 * Move the temporary file to a destination
 *
 * @param string $destination
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, moveTo);

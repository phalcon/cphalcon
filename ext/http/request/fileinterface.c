
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Http\Request\FileInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http\\Request, FileInterface, http_request_fileinterface, phalcon_http_request_fileinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Http\Request\FileInterface constructor
 *
 * @param array $file
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, __construct);
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
 * Move the temporary file to a destination
 *
 * @param string $destination
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_Request_FileInterface, moveTo);

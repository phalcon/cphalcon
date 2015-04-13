
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Http\Request\FileInterface
 *
 * Interface for Phalcon\Http\Request\File
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request_FileInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http\\Request, FileInterface, phalcon, http_request_fileinterface, phalcon_http_request_fileinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Http\Request\FileInterface constructor
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, __construct);

/**
 * Returns the file size of the uploaded file
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getSize);

/**
 * Returns the real name of the uploaded file
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getName);

/**
 * Returns the temporal name of the uploaded file
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getTempName);

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getType);

/**
 * Gets the real mime type of the upload file using finfo
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getRealType);

/**
 * Move the temporary file to a destination
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, moveTo);



#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
 * Returns the error if any
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getError);
/**
 * Returns the real name of the uploaded file
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getName);
/**
 * Gets the real mime type of the upload file using finfo
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getRealType);
/**
 * Returns the file size of the uploaded file
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, getSize);
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
 * Move the temporary file to a destination
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Request_FileInterface, moveTo);

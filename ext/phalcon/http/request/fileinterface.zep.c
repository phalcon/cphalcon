
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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


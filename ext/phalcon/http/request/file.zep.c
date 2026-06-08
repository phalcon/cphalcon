
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *```php
 * use Phalcon\Mvc\Controller;
 *
 * class PostsController extends Controller
 * {
 *     public function uploadAction()
 *     {
 *         // Check if the user has uploaded files
 *         if ($this->request->hasFiles() == true) {
 *             // Print the real file names and their sizes
 *             foreach ($this->request->getUploadedFiles() as $file) {
 *                 echo $file->getName(), " ", $file->getSize(), "\n";
 *             }
 *         }
 *     }
 * }
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request_File)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Request, File, phalcon, http_request_file, phalcon_http_request_file_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_http_request_file_ce, SL("error"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_file_ce, SL("extension"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_file_ce, SL("key"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_file_ce, SL("name"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_http_request_file_ce, SL("realType"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_http_request_file_ce, SL("size"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_file_ce, SL("tmpName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_request_file_ce, SL("type"), "", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_http_request_file_ce, 1, phalcon_http_request_fileinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Http\Request\File constructor
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zval *file_param = NULL, key_zv, name, _4, _5, _6, _7, _8, _0$$3, _1$$3, _2$$4, _3$$4;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(file, file_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	file_param = ZEND_CALL_ARG(execute_data, 1);
	ZEPHIR_OBS_COPY_OR_DUP(&file, file_param);
	if (!key) {
		key = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&key_zv);
		ZVAL_STR(&key_zv, key);
	} else {
		zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	}
	zephir_memory_observe(&name);
	if (zephir_array_isset_string_fetch(&name, &file, SL("name"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "PATHINFO_EXTENSION");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "defined", NULL, 130, &_0$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZVAL_LONG(&_2$$4, 4);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "pathinfo", NULL, 167, &name, &_2$$4);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("extension"), &_3$$4);
		}
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "tmp_name");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getarrval", NULL, 0, &file, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("tmpName"), &_4);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "size");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getarrval", NULL, 0, &file, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("size"), &_6);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "type");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &file, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_7);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "error");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getarrval", NULL, 0, &file, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_8);
	if (!(ZEPHIR_IS_EMPTY(&key_zv))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("key"), &key_zv);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Http_Request_File, getError)
{

	RETURN_MEMBER_TYPED(getThis(), "error", IS_LONG);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getExtension)
{

	RETURN_MEMBER_TYPED(getThis(), "extension", IS_STRING);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getKey)
{

	RETURN_MEMBER_TYPED(getThis(), "key", IS_STRING);
}

/**
 * Returns the real name of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

/**
 * Gets the real mime type of the upload file using finfo
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getRealType)
{
	zval finfo, mime, _0, _1$$3, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&finfo);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("realType"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZVAL_LONG(&_1$$3, 16);
		ZEPHIR_CALL_FUNCTION(&finfo, "finfo_open", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&finfo)) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("tmpName"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 0, &finfo, &_2$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 0, &finfo);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("realType"), &mime);
		}
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "realType", IS_STRING);
}

/**
 * Returns the file size of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getSize)
{

	RETURN_MEMBER_TYPED(getThis(), "size", IS_LONG);
}

/**
 * Returns the temporary name of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getTempName)
{

	RETURN_MEMBER_TYPED(getThis(), "tmpName", IS_STRING);
}

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 */
PHP_METHOD(Phalcon_Http_Request_File, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_STRING);
}

/**
 * Checks whether the file has been uploaded via Post.
 */
PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile)
{
	zend_bool _0;
	zval name, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&name);
	zephir_read_property(&name, this_ptr, ZEND_STRL("tmpName"), PH_NOISY_CC);
	_0 = !(ZEPHIR_IS_EMPTY(&name));
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_uploaded_file", NULL, 34, &name);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	RETURN_MM_BOOL(_0);
}

/**
 * Moves the temporary file to a destination within the application
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval destination_zv, _0;
	zend_string *destination = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(destination)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&destination_zv);
	ZVAL_STR_COPY(&destination_zv, destination);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tmpName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("move_uploaded_file", NULL, 0, &_0, &destination_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Http_Request_File, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
}



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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "mvc/collection/gridfs.h"
#include "mvc/collection.h"
#include "mvc/collection/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/variables.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Mvc\Collection\GridFS
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
zend_class_entry *phalcon_mvc_collection_gridfs_ce;

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, storeFile);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, storeBytes);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, save);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, saveBytes);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, create);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, createBytes);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, update);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, updateBytes);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, delete);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, drop);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, getFile);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, getBytes);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_gridfs_storefile, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, metadata)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_gridfs_storebytes, 0, 0, 1)
	ZEND_ARG_INFO(0, bytes)
	ZEND_ARG_INFO(0, metadata)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_gridfs_write, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_gridfs_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection_GridFS, storeFile, arginfo_phalcon_mvc_collection_gridfs_storefile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, storeBytes, arginfo_phalcon_mvc_collection_gridfs_storebytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, saveBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, create, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, createBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, update, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, updateBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, drop, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, getFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, getBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, write, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\GridFS initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_GridFS){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Collection, GridFS, mvc_collection_gridfs, phalcon_mvc_collection_ce, phalcon_mvc_collection_gridfs_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, storeFile){

	zval *filename, *metadata = NULL, *options = NULL;
	zval *mongo_id = NULL, *source = NULL, *connection = NULL, *grid_fs = NULL;
	zval *sha1 = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &filename, &metadata, &options);

	if (!metadata) {
		PHALCON_INIT_VAR(metadata);
		array_init_size(metadata, 1);
	} else {
		PHALCON_SEPARATE_PARAM(metadata);

		if (Z_TYPE_P(metadata) != IS_ARRAY) {
			PHALCON_INIT_NVAR(metadata);
			array_init_size(metadata, 1);
		}
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init_size(options, 1);
	} else {
		PHALCON_SEPARATE_PARAM(options);

		if (Z_TYPE_P(options) != IS_ARRAY) {
			PHALCON_INIT_NVAR(options);
			array_init_size(options, 1);
		}
	}

	phalcon_array_update_string_long(&options, SL("w"), 0, 0);

	PHALCON_CALL_SELF(&mongo_id, "getid");

	convert_to_string_ex(&mongo_id);

	if (PHALCON_IS_EMPTY(mongo_id)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	phalcon_array_update_string(&metadata, SL("mongo_id"), mongo_id, PH_COPY);

	PHALCON_CALL_METHOD(&status, grid_fs, "remove", metadata, options);

	PHALCON_CALL_FUNCTION(&sha1, "sha1_file", filename);

	phalcon_array_update_string(&metadata, SL("sha1"), sha1, PH_COPY);

	if (PHALCON_IS_TRUE(status)){
		PHALCON_CALL_METHOD(&status, grid_fs, "storeFile", filename, metadata, options);

		if (zend_is_true(status)) {
			RETURN_MM_TRUE;
		}
	}

	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, storeBytes){

	zval *bytes, *metadata = NULL, *options = NULL;
	zval *mongo_id = NULL, *source = NULL, *connection = NULL, *grid_fs = NULL;
	zval *sha1 = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &bytes, &metadata, &options);

	if (!metadata) {
		PHALCON_INIT_NVAR(metadata);
		array_init_size(metadata, 1);
	} else {
		PHALCON_SEPARATE_PARAM(metadata);

		if (Z_TYPE_P(metadata) != IS_ARRAY) {
			PHALCON_INIT_NVAR(metadata);
			array_init_size(metadata, 1);
		}
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init_size(options, 1);
	} else {
		PHALCON_SEPARATE_PARAM(options);

		if (Z_TYPE_P(options) != IS_ARRAY) {
			PHALCON_INIT_NVAR(options);
			array_init_size(options, 1);
		}
	}

	phalcon_array_update_string_long(&options, SL("w"), 0, 0);

	PHALCON_CALL_SELF(&mongo_id, "getid");

	convert_to_string_ex(&mongo_id);

	if (PHALCON_IS_EMPTY(mongo_id)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	phalcon_array_update_string(&metadata, SL("mongo_id"), mongo_id, PH_COPY);

	PHALCON_CALL_METHOD(&status, grid_fs, "remove", metadata, options);

	PHALCON_CALL_FUNCTION(&sha1, "sha1", bytes);

	phalcon_array_update_string(&metadata, SL("sha1"), sha1, PH_COPY);

	if (PHALCON_IS_TRUE(status)){
		PHALCON_CALL_METHOD(&status, grid_fs, "storeBytes", bytes, metadata, options);

		if (zend_is_true(status)) {
			RETURN_MM_TRUE;
		}
	}

	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, save){

	zval *filedata = NULL, *arr = NULL, *white_list = NULL, *mode = NULL, *isBytes = NULL;
	zval *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 5, &filedata, &arr, &white_list, &mode, &isBytes);

	if (!filedata) {
		filedata = PHALCON_GLOBAL(z_null);
	}

	if (!arr) {
		arr = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!mode) {
		mode = PHALCON_GLOBAL(z_null);
	}

	if (!isBytes) {
		isBytes = PHALCON_GLOBAL(z_false);
	}

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "save", arr, white_list, mode);

	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (zend_is_true(filedata)) {
		if (PHALCON_IS_TRUE(isBytes)) {
			PHALCON_CALL_SELF(&status, "storeBytes", filedata);
		} else {
			PHALCON_CALL_SELF(&status, "storeFile", filedata);
		}
	}

	RETURN_CTOR(status);
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, saveBytes){

	zval *filedata = NULL, *arr = NULL, *white_list = NULL, *mode = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &filedata, &arr, &white_list, &mode);

	if (!arr) {
		arr = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!mode) {
		mode = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_SELF("save", filedata, arr, white_list, mode, PHALCON_GLOBAL(z_true));

	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, create){

	zval *filedata = NULL, *data = NULL, *white_list = NULL, *isBytes = NULL;
	zval *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &filedata, &data, &white_list, &isBytes);

	if (!filedata) {
		filedata = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!isBytes) {
		isBytes = PHALCON_GLOBAL(z_false);
	}

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "create", data, white_list);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (zend_is_true(filedata)) {
		if (PHALCON_IS_TRUE(isBytes)) {
			PHALCON_CALL_SELF(&status, "storeBytes", filedata);
		} else {
			PHALCON_CALL_SELF(&status, "storeFile", filedata);
		}
	}

	RETURN_CTOR(status);
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, createBytes){

	zval *filedata = NULL, *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &filedata, &data, &white_list);

	if (!filedata) {
		filedata = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "create", filedata, data, white_list, PHALCON_GLOBAL(z_true), PHALCON_GLOBAL(z_true));
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, update){

	zval *filedata = NULL, *data = NULL, *white_list = NULL, *isBytes = NULL;
	zval *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &filedata, &data, &white_list, &isBytes);

	if (!filedata) {
		filedata = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!isBytes) {
		isBytes = PHALCON_GLOBAL(z_false);
	}

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "update", data, white_list);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (zend_is_true(filedata)) {
		if (PHALCON_IS_TRUE(isBytes)) {
			PHALCON_CALL_SELF(&status, "storeBytes", filedata);
		} else {
			PHALCON_CALL_SELF(&status, "storeFile", filedata);
		}
	}

	RETURN_CTOR(status);
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, updateBytes){

	zval *filedata = NULL, *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &filedata, &data, &white_list);

	if (!filedata) {
		filedata = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "update", filedata, data, white_list, PHALCON_GLOBAL(z_true), PHALCON_GLOBAL(z_true));
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, delete){

	zval *mongo_id = NULL, *source = NULL, *connection = NULL, *grid_fs = NULL, *criteria, *options;
	zval *status = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_SELF(&mongo_id, "getid");

	convert_to_string_ex(&mongo_id);

	if (PHALCON_IS_EMPTY(mongo_id)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "delete");
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	PHALCON_INIT_VAR(criteria);
	array_init_size(criteria, 1);
	phalcon_array_update_string(&criteria, SL("mongo_id"), mongo_id, PH_COPY);

	PHALCON_INIT_VAR(options);
	array_init_size(options, 1);
	phalcon_array_update_string_long(&options, SL("w"), 0, 0);

	PHALCON_RETURN_CALL_METHOD(grid_fs, "remove", criteria, options);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, drop){

	zval *class_name, *collection, *source = NULL, *connection = NULL, *mongo_collection = NULL, *grid_fs = NULL;
	zval *status = NULL, *ok = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);

	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_INIT_NVAR(ok);
	ZVAL_BOOL(ok, 0);

	PHALCON_CALL_METHOD(&source, collection, "getsource");

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");

	PHALCON_CALL_METHOD(&mongo_collection, connection, "selectcollection", source);
	if (Z_TYPE_P(mongo_collection) == IS_OBJECT) {
		PHALCON_CALL_METHOD(&status, mongo_collection, "drop");

		if (phalcon_array_isset_string(status, SS("ok"))) {
			PHALCON_OBS_NVAR(ok);
			phalcon_array_fetch_string(&ok, status, SL("ok"), PH_NOISY);
		}
	}

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) == IS_OBJECT) {
		PHALCON_CALL_METHOD(&status, grid_fs, "drop");
		if (phalcon_array_isset_string(status, SS("ok"))) {
			PHALCON_OBS_NVAR(ok);
			phalcon_array_fetch_string(&ok, status, SL("ok"), PH_NOISY);
		}
	}

	if (zend_is_true(ok)) {
		RETURN_MM_TRUE;
	}

	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, getFile){

	zval *mongo_id = NULL, *source = NULL, *connection = NULL, *grid_fs = NULL, *criteria;

	PHALCON_MM_GROW();

	PHALCON_CALL_SELF(&mongo_id, "getid");

	convert_to_string_ex(&mongo_id);

	if (PHALCON_IS_EMPTY(mongo_id)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	PHALCON_INIT_VAR(criteria);
	array_init_size(criteria, 1);
	phalcon_array_update_string(&criteria, SL("mongo_id"), mongo_id, PH_COPY);

	PHALCON_RETURN_CALL_METHOD(grid_fs, "findOne", criteria);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, getBytes){

	zval *file = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&file, this_ptr, "getfile");

	if (Z_TYPE_P(file) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(file, "getbytes");
	} else {
		RETURN_MM_FALSE;
	}

	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, write){

	zval *filename, *file = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &filename);

	PHALCON_CALL_METHOD(&file, this_ptr, "getfile");

	if (Z_TYPE_P(file) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(file, "write", filename);
	} else {
		RETURN_MM_FALSE;
	}

	RETURN_MM();
}

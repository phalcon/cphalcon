
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

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, store);
PHP_METHOD(Phalcon_Mvc_Collection_GridFS, remove);
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
	ZEND_ARG_INFO(0, isBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_gridfs_write, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_gridfs_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection_GridFS, store, arginfo_phalcon_mvc_collection_gridfs_storefile, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection_GridFS, remove, NULL, ZEND_ACC_PROTECTED)
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
	PHP_ME(Phalcon_Mvc_Collection_GridFS, write, arginfo_phalcon_mvc_collection_gridfs_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\GridFS initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_GridFS){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Collection, GridFS, mvc_collection_gridfs, phalcon_mvc_collection_ce, phalcon_mvc_collection_gridfs_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_gridfs_ce, SL("sha1"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_gridfs_ce, SL("md5"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, store){

	zval *file, *metadata = NULL, *options = NULL, *isBytes = NULL;
	zval *mongo_id = NULL, *source = NULL, *files_source;
	zval *connection = NULL, *mongo_collection = NULL, *grid_fs = NULL;
	zval *sha1, *md5, *criteria, *operation, *field, *value, *new_object;
	zval *status = NULL, *ok, *exist;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &file, &metadata, &options, &isBytes);

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

	if (!isBytes) {
		isBytes = PHALCON_GLOBAL(z_false);
	}

	phalcon_array_update_string_long(&options, SL("w"), 0, PH_COPY);

	PHALCON_CALL_SELF(&mongo_id, "getid");

	if (!zend_is_true(mongo_id)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_INIT_VAR(files_source);
	PHALCON_CONCAT_VS(files_source, source, ".files");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&mongo_collection, connection, "selectcollection", files_source);
	if (Z_TYPE_P(mongo_collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo collection");
		return;
	}

	sha1 = phalcon_fetch_nproperty_this(this_ptr, SL("sha1"), PH_NOISY TSRMLS_CC);
	md5 = phalcon_fetch_nproperty_this(this_ptr, SL("md5"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(criteria);
	array_init_size(criteria, 3);

	phalcon_array_update_string(&criteria, SL("md5"), md5, PH_COPY);
	phalcon_array_update_string(&criteria, SL("sha1"), sha1, PH_COPY);

	PHALCON_INIT_VAR(operation);
	ZVAL_STRING(operation, "$gte", 1);

	PHALCON_INIT_VAR(field);
	ZVAL_STRING(field, "use", 1);

	PHALCON_INIT_VAR(value);
	ZVAL_LONG(value, 1)

	phalcon_array_update_multi_2(&criteria, field, operation, value, PH_COPY);

	PHALCON_INIT_NVAR(operation);
	ZVAL_STRING(operation, "$inc", 1);

	PHALCON_INIT_VAR(new_object);
	array_init_size(new_object, 1);

	phalcon_array_update_multi_2(&new_object, operation, field, value, PH_COPY);
	
	PHALCON_CALL_METHOD(&status, mongo_collection, "update", criteria, new_object);

	if (phalcon_array_isset_string_fetch(&ok, status, SS("ok"))) {
		if (zend_is_true(ok)) {
			if (phalcon_array_isset_string_fetch(&exist, status, SS("updatedExisting"))) {
				if (zend_is_true(exist)) {
					RETURN_MM_TRUE;
				}
			}
		} else {
			RETURN_MM_FALSE;
		}
	}

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	phalcon_array_update_string(&metadata, SL("sha1"), sha1, PH_COPY);
	phalcon_array_update_string(&metadata, SL("use"), value, PH_COPY);

	if (zend_is_true(isBytes)) {
		PHALCON_CALL_METHOD(&status, grid_fs, "storebytes", file, metadata, options);
	} else {
		PHALCON_CALL_METHOD(&status, grid_fs, "storefile", file, metadata, options);
	}

	if (zend_is_true(status)) {
		RETURN_MM_TRUE;
	}

	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, remove){

	zval *sha1 = NULL, *md5 = NULL, *source = NULL, *files_source;
	zval *connection = NULL, *mongo_collection = NULL;
	zval *criteria, *operation, *field, *value, *new_object;
	zval *status = NULL, *ok, *exist, *options, *grid_fs = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &sha1, &md5);

	if (!sha1) {
		sha1 = phalcon_fetch_nproperty_this(this_ptr, SL("sha1"), PH_NOISY TSRMLS_CC);
	}

	if (!md5) {
		md5 = phalcon_fetch_nproperty_this(this_ptr, SL("md5"), PH_NOISY TSRMLS_CC);
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_INIT_VAR(files_source);
	PHALCON_CONCAT_VS(files_source, source, ".files");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&mongo_collection, connection, "selectcollection", files_source);
	if (Z_TYPE_P(mongo_collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo collection");
		return;
	}

	PHALCON_INIT_VAR(criteria);
	array_init_size(criteria, 2);

	phalcon_array_update_string(&criteria, SL("md5"), md5, PH_COPY);
	phalcon_array_update_string(&criteria, SL("sha1"), sha1, PH_COPY);

	PHALCON_INIT_VAR(operation);
	ZVAL_STRING(operation, "$inc", 1);

	PHALCON_INIT_VAR(field);
	ZVAL_STRING(field, "use", 1);

	PHALCON_INIT_VAR(value);
	ZVAL_LONG(value, -1)

	PHALCON_INIT_VAR(new_object);
	array_init_size(new_object, 1);

	phalcon_array_update_multi_2(&new_object, operation, field, value, PH_COPY);
	
	PHALCON_CALL_METHOD(&status, mongo_collection, "update", criteria, new_object);

	if (phalcon_array_isset_string_fetch(&ok, status, SS("ok"))) {
		if (zend_is_true(ok)) {
			if (phalcon_array_isset_string_fetch(&exist, status, SS("updatedExisting"))) {
				if (!zend_is_true(exist)) {
					RETURN_MM_FALSE;
				}
			}
		} else {
			RETURN_MM_FALSE;
		}
	}

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	PHALCON_INIT_NVAR(criteria);
	array_init_size(criteria, 3);

	phalcon_array_update_string(&criteria, SL("sha1"), sha1, PH_COPY);
	phalcon_array_update_string(&criteria, SL("md5"), md5, PH_COPY);

	PHALCON_INIT_NVAR(operation);
	ZVAL_STRING(operation, "$lte", 1);

	PHALCON_INIT_NVAR(value);
	ZVAL_LONG(value, 0)

	phalcon_array_update_multi_2(&criteria, field, operation, value, PH_COPY);

	PHALCON_INIT_VAR(options);
	array_init_size(options, 1);

	phalcon_array_update_string_long(&options, SL("w"), 0, PH_COPY);

	PHALCON_RETURN_CALL_METHOD(grid_fs, "remove", criteria, options);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, save){

	zval *filename, *arr = NULL, *white_list = NULL, *mode = NULL;
	zval *old_sha1, *old_md5, *sha1 = NULL, *md5 = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &filename, &arr, &white_list, &mode);

	if (!arr) {
		arr = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!mode) {
		mode = PHALCON_GLOBAL(z_null);
	}

	if (zend_is_true(filename)) {
		PHALCON_OBS_VAR(old_sha1);
		phalcon_read_property_this(&old_sha1, this_ptr, SL("sha1"), PH_NOISY TSRMLS_CC);

		PHALCON_OBS_VAR(old_md5);
		phalcon_read_property_this(&old_md5, this_ptr, SL("md5"), PH_NOISY TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&sha1, "sha1_file", filename);
		PHALCON_CALL_FUNCTION(&md5, "md5_file", filename);

		phalcon_update_property_this(this_ptr, SL("sha1"), sha1 TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("md5"), md5 TSRMLS_CC);
	}

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "save", arr, white_list, mode);

	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (zend_is_true(filename)) {
		PHALCON_CALL_SELF(&status, "store", filename);
		PHALCON_CALL_SELF(NULL, "remove", old_sha1, old_md5);
	}

	RETURN_CTOR(status);
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, saveBytes){

	zval *bytes, *arr = NULL, *white_list = NULL, *mode = NULL;
	zval *old_sha1, *old_md5, *sha1 = NULL, *md5 = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &bytes, &arr, &white_list, &mode);

	if (!arr) {
		arr = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!mode) {
		mode = PHALCON_GLOBAL(z_null);
	}

	if (zend_is_true(bytes)) {
		old_sha1 = phalcon_fetch_nproperty_this(this_ptr, SL("sha1"), PH_NOISY TSRMLS_CC);
		old_md5 = phalcon_fetch_nproperty_this(this_ptr, SL("md5"), PH_NOISY TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&sha1, "sha1", bytes);
		PHALCON_CALL_FUNCTION(&md5, "md5", bytes);

		phalcon_update_property_this(this_ptr, SL("sha1"), sha1 TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("md5"), md5 TSRMLS_CC);
	}

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "save", arr, white_list, mode);

	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (zend_is_true(bytes)) {
		PHALCON_CALL_SELF(&status, "store", bytes, PHALCON_GLOBAL(z_null), PHALCON_GLOBAL(z_null), PHALCON_GLOBAL(z_true));
		if (zend_is_true(old_sha1)) {
			PHALCON_CALL_SELF(NULL, "remove", old_sha1, old_md5);
		}
	}

	RETURN_CTOR(status);
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, create){

	zval *filename = NULL, *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &filename, &data, &white_list);

	if (!filename) {
		filename = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "save", filename, data, white_list, PHALCON_GLOBAL(z_true));
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, createBytes){

	zval *bytes = NULL, *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &bytes, &data, &white_list);

	if (!bytes) {
		bytes = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "savebytes", bytes, data, white_list, PHALCON_GLOBAL(z_true));
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, update){

	zval *filename = NULL, *data = NULL, *white_list = NULL, *isBytes = NULL;
	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &filename, &data, &white_list, &isBytes);

	if (!filename) {
		filename = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "save", filename, data, white_list, PHALCON_GLOBAL(z_false));
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, updateBytes){

	zval *bytes = NULL, *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &bytes, &data, &white_list);

	if (!bytes) {
		bytes = PHALCON_GLOBAL(z_null);
	}

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "saveBytes", bytes, data, white_list, PHALCON_GLOBAL(z_false));
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Collection_GridFS, delete){

	zval *status = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_PARENT(&status, phalcon_mvc_collection_gridfs_ce, this_ptr, "delete");
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "remove");
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

	zval *mongo_id = NULL, *source = NULL, *connection = NULL, *grid_fs = NULL;
	zval *sha1, *md5, *criteria;
	PHALCON_MM_GROW();

	PHALCON_CALL_SELF(&mongo_id, "getid");

	if (!zend_is_true(mongo_id)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&grid_fs, connection, "getgridfs", source);
	if (Z_TYPE_P(grid_fs) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo GridFS");
		return;
	}

	sha1 = phalcon_fetch_nproperty_this(this_ptr, SL("sha1"), PH_NOISY TSRMLS_CC);
	md5 = phalcon_fetch_nproperty_this(this_ptr, SL("md5"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(criteria);
	array_init_size(criteria, 2);

	phalcon_array_update_string(&criteria, SL("md5"), md5, PH_COPY);
	phalcon_array_update_string(&criteria, SL("sha1"), sha1, PH_COPY);

	PHALCON_RETURN_CALL_METHOD(grid_fs, "findone", criteria);
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

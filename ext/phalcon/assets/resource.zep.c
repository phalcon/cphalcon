
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 *
 *<code>
 * $resource = new \Phalcon\Assets\Resource('js', 'javascripts/jquery.js');
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Resource, phalcon, assets_resource, phalcon_assets_resource_method_entry, 0);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_local"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Assets_Resource, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Phalcon_Assets_Resource, getPath) {


	RETURN_MEMBER(this_ptr, "_path");

}

PHP_METHOD(Phalcon_Assets_Resource, getLocal) {


	RETURN_MEMBER(this_ptr, "_local");

}

PHP_METHOD(Phalcon_Assets_Resource, getFilter) {


	RETURN_MEMBER(this_ptr, "_filter");

}

PHP_METHOD(Phalcon_Assets_Resource, getAttributes) {


	RETURN_MEMBER(this_ptr, "_attributes");

}

PHP_METHOD(Phalcon_Assets_Resource, getSourcePath) {


	RETURN_MEMBER(this_ptr, "_sourcePath");

}

PHP_METHOD(Phalcon_Assets_Resource, getTargetPath) {


	RETURN_MEMBER(this_ptr, "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Resource, getTargetUri) {


	RETURN_MEMBER(this_ptr, "_targetUri");

}

/**
 * Phalcon\Assets\Resource constructor
 *
 * @param string type
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, __construct) {

	zend_bool local, filter;
	zval *type_param = NULL, *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes = NULL;
	zval *type = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &type_param, &path_param, &local_param, &filter_param, &attributes);

	zephir_get_strval(type, type_param);
	zephir_get_strval(path, path_param);
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_local"), local ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_filter"), filter ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the resource's type
 */
PHP_METHOD(Phalcon_Assets_Resource, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the resource's path
 */
PHP_METHOD(Phalcon_Assets_Resource, setPath) {

	zval *path_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets if the resource is local or external
 */
PHP_METHOD(Phalcon_Assets_Resource, setLocal) {

	zval *local_param = NULL;
	zend_bool local;

	zephir_fetch_params(0, 1, 0, &local_param);

	local = zephir_get_boolval(local_param);


	zephir_update_property_this(this_ptr, SL("_local"), local ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets if the resource must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Resource, setFilter) {

	zval *filter_param = NULL;
	zend_bool filter;

	zephir_fetch_params(0, 1, 0, &filter_param);

	filter = zephir_get_boolval(filter_param);


	zephir_update_property_this(this_ptr, SL("_filter"), filter ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, setAttributes) {

	zval *attributes_param = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(attributes, attributes_param);


	zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri) {

	zval *targetUri_param = NULL;
	zval *targetUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	zephir_get_strval(targetUri, targetUri_param);


	zephir_update_property_this(this_ptr, SL("_targetUri"), targetUri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the resource's source path
 */
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath) {

	zval *sourcePath_param = NULL;
	zval *sourcePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	zephir_get_strval(sourcePath, sourcePath_param);


	zephir_update_property_this(this_ptr, SL("_sourcePath"), sourcePath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the resource's target path
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath) {

	zval *targetPath_param = NULL;
	zval *targetPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	zephir_get_strval(targetPath, targetPath_param);


	zephir_update_property_this(this_ptr, SL("_targetPath"), targetPath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the content of the resource as an string
 * Optionally a base path where the resource is located can be set
 */
PHP_METHOD(Phalcon_Assets_Resource, getContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, *sourcePath = NULL, *completePath, *content, *_0, *_1 = NULL, *_2 = NULL;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	} else {
		zephir_get_strval(basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(sourcePath);
	zephir_read_property_this(&sourcePath, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(sourcePath)) {
		ZEPHIR_OBS_NVAR(sourcePath);
		zephir_read_property_this(&sourcePath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(completePath);
	ZEPHIR_CONCAT_VV(completePath, basePath, sourcePath);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		if (!((zephir_file_exists(completePath TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SVS(_2, "Resource's content for '", completePath, "' cannot be read");
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "phalcon/assets/resource.zep", 169 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(content);
	zephir_file_get_contents(content, completePath TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(content)) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_assets_exception_ce);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Resource's content for '", completePath, "' cannot be read");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/assets/resource.zep", 179 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(content);

}

/**
 * Returns the real target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri) {

	zval *targetUri = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(targetUri);
	zephir_read_property_this(&targetUri, this_ptr, SL("_targetUri"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(targetUri)) {
		ZEPHIR_OBS_NVAR(targetUri);
		zephir_read_property_this(&targetUri, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(targetUri);

}

/**
 * Returns the complete location where the resource is located
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, *sourcePath = NULL, *_0, *_1;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	} else {
		zephir_get_strval(basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(sourcePath);
	zephir_read_property_this(&sourcePath, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(sourcePath)) {
		ZEPHIR_OBS_NVAR(sourcePath);
		zephir_read_property_this(&sourcePath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VV(_1, basePath, sourcePath);
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 25, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(sourcePath);

}

/**
 * Returns the complete location where the resource must be written
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, *targetPath = NULL, *completePath, *_0;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	} else {
		zephir_get_strval(basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(targetPath);
	zephir_read_property_this(&targetPath, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(targetPath)) {
		ZEPHIR_OBS_NVAR(targetPath);
		zephir_read_property_this(&targetPath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(completePath);
		ZEPHIR_CONCAT_VV(completePath, basePath, targetPath);
		if ((zephir_file_exists(completePath TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 25, completePath);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(completePath);
	}
	RETURN_CCTOR(targetPath);

}


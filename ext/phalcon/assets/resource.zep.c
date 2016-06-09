
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

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_local"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array | null
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getPath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_path");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getLocal) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_local");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getFilter) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_filter");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getAttributes) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_attributes");

}

PHP_METHOD(Phalcon_Assets_Resource, getSourcePath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_sourcePath");

}

PHP_METHOD(Phalcon_Assets_Resource, getTargetPath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Resource, getTargetUri) {

	ZEPHIR_INIT_THIS();


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
	zval *type_param = NULL, *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$true, __$false, __$null;
	zval type, path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &type_param, &path_param, &local_param, &filter_param, &attributes);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&path, path_param);
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
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_type"), &type);
	zephir_update_property_zval(this_ptr, SL("_path"), &path);
	if (local) {
		zephir_update_property_zval(this_ptr, SL("_local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_local"), &__$false);
	}
	if (filter) {
		zephir_update_property_zval(this_ptr, SL("_filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_filter"), &__$false);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_attributes"), attributes);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the resource's type
 */
PHP_METHOD(Phalcon_Assets_Resource, setType) {

	zval *type_param = NULL;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, SL("_type"), &type);
	RETURN_THIS();

}

/**
 * Sets the resource's path
 */
PHP_METHOD(Phalcon_Assets_Resource, setPath) {

	zval *path_param = NULL;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("_path"), &path);
	RETURN_THIS();

}

/**
 * Sets if the resource is local or external
 */
PHP_METHOD(Phalcon_Assets_Resource, setLocal) {

	zval *local_param = NULL, __$true, __$false;
	zend_bool local;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &local_param);

	local = zephir_get_boolval(local_param);


	if (local) {
		zephir_update_property_zval(this_ptr, SL("_local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if the resource must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Resource, setFilter) {

	zval *filter_param = NULL, __$true, __$false;
	zend_bool filter;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &filter_param);

	filter = zephir_get_boolval(filter_param);


	if (filter) {
		zephir_update_property_zval(this_ptr, SL("_filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_filter"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, setAttributes) {

	zval *attributes_param = NULL;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, SL("_attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri) {

	zval *targetUri_param = NULL;
	zval targetUri;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&targetUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	zephir_get_strval(&targetUri, targetUri_param);


	zephir_update_property_zval(this_ptr, SL("_targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets the resource's source path
 */
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath) {

	zval *sourcePath_param = NULL;
	zval sourcePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sourcePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	zephir_get_strval(&sourcePath, sourcePath_param);


	zephir_update_property_zval(this_ptr, SL("_sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Sets the resource's target path
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath) {

	zval *targetPath_param = NULL;
	zval targetPath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&targetPath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	zephir_get_strval(&targetPath, targetPath_param);


	zephir_update_property_zval(this_ptr, SL("_targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Returns the content of the resource as an string
 * Optionally a base path where the resource is located can be set
 */
PHP_METHOD(Phalcon_Assets_Resource, getContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, completePath, content, _0, _1$$5, _2$$5, _3$$6, _4$$6;
	zval basePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(&sourcePath);
	zephir_read_property(&sourcePath, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &sourcePath);
	zephir_read_property(&_0, this_ptr, SL("_local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		if (!((zephir_file_exists(&completePath TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SVS(&_2$$5, "Resource's content for '", &completePath, "' cannot be read");
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 9, &_2$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/assets/resource.zep", 183 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&content);
	zephir_file_get_contents(&content, &completePath TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "Resource's content for '", &completePath, "' cannot be read");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 9, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/assets/resource.zep", 192 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(content);

}

/**
 * Returns the real target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri) {

	zval targetUri;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&targetUri);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&targetUri);
	zephir_read_property(&targetUri, this_ptr, SL("_targetUri"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&targetUri)) {
		ZEPHIR_OBS_NVAR(&targetUri);
		zephir_read_property(&targetUri, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(targetUri);

}

/**
 * Returns the complete location where the resource is located
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, _0, _1$$4;
	zval basePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(&sourcePath);
	zephir_read_property(&sourcePath, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("_local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_VV(&_1$$4, &basePath, &sourcePath);
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 64, &_1$$4);
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
	zval *basePath_param = NULL, targetPath, completePath, _0;
	zval basePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(&targetPath);
	zephir_read_property(&targetPath, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&targetPath)) {
		ZEPHIR_OBS_NVAR(&targetPath);
		zephir_read_property(&targetPath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("_local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
		if ((zephir_file_exists(&completePath TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 64, &completePath);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(completePath);
	}
	RETURN_CCTOR(targetPath);

}


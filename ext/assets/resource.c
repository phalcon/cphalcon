
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/operators.h"
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
 * $resource = new Phalcon\Assets\Resource('js', 'javascripts/jquery.js');
 *</code>
 *
 */


/**
 * Phalcon\Assets\Resource initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Resource){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets, Resource, assets_resource, phalcon_assets_resource_method_entry, 0);

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

/**
 * Phalcon\Assets\Resource constructor
 *
 * @param string $type
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, __construct){

	zval *type, *path, *local = NULL, *filter = NULL, *attributes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 3, &type, &path, &local, &filter, &attributes);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	if (!filter) {
		PHALCON_INIT_VAR(filter);
		ZVAL_BOOL(filter, 1);
	}
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the resource's type
 *
 * @param string $type
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setType){

	zval *type;

	phalcon_fetch_params(0, 1, 0, &type);
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the type of resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Sets the resource's path
 *
 * @param string $path
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setPath){

	zval *path;

	phalcon_fetch_params(0, 1, 0, &path);
	
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the URI/URL path to the resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getPath){


	RETURN_MEMBER(this_ptr, "_path");
}

/**
 * Sets if the resource is local or external
 *
 * @param boolean $local
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setLocal){

	zval *local;

	phalcon_fetch_params(0, 1, 0, &local);
	
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns whether the resource is local or external
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getLocal){


	RETURN_MEMBER(this_ptr, "_local");
}

/**
 * Sets if the resource must be filtered or not
 *
 * @param boolean $filter
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setFilter){

	zval *filter;

	phalcon_fetch_params(0, 1, 0, &filter);
	
	phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns whether the resource must be filtered or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getFilter){


	RETURN_MEMBER(this_ptr, "_filter");
}

/**
 * Sets extra HTML attributes
 *
 * @param array $attributes
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setAttributes){

	zval *attributes;

	phalcon_fetch_params(0, 1, 0, &attributes);
	
	phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns extra HTML attributes set in the resource
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Resource, getAttributes){


	RETURN_MEMBER(this_ptr, "_attributes");
}

/**
 * Sets a target uri for the generated HTML
 *
 * @param string $targetUri
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri){

	zval *target_uri;

	phalcon_fetch_params(0, 1, 0, &target_uri);
	
	phalcon_update_property_this(this_ptr, SL("_targetUri"), target_uri TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getTargetUri){


	RETURN_MEMBER(this_ptr, "_targetUri");
}

/**
 * Sets the resource's source path
 *
 * @param string $sourcePath
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath){

	zval *source_path;

	phalcon_fetch_params(0, 1, 0, &source_path);
	
	phalcon_update_property_this(this_ptr, SL("_sourcePath"), source_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the resource's target path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getSourcePath){


	RETURN_MEMBER(this_ptr, "_targetPath");
}

/**
 * Sets the resource's target path
 *
 * @param string $targetPath
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath){

	zval *target_path;

	phalcon_fetch_params(0, 1, 0, &target_path);
	
	phalcon_update_property_this(this_ptr, SL("_targetPath"), target_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the resource's target path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getTargetPath){


	RETURN_MEMBER(this_ptr, "_sourcePath");
}

/**
 * Returns the content of the resource as an string
 * Optionally a base path where the resource is located can be set
 *
 * @param string $basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getContent){

	zval *base_path = NULL, *source_path = NULL, *complete_path;
	zval *local, *exception_message = NULL, *content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		PHALCON_INIT_VAR(base_path);
	}
	
	PHALCON_OBS_VAR(source_path);
	phalcon_read_property_this(&source_path, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (PHALCON_IS_EMPTY(source_path)) {
		PHALCON_OBS_NVAR(source_path);
		phalcon_read_property_this(&source_path, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	
	/** 
	 * A base path for resources can be set in the assets manager
	 */
	PHALCON_INIT_VAR(complete_path);
	PHALCON_CONCAT_VV(complete_path, base_path, source_path);
	
	PHALCON_OBS_VAR(local);
	phalcon_read_property_this(&local, this_ptr, SL("_local"), PH_NOISY_CC);
	
	/** 
	 * Local resources are loaded from the local disk
	 */
	if (zend_is_true(local)) {
	
		/** 
		 * Check first if the file is readable
		 */
		if (phalcon_file_exists(complete_path TSRMLS_CC) == FAILURE) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Resource's content for \"", complete_path, "\" cannot be loaded");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
			return;
		}
	}
	
	/** 
	 * Use file_get_contents to respect the openbase_dir. Access urls must be enabled
	 */
	PHALCON_INIT_VAR(content);
	phalcon_file_get_contents(content, complete_path TSRMLS_CC);
	if (PHALCON_IS_FALSE(content)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource's content for \"", complete_path, "\" cannot be read");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
		return;
	}
	
	RETURN_CCTOR(content);
}

/**
 * Returns the real target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri){

	zval *target_uri = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(target_uri);
	phalcon_read_property_this(&target_uri, this_ptr, SL("_targetUri"), PH_NOISY_CC);
	if (PHALCON_IS_EMPTY(target_uri)) {
		PHALCON_OBS_NVAR(target_uri);
		phalcon_read_property_this(&target_uri, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	
	RETURN_CCTOR(target_uri);
}

/**
 * Returns the complete location where the resource is located
 *
 * @param string $basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath){

	zval *base_path = NULL, *source_path = NULL, *local, *complete_path;
	zval *real_complete_path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		PHALCON_INIT_VAR(base_path);
	}
	
	PHALCON_OBS_VAR(source_path);
	phalcon_read_property_this(&source_path, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (PHALCON_IS_EMPTY(source_path)) {
		PHALCON_OBS_NVAR(source_path);
		phalcon_read_property_this(&source_path, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(local);
	phalcon_read_property_this(&local, this_ptr, SL("_local"), PH_NOISY_CC);
	if (zend_is_true(local)) {
		/** 
		 * A base path for resources can be set in the assets manager
		 */
		PHALCON_INIT_VAR(complete_path);
		PHALCON_CONCAT_VV(complete_path, base_path, source_path);
	
		/** 
		 * Get the real template path
		 */
		PHALCON_INIT_VAR(real_complete_path);
		phalcon_call_func_p1(real_complete_path, "realpath", complete_path);
		RETURN_CCTOR(real_complete_path);
	}
	
	RETURN_CCTOR(source_path);
}

/**
 * Returns the complete location where the resource must be written
 *
 * @param string $basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath){

	zval *base_path = NULL, *target_path = NULL, *local, *complete_path;
	zval *real_complete_path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		PHALCON_INIT_VAR(base_path);
	}
	
	PHALCON_OBS_VAR(target_path);
	phalcon_read_property_this(&target_path, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	if (PHALCON_IS_EMPTY(target_path)) {
		PHALCON_OBS_NVAR(target_path);
		phalcon_read_property_this(&target_path, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(local);
	phalcon_read_property_this(&local, this_ptr, SL("_local"), PH_NOISY_CC);
	if (zend_is_true(local)) {
	
		/** 
		 * A base path for resources can be set in the assets manager
		 */
		PHALCON_INIT_VAR(complete_path);
		PHALCON_CONCAT_VV(complete_path, base_path, target_path);
	
		/** 
		 * Get the real template path, the target path can optionally don't exist
		 */
		if (phalcon_file_exists(complete_path TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(real_complete_path);
			phalcon_call_func_p1(real_complete_path, "realpath", complete_path);
			RETURN_CCTOR(real_complete_path);
		}
	
		RETURN_CTOR(complete_path);
	}
	
	RETURN_CCTOR(target_path);
}


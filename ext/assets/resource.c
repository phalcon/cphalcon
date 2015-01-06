
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
  +------------------------------------------------------------------------+
*/

#include "assets/resource.h"
#include "assets/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/file.h"
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
zend_class_entry *phalcon_assets_resource_ce;

PHP_METHOD(Phalcon_Assets_Resource, __construct);
PHP_METHOD(Phalcon_Assets_Resource, setType);
PHP_METHOD(Phalcon_Assets_Resource, getType);
PHP_METHOD(Phalcon_Assets_Resource, setPath);
PHP_METHOD(Phalcon_Assets_Resource, getPath);
PHP_METHOD(Phalcon_Assets_Resource, setLocal);
PHP_METHOD(Phalcon_Assets_Resource, getLocal);
PHP_METHOD(Phalcon_Assets_Resource, setFilter);
PHP_METHOD(Phalcon_Assets_Resource, getFilter);
PHP_METHOD(Phalcon_Assets_Resource, setAttributes);
PHP_METHOD(Phalcon_Assets_Resource, getAttributes);
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri);
PHP_METHOD(Phalcon_Assets_Resource, getTargetUri);
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath);
PHP_METHOD(Phalcon_Assets_Resource, getSourcePath);
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath);
PHP_METHOD(Phalcon_Assets_Resource, getTargetPath);
PHP_METHOD(Phalcon_Assets_Resource, getContent);
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri);
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath);
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settargeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setsourcepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getcontent, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getrealsourcepath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getrealtargetpath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_resource_method_entry[] = {
	PHP_ME(Phalcon_Assets_Resource, __construct, arginfo_phalcon_assets_resource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Resource, setType, arginfo_phalcon_assets_resource_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setPath, arginfo_phalcon_assets_resource_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setLocal, arginfo_phalcon_assets_resource_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setFilter, arginfo_phalcon_assets_resource_setfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getFilter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setAttributes, arginfo_phalcon_assets_resource_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setTargetUri, arginfo_phalcon_assets_resource_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setSourcePath, arginfo_phalcon_assets_resource_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getSourcePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setTargetPath, arginfo_phalcon_assets_resource_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getTargetPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getContent, arginfo_phalcon_assets_resource_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealSourcePath, arginfo_phalcon_assets_resource_getrealsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealTargetPath, arginfo_phalcon_assets_resource_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	phalcon_fetch_params(0, 2, 3, &type, &path, &local, &filter, &attributes);
	
	if (!local) {
		local = PHALCON_GLOBAL(z_true);
	}
	
	if (!filter) {
		filter = PHALCON_GLOBAL(z_true);
	}
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
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
	zval *local, *exception_message = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		base_path = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(source_path);
	phalcon_read_property_this(&source_path, this_ptr, SL("_sourcePath"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_EMPTY(source_path)) {
		PHALCON_OBS_NVAR(source_path);
		phalcon_read_property_this(&source_path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	}
	
	/** 
	 * A base path for resources can be set in the assets manager
	 */
	PHALCON_INIT_VAR(complete_path);
	PHALCON_CONCAT_VV(complete_path, base_path, source_path);
	
	PHALCON_OBS_VAR(local);
	phalcon_read_property_this(&local, this_ptr, SL("_local"), PH_NOISY TSRMLS_CC);
	
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
	phalcon_file_get_contents(return_value, complete_path TSRMLS_CC);
	if (PHALCON_IS_FALSE(return_value)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource's content for \"", complete_path, "\" cannot be read");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the real target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri){

	zval *target_uri;

	target_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_targetUri"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_EMPTY(target_uri)) {
		target_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	}
	
	RETURN_ZVAL(target_uri, 1, 0);
}

/**
 * Returns the complete location where the resource is located
 *
 * @param string $basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath){

	zval *base_path = NULL, *source_path = NULL, *local, *complete_path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		base_path = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(source_path);
	phalcon_read_property_this(&source_path, this_ptr, SL("_sourcePath"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_EMPTY(source_path)) {
		PHALCON_OBS_NVAR(source_path);
		phalcon_read_property_this(&source_path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(local);
	phalcon_read_property_this(&local, this_ptr, SL("_local"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(local)) {
		/** 
		 * A base path for resources can be set in the assets manager
		 */
		PHALCON_INIT_VAR(complete_path);
		PHALCON_CONCAT_VV(complete_path, base_path, source_path);
	
		/** 
		 * Get the real template path
		 */
		phalcon_realpath(return_value, complete_path TSRMLS_CC);
		RETURN_MM();
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		base_path = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(target_path);
	phalcon_read_property_this(&target_path, this_ptr, SL("_targetPath"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_EMPTY(target_path)) {
		PHALCON_OBS_NVAR(target_path);
		phalcon_read_property_this(&target_path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(local);
	phalcon_read_property_this(&local, this_ptr, SL("_local"), PH_NOISY TSRMLS_CC);
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
			phalcon_realpath(return_value, complete_path TSRMLS_CC);
			RETURN_MM();
		}
	
		RETURN_CTOR(complete_path);
	}
	
	RETURN_CCTOR(target_path);
}

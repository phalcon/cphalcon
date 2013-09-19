
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
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


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
/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 *
 *<code>
 * $resource = new Phalcon\Assets\Resource('js', 'javascripts/jquery.js');
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

	zval *type, *path, *local = NULL, *filter = NULL, *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &type, &path, &local, &filter, &attributes);

	if (!local) {
		ZEPHIR_CPY_WRT(local, ZEPHIR_GLOBAL(global_true));
	}
	if (!filter) {
		ZEPHIR_CPY_WRT(filter, ZEPHIR_GLOBAL(global_true));
	}
	if (!attributes) {
		ZEPHIR_CPY_WRT(attributes, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the resource's type
 *
 * @param string type
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setType) {

	zval *type;

	zephir_fetch_params(0, 1, 0, &type);



	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the type of resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Sets the resource's path
 *
 * @param string path
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setPath) {

	zval *path;

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the URI/URL path to the resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getPath) {


	RETURN_MEMBER(this_ptr, "_path");

}

/**
 * Sets if the resource is local or external
 *
 * @param boolean local
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setLocal) {

	zval *local;

	zephir_fetch_params(0, 1, 0, &local);



	zephir_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns whether the resource is local or external
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getLocal) {


	RETURN_MEMBER(this_ptr, "_local");

}

/**
 * Sets if the resource must be filtered or not
 *
 * @param boolean filter
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setFilter) {

	zval *filter;

	zephir_fetch_params(0, 1, 0, &filter);



	zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns whether the resource must be filtered or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getFilter) {


	RETURN_MEMBER(this_ptr, "_filter");

}

/**
 * Sets extra HTML attributes
 *
 * @param array attributes
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setAttributes) {

	zval *attributes;

	zephir_fetch_params(0, 1, 0, &attributes);



	zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns extra HTML attributes set in the resource
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Resource, getAttributes) {


	RETURN_MEMBER(this_ptr, "_attributes");

}

/**
 * Sets a target uri for the generated HTML
 *
 * @param string targetUri
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri) {

	zval *targetUri;

	zephir_fetch_params(0, 1, 0, &targetUri);



	zephir_update_property_this(this_ptr, SL("_targetUri"), targetUri TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getTargetUri) {


	RETURN_MEMBER(this_ptr, "_targetUri");

}

/**
 * Sets the resource's source path
 *
 * @param string sourcePath
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath) {

	zval *sourcePath;

	zephir_fetch_params(0, 1, 0, &sourcePath);



	zephir_update_property_this(this_ptr, SL("_sourcePath"), sourcePath TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the resource's target path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getSourcePath) {


	RETURN_MEMBER(this_ptr, "_targetPath");

}

/**
 * Sets the resource's target path
 *
 * @param string targetPath
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath) {

	zval *targetPath;

	zephir_fetch_params(0, 1, 0, &targetPath);



	zephir_update_property_this(this_ptr, SL("_targetPath"), targetPath TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the resource's target path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getTargetPath) {


	RETURN_MEMBER(this_ptr, "_sourcePath");

}

/**
 * Returns the content of the resource as an string
 * Optionally a base path where the resource is located can be set
 *
 * @param string basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getContent) {

	zval *basePath = NULL, *sourcePath = NULL, *completePath, *content, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath);

	if (!basePath) {
		ZEPHIR_CPY_WRT(basePath, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(sourcePath);
	zephir_read_property_this(&sourcePath, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (0) {
		ZEPHIR_OBS_NVAR(sourcePath);
		zephir_read_property_this(&sourcePath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(completePath);
	concat_function(completePath, basePath, sourcePath TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "file_exists", completePath);
		if (!(zephir_is_true(_1))) {
			ZEPHIR_INIT_VAR(_2);
			object_init_ex(_2, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SV(_3, "Resource's content for '", completePath);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_VS(_4, _3, "' cannot be read");
			zephir_call_method_p1_noret(_2, "__construct", _4);
			zephir_throw_exception(_2 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(content);
	zephir_call_func_p1(content, "file_get_contents", completePath);
	if (ZEPHIR_IS_FALSE(content)) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_assets_exception_ce);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SV(_3, "Resource's content for '", completePath);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VS(_4, _3, "' cannot be read");
		zephir_call_method_p1_noret(_1, "__construct", _4);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(content);

}

/**
 * Returns the real target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri) {

	zval *targetUri = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(targetUri);
	zephir_read_property_this(&targetUri, this_ptr, SL("_targetUri"), PH_NOISY_CC);
	if (0) {
		ZEPHIR_OBS_NVAR(targetUri);
		zephir_read_property_this(&targetUri, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(targetUri);

}

/**
 * Returns the complete location where the resource is located
 *
 * @param string basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath) {

	zval *basePath = NULL, *sourcePath = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath);

	if (!basePath) {
		ZEPHIR_CPY_WRT(basePath, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(sourcePath);
	zephir_read_property_this(&sourcePath, this_ptr, SL("_sourcePath"), PH_NOISY_CC);
	if (0) {
		ZEPHIR_OBS_NVAR(sourcePath);
		zephir_read_property_this(&sourcePath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		concat_function(_1, basePath, sourcePath TSRMLS_CC);
		zephir_call_func_p1(return_value, "realpath", _1);
		RETURN_MM();
	}
	RETURN_CCTOR(sourcePath);

}

/**
 * Returns the complete location where the resource must be written
 *
 * @param string basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath) {

	zval *basePath = NULL, *targetPath = NULL, *completePath, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath);

	if (!basePath) {
		ZEPHIR_CPY_WRT(basePath, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(targetPath);
	zephir_read_property_this(&targetPath, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	if (0) {
		ZEPHIR_OBS_NVAR(targetPath);
		zephir_read_property_this(&targetPath, this_ptr, SL("_path"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(completePath);
		concat_function(completePath, basePath, targetPath TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "file_exists", completePath);
		if (zephir_is_true(_1)) {
			zephir_call_func_p1(return_value, "realpath", completePath);
			RETURN_MM();
		}
		RETURN_CCTOR(completePath);
	}
	RETURN_CCTOR(targetPath);

}



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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
 * Phalcon\Assets\Manager
 *
 * Manages collections of CSS/Javascript assets
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Manager, phalcon, assets_manager, phalcon_assets_manager_method_entry, 0);

/**
 * Options configure
 * @var array
 */
	zend_declare_property_null(phalcon_assets_manager_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_manager_ce, SL("_collections"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_assets_manager_ce, SL("_implicitOutput"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Assets\Manager
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Assets_Manager, __construct) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}

}

/**
 * Sets the manager's options
 *
 * @param array $options
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions) {

	zval *options, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "Options must be an array", 1);
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the manager's options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Manager, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Sets if the HTML generated must be directly printed or returned
 *
 * @param boolean implicitOutput
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput) {

	zval *implicitOutput_param = NULL, *_0;
	zend_bool implicitOutput;

	zephir_fetch_params(0, 1, 0, &implicitOutput_param);

		implicitOutput = zephir_get_boolval(implicitOutput_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, implicitOutput);
	zephir_update_property_this(this_ptr, SL("_implicitOutput"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds a Css resource to the 'css' collection
 *
 *<code>
 *	$assets->addCss('css/bootstrap.css');
 *	$assets->addCss('http://bootstrap.my-cdn.com/style.css', false);
 *</code>
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss) {

	zval *path_param = NULL, *local = NULL, *filter = NULL, *attributes, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &path_param, &local, &filter, &attributes);

		zephir_get_strval(path, path_param);
	if (!local) {
		ZEPHIR_CPY_WRT(local, ZEPHIR_GLOBAL(global_true));
	}
	if (!filter) {
		ZEPHIR_CPY_WRT(filter, ZEPHIR_GLOBAL(global_true));
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_js_ce);
	zephir_call_method_p4_noret(_0, "__construct", path, local, filter, attributes);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "css", 1);
	zephir_call_method_p2_noret(this_ptr, "addresourcebytype", _1, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a resource by its type
 *
 *<code>
 *	$assets->addResourceByType('css', new Phalcon\Assets\Resource\Css('css/style.css'));
 *</code>
 *
 * @param string type
 * @param Phalcon\Assets\Resource resource
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addResourceByType) {

	zval *type_param = NULL, *resource, *collections, *collection, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &resource);

		zephir_get_strval(type, type_param);


	collections = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, collections, type, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_assets_collection_ce);
		zephir_update_property_array(this_ptr, SL("_collections"), type, _0 TSRMLS_CC);
	}
	zephir_call_method_p1_noret(collection, "add", resource);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a raw resource to the manager
 *
 *<code>
 * $assets->addResource(new Phalcon\Assets\Resource('css', 'css/style.css'));
 *</code>
 *
 * @param Phalcon\Assets\Resource resource
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addResource) {

	zval *resource, *type, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	if ((Z_TYPE_P(resource) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "Resource must be an object", 1);
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(type);
	zephir_call_method(type, resource, "gettype");
	zephir_call_method_p2_noret(this_ptr, "addresourcebytype", type, resource);
	RETURN_THIS();

}

/**
 * Sets a collection in the Assets Manager
 *
 *<code>
 * $assets->set('js', $collection);
 *</code>
 *
 * @param string id
 * @param Phalcon\Assets\Collection collection
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, set) {

	zval *id_param = NULL, *collection;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &collection);

		zephir_get_strval(id, id_param);


	zephir_update_property_array(this_ptr, SL("_collections"), id, collection TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a collection by its id
 *
 *<code>
 * $scripts = $assets->get('js');
 *</code>
 *
 * @param string id
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, get) {

	zval *id_param = NULL, *collections, *collection, *_0, *_1;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

		zephir_get_strval(id, id_param);


	collections = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, collections, id, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "The collection does not exist in the manager", 1);
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
	RETURN_ZVAL(collection, 1, 0);

}

/**
 * Returns the CSS collection of assets
 *
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss) {

	zval *collection, *collections;


	collections = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&collection, collections, SS("css"), 1 TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		return;
	}
	RETURN_ZVAL(collection, 1, 0);

}

/**
 * Returns the CSS collection of assets
 *
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, getJs) {

	zval *collections, *collection;


	collections = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&collection, collections, SS("js"), 1 TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		return;
	}
	RETURN_ZVAL(collection, 1, 0);

}

/**
 * Creates/Returns a collection of resources
 *
 * @param string name
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, collection) {

	zval *name_param = NULL, *collections, *collection;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	collections = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(collection);
	if (!(zephir_array_isset_fetch(&collection, collections, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		zephir_update_property_array(this_ptr, SL("_collections"), name, collection TSRMLS_CC);
	}
	RETURN_CCTOR(collection);

}

/**
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param Phalcon\Assets\Collection collection
 * @param callback callback
 */
PHP_METHOD(Phalcon_Assets_Manager, output) {

	zval *collection, *callback, *type, *implicitOutput, *resources, *filters, *prefix, *sourceBasePath, *targetBasePath, *options, *collectionSourcePath, *completeSourcePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection, &callback, &type);



	implicitOutput = zephir_fetch_nproperty_this(this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(resources);
	zephir_call_method(resources, collection, "getresources");
	ZEPHIR_INIT_VAR(filters);
	zephir_call_method(filters, collection, "getfilters");
	ZEPHIR_INIT_VAR(prefix);
	zephir_call_method(prefix, collection, "getprefix");
	if ((Z_TYPE_P(filters) == IS_ARRAY)) {
		options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if ((Z_TYPE_P(options) == IS_ARRAY)) {
			if (zephir_array_isset_string(options, SS("sourceBasePath"))) {
				zephir_array_fetch_string(&sourceBasePath, options, SL("sourceBasePath"), PH_NOISY | PH_READONLY TSRMLS_CC);
			}
			if (zephir_array_isset_string(options, SS("targetBasePath"))) {
				zephir_array_fetch_string(&targetBasePath, options, SL("targetBasePath"), PH_NOISY | PH_READONLY TSRMLS_CC);
			}
		}
	}
	ZEPHIR_INIT_VAR(collectionSourcePath);
	zephir_call_method(collectionSourcePath, collection, "getsourcepath");
	if (zephir_is_true(collectionSourcePath)) {
		ZEPHIR_INIT_VAR(completeSourcePath);
		concat_function(completeSourcePath, sourceBasePath, collectionSourcePath TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(completeSourcePath, sourceBasePath);
	}
	ZEPHIR_MM_RESTORE();

}



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
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * Sets the manager options
 *
 * @param array options
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Options must be an array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the manager options
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

	zval *implicitOutput_param = NULL;
	zend_bool implicitOutput;

	zephir_fetch_params(0, 1, 0, &implicitOutput_param);

		implicitOutput = zephir_get_boolval(implicitOutput_param);


	zephir_update_property_this(this_ptr, SL("_implicitOutput"), implicitOutput ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	RETURN_THIS();

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

	zval *resource, *type;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	if ((Z_TYPE_P(resource) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Resource must be an object");
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

	zval *id_param = NULL, *collections, *collection;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

		zephir_get_strval(id, id_param);


	collections = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, collections, id, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "The collection does not exist in the manager");
		return;
	}
	RETURN_CTOR(collection);

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
	RETURN_CTORW(collection);

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
	RETURN_CTORW(collection);

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
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, output) {

	zend_function *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_25 = NULL, *_26 = NULL, *_27 = NULL;
	HashTable *_5, *_23;
	HashPosition _4, _22;
	zend_bool filterNeeded;
	zval *collection, *callback, *type = NULL, *output, *resources, *filters, *prefix, *sourceBasePath, *targetBasePath, *options, *collectionSourcePath, *completeSourcePath = NULL, *collectionTargetPath, *completeTargetPath = NULL, *filteredJoinedContent = NULL, *join, *resource = NULL, *local = NULL, *sourcePath = NULL, *targetPath = NULL, *path = NULL, *prefixedPath = NULL, *attributes = NULL, *parameters = NULL, *html = NULL, *useImplicitOutput, *content = NULL, *mustFilter = NULL, *filter = NULL, *filteredContent = NULL, *typeCss, *targetUri, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, **_6, *_14 = NULL, *_15 = NULL, **_24;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection, &callback, &type);

	ZEPHIR_SEPARATE_PARAM(type);


	useImplicitOutput = zephir_fetch_nproperty_this(this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_INIT_VAR(resources);
	zephir_call_method(resources, collection, "getresources");
	ZEPHIR_INIT_VAR(filters);
	zephir_call_method(filters, collection, "getfilters");
	ZEPHIR_INIT_VAR(prefix);
	zephir_call_method(prefix, collection, "getprefix");
	ZEPHIR_INIT_VAR(typeCss);
	ZVAL_STRING(typeCss, "css", 1);
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
	ZEPHIR_INIT_VAR(collectionTargetPath);
	zephir_call_method(collectionTargetPath, collection, "gettargetpath");
	if (zephir_is_true(collectionTargetPath)) {
		ZEPHIR_INIT_VAR(completeTargetPath);
		concat_function(completeTargetPath, targetBasePath, collectionTargetPath TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(completeTargetPath, targetBasePath);
	}
	ZEPHIR_INIT_VAR(filteredJoinedContent);
	ZVAL_NULL(filteredJoinedContent);
	ZEPHIR_INIT_VAR(join);
	zephir_call_method(join, collection, "getjoin");
	if (zephir_is_true(join)) {
		if (!(zephir_is_true(completeTargetPath))) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SV(_1, "Path '", completeTargetPath);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_VS(_2, _1, "' is not a valid target path (1)");
			zephir_call_method_p1_noret(_0, "__construct", _2);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_func_p1(_0, "is_dir", completeTargetPath);
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_VAR(_3);
			object_init_ex(_3, phalcon_assets_exception_ce);
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SV(_1, "Path '", completeTargetPath);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_VS(_2, _1, "' is not a valid target path (2), is dir.");
			zephir_call_method_p1_noret(_3, "__construct", _2);
			zephir_throw_exception(_3 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_is_iterable(resources, &_5, &_4, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(resource, _6);
		filterNeeded = 0;
		ZEPHIR_INIT_NVAR(type);
		zephir_call_method_cache(type, resource, "gettype", &_7);
		ZEPHIR_INIT_NVAR(local);
		zephir_call_method_cache(local, resource, "getlocal", &_8);
		if ((Z_TYPE_P(filters) == IS_ARRAY)) {
			if (zephir_is_true(join)) {
				ZEPHIR_INIT_NVAR(sourcePath);
				if (zephir_is_true(local)) {
					zephir_call_method_cache(sourcePath, resource, "getrealsourcepath", &_9);
					if (!(zephir_is_true(sourcePath))) {
						zephir_call_method_cache(sourcePath, resource, "getpath", &_10);
						ZEPHIR_INIT_NVAR(_0);
						object_init_ex(_0, phalcon_assets_exception_ce);
						ZEPHIR_INIT_LNVAR(_1);
						ZEPHIR_CONCAT_SV(_1, "Resource '", sourcePath);
						ZEPHIR_INIT_LNVAR(_2);
						ZEPHIR_CONCAT_VS(_2, _1, "' does not have a valid source path");
						zephir_call_method_p1_cache_noret(_0, "__construct", &_11, _2);
						zephir_throw_exception(_0 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(sourcePath);
					zephir_call_method_cache(sourcePath, resource, "getpath", &_12);
					filterNeeded = 1;
				}
				ZEPHIR_INIT_NVAR(targetPath);
				zephir_call_method_p1_cache(targetPath, resource, "getrealtargetpath", &_13, completeTargetPath);
				if (!(zephir_is_true(targetPath))) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_assets_exception_ce);
					ZEPHIR_INIT_LNVAR(_14);
					ZEPHIR_CONCAT_SV(_14, "Resource '", sourcePath);
					ZEPHIR_INIT_LNVAR(_15);
					ZEPHIR_CONCAT_VS(_15, _14, "' does not have a valid target path");
					zephir_call_method_p1_cache_noret(_0, "__construct", &_16, _15);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(local)) {
					if (ZEPHIR_IS_EQUAL(targetPath, sourcePath)) {
						ZEPHIR_INIT_NVAR(_0);
						object_init_ex(_0, phalcon_assets_exception_ce);
						ZEPHIR_INIT_LNVAR(_14);
						ZEPHIR_CONCAT_SV(_14, "Resource '", targetPath);
						ZEPHIR_INIT_LNVAR(_15);
						ZEPHIR_CONCAT_VS(_15, _14, "' have the same source and target paths");
						zephir_call_method_p1_cache_noret(_0, "__construct", &_17, _15);
						zephir_throw_exception(_0 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(_0);
					zephir_call_func_p1(_0, "file_exists", targetPath);
					if (zephir_is_true(_0)) {
						ZEPHIR_INIT_NVAR(_3);
						zephir_call_func_p2(_3, "compare_mtime", targetPath, sourcePath);
						if (zephir_is_true(_3)) {
							filterNeeded = 1;
						}
					} else {
						filterNeeded = 1;
					}
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(path);
			zephir_call_method_cache(path, resource, "getrealtargeturi", &_18);
			if (zephir_is_true(prefix)) {
				ZEPHIR_INIT_NVAR(prefixedPath);
				concat_function(prefixedPath, prefix, path TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(prefixedPath, path);
			}
			ZEPHIR_INIT_NVAR(attributes);
			zephir_call_method_cache(attributes, resource, "getattributes", &_19);
			ZEPHIR_INIT_NVAR(parameters);
			array_init(parameters);
			if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE);
				zephir_array_append(&parameters, attributes, PH_SEPARATE);
			} else {
				zephir_array_append(&parameters, prefixedPath, PH_SEPARATE);
			}
			zephir_array_append(&parameters, local, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(html);
			zephir_call_func_p2(html, "call_user_func_array", callback, parameters);
			if (ZEPHIR_IS_TRUE(useImplicitOutput)) {
				zend_print_zval(html, 0);
			} else {
				zephir_concat_self(&output, html TSRMLS_CC);
			}
			continue;
		}
		if ((filterNeeded == 1)) {
			ZEPHIR_INIT_NVAR(content);
			zephir_call_method_p1_cache(content, resource, "getcontent", &_20, completeSourcePath);
			ZEPHIR_INIT_NVAR(mustFilter);
			zephir_call_method_cache(mustFilter, resource, "getfilter", &_21);
			if (ZEPHIR_IS_TRUE(mustFilter)) {
				zephir_is_iterable(filters, &_23, &_22, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_23, (void**) &_24, &_22) == SUCCESS
					; zend_hash_move_forward_ex(_23, &_22)
				) {
					ZEPHIR_GET_HVALUE(filter, _24);
					if ((Z_TYPE_P(filter) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Filter is invalid");
						return;
					}
					ZEPHIR_INIT_NVAR(filteredContent);
					zephir_call_method_p1_cache(filteredContent, filter, "filter", &_25, content);
					if (ZEPHIR_IS_TRUE(join)) {
						if (ZEPHIR_IS_EQUAL(type, typeCss)) {
							if ((Z_TYPE_P(filteredJoinedContent) == IS_NULL)) {
								ZEPHIR_CPY_WRT(filteredJoinedContent, filteredContent);
							} else {
								zephir_concat_self(&filteredJoinedContent, filteredContent TSRMLS_CC);
							}
						} else {
							if ((Z_TYPE_P(filteredJoinedContent) == IS_NULL)) {
								ZEPHIR_INIT_NVAR(filteredJoinedContent);
								ZEPHIR_CONCAT_VS(filteredJoinedContent, filteredContent, ";");
							} else {
								ZEPHIR_INIT_LNVAR(_1);
								ZEPHIR_CONCAT_VS(_1, filteredContent, ";");
								zephir_concat_self(&filteredJoinedContent, _1 TSRMLS_CC);
							}
						}
					}
				}
			} else {
				if (ZEPHIR_IS_TRUE(join)) {
				} else {
					if ((Z_TYPE_P(filteredJoinedContent) == IS_NULL)) {
						ZEPHIR_CPY_WRT(filteredJoinedContent, content);
					} else {
						ZEPHIR_CPY_WRT(filteredContent, content);
					}
				}
			}
			if (!(zephir_is_true(join))) {
				zephir_call_func_p2_noret("file_put_contents", targetPath, filteredContent);
			}
		}
		if (!(zephir_is_true(join))) {
			ZEPHIR_INIT_NVAR(path);
			zephir_call_method_cache(path, resource, "getrealtargeturi", &_26);
			if (zephir_is_true(prefix)) {
				ZEPHIR_INIT_NVAR(prefixedPath);
				concat_function(prefixedPath, prefix, path TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(prefixedPath, path);
			}
			ZEPHIR_INIT_NVAR(attributes);
			zephir_call_method_cache(attributes, resource, "getattributes", &_27);
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
			ZEPHIR_INIT_NVAR(parameters);
			array_init(parameters);
			if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE);
				zephir_array_append(&parameters, attributes, PH_SEPARATE);
			} else {
				zephir_array_append(&parameters, prefixedPath, PH_SEPARATE);
			}
			zephir_array_append(&parameters, local, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(html);
			zephir_call_func_p2(html, "call_user_func_array", callback, parameters);
			if (ZEPHIR_IS_TRUE(useImplicitOutput)) {
				zend_print_zval(html, 0);
			} else {
				zephir_concat_self(&output, html TSRMLS_CC);
			}
		}
	}
	if ((Z_TYPE_P(filters) == IS_ARRAY)) {
		if (ZEPHIR_IS_TRUE(join)) {
			zephir_call_func_p2_noret("file_put_contents", completeTargetPath, filteredJoinedContent);
			ZEPHIR_INIT_VAR(targetUri);
			zephir_call_method(targetUri, collection, "gettargeturi");
			if (zephir_is_true(prefix)) {
				ZEPHIR_INIT_NVAR(prefixedPath);
				concat_function(prefixedPath, prefix, targetUri TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(prefixedPath, targetUri);
			}
			ZEPHIR_INIT_NVAR(attributes);
			zephir_call_method(attributes, resource, "getattributes");
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
			ZEPHIR_INIT_NVAR(parameters);
			array_init(parameters);
			if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE);
				zephir_array_append(&parameters, attributes, PH_SEPARATE);
			} else {
				zephir_array_append(&parameters, prefixedPath, PH_SEPARATE);
			}
			zephir_array_append(&parameters, local, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(html);
			zephir_call_func_p2(html, "call_user_func_array", callback, parameters);
			if (ZEPHIR_IS_TRUE(useImplicitOutput)) {
				zend_print_zval(html, 0);
			} else {
				zephir_concat_self(&output, html TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(output);

}

/**
 * Prints the HTML for CSS resources
 *
 * @param string collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss) {

	zval *collectionName, *collection, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionName);



	ZEPHIR_INIT_VAR(collection);
	if (!(zephir_is_true(collectionName))) {
		zephir_call_method(collection, this_ptr, "getcss");
	} else {
		zephir_call_method_p1(collection, this_ptr, "get", collectionName);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Phalcon\\Tag", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "stylesheetLink", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "css", 1);
	zephir_call_method_p3(return_value, this_ptr, "output", collection, _0, _1);
	RETURN_MM();

}

/**
 * Prints the HTML for JS resources
 *
 * @param string collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs) {

	zval *collectionName, *collection, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collectionName);



	ZEPHIR_INIT_VAR(collection);
	if (!(zephir_is_true(collectionName))) {
		zephir_call_method(collection, this_ptr, "getjs");
	} else {
		zephir_call_method_p1(collection, this_ptr, "get", collectionName);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Phalcon\\Tag", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "javascriptInclude", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "js", 1);
	zephir_call_method_p3(return_value, this_ptr, "output", collection, _0, _1);
	RETURN_MM();

}


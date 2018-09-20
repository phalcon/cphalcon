
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"


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

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	}

}

/**
 * Sets the manager options
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;


	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the manager options
 */
PHP_METHOD(Phalcon_Assets_Manager, getOptions) {

	

	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Sets if the HTML generated must be directly printed or returned
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput) {

	zval *implicitOutput_param = NULL;
	zend_bool implicitOutput;

	zephir_fetch_params(0, 1, 0, &implicitOutput_param);

	implicitOutput = zephir_get_boolval(implicitOutput_param);


	if (implicitOutput) {
		zephir_update_property_this(getThis(), SL("_implicitOutput"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_implicitOutput"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Adds a Css resource to the 'css' collection
 *
 *<code>
 *	$assets->addCss("css/bootstrap.css");
 *	$assets->addCss("http://bootstrap.my-cdn.com/style.css", false);
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *local = NULL, *filter = NULL, *attributes = NULL, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!local) {
		local = ZEPHIR_GLOBAL(global_true);
	}
	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_true);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_css_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 105, path, local, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresourcebytype", NULL, 0, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline Css to the 'css' collection
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *filter = NULL, *attributes = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter, &attributes);

	zephir_get_strval(content, content_param);
	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_true);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_inline_css_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 106, content, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a javascript resource to the 'js' collection
 *
 *<code>
 * $assets->addJs("scripts/jquery.js");
 * $assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *local = NULL, *filter = NULL, *attributes = NULL, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!local) {
		local = ZEPHIR_GLOBAL(global_true);
	}
	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_true);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_js_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 107, path, local, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "js", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresourcebytype", NULL, 0, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the 'js' collection
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *filter = NULL, *attributes = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter, &attributes);

	zephir_get_strval(content, content_param);
	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_true);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_inline_js_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 108, content, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "js", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a resource by its type
 *
 *<code>
 * $assets->addResourceByType("css",
 *     new \Phalcon\Assets\Resource\Css("css/style.css")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addResourceByType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *resource, *collection = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &resource);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	ZEPHIR_OBS_VAR(collection);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, _0, type, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 110);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_collections"), type, collection TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, collection, "add", NULL, 111, resource);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline code by its type
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *code, *collection = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &code);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	ZEPHIR_OBS_VAR(collection);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, _0, type, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 110);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_collections"), type, collection TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, collection, "addinline", NULL, 112, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a raw resource to the manager
 *
 *<code>
 * $assets->addResource(
 *     new Phalcon\Assets\Resource("css", "css/style.css")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addResource) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(&_0, resource, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresourcebytype", NULL, 0, _0, resource);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a raw inline code to the manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCode) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_CALL_METHOD(&_0, code, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, _0, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets a collection in the Assets Manager
 *
 *<code>
 * $assets->set("js", $collection);
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, set) {

	zval *id_param = NULL, *collection;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &collection);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	zephir_update_property_array(this_ptr, SL("_collections"), id, collection TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a collection by its id.
 *
 * <code>
 * $scripts = $assets->get("js");
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Manager, get) {

	zval *id_param = NULL, *collection = NULL, *_0;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	ZEPHIR_OBS_VAR(collection);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, _0, id, 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "The collection does not exist in the manager", "phalcon/assets/manager.zep", 235);
		return;
	}
	RETURN_CCTOR(collection);

}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss) {

	zval *collection = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&collection, _0, SS("css"), 1 TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 110);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(collection);

}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getJs) {

	zval *collection = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&collection, _0, SS("js"), 1 TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 110);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(collection);

}

/**
 * Creates/Returns a collection of resources
 */
PHP_METHOD(Phalcon_Assets_Manager, collection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *collection = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(collection);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&collection, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 110);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_collections"), name, collection TSRMLS_CC);
	}
	RETURN_CCTOR(collection);

}

PHP_METHOD(Phalcon_Assets_Manager, collectionResourcesByType) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type = NULL;
	zval *resources_param = NULL, *type_param = NULL, *filtered = NULL, *resource = NULL, **_2, *_3$$3 = NULL;
	zval *resources = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resources_param, &type_param);

	zephir_get_arrval(resources, resources_param);
	zephir_get_strval(type, type_param);


	ZEPHIR_INIT_VAR(filtered);
	array_init(filtered);
	zephir_is_iterable(resources, &_1, &_0, 0, 0, "phalcon/assets/manager.zep", 299);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(resource, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, resource, "gettype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_3$$3, type)) {
			zephir_array_append(&filtered, resource, PH_SEPARATE, "phalcon/assets/manager.zep", 295);
		}
	}
	RETURN_CCTOR(filtered);

}

/**
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param \Phalcon\Assets\Collection collection
 * @param callback callback
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, output) {

	HashTable *_7, *_17$$31;
	HashPosition _6, _16$$31;
	zend_bool filterNeeded = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *callback, *type = NULL, *output = NULL, *resources = NULL, *filters = NULL, *prefix = NULL, *sourceBasePath = NULL, *targetBasePath = NULL, *options = NULL, *collectionSourcePath = NULL, *completeSourcePath = NULL, *collectionTargetPath = NULL, *completeTargetPath = NULL, *filteredJoinedContent = NULL, *join = NULL, *resource = NULL, *local = NULL, *sourcePath = NULL, *targetPath = NULL, *path = NULL, *prefixedPath = NULL, *attributes = NULL, *parameters = NULL, *html = NULL, *useImplicitOutput = NULL, *content = NULL, *mustFilter = NULL, *filter = NULL, *filteredContent = NULL, *typeCss = NULL, *targetUri = NULL, *_0 = NULL, **_8, *_1$$10, *_2$$10, *_3$$9 = NULL, *_4$$11, *_5$$11, *_9$$15 = NULL, *_10$$15 = NULL, *_11$$17 = NULL, *_12$$17 = NULL, *_13$$19 = NULL, *_14$$19 = NULL, *_15$$20 = NULL, **_18$$31, *_19$$36 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection, &callback, &type);

	ZEPHIR_SEPARATE_PARAM(type);


	ZEPHIR_INIT_VAR(sourceBasePath);
	ZVAL_NULL(sourceBasePath);
	ZEPHIR_INIT_VAR(targetBasePath);
	ZVAL_NULL(targetBasePath);
	ZEPHIR_OBS_VAR(useImplicitOutput);
	zephir_read_property_this(&useImplicitOutput, this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_METHOD(&_0, collection, "getresources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resources, this_ptr, "collectionresourcesbytype", NULL, 0, _0, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filters, collection, "getfilters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(typeCss);
	ZVAL_STRING(typeCss, "css", 1);
	if (zephir_fast_count_int(filters TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(sourceBasePath);
			zephir_array_isset_string_fetch(&sourceBasePath, options, SS("sourceBasePath"), 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(targetBasePath);
			zephir_array_isset_string_fetch(&targetBasePath, options, SS("targetBasePath"), 0 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&collectionSourcePath, collection, "getsourcepath", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(collectionSourcePath)) {
			ZEPHIR_INIT_VAR(completeSourcePath);
			ZEPHIR_CONCAT_VV(completeSourcePath, sourceBasePath, collectionSourcePath);
		} else {
			ZEPHIR_CPY_WRT(completeSourcePath, sourceBasePath);
		}
		ZEPHIR_CALL_METHOD(&collectionTargetPath, collection, "gettargetpath", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(collectionTargetPath)) {
			ZEPHIR_INIT_VAR(completeTargetPath);
			ZEPHIR_CONCAT_VV(completeTargetPath, targetBasePath, collectionTargetPath);
		} else {
			ZEPHIR_CPY_WRT(completeTargetPath, targetBasePath);
		}
		ZEPHIR_INIT_VAR(filteredJoinedContent);
		ZVAL_STRING(filteredJoinedContent, "", 1);
		ZEPHIR_CALL_METHOD(&join, collection, "getjoin", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(join)) {
			if (!(zephir_is_true(completeTargetPath))) {
				ZEPHIR_INIT_VAR(_1$$10);
				object_init_ex(_1$$10, phalcon_assets_exception_ce);
				ZEPHIR_INIT_VAR(_2$$10);
				ZEPHIR_CONCAT_SVS(_2$$10, "Path '", completeTargetPath, "' is not a valid target path (1)");
				ZEPHIR_CALL_METHOD(NULL, _1$$10, "__construct", NULL, 9, _2$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1$$10, "phalcon/assets/manager.zep", 408 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_3$$9, "is_dir", NULL, 113, completeTargetPath);
			zephir_check_call_status();
			if (zephir_is_true(_3$$9)) {
				ZEPHIR_INIT_VAR(_4$$11);
				object_init_ex(_4$$11, phalcon_assets_exception_ce);
				ZEPHIR_INIT_VAR(_5$$11);
				ZEPHIR_CONCAT_SVS(_5$$11, "Path '", completeTargetPath, "' is not a valid target path (2), is dir.");
				ZEPHIR_CALL_METHOD(NULL, _4$$11, "__construct", NULL, 9, _5$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4$$11, "phalcon/assets/manager.zep", 412 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_is_iterable(resources, &_7, &_6, 0, 0, "phalcon/assets/manager.zep", 650);
	for (
	  ; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zend_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HVALUE(resource, _8);
		filterNeeded = 0;
		ZEPHIR_CALL_METHOD(&type, resource, "gettype", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&local, resource, "getlocal", NULL, 0);
		zephir_check_call_status();
		if (zephir_fast_count_int(filters TSRMLS_CC)) {
			if (zephir_is_true(local)) {
				ZEPHIR_CALL_METHOD(&sourcePath, resource, "getrealsourcepath", NULL, 0, completeSourcePath);
				zephir_check_call_status();
				if (!(zephir_is_true(sourcePath))) {
					ZEPHIR_CALL_METHOD(&sourcePath, resource, "getpath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_9$$15);
					object_init_ex(_9$$15, phalcon_assets_exception_ce);
					ZEPHIR_INIT_LNVAR(_10$$15);
					ZEPHIR_CONCAT_SVS(_10$$15, "Resource '", sourcePath, "' does not have a valid source path");
					ZEPHIR_CALL_METHOD(NULL, _9$$15, "__construct", NULL, 9, _10$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(_9$$15, "phalcon/assets/manager.zep", 446 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CALL_METHOD(&sourcePath, resource, "getpath", NULL, 0);
				zephir_check_call_status();
				filterNeeded = 1;
			}
			ZEPHIR_CALL_METHOD(&targetPath, resource, "getrealtargetpath", NULL, 0, completeTargetPath);
			zephir_check_call_status();
			if (!(zephir_is_true(targetPath))) {
				ZEPHIR_INIT_NVAR(_11$$17);
				object_init_ex(_11$$17, phalcon_assets_exception_ce);
				ZEPHIR_INIT_LNVAR(_12$$17);
				ZEPHIR_CONCAT_SVS(_12$$17, "Resource '", sourcePath, "' does not have a valid target path");
				ZEPHIR_CALL_METHOD(NULL, _11$$17, "__construct", NULL, 9, _12$$17);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11$$17, "phalcon/assets/manager.zep", 470 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(local)) {
				if (ZEPHIR_IS_EQUAL(targetPath, sourcePath)) {
					ZEPHIR_INIT_NVAR(_13$$19);
					object_init_ex(_13$$19, phalcon_assets_exception_ce);
					ZEPHIR_INIT_LNVAR(_14$$19);
					ZEPHIR_CONCAT_SVS(_14$$19, "Resource '", targetPath, "' have the same source and target paths");
					ZEPHIR_CALL_METHOD(NULL, _13$$19, "__construct", NULL, 9, _14$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(_13$$19, "phalcon/assets/manager.zep", 479 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if ((zephir_file_exists(targetPath TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_INIT_NVAR(_15$$20);
					if (zephir_compare_mtime(targetPath, sourcePath TSRMLS_CC)) {
						filterNeeded = 1;
					}
				} else {
					filterNeeded = 1;
				}
			}
		} else {
			ZEPHIR_CALL_METHOD(&path, resource, "getrealtargeturi", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(prefix)) {
				ZEPHIR_INIT_NVAR(prefixedPath);
				ZEPHIR_CONCAT_VV(prefixedPath, prefix, path);
			} else {
				ZEPHIR_CPY_WRT(prefixedPath, path);
			}
			ZEPHIR_CALL_METHOD(&attributes, resource, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(parameters);
			array_init(parameters);
			if (Z_TYPE_P(attributes) == IS_ARRAY) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				zephir_array_append(&parameters, attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 514);
			} else {
				zephir_array_append(&parameters, prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 516);
			}
			zephir_array_append(&parameters, local, PH_SEPARATE, "phalcon/assets/manager.zep", 518);
			ZEPHIR_INIT_NVAR(html);
			ZEPHIR_CALL_USER_FUNC_ARRAY(html, callback, parameters);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE(useImplicitOutput)) {
				zend_print_zval(html, 0);
			} else {
				zephir_concat_self(&output, html TSRMLS_CC);
			}
			continue;
		}
		if (filterNeeded == 1) {
			ZEPHIR_CALL_METHOD(&content, resource, "getcontent", NULL, 0, completeSourcePath);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&mustFilter, resource, "getfilter", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE(mustFilter)) {
				zephir_is_iterable(filters, &_17$$31, &_16$$31, 0, 0, "phalcon/assets/manager.zep", 571);
				for (
				  ; zend_hash_get_current_data_ex(_17$$31, (void**) &_18$$31, &_16$$31) == SUCCESS
				  ; zend_hash_move_forward_ex(_17$$31, &_16$$31)
				) {
					ZEPHIR_GET_HVALUE(filter, _18$$31);
					if (Z_TYPE_P(filter) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 559);
						return;
					}
					ZEPHIR_CALL_METHOD(&filteredContent, filter, "filter", NULL, 0, content);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(content, filteredContent);
				}
				if (ZEPHIR_IS_TRUE(join)) {
					if (ZEPHIR_IS_EQUAL(type, typeCss)) {
						zephir_concat_self(&filteredJoinedContent, filteredContent TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_19$$36);
						ZEPHIR_CONCAT_VS(_19$$36, filteredContent, ";");
						zephir_concat_self(&filteredJoinedContent, _19$$36 TSRMLS_CC);
					}
				}
			} else {
				if (ZEPHIR_IS_TRUE(join)) {
					zephir_concat_self(&filteredJoinedContent, content TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(filteredContent, content);
				}
			}
			if (!(zephir_is_true(join))) {
				zephir_file_put_contents(NULL, targetPath, filteredContent TSRMLS_CC);
			}
		}
		if (!(zephir_is_true(join))) {
			ZEPHIR_CALL_METHOD(&path, resource, "getrealtargeturi", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(prefix)) {
				ZEPHIR_INIT_NVAR(prefixedPath);
				ZEPHIR_CONCAT_VV(prefixedPath, prefix, path);
			} else {
				ZEPHIR_CPY_WRT(prefixedPath, path);
			}
			ZEPHIR_CALL_METHOD(&attributes, resource, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
			ZEPHIR_INIT_NVAR(parameters);
			array_init(parameters);
			if (Z_TYPE_P(attributes) == IS_ARRAY) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				zephir_array_append(&parameters, attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 628);
			} else {
				zephir_array_append(&parameters, prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 630);
			}
			zephir_array_append(&parameters, local, PH_SEPARATE, "phalcon/assets/manager.zep", 632);
			ZEPHIR_INIT_NVAR(html);
			ZEPHIR_CALL_USER_FUNC_ARRAY(html, callback, parameters);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE(useImplicitOutput)) {
				zend_print_zval(html, 0);
			} else {
				zephir_concat_self(&output, html TSRMLS_CC);
			}
		}
	}
	if (zephir_fast_count_int(filters TSRMLS_CC)) {
		if (ZEPHIR_IS_TRUE(join)) {
			zephir_file_put_contents(NULL, completeTargetPath, filteredJoinedContent TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&targetUri, collection, "gettargeturi", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(prefix)) {
				ZEPHIR_INIT_NVAR(prefixedPath);
				ZEPHIR_CONCAT_VV(prefixedPath, prefix, targetUri);
			} else {
				ZEPHIR_CPY_WRT(prefixedPath, targetUri);
			}
			ZEPHIR_CALL_METHOD(&attributes, collection, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&local, collection, "gettargetlocal", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(parameters);
			array_init(parameters);
			if (Z_TYPE_P(attributes) == IS_ARRAY) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				zephir_array_append(&parameters, attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 687);
			} else {
				zephir_array_append(&parameters, prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 689);
			}
			zephir_array_append(&parameters, local, PH_SEPARATE, "phalcon/assets/manager.zep", 691);
			ZEPHIR_INIT_NVAR(html);
			ZEPHIR_CALL_USER_FUNC_ARRAY(html, callback, parameters);
			zephir_check_call_status();
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
 * Traverses a collection and generate its HTML
 *
 * @param \Phalcon\Assets\Collection collection
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInline) {

	HashTable *_1$$3, *_4$$4;
	HashPosition _0$$3, _3$$4;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *type, *output = NULL, *html = NULL, *codes = NULL, *filters = NULL, *filter = NULL, *code = NULL, *attributes = NULL, *content = NULL, *join = NULL, *joinedContent = NULL, **_2$$3, *_19$$3, **_5$$4, *_6$$5 = NULL, *_7$$8 = NULL, *_9$$8 = NULL, *_10$$8 = NULL, *_11$$8 = NULL, *_13$$8 = NULL, *_14$$9 = NULL, *_15$$9 = NULL, *_16$$9, *_17$$9 = NULL, *_18$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection, &type);



	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_INIT_VAR(html);
	ZVAL_STRING(html, "", 1);
	ZEPHIR_INIT_VAR(joinedContent);
	ZVAL_STRING(joinedContent, "", 1);
	ZEPHIR_CALL_METHOD(&codes, collection, "getcodes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filters, collection, "getfilters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&join, collection, "getjoin", NULL, 0);
	zephir_check_call_status();
	if (zephir_fast_count_int(codes TSRMLS_CC)) {
		zephir_is_iterable(codes, &_1$$3, &_0$$3, 0, 0, "phalcon/assets/manager.zep", 756);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(code, _2$$3);
			ZEPHIR_CALL_METHOD(&attributes, code, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&content, code, "getcontent", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(filters, &_4$$4, &_3$$4, 0, 0, "phalcon/assets/manager.zep", 749);
			for (
			  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
			) {
				ZEPHIR_GET_HVALUE(filter, _5$$4);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 740);
					return;
				}
				ZEPHIR_CALL_METHOD(&_6$$5, filter, "filter", NULL, 0, content);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(content, _6$$5);
			}
			if (zephir_is_true(join)) {
				zephir_concat_self(&joinedContent, content TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_9$$8);
				ZVAL_BOOL(_9$$8, 0);
				ZEPHIR_INIT_NVAR(_10$$8);
				ZVAL_BOOL(_10$$8, 1);
				ZEPHIR_CALL_CE_STATIC(&_7$$8, phalcon_tag_ce, "taghtml", &_8, 0, type, attributes, _9$$8, _10$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_9$$8);
				ZVAL_BOOL(_9$$8, 1);
				ZEPHIR_CALL_CE_STATIC(&_11$$8, phalcon_tag_ce, "taghtmlclose", &_12, 0, type, _9$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13$$8);
				ZEPHIR_CONCAT_VVV(_13$$8, _7$$8, content, _11$$8);
				zephir_concat_self(&html, _13$$8 TSRMLS_CC);
			}
		}
		if (zephir_is_true(join)) {
			ZEPHIR_INIT_VAR(_15$$9);
			ZVAL_BOOL(_15$$9, 0);
			ZEPHIR_INIT_VAR(_16$$9);
			ZVAL_BOOL(_16$$9, 1);
			ZEPHIR_CALL_CE_STATIC(&_14$$9, phalcon_tag_ce, "taghtml", &_8, 0, type, attributes, _15$$9, _16$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_15$$9);
			ZVAL_BOOL(_15$$9, 1);
			ZEPHIR_CALL_CE_STATIC(&_17$$9, phalcon_tag_ce, "taghtmlclose", &_12, 0, type, _15$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_18$$9);
			ZEPHIR_CONCAT_VVV(_18$$9, _14$$9, joinedContent, _17$$9);
			zephir_concat_self(&html, _18$$9 TSRMLS_CC);
		}
		_19$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(_19$$3)) {
			zend_print_zval(html, 0);
		} else {
			zephir_concat_self(&output, html TSRMLS_CC);
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

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, *collection = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getcss", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Phalcon\\Tag", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "stylesheetLink", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, collection, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the HTML for inline CSS
 *
 * @param string collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, *collection = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getcss", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "style", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "outputinline", NULL, 0, collection, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the HTML for JS resources
 *
 * @param string collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, *collection = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getjs", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Phalcon\\Tag", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "javascriptInclude", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "js", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, collection, _0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the HTML for inline JS
 *
 * @param string collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, *collection = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getjs", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "script", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "outputinline", NULL, 0, collection, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns existing collections in the manager
 */
PHP_METHOD(Phalcon_Assets_Manager, getCollections) {

	

	RETURN_MEMBER(getThis(), "_collections");

}

/**
 * Returns true or false if collection exists.
 *
 * <code>
 * if ($assets->exists("jsHeader")) {
 *     // \Phalcon\Assets\Collection
 *     $collection = $assets->get("jsHeader");
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Manager, exists) {

	zval *id_param = NULL, *_0;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, id));

}


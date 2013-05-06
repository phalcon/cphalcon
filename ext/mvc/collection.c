
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
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

#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */


/**
 * Phalcon\Mvc\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Collection, mvc_collection, phalcon_mvc_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_id"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_reserved"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_collection_ce, SL("_disableEvents"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_NONE"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_CREATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 3, phalcon_mvc_collectioninterface_ce, phalcon_di_injectionawareinterface_ce, zend_ce_serializable);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param Phalcon\Mvc\Collection\ManagerInterface $modelsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection, __construct){

	zval *dependency_injector = NULL, *models_manager = NULL;
	zval *service_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &dependency_injector, &models_manager);
	
	if (!dependency_injector) {
		PHALCON_INIT_VAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	if (!models_manager) {
		PHALCON_INIT_VAR(models_manager);
	} else {
		PHALCON_SEPARATE_PARAM(models_manager);
	}
	
	/** 
	 * We use a default DI if the user doesn't define one
	 */
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	/** 
	 * Inject the manager service from the DI
	 */
	if (Z_TYPE_P(models_manager) != IS_OBJECT) {
	
		PHALCON_INIT_VAR(service_name);
		ZVAL_STRING(service_name, "collectionManager", 1);
	
		PHALCON_INIT_NVAR(models_manager);
		PHALCON_CALL_METHOD_PARAMS_1(models_manager, dependency_injector, "getshared", service_name);
		if (Z_TYPE_P(models_manager) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
			return;
		}
	}
	
	/** 
	 * Update the models-manager
	 */
	phalcon_update_property_this(this_ptr, SL("_modelsManager"), models_manager TSRMLS_CC);
	
	/** 
	 * The manager always initializes the object
	 */
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(models_manager, "initialize", this_ptr);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed $id
 */
PHP_METHOD(Phalcon_Mvc_Collection, setId){

	zval *id, *models_manager, *use_implicit_ids;
	zval *mongo_id = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);
	
	if (Z_TYPE_P(id) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(models_manager);
		phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		/** 
		 * Check if the model use implicit ids
		 */
		PHALCON_INIT_VAR(use_implicit_ids);
		PHALCON_CALL_METHOD_PARAMS_1(use_implicit_ids, models_manager, "isusingimplicitobjectids", this_ptr);
		if (zend_is_true(use_implicit_ids)) {
			ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce0);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	} else {
		PHALCON_CPY_WRT(mongo_id, id);
	}
	phalcon_update_property_this(this_ptr, SL("_id"), mongo_id TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the value of the _id property
 *
 * @return \MongoId
 */
PHP_METHOD(Phalcon_Mvc_Collection, getId){


	RETURN_MEMBER(this_ptr, "_id");
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a custom events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager){

	zval *events_manager, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &events_manager);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(models_manager, "setcustomeventsmanager", this_ptr, events_manager);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager){

	zval *models_manager, *events_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(events_manager);
	PHALCON_CALL_METHOD_PARAMS_1(events_manager, models_manager, "getcustomeventsmanager", this_ptr);
	RETURN_CCTOR(events_manager);
}

/**
 * Returns the models manager related to the entity instance
 *
 * @return Phalcon\Mvc\Model\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getModelsManager){


	RETURN_MEMBER(this_ptr, "_modelsManager");
}

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes){

	zval *reserved = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(reserved);
	phalcon_read_static_property(&reserved, SL("phalcon\\mvc\\collection"), SL("_reserved") TSRMLS_CC);
	if (Z_TYPE_P(reserved) == IS_NULL) {
		PHALCON_INIT_NVAR(reserved);
		array_init_size(reserved, 5);
		add_assoc_bool_ex(reserved, SS("_connection"), 1);
		add_assoc_bool_ex(reserved, SS("_dependencyInjector"), 1);
		add_assoc_bool_ex(reserved, SS("_source"), 1);
		add_assoc_bool_ex(reserved, SS("_operationMade"), 1);
		add_assoc_bool_ex(reserved, SS("_errorMessages"), 1);
		phalcon_update_static_property(SL("phalcon\\mvc\\collection"), SL("_reserved"), reserved TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(reserved);
}

/**
 * Sets if a model must use implicit objects ids
 *
 * @param boolean $useImplicitObjectIds
 */
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds){

	zval *use_implicit_object_ids, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &use_implicit_object_ids);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(models_manager, "useimplicitobjectids", this_ptr, use_implicit_object_ids);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets collection name which model should be mapped
 *
 * @param string $source
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, setSource){

	zval *source;

	phalcon_fetch_params(0, 1, 0, &source);
	
	phalcon_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns collection name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getSource){

	zval *source = NULL, *class_name;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(source);
	phalcon_read_property_this(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	if (!zend_is_true(source)) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class_ns(class_name, this_ptr, 0 TSRMLS_CC);
	
		PHALCON_INIT_NVAR(source);
		phalcon_uncamelize(source, class_name TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(source);
}

/**
 * Sets the DependencyInjection connection service name
 *
 * @param string $connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService){

	zval *connection_service, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &connection_service);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(models_manager, "setconnectionservice", this_ptr, connection_service);
	RETURN_THIS();
}

/**
 * Returns DependencyInjection connection service
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService){

	zval *models_manager, *connection_service;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(connection_service);
	PHALCON_CALL_METHOD_PARAMS_1(connection_service, models_manager, "getconnectionservice", this_ptr);
	RETURN_CCTOR(connection_service);
}

/**
 * Retrieves a database connection
 *
 * @return \MongoDb
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnection){

	zval *connection = NULL, *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_OBS_VAR(models_manager);
		phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD_PARAMS_1(connection, models_manager, "getconnection", this_ptr);
		phalcon_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Reads an attribute value by its name
 *
 *<code>
 *	echo $robot->readAttribute('name');
 *</code>
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute){

	zval *attribute, *attribute_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &attribute);
	
	if (phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
		PHALCON_OBS_VAR(attribute_value);
		phalcon_read_property_zval(&attribute_value, this_ptr, attribute, PH_NOISY_CC);
		RETURN_CCTOR(attribute_value);
	}
	RETURN_MM_NULL();
}

/**
 * Writes an attribute value by its name
 *
 * <code>
 *	$robot->writeAttribute('name', 'Rosey');
 * </code>
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute){

	zval *attribute, *value;

	phalcon_fetch_params(0, 2, 0, &attribute, &value);
	
	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
}

/**
 * Returns a cloned collection
 *
 * @param Phalcon\Mvc\Collection $collection
 * @param array $document
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult){

	zval *collection, *document, *cloned_collection;
	zval *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &collection, &document);
	
	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid collection");
		return;
	}
	if (Z_TYPE_P(document) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid document");
		return;
	}
	
	PHALCON_INIT_VAR(cloned_collection);
	if (phalcon_clone(cloned_collection, collection TSRMLS_CC) == FAILURE) {
		return;
	}
	
	if (!phalcon_is_iterable(document, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(cloned_collection, "writeattribute", key, value);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CCTOR(cloned_collection);
}

/**
 * Returns a collection resultset
 *
 * @param array $params
 * @param Phalcon\Mvc\Collection $collection
 * @param \MongoDb $connection
 * @param boolean $unique
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset){

	zval *params, *collection, *connection, *unique;
	zval *source, *mongo_collection, *conditions = NULL;
	zval *documents_cursor, *limit, *sort = NULL, *document = NULL;
	zval *collection_cloned = NULL, *collections, *documents_array;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &params, &collection, &connection, &unique);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(mongo_collection);
	PHALCON_CALL_METHOD_PARAMS_1(mongo_collection, connection, "selectcollection", source);
	
	/** 
	 * Convert the string to an array
	 */
	if (phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
	} else {
		if (phalcon_array_isset_string(params, SS("conditions"))) {
			PHALCON_OBS_NVAR(conditions);
			phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(conditions);
			array_init(conditions);
		}
	}
	
	/** 
	 * Perform the find
	 */
	PHALCON_INIT_VAR(documents_cursor);
	PHALCON_CALL_METHOD_PARAMS_1(documents_cursor, mongo_collection, "find", conditions);
	
	/** 
	 * Check if a 'limit' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, params, SL("limit"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(documents_cursor, "limit", limit);
	}
	
	/** 
	 * Check if a 'sort' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("sort"))) {
		PHALCON_OBS_VAR(sort);
		phalcon_array_fetch_string(&sort, params, SL("sort"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(documents_cursor, "sort", sort);
	}
	
	/** 
	 * Check if a 'skip' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("skip"))) {
		PHALCON_OBS_NVAR(sort);
		phalcon_array_fetch_string(&sort, params, SL("skip"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(documents_cursor, "skip", sort);
	}
	
	if (PHALCON_IS_TRUE(unique)) {
	
		/** 
		 * Requesting a unique row
		 */
		PHALCON_CALL_METHOD_NORETURN(documents_cursor, "rewind");
	
		PHALCON_INIT_VAR(document);
		PHALCON_CALL_METHOD(document, documents_cursor, "current");
		if (Z_TYPE_P(document) == IS_ARRAY) { 
			PHALCON_INIT_VAR(collection_cloned);
			PHALCON_CALL_SELF_PARAMS_2(collection_cloned, this_ptr, "cloneresult", collection, document);
			RETURN_CCTOR(collection_cloned);
		}
	
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Requesting a complete resultset
	 */
	PHALCON_INIT_VAR(collections);
	array_init(collections);
	
	PHALCON_INIT_VAR(documents_array);
	PHALCON_CALL_FUNC_PARAMS_1(documents_array, "iterator_to_array", documents_cursor);
	
	if (!phalcon_is_iterable(documents_array, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(document);
	
		PHALCON_INIT_NVAR(collection_cloned);
		PHALCON_CALL_SELF_PARAMS_2(collection_cloned, this_ptr, "cloneresult", collection, document);
		phalcon_array_append(&collections, collection_cloned, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(collections);
}

/**
 * Perform a count over a resultset
 *
 * @param array $params
 * @param Phalcon\Mvc\Collection $collection
 * @param \MongoDb $connection
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset){

	zval *params, *collection, *connection, *source;
	zval *mongo_collection, *conditions = NULL, *simple = NULL;
	zval *documents_cursor, *limit, *sort = NULL, *group = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &params, &collection, &connection);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(mongo_collection);
	PHALCON_CALL_METHOD_PARAMS_1(mongo_collection, connection, "selectcollection", source);
	
	/** 
	 * Convert the string to an array
	 */
	if (phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
	} else {
		if (phalcon_array_isset_string(params, SS("conditions"))) {
			PHALCON_OBS_NVAR(conditions);
			phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(conditions);
			array_init(conditions);
		}
	}
	
	PHALCON_INIT_VAR(simple);
	ZVAL_BOOL(simple, 1);
	if (phalcon_array_isset_string(params, SS("limit"))) {
		ZVAL_BOOL(simple, 0);
	} else {
		if (phalcon_array_isset_string(params, SS("sort"))) {
			ZVAL_BOOL(simple, 0);
		} else {
			if (phalcon_array_isset_string(params, SS("skip"))) {
				ZVAL_BOOL(simple, 0);
			}
		}
	}
	
	if (PHALCON_IS_FALSE(simple)) {
	
		/** 
		 * Perform the find
		 */
		PHALCON_INIT_VAR(documents_cursor);
		PHALCON_CALL_METHOD_PARAMS_1(documents_cursor, mongo_collection, "find", conditions);
	
		/** 
		 * Check if a 'limit' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("limit"))) {
			PHALCON_OBS_VAR(limit);
			phalcon_array_fetch_string(&limit, params, SL("limit"), PH_NOISY_CC);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(documents_cursor, "limit", limit);
		}
	
		/** 
		 * Check if a 'sort' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("sort"))) {
			PHALCON_OBS_VAR(sort);
			phalcon_array_fetch_string(&sort, params, SL("sort"), PH_NOISY_CC);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(documents_cursor, "sort", sort);
		}
	
		/** 
		 * Check if a 'skip' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("skip"))) {
			PHALCON_OBS_NVAR(sort);
			phalcon_array_fetch_string(&sort, params, SL("skip"), PH_NOISY_CC);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(documents_cursor, "skip", sort);
		}
	
		/** 
		 * Only 'count' is supported
		 */
		PHALCON_INIT_VAR(group);
		phalcon_fast_count(group, documents_cursor TSRMLS_CC);
	}
	
	PHALCON_INIT_NVAR(group);
	PHALCON_CALL_METHOD_PARAMS_1(group, mongo_collection, "count", conditions);
	
	RETURN_CCTOR(group);
}

/**
 * Executes internal hooks before save a document
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param boolean $disableEvents
 * @param boolean $exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _preSave){

	zval *dependency_injector, *disable_events;
	zval *exists, *event_name = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &dependency_injector, &disable_events, &exists);
	
	/** 
	 * Run Validation Callbacks Before
	 */
	if (!zend_is_true(disable_events)) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeValidation", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeValidationOnUpdate", 1);
		}
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Run validation
	 */
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "validation", 1);
	
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
	if (PHALCON_IS_FALSE(status)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
		}
		RETURN_MM_FALSE;
	}
	
	if (!zend_is_true(disable_events)) {
	
		/** 
		 * Run Validation Callbacks After
		 */
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnUpdate", 1);
		}
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "afterValidation", 1);
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * Run Before Callbacks
		 */
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "beforeSave", 1);
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		if (zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeUpdate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeCreate", 1);
		}
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Executes internal events after save a document
 *
 * @param boolean $disableEvents
 * @param boolean $success
 * @param boolean $exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _postSave){

	zval *disable_events, *success, *exists, *event_name = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &disable_events, &success, &exists);
	
	if (PHALCON_IS_TRUE(success)) {
		if (!zend_is_true(disable_events)) {
			if (PHALCON_IS_TRUE(exists)) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "afterUpdate", 1);
			} else {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "afterCreate", 1);
			}
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
		}
	
		RETURN_CCTOR(success);
	}
	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "notSave", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	}
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_canceloperation", disable_events);
	RETURN_MM_FALSE;
}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Collection
 *{
 *
 *	public function validation()
 *	{
 *		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @param object $validator
 */
PHP_METHOD(Phalcon_Mvc_Collection, validate){

	zval *validator, *status, *messages, *message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &validator);
	
	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Validator must be an Object");
		return;
	}
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, validator, "validate", this_ptr);
	if (PHALCON_IS_FALSE(status)) {
	
		PHALCON_INIT_VAR(messages);
		PHALCON_CALL_METHOD(messages, validator, "getmessages");
	
		if (!phalcon_is_iterable(messages, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(message);
	
			phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Collection
 *{
 *
 *	public function validation()
 *	{
 *		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed){

	zval *error_messages;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(error_messages);
	phalcon_read_property_this(&error_messages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(error_messages) == IS_ARRAY) { 
		if (phalcon_fast_count_ev(error_messages TSRMLS_CC)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Fires an internal event
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent){

	zval *event_name, *models_manager, *success;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &event_name);
	
	/** 
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, Z_STRVAL_P(event_name));
	}
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_2(success, models_manager, "notifyevent", event_name, this_ptr);
	
	RETURN_CCTOR(success);
}

/**
 * Fires an internal event that cancels the operation
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel){

	zval *event_name, *status = NULL, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &event_name);
	
	/** 
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD(status, this_ptr, Z_STRVAL_P(event_name));
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, models_manager, "notifyevent", event_name, this_ptr);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

/**
 * Cancel the current operation
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation){

	zval *disable_events, *operation_made, *event_name = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &disable_events);
	
	if (!zend_is_true(disable_events)) {
	
		PHALCON_OBS_VAR(operation_made);
		phalcon_read_property_this(&operation_made, this_ptr, SL("_operationMade"), PH_NOISY_CC);
		if (PHALCON_IS_LONG(operation_made, 3)) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "notDeleted", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "notSaved", 1);
		}
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	}
	RETURN_MM_FALSE;
}

/**
 * Checks if the document exists in the collection
 *
 * @param \MongoCollection $collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, _exists){

	zval *collection, *id, *mongo_id = NULL, *models_manager;
	zval *use_implicit_ids, *parameters, *document_count;
	zval *zero, *exist;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &collection);
	
	if (phalcon_isset_property(this_ptr, SS("_id") TSRMLS_CC)) {
	
		PHALCON_OBS_VAR(id);
		phalcon_read_property_this(&id, this_ptr, SL("_id"), PH_NOISY_CC);
		if (Z_TYPE_P(id) == IS_OBJECT) {
			PHALCON_CPY_WRT(mongo_id, id);
		} else {
			PHALCON_OBS_VAR(models_manager);
			phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
			/** 
			 * Check if the model use implicit ids
			 */
			PHALCON_INIT_VAR(use_implicit_ids);
			PHALCON_CALL_METHOD_PARAMS_1(use_implicit_ids, models_manager, "isusingimplicitobjectids", this_ptr);
			if (zend_is_true(use_implicit_ids)) {
				ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				PHALCON_INIT_VAR(mongo_id);
				object_init_ex(mongo_id, ce0);
				if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(mongo_id, "__construct", id);
				}
				phalcon_update_property_this(this_ptr, SL("_id"), mongo_id TSRMLS_CC);
			} else {
				PHALCON_CPY_WRT(mongo_id, id);
			}
		}
	
		PHALCON_INIT_VAR(parameters);
		array_init_size(parameters, 1);
		phalcon_array_update_string(&parameters, SL("_id"), &mongo_id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * Perform the count using the function provided by the driver
		 */
		PHALCON_INIT_VAR(document_count);
		PHALCON_CALL_METHOD_PARAMS_1(document_count, collection, "count", parameters);
	
		PHALCON_INIT_VAR(zero);
		ZVAL_LONG(zero, 0);
	
		PHALCON_INIT_VAR(exist);
		is_smaller_function(exist, zero, document_count TSRMLS_CC);
	
		RETURN_NCTOR(exist);
	}
	RETURN_MM_FALSE;
}

/**
 * Returns all the validation messages
 *
 * <code>
 *$robot = new Robots();
 *$robot->type = 'mechanical';
 *$robot->name = 'Astro Boy';
 *$robot->year = 1952;
 *if ($robot->save() == false) {
 *	echo "Umh, We can't store robots right now ";
 *	foreach ($robot->getMessages() as $message) {
 *		echo $message;
 *	}
 *} else {
 *	echo "Great, a new robot was saved successfully!";
 *}
 * </code>
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Collection, getMessages){


	RETURN_MEMBER(this_ptr, "_errorMessages");
}

/**
 * Appends a customized message on the validation process
 *
 *<code>
 *	use \Phalcon\Mvc\Model\Message as Message;
 *
 *	class Robots extends Phalcon\Mvc\Model
 *	{
 *
 *		public function beforeSave()
 *		{
 *			if ($this->name == 'Peter') {
 *				$message = new Message("Sorry, but a robot cannot be named Peter");
 *				$this->appendMessage($message);
 *			}
 *		}
 *	}
 *</code>
 *
 * @param Phalcon\Mvc\Model\MessageInterface $message
 */
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage){

	zval *message, *type, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_FUNC_PARAMS_1(type, "gettype", message);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid message format '", type, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Creates/Updates a collection based on the values in the atributes
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, save){

	zval *dependency_injector, *source, *connection;
	zval *collection, *exists, *empty_array, *disable_events;
	zval *status = NULL, *data, *reserved, *properties, *value = NULL;
	zval *key = NULL, *success = NULL, *options, *ok, *id, *post_success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection");
	
	/** 
	 * Choose a collection according to the collection name
	 */
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD_PARAMS_1(collection, connection, "selectcollection", source);
	
	/** 
	 * Check the dirty state of the current operation to update the current operation
	 */
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_1(exists, this_ptr, "_exists", collection);
	if (PHALCON_IS_FALSE(exists)) {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 2 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	/** 
	 * The messages added to the validator are reset here
	 */
	phalcon_update_property_this(this_ptr, SL("_errorMessages"), empty_array TSRMLS_CC);
	
	PHALCON_OBS_VAR(disable_events);
	phalcon_read_static_property(&disable_events, SL("phalcon\\mvc\\collection"), SL("_disableEvents") TSRMLS_CC);
	
	/** 
	 * Execute the preSave hook
	 */
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_3(status, this_ptr, "_presave", dependency_injector, disable_events, exists);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	
	PHALCON_INIT_VAR(reserved);
	PHALCON_CALL_METHOD(reserved, this_ptr, "getreservedattributes");
	
	PHALCON_INIT_VAR(properties);
	PHALCON_CALL_FUNC_PARAMS_1(properties, "get_object_vars", this_ptr);
	
	/** 
	 * We only assign values to the public properties
	 */
	
	if (!phalcon_is_iterable(properties, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		if (PHALCON_IS_STRING(key, "_id")) {
			if (Z_TYPE_P(value) != IS_NULL) {
				phalcon_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
		} else {
			if (!phalcon_array_isset(reserved, key)) {
				phalcon_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(success);
	ZVAL_BOOL(success, 0);
	
	/** 
	 * We always use safe stores to get the success state
	 */
	PHALCON_INIT_VAR(options);
	array_init_size(options, 1);
	add_assoc_bool_ex(options, SS("safe"), 1);
	
	/** 
	 * Save the document
	 */
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, collection, "save", data, options);
	if (Z_TYPE_P(status) == IS_ARRAY) { 
		if (phalcon_array_isset_string(status, SS("ok"))) {
	
			PHALCON_OBS_VAR(ok);
			phalcon_array_fetch_string(&ok, status, SL("ok"), PH_NOISY_CC);
			if (zend_is_true(ok)) {
	
				ZVAL_BOOL(success, 1);
				if (PHALCON_IS_FALSE(exists)) {
					if (phalcon_array_isset_string(data, SS("_id"))) {
						PHALCON_OBS_VAR(id);
						phalcon_array_fetch_string(&id, data, SL("_id"), PH_NOISY_CC);
						phalcon_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);
					}
				}
			}
		}
	} else {
		ZVAL_BOOL(success, 0);
	}
	
	/** 
	 * Call the postSave hooks
	 */
	PHALCON_INIT_VAR(post_success);
	PHALCON_CALL_METHOD_PARAMS_3(post_success, this_ptr, "_postsave", disable_events, success, exists);
	
	RETURN_CCTOR(post_success);
}

/**
 * Find a document by its id (_id)
 *
 * @param string|\MongoId $id
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, findById){

	zval *id, *class_name, *collection, *models_manager;
	zval *use_implicit_ids, *mongo_id = NULL, *conditions;
	zval *parameters, *result;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);
	
	if (Z_TYPE_P(id) != IS_OBJECT) {
	
		PHALCON_INIT_VAR(class_name);
		phalcon_get_called_class(class_name  TSRMLS_CC);
		ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
		PHALCON_INIT_VAR(collection);
		object_init_ex(collection, ce0);
		if (phalcon_has_constructor(collection TSRMLS_CC)) {
			PHALCON_CALL_METHOD_NORETURN(collection, "__construct");
		}
	
		PHALCON_INIT_VAR(models_manager);
		PHALCON_CALL_METHOD(models_manager, collection, "getmodelsmanager");
	
		/** 
		 * Check if the model use implicit ids
		 */
		PHALCON_INIT_VAR(use_implicit_ids);
		PHALCON_CALL_METHOD_PARAMS_1(use_implicit_ids, models_manager, "isusingimplicitobjectids", collection);
		if (zend_is_true(use_implicit_ids)) {
			ce1 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce1);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	} else {
		PHALCON_CPY_WRT(mongo_id, id);
	}
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("_id"), &mongo_id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(parameters);
	array_init_size(parameters, 1);
	phalcon_array_append(&parameters, conditions, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_SELF_PARAMS_1(result, this_ptr, "findfirst", parameters);
	
	RETURN_CCTOR(result);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in the robots table?
 * $robot = Robots::findFirst();
 * echo "The robot name is ", $robot->name, "\n";
 *
 * //What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(array(
 *     array("type" => "mechanical")
 * ));
 * echo "The first mechanical robot name is ", $robot->name, "\n";
 *
 * //Get first virtual robot ordered by name
 * $robot = Robots::findFirst(array(
 *     array("type" => "mechanical"),
 *     "order" => array("name" => 1)
 * ));
 * echo "The first virtual robot name is ", $robot->name, "\n";
 *
 * </code>
 *
 * @param array $parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, findFirst){

	zval *parameters = NULL, *class_name, *collection, *connection;
	zval *unique, *resultset;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_NULL) {
		if (Z_TYPE_P(parameters) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for findFirst");
			return;
		}
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD_NORETURN(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, collection, "getconnection");
	
	PHALCON_INIT_VAR(unique);
	ZVAL_BOOL(unique, 1);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_SELF_PARAMS_4(resultset, this_ptr, "_getresultset", parameters, collection, connection, unique);
	
	RETURN_CCTOR(resultset);
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $robots = Robots::find();
 * echo "There are ", count($robots), "\n";
 *
 * //How many mechanical robots are there?
 * $robots = Robots::find(array(
 *     array("type" => "mechanical")
 * ));
 * echo "There are ", count($robots), "\n";
 *
 * //Get and print virtual robots ordered by name
 * $robots = Robots::findFirst(array(
 *     array("type" => "virtual"),
 *     "order" => array("name" => 1)
 * ));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
 * //Get first 100 virtual robots ordered by name
 * $robots = Robots::find(array(
 *     array("type" => "virtual"),
 *     "order" => array("name" => 1),
 *     "limit" => 100
 * ));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 *
 * @param 	array $parameters
 * @return  array
 */
PHP_METHOD(Phalcon_Mvc_Collection, find){

	zval *parameters = NULL, *class_name, *collection, *connection;
	zval *unique, *resultset;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_NULL) {
		if (Z_TYPE_P(parameters) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for find");
			return;
		}
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD_NORETURN(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, collection, "getconnection");
	
	PHALCON_INIT_VAR(unique);
	ZVAL_BOOL(unique, 0);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_SELF_PARAMS_4(resultset, this_ptr, "_getresultset", parameters, collection, connection, unique);
	
	RETURN_CCTOR(resultset);
}

/**
 * Perform a count over a collection
 *
 *<code>
 * echo 'There are ', Robots::count(), ' robots';
 *</code>
 *
 * @param array $parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, count){

	zval *parameters = NULL, *class_name, *collection, *connection;
	zval *result;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_NULL) {
		if (Z_TYPE_P(parameters) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for count");
			return;
		}
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD_NORETURN(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, collection, "getconnection");
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_SELF_PARAMS_3(result, this_ptr, "_getgroupresultset", parameters, collection, connection);
	
	RETURN_CCTOR(result);
}

/**
 * Perform an aggregation using the Mongo aggregation framework
 *
 * @param array $parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, aggregate){

	zval *parameters, *class_name, *model, *connection;
	zval *source, *collection, *agregation;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);
	
	if (Z_TYPE_P(parameters) != IS_NULL) {
		if (Z_TYPE_P(parameters) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for aggregate");
			return;
		}
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(model);
	object_init_ex(model, ce0);
	if (phalcon_has_constructor(model TSRMLS_CC)) {
		PHALCON_CALL_METHOD_NORETURN(model, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection");
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, model, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD_PARAMS_1(collection, connection, "selectcollection", source);
	
	PHALCON_INIT_VAR(agregation);
	PHALCON_CALL_METHOD_PARAMS_1(agregation, collection, "aggregate", parameters);
	
	RETURN_CCTOR(agregation);
}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *
 *	$robot = Robots::findFirst();
 *	$robot->delete();
 *
 *	foreach (Robots::find() as $robot) {
 *		$robot->delete();
 *	}
 * </code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, delete){

	zval *disable_events, *event_name = NULL, *status = NULL, *id;
	zval *connection, *source, *collection, *mongo_id = NULL;
	zval *models_manager, *use_implicit_ids, *id_condition;
	zval *success = NULL, *options, *ok;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (!phalcon_isset_property(this_ptr, SS("_id") TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The document cannot be deleted because it doesn't exist");
		return;
	}
	
	PHALCON_OBS_VAR(disable_events);
	phalcon_read_static_property(&disable_events, SL("phalcon\\mvc\\collection"), SL("_disableEvents") TSRMLS_CC);
	if (!zend_is_true(disable_events)) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeDelete", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_OBS_VAR(id);
	phalcon_read_property_this(&id, this_ptr, SL("_id"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection");
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	/** 
	 * Get the \MongoCollection
	 */
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD_PARAMS_1(collection, connection, "selectcollection", source);
	if (Z_TYPE_P(id) == IS_OBJECT) {
		PHALCON_CPY_WRT(mongo_id, id);
	} else {
		PHALCON_OBS_VAR(models_manager);
		phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		/** 
		 * Is the collection using implicit object Ids?
		 */
		PHALCON_INIT_VAR(use_implicit_ids);
		PHALCON_CALL_METHOD_PARAMS_1(use_implicit_ids, models_manager, "isusingimplicitobjectids", this_ptr);
		if (zend_is_true(use_implicit_ids)) {
			ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce0);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	}
	
	PHALCON_INIT_VAR(id_condition);
	array_init_size(id_condition, 1);
	phalcon_array_update_string(&id_condition, SL("_id"), &mongo_id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(success);
	ZVAL_BOOL(success, 0);
	
	PHALCON_INIT_VAR(options);
	array_init_size(options, 1);
	add_assoc_bool_ex(options, SS("safe"), 1);
	
	/** 
	 * Remove the instance
	 */
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, collection, "remove", id_condition, options);
	if (Z_TYPE_P(status) != IS_ARRAY) { 
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Check the operation status
	 */
	if (phalcon_array_isset_string(status, SS("ok"))) {
	
		PHALCON_OBS_VAR(ok);
		phalcon_array_fetch_string(&ok, status, SL("ok"), PH_NOISY_CC);
		if (zend_is_true(ok)) {
	
			ZVAL_BOOL(success, 1);
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "afterDelete", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
			}
		}
	} else {
		ZVAL_BOOL(success, 0);
	}
	
	
	RETURN_NCTOR(success);
}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($robot->toArray());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, toArray){

	zval *data, *reserved, *properties, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(data);
	array_init(data);
	
	PHALCON_INIT_VAR(reserved);
	PHALCON_CALL_METHOD(reserved, this_ptr, "getreservedattributes");
	
	/** 
	 * Get an array with the values of the object
	 */
	PHALCON_INIT_VAR(properties);
	PHALCON_CALL_FUNC_PARAMS_1(properties, "get_object_vars", this_ptr);
	
	/** 
	 * We only assign values to the public properties
	 */
	
	if (!phalcon_is_iterable(properties, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		if (PHALCON_IS_STRING(key, "_id")) {
			if (Z_TYPE_P(value) != IS_NULL) {
				phalcon_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
		} else {
			if (!phalcon_array_isset(reserved, key)) {
				phalcon_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(data);
}

/**
 * Serializes the object ignoring connections or protected properties
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, serialize){

	zval *data, *serialize;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(data);
	PHALCON_CALL_METHOD(data, this_ptr, "toarray");
	
	/** 
	 * Use the standard serialize function to serialize the array data
	 */
	PHALCON_INIT_VAR(serialize);
	PHALCON_CALL_FUNC_PARAMS_1(serialize, "serialize", data);
	RETURN_CCTOR(serialize);
}

/**
 * Unserializes the object from a serialized string
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Collection, unserialize){

	zval *data, *attributes, *dependency_injector;
	zval *service, *manager, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	if (Z_TYPE_P(data) == IS_STRING) {
	
		PHALCON_INIT_VAR(attributes);
		PHALCON_CALL_FUNC_PARAMS_1(attributes, "unserialize", data);
		if (Z_TYPE_P(attributes) == IS_ARRAY) { 
	
			/** 
			 * Obtain the default DI
			 */
			PHALCON_INIT_VAR(dependency_injector);
			PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ODM");
				return;
			}
	
			/** 
			 * Update the dependency injector
			 */
			phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
			/** 
			 * Gets the default modelsManager service
			 */
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "collectionManager", 1);
	
			PHALCON_INIT_VAR(manager);
			PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service);
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'collectionManager' is not valid");
				return;
			}
	
			/** 
			 * Update the models manager
			 */
			phalcon_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
	
			/** 
			 * Update the objects attributes
			 */
	
			if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(value);
	
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			RETURN_MM_NULL();
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
	return;
}


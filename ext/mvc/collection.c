
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/variables.h"

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

	zval **dependency_injector = NULL, **models_manager = NULL;
	zval *di, *mm;
	zval *service_name;

	phalcon_fetch_params_ex(0, 2, &dependency_injector, &models_manager);
	
	PHALCON_MM_GROW();

	/** 
	 * We use a default DI if the user doesn't define one
	 */
	if (!dependency_injector || Z_TYPE_PP(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(di);
		phalcon_call_static(di, "phalcon\\di", "getdefault");
	}
	else {
		di = *dependency_injector;
	}

	PHALCON_VERIFY_INTERFACE_EX(di, phalcon_diinterface_ce, phalcon_mvc_model_exception_ce, 1);
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), di TSRMLS_CC);
	
	/** 
	 * Inject the manager service from the DI
	 */
	if (!models_manager || Z_TYPE_PP(models_manager) != IS_OBJECT) {
		PHALCON_ALLOC_GHOST_ZVAL(service_name);
		ZVAL_STRING(service_name, "collectionManager", 1);
	
		PHALCON_OBS_VAR(mm);
		phalcon_call_method_p1_ex(mm, &mm, di, "getshared", service_name);
		if (Z_TYPE_P(mm) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'collectionManager' is not valid");
			return;
		}
	}
	else {
		mm = *models_manager;
	}
	
	PHALCON_VERIFY_INTERFACE_EX(mm, phalcon_mvc_collection_managerinterface_ce, phalcon_mvc_model_exception_ce, 1);

	/** 
	 * Update the models-manager
	 */
	phalcon_update_property_this(this_ptr, SL("_modelsManager"), mm TSRMLS_CC);
	
	/** 
	 * The manager always initializes the object
	 */
	phalcon_call_method_p1_noret(mm, "initialize", this_ptr);
	
	/** 
	 * This allows the developer to execute initialization stuff every time an instance
	 * is created
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS) {
		phalcon_call_method_noret(this_ptr, "onconstruct");
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed $id
 */
PHP_METHOD(Phalcon_Mvc_Collection, setId){

	zval *id, *use_implicit_ids, *models_manager;
	zval *mongo_id = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);
	
	if (Z_TYPE_P(id) != IS_OBJECT) {
		models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		/** 
		 * Check if the model use implicit ids
		 */
		PHALCON_INIT_VAR(use_implicit_ids);
		phalcon_call_method_p1(use_implicit_ids, models_manager, "isusingimplicitobjectids", this_ptr);
		if (zend_is_true(use_implicit_ids)) {
			ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce0);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				phalcon_call_method_p1_noret(mongo_id, "__construct", id);
			}
		} else {
			mongo_id = id;
		}
	} else {
		mongo_id = id;
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
	
	models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	phalcon_call_method_p2_noret(models_manager, "setcustomeventsmanager", this_ptr, events_manager);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager){

	zval *models_manager;

	PHALCON_MM_GROW();

	models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	phalcon_call_method_p1(return_value, models_manager, "getcustomeventsmanager", this_ptr);
	RETURN_MM();
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

	zval *reserved;

	reserved = phalcon_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_reserved") TSRMLS_CC);
	if (Z_TYPE_P(reserved) == IS_NULL) {
		zval *dummy = PHALCON_GLOBAL(z_true);
	
		array_init_size(return_value, 5);
		Z_ADDREF_P(dummy);
		add_assoc_zval_ex(return_value, SS("_connection"), dummy);
		Z_ADDREF_P(dummy);
		add_assoc_zval_ex(return_value, SS("_dependencyInjector"), dummy);
		Z_ADDREF_P(dummy);
		add_assoc_zval_ex(return_value, SS("_source"), dummy);
		Z_ADDREF_P(dummy);
		add_assoc_zval_ex(return_value, SS("_operationMade"), dummy);
		Z_ADDREF_P(dummy);
		add_assoc_zval_ex(return_value, SS("_errorMessages"), dummy);

		phalcon_update_static_property_ce(phalcon_mvc_collection_ce, SL("_reserved"), return_value TSRMLS_CC);
		return;
	}

	RETURN_ZVAL(reserved, 1, 0);
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
	
	models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	phalcon_call_method_p2_noret(models_manager, "useimplicitobjectids", this_ptr, use_implicit_object_ids);
	
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
		phalcon_uncamelize(source, class_name);
		phalcon_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	}
	
	RETURN_CTOR(source);
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
	
	models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	phalcon_call_method_p2_noret(models_manager, "setconnectionservice", this_ptr, connection_service);
	RETURN_THIS();
}

/**
 * Returns DependencyInjection connection service
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService){

	zval *models_manager;

	PHALCON_MM_GROW();

	models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	phalcon_return_call_method_p1(models_manager, "getconnectionservice", this_ptr);
	RETURN_MM();
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
		models_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(connection);
		phalcon_call_method_p1(connection, models_manager, "getconnection", this_ptr);
		phalcon_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	}
	
	RETURN_CTOR(connection);
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
		RETURN_CTOR(attribute_value);
	}
	RETURN_MM_NULL();
}

/**
 * Writes an attribute value by its name
 *
 *<code>
 *	$robot->writeAttribute('name', 'Rosey');
 *</code>
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
		RETURN_MM();
	}
	
	phalcon_is_iterable(document, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		phalcon_call_method_p2_noret(cloned_collection, "writeattribute", key, value);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(cloned_collection);
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
	zval *fields, *documents_cursor = NULL, *limit, *sort = NULL;
	zval *base = NULL, *document = NULL, *collections, *documents_array;
	zval *collection_cloned = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &params, &collection, &connection, &unique);
	
	PHALCON_INIT_VAR(source);
	phalcon_call_method(source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(mongo_collection);
	phalcon_call_method_p1(mongo_collection, connection, "selectcollection", source);
	
	/** 
	 * Convert the string to an array
	 */
	if (phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("conditions"))) {
			PHALCON_OBS_NVAR(conditions);
			phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY);
		} else {
			PHALCON_INIT_NVAR(conditions);
			array_init(conditions);
		}
	}
	
	/** 
	 * Perform the find
	 */
	PHALCON_INIT_VAR(documents_cursor);
	if (phalcon_array_isset_string(params, SS("fields"))) {
		PHALCON_OBS_VAR(fields);
		phalcon_array_fetch_string(&fields, params, SL("fields"), PH_NOISY);
	
		phalcon_call_method_p2(documents_cursor, mongo_collection, "find", conditions, fields);
	} else {
		phalcon_call_method_p1(documents_cursor, mongo_collection, "find", conditions);
	}
	
	/** 
	 * Check if a 'limit' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, params, SL("limit"), PH_NOISY);
		phalcon_call_method_p1_noret(documents_cursor, "limit", limit);
	}
	
	/** 
	 * Check if a 'sort' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("sort"))) {
		PHALCON_OBS_VAR(sort);
		phalcon_array_fetch_string(&sort, params, SL("sort"), PH_NOISY);
		phalcon_call_method_p1_noret(documents_cursor, "sort", sort);
	}
	
	/** 
	 * Check if a 'skip' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("skip"))) {
		PHALCON_OBS_NVAR(sort);
		phalcon_array_fetch_string(&sort, params, SL("skip"), PH_NOISY);
		phalcon_call_method_p1_noret(documents_cursor, "skip", sort);
	}
	
	/** 
	 * If a group of specific fields are requested we use a
	 * Phalcon\Mvc\Collection\Document instead
	 */
	if (phalcon_array_isset_string(params, SS("fields"))) {
		PHALCON_INIT_VAR(base);
		object_init_ex(base, phalcon_mvc_collection_document_ce);
	} else {
		PHALCON_CPY_WRT(base, collection);
	}
	
	if (PHALCON_IS_TRUE(unique)) {
	
		/** 
		 * Requesting a single result
		 */
		phalcon_call_method_noret(documents_cursor, "rewind");
	
		PHALCON_INIT_VAR(document);
		phalcon_call_method(document, documents_cursor, "current");
		if (Z_TYPE_P(document) == IS_ARRAY) { 
			/** 
			 * Assign the values to the base object
			 */
			phalcon_call_self_p2(return_value, this_ptr, "cloneresult", base, document);
			RETURN_MM();
		}
	
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Requesting a complete resultset
	 */
	PHALCON_INIT_VAR(collections);
	array_init(collections);
	
	PHALCON_INIT_VAR(documents_array);
	phalcon_call_func_p1(documents_array, "iterator_to_array", documents_cursor);
	
	phalcon_is_iterable(documents_array, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(document);
	
		/** 
		 * Assign the values to the base object
		 */
		PHALCON_INIT_NVAR(collection_cloned);
		phalcon_call_self_p2(collection_cloned, this_ptr, "cloneresult", base, document);
		phalcon_array_append(&collections, collection_cloned, PH_SEPARATE);
	
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
	zval *documents_cursor, *limit, *sort = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &params, &collection, &connection);
	
	PHALCON_INIT_VAR(source);
	phalcon_call_method(source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(mongo_collection);
	phalcon_call_method_p1(mongo_collection, connection, "selectcollection", source);
	
	/** 
	 * Convert the string to an array
	 */
	if (phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("conditions"))) {
			PHALCON_OBS_NVAR(conditions);
			phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY);
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
			PHALCON_INIT_NVAR(simple);
			ZVAL_BOOL(simple, 0);
		} else {
			if (phalcon_array_isset_string(params, SS("skip"))) {
				PHALCON_INIT_NVAR(simple);
				ZVAL_BOOL(simple, 0);
			}
		}
	}
	
	if (PHALCON_IS_FALSE(simple)) {
	
		/** 
		 * Perform the find
		 */
		PHALCON_INIT_VAR(documents_cursor);
		phalcon_call_method_p1(documents_cursor, mongo_collection, "find", conditions);
	
		/** 
		 * Check if a 'limit' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("limit"))) {
			PHALCON_OBS_VAR(limit);
			phalcon_array_fetch_string(&limit, params, SL("limit"), PH_NOISY);
			phalcon_call_method_p1_noret(documents_cursor, "limit", limit);
		}
	
		/** 
		 * Check if a 'sort' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("sort"))) {
			PHALCON_OBS_VAR(sort);
			phalcon_array_fetch_string(&sort, params, SL("sort"), PH_NOISY);
			phalcon_call_method_p1_noret(documents_cursor, "sort", sort);
		}
	
		/** 
		 * Check if a 'skip' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("skip"))) {
			PHALCON_OBS_NVAR(sort);
			phalcon_array_fetch_string(&sort, params, SL("skip"), PH_NOISY);
			phalcon_call_method_p1_noret(documents_cursor, "skip", sort);
		}
	
		/** 
		 * Only 'count' is supported
		 */
		phalcon_fast_count(return_value, documents_cursor TSRMLS_CC);
		RETURN_MM();
	}
	
	phalcon_call_method_p1(return_value, mongo_collection, "count", conditions);
	RETURN_MM();
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
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
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
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
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
	phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
	if (PHALCON_IS_FALSE(status)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			phalcon_call_method_p1_noret(this_ptr, "fireevent", event_name);
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
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "afterValidation", 1);
	
		PHALCON_INIT_NVAR(status);
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * Run Before Callbacks
		 */
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "beforeSave", 1);
	
		PHALCON_INIT_NVAR(status);
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
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
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
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
			phalcon_call_method_p1_noret(this_ptr, "fireevent", event_name);
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterSave", 1);
			phalcon_call_method_p1_noret(this_ptr, "fireevent", event_name);
		}
	
		RETURN_CTOR(success);
	}
	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "notSave", 1);
		phalcon_call_method_p1_noret(this_ptr, "fireevent", event_name);
	}
	
	phalcon_call_method_p1_noret(this_ptr, "_canceloperation", disable_events);
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
	phalcon_call_method_p1(status, validator, "validate", this_ptr);
	if (PHALCON_IS_FALSE(status)) {
	
		PHALCON_INIT_VAR(messages);
		phalcon_call_method(messages, validator, "getmessages");
	
		phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(message);
	
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

	zval *event_name, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &event_name);
	
	/** 
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		phalcon_call_method_zval_noret(this_ptr, event_name);
	}
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	phalcon_call_method_p2(return_value, models_manager, "notifyevent", event_name, this_ptr);
	RETURN_MM();
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
		phalcon_call_method_zval(status, this_ptr, event_name);
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
	phalcon_call_method_p2(status, models_manager, "notifyevent", event_name, this_ptr);
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
	
		phalcon_call_method_p1_noret(this_ptr, "fireevent", event_name);
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
	zval *z_zero;
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
			phalcon_call_method_p1(use_implicit_ids, models_manager, "isusingimplicitobjectids", this_ptr);
			if (zend_is_true(use_implicit_ids)) {
				ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				PHALCON_INIT_NVAR(mongo_id);
				object_init_ex(mongo_id, ce0);
				if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
					phalcon_call_method_p1_noret(mongo_id, "__construct", id);
				}
				phalcon_update_property_this(this_ptr, SL("_id"), mongo_id TSRMLS_CC);
			} else {
				PHALCON_CPY_WRT(mongo_id, id);
			}
		}
	
		PHALCON_INIT_VAR(parameters);
		array_init_size(parameters, 1);
		phalcon_array_update_string(&parameters, SL("_id"), &mongo_id, PH_COPY | PH_SEPARATE);
	
		/** 
		 * Perform the count using the function provided by the driver
		 */
		PHALCON_INIT_VAR(document_count);
		phalcon_call_method_p1(document_count, collection, "count", parameters);
	
		z_zero = PHALCON_GLOBAL(z_zero);
		is_smaller_function(return_value, z_zero, document_count TSRMLS_CC);
	
		RETURN_MM();
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
		phalcon_call_func_p1(type, "gettype", message);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid message format '", type, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Creates/Updates a collection based on the values in the attributes
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, save){

	zval *source, *connection;
	zval *collection, *exists, *empty_array, *disable_events;
	zval *status = NULL, *data, *reserved, *properties;
	zval *success = NULL, *options;
	HashPosition hp0;
	zval **hd;
	zval *dependency_injector, *ok, *id;
	zval *params[2];
	zval func;

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(source);
	phalcon_call_method(source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, this_ptr, "getconnection");
	
	/** 
	 * Choose a collection according to the collection name
	 */
	PHALCON_INIT_VAR(collection);
	phalcon_call_method_p1(collection, connection, "selectcollection", source);
	
	/** 
	 * Check the dirty state of the current operation to update the current operation
	 */
	PHALCON_INIT_VAR(exists);
	phalcon_call_method_p1(exists, this_ptr, "_exists", collection);
	phalcon_update_property_long(this_ptr, SL("_operationMade"), (PHALCON_IS_FALSE(exists) ? 1 : 2) TSRMLS_CC);
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	/** 
	 * The messages added to the validator are reset here
	 */
	phalcon_update_property_this(this_ptr, SL("_errorMessages"), empty_array TSRMLS_CC);
	
	disable_events = phalcon_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	
	/** 
	 * Execute the preSave hook
	 */
	PHALCON_INIT_VAR(status);
	phalcon_call_method_p3(status, this_ptr, "_presave", dependency_injector, disable_events, exists);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}
	
	PHALCON_INIT_VAR(reserved);
	phalcon_call_method(reserved, this_ptr, "getreservedattributes");
	
	PHALCON_INIT_VAR(properties);
	phalcon_call_func_p1(properties, "get_object_vars", this_ptr);

	MAKE_STD_ZVAL(data);
	if (Z_TYPE_P(properties) == IS_ARRAY) {
		array_init_size(data, zend_hash_num_elements(Z_ARRVAL_P(properties)));

		/**
		 * We only assign values to the public properties
		 */
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(properties), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(properties), (void**) &hd, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(properties), &hp0)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(properties), &hp0);

			if ((PHALCON_IS_STRING(&key, "_id") && Z_TYPE_PP(hd) != IS_NULL) || !phalcon_array_isset(reserved, &key)) {
				Z_ADDREF_PP(hd);
				if (likely(Z_TYPE(key) == IS_STRING)) {
					add_assoc_zval_ex(data, Z_STRVAL(key), Z_STRLEN(key)+1, *hd);
				}
				else {
					add_index_zval(data, Z_LVAL(key), *hd);
				}
			}
		}
	}
	else {
		array_init(data);
	}
	
	PHALCON_INIT_NVAR(status);

	ZVAL_STRING(&func, "save", 0);

	/**
	 * We always use safe stores to get the success state
	 */
	MAKE_STD_ZVAL(options);
	array_init_size(options, 1);

	add_assoc_long_ex(options, SS("w"), 1);

	params[0] = data;
	params[1] = options;

	/**
	 * Save the document
	 */
	call_user_function(NULL, &collection, &func, status, 2, params TSRMLS_CC);

	zval_ptr_dtor(&options);
	zval_ptr_dtor(&data);

	PHALCON_INIT_NVAR(success);
	ZVAL_FALSE(success);

	if (phalcon_array_isset_string_fetch(&ok, status, SS("ok"))) {
		if (zend_is_true(ok)) {
			ZVAL_TRUE(success);
			if (PHALCON_IS_FALSE(exists) && phalcon_array_isset_string_fetch(&id, data, SS("_id"))) {
				phalcon_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);
			}
		}
	}
	
	/** 
	 * Call the postSave hooks
	 */
	phalcon_call_method_p3(return_value, this_ptr, "_postsave", disable_events, success, exists);
	RETURN_MM();
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
	zval *parameters;
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
			phalcon_call_method_noret(collection, "__construct");
		}
	
		PHALCON_INIT_VAR(models_manager);
		phalcon_call_method(models_manager, collection, "getmodelsmanager");
	
		/** 
		 * Check if the model use implicit ids
		 */
		PHALCON_INIT_VAR(use_implicit_ids);
		phalcon_call_method_p1(use_implicit_ids, models_manager, "isusingimplicitobjectids", collection);
		if (zend_is_true(use_implicit_ids)) {
			ce1 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce1);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				phalcon_call_method_p1_noret(mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	} else {
		PHALCON_CPY_WRT(mongo_id, id);
	}
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("_id"), &mongo_id, PH_COPY);
	
	PHALCON_INIT_VAR(parameters);
	array_init_size(parameters, 1);
	phalcon_array_append(&parameters, conditions, 0);
	phalcon_call_self_p1(return_value, this_ptr, "findfirst", parameters);
	RETURN_MM();
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
	zval *unique;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
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
		phalcon_call_method_noret(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, collection, "getconnection");

	unique = PHALCON_GLOBAL(z_true);
	phalcon_call_self_p4(return_value, this_ptr, "_getresultset", parameters, collection, connection, unique);
	RETURN_MM();
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
	zval *unique;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
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
		phalcon_call_method_noret(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, collection, "getconnection");
	
	unique = PHALCON_GLOBAL(z_false);
	phalcon_call_self_p4(return_value, this_ptr, "_getresultset", parameters, collection, connection, unique);
	RETURN_MM();
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
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
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
		phalcon_call_method_noret(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, collection, "getconnection");
	phalcon_call_self_p3(return_value, this_ptr, "_getgroupresultset", parameters, collection, connection);
	RETURN_MM();
}

/**
 * Perform an aggregation using the Mongo aggregation framework
 *
 * @param array $parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, aggregate){

	zval *parameters, *class_name, *model, *connection;
	zval *source, *collection;
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
		phalcon_call_method_noret(model, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, model, "getconnection");
	
	PHALCON_INIT_VAR(source);
	phalcon_call_method(source, model, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(collection);
	phalcon_call_method_p1(collection, connection, "selectcollection", source);
	phalcon_call_method_p1(return_value, collection, "aggregate", parameters);
	RETURN_MM();
}

/**
 * Allows to perform a summatory group for a column in the collection
 *
 * @param string $field
 * @param array $conditions
 * @param string $finalize
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, summatory){

	zval *field, *conditions = NULL, *finalize = NULL, *class_name;
	zval *model, *connection, *source, *collection;
	zval *keys, *empty_array, *initial, *reduce, *group;
	zval *retval, *first_retval, *summatory;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &field, &conditions, &finalize);
	
	if (!conditions) {
		conditions = PHALCON_GLOBAL(z_null);
	}
	
	if (!finalize) {
		finalize = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(field) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid field name for group");
		return;
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(model);
	object_init_ex(model, ce0);
	if (phalcon_has_constructor(model TSRMLS_CC)) {
		phalcon_call_method_noret(model, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, model, "getconnection");
	
	PHALCON_INIT_VAR(source);
	phalcon_call_method(source, model, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	PHALCON_INIT_VAR(collection);
	phalcon_call_method_p1(collection, connection, "selectcollection", source);
	
	PHALCON_INIT_VAR(keys);
	array_init(keys);
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	/** 
	 * Uses a javascript hash to group the results
	 */
	PHALCON_INIT_VAR(initial);
	array_init_size(initial, 1);
	phalcon_array_update_string(&initial, SL("summatory"), &empty_array, PH_COPY | PH_SEPARATE);
	
	/** 
	 * Uses a javascript hash to group the results, however this is slow with larger
	 * datasets
	 */
	PHALCON_INIT_VAR(reduce);
	PHALCON_CONCAT_SVSVSVS(reduce, "function (curr, result) { if (typeof result.summatory[curr.", field, "] === \"undefined\") { result.summatory[curr.", field, "] = 1; } else { result.summatory[curr.", field, "]++; } }");
	PHALCON_INIT_VAR(group);
	phalcon_call_method_p3(group, collection, "group", keys, initial, reduce);
	if (phalcon_array_isset_string(group, SS("retval"))) {
	
		PHALCON_OBS_VAR(retval);
		phalcon_array_fetch_string(&retval, group, SL("retval"), PH_NOISY);
		if (phalcon_array_isset_long(retval, 0)) {
	
			PHALCON_OBS_VAR(first_retval);
			phalcon_array_fetch_long(&first_retval, retval, 0, PH_NOISY);
			if (phalcon_array_isset_string(first_retval, SS("summatory"))) {
				PHALCON_OBS_VAR(summatory);
				phalcon_array_fetch_string(&summatory, first_retval, SL("summatory"), PH_NOISY);
				RETURN_CTOR(summatory);
			}
	
			RETURN_CTOR(first_retval);
		}
	
		RETURN_CTOR(retval);
	}
	
	PHALCON_MM_RESTORE();
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
	
	disable_events = phalcon_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	if (!zend_is_true(disable_events)) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeDelete", 1);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_OBS_VAR(id);
	phalcon_read_property_this(&id, this_ptr, SL("_id"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, this_ptr, "getconnection");
	
	PHALCON_INIT_VAR(source);
	phalcon_call_method(source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	
	/** 
	 * Get the \MongoCollection
	 */
	PHALCON_INIT_VAR(collection);
	phalcon_call_method_p1(collection, connection, "selectcollection", source);
	if (Z_TYPE_P(id) == IS_OBJECT) {
		PHALCON_CPY_WRT(mongo_id, id);
	} else {
		PHALCON_OBS_VAR(models_manager);
		phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		/** 
		 * Is the collection using implicit object Ids?
		 */
		PHALCON_INIT_VAR(use_implicit_ids);
		phalcon_call_method_p1(use_implicit_ids, models_manager, "isusingimplicitobjectids", this_ptr);
		if (zend_is_true(use_implicit_ids)) {
			ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_NVAR(mongo_id);
			object_init_ex(mongo_id, ce0);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				phalcon_call_method_p1_noret(mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	}
	
	PHALCON_INIT_VAR(id_condition);
	array_init_size(id_condition, 1);
	phalcon_array_update_string(&id_condition, SL("_id"), &mongo_id, PH_COPY);
	
	PHALCON_INIT_VAR(success);
	ZVAL_BOOL(success, 0);
	
	PHALCON_INIT_VAR(options);
	array_init_size(options, 1);
	add_assoc_bool_ex(options, SS("safe"), 1);
	
	/** 
	 * Remove the instance
	 */
	PHALCON_INIT_NVAR(status);
	phalcon_call_method_p2(status, collection, "remove", id_condition, options);
	if (Z_TYPE_P(status) != IS_ARRAY) { 
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Check the operation status
	 */
	if (phalcon_array_isset_string(status, SS("ok"))) {
	
		PHALCON_OBS_VAR(ok);
		phalcon_array_fetch_string(&ok, status, SL("ok"), PH_NOISY);
		if (zend_is_true(ok)) {
	
			ZVAL_BOOL(success, 1);
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "afterDelete", 1);
				phalcon_call_method_p1_noret(this_ptr, "fireevent", event_name);
			}
		}
	} else {
		PHALCON_INIT_NVAR(success);
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
	phalcon_call_method(reserved, this_ptr, "getreservedattributes");
	
	/** 
	 * Get an array with the values of the object
	 */
	PHALCON_INIT_VAR(properties);
	phalcon_call_func_p1(properties, "get_object_vars", this_ptr);
	
	/** 
	 * We only assign values to the public properties
	 */
	phalcon_is_iterable(properties, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (PHALCON_IS_STRING(key, "_id")) {
	
			if (Z_TYPE_P(value) != IS_NULL) {
				phalcon_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			if (!phalcon_array_isset(reserved, key)) {
				phalcon_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
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

	zval *data;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(data);
	phalcon_call_method(data, this_ptr, "toarray");
	
	/** 
	 * Use the standard serialize function to serialize the array data
	 */
	phalcon_serialize(return_value, &data TSRMLS_CC);
	RETURN_MM();
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
		phalcon_unserialize(attributes, data TSRMLS_CC);
		if (Z_TYPE_P(attributes) == IS_ARRAY) { 
	
			/** 
			 * Obtain the default DI
			 */
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_call_static(dependency_injector, "phalcon\\di", "getdefault");
	
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
			phalcon_call_method_p1(manager, dependency_injector, "getshared", service);
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'collectionManager' is not valid");
				return;
			}

			PHALCON_VERIFY_INTERFACE(manager, phalcon_mvc_collection_managerinterface_ce);
	
			/** 
			 * Update the models manager
			 */
			phalcon_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
	
			/** 
			 * Update the objects attributes
			 */
			phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(key, ah0, hp0);
				PHALCON_GET_HVALUE(value);
	
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			RETURN_MM_NULL();
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
	return;
}

/**
 * Runs JavaScript code on the database server.
 *
 * <code>
 *
 * $ret = Robots::execute("function() { return 'Hello, world!';}");
 * echo $ret['retval'], "\n";
 *
 * </code>
 *
 * @param mixed $code
 * @param array $args
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, execute){

	zval *parameters = NULL, *class_name, *collection, *connection;
	zval *unique;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
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
		phalcon_call_method_noret(collection, "__construct");
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method(connection, collection, "getconnection");

	unique = PHALCON_GLOBAL(z_true);
	phalcon_call_self_p4(return_value, this_ptr, "_getresultset", parameters, collection, connection, unique);
	RETURN_MM();
}


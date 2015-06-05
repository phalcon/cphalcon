
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Collection, phalcon, mvc_collection, phalcon_mvc_collection_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_id"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_reserved"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_disableEvents"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_collection_ce, SL("_skipped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_CREATE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, phalcon_mvc_collectioninterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Collection constructor
 */
PHP_METHOD(Phalcon_Mvc_Collection, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, *modelsManager = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &modelsManager);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}
	if (!modelsManager) {
		ZEPHIR_CPY_WRT(modelsManager, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/collection.zep", 81);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "collectionManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&modelsManager, dependencyInjector, "getshared", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/collection.zep", 92);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_modelsManager"), modelsManager TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed id
 */
PHP_METHOD(Phalcon_Mvc_Collection, setId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *mongoId = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (Z_TYPE_P(id) != IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1, _0, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(mongoId, id);
	}
	zephir_update_property_this(this_ptr, SL("_id"), mongoId TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the value of the _id property
 *
 * @return \MongoId
 */
PHP_METHOD(Phalcon_Mvc_Collection, getId) {


	RETURN_MEMBER(this_ptr, "_id");

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setcustomeventsmanager", NULL, 0, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Collection, getCollectionManager) {


	RETURN_MEMBER(this_ptr, "_modelsManager");

}

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 */
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes) {

	zval *reserved = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(reserved);
	zephir_read_static_property_ce(&reserved, phalcon_mvc_collection_ce, SL("_reserved") TSRMLS_CC);
	if (Z_TYPE_P(reserved) == IS_NULL) {
		ZEPHIR_INIT_NVAR(reserved);
		zephir_create_array(reserved, 5, 0 TSRMLS_CC);
		zephir_array_update_string(&reserved, SL("_connection"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_dependencyInjector"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_source"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_operationMade"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_errorMessages"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_update_static_property_ce(phalcon_mvc_collection_ce, SL("_reserved"), &reserved TSRMLS_CC);
	}
	RETURN_CCTOR(reserved);

}

/**
 * Sets if a model must use implicit objects ids
 */
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *useImplicitObjectIds_param = NULL, *_0;
	zend_bool useImplicitObjectIds;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &useImplicitObjectIds_param);

	useImplicitObjectIds = zephir_get_boolval(useImplicitObjectIds_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "useimplicitobjectids", NULL, 0, this_ptr, (useImplicitObjectIds ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets collection name which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Collection, setSource) {

	zval *source_param = NULL;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(source, source_param);
	} else {
		ZEPHIR_INIT_VAR(source);
		ZVAL_EMPTY_STRING(source);
	}


	zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns collection name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Collection, getSource) {

	zval *source = NULL, *collection = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(source);
	zephir_read_property_this(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	if (!(zephir_is_true(source))) {
		ZEPHIR_CPY_WRT(collection, this_ptr);
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class_ns(_0, collection, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(source);
		zephir_uncamelize(source, _0);
		zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	}
	RETURN_CCTOR(source);

}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setconnectionservice", NULL, 0, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns DependencyInjection connection service
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves a database connection
 *
 * @return \MongoDb
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&connection, _0, "getconnection", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	}
	RETURN_CCTOR(connection);

}

/**
 * Reads an attribute value by its name
 *
 *<code>
 *	echo robot->readAttribute('name');
 *</code>
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute) {

	zval *attribute_param = NULL, *_0;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	if (!(zephir_isset_property_zval(this_ptr, attribute TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_zval(&_0, this_ptr, attribute, PH_NOISY_CC);
	RETURN_CCTOR(_0);

}

/**
 * Writes an attribute value by its name
 *
 *<code>
 *	robot->writeAttribute('name', 'Rosey');
 *</code>
 *
 * @param string attribute
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute) {

	zval *attribute_param = NULL, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cloned collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *document = NULL;
	zval *collection, *document_param = NULL, *clonedCollection, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection, &document_param);

	document = document_param;



	ZEPHIR_INIT_VAR(clonedCollection);
	if (zephir_clone(clonedCollection, collection TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_is_iterable(document, &_1, &_0, 0, 0, "phalcon/mvc/collection.zep", 324);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, clonedCollection, "writeattribute", &_3, 0, key, value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(clonedCollection);

}

/**
 * Returns a collection resultset
 *
 * @param array params
 * @param Phalcon\Mvc\Collection collection
 * @param \MongoDb connection
 * @param boolean unique
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool unique;
	zval *params, *collection, *connection, *unique_param = NULL, *source = NULL, *mongoCollection = NULL, *conditions = NULL, *base = NULL, *documentsCursor = NULL, *fields, *skip, *limit, *sort, *document = NULL, *collections, *_0 = NULL, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &params, &collection, &connection, &unique_param);

	unique = zephir_get_boolval(unique_param);


	ZEPHIR_CALL_METHOD(&source, collection, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 343);
		return;
	}
	ZEPHIR_CALL_METHOD(&mongoCollection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	if (Z_TYPE_P(mongoCollection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo collection", "phalcon/mvc/collection.zep", 349);
		return;
	}
	ZEPHIR_OBS_VAR(conditions);
	if (!(zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(conditions);
		if (!(zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(conditions);
			array_init(conditions);
		}
	}
	if (Z_TYPE_P(conditions) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Find parameters must be an array", "phalcon/mvc/collection.zep", 362);
		return;
	}
	ZEPHIR_OBS_VAR(fields);
	if (zephir_array_isset_string_fetch(&fields, params, SS("fields"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&documentsCursor, mongoCollection, "find", NULL, 0, conditions, fields);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&documentsCursor, mongoCollection, "find", NULL, 0, conditions);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, params, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, documentsCursor, "limit", NULL, 0, limit);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(sort);
	if (zephir_array_isset_string_fetch(&sort, params, SS("sort"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, documentsCursor, "sort", NULL, 0, sort);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(skip);
	if (zephir_array_isset_string_fetch(&skip, params, SS("skip"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, documentsCursor, "skip", NULL, 0, skip);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(params, SS("fields"))) {
		ZEPHIR_INIT_VAR(base);
		object_init_ex(base, phalcon_mvc_collection_document_ce);
		if (zephir_has_constructor(base TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, base, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(base, collection);
	}
	if (unique == 1) {
		ZEPHIR_CALL_METHOD(NULL, documentsCursor, "rewind", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&document, documentsCursor, "current", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(document) != IS_ARRAY) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_STATIC("cloneresult", NULL, 0, base, document);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(collections);
	array_init(collections);
	ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, 286, documentsCursor);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/collection.zep", 435);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(document, _3);
		ZEPHIR_CALL_STATIC(&_4, "cloneresult", &_5, 0, base, document);
		zephir_check_call_status();
		zephir_array_append(&collections, _4, PH_SEPARATE, "phalcon/mvc/collection.zep", 432);
	}
	RETURN_CCTOR(collections);

}

/**
 * Perform a count over a resultset
 *
 * @param array params
 * @param Phalcon\Mvc\Collection collection
 * @param \MongoDb connection
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset) {

	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params, *collection, *connection, *source = NULL, *mongoCollection = NULL, *conditions = NULL, *limit, *sort = NULL, *documentsCursor = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &params, &collection, &connection);



	ZEPHIR_CALL_METHOD(&source, collection, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 452);
		return;
	}
	ZEPHIR_CALL_METHOD(&mongoCollection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(conditions);
	if (!(zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(conditions);
		if (!(zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(conditions);
			array_init(conditions);
		}
	}
	_0 = zephir_array_isset_string(params, SS("limit"));
	if (!(_0)) {
		_0 = zephir_array_isset_string(params, SS("sort"));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_array_isset_string(params, SS("skip"));
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&documentsCursor, mongoCollection, "find", NULL, 0, conditions);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(limit);
		if (zephir_array_isset_string_fetch(&limit, params, SS("limit"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, documentsCursor, "limit", NULL, 0, limit);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(sort);
		if (zephir_array_isset_string_fetch(&sort, params, SS("sort"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, documentsCursor, "sort", NULL, 0, sort);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(sort);
		if (zephir_array_isset_string_fetch(&sort, params, SS("skip"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, documentsCursor, "skip", NULL, 0, sort);
			zephir_check_call_status();
		}
		RETURN_MM_LONG(zephir_fast_count_int(documentsCursor TSRMLS_CC));
	}
	ZEPHIR_RETURN_CALL_METHOD(mongoCollection, "count", NULL, 0, conditions);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes internal hooks before save a document
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param boolean disableEvents
 * @param boolean exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _preSave) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool disableEvents, exists;
	zval *dependencyInjector, *disableEvents_param = NULL, *exists_param = NULL, *eventName = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &disableEvents_param, &exists_param);

	disableEvents = zephir_get_boolval(disableEvents_param);
	exists = zephir_get_boolval(exists_param);


	if (!(disableEvents)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "beforeValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(eventName);
		if (!(exists)) {
			ZVAL_STRING(eventName, "beforeValidationOnCreate", 1);
		} else {
			ZVAL_STRING(eventName, "beforeValidationOnUpdate", 1);
		}
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "validation", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", &_2, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (!(disableEvents)) {
		ZEPHIR_INIT_NVAR(eventName);
		if (!(exists)) {
			ZVAL_STRING(eventName, "afterValidationOnCreate", 1);
		} else {
			ZVAL_STRING(eventName, "afterValidationOnUpdate", 1);
		}
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", &_2, 0, eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "afterValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "beforeSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "fireeventcancel", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(eventName);
		if (exists) {
			ZVAL_STRING(eventName, "beforeUpdate", 1);
		} else {
			ZVAL_STRING(eventName, "beforeCreate", 1);
		}
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "fireeventcancel", &_2, 0, eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a document
 */
PHP_METHOD(Phalcon_Mvc_Collection, _postSave) {

	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *disableEvents_param = NULL, *success_param = NULL, *exists_param = NULL, *eventName, *_1 = NULL;
	zend_bool disableEvents, success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &disableEvents_param, &success_param, &exists_param);

	disableEvents = zephir_get_boolval(disableEvents_param);
	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success == 1) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_VAR(eventName);
			if (exists == 1) {
				ZVAL_STRING(eventName, "afterUpdate", 1);
			} else {
				ZVAL_STRING(eventName, "afterCreate", 1);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_0, 0, eventName);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "afterSave", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_0, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(success);
	}
	if (!(disableEvents)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "notSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_0, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0, (disableEvents ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends \Phalcon\Mvc\Collection
 *{
 *
 *	public function validation()
 *	{
 *		this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if (this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, validate) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validator, *message = NULL, *_0 = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	ZEPHIR_CALL_METHOD(&_0, validator, "validate", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(&_1, validator, "getmessages", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/collection.zep", 648);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(message, _4);
			zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends \Phalcon\Mvc\Collection
 *{
 *
 *	public function validation()
 *	{
 *		this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if (this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed) {

	zval *errorMessages;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(errorMessages);
	zephir_read_property_this(&errorMessages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(errorMessages) == IS_ARRAY) {
		if (zephir_fast_count_int(errorMessages TSRMLS_CC)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Fires an internal event
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, eventName, NULL, 0);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "notifyevent", NULL, 0, eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an internal event that cancels the operation
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0 = NULL, *_1;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0, this_ptr, eventName,  NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, _1, "notifyevent", NULL, 0, eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *disableEvents_param = NULL, *eventName, *_0;
	zend_bool disableEvents;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &disableEvents_param);

	disableEvents = zephir_get_boolval(disableEvents_param);


	if (!(disableEvents)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(eventName);
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZVAL_STRING(eventName, "notDeleted", 1);
		} else {
			ZVAL_STRING(eventName, "notSaved", 1);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, eventName);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks if the document exists in the collection
 *
 * @param \MongoCollection collection
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _exists) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *id, *mongoId = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_OBS_VAR(id);
	if (!(zephir_fetch_property(&id, this_ptr, SL("_id"), PH_SILENT_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(id) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(mongoId, id);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1, _0, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_NVAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_id"), mongoId TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, collection, "count", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_1, 0));

}

/**
 * Returns all the validation messages
 *
 * <code>
 *robot = new Robots();
 *robot->type = 'mechanical';
 *robot->name = 'Astro Boy';
 *robot->year = 1952;
 *if (robot->save() == false) {
 *	echo "Umh, We can't store robots right now ";
 *	foreach (robot->getMessages() as message) {
 *		echo message;
 *	}
 *} else {
 *	echo "Great, a new robot was saved successfully!";
 *}
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, getMessages) {


	RETURN_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Appends a customized message on the validation process
 *
 *<code>
 *	use \Phalcon\Mvc\Model\Message as Message;
 *
 *	class Robots extends \Phalcon\Mvc\Model
 *	{
 *
 *		public function beforeSave()
 *		{
 *			if (this->name == 'Peter') {
 *				message = new Message("Sorry, but a robot cannot be named Peter");
 *				this->appendMessage(message);
 *			}
 *		}
 *	}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage) {

	zval *message;

	zephir_fetch_params(0, 1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);

}

/**
 * Creates/Updates a collection based on the values in the atributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, save) {

	zval *_6;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool success;
	zval *dependencyInjector, *connection = NULL, *exists = NULL, *source = NULL, *data, *properties = NULL, *reserved = NULL, *status = NULL, *id, *ok, *collection = NULL, *disableEvents, *key = NULL, *value = NULL, *_0, *_1, *_2 = NULL, **_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/collection.zep", 839);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 844);
		return;
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&collection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, collection);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, 1);
		zephir_update_property_this(this_ptr, SL("_operationMade"), _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, 2);
		zephir_update_property_this(this_ptr, SL("_operationMade"), _0 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_errorMessages"), _1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(disableEvents);
	zephir_read_static_property_ce(&disableEvents, phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 287, dependencyInjector, disableEvents, exists);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_METHOD(&reserved, this_ptr, "getreservedattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&properties, "get_object_vars", NULL, 60, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(properties, &_4, &_3, 0, 0, "phalcon/mvc/collection.zep", 899);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		if (ZEPHIR_IS_STRING(key, "_id")) {
			if (zephir_is_true(value)) {
				zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			if (!(zephir_array_isset(reserved, key))) {
				zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	success = 0;
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("w"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, collection, "save", NULL, 0, data, _6);
	zephir_check_call_status();
	if (Z_TYPE_P(status) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(ok);
		if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 0 TSRMLS_CC)) {
			if (zephir_is_true(ok)) {
				success = 1;
				if (ZEPHIR_IS_FALSE_IDENTICAL(exists)) {
					ZEPHIR_OBS_VAR(id);
					if (zephir_array_isset_string_fetch(&id, data, SS("_id"), 0 TSRMLS_CC)) {
						zephir_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);
					}
				}
			}
		}
	} else {
		success = 0;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 288, disableEvents, (success ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), exists);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find a document by its id (_id)
 *
 * @param string|\MongoId id
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, findById) {

	zval *_4, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *id, *className, *collection, *mongoId = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (Z_TYPE_P(id) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(className);
		zephir_get_called_class(className TSRMLS_CC);
		ZEPHIR_INIT_VAR(collection);
		zephir_fetch_safe_class(_0, className);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(collection, _1);
		if (zephir_has_constructor(collection TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_2, collection, "getcollectionmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, _2, "isusingimplicitobjectids", NULL, 0, collection);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_INIT_VAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(mongoId, id);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_RETURN_CALL_STATIC("findfirst", NULL, 0, _4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in the robots table?
 * robot = Robots::findFirst();
 * echo "The robot name is ", robot->name, "\n";
 *
 * //What's the first mechanical robot in robots table?
 * robot = Robots::findFirst(array(
 *     array("type" => "mechanical")
 * ));
 * echo "The first mechanical robot name is ", robot->name, "\n";
 *
 * //Get first virtual robot ordered by name
 * robot = Robots::findFirst(array(
 *     array("type" => "mechanical"),
 *     "order" => array("name" => 1)
 * ));
 * echo "The first virtual robot name is ", robot->name, "\n";
 *
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, findFirst) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *parameters_param = NULL, *className, *collection, *connection = NULL, *_0 = NULL, *_2;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(collection);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(collection, _1);
	if (zephir_has_constructor(collection TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, collection, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_RETURN_CALL_STATIC("_getresultset", NULL, 0, parameters, collection, connection, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * robots = Robots::find();
 * echo "There are ", count(robots), "\n";
 *
 * //How many mechanical robots are there?
 * robots = Robots::find(array(
 *     array("type" => "mechanical")
 * ));
 * echo "There are ", count(robots), "\n";
 *
 * //Get and print virtual robots ordered by name
 * robots = Robots::findFirst(array(
 *     array("type" => "virtual"),
 *     "order" => array("name" => 1)
 * ));
 * foreach (robots as robot) {
 *	   echo robot->name, "\n";
 * }
 *
 * //Get first 100 virtual robots ordered by name
 * robots = Robots::find(array(
 *     array("type" => "virtual"),
 *     "order" => array("name" => 1),
 *     "limit" => 100
 * ));
 * foreach (robots as robot) {
 *	   echo robot->name, "\n";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *parameters_param = NULL, *className, *collection, *_0 = NULL, *_2 = NULL, *_3;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(collection);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(collection, _1);
	if (zephir_has_constructor(collection TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, collection, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_RETURN_CALL_STATIC("_getresultset", NULL, 0, parameters, collection, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Perform a count over a collection
 *
 *<code>
 * echo 'There are ', Robots::count(), ' robots';
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *parameters_param = NULL, *className, *collection, *connection = NULL, *_0 = NULL;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(collection);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(collection, _1);
	if (zephir_has_constructor(collection TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, collection, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_STATIC("_getgroupresultset", NULL, 0, parameters, collection, connection);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Perform an aggregation using the Mongo aggregation framework
 */
PHP_METHOD(Phalcon_Mvc_Collection, aggregate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *parameters_param = NULL, *className, *model, *connection = NULL, *source = NULL, *_0 = NULL, *_2 = NULL;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(model);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _1);
	if (zephir_has_constructor(model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, model, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1075);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "aggregate", NULL, 0, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to perform a summatory group for a column in the collection
 *
 * @param string field
 * @param array conditions
 * @param string finalize
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, summatory) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *field_param = NULL, *conditions = NULL, *finalize = NULL, *className, *model, *connection = NULL, *source = NULL, *collection = NULL, *keys, *emptyArray, *initial, *reduce = NULL, *group = NULL, *retval, *firstRetval, *_0 = NULL, *_3;
	zval *field = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field_param, &conditions, &finalize);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	if (!conditions) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!finalize) {
		finalize = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(model);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _1);
	if (zephir_has_constructor(model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, model, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1102);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(emptyArray);
	array_init(emptyArray);
	ZEPHIR_INIT_VAR(initial);
	zephir_create_array(initial, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&initial, SL("summatory"), &emptyArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSVSVS(_2, "function (curr, result) { if (typeof result.summatory[curr.", field, "] === \"undefined\") { result.summatory[curr.", field, "] = 1; } else { result.summatory[curr.", field, "]++; } }");
	ZEPHIR_CPY_WRT(reduce, _2);
	ZEPHIR_CALL_METHOD(&group, collection, "group", NULL, 0, keys, initial, reduce);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&retval, group, SS("retval"), 1 TSRMLS_CC)) {
		if (zephir_array_isset_long_fetch(&firstRetval, retval, 0, 1 TSRMLS_CC)) {
			if (zephir_array_isset_string(firstRetval, SS("summatory"))) {
				zephir_array_fetch_string(&_3, firstRetval, SL("summatory"), PH_NOISY | PH_READONLY, "phalcon/mvc/collection.zep", 1126 TSRMLS_CC);
				RETURN_CTOR(_3);
			}
			RETURN_CTOR(firstRetval);
		}
		RETURN_CTOR(retval);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *
 *	robot = Robots::findFirst();
 *	robot->delete();
 *
 *	foreach (Robots::find() as robot) {
 *		robot->delete();
 *	}
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, delete) {

	zval *_4, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool success;
	zval *disableEvents, *status = NULL, *id, *connection = NULL, *source = NULL, *collection = NULL, *mongoId = NULL, *ok, *_0 = NULL, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(id);
	if (!(zephir_fetch_property(&id, this_ptr, SL("_id"), PH_SILENT_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The document cannot be deleted because it doesn't exist", "phalcon/mvc/collection.zep", 1153);
		return;
	}
	ZEPHIR_OBS_VAR(disableEvents);
	zephir_read_static_property_ce(&disableEvents, phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	if (!(zephir_is_true(disableEvents))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "beforeDelete", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1172);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	if (Z_TYPE_P(id) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(mongoId, id);
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, _3, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_NVAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	}
	success = 0;
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_4, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("w"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, collection, "remove", NULL, 0, _4, _5);
	zephir_check_call_status();
	if (Z_TYPE_P(status) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(ok);
	if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 0 TSRMLS_CC)) {
		if (zephir_is_true(ok)) {
			success = 1;
			if (!(zephir_is_true(disableEvents))) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_STRING(_1, "afterDelete", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _1);
				zephir_check_temp_parameter(_1);
				zephir_check_call_status();
			}
		}
	} else {
		success = 0;
	}
	RETURN_MM_BOOL(success);

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r(robot->to[]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, toArray) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *reserved = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&reserved, this_ptr, "getreservedattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 60, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/collection.zep", 1250);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (ZEPHIR_IS_STRING(key, "_id")) {
			if (zephir_is_true(value)) {
				zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			if (!(zephir_array_isset(reserved, key))) {
				zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(data);

}

/**
 * Serializes the object ignoring connections or protected properties
 */
PHP_METHOD(Phalcon_Mvc_Collection, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 11, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Collection, unserialize) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *attributes = NULL, *dependencyInjector = NULL, *manager = NULL, *key = NULL, *value = NULL, *_1, **_4;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(data, data_param);
	} else {
		ZEPHIR_INIT_VAR(data);
		ZVAL_EMPTY_STRING(data);
	}


	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 10, data);
	zephir_check_call_status();
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 1279);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "collectionManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&manager, dependencyInjector, "getshared", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (Z_TYPE_P(manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The injected service 'collectionManager' is not valid", "phalcon/mvc/collection.zep", 1292);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
		zephir_is_iterable(attributes, &_3, &_2, 0, 0, "phalcon/mvc/collection.zep", 1306);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(key, _3, _2);
			ZEPHIR_GET_HVALUE(value, _4);
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets up a behavior in a collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, addBehavior) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "addbehavior", NULL, 0, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Skips the current operation forcing a success state
 */
PHP_METHOD(Phalcon_Mvc_Collection, skipOperation) {

	zval *skip_param = NULL;
	zend_bool skip;

	zephir_fetch_params(0, 1, 0, &skip_param);

	skip = zephir_get_boolval(skip_param);


	zephir_update_property_this(this_ptr, SL("_skipped"), skip ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}


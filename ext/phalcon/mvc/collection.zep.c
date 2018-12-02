
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

	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_dirtyState"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_reserved"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_disableEvents"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_collection_ce, SL("_skipped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_collection_ce->create_object = zephir_init_properties_Phalcon_Mvc_Collection;
	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_CREATE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("DIRTY_STATE_PERSISTENT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("DIRTY_STATE_TRANSIENT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_collection_ce, SL("DIRTY_STATE_DETACHED"), 2 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, phalcon_mvc_collectioninterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Collection constructor
 */
PHP_METHOD(Phalcon_Mvc_Collection, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, *modelsManager = NULL, *_1$$5;

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
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 92);
		return;
	}
	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_STRING(_1$$5, "collectionManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&modelsManager, dependencyInjector, "getshared", NULL, 0, _1$$5);
		zephir_check_temp_parameter(_1$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/collection.zep", 103);
			return;
		}
	}
	zephir_update_property_this(getThis(), SL("_modelsManager"), modelsManager TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, *mongoId = NULL, *_0$$3, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (Z_TYPE_P(id) != IS_OBJECT) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1$$3, _0$$3, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_INIT_VAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			if (zephir_has_constructor(mongoId TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(mongoId, id);
	}
	zephir_update_property_this(getThis(), SL("_id"), mongoId TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the value of the _id property
 *
 * @return \MongoId
 */
PHP_METHOD(Phalcon_Mvc_Collection, getId) {

	

	RETURN_MEMBER(getThis(), "_id");

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

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

	

	RETURN_MEMBER(getThis(), "_modelsManager");

}

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 */
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes) {

	zval *reserved = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(reserved);
	zephir_read_static_property_ce(&reserved, phalcon_mvc_collection_ce, SL("_reserved") TSRMLS_CC);
	if (Z_TYPE_P(reserved) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(reserved);
		zephir_create_array(reserved, 8, 0 TSRMLS_CC);
		zephir_array_update_string(&reserved, SL("_connection"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_dependencyInjector"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_source"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_operationMade"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_errorMessages"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_dirtyState"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_modelsManager"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_skipped"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_update_static_property_ce(phalcon_mvc_collection_ce, SL("_reserved"), &reserved TSRMLS_CC);
	}
	RETURN_CCTOR(reserved);

}

/**
 * Sets if a model must use implicit objects ids
 */
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *useImplicitObjectIds_param = NULL, *_0, *_1;
	zend_bool useImplicitObjectIds;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &useImplicitObjectIds_param);

	useImplicitObjectIds = zephir_get_boolval(useImplicitObjectIds_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (useImplicitObjectIds) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "useimplicitobjectids", NULL, 0, this_ptr, _1);
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

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(source, source_param);
	} else {
		ZEPHIR_INIT_VAR(source);
		ZVAL_EMPTY_STRING(source);
	}


	zephir_update_property_this(getThis(), SL("_source"), source TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns collection name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Collection, getSource) {

	zval *collection = NULL, *_0, *_1$$3, *_2$$3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_source"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CPY_WRT(collection, this_ptr);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_get_class_ns(_2$$3, collection, 0 TSRMLS_CC);
		zephir_uncamelize(_1$$3, _2$$3, NULL  );
		zephir_update_property_this(getThis(), SL("_source"), _1$$3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(getThis(), "_source");

}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
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

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

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

	zval *_0, *_1$$3, *_2$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_OBJECT) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$3, _1$$3, "getconnection", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_connection"), _2$$3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(getThis(), "_connection");

}

/**
 * Reads an attribute value by its name
 *
 *<code>
 *	echo $robot->readAttribute("name");
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

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
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
 *	$robot->writeAttribute("name", "Rosey");
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

	zephir_get_strval(attribute, attribute_param);


	zephir_update_property_zval_zval(getThis(), attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cloned collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *document = NULL;
	zval *collection, *document_param = NULL, *clonedCollection = NULL, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection, &document_param);

	document = document_param;


	ZEPHIR_INIT_VAR(clonedCollection);
	if (zephir_clone(clonedCollection, collection TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_is_iterable(document, &_1, &_0, 0, 0, "phalcon/mvc/collection.zep", 334);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, clonedCollection, "writeattribute", &_3, 0, key, value);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(clonedCollection, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, clonedCollection, "afterfetch", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(clonedCollection);

}

/**
 * Returns a collection resultset
 *
 * @param array params
 * @param \Phalcon\Mvc\Collection collection
 * @param \MongoDb connection
 * @param boolean unique
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset) {

	zend_class_entry *_1$$3;
	HashTable *_8;
	HashPosition _7;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool unique, _2$$3;
	zval *params, *collection, *connection, *unique_param = NULL, *source = NULL, *mongoCollection = NULL, *conditions = NULL, *base = NULL, *documentsCursor = NULL, *fields = NULL, *skip = NULL, *limit = NULL, *sort = NULL, *document = NULL, *collections = NULL, *className = NULL, *_6 = NULL, **_9, *_0$$3 = NULL, *_3$$4, *_4$$4, *_5$$6, *_10$$19 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &params, &collection, &connection, &unique_param);

	unique = zephir_get_boolval(unique_param);


	ZEPHIR_OBS_VAR(className);
	if (zephir_array_isset_string_fetch(&className, params, SS("class"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(base);
		zephir_fetch_safe_class(_0$$3, className);
			_1$$3 = zend_fetch_class(Z_STRVAL_P(_0$$3), Z_STRLEN_P(_0$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(base, _1$$3);
		if (zephir_has_constructor(base TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, base, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		_2$$3 = zephir_instance_of_ev(base, phalcon_mvc_collectioninterface_ce TSRMLS_CC);
		if (!(_2$$3)) {
			_2$$3 = zephir_instance_of_ev(base, phalcon_mvc_collection_document_ce TSRMLS_CC);
		}
		if (!(_2$$3)) {
			ZEPHIR_INIT_VAR(_3$$4);
			object_init_ex(_3$$4, phalcon_mvc_collection_exception_ce);
			ZEPHIR_INIT_VAR(_4$$4);
			ZEPHIR_CONCAT_SVS(_4$$4, "Object of class '", className, "' must be an implementation of Phalcon\\Mvc\\CollectionInterface or an instance of Phalcon\\Mvc\\Collection\\Document");
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 9, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "phalcon/mvc/collection.zep", 364 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(base, collection);
	}
	if (zephir_instance_of_ev(base, phalcon_mvc_collection_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5$$6);
		ZVAL_LONG(_5$$6, 0);
		ZEPHIR_CALL_METHOD(NULL, base, "setdirtystate", NULL, 0, _5$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&source, collection, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 376);
		return;
	}
	ZEPHIR_CALL_METHOD(&mongoCollection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	if (Z_TYPE_P(mongoCollection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo collection", "phalcon/mvc/collection.zep", 382);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Find parameters must be an array", "phalcon/mvc/collection.zep", 395);
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
	ZEPHIR_CALL_FUNCTION(&_6, "iterator_to_array", NULL, 318, documentsCursor, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "phalcon/mvc/collection.zep", 459);
	for (
	  ; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zend_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(document, _9);
		ZEPHIR_CALL_STATIC(&_10$$19, "cloneresult", &_11, 0, base, document);
		zephir_check_call_status();
		zephir_array_append(&collections, _10$$19, PH_SEPARATE, "phalcon/mvc/collection.zep", 456);
	}
	RETURN_CCTOR(collections);

}

/**
 * Perform a count over a resultset
 *
 * @param array params
 * @param \Phalcon\Mvc\Collection collection
 * @param \MongoDb connection
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params, *collection, *connection, *source = NULL, *mongoCollection = NULL, *conditions = NULL, *limit = NULL, *sort = NULL, *documentsCursor = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &params, &collection, &connection);



	ZEPHIR_CALL_METHOD(&source, collection, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 476);
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
 * @param \Phalcon\DiInterface dependencyInjector
 * @param boolean disableEvents
 * @param boolean exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _preSave) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool disableEvents, exists;
	zval *dependencyInjector, *disableEvents_param = NULL, *exists_param = NULL, *eventName = NULL, *_3 = NULL, *_4, *_0$$3 = NULL, *_1$$3, *_2$$3 = NULL, *_5$$9, *_6$$10 = NULL, *_7$$10 = NULL, *_8$$10 = NULL, *_9$$10 = NULL, *_10$$10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &disableEvents_param, &exists_param);

	disableEvents = zephir_get_boolval(disableEvents_param);
	exists = zephir_get_boolval(exists_param);


	if (!(disableEvents)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "beforeValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "fireeventcancel", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$3)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(eventName);
		if (!(exists)) {
			ZVAL_STRING(eventName, "beforeValidationOnCreate", 1);
		} else {
			ZVAL_STRING(eventName, "beforeValidationOnUpdate", 1);
		}
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "fireeventcancel", NULL, 0, eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "validation", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_VAR(_5$$9);
			ZVAL_STRING(_5$$9, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _5$$9);
			zephir_check_temp_parameter(_5$$9);
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
		ZEPHIR_CALL_METHOD(&_6$$10, this_ptr, "fireeventcancel", NULL, 0, eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$10)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(_8$$10);
		ZVAL_STRING(_8$$10, "afterValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7$$10, this_ptr, "fireeventcancel", NULL, 0, _8$$10);
		zephir_check_temp_parameter(_8$$10);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$10)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_8$$10);
		ZVAL_STRING(_8$$10, "beforeSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9$$10, this_ptr, "fireeventcancel", NULL, 0, _8$$10);
		zephir_check_temp_parameter(_8$$10);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_9$$10)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(eventName);
		if (exists) {
			ZVAL_STRING(eventName, "beforeUpdate", 1);
		} else {
			ZVAL_STRING(eventName, "beforeCreate", 1);
		}
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "fireeventcancel", NULL, 0, eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_10$$10)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a document
 */
PHP_METHOD(Phalcon_Mvc_Collection, _postSave) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *disableEvents_param = NULL, *success_param = NULL, *exists_param = NULL, *eventName = NULL, *_2, *_0$$4, *_1$$7;
	zend_bool disableEvents, success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &disableEvents_param, &success_param, &exists_param);

	disableEvents = zephir_get_boolval(disableEvents_param);
	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_VAR(eventName);
			if (exists) {
				ZVAL_STRING(eventName, "afterUpdate", 1);
			} else {
				ZVAL_STRING(eventName, "afterCreate", 1);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, eventName);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_0$$4);
			ZVAL_STRING(_0$$4, "afterSave", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _0$$4);
			zephir_check_temp_parameter(_0$$4);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(success);
	}
	if (!(disableEvents)) {
		ZEPHIR_INIT_VAR(_1$$7);
		ZVAL_STRING(_1$$7, "notSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _1$$7);
		zephir_check_temp_parameter(_1$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	if (disableEvents) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

/**
 * Executes validators on every validation call
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         // Old, deprecated syntax, use new one below
 *         $this->validate(
 *             new ExclusionIn(
 *                 [
 *                     "field"  => "status",
 *                     "domain" => ["A", "I"],
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() == true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 *<code>
 * use Phalcon\Validation\Validator\ExclusionIn as ExclusionIn;
 * use Phalcon\Validation;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *         $validator->add("status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => ["A", "I"]
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, validate) {

	HashTable *_3$$4;
	HashPosition _2$$4;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, *messages = NULL, *message = NULL, *_0$$3 = NULL, *_1$$4 = NULL, **_4$$4, *_5$$6, *_6$$7 = NULL, *_8$$8 = NULL, *_9$$8 = NULL, *_10$$8 = NULL, *_11$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	if (zephir_instance_of_ev(validator, phalcon_mvc_model_validatorinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, validator, "validate", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$3)) {
			ZEPHIR_CALL_METHOD(&_1$$4, validator, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(_1$$4, &_3$$4, &_2$$4, 0, 0, "phalcon/mvc/collection.zep", 700);
			for (
			  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HVALUE(message, _4$$4);
				zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
			}
		}
	} else if (zephir_instance_of_ev(validator, phalcon_validationinterface_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5$$6);
		ZVAL_NULL(_5$$6);
		ZEPHIR_CALL_METHOD(&messages, validator, "validate", NULL, 0, _5$$6, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(messages) != IS_BOOL) {
			ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$7, messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_6$$7))) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, messages, "current", &_7, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_8$$8);
				object_init_ex(_8$$8, phalcon_mvc_model_message_ce);
				ZEPHIR_CALL_METHOD(&_9$$8, message, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_10$$8, message, "getfield", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$8, message, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _8$$8, "__construct", &_12, 8, _9$$8, _10$$8, _11$$8);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_13, 0, _8$$8);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, messages, "next", &_14, 0);
				zephir_check_call_status();
			}
			RETURN_MM_BOOL(!(zephir_fast_count_int(messages TSRMLS_CC)));
		}
		RETURN_CCTOR(messages);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "You should pass Phalcon\\Mvc\\Model\\ValidatorInterface or Phalcon\\ValidationInterface object", "phalcon/mvc/collection.zep", 732);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new ExclusionIn(
 *                 [
 *                     "field"  => "status",
 *                     "domain" => ["A", "I"],
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() == true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	RETURN_BOOL((zephir_fast_count_int(_0 TSRMLS_CC) > 0));

}

/**
 * Fires an internal event
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0$$3 = NULL, *_1, *_2 = NULL;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, eventName, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "notifyevent", NULL, 0, eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *disableEvents_param = NULL, *eventName = NULL, *_0$$3;
	zend_bool disableEvents;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &disableEvents_param);

	disableEvents = zephir_get_boolval(disableEvents_param);


	if (!(disableEvents)) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(eventName);
		if (ZEPHIR_IS_LONG(_0$$3, 3)) {
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

	zval *_4;
	zend_bool exists = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, *id = NULL, *mongoId = NULL, *_2, *_3 = NULL, *_0$$5, *_1$$5 = NULL, *_5$$9, *_6$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_OBS_VAR(id);
	if (!(zephir_fetch_property(&id, this_ptr, SL("_id"), PH_SILENT_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(id) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(mongoId, id);
	} else {
		_0$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1$$5, _0$$5, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_1$$5)) {
			ZEPHIR_INIT_NVAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			if (zephir_has_constructor(mongoId TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
				zephir_check_call_status();
			}
			zephir_update_property_this(getThis(), SL("_id"), mongoId TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!(zephir_is_true(_2))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_4, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, collection, "count", NULL, 0, _4);
	zephir_check_call_status();
	exists = ZEPHIR_GT_LONG(_3, 0);
	if (exists) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$9);
		ZVAL_LONG(_5$$9, 0);
		zephir_update_property_this(getThis(), SL("_dirtyState"), _5$$9 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_6$$10);
		ZVAL_LONG(_6$$10, 1);
		zephir_update_property_this(getThis(), SL("_dirtyState"), _6$$10 TSRMLS_CC);
	}
	RETURN_MM_BOOL(exists);

}

/**
 * Returns all the validation messages
 *
 * <code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can't store robots right now ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, getMessages) {

	

	RETURN_MEMBER(getThis(), "_errorMessages");

}

/**
 * Appends a customized message on the validation process
 *
 *<code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $message = new Message(
 *                 "Sorry, but a robot cannot be named Peter"
 *             );
 *
 *             $this->appendMessage(message);
 *         }
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage) {

	zval *message;

	zephir_fetch_params(0, 1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);

}

/**
 * Shared Code for CU Operations
 * Prepares Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, prepareCU) {

	zval *dependencyInjector = NULL, *connection = NULL, *source = NULL, *collection = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 941);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 946);
		return;
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&collection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	RETURN_CCTOR(collection);

}

/**
 * Creates/Updates a collection based on the values in the attributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, save) {

	zval *_6;
	zend_bool success = 0;
	zval *exists = NULL, *data = NULL, *status = NULL, *id = NULL, *ok = NULL, *collection = NULL, *_2, *_3 = NULL, *_4, *_5, *_8, *_9, *_0$$3, *_1$$4, *_7$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, collection);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$3);
		ZVAL_LONG(_0$$3, 1);
		zephir_update_property_this(getThis(), SL("_operationMade"), _0$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_1$$4);
		ZVAL_LONG(_1$$4, 2);
		zephir_update_property_this(getThis(), SL("_operationMade"), _1$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(getThis(), SL("_errorMessages"), _2 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	_5 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_presave", NULL, 319, _4, _5, exists);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
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
						zephir_update_property_this(getThis(), SL("_id"), id TSRMLS_CC);
					}
					ZEPHIR_INIT_ZVAL_NREF(_7$$9);
					ZVAL_LONG(_7$$9, 0);
					zephir_update_property_this(getThis(), SL("_dirtyState"), _7$$9 TSRMLS_CC);
				}
			}
		}
	}
	_8 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	if (success) {
		ZVAL_BOOL(_9, 1);
	} else {
		ZVAL_BOOL(_9, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 320, _8, _9, exists);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a collection based on the values in the attributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, create) {

	zval *_5;
	zval *data = NULL, *status = NULL, *id = NULL, *ok = NULL, *collection = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_7, *_8, *_9, *_6$$7;
	zend_bool exists = 0, success = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	exists = 0;
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(getThis(), SL("_operationMade"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(getThis(), SL("_errorMessages"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	_3 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	if (exists) {
		ZVAL_BOOL(_4, 1);
	} else {
		ZVAL_BOOL(_4, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 319, _0, _3, _4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("w"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, collection, "insert", NULL, 0, data, _5);
	zephir_check_call_status();
	if (Z_TYPE_P(status) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(ok);
		if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 0 TSRMLS_CC)) {
			if (zephir_is_true(ok)) {
				success = 1;
				if (exists == 0) {
					ZEPHIR_OBS_VAR(id);
					if (zephir_array_isset_string_fetch(&id, data, SS("_id"), 0 TSRMLS_CC)) {
						zephir_update_property_this(getThis(), SL("_id"), id TSRMLS_CC);
					}
					ZEPHIR_INIT_ZVAL_NREF(_6$$7);
					ZVAL_LONG(_6$$7, 0);
					zephir_update_property_this(getThis(), SL("_dirtyState"), _6$$7 TSRMLS_CC);
				}
			}
		}
	}
	_7 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	if (success) {
		ZVAL_BOOL(_8, 1);
	} else {
		ZVAL_BOOL(_8, 0);
	}
	ZEPHIR_INIT_VAR(_9);
	if (exists) {
		ZVAL_BOOL(_9, 1);
	} else {
		ZVAL_BOOL(_9, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 320, _7, _8, _9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a document based on the values in the attributes, if not found by criteria
 * Preferred way to avoid duplication is to create index on attribute
 *
 * <code>
 * $robot = new Robot();
 *
 * $robot->name = "MyRobot";
 * $robot->type = "Droid";
 *
 * // Create only if robot with same name and type does not exist
 * $robot->createIfNotExist(
 *     [
 *         "name",
 *         "type",
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, createIfNotExist) {

	zend_bool exists = 0, success = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *criteria_param = NULL, *data = NULL, *keys = NULL, *query = NULL, *status = NULL, *doc = NULL, *collection = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5 = NULL, *_8 = NULL, *_13, *_14, *_9$$7, *_10$$7, *_11$$8, *_12$$8;
	zval *criteria = NULL, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &criteria_param);

	criteria = criteria_param;


	if (ZEPHIR_IS_EMPTY(criteria)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Criteria parameter must be array with one or more attributes of the model", "phalcon/mvc/collection.zep", 1101);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	exists = 0;
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_operationMade"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(getThis(), SL("_errorMessages"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	_3 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	if (exists) {
		ZVAL_BOOL(_4, 1);
	} else {
		ZVAL_BOOL(_4, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 319, _0, _3, _4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&keys, "array_flip", NULL, 321, criteria);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "array_diff_key", NULL, 322, keys, data);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Criteria parameter must be array with one or more attributes of the model", "phalcon/mvc/collection.zep", 1136);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&query, "array_intersect_key", NULL, 323, data, keys);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("$setOnInsert"), &data, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_7, SL("new"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_NULL(_8);
	ZEPHIR_CALL_METHOD(&status, collection, "findandmodify", NULL, 0, query, _6, _8, _7);
	zephir_check_call_status();
	if (Z_TYPE_P(status) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&doc, collection, "findone", NULL, 0, query);
		zephir_check_call_status();
		if (Z_TYPE_P(doc) == IS_ARRAY) {
			success = 1;
			ZEPHIR_INIT_ZVAL_NREF(_9$$7);
			ZVAL_LONG(_9$$7, 1);
			zephir_update_property_this(getThis(), SL("_operationMade"), _9$$7 TSRMLS_CC);
			zephir_array_fetch_string(&_10$$7, doc, SL("_id"), PH_NOISY | PH_READONLY, "phalcon/mvc/collection.zep", 1156 TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_id"), _10$$7 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(_11$$8);
		object_init_ex(_11$$8, phalcon_mvc_model_message_ce);
		ZEPHIR_INIT_VAR(_12$$8);
		ZVAL_STRING(_12$$8, "Document already exists", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11$$8, "__construct", NULL, 8, _12$$8);
		zephir_check_temp_parameter(_12$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _11$$8);
		zephir_check_call_status();
	}
	_13 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_8);
	if (success) {
		ZVAL_BOOL(_8, 1);
	} else {
		ZVAL_BOOL(_8, 0);
	}
	ZEPHIR_INIT_VAR(_14);
	if (exists) {
		ZVAL_BOOL(_14, 1);
	} else {
		ZVAL_BOOL(_14, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 320, _13, _8, _14);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates/Updates a collection based on the values in the attributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, update) {

	zval *_4, *_6;
	zend_bool success = 0;
	zval *exists = NULL, *data = NULL, *status = NULL, *ok = NULL, *collection = NULL, *_0, *_1, *_2 = NULL, *_3, *_5, *_7, *_8;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, collection);
	zephir_check_call_status();
	if (!(zephir_is_true(exists))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The document cannot be updated because it doesn't exist", "phalcon/mvc/collection.zep", 1183);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(getThis(), SL("_operationMade"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(getThis(), SL("_errorMessages"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	_3 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 319, _0, _3, exists);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_this(&_5, this_ptr, SL("_id"), PH_NOISY_CC);
	zephir_array_update_string(&_4, SL("_id"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("w"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, collection, "update", NULL, 0, _4, data, _6);
	zephir_check_call_status();
	if (Z_TYPE_P(status) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(ok);
		if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 0 TSRMLS_CC)) {
			if (zephir_is_true(ok)) {
				success = 1;
			}
		}
	} else {
		success = 0;
	}
	_7 = zephir_fetch_static_property_ce(phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	if (success) {
		ZVAL_BOOL(_8, 1);
	} else {
		ZVAL_BOOL(_8, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 320, _7, _8, exists);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find a document by its id (_id)
 *
 * <code>
 * // Find user by using \MongoId object
 * $user = Users::findById(
 *     new \MongoId("545eb081631d16153a293a66")
 * );
 *
 * // Find user by using id as sting
 * $user = Users::findById("45cbc4a0e4123f6920000002");
 *
 * // Validate input
 * if ($user = Users::findById($_POST["id"])) {
 *     // ...
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, findById) {

	zend_class_entry *_4$$3;
	zval *_7, *_8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, *className = NULL, *collection = NULL, *mongoId = NULL, *_0$$3, *_1$$3, _2$$3, *_3$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (Z_TYPE_P(id) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "/^[a-f\\d]{24}$/i", 0);
		zephir_preg_match(_1$$3, &_2$$3, id, _0$$3, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(_1$$3))) {
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(className);
		zephir_get_called_class(className TSRMLS_CC);
		ZEPHIR_INIT_VAR(collection);
		zephir_fetch_safe_class(_3$$3, className);
			_4$$3 = zend_fetch_class(Z_STRVAL_P(_3$$3), Z_STRLEN_P(_3$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(collection, _4$$3);
		if (zephir_has_constructor(collection TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_5$$3, collection, "getcollectionmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$3, _5$$3, "isusingimplicitobjectids", NULL, 0, collection);
		zephir_check_call_status();
		if (zephir_is_true(_6$$3)) {
			ZEPHIR_INIT_VAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			if (zephir_has_constructor(mongoId TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(mongoId, id);
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_8, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(_7, _8);
	ZEPHIR_RETURN_CALL_STATIC("findfirst", NULL, 0, _7);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 * // What's the first robot in the robots table?
 * $robot = Robots::findFirst();
 *
 * echo "The robot name is ", $robot->name, "\n";
 *
 * // What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(
 *     [
 *         [
 *             "type" => "mechanical",
 *         ]
 *     ]
 * );
 *
 * echo "The first mechanical robot name is ", $robot->name, "\n";
 *
 * // Get first virtual robot ordered by name
 * $robot = Robots::findFirst(
 *     [
 *         [
 *             "type" => "mechanical",
 *         ],
 *         "order" => [
 *             "name" => 1,
 *         ],
 *     ]
 * );
 *
 * echo "The first virtual robot name is ", $robot->name, "\n";
 *
 * // Get first robot by id (_id)
 * $robot = Robots::findFirst(
 *     [
 *         [
 *             "_id" => new \MongoId("45cbc4a0e4123f6920000002"),
 *         ]
 *     ]
 * );
 *
 * echo "The robot id is ", $robot->_id, "\n";
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, findFirst) {

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *className = NULL, *collection = NULL, *connection = NULL, *_0 = NULL, *_2;
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
 * // How many robots are there?
 * $robots = Robots::find();
 *
 * echo "There are ", count($robots), "\n";
 *
 * // How many mechanical robots are there?
 * $robots = Robots::find(
 *     [
 *         [
 *             "type" => "mechanical",
 *         ]
 *     ]
 * );
 *
 * echo "There are ", count(robots), "\n";
 *
 * // Get and print virtual robots ordered by name
 * $robots = Robots::findFirst(
 *     [
 *         [
 *             "type" => "virtual"
 *         ],
 *         "order" => [
 *             "name" => 1,
 *         ]
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
 * // Get first 100 virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         [
 *             "type" => "virtual",
 *         ],
 *         "order" => [
 *             "name" => 1,
 *         ],
 *         "limit" => 100,
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, find) {

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *className = NULL, *collection = NULL, *_0 = NULL, *_2 = NULL, *_3;
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
 * echo "There are ", Robots::count(), " robots";
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, count) {

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *className = NULL, *collection = NULL, *connection = NULL, *_0 = NULL;
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

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *options_param = NULL, *className = NULL, *model = NULL, *connection = NULL, *source = NULL, *_0 = NULL, *_2 = NULL;
	zval *parameters = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters_param, &options_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1429);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "aggregate", NULL, 0, parameters, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to perform a summatory group for a column in the collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, summatory) {

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *conditions = NULL, *finalize = NULL, *className = NULL, *model = NULL, *connection = NULL, *source = NULL, *collection = NULL, *initial = NULL, *reduce = NULL, *group = NULL, *retval = NULL, *firstRetval = NULL, *_0 = NULL, *_2 = NULL, *_4$$6;
	zval *field = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field_param, &conditions, &finalize);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1451);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(initial);
	zephir_create_array(initial, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_array_update_string(&initial, SL("summatory"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSVSVS(_3, "function (curr, result) { if (typeof result.summatory[curr.", field, "] === \"undefined\") { result.summatory[curr.", field, "] = 1; } else { result.summatory[curr.", field, "]++; } }");
	ZEPHIR_CPY_WRT(reduce, _3);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	ZEPHIR_CALL_METHOD(&group, collection, "group", NULL, 0, _2, initial, reduce);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&retval, group, SS("retval"), 1 TSRMLS_CC)) {
		if (zephir_array_isset_long_fetch(&firstRetval, retval, 0, 1 TSRMLS_CC)) {
			if (zephir_array_isset_string(firstRetval, SS("summatory"))) {
				zephir_array_fetch_string(&_4$$6, firstRetval, SL("summatory"), PH_NOISY | PH_READONLY, "phalcon/mvc/collection.zep", 1471 TSRMLS_CC);
				RETURN_CTOR(_4$$6);
			}
			RETURN_CTOR(firstRetval);
		}
		RETURN_CTOR(retval);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 * $robot = Robots::findFirst();
 *
 * $robot->delete();
 *
 * $robots = Robots::find();
 *
 * foreach ($robots as $robot) {
 *     $robot->delete();
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, delete) {

	zval *_5, *_6;
	zend_bool success = 0;
	zval *disableEvents = NULL, *status = NULL, *id = NULL, *connection = NULL, *source = NULL, *collection = NULL, *mongoId = NULL, *ok = NULL, *_2, *_0$$4 = NULL, *_1$$4, *_3$$9, *_4$$9 = NULL, *_7$$15, *_8$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(id);
	if (!(zephir_fetch_property(&id, this_ptr, SL("_id"), PH_SILENT_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The document cannot be deleted because it doesn't exist", "phalcon/mvc/collection.zep", 1502);
		return;
	}
	ZEPHIR_OBS_VAR(disableEvents);
	zephir_read_static_property_ce(&disableEvents, phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	if (!(zephir_is_true(disableEvents))) {
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_STRING(_1$$4, "beforeDelete", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "fireeventcancel", NULL, 0, _1$$4);
		zephir_check_temp_parameter(_1$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$4)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1521);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, connection, "selectcollection", NULL, 0, source);
	zephir_check_call_status();
	if (Z_TYPE_P(id) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(mongoId, id);
	} else {
		_3$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4$$9, _3$$9, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_4$$9)) {
			ZEPHIR_INIT_NVAR(mongoId);
			object_init_ex(mongoId, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			if (zephir_has_constructor(mongoId TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, mongoId, "__construct", NULL, 0, id);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	}
	success = 0;
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("w"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, collection, "remove", NULL, 0, _5, _6);
	zephir_check_call_status();
	if (Z_TYPE_P(status) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(ok);
	if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 0 TSRMLS_CC)) {
		if (zephir_is_true(ok)) {
			success = 1;
			if (!(zephir_is_true(disableEvents))) {
				ZEPHIR_INIT_VAR(_7$$15);
				ZVAL_STRING(_7$$15, "afterDelete", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _7$$15);
				zephir_check_temp_parameter(_7$$15);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_ZVAL_NREF(_8$$14);
			ZVAL_LONG(_8$$14, 2);
			zephir_update_property_this(getThis(), SL("_dirtyState"), _8$$14 TSRMLS_CC);
		}
	} else {
		success = 0;
	}
	RETURN_MM_BOOL(success);

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDirtyState) {

	zval *dirtyState_param = NULL, *_0;
	zend_long dirtyState;

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_update_property_this(getThis(), SL("_dirtyState"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the document exists in the collection or not
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDirtyState) {

	

	RETURN_MEMBER(getThis(), "_dirtyState");

}

/**
 * Sets up a behavior in a collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, addBehavior) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	if (skip) {
		zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r(
 *     $robot->toArray()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, toArray) {

	HashTable *_2;
	HashPosition _1;
	zval *data = NULL, *reserved = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&reserved, this_ptr, "getreservedattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 22, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/collection.zep", 1635);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
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

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 68, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Collection, unserialize) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *attributes = NULL, *dependencyInjector = NULL, *manager = NULL, *key = NULL, *value = NULL, *_1$$3, **_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 69, data);
	zephir_check_call_status();
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 1664);
			return;
		}
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "collectionManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&manager, dependencyInjector, "getshared", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The injected service 'collectionManager' is not valid", "phalcon/mvc/collection.zep", 1677);
			return;
		}
		zephir_update_property_this(getThis(), SL("_modelsManager"), manager TSRMLS_CC);
		zephir_is_iterable(attributes, &_3$$3, &_2$$3, 0, 0, "phalcon/mvc/collection.zep", 1691);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(value, _4$$3);
			zephir_update_property_zval_zval(getThis(), key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_errorMessages"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}


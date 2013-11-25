
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/hash.h"
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Collection, phalcon, mvc_collection, phalcon_mvc_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_id"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_reserved"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_disableEvents"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
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
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param Phalcon\Mvc\Collection\ManagerInterface modelsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection, __construct) {

	zval *dependencyInjector = NULL, *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &modelsManager);

	if (!dependencyInjector || Z_TYPE_P(dependencyInjector) == IS_NULL) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	if (!modelsManager || Z_TYPE_P(modelsManager) == IS_NULL) {
		ZEPHIR_CPY_WRT(modelsManager, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(modelsManager);


	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
	}
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if ((Z_TYPE_P(modelsManager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "collectionManager", 1);
		ZEPHIR_INIT_NVAR(modelsManager);
		zephir_call_method_p1(modelsManager, dependencyInjector, "getshared", _0);
		if ((Z_TYPE_P(modelsManager) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_modelsManager"), modelsManager TSRMLS_CC);
	zephir_call_method_p1_noret(modelsManager, "initialize", this_ptr);
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_noret(this_ptr, "onconstruct");
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed id
 */
PHP_METHOD(Phalcon_Mvc_Collection, setId) {

	zend_class_entry *_2;
	zval *id, *mongoId = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if ((Z_TYPE_P(id) != IS_OBJECT)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_method_p1(_1, _0, "isusingimplicitobjectids", this_ptr);
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(mongoId);
			_2 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(mongoId, _2);
			zephir_call_method_p1_noret(mongoId, "__construct", id);
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
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a custom events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager) {

	zval *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p2_noret(_0, "setcustomeventsmanager", this_ptr, eventsManager);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p1(return_value, _0, "getcustomeventsmanager", this_ptr);
	RETURN_MM();

}

/**
 * Returns the models manager related to the entity instance
 *
 * @return Phalcon\Mvc\Model\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getModelsManager) {


	RETURN_MEMBER(this_ptr, "_modelsManager");

}

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes) {

	zval *reserved, *_0;

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&reserved, phalcon_mvc_collection_ce, SL("_reserved") TSRMLS_CC);
	if ((Z_TYPE_P(reserved) == IS_NULL)) {
		ZEPHIR_INIT_VAR(reserved);
		array_init(reserved);
		zephir_array_update_string(&reserved, SL("_connection"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_dependencyInjector"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_source"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_operationMade"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&reserved, SL("_errorMessages"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		zephir_update_static_property_ce(phalcon_mvc_collection_ce, SL("_reserved"), reserved TSRMLS_CC);
	}
	RETURN_CCTOR(reserved);

}

/**
 * Sets if a model must use implicit objects ids
 *
 * @param boolean useImplicitObjectIds
 */
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds) {

	zval *useImplicitObjectIds_param = NULL, *_0;
	zend_bool useImplicitObjectIds;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &useImplicitObjectIds_param);

		useImplicitObjectIds = zephir_get_boolval(useImplicitObjectIds_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p2_noret(_0, "useimplicitobjectids", this_ptr, (useImplicitObjectIds ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets collection name which model should be mapped
 *
 * @param string source
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, setSource) {

	zval *source_param = NULL;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

		if (Z_TYPE_P(source_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		source = source_param;



	zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns collection name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getSource) {

	zval *source, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(source);
	zephir_read_property_this(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	if (!(zephir_is_true(source))) {
		ZEPHIR_INIT_BNVAR(source);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_ns", this_ptr);
		zephir_uncamelize(source, _0);
		zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	}
	RETURN_CCTOR(source);

}

/**
 * Sets the DependencyInjection connection service name
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService) {

	zval *connectionService, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p2_noret(_0, "setconnectionservice", this_ptr, connectionService);
	RETURN_THIS();

}

/**
 * Returns DependencyInjection connection service
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p1(return_value, _0, "getconnectionservice", this_ptr);
	RETURN_MM();

}

/**
 * Retrieves a database connection
 *
 * @return \MongoDb
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnection) {

	zval *connection, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if ((Z_TYPE_P(connection) != IS_OBJECT)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(connection);
		zephir_call_method_p1(connection, _0, "getconnection", this_ptr);
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

	zval *attribute_param = NULL, *attributeValue;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

		if (Z_TYPE_P(attribute_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		attribute = attribute_param;



	if ((0 == 1)) {
		RETURN_CTOR(attributeValue);
	}
	RETURN_MM_NULL();

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

		if (Z_TYPE_P(attribute_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		attribute = attribute_param;



	zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cloned collection
 *
 * @param Phalcon\Mvc\Collection collection
 * @param array document
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult) {

	zend_function *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *collection, *document, *clonedCollection, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection, &document);



	if ((Z_TYPE_P(collection) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid collection");
		return;
	}
	if ((Z_TYPE_P(document) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid document");
		return;
	}
	ZEPHIR_INIT_VAR(clonedCollection);
	if (zephir_clone(clonedCollection, collection TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_is_iterable(document, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		zephir_call_method_p2_cache_noret(clonedCollection, "writeattribute", &_3, key, value);
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

	HashTable *_2;
	HashPosition _1;
	zend_bool unique;
	zval *params, *collection, *connection, *unique_param = NULL, *source, *mongoCollection, *conditions = NULL, *base = NULL, *documentsCursor, *fields, *skip, *limit, *sort, *document = NULL, *collections, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &params, &collection, &connection, &unique_param);

		unique = zephir_get_boolval(unique_param);


	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, collection, "getsource");
	if ((0 == 0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	ZEPHIR_INIT_VAR(mongoCollection);
	zephir_call_method_p1(mongoCollection, connection, "selectcollection", source);
	ZEPHIR_OBS_VAR(conditions);
	if (!(zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(conditions);
		if (!(zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(conditions);
			array_init(conditions);
		}
	}
	ZEPHIR_INIT_VAR(documentsCursor);
	if (zephir_array_isset_string_fetch(&fields, params, SS("fields"), 1 TSRMLS_CC)) {
		zephir_call_method_p2(documentsCursor, mongoCollection, "find", conditions, fields);
	} else {
		zephir_call_method_p1(documentsCursor, mongoCollection, "find", conditions);
	}
	if (zephir_array_isset_string_fetch(&limit, params, SS("limit"), 1 TSRMLS_CC)) {
		zephir_call_method_p1_noret(documentsCursor, "limit", limit);
	}
	if (zephir_array_isset_string_fetch(&sort, params, SS("sort"), 1 TSRMLS_CC)) {
		zephir_call_method_p1_noret(documentsCursor, "sort", sort);
	}
	if (zephir_array_isset_string_fetch(&skip, params, SS("skip"), 1 TSRMLS_CC)) {
		zephir_call_method_p1_noret(documentsCursor, "skip", skip);
	}
	if (zephir_array_isset_string(params, SS("fields"))) {
		ZEPHIR_INIT_VAR(base);
		object_init_ex(base, phalcon_mvc_collection_document_ce);
	} else {
		ZEPHIR_CPY_WRT(base, collection);
	}
	if ((unique == 1)) {
		zephir_call_method_noret(documentsCursor, "rewind");
		ZEPHIR_INIT_VAR(document);
		zephir_call_method(document, documentsCursor, "current");
		if ((Z_TYPE_P(document) == IS_ARRAY)) {
			zephir_call_self_p2(return_value, this_ptr, "cloneresult", base, document);
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(collections);
	array_init(collections);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "iterator_to_array", documentsCursor);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(document, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_self_p2(_4, this_ptr, "cloneresult", base, document);
		zephir_array_append(&collections, _4, PH_SEPARATE);
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

	zend_bool simple;
	zval *params, *collection, *connection, *source, *mongoCollection, *conditions = NULL, *limit, *sort = NULL, *documentsCursor;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &params, &collection, &connection);



	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, collection, "getsource");
	if ((0 == 0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	ZEPHIR_INIT_VAR(mongoCollection);
	zephir_call_method_p1(mongoCollection, connection, "selectcollection", source);
	ZEPHIR_OBS_VAR(conditions);
	if (!(zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(conditions);
		if (!(zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(conditions);
			array_init(conditions);
		}
	}
	simple = 1;
	if (zephir_array_isset_string(params, SS("limit"))) {
		simple = 0;
	} else {
		if (zephir_array_isset_string(params, SS("sort"))) {
			simple = 0;
		} else {
			if (zephir_array_isset_string(params, SS("skip"))) {
				simple = 0;
			}
		}
	}
	if ((simple == 0)) {
		ZEPHIR_INIT_VAR(documentsCursor);
		zephir_call_method_p1(documentsCursor, mongoCollection, "find", conditions);
		if (zephir_array_isset_string_fetch(&limit, params, SS("limit"), 1 TSRMLS_CC)) {
			zephir_call_method_p1_noret(documentsCursor, "limit", limit);
		}
		ZEPHIR_OBS_VAR(sort);
		if (zephir_array_isset_string_fetch(&sort, params, SS("sort"), 0 TSRMLS_CC)) {
			zephir_call_method_p1_noret(documentsCursor, "sort", sort);
		}
		ZEPHIR_OBS_NVAR(sort);
		if (zephir_array_isset_string_fetch(&sort, params, SS("skip"), 0 TSRMLS_CC)) {
			zephir_call_method_p1_noret(documentsCursor, "skip", sort);
		}
		RETURN_MM_LONG(zephir_fast_count_int(documentsCursor TSRMLS_CC));
	}
	zephir_call_method_p1(return_value, mongoCollection, "count", conditions);
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

	zval *dependencyInjector, *disableEvents, *exists, *eventName = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &disableEvents, &exists);



	if (!(zephir_is_true(disableEvents))) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "beforeValidation", 1);
		zephir_call_method_p1(_0, this_ptr, "fireeventcancel", _1);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(eventName);
		if (!(zephir_is_true(exists))) {
			ZVAL_STRING(eventName, "beforeValidationOnCreate", 1);
		} else {
			ZVAL_STRING(eventName, "beforeValidationOnUpdate", 1);
		}
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_p1(_1, this_ptr, "fireeventcancel", eventName);
		if (ZEPHIR_IS_FALSE(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "validation", 1);
	zephir_call_method_p1(_0, this_ptr, "fireeventcancel", _1);
	if (ZEPHIR_IS_FALSE(_0)) {
		if (!(zephir_is_true(disableEvents))) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "onValidationFails", 1);
			zephir_call_method_p1_noret(this_ptr, "fireevent", _1);
		}
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(disableEvents))) {
		ZEPHIR_INIT_NVAR(eventName);
		if (!(zephir_is_true(exists))) {
			ZVAL_STRING(eventName, "afterValidationOnCreate", 1);
		} else {
			ZVAL_STRING(eventName, "afterValidationOnUpdate", 1);
		}
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_p1(_0, this_ptr, "fireeventcancel", eventName);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "afterValidation", 1);
		zephir_call_method_p1(_1, this_ptr, "fireeventcancel", _2);
		if (ZEPHIR_IS_FALSE(_1)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "beforeSave", 1);
		zephir_call_method_p1(_2, this_ptr, "fireeventcancel", _3);
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(eventName);
		if (zephir_is_true(exists)) {
			ZVAL_STRING(eventName, "beforeUpdate", 1);
		} else {
			ZVAL_STRING(eventName, "beforeCreate", 1);
		}
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p1(_3, this_ptr, "fireeventcancel", eventName);
		if (ZEPHIR_IS_FALSE(_3)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a document
 *
 * @param boolean disableEvents
 * @param boolean success
 * @param boolean exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _postSave) {

	zval *disableEvents_param = NULL, *success_param = NULL, *exists_param = NULL, *eventName, *_0 = NULL;
	zend_bool disableEvents, success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &disableEvents_param, &success_param, &exists_param);

		disableEvents = zephir_get_boolval(disableEvents_param);
		success = zephir_get_boolval(success_param);
		exists = zephir_get_boolval(exists_param);


	if ((success == 1)) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_VAR(eventName);
			if ((exists == 1)) {
				ZVAL_STRING(eventName, "afterUpdate", 1);
			} else {
				ZVAL_STRING(eventName, "afterCreate", 1);
			}
			zephir_call_method_p1_noret(this_ptr, "fireevent", eventName);
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "afterSave", 1);
			zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
		}
		RETURN_MM_BOOL(success);
	}
	if (!(disableEvents)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "notSave", 1);
		zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
	}
	zephir_call_method_p1_noret(this_ptr, "_canceloperation", (disableEvents ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	RETURN_MM_BOOL(0);

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
 *
 * @param object validator
 */
PHP_METHOD(Phalcon_Mvc_Collection, validate) {

	HashTable *_3;
	HashPosition _2;
	zval *validator, *message = NULL, *_0, *_1, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	if ((Z_TYPE_P(validator) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Validator must be an Object");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, validator, "validate", this_ptr);
	if (ZEPHIR_IS_FALSE(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_method(_1, validator, "getmessages");
		zephir_is_iterable(_1, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
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
 *class Subscriptors extends Phalcon\Mvc\Collection
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
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed) {

	zval *errorMessages;


	errorMessages = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if ((Z_TYPE_P(errorMessages) == IS_ARRAY)) {
		if (zephir_fast_count_int(errorMessages TSRMLS_CC)) {
			RETURN_BOOL(1);
		}
	}
	RETURN_BOOL(0);

}

/**
 * Fires an internal event
 *
 * @param string eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent) {

	zval *eventName_param = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

		if (Z_TYPE_P(eventName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		eventName = eventName_param;



	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		zephir_call_method_zval_noret(this_ptr, eventName);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p2(return_value, _0, "notifyevent", eventName, this_ptr);
	RETURN_MM();

}

/**
 * Fires an internal event that cancels the operation
 *
 * @param string eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel) {

	zval *eventName_param = NULL, *_0 = NULL, *_1;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

		if (Z_TYPE_P(eventName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		eventName = eventName_param;



	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_method_zval(_0, this_ptr, eventName);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method_p2(_0, _1, "notifyevent", eventName, this_ptr);
	if (ZEPHIR_IS_FALSE(_0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation) {

	zval *disableEvents_param = NULL, *eventName, *_0;
	zend_bool disableEvents;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &disableEvents_param);

		disableEvents = zephir_get_boolval(disableEvents_param);


	if (!(disableEvents)) {
		ZEPHIR_INIT_VAR(eventName);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZVAL_STRING(eventName, "notDeleted", 1);
		} else {
			ZVAL_STRING(eventName, "notSaved", 1);
		}
		zephir_call_method_p1_noret(this_ptr, "fireevent", eventName);
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

	zend_class_entry *_2;
	zval *collection, *id, *mongoId = NULL, *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	if ((0 == 1)) {
		if ((Z_TYPE_P(id) == IS_OBJECT)) {
			ZEPHIR_CPY_WRT(mongoId, id);
		} else {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_1);
			zephir_call_method_p1(_1, _0, "isusingimplicitobjectids", this_ptr);
			if (zephir_is_true(_1)) {
				ZEPHIR_INIT_VAR(mongoId);
				_2 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(mongoId, _2);
				zephir_call_method_p1_noret(mongoId, "__construct", id);
				zephir_update_property_this(this_ptr, SL("_id"), mongoId TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(mongoId, id);
			}
		}
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_3);
		array_init(_3);
		zephir_array_update_string(&_3, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_1, collection, "count", _3);
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(_1, 0));
	}
	RETURN_MM_BOOL(0);

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
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
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
 *	class Robots extends Phalcon\Mvc\Model
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
 *
 * @param Phalcon\Mvc\Model\MessageInterface message
 */
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage) {

	zval *message, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	if ((Z_TYPE_P(message) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "gettype", message);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Invalid message format '", _1, "'");
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Creates/Updates a collection based on the values in the atributes
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, save) {

	HashTable *_4;
	HashPosition _3;
	zend_bool success;
	zval *dependencyInjector, *connection, *exists, *source, *data, *properties, *reserved, *status, *id, *ok, *collection, *disableEvents, *key = NULL, *value = NULL, *_0, *_1, *_2, **_5, *_6;

	ZEPHIR_MM_GROW();

	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, this_ptr, "getsource");
	if ((0 == 0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	ZEPHIR_INIT_VAR(connection);
	zephir_call_method(connection, this_ptr, "getconnection");
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method_p1(collection, connection, "selectcollection", source);
	ZEPHIR_INIT_VAR(exists);
	zephir_call_method_p1(exists, this_ptr, "_exists", collection);
	if (ZEPHIR_IS_FALSE(exists)) {
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
	zephir_read_static_property_ce(&disableEvents, phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method_p3(_2, this_ptr, "_presave", dependencyInjector, disableEvents, exists);
	if (ZEPHIR_IS_FALSE(_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(reserved);
	zephir_call_method(reserved, this_ptr, "getreservedattributes");
	ZEPHIR_INIT_VAR(properties);
	zephir_call_func_p1(properties, "get_object_vars", this_ptr);
	zephir_is_iterable(properties, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
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
	array_init(_6);
	zephir_array_update_string(&_6, SL("safe"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(status);
	zephir_call_method_p2(status, collection, "save", data, _6);
	if ((Z_TYPE_P(status) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 1 TSRMLS_CC)) {
			if (zephir_is_true(ok)) {
				success = 1;
				if (ZEPHIR_IS_FALSE(exists)) {
					if (zephir_array_isset_string_fetch(&id, data, SS("_id"), 1 TSRMLS_CC)) {
						zephir_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);
					}
				}
			}
		}
	} else {
		success = 0;
	}
	zephir_call_method_p3(return_value, this_ptr, "_postsave", disableEvents, (success ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), exists);
	RETURN_MM();

}

/**
 * Find a document by its id (_id)
 *
 * @param string|\MongoId id
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, findById) {

	zend_class_entry *_0, *_3;
	zval *id, *className, *collection, *mongoId = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if ((Z_TYPE_P(id) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(className);
		zephir_call_func(className, "get_called_class");
		ZEPHIR_INIT_VAR(collection);
		_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(collection, _0);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_method(_1, collection, "getmodelsmanager");
		ZEPHIR_INIT_VAR(_2);
		zephir_call_method_p1(_2, _1, "isusingimplicitobjectids", collection);
		if (zephir_is_true(_2)) {
			ZEPHIR_INIT_VAR(mongoId);
			_3 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(mongoId, _3);
			zephir_call_method_p1_noret(mongoId, "__construct", id);
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(mongoId, id);
	}
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_array_update_string(&_2, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(_1, _2);
	zephir_call_self_p1(return_value, this_ptr, "findfirst", _1);
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
 *
 * @param array parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, findFirst) {

	zend_class_entry *_0;
	zval *parameters = NULL, *className, *collection, *connection;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters || Z_TYPE_P(parameters) == IS_NULL) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(parameters)) {
		if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for findFirst");
			return;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_call_func(className, "get_called_class");
	ZEPHIR_INIT_VAR(collection);
	_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(collection, _0);
	ZEPHIR_INIT_VAR(connection);
	zephir_call_method(connection, collection, "getconnection");
	zephir_call_self_p4(return_value, this_ptr, "_getresultset", parameters, collection, connection, ZEPHIR_GLOBAL(global_true));
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
 *
 * @param 	array parameters
 * @return  array
 */
PHP_METHOD(Phalcon_Mvc_Collection, find) {

	zend_class_entry *_0;
	zval *parameters = NULL, *className, *collection, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters || Z_TYPE_P(parameters) == IS_NULL) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(parameters)) {
		if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for find");
			return;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_call_func(className, "get_called_class");
	ZEPHIR_INIT_VAR(collection);
	_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(collection, _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, collection, "getconnection");
	zephir_call_self_p4(return_value, this_ptr, "_getresultset", parameters, collection, _1, ZEPHIR_GLOBAL(global_false));
	RETURN_MM();

}

/**
 * Perform a count over a collection
 *
 *<code>
 * echo 'There are ', Robots::count(), ' robots';
 *</code>
 *
 * @param array parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, count) {

	zend_class_entry *_0;
	zval *parameters = NULL, *className, *collection, *connection;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters || Z_TYPE_P(parameters) == IS_NULL) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(parameters)) {
		if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for count");
			return;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_call_func(className, "get_called_class");
	ZEPHIR_INIT_VAR(collection);
	_0 = zend_fetch_class(SL("className"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(collection, _0);
	ZEPHIR_INIT_VAR(connection);
	zephir_call_method(connection, collection, "getconnection");
	zephir_call_self_p3(return_value, this_ptr, "_getgroupresultset", parameters, collection, connection);
	RETURN_MM();

}

/**
 * Perform an aggregation using the Mongo aggregation framework
 *
 *
 * @param array parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, aggregate) {

	zend_class_entry *_0;
	zval *parameters, *className, *model, *connection, *source, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	if (zephir_is_true(parameters)) {
		if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid parameters for aggregate");
			return;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_call_func(className, "get_called_class");
	ZEPHIR_INIT_VAR(model);
	_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _0);
	ZEPHIR_INIT_VAR(connection);
	zephir_call_method(connection, model, "getconnection");
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, model, "getsource");
	if ((0 == 0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method_p1(_1, connection, "selectcollection", source);
	zephir_call_method_p1(return_value, _1, "aggregate", parameters);
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

	zend_class_entry *_0;
	zval *field, *conditions = NULL, *finalize = NULL, *className, *model, *connection, *source, *collection, *keys, *emptyArray, *initial, *reduce, *group, *retval, *firstRetval, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field, &conditions, &finalize);

	if (!conditions || Z_TYPE_P(conditions) == IS_NULL) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!finalize || Z_TYPE_P(finalize) == IS_NULL) {
		finalize = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(field) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid field name for group");
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_call_func(className, "get_called_class");
	ZEPHIR_INIT_VAR(model);
	_0 = zend_fetch_class(SL("className"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _0);
	ZEPHIR_INIT_VAR(connection);
	zephir_call_method(connection, model, "getconnection");
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, model, "getsource");
	if ((0 == 0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method_p1(collection, connection, "selectcollection", source);
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(emptyArray);
	array_init(emptyArray);
	ZEPHIR_INIT_VAR(initial);
	array_init(initial);
	zephir_array_update_string(&initial, SL("summatory"), &emptyArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(reduce);
	ZEPHIR_CONCAT_SVSVSVS(reduce, "function (curr, result) { if (typeof result.summatory[curr.", field, "] === \"undefined\") { result.summatory[curr.", field, "] = 1; } else { result.summatory[curr.", field, "]++; } }");
	ZEPHIR_INIT_VAR(group);
	zephir_call_method_p3(group, collection, "group", keys, initial, reduce);
	if (zephir_array_isset_string_fetch(&retval, group, SS("retval"), 1 TSRMLS_CC)) {
		if (zephir_array_isset_long_fetch(&firstRetval, retval, 0, 1 TSRMLS_CC)) {
			if (zephir_array_isset_string(firstRetval, SS("summatory"))) {
				zephir_array_fetch_string(&_1, firstRetval, SL("summatory"), PH_NOISY | PH_READONLY TSRMLS_CC);
				RETURN_CTOR(_1);
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
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, delete) {

	zend_class_entry *_3;
	zend_bool success;
	zval *disableEvents, *status, *id, *connection, *source, *collection, *mongoId = NULL, *ok, *_0 = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	if (!((0 == 1))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The document cannot be deleted because it doesn't exist");
		return;
	}
	zephir_read_static_property_ce(&disableEvents, phalcon_mvc_collection_ce, SL("_disableEvents") TSRMLS_CC);
	if (!(zephir_is_true(disableEvents))) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "beforeDelete", 1);
		zephir_call_method_p1(_0, this_ptr, "fireeventcancel", _1);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(connection);
	zephir_call_method(connection, this_ptr, "getconnection");
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, this_ptr, "getsource");
	if ((0 == 0)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method_p1(collection, connection, "selectcollection", source);
	if ((Z_TYPE_P(id) == IS_OBJECT)) {
		ZEPHIR_CPY_WRT(mongoId, id);
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_p1(_0, _2, "isusingimplicitobjectids", this_ptr);
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_VAR(mongoId);
			_3 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(mongoId, _3);
			zephir_call_method_p1_noret(mongoId, "__construct", id);
		} else {
			ZEPHIR_CPY_WRT(mongoId, id);
		}
	}
	success = 0;
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_array_update_string(&_0, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_1, SL("safe"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(status);
	zephir_call_method_p2(status, collection, "remove", _0, _1);
	if ((Z_TYPE_P(status) != IS_ARRAY)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_array_isset_string_fetch(&ok, status, SS("ok"), 1 TSRMLS_CC)) {
		if (zephir_is_true(ok)) {
			success = 1;
			if (!(zephir_is_true(disableEvents))) {
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_STRING(_0, "afterDelete", 1);
				zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
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
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, toArray) {

	HashTable *_2;
	HashPosition _1;
	zval *data, *reserved, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(reserved);
	zephir_call_method(reserved, this_ptr, "getreservedattributes");
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_object_vars", this_ptr);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
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
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, serialize) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "toarray");
	zephir_call_func_p1(return_value, "serialize", _0);
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 *
 * @param string data
 */
PHP_METHOD(Phalcon_Mvc_Collection, unserialize) {

	HashTable *_2;
	HashPosition _1;
	zval *data, *attributes, *dependencyInjector, *manager, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if ((Z_TYPE_P(data) == IS_STRING)) {
		ZEPHIR_INIT_VAR(attributes);
		zephir_call_func_p1(attributes, "unserialize", data);
		if ((Z_TYPE_P(attributes) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(dependencyInjector);
			zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
			if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ODM");
				return;
			}
			zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "collectionManager", 1);
			ZEPHIR_INIT_VAR(manager);
			zephir_call_method_p1(manager, dependencyInjector, "getshared", _0);
			if ((Z_TYPE_P(manager) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'collectionManager' is not valid");
				return;
			}
			zephir_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
			zephir_is_iterable(attributes, &_2, &_1, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HMKEY(key, _2, _1);
				ZEPHIR_GET_HVALUE(value, _3);
				zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			}
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
	return;

}


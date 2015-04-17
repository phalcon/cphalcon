
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

#include "mvc/collection.h"
#include "mvc/collectioninterface.h"
#include "mvc/collection/document.h"
#include "mvc/collection/exception.h"
#include "mvc/collection/message.h"
#include "mvc/collection/managerinterface.h"
#include "di.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "events/eventsawareinterface.h"

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

#include "internal/arginfo.h"

/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
zend_class_entry *phalcon_mvc_collection_ce;

PHP_METHOD(Phalcon_Mvc_Collection, __construct);
PHP_METHOD(Phalcon_Mvc_Collection, setId);
PHP_METHOD(Phalcon_Mvc_Collection, getId);
PHP_METHOD(Phalcon_Mvc_Collection, setDI);
PHP_METHOD(Phalcon_Mvc_Collection, getDI);
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getCollectionManager);
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes);
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds);
PHP_METHOD(Phalcon_Mvc_Collection, setSource);
PHP_METHOD(Phalcon_Mvc_Collection, getSource);
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult);
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset);
PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset);
PHP_METHOD(Phalcon_Mvc_Collection, _preSave);
PHP_METHOD(Phalcon_Mvc_Collection, _postSave);
PHP_METHOD(Phalcon_Mvc_Collection, validate);
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent);
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel);
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation);
PHP_METHOD(Phalcon_Mvc_Collection, _exists);
PHP_METHOD(Phalcon_Mvc_Collection, getMessages);
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage);
PHP_METHOD(Phalcon_Mvc_Collection, save);
PHP_METHOD(Phalcon_Mvc_Collection, findById);
PHP_METHOD(Phalcon_Mvc_Collection, findFirst);
PHP_METHOD(Phalcon_Mvc_Collection, find);
PHP_METHOD(Phalcon_Mvc_Collection, count);
PHP_METHOD(Phalcon_Mvc_Collection, aggregate);
PHP_METHOD(Phalcon_Mvc_Collection, summatory);
PHP_METHOD(Phalcon_Mvc_Collection, create);
PHP_METHOD(Phalcon_Mvc_Collection, update);
PHP_METHOD(Phalcon_Mvc_Collection, delete);
PHP_METHOD(Phalcon_Mvc_Collection, toArray);
PHP_METHOD(Phalcon_Mvc_Collection, serialize);
PHP_METHOD(Phalcon_Mvc_Collection, unserialize);
PHP_METHOD(Phalcon_Mvc_Collection, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_aggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_summatory, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, finalize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection, __construct, arginfo_phalcon_mvc_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection, setId, arginfo_phalcon_mvc_collectioninterface_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getCollectionManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getReservedAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, useImplicitObjectIds, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, setSource, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setConnectionService, arginfo_phalcon_mvc_collectioninterface_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, readAttribute, arginfo_phalcon_mvc_collectioninterface_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, writeAttribute, arginfo_phalcon_mvc_collectioninterface_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, cloneResult, arginfo_phalcon_mvc_collectioninterface_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _getResultset, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _getGroupResultset, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _preSave, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, _postSave, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, validate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, validationHasFailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, fireEvent, arginfo_phalcon_mvc_collectioninterface_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, fireEventCancel, arginfo_phalcon_mvc_collectioninterface_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, _cancelOperation, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, _exists, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, appendMessage, arginfo_phalcon_mvc_collectioninterface_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, findById, arginfo_phalcon_mvc_collectioninterface_findbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, findFirst, arginfo_phalcon_mvc_collectioninterface_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, find, arginfo_phalcon_mvc_collectioninterface_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, count, arginfo_phalcon_mvc_collectioninterface_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, aggregate, arginfo_phalcon_mvc_collection_aggregate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, summatory, arginfo_phalcon_mvc_collection_summatory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, create, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, update, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, serialize, arginfo_serializable_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, unserialize, arginfo_serializable_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, execute, arginfo_phalcon_mvc_collection_execute, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Collection, mvc_collection, phalcon_mvc_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_id"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_collectionManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
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
 * Phalcon\Mvc\Collection constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param Phalcon\Mvc\Collection\ManagerInterface $collectionManager
 */
PHP_METHOD(Phalcon_Mvc_Collection, __construct){

	zval **dependency_injector = NULL, **collection_manager = NULL;
	zval *di = NULL, *mm = NULL;
	zval *service_name;

	phalcon_fetch_params_ex(0, 2, &dependency_injector, &collection_manager);

	PHALCON_MM_GROW();

	/**
	 * We use a default DI if the user doesn't define one
	 */
	if (!dependency_injector || Z_TYPE_PP(dependency_injector) != IS_OBJECT) {
		PHALCON_CALL_CE_STATIC(&di, phalcon_di_ce, "getdefault");
	}
	else {
		di = *dependency_injector;
	}

	PHALCON_VERIFY_INTERFACE_EX(di, phalcon_diinterface_ce, phalcon_mvc_collection_exception_ce, 1);

	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), di TSRMLS_CC);

	/**
	 * Inject the manager service from the DI
	 */
	if (!collection_manager || Z_TYPE_PP(collection_manager) != IS_OBJECT) {
		PHALCON_ALLOC_GHOST_ZVAL(service_name);
		ZVAL_STRING(service_name, "collectionManager", 1);

		PHALCON_CALL_METHOD(&mm, di, "getshared", service_name);
		if (Z_TYPE_P(mm) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The injected service 'collectionManager' is not valid");
			return;
		}
	}
	else {
		mm = *collection_manager;
	}

	PHALCON_VERIFY_INTERFACE_EX(mm, phalcon_mvc_collection_managerinterface_ce, phalcon_mvc_collection_exception_ce, 1);

	/**
	 * Update the collection-manager
	 */
	phalcon_update_property_this(this_ptr, SL("_collectionManager"), mm TSRMLS_CC);

	/**
	 * The manager always initializes the object
	 */
	PHALCON_CALL_METHOD(NULL, mm, "initialize", this_ptr);

	/**
	 * This allows the developer to execute initialization stuff every time an instance
	 * is created
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "onconstruct");
	}

	PHALCON_MM_RESTORE();
}

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed $id
 */
PHP_METHOD(Phalcon_Mvc_Collection, setId){

	zval *id, *use_implicit_ids = NULL, *collection_manager;
	zval *mongo_id = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);

	if (Z_TYPE_P(id) != IS_OBJECT) {
		collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);

		/**
		 * Check if the collection use implicit ids
		 */
		PHALCON_CALL_METHOD(&use_implicit_ids, collection_manager, "isusingimplicitobjectids", this_ptr);
		if (zend_is_true(use_implicit_ids)) {
			ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce0);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				PHALCON_CALL_METHOD(NULL, mongo_id, "__construct", id);
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
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_collection_exception_ce, 0);
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

	zval *events_manager, *collection_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &events_manager);

	collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, collection_manager, "setcustomeventsmanager", this_ptr, events_manager);

	PHALCON_MM_RESTORE();
}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager){

	zval *collection_manager;

	collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(collection_manager, "getcustomeventsmanager", this_ptr);
}

/**
 * Returns the collection manager related to the entity instance
 *
 * @return Phalcon\Mvc\Collection\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection, getCollectionManager){


	RETURN_MEMBER(this_ptr, "_collectionManager");
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
		Z_ADDREF_P(dummy); add_assoc_zval_ex(return_value, SS("_connection"), dummy);
		Z_ADDREF_P(dummy); add_assoc_zval_ex(return_value, SS("_dependencyInjector"), dummy);
		Z_ADDREF_P(dummy); add_assoc_zval_ex(return_value, SS("_source"), dummy);
		Z_ADDREF_P(dummy); add_assoc_zval_ex(return_value, SS("_operationMade"), dummy);
		Z_ADDREF_P(dummy); add_assoc_zval_ex(return_value, SS("_errorMessages"), dummy);

		phalcon_update_static_property_ce(phalcon_mvc_collection_ce, SL("_reserved"), return_value TSRMLS_CC);
		return;
	}

	RETURN_ZVAL(reserved, 1, 0);
}

/**
 * Sets if a collection must use implicit objects ids
 *
 * @param boolean $useImplicitObjectIds
 */
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds){

	zval *use_implicit_object_ids, *collection_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &use_implicit_object_ids);

	collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, collection_manager, "useimplicitobjectids", this_ptr, use_implicit_object_ids);

	PHALCON_MM_RESTORE();
}

/**
 * Sets collection name which collection should be mapped
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
 * Returns collection name mapped in the collection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getSource){

	zval *source = NULL, *class_name;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(source);
	phalcon_read_property_this(&source, this_ptr, SL("_source"), PH_NOISY TSRMLS_CC);
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
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService){

	zval *connection_service, *collection_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &connection_service);

	collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, collection_manager, "setconnectionservice", this_ptr, connection_service);
	RETURN_THIS();
}

/**
 * Returns DependencyInjection connection service
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService){

	zval *collection_manager;

	collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(collection_manager, "getconnectionservice", this_ptr);
}

/**
 * Retrieves a database connection
 *
 * @return \MongoDb
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnection){

	zval *connection = NULL, *collection_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		collection_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);

		PHALCON_CALL_METHOD(&connection, collection_manager, "getconnection", this_ptr);
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
		phalcon_read_property_zval(&attribute_value, this_ptr, attribute, PH_NOISY TSRMLS_CC);
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

		PHALCON_CALL_METHOD(NULL, cloned_collection, "writeattribute", key, value);

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
	zval *source = NULL, *mongo_collection = NULL, *conditions = NULL;
	zval *fields, *documents_cursor = NULL, *limit, *sort = NULL;
	zval *base = NULL, *document = NULL, *collections, *documents_array = NULL;
	zval *collection_cloned = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &params, &collection, &connection, &unique);

	PHALCON_CALL_METHOD(&source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	PHALCON_CALL_METHOD(&mongo_collection, connection, "selectcollection", source);
	if (Z_TYPE_P(mongo_collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo collection");
		return;
	}

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

	if (Z_TYPE_P(conditions) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Find parameters must be an array");
		return;
	}

	/**
	 * Perform the find
	 */
	PHALCON_INIT_VAR(documents_cursor);
	if (phalcon_array_isset_string(params, SS("fields"))) {
		PHALCON_OBS_VAR(fields);
		phalcon_array_fetch_string(&fields, params, SL("fields"), PH_NOISY);

		PHALCON_CALL_METHOD(&documents_cursor, mongo_collection, "find", conditions, fields);
	} else {
		PHALCON_CALL_METHOD(&documents_cursor, mongo_collection, "find", conditions);
	}

	/**
	 * Check if a 'limit' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, params, SL("limit"), PH_NOISY);
		PHALCON_CALL_METHOD(NULL, documents_cursor, "limit", limit);
	}

	/**
	 * Check if a 'sort' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("sort"))) {
		PHALCON_OBS_VAR(sort);
		phalcon_array_fetch_string(&sort, params, SL("sort"), PH_NOISY);
		PHALCON_CALL_METHOD(NULL, documents_cursor, "sort", sort);
	}

	/**
	 * Check if a 'skip' clause was defined
	 */
	if (phalcon_array_isset_string(params, SS("skip"))) {
		PHALCON_OBS_NVAR(sort);
		phalcon_array_fetch_string(&sort, params, SL("skip"), PH_NOISY);
		PHALCON_CALL_METHOD(NULL, documents_cursor, "skip", sort);
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
		PHALCON_CALL_METHOD(NULL, documents_cursor, "rewind");
		PHALCON_CALL_METHOD(&document, documents_cursor, "current");
		if (Z_TYPE_P(document) == IS_ARRAY) {
			/**
			 * Assign the values to the base object
			 */
			PHALCON_RETURN_CALL_SELF("cloneresult", base, document);
			RETURN_MM();
		}

		RETURN_MM_FALSE;
	}

	/**
	 * Requesting a complete resultset
	 */
	PHALCON_INIT_VAR(collections);
	array_init(collections);

	PHALCON_CALL_FUNCTION(&documents_array, "iterator_to_array", documents_cursor);

	phalcon_is_iterable(documents_array, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(document);

		/**
		 * Assign the values to the base object
		 */
		PHALCON_CALL_SELF(&collection_cloned, "cloneresult", base, document);
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

	zval *params, *collection, *connection, *source = NULL;
	zval *mongo_collection = NULL, *conditions = NULL, *simple = NULL;
	zval *documents_cursor = NULL, *limit, *sort = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &params, &collection, &connection);

	PHALCON_CALL_METHOD(&source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	PHALCON_CALL_METHOD(&mongo_collection, connection, "selectcollection", source);

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
		PHALCON_CALL_METHOD(&documents_cursor, mongo_collection, "find", conditions);

		/**
		 * Check if a 'limit' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("limit"))) {
			PHALCON_OBS_VAR(limit);
			phalcon_array_fetch_string(&limit, params, SL("limit"), PH_NOISY);
			PHALCON_CALL_METHOD(NULL, documents_cursor, "limit", limit);
		}

		/**
		 * Check if a 'sort' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("sort"))) {
			PHALCON_OBS_VAR(sort);
			phalcon_array_fetch_string(&sort, params, SL("sort"), PH_NOISY);
			PHALCON_CALL_METHOD(NULL, documents_cursor, "sort", sort);
		}

		/**
		 * Check if a 'skip' clause was defined
		 */
		if (phalcon_array_isset_string(params, SS("skip"))) {
			PHALCON_OBS_NVAR(sort);
			phalcon_array_fetch_string(&sort, params, SL("skip"), PH_NOISY);
			PHALCON_CALL_METHOD(NULL, documents_cursor, "skip", sort);
		}

		/**
		 * Only 'count' is supported
		 */
		phalcon_fast_count(return_value, documents_cursor TSRMLS_CC);
		RETURN_MM();
	}

	PHALCON_RETURN_CALL_METHOD(mongo_collection, "count", conditions);
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

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
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

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	/**
	 * Run validation
	 */
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "validation", 1);

	PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
	if (PHALCON_IS_FALSE(status)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
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

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}

		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "afterValidation", 1);

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}

		/**
		 * Run Before Callbacks
		 */
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "beforeSave", 1);

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
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

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
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
			PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);

			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterSave", 1);
			PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
		}

		RETURN_CTOR(success);
	}
	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "notSave", 1);
		PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_canceloperation", disable_events);
	RETURN_MM_FALSE;
}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Collection\Validator\ExclusionIn as ExclusionIn;
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

	zval *validator, *status = NULL, *messages = NULL, *message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &validator);

	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Validator must be an Object");
		return;
	}

	PHALCON_CALL_METHOD(&status, validator, "validate", this_ptr);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_CALL_METHOD(&messages, validator, "getmessages");

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
 *use Phalcon\Mvc\Collection\Validator\ExclusionIn as ExclusionIn;
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
	phalcon_read_property_this(&error_messages, this_ptr, SL("_errorMessages"), PH_NOISY TSRMLS_CC);
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

	zval **event_name, *collection_manager;

	zval *lower;
	char *tmp;

	phalcon_fetch_params_ex(1, 0, &event_name);
	PHALCON_ENSURE_IS_STRING(event_name);

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(lower);
	tmp = zend_str_tolower_dup(Z_STRVAL_PP(event_name), Z_STRLEN_PP(event_name));
	ZVAL_STRINGL(lower, tmp, Z_STRLEN_PP(event_name), 0);

	/**
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists_ex(this_ptr, Z_STRVAL_P(lower), Z_STRLEN_P(lower)+1  TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(lower));
	}

	/**
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(collection_manager);
	phalcon_read_property_this(&collection_manager, this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(collection_manager, "notifyevent", *event_name, this_ptr);
	RETURN_MM();
}

/**
 * Fires an internal event that cancels the operation
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel){

	zval **event_name, *status = NULL, *collection_manager;
	zval *lower;
	char *tmp;

	phalcon_fetch_params_ex(1, 0, &event_name);
	PHALCON_ENSURE_IS_STRING(event_name);

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(lower);
	tmp = zend_str_tolower_dup(Z_STRVAL_PP(event_name), Z_STRLEN_PP(event_name));
	ZVAL_STRINGL(lower, tmp, Z_STRLEN_PP(event_name), 0);

	/**
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists_ex(this_ptr, Z_STRVAL_P(lower), Z_STRLEN_P(lower)+1  TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(&status, this_ptr, Z_STRVAL_P(lower));
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	/**
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(collection_manager);
	phalcon_read_property_this(&collection_manager, this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&status, collection_manager, "notifyevent", *event_name, this_ptr);
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
		phalcon_read_property_this(&operation_made, this_ptr, SL("_operationMade"), PH_NOISY TSRMLS_CC);
		if (PHALCON_IS_LONG(operation_made, 3)) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "notDeleted", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "notSaved", 1);
		}

		PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
	}
	RETURN_MM_FALSE;
}

/**
 * Checks if the document exists in the collection
 *
 * @param \MongoCollection $collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, _exists){

	zval *collection, *id, *mongo_id = NULL, *collection_manager;
	zval *use_implicit_ids = NULL, *parameters, *document_count = NULL;
	zval *z_zero;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &collection);

	if (phalcon_isset_property(this_ptr, SS("_id") TSRMLS_CC)) {

		PHALCON_OBS_VAR(id);
		phalcon_read_property_this(&id, this_ptr, SL("_id"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(id) == IS_OBJECT) {
			PHALCON_CPY_WRT(mongo_id, id);
		} else {
			PHALCON_OBS_VAR(collection_manager);
			phalcon_read_property_this(&collection_manager, this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);

			/**
			 * Check if the collection use implicit ids
			 */
			PHALCON_CALL_METHOD(&use_implicit_ids, collection_manager, "isusingimplicitobjectids", this_ptr);
			if (zend_is_true(use_implicit_ids)) {
				ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				PHALCON_INIT_NVAR(mongo_id);
				object_init_ex(mongo_id, ce0);
				if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
					PHALCON_CALL_METHOD(NULL, mongo_id, "__construct", id);
				}
				phalcon_update_property_this(this_ptr, SL("_id"), mongo_id TSRMLS_CC);
			} else {
				PHALCON_CPY_WRT(mongo_id, id);
			}
		}

		PHALCON_INIT_VAR(parameters);
		array_init_size(parameters, 1);
		phalcon_array_update_string(&parameters, SL("_id"), mongo_id, PH_COPY);

		/**
		 * Perform the count using the function provided by the driver
		 */
		PHALCON_CALL_METHOD(&document_count, collection, "count", parameters);

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
 * @return Phalcon\Mvc\Collection\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Collection, getMessages){


	RETURN_MEMBER(this_ptr, "_errorMessages");
}

/**
 * Appends a customized message on the validation process
 *
 *<code>
 *	use \Phalcon\Mvc\Collection\Message as Message;
 *
 *	class Robots extends Phalcon\Mvc\Collection
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
 * @param Phalcon\Mvc\Collection\MessageInterface $message
 */
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage){

	zval *message, *type = NULL, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);

	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_CALL_FUNCTION(&type, "gettype", message);

		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid message format '", type, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_collection_exception_ce, exception_message);
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Creates/Updates a collection based on the values in the attributes
 *
 * @param array $data
 * @param array $whiteList
 * @param boolean $mode true is insert or false is update
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, save){

	zval *source = NULL, *connection = NULL;
	zval *collection = NULL, *exists = NULL, *empty_array, *disable_events;
	zval *status = NULL, *data, *reserved = NULL, *properties = NULL;
	zval *success = NULL, *options;
	zval *arr = NULL, *white_list = NULL, *mode = NULL, *value = NULL;
	HashPosition hp0;
	zval **hd;
	zval *dependency_injector, *ok, *id;
	zval *params[2];
	zval func;

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &arr, &white_list, &mode);

	if (!arr) {
		arr = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	if (!mode) {
		mode = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	/**
	 * Choose a collection according to the collection name
	 */
	PHALCON_CALL_METHOD(&collection, connection, "selectcollection", source);

	/**
	 * Check the dirty state of the current operation to update the current operation
	 */
	if (Z_TYPE_P(mode) == IS_NULL) {
		PHALCON_SEPARATE_PARAM(mode);
		PHALCON_CALL_METHOD(&exists, this_ptr, "_exists", collection);

		PHALCON_INIT_NVAR(mode);

		ZVAL_BOOL(mode, (PHALCON_IS_FALSE(exists) ? 1 : 0));
		phalcon_update_property_long(this_ptr, SL("_operationMade"), (PHALCON_IS_FALSE(exists) ? 1 : 2) TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(exists);
		ZVAL_BOOL(exists, (PHALCON_IS_FALSE(mode) ? 1 : 0));

		phalcon_update_property_long(this_ptr, SL("_operationMade"), (PHALCON_IS_FALSE(exists) ? 1 : 2) TSRMLS_CC);
	}

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
	PHALCON_CALL_METHOD(&status, this_ptr, "_presave", dependency_injector, disable_events, exists);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_METHOD(&reserved, this_ptr, "getreservedattributes");
	PHALCON_CALL_FUNCTION(&properties, "get_object_vars", this_ptr);

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
				if (Z_TYPE_P(arr) == IS_ARRAY && phalcon_array_isset(arr, &key)) {
					if (Z_TYPE_P(white_list) != IS_ARRAY || phalcon_fast_in_array(&key, white_list TSRMLS_CC)) {
						PHALCON_OBS_NVAR(value);
						phalcon_array_fetch(&value, arr, &key, PH_NOISY);

						Z_ADDREF_P(value);
						if (likely(Z_TYPE(key) == IS_STRING)) {
							add_assoc_zval_ex(data, Z_STRVAL(key), Z_STRLEN(key)+1, value);
						}
						else {
							add_index_zval(data, Z_LVAL(key), value);
						}
						continue;
					}
				}

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

	if (PHALCON_IS_FALSE(mode)){
		ZVAL_STRING(&func, "save", 0);
	} else {
		ZVAL_STRING(&func, "insert", 0);
	}

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
	if (EG(exception)) {
		zval_ptr_dtor(&data);
		RETURN_MM();
	}

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

	zval_ptr_dtor(&data);

	/**
	 * Call the postSave hooks
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_postsave", disable_events, success, exists);
	RETURN_MM();
}

/**
 * Find a document by its id (_id)
 *
 * @param string|\MongoId $id
 * @return Phalcon\Mvc\Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, findById){

	zval *id, *class_name, *collection, *collection_manager = NULL;
	zval *use_implicit_ids = NULL, *mongo_id = NULL, *conditions;
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
			PHALCON_CALL_METHOD(NULL, collection, "__construct");
		}

		PHALCON_CALL_METHOD(&collection_manager, collection, "getcollectionmanager");

		/**
		 * Check if the collection use implicit ids
		 */
		PHALCON_CALL_METHOD(&use_implicit_ids, collection_manager, "isusingimplicitobjectids", collection);
		if (zend_is_true(use_implicit_ids)) {
			ce1 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(mongo_id);
			object_init_ex(mongo_id, ce1);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				PHALCON_CALL_METHOD(NULL, mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	} else {
		PHALCON_CPY_WRT(mongo_id, id);
	}

	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("_id"), mongo_id, PH_COPY);

	PHALCON_INIT_VAR(parameters);
	array_init_size(parameters, 1);
	phalcon_array_append(&parameters, conditions, 0);
	PHALCON_RETURN_CALL_SELF("findfirst", parameters);
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

	zval *parameters = NULL, *class_name, *collection, *connection = NULL;
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
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");

	unique = PHALCON_GLOBAL(z_true);
	PHALCON_RETURN_CALL_SELF("_getresultset", parameters, collection, connection, unique);
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

	zval *parameters = NULL, *class_name, *collection, *connection = NULL;
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
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");

	unique = PHALCON_GLOBAL(z_false);
	PHALCON_RETURN_CALL_SELF("_getresultset", parameters, collection, connection, unique);
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

	zval *parameters = NULL, *class_name, *collection, *connection = NULL;
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
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");
	PHALCON_RETURN_CALL_SELF("_getgroupresultset", parameters, collection, connection);
	RETURN_MM();
}

/**
 * Perform an aggregation using the Mongo aggregation framework
 *
 * @param array $parameters
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, aggregate){

	zval *parameters, *class_name, *connection = NULL;
	zval *source = NULL, *collection = NULL;
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

	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");

	PHALCON_CALL_METHOD(&source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	PHALCON_CALL_METHOD(&collection, connection, "selectcollection", source);
	PHALCON_RETURN_CALL_METHOD(collection, "aggregate", parameters);
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
	zval *connection = NULL, *source = NULL, *collection = NULL;
	zval *keys, *empty_array, *initial, *reduce, *group = NULL;
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

	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");

	PHALCON_CALL_METHOD(&source, collection, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	PHALCON_CALL_METHOD(&collection, connection, "selectcollection", source);

	PHALCON_INIT_VAR(keys);
	array_init(keys);

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);

	/**
	 * Uses a javascript hash to group the results
	 */
	PHALCON_INIT_VAR(initial);
	array_init_size(initial, 1);
	phalcon_array_update_string(&initial, SL("summatory"), empty_array, PH_COPY);

	/**
	 * Uses a javascript hash to group the results, however this is slow with larger
	 * datasets
	 */
	PHALCON_INIT_VAR(reduce);
	PHALCON_CONCAT_SVSVSVS(reduce, "function (curr, result) { if (typeof result.summatory[curr.", field, "] === \"undefined\") { result.summatory[curr.", field, "] = 1; } else { result.summatory[curr.", field, "]++; } }");

	PHALCON_CALL_METHOD(&group, collection, "group", keys, initial, reduce);
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
 * Creates a document based on the values in the attributes
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, create){

	zval *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &white_list);

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "save", data, white_list, PHALCON_GLOBAL(z_true));
	RETURN_MM();
}

/**
 * Updates a document based on the values in the attributes
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, update){

	zval *source = NULL, *connection = NULL, *collection = NULL, *exists = NULL;
	zval *type, *message, *collection_message, *messages;
	zval *data = NULL, *white_list = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &white_list);

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	/**
	 * Choose a collection according to the collection name
	 */
	PHALCON_CALL_METHOD(&collection, connection, "selectcollection", source);

	/**
	 * Check the dirty state of the current operation to update the current operation
	 */
	PHALCON_CALL_METHOD(&exists, this_ptr, "_exists", collection);

	/**
	 * If the record already exists we must throw an exception
	 */
	if (!zend_is_true(exists)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "InvalidUpdateAttempt", 1);

		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "Document cannot be updated because it does not exist", 1);

		PHALCON_INIT_VAR(collection_message);
		object_init_ex(collection_message, phalcon_mvc_collection_message_ce);
		PHALCON_CALL_METHOD(NULL, collection_message, "__construct", message, PHALCON_GLOBAL(z_null), type);

		PHALCON_INIT_VAR(messages);
		array_init_size(messages, 1);
		phalcon_array_append(&messages, collection_message, PH_SEPARATE);
		phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
		RETURN_MM_FALSE;
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "save", data, white_list, PHALCON_GLOBAL(z_false));
	RETURN_MM();
}

/**
 * Deletes a collection instance. Returning true on success or false otherwise.
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
	zval *connection = NULL, *source = NULL, *collection = NULL, *mongo_id = NULL;
	zval *collection_manager, *use_implicit_ids = NULL, *id_condition;
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

		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	PHALCON_OBS_VAR(id);
	phalcon_read_property_this(&id, this_ptr, SL("_id"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&connection, this_ptr, "getconnection");

	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	if (PHALCON_IS_EMPTY(source)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string");
		return;
	}

	/**
	 * Get the \MongoCollection
	 */
	PHALCON_CALL_METHOD(&collection, connection, "selectcollection", source);
	if (Z_TYPE_P(id) == IS_OBJECT || Z_TYPE_P(id) == IS_NULL) {
		PHALCON_CPY_WRT(mongo_id, id);
	} else {
		PHALCON_OBS_VAR(collection_manager);
		phalcon_read_property_this(&collection_manager, this_ptr, SL("_collectionManager"), PH_NOISY TSRMLS_CC);

		/**
		 * Is the collection using implicit object Ids?
		 */
		PHALCON_CALL_METHOD(&use_implicit_ids, collection_manager, "isusingimplicitobjectids", this_ptr);
		if (zend_is_true(use_implicit_ids)) {
			ce0 = zend_fetch_class(SL("MongoId"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_NVAR(mongo_id);
			object_init_ex(mongo_id, ce0);
			if (phalcon_has_constructor(mongo_id TSRMLS_CC)) {
				PHALCON_CALL_METHOD(NULL, mongo_id, "__construct", id);
			}
		} else {
			PHALCON_CPY_WRT(mongo_id, id);
		}
	}

	PHALCON_INIT_VAR(id_condition);
	array_init_size(id_condition, 1);
	phalcon_array_update_string(&id_condition, SL("_id"), mongo_id, PH_COPY);

	PHALCON_INIT_VAR(success);
	ZVAL_BOOL(success, 0);

	PHALCON_INIT_VAR(options);
	array_init_size(options, 1);
	add_assoc_long_ex(options, SS("w"), 1);

	/**
	 * Remove the instance
	 */
	PHALCON_CALL_METHOD(&status, collection, "remove", id_condition, options);
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
				PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
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

	zval *data, *reserved = NULL, *properties = NULL, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(data);
	array_init(data);

	PHALCON_CALL_METHOD(&reserved, this_ptr, "getreservedattributes");

	/**
	 * Get an array with the values of the object
	 */
	PHALCON_CALL_FUNCTION(&properties, "get_object_vars", this_ptr);

	/**
	 * We only assign values to the public properties
	 */
	phalcon_is_iterable(properties, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (PHALCON_IS_STRING(key, "_id")) {

			if (Z_TYPE_P(value) != IS_NULL) {
				phalcon_array_update_zval(&data, key, value, PH_COPY);
			}
		} else {
			if (!phalcon_array_isset(reserved, key)) {
				phalcon_array_update_zval(&data, key, value, PH_COPY);
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

	zval *data = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&data, this_ptr, "toarray");

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

	zval *data, *attributes, *dependency_injector = NULL;
	zval *service, *manager = NULL, *value = NULL, *key = NULL;
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
			PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");

			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM");
				return;
			}

			/**
			 * Update the dependency injector
			 */
			phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);

			/**
			 * Gets the default collectionManager service
			 */
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "collectionManager", 1);

			PHALCON_CALL_METHOD(&manager, dependency_injector, "getshared", service);
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The injected service 'collectionManager' is not valid");
				return;
			}

			PHALCON_VERIFY_INTERFACE(manager, phalcon_mvc_collection_managerinterface_ce);

			/**
			 * Update the collection manager
			 */
			phalcon_update_property_this(this_ptr, SL("_collectionManager"), manager TSRMLS_CC);

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
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid serialization data");
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

	zval *code, *args = NULL, *class_name, *collection, *connection = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &code, &args);

	if (args && Z_TYPE_P(args) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid args for execute");
		return;
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);

	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, ce0);
	if (phalcon_has_constructor(collection TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, collection, "__construct");
	}

	PHALCON_CALL_METHOD(&connection, collection, "getconnection");

	if (args) {
		PHALCON_RETURN_CALL_METHOD(connection, "execute", code, args);
	} else {
		PHALCON_RETURN_CALL_METHOD(connection, "execute", code);
	}

	PHALCON_MM_RESTORE();
}

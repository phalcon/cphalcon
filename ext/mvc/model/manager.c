
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
  +------------------------------------------------------------------------+
*/

#include "mvc/model/manager.h"
#include "mvc/model/managerinterface.h"
#include "mvc/model/exception.h"
#include "mvc/model/query.h"
#include "mvc/model/query/builder.h"
#include "mvc/model/relation.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "db/adapterinterface.h"
#include "events/eventsawareinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/framework/orm.h"

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\DI.
 *
 * <code>
 * $di = new Phalcon\DI();
 *
 * $di->set('modelsManager', function() {
 *      return new Phalcon\Mvc\Model\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */
zend_class_entry *phalcon_mvc_model_manager_ce;

PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, load);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent);
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior);
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots);
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, registerNamespaceAlias);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases);
PHP_METHOD(Phalcon_Mvc_Model_Manager, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelsource, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelsource, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelschema, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelschema, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setreadconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_keepsnapshots, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_usedynamicupdate, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, dynamicUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmanytomany, 0, 0, 7)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmanytomany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationrecords, 0, 0, 3)
	ZEND_ARG_INFO(0, relation)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreusablerecords, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setreusablerecords, 0, 0, 3)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, records)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmanytomany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_registernamespacealias, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getnamespacealias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_manager_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Manager, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setCustomEventsManager, arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getCustomEventsManager, arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, initialize, arginfo_phalcon_mvc_model_managerinterface_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isInitialized, arginfo_phalcon_mvc_model_managerinterface_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, load, arginfo_phalcon_mvc_model_managerinterface_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSource, arginfo_phalcon_mvc_model_manager_setmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSource, arginfo_phalcon_mvc_model_manager_getmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSchema, arginfo_phalcon_mvc_model_manager_setmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSchema, arginfo_phalcon_mvc_model_manager_getmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setConnectionService, arginfo_phalcon_mvc_model_manager_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setWriteConnectionService, arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReadConnectionService, arginfo_phalcon_mvc_model_manager_setreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnection, arginfo_phalcon_mvc_model_manager_getwriteconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnection, arginfo_phalcon_mvc_model_manager_getreadconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnectionService, arginfo_phalcon_mvc_model_manager_getreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnectionService, arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, notifyEvent, arginfo_phalcon_mvc_model_managerinterface_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, missingMethod, arginfo_phalcon_mvc_model_managerinterface_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBehavior, arginfo_phalcon_mvc_model_managerinterface_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, keepSnapshots, arginfo_phalcon_mvc_model_manager_keepsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isKeepingSnapshots, arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, useDynamicUpdate, arginfo_phalcon_mvc_model_manager_usedynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate, arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasOne, arginfo_phalcon_mvc_model_managerinterface_addhasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBelongsTo, arginfo_phalcon_mvc_model_managerinterface_addbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasMany, arginfo_phalcon_mvc_model_managerinterface_addhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasManyToMany, arginfo_phalcon_mvc_model_manager_addhasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsBelongsTo, arginfo_phalcon_mvc_model_managerinterface_existsbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasMany, arginfo_phalcon_mvc_model_managerinterface_existshasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasOne, arginfo_phalcon_mvc_model_managerinterface_existshasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasManyToMany, arginfo_phalcon_mvc_model_manager_existshasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationByAlias, arginfo_phalcon_mvc_model_manager_getrelationbyalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationRecords, arginfo_phalcon_mvc_model_manager_getrelationrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReusableRecords, arginfo_phalcon_mvc_model_manager_getreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReusableRecords, arginfo_phalcon_mvc_model_manager_setreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, clearReusableObjects, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsToRecords, arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyRecords, arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneRecords, arginfo_phalcon_mvc_model_managerinterface_gethasonerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsTo, arginfo_phalcon_mvc_model_managerinterface_getbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOne, arginfo_phalcon_mvc_model_managerinterface_gethasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyToMany, arginfo_phalcon_mvc_model_manager_gethasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelations, arginfo_phalcon_mvc_model_managerinterface_getrelations, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationsBetween, arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createQuery, arginfo_phalcon_mvc_model_managerinterface_createquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, executeQuery, arginfo_phalcon_mvc_model_managerinterface_executequery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createBuilder, arginfo_phalcon_mvc_model_managerinterface_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, registerNamespaceAlias, arginfo_phalcon_mvc_model_manager_registernamespacealias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getNamespaceAlias, arginfo_phalcon_mvc_model_manager_getnamespacealias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getNamespaceAliases, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Manager, mvc_model_manager, phalcon_mvc_model_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_readConnectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_writeConnectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasMany"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManySingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOne"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOneSingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsTo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsToSingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManyToMany"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManyToManySingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_sources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_schemas"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_behaviors"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastQuery"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_reusable"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_keepSnapshots"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dynamicUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_namespaceAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_manager_ce TSRMLS_CC, 3, phalcon_mvc_model_managerinterface_ce, phalcon_di_injectionawareinterface_ce, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a global events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager){

	zval *model, *events_manager, *class_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &events_manager);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_customEventsManager"), class_name, events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager){

	zval *model, *custom_events_manager, *class_name;
	zval *events_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(custom_events_manager);
	phalcon_read_property_this(&custom_events_manager, this_ptr, SL("_customEventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(custom_events_manager, class_name)) {
			PHALCON_OBS_VAR(events_manager);
			phalcon_array_fetch(&events_manager, custom_events_manager, class_name, PH_NOISY);
			RETURN_CTOR(events_manager);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize){

	zval *model, *class_name, *initialized, *events_manager;
	zval *event_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Models are just initialized once per request
	 */
	if (phalcon_array_isset(initialized, class_name)) {
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Update the model as initialized, this avoid cyclic initializations
	 */
	phalcon_update_property_array(this_ptr, SL("_initialized"), class_name, model TSRMLS_CC);
	
	/** 
	 * Call the 'initialize' method if it's implemented
	 */
	if (phalcon_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, model, "initialize");
	}
	
	/** 
	 * Update the last initialized model, so it can be used in
	 * modelsManager:afterInitialize
	 */
	phalcon_update_property_this(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	
	/** 
	 * If an EventsManager is available we pass to it every initialized model
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "modelsManager:afterInitialize", 1);
		PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr, model);
	}
	
	RETURN_MM_TRUE;
}

/**
 * Check whether a model is already initialized
 *
 * @param string $modelName
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized){

	zval *model_name, *initialized, *lowercased;

	phalcon_fetch_params(0, 1, 0, &model_name);
	
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	ALLOC_INIT_ZVAL(lowercased);
	phalcon_fast_strtolower(lowercased, model_name);
	
	RETVAL_BOOL(phalcon_array_isset(initialized, lowercased));
	zval_ptr_dtor(&lowercased);
}

/**
 * Get last initialized model
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized){


	RETURN_MEMBER(this_ptr, "_lastInitialized");
}

/**
 * Loads a model throwing an exception if it doesn't exist
 *
 * @param  string $modelName
 * @param  boolean $newInstance
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load){

	zval **model_name, **new_instance = NULL, *initialized;
	zval *lowercased, *model, *dependency_injector;
	zend_class_entry *ce0;

	phalcon_fetch_params_ex(1, 1, &model_name, &new_instance);

	PHALCON_MM_GROW();
	PHALCON_ENSURE_IS_STRING(model_name);

	if (!new_instance) {
		new_instance = &PHALCON_GLOBAL(z_false);
	}
	
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(lowercased);
	ZVAL_STRINGL(lowercased, zend_str_tolower_dup(Z_STRVAL_PP(model_name), Z_STRLEN_PP(model_name)), Z_STRLEN_PP(model_name), 0);
	
	/** 
	 * Check if a model with the same is already loaded
	 */
	if (phalcon_array_isset_fetch(&model, initialized, lowercased)) {
		if (zend_is_true(*new_instance)) {
			dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);

			if (Z_TYPE_P(model) != IS_OBJECT) {
				/* This shouls never happen but better safe than sorry */
				RETURN_MM_NULL();
			}

			object_init_ex(return_value, Z_OBJCE_P(model));

			if (phalcon_has_constructor(return_value TSRMLS_CC)) {
				PHALCON_CALL_METHOD(NULL, return_value, "__construct", dependency_injector, this_ptr);
			}

			RETURN_MM();
		} else {
			PHALCON_CALL_METHOD(NULL, model, "reset");
		}
	
		RETURN_CTOR(model);
	}
	
	/** 
	 * Load it using an autoloader
	 */
	if (phalcon_class_exists_ex(&ce0, *model_name, 1 TSRMLS_CC)) {
		dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);

		object_init_ex(return_value, ce0);
		if (phalcon_has_constructor(return_value TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, return_value, "__construct", dependency_injector, this_ptr);
		}
		RETURN_MM();
	}
	
	/** 
	 * The model doesn't exist throw an exception
	 */
	zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Model '%s' could not be loaded", Z_STRVAL_PP(model_name));
	PHALCON_MM_RESTORE();
}

/**
 * Sets the mapped source for a model
 *
 * @param Phalcon\Mvc\Model $model
 * @param string $source
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource){

	zval *model, *source, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &source);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model is not an object");
		return;
	}
	if (Z_TYPE_P(source) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_sources"), entity_name, source TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the mapped source for a model
 *
 * @param Phalcon\Mvc\Model $model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource){

	zval *model, *entity_name, *sources, *source = NULL, *class_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model is not an object");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(sources);
	phalcon_read_property_this(&sources, this_ptr, SL("_sources"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(sources) == IS_ARRAY) { 
		if (phalcon_array_isset(sources, entity_name)) {
			PHALCON_OBS_VAR(source);
			phalcon_array_fetch(&source, sources, entity_name, PH_NOISY);
			RETURN_CTOR(source);
		}
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class_ns(class_name, model, 0 TSRMLS_CC);
	
	PHALCON_INIT_NVAR(source);
	phalcon_uncamelize(source, class_name);
	phalcon_update_property_array(this_ptr, SL("_sources"), entity_name, source TSRMLS_CC);
	
	RETURN_CTOR(source);
}

/**
 * Sets the mapped schema for a model
 *
 * @param Phalcon\Mvc\Model $model
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema){

	zval *model, *schema, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &schema);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model is not an object");
		return;
	}
	if (Z_TYPE_P(schema) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Schema must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_schemas"), entity_name, schema TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the mapped schema for a model
 *
 * @param Phalcon\Mvc\Model $model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema){

	zval *model, *entity_name, *schemas, *schema;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model is not an object");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(schemas);
	phalcon_read_property_this(&schemas, this_ptr, SL("_schemas"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(schemas) == IS_ARRAY) { 
		if (phalcon_array_isset(schemas, entity_name)) {
			PHALCON_OBS_VAR(schema);
			phalcon_array_fetch(&schema, schemas, entity_name, PH_NOISY);
			RETURN_CTOR(schema);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Sets both write and read connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService){

	zval *model, *connection_service, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &connection_service);
	
	if (Z_TYPE_P(connection_service) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The connection service must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_readConnectionServices"), entity_name, connection_service TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_writeConnectionServices"), entity_name, connection_service TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets write connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService){

	zval *model, *connection_service, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &connection_service);
	
	if (Z_TYPE_P(connection_service) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The connection service must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_writeConnectionServices"), entity_name, connection_service TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets read connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService){

	zval *model, *connection_service, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &connection_service);
	
	if (Z_TYPE_P(connection_service) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The connection service must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_readConnectionServices"), entity_name, connection_service TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the connection to write data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection){

	zval *model, *service = NULL, *connection_services;
	zval *entity_name, *dependency_injector, *connection = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "db", 1);
	
	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property_this(&connection_services, this_ptr, SL("_writeConnectionServices"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if the model has a custom connection service
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_NVAR(service);
			phalcon_array_fetch(&service, connection_services, entity_name, PH_NOISY);
		}
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	/** 
	 * Request the connection service from the DI
	 */
	PHALCON_CALL_METHOD(&connection, dependency_injector, "getshared", service);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service");
		return;
	}
	
	PHALCON_VERIFY_INTERFACE(connection, phalcon_db_adapterinterface_ce);
	RETURN_CTOR(connection);
}

/**
 * Returns the connection to read data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection){

	zval *model, *service = NULL, *connection_services;
	zval *entity_name, *dependency_injector, *connection = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "db", 1);
	
	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property_this(&connection_services, this_ptr, SL("_readConnectionServices"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if the model has a custom connection service
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_NVAR(service);
			phalcon_array_fetch(&service, connection_services, entity_name, PH_NOISY);
		}
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	/** 
	 * Request the connection service from the DI
	 */
	PHALCON_CALL_METHOD(&connection, dependency_injector, "getshared", service);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service");
		return;
	}
	
	PHALCON_VERIFY_INTERFACE(connection, phalcon_db_adapterinterface_ce);
	RETURN_CTOR(connection);
}

/**
 * Returns the connection service name used to read data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService){

	zval *model, *connection_services, *entity_name;
	zval *connection;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property_this(&connection_services, this_ptr, SL("_readConnectionServices"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if there is a custom service connection name
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_VAR(connection);
			phalcon_array_fetch(&connection, connection_services, entity_name, PH_NOISY);
			RETURN_CTOR(connection);
		}
	}
	
	RETURN_MM_STRING("db", 1);
}

/**
 * Returns the connection service name used to write data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService){

	zval *model, *connection_services, *entity_name;
	zval *connection;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property_this(&connection_services, this_ptr, SL("_writeConnectionServices"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if there is a custom service connection name
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_VAR(connection);
			phalcon_array_fetch(&connection, connection_services, entity_name, PH_NOISY);
			RETURN_CTOR(connection);
		}
	}
	
	RETURN_MM_STRING("db", 1);
}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string $eventName
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent){

	zval *event_name, *model, *status = NULL, *behaviors, *entity_name = NULL;
	zval *models_behaviors, *behavior = NULL, *events_manager, *mgr;
	zval *fire_event_name = NULL, *custom_events_manager;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &event_name, &model);
	
	PHALCON_INIT_VAR(status);
	
	/** 
	 * Dispatch events to the global events manager
	 */
	behaviors = phalcon_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(behaviors) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset_fetch(&models_behaviors, behaviors, entity_name)) {
	
			/** 
			 * Notify all the events on the behavior
			 */
			phalcon_is_iterable(models_behaviors, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(behavior);
	
				PHALCON_CALL_METHOD(&status, behavior, "notify", event_name, model);
				if (PHALCON_IS_FALSE(status)) {
					RETURN_CTOR(status);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Dispatch events to the global events manager
	 */
	events_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
	
		PHALCON_CALL_METHOD(&status, events_manager, "fire", fire_event_name, model);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CTOR(status);
		}
	}
	
	/** 
	 * A model can has a specific events manager for it
	 */
	custom_events_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 
	
		PHALCON_INIT_NVAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset_fetch(&mgr, custom_events_manager, entity_name)) {
	
			PHALCON_INIT_NVAR(fire_event_name);
			PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
	
			PHALCON_CALL_METHOD(&status, mgr, "fire", fire_event_name, model);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_CTOR(status);
			}
		}
	}
	
	RETURN_CTOR(status);
}

/**
 * Dispatch a event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one is implemented
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $eventName
 * @param array $data
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod){

	zval *model, *event_name, *data, *behaviors, *entity_name;
	zval *models_behaviors, *behavior = NULL, *result = NULL, *events_manager;
	zval *fire_event_name;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &model, &event_name, &data);
	
	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(behaviors);
	phalcon_read_property_this(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(behaviors) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(behaviors, entity_name)) {
	
			/** 
			 * Notify all the events on the behavior
			 */
			PHALCON_OBS_VAR(models_behaviors);
			phalcon_array_fetch(&models_behaviors, behaviors, entity_name, PH_NOISY);
	
			phalcon_is_iterable(models_behaviors, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(behavior);
	
				PHALCON_CALL_METHOD(&result, behavior, "missingmethod", model, event_name, data);
				if (Z_TYPE_P(result) != IS_NULL) {
					RETURN_CTOR(result);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
		PHALCON_RETURN_CALL_METHOD(events_manager, "fire", fire_event_name, model, data);
		RETURN_MM();
	}
	
	RETURN_MM_NULL();
}

/**
 * Binds a behavior to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\Mvc\Model\BehaviorInterface $behavior
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior){

	zval *model, *behavior, *entity_name, *behaviors;
	zval *models_behaviors = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &behavior);
	
	if (Z_TYPE_P(behavior) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The behavior is invalid");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	/** 
	 * Get the current behaviors
	 */
	PHALCON_OBS_VAR(behaviors);
	phalcon_read_property_this(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(behaviors, entity_name)) {
		PHALCON_OBS_VAR(models_behaviors);
		phalcon_array_fetch(&models_behaviors, behaviors, entity_name, PH_NOISY);
	} else {
		PHALCON_INIT_NVAR(models_behaviors);
		array_init(models_behaviors);
	}
	
	/** 
	 * Append the behavior to the list of behaviors
	 */
	phalcon_array_append(&models_behaviors, behavior, PH_SEPARATE);
	
	/** 
	 * Update the behaviors list
	 */
	phalcon_update_property_array(this_ptr, SL("_behaviors"), entity_name, models_behaviors TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets if a model must keep snapshots
 *
 * @param Phalcon\Mvc\Model $model
 * @param boolean $keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots){

	zval *model, *keep_snapshots, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &keep_snapshots);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_keepSnapshots"), entity_name, keep_snapshots TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if a model is keeping snapshots for the queried records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots){

	zval *model, *keep_snapshots, *entity_name, *is_keeping;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(keep_snapshots);
	phalcon_read_property_this(&keep_snapshots, this_ptr, SL("_keepSnapshots"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(keep_snapshots) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(keep_snapshots, entity_name)) {
			PHALCON_OBS_VAR(is_keeping);
			phalcon_array_fetch(&is_keeping, keep_snapshots, entity_name, PH_NOISY);
			RETURN_CTOR(is_keeping);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 * @param Phalcon\Mvc\Model $model
 * @param boolean $dynamicUpdate
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate){

	zval *model, *dynamic_update, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &dynamic_update);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_dynamicUpdate"), entity_name, dynamic_update TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_keepSnapshots"), entity_name, dynamic_update TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if a model is using dynamic update instead of all-field update
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate){

	zval *model, *dynamic_update, *entity_name, *is_using;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(dynamic_update);
	phalcon_read_property_this(&dynamic_update, this_ptr, SL("_dynamicUpdate"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dynamic_update) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(dynamic_update, entity_name)) {
			PHALCON_OBS_VAR(is_using);
			phalcon_array_fetch(&is_using, dynamic_update, entity_name, PH_NOISY);
			RETURN_CTOR(is_using);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Setup a 1-1 relation between two models
 *
 * @param   Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne){

	zval *model, *fields, *referenced_model, *referenced_fields;
	zval *options = NULL, *entity_name, *referenced_entity;
	zval *key_relation, *has_one, *relations = NULL, *number_fields;
	zval *number_referenced, *type, *relation, *alias;
	zval *lower_alias = NULL, *key_alias, *has_one_single;
	zval *single_relations = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &model, &fields, &referenced_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property_this(&has_one, this_ptr, SL("_hasOne"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(has_one, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, has_one, key_relation, PH_NOISY);
	}
	
	/** 
	 * Check if the number of fields are the same
	 */
	if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
		if (!PHALCON_IS_EQUAL(number_fields, number_referenced)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '1' is 'has one'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 1);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD(NULL, relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_hasOne"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(has_one_single);
	phalcon_read_property_this(&has_one_single, this_ptr, SL("_hasOneSingle"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(has_one_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, has_one_single, entity_name, PH_NOISY);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_hasOneSingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

/**
 * Setup a relation reverse many to one between two models
 *
 * @param   Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo){

	zval *model, *fields, *referenced_model, *referenced_fields;
	zval *options = NULL, *entity_name, *referenced_entity;
	zval *key_relation, *belongs_to, *relations = NULL;
	zval *number_fields, *number_referenced, *type;
	zval *relation, *alias, *lower_alias = NULL, *key_alias;
	zval *belongs_to_single, *single_relations = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &model, &fields, &referenced_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property_this(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(belongs_to, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, belongs_to, key_relation, PH_NOISY);
	}
	
	/** 
	 * Check if the number of fields are the same
	 */
	if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
		if (!PHALCON_IS_EQUAL(number_fields, number_referenced)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '0' is 'belongs to'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 0);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD(NULL, relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_belongsTo"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(belongs_to_single);
	phalcon_read_property_this(&belongs_to_single, this_ptr, SL("_belongsToSingle"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(belongs_to_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, belongs_to_single, entity_name, PH_NOISY);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_belongsToSingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

/**
 * Setup a relation 1-n between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany){

	zval *model, *fields, *referenced_model, *referenced_fields;
	zval *options = NULL, *entity_name, *referenced_entity;
	zval *key_relation, *has_many, *relations = NULL, *number_fields;
	zval *number_referenced, *type, *relation, *alias;
	zval *lower_alias = NULL, *key_alias, *has_many_single;
	zval *single_relations = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &model, &fields, &referenced_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property_this(&has_many, this_ptr, SL("_hasMany"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(has_many, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, has_many, key_relation, PH_NOISY);
	}
	
	/** 
	 * Check if the number of fields are the same
	 */
	if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
		if (!PHALCON_IS_EQUAL(number_fields, number_referenced)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '2' is 'has many'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 2);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD(NULL, relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_hasMany"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(has_many_single);
	phalcon_read_property_this(&has_many_single, this_ptr, SL("_hasManySingle"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(has_many_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, has_many_single, entity_name, PH_NOISY);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_hasManySingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

/**
 * Setups a relation n-m between two models
 *
 * @param string $fields
 * @param string $intermediateModel
 * @param string $intermediateFields
 * @param string $intermediateReferencedFields
 * @param string $referencedModel
 * @param string $referencedFields
 * @param   array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany){

	zval *model, *fields, *intermediate_model, *intermediate_fields;
	zval *intermediate_referenced_fields, *referenced_model;
	zval *referenced_fields, *options = NULL, *entity_name;
	zval *intermediate_entity, *referenced_entity;
	zval *key_relation, *has_many_to_many, *relations = NULL;
	zval *number_fields = NULL, *number_referenced = NULL, *type;
	zval *relation, *alias, *lower_alias = NULL, *key_alias;
	zval *has_many_to_many_single, *single_relations = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 7, 1, &model, &fields, &intermediate_model, &intermediate_fields, &intermediate_referenced_fields, &referenced_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(intermediate_entity);
	phalcon_fast_strtolower(intermediate_entity, intermediate_model);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(has_many_to_many);
	phalcon_read_property_this(&has_many_to_many, this_ptr, SL("_hasManyToMany"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(has_many_to_many, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, has_many_to_many, key_relation, PH_NOISY);
	}
	
	/** 
	 * Check if the number of fields are the same from the model to the intermediate
	 * model
	 */
	if (Z_TYPE_P(intermediate_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, intermediate_fields TSRMLS_CC);
		if (!PHALCON_IS_EQUAL(number_fields, number_referenced)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Check if the number of fields are the same from the intermediate model to the
	 * referenced model
	 */
	if (Z_TYPE_P(intermediate_referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_NVAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_NVAR(number_referenced);
		phalcon_fast_count(number_referenced, intermediate_fields TSRMLS_CC);
		if (!PHALCON_IS_EQUAL(number_fields, number_referenced)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '4' is 'has many through'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 4);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD(NULL, relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Set extended intermediate relation data
	 */
	PHALCON_CALL_METHOD(NULL, relation, "setintermediaterelation", intermediate_fields, intermediate_model, intermediate_referenced_fields);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_hasManyToMany"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(has_many_to_many_single);
	phalcon_read_property_this(&has_many_to_many_single, this_ptr, SL("_hasManyToManySingle"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(has_many_to_many_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, has_many_to_many_single, entity_name, PH_NOISY);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_hasManyToManySingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *belongs_to;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model_name, &model_relation);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property_this(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(belongs_to, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether a model has a hasMany relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *has_many;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model_name, &model_relation);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property_this(&has_many, this_ptr, SL("_hasMany"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(has_many, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether a model has a hasOne relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *has_one;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model_name, &model_relation);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property_this(&has_one, this_ptr, SL("_hasOne"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(has_one, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether a model has a hasManyToMany relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *has_many_to_many;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model_name, &model_relation);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_many_to_many);
	phalcon_read_property_this(&has_many_to_many, this_ptr, SL("_hasManyToMany"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(has_many_to_many, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns a relation by its alias
 *
 * @param string $modelName
 * @param string $alias
 * @return Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias){

	zval *model_name, *alias, *aliases, *key_alias;
	zval *key_lower, *relation;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model_name, &alias);
	
	PHALCON_OBS_VAR(aliases);
	phalcon_read_property_this(&aliases, this_ptr, SL("_aliases"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(aliases) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(key_alias);
		PHALCON_CONCAT_VSV(key_alias, model_name, "$", alias);
	
		PHALCON_INIT_VAR(key_lower);
		phalcon_fast_strtolower(key_lower, key_alias);
		if (phalcon_array_isset(aliases, key_lower)) {
			PHALCON_OBS_VAR(relation);
			phalcon_array_fetch(&relation, aliases, key_lower, PH_NOISY);
			RETURN_CTOR(relation);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Helper method to query records based on a relation definition
 *
 * @param Phalcon\Mvc\Model\Relation $relation
 * @param string $method
 * @param Phalcon\Mvc\ModelInterface $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\Resultset\Simple
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords){

	zval *relation, *method, *record, *parameters = NULL, *pre_conditions = NULL;
	zval *placeholders = NULL, *referenced_model = NULL, *is_through = NULL;
	zval *conditions = NULL, *intermediate_model = NULL, *intermediate_fields = NULL;
	zval *fields = NULL, *value = NULL, *condition = NULL, *join_conditions;
	zval *referenced_fields = NULL, *joined_join_conditions;
	zval *joined_conditions = NULL, *builder = NULL, *query = NULL, *referenced_field = NULL;
	zval *field = NULL, *ref_position = NULL, *dependency_injector = NULL;
	zval *find_params, *find_arguments = NULL, *arguments;
	zval *type = NULL, *retrieve_method = NULL, *reusable = NULL, *unique_key;
	zval *records = NULL, *referenced_entity = NULL, *call_object;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int f_reusable;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 1, &relation, &method, &record, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	} else {
		PHALCON_SEPARATE_PARAM(parameters);
	}
	
	/** 
	 * Re-use conditions
	 */
	PHALCON_INIT_VAR(pre_conditions);
	
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		if (phalcon_array_isset_long(parameters, 0)) {
			PHALCON_OBS_NVAR(pre_conditions);
			phalcon_array_fetch_long(&pre_conditions, parameters, 0, PH_NOISY);
			phalcon_array_unset_long(&parameters, 0, PH_SEPARATE);
		} else {
			if (phalcon_array_isset_string(parameters, SS("conditions"))) {
				PHALCON_OBS_NVAR(pre_conditions);
				phalcon_array_fetch_string(&pre_conditions, parameters, SL("conditions"), PH_NOISY);
				phalcon_array_unset_string(&parameters, SS("conditions"), PH_SEPARATE);
			}
		}
	} else {
		if (Z_TYPE_P(parameters) == IS_STRING) {
			PHALCON_CPY_WRT(pre_conditions, parameters);
		}
	}
	
	/** 
	 * Re-use bound parameters
	 */
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		if (phalcon_array_isset_string(parameters, SS("bind"))) {
			PHALCON_OBS_VAR(placeholders);
			phalcon_array_fetch_string(&placeholders, parameters, SL("bind"), PH_NOISY);
			phalcon_array_unset_string(&parameters, SS("bind"), PH_SEPARATE);
		} else {
			PHALCON_INIT_NVAR(placeholders);
			array_init(placeholders);
		}
	} else {
		PHALCON_INIT_NVAR(placeholders);
		array_init(placeholders);
	}
	
	/** 
	 * Perform the query on the referenced model
	 */
	PHALCON_CALL_METHOD(&referenced_model, relation, "getreferencedmodel");
	
	/** 
	 * Check if the relation is direct or through an intermediate model
	 */
	PHALCON_CALL_METHOD(&is_through, relation, "isthrough");
	if (zend_is_true(is_through)) {
	
		PHALCON_INIT_VAR(conditions);
		array_init(conditions);
	
		PHALCON_CALL_METHOD(&intermediate_model, relation, "getintermediatemodel");
		PHALCON_CALL_METHOD(&intermediate_fields, relation, "getintermediatefields");
	
		/** 
		 * Appends conditions created from the fields defined in the relation
		 */
		PHALCON_CALL_METHOD(&fields, relation, "getfields");
		if (Z_TYPE_P(fields) != IS_ARRAY) { 
			PHALCON_CALL_METHOD(&value, record, "readattribute", fields);
	
			PHALCON_INIT_VAR(condition);
			PHALCON_CONCAT_SVSVS(condition, "[", intermediate_model, "].[", intermediate_fields, "] = ?0");
			phalcon_array_append(&conditions, condition, 0);
			phalcon_array_append(&placeholders, value, PH_SEPARATE);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not supported");
			return;
		}
	
		PHALCON_INIT_VAR(join_conditions);
		array_init(join_conditions);
	
		/** 
		 * Create the join conditions
		 */
		PHALCON_CALL_METHOD(&intermediate_fields, relation, "getintermediatereferencedfields");
		if (Z_TYPE_P(intermediate_fields) != IS_ARRAY) { 
			PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
	
			PHALCON_INIT_NVAR(condition);
			PHALCON_CONCAT_SVSV(condition, "[", intermediate_model, "].[", intermediate_fields);
			PHALCON_SCONCAT_SVSVS(condition, "] = [", referenced_model, "].[", referenced_fields, "]");
			phalcon_array_append(&join_conditions, condition, PH_SEPARATE);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not supported");
			return;
		}
	
		/** 
		 * We don't trust the user or the database so we use bound parameters
		 */
		PHALCON_INIT_VAR(joined_join_conditions);
		phalcon_fast_join_str(joined_join_conditions, SL(" AND "), join_conditions TSRMLS_CC);
	
		/** 
		 * Add extra conditions passed by the programmer
		 */
		if (PHALCON_IS_NOT_EMPTY(pre_conditions)) {
			phalcon_array_append(&conditions, pre_conditions, PH_SEPARATE);
		}
	
		/** 
		 * We don't trust the user or the database so we use bound parameters
		 */
		PHALCON_INIT_VAR(joined_conditions);
		phalcon_fast_join_str(joined_conditions, SL(" AND "), conditions TSRMLS_CC);
	
		/** 
		 * Create a query builder
		 */
		PHALCON_CALL_METHOD(&builder, this_ptr, "createbuilder", parameters);
		PHALCON_CALL_METHOD(NULL, builder, "from", referenced_model);
		PHALCON_CALL_METHOD(NULL, builder, "innerjoin", intermediate_model, joined_join_conditions);
		PHALCON_CALL_METHOD(NULL, builder, "andwhere", joined_conditions, placeholders);
	
		/** 
		 * Get the query
		 */
		PHALCON_CALL_METHOD(&query, builder, "getquery");
	
		/** 
		 * Execute the query
		 */
		PHALCON_RETURN_CALL_METHOD(query, "execute");
		RETURN_MM();
	}
	
	if (PHALCON_IS_NOT_EMPTY(pre_conditions)) {
		PHALCON_INIT_NVAR(conditions);
		array_init_size(conditions, 1);
		phalcon_array_append(&conditions, pre_conditions, PH_SEPARATE);
	} else {
		PHALCON_INIT_NVAR(conditions);
		array_init(conditions);
	}
	
	/** 
	 * Appends conditions created from the fields defined in the relation
	 */
	PHALCON_CALL_METHOD(&fields, relation, "getfields");
	if (Z_TYPE_P(fields) != IS_ARRAY) { 
		PHALCON_CALL_METHOD(&value, record, "readattribute", fields);
	
		PHALCON_CALL_METHOD(&referenced_field, relation, "getreferencedfields");
	
		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_SVS(condition, "[", referenced_field, "] = ?0");
		phalcon_array_append(&conditions, condition, PH_SEPARATE);
		phalcon_array_append(&placeholders, value, PH_SEPARATE);
	} else {
		/** 
		 * Compound relation
		 */
		PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
	
		phalcon_is_iterable(fields, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(ref_position, ah0, hp0);
			PHALCON_GET_HVALUE(field);
	
			PHALCON_CALL_METHOD(&value, record, "readattribute", field);
	
			PHALCON_OBS_NVAR(referenced_field);
			phalcon_array_fetch(&referenced_field, referenced_fields, ref_position, PH_NOISY);
	
			PHALCON_INIT_NVAR(condition);
			PHALCON_CONCAT_SVSV(condition, "[", referenced_field, "] = ?", ref_position);
			phalcon_array_append(&conditions, condition, PH_SEPARATE);
			phalcon_array_append(&placeholders, value, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_CALL_METHOD(&dependency_injector, record, "getdi");
	
	/** 
	 * We don't trust the user or the database so we use bound parameters
	 */
	PHALCON_INIT_NVAR(joined_conditions);
	phalcon_fast_join_str(joined_conditions, SL(" AND "), conditions TSRMLS_CC);
	
	/** 
	 * Create a valid params array to pass to the find/findFirst method
	 */
	PHALCON_INIT_VAR(find_params);
	array_init_size(find_params, 3);
	phalcon_array_append(&find_params, joined_conditions, 0);
	phalcon_array_update_string(&find_params, SL("bind"), placeholders, PH_COPY);
	phalcon_array_update_string(&find_params, SL("di"), dependency_injector, PH_COPY);
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		PHALCON_INIT_VAR(find_arguments);
		phalcon_fast_array_merge(find_arguments, &find_params, &parameters TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(find_arguments, find_params);
	}
	
	PHALCON_INIT_VAR(arguments);
	array_init_size(arguments, 1);
	phalcon_array_append(&arguments, find_arguments, PH_SEPARATE);
	
	/** 
	 * Check the right method to get the data
	 */
	if (Z_TYPE_P(method) == IS_NULL) {
		PHALCON_CALL_METHOD(&type, relation, "gettype");
	
		PHALCON_INIT_VAR(retrieve_method);
		switch (phalcon_get_intval(type)) {
	
			case 0:
				ZVAL_STRING(retrieve_method, "findFirst", 1);
				break;
	
			case 1:
				ZVAL_STRING(retrieve_method, "findFirst", 1);
				break;
	
			case 2:
				ZVAL_STRING(retrieve_method, "find", 1);
				break;
	
		}
	} else {
		PHALCON_CPY_WRT(retrieve_method, method);
	}
	
	/** 
	 * Find first results could be reusable
	 */
	PHALCON_CALL_METHOD(&reusable, relation, "isreusable");
	if (zend_is_true(reusable)) {
		f_reusable = 1;
	
		PHALCON_INIT_VAR(unique_key);
		phalcon_unique_key(unique_key, referenced_model, arguments TSRMLS_CC);
	
		PHALCON_CALL_METHOD(&records, this_ptr, "getreusablerecords", referenced_model, unique_key);
		if (Z_TYPE_P(records) == IS_ARRAY || Z_TYPE_P(records) == IS_OBJECT) {
			RETURN_CTOR(records);
		}
	}
	else {
		/* Use int variable in order not to confuse static code analysers */
		f_reusable = 0;
	}
	
	/** 
	 * Load the referenced model
	 */
	PHALCON_CALL_METHOD(&referenced_entity, this_ptr, "load", referenced_model);
	
	/** 
	 * Call the function in the model
	 */
	PHALCON_INIT_VAR(call_object);
	array_init_size(call_object, 2);
	phalcon_array_append(&call_object, referenced_entity, 0);
	phalcon_array_append(&call_object, retrieve_method, 0);
	
	PHALCON_INIT_NVAR(records);/**/
	PHALCON_CALL_USER_FUNC_ARRAY(records, call_object, arguments);
	
	/** 
	 * Store the result in the cache if it's reusable
	 */
	if (f_reusable) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "setreusablerecords", referenced_model, unique_key, records);
	}
	
	RETURN_CTOR(records);
}

/**
 * Returns a reusable object from the internal list
 *
 * @param string $modelName
 * @param string $key
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords){

	zval *model_name, *key, *reusable, *records;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model_name, &key);
	
	PHALCON_OBS_VAR(reusable);
	phalcon_read_property_this(&reusable, this_ptr, SL("_reusable"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(reusable, key)) {
		PHALCON_OBS_VAR(records);
		phalcon_array_fetch(&records, reusable, key, PH_NOISY);
		RETURN_CTOR(records);
	}
	
	RETURN_MM_NULL();
}

/**
 * Stores a reusable record in the internal list
 *
 * @param string $modelName
 * @param string $key
 * @param mixed $records
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords){

	zval *model_name, *key, *records;

	phalcon_fetch_params(0, 3, 0, &model_name, &key, &records);
	
	phalcon_update_property_array(this_ptr, SL("_reusable"), key, records TSRMLS_CC);
	
}

/**
 * Clears the internal reusable list
 *
 * @param
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects){


	phalcon_update_property_null(this_ptr, SL("_reusable") TSRMLS_CC);
	
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *belongs_to, *entity_name;
	zval *entity_relation, *key_relation, *relations;
	zval *relation;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &method, &model_name, &model_relation, &record, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property_this(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
	
		/** 
		 * Check if there is a relation between them
		 */
		PHALCON_INIT_VAR(key_relation);
		PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
		if (!phalcon_array_isset(belongs_to, key_relation)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * relations is an array with all the belongsTo relationships to that model
		 */
		PHALCON_OBS_VAR(relations);
		phalcon_array_fetch(&relations, belongs_to, key_relation, PH_NOISY);
	
		/** 
		 * Get the first relation
		 */
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY);
	
		/** 
		 * Perform the query
		 */
		PHALCON_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", relation, method, record, parameters);
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *has_many, *entity_name, *entity_relation;
	zval *key_relation, *relations, *relation;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &method, &model_name, &model_relation, &record, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property_this(&has_many, this_ptr, SL("_hasMany"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
	
		/** 
		 * Check if there is a relation between them
		 */
		PHALCON_INIT_VAR(key_relation);
		PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
		if (!phalcon_array_isset(has_many, key_relation)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * relations is an array with all the belongsTo relationships to that model
		 */
		PHALCON_OBS_VAR(relations);
		phalcon_array_fetch(&relations, has_many, key_relation, PH_NOISY);
	
		/** 
		 * Get the first relation
		 */
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY);
	
		/** 
		 * Perform the query
		 */
		PHALCON_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", relation, method, record, parameters);
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *has_one, *entity_name, *entity_relation;
	zval *key_relation, *relations, *relation;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &method, &model_name, &model_relation, &record, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property_this(&has_one, this_ptr, SL("_hasOne"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
	
		/** 
		 * Check if there is a relation between them
		 */
		PHALCON_INIT_VAR(key_relation);
		PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
		if (!phalcon_array_isset(has_one, key_relation)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * relations is an array with all the belongsTo relationships to that model
		 */
		PHALCON_OBS_VAR(relations);
		phalcon_array_fetch(&relations, has_one, key_relation, PH_NOISY);
	
		/** 
		 * Get the first relation
		 */
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY);
	
		/** 
		 * Perform the query
		 */
		PHALCON_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", relation, method, record, parameters);
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets all the belongsTo relations defined in a model
 *
 *<code>
 *	$relations = $modelsManager->getBelongsTo(new Robots());
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo){

	zval *model, *belongs_to_single, *lower_name;
	zval *relations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(belongs_to_single);
	phalcon_read_property_this(&belongs_to_single, this_ptr, SL("_belongsToSingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(belongs_to_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(belongs_to_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to_single, lower_name, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany){

	zval *model, *has_many_single, *lower_name, *relations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(has_many_single);
	phalcon_read_property_this(&has_many_single, this_ptr, SL("_hasManySingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_many_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(has_many_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_many_single, lower_name, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne){

	zval *model, *has_one_single, *lower_name, *relations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(has_one_single);
	phalcon_read_property_this(&has_one_single, this_ptr, SL("_hasOneSingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_one_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(has_one_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_one_single, lower_name, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Gets hasManyToMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany){

	zval *model, *has_many_to_many_single, *lower_name;
	zval *relations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(has_many_to_many_single);
	phalcon_read_property_this(&has_many_to_many_single, this_ptr, SL("_hasManyToManySingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_many_to_many_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(has_many_to_many_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_many_to_many_single, lower_name, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany){

	zval *model, *has_one = NULL, *has_many = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_CALL_METHOD(&has_one, this_ptr, "gethasone", model);
	PHALCON_CALL_METHOD(&has_many, this_ptr, "gethasmany", model);
	phalcon_fast_array_merge(return_value, &has_one, &has_many TSRMLS_CC);
	RETURN_MM();
}

/**
 * Query all the relationships defined on a model
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations){

	zval *model_name, *entity_name, *all_relations;
	zval *belongs_to, *relations = NULL, *relation = NULL, *has_many;
	zval *has_one;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model_name);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(all_relations);
	array_init(all_relations);
	
	/** 
	 * Get belongs-to relations
	 */
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property_this(&belongs_to, this_ptr, SL("_belongsToSingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
		if (phalcon_array_isset(belongs_to, entity_name)) {
	
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to, entity_name, PH_NOISY);
	
			phalcon_is_iterable(relations, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(relation);
	
				phalcon_array_append(&all_relations, relation, PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Get has-many relations
	 */
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property_this(&has_many, this_ptr, SL("_hasManySingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
		if (phalcon_array_isset(has_many, entity_name)) {
	
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_many, entity_name, PH_NOISY);
	
			phalcon_is_iterable(relations, &ah1, &hp1, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_HVALUE(relation);
	
				phalcon_array_append(&all_relations, relation, PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		}
	}
	
	/** 
	 * Get has-one relations
	 */
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property_this(&has_one, this_ptr, SL("_hasOneSingle"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
		if (phalcon_array_isset(has_one, entity_name)) {
	
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_one, entity_name, PH_NOISY);
	
			phalcon_is_iterable(relations, &ah2, &hp2, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
				PHALCON_GET_HVALUE(relation);
	
				phalcon_array_append(&all_relations, relation, PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah2, &hp2);
			}
	
		}
	}
	
	RETURN_CTOR(all_relations);
}

/**
 * Query the first relationship defined between two models
 *
 * @param string $first
 * @param string $second
 * @return Phalcon\Mvc\Model\RelationInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween){

	zval *first, *second, *first_name, *second_name;
	zval *key_relation, *belongs_to, *relations = NULL;
	zval *has_many, *has_one;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &first, &second);
	
	PHALCON_INIT_VAR(first_name);
	phalcon_fast_strtolower(first_name, first);
	
	PHALCON_INIT_VAR(second_name);
	phalcon_fast_strtolower(second_name, second);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, first_name, "$", second_name);
	
	/** 
	 * Check if it's a belongs-to relationship
	 */
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property_this(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
		if (phalcon_array_isset(belongs_to, key_relation)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to, key_relation, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	/** 
	 * Check if it's a has-many relationship
	 */
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property_this(&has_many, this_ptr, SL("_hasMany"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
		if (phalcon_array_isset(has_many, key_relation)) {
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_many, key_relation, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	/** 
	 * Check if it's a has-one relationship
	 */
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property_this(&has_one, this_ptr, SL("_hasOne"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
		if (phalcon_array_isset(has_one, key_relation)) {
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_one, key_relation, PH_NOISY);
			RETURN_CTOR(relations);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 *
 * @param string $phql
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery){

	zval *phql, *dependency_injector, *query;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &phql);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_exception_ce, 1);
	
	/** 
	 * Create a query
	 */
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD(NULL, query, "__construct", phql);
	
	PHALCON_CALL_METHOD(NULL, query, "setdi", dependency_injector);
	phalcon_update_property_this(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	
	RETURN_CTOR(query);
}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param string $phql
 * @param array $placeholders
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery){

	zval *phql, *placeholders = NULL, *types = NULL, *dependency_injector;
	zval *query;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &phql, &placeholders, &types);
	
	if (!placeholders) {
		placeholders = PHALCON_GLOBAL(z_null);
	}
	
	if (!types) {
		types = PHALCON_GLOBAL(z_null);
	}

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	/** 
	 * Create a query
	 */
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD(NULL, query, "__construct", phql);
	
	PHALCON_CALL_METHOD(NULL, query, "setdi", dependency_injector);
	phalcon_update_property_this(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	
	/** 
	 * Execute the query
	 */
	PHALCON_RETURN_CALL_METHOD(query, "execute", placeholders, types);
	RETURN_MM();
}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string $params
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder){

	zval *params = NULL, *dependency_injector;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &params);
	
	if (!params) {
		params = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	/** 
	 * Create a query builder
	 */
	object_init_ex(return_value, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", params, dependency_injector);
	
	RETURN_MM();
}

/**
 * Returns the lastest query created or executed in the models manager
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery){


	RETURN_MEMBER(this_ptr, "_lastQuery");
}

/**
 * Registers shorter aliases for namespaces in PHQL statements
 *
 * @param string $alias
 * @param string $namespace
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, registerNamespaceAlias){

	zval *alias, *namespace;

	phalcon_fetch_params(0, 2, 0, &alias, &namespace);
	
	if (Z_TYPE_P(alias) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "The namespace alias must be a string");
		return;
	}
	if (Z_TYPE_P(namespace) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "The namespace must be a string");
		return;
	}
	
	phalcon_update_property_array(this_ptr, SL("_namespaceAliases"), alias, namespace TSRMLS_CC);
	
}

/**
 * Returns a real namespace from its alias
 *
 * @param string $alias
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias){

	zval *alias, *namespace_aliases, *namespace;
	zval *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &alias);
	
	PHALCON_OBS_VAR(namespace_aliases);
	phalcon_read_property_this(&namespace_aliases, this_ptr, SL("_namespaceAliases"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(namespace_aliases, alias)) {
		PHALCON_OBS_VAR(namespace);
		phalcon_array_fetch(&namespace, namespace_aliases, alias, PH_NOISY);
		RETURN_CTOR(namespace);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Namespace alias '", alias, "' is not registered");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
}

/**
 * Returns all the registered namespace aliases
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases){


	RETURN_MEMBER(this_ptr, "_namespaceAliases");
}

/**
 * Destroys the PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, __destruct){

	phalcon_orm_destroy_cache(TSRMLS_C);
}

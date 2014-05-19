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

#include "mvc/model.h"
#include "mvc/modelinterface.h"
#include "mvc/model/criteria.h"
#include "mvc/model/exception.h"
#include "mvc/model/managerinterface.h"
#include "mvc/model/message.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/query/builder.h"
#include "mvc/model/resultinterface.h"
#include "mvc/model/validationfailed.h"
#include "mvc/model/validatorinterface.h"
#include "di.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "db/rawvalue.h"

#include <ext/pdo/php_pdo_driver.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/variables.h"

#include "interned-strings.h"

/**
 * Phalcon\Mvc\Model
 *
 * <p>Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.</p>
 *
 * <p>Phalcon\Mvc\Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.</p>
 *
 * <code>
 *
 * $robot = new Robots();
 * $robot->type = 'mechanical';
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo $message;
 *  }
 * } else {
 *  echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 *
 */
zend_class_entry *phalcon_mvc_model_ce;

PHP_METHOD(Phalcon_Mvc_Model, __construct);
PHP_METHOD(Phalcon_Mvc_Model, setDI);
PHP_METHOD(Phalcon_Mvc_Model, getDI);
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData);
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager);
PHP_METHOD(Phalcon_Mvc_Model, setTransaction);
PHP_METHOD(Phalcon_Mvc_Model, setSource);
PHP_METHOD(Phalcon_Mvc_Model, getSource);
PHP_METHOD(Phalcon_Mvc_Model, setSchema);
PHP_METHOD(Phalcon_Mvc_Model, getSchema);
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState);
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState);
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection);
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection);
PHP_METHOD(Phalcon_Mvc_Model, assign);
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap);
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate);
PHP_METHOD(Phalcon_Mvc_Model, cloneResult);
PHP_METHOD(Phalcon_Mvc_Model, find);
PHP_METHOD(Phalcon_Mvc_Model, findFirst);
PHP_METHOD(Phalcon_Mvc_Model, query);
PHP_METHOD(Phalcon_Mvc_Model, _exists);
PHP_METHOD(Phalcon_Mvc_Model, _groupResult);
PHP_METHOD(Phalcon_Mvc_Model, count);
PHP_METHOD(Phalcon_Mvc_Model, sum);
PHP_METHOD(Phalcon_Mvc_Model, maximum);
PHP_METHOD(Phalcon_Mvc_Model, minimum);
PHP_METHOD(Phalcon_Mvc_Model, average);
PHP_METHOD(Phalcon_Mvc_Model, fireEvent);
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel);
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation);
PHP_METHOD(Phalcon_Mvc_Model, appendMessage);
PHP_METHOD(Phalcon_Mvc_Model, validate);
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Model, getMessages);
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict);
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict);
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade);
PHP_METHOD(Phalcon_Mvc_Model, _preSave);
PHP_METHOD(Phalcon_Mvc_Model, _postSave);
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert);
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate);
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, _postSaveRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, save);
PHP_METHOD(Phalcon_Mvc_Model, create);
PHP_METHOD(Phalcon_Mvc_Model, update);
PHP_METHOD(Phalcon_Mvc_Model, delete);
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade);
PHP_METHOD(Phalcon_Mvc_Model, refresh);
PHP_METHOD(Phalcon_Mvc_Model, skipOperation);
PHP_METHOD(Phalcon_Mvc_Model, readAttribute);
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate);
PHP_METHOD(Phalcon_Mvc_Model, hasOne);
PHP_METHOD(Phalcon_Mvc_Model, belongsTo);
PHP_METHOD(Phalcon_Mvc_Model, hasMany);
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model, addBehavior);
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots);
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, hasChanged);
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields);
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model, getRelated);
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, __call);
PHP_METHOD(Phalcon_Mvc_Model, __callStatic);
PHP_METHOD(Phalcon_Mvc_Model, __set);
PHP_METHOD(Phalcon_Mvc_Model, __get);
PHP_METHOD(Phalcon_Mvc_Model, __isset);
PHP_METHOD(Phalcon_Mvc_Model, serialize);
PHP_METHOD(Phalcon_Mvc_Model, unserialize);
PHP_METHOD(Phalcon_Mvc_Model, dump);
PHP_METHOD(Phalcon_Mvc_Model, toArray);
PHP_METHOD(Phalcon_Mvc_Model, setup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setschema, 0, 0, 1)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, validator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipoperation, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipattributesoncreate, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipattributesonupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hasone, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_belongsto, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hasmany, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hasmanytomany, 0, 0, 6)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_addbehavior, 0, 0, 1)
	ZEND_ARG_INFO(0, behavior)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_keepsnapshots, 0, 0, 1)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setsnapshotdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_haschanged, 0, 0, 0)
	ZEND_ARG_INFO(0, fieldName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_usedynamicupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, dynamicUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___callstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setup, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model, __construct, arginfo_phalcon_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setEventsManager, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getEventsManager, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getModelsMetaData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getModelsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setTransaction, arginfo_phalcon_mvc_modelinterface_settransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setSource, arginfo_phalcon_mvc_model_setsource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setSchema, arginfo_phalcon_mvc_model_setschema, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getSchema, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setConnectionService, arginfo_phalcon_mvc_modelinterface_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setReadConnectionService, arginfo_phalcon_mvc_modelinterface_setreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setWriteConnectionService, arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getReadConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getWriteConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setDirtyState, arginfo_phalcon_mvc_model_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getDirtyState, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getReadConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getWriteConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, assign, arginfo_phalcon_mvc_modelinterface_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResultMap, arginfo_phalcon_mvc_modelinterface_cloneresultmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResultMapHydrate, arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResult, arginfo_phalcon_mvc_modelinterface_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, find, arginfo_phalcon_mvc_modelinterface_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, findFirst, arginfo_phalcon_mvc_modelinterface_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, query, arginfo_phalcon_mvc_modelinterface_query, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, _exists, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _groupResult, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, count, arginfo_phalcon_mvc_modelinterface_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, sum, arginfo_phalcon_mvc_modelinterface_sum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, maximum, arginfo_phalcon_mvc_modelinterface_maximum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, minimum, arginfo_phalcon_mvc_modelinterface_minimum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, average, arginfo_phalcon_mvc_modelinterface_average, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, fireEvent, arginfo_phalcon_mvc_modelinterface_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, fireEventCancel, arginfo_phalcon_mvc_modelinterface_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, _cancelOperation, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, appendMessage, arginfo_phalcon_mvc_modelinterface_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, validate, arginfo_phalcon_mvc_model_validate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, validationHasFailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getMessages, arginfo_phalcon_mvc_modelinterface_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysRestrict, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _preSave, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _postSave, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _doLowInsert, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _doLowUpdate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _preSaveRelatedRecords, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _postSaveRelatedRecords, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, save, arginfo_phalcon_mvc_modelinterface_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, create, arginfo_phalcon_mvc_modelinterface_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, update, arginfo_phalcon_mvc_modelinterface_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getOperationMade, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, refresh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, skipOperation, arginfo_phalcon_mvc_model_skipoperation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, readAttribute, arginfo_phalcon_mvc_modelinterface_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, writeAttribute, arginfo_phalcon_mvc_modelinterface_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, skipAttributes, arginfo_phalcon_mvc_model_skipattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnCreate, arginfo_phalcon_mvc_model_skipattributesoncreate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnUpdate, arginfo_phalcon_mvc_model_skipattributesonupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasOne, arginfo_phalcon_mvc_model_hasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, belongsTo, arginfo_phalcon_mvc_model_belongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasMany, arginfo_phalcon_mvc_model_hasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasManyToMany, arginfo_phalcon_mvc_model_hasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, addBehavior, arginfo_phalcon_mvc_model_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, keepSnapshots, arginfo_phalcon_mvc_model_keepsnapshots, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, setSnapshotData, arginfo_phalcon_mvc_model_setsnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasSnapshotData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getSnapshotData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasChanged, arginfo_phalcon_mvc_model_haschanged, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getChangedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, useDynamicUpdate, arginfo_phalcon_mvc_model_usedynamicupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getRelated, arginfo_phalcon_mvc_modelinterface_getrelated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, _getRelatedRecords, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, __call, arginfo_phalcon_mvc_model___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __callStatic, arginfo_phalcon_mvc_model___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, __set, arginfo_phalcon_mvc_model___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __get, arginfo_phalcon_mvc_model___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __isset, arginfo_phalcon_mvc_model___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, unserialize, arginfo_phalcon_mvc_model_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, dump, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, toArray, arginfo_phalcon_mvc_model_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setup, arginfo_phalcon_mvc_model_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Model, mvc_model, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsMetaData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_ce, SL("_dirtyState"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_skipped"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_related"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_snapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 4, phalcon_mvc_modelinterface_ce, phalcon_mvc_model_resultinterface_ce, phalcon_di_injectionawareinterface_ce, zend_ce_serializable);

	return SUCCESS;
}

/**
 * <code>
 * 	private function getMessagesFromModel($model, $target)
 * 	{
 * 		$messages = $model->getMessages();
 * 		foreach ($messages as $message) {
 * 			if (is_object($message)) {
 * 				$message->setModel($target);
 * 			}
 *
 * 			$this->appendMessage($message);
 * 		}
 * 	}
 * </code>
 */
static int phalcon_mvc_model_get_messages_from_model(zval *this_ptr, zval *model, zval *target TSRMLS_DC)
{
	zval *messages = NULL, **message;
	HashPosition hp;

	if (
		   phalcon_call_method(&messages, model, "getmessages", 0, NULL TSRMLS_CC) == FAILURE
		|| Z_TYPE_P(messages) != IS_ARRAY
	) {
		if (messages) {
			zval_ptr_dtor(&messages);
		}

		return FAILURE;
	}

	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(messages), &hp);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(messages), (void**)&message, &hp) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(messages), &hp)
	) {
		if (Z_TYPE_PP(message) == IS_OBJECT) {
			zval *params[] = { target };
			if (FAILURE == phalcon_call_method(NULL, *message, "setmodel", 1, params TSRMLS_CC)) {
				break;
			}
		}

		{
			zval *params[] = { *message };
			if (FAILURE == phalcon_call_method(NULL, this_ptr, "appendmessage", 1, params TSRMLS_CC)) {
				break;
			}
		}
	}

	zval_ptr_dtor(&messages);
	return likely(!EG(exception)) ? SUCCESS : FAILURE;
}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param Phalcon\Mvc\Model\ManagerInterface $modelsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct){

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
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
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
		ZVAL_STRING(service_name, "modelsManager", 1);
	
		PHALCON_CALL_METHOD(&models_manager, dependency_injector, "getshared", service_name);
		if (Z_TYPE_P(models_manager) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
			return;
		}

		PHALCON_VERIFY_INTERFACE(models_manager, phalcon_mvc_model_managerinterface_ce);
	}
	
	/** 
	 * Update the models-manager
	 */
	phalcon_update_property_this(this_ptr, SL("_modelsManager"), models_manager TSRMLS_CC);
	
	/** 
	 * The manager always initializes the object
	 */
	PHALCON_CALL_METHOD(NULL, models_manager, "initialize", this_ptr);
	
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
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a custom events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager){

	zval *events_manager, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &events_manager);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, models_manager, "setcustomeventsmanager", this_ptr, events_manager);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager){

	zval *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getcustomeventsmanager", this_ptr);
	RETURN_MM();
}

/**
 * Returns the models meta-data service related to the entity instance
 *
 * @return Phalcon\Mvc\Model\MetaDataInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData){

	zval *meta_data = NULL, *dependency_injector, *service;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_modelsMetaData"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(meta_data) != IS_OBJECT) {
	
		/** 
		 * Check if the DI is valid
		 */
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
			return;
		}
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "modelsMetadata", 1);
	
		/** 
		 * Obtain the models-metadata service from the DI
		 */
		PHALCON_CALL_METHOD(&meta_data, dependency_injector, "getshared", service);
		if (Z_TYPE_P(meta_data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid");
			return;
		}
	
		PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);

		/** 
		 * Update the models-metada property
		 */
		phalcon_update_property_this(this_ptr, SL("_modelsMetaData"), meta_data TSRMLS_CC);
	}
	
	RETURN_CTOR(meta_data);
}

/**
 * Returns the models manager related to the entity instance
 *
 * @return Phalcon\Mvc\Model\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager){


	RETURN_MEMBER(this_ptr, "_modelsManager");
}

/**
 * Sets a transaction related to the Model instance
 *
 *<code>
 *use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
 *use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
 *
 *try {
 *
 *  $txManager = new TxManager();
 *
 *  $transaction = $txManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if ($robot->save() == false) {
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Robot part cannot be saved");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch (TxFailed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction){

	zval *transaction;

	phalcon_fetch_params(0, 1, 0, &transaction);
	
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_transaction"), transaction TSRMLS_CC);
		RETURN_THISW();
	}
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Transaction should be an object");
	return;
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource){

	zval *source, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &source);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, models_manager, "setmodelsource", this_ptr, source);
	RETURN_THIS();
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource){

	zval *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getmodelsource", this_ptr);
	RETURN_MM();
}

/**
 * Sets schema name where table mapped is located
 *
 * @param string $schema
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema){

	zval *schema, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &schema);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, models_manager, "setmodelschema", this_ptr, schema);
	RETURN_THIS();
}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema){

	zval *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getmodelschema", this_ptr);
	RETURN_MM();
}

/**
 * Sets the DependencyInjection connection service name
 *
 * @param string $connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService){

	zval *connection_service, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &connection_service);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, models_manager, "setconnectionservice", this_ptr, connection_service);
	RETURN_THIS();
}

/**
 * Sets the DependencyInjection connection service name used to read data
 *
 * @param string $connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService){

	zval *connection_service, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &connection_service);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, models_manager, "setreadconnectionservice", this_ptr, connection_service);
	RETURN_THIS();
}

/**
 * Sets the DependencyInjection connection service name used to write data
 *
 * @param string $connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService){

	zval *connection_service, *models_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &connection_service);
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, models_manager, "setwriteconnectionservice", this_ptr, connection_service);
	RETURN_THIS();
}

/**
 * Returns the DependencyInjection connection service name used to read data related the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService){

	zval *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getreadconnectionservice", this_ptr);
	RETURN_MM();
}

/**
 * Returns the DependencyInjection connection service name used to write data related to the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService){

	zval *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getwriteconnectionservice", this_ptr);
	RETURN_MM();
}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 *
 * @param int $dirtyState
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState){

	zval *dirty_state;

	phalcon_fetch_params(0, 1, 0, &dirty_state);
	
	phalcon_update_property_this(this_ptr, SL("_dirtyState"), dirty_state TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState){


	RETURN_MEMBER(this_ptr, "_dirtyState");
}

/**
 * Gets the connection used to read data for the model
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection){

	zval *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getreadconnection", this_ptr);
	RETURN_MM();
}

/**
 * Gets the connection used to write data to the model
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection){

	zval *transaction, *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
	phalcon_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(transaction, "getconnection");
		RETURN_MM();
	}
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(models_manager, "getwriteconnection", this_ptr);
	RETURN_MM();
}

/**
 * Assigns values to a model from an array
 *
 *<code>
 *$robot->assign(array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model $object
 * @param array $data
 * @param array $columnMap
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, assign){

	zval *data, *column_map = NULL, *value = NULL, *key = NULL, *attribute = NULL;
	zval *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &data, &column_map);
	
	if (!column_map) {
		column_map = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
		return;
	}
	
	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		/** 
		 * Only string keys in the data are valid
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
	
			/** 
			 * Every field must be part of the column map
			 */
			if (phalcon_array_isset(column_map, key)) {
				PHALCON_OBS_NVAR(attribute);
				phalcon_array_fetch(&attribute, column_map, key, PH_NOISY);
				phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column \"", key, "\" doesn't make part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Assigns values to a model from an array returning a new model.
 *
 *<code>
 *$robot = \Phalcon\Mvc\Model::cloneResultMap(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model $base
 * @param array $data
 * @param array $columnMap
 * @param int $dirtyState
 * @param boolean $keepSnapshots
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap){

	zval *base, *data, *column_map, *dirty_state = NULL, *keep_snapshots = NULL;
	zval *object, *value = NULL, *key = NULL, *attribute = NULL, *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 2, &base, &data, &column_map, &dirty_state, &keep_snapshots);
	
	if (!dirty_state) {
		dirty_state = PHALCON_GLOBAL(z_zero);
	}
	
	if (!keep_snapshots) {
		keep_snapshots = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
		return;
	}
	
	PHALCON_INIT_VAR(object);
	if (phalcon_clone(object, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	/** 
	 * Change the dirty state to persistent
	 */
	PHALCON_CALL_METHOD(NULL, object, "setdirtystate", dirty_state);
	
	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (Z_TYPE_P(key) == IS_STRING) {
	
			/** 
			 * Only string keys in the data are valid
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
	
				/** 
				 * Every field must be part of the column map
				 */
				if (phalcon_array_isset(column_map, key)) {
					PHALCON_OBS_NVAR(attribute);
					phalcon_array_fetch(&attribute, column_map, key, PH_NOISY);
					phalcon_update_property_zval_zval(object, attribute, value TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column \"", key, "\" doesn't make part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	if (zend_is_true(keep_snapshots)) {
		PHALCON_CALL_METHOD(NULL, object, "setsnapshotdata", data, column_map);
	}
	
	/** 
	 * Call afterFetch, this allows the developer to execute actions after a record is
	 * fetched from the database
	 */
	if (phalcon_method_exists_ex(object, SS("afterfetch") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, object, "afterfetch");
	}
	
	RETURN_CTOR(object);
}

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array $data
 * @param array $columnMap
 * @param int $hydrationMode
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate){

	zval *data, *column_map, *hydration_mode, *hydrate = NULL;
	zval *value = NULL, *key = NULL, *exception_message = NULL, *attribute = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &data, &column_map, &hydration_mode);
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to hidrate must be an Array");
		return;
	}
	
	/** 
	 * If there is no column map and the hydration mode is arrays return the data as it
	 * is
	 */
	if (Z_TYPE_P(column_map) != IS_ARRAY) { 
		if (PHALCON_IS_LONG(hydration_mode, 1)) {
			RETURN_CTOR(data);
		}
	}
	
	/** 
	 * Create the destination object according to the hydration mode
	 */
	if (PHALCON_IS_LONG(hydration_mode, 1)) {
		PHALCON_INIT_VAR(hydrate);
		array_init(hydrate);
	} else {
		PHALCON_INIT_NVAR(hydrate);
		object_init(hydrate);
	}
	
	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (Z_TYPE_P(key) == IS_STRING) {
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
	
				/** 
				 * Every field must be part of the column map
				 */
				if (!phalcon_array_isset(column_map, key)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column \"", key, "\" doesn't make part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				PHALCON_OBS_NVAR(attribute);
				phalcon_array_fetch(&attribute, column_map, key, PH_NOISY);
				if (PHALCON_IS_LONG(hydration_mode, 1)) {
					phalcon_array_update_zval(&hydrate, attribute, value, PH_COPY | PH_SEPARATE);
				} else {
					phalcon_update_property_zval_zval(hydrate, attribute, value TSRMLS_CC);
				}
			} else {
				if (PHALCON_IS_LONG(hydration_mode, 1)) {
					phalcon_array_update_zval(&hydrate, key, value, PH_COPY | PH_SEPARATE);
				} else {
					phalcon_update_property_zval_zval(hydrate, key, value TSRMLS_CC);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(hydrate);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *<code>
 *$robot = Phalcon\Mvc\Model::cloneResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model $base
 * @param array $data
 * @param int $dirtyState
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult){

	zval *base, *data, *dirty_state = NULL, *object, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &base, &data, &dirty_state);
	
	if (!dirty_state) {
		dirty_state = PHALCON_GLOBAL(z_zero);
	}
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
		return;
	}
	
	/** 
	 * Clone the base record
	 */
	PHALCON_INIT_VAR(object);
	if (phalcon_clone(object, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	/** 
	 * Mark the object as persistent
	 */
	PHALCON_CALL_METHOD(NULL, object, "setdirtystate", dirty_state);
	
	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (Z_TYPE_P(key) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()");
			return;
		}
		phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Call afterFetch, this allows the developer to execute actions after a record is
	 * fetched from the database
	 */
	if (phalcon_method_exists_ex(object, SS("afterfetch") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, object, "afterfetch");
	}
	
	RETURN_CTOR(object);
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
 * $robots = Robots::find("type='mechanical'");
 * echo "There are ", count($robots), "\n";
 *
 * //Get and print virtual robots ordered by name
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
 * //Get first 100 virtual robots ordered by name
 * $robots = Robots::find(array("type='virtual'", "order" => "name", "limit" => 100));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 *
 * @param 	array $parameters
 * @return  Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, find){

	zval *parameters = NULL, *model_name, *params = NULL, *builder;
	zval *query = NULL, *bind_params = NULL, *bind_types = NULL, *cache;
	zval *resultset = NULL, *hydration;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
	
		PHALCON_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			phalcon_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	/** 
	 * Builds a query with the passed parameters
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD(NULL, builder, "__construct", params);
	
	PHALCON_CALL_METHOD(NULL, builder, "from", model_name);
	PHALCON_CALL_METHOD(&query, builder, "getquery");
	
	PHALCON_INIT_VAR(bind_params);
	
	PHALCON_INIT_VAR(bind_types);
	
	/** 
	 * Check for bind parameters
	 */
	if (phalcon_array_isset_string(params, SS("bind"))) {
	
		PHALCON_OBS_NVAR(bind_params);
		phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_NVAR(bind_types);
			phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY);
		}
	}
	
	/** 
	 * Pass the cache options to the query
	 */
	if (phalcon_array_isset_string(params, SS("cache"))) {
		PHALCON_OBS_VAR(cache);
		phalcon_array_fetch_string(&cache, params, SL("cache"), PH_NOISY);
		PHALCON_CALL_METHOD(NULL, query, "cache", cache);
	}
	
	/** 
	 * Execute the query passing the bind-params and casting-types
	 */
	PHALCON_CALL_METHOD(&resultset, query, "execute", bind_params, bind_types);
	
	/** 
	 * Define an hydration mode
	 */
	if (Z_TYPE_P(resultset) == IS_OBJECT) {
		if (phalcon_array_isset_string(params, SS("hydration"))) {
			PHALCON_OBS_VAR(hydration);
			phalcon_array_fetch_string(&hydration, params, SL("hydration"), PH_NOISY);
			PHALCON_CALL_METHOD(NULL, resultset, "sethydratemode", hydration);
		}
	}
	
	RETURN_CTOR(resultset);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in robots table?
 * $robot = Robots::findFirst();
 * echo "The robot name is ", $robot->name;
 *
 * //What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst("type='mechanical'");
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * //Get first virtual robot ordered by name
 * $robot = Robots::findFirst(array("type='virtual'", "order" => "name"));
 * echo "The first virtual robot name is ", $robot->name;
 *
 * </code>
 *
 * @param array $parameters
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst){

	zval *parameters = NULL, *model_name, *params = NULL, *builder;
	zval *query = NULL, *bind_params = NULL, *bind_types = NULL, *cache;
	zval *unique, *index, tmp = zval_used_for_init;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
	
		PHALCON_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			phalcon_array_append(&params, parameters, 0);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	/** 
	 * Builds a query with the passed parameters
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD(NULL, builder, "__construct", params);
	
	PHALCON_CALL_METHOD(NULL, builder, "from", model_name);
	
	/** 
	 * Check for bind parameters
	 */
	PHALCON_OBS_VAR(bind_params);
	PHALCON_OBS_VAR(bind_types);
	if (phalcon_array_isset_string_fetch(&bind_params, params, SS("bind"))) {
		Z_ADDREF_P(bind_params);
		SEPARATE_ZVAL(&bind_params);
		if (Z_TYPE_P(bind_params) != IS_ARRAY) {
			zval_dtor(bind_params);
			array_init_size(bind_params, 1);
		}

		if (phalcon_array_isset_string_fetch(&bind_types, params, SS("bindTypes"))) {
			Z_ADDREF_P(bind_types);
			SEPARATE_ZVAL(&bind_types);
			if (Z_TYPE_P(bind_types) != IS_ARRAY) {
				zval_dtor(bind_types);
				array_init_size(bind_types, 1);
			}
		}
		else {
			MAKE_STD_ZVAL(bind_types);
			array_init_size(bind_types, 1);
		}
	}
	else {
		MAKE_STD_ZVAL(bind_params);
		MAKE_STD_ZVAL(bind_types);
		array_init_size(bind_params, 1);
		array_init_size(bind_types, 1);
	}

	ZVAL_LONG(&tmp, zend_hash_num_elements(Z_ARRVAL_P(bind_params)) + 1);
	PHALCON_INIT_VAR(index);
	PHALCON_CONCAT_SV(index, "?", &tmp);

	/**
	 * We only want the first record
	 */
	PHALCON_CALL_METHOD(NULL, builder, "limit", index);
	PHALCON_CALL_METHOD(&query, builder, "getquery");

	add_index_long(bind_params, Z_LVAL(tmp), 1);
	add_index_long(bind_types, Z_LVAL(tmp), 1 /* BIND_PARAM_INT */);

	/** 
	 * Pass the cache options to the query
	 */
	if (phalcon_array_isset_string_fetch(&cache, params, SS("cache"))) {
		PHALCON_CALL_METHOD(NULL, query, "cache", cache);
	}
	
	unique = PHALCON_GLOBAL(z_true);
	
	/** 
	 * Return only the first row
	 */
	PHALCON_CALL_METHOD(NULL, query, "setuniquerow", unique);
	
	/** 
	 * Execute the query passing the bind-params and casting-types
	 */
	PHALCON_RETURN_CALL_METHOD(query, "execute", bind_params, bind_types);
	RETURN_MM();
}

/**
 * Create a criteria for a specific model
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model, query){

	zval *dependency_injector = NULL, *model_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &dependency_injector);
	
	if (!dependency_injector) {
		PHALCON_INIT_VAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name TSRMLS_CC);
	
	/** 
	 * Use the global dependency injector if there is no one defined
	 */
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
	}
	
	object_init_ex(return_value, phalcon_mvc_model_criteria_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "setdi", dependency_injector);
	PHALCON_CALL_METHOD(NULL, return_value, "setmodelname", model_name);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the current record already exists or not
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists){

	zval *meta_data, *connection, *table = NULL, *unique_params = NULL;
	zval *unique_types = NULL, *unique_key = NULL, *primary_keys = NULL;
	zval *bind_data_types = NULL, *number_primary, *column_map = NULL;
	zval *null_value, *number_empty, *where_pk, *field = NULL;
	zval *attribute_field = NULL, *exception_message = NULL;
	zval *value = NULL, *escaped_field = NULL, *pk_condition = NULL, *type = NULL;
	zval *join_where, *dirty_state, *schema = NULL, *source = NULL;
	zval *escaped_table = NULL, *null_mode, *select, *num = NULL;
	zval *row_count, *v;
	int seen_rawvalues = 0;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &meta_data, &connection, &table);
	
	if (!table) {
		PHALCON_INIT_VAR(table);
	} else {
		PHALCON_SEPARATE_PARAM(table);
	}
	
	PHALCON_INIT_VAR(unique_params);
	
	PHALCON_INIT_VAR(unique_types);
	
	/** 
	 * Builds a unique primary key condition
	 */
	PHALCON_OBS_VAR(unique_key);
	phalcon_read_property_this(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(unique_key) == IS_NULL) {
		PHALCON_CALL_METHOD(&primary_keys, meta_data, "getprimarykeyattributes", this_ptr);
		PHALCON_CALL_METHOD(&bind_data_types, meta_data, "getbindtypes", this_ptr);
	
		PHALCON_INIT_VAR(number_primary);
		phalcon_fast_count(number_primary, primary_keys TSRMLS_CC);
		if (!zend_is_true(number_primary)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * Check if column renaming is globally activated
		 */
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
		} else {
			PHALCON_INIT_VAR(column_map);
		}
	
		PHALCON_INIT_VAR(null_value);
	
		PHALCON_INIT_VAR(number_empty);
		ZVAL_LONG(number_empty, 0);
	
		PHALCON_INIT_VAR(where_pk);
		array_init(where_pk);
	
		array_init(unique_params);
	
		array_init(unique_types);
	
		/** 
		 * We need to create a primary key based on the current data
		 */
		phalcon_is_iterable(primary_keys, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(field);
	
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, field);
			}
	
			/** 
			 * If the primary key attribute is set append it to the conditions
			 */
			if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
				PHALCON_OBS_NVAR(value);
				phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
	
				/** 
				 * We count how many fields are empty, if all fields are empty we don't perform an
				 * 'exist' check
				 */
				if (PHALCON_IS_EMPTY(value)) {
					phalcon_increment(number_empty);
				}
	
				v = value;
			} else {
				v = null_value;
				phalcon_increment(number_empty);
			}
	
			PHALCON_CALL_METHOD(&escaped_field, connection, "escapeidentifier", field);
	
			PHALCON_INIT_NVAR(pk_condition);

			if (Z_TYPE_P(v) == IS_OBJECT && instanceof_function(Z_OBJCE_P(v), phalcon_db_rawvalue_ce TSRMLS_CC)) {
				PHALCON_CONCAT_VSV(pk_condition, escaped_field, " = ", v);
				seen_rawvalues = 1;
			}
			else {
				PHALCON_CONCAT_VS(pk_condition, escaped_field, " = ?");
				phalcon_array_append(&unique_params, v, 0);
				v = NULL;
			}

			if (!phalcon_array_isset(bind_data_types, field)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' isn't a part of the table columns");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			if (v) {
				PHALCON_OBS_NVAR(type);
				phalcon_array_fetch(&type, bind_data_types, field, PH_NOISY);
				phalcon_array_append(&unique_types, type, PH_SEPARATE);
			}

			phalcon_array_append(&where_pk, pk_condition, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * There are no primary key fields defined, assume the record does not exist
		 */
		if (PHALCON_IS_EQUAL(number_primary, number_empty)) {
			RETURN_MM_FALSE;
		}
	
		PHALCON_INIT_VAR(join_where);
		phalcon_fast_join_str(join_where, SL(" AND "), where_pk TSRMLS_CC);
	
		/** 
		 * The unique key is composed of 3 parts _uniqueKey, uniqueParams, uniqueTypes
		 */
		phalcon_update_property_this(this_ptr, SL("_uniqueKey"), join_where TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_uniqueParams"), unique_params TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_uniqueTypes"), unique_types TSRMLS_CC);
		PHALCON_CPY_WRT(unique_key, join_where);
	}
	
	/** 
	 * If we already know if the record exists we don't check it
	 */
	PHALCON_OBS_VAR(dirty_state);
	phalcon_read_property_this(&dirty_state, this_ptr, SL("_dirtyState"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(dirty_state)) {
		RETURN_MM_TRUE;
	}
	
	if (Z_TYPE_P(unique_key) == IS_NULL) {
		PHALCON_OBS_NVAR(unique_key);
		phalcon_read_property_this(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY TSRMLS_CC);
	}
	
	if (Z_TYPE_P(unique_params) == IS_NULL) {
		PHALCON_OBS_NVAR(unique_params);
		phalcon_read_property_this(&unique_params, this_ptr, SL("_uniqueParams"), PH_NOISY TSRMLS_CC);
	}
	
	if (Z_TYPE_P(unique_types) == IS_NULL) {
		PHALCON_OBS_NVAR(unique_types);
		phalcon_read_property_this(&unique_types, this_ptr, SL("_uniqueTypes"), PH_NOISY TSRMLS_CC);
	}
	
	PHALCON_CALL_METHOD(&schema, this_ptr, "getschema");
	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	if (zend_is_true(schema)) {
		PHALCON_INIT_NVAR(table);
		array_init_size(table, 2);
		phalcon_array_append(&table, schema, PH_SEPARATE);
		phalcon_array_append(&table, source, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	PHALCON_CALL_METHOD(&escaped_table, connection, "escapeidentifier", table);
	
	PHALCON_INIT_VAR(null_mode);
	
	/** 
	 * Here we use a single COUNT(*) without PHQL to make the execution faster
	 */
	PHALCON_INIT_VAR(select);
	PHALCON_CONCAT_SVSV(select, "SELECT COUNT(*) \"rowcount\" FROM ", escaped_table, " WHERE ", unique_key);
	
	PHALCON_CALL_METHOD(&num, connection, "fetchone", select, null_mode, unique_params, unique_types);
	
	if (seen_rawvalues) {
		phalcon_update_property_this(this_ptr, SL("_uniqueKey"), PHALCON_GLOBAL(z_null) TSRMLS_CC);
	}

	PHALCON_OBS_VAR(row_count);
	phalcon_array_fetch_string(&row_count, num, SL("rowcount"), PH_NOISY);
	if (zend_is_true(row_count)) {
		phalcon_update_property_long(this_ptr, SL("_dirtyState"), 0 TSRMLS_CC);
		RETURN_MM_TRUE;
	} else {
		phalcon_update_property_long(this_ptr, SL("_dirtyState"), 1 TSRMLS_CC);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param string $function
 * @param string $alias
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult){

	zval *function, *alias, *parameters, *params = NULL, *group_column = NULL;
	zval *distinct_column, *columns = NULL, *group_columns;
	zval *model_name, *builder, *query = NULL, *bind_params = NULL;
	zval *bind_types = NULL, *resultset = NULL, *cache, *number_rows;
	zval *first_row = NULL, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &function, &alias, &parameters);
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			array_init_size(params, 1);
			phalcon_array_append(&params, parameters, 0);
		} else {
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (phalcon_array_isset_string(params, SS("column"))) {
		PHALCON_OBS_VAR(group_column);
		phalcon_array_fetch_string(&group_column, params, SL("column"), PH_NOISY);
	} else {
		PHALCON_INIT_NVAR(group_column);
		ZVAL_STRING(group_column, "*", 1);
	}
	
	/** 
	 * Builds the columns to query according to the received parameters
	 */
	if (phalcon_array_isset_string(params, SS("distinct"))) {
		PHALCON_OBS_VAR(distinct_column);
		phalcon_array_fetch_string(&distinct_column, params, SL("distinct"), PH_NOISY);
	
		PHALCON_INIT_VAR(columns);
		PHALCON_CONCAT_VSVSV(columns, function, "(DISTINCT ", distinct_column, ") AS ", alias);
	} else {
		if (phalcon_array_isset_string(params, SS("group"))) {
			PHALCON_OBS_VAR(group_columns);
			phalcon_array_fetch_string(&group_columns, params, SL("group"), PH_NOISY);
	
			PHALCON_INIT_NVAR(columns);
			PHALCON_CONCAT_VSVSVSV(columns, group_columns, ", ", function, "(", group_column, ") AS ", alias);
		} else {
			PHALCON_INIT_NVAR(columns);
			PHALCON_CONCAT_VSVSV(columns, function, "(", group_column, ") AS ", alias);
		}
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	
	/** 
	 * Builds a query with the passed parameters
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD(NULL, builder, "__construct", params);
	
	PHALCON_CALL_METHOD(NULL, builder, "columns", columns);
	PHALCON_CALL_METHOD(NULL, builder, "from", model_name);
	PHALCON_CALL_METHOD(&query, builder, "getquery");
	
	/** 
	 * Check for bind parameters
	 */
	PHALCON_INIT_VAR(bind_params);
	
	PHALCON_INIT_VAR(bind_types);
	if (phalcon_array_isset_string(params, SS("bind"))) {
	
		PHALCON_OBS_NVAR(bind_params);
		phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_NVAR(bind_types);
			phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY);
		}
	}
	
	/** 
	 * Execute the query
	 */
	PHALCON_CALL_METHOD(&resultset, query, "execute", bind_params, bind_types);
	
	/** 
	 * Pass the cache options to the query
	 */
	if (phalcon_array_isset_string(params, SS("cache"))) {
		PHALCON_OBS_VAR(cache);
		phalcon_array_fetch_string(&cache, params, SL("cache"), PH_NOISY);
		PHALCON_CALL_METHOD(NULL, query, "cache", cache);
	}
	
	/** 
	 * Return the full resultset if the query is grouped
	 */
	if (phalcon_array_isset_string(params, SS("group"))) {
		RETURN_CTOR(resultset);
	}
	
	/** 
	 * Return only the value in the first result
	 */
	PHALCON_INIT_VAR(number_rows);
	phalcon_fast_count(number_rows, resultset TSRMLS_CC);
	PHALCON_CALL_METHOD(&first_row, resultset, "getfirst");
	
	PHALCON_OBS_VAR(value);
	phalcon_read_property_zval(&value, first_row, alias, PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(value);
}

/**
 * Allows to count how many records match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $number = Robots::count();
 * echo "There are ", $number, "\n";
 *
 * //How many mechanical robots are there?
 * $number = Robots::count("type='mechanical'");
 * echo "There are ", $number, " mechanical robots\n";
 *
 * </code>
 *
 * @param array $parameters
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, count){

	zval *parameters = NULL, *function, *alias;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "COUNT", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "rowcount", 1);
	PHALCON_RETURN_CALL_SELF("_groupresult", function, alias, parameters);
	RETURN_MM();
}

/**
 * Allows to calculate a summatory on a column that match the specified conditions
 *
 * <code>
 *
 * //How much are all robots?
 * $sum = Robots::sum(array('column' => 'price'));
 * echo "The total price of robots is ", $sum, "\n";
 *
 * //How much are mechanical robots?
 * $sum = Robots::sum(array("type='mechanical'", 'column' => 'price'));
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 *
 * </code>
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, sum){

	zval *parameters = NULL, *function, *alias;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "SUM", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "sumatory", 1);
	PHALCON_RETURN_CALL_SELF("_groupresult", function, alias, parameters);
	RETURN_MM();
}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the maximum robot id?
 * $id = Robots::maximum(array('column' => 'id'));
 * echo "The maximum robot id is: ", $id, "\n";
 *
 * //What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(array("type='mechanical'", 'column' => 'id'));
 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
 *
 * </code>
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum){

	zval *parameters = NULL, *function, *alias;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "MAX", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "maximum", 1);
	PHALCON_RETURN_CALL_SELF("_groupresult", function, alias, parameters);
	RETURN_MM();
}

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the minimum robot id?
 * $id = Robots::minimum(array('column' => 'id'));
 * echo "The minimum robot id is: ", $id;
 *
 * //What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(array("type='mechanical'", 'column' => 'id'));
 * echo "The minimum robot id of mechanical robots is ", $id;
 *
 * </code>
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum){

	zval *parameters = NULL, *function, *alias;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "MIN", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "minimum", 1);
	PHALCON_RETURN_CALL_SELF("_groupresult", function, alias, parameters);
	RETURN_MM();
}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * <code>
 *
 * //What's the average price of robots?
 * $average = Robots::average(array('column' => 'price'));
 * echo "The average price is ", $average, "\n";
 *
 * //What's the average price of mechanical robots?
 * $average = Robots::average(array("type='mechanical'", 'column' => 'price'));
 * echo "The average price of mechanical robots is ", $average, "\n";
 *
 * </code>
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average){

	zval *parameters = NULL, *function, *alias;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "AVG", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "average", 1);
	PHALCON_RETURN_CALL_SELF("_groupresult", function, alias, parameters);
	RETURN_MM();
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent){

	zval **event_name, *models_manager;
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
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_RETURN_CALL_METHOD(models_manager, "notifyevent", *event_name, this_ptr);
	RETURN_MM();
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel){

	zval **event_name, *status = NULL, *models_manager;
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
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_CALL_METHOD(&status, models_manager, "notifyevent", *event_name, this_ptr);
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
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation){

	zval *operation_made, *event_name = NULL;

	PHALCON_MM_GROW();

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
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends Phalcon\Mvc\Model
 * {
 *
 *   public function beforeSave()
 *   {
 *     if ($this->name == 'Peter') {
 *        $message = new Message("Sorry, but a robot cannot be named Peter");
 *        $this->appendMessage($message);
 *     }
 *   }
 * }
 * </code>
 *
 * @param Phalcon\Mvc\Model\MessageInterface $message
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage){

	zval *message, *type, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, zend_zval_type_name(message), 1);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid message format '", type, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
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
 * @param Phalcon\Mvc\Model\ValidatorInterface $validator
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, validate){

	zval *validator, *status = NULL, *messages = NULL, *errors, *new_errors;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &validator);
	
	/** 
	 * Valid validators are objects
	 */
	PHALCON_VERIFY_INTERFACE_EX(validator, phalcon_mvc_model_validatorinterface_ce, phalcon_mvc_model_exception_ce, 1);
	
	/** 
	 * Call the validation, if it returns false we append the messages to the current
	 * object
	 */
	PHALCON_CALL_METHOD(&status, validator, "validate", this_ptr);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_CALL_METHOD(&messages, validator, "getmessages");

		if (Z_TYPE_P(messages) == IS_ARRAY) {
			PHALCON_INIT_VAR(new_errors);
			errors = phalcon_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(errors) == IS_ARRAY) {
				phalcon_fast_array_merge(new_errors, &errors, &messages TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_errorMessages"), new_errors TSRMLS_CC);
			} else {
				phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
			}
		}
		else {
			int dup;
#if PHP_VERSION_ID >= 50400
			const
#endif
			char *name = "";
			zend_uint name_len = 0;

			dup = zend_get_object_classname(validator, &name, &name_len TSRMLS_CC);
			zend_throw_exception_ex(spl_ce_LogicException, 0 TSRMLS_CC, "Validator '%s' returned false but did not call appendMessage()", name);
			if (!dup) {
				efree((char*)name);
			}
		}
	}
	
	RETURN_THIS();
}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
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
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed){

	zval *error_messages;

	error_messages = phalcon_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(error_messages) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(error_messages))) {
		RETURN_TRUE;
	}
	
	RETURN_FALSE;
}

/**
 * Returns all the validation messages
 *
 *<code>
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	if ($robot->save() == false) {
 *  	echo "Umh, We can't store robots right now ";
 *  	foreach ($robot->getMessages() as $message) {
 *			echo $message;
 *		}
 *	} else {
 *  	echo "Great, a new robot was saved successfully!";
 *	}
 * </code>
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages){

	zval *filter = NULL, *messages;

	phalcon_fetch_params(0, 0, 1, &filter);
	if (!filter || Z_TYPE_P(filter) != IS_STRING) {
		RETURN_MEMBER(this_ptr, "_errorMessages");
	}

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_errorMessages"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		HashPosition pos;
		zval **value, *field = NULL;

		array_init(return_value);

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(messages), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(messages), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(messages), &pos)
		) {
			PHALCON_CALL_METHOD(&field, *value, "getfield");

			if (PHALCON_IS_EQUAL(filter, field)) {
				phalcon_array_append(&return_value, *value, PH_COPY);
			}
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict){

	zval *manager, *belongs_to = NULL, *error = NULL, *relation = NULL, *foreign_key = NULL;
	zval *action = NULL, *relation_class = NULL, *referenced_model = NULL;
	zval *conditions = NULL, *bind_params = NULL, *fields = NULL, *referenced_fields = NULL;
	zval *field = NULL, *position = NULL, *value = NULL, *referenced_field = NULL;
	zval *condition = NULL, *extra_conditions = NULL, *join_conditions = NULL;
	zval *parameters = NULL, *rowcount = NULL, *user_message = NULL, *joined_fields = NULL;
	zval *type = NULL, *message = NULL, *event_name;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	/** 
	 * Get the models manager
	 */
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We check if some of the belongsTo relations act as virtual foreign key
	 */
	PHALCON_CALL_METHOD(&belongs_to, manager, "getbelongsto", this_ptr);
	if (phalcon_fast_count_ev(belongs_to TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
	
		phalcon_is_iterable(belongs_to, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(relation);
	
			PHALCON_CALL_METHOD(&foreign_key, relation, "getforeignkey");
			if (PHALCON_IS_NOT_FALSE(foreign_key)) {
	
				/** 
				 * By default action is restrict
				 */
				PHALCON_INIT_NVAR(action);
				ZVAL_LONG(action, 1);
	
				/** 
				 * Try to find a different action in the foreign key's options
				 */
				if (Z_TYPE_P(foreign_key) == IS_ARRAY) { 
					if (phalcon_array_isset_string(foreign_key, SS("action"))) {
						PHALCON_OBS_NVAR(action);
						phalcon_array_fetch_string(&action, foreign_key, SL("action"), PH_NOISY);
					}
				}
	
				/** 
				 * Check only if the operation is restrict
				 */
				if (PHALCON_IS_LONG(action, 1)) {
					PHALCON_CALL_METHOD(&relation_class, relation, "getreferencedmodel");
	
					/** 
					 * Load the referenced model if needed
					 */
					PHALCON_CALL_METHOD(&referenced_model, manager, "load", relation_class);
	
					/** 
					 * Since relations can have multiple columns or a single one, we need to build a
					 * condition for each of these cases
					 */
					PHALCON_INIT_NVAR(conditions);
					array_init(conditions);
	
					PHALCON_INIT_NVAR(bind_params);
					array_init(bind_params);
	
					PHALCON_CALL_METHOD(&fields, relation, "getfields");
					PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
	
						/** 
						 * Create a compound condition
						 */
						phalcon_is_iterable(fields, &ah1, &hp1, 0, 0);
	
						while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
							PHALCON_GET_HKEY(position, ah1, hp1);
							PHALCON_GET_HVALUE(field);
	
							if (phalcon_isset_property_zval(this_ptr, field TSRMLS_CC)) {
								PHALCON_OBS_NVAR(value);
								phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY TSRMLS_CC);
							} else {
								PHALCON_INIT_NVAR(value);
							}
	
							PHALCON_OBS_NVAR(referenced_field);
							phalcon_array_fetch(&referenced_field, referenced_fields, position, PH_NOISY);
	
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_SVSV(condition, "[", referenced_field, "] = ?", position);
							phalcon_array_append(&conditions, condition, PH_SEPARATE);
							phalcon_array_append(&bind_params, value, PH_SEPARATE);
	
							zend_hash_move_forward_ex(ah1, &hp1);
						}
	
					} else {
						/** 
						 * Create a simple condition
						 */
						if (phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC)) {
							PHALCON_OBS_NVAR(value);
							phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY TSRMLS_CC);
						} else {
							PHALCON_INIT_NVAR(value);
						}
	
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_SVS(condition, "[", referenced_fields, "] = ?0");
						phalcon_array_append(&conditions, condition, PH_SEPARATE);
						phalcon_array_append(&bind_params, value, PH_SEPARATE);
					}
	
					/** 
					 * Check if the virtual foreign key has extra conditions
					 */
					if (phalcon_array_isset_string(foreign_key, SS("conditions"))) {
						PHALCON_OBS_NVAR(extra_conditions);
						phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY);
						phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE);
					}
	
					/** 
					 * We don't trust the actual values in the object and pass the values using bound
					 * parameters
					 */
					PHALCON_INIT_NVAR(join_conditions);
					phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
					PHALCON_INIT_NVAR(parameters);
					array_init_size(parameters, 2);
					phalcon_array_append(&parameters, join_conditions, 0);
					phalcon_array_update_string(&parameters, SL("bind"), bind_params, PH_COPY);
	
					/** 
					 * Let's make the checking
					 */
					PHALCON_CALL_METHOD(&rowcount, referenced_model, "count", parameters);
					if (!zend_is_true(rowcount)) {
	
						/** 
						 * Get the user message or produce a new one
						 */
						if (phalcon_array_isset_string(foreign_key, SS("message"))) {
							PHALCON_OBS_NVAR(user_message);
							phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY);
						} else {
							if (Z_TYPE_P(fields) == IS_ARRAY) { 
								PHALCON_INIT_NVAR(joined_fields);
								phalcon_fast_join_str(joined_fields, SL(", "), fields TSRMLS_CC);
	
								PHALCON_INIT_NVAR(user_message);
								PHALCON_CONCAT_SVS(user_message, "Value of fields \"", joined_fields, "\" does not exist on referenced table");
							} else {
								PHALCON_INIT_NVAR(user_message);
								PHALCON_CONCAT_SVS(user_message, "Value of field \"", fields, "\" does not exist on referenced table");
							}
						}
	
						/** 
						 * Create a message
						 */
						PHALCON_INIT_NVAR(type);
						ZVAL_STRING(type, "ConstraintViolation", 1);
	
						PHALCON_INIT_NVAR(message);
						object_init_ex(message, phalcon_mvc_model_message_ce);
						PHALCON_CALL_METHOD(NULL, message, "__construct", user_message, fields, type);
	
						PHALCON_CALL_METHOD(NULL, this_ptr, "appendmessage", message);
	
						PHALCON_INIT_NVAR(error);
						ZVAL_BOOL(error, 1);
						break;
					}
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * Call 'onValidationFails' if the validation fails
		 */
		if (PHALCON_IS_TRUE(error)) {
			if (PHALCON_GLOBAL(orm).events) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "onValidationFails", 1);
				PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
				PHALCON_CALL_METHOD(NULL, this_ptr, "_canceloperation");
			}
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict){

	zval *manager, *relations = NULL, *error = NULL, *relation = NULL, *foreign_key = NULL;
	zval *action = NULL, *relation_class = NULL, *referenced_model = NULL;
	zval *fields = NULL, *referenced_fields = NULL, *conditions = NULL;
	zval *bind_params = NULL, *field = NULL, *position = NULL, *value = NULL, *referenced_field = NULL;
	zval *condition = NULL, *extra_conditions = NULL, *join_conditions = NULL;
	zval *parameters = NULL, *rowcount = NULL, *user_message = NULL, *type = NULL;
	zval *message = NULL, *event_name;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	/** 
	 * Get the models manager
	 */
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We check if some of the hasOne/hasMany relations is a foreign key
	 */
	PHALCON_CALL_METHOD(&relations, manager, "gethasoneandhasmany", this_ptr);
	if (phalcon_fast_count_ev(relations TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
	
		phalcon_is_iterable(relations, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(relation);
	
			/** 
			 * Check if the relation has a virtual foreign key
			 */
			PHALCON_CALL_METHOD(&foreign_key, relation, "getforeignkey");
			if (PHALCON_IS_NOT_FALSE(foreign_key)) {
	
				/** 
				 * By default action is restrict
				 */
				PHALCON_INIT_NVAR(action);
				ZVAL_LONG(action, 1);
	
				/** 
				 * Try to find a different action in the foreign key's options
				 */
				if (Z_TYPE_P(foreign_key) == IS_ARRAY) { 
					if (phalcon_array_isset_string(foreign_key, SS("action"))) {
						PHALCON_OBS_NVAR(action);
						phalcon_array_fetch_string(&action, foreign_key, SL("action"), PH_NOISY);
					}
				}
	
				/** 
				 * Check only if the operation is restrict
				 */
				if (PHALCON_IS_LONG(action, 1)) {
	
					PHALCON_CALL_METHOD(&relation_class, relation, "getreferencedmodel");
	
					/** 
					 * Load a plain instance from the models manager
					 */
					PHALCON_CALL_METHOD(&referenced_model, manager, "load", relation_class);
					PHALCON_CALL_METHOD(&fields, relation, "getfields");
					PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
	
					/** 
					 * Create the checking conditions. A relation can has many fields or a single one
					 */
					PHALCON_INIT_NVAR(conditions);
					array_init(conditions);
	
					PHALCON_INIT_NVAR(bind_params);
					array_init(bind_params);
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
	
						phalcon_is_iterable(fields, &ah1, &hp1, 0, 0);
	
						while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
							PHALCON_GET_HKEY(position, ah1, hp1);
							PHALCON_GET_HVALUE(field);
	
							if (phalcon_isset_property_zval(this_ptr, field TSRMLS_CC)) {
								PHALCON_OBS_NVAR(value);
								phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY TSRMLS_CC);
							} else {
								PHALCON_INIT_NVAR(value);
							}
	
							PHALCON_OBS_NVAR(referenced_field);
							phalcon_array_fetch(&referenced_field, referenced_fields, position, PH_NOISY);
	
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_SVSV(condition, "[", referenced_field, "] = ?", position);
							phalcon_array_append(&conditions, condition, PH_SEPARATE);
							phalcon_array_append(&bind_params, value, PH_SEPARATE);
	
							zend_hash_move_forward_ex(ah1, &hp1);
						}
	
					} else {
						if (phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC)) {
							PHALCON_OBS_NVAR(value);
							phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY TSRMLS_CC);
						} else {
							PHALCON_INIT_NVAR(value);
						}
	
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_SVS(condition, "[", referenced_fields, "] = ?0");
						phalcon_array_append(&conditions, condition, PH_SEPARATE);
						phalcon_array_append(&bind_params, value, PH_SEPARATE);
					}
	
					/** 
					 * Check if the virtual foreign key has extra conditions
					 */
					if (phalcon_array_isset_string(foreign_key, SS("conditions"))) {
						PHALCON_OBS_NVAR(extra_conditions);
						phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY);
						phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE);
					}
	
					/** 
					 * We don't trust the actual values in the object and then we're passing the values
					 * using bound parameters
					 */
					PHALCON_INIT_NVAR(join_conditions);
					phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
					PHALCON_INIT_NVAR(parameters);
					array_init_size(parameters, 2);
					phalcon_array_append(&parameters, join_conditions, 0);
					phalcon_array_update_string(&parameters, SL("bind"), bind_params, PH_COPY);
	
					/** 
					 * Let's make the checking
					 */
					PHALCON_CALL_METHOD(&rowcount, referenced_model, "count", parameters);
					if (zend_is_true(rowcount)) {
	
						/** 
						 * Create a new message
						 */
						if (phalcon_array_isset_string(foreign_key, SS("message"))) {
							PHALCON_OBS_NVAR(user_message);
							phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY);
						} else {
							PHALCON_INIT_NVAR(user_message);
							PHALCON_CONCAT_SV(user_message, "Record is referenced by model ", relation_class);
						}
	
						/** 
						 * Create a message
						 */
						PHALCON_INIT_NVAR(type);
						ZVAL_STRING(type, "ConstraintViolation", 1);
	
						PHALCON_INIT_NVAR(message);
						object_init_ex(message, phalcon_mvc_model_message_ce);
						PHALCON_CALL_METHOD(NULL, message, "__construct", user_message, fields, type);
	
						PHALCON_CALL_METHOD(NULL, this_ptr, "appendmessage", message);
	
						PHALCON_INIT_NVAR(error);
						ZVAL_BOOL(error, 1);
						break;
					}
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * Call validation fails event
		 */
		if (PHALCON_IS_TRUE(error)) {
			if (PHALCON_GLOBAL(orm).events) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "onValidationFails", 1);
				PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
				PHALCON_CALL_METHOD(NULL, this_ptr, "_canceloperation");
			}
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade){

	zval *manager, *relations = NULL, *relation = NULL, *foreign_key = NULL;
	zval *action = NULL, *relation_class = NULL, *referenced_model = NULL;
	zval *fields = NULL, *referenced_fields = NULL, *conditions = NULL;
	zval *bind_params = NULL, *field = NULL, *position = NULL, *value = NULL, *referenced_field = NULL;
	zval *condition = NULL, *extra_conditions = NULL, *join_conditions = NULL;
	zval *parameters = NULL, *resulset = NULL, *status = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	/** 
	 * Get the models manager
	 */
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We check if some of the hasOne/hasMany relations is a foreign key
	 */
	PHALCON_CALL_METHOD(&relations, manager, "gethasoneandhasmany", this_ptr);
	if (phalcon_fast_count_ev(relations TSRMLS_CC)) {
	
		phalcon_is_iterable(relations, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(relation);
	
			/** 
			 * Check if the relation has a virtual foreign key
			 */
			PHALCON_CALL_METHOD(&foreign_key, relation, "getforeignkey");
			if (PHALCON_IS_NOT_FALSE(foreign_key)) {
	
				/** 
				 * By default action is restrict
				 */
				PHALCON_INIT_NVAR(action);
				ZVAL_LONG(action, 0);
	
				/** 
				 * Try to find a different action in the foreign key's options
				 */
				if (Z_TYPE_P(foreign_key) == IS_ARRAY) { 
					if (phalcon_array_isset_string(foreign_key, SS("action"))) {
						PHALCON_OBS_NVAR(action);
						phalcon_array_fetch_string(&action, foreign_key, SL("action"), PH_NOISY);
					}
				}
	
				/** 
				 * Check only if the operation is restrict
				 */
				if (PHALCON_IS_LONG(action, 2)) {
	
					PHALCON_CALL_METHOD(&relation_class, relation, "getreferencedmodel");
	
					/** 
					 * Load a plain instance from the models manager
					 */
					PHALCON_CALL_METHOD(&referenced_model, manager, "load", relation_class);
					PHALCON_CALL_METHOD(&fields, relation, "getfields");
					PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
	
					/** 
					 * Create the checking conditions. A relation can has many fields or a single one
					 */
					PHALCON_INIT_NVAR(conditions);
					array_init(conditions);
	
					PHALCON_INIT_NVAR(bind_params);
					array_init(bind_params);
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
	
						phalcon_is_iterable(fields, &ah1, &hp1, 0, 0);
	
						while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
							PHALCON_GET_HKEY(position, ah1, hp1);
							PHALCON_GET_HVALUE(field);
	
							if (phalcon_isset_property_zval(this_ptr, field TSRMLS_CC)) {
								PHALCON_OBS_NVAR(value);
								phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY TSRMLS_CC);
							} else {
								PHALCON_INIT_NVAR(value);
							}
	
							PHALCON_OBS_NVAR(referenced_field);
							phalcon_array_fetch(&referenced_field, referenced_fields, position, PH_NOISY);
	
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_SVSV(condition, "[", referenced_field, "] = ?", position);
							phalcon_array_append(&conditions, condition, PH_SEPARATE);
							phalcon_array_append(&bind_params, value, PH_SEPARATE);
	
							zend_hash_move_forward_ex(ah1, &hp1);
						}
	
					} else {
						if (phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC)) {
							PHALCON_OBS_NVAR(value);
							phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY TSRMLS_CC);
						} else {
							PHALCON_INIT_NVAR(value);
						}
	
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_SVS(condition, "[", referenced_fields, "] = ?0");
						phalcon_array_append(&conditions, condition, PH_SEPARATE);
						phalcon_array_append(&bind_params, value, PH_SEPARATE);
					}
	
					/** 
					 * Check if the virtual foreign key has extra conditions
					 */
					if (phalcon_array_isset_string(foreign_key, SS("conditions"))) {
						PHALCON_OBS_NVAR(extra_conditions);
						phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY);
						phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE);
					}
	
					/** 
					 * We don't trust the actual values in the object and then we're passing the values
					 * using bound parameters
					 */
					PHALCON_INIT_NVAR(join_conditions);
					phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
					PHALCON_INIT_NVAR(parameters);
					array_init_size(parameters, 2);
					phalcon_array_append(&parameters, join_conditions, 0);
					phalcon_array_update_string(&parameters, SL("bind"), bind_params, PH_COPY);
	
					/** 
					 * Let's make the checking
					 */
					PHALCON_CALL_METHOD(&resulset, referenced_model, "find", parameters);
	
					/** 
					 * Delete the resultset
					 */
					PHALCON_CALL_METHOD(&status, resulset, "delete");
	
					/** 
					 * Stop the operation
					 */
					if (PHALCON_IS_FALSE(status)) {
						RETURN_MM_FALSE;
					}
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_MM_TRUE;
}

/**
 * Executes internal hooks before save a record
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param boolean $exists
 * @param string $identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave){

	zval *meta_data, *exists, *identity_field, *event_name = NULL;
	zval *status = NULL, *not_null = NULL, *data_type_numeric = NULL;
	zval *column_map = NULL, *automatic_attributes = NULL, *error = NULL;
	zval *null_value, *field = NULL, *is_null = NULL, *attribute_field = NULL;
	zval *exception_message = NULL, *value = NULL, *message = NULL, *type = NULL;
	zval *model_message = NULL, *skipped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &meta_data, &exists, &identity_field);
	
	/** 
	 * Run Validation Callbacks Before
	 */
	if (PHALCON_GLOBAL(orm).events) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeValidation", 1);
	
		/** 
		 * Call the beforeValidation
		 */
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
	
		/** 
		 * Call the specific beforeValidation event for the current action
		 */
		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Check for Virtual foreign keys
	 */
	if (PHALCON_GLOBAL(orm).virtual_foreign_keys) {
		PHALCON_CALL_METHOD(&status, this_ptr, "_checkforeignkeysrestrict");
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Columns marked as not null are automatically validated by the ORM
	 */
	if (PHALCON_GLOBAL(orm).not_null_validations) {
		PHALCON_CALL_METHOD(&not_null, meta_data, "getnotnullattributes", this_ptr);
		if (Z_TYPE_P(not_null) == IS_ARRAY) { 
	
			/** 
			 * Gets the fields that are numeric, these are validated in a diferent way
			 */
			PHALCON_CALL_METHOD(&data_type_numeric, meta_data, "getdatatypesnumeric", this_ptr);
			if (PHALCON_GLOBAL(orm).column_renaming) {
				PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
			} else {
				PHALCON_INIT_VAR(column_map);
			}
	
			/** 
			 * Get fields that must be omitted from the SQL generation
			 */
			if (zend_is_true(exists)) {
				PHALCON_CALL_METHOD(&automatic_attributes, meta_data, "getautomaticupdateattributes", this_ptr);
			} else {
				PHALCON_CALL_METHOD(&automatic_attributes, meta_data, "getautomaticcreateattributes", this_ptr);
			}
	
			PHALCON_INIT_VAR(error);
			ZVAL_BOOL(error, 0);
	
			PHALCON_INIT_VAR(null_value);
	
			phalcon_is_iterable(not_null, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(field);
	
				/** 
				 * We don't check fields that must be omitted
				 */
				if (!phalcon_array_isset(automatic_attributes, field)) {
	
					PHALCON_INIT_NVAR(is_null);
					ZVAL_BOOL(is_null, 0);
					if (Z_TYPE_P(column_map) == IS_ARRAY) { 
						if (phalcon_array_isset(column_map, field)) {
							PHALCON_OBS_NVAR(attribute_field);
							phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY);
						} else {
							PHALCON_INIT_NVAR(exception_message);
							PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' isn't part of the column map");
							PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
							return;
						}
					} else {
						PHALCON_CPY_WRT(attribute_field, field);
					}
	
					/** 
					 * Field is null when: 1) is not set, 2) is numeric but its value is not numeric,
					 * 3) is null or 4) is empty string
					 */
					if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
						/** 
						 * Read the attribute from the this_ptr using the real or renamed name
						 */
						PHALCON_OBS_NVAR(value);
						phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
	
						/** 
						 * Objects are never treated as null, numeric fields must be numeric to be accepted
						 * as not null
						 */
						if (Z_TYPE_P(value) != IS_OBJECT) {
							if (!phalcon_array_isset(data_type_numeric, field)) {
								if (PHALCON_IS_EMPTY(value)) {
									PHALCON_INIT_NVAR(is_null);
									ZVAL_BOOL(is_null, 1);
								}
							} else {
								if (!phalcon_is_numeric(value)) {
									PHALCON_INIT_NVAR(is_null);
									ZVAL_BOOL(is_null, 1);
								}
							}
						}
					} else {
						PHALCON_INIT_NVAR(is_null);
						ZVAL_BOOL(is_null, 1);
					}
	
					if (PHALCON_IS_TRUE(is_null)) {
						if (!zend_is_true(exists)) {
	
							/** 
							 * The identity field can be null
							 */
							if (PHALCON_IS_EQUAL(field, identity_field)) {
								zend_hash_move_forward_ex(ah0, &hp0);
								continue;
							}
						}
	
						PHALCON_INIT_NVAR(message);
						PHALCON_CONCAT_VS(message, attribute_field, " is required");
	
						PHALCON_INIT_NVAR(type);
						ZVAL_STRING(type, "PresenceOf", 1);
	
						/** 
						 * A implicit PresenceOf message is created
						 */
						PHALCON_INIT_NVAR(model_message);
						object_init_ex(model_message, phalcon_mvc_model_message_ce);
						PHALCON_CALL_METHOD(NULL, model_message, "__construct", message, attribute_field, type);
	
						phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), model_message TSRMLS_CC);
	
						PHALCON_INIT_NVAR(error);
						ZVAL_BOOL(error, 1);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			if (PHALCON_IS_TRUE(error)) {
				if (PHALCON_GLOBAL(orm).events) {
					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "onValidationFails", 1);
					PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
					PHALCON_CALL_METHOD(NULL, this_ptr, "_canceloperation");
				}
				RETURN_MM_FALSE;
			}
		}
	}
	
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "validation", 1);
	
	/** 
	 * Call the main validation event
	 */
	PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
	if (PHALCON_IS_FALSE(status)) {
		if (PHALCON_GLOBAL(orm).events) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
		}
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Run Validation
	 */
	if (PHALCON_GLOBAL(orm).events) {
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnUpdate", 1);
		}
	
		/** 
		 * Run Validation Callbacks After
		 */
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
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "beforeSave", 1);
	
		/** 
		 * Run Before Callbacks
		 */
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
	
		phalcon_update_property_bool(this_ptr, SL("_skipped"), 0 TSRMLS_CC);
	
		/** 
		 * The operation can be skipped here
		 */
		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * Always return true if the operation is skipped
		 */
		PHALCON_OBS_VAR(skipped);
		phalcon_read_property_this(&skipped, this_ptr, SL("_skipped"), PH_NOISY TSRMLS_CC);
		if (PHALCON_IS_TRUE(skipped)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Executes internal events after save a record
 *
 * @param boolean $success
 * @param boolean $exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave){

	zval *success, *exists, *event_name = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &success, &exists);
	
	if (PHALCON_IS_TRUE(success)) {
		if (zend_is_true(exists)) {
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
	
		RETURN_CTOR(success);
	}
	
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "notSave", 1);
	PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
	PHALCON_CALL_METHOD(NULL, this_ptr, "_canceloperation");
	RETURN_MM_FALSE;
}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert){

	zval *meta_data, *connection, *table, *identity_field;
	zval *null_value, *bind_skip, *fields, *values;
	zval *bind_types, *attributes = NULL, *bind_data_types = NULL;
	zval *automatic_attributes = NULL, *column_map = NULL, *field = NULL;
	zval *attribute_field = NULL, *exception_message = NULL;
	zval *value = NULL, *bind_type = NULL, *default_value = NULL, *use_explicit_identity = NULL;
	zval *success = NULL, *sequence_name = NULL, *support_sequences = NULL;
	zval *schema = NULL, *source = NULL, *last_insert_id = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int identity_field_is_not_false; /* scan-build insists on using flags */

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &meta_data, &connection, &table, &identity_field);

	null_value = PHALCON_GLOBAL(z_null);
	
	PHALCON_INIT_VAR(bind_skip);
	ZVAL_LONG(bind_skip, 1024);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
	PHALCON_CALL_METHOD(&bind_data_types, meta_data, "getbindtypes", this_ptr);
	PHALCON_CALL_METHOD(&automatic_attributes, meta_data, "getautomaticcreateattributes", this_ptr);

	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
	}
	else {
		PHALCON_INIT_VAR(column_map);
	}
	
	/** 
	 * All fields in the model makes part or the INSERT
	 */
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(field);
	
		if (!phalcon_array_isset(automatic_attributes, field)) {
	
			/** 
			 * Check if the model has a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, field);
			}
	
			/** 
			 * Check every attribute in the model except identity field
			 */
			if (!PHALCON_IS_EQUAL(field, identity_field)) {
				phalcon_array_append(&fields, field, PH_SEPARATE);
	
				/** 
				 * This isset checks that the property be defined in the model
				 */
				if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
					/** 
					 * Every column must have a bind data type defined
					 */
					if (!phalcon_array_isset(bind_data_types, field)) {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' has not defined a bind data type");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
	
					PHALCON_OBS_NVAR(value);
					phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
					phalcon_array_append(&values, value, PH_SEPARATE);
	
					PHALCON_OBS_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY);
					phalcon_array_append(&bind_types, bind_type, PH_SEPARATE);
				} else {
					phalcon_array_append(&values, null_value, PH_SEPARATE);
					phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * If there is an identity field we add it using "null" or "default"
	 */
	identity_field_is_not_false = PHALCON_IS_NOT_FALSE(identity_field);
	if (identity_field_is_not_false) {
		PHALCON_CALL_METHOD(&default_value, connection, "getdefaultidvalue");
	
		/** 
		 * Not all the database systems require an explicit value for identity columns
		 */
		PHALCON_CALL_METHOD(&use_explicit_identity, connection, "useexplicitidvalue");
		if (zend_is_true(use_explicit_identity)) {
			phalcon_array_append(&fields, identity_field, PH_SEPARATE);
		}
	
		/** 
		 * Check if the model has a column map
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, identity_field)) {
				PHALCON_OBS_NVAR(attribute_field);
				phalcon_array_fetch(&attribute_field, column_map, identity_field, PH_NOISY);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Identity column '", identity_field, "' isn't part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(attribute_field, identity_field);
		}
	
		/** 
		 * Check if the developer set an explicit value for the column
		 */
		if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_EMPTY(value)) {
				if (zend_is_true(use_explicit_identity)) {
					phalcon_array_append(&values, default_value, PH_SEPARATE);
					phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE);
				}
			} else {
				/** 
				 * Add the explicit value to the field list if the user has defined a value for it
				 */
				if (!zend_is_true(use_explicit_identity)) {
					phalcon_array_append(&fields, identity_field, PH_SEPARATE);
				}
	
				/** 
				 * The field is valid we look for a bind value (normally int)
				 */
				if (!phalcon_array_isset(bind_data_types, identity_field)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Identity column '", identity_field, "' isn't part of the table columns");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				phalcon_array_append(&values, value, PH_SEPARATE);
	
				PHALCON_OBS_NVAR(bind_type);
				phalcon_array_fetch(&bind_type, bind_data_types, identity_field, PH_NOISY);
				phalcon_array_append(&bind_types, bind_type, PH_SEPARATE);
			}
		} else {
			if (zend_is_true(use_explicit_identity)) {
				phalcon_array_append(&values, default_value, PH_SEPARATE);
				phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE);
			}
		}
	}
	
	/** 
	 * The low level insert is performed
	 */
	PHALCON_CALL_METHOD(&success, connection, "insert", table, values, fields, bind_types);
	if (identity_field_is_not_false) {
	
		/** 
		 * We check if the model have sequences
		 */
		PHALCON_CALL_METHOD(&support_sequences, connection, "supportsequences");
		if (PHALCON_IS_TRUE(support_sequences)) {
			if (phalcon_method_exists_ex(this_ptr, SS("getsequencename") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD(&sequence_name, this_ptr, "getsequencename");
			} else {
				PHALCON_CALL_METHOD(&schema, this_ptr, "getschema"); 
				PHALCON_CALL_METHOD(&source, this_ptr, "getsource");

				PHALCON_INIT_VAR(sequence_name);
				if (PHALCON_IS_EMPTY(schema)) {	
					PHALCON_CONCAT_VSVS(sequence_name, source, "_", identity_field, "_seq");
				} else {
					PHALCON_CONCAT_VSVSVS(sequence_name, schema, ".", source, "_", identity_field, "_seq");
				}
			}
		}
		else {
			PHALCON_INIT_VAR(sequence_name);
		}
	
		/** 
		 * Recover the last "insert id" and assign it to the object
		 */
		PHALCON_CALL_METHOD(&last_insert_id, connection, "lastinsertid", sequence_name);
		phalcon_update_property_zval_zval(this_ptr, attribute_field, last_insert_id TSRMLS_CC);
	
		/** 
		 * Since the primary key was modified, we delete the _uniqueParams to force any
		 * future update to re-build the primary key
		 */
		phalcon_update_property_null(this_ptr, SL("_uniqueParams") TSRMLS_CC);
	}
	
	RETURN_CTOR(success);
}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string|array $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate){

	zval *meta_data, *connection, *table, *null_value;
	zval *bind_skip, *fields, *values, *bind_types;
	zval *manager, *use_dynamic_update = NULL, *snapshot;
	zval *bind_data_types = NULL, *non_primary = NULL, *automatic_attributes = NULL;
	zval *column_map = NULL, *field = NULL, *exception_message = NULL;
	zval *attribute_field = NULL, *value = NULL, *bind_type = NULL, *changed = NULL;
	zval *snapshot_value = NULL, *unique_key, *unique_params = NULL;
	zval *unique_types, *primary_keys = NULL, *conditions;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int i_use_dynamic_update; /* To keep static code analyzer happy */

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &meta_data, &connection, &table);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(bind_skip);
	ZVAL_LONG(bind_skip, 1024);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the model must use dynamic update
	 */
	PHALCON_CALL_METHOD(&use_dynamic_update, manager, "isusingdynamicupdate", this_ptr);
	i_use_dynamic_update = zend_is_true(use_dynamic_update);
	if (i_use_dynamic_update) {
	
		PHALCON_OBS_VAR(snapshot);
		phalcon_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(snapshot) != IS_ARRAY) { 
			i_use_dynamic_update = 0;
		}
	}
	
	PHALCON_CALL_METHOD(&bind_data_types, meta_data, "getbindtypes", this_ptr);
	PHALCON_CALL_METHOD(&non_primary, meta_data, "getnonprimarykeyattributes", this_ptr);
	PHALCON_CALL_METHOD(&automatic_attributes, meta_data, "getautomaticupdateattributes", this_ptr);
	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
	} else {
		PHALCON_INIT_VAR(column_map);
	}
	
	/** 
	 * We only make the update based on the non-primary attributes, values in primary
	 * key attributes are ignored
	 */
	phalcon_is_iterable(non_primary, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(field);
	
		if (!phalcon_array_isset(automatic_attributes, field)) {
	
			/** 
			 * Check a bind type for field to update
			 */
			if (!phalcon_array_isset(bind_data_types, field)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' have not defined a bind data type");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Check if the model has a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, field);
			}
	
			/** 
			 * If a field isn't set we pass a null value
			 */
			if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
				/** 
				 * Get the field's value
				 */
				PHALCON_OBS_NVAR(value);
				phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
	
				/** 
				 * When dynamic update is not used we pass every field to the update
				 */
				if (!i_use_dynamic_update) {
					phalcon_array_append(&fields, field, PH_SEPARATE);
					phalcon_array_append(&values, value, PH_SEPARATE);
	
					PHALCON_OBS_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY);
					phalcon_array_append(&bind_types, bind_type, PH_SEPARATE);
				} else {
					/** 
					 * If the field is not part of the snapshot we add them as changed
					 */
					if (!phalcon_array_isset(snapshot, attribute_field)) {
						PHALCON_INIT_NVAR(changed);
						ZVAL_BOOL(changed, 1);
					} else {
						PHALCON_OBS_NVAR(snapshot_value);
						phalcon_array_fetch(&snapshot_value, snapshot, attribute_field, PH_NOISY);
						if (!PHALCON_IS_EQUAL(value, snapshot_value)) {
							PHALCON_INIT_NVAR(changed);
							ZVAL_BOOL(changed, 1);
						} else {
							PHALCON_INIT_NVAR(changed);
							ZVAL_BOOL(changed, 0);
						}
					}
	
					/** 
					 * Only changed values are added to the SQL Update
					 */
					if (zend_is_true(changed)) {
						phalcon_array_append(&fields, field, PH_SEPARATE);
						phalcon_array_append(&values, value, PH_SEPARATE);
	
						PHALCON_OBS_NVAR(bind_type);
						phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY);
						phalcon_array_append(&bind_types, bind_type, PH_SEPARATE);
					}
				}
			} else {
				phalcon_array_append(&fields, field, PH_SEPARATE);
				phalcon_array_append(&values, null_value, PH_SEPARATE);
				phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * If there is no fields to update we return true
	 */
	if (!phalcon_fast_count_ev(fields TSRMLS_CC)) {
		RETURN_MM_TRUE;
	}
	
	PHALCON_OBS_VAR(unique_key);
	phalcon_read_property_this(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(unique_params);
	phalcon_read_property_this(&unique_params, this_ptr, SL("_uniqueParams"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(unique_types);
	phalcon_read_property_this(&unique_types, this_ptr, SL("_uniqueTypes"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * When unique params is null we need to rebuild the bind params
	 */
	if (Z_TYPE_P(unique_params) != IS_ARRAY) { 
	
		PHALCON_INIT_NVAR(unique_params);
		array_init(unique_params);
	
		PHALCON_CALL_METHOD(&primary_keys, meta_data, "getprimarykeyattributes", this_ptr);
	
		/** 
		 * We can't create dynamic SQL without a primary key
		 */
		if (!phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation");
			return;
		}
	
		phalcon_is_iterable(primary_keys, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(field);
	
			/** 
			 * Check if the model has a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "' isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, field);
			}
			if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
				PHALCON_OBS_NVAR(value);
				phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
				phalcon_array_append(&unique_params, value, PH_SEPARATE);
			} else {
				phalcon_array_append(&unique_params, null_value, PH_SEPARATE);
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	}
	
	/** 
	 * We build the conditions as an array
	 */
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 3);
	phalcon_array_update_string(&conditions, ISL(conditions), unique_key, PH_COPY);
	phalcon_array_update_string(&conditions, SL("bind"), unique_params, PH_COPY);
	phalcon_array_update_string(&conditions, SL("bindTypes"), unique_types, PH_COPY);

	/** 
	 * Perform the low level update
	 */
	PHALCON_RETURN_CALL_METHOD(connection, "update", table, fields, values, conditions, bind_types);
	RETURN_MM();
}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param Phalcon\Db\AdapterInterface $connection
 * @param Phalcon\Mvc\ModelInterface[] $related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords){

	zval *connection, *related, *nesting, *class_name;
	zval *manager = NULL, *record = NULL, *name = NULL, *relation = NULL, *type = NULL, *columns = NULL;
	zval *referenced_model = NULL, *referenced_fields = NULL;
	zval *status = NULL, *referenced_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &connection, &related);
	
	nesting = PHALCON_GLOBAL(z_false);
	
	/** 
	 * Start an implicit transaction
	 */
	PHALCON_CALL_METHOD(NULL, connection, "begin", nesting);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, this_ptr, 0 TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&manager, this_ptr, "getmodelsmanager");
	
	phalcon_is_iterable(related, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(name, ah0, hp0);
		PHALCON_GET_HVALUE(record);
	
		/** 
		 * Try to get a relation with the same name
		 */
		PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", class_name, name);
		if (Z_TYPE_P(relation) == IS_OBJECT) {
	
			/** 
			 * Get the relation type
			 */
			PHALCON_CALL_METHOD(&type, relation, "gettype");
	
			/** 
			 * Only belongsTo are stored before save the master record
			 */
			if (PHALCON_IS_LONG(type, 0)) {
	
				if (Z_TYPE_P(record) != IS_OBJECT) {
					PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations");
					return;
				}
	
				PHALCON_CALL_METHOD(&columns, relation, "getfields");
				PHALCON_CALL_METHOD(&referenced_model, relation, "getreferencedmodel");
				PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
				if (Z_TYPE_P(columns) == IS_ARRAY) { 
					PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not implemented");
					return;
				}
	
				/** 
				 * If dynamic update is enabled, saving the record must not take any action
				 */
				PHALCON_CALL_METHOD(&status, record, "save");
				if (!zend_is_true(status)) {
	
					/** 
					 * Get the validation messages generated by the referenced model
					 */
					if (phalcon_mvc_model_get_messages_from_model(this_ptr, record, record TSRMLS_CC) == FAILURE) {
						RETURN_MM();
					}
	
					/** 
					 * Rollback the implicit transaction
					 */
					PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
					RETURN_MM_FALSE;
				}
	
				/** 
				 * Read the attribute from the referenced model and assigns it to the current model
				 */
				PHALCON_CALL_METHOD(&referenced_value, record, "readattribute", referenced_fields);
	
				/** 
				 * Assign it to the model
				 */
				phalcon_update_property_zval_zval(this_ptr, columns, referenced_value TSRMLS_CC);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM_TRUE;
}

/**
 * Save the related records assigned in the has-one/has-many relations
 *
 * @param Phalcon\Db\AdapterInterface $connection
 * @param Phalcon\Mvc\ModelInterface[] $related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSaveRelatedRecords){

	zval *connection, *related, *nesting, *class_name;
	zval *manager = NULL, *record = NULL, *name = NULL, *relation = NULL, *type = NULL, *columns = NULL;
	zval *referenced_model = NULL, *referenced_fields = NULL;
	zval *related_records = NULL, *exception_message = NULL;
	zval *value = NULL, *is_through = NULL, *new_instance, *intermediate_model_name = NULL;
	zval *intermediate_fields = NULL, *intermediate_referenced_fields = NULL;
	zval *record_after = NULL, *intermediate_model = NULL, *intermediate_value = NULL;
	zval *status = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	phalcon_fetch_params(0, 2, 0, &connection, &related);

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(nesting);
	ZVAL_FALSE(nesting);
	
	PHALCON_INIT_VAR(new_instance);
	ZVAL_TRUE(new_instance);

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, this_ptr, 0 TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&manager, this_ptr, "getmodelsmanager");
	
	phalcon_is_iterable(related, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(name, ah0, hp0);
		PHALCON_GET_HVALUE(record);
	
		/** 
		 * Try to get a relation with the same name
		 */
		PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", class_name, name);
		if (Z_TYPE_P(relation) == IS_OBJECT) {
	
			PHALCON_CALL_METHOD(&type, relation, "gettype");
	
			/** 
			 * Discard belongsTo relations
			 */
			if (PHALCON_IS_LONG(type, 0)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
	
			if (Z_TYPE_P(record) != IS_OBJECT && Z_TYPE_P(record) != IS_ARRAY) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations");
				return;
			}
	
			PHALCON_CALL_METHOD(&columns, relation, "getfields");
			PHALCON_CALL_METHOD(&referenced_model, relation, "getreferencedmodel");
			PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");

			if (Z_TYPE_P(columns) == IS_ARRAY) { 
				PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not implemented");
				return;
			}
	
			/** 
			 * Create an implicit array for has-many/has-one records
			 */
			if (Z_TYPE_P(record) == IS_OBJECT) {
				PHALCON_INIT_NVAR(related_records);
				array_init_size(related_records, 1);
				phalcon_array_append(&related_records, record, 0);
			} else {
				PHALCON_CPY_WRT(related_records, record);
			}
	
			if (!phalcon_isset_property_zval(this_ptr, columns TSRMLS_CC)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "The column '", columns, "' needs to be present in the model");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Get the value of the field from the current model
			 */
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, columns, PH_NOISY TSRMLS_CC);
	
			/** 
			 * Check if the relation is a has-many-to-many
			 */
			PHALCON_CALL_METHOD(&is_through, relation, "isthrough");
	
			/** 
			 * Get the rest of intermediate model info
			 */
			if (zend_is_true(is_through)) {
				PHALCON_CALL_METHOD(&intermediate_model_name, relation, "getintermediatemodel");
				PHALCON_CALL_METHOD(&intermediate_fields, relation, "getintermediatefields");
				PHALCON_CALL_METHOD(&intermediate_referenced_fields, relation, "getintermediatereferencedfields");
			}
	
			phalcon_is_iterable(related_records, &ah1, &hp1, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_HVALUE(record_after);
	
				/** 
				 * For non has-many-to-many relations just assign the local value in the referenced
				 * model
				 */
				if (!zend_is_true(is_through)) {
					/** 
					 * Assign the value to the 
					 */
					PHALCON_CALL_METHOD(NULL, record_after, "writeattribute", referenced_fields, value);
				}

				/**
				 * Save the record and get messages
				 */
				PHALCON_CALL_METHOD(&status, record_after, "save");
				if (!zend_is_true(status)) {

					/**
					 * Get the validation messages generated by the referenced model
					 */
					if (phalcon_mvc_model_get_messages_from_model(this_ptr, record_after, record TSRMLS_CC) == FAILURE) {
						RETURN_MM();
					}

					/**
					 * Rollback the implicit transaction
					 */
					PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
					RETURN_MM_FALSE;
				}

				if (zend_is_true(is_through)) {
					/** 
					 * Create a new instance of the intermediate model
					 */
					PHALCON_CALL_METHOD(&intermediate_model, manager, "load", intermediate_model_name, new_instance);
	
					/** 
					 * Write value in the intermediate model
					 */
					PHALCON_CALL_METHOD(NULL, intermediate_model, "writeattribute", intermediate_fields, value);
	
					/** 
					 * Get the value from the referenced model
					 */
					PHALCON_OBS_NVAR(intermediate_value);
					phalcon_read_property_zval(&intermediate_value, record_after, referenced_fields, PH_NOISY TSRMLS_CC);
	
					/** 
					 * Write the intermediate value in the intermediate model
					 */
					PHALCON_CALL_METHOD(NULL, intermediate_model, "writeattribute", intermediate_referenced_fields, intermediate_value);
	
					/** 
					 * Save the record and get messages
					 */
					PHALCON_CALL_METHOD(&status, intermediate_model, "save");
					if (!zend_is_true(status)) {
	
						/** 
						 * Get the validation messages generated by the referenced model
						 */
						if (phalcon_mvc_model_get_messages_from_model(this_ptr, intermediate_model, record TSRMLS_CC) == FAILURE) {
							RETURN_MM();
						}

						/** 
						 * Rollback the implicit transaction
						 */
						PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
						RETURN_MM_FALSE;
					}
				}
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		} else {
			if (Z_TYPE_P(record) != IS_ARRAY) { 
				PHALCON_CALL_METHOD(NULL, connection, "rollback", nesting);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "There are no defined relations for the model \"", class_name, "\" using alias \"", name, "\"");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Commit the implicit transaction
	 */
	PHALCON_CALL_METHOD(NULL, connection, "commit", nesting);
	RETURN_MM_TRUE;
}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->save();
 *
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->save();
 *</code>
 *
 * @param array $data
 * @param array $whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save){

	zval *data = NULL, *white_list = NULL, *meta_data = NULL, *attributes = NULL;
	zval *attribute = NULL, *value = NULL, *possible_setter = NULL, *write_connection = NULL;
	zval *related, *status = NULL, *schema = NULL, *source = NULL, *table = NULL, *read_connection = NULL;
	zval *exists = NULL, *error_messages = NULL, *identity_field = NULL;
	zval *nesting = NULL, *exception, *success = NULL, *new_success = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &white_list);
	
	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}
	
	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * Assign the values passed
	 */
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data passed to save() must be an array");
			return;
		}
	
		/** 
		 * Get the reversed column map for future renamings
		 */
		PHALCON_CALL_METHOD(&attributes, meta_data, "getcolumnmap", this_ptr);
		if (Z_TYPE_P(attributes) != IS_ARRAY) { 
			/** 
			 * Use the standard column map if there are no renamings
			 */
			PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
		}
	
		phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(attribute);
	
			if (phalcon_array_isset(data, attribute)) {
	
				/** 
				 * If the white-list is an array check if the attribute is on that list
				 */
				if (Z_TYPE_P(white_list) == IS_ARRAY) { 
					if (!phalcon_fast_in_array(attribute, white_list TSRMLS_CC)) {
						zend_hash_move_forward_ex(ah0, &hp0);
						continue;
					}
				}
	
				/** 
				 * We check if the field has a setter
				 */
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch(&value, data, attribute, PH_NOISY);
	
				PHALCON_INIT_NVAR(possible_setter);
				PHALCON_CONCAT_SV(possible_setter, "set", attribute);
				zend_str_tolower(Z_STRVAL_P(possible_setter), Z_STRLEN_P(possible_setter));
				if (phalcon_method_exists_ex(this_ptr, Z_STRVAL_P(possible_setter), Z_STRLEN_P(possible_setter)+1 TSRMLS_CC) == SUCCESS) {
					PHALCON_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(possible_setter), value);
				} else {
					/** 
					 * Otherwise we assign the attribute directly
					 */
					phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Create/Get the current database connection
	 */
	PHALCON_CALL_METHOD(&write_connection, this_ptr, "getwriteconnection");
	
	/** 
	 * Save related records in belongsTo relationships
	 */
	PHALCON_OBS_VAR(related);
	phalcon_read_property_this(&related, this_ptr, SL("_related"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(related) == IS_ARRAY) { 
	
		PHALCON_CALL_METHOD(&status, this_ptr, "_presaverelatedrecords", write_connection, related);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_CALL_METHOD(&schema, this_ptr, "getschema");
	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		array_init_size(table, 2);
		phalcon_array_append(&table, schema, 0);
		phalcon_array_append(&table, source, 0);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	/** 
	 * Create/Get the current database connection
	 */
	PHALCON_CALL_METHOD(&read_connection, this_ptr, "getreadconnection");
	
	/** 
	 * We need to check if the record exists
	 */
	PHALCON_CALL_METHOD(&exists, this_ptr, "_exists", meta_data, read_connection, table);
	if (zend_is_true(exists)) {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 2 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 1 TSRMLS_CC);
	}
	
	/** 
	 * Clean the messages
	 */
	PHALCON_INIT_VAR(error_messages);
	array_init(error_messages);
	phalcon_update_property_this(this_ptr, SL("_errorMessages"), error_messages TSRMLS_CC);
	
	/** 
	 * Query the identity field
	 */
	PHALCON_CALL_METHOD(&identity_field, meta_data, "getidentityfield", this_ptr);
	
	/** 
	 * _preSave() makes all the validations
	 */
	PHALCON_CALL_METHOD(&status, this_ptr, "_presave", meta_data, exists, identity_field);
	if (PHALCON_IS_FALSE(status)) {
	
		/** 
		 * Rollback the current transaction if there was validation errors
		 */
		if (Z_TYPE_P(related) == IS_ARRAY) { 
			PHALCON_INIT_VAR(nesting);
			ZVAL_BOOL(nesting, 0);
			PHALCON_CALL_METHOD(NULL, write_connection, "rollback", nesting);
		}
	
		/** 
		 * Throw exceptions on failed saves?
		 */
		if (PHALCON_GLOBAL(orm).exception_on_failed_save) {
			PHALCON_OBS_NVAR(error_messages);
			phalcon_read_property_this(&error_messages, this_ptr, SL("_errorMessages"), PH_NOISY TSRMLS_CC);
	
			/** 
			 * Launch a Phalcon\Mvc\Model\ValidationFailed to notify that the save failed
			 */
			PHALCON_INIT_VAR(exception);
			object_init_ex(exception, phalcon_mvc_model_validationfailed_ce);
			PHALCON_CALL_METHOD(NULL, exception, "__construct", this_ptr, error_messages);
	
			phalcon_throw_exception(exception TSRMLS_CC);
			RETURN_MM();
		}
	
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Depending if the record exists we do an update or an insert operation
	 */
	if (zend_is_true(exists)) {
		PHALCON_CALL_METHOD(&success, this_ptr, "_dolowupdate", meta_data, write_connection, table);
	} else {
		PHALCON_CALL_METHOD(&success, this_ptr, "_dolowinsert", meta_data, write_connection, table, identity_field);
	}
	
	/** 
	 * Change the dirty state to persistent
	 */
	if (zend_is_true(success)) {
		phalcon_update_property_long(this_ptr, SL("_dirtyState"), 0 TSRMLS_CC);
	}
	
	/** 
	 * _postSave() makes all the validations
	 */
	if (PHALCON_GLOBAL(orm).events) {
		PHALCON_CALL_METHOD(&new_success, this_ptr, "_postsave", success, exists);
	} else {
		PHALCON_CPY_WRT(new_success, success);
	}
	
	if (Z_TYPE_P(related) == IS_ARRAY) { 
	
		/** 
		 * Rollbacks the implicit transaction if the master save has failed
		 */
		if (PHALCON_IS_FALSE(new_success)) {
			PHALCON_INIT_NVAR(nesting);
			ZVAL_BOOL(nesting, 0);
			PHALCON_CALL_METHOD(NULL, write_connection, "rollback", nesting);
			RETURN_MM_FALSE;
		}
	
		/** 
		 * Save the post-related records
		 */
		PHALCON_CALL_METHOD(&status, this_ptr, "_postsaverelatedrecords", write_connection, related);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_CTOR(new_success);
}

/**
 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->create();
 *
 *  //Passing an array to create
 *  $robot = new Robots();
 *  $robot->create(array(
 *      'type' => 'mechanical',
 *      'name' => 'Astroy Boy',
 *      'year' => 1952
 *  ));
 *</code>
 *
 * @param array $data
 * @param array $whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, create){

	zval *data = NULL, *white_list = NULL, *meta_data = NULL, *column_map = NULL;
	zval *attributes = NULL, *attribute = NULL, *attribute_field = NULL;
	zval *exception_message = NULL, *value = NULL, *possible_setter = NULL;
	zval *read_connection = NULL, *exists = NULL, *field, *type, *message;
	zval *model_message, *messages;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &white_list);
	
	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}
	
	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * Assign the values passed
	 */
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data passed to create() must be an array");
			return;
		}
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
		} else {
			PHALCON_INIT_VAR(column_map);
		}
	
		/** 
		 * We assign the fields starting from the current attributes in the model
		 */
		PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
	
		phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(attribute);
	
			/** 
			 * Check if we need to rename the field
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, attribute)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, attribute, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", attribute, "' isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, attribute);
			}
	
			/** 
			 * Check if we there is data for the field
			 */
			if (phalcon_array_isset(data, attribute_field)) {
	
				/** 
				 * If the white-list is an array check if the attribute is on that list
				 */
				if (Z_TYPE_P(white_list) == IS_ARRAY) { 
					if (!phalcon_fast_in_array(attribute_field, white_list TSRMLS_CC)) {
						zend_hash_move_forward_ex(ah0, &hp0);
						continue;
					}
				}
	
				/** 
				 * The value in the array passed
				 */
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch(&value, data, attribute_field, PH_NOISY);
	
				/** 
				 * Check if the field has a posible setter
				 */
				PHALCON_INIT_NVAR(possible_setter);
				PHALCON_CONCAT_SV(possible_setter, "set", attribute_field);
				zend_str_tolower(Z_STRVAL_P(possible_setter), Z_STRLEN_P(possible_setter));
				if (phalcon_method_exists_ex(this_ptr, Z_STRVAL_P(possible_setter), Z_STRLEN_P(possible_setter)+1 TSRMLS_CC) == SUCCESS) {
					PHALCON_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(possible_setter), value);
				} else {
					phalcon_update_property_zval_zval(this_ptr, attribute_field, value TSRMLS_CC);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Get the current connection
	 */
	PHALCON_CALL_METHOD(&read_connection, this_ptr, "getreadconnection");
	
	/** 
	 * A 'exists' confirmation is performed first
	 */
	PHALCON_CALL_METHOD(&exists, this_ptr, "_exists", meta_data, read_connection);
	
	/** 
	 * If the record already exists we must throw an exception
	 */
	if (zend_is_true(exists)) {
		PHALCON_INIT_VAR(field);
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "InvalidCreateAttempt", 1);
	
		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "Record cannot be created because it already exists", 1);
	
		PHALCON_INIT_VAR(model_message);
		object_init_ex(model_message, phalcon_mvc_model_message_ce);
		PHALCON_CALL_METHOD(NULL, model_message, "__construct", message, field, type);
	
		PHALCON_INIT_VAR(messages);
		array_init_size(messages, 1);
		phalcon_array_append(&messages, model_message, PH_SEPARATE);
		phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Using save() anyways
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "save");
	RETURN_MM();
}

/**
 * Updates a model instance. If the instance doesn't exist in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->update();
 *</code>
 *
 * @param array $data
 * @param array $whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, update){

	zval *data = NULL, *white_list = NULL, *meta_data = NULL, *column_map = NULL;
	zval *attributes = NULL, *attribute = NULL, *attribute_field = NULL;
	zval *exception_message = NULL, *value = NULL, *possible_setter = NULL;
	zval *dirty_state, *read_connection = NULL, *exists = NULL;
	zval *field, *type, *message, *model_message, *messages;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &white_list);
	
	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}
	
	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(meta_data);
	
	/** 
	 * Assign the values bassed on the passed
	 */
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data passed to update() must be an array");
			return;
		}
	
		PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
		} else {
			PHALCON_INIT_VAR(column_map);
		}
	
		/** 
		 * We assign the fields starting from the current attributes in the model
		 */
		PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
	
		phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(attribute);
	
			/** 
			 * Check if we need to rename the field
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, attribute)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, attribute, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", attribute, "' isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, attribute);
			}
	
			/** 
			 * Check if we there is data for the field
			 */
			if (phalcon_array_isset(data, attribute_field)) {
	
				/** 
				 * If the white-list is an array check if the attribute is on that list
				 */
				if (Z_TYPE_P(white_list) == IS_ARRAY) { 
					if (!phalcon_fast_in_array(attribute_field, white_list TSRMLS_CC)) {
						zend_hash_move_forward_ex(ah0, &hp0);
						continue;
					}
				}
	
				/** 
				 * Reads the attribute from the data
				 */
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch(&value, data, attribute_field, PH_NOISY);
	
				/** 
				 * Try to find a possible getter
				 */
				PHALCON_INIT_NVAR(possible_setter);
				PHALCON_CONCAT_SV(possible_setter, "set", attribute_field);
				zend_str_tolower(Z_STRVAL_P(possible_setter), Z_STRLEN_P(possible_setter));
				if (phalcon_method_exists_ex(this_ptr, Z_STRVAL_P(possible_setter), Z_STRLEN_P(possible_setter)+1 TSRMLS_CC) == SUCCESS) {
					PHALCON_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(possible_setter), value);
				} else {
					phalcon_update_property_zval_zval(this_ptr, attribute_field, value TSRMLS_CC);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * We don't check if the record exists if the record is already checked
	 */
	PHALCON_OBS_VAR(dirty_state);
	phalcon_read_property_this(&dirty_state, this_ptr, SL("_dirtyState"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(dirty_state)) {
		if (Z_TYPE_P(meta_data) == IS_NULL) {
			PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
		}
	
		PHALCON_CALL_METHOD(&read_connection, this_ptr, "getreadconnection");

		PHALCON_CALL_METHOD(&exists, this_ptr, "_exists", meta_data, read_connection);
		if (!zend_is_true(exists)) {
			PHALCON_INIT_VAR(field);
	
			PHALCON_INIT_VAR(type);
			ZVAL_STRING(type, "InvalidUpdateAttempt", 1);
	
			PHALCON_INIT_VAR(message);
			ZVAL_STRING(message, "Record cannot be updated because it does not exist", 1);
	
			PHALCON_INIT_VAR(model_message);
			object_init_ex(model_message, phalcon_mvc_model_message_ce);
			PHALCON_CALL_METHOD(NULL, model_message, "__construct", message, field, type);
	
			PHALCON_INIT_VAR(messages);
			array_init_size(messages, 1);
			phalcon_array_append(&messages, model_message, 0);
			phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Call save() anyways
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "save");
	RETURN_MM();
}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *$robot = Robots::findFirst("id=100");
 *$robot->delete();
 *
 *foreach (Robots::find("type = 'mechanical'") as $robot) {
 *   $robot->delete();
 *}
 * </code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, delete){

	zval *meta_data = NULL, *write_connection = NULL, *empty_array;
	zval *check_foreign_keys = NULL, *values, *bind_types;
	zval *conditions, *primary_keys = NULL, *bind_data_types = NULL;
	zval *column_map = NULL, *primary_key = NULL, *exception_message = NULL;
	zval *attribute_field = NULL, *value = NULL, *escaped_field = NULL;
	zval *primary_condition = NULL, *bind_type = NULL, *delete_conditions;
	zval *event_name = NULL, *status = NULL, *skipped, *schema = NULL, *source = NULL;
	zval *table = NULL, *success = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD(&write_connection, this_ptr, "getwriteconnection");
	
	/** 
	 * Operation made is OP_DELETE
	 */
	phalcon_update_property_long(this_ptr, SL("_operationMade"), 3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_errorMessages"), empty_array TSRMLS_CC);
	
	/** 
	 * Check if deleting the record violates a virtual foreign key
	 */
	if (PHALCON_GLOBAL(orm).virtual_foreign_keys) {
		PHALCON_CALL_METHOD(&check_foreign_keys, this_ptr, "_checkforeignkeysreverserestrict");
		if (PHALCON_IS_FALSE(check_foreign_keys)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_CALL_METHOD(&primary_keys, meta_data, "getprimarykeyattributes", this_ptr);
	PHALCON_CALL_METHOD(&bind_data_types, meta_data, "getbindtypes", this_ptr);
	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
	} else {
		PHALCON_INIT_VAR(column_map);
	}
	
	/** 
	 * We can't create dynamic SQL without a primary key
	 */
	if (!phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation");
		return;
	}
	
	/** 
	 * Create a condition from the primary keys
	 */
	phalcon_is_iterable(primary_keys, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(primary_key);
	
		/** 
		 * Every column part of the primary key must be in the bind data types
		 */
		if (!phalcon_array_isset(bind_data_types, primary_key)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", primary_key, "' have not defined a bind data type");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Take the column values based on the column map if any
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, primary_key)) {
				PHALCON_OBS_NVAR(attribute_field);
				phalcon_array_fetch(&attribute_field, column_map, primary_key, PH_NOISY);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", primary_key, "' isn't part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(attribute_field, primary_key);
		}
	
		/** 
		 * If the attribute is currently set in the object add it to the conditions
		 */
		if (!phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Cannot delete the record because the primary key attribute: '", attribute_field, "' wasn't set");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		PHALCON_OBS_NVAR(value);
		phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
		phalcon_array_append(&values, value, PH_SEPARATE);
	
		/** 
		 * Escape the column identifier
		 */
		PHALCON_CALL_METHOD(&escaped_field, write_connection, "escapeidentifier", primary_key);
	
		PHALCON_INIT_NVAR(primary_condition);
		PHALCON_CONCAT_VS(primary_condition, escaped_field, " = ?");
		phalcon_array_append(&conditions, primary_condition, PH_SEPARATE);
	
		PHALCON_OBS_NVAR(bind_type);
		phalcon_array_fetch(&bind_type, bind_data_types, primary_key, PH_NOISY);
		phalcon_array_append(&bind_types, bind_type, PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Join the conditions in the array using an AND operator
	 */
	PHALCON_INIT_VAR(delete_conditions);
	phalcon_fast_join_str(delete_conditions, SL(" AND "), conditions TSRMLS_CC);
	if (PHALCON_GLOBAL(orm).events) {
		phalcon_update_property_bool(this_ptr, SL("_skipped"), 0 TSRMLS_CC);
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeDelete", 1);
	
		/** 
		 * Fire the beforeDelete event
		 */
		PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		} else {
			/** 
			 * The operation can be skipped
			 */
			PHALCON_OBS_VAR(skipped);
			phalcon_read_property_this(&skipped, this_ptr, SL("_skipped"), PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_TRUE(skipped)) {
				RETURN_MM_TRUE;
			}
		}
	}
	
	PHALCON_CALL_METHOD(&schema, this_ptr, "getschema");
	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		array_init_size(table, 2);
		phalcon_array_append(&table, schema, 0);
		phalcon_array_append(&table, source, 0);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	/** 
	 * Do the deletion
	 */
	PHALCON_CALL_METHOD(&success, write_connection, "delete", table, delete_conditions, values, bind_types);
	
	/** 
	 * Check if there is virtual foreign keys with cascade action
	 */
	if (PHALCON_GLOBAL(orm).virtual_foreign_keys) {
		PHALCON_CALL_METHOD(&check_foreign_keys, this_ptr, "_checkforeignkeysreversecascade");
		if (PHALCON_IS_FALSE(check_foreign_keys)) {
			RETURN_MM_FALSE;
		}
	}
	
	if (PHALCON_GLOBAL(orm).events) {
		if (zend_is_true(success)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterDelete", 1);
			PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name);
		}
	}
	
	/** 
	 * Force perform the record existence checking again
	 */
	phalcon_update_property_long(this_ptr, SL("_dirtyState"), 2 TSRMLS_CC);
	
	RETURN_CTOR(success);
}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade){


	RETURN_MEMBER(this_ptr, "_operationMade");
}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh){

	zval *dirty_state, *meta_data = NULL, *read_connection = NULL;
	zval *schema = NULL, *source = NULL, *table = NULL, *unique_key = NULL, *exists = NULL;
	zval *unique_params, *unique_types, *attributes = NULL;
	zval *fields, *escaped_table = NULL;
	zval *select, *dialect = NULL, *sql = NULL, *fetch_type, *row = NULL, *column_map = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dirty_state);
	phalcon_read_property_this(&dirty_state, this_ptr, SL("_dirtyState"), PH_NOISY TSRMLS_CC);
	if (!PHALCON_IS_LONG(dirty_state, 0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted");
		return;
	}
	
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD(&read_connection, this_ptr, "getreadconnection");
	PHALCON_CALL_METHOD(&schema, this_ptr, "getschema");
	PHALCON_CALL_METHOD(&source, this_ptr, "getsource");
	
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		array_init_size(table, 2);
		phalcon_array_append(&table, schema, 0);
		phalcon_array_append(&table, source, 0);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	PHALCON_OBS_VAR(unique_key);
	phalcon_read_property_this(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(unique_key)) {
	
		/** 
		 * We need to check if the record exists
		 */
		PHALCON_CALL_METHOD(&exists, this_ptr, "_exists", meta_data, read_connection, table);
		if (!zend_is_true(exists)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted");
			return;
		}
	
		PHALCON_OBS_NVAR(unique_key);
		phalcon_read_property_this(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(unique_params);
	phalcon_read_property_this(&unique_params, this_ptr, SL("_uniqueParams"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(unique_params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted");
		return;
	}
	
	PHALCON_OBS_VAR(unique_types);
	phalcon_read_property_this(&unique_types, this_ptr, SL("_uniqueTypes"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We only refresh the attributes in the model's metadata
	 */
	PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		zval *field_item;

		MAKE_STD_ZVAL(field_item);
		array_init_size(field_item, 1);
		phalcon_array_append(&field_item, *hd, 0);

		add_next_index_zval(fields, field_item);

		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_CALL_METHOD(&escaped_table, read_connection, "escapeidentifier", table);
	
	PHALCON_INIT_VAR(select);
	array_init_size(select, 3);
	phalcon_array_update_string(&select, ISL(columns), fields, PH_COPY);
	phalcon_array_update_string(&select, ISL(tables), escaped_table, PH_COPY);
	phalcon_array_update_string(&select, ISL(where), unique_key, PH_COPY);
	
	/** 
	 * We directly build the SELECT to save resources
	 */
	PHALCON_CALL_METHOD(&dialect, read_connection, "getdialect");
	PHALCON_CALL_METHOD(&sql, dialect, "select", select);
	
	PHALCON_INIT_VAR(fetch_type);
	ZVAL_LONG(fetch_type, PDO_FETCH_ASSOC);
	
	PHALCON_CALL_METHOD(&row, read_connection, "fetchone", sql, fetch_type, unique_params, unique_types);
	
	/** 
	 * Get a column map if any
	 */
	PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
	
	/** 
	 * Assign the resulting array to the this_ptr object
	 */
	if (Z_TYPE_P(row) == IS_ARRAY) { 
		PHALCON_CALL_METHOD(NULL, this_ptr, "assign", row, column_map);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Skips the current operation forcing a success state
 *
 * @param boolean $skip
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation){

	zval *skip;

	phalcon_fetch_params(0, 1, 0, &skip);
	
	phalcon_update_property_this(this_ptr, SL("_skipped"), skip TSRMLS_CC);
	
}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute('name');
 * </code>
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute){

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
 * <code>
 * 	$robot->writeAttribute('name', 'Rosey');
 * </code>
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute){

	zval *attribute, *value;

	phalcon_fetch_params(0, 2, 0, &attribute, &value);
	
	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributes(array('price'));
 *   }
 *
 *}
 *</code>
 *
 * @param array $attributes
 * @param boolean $replace
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes){

	zval *attributes, *replace = NULL, *null_value, *keys_attributes;
	zval *attribute = NULL, *meta_data = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &attributes, &replace);
	
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array");
		return;
	}

	if (!replace) {
		replace = PHALCON_GLOBAL(z_false);
	}
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(keys_attributes);
	array_init(keys_attributes);
	
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(attribute);
	
		phalcon_array_update_zval(&keys_attributes, attribute, null_value, PH_COPY);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD(NULL, meta_data, "setautomaticcreateattributes", this_ptr, keys_attributes, replace);
	PHALCON_CALL_METHOD(NULL, meta_data, "setautomaticupdateattributes", this_ptr, keys_attributes, replace);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnCreate(array('created_at'));
 *   }
 *
 *}
 *</code>
 *
 * @param array $attributes
 * @param boolean $replace
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate){

	zval *attributes, *replace = NULL, *null_value, *keys_attributes;
	zval *attribute = NULL, *meta_data = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &attributes, &replace);
	
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array");
		return;
	}

	if (!replace) {
		replace = PHALCON_GLOBAL(z_false);
		ZVAL_FALSE(replace);
	}
	
	null_value = PHALCON_GLOBAL(z_null);
	
	PHALCON_INIT_VAR(keys_attributes);
	array_init(keys_attributes);
	
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(attribute);
	
		phalcon_array_update_zval(&keys_attributes, attribute, null_value, PH_COPY);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD(NULL, meta_data, "setautomaticcreateattributes", this_ptr, keys_attributes, replace);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnUpdate(array('modified_in'));
 *   }
 *
 *}
 *</code>
 *
 * @param array $attributes
 * @param boolean $replace
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate){

	zval *attributes, *replace = NULL, *null_value, *keys_attributes;
	zval *attribute = NULL, *meta_data = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &attributes, &replace);
	
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array");
		return;
	}

	if (!replace) {
		replace = PHALCON_GLOBAL(z_false);
	}
	
	null_value = PHALCON_GLOBAL(z_null);
	
	PHALCON_INIT_VAR(keys_attributes);
	array_init(keys_attributes);
	
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(attribute);
	
		phalcon_array_update_zval(&keys_attributes, attribute, null_value, PH_COPY);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD(NULL, meta_data, "setautomaticupdateattributes", this_ptr, keys_attributes, replace);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasOne('id', 'RobotsDescription', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 1, &fields, &reference_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(manager, "addhasone", this_ptr, fields, reference_model, referenced_fields, options);
	RETURN_MM();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *<code>
 *
 *class RobotsParts extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->belongsTo('robots_id', 'Robots', 'id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 1, &fields, &reference_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(manager, "addbelongsto", this_ptr, fields, reference_model, referenced_fields, options);
	RETURN_MM();
}

/**
 * Setup a relation 1-n between two models
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 1, &fields, &reference_model, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(manager, "addhasmany", this_ptr, fields, reference_model, referenced_fields, options);
	RETURN_MM();
}

/**
 * Setup a relation n-n between two models through an intermediate relation
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       //Setup a many-to-many relation to Parts through RobotsParts
 *       $this->hasManyToMany(
 *			'id',
 *			'RobotsParts',
 *			'robots_id',
 *			'parts_id',
 *			'Parts',
 *			'id'
 *		);
 *   }
 *
 *}
 *</code>
 *
 * @param string $fields
 * @param string $intermediateModel
 * @param string $intermediateFields
 * @param string $intermediateReferencedFields
 * @param string $referencedModel
 * @param   string $referencedFields
 * @param   array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany){

	zval *fields, *intermediate_model, *intermediate_fields;
	zval *intermediate_referenced_fields, *reference_model;
	zval *referenced_fields, *options = NULL, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 6, 1, &fields, &intermediate_model, &intermediate_fields, &intermediate_referenced_fields, &reference_model, &referenced_fields, &options);
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CALL_METHOD(manager, "addhasmanytomany", this_ptr, fields, intermediate_model, intermediate_fields, intermediate_referenced_fields, reference_model, referenced_fields, options ? options : PHALCON_GLOBAL(z_null));
	RETURN_MM();
}

/**
 * Setups a behavior in a model
 *
 *<code>
 *
 *use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->addBehavior(new Timestampable(array(
 *			'onCreate' => array(
 *				'field' => 'created_at',
 *				'format' => 'Y-m-d'
 *			)
 *		)));
 *   }
 *
 *}
 *</code>
 *
 * @param Phalcon\Mvc\Model\BehaviorInterface $behavior
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior){

	zval *behavior, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &behavior);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, manager, "addbehavior", this_ptr, behavior);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->keepSnapshots(true);
 *   }
 *
 *}
 *</code>
 *
 * @param boolean $keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots){

	zval *keep_snapshot, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &keep_snapshot);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, manager, "keepsnapshots", this_ptr, keep_snapshot);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
 *
 * @param array $data
 * @param array $columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData){

	zval *data, *column_map = NULL, *snapshot, *value = NULL, *key = NULL, *exception_message = NULL;
	zval *attribute = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &data, &column_map);
	
	if (!column_map) {
		column_map = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The snapshot data must be an array");
		return;
	}
	
	/** 
	 * Build the snapshot based on a column map
	 */
	if (Z_TYPE_P(column_map) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(snapshot);
		array_init(snapshot);
	
		phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			/** 
			 * Use only strings
			 */
			if (Z_TYPE_P(key) != IS_STRING) {
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
	
			/** 
			 * Every field must be part of the column map
			 */
			if (!phalcon_array_isset(column_map, key)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column \"", key, "\" doesn't make part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			PHALCON_OBS_NVAR(attribute);
			phalcon_array_fetch(&attribute, column_map, key, PH_NOISY);
			phalcon_array_update_zval(&snapshot, attribute, value, PH_COPY);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_update_property_this(this_ptr, SL("_snapshot"), snapshot TSRMLS_CC);
		RETURN_MM_NULL();
	}
	
	phalcon_update_property_this(this_ptr, SL("_snapshot"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the object has internal snapshot data
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData){

	zval *snapshot;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(snapshot);
	phalcon_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(snapshot) == IS_ARRAY) { 
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns the internal snapshot data
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData){


	RETURN_MEMBER(this_ptr, "_snapshot");
}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 * @param boolean $fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged){

	zval *field_name = NULL, *snapshot, *dirty_state, *meta_data = NULL;
	zval *column_map = NULL, *attributes = NULL, *all_attributes = NULL;
	zval *exception_message = NULL, *value = NULL, *original_value = NULL;
	zval *type = NULL, *name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &field_name);
	
	if (!field_name) {
		field_name = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(snapshot);
	phalcon_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot");
		return;
	}
	
	if (Z_TYPE_P(field_name) != IS_STRING) {
		if (Z_TYPE_P(field_name) != IS_NULL) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The field name must be string");
			return;
		}
	}
	
	PHALCON_OBS_VAR(dirty_state);
	phalcon_read_property_this(&dirty_state, this_ptr, SL("_dirtyState"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Dirty state must be DIRTY_PERSISTENT to make the checking 
	 */
	if (!PHALCON_IS_LONG(dirty_state, 0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted");
		return;
	}
	
	/** 
	 * Return the models meta-data
	 */
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * The reversed column map is an array if the model has a column map
	 */
	PHALCON_CALL_METHOD(&column_map, meta_data, "getreversecolumnmap", this_ptr);
	
	/** 
	 * Data types are field indexed
	 */
	if (Z_TYPE_P(column_map) != IS_ARRAY) { 
		PHALCON_CALL_METHOD(&attributes, meta_data, "getdatatypes", this_ptr);
		PHALCON_CPY_WRT(all_attributes, attributes);
	} else {
		PHALCON_CPY_WRT(all_attributes, column_map);
	}
	
	/** 
	 * If a field was specified we only check it
	 */
	if (Z_TYPE_P(field_name) == IS_STRING) {
	
		/** 
		 * We only make this validation over valid fields
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (!phalcon_array_isset(column_map, field_name)) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "The field '", field_name, "' is not part of the model");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			if (!phalcon_array_isset(attributes, field_name)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "The field '", field_name, "' is not part of the model");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		}
	
		/** 
		 * The field is not part of the model, throw exception
		 */
		if (!phalcon_isset_property_zval(this_ptr, field_name TSRMLS_CC)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "The field '", field_name, "' is not defined on the model");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * The field is not part of the data snapshot, throw exception
		 */
		if (!phalcon_array_isset(snapshot, field_name)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "The field '", field_name, "' was not found in the snapshot");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		PHALCON_OBS_VAR(value);
		phalcon_read_property_zval(&value, this_ptr, field_name, PH_NOISY TSRMLS_CC);
	
		PHALCON_OBS_VAR(original_value);
		phalcon_array_fetch(&original_value, snapshot, field_name, PH_NOISY);
	
		/** 
		 * Check if the field has changed
		 */
		if (PHALCON_IS_EQUAL(value, original_value)) {
			RETURN_MM_FALSE;
		} else {
			RETURN_MM_TRUE;
		}
	}
	
	/** 
	 * Check every attribute in the model
	 */
	phalcon_is_iterable(all_attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(name, ah0, hp0);
		PHALCON_GET_HVALUE(type);
	
		/** 
		 * If some attribute is not present in the snapshot, we assume the record as
		 * changed
		 */
		if (!phalcon_array_isset(snapshot, name)) {
			RETURN_MM_TRUE;
		}
	
		/** 
		 * If some attribute is not present in the model, we assume the record as changed
		 */
		if (!phalcon_isset_property_zval(this_ptr, name TSRMLS_CC)) {
			RETURN_MM_TRUE;
		}
	
		PHALCON_OBS_NVAR(value);
		phalcon_read_property_zval(&value, this_ptr, name, PH_NOISY TSRMLS_CC);
	
		PHALCON_OBS_NVAR(original_value);
		phalcon_array_fetch(&original_value, snapshot, name, PH_NOISY);
	
		/** 
		 * Check if the field has changed
		 */
		if (!PHALCON_IS_EQUAL(value, original_value)) {
			RETURN_MM_TRUE;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns a list of changed values
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields){

	zval *snapshot, *dirty_state, *meta_data = NULL, *column_map = NULL;
	zval *attributes = NULL, *all_attributes = NULL, *changed;
	zval *type = NULL, *name = NULL, *value = NULL, *original_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(snapshot);
	phalcon_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot");
		return;
	}
	
	PHALCON_OBS_VAR(dirty_state);
	phalcon_read_property_this(&dirty_state, this_ptr, SL("_dirtyState"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Dirty state must be DIRTY_PERSISTENT to make the checking 
	 */
	if (!PHALCON_IS_LONG(dirty_state, 0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted");
		return;
	}
	
	/** 
	 * Return the models meta-data
	 */
	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * The reversed column map is an array if the model has a column map
	 */
	PHALCON_CALL_METHOD(&column_map, meta_data, "getreversecolumnmap", this_ptr);
	
	/** 
	 * Data types are field indexed
	 */
	if (Z_TYPE_P(column_map) != IS_ARRAY) { 
		PHALCON_CALL_METHOD(&attributes, meta_data, "getdatatypes", this_ptr);
		PHALCON_CPY_WRT(all_attributes, attributes);
	} else {
		PHALCON_CPY_WRT(all_attributes, column_map);
	}
	
	PHALCON_INIT_VAR(changed);
	array_init(changed);
	
	/** 
	 * Check every attribute in the model
	 */
	phalcon_is_iterable(all_attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(name, ah0, hp0);
		PHALCON_GET_HVALUE(type);
	
		/** 
		 * If some attribute is not present in the snapshot, we assume the record as
		 * changed
		 */
		if (!phalcon_array_isset(snapshot, name)) {
			phalcon_array_append(&changed, name, PH_SEPARATE);
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		/** 
		 * If some attribute is not present in the model, we assume the record as changed
		 */
		if (!phalcon_isset_property_zval(this_ptr, name TSRMLS_CC)) {
			phalcon_array_append(&changed, name, PH_SEPARATE);
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		PHALCON_OBS_NVAR(value);
		phalcon_read_property_zval(&value, this_ptr, name, PH_NOISY TSRMLS_CC);
	
		PHALCON_OBS_NVAR(original_value);
		phalcon_array_fetch(&original_value, snapshot, name, PH_NOISY);
	
		/** 
		 * Check if the field has changed
		 */
		if (!PHALCON_IS_EQUAL(value, original_value)) {
			phalcon_array_append(&changed, name, PH_SEPARATE);
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(changed);
}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->useDynamicUpdate(true);
 *   }
 *
 *}
 *</code>
 *
 * @param boolean $dynamicUpdate
 */
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate){

	zval *dynamic_update, *manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &dynamic_update);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(NULL, manager, "usedynamicupdate", this_ptr, dynamic_update);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns related records based on defined relations
 *
 * @param string $alias
 * @param array $arguments
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated){

	zval *alias, *arguments = NULL, *manager, *class_name;
	zval *relation = NULL, *exception_message, *call_object;
	zval *model_args;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &alias, &arguments);
	
	if (!arguments) {
		arguments = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, this_ptr, 0 TSRMLS_CC);
	
	/** 
	 * Query the relation by alias
	 */
	PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", class_name, alias);
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVSVS(exception_message, "There is no defined relations for the model \"", class_name, "\" using alias \"", alias, "\"");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Call the 'getRelationRecords' in the models manager
	 */
	PHALCON_INIT_VAR(call_object);
	array_init_size(call_object, 2);
	phalcon_array_append(&call_object, manager, PH_SEPARATE);
	add_next_index_stringl(call_object, SL("getRelationRecords"), 1);
	
	PHALCON_INIT_VAR(model_args);
	array_init_size(model_args, 4);
	phalcon_array_append(&model_args, relation, PH_SEPARATE);
	add_next_index_null(model_args);
	phalcon_array_append(&model_args, this_ptr, PH_SEPARATE);
	phalcon_array_append(&model_args, arguments, PH_SEPARATE);
	PHALCON_CALL_USER_FUNC_ARRAY(return_value, call_object, model_args);
	RETURN_MM();
}

/**
 * Returns related records defined relations depending on the method name
 *
 * @param string $modelName
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords){

	zval *model_name, *method, *arguments, *manager;
	zval *relation = NULL, *query_method = NULL, *alias = NULL, *extra_args = NULL;
	zval *call_args, *call_object;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &model_name, &method, &arguments);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(relation);
	ZVAL_BOOL(relation, 0);
	
	PHALCON_INIT_VAR(query_method);
	
	/** 
	 * Calling find/findFirst if the method starts with "get"
	 */
	if (phalcon_start_with_str(method, SL("get"))) {
		PHALCON_INIT_VAR(alias);
		phalcon_substr(alias, method, 3, 0);
	
		PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", model_name, alias);
	}
	
	/** 
	 * Calling count if the method starts with "count"
	 */
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		if (phalcon_start_with_str(method, SL("count"))) {
			ZVAL_STRING(query_method, "count", 1);
	
			PHALCON_INIT_NVAR(alias);
			phalcon_substr(alias, method, 5, 0);
	
			PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", model_name, alias);
		}
	}
	
	/** 
	 * If the relation was found perform the query via the models manager
	 */
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		if (phalcon_array_isset_long(arguments, 0)) {
			PHALCON_OBS_VAR(extra_args);
			phalcon_array_fetch_long(&extra_args, arguments, 0, PH_NOISY);
		} else {
			PHALCON_INIT_NVAR(extra_args);
		}
	
		PHALCON_INIT_VAR(call_args);
		array_init_size(call_args, 4);
		phalcon_array_append(&call_args, relation, PH_SEPARATE);
		phalcon_array_append(&call_args, query_method, PH_SEPARATE);
		phalcon_array_append(&call_args, this_ptr, PH_SEPARATE);
		phalcon_array_append(&call_args, extra_args, PH_SEPARATE);
	
		PHALCON_INIT_VAR(call_object);
		array_init_size(call_object, 2);
		phalcon_array_append(&call_object, manager, PH_SEPARATE);
		add_next_index_stringl(call_object, SL("getRelationRecords"), 1);
		PHALCON_CALL_USER_FUNC_ARRAY(return_value, call_object, call_args);
		RETURN_MM();
	}
	
	RETURN_MM_NULL();
}

/**
 * Handles method calls when a method is not implemented
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __call){

	zval *method, *arguments = NULL, *model_name, *records = NULL;
	zval *models_manager, *status = NULL, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &method, &arguments);
	
	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, this_ptr, 0 TSRMLS_CC);
	
	/** 
	 * Check if there is a default action using the magic getter
	 */
	PHALCON_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", model_name, method, arguments);
	if (Z_TYPE_P(records) != IS_NULL) {
		RETURN_CTOR(records);
	}
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property_this(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Try to find a replacement for the missing method in a behavior/listener
	 */
	PHALCON_CALL_METHOD(&status, models_manager, "missingmethod", this_ptr, method, arguments);
	if (Z_TYPE_P(status) != IS_NULL) {
		RETURN_CTOR(status);
	}
	
	/** 
	 * The method doesn't exist throw an exception
	 */
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVSVS(exception_message, "The method \"", method, "\" doesn't exist on model \"", model_name, "\"");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
}

/**
 * Handles method calls when a static method is not implemented
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic){

	zval *method, *arguments = NULL, *extra_method = NULL;
	zval *model_name, *exception_message = NULL, *value;
	zval *model, *meta_data = NULL, *attributes = NULL, *field = NULL, *extra_method_first;
	zval *conditions, *bind_params, *parameters;
	zend_class_entry *ce0;
	const char *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &method, &arguments);
	
	if (!arguments) {
		arguments = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(extra_method);
	
	/** 
	 * Check if the method starts with 'findFirst'
	 */
	if (phalcon_start_with_str(method, SL("findFirstBy"))) {
		type = "findfirst";
		phalcon_substr(extra_method, method, 11, 0);
	}
	
	/** 
	 * Check if the method starts with 'find'
	 */
	if (Z_TYPE_P(extra_method) == IS_NULL) {
		if (phalcon_start_with_str(method, SL("findBy"))) {
			type = "find";
			phalcon_substr(extra_method, method, 6, 0);
		}
	}
	
	/** 
	 * Check if the method starts with 'count'
	 */
	if (Z_TYPE_P(extra_method) == IS_NULL) {
		if (phalcon_start_with_str(method, SL("countBy"))) {
			type = "count";
			phalcon_substr(extra_method, method, 7, 0);
		}
	}
	
	/** 
	 * The called class is the model
	 */
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	if (!zend_is_true(extra_method)) {
		/** 
		 * The method doesn't exist throw an exception
		 */
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVSVS(exception_message, "The static method \"", method, "\" doesn't exist on model \"", model_name, "\"");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	if (!phalcon_array_isset_long(arguments, 0)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "The static method \"", method, "\" requires one argument");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(value);
	phalcon_array_fetch_long(&value, arguments, 0, PH_NOISY);
	ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(model);
	object_init_ex(model, ce0);
	if (phalcon_has_constructor(model TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, model, "__construct");
	}
	
	/** 
	 * Get the model's meta-data
	 */
	PHALCON_CALL_METHOD(&meta_data, model, "getmodelsmetadata");
	
	/** 
	 * Get the attributes
	 */
	PHALCON_CALL_METHOD(&attributes, meta_data, "getreversecolumnmap", model);
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		/** 
		 * Use the standard attributes if there is no column map available
		 */
		PHALCON_CALL_METHOD(&attributes, meta_data, "getdatatypes", model);
	}
	
	/** 
	 * Check if the extra-method is an attribute
	 */
	if (phalcon_array_isset(attributes, extra_method)) {
		PHALCON_CPY_WRT(field, extra_method);
	} else {
		/** 
		 * Lowercase the first letter of the extra-method
		 */
		PHALCON_INIT_VAR(extra_method_first);
		phalcon_lcfirst(extra_method_first, extra_method);
		if (phalcon_array_isset(attributes, extra_method_first)) {
			PHALCON_CPY_WRT(field, extra_method_first);
		} else {
			/** 
			 * Get the possible real method name
			 */
			PHALCON_INIT_NVAR(field);
			phalcon_uncamelize(field, extra_method);
			if (!phalcon_array_isset(attributes, field)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Cannot resolve attribute \"", extra_method, "' in the model");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		}
	}
	
	PHALCON_INIT_VAR(conditions);
	PHALCON_CONCAT_VS(conditions, field, " = ?0");
	
	PHALCON_INIT_VAR(bind_params);
	array_init_size(bind_params, 1);
	phalcon_array_append(&bind_params, value, 0);
	
	PHALCON_INIT_VAR(parameters);
	array_init_size(parameters, 2);
	phalcon_array_update_string(&parameters, ISL(conditions), conditions, PH_COPY);
	phalcon_array_update_string(&parameters, SL("bind"), bind_params, PH_COPY);
	
	/** 
	 * Execute the query
	 */
	PHALCON_RETURN_CALL_CE_STATIC(ce0, type, parameters);
	RETURN_MM();
}

/**
 * Magic method to assign values to the the model
 *
 * @param string $property
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Model, __set){

	zval *property, *value, *lower_property = NULL;
	zval *meta_data = NULL, *column_map = NULL, *attributes = NULL;
	zval *related, *key = NULL, *lower_key = NULL, *item = NULL, *model_name, *manager = NULL;
	zval *relation = NULL, *new_instance, *referenced_model_name = NULL, *referenced_model = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int i = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &property, &value);

	if (Z_TYPE_P(property) == IS_STRING) {
		PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
		PHALCON_CALL_METHOD(&column_map, meta_data, "getreversecolumnmap", this_ptr);
		if (Z_TYPE_P(column_map) != IS_ARRAY) {
			PHALCON_CALL_METHOD(&attributes, meta_data, "getdatatypes", this_ptr);

			if (phalcon_array_isset(attributes, property)) {
				phalcon_update_property_zval_zval(this_ptr, property, value TSRMLS_CC);
				RETURN_CTOR(value);
			}
		} else {
			if (phalcon_array_isset(column_map, property)) {
				phalcon_update_property_zval_zval(this_ptr, property, value TSRMLS_CC);
				RETURN_CTOR(value);
			}
		}
	}
	
	/** 
	 * Values are probably relationships if they are objects
	 */
	if (Z_TYPE_P(value) == IS_OBJECT) {
	
		if (instanceof_function_ex(Z_OBJCE_P(value), phalcon_mvc_modelinterface_ce, 1 TSRMLS_CC)) {
			PHALCON_INIT_VAR(lower_property);
			phalcon_fast_strtolower(lower_property, property);
			phalcon_update_property_zval_zval(this_ptr, lower_property, value TSRMLS_CC);
			phalcon_update_property_array(this_ptr, SL("_related"), lower_property, value TSRMLS_CC);
			phalcon_update_property_long(this_ptr, SL("_dirtyState"), 1 TSRMLS_CC);
			RETURN_CTOR(value);
		}
	}
	
	/** 
	 * Check if the value is an array
	 */
	if (Z_TYPE_P(value) == IS_ARRAY) {
		PHALCON_INIT_VAR(related);
		array_init(related);

		PHALCON_INIT_VAR(lower_property);
		phalcon_fast_strtolower(lower_property, property);

		PHALCON_INIT_VAR(model_name);
		phalcon_get_class(model_name, this_ptr, 0 TSRMLS_CC);
		
		PHALCON_CALL_METHOD(&manager, this_ptr, "getmodelsmanager");

		phalcon_is_iterable(value, &ah0, &hp0, 0, 0);
		
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(item);

			if (Z_TYPE_P(item) == IS_OBJECT) {
				if (instanceof_function_ex(Z_OBJCE_P(item), phalcon_mvc_modelinterface_ce, 1 TSRMLS_CC)) {
					i++;
					phalcon_array_append(&related, item, 0);
				}
			} else {
				PHALCON_INIT_NVAR(lower_key);
				phalcon_fast_strtolower(lower_key, key);

				phalcon_update_property_zval_zval(this_ptr, lower_key, item TSRMLS_CC);

				PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", model_name, lower_property);
				if (Z_TYPE_P(relation) == IS_OBJECT) {					
					PHALCON_INIT_VAR(new_instance);
					ZVAL_FALSE(new_instance);

					PHALCON_CALL_METHOD(&referenced_model_name, relation, "getreferencedmodel");
					PHALCON_CALL_METHOD(&referenced_model, manager, "load", referenced_model_name, new_instance);
					PHALCON_CALL_METHOD(NULL, referenced_model, "writeattribute", lower_key, item);	
				}
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		if (i > 0) {
			phalcon_update_property_zval_zval(this_ptr, lower_property, related TSRMLS_CC);
			phalcon_update_property_array(this_ptr, SL("_related"), lower_property, related TSRMLS_CC);
			phalcon_update_property_long(this_ptr, SL("_dirtyState"), 1 TSRMLS_CC);
		}

		RETURN_CTOR(value);
	}
	
	/** 
	 * Fallback assigning the value to the instance
	 */
	phalcon_update_property_zval_zval(this_ptr, property, value TSRMLS_CC);
	
	RETURN_CTOR(value);
}

/**
 * Magic method to get related records using the relation alias as a property
 *
 * @param string $property
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model, __get){

	zval *property, *model_name, *manager = NULL, *lower_property;
	zval *relation = NULL, *call_args, *call_object, *result;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &property);
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, this_ptr, 0 TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&manager, this_ptr, "getmodelsmanager");
	
	PHALCON_INIT_VAR(lower_property);
	phalcon_fast_strtolower(lower_property, property);
	
	/** 
	 * Check if the property is a relationship
	 */
	PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", model_name, lower_property);
	if (Z_TYPE_P(relation) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(call_args);
		array_init_size(call_args, 4);
		phalcon_array_append(&call_args, relation, 0);
		add_next_index_null(call_args);
		phalcon_array_append(&call_args, this_ptr, 0);
		add_next_index_null(call_args);
	
		PHALCON_INIT_VAR(call_object);
		array_init_size(call_object, 2);
		phalcon_array_append(&call_object, manager, 0);
		add_next_index_stringl(call_object, SL("getRelationRecords"), 1);
	
		/** 
		 * Get the related records
		 */
		PHALCON_INIT_VAR(result);/**/
		PHALCON_CALL_USER_FUNC_ARRAY(result, call_object, call_args);
	
		/** 
		 * Assign the result to the object
		 */
		if (Z_TYPE_P(result) == IS_OBJECT) {
	
			/** 
			 * We assign the result to the instance avoiding future queries
			 */
			phalcon_update_property_zval_zval(this_ptr, lower_property, result TSRMLS_CC);
	
			/** 
			 * For belongs-to relations we store the object in the related bag
			 */
			if (instanceof_function_ex(Z_OBJCE_P(result), phalcon_mvc_modelinterface_ce, 1 TSRMLS_CC)) {
				phalcon_update_property_array(this_ptr, SL("_related"), lower_property, result TSRMLS_CC);
			}
		}
	
		RETURN_CTOR(result);
	}
	
	/** 
	 * A notice is shown if the property is not defined and it isn't a relationship
	 */
	/* TODO see if segfault is possible */
	zend_error(E_NOTICE, "Access to undefined property %s::%s", Z_STRVAL_P(model_name), Z_STRVAL_P(property));
	RETURN_MM_NULL();
}

/**
 * Magic method to check if a property is a valid relation
 *
 * @param string $property
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset){

	zval *property, *model_name, *manager = NULL, *relation = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &property);
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, this_ptr, 0 TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&manager, this_ptr, "getmodelsmanager");
	
	/** 
	 * Check if the property is a relationship
	 */
	PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", model_name, property);
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Serializes the object ignoring connections, services, related objects or static properties
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize){

	zval *meta_data = NULL, *attributes = NULL, *null_value, *data;
	zval *attribute = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * We get the model's attributes to only serialize them
	 */
	PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(attribute);
	
		if (phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute, PH_NOISY TSRMLS_CC);
			phalcon_array_update_zval(&data, attribute, value, PH_COPY);
		} else {
			phalcon_array_update_zval(&data, attribute, null_value, PH_COPY);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
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
PHP_METHOD(Phalcon_Mvc_Model, unserialize){

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
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
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
			ZVAL_STRING(service, "modelsManager", 1);
	
			PHALCON_CALL_METHOD(&manager, dependency_injector, "getshared", service);
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
				return;
			}

			PHALCON_VERIFY_INTERFACE(manager, phalcon_mvc_model_managerinterface_ce);
	
			/** 
			 * Update the models manager
			 */
			phalcon_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
	
			/** 
			 * Try to initialize the model
			 */
			PHALCON_CALL_METHOD(NULL, manager, "initialize", this_ptr);
	
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
 * Returns a simple representation of the object that can be used with var_dump
 *
 *<code>
 * var_dump($robot->dump());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, dump){

	PHALCON_RETURN_CALL_FUNCTIONW("get_object_vars", this_ptr);
}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($robot->toArray());
 *</code>
 *
 * @param array $columns
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray){

	zval *columns = NULL, *meta_data = NULL, *data, *null_value, *attributes = NULL;
	zval *column_map = NULL, *attribute = NULL, *exception_message = NULL;
	zval *attribute_field = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &columns);

	PHALCON_CALL_METHOD(&meta_data, this_ptr, "getmodelsmetadata");
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	
	PHALCON_INIT_VAR(null_value);
	
	/** 
	 * Original attributes
	 */
	PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", this_ptr);
	
	/** 
	 * Reverse column map
	 */
	PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", this_ptr);
	
	phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(attribute);

		if (columns && Z_TYPE_P(columns) == IS_ARRAY) {
			if (!phalcon_fast_in_array(attribute, columns TSRMLS_CC)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
		}

		/** 
		 * Check if the columns must be renamed
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (!phalcon_array_isset(column_map, attribute)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column \"", attribute, "\" doesn't make part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			PHALCON_OBS_NVAR(attribute_field);
			phalcon_array_fetch(&attribute_field, column_map, attribute, PH_NOISY);
		} else {
			PHALCON_CPY_WRT(attribute_field, attribute);
		}
		if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY TSRMLS_CC);
			phalcon_array_update_zval(&data, attribute_field, value, PH_COPY);
		} else {
			phalcon_array_update_zval(&data, attribute_field, null_value, PH_COPY);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(data);
}

/**
 * Enables/disables options in the ORM
 * Available options:
 * events                — Enables/Disables globally the internal events
 * virtualForeignKeys    — Enables/Disables virtual foreign keys
 * columnRenaming        — Enables/Disables column renaming
 * notNullValidations    — Enables/Disables automatic not null validation
 * exceptionOnFailedSave — Enables/Disables throws an exception if the saving process fails
 * phqlLiterals          — Enables/Disables literals in PHQL this improves the security of applications  
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, setup){

	zval *options, *disable_events, *virtual_foreign_keys;
	zval *column_renaming, *not_null_validations;
	zval *exception_on_failed_save, *phql_literals;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Options must be an array");
		return;
	}
	
	/** 
	 * Enables/Disables globally the internal events
	 */
	if (phalcon_array_isset_string(options, SS("events"))) {
		PHALCON_OBS_VAR(disable_events);
		phalcon_array_fetch_string(&disable_events, options, SL("events"), PH_NOISY);
		PHALCON_GLOBAL(orm).events = zend_is_true(disable_events);
	}
	
	/** 
	 * Enables/Disables virtual foreign keys
	 */
	if (phalcon_array_isset_string(options, SS("virtualForeignKeys"))) {
		PHALCON_OBS_VAR(virtual_foreign_keys);
		phalcon_array_fetch_string(&virtual_foreign_keys, options, SL("virtualForeignKeys"), PH_NOISY);
		PHALCON_GLOBAL(orm).virtual_foreign_keys = zend_is_true(virtual_foreign_keys);
	}
	
	/** 
	 * Enables/Disables column renaming
	 */
	if (phalcon_array_isset_string(options, SS("columnRenaming"))) {
		PHALCON_OBS_VAR(column_renaming);
		phalcon_array_fetch_string(&column_renaming, options, SL("columnRenaming"), PH_NOISY);
		PHALCON_GLOBAL(orm).column_renaming = zend_is_true(column_renaming);
	}
	
	/** 
	 * Enables/Disables automatic not null validation
	 */
	if (phalcon_array_isset_string(options, SS("notNullValidations"))) {
		PHALCON_OBS_VAR(not_null_validations);
		phalcon_array_fetch_string(&not_null_validations, options, SL("notNullValidations"), PH_NOISY);
		PHALCON_GLOBAL(orm).not_null_validations = zend_is_true(not_null_validations);
	}
	
	/** 
	 * Enables/Disables throws an exception if the saving process fails
	 */
	if (phalcon_array_isset_string(options, SS("exceptionOnFailedSave"))) {
		PHALCON_OBS_VAR(exception_on_failed_save);
		phalcon_array_fetch_string(&exception_on_failed_save, options, SL("exceptionOnFailedSave"), PH_NOISY);
		PHALCON_GLOBAL(orm).exception_on_failed_save = zend_is_true(exception_on_failed_save);
	}
	
	/** 
	 * Enables/Disables literals in PHQL this improves the security of applications
	 */
	if (phalcon_array_isset_string(options, SS("phqlLiterals"))) {
		PHALCON_OBS_VAR(phql_literals);
		phalcon_array_fetch_string(&phql_literals, options, SL("phqlLiterals"), PH_NOISY);
		PHALCON_GLOBAL(orm).enable_literals = zend_is_true(phql_literals);
	}
	
	PHALCON_MM_RESTORE();
}


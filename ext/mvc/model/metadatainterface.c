
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

#include "mvc/model/metadatainterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_metadatainterface_ce;

static const zend_function_entry phalcon_mvc_model_metadatainterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setStrategy, arginfo_phalcon_mvc_model_metadatainterface_setstrategy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getStrategy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaData, arginfo_phalcon_mvc_model_metadatainterface_readmetadata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAttributes, arginfo_phalcon_mvc_model_metadatainterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes, arginfo_phalcon_mvc_model_metadatainterface_getdatatypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField, arginfo_phalcon_mvc_model_metadatainterface_getidentityfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes, arginfo_phalcon_mvc_model_metadatainterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute, arginfo_phalcon_mvc_model_metadatainterface_hasattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, isEmpty, arginfo_phalcon_mvc_model_metadatainterface_isempty)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, reset, arginfo_phalcon_mvc_model_metadatainterface_reset)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, read, arginfo_phalcon_mvc_model_metadatainterface_read)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, write, arginfo_phalcon_mvc_model_metadatainterface_write)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaDataInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, MetaDataInterface, mvc_model_metadatainterface, phalcon_mvc_model_metadatainterface_method_entry);

	return SUCCESS;
}

/**
 * Set the meta-data extraction strategy
 *
 * @param Phalcon\Mvc\Model\MetaData\Strategy\Introspection $strategy
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setStrategy);

/**
 * Return the strategy to obtain the meta-data
 *
 * @return Phalcon\Mvc\Model\MetaData\Strategy\Introspection
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getStrategy);

/**
 * Reads meta-data for certain model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaData);

/**
 * Reads meta-data for certain model using a MODEL_* constant
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param int $index
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex);

/**
 * Writes meta-data for certain model using a MODEL_* constant
 *
 * @param Phalcon\Mvc\Model $model
 * @param int $index
 * @param mixed $data
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex);

/**
 * Reads the ordered/reversed column map for certain model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap);

/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param int $index
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex);

/**
 * Returns table attributes names (fields)
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return 	array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAttributes);

/**
 * Returns an array of fields which are part of the primary key
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes);

/**
 * Returns an arrau of fields which are not part of the primary key
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return 	array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes);

/**
 * Returns an array of not null attributes
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes);

/**
 * Returns attributes and their data types
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes);

/**
 * Returns attributes which types are numerical
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric);

/**
 * Returns the name of identity field (if one is present)
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField);

/**
 * Returns attributes and their bind data types
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes);

/**
 * Returns attributes that must be ignored from the INSERT SQL generation
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes);

/**
 * Returns attributes that must be ignored from the UPDATE SQL generation
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes);

/**
 * Set the attributes that must be ignored from the INSERT SQL generation
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @param  array $attributes
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes);

/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @param  array $attributes
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes);

/**
 * Returns the column map if any
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap);

/**
 * Returns the reverse column map if any
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap);

/**
 * Check if a model has certain attribute
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $attribute
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute);

/**
 * Checks if the internal meta-data container is empty
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, isEmpty);

/**
 * Resets internal meta-data in order to regenerate it
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, reset);

/**
 * Reads meta-data from the adapter
 *
 * @param string $key
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, read);

/**
 * Writes meta-data to the adapter
 *
 * @param string $key
 * @param array $data
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, write);


#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
/**
 * Phalcon\Mvc\Model\MetaDataInterface
 *
 * Interface for Phalcon\Mvc\Model\MetaData
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, MetaDataInterface, phalcon, mvc_model_metadatainterface, phalcon_mvc_model_metadatainterface_method_entry);

	return SUCCESS;

}

/**
 * Set the meta-data extraction strategy
 *
 * @param Phalcon\Mvc\Model\MetaData\StrategyInterface strategy
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setStrategy);

/**
 * Return the strategy to obtain the meta-data
 *
 * @return Phalcon\Mvc\Model\MetaData\StrategyInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getStrategy);

/**
 * Reads meta-data for certain model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaData);

/**
 * Reads meta-data for certain model using a MODEL_* constant
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param int index
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex);

/**
 * Writes meta-data for certain model using a MODEL_* constant
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param int index
 * @param mixed data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex);

/**
 * Reads the ordered/reversed column map for certain model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap);

/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param int index
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex);

/**
 * Returns table attributes names (fields)
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAttributes);

/**
 * Returns an array of fields which are part of the primary key
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes);

/**
 * Returns an arrau of fields which are not part of the primary key
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes);

/**
 * Returns an array of not null attributes
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes);

/**
 * Returns attributes and their data types
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes);

/**
 * Returns attributes which types are numerical
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric);

/**
 * Returns the name of identity field (if one is present)
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField);

/**
 * Returns attributes and their bind data types
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes);

/**
 * Returns attributes that must be ignored from the INSERT SQL generation
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes);

/**
 * Returns attributes that must be ignored from the UPDATE SQL generation
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes);

/**
 * Set the attributes that must be ignored from the INSERT SQL generation
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @param  array attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes);

/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @param  array attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes);

/**
 * Returns attributes (which have default values) and their default values
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDefaultValues);

/**
 * Returns the column map if any
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap);

/**
 * Returns the reverse column map if any
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap);

/**
 * Check if a model has certain attribute
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string attribute
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute);

/**
 * Checks if the internal meta-data container is empty
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, isEmpty);

/**
 * Resets internal meta-data in order to regenerate it
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, reset);

/**
 * Reads meta-data from the adapter
 *
 * @param string key
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, read);

/**
 * Writes meta-data to the adapter
 *
 * @param string key
 * @param array data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, write);


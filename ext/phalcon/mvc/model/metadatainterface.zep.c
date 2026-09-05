
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaDataInterface
 *
 * Interface for Phalcon\Mvc\Model\MetaData
 *
 * @phpstan-import-type mvc_model_attributes from MvcTypes
 * @phpstan-import-type mvc_metadata_column_map from MvcTypes
 * @phpstan-import-type mvc_metadata_default_values from MvcTypes
 * @phpstan-import-type mvc_metadata_index from MvcTypes
 * @phpstan-import-type mvc_metadata_model from MvcTypes
 * @phpstan-import-type mvc_metadata_slot from MvcTypes
 * @phpstan-import-type mvc_metadata_types from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, MetaDataInterface, phalcon, mvc_model_metadatainterface, phalcon_mvc_model_metadatainterface_method_entry);

	return SUCCESS;
}

/**
 * Returns table attributes names (fields)
 *
 * @phpstan-return mvc_model_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAttributes);
/**
 * Returns attributes that must be ignored from the INSERT SQL generation
 *
 * @phpstan-return array<string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes);
/**
 * Returns attributes that must be ignored from the UPDATE SQL generation
 *
 * @phpstan-return array<string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes);
/**
 * Returns attributes and their bind data types
 *
 * @phpstan-return array<string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes);
/**
 * Returns the column map if any
 *
 * @phpstan-return mvc_metadata_column_map|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap);
/**
 * Returns attributes and their data types
 *
 * @phpstan-return mvc_metadata_types
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes);
/**
 * Returns attributes which types are numerical
 *
 * @phpstan-return array<string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric);
/**
 * Returns attributes (which have default values) and their default values
 *
 * @phpstan-return mvc_metadata_default_values
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDefaultValues);
/**
 * Returns attributes allow empty strings
 *
 * @phpstan-return array<string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getEmptyStringAttributes);
/**
 * Returns the name of identity field (if one is present)
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField);
/**
 * Returns an array of fields which are not part of the primary key
 *
 * @phpstan-return mvc_model_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes);
/**
 * Returns an array of not null attributes
 *
 * @phpstan-return mvc_model_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes);
/**
 * Returns an array of fields which are part of the primary key
 *
 * @phpstan-return mvc_model_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes);
/**
 * Returns the reverse column map if any
 *
 * @phpstan-return mvc_metadata_column_map|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap);
/**
 * Return the strategy to obtain the meta-data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getStrategy);
/**
 * Check if a model has certain attribute
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute);
/**
 * Checks if the internal meta-data container is empty
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, isEmpty);
/**
 * Reads meta-data from the adapter
 *
 * @phpstan-return mvc_metadata_index|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, read);
/**
 * Reads the ordered/reversed column map for certain model
 *
 * @phpstan-return mvc_metadata_index|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap);
/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 * @phpstan-return mvc_metadata_slot
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex);
/**
 * Reads meta-data for certain model
 *
 * @phpstan-return mvc_metadata_model|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaData);
/**
 * Reads meta-data for certain model using a MODEL_* constant
 *
 * @phpstan-return mvc_metadata_slot
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex);
/**
 * Resets internal meta-data in order to regenerate it
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, reset);
/**
 * Set the attributes that must be ignored from the INSERT SQL generation
 *
 * @phpstan-param array<string, mixed> $attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes);
/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 * @phpstan-param array<string, mixed> $attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes);
/**
 * Set the attributes that allow empty string values
 *
 * @phpstan-param array<string, mixed> $attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setEmptyStringAttributes);
/**
 * Set the meta-data extraction strategy
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setStrategy);
/**
 * Writes meta-data to the adapter
 *
 * @phpstan-param mvc_metadata_index $data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, write);
/**
 * Writes meta-data for certain model using a MODEL_* constant
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex);

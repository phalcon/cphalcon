
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\MetaData\Strategy\StrategyInterface;

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
interface MetaDataInterface
{
    /**
     * Returns table attributes names (fields)
     *
     * @phpstan-return mvc_model_attributes
     */
    public function getAttributes(<ModelInterface> model) -> array;

    /**
     * Returns attributes that must be ignored from the INSERT SQL generation
     *
     * @phpstan-return array<string, mixed>
     */
    public function getAutomaticCreateAttributes(<ModelInterface> model) -> array;

    /**
     * Returns attributes that must be ignored from the UPDATE SQL generation
     *
     * @phpstan-return array<string, mixed>
     */
    public function getAutomaticUpdateAttributes(<ModelInterface> model) -> array;

    /**
     * Returns attributes and their bind data types
     *
     * @phpstan-return array<string, mixed>
     */
    public function getBindTypes(<ModelInterface> model) -> array;

    /**
     * Returns the column map if any
     *
     * @phpstan-return mvc_metadata_column_map|null
     */
    public function getColumnMap(<ModelInterface> model) -> array | null;

    /**
     * Returns attributes and their data types
     *
     * @phpstan-return mvc_metadata_types
     */
    public function getDataTypes(<ModelInterface> model) -> array;

    /**
     * Returns attributes which types are numerical
     *
     * @phpstan-return array<string, mixed>
     */
    public function getDataTypesNumeric(<ModelInterface> model) -> array;

    /**
     * Returns attributes (which have default values) and their default values
     *
     * @phpstan-return mvc_metadata_default_values
     */
    public function getDefaultValues(<ModelInterface> model) -> array;

    /**
     * Returns attributes allow empty strings
     *
     * @phpstan-return array<string, mixed>
     */
    public function getEmptyStringAttributes(<ModelInterface> model) -> array;

    /**
     * Returns the name of identity field (if one is present)
     */
    public function getIdentityField(<ModelInterface> model) -> bool | string | null;

    /**
     * Returns an array of fields which are not part of the primary key
     *
     * @phpstan-return mvc_model_attributes
     */
    public function getNonPrimaryKeyAttributes(<ModelInterface> model) -> array;

    /**
     * Returns an array of not null attributes
     *
     * @phpstan-return mvc_model_attributes
     */
    public function getNotNullAttributes(<ModelInterface> model) -> array;

    /**
     * Returns an array of fields which are part of the primary key
     *
     * @phpstan-return mvc_model_attributes
     */
    public function getPrimaryKeyAttributes(<ModelInterface> model) -> array;

    /**
     * Returns the reverse column map if any
     *
     * @phpstan-return mvc_metadata_column_map|null
     */
    public function getReverseColumnMap(<ModelInterface> model) -> array | null;

    /**
     * Return the strategy to obtain the meta-data
     */
    public function getStrategy() -> <StrategyInterface>;

    /**
     * Check if a model has certain attribute
     */
    public function hasAttribute(<ModelInterface> model, string attribute) -> bool;

    /**
     * Checks if the internal meta-data container is empty
     */
    public function isEmpty() -> bool;

    /**
     * Reads meta-data from the adapter
     *
     * @phpstan-return mvc_metadata_index|null
     */
    public function read(string key) -> array | null;

    /**
     * Reads the ordered/reversed column map for certain model
     *
     * @phpstan-return mvc_metadata_index|null
     */
    public function readColumnMap(<ModelInterface> model) -> array | null;

    /**
     * Reads column-map information for certain model using a MODEL_* constant
     *
     * @phpstan-return mvc_metadata_slot
     */
    public function readColumnMapIndex(<ModelInterface> model, int index) -> array | bool | string | null;

    /**
     * Reads meta-data for certain model
     *
     * @phpstan-return mvc_metadata_model|null
     */
    public function readMetaData(<ModelInterface> model) -> array | null;

    /**
     * Reads meta-data for certain model using a MODEL_* constant
     *
     * @phpstan-return mvc_metadata_slot
     */
    public function readMetaDataIndex(<ModelInterface> model, int index) -> array | bool | string | null;

    /**
     * Resets internal meta-data in order to regenerate it
     */
    public function reset();

    /**
     * Set the attributes that must be ignored from the INSERT SQL generation
     *
     * @phpstan-param array<string, mixed> $attributes
     */
    public function setAutomaticCreateAttributes(<ModelInterface> model, array attributes);

    /**
     * Set the attributes that must be ignored from the UPDATE SQL generation
     *
     * @phpstan-param array<string, mixed> $attributes
     */
    public function setAutomaticUpdateAttributes(<ModelInterface> model, array attributes);

    /**
     * Set the attributes that allow empty string values
     *
     * @phpstan-param array<string, mixed> $attributes
     */
    public function setEmptyStringAttributes(<ModelInterface> model, array attributes) -> void;

    /**
     * Set the meta-data extraction strategy
     */
    public function setStrategy(<StrategyInterface> strategy);

    /**
     * Writes meta-data to the adapter
     *
     * @phpstan-param mvc_metadata_index $data
     */
    public function write( string key, array data) -> void;

    /**
     * Writes meta-data for certain model using a MODEL_* constant
     */
    public function writeMetaDataIndex(<ModelInterface> model, int index, var data);
}

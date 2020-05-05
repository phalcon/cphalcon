
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\MetaData\Strategy\StrategyInterface;

/**
 * Phalcon\Mvc\Model\MetaDataInterface
 *
 * Interface for Phalcon\Mvc\Model\MetaData
 */
interface MetaDataInterface
{
    /**
     * Returns table attributes names (fields)
     */
    public function getAttributes(<ModelInterface> model) -> array;

    /**
     * Returns attributes that must be ignored from the INSERT SQL generation
     */
    public function getAutomaticCreateAttributes(<ModelInterface> model) -> array;

    /**
     * Returns attributes that must be ignored from the UPDATE SQL generation
     */
    public function getAutomaticUpdateAttributes(<ModelInterface> model) -> array;

    /**
     * Returns attributes and their bind data types
     */
    public function getBindTypes(<ModelInterface> model) -> array;

    /**
     * Returns the column map if any
     */
    public function getColumnMap(<ModelInterface> model) -> array | null;

    /**
     * Returns attributes (which have default values) and their default values
     */
    public function getDefaultValues(<ModelInterface> model) -> array;

    /**
     * Returns attributes and their data types
     */
    public function getDataTypes(<ModelInterface> model) -> array;

    /**
     * Returns attributes which types are numerical
     */
    public function getDataTypesNumeric(<ModelInterface> model) -> array;

    /**
     * Returns attributes allow empty strings
     */
    public function getEmptyStringAttributes(<ModelInterface> model) -> array;

    /**
     * Returns the name of identity field (if one is present)
     */
    public function getIdentityField(<ModelInterface> model) -> string | null;

    /**
     * Returns an array of fields which are not part of the primary key
     */
    public function getNonPrimaryKeyAttributes(<ModelInterface> model) -> array;

    /**
     * Returns an array of not null attributes
     */
    public function getNotNullAttributes(<ModelInterface> model) -> array;

    /**
     * Returns an array of fields which are part of the primary key
     */
    public function getPrimaryKeyAttributes(<ModelInterface> model) -> array;

    /**
     * Returns the reverse column map if any
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
     */
    public function read(string key) -> array | null;

    /**
     * Reads the ordered/reversed column map for certain model
     */
    public function readColumnMap(<ModelInterface> model) -> array | null;

    /**
     * Reads column-map information for certain model using a MODEL_* constant
     */
    public function readColumnMapIndex(<ModelInterface> model, int index);

    /**
     * Reads meta-data for certain model
     */
    public function readMetaData(<ModelInterface> model) -> array;

    /**
     * Reads meta-data for certain model using a MODEL_* constant
     */
    public function readMetaDataIndex(<ModelInterface> model, int index) -> var;

    /**
     * Resets internal meta-data in order to regenerate it
     */
    public function reset();

    /**
     * Set the attributes that must be ignored from the INSERT SQL generation
     */
    public function setAutomaticCreateAttributes(<ModelInterface> model, array attributes);

    /**
     * Set the attributes that must be ignored from the UPDATE SQL generation
     */
    public function setAutomaticUpdateAttributes(<ModelInterface> model, array attributes);

    /**
     * Set the attributes that allow empty string values
     */
    public function setEmptyStringAttributes(<ModelInterface> model, array attributes) -> void;

    /**
     * Writes meta-data for certain model using a MODEL_* constant
     */
    public function writeMetaDataIndex(<ModelInterface> model, int index, var data);

    /**
     * Set the meta-data extraction strategy
     */
    public function setStrategy(<StrategyInterface> strategy);

    /**
     * Writes meta-data to the adapter
     */
    public function write(string! key, array data) -> void;
}

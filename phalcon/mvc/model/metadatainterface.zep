
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\MetaData\StrategyInterface;

/**
 * Phalcon\Mvc\Model\MetaDataInterface
 *
 * Interface for Phalcon\Mvc\Model\MetaData
 */
interface MetaDataInterface
{

	/**
	 * Set the meta-data extraction strategy
	 */
	public function setStrategy(<StrategyInterface> strategy);

	/**
	 * Return the strategy to obtain the meta-data
	 */
	public function getStrategy() -> <StrategyInterface>;

	/**
	 * Reads meta-data for certain model
	 */
	public function readMetaData(<ModelInterface> model) -> array;

	/**
	 * Reads meta-data for certain model using a MODEL_* constant
	 */
	public function readMetaDataIndex(<ModelInterface> model, int index) -> var;

	/**
	 * Writes meta-data for certain model using a MODEL_* constant
	 */
	public function writeMetaDataIndex(<ModelInterface> model, int index, var data);

	/**
	 * Reads the ordered/reversed column map for certain model
	 */
	public function readColumnMap(<ModelInterface> model) -> array;

	/**
	 * Reads column-map information for certain model using a MODEL_* constant
	 */
	public function readColumnMapIndex(<ModelInterface> model, int index);

	/**
	 * Returns table attributes names (fields)
	 */
	public function getAttributes(<ModelInterface> model) -> array;

	/**
	 * Returns an array of fields which are part of the primary key
	 */
	public function getPrimaryKeyAttributes(<ModelInterface> model) -> array;

	/**
	 * Returns an array of fields which are not part of the primary key
	 */
	public function getNonPrimaryKeyAttributes(<ModelInterface> model) -> array;

	/**
	 * Returns an array of not null attributes
	 */
	public function getNotNullAttributes(<ModelInterface> model) -> array;

	/**
	 * Returns attributes and their data types
	 */
	public function getDataTypes(<ModelInterface> model) -> array;

	/**
	 * Returns attributes which types are numerical
	 */
	public function getDataTypesNumeric(<ModelInterface> model) -> array;

	/**
	 * Returns the name of identity field (if one is present)
	 */
	public function getIdentityField(<ModelInterface> model) -> string;

	/**
	 * Returns attributes and their bind data types
	 */
	public function getBindTypes(<ModelInterface> model) -> array;

	/**
	 * Returns attributes that must be ignored from the INSERT SQL generation
	 */
	public function getAutomaticCreateAttributes(<ModelInterface> model) -> array;

	/**
	 * Returns attributes that must be ignored from the UPDATE SQL generation
	 */
	public function getAutomaticUpdateAttributes(<ModelInterface> model) -> array;

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
	 * Returns attributes allow empty strings
	 */
	public function getEmptyStringAttributes(<ModelInterface> model) -> array;

	/**
	 * Returns attributes (which have default values) and their default values
	 */
	public function getDefaultValues(<ModelInterface> model) -> array;

	/**
	 * Returns the column map if any
	 */
	public function getColumnMap(<ModelInterface> model) -> array;

	/**
	 * Returns the reverse column map if any
	 */
	public function getReverseColumnMap(<ModelInterface> model) -> array;

	/**
	 * Check if a model has certain attribute
	 */
	public function hasAttribute(<ModelInterface> model, string attribute) -> boolean;

	/**
	 * Checks if the internal meta-data container is empty
	 */
	public function isEmpty() -> boolean;

	/**
	 * Resets internal meta-data in order to regenerate it
	 */
	public function reset();

	/**
	 * Reads meta-data from the adapter
	 */
	public function read(string key) -> array | null;

	/**
	 * Writes meta-data to the adapter
	 */
	public function write(string! key, array data) -> void;
}

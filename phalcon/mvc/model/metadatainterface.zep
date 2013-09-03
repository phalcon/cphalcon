
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\MetaDataInterface
 *
 * Interface for Phalcon\Mvc\Model\MetaData
 */
interface MetaDataInterface
{

	/**
	 * Set the meta-data extraction strategy
	 *
	 * @param Phalcon\Mvc\Model\MetaData\Strategy\Introspection strategy
	 */
	public function setStrategy(strategy);

	/**
	 * Return the strategy to obtain the meta-data
	 *
	 * @return Phalcon\Mvc\Model\MetaData\Strategy\Introspection
	 */
	public function getStrategy();

	/**
	 * Reads meta-data for certain model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function readMetaData(model);

	/**
	 * Reads meta-data for certain model using a MODEL_* constant
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param int index
	 * @return mixed
	 */
	public function readMetaDataIndex(model, index);

	/**
	 * Writes meta-data for certain model using a MODEL_* constant
	 *
	 * @param Phalcon\Mvc\Model model
	 * @param int index
	 * @param mixed data
	 */
	public function writeMetaDataIndex(model, index, data);

	/**
	 * Reads the ordered/reversed column map for certain model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function readColumnMap(model);

	/**
	 * Reads column-map information for certain model using a MODEL_* constant
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param int index
	 */
	public function readColumnMapIndex(model, index);

	/**
	 * Returns table attributes names (fields)
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return 	array
	 */
	public function getAttributes(model);

	/**
	 * Returns an array of fields which are part of the primary key
	 *
	 * @param	Phalcon\Mvc\ModelInterface model
	 * @return	array
	 */
	public function getPrimaryKeyAttributes(model);

	/**
	 * Returns an arrau of fields which are not part of the primary key
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return 	array
	 */
	public function getNonPrimaryKeyAttributes(model);

	/**
	 * Returns an array of not null attributes
	 *
     * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getNotNullAttributes(model);

	/**
	 * Returns attributes and their data types
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getDataTypes(model);

	/**
	 * Returns attributes which types are numerical
	 *
     * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getDataTypesNumeric(model);

	/**
	 * Returns the name of identity field (if one is present)
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @return string
	 */
	public function getIdentityField(model);

	/**
	 * Returns attributes and their bind data types
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getBindTypes(model);

	/**
	 * Returns attributes that must be ignored from the INSERT SQL generation
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getAutomaticCreateAttributes(model);

	/**
	 * Returns attributes that must be ignored from the UPDATE SQL generation
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getAutomaticUpdateAttributes(model);

	/**
	 * Set the attributes that must be ignored from the INSERT SQL generation
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @param  array attributes
	 */
	public function setAutomaticCreateAttributes(model, attributes);

	/**
	 * Set the attributes that must be ignored from the UPDATE SQL generation
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @param  array attributes
	 */
	public function setAutomaticUpdateAttributes(model, attributes);

	/**
	 * Returns the column map if any
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getColumnMap(model);

	/**
	 * Returns the reverse column map if any
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getReverseColumnMap(model);

	/**
	 * Check if a model has certain attribute
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string attribute
	 * @return boolean
	 */
	public function hasAttribute(model, attribute);

	/**
	 * Checks if the internal meta-data container is empty
	 *
	 * @return boolean
	 */
	public function isEmpty();

	/**
	 * Resets internal meta-data in order to regenerate it
	 */
	public function reset();

	/**
	 * Reads meta-data from the adapter
	 *
	 * @param string key
	 * @return array
	 */
	public function read(key);

	/**
	 * Writes meta-data to the adapter
	 *
	 * @param string key
	 * @param array data
	 */
	public function write(key, data);

}
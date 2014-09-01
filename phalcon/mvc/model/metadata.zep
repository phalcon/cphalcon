
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

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
use Phalcon\Mvc\Model\MetaData\StrategyInterface;

/**
 * Phalcon\Mvc\Model\MetaData
 *
 * <p>Because Phalcon\Mvc\Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon\Mvc\Model.
 * Phalcon\Mvc\Model\MetaData can also use adapters to store temporarily or permanently the meta-data.</p>
 *
 * <p>A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:</p>
 *
 * <code>
 *	$metaData = new \Phalcon\Mvc\Model\MetaData\Memory();
 *	$attributes = $metaData->getAttributes(new Robots());
 *	print_r($attributes);
 * </code>
 *
 */
abstract class MetaData implements InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _strategy;

	protected _metaData;

	protected _columnMap;

	const MODELS_ATTRIBUTES = 0;

	const MODELS_PRIMARY_KEY = 1;

	const MODELS_NON_PRIMARY_KEY = 2;

	const MODELS_NOT_NULL = 3;

	const MODELS_DATA_TYPES = 4;

	const MODELS_DATA_TYPES_NUMERIC = 5;

	const MODELS_DATE_AT = 6;

	const MODELS_DATE_IN = 7;

	const MODELS_IDENTITY_COLUMN = 8;

	const MODELS_DATA_TYPES_BIND = 9;

	const MODELS_AUTOMATIC_DEFAULT_INSERT = 10;

	const MODELS_AUTOMATIC_DEFAULT_UPDATE = 11;

	const MODELS_COLUMN_MAP = 0;

	const MODELS_REVERSE_COLUMN_MAP = 1;

	/**
	 * Initialize the metadata for certain table
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string|null key
	 * @param string|null table
	 * @param string|null schema
	 */
	protected final function _initialize(<ModelInterface> model, var key, var table, var schema)
	{
		var strategy, className, metaData, data, modelMetadata, modelColumnMap,
			dependencyInjector, keyName, prefixKey;

		let strategy = null,
			className = get_class(model);

		if key !== null {

			let metaData = this->_metaData;
			if !isset metaData[key] {

				/**
				 * The meta-data is read from the adapter always
				 */
				let prefixKey = "meta-" . key,
					data = this->{"read"}(prefixKey);
				if data !== null {
					let this->_metaData[key] = data;
				} else {

					/**
					 * Check if there is a method 'metaData' in the model to retrieve meta-data from it
					 */
					if method_exists(model, "metaData") {
						let modelMetadata = model->{"metaData"}();
						if typeof modelMetadata != "array" {
							throw new Exception("Invalid meta-data for model " . className);
						}
					} else {

						/**
						 * Get the meta-data extraction strategy
						 * Get the meta-data
						 */
						let dependencyInjector = this->_dependencyInjector,
							strategy = this->getStrategy(),
							modelMetadata = strategy->getMetaData(model, dependencyInjector);
					}

					/**
					 * Store the meta-data locally
					 */
					let this->_metaData[key] = modelMetadata;

					/**
					 * Store the meta-data in the adapter
					 */
					this->{"write"}(prefixKey, modelMetadata);
				}

			}
		}

		/**
		 * Check for a column map, store in _columnMap in order and reversed order
		 */
		if !globals_get("orm.column_renaming") {
			return null;
		}

		let keyName = strtolower(className);
		if isset this->_columnMap[keyName] {
			return null;
		}

		/**
		 * Create the map key name
		 * Check if the meta-data is already in the adapter
		 */
		let prefixKey = "map-" . keyName,
			data = this->{"read"}(prefixKey);

		if data !== null {
			let this->_columnMap[keyName] = data;
			return null;
		}

		/**
		 * Get the meta-data extraction strategy
		 */
		if typeof strategy != "object" {
			let dependencyInjector = this->_dependencyInjector,
				strategy = this->getStrategy();
		}

		/**
		 * Get the meta-data
		 * Update the column map locally
		 */
		let modelColumnMap = strategy->getColumnMaps(model, dependencyInjector), this->_columnMap[keyName] = modelColumnMap;

		/**
		 * Write the data to the adapter
		 */
		this->{"write"}(prefixKey, modelColumnMap);
	}

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <\Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Set the meta-data extraction strategy
	 *
	 * @param Phalcon\Mvc\Model\MetaData\Strategy\Introspection strategy
	 */
	public function setStrategy(<StrategyInterface> strategy) -> void
	{
		let this->_strategy = strategy;
	}

	/**
	 * Return the strategy to obtain the meta-data
	 *
	 * @return Phalcon\Mvc\Model\MetaData\Strategy\StrategyInterface
	 */
	public function getStrategy() -> <StrategyInterface>
	{
		var strategy;
		let strategy = this->_strategy;
		if typeof strategy == "null" {
			let strategy = new Introspection(),
				this->_strategy = strategy;
		}
		return strategy;
	}

	/**
	 * Reads the complete meta-data for certain model
	 *
	 *<code>
	 *	print_r($metaData->readMetaData(new Robots());
	 *</code>
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public final function readMetaData(<ModelInterface> model)
	{
		var source, schema, key;

		let source = model->getSource(),
			schema = model->getSchema();

		/*
		 * Unique key for meta-data is created using class-name-schema-source
		 */
		let key = get_class_lower(model) . "-" . schema . source;
		if !isset this->_metaData[key] {
			this->_initialize(model, key, source, schema);
		}

		return this->_metaData[key];
	}

	/**
	 * Reads meta-data for certain model using a MODEL_* constant
	 *
	 *<code>
	 *	print_r($metaData->writeColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP, array('leName' => 'name')));
	 *</code>
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param int index
	 * @return mixed
	 */
	public final function readMetaDataIndex(<ModelInterface> model, int index)
	{
		var source, schema, key, metaData;

		let source = model->getSource(),
			schema = model->getSchema();

		/*
		 * Unique key for meta-data is created using class-name-schema-source
		 */
		let key = get_class_lower(model) . "-" . schema . source;

		if fetch metaData, this->_metaData[key][index] {
			return metaData;
		}

		this->_initialize(model, key, source, schema);
		return this->_metaData[key][index];
	}

	/**
	 * Writes meta-data for certain model using a MODEL_* constant
	 *
	 *<code>
	 *	print_r($metaData->writeColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP, array('leName' => 'name')));
	 *</code>
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param int index
	 * @param mixed data
	 */
	public final function writeMetaDataIndex(<ModelInterface> model, int index, var data) -> void
	{
		var source, schema, key;

		if typeof data != "array" && typeof data != "string" &&  typeof data != "boolean" {
			throw new Exception("Invalid data for index");
		}

		let source = model->getSource(),
			schema = model->getSchema();

		/*
		 * Unique key for meta-data is created using class-name-schema-table
		 */
		let key = get_class_lower(model) . "-" . schema . source;

		if !isset this->_metaData[key] {
			this->_initialize(model, key, source, schema);
		}

		let this->_metaData[key][index] = data;
	}

	/**
	 * Reads the ordered/reversed column map for certain model
	 *
	 *<code>
	 *	print_r($metaData->readColumnMap(new Robots()));
	 *</code>
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public final function readColumnMap(<ModelInterface> model)
	{
		var keyName, data;

		let keyName = get_class_lower(model);
		if !fetch data, this->_columnMap[keyName] {
			this->_initialize(model, null, null, null);
			let data = this->_columnMap[keyName];
		}

		return data;
	}

	/**
	 * Reads column-map information for certain model using a MODEL_* constant
	 *
	 *<code>
	 *	print_r($metaData->readColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP));
	 *</code>
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param int index
	 */
	public final function readColumnMapIndex(<ModelInterface> model, int index)
	{
		var keyName, columnMapModel;

		let keyName = get_class_lower(model);

		if !fetch columnMapModel, this->_columnMap[keyName] {
			this->_initialize(model, null, null, null);
			let columnMapModel = this->_columnMap[keyName];
		}

		return columnMapModel[index];
	}

	/**
	 * Returns table attributes names (fields)
	 *
	 *<code>
	 *	print_r($metaData->getAttributes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface $model
	 * @return 	array
	 */
	public function getAttributes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_ATTRIBUTES);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns an array of fields which are part of the primary key
	 *
	 *<code>
	 *	print_r($metaData->getPrimaryKeyAttributes(new Robots()));
	 *</code>
	 *
	 * @param	Phalcon\Mvc\ModelInterface model
	 * @return	array
	 */
	public function getPrimaryKeyAttributes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_PRIMARY_KEY);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns an array of fields which are not part of the primary key
	 *
	 *<code>
	 *	print_r($metaData->getNonPrimaryKeyAttributes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return 	array
	 */
	public function getNonPrimaryKeyAttributes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_NON_PRIMARY_KEY);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns an array of not null attributes
	 *
	 *<code>
	 *	print_r($metaData->getNotNullAttributes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getNotNullAttributes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_NOT_NULL);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns attributes and their data types
	 *
	 *<code>
	 *	print_r($metaData->getDataTypes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getDataTypes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_DATA_TYPES);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns attributes which types are numerical
	 *
	 *<code>
	 *	print_r($metaData->getDataTypesNumeric(new Robots()));
	 *</code>
	 *
     * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getDataTypesNumeric(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_DATA_TYPES_NUMERIC);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns the name of identity field (if one is present)
	 *
	 *<code>
	 *	print_r($metaData->getIdentityField(new Robots()));
	 *</code>
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @return string
	 */
	public function getIdentityField(<ModelInterface> model)
	{
		return this->readMetaDataIndex(model, self::MODELS_IDENTITY_COLUMN);
	}

	/**
	 * Returns attributes and their bind data types
	 *
	 *<code>
	 *	print_r($metaData->getBindTypes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getBindTypes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_DATA_TYPES_BIND);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns attributes that must be ignored from the INSERT SQL generation
	 *
	 *<code>
	 *	print_r($metaData->getAutomaticCreateAttributes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getAutomaticCreateAttributes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_AUTOMATIC_DEFAULT_INSERT);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns attributes that must be ignored from the UPDATE SQL generation
	 *
	 *<code>
	 *	print_r($metaData->getAutomaticUpdateAttributes(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getAutomaticUpdateAttributes(<ModelInterface> model)
	{
		var data;
		let data = this->readMetaDataIndex(model, self::MODELS_AUTOMATIC_DEFAULT_UPDATE);
		if typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Set the attributes that must be ignored from the INSERT SQL generation
	 *
	 *<code>
	 *	$metaData->setAutomaticCreateAttributes(new Robots(), array('created_at' => true));
	 *</code>
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @param  array attributes
	 */
	public function setAutomaticCreateAttributes(<ModelInterface> model, attributes) -> void
	{
		this->writeMetaDataIndex(model, self::MODELS_AUTOMATIC_DEFAULT_INSERT, attributes);
	}

	/**
	 * Set the attributes that must be ignored from the UPDATE SQL generation
	 *
	 *<code>
	 *	$metaData->setAutomaticUpdateAttributes(new Robots(), array('modified_at' => true));
	 *</code>
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @param  array attributes
	 */
	public function setAutomaticUpdateAttributes(<ModelInterface> model, attributes) -> void
	{
		this->writeMetaDataIndex(model, self::MODELS_AUTOMATIC_DEFAULT_UPDATE, attributes);
	}

	/**
	 * Returns the column map if any
	 *
	 *<code>
	 *	print_r($metaData->getColumnMap(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getColumnMap(<ModelInterface> model) -> array
	{
		var data;

		let data = this->readColumnMapIndex(model, self::MODELS_COLUMN_MAP);
		if typeof data != "null" && typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Returns the reverse column map if any
	 *
	 *<code>
	 *	print_r($metaData->getReverseColumnMap(new Robots()));
	 *</code>
	 *
     * @param	Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getReverseColumnMap(<ModelInterface> model) -> array
	{
		var data;

		let data = this->readColumnMapIndex(model, self::MODELS_REVERSE_COLUMN_MAP);
		if typeof data != "null" && typeof data != "array" {
			throw new Exception("The meta-data is invalid or is corrupt");
		}
		return data;
	}

	/**
	 * Check if a model has certain attribute
	 *
	 *<code>
	 *	var_dump($metaData->hasAttribute(new Robots(), 'name'));
	 *</code>
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string attribute
	 * @return boolean
	 */
	public function hasAttribute(<ModelInterface> model, string attribute) -> boolean
	{
		var columnMap;

		let columnMap = this->getReverseColumnMap(model);
		if typeof columnMap == "array" {
			return isset columnMap[attribute];
		} else {
			return isset this->readMetaData(model)[self::MODELS_DATA_TYPES][attribute];
		}

		return false;
	}

	/**
	 * Checks if the internal meta-data container is empty
	 *
	 *<code>
	 *	var_dump($metaData->isEmpty());
	 *</code>
	 *
	 * @return boolean
	 */
	public function isEmpty() -> boolean
	{
		return count(this->_metaData) == 0;
	}

	/**
	 * Resets internal meta-data in order to regenerate it
	 *
	 *<code>
	 *	$metaData->reset();
	 *</code>
	 */
	public function reset() -> void
	{
		let this->_metaData = [],
			this->_columnMap = [];
	}

}

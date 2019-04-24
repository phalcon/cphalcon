
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\DiInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
use Phalcon\Mvc\Model\MetaData\StrategyInterface;
use Phalcon\Storage\Adapter\AdapterInterface as StorageAdapterInterface;

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
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Memory();
 *
 * $attributes = $metaData->getAttributes(
 *     new Robots()
 * );
 *
 * print_r($attributes);
 * </code>
 */
abstract class MetaData implements InjectionAwareInterface, MetaDataInterface
{
    const MODELS_ATTRIBUTES = 0;
    const MODELS_AUTOMATIC_DEFAULT_INSERT = 10;
    const MODELS_AUTOMATIC_DEFAULT_UPDATE = 11;
    const MODELS_COLUMN_MAP = 0;
    const MODELS_DATE_AT = 6;
    const MODELS_DATE_IN = 7;
    const MODELS_DATA_TYPES = 4;
    const MODELS_DATA_TYPES_BIND = 9;
    const MODELS_DATA_TYPES_NUMERIC = 5;
    const MODELS_DEFAULT_VALUES = 12;
    const MODELS_EMPTY_STRING_VALUES = 13;
    const MODELS_IDENTITY_COLUMN = 8;
    const MODELS_NON_PRIMARY_KEY = 2;
    const MODELS_NOT_NULL = 3;
    const MODELS_PRIMARY_KEY = 1;
    const MODELS_REVERSE_COLUMN_MAP = 1;

    /**
     * @var StorageAdapterInterface
     */
    protected adapter;

    protected columnMap;

    protected container;

    protected metaData;

    protected strategy;

    /**
     * Returns table attributes names (fields)
     *
     *<code>
     * print_r(
     *     $metaData->getAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_ATTRIBUTES);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns attributes that must be ignored from the INSERT SQL generation
     *
     *<code>
     * print_r(
     *     $metaData->getAutomaticCreateAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getAutomaticCreateAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_AUTOMATIC_DEFAULT_INSERT);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns attributes that must be ignored from the UPDATE SQL generation
     *
     *<code>
     * print_r(
     *     $metaData->getAutomaticUpdateAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getAutomaticUpdateAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_AUTOMATIC_DEFAULT_UPDATE);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns attributes and their bind data types
     *
     *<code>
     * print_r(
     *     $metaData->getBindTypes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getBindTypes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_DATA_TYPES_BIND);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns the column map if any
     *
     *<code>
     * print_r(
     *     $metaData->getColumnMap(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getColumnMap(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readColumnMapIndex(model, self::MODELS_COLUMN_MAP);

        if unlikely (data !== null && typeof data != "array") {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns attributes (which have default values) and their default values
     *
     *<code>
     * print_r(
     *     $metaData->getDefaultValues(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getDefaultValues(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_DEFAULT_VALUES);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns attributes and their data types
     *
     *<code>
     * print_r(
     *     $metaData->getDataTypes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getDataTypes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_DATA_TYPES);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns attributes which types are numerical
     *
     *<code>
     * print_r(
     *     $metaData->getDataTypesNumeric(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getDataTypesNumeric(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_DATA_TYPES_NUMERIC);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns attributes allow empty strings
     *
     *<code>
     * print_r(
     *     $metaData->getEmptyStringAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getEmptyStringAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_EMPTY_STRING_VALUES);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns the name of identity field (if one is present)
     *
     *<code>
     * print_r(
     *     $metaData->getIdentityField(
     *         new Robots()
     *     )
     * );
     *</code>
     *
     * @param  Phalcon\Mvc\ModelInterface model
     * @return string
     */
    public function getIdentityField(<ModelInterface> model) -> string
    {
        return this->readMetaDataIndex(model, self::MODELS_IDENTITY_COLUMN);
    }

    /**
     * Returns an array of fields which are not part of the primary key
     *
     *<code>
     * print_r(
     *     $metaData->getNonPrimaryKeyAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getNonPrimaryKeyAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_NON_PRIMARY_KEY);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns an array of not null attributes
     *
     *<code>
     * print_r(
     *     $metaData->getNotNullAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getNotNullAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_NOT_NULL);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns an array of fields which are part of the primary key
     *
     *<code>
     * print_r(
     *     $metaData->getPrimaryKeyAttributes(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getPrimaryKeyAttributes(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readMetaDataIndex(model, self::MODELS_PRIMARY_KEY);

        if unlikely typeof data != "array" {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Returns the reverse column map if any
     *
     *<code>
     * print_r(
     *     $metaData->getReverseColumnMap(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    public function getReverseColumnMap(<ModelInterface> model) -> array
    {
        var data;

        let data = this->readColumnMapIndex(model, self::MODELS_REVERSE_COLUMN_MAP);

        if unlikely (data !== null && typeof data != "array") {
            throw new Exception("The meta-data is invalid or is corrupt");
        }

        return data;
    }

    /**
     * Return the strategy to obtain the meta-data
     */
    public function getStrategy() -> <StrategyInterface>
    {
        if this->strategy === null {
            let this->strategy = new Introspection();
        }

        return this->strategy;
    }

    /**
     * Check if a model has certain attribute
     *
     *<code>
     * var_dump(
     *     $metaData->hasAttribute(
     *         new Robots(),
     *         "name"
     *     )
     * );
     *</code>
     */
    public function hasAttribute(<ModelInterface> model, string attribute) -> bool
    {
        var columnMap;

        let columnMap = this->getReverseColumnMap(model);

        if typeof columnMap == "array" {
            return isset columnMap[attribute];
        }

        return isset this->readMetaData(model)[self::MODELS_DATA_TYPES][attribute];
    }

    /**
     * Checks if the internal meta-data container is empty
     *
     *<code>
     * var_dump(
     *     $metaData->isEmpty()
     * );
     *</code>
     */
    public function isEmpty() -> bool
    {
        return count(this->metaData) == 0;
    }

    /**
     * Reads metadata from the adapter
     */
    public function read(string! key) -> array | null
    {
        return this->adapter->get(key);
    }

    /**
     * Reads the ordered/reversed column map for certain model
     *
     *<code>
     * print_r(
     *     $metaData->readColumnMap(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    final public function readColumnMap(<ModelInterface> model) -> array | null
    {
        var keyName, data;

        if !globals_get("orm.column_renaming") {
            return null;
        }

        let keyName = get_class_lower(model);

        if !fetch data, this->columnMap[keyName] {
            this->initialize(model, null, null, null);

            let data = this->columnMap[keyName];
        }

        return data;
    }

    /**
     * Reads column-map information for certain model using a MODEL_* constant
     *
     *<code>
     * print_r(
     *     $metaData->readColumnMapIndex(
     *         new Robots(),
     *         MetaData::MODELS_REVERSE_COLUMN_MAP
     *     )
     * );
     *</code>
     */
    final public function readColumnMapIndex(<ModelInterface> model, int index)
    {
        var keyName, columnMapModel, map;

        if !globals_get("orm.column_renaming") {
            return null;
        }

        let keyName = get_class_lower(model);

        if !fetch columnMapModel, this->columnMap[keyName] {
            this->initialize(model, null, null, null);

            let columnMapModel = this->columnMap[keyName];
        }

        fetch map, columnMapModel[index];

        return map;
    }

    /**
     * Reads the complete meta-data for certain model
     *
     *<code>
     * print_r(
     *     $metaData->readMetaData(
     *         new Robots()
     *     )
     * );
     *</code>
     */
    final public function readMetaData(<ModelInterface> model) -> array
    {
        var source, schema;
        string key;

        let source = model->getSource(),
            schema = model->getSchema();

        /*
         * Unique key for meta-data is created using class-name-schema-source
         */
        let key = get_class_lower(model) . "-" . schema . source;

        if !isset this->metaData[key] {
            this->initialize(model, key, source, schema);
        }

        return this->metaData[key];
    }

    /**
     * Reads meta-data for certain model
     *
     *<code>
     * print_r(
     *     $metaData->readMetaDataIndex(
     *         new Robots(),
     *         0
     *     )
     * );
     *</code>
     */
    final public function readMetaDataIndex(<ModelInterface> model, int index)
    {
        var source, schema;
        string key;

        let source = model->getSource(),
            schema = model->getSchema();

        /*
         * Unique key for meta-data is created using class-name-schema-source
         */
        let key = get_class_lower(model) . "-" . schema . source;

        if !isset this->metaData[key][index] {
            this->initialize(model, key, source, schema);
        }

        return this->metaData[key][index];
    }

    /**
     * Resets internal meta-data in order to regenerate it
     *
     *<code>
     * $metaData->reset();
     *</code>
     */
    public function reset() -> void
    {
        let this->metaData = [],
            this->columnMap = [];
    }

    /**
     * Set the attributes that must be ignored from the INSERT SQL generation
     *
     *<code>
     * $metaData->setAutomaticCreateAttributes(
     *     new Robots(),
     *     [
     *         "created_at" => true,
     *     ]
     * );
     *</code>
     */
    public function setAutomaticCreateAttributes(<ModelInterface> model, array attributes) -> void
    {
        this->writeMetaDataIndex(
            model,
            self::MODELS_AUTOMATIC_DEFAULT_INSERT,
            attributes
        );
    }

    /**
     * Set the attributes that must be ignored from the UPDATE SQL generation
     *
     *<code>
     * $metaData->setAutomaticUpdateAttributes(
     *     new Robots(),
     *     [
     *         "modified_at" => true,
     *     ]
     * );
     *</code>
     */
    public function setAutomaticUpdateAttributes(<ModelInterface> model, array attributes) -> void
    {
        this->writeMetaDataIndex(
            model,
            self::MODELS_AUTOMATIC_DEFAULT_UPDATE,
            attributes
        );
    }

    /**
     * Set the attributes that allow empty string values
     *
     *<code>
     * $metaData->setEmptyStringAttributes(
     *     new Robots(),
     *     [
     *         "name" => true,
     *     ]
     * );
     *</code>
     */
    public function setEmptyStringAttributes(<ModelInterface> model, array attributes) -> void
    {
        this->writeMetaDataIndex(
            model,
            self::MODELS_EMPTY_STRING_VALUES,
            attributes
        );
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Set the meta-data extraction strategy
     */
    public function setStrategy(<StrategyInterface> strategy) -> void
    {
        let this->strategy = strategy;
    }

    /**
     * Writes the metadata to adapter
     */
    public function write(string! key, array data) -> void
    {
        this->adapter->set(key, data);
    }

    /**
     * Writes meta-data for certain model using a MODEL_* constant
     *
     *<code>
     * print_r(
     *     $metaData->writeColumnMapIndex(
     *         new Robots(),
     *         MetaData::MODELS_REVERSE_COLUMN_MAP,
     *         [
     *             "leName" => "name",
     *         ]
     *     )
     * );
     *</code>
     */
    final public function writeMetaDataIndex(<ModelInterface> model, int index, var data) -> void
    {
        var source, schema;
        string key;

        if unlikely (typeof data != "array" && typeof data != "string" && typeof data != "boolean") {
            throw new Exception("Invalid data for index");
        }

        let source = model->getSource(),
            schema = model->getSchema();

        /*
         * Unique key for meta-data is created using class-name-schema-table
         */
        let key = get_class_lower(model) . "-" . schema . source;

        if !isset this->metaData[key] {
            this->initialize(model, key, source, schema);
        }

        let this->metaData[key][index] = data;
    }

    /**
     * Initialize the metadata for certain table
     */
    final protected function initialize(<ModelInterface> model, var key, var table, var schema)
    {
        var strategy, className, metaData, data, modelMetadata, modelColumnMap,
            container, keyName;
        string prefixKey;

        let strategy = null,
            className = get_class(model);

        if key !== null {
            let metaData = this->metaData;

            if !isset metaData[key] {
                /**
                 * The meta-data is read from the adapter always if not available in _metaData property
                 */
                let prefixKey = "meta-" . key,
                    data = this->{"read"}(prefixKey);

                if data !== null {
                    let this->metaData[key] = data;
                } else {
                    /**
                     * Check if there is a method 'metaData' in the model to retrieve meta-data from it
                     */
                    if method_exists(model, "metaData") {
                        let modelMetadata = model->{"metaData"}();

                        if unlikely typeof modelMetadata != "array" {
                            throw new Exception(
                                "Invalid meta-data for model " . className
                            );
                        }
                    } else {
                        /**
                         * Get the meta-data extraction strategy
                         */
                        let container = this->container,
                            strategy = this->getStrategy(),
                            modelMetadata = strategy->getMetaData(model, container);
                    }

                    /**
                     * Store the meta-data locally
                     */
                    let this->metaData[key] = modelMetadata;

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

        if isset this->columnMap[keyName] {
            return null;
        }

        /**
         * Create the map key name
         * Check if the meta-data is already in the adapter
         */
        let prefixKey = "map-" . keyName,
            data = this->{"read"}(prefixKey);

        if data !== null {
            let this->columnMap[keyName] = data;

            return null;
        }

        /**
         * Get the meta-data extraction strategy
         */
        if typeof strategy != "object" {
            let container = this->container,
                strategy = this->getStrategy();
        }

        /**
         * Get the meta-data
         * Update the column map locally
         */
        let modelColumnMap = strategy->getColumnMaps(model, container),
            this->columnMap[keyName] = modelColumnMap;

        /**
         * Write the data to the adapter
         */
        this->{"write"}(prefixKey, modelColumnMap);
    }
}

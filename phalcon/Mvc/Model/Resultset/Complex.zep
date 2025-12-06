
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Resultset;

use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Db\ResultInterface;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\Row;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Storage\Serializer\SerializerInterface;
use stdClass;

/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 *
 * @template TKey of int
 * @template TValue of mixed
 */
class Complex extends Resultset
{
    /**
     * @var array
     */
    protected columnTypes;

    /**
     * Unserialised result-set hydrated all rows already. unserialise() sets
     * disableHydration to true
     *
     * @var bool
     */
    protected disableHydration = false;

    /**
     * Phalcon\Mvc\Model\Resultset\Complex constructor
     *
     * @param array                $columnTypes
     * @param ResultInterface|null $result
     * @param mixed|null           $cache
     */
    public function __construct(
        var columnTypes,
        <ResultInterface> result = null,
        var cache = null
    )
    {
        /**
         * Column types, tell the resultset how to build the result
         */
        let this->columnTypes = columnTypes;

        parent::__construct(result, cache);
    }

    /**
     * Returns current row in the resultset
     */
    final public function current() -> mixed
    {
        var row, hydrateMode, eager, dirtyState, alias, activeRow, type, column,
            columnValue, value, attribute, source, attributes, columnMap,
            rowModel, keepSnapshots, sqlAlias, modelName;

        let activeRow = this->activeRow;

        if activeRow !== null {
            return activeRow;
        }

        /**
         * Current row is set by seek() operations
         */
        let row = this->row;

        /**
         * Resultset was unserialized, we do not need to hydrate
         */
        if this->disableHydration {
            let this->activeRow = row;

            return row;
        }

        /**
         * Valid records are arrays
         */
        if typeof row != "array" {
            let this->activeRow = false;

            return false;
        }

        /**
         * Get current hydration mode
         */
        let hydrateMode = this->hydrateMode;

        /**
         * Each row in a complex result is a Phalcon\Mvc\Model\Row instance
         */
        switch hydrateMode {
            case Resultset::HYDRATE_RECORDS:
                let activeRow = new Row();
                break;

            case Resultset::HYDRATE_ARRAYS:
                let activeRow = [];
                break;

            case Resultset::HYDRATE_OBJECTS:
            default:
                let activeRow = new stdClass();
                break;
        }

        /**
         * Set records as dirty state PERSISTENT by default
         */
        let dirtyState = 0;

        /**
         * Create every record according to the column types
         */
        for alias, column in this->columnTypes {
            if unlikely typeof column != "array" {
                throw new Exception("Column type is corrupt");
            }

            let type = column["type"];

            if type == "object" {
                /**
                 * Object columns are assigned column by column
                 */
                let source = column["column"],
                    attributes = column["attributes"],
                    columnMap = column["columnMap"];

                /**
                 * Assign the values from the _source_attribute notation to its real column name
                 */
                let rowModel = [];

                for attribute in attributes {
                    /**
                     * Columns are supposed to be in the form _table_field
                     */
                    let columnValue = row["_" . source . "_". attribute],
                        rowModel[attribute] = columnValue;
                }

                /**
                 * Generate the column value according to the hydration type
                 */
                switch hydrateMode {
                    case Resultset::HYDRATE_RECORDS:
                        // Check if the resultset must keep snapshots
                        if !fetch keepSnapshots, column["keepSnapshots"] {
                            let keepSnapshots = false;
                        }

                        if globals_get("orm.late_state_binding") {
                            if column["instance"] instanceof Model {
                                let modelName = get_class(column["instance"]);
                            } else {
                                let modelName = "Phalcon\\Mvc\\Model";
                            }

                            let value = {modelName}::cloneResultMap(
                                column["instance"],
                                rowModel,
                                columnMap,
                                dirtyState,
                                keepSnapshots
                            );
                        } else {
                            /**
                             * Get the base instance. Assign the values to the
                             * attributes using a column map
                             */
                            let value = Model::cloneResultMap(
                                column["instance"],
                                rowModel,
                                columnMap,
                                dirtyState,
                                keepSnapshots
                            );
                        }

                        break;

                    default:
                        // Other kinds of hydration
                        let value = Model::cloneResultMapHydrate(
                            rowModel,
                            columnMap,
                            hydrateMode
                        );

                        break;
                }

                /**
                 * The complete object is assigned to an attribute with the name of the alias or the model name
                 */
                let attribute = column["balias"];
            } else {
                /**
                 * Scalar columns are simply assigned to the result object
                 */
                if fetch sqlAlias, column["sqlAlias"] {
                    let value = row[sqlAlias];
                } else {
                    fetch value, row[alias];
                }

                /**
                 * If a "balias" is defined is not an unnamed scalar
                 */
                if isset column["balias"] {
                    let attribute = alias;
                } else {
                    let attribute = str_replace("_", "", alias);
                }
            }

            if !fetch eager, column["eager"] {
                /**
                 * Assign the instance according to the hydration type
                 */
                switch hydrateMode {

                    case Resultset::HYDRATE_ARRAYS:
                        let activeRow[attribute] = value;
                        break;

                    default:
                        let activeRow->{attribute} = value;
                        break;
                }
            }
        }

        /**
         * Store the generated row in this_ptr->activeRow to be retrieved by 'current'
         */
        let this->activeRow = activeRow;

        return activeRow;
    }

    /**
     * Returns a complete resultset as an array, if the resultset has a big
     * number of rows it could consume more memory than currently it does.
     */
    public function toArray() -> array
    {
        var current;
        array records;

        let records = [];

        this->rewind();

        while this->valid() {
            let current = this->current();
            let records[] = current;

            this->next();
        }

        return records;
    }

    /**
     * Serializing a resultset will dump all related rows into a big array,
     * serialize it and return the resulting string
     */
    public function serialize() -> string
    {
        var container, serializer;
        array data;

        let container = Di::getDefault();
        if container === null {
            throw new Exception(
                "The dependency injector container is not valid"
            );
        }

        let data = [
            "cache"       : this->cache,
            "rows"        : this->toArray(),
            "columnTypes" : this->columnTypes,
            "hydrateMode" : this->hydrateMode
        ];

        if container->has("serializer") {
            let serializer = <SerializerInterface> container->getShared("serializer");
            serializer->setData(data);

            return serializer->serialize();
        }

        return serialize(data);
    }

    /**
     * Unserializing a resultset will allow to only works on the rows present in the saved state
     */
    public function unserialize(var data) -> void
    {
        var resultset, container, serializer;

        /**
         * Rows are already hydrated
         */
        let this->disableHydration = true;

        let container = Di::getDefault();
        if container === null {
            throw new Exception(
                "The dependency injector container is not valid"
            );
        }

        if container->has("serializer") {
            let serializer = <SerializerInterface> container->getShared("serializer");

            serializer->unserialize(data);
            let resultset = serializer->getData();
        } else {
            let resultset = unserialize(data);
        }

        if unlikely typeof resultset != "array" {
            throw new Exception("Invalid serialization data");
        }

        let this->rows        = resultset["rows"],
            this->count       = count(resultset["rows"]),
            this->cache       = resultset["cache"],
            this->columnTypes = resultset["columnTypes"],
            this->hydrateMode = resultset["hydrateMode"];
    }

    public function __serialize() -> array
    {
        var records, cache, columnTypes, hydrateMode;

        /**
         * Obtain the records as an array
         */
        let records = this->toArray();

        let cache       = this->cache,
            columnTypes = this->columnTypes,
            hydrateMode = this->hydrateMode;

        return [
           "cache"       : cache,
           "rows"        : records,
           "columnTypes" : columnTypes,
           "hydrateMode" : hydrateMode
        ];
    }

    public function __unserialize(array data) -> void
    {
        /**
         * Rows are already hydrated
         */
        let this->disableHydration = true;

        let this->rows        = data["rows"],
            this->count       = count(data["rows"]),
            this->cache       = data["cache"],
            this->columnTypes = data["columnTypes"],
            this->hydrateMode = data["hydrateMode"];
    }
}

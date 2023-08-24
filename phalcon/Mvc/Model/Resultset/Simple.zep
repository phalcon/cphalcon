
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
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Eager\Loader;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Exceptions\InvalidContainer;
use Phalcon\Mvc\Model\Exceptions\InvalidSerializationData;
use Phalcon\Mvc\Model\Exceptions\ResultsetColumnNotInMap;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Row;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Storage\Serializer\SerializerInterface;
use Phalcon\Support\Settings;

/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 *
 * @template TKey of int
 * @template TValue of \Phalcon\Mvc\ModelInterface
 */
class Simple extends Resultset
{
    /**
     * @var array|string
     */
    protected columnMap;

    /**
     * @var array|null
     */
    protected eagerMap = null;

    /**
     * @var ModelInterface|Row
     */
    protected model;

    /**
     * @var bool
     */
    protected keepSnapshots = false;

    /**
     * Phalcon\Mvc\Model\Resultset\Simple constructor
     *
     * @param array                             columnMap
     * @param ModelInterface|Row                model
     * @param \Phalcon\Db\ResultInterface|false result
     * @param mixed|null                        cache
     * @param bool keepSnapshots                false
     */
    public function __construct(
        var columnMap,
        var model,
        result,
        var cache = null,
        bool keepSnapshots = false,
        manager = null,
        metaData = null
    )
    {
        let this->model     = model,
            this->columnMap = columnMap;
        /**
         * Set if the returned resultset must keep the record snapshots
         */
        let this->keepSnapshots = keepSnapshots;

        parent::__construct(result, cache, manager, metaData);
    }

    public function __serialize() -> array
    {
        return [
            "model"         : this->model,
            "cache"         : this->cache,
            "rows"          : this->toArray(false),
            "columnMap"     : this->columnMap,
            "hydrateMode"   : this->hydrateMode,
            "keepSnapshots" : this->keepSnapshots
        ];
    }

    public function __unserialize(array data) -> void
    {
        var keepSnapshots;

        let this->model       = data["model"],
            this->rows        = data["rows"],
            this->count       = count(data["rows"]),
            this->cache       = data["cache"],
            this->columnMap   = data["columnMap"],
            this->hydrateMode = data["hydrateMode"];

        if fetch keepSnapshots, data["keepSnapshots"] {
            let this->keepSnapshots = keepSnapshots;
        }
    }

    /**
     * Returns current row in the resultset
     * @return TValue
     */
    final public function current() -> <ModelInterface> | <Row> | null
    {
        var row, hydrateMode, columnMap, activeRow, modelName, uuid;

        let activeRow = this->activeRow;

        if activeRow !== null {
            return activeRow;
        }

        /**
         * Current row is set by seek() operations
         */
        let row = this->row;

        /**
         * Valid records are arrays
         */
        if typeof row != "array" {
            let this->activeRow = false;

            return null;
        }

        /**
         * Get current hydration mode
         */
        let hydrateMode = this->hydrateMode;

        /**
         * Get the resultset column map
         */
        let columnMap = this->columnMap;

        /**
         * Hydrate based on the current hydration
         */
        switch hydrateMode {
            case Resultset::HYDRATE_RECORDS:
                /**
                 * checks for session cache and returns already in memory models
                 */
                 if true === globals_get("orm.session_cache") {
                    let uuid = this->metaData->getModelUUID(this->model, row);
                    let activeRow = this->sessionCache->get(uuid);
                    if null !== activeRow {
                        let this->activeRow = activeRow;
                        return activeRow;
                    }
                }

                /**
                 * Set records as dirty state PERSISTENT by default
                 * Performs the standard hydration based on objects
                 */
                if Settings::get("orm.late_state_binding") {
                    if this->model instanceof Model {
                        let modelName = get_class(this->model);
                    } else {
                        let modelName = Model::class;
                    }

                    let activeRow = {modelName}::cloneResultMap(
                        this->model,
                        row,
                        columnMap,
                        Model::DIRTY_STATE_PERSISTENT,
                        this->keepSnapshots
                    );
                } else {
                    let activeRow = Model::cloneResultMap(
                        this->model,
                        row,
                        columnMap,
                        Model::DIRTY_STATE_PERSISTENT,
                        this->keepSnapshots
                    );
                }

                if this->eagerMap !== null {
                    Loader::apply(activeRow, this->eagerMap);
                }

                if true === Settings::get("orm.session_cache") {
                    this->sessionCache->set(uuid, activeRow);
                }
                break;

            default:
                /**
                 * Other kinds of hydrations. Eagerly loaded relations are
                 * deliberately not applied here: arrays and standard objects
                 * have neither a relation cache nor writeAttribute().
                 */
                let activeRow = Model::cloneResultMapHydrate(
                    row,
                    columnMap,
                    hydrateMode
                );

                break;
        }

        let this->activeRow = activeRow;

        return activeRow;
    }

    /**
     * Serializing a resultset will dump all related rows into a big array
     */
    public function serialize() -> string
    {
        var container, serializer;
        array data;

        let container = Di::getDefault();
        if container === null {
            throw new InvalidContainer();
        }

        let data = [
            "model"         : this->model,
            "cache"         : this->cache,
            "rows"          : this->toArray(false),
            "columnMap"     : this->columnMap,
            "hydrateMode"   : this->hydrateMode,
            "keepSnapshots" : this->keepSnapshots
        ];

        if container->has("serializer") {
            let serializer = <SerializerInterface> container->getShared("serializer");
            serializer->setData(data);

            return serializer->serialize();
        }

        /**
         * Serialize the cache using the serialize function
         */
        return serialize(data);
    }

    /**
     * Attaches a pre-loaded relation map, applied to every record as it is
     * hydrated.
     *
     * Records in a resultset are transient - seek() clears activeRow on every
     * move and current() re-hydrates from the raw row - so hydration is the
     * only durable point at which relations can be stamped.
     */
    public function setEagerMap(array eagerMap) -> void
    {
        let this->eagerMap = eagerMap;
    }

    /**
     * Builds a new resultset of the same concrete class over the rows at the
     * given positions, preserving the column map, record prototype and
     * snapshot behavior of this resultset.
     *
     * @param array $indexes zero-based row positions, in the desired order
     */
    public function sliceRows(array indexes) -> <Simple>
    {
        var index, resultset, row;
        array sliced;

        this->materialize();

        let sliced = [];

        for index in indexes {
            if fetch row, this->rows[index] {
                let sliced[] = row;
            }
        }

        let resultset = <Simple> create_instance_params(
            get_class(this),
            [
                this->columnMap,
                this->model,
                false,
                null,
                this->keepSnapshots
            ]
        );

        let resultset->rows  = sliced,
            resultset->count = count(sliced);

        return resultset;
    }

    /**
     * Returns a complete resultset as an array, if the resultset has a big
     * number of rows it could consume more memory than currently it does.
     * Export the resultset to an array couldn't be faster with a large number
     * of records
     */
    public function toArray(bool renameColumns = true) -> array
    {
        var records, record, renamedKey, key, value, columnMap;
        array renamedRecords, renamed;

        /**
         * If the rows are not present, fetch them from the database and keep
         * them in memory for further operations
         */
        this->materialize();

        let records = this->rows;

        /**
         * We need to rename the whole set here, this could be slow
         *
         * Only rename when it is Model
         */
        if renameColumns && !(this->model instanceof Row) {
            /**
             * Get the resultset column map
             */
            let columnMap = this->columnMap;

            if typeof columnMap != "array" {
                return records;
            }

            let renamedRecords = [];

            if typeof records == "array" {
                for record in records {
                    let renamed = [];

                    for key, value in record {
                        if (typeof key === "string") {
                            /**
                             * Check if the key is part of the column map
                             */
                            if unlikely !fetch renamedKey, columnMap[key] {
                                throw new ResultsetColumnNotInMap(key);
                            }

                            if typeof renamedKey == "array" {
                                if unlikely !fetch renamedKey, renamedKey[0] {
                                    throw new ResultsetColumnNotInMap(key);
                                }
                            }

                            let renamed[renamedKey] = value;
                        }
                    }

                    /**
                     * Append the renamed records to the main array
                     */
                    let renamedRecords[] = renamed;
                }
            }

            return renamedRecords;
        }

        return records;
    }

    /**
     * Unserializing a resultset will allow to only works on the rows present in
     * the saved state
     */
    public function unserialize(var data) -> void
    {
        var resultset, keepSnapshots, container, serializer;

        let container = Di::getDefault();
        if container === null {
            throw new InvalidContainer();
        }

        if container->has("serializer") {
            let serializer = <SerializerInterface> container->getShared("serializer");

            serializer->unserialize(data);
            let resultset = serializer->getData();
        } else {
            let resultset = unserialize(data);
        }

        if unlikely typeof resultset !== "array" {
            throw new InvalidSerializationData();
        }

        let this->model       = resultset["model"],
            this->rows        = resultset["rows"],
            this->count       = count(resultset["rows"]),
            this->cache       = resultset["cache"],
            this->columnMap   = resultset["columnMap"],
            this->hydrateMode = resultset["hydrateMode"];

        if fetch keepSnapshots, resultset["keepSnapshots"] {
            let this->keepSnapshots = keepSnapshots;
        }
    }
}

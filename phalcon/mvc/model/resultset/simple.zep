
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Resultset;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Cache\BackendInterface;
use Phalcon\DiInterface;
use Phalcon\Di;
use Phalcon\Cache\FrontendInterface;


/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 */
class Simple extends Resultset
{

    protected _model;

    protected _columnMap;

    protected _keepSnapshots = false;

    /**
     * Phalcon\Mvc\Model\Resultset\Simple constructor
     *
     * @param array columnMap
     * @param \Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
     */
    public function __construct(var columnMap, var model, result, <BackendInterface> cache = null, bool keepSnapshots = null)
    {
        let this->_model = model,
            this->_columnMap = columnMap;

        /**
         * Set if the returned resultset must keep the record snapshots
         */
        let this->_keepSnapshots = keepSnapshots;

        parent::__construct(result, cache);
    }

    /**
     * Returns current row in the resultset
     */
    public final function current() -> <ModelInterface> | bool
    {
        var row, hydrateMode, columnMap, activeRow, modelName;

        let activeRow = this->_activeRow;
        if activeRow !== null {
            return activeRow;
        }

        /**
         * Current row is set by seek() operations
         */
        let row = this->_row;

        /**
         * Valid records are arrays
         */
        if typeof row != "array" {
            let this->_activeRow = false;
            return false;
        }

        /**
         * Get current hydration mode
         */
        let hydrateMode = this->_hydrateMode;

        /**
         * Get the resultset column map
         */
        let columnMap = this->_columnMap;

        /**
         * Hydrate based on the current hydration
         */
        switch hydrateMode {

            case Resultset::HYDRATE_RECORDS:

                /**
                 * Set records as dirty state PERSISTENT by default
                 * Performs the standard hydration based on objects
                 */
                if globals_get("orm.late_state_binding") {

                    if this->_model instanceof \Phalcon\Mvc\Model {
                        let modelName = get_class(this->_model);
                    } else {
                        let modelName = "Phalcon\\Mvc\\Model";
                    }

                    let activeRow = {modelName}::cloneResultMap(
                        this->_model,
                        row,
                        columnMap,
                        Model::DIRTY_STATE_PERSISTENT,
                        this->_keepSnapshots
                    );
                } else {
                    let activeRow = Model::cloneResultMap(
                        this->_model,
                        row,
                        columnMap,
                        Model::DIRTY_STATE_PERSISTENT,
                        this->_keepSnapshots
                    );
                }
                break;

            default:
                /**
                 * Other kinds of hydrations
                 */
                let activeRow = Model::cloneResultMapHydrate(row, columnMap, hydrateMode);
                break;
        }

        let this->_activeRow = activeRow;
        return activeRow;
    }

    /**
     * Returns a complete resultset as an array, if the resultset has a big number of rows
     * it could consume more memory than currently it does. Export the resultset to an array
     * couldn't be faster with a large number of records
     */
    public function toArray(bool renameColumns = true) -> array
    {
        var result, records, record, renamed, renamedKey,
            key, value, renamedRecords, columnMap;

        /**
         * If _rows is not present, fetchAll from database
         * and keep them in memory for further operations
         */
        let records = this->_rows;
        if typeof records != "array" {
            let result = this->_result;
            if this->_row !== null {
                // re-execute query if required and fetchAll rows
                result->execute();
            }
            let records = result->fetchAll();
            let this->_row = null;
            let this->_rows = records; // keep result-set in memory
        }

        /**
         * We need to rename the whole set here, this could be slow
         */
        if renameColumns {

            /**
             * Get the resultset column map
             */
            let columnMap = this->_columnMap;
            if typeof columnMap != "array" {
                return records;
            }

            let renamedRecords = [];
            if typeof records == "array" {

                for record in records {

                    let renamed = [];
                    for key, value in record {

                        /**
                         * Check if the key is part of the column map
                         */
                        if !fetch renamedKey, columnMap[key] {
                            throw new Exception("Column '" . key . "' is not part of the column map");
                        }

                        if typeof renamedKey == "array" {

                            if !fetch renamedKey, renamedKey[0] {
                                throw new Exception("Column '" . key . "' is not part of the column map");
                            }
                        }

                        let renamed[renamedKey] = value;
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
     * Serializing a resultset will dump all related rows into a big array
     */
    public function serialize() -> string
    {
        var container, serializer;
        let container = Di::getDefault();
        if typeof container != "object" {
            throw new Exception("The dependency injector container is not valid");
        }
        if container->has("serializer") {
            let serializer = <FrontendInterface> container->getShared("serializer");
            return serializer->beforeStore([
                "model"         : this->_model,
                "cache"         : this->_cache,
                "rows"          : this->toArray(false),
                "columnMap"     : this->_columnMap,
                "hydrateMode"   : this->_hydrateMode,
                "keepSnapshots" : this->_keepSnapshots
            ]);
        }
        /**
         * Serialize the cache using the serialize function
         */
        return serialize([
            "model"         : this->_model,
            "cache"         : this->_cache,
            "rows"          : this->toArray(false),
            "columnMap"     : this->_columnMap,
            "hydrateMode"   : this->_hydrateMode,
            "keepSnapshots" : this->_keepSnapshots
        ]);
    }

    /**
     * Unserializing a resultset will allow to only works on the rows present in the saved state
     */
    public function unserialize(var data) -> void
    {
        var resultset, keepSnapshots, container, serializer;
        let container = Di::getDefault();
        if typeof container != "object" {
            throw new Exception("The dependency injector container is not valid");
        }
        if container->has("serializer") {
            let serializer = <FrontendInterface> container->getShared("serializer");
            let resultset = serializer->afterRetrieve(data);
        } else {
            let resultset = unserialize(data);
        }
        if typeof resultset != "array" {
            throw new Exception("Invalid serialization data");
        }

        let this->_model = resultset["model"],
            this->_rows = resultset["rows"],
            this->_count = count(resultset["rows"]),
            this->_cache = resultset["cache"],
            this->_columnMap = resultset["columnMap"],
            this->_hydrateMode = resultset["hydrateMode"];

        if fetch keepSnapshots, resultset["keepSnapshots"] {
            let this->_keepSnapshots = keepSnapshots;
        }
    }
}

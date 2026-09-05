
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Hydration;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exceptions\ColumnNotInMap;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Support\Settings;

/**
 * @phpstan-import-type mvc_hydration_column_map from MvcTypes
 */
class CloneResultMapHydrate
{
    /**
     * Returns an hydrated result based on the data and the column map
     *
     * @phpstan-param array<array-key, mixed> $data
     */
    public static function cloneResultMapHydrate(
        array data, 
        var columnMap, 
        int hydrationMode, 
        string calledClass = "Phalcon\\Mvc\\Model"
    ) {
        var key, value, attribute, attributeName;
        array hydrateArray;

        /**
         * If there is no column map and the hydration mode is arrays return the
         * data as it is
         */
        if typeof columnMap !== "array" {
            if hydrationMode == Resultset::HYDRATE_ARRAYS {
                return data;
            }
        }

        /**
         * Create the destination object
         */
        let hydrateArray = [];

        for key, value in data {
            if typeof key !== "string" {
                continue;
            }

            if typeof columnMap === "array" {
                // Try to find case-insensitive key variant
                if !isset columnMap[key] && Settings::get("orm.case_insensitive_column_map") {
                    let key = CaseInsensitiveColumnMap::caseInsensitiveColumnMap(columnMap, key);
                }

                /**
                 * Every field must be part of the column map
                 */
                if !fetch attribute, columnMap[key] {
                    if unlikely !Settings::get("orm.ignore_unknown_columns") {
                        throw new ColumnNotInMap(key, calledClass);
                    }

                    continue;
                }

                /**
                 * Attribute can store info about his type
                 */
                if typeof attribute === "array" {
                    let attributeName = attribute[0];
                } else {
                    let attributeName = attribute;
                }

                let hydrateArray[attributeName] = value;
            } else {
                let hydrateArray[key] = value;
            }
        }

        if hydrationMode != Resultset::HYDRATE_ARRAYS {
            return (object) hydrateArray;
        }

        return hydrateArray;
    }
}

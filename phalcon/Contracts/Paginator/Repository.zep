
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Paginator;

/**
 * Interface for the repository of current state
 * Phalcon\Paginator\AdapterInterface::paginate()
 *
 * Two adapter dialects fill this repository:
 *
 * - Offset adapters (Model, NativeArray, QueryBuilder) populate every
 *   property as a sequential page number / item count.
 * - Cursor adapters (QueryBuilderCursor) reuse the same properties with a
 *   different meaning: `getCurrent()`/`getNext()` carry keyset cursor values
 *   rather than page numbers, and `getTotalItems()`, `getLast()` and
 *   `getPrevious()` are not computed (they return 0).
 */
interface Repository
{
    /**
     * @var string
     */
    const PROPERTY_CURRENT_PAGE  = "current";
    /**
     * @var string
     */
    const PROPERTY_FIRST_PAGE    = "first";
    /**
     * @var string
     */
    const PROPERTY_ITEMS         = "items";
    /**
     * @var string
     */
    const PROPERTY_LAST_PAGE     = "last";
    /**
     * @var string
     */
    const PROPERTY_LIMIT         = "limit";
    /**
     * @var string
     */
    const PROPERTY_NEXT_PAGE     = "next";
    /**
     * @var string
     */
    const PROPERTY_PREVIOUS_PAGE = "previous";
    /**
     * @var string
     */
    const PROPERTY_TOTAL_ITEMS   = "total_items";

    /**
     * Gets the aliases for properties repository
     *
     * @return array
     */
    public function getAliases() -> array;

    /**
     * Gets number of the current page
     *
     * Cursor adapters store the cursor value used for the current page here
     * (0 on the first page), not a sequential page number.
     *
     * @return int
     */
    public function getCurrent() -> int;

    /**
     * Gets number of the first page
     *
     * @return int
     */
    public function getFirst() -> int;

    /**
     * Gets the items on the current page
     */
    public function getItems() -> var;

    /**
     * Gets number of the last page
     *
     * Cursor adapters do not compute this and return 0.
     *
     * @return int
     */
    public function getLast() -> int;

    /**
     * Gets current rows limit
     *
     * @return int
     */
    public function getLimit() -> int;

    /**
     * Gets number of the next page
     *
     * Cursor adapters store the next cursor value here rather than a page
     * number; 0 means there is no next page.
     *
     * @return int
     */
    public function getNext() -> int;

    /**
     * Gets number of the previous page
     *
     * Cursor adapters do not compute this and return 0.
     *
     * @return int
     */
    public function getPrevious() -> int;

    /**
     * Gets the total number of items
     *
     * Cursor adapters do not compute this and return 0.
     *
     * @return int
     */
    public function getTotalItems() -> int;

    /**
     * Sets the aliases for properties repository
     *
     * @param array $aliases
     *
     * @return Repository
     */
    public function setAliases(array aliases) -> <Repository>;

    /**
     * Sets values for properties of the repository
     *
     * @param array $properties
     *
     * @return Repository
     */
    public function setProperties(array properties) -> <Repository>;
}

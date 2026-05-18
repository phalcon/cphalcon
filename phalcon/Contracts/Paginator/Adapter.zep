
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
 * Interface for Phalcon\Paginator adapters
 */
interface Adapter
{
    /**
     * Get current rows limit
     */
    public function getLimit() -> int;

    /**
     * Returns a slice of the resultset to show in the pagination
     */
    public function paginate() -> <Repository>;

    /**
     * Set the current page number
     */
    public function setCurrentPage(int page);

    /**
     * Set current rows limit
     */
    public function setLimit(int limit);
}

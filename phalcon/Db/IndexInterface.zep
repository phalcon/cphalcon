
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Interface for Phalcon\Db\Index
 */
interface IndexInterface
{
    /**
     * Gets the columns that corresponds the index
     */
    public function getColumns() -> array;

    /**
     * Gets the index name
     */
    public function getName() -> string;

    /**
     * Gets the index type
     */
    public function getType() -> string;
}

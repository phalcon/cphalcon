
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Db;

/**
 * Canonical contract for Phalcon\Db\Index.
 *
 * @todo v7 - these will become required interface members. They are
 *            omitted from the v5 line to avoid breaking third-party
 *            implementors:
 *              - getDirections() : array
 *              - getWhere()      : string
 *              - isConcurrent()  : bool
 *              - isInvisible()   : bool
 */
interface Index
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


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
 * @phpstan-import-type db_index_columns from DbTypes
 * @phpstan-import-type db_index_directions from DbTypes
 *
 * @todo v7 - these will become required interface members. They are
 *            omitted from the v5 line to avoid breaking third-party
 *            implementors:
 *              - getDirections() : array
 *              - getWhere()      : string
 *              - isConcurrent()  : bool
 *              - isInvisible()   : bool
 *
 * The dialects call the members above on the interface. They join the
 * interface in the next major; until then the tags below record what all
 * implementations provide.
 *
 * @method db_index_directions getDirections()
 * @method string              getWhere()
 * @method bool                isConcurrent()
 * @method bool                isInvisible()
 */
interface Index
{
    /**
     * Gets the columns that corresponds the index
     *
     * @phpstan-return db_index_columns
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

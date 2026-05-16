
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
 * @todo v7 — promote the methods below to required interface members.
 *            They live as commented-out stubs to avoid breaking third-party
 *            implementations of this interface in the v5 line:
 *              - getDirections() : array
 *              - getWhere()      : string
 *              - isInvisible()   : bool
 */
interface Index
{
    /**
     * Gets the columns that corresponds the index
     */
    public function getColumns() -> array;

    /**
     * @todo v7 — uncomment when promoting descending-index API.
     *
     * Returns the per-column sort directions (`ASC` / `DESC`). Empty array
     * means no per-column direction was declared.
     */
    // public function getDirections() -> array;

    /**
     * Gets the index name
     */
    public function getName() -> string;

    /**
     * Gets the index type
     */
    public function getType() -> string;

    /**
     * @todo v7 — uncomment when promoting partial-index API.
     *
     * Returns the partial-index WHERE predicate, or "" when none.
     */
    // public function getWhere() -> string;

    /**
     * @todo v7 — uncomment when promoting invisible-index API.
     *
     * Whether the index is declared INVISIBLE (MySQL 8.0+).
     */
    // public function isInvisible() -> bool;
}

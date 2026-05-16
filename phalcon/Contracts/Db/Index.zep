
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
 * @todo v7 — promote the invisible-index method below to a required
 *            interface member. It lives as a commented-out stub to avoid
 *            breaking third-party implementations of this interface in the
 *            v5 line:
 *              - isInvisible() : bool
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

    /**
     * @todo v7 — uncomment when promoting invisible-index API.
     *
     * Whether the index is declared INVISIBLE (MySQL 8.0+).
     */
    // public function isInvisible() -> bool;
}


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
 * Canonical contract for Phalcon\Db\Reference.
 */
interface Reference
{
    /**
     * Gets local columns which reference is based
     */
    public function getColumns() -> array;

    /**
     * Gets the index name
     */
    public function getName() -> string;

    /**
     * Gets the referenced on delete
     */
    public function getOnDelete() -> string | null;

    /**
     * Gets the referenced on update
     */
    public function getOnUpdate() -> string | null;

    /**
     * Gets referenced columns
     */
    public function getReferencedColumns() -> array;

    /**
     * Gets the schema where referenced table is
     */
    public function getReferencedSchema() -> string | null;

    /**
     * Gets the referenced table
     */
    public function getReferencedTable() -> string;

    /**
     * Gets the schema where referenced table is
     */
    public function getSchemaName() -> string | null;
}

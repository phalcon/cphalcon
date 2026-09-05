
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Contracts\Db\DbTypes;
use Phalcon\Db\Exceptions\ForeignKeyColumnsRequired;
use Phalcon\Db\Exceptions\ReferencedColumnCountMismatch;
use Phalcon\Db\Exceptions\ReferencedColumnsRequired;
use Phalcon\Db\Exceptions\ReferencedTableRequired;

/**
 * Allows to define reference constraints on tables
 *
 *```php
 * $reference = new \Phalcon\Db\Reference(
 *     "field_fk",
 *     [
 *         "referencedSchema"  => "invoicing",
 *         "referencedTable"   => "products",
 *         "columns"           => [
 *             "producttype",
 *             "product_code",
 *         ],
 *         "referencedColumns" => [
 *             "type",
 *             "code",
 *         ],
 *     ]
 * );
 *```
 *
 * @phpstan-import-type db_column_names from DbTypes
 * @phpstan-import-type db_reference_definition from DbTypes
 */
class Reference implements ReferenceInterface
{
    /**
     * Local reference columns
     *
     * @var array
     *
     * @phpstan-var db_column_names
     */
    protected columns;

    /**
     * Constraint name
     *
     * @var string
     */
    protected name;

    /**
     * Referenced Columns
     *
     * @var array
     *
     * @phpstan-var db_column_names
     */
    protected referencedColumns;

    /**
     * Referenced Schema
     *
     * @var string
     */
    protected referencedSchema;

    /**
     * Referenced Table
     *
     * @var string
     */
    protected referencedTable;

    /**
     * Schema name
     *
     * @var string
     */
    protected schemaName;

    /**
     * ON DELETE
     *
     * @var string
     */
    protected onDelete;

    /**
     * ON UPDATE
     *
     * @var string
     */
    protected onUpdate;

    /**
     * Phalcon\Db\Reference constructor
     *
     * @phpstan-param db_reference_definition $definition
     */
    public function __construct( string name,  array definition)
    {
        var columns, schema, referencedTable, referencedSchema,
            referencedColumns, onDelete, onUpdate;

        let this->name = name;

        if unlikely !fetch referencedTable, definition["referencedTable"] {
            throw new ReferencedTableRequired();
        }

        let this->referencedTable = referencedTable;

        if unlikely !fetch columns, definition["columns"] {
            throw new ForeignKeyColumnsRequired();
        }

        let this->columns = columns;

        if unlikely !fetch referencedColumns, definition["referencedColumns"] {
            throw new ReferencedColumnsRequired();
        }

        let this->referencedColumns = referencedColumns;

        if fetch schema, definition["schema"] {
            let this->schemaName = schema;
        }

        if fetch referencedSchema, definition["referencedSchema"] {
            let this->referencedSchema = referencedSchema;
        }

        if fetch onDelete, definition["onDelete"] {
            let this->onDelete = onDelete;
        }

        if fetch onUpdate, definition["onUpdate"] {
            let this->onUpdate = onUpdate;
        }

        if unlikely count(columns) != count(referencedColumns) {
            throw new ReferencedColumnCountMismatch();
        }
    }

    /**
     * Local reference columns
     *
     * @phpstan-return db_column_names
     */
    public function getColumns() -> array
    {
        return this->columns;
    }

    /**
     * Constraint name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Referenced Columns
     *
     * @phpstan-return db_column_names
     */
    public function getReferencedColumns() -> array
    {
        return this->referencedColumns;
    }

    /**
     * Referenced Schema
     */
    public function getReferencedSchema() -> string | null
    {
        return this->referencedSchema;
    }

    /**
     * Referenced Table
     */
    public function getReferencedTable() -> string
    {
        return this->referencedTable;
    }

    /**
     * Schema name
     */
    public function getSchemaName() -> string | null
    {
        return this->schemaName;
    }

    /**
     * ON DELETE
     */
    public function getOnDelete() -> string | null
    {
        return this->onDelete;
    }

    /**
     * ON UPDATE
     */
    public function getOnUpdate() -> string | null
    {
        return this->onUpdate;
    }
}

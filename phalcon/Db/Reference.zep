
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Phalcon\Db\Reference
 *
 * Allows to define reference constraints on tables
 *
 *<code>
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
 *</code>
 */
class Reference implements ReferenceInterface
{
    /**
     * Local reference columns
     *
     * @var array
     */
    protected columns { get };

    /**
     * Constraint name
     *
     * @var string
     */
    protected name { get };

    /**
     * Referenced Columns
     *
     * @var array
     */
    protected referencedColumns { get };

    /**
     * Referenced Schema
     *
     * @var string
     */
    protected referencedSchema { get };

    /**
     * Referenced Table
     *
     * @var string
     */
    protected referencedTable { get };

    /**
     * Schema name
     *
     * @var string
     */
    protected schemaName { get };

    /**
     * ON DELETE
     *
     * @var string
     */
    protected onDelete { get };

    /**
     * ON UPDATE
     *
     * @var string
     */
    protected onUpdate { get };

    /**
     * Phalcon\Db\Reference constructor
     */
    public function __construct(string! name, array! definition) -> void
    {
        var columns, schema, referencedTable, referencedSchema,
            referencedColumns, onDelete, onUpdate;

        let this->name = name;

        if !fetch referencedTable, definition["referencedTable"] {
            throw new Exception("Referenced table is required");
        }

        let this->referencedTable = referencedTable;

        if !fetch columns, definition["columns"] {
            throw new Exception("Foreign key columns are required");
        }

        let this->columns = columns;

        if !fetch referencedColumns, definition["referencedColumns"] {
            throw new Exception(
                "Referenced columns of the foreign key are required"
            );
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

        if count(columns) != count(referencedColumns) {
            throw new Exception(
                "Number of columns is not equals than the number of columns referenced"
            );
        }
    }

    /**
     * Restore a Phalcon\Db\Reference object from export
     */
    public static function __set_state(array! data) -> <ReferenceInterface>
    {
        var referencedSchema, referencedTable, columns,
            referencedColumns, constraintName,
            onDelete, onUpdate;

        if !fetch constraintName, data["referenceName"] {
            if !fetch constraintName, data["name"] {
                throw new Exception("name parameter is required");
            }
        }

        fetch referencedSchema, data["referencedSchema"];
        fetch referencedTable, data["referencedTable"];
        fetch columns, data["columns"];
        fetch referencedColumns, data["referencedColumns"];
        fetch onDelete, data["onDelete"];
        fetch onUpdate, data["onUpdate"];

        return new Reference(
            constraintName,
            [
                "referencedSchema":  referencedSchema,
                "referencedTable":   referencedTable,
                "columns":           columns,
                "referencedColumns": referencedColumns,
                "onDelete":          onDelete,
                "onUpdate":          onUpdate
            ]
        );
    }
}

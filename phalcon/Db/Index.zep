
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
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index.
 *
 * The constructor accepts either the legacy positional form (a plain array
 * of column names) or a definition-array form (an associative array with a
 * `columns` key); the latter is the path used by features such as
 * `invisible` (MySQL 8.0+) and is the form that future per-index modifiers
 * will extend.
 *
 *```php
 * // Legacy positional form
 * $unique = new \Phalcon\Db\Index(
 *     'column_UNIQUE',
 *     [
 *         'column',
 *     ],
 *     'UNIQUE'
 * );
 *
 * $primary = new \Phalcon\Db\Index(
 *     'PRIMARY',
 *     [
 *         'column',
 *     ]
 * );
 *
 * // Definition-array form (MySQL 8.0+ invisible index)
 * $hidden = new \Phalcon\Db\Index(
 *     'idx_hidden',
 *     [
 *         'columns'   => ['col1'],
 *         'type'      => '',
 *         'invisible' => true,
 *     ]
 * );
 *
 * $connection->addIndex("robots", null, $unique);
 * $connection->addIndex("robots", null, $primary);
 * $connection->addIndex("robots", null, $hidden);
 *```
 */
class Index implements IndexInterface
{
    /**
     * Index columns
     *
     * @var array
     */
    protected columns;

    /**
     * Whether to build the index without taking a strong lock that blocks
     * writes — emits `CONCURRENTLY` between `INDEX` and the index name on
     * PostgreSQL (`CREATE INDEX CONCURRENTLY name ON ...`). MySQL and
     * SQLite have no equivalent and ignore the flag.
     *
     * @var bool
     */
    protected concurrent = false;

    /**
     * Per-column sort directions (`ASC` / `DESC`). Empty array means
     * "emit no per-column direction" — preserves the legacy plain
     * `(col1, col2)` rendering. When populated, entries shorter than
     * the columns list default to `ASC` for the missing positions.
     *
     * @var array
     */
    protected directions = [];

    /**
     * Whether the index is declared `INVISIBLE` (MySQL 8.0+). Invisible
     * indexes are ignored by the optimizer — useful for testing what
     * happens when an index is removed before actually dropping it.
     * PostgreSQL and SQLite have no equivalent and ignore the flag.
     *
     * @var bool
     */
    protected invisible = false;

    /**
     * Index name
     *
     * @var string
     */
    protected name;

    /**
     * Index type
     *
     * @var string
     */
    protected type;

    /**
     * Optional partial-index `WHERE` predicate. Supported by PostgreSQL and
     * SQLite (`CREATE INDEX ... WHERE <expr>`); MySQL has no partial-index
     * concept and its dialect ignores this value. Empty string means no
     * predicate.
     *
     * @var string
     */
    protected where = "";

    /**
     * Phalcon\Db\Index constructor.
     *
     * Accepts either the legacy positional form `(name, columns, type)` or a
     * definition-array form `(name, ["columns" => [...], "type" => "...",
     * "invisible" => true, ...])`. Detection is based on the presence of a
     * `columns` key in the second argument; when present, the third
     * positional `type` argument is ignored in favor of the definition.
     */
    public function __construct(string! name, array! columnsOrDefinition, string type = "")
    {
        var definitionType, invisible, directions, where, concurrent;

        let this->name = name;

        if isset columnsOrDefinition["columns"] {
            if unlikely typeof columnsOrDefinition["columns"] != "array" {
                throw new Exception(
                    "Index definition 'columns' key must be an array"
                );
            }

            let this->columns = columnsOrDefinition["columns"];

            if fetch definitionType, columnsOrDefinition["type"] {
                let this->type = (string) definitionType;
            }

            if fetch invisible, columnsOrDefinition["invisible"] {
                let this->invisible = (bool) invisible;
            }

            if fetch directions, columnsOrDefinition["directions"] {
                if unlikely typeof directions != "array" {
                    throw new Exception(
                        "Index definition 'directions' key must be an array"
                    );
                }

                let this->directions = directions;
            }

            if fetch where, columnsOrDefinition["where"] {
                if unlikely typeof where != "string" {
                    throw new Exception(
                        "Index definition 'where' key must be a string"
                    );
                }

                let this->where = where;
            }

            if fetch concurrent, columnsOrDefinition["concurrently"] {
                let this->concurrent = (bool) concurrent;
            }
        } else {
            let this->columns = columnsOrDefinition;
            let this->type    = type;
        }
    }

    /**
     * Index columns
     */
    public function getColumns() -> array
    {
        return this->columns;
    }

    /**
     * Returns the per-column sort directions array (`ASC` / `DESC`).
     * Empty array means the index was declared without explicit per-column
     * directions and dialects emit the columns plainly. When populated,
     * entries are aligned with `getColumns()`; missing trailing positions
     * default to `ASC` at emission time.
     */
    public function getDirections() -> array
    {
        return this->directions;
    }

    /**
     * Index name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Index type
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Returns the partial-index `WHERE` predicate, or an empty string when
     * the index has none. Supported by PostgreSQL and SQLite; ignored by
     * the MySQL dialect (MySQL has no partial-index feature).
     */
    public function getWhere() -> string
    {
        return this->where;
    }

    /**
     * Whether the index is built `CONCURRENTLY` (PostgreSQL only). MySQL
     * and SQLite have no equivalent and ignore the flag.
     */
    public function isConcurrent() -> bool
    {
        return this->concurrent;
    }

    /**
     * Whether the index is declared `INVISIBLE` (MySQL 8.0+). Invisible
     * indexes are ignored by the optimizer but still maintained, so they
     * can be flipped back to visible without a rebuild.
     */
    public function isInvisible() -> bool
    {
        return this->invisible;
    }
}

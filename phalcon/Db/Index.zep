
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
 * and retrieve specific rows much faster than it could do without an index
 *
 *```php
 * // Define new unique index
 * $index_unique = new \Phalcon\Db\Index(
 *     'column_UNIQUE',
 *     [
 *         'column',
 *         'column',
 *     ],
 *     'UNIQUE'
 * );
 *
 * // Define new primary index
 * $index_primary = new \Phalcon\Db\Index(
 *     'PRIMARY',
 *     [
 *         'column',
 *     ]
 * );
 *
 * // Add index to existing table
 * $connection->addIndex("robots", null, $index_unique);
 * $connection->addIndex("robots", null, $index_primary);
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
     * Phalcon\Db\Index constructor
     */
    public function __construct(string! name, array! columns, string type = "")
    {
        let this->name    = name;
        let this->columns = columns;
        let this->type    = type;
    }

    /**
     * Index columns
     */
    public function getColumns() -> array
    {
        return this->columns;
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
}

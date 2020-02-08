
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Qyert/blob/1.x/LICENSE.md
 */

namespace Phalcon\DataMapper\Query;

use Phalcon\DataMapper\Pdo\Connection;

class Delete extends AbstractConditions
{
    /**
     * Delete constructor.
     *
     * @param Connection $connection
     * @param Bind       $bind
     */
    public function __construct(<Connection> connection, <Bind> bind)
    {
        parent::__construct(connection, bind);

        let this->store["FROM"]      = "",
            this->store["RETURNING"] = [];
    }

    /**
     * Adds table(s) in the query
     *
     * @param string $table
     *
     * @return AbstractConditions
     */
    public function from(string $table) -> <Delete>
    {
        let this->store["FROM"] = table;

        return this;
    }

    /**
     * Adds the `RETURNING` clause
     *
     * @param string ...$columns
     *
     * @return Delete
     */
    public function returning() -> <Delete>
    {
        let this->store["RETURNING"] = array_merge(
            this->store["RETURNING"],
            func_get_args()
        );

        return this;
    }

    /**
     * @return string
     */
    public function getStatement() -> string
    {
        return "DELETE"
            . this->buildFlags()
            . " FROM " . this->store["FROM"]
            . this->buildCondition("WHERE")
            . this->buildReturning();
    }

    /**
     * Resets the internal store
     */
    public function reset()
    {
        parent::reset();

        let this->store["FROM"]      = "",
            this->store["RETURNING"] = [];
    }
}

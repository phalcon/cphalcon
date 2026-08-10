
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

/**
 * QueryFactory
 */
class QueryFactory
{
    /**
     * @var string
     */
    protected string selectClass = "";

    /**
     * QueryFactory constructor.
     */
    public function __construct(string selectClass = "")
    {
        if empty selectClass {
            let selectClass = Select::class;
        }

        let this->selectClass = selectClass;
    }

    /**
     * Create a new Bind object
     */
    public function newBind() -> <Bind>
    {
        return new Bind();
    }

    /**
     * Create a new Delete object
     */
    public function newDelete(<Connection> connection) -> <Delete>
    {
        return new Delete(connection, this->newBind());
    }

    /**
     * Create a new Insert object
     */
    public function newInsert(<Connection> connection) -> <Insert>
    {
        return new Insert(connection, this->newBind());
    }

    /**
     * Create a new Select object
     */
    public function newSelect(<Connection> connection) -> <Select>
    {
        string selectClass;

        let selectClass = this->selectClass;

        return new {selectClass}(connection, this->newBind());
    }

    /**
     * Create a new Update object
     */
    public function newUpdate(<Connection> connection) -> <Update>
    {
        return new Update(connection, this->newBind());
    }
}

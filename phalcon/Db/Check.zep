
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Db\Exceptions\CheckExpressionRequired;
use Phalcon\Db\Exceptions\InvalidCheckExpression;

/**
 * Allows to define `CHECK` constraints on tables. CHECK constraints enforce
 * a boolean SQL predicate on each row of the table; rows that fail the
 * predicate are rejected at INSERT/UPDATE time.
 *
 *```php
 * use Phalcon\Db\Check;
 *
 * $positivePrice = new Check(
 *     "chk_price_positive",
 *     [
 *         "expression" => "price > 0",
 *     ]
 * );
 *
 * // Used inside a createTable() definition
 * $connection->createTable(
 *     "products",
 *     null,
 *     [
 *         "columns" => [ ... ],
 *         "checks"  => [$positivePrice],
 *     ]
 * );
 *
 * // Or added to an existing table (MySQL 8.0.16+ and PostgreSQL).
 * // SQLite cannot add CHECK constraints to existing tables.
 * $connection->addCheck("products", null, $positivePrice);
 *```
 */
class Check implements CheckInterface
{
    /**
     * The boolean SQL predicate this constraint enforces.
     *
     * @var string
     */
    protected expression;

    /**
     * The CHECK constraint name. An empty string indicates an unnamed
     * constraint — the dialect will emit the clause without a `CONSTRAINT`
     * prefix in that case.
     *
     * @var string
     */
    protected name;

    /**
     * Phalcon\Db\Check constructor
     */
    public function __construct(string! name, array! definition)
    {
        var expression;

        if unlikely !fetch expression, definition["expression"] {
            throw new CheckExpressionRequired();
        }

        if unlikely typeof expression != "string" || expression === "" {
            throw new InvalidCheckExpression();
        }

        let this->name       = name;
        let this->expression = expression;
    }

    /**
     * Returns the CHECK expression
     */
    public function getExpression() -> string
    {
        return this->expression;
    }

    /**
     * Returns the constraint name (may be an empty string for unnamed)
     */
    public function getName() -> string
    {
        return this->name;
    }
}

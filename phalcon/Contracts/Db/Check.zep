
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
 * Canonical contract for Phalcon\Db\Check.
 */
interface Check
{
    /**
     * Gets the CHECK expression (the SQL boolean predicate).
     */
    public function getExpression() -> string;

    /**
     * Gets the constraint name. An empty string indicates an unnamed CHECK
     * constraint - the dialect will emit the clause without a `CONSTRAINT`
     * prefix in that case.
     */
    public function getName() -> string;
}

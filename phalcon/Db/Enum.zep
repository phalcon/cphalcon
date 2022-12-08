
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
 * Constants for Phalcon\Db
 */
class Enum
{
    const FETCH_ASSOC      = \PDO::FETCH_ASSOC;
    const FETCH_BOTH       = \PDO::FETCH_BOTH;
    const FETCH_BOUND      = \PDO::FETCH_BOUND;
    const FETCH_CLASS      = \PDO::FETCH_CLASS;
    const FETCH_CLASSTYPE  = \PDO::FETCH_CLASSTYPE;
    const FETCH_COLUMN     = \PDO::FETCH_COLUMN;
    const FETCH_FUNC       = \PDO::FETCH_FUNC;
    const FETCH_GROUP      = \PDO::FETCH_GROUP;
    const FETCH_INTO       = \PDO::FETCH_INTO;
    const FETCH_KEY_PAIR   = \PDO::FETCH_KEY_PAIR;
    const FETCH_LAZY       = \PDO::FETCH_LAZY;
    const FETCH_NAMED      = \PDO::FETCH_NAMED;
    const FETCH_NUM        = \PDO::FETCH_NUM;
    const FETCH_OBJ        = \PDO::FETCH_OBJ;
    const FETCH_ORI_NEXT   = \PDO::FETCH_ORI_NEXT;
    const FETCH_PROPS_LATE = \PDO::FETCH_PROPS_LATE;
    const FETCH_SERIALIZE  = \PDO::FETCH_SERIALIZE;
    const FETCH_UNIQUE     = \PDO::FETCH_UNIQUE;
    const FETCH_DEFAULT    = 0; // TODO: Use \Pdo::FETCH_DEFAULT after min PHP version is 8.0.7;
}

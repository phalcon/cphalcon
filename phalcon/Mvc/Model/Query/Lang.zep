/*
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query;

/**
 * Phalcon\Mvc\Model\Query\Lang
 *
 * PHQL is implemented as a parser (written in C) that translates syntax in
 * that of the target RDBMS. It allows Phalcon to offer a unified SQL language to
 * the developer, while internally doing all the work of translating PHQL
 * instructions to the most optimal SQL instructions depending on the
 * RDBMS type associated with a model.
 *
 * To achieve the highest performance possible, we wrote a parser that uses
 * the same technology as SQLite. This technology provides a small in-memory
 * parser with a very low memory footprint that is also thread-safe.
 *
 * ```php
 * use Phalcon\Mvc\Model\Query\Lang;
 *
 * $intermediate = Lang::parsePHQL(
 *     "SELECT r.* FROM Robots r LIMIT 10"
 * );
 * ```
 */
abstract class Lang
{
    /**
     * Parses a PHQL statement returning an intermediate representation (IR)
     */
    public static function parsePHQL(string! phql) -> array
    {
        return phql_parse_phql(phql);
    }
}

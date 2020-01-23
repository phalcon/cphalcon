
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
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */

namespace Phalcon\DM\Pdo\Parser;

/**
 * Interface for query parsing/rebuilding functionality.
 */
interface ParserInterface
{
    /**
     * Rebuilds a query and its parameters to adapt it to PDO's limitations,
     * and returns a list of queries.
     *
     * @param string $input
     * @param array  $parameters
     *
     * @return array
     */
    public function rebuild(string input, array parameters = []) -> array;
}

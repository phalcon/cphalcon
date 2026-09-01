
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Exceptions;

use Phalcon\Auth\Exception;

/**
 * Option must be a non-empty array
 */
class OptionRequiresArray extends Exception
{
    public function __construct(string context, string key)
    {
        parent::__construct(
            "Auth " . context . " requires '" . key
            . "' to be a non-empty array"
        );
    }
}

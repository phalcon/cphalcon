
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by lcobucci/clock
 *
 * @link    https://github.com/lcobucci/clock
 * @license https://github.com/lcobucci/clock/blob/3.7.x/LICENSE
 */

namespace Phalcon\Time\Clock;

use Throwable;

class Exception extends \Exception
{
    public static function invalidModifier(string message, <Throwable> ex = null) -> <Exception>
    {
        return new Exception("Invalid modifier: \"" . message . "\"", 0, ex);
    }
}

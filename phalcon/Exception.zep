
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * Phalcon\Exception
 *
 * All framework exceptions should use or extend this exception
 */
class Exception extends \Exception implements \Throwable
{
    public static function containerServiceNotFound(string! service) -> string
    {
        return "A dependency injection container is required to access " . service;
    }
}

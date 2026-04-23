
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

/**
 * Exceptions thrown in Phalcon\Di will use this class
 */
class Exception extends \Exception
{
    public static function serviceCannotBeResolved(string name) -> <Exception>
    {
        return new Exception(
            "Service '" . name . "' cannot be resolved"
        );
    }

    public static function serviceNotFound(string name) -> <Exception>
    {
        return new Exception(
            "Service '" . name . "' is not registered in the container"
        );
    }

    public static function unknownServiceInParameter(int position) -> <Exception>
    {
        return new Exception(
            "Unknown service type in parameter on position " . position
        );
    }

    public static function undefinedMethod(string method) -> <Exception>
    {
        return new Exception(
            "Call to undefined method or service '" . method . "'"
        );
    }
}

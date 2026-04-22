
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Container\Exception;

class NotFound extends Invalid
{
    public static function envNotDefined(string! varname) -> <NotFound>
    {
        return new self("Environment variable '" . varname . "' is not defined");
    }

    public static function instanceNotFound(string! name) -> <NotFound>
    {
        return new self("Instance '" . name . "' not found");
    }

    public static function parameterNotFound(string! name) -> <NotFound>
    {
        return new self("Parameter '" . name . "' not found");
    }

    public static function serviceNotFound(string! name) -> <NotFound>
    {
        return new self("Service '" . name . "' not found");
    }
}

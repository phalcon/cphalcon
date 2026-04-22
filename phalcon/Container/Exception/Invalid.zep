
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Container\Exception;

use Phalcon\Container\Exception\ContainerThrowable;

class Invalid extends \Exception implements ContainerThrowable
{
    public static function cannotExtendResolved(string! name) -> <Invalid>
    {
        return new self("Cannot extend already-resolved service '" . name . "'");
    }

    public static function cannotResolveParameter(string! param, string! className) -> <Invalid>
    {
        return new self("Cannot resolve parameter '$" . param . "' for '" . className . "'");
    }

    public static function circularAlias(string! name) -> <Invalid>
    {
        return new self("Circular alias detected: '" . name . "'");
    }

    public static function frozenDefinition(string! name) -> <Invalid>
    {
        return new self("Cannot modify frozen definition '" . name . "'");
    }

    public static function invalidExtender(string! service, var key) -> <Invalid>
    {
        if unlikely (typeof key != "integer" && typeof key != "string") {
            throw new \TypeError("Argument 'key' must be int or string");
        }

        return new self("Extender at key '" . key . "' for service '" . service . "' is not callable");
    }

    public static function noClassSet(string! name) -> <Invalid>
    {
        return new self("No class set for service '" . name . "'");
    }

    public static function noFactorySet(string! name) -> <Invalid>
    {
        return new self("No factory set for service '" . name . "'");
    }

    public static function noProcessorFound() -> <Invalid>
    {
        return new self("No processor found for the given definition");
    }

    public static function serviceNotFound(string! name) -> <Invalid>
    {
        return new self("Service '" . name . "' not registered");
    }
}

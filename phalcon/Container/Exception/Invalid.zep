
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, service-interop
 * and resolver-interop. These have been copied and implemented here since
 * PHP extensions cannot have more than one namespace.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
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

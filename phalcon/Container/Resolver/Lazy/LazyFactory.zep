
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

namespace Phalcon\Container\Resolver\Lazy;

use Phalcon\Container\Resolver\Lazy\ArrayValues;
use Phalcon\Container\Resolver\Lazy\Call;
use Phalcon\Container\Resolver\Lazy\CsEnv;
use Phalcon\Container\Resolver\Lazy\Env;
use Phalcon\Container\Resolver\Lazy\EnvDefault;
use Phalcon\Container\Resolver\Lazy\FunctionCall;
use Phalcon\Container\Resolver\Lazy\Get;
use Phalcon\Container\Resolver\Lazy\GetCall;
use Phalcon\Container\Resolver\Lazy\NewCall;
use Phalcon\Container\Resolver\Lazy\NewInstance;
use Phalcon\Container\Resolver\Lazy\StaticCall;
use RuntimeException;
use TypeError;

class LazyFactory
{
    public static function arrayValues(array values) -> <ArrayValues>
    {
        return new ArrayValues(values);
    }

    public static function call(var callableObject) -> <Call>
    {
        return new Call(callableObject);
    }

    public static function callableGet(string! id) -> var
    {
        throw new RuntimeException("Not implemented: requires Zephir \$this-in-closure support");
    }

    public static function callableNew(string! id) -> var
    {
        throw new RuntimeException("Not implemented: requires Zephir \$this-in-closure support");
    }

    public static function csEnv(string! name, var type = null) -> <CsEnv>
    {
        if unlikely (typeof type != "string" && typeof type != "null") {
            throw new TypeError("Argument 'type' must be string or null");
        }

        return new CsEnv(name, type);
    }

    public static function env(string! name, var type = null) -> <Env>
    {
        if unlikely (typeof type != "string" && typeof type != "null") {
            throw new TypeError("Argument 'type' must be string or null");
        }

        return new Env(name, type);
    }

    public static function envDefault(string! name, var defaultValue, var type = null) -> <EnvDefault>
    {
        if unlikely (typeof type != "string" && typeof type != "null") {
            throw new TypeError("Argument 'type' must be string or null");
        }

        return new EnvDefault(name, defaultValue, type);
    }

    public static function functionCall(string! functionName, array args) -> <FunctionCall>
    {
        return new FunctionCall(functionName, args);
    }

    public static function get(string! id) -> <Get>
    {
        return new Get(id);
    }

    public static function getCall(var id, string! method, array args) -> <GetCall>
    {
        return new GetCall(id, method, args);
    }

    public static function newCall(var id, string! method, array args) -> <NewCall>
    {
        return new NewCall(id, method, args);
    }

    public static function newInstance(string! id) -> <NewInstance>
    {
        return new NewInstance(id);
    }

    public static function staticCall(var className, string! method, array args) -> <StaticCall>
    {
        return new StaticCall(className, method, args);
    }
}

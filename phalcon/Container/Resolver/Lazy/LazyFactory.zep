
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
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

class LazyFactory
{
    /**
     * @param array<array-key, mixed> $values
     *
     * @return ArrayValues
     */
    public static function arrayValues(array values) -> <ArrayValues>
    {
        return new ArrayValues(values);
    }

    public static function call(callable callableObject) -> <Call>
    {
        return new Call(callableObject);
    }

    public static function callableGet(string id) -> <CallableGet>
    {
        return new CallableGet(id);
    }

    public static function callableNew(string id) -> <CallableNew>
    {
        return new CallableNew(id);
    }

    public static function csEnv(string name, string type = null) -> <CsEnv>
    {
        return new CsEnv(name, type);
    }

    public static function env(string name, string type = null) -> <Env>
    {
        return new Env(name, type);
    }

    public static function envDefault(string name, mixed defaultValue, string type = null) -> <EnvDefault>
    {
        return new EnvDefault(name, defaultValue, type);
    }

    /**
     * @param string                  $function
     * @param array<array-key, mixed> $args
     *
     * @return FunctionCall
     */
    public static function functionCall(string functionName, array args) -> <FunctionCall>
    {
        return new FunctionCall(functionName, args);
    }

    public static function get(string id) -> <Get>
    {
        return new Get(id);
    }

    /**
     * @param string                  $id
     * @param string                  $method
     * @param array<array-key, mixed> $args
     *
     * @return GetCall
     */
    public static function getCall(string id, string method, array args) -> <GetCall>
    {
        return new GetCall(id, method, args);
    }

    /**
     * @param string                  $id
     * @param string                  $method
     * @param array<array-key, mixed> $args
     *
     * @return NewCall
     */
    public static function newCall(string id, string method, array args) -> <NewCall>
    {
        return new NewCall(id, method, args);
    }

    public static function newInstance(string id) -> <NewInstance>
    {
        return new NewInstance(id);
    }

    /**
     * @param string                  $className
     * @param string                  $method
     * @param array<array-key, mixed> $args
     *
     * @return StaticCall
     */
    public static function staticCall(string className, string method, array args) -> <StaticCall>
    {
        return new StaticCall(className, method, args);
    }
}

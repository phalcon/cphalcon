
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

class NewCall extends Lazy
{
    /**
     * @var array<array-key, mixed>
     */
    protected arguments;
    /**
     * @var string|Lazy
     */
    protected id;
    /**
     * @var string
     */
    protected method;

    /**
     * @param string|Lazy             $id
     * @param string                  $method
     * @param array<array-key, mixed> $arguments
     */
    public function __construct(var id, string method, array arguments)
    {
        let this->id        = id;
        let this->method    = method;
        let this->arguments = arguments;
    }

    /**
     * Resolve a new instance method call
     *
     * @param object $ioc
     *
     * @return mixed
     */
    public function resolve(object ioc) -> mixed
    {
        var id, arguments, service;

        let id        = this->resolveArgument(ioc, this->id);
        let arguments = this->resolveArguments(ioc, this->arguments);
        let service   = ioc->$new(id);

        return call_user_func_array([service, this->method], arguments);
    }
}

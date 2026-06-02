
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
 * Composer dependency, and from service-interop and resolver-interop. They
 * are copied and re-implemented here because we need to support PHP 8.1.
 * Once we move to min 8.4 and packages become available and compatible, the
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

namespace Phalcon\Contracts\Container\Resolver;

use Phalcon\Contracts\Container\Ioc\IocContainer;
use ReflectionMethod;
use ReflectionParameter;
use ReflectionType;

interface ResolverService extends ReflectionParameterResolver
{
    public function isResolvableClass(string className) -> bool;

    public function resolveCall(<IocContainer> ioc, callable callableObject, array arguments) -> mixed;

    public function resolveClass(<IocContainer> ioc, string className, array arguments) -> object;

    public function resolveMethod(<IocContainer> ioc, <ReflectionMethod> method, object instance) -> void;

    public function resolveParameters(<IocContainer> ioc, array parameters, array arguments) -> array;

    public function resolveType(<IocContainer> ioc, <ReflectionType> type) -> mixed;
}

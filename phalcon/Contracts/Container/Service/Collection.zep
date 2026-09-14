
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

namespace Phalcon\Contracts\Container\Service;

use Closure;
use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Resolver\Resolver;
use Phalcon\Contracts\Container\ContainerTypes;
use Phalcon\Contracts\Container\Ioc\IocContainer;

/**
 * @phpstan-import-type container_tagged_services from ContainerTypes
 */
interface Collection extends IocContainer
{
    public function bind(string interfaceName, string concrete) -> <ServiceDefinition>;

    public function callableGet(string name) -> <Closure>;

    public function callableNew(string name) -> <Closure>;

    public function extend(string name, callable callableObject) -> void;

    public function get(string name) -> mixed;

    public function getAlias(string name) -> string;

    /**
     * @phpstan-return container_tagged_services
     */
    public function getByTag(string tag) -> array;

    public function getDefinition(string name) -> <ServiceDefinition>;

    public function getInstance(string name) -> object;

    public function getParameter(string name) -> mixed;

    public function getResolver() -> <Resolver>;

    public function has(string name) -> bool;

    public function hasAlias(string name) -> bool;

    public function hasDefinition(string name) -> bool;

    public function hasInstance(string name) -> bool;

    public function hasParameter(string name) -> bool;

    public function isAutowireEnabled() -> bool;

    public function $new(string name) -> mixed;

    public function newDefinition(string name) -> <ServiceDefinition>;

    public function set(string name, var definition) -> <ServiceDefinition>;

    public function setAlias(string name, string alias) -> <static>;

    public function setAutowire(bool enabled) -> <static>;

    public function setDefinition(string name, <ServiceDefinition> definition) -> <static>;

    public function setInstance(string name, object instance, string lifetime) -> <static>;

    public function setParameter(string name, var value) -> <static>;

    public function unsetAlias(string name) -> void;

    public function unsetDefinition(string name) -> void;

    public function unsetInstance(string name) -> void;

    public function unsetInstances(string lifetime) -> void;

    public function unsetParameter(string name) -> void;
}

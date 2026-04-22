
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

namespace Phalcon\Container\Interop\Service;

use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Interop\Ioc\IocContainer;
use Phalcon\Container\Resolver\Resolver;

interface Collection extends IocContainer
{
    public function bind(string! interfaceName, string! concrete) -> <ServiceDefinition>;

    public function callableGet(string! name) -> var;

    public function callableNew(string! name) -> var;

    public function extend(string! name, var callableObject) -> void;

    public function get(string! name) -> var;

    public function getAlias(string! name) -> string;

    public function getByTag(string! tag) -> array;

    public function getDefinition(string! name) -> <ServiceDefinition>;

    public function getInstance(string! name) -> object;

    public function getParameter(string! name) -> var;

    public function getResolver() -> <Resolver>;

    public function has(string! name) -> bool;

    public function hasAlias(string! name) -> bool;

    public function hasDefinition(string! name) -> bool;

    public function hasInstance(string! name) -> bool;

    public function hasParameter(string! name) -> bool;

    public function isAutowireEnabled() -> bool;

    public function $new(string! name) -> var;

    public function newDefinition(string! name) -> <ServiceDefinition>;

    public function set(string! name, var definition) -> <ServiceDefinition>;

    public function setAlias(string! name, string! alias) -> <Collection>;

    public function setAutowire(bool enabled) -> <Collection>;

    public function setDefinition(string! name, <ServiceDefinition> definition) -> <Collection>;

    public function setInstance(string! name, object instance, string! lifetime) -> <Collection>;

    public function setParameter(string! name, var value) -> <Collection>;

    public function unsetAlias(string! name) -> void;

    public function unsetDefinition(string! name) -> void;

    public function unsetInstance(string! name) -> void;

    public function unsetInstances(string! lifetime) -> void;

    public function unsetParameter(string! name) -> void;
}

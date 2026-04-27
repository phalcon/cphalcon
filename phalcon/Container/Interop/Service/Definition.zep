
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

interface Definition
{
    public function addExtender(var extender) -> <Definition>;

    public function buildService(object ioc) -> object;

    public function getClass() -> string;

    public function getExtenders() -> array;

    public function getFactory() -> var;

    public function getLifetime() -> string;

    public function getServiceName() -> string;

    public function hasClass() -> bool;

    public function hasExtenders() -> bool;

    public function hasFactory() -> bool;

    public function setClass(string! className) -> <Definition>;

    public function setExtenders(array extenders) -> <Definition>;

    public function setFactory(var factory) -> <Definition>;

    public function setLifetime(string! lifetime) -> <Definition>;

    public function unsetClass() -> <Definition>;

    public function unsetExtenders() -> <Definition>;

    public function unsetFactory() -> <Definition>;
}

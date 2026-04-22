
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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

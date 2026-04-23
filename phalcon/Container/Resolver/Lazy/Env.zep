
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

use Phalcon\Container\Exception\NotFound;
use Phalcon\Container\Resolver\Lazy\Lazy;
use TypeError;

class Env extends Lazy
{
    /**
     * @var string
     */
    protected varname;
    /**
     * @var string|null
     */
    protected vartype = null;

    public function __construct(string! varname, var vartype = null)
    {
        if unlikely (typeof vartype !== "string" && vartype !== null) {
            throw new TypeError("Argument 'vartype' must be string or null");
        }

        let this->varname = varname;
        let this->vartype = vartype;
    }

    public function resolve(object container) -> var
    {
        return this->cast(this->getEnv());
    }

    protected function cast(string! value) -> var
    {
        var castValue;

        let castValue = value;

        if this->vartype !== null {
            settype(castValue, this->vartype);
        }

        return castValue;
    }

    protected function getEnv() -> string
    {
        var envs;

        let envs = array_merge(_ENV, getenv());

        if !array_key_exists(this->varname, envs) {
            throw NotFound::envNotDefined(this->varname);
        }

        return envs[this->varname];
    }
}

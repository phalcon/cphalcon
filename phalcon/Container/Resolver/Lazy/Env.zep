
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

use Phalcon\Container\Exceptions\EnvNotDefined;

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

    /**
     * @param string      $varname
     * @param string|null $vartype
     */
    public function __construct(string varname, string vartype = null)
    {
        let this->varname = varname;
        let this->vartype = vartype;
    }

    /**
     * Resolve an environment variable
     *
     * @param object $container
     *
     * @return mixed
     * @throws EnvNotDefined
     */
    public function resolve(object container) -> mixed
    {
        return this->cast(this->getEnv());
    }

    /**
     * Cast a value to the defined type (if any)
     *
     * @param string $value
     *
     * @return mixed
     */
    protected function cast(var value) -> mixed
    {
        if (this->vartype !== null) {
            settype(value, this->vartype);
        }

        return value;
    }

    /**
     * Return the env value
     *
     * @return string
     * @throws EnvNotDefined
     */
    protected function getEnv() -> string
    {
        var envs;

        let envs = array_merge(_ENV, getenv());

        if (!array_key_exists(this->varname, envs)) {
            throw new EnvNotDefined(this->varname);
        }

        return envs[this->varname];
    }
}

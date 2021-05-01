
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use Phalcon\Factory\AbstractFactory;

/**
 * ServiceLocator implementation for helpers
 */
class HelperFactory extends AbstractFactory
{
    protected exception = "Phalcon\\Support\\Exception";

    /**
     * HelperFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * @param string $name
     * @param array  $arguments
     *
     * @return mixed
     * @throws Exception
     */
    public function __call(string name, array arguments)
    {
        var helper;

        let helper = this->newInstance(name);

        return call_user_func_array([helper, "__invoke"], arguments);
    }

    /**
     * @param string $name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string name)
    {
        return create_instance(this->getService(name));
    }

    /**
     * @return string[]
     */
    protected function getAdapters() -> array
    {
        return [
            "interpolate" : "Phalcon\\Support\\Helper\\Str\\Interpolate"
        ];
    }
}

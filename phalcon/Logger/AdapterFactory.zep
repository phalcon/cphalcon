
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use Exception as BaseException;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Adapter\Syslog;
use Throwable;

/**
 * Factory used to create adapters used for Logging
 */
class AdapterFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     *
     * @param array $services
     */
    public function __construct( array services = [])
    {
        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     *
     * @param string $name
     * @param string $fileName
     * @param array  $options
     *
     * @return AdapterInterface
     * @throws BaseException
     */
    public function newInstance(
         string name,
         string fileName,
        array options = []
    ) -> <AdapterInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance_params(
            definition,
            [
                fileName,
                options
            ]
        );
    }

    /**
     * @return class-string<Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "noop"   : Noop::class,
            "stream" : Stream::class,
            "syslog" : Syslog::class
        ];
    }
}

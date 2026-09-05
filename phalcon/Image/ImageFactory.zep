
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image;

use Exception as BaseException;
use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Image\ImageTypes;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Image\Adapter\AdapterInterface;
use Phalcon\Image\Adapter\Gd;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;

/**
 * Factory to create adapters for image manipulation
 *
 * @phpstan-import-type image_factory_config from ImageTypes
 * @phpstan-import-type image_factory_services from ImageTypes
 */
class ImageFactory extends AbstractFactory
{
    use GetTrait;

    /**
     * Constructor
     *
     * @phpstan-param image_factory_services $services
     */
    public function __construct(array services = [])
    {
        this->init(services);
    }

    /**
     * Factory to create an instance from a Config object
     *
     * @phpstan-param ConfigInterface|image_factory_config $config
     *
     * @param array|ConfigInterface config = [
     *     'adapter' => 'gd',
     *     'file' => 'image.jpg',
     *     'height' => null,
     *     'width' => null
     * ]
     */
    public function load(var config) -> <AdapterInterface>
    {
        var height, file, name, width;

        /** @phpstan-var image_factory_config $config */
        let config = this->checkConfig(config),
            config = this->checkConfigElement(config, "adapter"),
            config = this->checkConfigElement(config, "file");

        let name = config["adapter"];

        unset config["adapter"];

        let file   = this->getArrVal(config, "file"),
            height = this->getArrVal(config, "height", null),
            width  = this->getArrVal(config, "width", null);

        return this->newInstance(name, file, width, height);
    }

    /**
     * Creates a new instance
     *
     * @throws BaseException
     */
    public function newInstance(
         string name,
         string file,
        int width = null,
        int height = null
    ) -> <AdapterInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance_params(
            definition,
            [
                file,
                width,
                height
            ]
        );
    }

    /**
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @phpstan-return image_factory_services
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "gd"      : Gd::class,
            "imagick" : Imagick::class
        ];
    }
}

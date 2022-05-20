
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Image\Adapter\AdapterInterface;

/**
 * Phalcon\Image\ImageFactory
 */
class ImageFactory extends AbstractFactory
{
    /**
     * TagFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Factory to create an instance from a Config object
     *
     * @param array|\Phalcon\Config\Config config = [
     *     'adapter' => 'gd',
     *     'file' => 'image.jpg',
     *     'height' => null,
     *     'width' => null
     * ]
     */
    public function load(var config) -> <AdapterInterface>
    {
        var height, file, name, width;

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
     */
    public function newInstance(
        string! name,
        string! file,
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
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Image\\Exception";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "gd"      : "Phalcon\\Image\\Adapter\\Gd",
            "imagick" : "Phalcon\\Image\\Adapter\\Imagick"
        ];
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}

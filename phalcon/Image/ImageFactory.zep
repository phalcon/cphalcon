
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image;

use Phalcon\Config;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;
use Phalcon\Image\Adapter\AdapterInterface;

/**
 * Phalcon\Image/ImageFactory
 */
class ImageFactory extends AbstractFactory
{
    protected exception = "Phalcon\\Image\\Exception";

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
     * @param array|\Phalcon\Config config = [
     *     'adapter' => 'gd',
     *     'file' => 'image.jpg',
     *     'height' => null,
     *     'width' => null
     * ]
     */
    public function load(var config) -> <AdapterInterface>
    {
        var height, file, name, width;

        let config = this->checkConfig(config);

        if unlikely !isset config["file"] {
            throw new Exception(
                "You must provide 'file' option in factory config parameter."
            );
        }

        let name = config["adapter"];

        unset config["adapter"];

        let file   = Arr::get(config, "file"),
            height = Arr::get(config, "height", null),
            width  = Arr::get(config, "width", null);

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

    protected function getAdapters() -> array
    {
        return [
            "gd"      : "Phalcon\\Image\\Adapter\\Gd",
            "imagick" : "Phalcon\\Image\\Adapter\\Imagick"
        ];
    }
}

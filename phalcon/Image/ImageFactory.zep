
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image;

use Phalcon\Config\Config;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;
use Phalcon\Image\Adapter\AdapterInterface;

/**
 * Phalcon\Image/ImageFactory
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
     * Factory to create an instace from a Config object
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

        this->checkService(name);

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(file, width, height);
        }

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "gd"      : "\\Phalcon\\Image\\Adapter\\Gd",
            "imagick" : "\\Phalcon\\Image\\Adapter\\Imagick"
        ];
    }
}

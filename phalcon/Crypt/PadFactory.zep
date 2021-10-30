
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Crypt;

use Phalcon\Crypt\Padding\PadInterface;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

/**
 * Class PadFactory
 *
 * @package Phalcon\Crypt
 */
class PadFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string! name) -> <PadInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance(definition);
    }

    /**
     * Gets a Crypt pad constant and returns the unique service name for the
     * padding class
     *
     * @param int $number
     *
     * @return string
     */
    public function padNumberToService(int number) -> string
    {
        array map;

        let map = [
            Crypt::PADDING_ANSI_X_923     : "ansi",
            Crypt::PADDING_ISO_10126      : "iso10126",
            Crypt::PADDING_ISO_IEC_7816_4 : "isoiek",
            Crypt::PADDING_PKCS7          : "pjcs7",
            Crypt::PADDING_SPACE          : "space",
            Crypt::PADDING_ZERO           : "zero"
        ];

        return Arr::get(map, number, "noop");
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Crypt\\Exception\\Exception";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "ansi"     : "Phalcon\\Crypt\\Padding\\Ansi",
            "iso10126" : "Phalcon\\Crypt\\Padding\\Iso10126",
            "isoiek"   : "Phalcon\\Crypt\\Padding\\IsoIek",
            "noop"     : "Phalcon\\Crypt\\Padding\\Noop",
            "pjcs7"    : "Phalcon\\Crypt\\Padding\\Pkcs7",
            "space"    : "Phalcon\\Crypt\\Padding\\Space",
            "zero"     : "Phalcon\\Crypt\\Padding\\Zero"
        ];
    }
}

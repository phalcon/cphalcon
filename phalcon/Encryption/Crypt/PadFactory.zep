
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;
use Phalcon\Encryption\Crypt\Padding\Ansi;
use Phalcon\Encryption\Crypt\Padding\Iso10126;
use Phalcon\Encryption\Crypt\Padding\IsoIek;
use Phalcon\Encryption\Crypt\Padding\Noop;
use Phalcon\Encryption\Crypt\Padding\PadInterface;
use Phalcon\Encryption\Crypt\Padding\Pkcs7;
use Phalcon\Encryption\Crypt\Padding\Space;
use Phalcon\Encryption\Crypt\Padding\Zero;
use Phalcon\Factory\AbstractFactory;

/**
 * Factory for creating pad classes
 */
class PadFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     */
    public function __construct(array services = [])
    {
        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string name) -> <PadInterface>
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
            Crypt::PADDING_DEFAULT        : "noop",
            Crypt::PADDING_ANSI_X_923     : "ansi",
            Crypt::PADDING_ISO_10126      : "iso10126",
            Crypt::PADDING_ISO_IEC_7816_4 : "isoiek",
            Crypt::PADDING_PKCS7          : "pjcs7",
            Crypt::PADDING_SPACE          : "space",
            Crypt::PADDING_ZERO           : "zero"
        ];

        if unlikely !isset map[number] {
            throw this->getException(
                "Unknown padding constant " . number
            );
        }

        return map[number];
    }

    /**
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * @return array<string, string>
     */
    protected function getServices() -> array
    {
        return [
            "ansi"     : Ansi::class,
            "iso10126" : Iso10126::class,
            "isoiek"   : IsoIek::class,
            "noop"     : Noop::class,
            "pjcs7"    : Pkcs7::class,
            "pkcs7"    : Pkcs7::class,
            "space"    : Space::class,
            "zero"     : Zero::class
        ];
    }
}

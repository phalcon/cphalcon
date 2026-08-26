
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use Phalcon\Storage\Serializer\Exceptions\InvalidUnserializationInput;
use Phalcon\Traits\Php\SerializeTrait;

class Php extends AbstractSerializer
{
    use SerializeTrait;

    /**
     * Classes that unserialize() may instantiate: true (any class, the PHP
     * default), false (none) or a list of class names. Stored bytes that
     * try to build another class are rejected on read.
     */
    protected allowedClasses = true;

    /**
     * @return bool|array<int, string>
     */
    public function getAllowedClasses() -> var
    {
        return this->allowedClasses;
    }

    /**
     * Serializes data
     *
     * @return bool|float|int|string|null
     */
    public function serialize() -> mixed
    {
        if (true !== this->isSerializable(this->data)) {
            return this->data;
        }

        return this->phpSerialize(this->data);
    }

    /**
     * Restricts the classes that unserialize() may instantiate (see the
     * "allowed_classes" option of unserialize()).
     *
     * @param bool|array<int, string> $allowedClasses
     */
    public function setAllowedClasses(var allowedClasses) -> <static>
    {
        let this->allowedClasses = allowedClasses;

        return this;
    }

    /**
     * Unserializes data
     */
    public function unserialize(mixed data) -> void
    {
        var result;

        if (true !== this->isSerializable(data)) {
            let this->data = data;

            return;
        }

        if unlikely typeof data != "string" {
            throw new InvalidUnserializationInput();
        }

        globals_set("warning.enable", false);
        set_error_handler(
            function (number, message, file, line) {
                globals_set("warning.enable", true);
            },
            E_NOTICE | E_WARNING
        );

        let result = this->phpUnserialize(
            data,
            ["allowed_classes": this->allowedClasses]
        );

        restore_error_handler();

        /**
         * A class outside the allow-list comes back as
         * __PHP_Incomplete_Class: treat it as a failed unserialize.
         */
        if unlikely globals_get("warning.enable") || result === false ||
            (typeof result === "object" && get_class(result) === "__PHP_Incomplete_Class") {
            let this->isSuccess = false,
                result          = "";
        } else {
            let this->isSuccess = true;
        }

        let this->data = result;
    }

}


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

class Igbinary extends AbstractSerializer
{
    /**
     * Serializes data
     *
     * @return string
     */
    public function serialize()
    {
        var result;

        if (true !== this->isSerializable(this->data)) {
            return this->data;
        }

        let result = this->doSerialize(this->data);

        if unlikely null === result {
            let this->isSuccess = false,
                result          = "";
        }

        return result;
    }

    /**
     * Unserializes data
     *
     * @param string $data
     *
     * @return void
     */
	public function unserialize(var data) -> void
	{
	    var result, version;

        if (true !== this->isSerializable(data)) {
            let this->data = data;
        } else {
            let version = phpversion();

            globals_set("warning.enable", false);
            if version_compare(version, "8.0", ">=") {
                set_error_handler(
                    function (number, message, file, line) {
                        globals_set("warning.enable", true);
                    },
                    E_WARNING
                );
            } else {
                set_error_handler(
                    function (number, message, file, line, context) {
                        globals_set("warning.enable", true);
                    },
                    E_WARNING
                );
            }

            let result = this->doUnserialize(data);

            restore_error_handler();

            if unlikely globals_get("warning.enable") || false === result {
                let this->isSuccess = false,
                    result          = "";
            }

            let this->data = result;
        }
    }

    /**
     * Wrapper for `igbinary_serialize`
     *
     * @param mixed $value
     *
     * @return string|null
     */
    protected function phpIgbinarySerialize(var value) -> string | null
    {
        return igbinary_serialize(value);
    }

    /**
     * Serialize
     *
     * @param mixed $value
     *
     * @return string|null
     */
    protected function doSerialize(var value) -> string | null
    {
        return this->phpIgbinarySerialize(value);
    }

    /**
     * Unserialize
     *
     * @param string $value
     *
     * @return mixed|false
     */
    protected function doUnserialize(value)
    {
        return igbinary_unserialize(value);
    }
}

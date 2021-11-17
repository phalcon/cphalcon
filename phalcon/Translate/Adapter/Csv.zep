
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use ArrayAccess;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

/**
 * Class Csv
 *
 * @package Phalcon\Translate\Adapter
 *
 * @property array $translate
 */
class Csv extends AbstractAdapter implements ArrayAccess
{
    /**
     * @var array
     */
    protected translate = [];

    /**
     * Csv constructor.
     *
     * @param InterpolatorFactory $interpolator
     * @param array               $options = [
     *                                       'content'   => '',
     *                                       'delimiter' => ';',
     *                                       'enclosure' => '"'
     *                                       ]
     *
     * @throws Exception
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
        array options
    ) {
        var delimiter, enclosure;

        parent::__construct(interpolator, options);

        if unlikely !isset options["content"] {
            throw new Exception("Parameter 'content' is required");
        }

        if isset options["delimiter"] {
            let delimiter = options["delimiter"];
        } else {
            let delimiter = ";";
        }

        if isset options["enclosure"] {
            let enclosure = options["enclosure"];
        } else {
            let enclosure = "\"";
        }

        this->load(options["content"], 0, delimiter, enclosure);
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     * @deprecated
     */
    public function exists(string! index) -> bool
    {
        return this->has(index);
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     */
    public function has(string! index) -> bool
    {
        return isset this->translate[index];
    }

    /**
     * Returns the translation related to the given key
     *
     * @param string $translateKey
     * @param array  $placeholders
     *
     * @return string
     */
    public function query(string! translateKey, array placeholders = []) -> string
    {
        var translation;

        if !fetch translation, this->translate[translateKey] {
            let translation = translateKey;
        }

        return this->replacePlaceholders(translation, placeholders);
    }

    /**
     * Load translations from file
     *
     * @param string $file
     * @param int    $length
     * @param string $separator
     * @param string $enclosure
     *
     * @throws Exception
     */
    private function load(string file, int length, string delimiter, string enclosure) -> void
    {
        var data, fileHandler;

        let fileHandler = this->phpFopen(file, "rb");

        if unlikely typeof fileHandler !== "resource" {
            throw new Exception(
                "Error opening translation file '" . file . "'"
            );
        }

        loop {
            let data = fgetcsv(fileHandler, length, delimiter, enclosure);

            if data === false {
                break;
            }

            if substr(data[0], 0, 1) === "#" || !isset data[1] {
                continue;
            }

            let this->translate[data[0]] = data[1];
        }

        fclose(fileHandler);
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpFopen(string filename, string mode)
    {
        return fopen(filename, mode);
    }
}

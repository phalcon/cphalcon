
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
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
class Csv extends AbstractAdapter implements ArrayAccess
{
    /**
     * @var array
     */
    protected translate = [];

    /**
     * Phalcon\Translate\Adapter\Csv constructor
     *
     * @param array options = [
     *     'content' => '',
     *     'delimiter' => ';',
     *     'enclosure' => '"'
     * ]
     */
    public function __construct(<InterpolatorFactory> interpolator, array! options)
    {
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
     */
    public function exists(string! index) -> bool
    {
        return isset this->translate[index];
    }

    /**
     * Returns the translation related to the given key
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
    * Load translates from file
    */
    private function load(string file, int length, string delimiter, string enclosure) -> void
    {
        var data, fileHandler;

        let fileHandler = fopen(file, "rb");

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
}

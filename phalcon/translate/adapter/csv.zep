
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
class Csv extends Adapter implements \ArrayAccess
{

    protected translate = [];

    /**
     * Phalcon\Translate\Adapter\Csv constructor
     */
    public function __construct(array! options) -> void
    {
        var delimiter, enclosure;

        parent::__construct(options);

        if !isset options["content"] {
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
    public function query(string! index, placeholders = null) -> string
    {
        var translation;

        if !fetch translation, this->translate[index] {
            let translation = index;
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

        if typeof fileHandler !== "resource" {
            throw new Exception("Error opening translation file '" . file . "'");
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

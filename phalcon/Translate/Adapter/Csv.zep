
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Contracts\Translate\TranslateTypes;
use Phalcon\Traits\Php\FileTrait;
use Phalcon\Translate\Exception;
use Phalcon\Translate\Exceptions\FileOpenError;
use Phalcon\Translate\Exceptions\MissingRequiredParameter;
use Phalcon\Translate\InterpolatorFactory;

/**
 * @phpstan-import-type translate_csv_options from TranslateTypes
 * @phpstan-import-type translate_data from TranslateTypes
 * @phpstan-import-type translate_placeholders from TranslateTypes
 */
class Csv extends AbstractAdapter
{
    use FileTrait;

    /**
     * @phpstan-var translate_data
     */
    protected translate = [];

    /**
     * Csv constructor.
     *
     * @phpstan-param translate_csv_options $options
     *
     * @throws Exception
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
        array options
    ) {
        var delimiter, enclosure, escape;

        parent::__construct(interpolator, options);

        if unlikely !isset options["content"] {
            throw new MissingRequiredParameter("content");
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

        if isset options["escape"] {
            let escape = options["escape"];
        } else {
            let escape = "\\";
        }

        this->load(options["content"], 0, delimiter, enclosure, escape);
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     * @deprecated
     */
    public function exists( string index) -> bool
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
    public function has( string index) -> bool
    {
        return isset this->translate[index];
    }

    /**
     * Returns the translation related to the given key
     *
     * @phpstan-param translate_placeholders $placeholders
     *
     * @return string
     * @throws Exception
     */
    public function query( string translateKey, array placeholders = []) -> string
    {
        var translation;

        if !fetch translation, this->translate[translateKey] {
            let translation = this->notFound(translateKey);
        }

        return this->replacePlaceholders(translation, placeholders);
    }

    /**
     * Returns the internal array
     *
     * @phpstan-return translate_data
     */
    public function toArray() -> array
    {
        return this->translate;
    }

    /**
     * Load translations from file
     *
     * Lines whose first column begins with a `#` are treated as comments
     * and skipped.
     *
     * @phpstan-param int<0, max> $length
     *
     * @return void
     * @throws FileOpenError
     */
    private function load(
        string file, 
	int length, 
	string delimiter, 
	string enclosure, 
	string escape
    ) -> void {
        var data, fileHandler;

        let fileHandler = this->phpFopen(file, "rb");

        if unlikely typeof fileHandler !== "resource" {
            throw new FileOpenError(file);
        }

        loop {
            let data = this->phpFgetCsv(fileHandler, length, delimiter, enclosure, escape);

            if data === false {
                break;
            }

            if substr(data[0], 0, 1) === "#" || !isset data[1] {
                continue;
            }

            let this->translate[data[0]] = data[1];
        }

        this->phpFclose(fileHandler);
    }
}

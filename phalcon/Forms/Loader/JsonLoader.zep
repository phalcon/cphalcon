
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Loader;

use InvalidArgumentException;
use Phalcon\Contracts\Forms\Schema;
use Phalcon\Forms\Exception;
use Phalcon\Support\Helper\Json\Decode;

/**
 * Supplies form element definitions from a JSON string or file.
 *
 * When $source looks like an existing, readable file path it is read from
 * disk first; otherwise the value is treated as a raw JSON string.
 */
class JsonLoader implements Schema
{
    /**
     * @var string
     */
    protected source;

    /**
     * @param string $source JSON string or path to a JSON file
     */
    public function __construct(string source)
    {
        let this->source = source;
    }

    /**
     * @phpstan-return array<int, array<string, mixed>>
     * @throws Exception
     */
    public function load() -> array
    {
        var ex, definitions, json, loader;

        let json = this->source;

        if is_file(json) && is_readable(json) {
            let json = (string) this->phpFileGetContents(json);
        }

        try {
            let definitions = (new Decode())->__invoke(json, true, 512, JSON_THROW_ON_ERROR);
        } catch InvalidArgumentException, ex {
            throw new Exception("JSON form schema is invalid: " . ex->getMessage());
        }

        if typeof definitions !== "array" || !array_is_list(definitions) {
            throw new Exception("JSON form schema must decode to an array");
        }

        let loader = new ArrayLoader(definitions);

        return loader->load();
    }

    protected function phpFileGetContents(string filename)
    {
        return file_get_contents(filename);
    }
}

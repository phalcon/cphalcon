
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Loader;

use Phalcon\Contracts\Forms\Schema;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Exceptions\YamlExtensionRequired;
use Phalcon\Forms\Exceptions\YamlSchemaNotArray;

/**
 * Supplies form element definitions from a YAML string or file.
 *
 * Requires the PHP `yaml` extension (pecl/yaml).
 *
 * When $source is an existing, readable file path the file is parsed
 * directly; otherwise the value is treated as a raw YAML string.
 */
class YamlLoader implements Schema
{
    /**
     * @var string
     */
    protected source;

    /**
     * @param string $source YAML string or path to a YAML file
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
        var definitions, loader, source;

        if !extension_loaded("yaml") {
            throw new YamlExtensionRequired();
        }

        let source = this->source;

        if is_file(source) && is_readable(source) {
            let definitions = yaml_parse_file(source);
        } else {
            let definitions = yaml_parse(source);
        }

        if typeof definitions !== "array" {
            throw new YamlSchemaNotArray();
        }

        let loader = new ArrayLoader(definitions);

        return loader->load();
    }
}


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

/**
 * Supplies form element definitions from a PHP array.
 */
class ArrayLoader implements Schema
{
    /**
     * @var array
     */
    protected definitions;

    /**
     * @param array $definitions
     */
    public function __construct(array definitions)
    {
        let this->definitions = definitions;
    }

    /**
     * @return array
     * @throws Exception
     */
    public function load() -> array
    {
        var definition, index;

        for index, definition in this->definitions {
            this->validateDefinition(definition, (int) index);
        }

        return this->definitions;
    }

    /**
     * @param mixed $definition
     * @param int   $index
     *
     * @throws Exception
     */
    protected function validateDefinition(var definition, int index) -> void
    {
        if typeof definition !== "array" {
            throw new Exception(
                "Form schema definition at index " . index . " must be an array"
            );
        }

        if !isset definition["type"] || empty definition["type"] {
            throw new Exception(
                "Form schema definition at index " . index . " is missing required key \"type\""
            );
        }

        if !isset definition["name"] || empty definition["name"] {
            throw new Exception(
                "Form schema definition at index " . index . " is missing required key \"name\""
            );
        }
    }
}

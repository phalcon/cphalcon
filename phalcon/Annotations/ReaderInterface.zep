
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Contracts\Annotations\AnnotationsTypes;

/**
 * Reads the annotations of a class and returns them as an array
 *
 * Phalcon\Annotations\Reader reads the docblocks and Phalcon\Annotations\AttributesReader
 * reads the PHP attributes. The two give the same array shape, so the adapter
 * and the classes after it do not know which reader made it.
 *
 * @phpstan-import-type annotations_reflection_data from AnnotationsTypes
 */
interface ReaderInterface
{
    /**
     * Reads annotations from the class, its constants, properties and methods
     *
     * @phpstan-param class-string $className
     *
     * @phpstan-return annotations_reflection_data
     */
    public function parse(string className) -> array;
}

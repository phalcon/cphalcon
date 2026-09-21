
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Router;

use Phalcon\Contracts\Annotations\AnnotationsTypes;

/**
 * Marks a method as a route. It is the attribute form of `@Route`.
 *
 * The annotations service never makes an instance of this class. It reads the
 * arguments with ReflectionAttribute::getArguments(). The class gives the
 * name, the targets and the signature that an IDE and a static analyzer read.
 *
 * @phpstan-import-type annotations_route_before_match from AnnotationsTypes
 * @phpstan-import-type annotations_route_converters from AnnotationsTypes
 * @phpstan-import-type annotations_route_methods from AnnotationsTypes
 * @phpstan-import-type annotations_route_paths from AnnotationsTypes
 */
#[\Attribute(\Attribute::TARGET_METHOD | \Attribute::IS_REPEATABLE)]
class Route
{
    /**
     * @var array|string|null
     *
     * @phpstan-var annotations_route_before_match
     */
    public beforeMatch;

    /**
     * @var array
     *
     * @phpstan-var annotations_route_converters
     */
    public converters;

    /**
     * @var array|string|null
     *
     * @phpstan-var annotations_route_methods
     */
    public methods;

    /**
     * @var string|null
     */
    public name;

    /**
     * @var array
     *
     * @phpstan-var annotations_route_paths
     */
    public paths;

    /**
     * @var string
     */
    public route;

    /**
     * @phpstan-param annotations_route_methods      $methods
     * @phpstan-param annotations_route_paths        $paths
     * @phpstan-param annotations_route_converters   $converters
     * @phpstan-param annotations_route_before_match $beforeMatch
     */
    public function __construct(
        string route,
        var methods = null,
        string name = null,
        array paths = [],
        array converters = [],
        var beforeMatch = null
    ) {
        let this->route       = route,
            this->methods     = methods,
            this->name        = name,
            this->paths       = paths,
            this->converters  = converters,
            this->beforeMatch = beforeMatch;
    }
}

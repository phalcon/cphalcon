
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Mvc\Model\Relation;

/**
 * Interface for models that provide a custom unique key for the reusable
 * records cache in the Model Manager. Implement this interface when the
 * default object-identity based key (unique_key) does not produce stable
 * cache hits across multiple object instances that represent the same
 * database record.
 */
interface CacheKeyProvider
{
    /**
     * Returns a string that uniquely identifies this model instance for
     * use as the key in the reusable records cache.
     */
    public function getUniqueKey() -> string;
}

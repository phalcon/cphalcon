
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Collection;

use Phalcon\Support\Collection;
use Phalcon\Support\Collection\Exceptions\ReadOnlyViolation;

/**
 * A read only Collection object
 */
class ReadOnlyCollection extends Collection
{
    /**
     * @var bool
     */
    protected constructed = false;

    /**
     * ReadOnlyCollection constructor.
     *
     * @param array<int|string, mixed> $data
     * @param bool                     $insensitive
     * @param bool                     $strictNull
     * @param string|null              $type
     */
    public function __construct(
        array data = [],
        bool insensitive = true,
        bool strictNull = false,
        string type = null
    ) {
        parent::__construct(data, insensitive, strictNull, type);

        let this->constructed = true;
    }

    /**
     * Restores the collection state during unserialization.
     *
     * Temporarily disables the read-only guard so the parent class can restore
     * the collection state. The guard is re-enabled before the method returns.
     *
     * @param array $data
     */
    public function __unserialize(array data) -> void
    {
        var ex;

        let this->constructed = false;

        try {
            parent::__unserialize(data);
        } catch Throwable, ex {
            let this->constructed = true;
            
            throw ex;
        }
    }

    /**
     * @throws ReadOnlyViolation
     */
    public function clear() -> void
    {
        throw new ReadOnlyViolation();
    }

    /**
     * @throws ReadOnlyViolation
     */
    public function init(array data = []) -> void
    {
        if (this->constructed) {
            throw new ReadOnlyViolation();
        }

        parent::init(data);
    }

    /**
     * Delete the element from the collection
     *
     * @param string $element Name of the element
     *
     * @throws ReadOnlyViolation
     */
    public function remove(string element) -> void
    {
        throw new ReadOnlyViolation();
    }

    /**
     * Replaces the collection data with a new array
     *
     * @param array<int|string, mixed> $data
     *
     * @throws ReadOnlyViolation
     */
    public function replace(array data) -> void
    {
        throw new ReadOnlyViolation();
    }

    /**
     * Set an element in the collection
     *
     * @param string $element Name of the element
     * @param mixed  $value   Value to store for the element
     *
     * @throws ReadOnlyViolation
     */
    public function set(string element, var value) -> void
    {
        throw new ReadOnlyViolation();
    }
}

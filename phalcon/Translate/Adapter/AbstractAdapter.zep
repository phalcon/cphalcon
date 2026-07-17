
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
use Phalcon\Translate\Exceptions\ImmutableObject;
use Phalcon\Translate\Exceptions\KeyNotFound;
use Phalcon\Translate\InterpolatorFactory;
use Phalcon\Translate\Interpolator\InterpolatorInterface;

/**
 * @psalm-type TOptions array{
 *     defaultInterpolator?: string
 * }
 *
 * @template TKey of string
 * @template TValue of string
 * @implements ArrayAccess<TKey, TValue>
 */
abstract class AbstractAdapter implements AdapterInterface, ArrayAccess
{
    /**
     * @var string
     */
    protected defaultInterpolator = "";

    /**
     * @var InterpolatorInterface | null
     */
    protected interpolator = null;

    /**
    * @var InterpolatorFactory
    */
    protected interpolatorFactory;

    /**
     * @var bool
     */
    protected triggerError = false;

    /**
     * AbstractAdapter constructor.
     *
     * @param TOptions            $options
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
        array options = []
    ) {
        var error, value;

        if !fetch value, options["defaultInterpolator"] {
            let value = "associativeArray";
        }

        let this->defaultInterpolator = value,
            this->interpolatorFactory = interpolator;

        if fetch error, options["triggerError"] {
            let this->triggerError = (bool) error;
        }
    }

    /**
     * Returns the translation string of the given key (alias of method 't')
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    public function _( string translateKey, array placeholders = []) -> string
    {
        return this->query(translateKey, placeholders);
    }

    /**
     * Whenever a key is not found this method will be called
     *
     * @param string $index
     *
     * @return string
     * @throws Exception
     */
    public function notFound( string index) -> string
    {
        if unlikely (true === this->triggerError) {
            throw new KeyNotFound(index);
        }

        return index;
    }

    /**
     * Check whether a translation key exists
     *
     * @param mixed $translateKey
     *
     * @return bool
     */
    public function offsetExists(var translateKey) -> bool
    {
        return this->has(translateKey);
    }

    /**
     * Returns the translation related to the given key
     *
     * @param TKey $translateKey
     *
     * @return TValue
     */
    public function offsetGet(mixed translateKey) -> string | null
    {
        return this->query(translateKey);
    }

    /**
     * Sets a translation value
     *
     * @param mixed $offset
     * @param mixed $value
     *
     * @return void
     * @throws ImmutableObject
     */
    public function offsetSet(var offset, var value) -> void
    {
        throw new ImmutableObject();
    }

    /**
     * Unsets a translation from the dictionary
     *
     * @param mixed $offset
     *
     * @return void
     * @throws ImmutableObject
     */
    public function offsetUnset(var offset) -> void
    {
        throw new ImmutableObject();
    }

    /**
     * Returns the translation string of the given key
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    public function t( string translateKey, array placeholders = []) -> string
    {
        return this->query(translateKey, placeholders);
    }

    /**
     * Replaces placeholders by the values passed
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    protected function replacePlaceholders(
         string translation,
        array placeholders = []
    ) -> string {
        if null === this->interpolator {
            let this->interpolator = this->interpolatorFactory->newInstance(
                this->defaultInterpolator
            );
        }

        return this->interpolator->replacePlaceholders(
            translation,
            placeholders
        );
    }
}

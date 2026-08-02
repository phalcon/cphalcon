
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
use Phalcon\Translate\Interpolator\InterpolatorInterface;
use Phalcon\Translate\InterpolatorFactory;

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
    protected string defaultInterpolator = "";
    protected ?<InterpolatorInterface> interpolator = null;
    protected <InterpolatorFactory> interpolatorFactory;
    protected bool triggerError = false;

    /**
     * AbstractAdapter constructor.
     *
     * @param TOptions            $options
     */
    public function __construct(
        <InterpolatorFactory> interpolatorFactory,
        array options = []
    ) {
        var error, value;

        if !fetch value, options["defaultInterpolator"] {
            let value = "associativeArray";
        }

        let this->defaultInterpolator = value,
            this->interpolatorFactory = interpolatorFactory;

        if fetch error, options["triggerError"] {
            let this->triggerError = (bool) error;
        }
    }

    /**
     * Returns the translation string of the given key (alias of method 't')
     *
     * @phpstan-param array<string, string> $placeholders
     */
    public function _(string translateKey, array placeholders = []) -> string
    {
        return this->query(translateKey, placeholders);
    }

    /**
     * Whenever a key is not found this method will be called
     *
     * @throws KeyNotFound
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
     */
    public function offsetExists(var offset) -> bool
    {
        return this->has(offset);
    }

    /**
     * Returns the translation related to the given key
     *
     * @param TKey $offset
     *
     * @return TValue
     */
    public function offsetGet(mixed offset) -> string
    {
        return this->query(offset);
    }

    /**
     * Sets a translation value
     *
     * @throws ImmutableObject
     */
    public function offsetSet(var offset, var value) -> void
    {
        throw new ImmutableObject();
    }

    /**
     * Unsets a translation from the dictionary
     *
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
     * @throws Exception
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

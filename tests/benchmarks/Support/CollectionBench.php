<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Benchmarks\Support;

use Closure;
use Phalcon\Support\Collection;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class CollectionBench
{
    private Collection $collection;

    private int $counter = 0;

    private Closure $filterCallback;

    private array $filtered = [];

    private array $items = [];

    private Collection $itemsCollection;

    private string $json = '';

    public function setUp(): void
    {
        $this->collection = new Collection(
            [
                'one'   => 1,
                'three' => 3,
                'two'   => 2,
            ]
        );

        foreach (range(1, 10) as $number) {
            $this->items['key' . $number] = $number;
        }

        $this->filterCallback  = static fn (int $value): bool => $value > 5;
        $this->filtered        = array_filter($this->items, $this->filterCallback);
        $this->itemsCollection = new Collection($this->items);
        $this->json            = (string) json_encode($this->items, 79);
    }

    /**
     * A new collection with 10 items: init() calls setData() for each item.
     */
    public function benchConstruct(): void
    {
        $collection = new Collection($this->items);

        if ($this->items !== $collection->toArray()) {
            throw new RuntimeException('new Collection() stored unexpected data');
        }
    }

    /**
     * filter() keeps 5 of the 10 items and returns a new collection
     * (cloneEmpty()).
     */
    public function benchFilter(): void
    {
        $result = $this->itemsCollection->filter($this->filterCallback);

        if ($this->filtered !== $result->toArray()) {
            throw new RuntimeException('Collection::filter() returned unexpected data');
        }
    }

    public function benchGet(): void
    {
        if (2 !== $this->collection->get('two')) {
            throw new RuntimeException('Collection::get() returned an unexpected value');
        }
    }

    /**
     * Array access: offsetGet() calls get().
     */
    public function benchOffsetGet(): void
    {
        if (2 !== $this->collection['two']) {
            throw new RuntimeException('Collection::offsetGet() returned an unexpected value');
        }
    }

    /**
     * set() and then remove() of one key. The key must be there again for
     * the next call, so the subject also measures one set().
     */
    public function benchRemove(): void
    {
        $this->collection->set('four', 4);
        $this->collection->remove('four');

        if (3 !== $this->collection->count()) {
            throw new RuntimeException('Collection::remove() did not remove the key');
        }
    }

    /**
     * set() of a key that exists, with a new value on each call.
     */
    public function benchSet(): void
    {
        $this->counter++;

        $this->collection->set('two', $this->counter);

        if ($this->counter !== $this->collection->toArray()['two']) {
            throw new RuntimeException('Collection::set() did not store the value');
        }
    }

    /**
     * toJson() of 10 items: jsonSerialize() checks each value.
     */
    public function benchToJson(): void
    {
        if ($this->json !== $this->itemsCollection->toJson()) {
            throw new RuntimeException('Collection::toJson() returned an unexpected value');
        }
    }
}

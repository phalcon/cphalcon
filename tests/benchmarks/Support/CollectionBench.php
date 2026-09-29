<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Benchmarks\Support;

use Phalcon\Support\Collection;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class CollectionBench
{
    private Collection $collection;

    public function setUp(): void
    {
        $this->collection = new Collection(
            [
                'one'   => 1,
                'three' => 3,
                'two'   => 2,
            ]
        );
    }

    public function benchGet(): void
    {
        if (2 !== $this->collection->get('two')) {
            throw new RuntimeException('Collection::get() returned an unexpected value');
        }
    }
}

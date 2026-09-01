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

namespace Phalcon\Tests\Unit\Support\Collection;

use Phalcon\Support\Collection;

use function strcmp;

use const SORT_DESC;

final class SortTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionSortAscByDefault(): void
    {
        $collection = new Collection(['b' => 2, 'a' => 1, 'c' => 3]);

        $sorted = $collection->sort();

        $this->assertSame(['a' => 1, 'b' => 2, 'c' => 3], $sorted->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionSortDesc(): void
    {
        $collection = new Collection(['b' => 2, 'a' => 1, 'c' => 3]);

        $sorted = $collection->sort(null, SORT_DESC);

        $this->assertSame(['c' => 3, 'b' => 2, 'a' => 1], $sorted->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionSortDoesNotMutateOriginal(): void
    {
        $collection = new Collection(['b' => 2, 'a' => 1]);
        $collection->sort();

        $this->assertSame(['b' => 2, 'a' => 1], $collection->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionSortWithCallbackPreservesKeys(): void
    {
        $collection = new Collection([
            'a' => 'banana',
            'b' => 'apple',
            'c' => 'cherry',
        ]);

        $sorted = $collection->sort(static fn ($x, $y) => strcmp($x, $y));

        $this->assertSame(
            ['b' => 'apple', 'a' => 'banana', 'c' => 'cherry'],
            $sorted->toArray()
        );
    }
}

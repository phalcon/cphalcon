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

final class ReduceTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionReducePassesKeyToCallback(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2]);

        $result = $collection->reduce(
            static fn ($acc, $v, $k) => $acc . $k . $v,
            ''
        );

        $this->assertSame('a1b2', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionReduceReturnsInitialWhenEmpty(): void
    {
        $collection = new Collection();

        $this->assertSame(
            'seed',
            $collection->reduce(static fn ($a, $v) => $v, 'seed')
        );
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionReduceSumsValues(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2, 'c' => 3]);

        $sum = $collection->reduce(static fn ($acc, $v) => $acc + $v, 0);

        $this->assertSame(6, $sum);
    }
}

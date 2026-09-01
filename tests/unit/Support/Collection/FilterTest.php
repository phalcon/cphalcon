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

use function strlen;

final class FilterTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionFilterPassesKeyToCallback(): void
    {
        $collection = new Collection(['a' => 1, 'bb' => 2, 'ccc' => 3]);

        $filtered = $collection->filter(static fn ($v, $k) => strlen((string) $k) > 1);

        $this->assertSame(['bb' => 2, 'ccc' => 3], $filtered->toArray());
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionFilterReturnsNewCollection(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2, 'c' => 3]);

        $filtered = $collection->filter(static fn ($v) => $v > 1);

        $this->assertNotSame($collection, $filtered);
        $this->assertSame(['b' => 2, 'c' => 3], $filtered->toArray());
        $this->assertSame(['a' => 1, 'b' => 2, 'c' => 3], $collection->toArray());
    }
}

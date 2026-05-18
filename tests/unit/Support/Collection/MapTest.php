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

final class MapTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionMapPreservesKeys(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2]);

        $mapped = $collection->map(static fn ($v) => $v * 10);

        $this->assertSame(['a' => 10, 'b' => 20], $mapped->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionMapPassesKeyToCallback(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2]);

        $mapped = $collection->map(static fn ($v, $k) => "$k=$v");

        $this->assertSame(['a' => 'a=1', 'b' => 'b=2'], $mapped->toArray());
    }
}

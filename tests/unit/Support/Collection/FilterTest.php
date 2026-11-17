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

namespace Phalcon\Tests\Unit\Support\Collection;

use Error;
use Phalcon\Support\Collection;
use Throwable;

use function strlen;

final class FilterTest extends AbstractCollectionTestCase
{
    /**
     * A callback that cannot be called throws Error with the cphalcon message.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testSupportCollectionFilterNotCallable(): void
    {
        $collection = new Collection(['a' => 1]);

        $actual = null;
        try {
            $collection->filter('nope');
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame([Error::class, 'Call to undefined function nope()'], $actual);
    }

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

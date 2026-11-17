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

final class EachTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionEachInvokesCallbackForEachItem(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2, 'c' => 3]);
        $seen       = [];

        $collection->each(
            function ($value, $key) use (&$seen) {
                $seen[$key] = $value;
            }
        );

        $this->assertSame(['a' => 1, 'b' => 2, 'c' => 3], $seen);
    }

    /**
     * A callback that cannot be called throws Error with the cphalcon message.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testSupportCollectionEachNotCallable(): void
    {
        $collection = new Collection(['a' => 1]);

        $actual = null;
        try {
            $collection->each('nope');
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame([Error::class, 'Call to undefined function nope()'], $actual);
    }

    /**
     * With no items, a callback that cannot be called is not called.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testSupportCollectionEachNotCallableEmpty(): void
    {
        $collection = new Collection();

        $this->assertSame($collection, $collection->each('nope'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionEachReturnsSelf(): void
    {
        $collection = new Collection(['a' => 1]);

        $this->assertSame(
            $collection,
            $collection->each(static fn () => null)
        );
    }
}

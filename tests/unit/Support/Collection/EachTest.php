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

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
use Phalcon\Support\Collection\Exception;
use Phalcon\Support\Collection\ReadOnlyCollection;

final class ReplaceTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-11
     */
    public function testSupportCollectionReplaceClearsAndLoads(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2]);

        $collection->replace(['c' => 3]);

        $this->assertSame(['c' => 3], $collection->toArray());
        $this->assertFalse($collection->has('a'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-11
     */
    public function testSupportCollectionReplaceEmpty(): void
    {
        $collection = new Collection(['a' => 1]);

        $collection->replace([]);

        $this->assertSame([], $collection->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-11
     */
    public function testSupportCollectionReplaceThrowsOnReadOnly(): void
    {
        $this->expectException(Exception::class);

        $collection = new ReadOnlyCollection(['a' => 1]);
        $collection->replace(['b' => 2]);
    }
}

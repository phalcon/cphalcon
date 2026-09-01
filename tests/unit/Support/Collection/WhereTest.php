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

final class WhereTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionWhereFiltersByArrayKeyValue(): void
    {
        $collection = new Collection([
            'a' => ['active' => true,  'name' => 'Alice'],
            'b' => ['active' => false, 'name' => 'Bob'],
            'c' => ['active' => true,  'name' => 'Charlie'],
        ]);

        $filtered = $collection->where('active', true);

        $this->assertSame(['a', 'c'], $filtered->keys(false));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionWhereReturnsEmptyWhenNoMatches(): void
    {
        $collection = new Collection(['a' => ['x' => 1]]);

        $this->assertTrue($collection->where('x', 999)->isEmpty());
    }
}

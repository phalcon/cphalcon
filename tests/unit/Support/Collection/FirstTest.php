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

use PHPUnit\Framework\Attributes\DataProvider;

final class FirstTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-11
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionFirstReturnsFirstValue(string $class): void
    {
        $collection = new $class(['a' => 1, 'b' => 2, 'c' => 3]);

        $this->assertSame(1, $collection->first());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-11
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionFirstReturnsNullWhenEmpty(string $class): void
    {
        $collection = new $class();

        $this->assertNull($collection->first());
    }
}

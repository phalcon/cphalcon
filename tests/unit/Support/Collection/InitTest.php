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

final class InitTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionInit(): void
    {
        $data = $this->getData();
        $collection = new Collection();

        $expected = 0;
        $actual = $collection->count();
        $this->assertSame($expected, $actual);

        $collection->init($data);

        $expected = $data;
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-11
     */
    public function testSupportCollectionReadOnlyInitThrows(): void
    {
        $this->expectException(Exception::class);

        (new ReadOnlyCollection())->init(['a' => 1]);
    }
}

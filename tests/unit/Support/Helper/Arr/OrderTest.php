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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Order;
use Phalcon\Tests\AbstractUnitTestCase;

final class OrderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrOrder(): void
    {
        $object = new Order();
        $collection = [
            [
                'id'   => 2,
                'name' => 'Paul',
            ],
            [
                'id'   => 3,
                'name' => 'Peter',
            ],
            [
                'id'   => 1,
                'name' => 'John',
            ],
        ];

        $expected = [
            [
                'id'   => 1,
                'name' => 'John',
            ],
            [
                'id'   => 2,
                'name' => 'Paul',
            ],
            [
                'id'   => 3,
                'name' => 'Peter',
            ],
        ];
        $actual = $object($collection, 'id');
        $this->assertSame($expected, $actual);

        $expected = [
            [
                'id'   => 3,
                'name' => 'Peter',
            ],
            [
                'id'   => 2,
                'name' => 'Paul',
            ],
            [
                'id'   => 1,
                'name' => 'John',
            ],
        ];
        $actual = $object($collection, 'id', $object::ORDER_DESC);
        $this->assertSame($expected, $actual);

        $collection = [
            (object)[
                'id'   => 2,
                'name' => 'Paul',
            ],
            (object)[
                'id'   => 3,
                'name' => 'Peter',
            ],
            (object)[
                'id'   => 1,
                'name' => 'John',
            ],
        ];

        $expected = [
            (object)[
                'id'   => 1,
                'name' => 'John',
            ],
            (object)[
                'id'   => 2,
                'name' => 'Paul',
            ],
            (object)[
                'id'   => 3,
                'name' => 'Peter',
            ],
        ];
        $actual = $object($collection, 'id');
        $this->assertEquals($expected, $actual);
    }
}

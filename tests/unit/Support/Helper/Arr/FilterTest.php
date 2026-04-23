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

use Phalcon\Support\Helper\Arr\Filter;
use Phalcon\Tests\AbstractUnitTestCase;

final class FilterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrFilter(): void
    {
        $object = new Filter();
        $collection = [
            1  => 1,
            2  => 2,
            3  => 3,
            4  => 4,
            5  => 5,
            6  => 6,
            7  => 7,
            8  => 8,
            9  => 9,
            10 => 10,
        ];

        $expected = [
            1 => 1,
            3 => 3,
            5 => 5,
            7 => 7,
            9 => 9,
        ];
        $actual = $object->__invoke(
            $collection,
            function ($element) {
                return $element & 1;
            },
        );
        $this->assertSame($expected, $actual);
    }
}

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

use Phalcon\Support\Helper\Arr\SliceRight;
use Phalcon\Tests\AbstractUnitTestCase;

final class SliceRightTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrSliceRight(): void
    {
        $object = new SliceRight();
        $collection = [
            'Phalcon',
            'Framework',
            'for',
            'PHP',
        ];

        $expected = [
            'Framework',
            'for',
            'PHP',
        ];
        $actual = $object($collection, 1);
        $this->assertSame($expected, $actual);

        $expected = [
            'PHP',
        ];
        $actual = $object($collection, 3);
        $this->assertSame($expected, $actual);
    }
}

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

use Phalcon\Support\Helper\Arr\Last;
use Phalcon\Tests\AbstractUnitTestCase;

use function strlen;

final class LastTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrLast(): void
    {
        $object = new Last();
        $collection = [
            'Phalcon',
            'Framework',
        ];

        $expected = 'Framework';
        $actual = $object($collection);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrLastFunction(): void
    {
        $object = new Last();
        $collection = [
            'Phalcon',
            'Framework',
        ];

        $expected = 'Phalcon';
        $actual = $object(
            $collection,
            function ($element) {
                return strlen($element) < 8;
            },
        );
        $this->assertSame($expected, $actual);
    }
}

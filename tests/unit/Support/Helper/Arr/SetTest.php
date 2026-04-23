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

use Phalcon\Support\Helper\Arr\Set;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrSetNoIndex(): void
    {
        $object = new Set();
        $collection = [];

        $expected = [
            0 => 'Phalcon',
        ];
        $actual = $object($collection, 'Phalcon');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrSetNumeric(): void
    {
        $object = new Set();
        $collection = [];

        $expected = [
            1 => 'Phalcon',
        ];
        $actual = $object($collection, 'Phalcon', 1);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrSetOverwride(): void
    {
        $object = new Set();
        $collection = [
            1 => 'Phalcon',
        ];

        $expected = [
            1 => 'Framework',
        ];
        $actual = $object($collection, 'Framework', 1);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrSetString(): void
    {
        $object = new Set();
        $collection = [];

        $expected = [
            'suffix' => 'Framework',
        ];
        $actual = $object($collection, 'Framework', 'suffix');
        $this->assertSame($expected, $actual);
    }
}

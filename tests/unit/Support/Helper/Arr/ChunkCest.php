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

use Phalcon\Support\Helper\Arr\Chunk;
use UnitTester;

/**
 * Class ChunkCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class ChunkCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: chunk()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrChunk(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - chunk()');

        $source = [
            'k1' => 1,
            'k2' => 2,
            'k3' => 3,
            'k4' => 4,
            'k5' => 5,
            'k6' => 6,
        ];

        $object   = new Chunk();
        $expected = [
            [1, 2],
            [3, 4],
            [5, 6],
        ];
        $actual   = $object($source, 2);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: chunk() - preserve
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrChunkPreserve(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - chunk() - preserve');

        $source = [
            'k1' => 1,
            'k2' => 2,
            'k3' => 3,
            'k4' => 4,
            'k5' => 5,
            'k6' => 6,
        ];

        $object   = new Chunk();
        $expected = [
            [
                'k1' => 1,
                'k2' => 2,
            ],
            [
                'k3' => 3,
                'k4' => 4,
            ],
            [
                'k5' => 5,
                'k6' => 6,
            ],
        ];
        $actual   = $object($source, 2, true);
        $I->assertEquals($expected, $actual);
    }
}

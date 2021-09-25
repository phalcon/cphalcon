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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class ChunkCest
{
    /**
     * Tests Phalcon\Helper\Arr :: chunk()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrChunk(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - chunk()');

        $source = [
            'k1' => 1,
            'k2' => 2,
            'k3' => 3,
            'k4' => 4,
            'k5' => 5,
            'k6' => 6,
        ];

        $expected = [
            [1, 2],
            [3, 4],
            [5, 6],
        ];

        $I->assertEquals(
            $expected,
            Arr::chunk($source, 2)
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: chunk() - preserve
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrChunkPreserve(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - chunk() - preserve');

        $source = [
            'k1' => 1,
            'k2' => 2,
            'k3' => 3,
            'k4' => 4,
            'k5' => 5,
            'k6' => 6,
        ];

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

        $I->assertEquals(
            $expected,
            Arr::chunk($source, 2, true)
        );
    }
}

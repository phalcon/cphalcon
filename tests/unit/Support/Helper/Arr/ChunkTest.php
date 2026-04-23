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
use Phalcon\Tests\AbstractUnitTestCase;

final class ChunkTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrChunk(): void
    {
        $source = [
            'k1' => 1,
            'k2' => 2,
            'k3' => 3,
            'k4' => 4,
            'k5' => 5,
            'k6' => 6,
        ];

        $object = new Chunk();
        $expected = [
            [1, 2],
            [3, 4],
            [5, 6],
        ];
        $actual = $object($source, 2);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrChunkPreserve(): void
    {
        $source = [
            'k1' => 1,
            'k2' => 2,
            'k3' => 3,
            'k4' => 4,
            'k5' => 5,
            'k6' => 6,
        ];

        $object = new Chunk();
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
        $actual = $object($source, 2, true);
        $this->assertSame($expected, $actual);
    }
}

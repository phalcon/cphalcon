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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Tests\AbstractUnitTestCase;

class LengthTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array{0: mixed, 1: int}>
     */
    public static function provideLength(): array
    {
        return [
            [null, 0],
            ['hello', 5],
            [[1, 2, 3], 3],
        ];
    }

    /**
     * @dataProvider provideLength
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltLength(mixed $item, int $expected): void
    {
        $volt = new Volt(new View());
        $this->assertSame($expected, $volt->length($item));
    }
}

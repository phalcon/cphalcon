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

class SliceTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array{0: mixed, 1: int, 2: int|null, 3: mixed}>
     */
    public static function provideSlice(): array
    {
        return [
            ['hello', 1, null, 'ello'],
            ['hello', 0, 2, 'hel'],
            [[0, 1, 2, 3], 1, 2, [1, 2]],
        ];
    }

    /**
     * @dataProvider provideSlice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltSlice(mixed $value, int $start, int|null $end, mixed $expected): void
    {
        $volt = new Volt(new View());
        $this->assertSame($expected, $volt->slice($value, $start, $end));
    }
}

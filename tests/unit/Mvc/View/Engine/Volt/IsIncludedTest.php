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

class IsIncludedTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array{0: mixed, 1: array<int, string>|string, 2: bool}>
     */
    public static function provideIsIncluded(): array
    {
        return [
            ['o', 'hello', true],
            ['z', 'hello', false],
            ['b', ['a', 'b', 'c'], true],
            ['d', ['a', 'b', 'c'], false],
        ];
    }

    /**
     * @dataProvider provideIsIncluded
     *
     * @param array<int, string>|string $haystack
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltIsIncluded(mixed $needle, array|string $haystack, bool $expected): void
    {
        $volt = new Volt(new View());
        $this->assertSame($expected, $volt->isIncluded($needle, $haystack));
    }
}

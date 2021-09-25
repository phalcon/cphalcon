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

namespace Phalcon\Tests\Unit\Filter\Sanitize;

use Codeception\Example;
use Phalcon\Filter\Sanitize\IntVal;
use UnitTester;

class IntValCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\IntVal :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeIntValInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\IntVal - __invoke()');

        $sanitizer = new IntVal();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            [1000, 1000],
            [0xFFA, 0xFFA],
            ['1000', '1000'],
            ['lol', 0],
            ['!100a019.01a', 10001901],
        ];
    }
}

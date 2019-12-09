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

namespace Phalcon\Test\Unit\Filter\Sanitize;

use Codeception\Example;
use Phalcon\Filter\Sanitize\Alnum;
use UnitTester;

class AlnumCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Alnum :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeAlnumInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Alnum - __invoke()');

        $sanitizer = new Alnum();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            ['0', 0],
            ['', null],
            ['?a&5xka\tŧ?1-s.Xa[\n', 'a5xkat1sXan'],
        ];
    }
}

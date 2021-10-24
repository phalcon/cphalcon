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
use Phalcon\Filter\Sanitize\Regex;
use UnitTester;

class RegexCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Regex :: __invoke()
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function filterSanitizeRegexInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Regex - __invoke()');

        $sanitizer = new Regex();

        $actual = $sanitizer($example[0], $example[1], $example[2]);
        $I->assertEquals($example[3], $actual);
    }

    /**
     * @return string[][]
     */
    private function getData(): array
    {
        return [
            ['mary abc a little lamb', '/abc/', 'had', 'mary had a little lamb'],
        ];
    }
}

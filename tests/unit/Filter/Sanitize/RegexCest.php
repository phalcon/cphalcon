<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Filter\Sanitize;

use Codeception\Example;
use Phalcon\Filter\Sanitize\Regex;
use UnitTester;

/**
 * Class RegexCest
 */
class RegexCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Email :: __invoke()
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function filterSanitizeRegexInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Regex - __invoke()');

        $sanitizer = new Regex();

        $actual = $sanitizer($example[0], $example[1], $example[2]);
        $I->assertEquals($example[3], $actual);
    }

    /**
     * @return array
     */
    private function getData(): array
    {
        return [
            ['mary abc a little lamb', '/abc/', 'had', 'mary had a little lamb'],
        ];
    }
}

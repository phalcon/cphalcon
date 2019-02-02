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
use function number_format;
use Phalcon\Filter\Sanitize\FloatVal;
use UnitTester;

/**
 * Class FloatValCest
 */
class FloatValCest
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
    public function filterSanitizeFloatValInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\FloatVal - __invoke()');

        $sanitizer = new FloatVal();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    /**
     * Tests Phalcon\Filter\Sanitize\Email :: __invoke()
     * This is on its own to align the float values (fraction)
     *
     * @param UnitTester $I
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function filterSanitizeFloatValInvokeFloat(UnitTester $I)
    {
        $I->wantToTest('Filter\Sanitize\FloatVal - __invoke() - float');

        $sanitizer = new FloatVal();

        $actual   = number_format($sanitizer('!10001901.01a'), 3);
        $expected = '10,001,901.010';
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getData(): array
    {
        return [
            ['1000.01', 1000.01],
            [0xFFA, 0xFFA],
            ['lol', 0.0],
        ];
    }
}

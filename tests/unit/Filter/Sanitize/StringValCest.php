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
use Phalcon\Filter\Sanitize\StringVal;
use UnitTester;

/**
 * Class StringValCest
 */
class StringValCest
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
    public function filterSanitizeStringValInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\StringVal - __invoke()');

        $sanitizer = new StringVal();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    /**
     * @return array
     */
    private function getData(): array
    {
        return [
            [
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>',
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+',
            ],
            [
                "{[<within french quotes>]}",
                '{[]}',
            ],
            [
                'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>',
                'buenos días123καλημέρα!@#$%^&*早安()_ `~=+',
            ],
            [
                '{[<buenos días 123 καλημέρα! 早安>]}',
                '{[]}',
            ],
        ];
    }
}

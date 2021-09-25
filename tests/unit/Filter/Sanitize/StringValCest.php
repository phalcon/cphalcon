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
use Phalcon\Filter\Sanitize\StringVal;
use UnitTester;

class StringValCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\StringVal :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeStringValInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\StringVal - __invoke()');

        $sanitizer = new StringVal();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            [
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>',
                'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+',
            ],
            [
                '{[<within french quotes>]}',
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

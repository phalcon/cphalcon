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
use Phalcon\Filter\Sanitize\Url;
use UnitTester;

class UrlCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Url :: __invoke()
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function filterSanitizeUrlInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Url - __invoke()');

        $sanitizer = new Url();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    /**
     * @return string[][]
     */
    private function getData(): array
    {
        return [
            ['https://pha�lc�on.i�o', 'https://phalcon.io'],
        ];
    }
}

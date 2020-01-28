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
use Phalcon\Filter\Sanitize\Url;
use UnitTester;

class UrlCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Url :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeUrlInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Url - __invoke()');

        $sanitizer = new Url();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            ['http://juhara��.co�m', 'http://juhara.com'],
        ];
    }
}

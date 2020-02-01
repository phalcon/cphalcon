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
use Phalcon\Filter\Sanitize\SpecialFull;
use UnitTester;

class SpecialFullCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\SpecialFull :: __invoke()
     *
     * @dataProvider getData
     */
    public function filterSanitizeSpecialFullInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\SpecialFull - __invoke()');

        $sanitizer = new SpecialFull();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            ['This is <html> tags', 'This is &lt;html&gt; tags'],
        ];
    }
}

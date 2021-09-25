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
use Phalcon\Filter\Sanitize\UpperFirst;
use UnitTester;

class UpperFirstCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\UpperFirst :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeUpperFirstInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\UpperFirst - __invoke()');

        $sanitizer = new UpperFirst();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            ['test', 'Test'],
            ['tEsT', 'TEsT'],
            ['TEST', 'TEST'],
        ];
    }
}

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
use Phalcon\Filter\Sanitize\Trim;
use UnitTester;

class TrimCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Trim :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeTrimInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Trim - __invoke()');

        $sanitizer = new Trim();

        $I->assertEquals(
            $example[1],
            $sanitizer($example[0])
        );
    }

    private function getData(): array
    {
        return [
            ['    Hello', 'Hello'],
            ['Hello    ', 'Hello'],
            ['  Hello    ', 'Hello'],
        ];
    }
}

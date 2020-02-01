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
use Phalcon\Filter\Sanitize\Replace;
use UnitTester;

class ReplaceCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Replace :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeReplaceInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Replace - __invoke()');

        $sanitizer = new Replace();
        $actual    = $sanitizer($example[0], $example[1], $example[2]);
        $I->assertEquals($example[3], $actual);
    }

    private function getData(): array
    {
        return [
            ['test test', 'e', 'a', 'tast tast'],
            ['tEsT tEsT', 'E', 'A', 'tAsT tAsT'],
            ['TEST TEST', 'E', 'A', 'TAST TAST'],
        ];
    }
}

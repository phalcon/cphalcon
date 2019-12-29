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
use Phalcon\Filter\Sanitize\Alpha;
use UnitTester;

class AlphaCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Alpha :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeAlphaInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Alpha - __invoke()');

        $sanitizer = new Alpha();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    private function getData(): array
    {
        return [
            ['0', ''],
            ['', null],
            ['a5@xkat1s!Xan', 'axkatsXan'],
        ];
    }
}

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
use Phalcon\Filter\Sanitize\Remove;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Remove :: __invoke()
     *
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterSanitizeRemoveInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Remove - __invoke()');

        $sanitizer = new Remove();

        $actual = $sanitizer($example[0], $example[1]);
        $I->assertEquals($example[2], $actual);
    }

    private function getData(): array
    {
        return [
            ['mary had a little lamb', 'a', 'mry hd  little lmb'],
        ];
    }
}

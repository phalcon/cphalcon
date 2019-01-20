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
use Phalcon\Filter\Sanitize\Remove;
use UnitTester;

/**
 * Class RemoveCest
 */
class RemoveCest
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
    public function filterSanitizeRemoveInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Remove - __invoke()');

        $sanitizer = new Remove();

        $actual = $sanitizer($example[0], $example[1]);
        $I->assertEquals($example[2], $actual);
    }

    /**
     * @return array
     */
    private function getData(): array
    {
        return [
            ['mary had a little lamb', 'a', 'mry hd  little lmb'],
        ];
    }
}

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
use Phalcon\Filter\Sanitize\Lower;
use UnitTester;

/**
 * Class LowerCest
 */
class LowerCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Lower :: __invoke()
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function filterSanitizeLowerInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\Sanitize\Lower - __invoke()');

        $sanitizer = new Lower();

        $actual = $sanitizer($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    /**
     * @return array
     */
    private function getData(): array
    {
        return [
            ['test', 'test'],
            ['tEsT', 'test'],
            ['TEST', 'test'],
        ];
    }
}

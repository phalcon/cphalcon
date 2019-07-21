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

namespace Phalcon\Test\Unit\Text;

use Codeception\Example;
use Phalcon\Text;
use UnitTester;

class ReduceSlashesCest
{
    /**
     * Tests Phalcon\Text :: reduceSlashes()
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     *
     * @dataProvider textReduceSlashesProvider
     */
    public function textReduceSlashes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - reduceSlashes()');

        $I->assertEquals(
            $example['expected'],
            Text::reduceSlashes($example['string'])
        );
    }

    private function textReduceSlashesProvider(): array
    {
        return [
            [
                'string'   => 'app/controllers//IndexController',
                'expected' => 'app/controllers/IndexController',
            ],

            [
                'string'   => 'http://foo//bar/baz/buz',
                'expected' => 'http://foo/bar/baz/buz',
            ],

            [
                'string'   => 'php://memory',
                'expected' => 'php://memory',
            ],

            [
                'string'   => 'http//https',
                'expected' => 'http/https',
            ],
        ];
    }
}

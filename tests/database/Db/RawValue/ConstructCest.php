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

namespace Phalcon\Test\Database\Db\RawValue;

use Codeception\Example;
use DatabaseTester;
use Phalcon\Db\RawValue;

class ConstructCest
{
    /**
     * Tests Phalcon\Db\RawValue :: __construct()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-04-17
     *
     * @dataProvider valueProvider
     */
    public function dbRawvalueConstruct(DatabaseTester $I, Example $example)
    {
        $I->wantToTest('Db\RawValue - __construct()');

        $rawValue = new RawValue(
            $example['value']
        );

        $I->assertEquals(
            $example['expected'],
            $rawValue->getValue()
        );
    }

    private function valueProvider(): array
    {
        return [
            [
                'value'    => 'hello',
                'expected' => 'hello',
            ],

            [
                'value'    => null,
                'expected' => 'NULL',
            ],

            [
                'value'    => 123,
                'expected' => '123',
            ],

            [
                'value'    => '',
                'expected' => "''",
            ],
        ];
    }
}

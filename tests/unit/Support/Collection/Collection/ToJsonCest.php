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

namespace Phalcon\Tests\Unit\Support\Collection\Collection;

use Codeception\Util\Stub;
use Phalcon\Support\Collection;
use UnitTester;

class ToJsonCest
{
    /**
     * Tests Phalcon\Support\Collection :: toJson()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionToJson(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - toJson()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $expected = json_encode($data);
        $actual   = $collection->toJson();
        $I->assertEquals($expected, $actual);

        $expected = json_encode($data, JSON_PRETTY_PRINT);
        $actual   = $collection->toJson(JSON_PRETTY_PRINT);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Collection :: toJson() - encode fail
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionToJsonEncodeFail(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - toJson() - encode fail');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = Stub::construct(
            Collection::class,
            [
                $data,
            ],
            [
                'phpJsonEncode' => false,
            ]
        );

        $actual = $collection->toJson();
        $I->assertEmpty($actual);
    }
}

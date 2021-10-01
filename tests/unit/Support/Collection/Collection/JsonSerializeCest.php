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

use Phalcon\Support\Collection;
use Phalcon\Tests\Fixtures\JsonFixture;
use UnitTester;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Support\Collection :: jsonSerialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionJsonSerialize(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - jsonSerialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $expected = $data;
        $actual   = $collection->jsonSerialize();
        $I->assertEquals($expected, $actual);

        $data = [
            'one'    => 'two',
            'three'  => 'four',
            'five'   => 'six',
            'object' => new JsonFixture(),
        ];

        $expected = [
            'one'    => 'two',
            'three'  => 'four',
            'five'   => 'six',
            'object' => [
                'one' => 'two',
            ],
        ];

        $collection = new Collection($data);

        $actual = $collection->jsonSerialize();
        $I->assertEquals($expected, $actual);
    }
}

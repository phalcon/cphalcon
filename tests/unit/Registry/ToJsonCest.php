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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class ToJsonCest
{
    /**
     * Tests Phalcon\Registry :: toJson()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionToJson(UnitTester $I)
    {
        $I->wantToTest('Registry - toJson()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertEquals(
            json_encode($data),
            $registry->toJson()
        );

        $I->assertEquals(
            json_encode($data, JSON_PRETTY_PRINT),
            $registry->toJson(JSON_PRETTY_PRINT)
        );
    }
}

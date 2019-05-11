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

class GetCest
{
    /**
     * Tests Phalcon\Registry :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionGet(UnitTester $I)
    {
        $I->wantToTest('Registry - get()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $expected = 'four';

        $I->assertEquals(
            $expected,
            $registry->get('three')
        );

        $I->assertEquals(
            $expected,
            $registry['three']
        );

        $I->assertEquals(
            $expected,
            $registry->three
        );

        $I->assertEquals(
            $expected,
            $registry->offsetGet('three')
        );
    }
}

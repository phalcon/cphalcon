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

/**
 * Class GetCest
 */
class GetCest
{
    /**
     * Tests Phalcon\Registry :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionGet(UnitTester $I)
    {
        $I->wantToTest('Registry - get()');
        $data     = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $registry = new Registry($data);

        $expected = 'four';
        $actual   = $registry->get('three');
        $I->assertEquals($expected, $actual);

        $actual = $registry['three'];
        $I->assertEquals($expected, $actual);

        $actual = $registry->three;
        $I->assertEquals($expected, $actual);

        $actual = $registry->offsetGet('three');
        $I->assertEquals($expected, $actual);
    }
}

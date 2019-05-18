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

class SetCest
{
    /**
     * Tests Phalcon\Registry :: set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionSet(UnitTester $I)
    {
        $I->wantToTest('Registry - set()');

        $registry = new Registry();



        $registry->set('three', 'two');

        $I->assertEquals(
            'two',
            $registry->get('three')
        );



        $registry->three = 'Phalcon';

        $I->assertEquals(
            'Phalcon',
            $registry->get('three')
        );



        $registry->offsetSet('three', 123);

        $I->assertEquals(
            123,
            $registry->get('three')
        );



        $registry['three'] = true;

        $I->assertTrue(
            $registry->get('three')
        );
    }
}

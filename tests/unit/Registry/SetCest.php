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
 * Class SetCest
 */
class SetCest
{
    /**
     * Tests Phalcon\Registry :: set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionSet(UnitTester $I)
    {
        $I->wantToTest('Registry - set()');
        $registry = new Registry();

        $registry->set('three', 'two');
        $expected = 'two';
        $actual   = $registry->get('three');
        $I->assertEquals($expected, $actual);

        $registry->three = 'Phalcon';
        $expected        = 'Phalcon';
        $actual          = $registry->get('three');
        $I->assertEquals($expected, $actual);

        $registry->offsetSet('three', 123);
        $expected = 123;
        $actual   = $registry->get('three');
        $I->assertEquals($expected, $actual);

        $registry['three'] = true;
        $actual            = $registry->get('three');
        $I->assertTrue($actual);
    }
}

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
 * Class RemoveCest
 */
class RemoveCest
{
    /**
     * Tests Phalcon\Registry :: remove()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionRemove(UnitTester $I)
    {
        $I->wantToTest('Registry - remove()');
        $data     = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $registry = new Registry($data);

        $expected = $data;
        $actual   = $registry->toArray();
        $I->assertEquals($expected, $actual);

        $registry->remove('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $registry->toArray();
        $I->assertEquals($expected, $actual);

        $registry->init($data);
        unset($registry['five']);
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $registry->toArray();
        $I->assertEquals($expected, $actual);

        $registry->init($data);
        $registry->offsetUnset('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $registry->toArray();
        $I->assertEquals($expected, $actual);
    }
}

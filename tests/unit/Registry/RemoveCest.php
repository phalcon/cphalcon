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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Registry :: remove()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function registryRemove(UnitTester $I)
    {
        $I->wantToTest('Registry - remove()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertEquals(
            $data,
            $registry->toArray()
        );


        $registry->remove('five');

        $I->assertEquals(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray()
        );


        $registry->remove('FIVE');

        $I->assertEquals(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray()
        );


        $registry->init($data);

        unset($registry['five']);

        $I->assertEquals(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray()
        );


        $registry->init($data);

        $registry->offsetUnset('five');

        $I->assertEquals(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray()
        );
    }
}

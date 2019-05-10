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

class HasCest
{
    /**
     * Tests Phalcon\Registry :: has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionHas(UnitTester $I)
    {
        $I->wantToTest('Registry - has()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertTrue(
            $registry->has('three')
        );

        $I->assertFalse(
            $registry->has('unknown')
        );

        $I->assertTrue(
            isset($registry['three'])
        );

        $I->assertFalse(
            isset($registry['unknown'])
        );

        $I->assertTrue(
            $registry->offsetExists('three')
        );

        $I->assertFalse(
            $registry->offsetExists('unknown')
        );
    }
}

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
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Registry :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionHas(UnitTester $I)
    {
        $I->wantToTest('Registry - has()');
        $data     = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $registry = new Registry($data);

        $actual = $registry->has('three');
        $I->assertTrue($actual);

        $actual = $registry->has('unknown');
        $I->assertFalse($actual);

        $actual = isset($registry['three']);
        $I->assertTrue($actual);

        $actual = isset($registry['unknown']);
        $I->assertFalse($actual);

        $actual = $registry->offsetExists('three');
        $I->assertTrue($actual);

        $actual = $registry->offsetExists('unknown');
        $I->assertFalse($actual);
    }
}

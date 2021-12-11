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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetSetSharedCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetSetSharedCest
{
    /**
     * Tests Phalcon\Di\Di :: getShared()/setShared()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetShared(UnitTester $I)
    {
        $I->wantToTest('Di - getShared()');

        $container = new Di();

        $class = new Escaper();
        $container->setShared('escaper', $class);

        $object = $container->getShared('escaper');

        $expected = spl_object_hash($class);
        $actual   = spl_object_hash($object);
        $I->assertEquals($expected, $actual);

        $objectTwo = $container->getShared('escaper');
        $actual    = spl_object_hash($objectTwo);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Di\Di :: getShared() - set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetSetSharedSet(UnitTester $I)
    {
        $I->wantToTest('Di - getShared() - set');

        $container = new Di();

        $class = new Escaper();
        $container->set('escaper', $class, true);

        $object = $container->getShared('escaper');

        $expected = spl_object_hash($class);
        $actual   = spl_object_hash($object);
        $I->assertEquals($expected, $actual);

        $objectTwo = $container->getShared('escaper');
        $actual    = spl_object_hash($objectTwo);
        $I->assertEquals($expected, $actual);
    }
}

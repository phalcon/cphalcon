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
use Phalcon\Html\Escaper\EscaperInterface;
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
        $I->assertSame($expected, $actual);

        $objectTwo = $container->getShared('escaper');
        $actual    = spl_object_hash($objectTwo);
        $I->assertSame($expected, $actual);
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
        $I->assertSame($expected, $actual);

        $objectTwo = $container->getShared('escaper');
        $actual    = spl_object_hash($objectTwo);
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Di\Di :: getShared()/setShared() - class name
     *
     * @param UnitTester $I
     *
     * @issue  15032
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-12-12
     */
    public function diGetSetSharedClassName(UnitTester $I)
    {
        $I->wantToTest('Di - getShared() - set');

        $container   = new Di();
        $serviceName = 'escaper';

        /**
         * String name
         */
        $container->setShared($serviceName, Escaper::class);
        $actual = $container->getShared($serviceName);

        $class = Escaper::class;
        $I->assertInstanceOf($class, $actual);

        /**
         * Interface class string
         */
        $serviceName = EscaperInterface::class;
        $container->setShared($serviceName, Escaper::class);
        $actual = $container->getShared($serviceName);

        $class = Escaper::class;
        $I->assertInstanceOf($class, $actual);

        /**
         * Class string
         */
        $serviceName = Escaper::class;
        $container->setShared($serviceName, Escaper::class);
        $actual = $container->getShared($serviceName);

        $class = Escaper::class;
        $I->assertInstanceOf($class, $actual);
    }
}

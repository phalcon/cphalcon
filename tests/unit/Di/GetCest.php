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
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Di\ServiceInterface;
use Phalcon\Html\Escaper;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetCest
{
    /**
     * Unit Tests Phalcon\Di\Di :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGet(UnitTester $I)
    {
        $I->wantToTest('Di - get()');

        // setup
        $container = new Di();

        // set a service and get it to check
        $service = $container->set('escaper', Escaper::class);

        $class = ServiceInterface::class;
        $I->assertInstanceOf($class, $service);

        $class = Service::class;
        $I->assertInstanceOf($class, $service);

        $actual = $service->isShared();
        $I->assertFalse($actual);

        // get escaper service
        $actual = $container->get('escaper');

        $class = Escaper::class;
        $I->assertInstanceOf($class, $actual);

        $expected = spl_object_hash(new Escaper());
        $actual   = spl_object_hash($actual);
        $I->assertNotEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di :: get() - shared
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetShared(UnitTester $I)
    {
        $I->wantToTest('Di - get() - shared ');

        // setup
        $container = new Di();

        $escaper = new Escaper();
        $service = $container->set('escaper', $escaper, true);

        $actual = $service->isShared();
        $I->assertTrue($actual);

        // get escaper service - twice to cache it
        $actual = $container->get('escaper');
        $actual = $container->get('escaper');

        $expected = spl_object_hash($escaper);
        $actual   = spl_object_hash($actual);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di :: get() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetException(UnitTester $I)
    {
        $I->wantToTest('Di - get() - exception');

        // setup
        $container = new Di();

        // non exists service
        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' was not found in the " .
                "dependency injection container"
            ),
            function () use ($container) {
                $container->get('non-exists');
            }
        );
    }
}

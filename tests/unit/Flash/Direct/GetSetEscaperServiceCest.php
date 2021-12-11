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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Di\Di;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Exception;
use Phalcon\Html\Escaper;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetSetEscaperServiceCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class GetSetEscaperServiceCest
{
    /**
     * Tests Phalcon\Flash\Direct :: getEscaperService()/setEscaperService()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetSetEscaperService(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getEscaperService()/setEscaperService()');

        $escaper = new Escaper();
        $flash   = new Direct($escaper);

        $actual = $flash->getEscaperService();
        $I->assertEquals(spl_object_hash($escaper), spl_object_hash($actual));

        $newEscaper = new Escaper();
        $actual     = $flash->setEscaperService($newEscaper);
        $I->assertInstanceOf(Direct::class, $actual);

        $actual = $flash->getEscaperService();
        $I->assertEquals(spl_object_hash($newEscaper), spl_object_hash($actual));
    }

    /**
     * Tests Phalcon\Flash\Direct :: getEscaperService() - container
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetSetEscaperServiceContainer(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getEscaperService() - Container');

        $container = new Di();
        $escaper   = new Escaper();
        $container->setShared('escaper', $escaper);
        $flash = new Direct();
        $flash->setDI($container);

        $actual = $flash->getEscaperService();
        $I->assertEquals(spl_object_hash($escaper), spl_object_hash($actual));
    }

    /**
     * Tests Phalcon\Flash\Direct :: getEscaperService() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetEscaperServiceException(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getEscaperService() - exception');

        $I->expectThrowable(
            new Exception(
                "A dependency injection container is required to " .
                "access the 'escaper' service"
            ),
            function () {
                $flash = new Direct();

                $actual = $flash->getEscaperService();
            }
        );
    }
}

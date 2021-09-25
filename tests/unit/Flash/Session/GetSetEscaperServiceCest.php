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

namespace Phalcon\Tests\Unit\Flash\Session;

use Phalcon\Flash\Exception;
use Phalcon\Flash\Session;
use Phalcon\Html\Escaper;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetSetEscaperServiceCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class GetSetEscaperServiceCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Flash\Session :: getEscaperService()/setEscaperService()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetSetEscaperService(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getEscaperService()/setEscaperService()');

        $session = $this->container->getShared('session');
        $session->start();

        $escaper = new Escaper();
        $flash   = new Session($escaper);

        $actual = $flash->getEscaperService();
        $I->assertEquals(spl_object_hash($escaper), spl_object_hash($actual));

        $newEscaper = new Escaper();
        $actual     = $flash->setEscaperService($newEscaper);
        $I->assertInstanceOf(Session::class, $actual);

        $actual = $flash->getEscaperService();
        $I->assertEquals(spl_object_hash($newEscaper), spl_object_hash($actual));

        $session->destroy();
    }

    /**
     * Tests Phalcon\Flash\Session :: getEscaperService() - container
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetSetEscaperServiceContainer(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getEscaperService() - Container');

        $escaper = new Escaper();
        $this->container->setShared('escaper', $escaper);

        $flash = new Session();
        $flash->setDI($this->container);

        $actual = $flash->getEscaperService();
        $I->assertEquals(spl_object_hash($escaper), spl_object_hash($actual));
    }

    /**
     * Tests Phalcon\Flash\Session :: getEscaperService() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetEscaperServiceException(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getEscaperService() - exception');

        $I->expectThrowable(
            new Exception(
                'A dependency injection container is required to ' .
                'access the "escaper" service'
            ),
            function () {
                $flash = new Session();

                $actual = $flash->getEscaperService();
            }
        );
    }
}

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
use Phalcon\Flash\FlashInterface;
use Phalcon\Flash\Session;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Flash\Session :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionConstruct(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - __construct()');


        $flash = new Session();
        $I->assertInstanceOf(FlashInterface::class, $flash);
    }

    /**
     * Tests Phalcon\Flash\Session :: __construct() - no session service
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionConstructNoSessionService(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - __construct() - no session service');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');

        $I->expectThrowable(
            new Exception(
                'A dependency injection container is required to ' .
                'access the "session" service'
            ),
            function () {
                $flash = new Session();
                $flash->getMessages();
            }
        );
    }
}

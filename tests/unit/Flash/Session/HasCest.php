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

namespace Phalcon\Test\Unit\Flash\Session;

use Phalcon\Flash\Session;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class HasCest
{

    use DiTrait;

    public function _before(UnitTester $I): void
    {
        $this->newDi();

        try {
            $this->setDiService('escaper');
            $this->setDiService('sessionStream');
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        if (PHP_SESSION_ACTIVE !== session_status()) {
            session_start();
        }

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }
    }

    /**
     * Executed after each test
     *
     * @param  UnitTester $I
     * @return void
     */
    public function _after(UnitTester $I): void
    {
        session_destroy();
    }

    /**
     * Return flash instance
     */
    protected function getFlash(): Session
    {
        $container = $this->getDi();

        $flash = new Session();
        $flash->setDI($container);

        return $flash;
    }

    /**
     * Tests Phalcon\Flash\Session :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-03-30
     */
    public function flashSessionHas(UnitTester $I)
    {
        $flash = $this->getFlash();

        $I->assertFalse($flash->has());

        $flash->success("test success");

        $I->assertTrue($flash->has());

        $I->assertFalse($flash->has("error"));

        $I->assertTrue($flash->has("success"));
    }
}

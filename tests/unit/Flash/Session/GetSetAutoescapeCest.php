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

use Phalcon\Flash\Session;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class GetAutoescapeCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class GetSetAutoescapeCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Flash\Session :: getAutoescape()/setAutoescape()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetSetAutoescape(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getAutoescape()/setAutoescape()');

        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $actual = $flash->getAutoescape();
        $I->assertTrue($actual);

        $actual = $flash->setAutoescape(false);
        $I->assertInstanceOf(Session::class, $actual);

        $actual = $flash->getAutoescape();
        $I->assertFalse($actual);

        $session->destroy();
    }
}

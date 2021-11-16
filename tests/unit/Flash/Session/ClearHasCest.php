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

use function uniqid;

/**
 * Class ClearHasCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class ClearHasCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Flash\Session :: clear()/has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionClearHas(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - clear()/has');

        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);

        $actual = $flash->has();
        $I->assertTrue($actual);

        $actual = $flash->has('success');
        $I->assertTrue($actual);

        $actual = $flash->has('error');
        $I->assertTrue($actual);

        $actual = $flash->has('warning');
        $I->assertFalse($actual);

        $actual = $flash->has('notice');
        $I->assertFalse($actual);

        $expected = [$message1];
        $actual   = $flash->getMessages('success', false);
        $I->assertEquals($expected, $actual);

        $expected = [$message2];
        $actual   = $flash->getMessages('error', false);
        $I->assertEquals($expected, $actual);

        $flash->clear();

        $actual = $flash->getMessages();
        $I->assertEmpty($actual);

        $session->destroy();
    }
}

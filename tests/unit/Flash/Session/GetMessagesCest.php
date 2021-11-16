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
 * Class GetMessagesCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class GetMessagesCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Flash\Session :: getMessages()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetMessages(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getMessages()');

        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);

        $expected = [
            'success' => [$message1],
            'error'   => [$message2],
        ];
        $actual   = $flash->getMessages();
        $I->assertEquals($expected, $actual);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $message3 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);
        $flash->warning($message3);

        $expected = [$message1];
        $actual   = $flash->getMessages('success', false);
        $I->assertEquals($expected, $actual);

        $expected = [$message2];
        $actual   = $flash->getMessages('error', false);
        $I->assertEquals($expected, $actual);

        $expected = [$message3];
        $actual   = $flash->getMessages('warning', true);
        $I->assertEquals($expected, $actual);

        $expected = [
            'success' => [$message1],
            'error'   => [$message2],
        ];
        $actual   = $flash->getMessages();
        $I->assertEquals($expected, $actual);

        $session->destroy();
    }
}

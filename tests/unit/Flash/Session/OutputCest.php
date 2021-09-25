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

use function ob_end_clean;
use function ob_get_contents;
use function ob_start;
use function uniqid;

use const PHP_EOL;

/**
 * Class OutputCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class OutputCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Flash\Session :: output() - empty session
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionOutput(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - output() - empty session');

        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $flash->clear();

        ob_start();
        $flash->output();
        $result = ob_get_contents();
        ob_end_clean();

        $I->assertEmpty($result);

        $session->destroy();
    }

    /**
     * Tests Phalcon\Flash\Session :: output() - types
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionOutputTypes(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - output() - types');

        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);
        $flash->clear();

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '<div class="successMessage">' . $message1 . '</div>' . PHP_EOL
            . '<div class="errorMessage">' . $message2 . '</div>' . PHP_EOL;
        $I->assertEquals($expected, $actual);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '';
        $I->assertEquals($expected, $actual);

        $session->destroy();
    }
}

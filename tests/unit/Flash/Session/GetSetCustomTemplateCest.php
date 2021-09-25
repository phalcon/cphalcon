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
 * Class GetSetCustomTemplateCest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class GetSetCustomTemplateCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Flash\Session :: getCustomTemplate()/setCustomTemplate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetSetCustomTemplate(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getCustomTemplate()/setCustomTemplate()');

        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $actual = $flash->getCustomTemplate();
        $I->assertEmpty($actual);

        $template = '<span class="{cssClasses}">{message}</span>';
        $actual   = $flash->setCustomTemplate($template);
        $I->assertInstanceOf(Session::class, $actual);

        $actual = $flash->getCustomTemplate();
        $I->assertEquals($template, $actual);

        $session->destroy();
    }
}

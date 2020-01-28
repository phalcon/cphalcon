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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class OutputCest
{
    use DiTrait;

    /**
     * @var array
     */
    protected $classes = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiSessionFiles();
    }

    /**
     * Tests Phalcon\Flash\Session :: output()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashSessionOutput(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - output()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Flash\Session :: output() in case the session is empty
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-29
     */
    public function emptyFlashSessionOutput(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - output() when session is empty');

        $flash = $this->getFlash();

        $flash->clear();

        ob_start();
        $flash->output();
        $result = ob_get_contents();
        ob_end_clean();

        $I->assertEmpty($result);
    }

    /**
     * Return flash instance
     */
    protected function getFlash()
    {
        $container = $this->getDi();
        $flash     = new Session();
        $flash->setDI($container);
        $flash->setCssClasses($this->classes);

        return $flash;
    }
}

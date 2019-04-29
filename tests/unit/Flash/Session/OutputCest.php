<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash\Session;

use Phalcon\Flash\Session;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class OutputCest
 */
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @param UnitTester $I
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since 2019-04-29
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
        $flash     = new Session($this->classes);
        $flash->setDI($container);

        return $flash;
    }
}

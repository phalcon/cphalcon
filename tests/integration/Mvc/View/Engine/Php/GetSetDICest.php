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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Php;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Php;

class GetSetDICest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Php :: getDI() / setDI()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEnginePhpGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Php - getDI() / setDI()');

        $view = new View();

        $di1 = new Di();
        $di2 = new Di();

        $engine = new Php($view, $di1);

        $I->assertSame(
            $di1,
            $engine->getDI()
        );

        $engine->setDI($di2);

        $I->assertSame(
            $di2,
            $engine->getDI()
        );
    }
}

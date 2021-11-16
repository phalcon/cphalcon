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

namespace Phalcon\Tests\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\View\Simple;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class GetDICest
 */
class GetSetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Simple :: getDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleGetDI(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - getDI()');

        $container = new Di();
        $view      = new Simple();

        $view->setDI($container);

        $class  = Di::class;
        $actual = $view->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}

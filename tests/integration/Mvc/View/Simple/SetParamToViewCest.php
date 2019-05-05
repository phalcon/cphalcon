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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class SetParamToViewCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();
    }

    /**
     * Tests render with variables
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithVariables(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $view->setParamToView('a_cool_var', 'le-this');

        $I->assertEquals(
            '<p>le-this</p>',
            $view->render('currentrender/another')
        );
    }
}

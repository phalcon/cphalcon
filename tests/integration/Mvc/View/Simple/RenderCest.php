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

class RenderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();
    }

    /**
     * Tests render
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRender(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $I->assertEquals(
            'here',
            $view->render('currentrender/other')
        );
    }

    /**
     * Tests render
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderStandard(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $I->assertEquals(
            'We are here',
            $view->render('simple/index')
        );

        $I->assertEquals(
            'We are here',
            $view->getContent()
        );
    }
}

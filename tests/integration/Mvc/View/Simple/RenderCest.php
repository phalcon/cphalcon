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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\ViewTrait;

use function dataDir;
use function ob_end_clean;
use function ob_get_level;
use function ob_start;
use function sprintf;

class RenderCest
{
    use DiTrait;
    use ViewTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();

        ob_start();
    }

    public function _after(IntegrationTester $I)
    {
        if (ob_get_level()) {
            ob_end_clean();
        }
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: render()
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function mvcViewSimpleRender(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $I->assertEquals(
            'here',
            $view->render('currentrender/other')
        );
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: render() - standard
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

    /**
     * Tests Phalcon\Mvc\View\Simple :: render() - with mustache
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderRenderWithMustache(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - render() - with mustache');
        $view = $this->container->get('viewSimple');

        $view->setParamToView('name', 'FooBar');

        $view->registerEngines(
            [
                '.mhtml' => Volt::class,
            ]
        );

        $I->assertEquals(
            'Hello FooBar',
            $view->render('mustache/index')
        );

        $I->amInPath(
            dataDir('fixtures/views/mustache')
        );

        $I->seeFileFound('index.mhtml.php');

        $I->safeDeleteFile('index.mhtml.php');
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: render() - missing view
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderMissingView(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - render() - missing view');

        $I->expectThrowable(
            new Exception(
                sprintf(
                    "View '%sfixtures/views/unknown/view' was not found in the views directory",
                    dataDir()
                )
            ),
            function () {
                $view = $this->container->get('viewSimple');

                $view->render('unknown/view');
            }
        );
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: render() - with partials
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithPartials(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - render() - with partials');

        $view = $this->container->get('viewSimple');

        $expectedParams = [
            'cool_var' => 'FooBar',
        ];

        $view->partial('partials/partial', $expectedParams);

        $I->assertEquals(
            'Hey, this is a partial, also FooBar',
            $view->getContent()
        );

        $view->setVars($expectedParams);
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: render() - filename missing engine
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderFilenameWithoutEngine(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - render() - filename missing engine');

        $I->expectThrowable(
            new Exception(
                sprintf(
                    "View '%sfixtures/views/unknown/view' was not found in the views directory",
                    dataDir()
                )
            ),
            function () {
                $view = $this->container->get('viewSimple');

                $view->setParamToView('name', 'FooBar');

                $view->render('unknown/view');
            }
        );
    }
}

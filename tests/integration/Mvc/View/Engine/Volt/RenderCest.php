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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Test\Fixtures\Listener\ViewCompileListener;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class RenderCest
 */
class RenderCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: render()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltRender(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - render()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: render() - events
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-13
     */
    public function mvcViewEngineVoltRenderEvents(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - render() - events');
        $this->setNewFactoryDefault();
        $this->setDiViewSimple();
        $view = $this->getService('viewSimple');
        $eventsManager = $this->newEventsManager();
        $listener = new ViewCompileListener();
        $listener->setTestCase($this, $I);
        $eventsManager->attach('view:afterCompile', $listener);
        $eventsManager->attach('view:beforeCompile', $listener);

        $view->setEventsManager($eventsManager);
        $volt = new Volt($view, $this->container);
        $volt->setEventsManager($eventsManager);

        $template = dataFolder('fixtures/views/compiler/partial.volt');
        $volt->render($template, ['some_var' => 'aaa']);

        $expected = 'Before fired';
        $actual   = $listener->getBefore();
        $I->assertEquals($expected, $actual);

        $expected = 'After fired';
        $actual   = $listener->getAfter();
        $I->assertEquals($expected, $actual);
    }
}

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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Test\Fixtures\Listener\ViewCompileListener;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class RenderCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: render()
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-13
     */
    public function mvcViewEngineVoltRenderEvents(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - render() - events');

        $this->setNewFactoryDefault();
        $this->setDiService('viewSimple');

        $view          = $this->getService('viewSimple');
        $eventsManager = $this->newService('eventsManager');

        $listener = new ViewCompileListener();

        $listener->setTestCase($this, $I);

        $eventsManager->attach('view:afterCompile', $listener);
        $eventsManager->attach('view:beforeCompile', $listener);

        $view->setEventsManager($eventsManager);


        $volt = new Volt($view, $this->container);

        $volt->setEventsManager($eventsManager);

        // render() echoes out its result
        ob_start();
        $volt->render(
            dataDir('fixtures/views/compiler/partial.volt'),
            [
                'some_var' => 'aaa',
            ]
        );
        ob_end_clean();

        $I->assertEquals(
            'Before fired',
            $listener->getBefore()
        );

        $I->assertEquals(
            'After fired',
            $listener->getAfter()
        );
    }
}

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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Listener\ViewCompileListener;
use Phalcon\Tests\Support\Traits\DiTrait;

class RenderTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltRender(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('viewSimple');

        $view = $this->getService('viewSimple');
        $volt = new Volt($view, $this->container);

        $templatePath = supportDir('assets/views/compiler/partial.volt');

        ob_start();
        $volt->render($templatePath, ['some_var' => 'Label']);
        $output = ob_get_clean();

        $this->assertSame('Some label: Label', $output);
        $this->safeDeleteFile($templatePath . '.php');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-13
     */
    public function testMvcViewEngineVoltRenderEvents(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('viewSimple');

        $view = $this->getService('viewSimple');
        $eventsManager = $this->newService('eventsManager');

        $listener = new ViewCompileListener();

        $listener->setTestCase($this);

        $eventsManager->attach('view:afterCompile', $listener);
        $eventsManager->attach('view:beforeCompile', $listener);

        $view->setEventsManager($eventsManager);

        $volt = new Volt($view, $this->container);

        $volt->setEventsManager($eventsManager);

        // render() echoes out its result
        ob_start();
        $volt->render(
            supportDir('assets/views/compiler/partial.volt'),
            [
                'some_var' => 'aaa',
            ]
        );
        ob_end_clean();

        $this->assertSame(
            'Before fired',
            $listener->getBefore()
        );

        $this->assertSame(
            'After fired',
            $listener->getAfter()
        );
    }
}

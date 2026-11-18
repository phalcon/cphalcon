<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Simple;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
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

        $templatePath = Talon::settings()->supportPath('assets/views/compiler/partial.volt');

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

        $view          = $this->getService('viewSimple');
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
            Talon::settings()->supportPath('assets/views/compiler/partial.volt'),
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

    /**
     * A view parameter named after an engine local (`compiledTemplatePath`)
     * must not replace the compiled file that is included.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcViewEngineVoltRenderIgnoresCompiledTemplatePathParameter(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('viewSimple');

        $view = $this->getService('viewSimple');
        $volt = new Volt($view, $this->container);

        $templatePath = Talon::settings()->supportPath('assets/views/compiler/partial.volt');

        ob_start();
        $volt->render(
            $templatePath,
            ['some_var' => 'Label', 'compiledTemplatePath' => '/etc/hostname']
        );
        $output = ob_get_clean();

        $this->assertSame('Some label: Label', $output);
        $this->safeDeleteFile($templatePath . '.php');
    }

    /**
     * A variable that the action view sets is visible in the layout.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/810
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcViewEngineVoltRenderSharesVariablesWithLayout(): void
    {
        $this->newDi();
        $this->setDiService('view');

        /** @var View $view */
        $view = $this->container->get('view');
        $view->registerEngines(['.volt' => Volt::class]);

        $view->start();
        $view->render('scope', 'set');
        $view->finish();

        $this->assertSame('upper', $view->getContent());

        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/scope/set.volt.php'));
        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/layouts/scope.volt.php'));
    }

    /**
     * Each render starts with a new scope, the same as cphalcon. A variable
     * that a template sets in one render is not visible in the next render.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/810
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcViewEngineVoltRenderStartsWithNewScope(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view = $this->container->get('viewSimple');
        $view->registerEngines(['.volt' => Volt::class]);

        $view->render('scope/set');

        $actual = $view->render('scope/child');
        $this->assertSame('none', $actual);

        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/scope/set.volt.php'));
        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/scope/child.volt.php'));
    }
}

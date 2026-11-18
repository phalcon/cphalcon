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

use Phalcon\Mvc\View\Engine\Php;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Simple;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;

use function ob_end_clean;
use function ob_start;

class PartialTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @return array<array-key, array<array-key, string>>
     */
    public static function getScopeExamples(): array
    {
        return [
            'partial'             => ['scope/partial', 'upper'],
            'include with params' => ['scope/include', 'none'],
            'params'              => ['scope/params', 'param'],
            'set in partial'      => ['scope/caller', 'upper'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltPartial(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view   = $this->container->get('viewSimple');
        $engine = new Volt($view);

        ob_start();
        $engine->partial('partials/partial', ['cool_var' => 'FooBar']);
        ob_end_clean();

        $this->assertSame('Hey, this is a partial, also FooBar', $view->getContent());
    }

    /**
     * A variable that a Volt template sets is visible in a partial that the
     * Php engine renders. All the engines of a view share the variables, the
     * same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/810
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcViewEngineVoltPartialSharesVariablesWithPhpEngine(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view = $this->container->get('viewSimple');
        $view->registerEngines(
            [
                '.volt'  => Volt::class,
                '.phtml' => Php::class,
            ]
        );

        $actual = $view->render('scope/volt-to-php');
        $this->assertSame('upper', $actual);

        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/scope/volt-to-php.volt.php'));
    }

    /**
     * A variable that a template sets is visible in a partial with no
     * parameters. A partial with parameters gets a new scope with the view
     * variables and its parameters only, the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/810
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    #[DataProvider('getScopeExamples')]
    public function testMvcViewEngineVoltPartialTemplateVariables(
        string $template,
        string $expected
    ): void {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view = $this->container->get('viewSimple');
        $view->registerEngines(['.volt' => Volt::class]);

        $actual = $view->render($template);
        $this->assertSame($expected, $actual);

        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/' . $template . '.volt.php'));
        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/scope/child.volt.php'));
        $this->safeDeleteFile(Talon::settings()->supportPath('assets/views/scope/set.volt.php'));
    }
}

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
            'partial' => ['scope/partial', 'upper'],
            'include' => ['scope/include', 'upper'],
            'params'  => ['scope/params', 'param'],
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
     * A variable that a template sets is visible in the partials that the
     * template calls. Parameters of the partial win over the variable.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/810
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    #[DataProvider('getScopeExamples')]
    public function testMvcViewEngineVoltPartialInheritsTemplateVariables(
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
    }
}

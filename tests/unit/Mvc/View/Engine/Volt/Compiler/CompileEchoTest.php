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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

class CompileEchoTest extends AbstractUnitTestCase
{
    public static function getAutoescapeEscapeFilters(): array
    {
        return [
            [
                '{{ name|e }}',
                '<?= $this->escaper->html($name) ?>',
            ],
            [
                '{{ name|e() }}',
                '<?= $this->escaper->html($name) ?>',
            ],
            [
                '{{ name|escape }}',
                '<?= $this->escaper->html($name) ?>',
            ],
            [
                '{{ name|escape_attr }}',
                '<?= $this->escaper->attributes($name) ?>',
            ],
            [
                '{{ name|escape_css }}',
                '<?= $this->escaper->css($name) ?>',
            ],
            [
                '{{ name|escape_js }}',
                '<?= $this->escaper->js($name) ?>',
            ],
            [
                '{{ name|url_encode }}',
                '<?= urlencode($name) ?>',
            ],
        ];
    }

    public static function getAutoescapeEscapeFiltersNotOutermost(): array
    {
        return [
            [
                '{{ name|e ~ other }}',
                '<?= $this->escaper->html($this->escaper->html($name) . $other) ?>',
            ],
            [
                '{{ name|e|upper }}',
                '<?= $this->escaper->html(strtoupper($this->escaper->html($name))) ?>',
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileEcho(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString('{{ variable }}');
        $this->assertSame('<?= $variable ?>', $actual);
    }

    /**
     * With autoescape on, the output of a built-in escape filter is not
     * escaped again.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17678
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getAutoescapeEscapeFilters')]
    public function testMvcViewEngineVoltCompilerCompileEchoAutoescapeEscapeFilter(
        string $source,
        string $expected
    ): void {
        $compiler = new Compiler();
        $compiler->setOption('autoescape', true);

        $actual = $compiler->compileString($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * With autoescape on, the output is escaped when the escape filter is
     * not the outermost node of the expression.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17678
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getAutoescapeEscapeFiltersNotOutermost')]
    public function testMvcViewEngineVoltCompilerCompileEchoAutoescapeEscapeFilterNotOutermost(
        string $source,
        string $expected
    ): void {
        $compiler = new Compiler();
        $compiler->setOption('autoescape', true);

        $actual = $compiler->compileString($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * With autoescape on, the output is escaped when an extension compiles
     * a filter with the name of a built-in escape filter.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17678
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testMvcViewEngineVoltCompilerCompileEchoAutoescapeExtensionFilter(): void
    {
        $extension = new class () {
            public function compileFilter(
                string $name,
                string $arguments,
                mixed $funcArguments
            ): ?string {
                if ('e' === $name) {
                    return 'strrev(' . $arguments . ')';
                }

                return null;
            }
        };

        $compiler = new Compiler();
        $compiler->setOption('autoescape', true);
        $compiler->addExtension($extension);

        $expected = '<?= $this->escaper->html(strrev($name)) ?>';
        $actual   = $compiler->compileString('{{ name|e }}');
        $this->assertSame($expected, $actual);
    }

    /**
     * With autoescape on, the output is escaped when a user filter has the
     * name of a built-in escape filter.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17678
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testMvcViewEngineVoltCompilerCompileEchoAutoescapeUserFilter(): void
    {
        $compiler = new Compiler();
        $compiler->setOption('autoescape', true);
        $compiler->addFilter('e', 'strrev');

        $expected = '<?= $this->escaper->html(strrev($name)) ?>';
        $actual   = $compiler->compileString('{{ name|e }}');
        $this->assertSame($expected, $actual);
    }
}

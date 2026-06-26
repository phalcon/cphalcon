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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;

class CompileSwitchTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileSwitch(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            '{% switch x %}{% case 1 %}one{% default %}other{% endswitch %}'
        );

        $this->assertStringContainsString('<?php switch ($x):', $actual);
        $this->assertStringContainsString('<?php case 1: ?>', $actual);
        $this->assertStringContainsString('<?php default: ?>', $actual);
    }

    /**
     * Tests the "default" filter inside a case block of a switch
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltCompilerCompileSwitchCaseWithDefaultFilter(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            "{% set aNumber = 1 %}
{% switch aNumber %}
    {% case 0 %}
        {{ greatText }}
        {% break %}
    {% case 1 %}
        {{ false|default('simple text') }}
        {% break %}
{% endswitch %}"
        );

        $this->assertStringContainsString('<?php switch ($aNumber):', $actual);
        $this->assertStringContainsString('<?php case 0: ?>', $actual);
        $this->assertStringContainsString('<?php case 1: ?>', $actual);
        $this->assertStringContainsString(
            "(empty(false) ? ('simple text') : (false))",
            $actual
        );
    }

    /**
     * Tests the {% default %} clause surrounded by extra whitespace
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltCompilerCompileSwitchDefaultClauseWhitespace(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            "{% switch x %}{% case 1 %}one{%   default   %}other{% endswitch %}"
        );

        $this->assertStringContainsString('<?php default: ?>', $actual);
    }

    /**
     * Tests the {% default %} clause with whitespace control markers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltCompilerCompileSwitchDefaultClauseWhitespaceControl(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            "{% switch x %}{% case 1 %}one{%- default -%}other{% endswitch %}"
        );

        $this->assertStringContainsString('<?php default: ?>', $actual);
    }

    /**
     * Tests the "default" filter inside the {% default %} clause itself
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltCompilerCompileSwitchDefaultClauseWithDefaultFilter(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            "{% switch x %}{% case 1 %}one{% default %}"
            . "{{ value|default('unknown') }}{% endswitch %}"
        );

        $this->assertStringContainsString('<?php default: ?>', $actual);
        $this->assertStringContainsString(
            "(empty(\$value) ? ('unknown') : (\$value))",
            $actual
        );
    }

    /**
     * Tests the "default" filter outside a switch (issue #13242 regression)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltCompilerCompileSwitchDefaultFilterOutsideSwitch(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            "{{ value|default('unknown') }}"
        );

        $this->assertStringContainsString(
            "(empty(\$value) ? ('unknown') : (\$value))",
            $actual
        );
    }

    /**
     * Tests "default" used as a plain identifier inside a switch
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-10
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16003
     */
    public function testMvcViewEngineVoltCompilerCompileSwitchDefaultIdentifierInsideSwitch(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            "{% switch x %}{% case 1 %}"
            . "{% set default = 'abc' %}{{ default }}{% endswitch %}"
        );

        $this->assertStringContainsString("\$default = 'abc'", $actual);
        $this->assertStringContainsString('<?= $default ?>', $actual);
    }
}

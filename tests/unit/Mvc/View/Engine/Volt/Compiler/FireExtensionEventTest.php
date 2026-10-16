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

class FireExtensionEventTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerFireExtensionEvent(): void
    {
        $extension = new class () {
            public bool $called = false;

            public function compileFunction(array $expr, bool $extendsMode): mixed
            {
                $this->called = true;

                return null;
            }
        };

        $compiler = new Compiler();
        $compiler->addExtension($extension);
        $compiler->fireExtensionEvent(
            'compileFunction',
            [['name' => ['value' => 'dummy']], false]
        );

        $this->assertTrue($extension->called);
    }

    /**
     * An extension added during the compilation (here by a function) gets
     * the events for the remaining statements and expressions.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerFireExtensionEventAddedDuringCompile(): void
    {
        $extension = new class () {
            /**
             * @var string[]
             */
            public array $events = [];

            public function compileStatement(array $statement): ?string
            {
                $this->events[] = 'compileStatement';

                return null;
            }

            public function resolveExpression(array $expr): ?string
            {
                $this->events[] = 'resolveExpression';

                return null;
            }
        };

        $compiler = new Compiler();
        $compiler->addFunction(
            'add_extension',
            function () use ($compiler, $extension): string {
                $compiler->addExtension($extension);

                return "''";
            }
        );

        $actual = $compiler->compileString('{{ add_extension() }}a{{ 1 }}b');

        $this->assertSame("<?= '' ?>a<?= 1 ?>b", $actual);
        $this->assertSame(
            [
                'compileStatement',
                'compileStatement',
                'resolveExpression',
                'compileStatement',
            ],
            $extension->events
        );
    }

    /**
     * The compiler uses the string results of the extension events and
     * compiles the other parts as usual.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerFireExtensionEventCompileString(): void
    {
        $extension = new class () {
            /**
             * @var array<string, bool>
             */
            public array $events = [];

            public function compileFilter(string $name, string $arguments, mixed $funcArguments): ?string
            {
                $this->events['compileFilter'] = true;

                return 'ext_filter' === $name ? "'filter'" : null;
            }

            public function compileFunction(string $name, string $arguments, mixed $funcArguments): ?string
            {
                $this->events['compileFunction'] = true;

                return 'ext_function' === $name ? "'function'" : null;
            }

            public function compileStatement(array $statement): ?string
            {
                $this->events['compileStatement'] = true;

                return 'ext_raw' === ($statement['value'] ?? null) ? 'raw' : null;
            }

            public function resolveExpression(array $expr): ?string
            {
                $this->events['resolveExpression'] = true;

                return 'ext_expression' === ($expr['value'] ?? null) ? "'expression'" : null;
            }
        };

        $compiler = new Compiler();
        $compiler->addExtension($extension);

        $actual = $compiler->compileString(
            'ext_raw{{ ext_function() }}{{ "ext_expression" }}{{ 1|ext_filter }}{{ "other" }}'
        );

        $events = array_keys($extension->events);
        sort($events);

        $this->assertSame(
            "raw<?= 'function' ?><?= 'expression' ?><?= 'filter' ?><?= 'other' ?>",
            $actual
        );
        $this->assertSame(
            ['compileFilter', 'compileFunction', 'compileStatement', 'resolveExpression'],
            $events
        );
    }
}

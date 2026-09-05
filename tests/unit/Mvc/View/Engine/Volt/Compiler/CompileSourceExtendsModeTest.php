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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use ReflectionMethod;

final class CompileSourceExtendsModeTest extends AbstractUnitTestCase
{
    /**
     * @return array<array-key, array<array-key, string>>
     */
    public static function noBlockProvider(): array
    {
        return [
            'empty'        => [''],
            'comment only' => ['{# just a comment #}'],
        ];
    }

    /**
     * In extends mode a template that contributes no blocks gives back an
     * empty array instead of the null its return type forbids.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    #[DataProvider('noBlockProvider')]
    public function testMvcViewEngineVoltCompilerCompileSourceNoBlocks(string $source): void
    {
        $compiler = new Compiler();

        $method = new ReflectionMethod($compiler, 'compileSource');

        $expected = [];
        $actual   = $method->invoke($compiler, $source, true);
        $this->assertSame($expected, $actual);
    }
}

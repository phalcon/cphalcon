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

class CompileForElseTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileForElse(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            '{% for a in b %}{{ a }}{% else %}empty{% endfor %}'
        );

        $this->assertStringContainsString('foreach', $actual);
        $this->assertStringContainsString('iterated', $actual);
        $this->assertStringContainsString('empty', $actual);
    }
}

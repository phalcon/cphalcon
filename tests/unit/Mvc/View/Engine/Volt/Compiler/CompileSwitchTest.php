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
}

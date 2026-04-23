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

class CompileIncludeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileInclude(): void
    {
        $compiler = new Compiler();

        /**
         * A dynamic (variable) path produces a $this->partial() call
         * rather than attempting to statically compile the file.
         */
        $actual = $compiler->compileString('{% include templatePath %}');
        $this->assertSame('<?php $this->partial($templatePath); ?>', $actual);
    }
}

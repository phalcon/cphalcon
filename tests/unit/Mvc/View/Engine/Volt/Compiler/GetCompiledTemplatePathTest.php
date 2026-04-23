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

class GetCompiledTemplatePathTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerGetCompiledTemplatePath(): void
    {
        $viewFile    = supportDir('assets/views/compiler/partial.volt');
        $compileFile = $viewFile . '.php';

        $compiler = new Compiler();
        $compiler->compile($viewFile);

        $this->assertSame($compileFile, $compiler->getCompiledTemplatePath());

        $this->safeDeleteFile($compileFile);
    }
}

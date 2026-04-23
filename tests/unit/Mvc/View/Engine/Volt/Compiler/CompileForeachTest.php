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

class CompileForeachTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileForeach(): void
    {
        $compiler = new Compiler();

        $actual = $compiler->compileString(
            '{% for item in items %}{{ item }}{% endfor %}'
        );

        $this->assertSame(
            '<?php foreach ($items as $item) { ?><?= $item ?><?php } ?>',
            $actual
        );
    }
}

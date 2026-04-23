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

class CompileElseIfTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcViewEngineVoltCompilerCompileElseIf(): void
    {
        $volt = new Compiler();

        $compiled = $volt->compileString(
            '{% if i == 0 %}zero{% elseif i == 1 %}one{% else %}more than one{% endif %}'
        );

        $this->assertEquals(
            '<?php if ($i == 0) { ?>zero<?php } elseif ($i == 1) { ?>one<?php } else { ?>more than one<?php } ?>',
            $compiled
        );
    }
}

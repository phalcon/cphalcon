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

class CompileIfTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcViewEngineVoltCompilerCompileIf(): void
    {
        $volt = new Compiler();

        $compiled = $volt->compileString(
            '{% if i == 0 %}zero{% else %}not zero{% endif %}'
        );

        $this->assertEquals(
            '<?php if ($i == 0) { ?>zero<?php } else { ?>not zero<?php } ?>',
            $compiled
        );
    }
}

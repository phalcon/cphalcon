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

    /**
     * "in" has higher precedence than "and"
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14816
     */
    public function testMvcViewEngineVoltCompilerCompileIfInPrecedence(): void
    {
        $volt = new Compiler();

        $source = "{% if categoryIds is defined AND category['id'] in categoryIds %}\n"
            . "    checked\n"
            . "{% endif %}";

        $exprs    = $volt->parse($source);
        $compiled = $volt->compileIf($exprs[0], false);

        $this->assertSame(
            "<?php if (isset(\$categoryIds) && "
            . "\$this->isIncluded(\$category['id'], \$categoryIds)) { ?>\n"
            . "    checked\n"
            . "<?php } ?>",
            $compiled
        );
    }
}

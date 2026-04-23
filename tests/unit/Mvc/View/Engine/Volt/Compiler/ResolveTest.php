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

class ResolveTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getResolveTestCases(): array
    {
        return [
            [
                '{% if a is empty %} yes {% endif %}',
                '<?php if (empty($a)) { ?> yes <?php } ?>',
            ],
            [
                '{% if a is even %} yes {% endif %}',
                '<?php if (((($a) % 2) == 0)) { ?> yes <?php } ?>',
            ],
            [
                '{% if a is odd %} yes {% endif %}',
                '<?php if (((($a) % 2) != 0)) { ?> yes <?php } ?>',
            ],
            [
                '{% if a is numeric %} yes {% endif %}',
                '<?php if (is_numeric($a)) { ?> yes <?php } ?>',
            ],
            [
                '{% if a is defined %} yes {% endif %}',
                '<?php if (isset($a)) { ?> yes <?php } ?>',
            ],
        ];
    }

    /**
     * @dataProvider getResolveTestCases
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerResolveTest(
        string $template,
        string $expected
    ): void {
        $compiler = new Compiler();
        $actual   = $compiler->compileString($template);

        $this->assertSame($expected, $actual);
    }
}

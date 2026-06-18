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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class VerbatimTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array<int, string>>
     */
    public static function getVerbatimSources(): array
    {
        return [
            // Echo delimiters are emitted as-is
            [
                '{% verbatim %}{{ foo }}{% endverbatim %}',
                '{{ foo }}',
            ],
            // Statement delimiters are emitted as-is
            [
                '{% verbatim %}{% if x %}literal{% endif %}{% endverbatim %}',
                '{% if x %}literal{% endif %}',
            ],
            // Comment delimiters are emitted as-is
            [
                '{% verbatim %}{# not a comment #}{% endverbatim %}',
                '{# not a comment #}',
            ],
            // XML processing instruction
            [
                "{% verbatim %}<?xml version='1.0' encoding='UTF-8'?>{% endverbatim %}",
                "<?xml version='1.0' encoding='UTF-8'?>",
            ],
            // Handlebars/mustache style braces from the issue
            [
                '{% verbatim %}<b>{{</b> keep {{ }} <b>}}</b>{% endverbatim %}',
                '<b>{{</b> keep {{ }} <b>}}</b>',
            ],
            // Content before and after the block is compiled normally
            [
                'a {{ "b" }} {% verbatim %}{{ c }}{% endverbatim %} d',
                "a <?= 'b' ?> {{ c }} d",
            ],
            // Empty block
            [
                '{% verbatim %}{% endverbatim %}',
                '',
            ],
        ];
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileString() with the
     * {% verbatim %} tag - its body is emitted literally, without being parsed.
     *
     * @issue        https://github.com/phalcon/cphalcon/issues/17085
     * @author       Phalcon Team <team@phalcon.io>
     * @since         2026-06-06
     */
    #[DataProvider('getVerbatimSources')]
    public function testMvcViewEngineVoltCompilerVerbatim(
        string $source,
        string $expected
    ): void {
        $compiler = new Compiler();

        $actual = $compiler->compileString($source);

        $this->assertSame($expected, $actual);
    }
}

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

class SetOptionTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getVoltSetOptionAutoescape(): array
    {
        return [
            [
                '{{ "hello" }}{% autoescape true %}{{ "hello" }}' .
                '{% autoescape false %}{{ "hello" }}{% endautoescape %}' .
                '{{ "hello" }}{% endautoescape %}{{ "hello" }}',
                "<?= \$this->escaper->html('hello') ?>" .
                "<?= \$this->escaper->html('hello') ?>" .
                "<?= 'hello' ?><?= \$this->escaper->html('hello') ?>" .
                "<?= \$this->escaper->html('hello') ?>",
            ],
        ];
    }

    /**
     * @dataProvider getVoltSetOptionAutoescape
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     */
    public function testMvcViewEngineVoltCompilerSetOptionAutoescape(
        string $param,
        string $expected
    ): void {
        $volt = new Compiler();

        $volt->setOption('autoescape', true);

        $actual = $volt->compileString($param);
        $this->assertSame($expected, $actual);
    }
}

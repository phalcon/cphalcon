<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use UnitTester;

class SetOptionCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: setOption() - autoescape
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-01-17
     */
    public function mvcViewEngineVoltCompilerSetOptionAutoescape(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - setOption() - autoescape");
        $examples = $this->getVoltSetOptionAutoescape();
        foreach ($examples as $item) {
            $param    = $item[0];
            $expected = $item[1];
            $volt     = new Compiler();
            $volt->setOption('autoescape', true);

            $actual = $volt->compileString($param);
            $I->assertEquals($expected, $actual);
        };
    }

    /**
     * @return array
     */
    private function getVoltSetOptionAutoescape(): array
    {
        return [
            [
                '{{ "hello" }}{% autoescape true %}{{ "hello" }}{% autoescape false %}{{ "hello" }}{% endautoescape %}{{ "hello" }}{% endautoescape %}{{ "hello" }}',
                "<?= \$this->escaper->escapeHtml('hello') ?><?= \$this->escaper->escapeHtml('hello') ?><?= 'hello' ?><?= \$this->escaper->escapeHtml('hello') ?><?= \$this->escaper->escapeHtml('hello') ?>",
            ],
        ];
    }
}

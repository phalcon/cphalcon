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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

/**
 * Class SetOptionCest
 */
class SetOptionCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: setOption() - autoescape
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     *
     * @dataProvider getVoltSetOptionAutoescape
     */
    public function mvcViewEngineVoltCompilerSetOptionAutoescape(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - setOption() - autoescape");

        $param    = $example[0];
        $expected = $example[1];

        $volt = new Compiler();

        $volt->setOption('autoescape', true);

        $I->assertEquals(
            $expected,
            $volt->compileString($param)
        );
    }


    private function getVoltSetOptionAutoescape(): array
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
}

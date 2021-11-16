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
 * Class AddFunctionCest
 */
class AddFunctionCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFunction()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     *
     * @dataProvider getVoltAddFunction
     */
    public function mvcViewEngineVoltCompilerAddFunction(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFunction()");

        $name     = $example[0];
        $funcName = $example[1];
        $voltName = $example[2];
        $expected = $example[3];

        $volt = new Compiler();

        $volt->addFunction($name, $funcName);

        $I->assertEquals(
            $expected,
            $volt->compileString($voltName)
        );
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFunction()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     *
     * @dataProvider getVoltAddFunctionClosure
     */
    public function mvcViewEngineVoltCompilerAddFunctionClosure(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFunction() - closure");

        $name     = $example[0];
        $funcName = $example[1];
        $voltName = $example[2];
        $expected = $example[3];

        $volt = new Compiler();

        $volt->addFunction(
            $name,
            function ($arguments) use ($funcName) {
                return $funcName . '(' . $arguments . ')';
            }
        );

        $I->assertEquals(
            $expected,
            $volt->compileString($voltName)
        );
    }

    private function getVoltAddFunction(): array
    {
        return [
            [
                'random',
                'mt_rand',
                '{{ random() }}',
                '<?= mt_rand() ?>',
            ],

            [
                'strtotime',
                'strtotime',
                '{{ strtotime("now") }}',
                "<?= strtotime('now') ?>",
            ],
        ];
    }

    private function getVoltAddFunctionClosure(): array
    {
        return [
            [
                'shuffle',
                'str_shuffle',
                '{{ shuffle("hello") }}',
                '<?= str_shuffle(\'hello\') ?>',
            ],
        ];
    }
}

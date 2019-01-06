<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-01-17
     */
    public function mvcViewEngineVoltCompilerAddFunction(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFunction()");
        $examples = $this->getVoltAddFunction();
        foreach ($examples as $item) {
            $name     = $item[0];
            $funcName = $item[1];
            $voltName = $item[2];
            $expected = $item[3];

            $volt = new Compiler();
            $volt->addFunction($name, $funcName);

            $actual = $volt->compileString($voltName);
            $I->assertEquals($expected, $actual);
        };
    }

    /**
     * @return array
     */
    private function getVoltAddFunction(): array
    {
        return [
            ['random', 'mt_rand', '{{ random() }}', '<?= mt_rand() ?>'],
            ['strtotime', 'strtotime', '{{ strtotime("now") }}', "<?= strtotime('now') ?>"],
        ];
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFunction()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-01-17
     */
    public function mvcViewEngineVoltCompilerAddFunctionClosure(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFunction() - closure");
        $examples = $this->getVoltAddFunctionClosure();
        foreach ($examples as $item) {
            $name     = $item[0];
            $funcName = $item[1];
            $voltName = $item[2];
            $expected = $item[3];

            $volt = new Compiler();
            $volt->addFunction(
                $name,
                function ($arguments) use ($funcName) {
                    return $funcName . '(' . $arguments . ')';
                }
            );

            $actual = $volt->compileString($voltName);
            $I->assertEquals($expected, $actual);
        };
    }

    /**
     * @return array
     */
    private function getVoltAddFunctionClosure(): array
    {
        return [
            ['shuffle', 'str_shuffle', '{{ shuffle("hello") }}', '<?= str_shuffle(\'hello\') ?>'],
        ];
    }
}

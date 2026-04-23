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

class AddFunctionTest extends AbstractUnitTestCase
{
    public static function getVoltAddFunction(): array
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
                '<?= strtotime(\'now\') ?>',
            ],
        ];
    }

    public static function getVoltAddFunctionClosure(): array
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

    /**
     * @dataProvider getVoltAddFunction
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     */
    public function testMvcViewEngineVoltCompilerAddFunction(
        string $name,
        string $funcName,
        string $voltName,
        string $expected
    ): void {
        $volt = new Compiler();

        $volt->addFunction($name, $funcName);

        $this->assertEquals(
            $expected,
            $volt->compileString($voltName)
        );
    }

    /**
     * @dataProvider getVoltAddFunctionClosure
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     */
    public function testMvcViewEngineVoltCompilerAddFunctionClosure(
        string $name,
        string $funcName,
        string $voltName,
        string $expected
    ): void {
        $volt = new Compiler();

        $volt->addFunction(
            $name,
            function ($arguments) use ($funcName) {
                return $funcName . '(' . $arguments . ')';
            }
        );

        $this->assertEquals(
            $expected,
            $volt->compileString($voltName)
        );
    }
}

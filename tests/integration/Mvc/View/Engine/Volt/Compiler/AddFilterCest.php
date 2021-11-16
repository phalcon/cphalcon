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
 * Class AddFilterCest
 */
class AddFilterCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFilter()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider getVoltAddFilter
     */
    public function mvcViewEngineVoltCompilerAddFilter(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFilter()");

        $name     = $example[0];
        $filter   = $example[1];
        $voltName = $example[2];
        $expected = $example[3];

        $volt = new Compiler();

        $volt->addFilter($name, $filter);

        $actual = $volt->compileString($voltName);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFilter() - closure
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider getVoltAddFilterClosure
     */
    public function mvcViewEngineVoltCompilerAddFilterClosure(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFilter() - closure");

        $name     = $example[0];
        $filter   = $example[1];
        $voltName = $example[2];
        $expected = $example[3];

        $volt = new Compiler();

        $volt->addFilter(
            $name,
            function ($arguments) use ($filter) {
                return $filter . '(",", ' . $arguments . ')';
            }
        );

        $I->assertEquals(
            $expected,
            $volt->compileString($voltName)
        );
    }

    private function getVoltAddFilter(): array
    {
        return [
            [
                'reverse',
                'strrev',
                '{{ "hello"|reverse }}',
                '<?= strrev(\'hello\') ?>',
            ],
        ];
    }

    private function getVoltAddFilterClosure(): array
    {
        return [
            [
                'separate',
                'explode',
                '{{ "1,2,3,4"|separate }}',
                '<?= explode(",", \'1,2,3,4\') ?>',
            ],
        ];
    }
}

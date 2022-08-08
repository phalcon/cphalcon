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

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class ExpressionCest
 */
class ExpressionCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: expression()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-07-01
     */
    public function mvcViewEngineVoltCompilerExpression(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - expression()');

        $this->setNewFactoryDefault();

        $volt = new Compiler();
        $volt->setDI($this->container);

        // title("\r\n", "\n\n")
        $source   = [
            [
                'expr' => [
                    'type' => 260,
                    'value' => "\t",
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'file' => 'eval code',
                'line' => 1,
            ],
            [
                'expr' => [
                    'type' => 260,
                    'value' => "\n\n",
                    'file' => 'eval code',
                    'line' => 1,
                ],
                'file' => 'eval code',
                'line' => 1,
            ]
        ];

        $expected = "\"\t\", \"\n\n\"";
        $actual   = $volt->expression($source, true);

        $I->assertEquals($expected, $actual);
    }
}

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
 * Class AddFilterCest
 */
class AddFilterCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFilter()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerAddFilter(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFilter()");
        $examples = $this->getVoltAddFilter();
        foreach ($examples as $item) {
            $name     = $item[0];
            $filter   = $item[1];
            $voltName = $item[2];
            $expected = $item[3];

            $volt = new Compiler();
            $volt->addFilter($name, $filter);
            $actual = $volt->compileString($voltName);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    private function getVoltAddFilter(): array
    {
        return [
            ['reverse', 'strrev', '{{ "hello"|reverse }}', '<?= strrev(\'hello\') ?>'],
        ];
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: addFilter() - closure
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerAddFilterClosure(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - addFilter() - closure");
        $examples = $this->getVoltAddFilterClosure();
        foreach ($examples as $item) {
            $name     = $item[0];
            $filter   = $item[1];
            $voltName = $item[2];
            $expected = $item[3];

            $volt = new Compiler();
            $volt->addFilter(
                $name,
                function ($arguments) use ($filter) {
                    return $filter . '(",", ' . $arguments . ')';
                }
            );

            $actual = $volt->compileString($voltName);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    private function getVoltAddFilterClosure(): array
    {
        return [
            ['separate', 'explode', '{{ "1,2,3,4"|separate }}', '<?= explode(",", \'1,2,3,4\') ?>'],
        ];
    }
}

<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Base;

use Codeception\Example;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Base;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Base :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     * @throws ExceptionAlias
     *
     * @dataProvider getExamples
     * @since        2020-01-05
     *
     */
    public function htmlHelperBaseUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Base - __invoke()');
        $escaper = new Escaper();
        $helper  = new Base($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('base');
        $expected = $example[0];
        $actual   = $locator($example[1], $example[2]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                '<base>',
                '',
                [],
            ],
            [
                '<base href="https://phalcon.io">',
                'https://phalcon.io',
                [],
            ],
            [
                '<base href="https://phalcon.io">',
                'https://phalcon.io',
                [
                    'href' => 'https://phalcon.io',
                ],
            ],
            [
                '<base href="https://phalcon.io" target="_top">',
                'https://phalcon.io',
                [
                    'target' => '_top',
                ],
            ],
        ];
    }
}

<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Body;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Body;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Body :: __invoke()
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
    public function htmlHelperBodyUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Body - __invoke()');
        $escaper = new Escaper();
        $helper  = new Body($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('body');
        $expected = $example[0];
        $actual   = $locator($example[1]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                '<body>',
                [],
            ],
            [
                '<body id="my-id">',
                [
                    'id' => 'my-id',
                ],
            ],
            [
                '<body id="my-id" class="my-class">',
                [
                    'class' => 'my-class',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}

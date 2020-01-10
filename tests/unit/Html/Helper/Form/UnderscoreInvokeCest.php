<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Form;

use Codeception\Example;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Form;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Form :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     * @throws ExceptionAlias
     * @dataProvider getExamples
     * @since        2020-01-05
     *
     */
    public function htmlHelperFormUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Form - __invoke()');
        $escaper = new Escaper();
        $helper  = new Form($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('form');
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
                '<form method="post" enctype="multipart/form-data">',
                [],
            ],
            [
                '<form id="my-id" name="my-name" method="post" enctype="multipart/form-data">',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<form id="my-id" name="my-name" class="my-class" method="post" enctype="multipart/form-data">',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}

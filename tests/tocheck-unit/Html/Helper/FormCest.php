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

namespace Phalcon\Test\Unit\Html\Helper;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Form;
use Phalcon\Html\TagFactory;
use UnitTester;

class FormCest
{
    /**
     * Tests Phalcon\Html\Helper\Form :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperFormConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Form - __construct()');
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

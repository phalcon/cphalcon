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

namespace Phalcon\Test\Unit\Html\Helper\TextArea;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\TextArea;
use Phalcon\Html\TagFactory;
use UnitTester;

class TextAreaCest
{
    /**
     * Tests Phalcon\Html\Helper\TextArea :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperTextareaConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\TextArea - __construct()');
        $escaper = new Escaper();
        $helper  = new TextArea($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('textarea');
        $expected = $example[0];
        $actual   = $locator($example[1], $example[2]);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                '<textarea>Phalcon Framework</textarea>',
                'Phalcon Framework',
                [],
            ],
            [
                '<textarea>Jack &amp; Jill</textarea>',
                'Jack & Jill',
                [],
            ],
            [
                '<textarea>&lt;script&gt;alert(&quot;hello&quot;);&lt;/script&gt;test tag</textarea>',
                '<script>alert("hello");</script>test tag',
                [],
            ],
            [
                '<textarea id="my-id" name="my-name">test tag</textarea>',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<textarea id="my-id" name="my-name" class="my-class">test tag</textarea>',
                'test tag',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}

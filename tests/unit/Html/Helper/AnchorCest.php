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
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\TagFactory;
use UnitTester;

class AnchorCest
{
    /**
     * Tests Phalcon\Html\Helper\Anchor :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperAnchorConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Anchor - __construct()');
        $escaper = new Escaper();
        $anchor  = new Anchor($escaper);

        $expected = $example[0];
        $actual   = $anchor('/myurl', 'click<>me', $example[1]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('a');
        $expected = $example[0];
        $actual   = $locator('/myurl', 'click<>me', $example[1]);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                '<a href="/myurl">click&lt;&gt;me</a>',
                [],
            ],
            [
                '<a href="/myurl">click&lt;&gt;me</a>',
                [
                    'href' => '/somethingelse',
                ],
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name">click&lt;&gt;me</a>',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name" class="my-class">click&lt;&gt;me</a>',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}

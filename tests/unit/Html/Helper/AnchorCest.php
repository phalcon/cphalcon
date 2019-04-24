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

namespace Phalcon\Test\Unit\Html\Helper;

use Codeception\Example;
use Phalcon\Html\Helper\Anchor;
use UnitTester;

/**
 * Class AnchorCest
 */
class AnchorCest
{
    /**
     * Tests Phalcon\Html\Helper\Anchor :: __construct()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-01-19
     */
    public function htmlHelperAnchorConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Anchor - __construct()');
        $anchor  = new Anchor();

        $expected = $example[0];
        $actual   = $anchor('/myurl', 'click<>me', $example[1]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
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

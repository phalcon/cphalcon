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

namespace Phalcon\Test\Unit\Escaper;

use Codeception\Example;
use Phalcon\Escaper;
use UnitTester;

use const ENT_HTML401;
use const ENT_HTML5;
use const ENT_XHTML;
use const ENT_XML1;

class EscapeHtmlAttrCest
{
    /**
     * Tests Phalcon\Escaper :: escapeHtmlAttr()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-16
     *
     * @dataProvider escaperEscapeHtmlAttrProvider
     */
    public function escaperEscapeHtmlAttr(UnitTester $I, Example $example)
    {
        $I->wantToTest('Escaper - escapeHtmlAttr()');

        $escaper = new Escaper();

        $escaper->setHtmlQuoteType(
            $example['htmlQuoteType']
        );

        $I->assertEquals(
            $example['expected'],
            $escaper->escapeHtmlAttr(
                $example['text']
            )
        );
    }

    private function escaperEscapeHtmlAttrProvider(): array
    {
        return [
            [
                'htmlQuoteType' => ENT_HTML401,
                'expected'      => 'That&#039;s right',
                'text'          => "That's right",
            ],

            [
                'htmlQuoteType' => ENT_XML1,
                'expected'      => 'That&#039;s right',
                'text'          => "That's right",
            ],

            [
                'htmlQuoteType' => ENT_XHTML,
                'expected'      => 'That&#039;s right',
                'text'          => "That's right",
            ],

            [
                'htmlQuoteType' => ENT_HTML5,
                'expected'      => 'That&#039;s right',
                'text'          => "That's right",
            ],
            [
                'htmlQuoteType' => ENT_HTML401,
                'expected'      => '',
                'text'          => null,
            ],

            [
                'htmlQuoteType' => ENT_XML1,
                'expected'      => '',
                'text'          => null,
            ],

            [
                'htmlQuoteType' => ENT_XHTML,
                'expected'      => '',
                'text'          => null,
            ],

            [
                'htmlQuoteType' => ENT_HTML5,
                'expected'      => '',
                'text'          => null,
            ],
        ];
    }
}

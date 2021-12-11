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

namespace Phalcon\Tests\Integration\Forms\Element\Radio;

use IntegrationTester;
use Phalcon\Forms\Element\Radio;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class RenderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(
            Tag::XHTML5
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Radio :: render()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementRadioRenderSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Radio - render()');

        $element = new Radio('simple');

        $I->assertSame(
            '<input type="radio" id="simple" name="simple" />',
            $element->render()
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Radio :: render() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementRadioRenderWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Radio - render() with parameters');

        $element = new Radio(
            'fantastic',
            [
                'class' => 'fancy',
            ]
        );

        $I->assertSame(
            '<input type="radio" id="fantastic" name="fantastic" class="fancy" />',
            $element->render()
        );
    }
}

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

namespace Phalcon\Tests\Integration\Forms\Element\Password;

use IntegrationTester;
use Phalcon\Forms\Element\Password;
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
     * Tests Phalcon\Forms\Element\Password :: render()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementPasswordRenderSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - render()');

        $element = new Password('simple');

        $I->assertSame(
            '<input type="password" id="simple" name="simple" />',
            $element->render()
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Password :: render() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementPasswordRenderWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - render() with parameters');

        $element = new Password(
            'fantastic',
            [
                'class'       => 'fancy',
                'placeholder' => 'Initial value',
            ]
        );

        $I->assertSame(
            '<input type="password" id="fantastic" name="fantastic" class="fancy" placeholder="Initial value" />',
            $element->render()
        );
    }
}

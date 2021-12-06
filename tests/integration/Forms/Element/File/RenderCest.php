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

namespace Phalcon\Tests\Integration\Forms\Element\File;

use IntegrationTester;
use Phalcon\Forms\Element\File;
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
     * Tests Phalcon\Forms\Element\File :: render()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementFileRenderSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\File - render()');

        $element = new File('simple');

        $I->assertSame(
            '<input type="file" id="simple" name="simple" />',
            $element->render()
        );
    }

    /**
     * Tests Phalcon\Forms\Element\File :: render() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementFileRenderWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\File - render() with parameters');

        $element = new File(
            'fantastic',
            [
                'class' => 'fancy',
            ]
        );

        $I->assertSame(
            '<input type="file" id="fantastic" name="fantastic" class="fancy" />',
            $element->render()
        );
    }
}

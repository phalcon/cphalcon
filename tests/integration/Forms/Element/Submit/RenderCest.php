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

namespace Phalcon\Tests\Integration\Forms\Element\Submit;

use IntegrationTester;
use Phalcon\Forms\Element\Submit;
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
     * Tests Phalcon\Forms\Element\Submit :: render()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementSubmitRenderSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Submit - render()');

        Tag::setDocType(
            Tag::XHTML5
        );

        $element = new Submit('simple');

        $I->assertSame(
            '<input type="submit" value="simple" />',
            $element->render()
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Submit :: render() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementSubmitRenderWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Submit - render() with parameters');

        Tag::setDocType(
            Tag::XHTML5
        );

        $element = new Submit(
            'fantastic',
            [
                'class' => 'fancy',
            ]
        );

        $I->assertSame(
            '<input type="submit" value="fantastic" class="fancy" />',
            $element->render()
        );
    }
}

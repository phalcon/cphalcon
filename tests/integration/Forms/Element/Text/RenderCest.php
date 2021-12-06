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

namespace Phalcon\Tests\Integration\Forms\Element\Text;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;

class RenderCest
{
    /**
     * Tests Phalcon\Forms\Element\Text :: render()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementTextRenderSimple(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Text - render()');

        $factory = new TagFactory(new Escaper());
        $element = new Text('simple');
        $element->setTagFactory($factory);

        $expected = '<input type="text" id="simple" name="simple" />';
        $actual   = $element->render();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Forms\Element\Text :: render() with parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsElementTextRenderWithParameters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Text - render() with parameters');

        $factory = new TagFactory(new Escaper());
        $element = new Text(
            'fantastic',
            [
                'class'       => 'fancy',
                'placeholder' => 'Initial value',
            ]
        );
        $element->setTagFactory($factory);

        $expected = '<input type="text" id="fantastic" name="fantastic" '
            . 'class="fancy" placeholder="Initial value" />';
        $actual   = $element->render();
        $I->assertSame($expected, $actual);
    }
}

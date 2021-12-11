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

namespace Phalcon\Tests\Integration\Forms\Element\Select;

use IntegrationTester;
use Phalcon\Forms\Element\Select;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class AddOptionCest
{
    use DiTrait;

    public function _before()
    {
        $this->setNewFactoryDefault();

        Tag::setDoctype(
            Tag::HTML5
        );
    }

    public function testCorrectlyAddOptionToSelectElementIfParameterIsAnArray(IntegrationTester $I)
    {
        $element = new Select('test-select');

        $element->addOption(
            [
                'key' => 'value',
            ]
        );

        $I->assertSame(
            '<select id="test-select" name="test-select"><option value="key">value</option></select>',
            preg_replace(
                '/[[:cntrl:]]/',
                '',
                $element->render()
            )
        );
    }

    public function testCorrectlyAddOptionToSelectElementIfParameterIsAString(IntegrationTester $I)
    {
        $element = new Select('test-select');

        $element->addOption('value');

        $I->assertSame(
            '<select id="test-select" name="test-select"><option value="0">value</option></select>',
            preg_replace(
                '/[[:cntrl:]]/',
                '',
                $element->render()
            )
        );
    }
}

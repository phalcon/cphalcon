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

namespace Phalcon\Test\Unit\Assets\Inline;

use Codeception\Example;
use Phalcon\Assets\Inline;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getAttributes()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsInlineGetAttributes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Inline - getAttributes()');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Inline(
            $example['type'],
            $example['content'],
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'type'    => 'css',
                'content' => 'p {color: #000099}',
            ],
            [
                'type'    => 'js',
                'content' => '<script>alert("Hello");</script>',
            ],
        ];
    }
}

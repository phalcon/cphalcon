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

class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline :: setType()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsInlineSetType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Inline - setType()');

        $asset = new Inline(
            $example['type'],
            $example['content']
        );

        $asset->setType(
            $example['newType']
        );

        $I->assertEquals(
            $example['newType'],
            $asset->getType()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'type'    => 'css',
                'content' => 'p {color: #000099}',
                'newType' => 'js',
            ],
            [
                'type'    => 'js',
                'content' => '<script>alert("Hello");</script>',
                'newType' => 'css',
            ],
        ];
    }
}

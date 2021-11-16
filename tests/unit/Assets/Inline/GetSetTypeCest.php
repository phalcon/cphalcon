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

namespace Phalcon\Tests\Unit\Assets\Inline;

use Codeception\Example;
use Phalcon\Assets\Inline;
use UnitTester;

/**
 * Class GetSetTypeCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline
 */
class GetSetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getType()/setType()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsInlineGetSetType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Inline - getType()/setType()');

        $asset = new Inline($example['type'], $example['content']);
        $asset->setType($example['newType']);

        $expected = $example['newType'];
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
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
